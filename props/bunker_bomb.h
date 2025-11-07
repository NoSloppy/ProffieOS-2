/*
bunker_bomb.h prop file.
  Brian Conner 2024 for Jon Rossi @SabersForever

  http://fredrik.hubbe.net/lightsaber/proffieos.html
  Copyright (c) 2016-2023 Fredrik Hubinette
  Copyright (c) 2023 Brian Conner with contributions by:
  Fredrik Hubinette, Fernando da Rosa, Matthew McGeary, and Scott Weber.
  Distributed under the terms of the GNU General Public License v3.
  http://www.gnu.org/licenses/

Requirements:
- destruct.wav - armed state sound (ticking)
    Detonation occurs at the end of the wav file, so different length delays are easy.
    Files can play randomly as any other effect does, so a font with multiple numbered
    destruct.wavs of various lengths can vary the variety of varied explosion timings. :)
- in.wav
- out.wav
- boom.wav
- boot.wav
- font.wav

Controls:
- Power on        - Use killswitch knob. Bomb auto arms and detonates after length of destruct.wav
- Play track      - Double Click and Hold button to start and stop track set in preset.
- Rotate Presets  - Click the button. Will load last preset in list, save it in the first position,
                    shifting all other presets down. Arrange config presets in decending order
                    to have it feel like cylcling forward through the list.
                    Power on resumes in the preset last used when powered off,
                    no need for #define SAVE_PRESET. Plays font.wav and out.wav.
- Disarm          - Double Click the button to stop the countdown. Plays in.wav.
- Re-arm          - Hold button to re-engage the armed state, countdown starts again. Plays out.wav

Now go virtually blow stuff up! Enjoy.
*/

#ifndef PROPS_DETONATOR_H
#define PROPS_DETONATOR_H

#include "prop_base.h"

#define PROP_TYPE Detonator

EFFECT(destruct);

class Detonator : public PROP_INHERIT_PREFIX PropBase {
public:
  Detonator() : PropBase() {}
  const char* name() override { return "Detonator"; }

  enum NextAction {
    NEXT_ACTION_NOTHING,
    NEXT_ACTION_ARM,
    NEXT_ACTION_BLOW,
  };

  NextAction next_action_ = NEXT_ACTION_NOTHING;
  uint32_t time_base_;
  uint32_t next_event_time_;
  
  void SetNextAction(NextAction what, uint32_t when) {
    time_base_ = millis();
    next_event_time_ = when;
    next_action_ = what;
  }

  void SetNextActionF(NextAction what, float when) {
    SetNextAction(what, when * 1000);
  }
  
  void PollNextAction() {
    if (millis() - time_base_ > next_event_time_) {
      switch (next_action_) {
        case NEXT_ACTION_NOTHING:
          break;
        case NEXT_ACTION_BLOW:
          Off(OFF_BLAST);
          break;
      }
      next_action_ = NEXT_ACTION_NOTHING;
    }
  }

  void SetPreset(int preset_num, bool announce) override {
    PropBase::SetPreset(preset_num, announce);
    if (booted_) hybrid_font.PlayCommon(&SFX_out);
      // Just always default to on.
       // if (!SaberBase::IsOn()) On();
  }

  void selfDestruct() {
    hybrid_font.PlayCommon(&SFX_destruct);
    float len = hybrid_font.GetCurrentEffectLength();
      SetNextActionF(NEXT_ACTION_BLOW, len);
  }

  void Loop() override {
    PropBase::Loop();
    PollNextAction();
    if (!booted_ && millis() - saber_off_time_ > 1100) {
      On();
      selfDestruct();
      booted_ = true;
    }
  }

  // Make clash do nothing
  void Clash(bool stab, float strength) override {}

  // Make swings do nothing
  void DoMotion(const Vec3& motion, bool clear) override { }


  bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
    switch (EVENTID(button, event, modifiers)) {

// Re-arm
      case EVENTID(BUTTON_AUX, EVENT_FIRST_HELD_MEDIUM, MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_FIRST_HELD_MEDIUM, MODE_OFF):
        On();
        selfDestruct();
        return true;

// Start/stop track
      case EVENTID(BUTTON_AUX, EVENT_SECOND_HELD_MEDIUM, MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_SECOND_HELD_MEDIUM, MODE_OFF):
      StartOrStopTrack();
      return true;

// Next Preset
      case EVENTID(BUTTON_AUX, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_OFF):
        rotate_presets();
        return true;

// Disarm
    case EVENTID(BUTTON_AUX, EVENT_SECOND_SAVED_CLICK_SHORT, MODE_ON):
    case EVENTID(BUTTON_AUX, EVENT_SECOND_SAVED_CLICK_SHORT, MODE_OFF):
    RefPtr<BufferedWavPlayer> tmp = GetWavPlayerPlaying(&SFX_destruct);
      if (tmp) {
        tmp->set_fade_time(0.001);
        tmp->FadeAndStop();
      }
      Off();
      return true;

    }
    return false;
  }

private:
  bool booted_ = false;
  bool saber_off_time_ = millis();

};

#endif
