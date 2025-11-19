/*
saber_WS_buttons.h
  http://fredrik.hubbe.net/lightsaber/proffieos.html
  Copyright (c) 2016-2023 Fredrik Hubinette
  Copyright (c) 2023 Russell Mitchem with contributions by Brian Conner,
  Fredrik Hubinette, Fernando da Rosa, Matthew McGeary, and Scott Weber.
  Distributed under the terms of the GNU General Public License v3.
  http://www.gnu.org/licenses/

Includes 1 and 2 button controls.

Best if used with OS6 ProffieOS_Voicepack spoken menu prompts.
Download your choice of language and variation here:
http://fredrik.hubbe.net/lightsaber/sound/
Also, a large variety of FREE in-universe character Voicepacks available here:
https://crucible.hubbe.net/t/additional-voicepacks/4227
If you'd care to make a donation for Brian's time, a coffee would be nice!
https://www.buymeacoffee.com/brianconner

"Battle Mode 1.0" by fett263, BC modified version:
- Once you enter battle mode, buttons are not used for lockup.
  Clashing the blade against something will automatically do lockup and then end
  when you pull away.
- Automatic lockup and grazing clash (swinging through) detection works
  by measuring delay of the saber blade pulling back from the clash.
  If you clash the blade and it does not pull back during the delay period,
  it is assumed to be a lockup and the lockup effect will show on the blade.
  If you clash the blade and pull away, only the bgn/end lockup effects will show.
  You can adjust the threshold of this detection by using:
#define WS_LOCKUP_DELAY (insert number here)
  Default value is 200.
  If you don't rebound off the object (opponent's blade) but instead clash while
  swinging through, clash will automatically trigger.
- To manually override the auto-lockup temporarily and get a regular clash,
  hold any button while clashing.
- Automatic clash/lockup uses the bgnlock and endlock effects
  so your blade style and font MUST have those capabilities to support
  battle mode.

-----------------------------------------------
Optional defines for Gesture Controls:

    Add any of the following to the config to enable the various gestures.
    *Note* - Using a gesture ignition will intentionally skip the preon effect.

#define WS_SWING_ON
#define WS_SWING_ON_SPEED 250        // Adjust swing speed required to ignite with swing.
#define WS_SWING_ON_AUTO_BATTLE_MODE // Makes SWING_ON gesture ignition ALSO enter battle mode automatically on ignition.
#define WS_TWIST_ON
#define WS_TWIST_OFF
#define WS_THRUST_ON
#define WS_ROTATE_TO_CHANGE_PRESET   // Enables change preset while blade is ON by Rotating while pointing down.
#define WS_ROTATE_TO_CHANGE_VOLUME   // Enables Volume Menu rotate option.
#define WS_AUTO_SWING_BLAST          // Auto enter/exit multi-blast block with swings if swing within 1 second.
#define WS_LOCKUP_DELAY 200          // See above (adjust number to taste)

************** 1 Button Controls **************

=============== While OFF or ON ===============
Turn blade ON and OFF ------- Short click button 
                      ------- Twist on/off
                      ------- Swing on
*defines must be enabled - see above options

================== While OFF ==================
Play/Stop Music ------------- Triple click button fast.
Next Preset ----------------- Hold button 1 second and release.
Previous Preset ------------- Hold button and wait.
Enter / Exit Volume Menu ---- Hold button + Clash.
    Volume Up --------------- Short click button or Rotate hilt Right.
    Volume Down ------------- Hold button or Rotate hilt Left.
Battery Level --------------- Double click + Hold button.

================== While ON ===================
Clash ----------------------- Clash the saber.
Blaster Blocks -------------- Double click button.
Auto Swing Blaster Blocks---- If #define WS_AUTO_SWING_BLAST is active,
                              swinging within 1 second of doing a button activated
                              Blaster Block will start this timed mode.
                              To trigger auto blaster blocks, swing saber
                              within 1 second of last Swing Blast block.
                              To exit, stop swinging for 1 second.

Lockup ---------------------- Hold button + Clash.
Drag ------------------------ Hold button + Clash while pointing down.
Melt ------------------------ Hold button.
Stab ------------------------ Stab something. Triggered by forward thrust with an impact.
Lightning Block ------------- Double click + Hold button.
Battle Mode------------------ Use SWING_ON gesture ignition (requires #define, see above)
    Power off blade to exit battle mode, normal ignition to not use.
Enter Color Change mode ----- Hold button 1 second and release
    If RotateColorsX<Variation,COLOR> is used in the blade style,
      Rotate hilt to cycle through all available colors, 
      Hold POW to save color selection and exit.
    If ColorChange<> is used in the blade style, entering Color Change Mode 
      will simply select the next color in the list and exit Color Change Mode.
    Double click POWER to cancel Color Change and restore original config color.

Next Preset Fast ------------ Hold button and Rotate hilt Right while pointing down.
Previous Preset Fast -------- Hold button and Rotate hilt Left  while pointing down.
    *Note - require #define WS_ROTATE_TO_CHANGE_PRESET

************** 2 Buttons Controls *************

=============== While OFF or ON ===============
Turn blade ON and OFF ------- Short click POWER 
Gestures if defined. (see Optional Defines above)
Twist Blade On and OFF

================== While OFF ==================
Play/Stop Music ------------- Press power and then release.
Next Preset ----------------- Short click AUX button.
Previous Preset ------------- Hold POWER.
Enter Volume Menu ----------- Press AUX then release.
    Volume Up --------------- Short click POWER or Rotate hilt Right.
    Volume Down ------------- Short click AUX or Rotate hilt Left.
Exit Volume Menu ------------ Press AUX then release.    
Battery level --------------- Hold AUX button.

================== While ON ===================
Clash ----------------------- Clash the saber.
Blaster Blocks -------------- Short click AUX button.
Auto Swing Blaster Blocks---- If #define WS_AUTO_SWING_BLAST is active,
                              swinging within 1 second of doing a button activated
                              Blaster Block will start this timed mode.
                              To trigger auto blaster blocks, swing saber
                              within 1 second of last Swing Blast block.
                              To exit, stop swinging for 1 second.
Lockup ---------------------- Hold AUX button.
Drag ------------------------ Hold AUX button while pointing the blade tip down.
Melt ------------------------ Hold POWER button.
Stab ------------------------ Stab something. Triggered by forward thrust with an impact.
Force Effect----------------- Double Click Aux button. 
Lightning Block ------------- Double Click POWER button and hold. 
Battle Mode------------------ Use SWING_ON gesture ignition (requires #define, see above)
    Power off blade to exit battle mode, normal ignition to not use.
Enter Color Change mode ----- Hold AUX and click POWER,
    If RotateColorsX<Variation,COLOR> is used in the blade style:
        Rotate hilt to cycle through all available colors, 
        Hold POW to save color selection and exit.
    If ColorChange<> is used in the blade style:
        There are up to 12 colors per rotation with a ccchange.wav sound at each step.
        If also using #define COLOR_CHANGE_DIRECT in the config,
        simply entering Color Change Mode will select the next color in the list and exit Color Change Mode.
    Click AUX to cancel Color Change and restore original config color.
Play/Stop Music ------------- Press POWER then release.
Next Preset Fast ------------ Hold POWER and Rotate hilt Right.
Previous Preset Fast -------- Hold POWER and Rotate hilt Left.
    *Note - require #define WS_ROTATE_TO_CHANGE_PRESET



CUSTOM SOUNDS SUPPORTED (add to font to enable):

On Demand Battery Level ----- battery.wav
Enter Volume Menu ----------- vmbegin.wav
Exit Volume Menu ------------ vmend.wav
Volume up ------------------- volup.wav
Volume Down ----------------- voldown.wav
Maximum Volume -------------- volmax.wav
Minimum Volume -------------- volmin.wav
Force Push ------------------ push.wav
Fast On (optional) ---------- faston.wav (*note - faston.wav to be depricated soon. Use fastout.wav instead)
*/


#ifndef PROPS_SABER_WS_BUTTONS_H
#define PROPS_SABER_WS_BUTTONS_H

#include "prop_base.h"
#include "../sound/hybrid_font.h"

#undef PROP_TYPE
#define PROP_TYPE SaberWSButtons

#ifndef MOTION_TIMEOUT
#define MOTION_TIMEOUT 60 * 5 * 1000
#endif

#ifndef WS_SWING_ON_SPEED
#define WS_SWING_ON_SPEED 250
#endif

#ifndef WS_LOCKUP_DELAY
#define WS_LOCKUP_DELAY 200
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

#ifdef WS_SWING_ON
#define SWING_GESTURE
#endif

#ifdef WS_TWIST_ON
#define TWIST_GESTURE
#endif

#ifdef WS_THRUST_ON
#define THRUST_GESTURE
#endif


EFFECT(dim);        // for EFFECT_POWERSAVE
EFFECT(battery);    // for EFFECT_BATTERY_LEVEL
EFFECT(vmbegin);    // for Begin Volume Menu
EFFECT(vmend);      // for End Volume Menu
EFFECT(volup);      // for increse volume
EFFECT(voldown);    // for decrease volume
EFFECT(volmin);     // for minimum volume reached
EFFECT(volmax);     // for maximum volume reached
EFFECT(quote);      // for playing quotes
EFFECT(faston);     // for EFFECT_FAST_ON
                    // *note* faston.wav does not replace out.wav.
                    // they play layered and concurrently.

#include "../sound/sound_library.h"

class SaberWSButtons : public PROP_INHERIT_PREFIX PropBase {
public:
  SaberWSButtons() : PropBase() {}
  const char* name() override { return "SaberWSButtons"; }

BLADE_ID_CLASS_INTERNAL blade_id;
  void Loop() override {
    PropBase::Loop();
    DetectMenuTurn();
    DetectTwist();

    Vec3 mss = fusor.mss();
    sound_library_.Poll(wav_player);
    if (wav_player && !wav_player->isPlaying()) wav_player.Free();

    if (SaberBase::IsOn()) {
      DetectSwing();
      if (auto_lockup_on_ &&
          !swinging_ &&
          fusor.swing_speed() > 120 &&
          millis() - clash_impact_millis_ > WS_LOCKUP_DELAY &&
          SaberBase::Lockup()) {
        SaberBase::DoEndLockup();
        SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
        auto_lockup_on_ = false;
      }
    } else {
    // EVENT_SWING - Swing On gesture control to allow fine tuning of speed needed to ignite
      if (millis() - saber_off_time_ < MOTION_TIMEOUT) {
        SaberBase::RequestMotion();
        if (swinging_ && fusor.swing_speed() < 90) {
          swinging_ = false;
        }
        if (!swinging_ && fusor.swing_speed() > WS_SWING_ON_SPEED) {
          swinging_ = true;
          Event(BUTTON_NONE, EVENT_SWING);
        }
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

  void DetectMenuTurn() {
    float a = fusor.angle2() - current_menu_angle_;
    if (a > M_PI) a-=M_PI*2;
    if (a < -M_PI) a+=M_PI*2;
#ifdef WS_ROTATE_TO_CHANGE_VOLUME
    if (mode_volume_) {
      if (a > M_PI / 6) VolumeUp();
      if (a < -M_PI / 6) VolumeDown();
    }
#endif
//     if (a > M_PI / 4 * 2/3) {    // original angle ( ??) Very tight.
//    if (a > M_PI / 6) {    // 30 degrees to the Right
   if (a > 2 * M_PI / 9) {    // 40 degrees to the Right
//    if (a > 5 * M_PI / 18) {    // 50 degrees to the Right
//    if (a > M_PI / 3) {    // 60 degrees to the Right
//    if (a > 7 * M_PI / 18) {    // 70 degrees to the Right
//    if (a > 4 * M_PI / 9) {    // 80 degrees to the Right
//    if (a > M_PI / 2) {    // 90 degrees to the Right
      Event(BUTTON_NONE, EVENT_TWIST_RIGHT);
      STDOUT << "TWIST RIGHT\n";
      current_menu_angle_ = fusor.angle2();
    }
    // if (a < -M_PI / 4 * 2/3) {    // original angle ( ??) Very tight.
//    if (a < -M_PI / 6) {    // 30 degrees to the Left
    if (a < -2 * M_PI / 9) {    // 40 degrees to the Left
//    if (a < -5 * M_PI / 18) {    // 50 degrees to the Left
//    if (a < -M_PI / 3) {    // 60 degrees to the Left
//    if (a < -7 * M_PI / 18) {    // 70 degrees to the Left
//    if (a < -4 * M_PI / 9) {    // 80 degrees to the Left
//    if (a < -M_PI / 2) {    // 90 degrees to the Left

      Event(BUTTON_NONE, EVENT_TWIST_LEFT);
      STDOUT << "TWIST LEFT\n";
      current_menu_angle_ = fusor.angle2();
    }
  }

// Revert colorchange witout saving (reset to Variation == 0)
  void ResetColorChangeMode() {
    if (!current_style()) return;
      SetVariation(0);
      STDOUT << "Exiting Color Change mode. Color reset to config color.\n";
      STDOUT << "Variation = " << SaberBase::GetCurrentVariation() << "\n";
      SaberBase::SetColorChangeMode(SaberBase::COLOR_CHANGE_MODE_NONE);
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
  }

  RefPtr<BufferedWavPlayer> wav_player;


  bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
    switch (EVENTID(button, event, modifiers)) {
//       // storage of unused cases
      case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_ON):

      case EVENTID(BUTTON_AUX, EVENT_PRESSED, MODE_ON):
      case EVENTID(BUTTON_AUX2, EVENT_PRESSED, MODE_ON):
      return true;

// Gesture Ignition Controls
#ifdef WS_SWING_ON
    case EVENTID(BUTTON_NONE, EVENT_SWING, MODE_OFF):
      if (mode_volume_) return false;
        FastOn();
#ifdef WS_SWING_ON_AUTO_BATTLE_MODE
        STDOUT << "Entering Battle Mode\n";
        battle_mode_ = true;
#endif
      return true;
#endif  // WS_SWING_ON

#ifdef WS_TWIST_ON
    case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_OFF):
      if (mode_volume_) return false;
      // Delay twist events to prevent false trigger from over twisting
      if (millis() - last_twist_ > 1000 &&
        millis() - saber_off_time_ > 1000) {
        FastOn();
        last_twist_ = millis();
      }
      return true;
#endif  // WS_TWIST_ON

#ifdef WS_TWIST_OFF
    case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_ON):
      if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) return false;
      // Delay twist events to prevent false trigger from over twisting
      if (millis() - last_twist_ > 1000) {
        last_twist_ = millis();
        saber_off_time_ = millis();
        battle_mode_ = false;
        Off();
      }
      return true;
#endif  // WS_TWIST_OFF

#ifdef WS_THRUST_ON
    case EVENTID(BUTTON_NONE, EVENT_THRUST, MODE_OFF):
      if (mode_volume_) return false;
      // Delay Thrust On at boot
      if (millis() - saber_off_time_ > 1000) {
        FastOn();
      }
      return true;
#endif  // WS_THRUST_ON


// // ---------------------------------------------------------------------


// Turn Saber ON and OFF
// Exit Color Change Mode
// Volume Up
    case EVENTID(BUTTON_POWER, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_OFF):
    case EVENTID(BUTTON_POWER, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_ON):
      if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) return false;
      if (SaberBase::IsOn()) {
        if (!SaberBase::Lockup()) {
          saber_off_time_ = millis();
          battle_mode_ = false;
          Off();
        } else {
          return false;
        }
      } else {
      // No power on without exiting Vol Menu first
        if (!mode_volume_) {
          On();
        } else {
          VolumeUp();
        }
      }
      return true;


// Start or Stop Music Track
#if NUM_BUTTONS ==1
    case EVENTID(BUTTON_POWER, EVENT_THIRD_SAVED_CLICK_SHORT, MODE_OFF):
#else
 // Start or Stop Music Track
      case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_OFF):
      case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_ON):
#endif
      if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) return false;
      StartOrStopTrack();
      return true;


// Next Preset
// Next Preset Fast with Rotate Right while pointing down
    case EVENTID(BUTTON_NONE, EVENT_TWIST_RIGHT, MODE_ON | BUTTON_POWER):
      if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) return false;
      // Bypasses NewFont and preon if pointing down.
     {
        //Don't change preset or Don't Exit Colorchange if in colorchange mode.
#ifdef WS_ROTATE_TO_CHANGE_PRESET
        next_preset_fast();
#endif
      
        // NOT pointing down
       
      }
      return true;

#if NUM_BUTTONS ==1
    // Hold button 1 second and release
    case EVENTID(BUTTON_POWER, EVENT_FIRST_CLICK_LONG, MODE_OFF):
    if (!mode_volume_) {
      next_preset();
    }
      return true;
#else
    case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_OFF):
      if (!mode_volume_) {
        next_preset();
      } else {
        VolumeDown();
      }
      return true;
#endif


// Previous Preset
// Previous Preset Fast with Rotate Left while pointing down
// Volume Down
    case EVENTID(BUTTON_NONE, EVENT_TWIST_LEFT, MODE_ON | BUTTON_POWER):
      if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) return false;
     {
        // Don't change preset if in colorchange mode
        // Bypasses NewFont and preon if pointing down.
#ifdef WS_ROTATE_TO_CHANGE_PRESET
        previous_preset_fast();
#endif
  
        // NOT pointing down
        
      }
      return true;

    case EVENTID(BUTTON_POWER, EVENT_FIRST_HELD_MEDIUM, MODE_OFF):
      if (!mode_volume_) {
        previous_preset();
      } else {
#if NUM_BUTTONS == 1
        VolumeDown();
#endif
      }
      return true;


// Enter / Exit Volume MENU
#if NUM_BUTTONS == 1
    case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_OFF | BUTTON_POWER):
#else
    case EVENTID(BUTTON_AUX, EVENT_FIRST_CLICK_LONG, MODE_OFF):
#endif
      VolumeMenu();
      return true;


// Spoken Battery Level in percentage
#if NUM_BUTTONS == 1
    case EVENTID(BUTTON_POWER, EVENT_SECOND_HELD_MEDIUM, MODE_OFF):
#else
    case EVENTID(BUTTON_AUX, EVENT_HELD_MEDIUM, MODE_OFF):
#endif
       if (!mode_volume_) {
        sound_library_.SayTheBatteryLevelIs();
        sound_library_.SayNumber(battery_monitor.battery_percent(), SAY_WHOLE);
        sound_library_.SayPercent();
        STDOUT << "Battery Percentage: " <<battery_monitor.battery_percent() << "\n";
        speaking_ = true;
        SaberBase::DoEffect(EFFECT_BATTERY_LEVEL, 0);
      }
      return true;


// Blaster Deflection
// Revert Color Change without saving (reset to Variation == 0)
#if NUM_BUTTONS == 1
    case EVENTID(BUTTON_POWER, EVENT_SECOND_SAVED_CLICK_SHORT, MODE_ON):
#else
    case EVENTID(BUTTON_AUX, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_ON):
#endif
      if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) {
        ResetColorChangeMode();
        return true;
      } else {
        SaberBase::DoBlast();
        last_blast_ = millis();
        return true;
      }


// Multi-Blaster Deflection mode
#ifdef WS_AUTO_SWING_BLAST
    // Auto enter/exit multi-blast block with swings if swing within 1 second
    case EVENTID(BUTTON_NONE, EVENT_SWING, MODE_ON):
      if (millis() - last_blast_ < 1000) {
        SaberBase::DoBlast();
        last_blast_ = millis();
        STDOUT << "Auto Swing Blast mode\n";
      }
      break;
#endif


// Lockup / Drag
#if NUM_BUTTONS == 1
    case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_POWER):
#else
    case EVENTID(BUTTON_AUX, EVENT_HELD, MODE_ON):
#endif
      //Don't lockup if in colorchange mode
      if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) return false;
      if (!SaberBase::Lockup() && SaberBase::IsOn()) {  // Also avoid lockup during preon.
        // pointing down
        if (fusor.angle1() < - M_PI / 4) {
          SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
        } else {
          if (!battle_mode_) {
            SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
          } else {
   // Overrides Auto-lockup if holding Button during clash, NOT pointing down
            break;
          }
        }        SaberBase::DoBeginLockup();
        return true;
      }
      break;

  // Auto Lockup Mode
    case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON):
      if (!battle_mode_ || swinging_) return false;
      clash_impact_millis_ = millis();
      SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
      auto_lockup_on_ = true;
      SaberBase::DoBeginLockup();
      return true;


// Melt
// Exit Color Change mode
    case EVENTID(BUTTON_POWER, EVENT_FIRST_HELD_MEDIUM, MODE_ON):
      if (fusor.angle1() < - M_PI / 4) {
        STDOUT << "*** TOO LOW FOR MELT ***\n";
        return false;
      } 
      if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) {
          STDOUT << "Exiting Color Change mode. Color choice saved.\n";
          ToggleColorChangeMode();
        return true;
      }
        if (!SaberBase::Lockup() && !swinging_) {
        SaberBase::SetLockup(SaberBase::LOCKUP_MELT);
        SaberBase::DoBeginLockup();
        }
      return true;


// Stab
    case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_ON):
      SaberBase::SetClashStrength(2.0);
      SaberBase::DoStab();
    return true;


// Lightning Block
#if NUM_BUTTONS == 1
    case EVENTID(BUTTON_POWER, EVENT_SECOND_HELD, MODE_ON):
#else
    case EVENTID(BUTTON_POWER, EVENT_SECOND_HELD, MODE_ON):
#endif
      SaberBase::SetLockup(SaberBase::LOCKUP_LIGHTNING_BLOCK);
      SaberBase::DoBeginLockup();
      return true;


  // 1 button Force effect
    #if NUM_BUTTONS == 1
  case EVENTID(BUTTON_POWER, EVENT_THIRD_SAVED_CLICK_SHORT, MODE_ON):
    #else
    // 2 button Force effect
  case EVENTID(BUTTON_AUX, EVENT_SECOND_SAVED_CLICK_SHORT, MODE_ON):
#endif
    SaberBase::DoForce();
    return true;


// Enter Color Change mode 1 button 
 #if NUM_BUTTONS == 1
  case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_ON):
// Enter Color Change mode 2 button 
     #else
    case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_ON | BUTTON_AUX):
      #endif
      ToggleColorChangeMode();
      return true;


// Blade Detect
#ifdef BLADE_DETECT_PIN
    case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_ON, MODE_ANY_BUTTON | MODE_ON):
    case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_ON, MODE_ANY_BUTTON | MODE_OFF):
      // Might need to do something cleaner, but let's try this for now.
      blade_detected_ = true;
      FindBladeAgain();
      SaberBase::DoBladeDetect(true);
      return true;

    case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_OFF, MODE_ANY_BUTTON | MODE_ON):
    case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_OFF, MODE_ANY_BUTTON | MODE_OFF):
      // Might need to do something cleaner, but let's try this for now.
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
      // Dim
      case EFFECT_POWERSAVE:
        if (SFX_dim) {
          hybrid_font.PlayCommon(&SFX_dim);
        } else {
          beeper.Beep(0.1, 1300);
          beeper.Beep(0.1, 900);
          beeper.Beep(0.1, 600);
          beeper.Beep(0.1, 300);
        }
        return;
      // On-Demand Battery Level
      case EFFECT_BATTERY_LEVEL:
        if (speaking_) {
          speaking_ = false;
          return;
        }
        if (SFX_battery) {
          hybrid_font.PlayCommon(&SFX_battery);
        } else {
          beeper.Beep(1.0, 475);
          beeper.Beep(0.5, 693);
          beeper.Beep(0.16, 625);
          beeper.Beep(0.16, 595);
          beeper.Beep(0.16, 525);
          beeper.Beep(1.1, 950);
          beeper.Beep(0.5, 693);
        }
        return;


    }
  }

private:
  float current_menu_angle_ = 0.0;
  bool mode_volume_ = false;
   // Avoid overlap of battery.wav when doing Spoken Battery Level
  bool speaking_ = false;
  bool auto_lockup_on_ = false;
  bool battle_mode_ = false;
  uint32_t clash_impact_millis_ = millis();
  uint32_t thrust_begin_millis_ = millis();
  uint32_t last_twist_ = millis();
  uint32_t last_blast_ = millis();
  uint32_t saber_off_time_ = millis();
  uint32_t volume_range_delay_ = millis();

};

#endif
