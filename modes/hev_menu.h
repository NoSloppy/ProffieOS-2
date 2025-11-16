#ifndef MODES_HEV_MENU_H
#define MODES_HEV_MENU_H

//=====================================================================//
//                      HEV SETTINGS MENU SYSTEM                       //
//                     ─────────────────────────                       //
//                                                                     //
// This file implements the settings menu for the HEV prop file,       //
// allowing users to toggle various HEV suit features on/off via       //
// the board's rotation-based menu system.                             //
//                                                                     //
// Settings are stored in the global hev_settings namespace and are    //
// accessible from both the prop file and the menu system.             //
//                                                                     //
// How to use:                                                         //
// - Quad-click POWER or AUX while suit is OFF to enter menu          //
// - Rotate board to navigate through settings                         //
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

// HEV Menu Specification
template<class SPEC>
struct HevMenuSpec {
  typedef mode::SelectCancelMode SelectCancelMode;
  typedef mode::SteppedModeBase<SPEC> SteppedModeBase;
  typedef mode::SteppedMode<SPEC> SteppedMode;
  typedef mode::MenuBase<SPEC> MenuBase;
  typedef SoundLibraryV2 SoundLibrary;
  typedef mode::HevSettingsMenu<SPEC> HevSettingsMenu;
};

}  // namespace mode

#endif // MODES_HEV_MENU_H
