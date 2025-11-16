# HEV Suit Settings Menu Documentation

## Overview

The HEV (Hazardous Environment Suit) prop file now includes a settings menu system that allows users to toggle various features on and off without needing to modify code or configuration files.

## Accessing the Menu

To enter the settings menu:
1. Make sure the HEV suit is **OFF**
2. **Quad-click** either the POWER or AUX button (click 4 times quickly)

## Navigating the Menu

Once in the menu, you can:
- **Rotate the board** to scroll through the available settings
- **Single-click POWER** to toggle the selected setting ON/OFF
- **Single-click AUX** (or double-click POWER) to exit the menu

The board will provide audio feedback:
- A sound plays when you navigate to each menu item
- "Enabled" or "Disabled" sounds play when you toggle a setting
- A confirmation sound plays when you exit the menu

## Available Settings

### 1. Hazards
- **Function**: Enables or disables random hazard events
- **Default**: Enabled
- **When Disabled**: No random hazards will occur, but existing hazards can still be cleared

### 2. Health Alerts
- **Function**: Enables or disables HEV voice alerts for health status
- **Default**: Enabled
- **When Disabled**: The suit will remain silent about health status changes, but health values still change normally

### 3. Armor Alerts
- **Function**: Enables or disables armor-related alerts (armor compromised warnings, armor alarm sounds)
- **Default**: Enabled
- **When Disabled**: The suit will not announce when armor is compromised or play alarm sounds for heavy damage

### 4. Clash Damage
- **Function**: Enables or disables physical damage from clashes
- **Default**: Enabled
- **When Disabled**: Clashes will still play sounds but will not cause damage to health or armor

## Important Notes

- **Settings are not saved**: When you power cycle the device, all settings reset to their defaults (all enabled)
- **Menu access**: The menu can only be accessed when the suit is OFF
- **No impact on performance**: Disabled features are completely skipped, so disabling features you don't use can be beneficial

## Technical Details

### For Developers

The settings are stored in a global namespace `hev_settings` defined in `props/hev.h`:

```cpp
namespace hev_settings {
  bool hazards_enabled = true;
  bool health_alerts_enabled = true;
  bool armor_alerts_enabled = true;
  bool clash_damage_enabled = true;
}
```

The menu system is implemented using ProffieOS's mode system:
- Menu specification: `modes/hev_menu.h`
- BoolSetting classes for each toggleable feature
- Integration with prop file via pushMode/popMode

### Adding Persistent Settings (Future Enhancement)

To make settings persistent across power cycles, you would need to:
1. Add save/load functionality using ProffieOS's config save system
2. Store settings in EEPROM or on the SD card
3. Load settings during prop initialization

## Troubleshooting

**Menu doesn't open:**
- Make sure the suit is OFF (not just idle, but completely OFF)
- Try quad-clicking more slowly or more quickly
- Check that no other modes or menus are currently active

**Settings don't seem to work:**
- Settings only take effect after you toggle them in the menu
- Some settings (like hazards) only apply when the suit is ON
- Remember that settings reset to defaults on power cycle

**Board doesn't respond in menu:**
- Try rotating the board more firmly
- Ensure your motion sensors are working properly
- Try using button navigation if rotation isn't working

## Example Usage Scenarios

### Scenario 1: Disable Hazards for a Performance
If you're doing a performance and want consistent behavior without random hazards:
1. Turn suit OFF
2. Quad-click POWER or AUX to enter menu
3. First option is "Hazards" - single-click POWER to toggle to OFF
4. Single-click AUX to exit menu
5. Turn suit ON - no random hazards will occur

### Scenario 2: Silent Mode (No Voice Alerts)
If you want visual effects only without voice announcements:
1. Turn suit OFF
2. Enter menu (quad-click)
3. Navigate to "Health Alerts" (rotate board once)
4. Toggle OFF (single-click POWER)
5. Navigate to "Armor Alerts" (rotate board once more)
6. Toggle OFF (single-click POWER)
7. Exit menu (single-click AUX)

### Scenario 3: No Damage Mode for Practice
If you want to practice movements without worrying about damage:
1. Turn suit OFF
2. Enter menu (quad-click)
3. Navigate through to "Clash Damage" (rotate 3 times)
4. Toggle OFF (single-click POWER)
5. Exit menu (single-click AUX)
6. You can now clash all you want without taking damage!

## Future Enhancements

Potential improvements for future versions:
- Save settings persistently
- Add more toggleable features (individual hazard types, damage multipliers, etc.)
- Visual indicators of current settings (LED patterns)
- Preset profiles (Combat, Practice, Performance, etc.)
- Menu for adjusting timing values (hazard frequency, heal rate, etc.)
