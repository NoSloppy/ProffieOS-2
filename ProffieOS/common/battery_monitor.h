#ifndef COMMON_BATTERY_MONITOR_H
#define COMMON_BATTERY_MONITOR_H

#ifndef NO_BATTERY_MONITOR

#include "analog_read.h"
#include "saber_base.h"

// Battery voltage smoothing time constant (0.0-1.0)
// Lower values = more stable readings but slower response
// Higher values = faster response but more fluctuation
// Default 0.01 gives ~3 second settling time (95% of final value)
#ifndef BATTERY_VOLTAGE_SMOOTHING
#define BATTERY_VOLTAGE_SMOOTHING 0.01
#endif

class BatteryMonitor : Looper, CommandParser, StateMachine {
public:
BatteryMonitor() : reader_(batteryLevelPin,
			     INPUT
#if VERSION_MAJOR == 5 || VERSION_MAJOR == 6
                             , 10e-6
#endif
   ) {}
  const char* name() override { return "BatteryMonitor"; }
  
  // Returns the load-compensated battery voltage
  float battery() const {
    return last_voltage_compensated_;
  }
  
  // Returns the raw measured voltage (for debugging)
  float battery_raw() const {
    return last_voltage_;
  }
  
  // Returns the estimated battery internal resistance in ohms
  float battery_resistance() const {
    return battery_resistance_;
  }
  void SetLoad(bool on) {
    loaded_ = on;
  }
  bool low() const { return low_count_ > 1000; }
  float battery_percent() {
    // Energy is roughly proportional to voltage squared.
    float v = battery();
    float min_v = 2.85;
    float max_v = 4.1;
    return 100.0 * clamp((v * v - min_v * min_v) / (max_v * max_v - min_v * min_v), 0, 1);
//    return 100.0 * (v - min_v) / (max_v - min_v);
  }
  void SetPinHigh(bool go_high) {
    if (go_high) {
      pinMode(batteryLevelPin, OUTPUT);
      digitalWrite(batteryLevelPin, HIGH);
    } else {
#if VERSION_MAJOR >= 2
      pinMode(batteryLevelPin, INPUT);
#else
      pinMode(batteryLevelPin, INPUT_PULLDOWN);
#endif
      // delay reading voltage for a bit to let it settle.
      last_voltage_read_time_ = micros();
    }
  }
protected:
  void Setup() override {
    last_voltage_ = battery_now();
    last_voltage_compensated_ = last_voltage_;
    last_voltage_before_change_ = last_voltage_;
    last_current_estimate_ = 0.0;
    battery_resistance_ = 0.1; // Initial estimate: 100 milliohms
    calibration_count_ = 1; // Allow calibration from first measurement
    SetPinHigh(false);
  }
  void Loop() override {
    if (monitor.ShouldPrint(Monitoring::MonitorBattery) ||
        millis() - last_print_millis_ > 20000) {
      STDOUT.print("Battery voltage: ");
      STDOUT.println(battery());
      last_print_millis_ = millis();
    }

    STATE_MACHINE_BEGIN();
    last_voltage_read_time_ = micros();
    while (true) {
      while (micros() - last_voltage_read_time_ < 1000) YIELD();
      while (!reader_.Start()) YIELD();
      while (!reader_.Done()) YIELD();
      float v = battery_now();
      uint32_t now = micros();
      // float mul = powf(BATTERY_VOLTAGE_SMOOTHING, (now - last_voltage_read_time_) / 1000000.0);
      float mul = expf(logf(BATTERY_VOLTAGE_SMOOTHING) * (now - last_voltage_read_time_) / 1000000.0);
      last_voltage_read_time_ = now;
      last_voltage_ = last_voltage_ * mul + v * (1 - mul);
      
      // Skip load compensation if no battery detected (USB power)
      if (last_voltage_ < 0.5) {
        last_voltage_compensated_ = last_voltage_;
        if (IsLow()) {
          low_count_++;
        } else {
          low_count_ = 0;
        }
        continue;
      }
      
      // Get current estimate from all saberbases
      float current_ma = SaberBase::GetTotalCurrent();
      
      // Detect large changes in current for resistance calibration
      float current_change = fabsf(current_ma - last_current_estimate_);
      if (current_change > 100.0) { // Significant change (>100mA)
        // Only calibrate if we have valid previous readings and enough time has passed
        if (calibration_count_ > 0 && (now - last_calibration_time_) > 500000) { // 500ms
          // Calculate resistance: R = (V_before - V_now) / (I_now - I_before)
          // Use the stored voltage from before the change
          // Convert current from mA to A for calculation
          float voltage_change = last_voltage_before_change_ - last_voltage_;
          float current_change_a = (current_ma - last_current_estimate_) / 1000.0;
          
          float new_resistance = voltage_change / current_change_a;
          
          // Sanity check: resistance should be between 10mΩ and 500mΩ
          if (new_resistance > 0.01 && new_resistance < 0.5) {
            // Smooth the resistance estimate
            float r_mul = 0.3; // Weight new measurement at 30%
            battery_resistance_ = battery_resistance_ * (1 - r_mul) + new_resistance * r_mul;
            calibration_count_++;
            last_calibration_time_ = now;
          }
        }
        // Store state for next calibration (use current voltage before next change)
        last_voltage_before_change_ = last_voltage_;
      }
      
      last_current_estimate_ = current_ma;
      
      // Calculate load-compensated voltage
      // V_ideal = V_measured + I * R_battery
      // Current in mA, resistance in ohms, so: I(mA) / 1000 * R(ohms)
      float compensation = (current_ma / 1000.0) * battery_resistance_;
      float new_compensated = last_voltage_ + compensation;
      
      // Apply additional smoothing to compensated voltage for stability
      // Use a slower smoothing for the final output to reduce visible fluctuation
      if (last_compensated_update_time_ == 0) {
        last_compensated_update_time_ = now;
        last_voltage_compensated_ = new_compensated;
      } else {
        float comp_mul = expf(logf(BATTERY_VOLTAGE_SMOOTHING) * (now - last_compensated_update_time_) / 1000000.0);
        last_voltage_compensated_ = last_voltage_compensated_ * comp_mul + new_compensated * (1 - comp_mul);
        last_compensated_update_time_ = now;
      }
      
      if (IsLow()) {
        low_count_++;
      } else {
        low_count_ = 0;
      }
    }
    STATE_MACHINE_END();
  }

  bool IsLow() {
#if VERSION_MAJOR >= 4
    if (USBD_Connected()) return false;
#endif
    // Battery isn't low if it's not connected at all.
    if (battery() < 0.5) return false;

    return battery() < (loaded_ ? 2.6 : 3.0);
  }

  bool Parse(const char* cmd, const char* arg) override {
    if (!strcmp(cmd, "battery_voltage")) {
      STDOUT.println(battery());
      return true;
    }
    if (!strcmp(cmd, "batt") || !strcmp(cmd, "battery")) {
      STDOUT.print("Battery voltage: ");
      float v = battery();
      STDOUT.println(v);
#if defined(ENABLE_AUDIO) && !defined(DISABLE_TALKIE)
      talkie.SayDigit((int)floorf(v));
      talkie.Say(spPOINT);
      talkie.SayDigit(((int)floorf(v * 10)) % 10);
      talkie.SayDigit(((int)floorf(v * 100)) % 10);
      talkie.Say(spVOLTS);
#endif
      return true;
    }
    if (!strcmp(cmd, "battery_info")) {
      STDOUT.print("Battery voltage (compensated): ");
      STDOUT.println(battery());
      STDOUT.print("Battery voltage (raw): ");
      STDOUT.println(battery_raw());
      STDOUT.print("Battery resistance (ohms): ");
      STDOUT.println(battery_resistance());
      STDOUT.print("Current estimate (mA): ");
      STDOUT.println(last_current_estimate_);
      STDOUT.print("Calibration count: ");
      STDOUT.println(calibration_count_);
      return true;
    }
#if 0
    if (!strcmp(cmd, "bstate")) {
      STDOUT.print("Next state: ");
      STDOUT.println(reader_.state_machine_.next_state_);
      STDOUT.print("ADC SMP: ");
      STDOUT.println(reader_.adc_smp_);
      STDOUT.print("ADC state: ");
      STDOUT.println(stm32l4_adc.state);
      return true;
    }
#endif
    return false;
  }
private:
  float battery_now() {
    // This is the volts on the battery monitor pin.
    float volts = 3.3 * reader_.Value() / 1024.0;
#if VERSION_MAJOR == 5 || VERSION_MAJOR == 6
    return volts * 2.0;
#else
#ifdef V2
    float pulldown = 220000;  // External pulldown
    float pullup = 2000000;   // External pullup
#else
    float pulldown = 33000;  // Internal pulldown is 33kOhm
    float pullup = BATTERY_PULLUP_OHMS;  // External pullup
#endif
    return volts * (1.0 + pullup / pulldown);
#endif
  }

  bool loaded_ = false;
  float last_voltage_ = 0.0;
  float last_voltage_compensated_ = 0.0;
  float last_voltage_before_change_ = 0.0;
  float last_current_estimate_ = 0.0;
  float battery_resistance_ = 0.1; // Internal resistance in ohms (initial estimate)
  uint32_t last_voltage_read_time_ = 0;
  uint32_t last_compensated_update_time_ = 0;
  uint32_t last_calibration_time_ = 0;
  uint32_t last_print_millis_;
  uint32_t low_count_ = 0;
  uint32_t calibration_count_ = 0;
  AnalogReader reader_;
};

#else  // NO_BATTERY_MONITOR

class BatteryMonitor {
public:
  float battery() const { return 3.7f; }
  void SetLoad(bool on) {}
  bool low() const { return false; }
  float battery_percent() { return 100.0f;  }
  void SetPinHigh(bool go_high) {}
};

#endif  // NO_BATTERY_MONITOR

BatteryMonitor battery_monitor;

#endif  // COMMON_BATTERY_MONITOR_H
