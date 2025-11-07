/*
saber_JJ_buttons.h
  http://fredrik.hubbe.net/lightsaber/proffieos.html
  Copyright (c) 2016-2019 Fredrik Hubinette
  Copyright (c) 2024 Brian Conner with contributions by:
  Fredrik Hubinette, Fernando da Rosa, and Matthew McGeary.
  Distributed under the terms of the GNU General Public License v3.
  http://www.gnu.org/licenses/

====================== CONTROLS ===========================
| Sorted by ON or OFF state: (what it's like while using) |
===========================================================

*************   WHILE SABER BLADE IS OFF   ***************
Start Pre-launch        - Click POWbutton (plays preon.wav)
Turn ON (launch)        - Shake, Thrust, Swing, Stab. (triggered by launch)
Next Preset             - Long click and release POW.
Prev Preset             - Double click and hold POW, release after a second.
                          (click then long click)
Play/Stop Track         - 3x click POW.
Volume Menu:
        Enter/Exit      - Hold POW + Clash.
        Volume UP       - Rotate Right
        Volume DOWN     - Rotate Left
Spoken Battery Level
        in volts        - 4x click POW.
        in percentage   - 4x click and hold POW.

*************   WHILE LAUNCHED (BLADE IS ON)   ****************
Effects (blast)         - Click or Double click POW.
Clash                   - No buttons, just hit against something.
Lockup                  - Hold POW + Clash.
Quote/Force Player      - 3x click POW.
Turn OFF (reset launcer)
*/

#ifndef PROPS_SABER_JJ_BUTTONS_H
#define PROPS_SABER_JJ_BUTTONS_H

#include "prop_base.h"
#include "../sound/hybrid_font.h"

#undef PROP_TYPE
#define PROP_TYPE SaberJJButtons

#ifndef MOTION_TIMEOUT
#define MOTION_TIMEOUT 60 * 15 * 1000
#endif

#ifndef JJ_SWING_ON_SPEED
#define JJ_SWING_ON_SPEED 250
#endif

#ifndef JJ_LOCKUP_DELAY
#define JJ_LOCKUP_DELAY 200
#endif

#ifndef JJ_FORCE_PUSH_LENGTH
#define JJ_FORCE_PUSH_LENGTH 5
#endif

#ifndef BUTTON_DOUBLE_CLICK_TIMEOUT
#define BUTTON_DOUBLE_CLICK_TIMEOUT 300
#endif

#ifndef BUTTON_SHORT_CLICK_TIMEOUT
#define BUTTON_SHORT_CLICK_TIMEOUT 300
#endif

#ifndef BUTTON_HELD_TIMEOUT
#define BUTTON_HELD_TIMEOUT 300
#endif

#ifndef BUTTON_HELD_MEDIUM_TIMEOUT
#define BUTTON_HELD_MEDIUM_TIMEOUT 800
#endif

#ifndef BUTTON_HELD_LONG_TIMEOUT
#define BUTTON_HELD_LONG_TIMEOUT 2000
#endif

#ifdef JJ_SWING_ON
#define SWING_GESTURE
#endif

#ifdef JJ_STAB_ON
#define STAB_GESTURE
#endif

#ifdef JJ_TWIST_ON
#define TWIST_GESTURE
#endif

#ifdef JJ_THRUST_ON
#define THRUST_GESTURE
#endif


EFFECT(battery);    // for EFFECT_BATTERY_LEVEL
EFFECT(vmbegin);    // for Begin Volume Menu
EFFECT(vmend);      // for End Volume Menu
EFFECT(volup);      // for increse volume
EFFECT(voldown);    // for decrease volume
EFFECT(volmin);     // for minimum volume reached
EFFECT(volmax);     // for maximum volume reached
EFFECT(quote);      // for playing quotes


#include "../sound/sound_library.h"

// The Saber class implements the basic states and actions
// for the saber.
class SaberJJButtons : public PROP_INHERIT_PREFIX PropBase {
public:
  SaberJJButtons() : PropBase() {}
  const char* name() override { return "SaberJJButtons"; }
 
  void Loop() override {
    PropBase::Loop();
    DetectTwist();
    DetectMenuTurn();
    DetectShake();
    Vec3 mss = fusor.mss();
    sound_library_.Poll(wav_player);
    if (wav_player && !wav_player->isPlaying()) wav_player.Free();
    if (SaberBase::IsOn()) {
      DetectSwing();
    } else {

    //EVENT_PUSH
      if (fabs(mss.x) < 3.0 &&
          mss.y * mss.y + mss.z * mss.z > 70 &&
          fusor.swing_speed() < 30 &&
          fabs(fusor.gyro().x) < 10) {
        if (millis() - push_begin_millis_ > JJ_FORCE_PUSH_LENGTH) {
          Event(BUTTON_NONE, EVENT_PUSH);
          push_begin_millis_ = millis();
        }
      } else {
        push_begin_millis_ = millis();
      }
    // EVENT_SWING - Swing On gesture control to allow fine tuning of speed needed to ignite
      if (millis() - saber_off_time_ < MOTION_TIMEOUT) {
        SaberBase::RequestMotion();
        if (swinging_ && fusor.swing_speed() < 90) {
          swinging_ = false;
        }
        if (!swinging_ && fusor.swing_speed() > JJ_SWING_ON_SPEED) {
          swinging_ = true;
          Event(BUTTON_NONE, EVENT_SWING);
        }
      }

    // EVENT_THRUST
      if (mss.y * mss.y + mss.z * mss.z < 16.0 &&
          mss.x > 14  &&
          fusor.swing_speed() < 150) {
        if (millis() - thrust_begin_millis_ > 15) {
          Event(BUTTON_NONE, EVENT_THRUST);
          thrust_begin_millis_ = millis();
        }
      } else {
        thrust_begin_millis_ = millis();
      }
    }
  }


// Volume Menu
    void VolumeMenu() {
    if (!mode_volume_) {
      current_menu_angle_ = fusor.angle2();
      mode_volume_ = true;
      if (SFX_vmbegin) {
        sound_library_.SayEnterVolumeMenu();
      } else {
        beeper.Beep(0.1, 1000);
        beeper.Beep(0.1, 2000);
        beeper.Beep(0.1, 3000);
      }
      STDOUT << "Enter Volume Menu\n";
      SaberBase::DoEffect(EFFECT_VOLUME_LEVEL, 0);
    } else {
      mode_volume_ = false;
      if (SFX_vmend) {
        sound_library_.SayVolumeMenuEnd();
      } else {
        beeper.Beep(0.1, 3000);
        beeper.Beep(0.1, 2000);
        beeper.Beep(0.1, 1000);
      }
      STDOUT << "Exit Volume Menu\n";
    }
  }

  void VolumeUp() {
    SaberBase::DoEffect(EFFECT_VOLUME_LEVEL, 0);
    current_menu_angle_ = fusor.angle2();
    if (dynamic_mixer.get_volume() < VOLUME) {
      dynamic_mixer.set_volume(std::min<int>(VOLUME + VOLUME * 0.1,
        dynamic_mixer.get_volume() + VOLUME * 0.10));
      if (SFX_volup) {
        hybrid_font.PlayPolyphonic(&SFX_volup);
      } else {
        beeper.Beep(0.10, 2000);
        beeper.Beep(0.20, 2500);
      }
      STDOUT << "Volume Up - Current Volume: ";
      STDOUT << dynamic_mixer.get_volume() << "\n";
    } else {
      QuickMaxVolume();
    }
  }

  void VolumeDown() {
    SaberBase::DoEffect(EFFECT_VOLUME_LEVEL, 0);
    current_menu_angle_ = fusor.angle2();
    if (dynamic_mixer.get_volume() > (0.10 * VOLUME)) {
      dynamic_mixer.set_volume(std::max<int>(VOLUME * 0.1,
        dynamic_mixer.get_volume() - VOLUME * 0.10));
      if (SFX_voldown) {
        hybrid_font.PlayPolyphonic(&SFX_voldown);
      } else {
        beeper.Beep(0.10, 2000);
        beeper.Beep(0.20, 1500);
      }
      STDOUT << "Volume Down - Current Volume: ";
      STDOUT << dynamic_mixer.get_volume() << "\n";
    } else {
      QuickMinVolume();
    }
  }

  void QuickMaxVolume() {
    SaberBase::DoEffect(EFFECT_VOLUME_LEVEL, 0);
    dynamic_mixer.set_volume(VOLUME);
    if (millis() - volume_range_delay_ > 2000) {
      if (SFX_volmax) {
        hybrid_font.PlayPolyphonic(&SFX_volmax);
      } else {
        beeper.Beep(0.5, 3000);
      }
      STDOUT << "Maximum Volume\n";
      volume_range_delay_ = millis();
    }
  }

  void QuickMinVolume() {
    SaberBase::DoEffect(EFFECT_VOLUME_LEVEL, 0);
    dynamic_mixer.set_volume(std::max<int>(VOLUME * 0.1,
    dynamic_mixer.get_volume() - VOLUME * 0.90));
    if (millis() - volume_range_delay_ > 2000) {
      if (SFX_volmin) {
        hybrid_font.PlayPolyphonic(&SFX_volmin);
      } else {
        beeper.Beep(0.5, 1000);
      }
      STDOUT << "Minimum Volume\n";
      volume_range_delay_ = millis();
    }
  }

  void DetectMenuTurn() {
    float a = fusor.angle2() - current_menu_angle_;
    if (a > M_PI) a-=M_PI*2;
    if (a < -M_PI) a+=M_PI*2;
    if (mode_volume_) {
      if (a > M_PI / 6) VolumeUp();
      if (a < -M_PI / 6) VolumeDown();
    }
  }


  RefPtr<BufferedWavPlayer> wav_player;

  bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
    switch (EVENTID(button, event, modifiers)) {
      // storage of unused cases
      case EVENTID(BUTTON_AUX, EVENT_PRESSED, MODE_ON):
      case EVENTID(BUTTON_AUX2, EVENT_PRESSED, MODE_ON):
      return true;

// Gesture Ignition Controls

    case EVENTID(BUTTON_NONE, EVENT_SWING, MODE_OFF):
    case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_OFF):
    case EVENTID(BUTTON_NONE, EVENT_THRUST, MODE_OFF):
    case EVENTID(BUTTON_NONE, EVENT_PUSH, MODE_ON):
      // Delay ignition at boot
      if (millis() - saber_off_time_ > 1000) {
        // No power on without exiting Vol Menu first
        if (!mode_volume_) {
          RefPtr<BufferedWavPlayer> tmp = GetWavPlayerPlaying(&SFX_preon);
            if (tmp) {
              tmp->set_fade_time(0.001);
              tmp->FadeAndStop();
            }
          FastOn();
        }
      }
      return true;

// Next Preset
    case EVENTID(BUTTON_POWER, EVENT_FIRST_CLICK_LONG, MODE_OFF):
      if (!mode_volume_) {
        next_preset();
      }
      return true;

// Previous Preset AND Volume Down
    case EVENTID(BUTTON_POWER, EVENT_SECOND_CLICK_LONG, MODE_OFF):
      if (!mode_volume_) {
        previous_preset();
      }
      return true;

// Start or Stop Track
    case EVENTID(BUTTON_POWER, EVENT_THIRD_SAVED_CLICK_SHORT, MODE_OFF):
      if (!mode_volume_) {
        StartOrStopTrack();
      }
      return true;

// Enter / Exit Volume MENU
    case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_OFF | BUTTON_POWER):
       VolumeMenu();
      return true;

// Spoken Battery Level in volts
    case EVENTID(BUTTON_POWER, EVENT_FOURTH_SAVED_CLICK_SHORT, MODE_OFF):
      if (!mode_volume_) {
        sound_library_.SayTheBatteryLevelIs();
        sound_library_.SayNumber(battery_monitor.battery(), SAY_DECIMAL);
        sound_library_.SayVolts();
        STDOUT<< "Battery Voltage: " << battery_monitor.battery() << "\n";
        SaberBase::DoEffect(EFFECT_BATTERY_LEVEL, 0);
      }
      return true;

// Spoken Battery Level in percentage
    case EVENTID(BUTTON_POWER, EVENT_FOURTH_HELD, MODE_OFF):
      if (!mode_volume_) {
        sound_library_.SayTheBatteryLevelIs();
        sound_library_.SayNumber(battery_monitor.battery_percent(), SAY_WHOLE);
        sound_library_.SayPercent();
        STDOUT<< "Battery Percentage: " <<battery_monitor.battery_percent() << "%\n";
        SaberBase::DoEffect(EFFECT_BATTERY_LEVEL, 0);
      }
      return true;

// Blaster Deflection (trigger effects)
    case EVENTID(BUTTON_POWER, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_ON):
    case EVENTID(BUTTON_POWER, EVENT_SECOND_SAVED_CLICK_SHORT, MODE_ON):
      SaberBase::DoBlast();
      return true;

// Lockup
    case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_POWER):
      if (!SaberBase::Lockup()) {
        SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
        SaberBase::DoBeginLockup();
        return true;
      }

// Quote
    case EVENTID(BUTTON_POWER, EVENT_THIRD_SAVED_CLICK_SHORT, MODE_ON):
        if (SFX_quote) {
          SaberBase::DoEffect(EFFECT_QUOTE, 0);
        } else {
          SaberBase::DoForce();
        }
      return true;

// Turn Blade OFF (Reset for launch)
    case EVENTID(BUTTON_POWER, EVENT_FIRST_HELD_MEDIUM, MODE_ON):
      if (!SaberBase::Lockup()) {
        Off();
      }
      return true;

// Preon (prep for launch via gesture)
    case EVENTID(BUTTON_NONE, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_OFF):
      SaberBase::DoEffect(EFFECT_PREON, 0);
      return true;

// Blade Detect (for future use if desired)
  #ifdef BLADE_DETECT_PIN
    case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_ON, MODE_ANY_BUTTON | MODE_ON):
    case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_ON, MODE_ANY_BUTTON | MODE_OFF):
      blade_detected_ = true;
      FindBladeAgain();
      SaberBase::DoBladeDetect(true);
      return true;

    case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_OFF, MODE_ANY_BUTTON | MODE_ON):
    case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_OFF, MODE_ANY_BUTTON | MODE_OFF):
      blade_detected_ = false;
      FindBladeAgain();
      SaberBase::DoBladeDetect(false);
      return true;
  #endif

// Events that needs to be handled regardless of what other buttons are pressed.
    case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_OFF):
    case EVENTID(BUTTON_AUX, EVENT_PRESSED, MODE_OFF):
    case EVENTID(BUTTON_AUX2, EVENT_PRESSED, MODE_OFF):
      SaberBase::RequestMotion();
      return true;

    case EVENTID(BUTTON_POWER, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
    case EVENTID(BUTTON_AUX, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
    case EVENTID(BUTTON_AUX2, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
      if (SaberBase::Lockup()) {
        SaberBase::DoEndLockup();
        SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
        return true;
      }
    }
    return false;
  }

  void SB_Effect(EffectType effect, float location) override {
    switch (effect) {
      case EFFECT_QUOTE: hybrid_font.PlayCommon(&SFX_quote); return;
   }
  }

private:
  // bool pointing_down_ = false;
  bool mode_volume_ = false;
  bool max_vol_reached_ = false;
  bool min_vol_reached_ = false;
  float current_menu_angle_ = 0.0;

  uint32_t thrust_begin_millis_ = millis();
  uint32_t push_begin_millis_ = millis();
  uint32_t clash_impact_millis_ = millis();
  uint32_t saber_off_time_ = millis();
  uint32_t volume_range_delay_ = millis();


};

#endif
