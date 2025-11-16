#ifndef MODES_HEV_MENU_H
#define MODES_HEV_MENU_H

//=====================================================================//
//                      HEV SETTINGS MENU SYSTEM                       //
//                     ─────────────────────────                       //
//                                                                     //
// This file implements the settings menu for the HEV prop file,       //
// allowing users to toggle various HEV suit features on/off via       //
// button-based navigation (no rotation required).                     //
//                                                                     //
// Settings are stored in the global hev_settings namespace and are    //
// accessible from both the prop file and the menu system.             //
//                                                                     //
// How to use:                                                         //
// - Quad-click POWER or AUX while suit is OFF to enter menu          //
// - Hold POWER (medium) to navigate forward through settings          //
// - Hold AUX (medium) to navigate backward through settings           //
// - Single-click POWER to toggle selected setting                     //
// - Single-click AUX to exit menu                                     //
//                                                                     //
//=====================================================================//

#include "menu_base.h"
#include "bool_setting.h"
#include "menu_list.h"

namespace mode {

// Forward declare the HEV prop class so we can access its settings
class HevProp;

// Button-based menu navigation mode (no rotation required)
// Uses HELD_MEDIUM events for forward/back navigation
template<class SPEC>
struct ButtonSteppedMode : public SPEC::SelectCancelMode {
  virtual void next() = 0;
  virtual void prev() = 0;
  virtual void update() {}

  bool mode_Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
    switch (EVENTID(button, event, 0)) {
      case EVENTID(BUTTON_POWER, EVENT_HELD_MEDIUM, 0):
        next();
        update();
        return true;

      case EVENTID(BUTTON_AUX, EVENT_HELD_MEDIUM, 0):
        prev();
        update();
        return true;
    }
    return SPEC::SelectCancelMode::mode_Event2(button, event, modifiers);
  }

  bool mode_Parse(const char *cmd, const char* arg) override {
#ifndef DISABLE_DIAGNOSTIC_COMMANDS
    if (!strcmp(cmd, "next") || !strcmp(cmd, "n")) {
      next();
      update();
      return true;
    }
    if (!strcmp(cmd, "prev") || !strcmp(cmd, "p")) {
      prev();
      update();
      return true;
    }
#endif
    return SPEC::SelectCancelMode::mode_Parse(cmd, arg);
  }
};

// Button-based menu base class
template<class SPEC>
struct ButtonMenuBase : public ButtonSteppedMode<SPEC> {
  virtual void say() = 0;
  virtual uint16_t size() = 0;

  void exit() override {
    getSL<SPEC>()->SayCancel();
    popMode();
  }
  
  void select() override {
    getSL<SPEC>()->SaySelect();
    popMode();
  }
  
  void mode_activate(bool onreturn) override {
    say();
  }
  
  void fadeout(float len) {
    getSL<SPEC>()->fadeout(len);
  }
  
  void next() override {
    pos_ = MOD(pos_ + 1, size());
    say();
  }
  void prev() override {
    pos_ = MOD(pos_ - 1, size());
    say();
  }

  uint16_t pos_;
};

// BoolSetting for enabling/disabling hazards
template<class SPEC>
struct HazardEnabledSetting : public BoolSetting {
  bool get();
  void set(bool value);
  void say() { 
    // Play "Hazards" sound - we'll use a custom approach
    // For now, just use the select sound as placeholder
    getSL<SPEC>()->SaySelect(); 
  }
};

// BoolSetting for enabling/disabling health alerts
template<class SPEC>
struct HealthAlertsEnabledSetting : public BoolSetting {
  bool get();
  void set(bool value);
  void say() { 
    getSL<SPEC>()->SaySelect();
  }
};

// BoolSetting for enabling/disabling armor alerts
template<class SPEC>
struct ArmorAlertsEnabledSetting : public BoolSetting {
  bool get();
  void set(bool value);
  void say() { 
    getSL<SPEC>()->SaySelect();
  }
};

// BoolSetting for enabling/disabling clash damage
template<class SPEC>
struct ClashDamageEnabledSetting : public BoolSetting {
  bool get();
  void set(bool value);
  void say() { 
    getSL<SPEC>()->SaySelect();
  }
};

// Main HEV Settings Menu
template<class SPEC>
struct HevSettingsMenu : public MenuEntryMenu<SPEC,
  DirectBoolEntry<SPEC, HazardEnabledSetting<SPEC>>,
  DirectBoolEntry<SPEC, HealthAlertsEnabledSetting<SPEC>>,
  DirectBoolEntry<SPEC, ArmorAlertsEnabledSetting<SPEC>>,
  DirectBoolEntry<SPEC, ClashDamageEnabledSetting<SPEC>>
> {};

// HEV Menu Specification (button-based, no rotation)
template<class SPEC>
struct HevMenuSpec {
  typedef mode::SelectCancelMode SelectCancelMode;
  typedef mode::ButtonSteppedMode<SPEC> SteppedModeBase;
  typedef mode::ButtonSteppedMode<SPEC> SteppedMode;
  typedef mode::ButtonMenuBase<SPEC> MenuBase;
  typedef SoundLibraryV2 SoundLibrary;
  typedef mode::HevSettingsMenu<SPEC> HevSettingsMenu;
};

}  // namespace mode

#endif // MODES_HEV_MENU_H
