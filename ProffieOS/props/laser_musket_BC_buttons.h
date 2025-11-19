/*
Fallout laser_musket_buttons.h prop file.

  http://fredrik.hubbe.net/lightsaber/proffieos.html
  Copyright (c) 2016-2025 Fredrik Hubinette
  Copyright (c) 2025 Brian Conner with contributions by:
  Fredrik Hubinette, Fernando da Rosa, Matthew McGeary, and Scott Weber.
  Distributed under the terms of the GNU General Public License v3.
  http://www.gnu.org/licenses/

Includes:
- Next / previous / first preset based on angle.
- Track playback.
- ProffieOS8 Menu system for editing volume, presets and more.
- Spoken Battery Level in percentage or volts based on angle.
- On blade battery meter.
- Quote playback.
- Increase charge level from 0-6 with each press of AUX (CHARGE).
- FIRE with POW button.

This prop requires a blade style and sound font that use "alt sounds" to
allow for the charge up feature to work.
Folders named alt000 - alt006 should each contain an appropriate sound for
its respective power level, and all named the same.
- altchng.wav (the charge up sound heard)
- hum.wav (the increasingly more powerful hum sound at each level)
- blast.wav (the increasingly more powerful discharge sound at each level)

The key to cycling up through these levels in the blade style is to use the following layer:
TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<7>>,Int<-1>>,EFFECT_USER1>

More or less levels can be set by changing the `Int<7>` value above (there's an off set of 1 in the code),
and having the corresponding number of alt folders set up in the font.

This prop version requires a ProffieOS Voicepack V2 for menus to work right.

=====================================================================
| 2 Buttons: FIRE and CHARGE (btn1 and btn2, typically POW and AUX) |
=====================================================================
Power Blaster ON          - Do Change Preset if blaster is OFF.
Change Preset             - Long Click and release CHARGE.
        Next                  (while NOT pointing UP or DOWN).
        Previous              (while pointing DOWN).
        Jump to First         (while pointing UP).
Start/Stop Track          - Click and hold CHARGE.

OS8 System Menus:         - 2x Click and hold CHARGE.
  System menu will allow for editing of presets, colors and styles,
  similar to way the ProffieOS Workbench webpage and Edit mode work.
  There's also an Edit Settings mode that has a volume level menu, preset and blade length editing, and more.
  To use the OS System Menu, you need to use `#define MENU_SPEC_TEMPLATE DefaultMenuSpec` in the config file.
While in any menu mode the following controls apply:
Navigate            - Rotate hilt back and forth.
Enter Option/Save   - Click FIRE.
Exit/Cancel `       - Click CHARGE or Double Click FIRE.

Spoken Battery Level
        in percentage     - 3x Click and Hold CHARGE.
        in volts          - 3x Click and Hold CHARGE (while pointing DOWN).
                            * Will show On-blade display if EFFECT_BATTERY_LEVEL is used in blade style.
Quote Player              - Double Click CHARGE.

Charge up                 - Click CHARGE. (up to level 6 max)
Fire                      - Click FIRE.
*/


#ifndef PROPS_LASER_MUSKET_H
#define PROPS_LASER_MUSKET_H

#include "blaster.h"
#include "../sound/sound_library.h"

#ifdef PROP_TYPE
#undef PROP_TYPE
#endif

#define PROP_TYPE LaserMusketButtons

#ifndef BUTTON_HELD_LONG_TIMEOUT
#define BUTTON_HELD_LONG_TIMEOUT 1200
#endif

EFFECT(maxcharge);
EFFECT(battery);    // for EFFECT_BATTERY_LEVEL

class LaserMusketButtons : public Blaster {
public:
  LaserMusketButtons() : Blaster() {}
  const char* name() override { return "LaserMusketButtons"; }

  void Loop() override {
    PropBase::Loop();
    sound_library_.Poll(wav_player);
    if (wav_player && !wav_player->isPlaying()) wav_player.Free();
  }

  bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
    switch (EVENTID(button, event, modifiers)) {

  // Change Preset
      case EVENTID(BUTTON_AUX, EVENT_FIRST_CLICK_LONG, MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_FIRST_CLICK_LONG, MODE_OFF):
        if (fusor.angle1() > M_PI / 3) {
        // Muzzle pointing UP
          first_preset();
          PVLOG_NORMAL << "**** Jumped to first preset\n";
        } else if (fusor.angle1() < -M_PI / 3) {
        // Muzzle pointing DOWN
          previous_preset();
          PVLOG_NORMAL << "**** Previous preset\n";
        } else {
        // Muzzle NOT pointing UP or DOWN
          next_preset();
          PVLOG_NORMAL << "**** Next preset\n";
        }
        if (!SaberBase::IsOn()) On();
        return true;

  // Start or Stop Track
      case EVENTID(BUTTON_AUX, EVENT_FIRST_HELD_LONG, MODE_ON):
        PVLOG_NORMAL << "**** StartOrStopTrack\n";
        StartOrStopTrack();
        return true;

  // Enter OS System Menu
      case EVENTID(BUTTON_AUX, EVENT_SECOND_HELD_MEDIUM, MODE_ON):
#ifdef MENU_SPEC_TEMPLATE
        PVLOG_NORMAL << "**** Entering ProffieOS Menu System\n";
        EnterMenu();
#endif
        return true;

  // Spoken Battery Level in percentage
  // Spoken Battery Level in volts - pointing DOWN
  // Show Battery Meter on LEDs
      case EVENTID(BUTTON_AUX, EVENT_THIRD_HELD_MEDIUM, MODE_ON):
        // Avoid weird battery readings when using USB
        if (battery_monitor.battery() < 0.5) {
          PVLOG_NORMAL << "**** USB power only. The battery level report is disabled\n";
          sound_library_.SayTheBatteryLevelIs();
          sound_library_.SayDisabled();
          return true;
        }
        sound_library_.SayTheBatteryLevelIs();
        // pointing DOWN
        if (fusor.angle1() < -M_PI / 4) {
          sound_library_.SayNumber(battery_monitor.battery(), SAY_DECIMAL);
          sound_library_.SayVolts();
          PVLOG_NORMAL << "**** Battery Voltage: " << battery_monitor.battery() << "\n";
          SaberBase::DoEffect(EFFECT_BATTERY_LEVEL, 0);
        } else {
          sound_library_.SayNumber(battery_monitor.battery_percent(), SAY_WHOLE);
          sound_library_.SayPercent();
          PVLOG_NORMAL << "**** Battery Percentage: " <<battery_monitor.battery_percent() << "%\n";
          SaberBase::DoEffect(EFFECT_BATTERY_LEVEL, 0);
        }
        return true;

  // Quote
      case EVENTID(BUTTON_AUX, EVENT_SECOND_SAVED_CLICK_SHORT, MODE_ON):
          PVLOG_NORMAL << "**** SFX_quote **\n";
        if (SFX_quote) {
          if (GetWavPlayerPlaying(&SFX_quote)) return false;  // Simple prevention of quote overlap
          hybrid_font.PlayCommon(&SFX_quote);
        }
        return true;

  // Crank to charge
      case EVENTID(BUTTON_AUX, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_ON):
          PVLOG_DEBUG << "**** current_alternative BEFORE = " << current_alternative << "\n";
        if (current_alternative == 6) {
          hybrid_font.PlayCommon(&SFX_maxcharge);
          return true;
        } else {
          PVLOG_DEBUG << "**** EFFECT_USER1 - Next Phase **\n";
          SaberBase::DoEffect(EFFECT_USER1, 0);
          PVLOG_DEBUG << "**** current_alternative AFTER = " << current_alternative << "\n";
        }
        return true;

  // Trigger to fire
      case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_ON):
          PVLOG_DEBUG << "**** current_alternative At BOOT = " << current_alternative << "\n";
        if (current_alternative == 0) {
          PVLOG_DEBUG << "**** No charge = EMPTY - No FIRE **\n";
          SaberBase::DoEffect(EFFECT_EMPTY, 0);
        } else {
          PVLOG_DEBUG << "**** FIRE ****\n";
          SaberBase::DoEffect(EFFECT_FIRE, 0);
          ResetCurrentAlternative();
        }
        return true;

      default:
        break;
    }
    return false;
  }

  void SB_Effect(EffectType effect, EffectLocation location) override {
    Blaster::SB_Effect(effect, location);
    switch (effect) {
      default: return;
      case EFFECT_BATTERY_LEVEL:
        if (SFX_battery) hybrid_font.PlayCommon(&SFX_battery);
    }
  }

private:
  RefPtr<BufferedWavPlayer> wav_player;

};

#endif
