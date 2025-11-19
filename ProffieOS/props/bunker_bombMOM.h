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
  
  void PollNextAction() override {
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
  
  void selfDestruct() override {
    SaberBase::DoEffect(EFFECT_DESTRUCT, 0);
    float len = hybrid_font.GetCurrentEffectLength();
    SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
      SetNextActionF(NEXT_ACTION_BLOW, len);
  }

  void Loop() override {
    PropBase::Loop();
    PollNextAction();
  }


  // Make clash do nothing
  void Clash(bool stab, float strength) override {}

  // Make swings do nothing
  void DoMotion(const Vec3& motion, bool clear) override { }


  bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
    switch (EVENTID(button, event, modifiers)) {
      case EVENTID(BUTTON_POWER, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_ON):
      case EVENTID(BUTTON_POWER, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_OFF):
        SetPower(true);
        On();
        selfDestruct()
        return true;

// Next Preset
      case EVENTID(BUTTON_AUX, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_OFF):
        rotate_presets();
        return true;
 
    }
    return false;
  }

  void SB_Effect(EffectType effect, float location) override {
    switch (effect) {
      case EFFECT_DESTRUCT: hybrid_font.PlayCommon(&SFX_destruct); return;
      default: return;

};

#endif
