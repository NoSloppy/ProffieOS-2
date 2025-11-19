/*
What to expect:
The test script will test capacitors and should report "CAP: OK".
Pullup/pulldown resistors will check BLADE ID reading reporting "ID: N" where N is the resistor value. ??? It should be something close to 35000 ???
The script will cycle through the LED1-6 and data1-4 pads 1:1 in sequence
and light up the yellow diagnostic LEDs. Step 5 and 6 of the sequence should 
also light TX and RX repectively. (1.5 boatd, Data5 will follow these)
Data5, SDA, SCL, and 5V should be lit solid.
Data2 should be lit but not full. (why??)
Any LED1-6 or data1-4 LED not lighting or staying lit indicates a problem.
The speaker should play spoken prompts to test buttons.

Preparations to use the test script:
1. Edit ProffieOS.ino. Define the CONFIG_FILE to use proffieboard_test_bench_config.h and upload.
2. Take a sip.
3. Put TestRig font on the SD card.
4. Set up a multimeter to beep on short (continuity mode).
  - Check BATT+ against all other pads.
  - Attach the leads to one of the pairs of power inputs on the breakout board and make sure there's 
    no beep when putting the board on the test bed pins.
5. Start up Arduino
6. Choose the Proffieboard in menu Tools>Port.
7. Open Serial Monitor
8. On the breakout board, populate all jumpers except LED1->PXL and "PXL"
9. Upload

For each board:
*** Make sure Multimeter power is on and in beep mode. ***
***Make sure battery power is off and USB disconnected ***
1. Insert SD card, put board on tester, and plug in USB.
  - Upload to the board with the settings above.
  - Verify OLED shows ProffieOS startup screen.
  - boot.wav should be heard.
  - If you hear a beep from the multimeter, stop now and do NOT turn on battery power.
  - If you hear beeps from the board itself, check serial monitor for errors.

2. Watch Serial Monitor and make sure the "Welcome to ProffieOS" message pops up.
  - Make sure there are no motion related errors.
  - Capacitors test should report "CAP: OK"
  - Blade ID test should report info. Note the USB-only power will skew these value for now.
  - It should say "Waiting for battery power" repeatedly, no beeps.
3. Press the RESET button, should repeat step 2 results
4. Switch on battery power.
  - Verify OLED displays Battery Meter PLI.
  - Blade ID test should report info again, this time with correct values.
  - You should hear "Press the BOOT button".
5. Press the BOOT button.
  - You should hear "Press POWER button".
8. Press the Power button. (button closest to speaker connector)
  - You should hear "Press AUXILIARY button".
9. Press the AUX button. (button farthest from speaker connector)
  - You should hear "Press second AUXILIARY button".
10. Press the AUX2 button. (middle button)
  - You should hear "Check lights sequence and music"
11. Verify that LEDs light up in order.
  - LED1-6 should light up in order.
  - DATA2 should glow dimly (why??)
  - DATA1, DATA3, DATA4 should light up in order.
  - RX and TX are reverse order.(1.5 boatd, Data5 will follow these)
  - Data5, SDA, SCL, and 5V should be lit solid.
12. Verify that music is playing.
13. Type n in Serial Monitor and hit send (press enter).
  - font.wav should play.
  - Verify OLED says TestRig then shows a test pattern loop.
14. Verify tapping board triggers an EVENT: Clash in Serial Monitor.
15. Switch off battery power then remove USB.
16. Confirm no power before removing board from tester pins.

Optional: 
*Note* The following is for using the test rig and proffieboard_v2_test_bench_config file and presets without running the script test.
This can be useful for just testing blade styles and button actions of a prop file etc...
The following lines in the test bench config file should be commented out for this type of use:


Onboard 10 pixels can act as data1/LED1 blade showing a blade style fom the 
config with jumpers placed on "LED1-PXL" and D1's PXL pins on the breakout test board.
Additional external blades can be patched to the breakout board jumpers.(LED- and data) such as the mini strip on testbed.
Any connected blades (including onboard pixels as data1/LED1 blade)
will flash in sync with the diagnostic sequence, showing the blade style assigned to them.
The default blade colors assigned in order data1->data4 are Red, Green, Blue, Yellow.
Any blades declared in the BladeConfig that are not actually hooked up will be reported as a short on that pin (expected).
Edit proffieboard_v2_test_bench_config.h:
  - Set NUM_BLADES accordingly if more than the 1 blade of onboard pixels are used.
  - Edit pixel counts in the blades[] array accordingly for additional external blades.
  - The following lines in the test bench config file should be commented out for this type of use:

 // #ifdef CONFIG_BUTTONS

// #include "../scripts/proffieboard_test_script.h"
// #warning !!! PROFFIEBOARD TEST SCRIPT ACTIVE !!!
// V4TestScript script;
// Blinker1 blinker1;
// Blinker2 blinker2;
// CapTest captest;
// #endif  // CONFIG_BUTTONS 

and the regular saber or dual prop buttons shoud be UNcommented

#ifdef CONFIG_BUTTONS

// For saber or dual_prop:
#if 0
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
Button Aux2Button(BUTTON_AUX2, aux2Pin, "aux2");
//Button Clip(BUTTON_CLIP_DETECT, aux2Pin, "clip");
#endif

______ alternately, test with BlankTestORIG.h for normal saber behavior, check with loose leads from stripLEDs to test @LED and data jumpers.

*/

// FREDRIK OFFICIAL VERSION

/*
Preparations to use the test script:
1. Edit ProffieOS.ino. Define the CONFIG_FILE to use proffieboard_v2_testing_config.h
2. Use the default ProffieOS SD card.
  - https://fredrik.hubbe.net/lightsaber/sound.html
3. Set up a multimeter to beep on short (continuity mode).
  - Check BATT+ against all other pads.
  - Attach the leads to one of the power inputs on the breakout board and make sure there's 
    no beep when putting the board on the test bed pins.
4. Start up Arduino
5. Choose the Proffieboard in menu Tools>Port.
6. Open Serial Monitor
7. Open up OpenOCD or ST-link utility and run it while testing.
8. On the breakout board, populate all jumpers except LED1->PXL and "PXL"

For each board:
1. Make sure power switch is on the Multimeter, and that the multimeter is still on and in beep mode.
2. Insert SD card, put board on tester, and plug in USB.
  - boot.wav should be heard.
  - If you hear a beep from the multimeter, stop now and do NOT turn on battery power.
  - If you hear beeps from the board itself, check serial monitor for errors.
3. Press reset button.
  - Same thing should happen as in previous step
4. Check OpenOCD/St-link to make sure that SWDIO pins are working.
5. Check Serial Monitor and verify that the board connects.
  - Also make sure there are no motion related errors.
6. Switch on battery power.
  - You should hear "press boot button"
7. Press the BOOT button.
  - You should hear "press power button"
8. Press the Power button (button closest to speaker connector)
  - You should hear "press A-U-X button"
9. Press the AUX button (button farthest from speaker connector)
  - You should hear "press second A-U-X button"
10. Press the AUX2 button (middle button)
  - You should hear "check lights"
11. Verify that LEDs light up in order.
  - LED1-6 should light up in order.
  - DATA1 should glow dimly
  - DATA2, DATA3, DATA4, RX and TX should light up in order.
  - Data5, SDA, SCL, and 5V should be lit solid.
12. Verify that music is playing.
13. Switch off battery power then remove USB.

Troubleshooting:

If you get beeps in the beginning, you might have left the power on.
If you get beeps when turning on battery power, then the 5v booster might not be working correctly, or PU/PD jumpers are not populated.
If you see CAP FAIL, then the touch capacitor is not working properly.
If motion is not working, you'll see "motion timeout" errors in the serial monitor.

*/

#ifndef SCRIPTS_PROFFIEBOARD_TEST_SCRIPT_H
#define SCRIPTS_PROFFIEBOARD_TEST_SCRIPT_H

#ifndef TEENSYDUINO

enum class PinState {
  Unknown,
  Unconnected,
  InputPullup,
  LowOrInput,
};

class V4ShortChecker : Looper, StateMachine {
public:
  V4ShortChecker() : Looper(), StateMachine() {
    for (size_t i = 0; i < NELEM(pins_); i++) pins_[i] = PinState::Unknown;
  }
  void SetPinState(int pin, PinState state) {
    pins_[pin] = state;
  }
  const char* name() override { return "ShortChecker"; }
  void fail(const char* error) {
    STDOUT.print("Short on pin ");
    STDOUT.print(current_pin);
    STDOUT.print(" ");
    STDOUT.println(error);
    fail_ = true;
  }
  void Loop() override {
    STATE_MACHINE_BEGIN();
    while(1) {
      for (current_pin = 0; current_pin < NELEM(pins_); current_pin++) {
	switch (pins_[current_pin]) {
	  case PinState::Unknown: // Do nothing
	    break;
	  case PinState::Unconnected:
	    pinMode(current_pin, INPUT_PULLUP);
	    delayMicroseconds(10);
	    if (digitalRead(current_pin) != HIGH)
	      fail("expected high with pullup");
	    // fall through
	  case PinState::LowOrInput:
	    pinMode(current_pin, INPUT_PULLDOWN);
	    delayMicroseconds(10);
	    if (digitalRead(current_pin) != LOW)
	      fail("expected low with pulldown");
	    break;
	  case PinState::InputPullup:
	    pinMode(current_pin, INPUT_PULLDOWN);
	    delayMicroseconds(10);
	    if (digitalRead(current_pin) != LOW)
	      fail("expected low with pulldown");
	    pinMode(current_pin, INPUT_PULLUP);
	    delayMicroseconds(10);
	    if (digitalRead(current_pin) != HIGH)
	      fail("expected high with pullup");
	    break;
	}
	if (fail_) {
	  beeper.Beep(0.5, 900.0);
	  SLEEP(300);
	  // beeper.Beep(0.5, 500.0);
	  // SLEEP(300);
	  // beeper.Beep(0.5, 900.0);
	  // SLEEP(300);
	  fail_ = false;
	}
	SLEEP_MICROS(100);
      }
    }
    STATE_MACHINE_END();
  }
private:
  bool fail_ = false;
  size_t current_pin;
  PinState pins_[40];
};

V4ShortChecker short_checker;

class V4TestScript : Looper, StateMachine {
public:
  const char* name() override { return "Script"; }
  void Loop() override {
    STATE_MACHINE_BEGIN();
    while (millis() < 5000) {
      STDOUT.println("Waiting for Serial Monitor to catch up");
      SLEEP(1000);
    }
    short_checker.SetPinState(powerButtonPin, PinState::InputPullup);
    short_checker.SetPinState(auxPin, PinState::InputPullup);
    short_checker.SetPinState(aux2Pin, PinState::InputPullup);
    if (prop.id() > 22687.0f) {
      STDOUT.println("ID is wrong, should be zero at first!!!");
      beeper.Beep(0.5, 500.0);
      SLEEP(300);
      beeper.Beep(0.5, 900.0);
      SLEEP(300);
      beeper.Beep(0.5, 500.0);
      SLEEP(300);
    }
    while (battery_monitor.battery() < 3.5) {
      STDOUT.println(" Waiting for battery power");
      SLEEP(3000);
    }
    STDOUT.println(" Battery found.");
    EnableBooster();
    STDOUT.println(" Booster enabled.");
    dynamic_mixer.set_volume(700);
    STDOUT.println(" Volume set to 700.");
    SLEEP(100);
    if (fabsf(prop.id() - 110000.0f) > 22687.0f) {
      STDOUT.println("ID IS WRONG (want 2.5 volts)!!!");
      beeper.Beep(0.5, 1100.0);
      SLEEP(300);
      beeper.Beep(0.5, 800.0);
      SLEEP(300);
      beeper.Beep(0.5, 500.0);
      SLEEP(300);
    }
    talkie.Say(spPRESS);
    talkie.Say(spTHE);
    talkie.Say(spBOOT);
    talkie.Say(spBUTTON);
    stm32l4_gpio_pin_configure(GPIO_PIN_PH3,   (GPIO_PUPD_PULLDOWN | GPIO_OSPEED_HIGH | GPIO_MODE_INPUT));
    SLEEP(300);
    while (!stm32l4_gpio_pin_read(GPIO_PIN_PH3)) YIELD();
    short_checker.SetPinState(powerButtonPin, PinState::Unknown);
    talkie.Say(spPRESS);
    talkie.Say(spPOWER);
    talkie.Say(spBUTTON);
    talkie.Say(spONE);
    SLEEP(50);
    while (digitalRead(powerButtonPin) == HIGH) YIELD();
    SLEEP(50); // Debounce
    while (digitalRead(powerButtonPin) == LOW) YIELD();
    SLEEP(50); // Debounce
    short_checker.SetPinState(powerButtonPin, PinState::InputPullup);
    short_checker.SetPinState(auxPin, PinState::Unknown);
    talkie.Say(spPRESS);
    talkie.Say(spAUXILIARY);
    talkie.Say(spBUTTON);
    talkie.Say(spTWO);
    SLEEP(50);
    while (digitalRead(auxPin) == HIGH) YIELD();
    SLEEP(50);
    while (digitalRead(auxPin) == LOW) YIELD();
    SLEEP(50);
    short_checker.SetPinState(auxPin, PinState::InputPullup);
    short_checker.SetPinState(aux2Pin, PinState::Unknown);
    talkie.Say(spPRESS);
    talkie.Say(spSECONDS);
    talkie.Say(spAUXILIARY);
    talkie.Say(spBUTTON);
    talkie.Say(spTHREE);
    SLEEP(50);
    while (digitalRead(aux2Pin) == HIGH) YIELD();
    SLEEP(50);
    while (digitalRead(aux2Pin) == LOW) YIELD();
    SLEEP(50);
    short_checker.SetPinState(aux2Pin, PinState::InputPullup);
    CommandParser::DoParse("play", "TestRig/tracks/mars.wav");

    talkie.Say(spCHECK);
    talkie.Say(spLIGHTS);
    talkie.Say(spSEQUENCE);
    talkie.Say(spAND);
    talkie.Say(spMUSIC);
    SLEEP(12000);
    talkie.Say(spENTER);
    SLEEP(50);
    talkie.Say(spN);
    talkie.Say(spAND);    
    talkie.Say(spCHECK);
    talkie.Say(spDISPLAY);

    STATE_MACHINE_END();
  }
};

class Blinker1 : Looper, StateMachine {
public:
  const char* name() override { return "Blinker1"; }
  void Loop() override {
    STATE_MACHINE_BEGIN();
    while (true) {
#define TESTPIN2(X, DEFAULT_STATE) do {			\
    short_checker.SetPinState(X, PinState::Unknown);	\
    pinMode(X, OUTPUT);					\
    digitalWrite(X, HIGH);				\
    SLEEP(200);						\
    digitalWrite(X, LOW);				\
    short_checker.SetPinState(X, DEFAULT_STATE); \
  } while(0);

#define TESTPIN(X) TESTPIN2(X, PinState::LowOrInput)      

      TESTPIN(bladePowerPin1);
      TESTPIN(bladePowerPin2);
      TESTPIN(bladePowerPin3);
      TESTPIN(bladePowerPin4);
      TESTPIN(bladePowerPin5);
      TESTPIN(bladePowerPin6);
    }
    STATE_MACHINE_END();
  }
};

class Blinker2 : Looper, StateMachine {
public:
  const char* name() override { return "Blinker2"; }
  void Loop() override {
    STATE_MACHINE_BEGIN();
    while (true) {
      TESTPIN2(bladePin, PinState::Unknown); // hooked up to 10k voltage divider
      TESTPIN2(blade2Pin, PinState::Unknown); // hooked up to neopixels
      TESTPIN(blade3Pin);
      TESTPIN(blade4Pin);
#if VERSION_MAJOR == 4      
      TESTPIN(blade7Pin);
#endif
      TESTPIN(blade6Pin);
      TESTPIN(blade5Pin);
    }
    STATE_MACHINE_END();
  }
};

class CapTest : Looper, StateMachine {
public:
  const char* name() override { return "CapTest"; }
  void Loop() override {
    STATE_MACHINE_BEGIN();
    while (true) {
      pinMode(20, INPUT_PULLDOWN);
      SLEEP(100);
      pinMode(20, INPUT_PULLUP);
      last_eq_ = start_ = micros();
      first_ne_ = start_ + 10000;
      while (true) {
      	if (digitalRead(20) == LOW) {
      	  last_eq_ = micros();
      	  if (last_eq_ - start_ > 10000) break;
      	} else {
      	  first_ne_ = micros();
      	  break;
      	}
      	YIELD();
      }

      if (first_ne_ - start_ < 2000 || last_eq_ - start_ > 6000) {
        STDOUT.print("CAP FAIL LOW-HIGH! ");
        STDOUT.print(last_eq_ - start_);
        STDOUT.print(" ");
        STDOUT.println(first_ne_ - start_);
        loops_ = 10000;
        beeper.Beep(0.5, 500.0);
        SLEEP(300);
        beeper.Beep(0.5, 500.0);
        SLEEP(300);
        beeper.Beep(0.5, 900.0);
        SLEEP(300);
      }

      SLEEP(100);
      pinMode(20, INPUT_PULLDOWN);
      last_eq_ = start_ = micros();
      first_ne_ = start_ + 10000;
      while (true) {
      	if (digitalRead(20) == HIGH) {
      	  last_eq_ = micros();
      	  if (last_eq_ - start_ > 10000) break;
      	} else {
      	  first_ne_ = micros();
      	  break;
      	}
      	YIELD();
      }

      if (first_ne_ - start_ < 2000 || last_eq_ - start_ > 6000) {
        STDOUT.print("CAP FAIL HIGH-LOW! ");
        STDOUT.print(last_eq_ - start_);
        STDOUT.print(" ");
        STDOUT.println(first_ne_ - start_);
        loops_ = 10000;
        beeper.Beep(0.5, 500.0);
        SLEEP(300);
        beeper.Beep(0.5, 500.0);
        SLEEP(300);
        beeper.Beep(0.5, 900.0);
        SLEEP(300);
      }
      if (loops_++ == 20) {
        STDOUT.println("Cap OK");
      }
    }
    STATE_MACHINE_END();
  }
  void Run() {
    state_machine_.reset_state_machine();
  }
  int loops_ = 0;
  uint32_t start_, last_eq_, first_ne_;
};


#endif  // not TEENSYDUINO
#endif
