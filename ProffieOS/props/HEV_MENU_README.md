# HEV Suit Settings Menu Documentation

## Overview

The HEV (Hazardous Environment Suit) prop file now includes a settings menu system that allows users to toggle various features on and off without needing to modify code or configuration files. Additionally, a real-time **Combat Mode** provides instant audio control during operation.

## Combat Mode (Real-Time Toggle)

Combat Mode allows you to instantly disable all voice lines and sound effects while the suit is running, perfect for combat scenarios where audio feedback would be distracting.

### Activating Combat Mode

**While the suit is ON:**
1. **Hold** the POWER button
2. While holding POWER, **click** the AUX button
3. Combat Mode toggles on/off instantly

### What Combat Mode Does

**When ENABLED:**
- ✓ Disables all HEV voice announcements (health, armor, hazard alerts)
- ✓ Disables armor alarm sounds
- ✓ Disables environmental damage sounds
- ✓ Disables death sound effects
- ✓ All damage tracking continues normally (health, armor, hazards)
- ✓ Visual effects remain active
- ✓ Clash sounds still play (handled by base prop)
- ✓ User-triggered sounds still work (armor readout via double-click AUX)

**When DISABLED:**
- All voice lines and effects function normally according to menu settings

### Use Cases for Combat Mode

- **Active Combat**: Focus on fighting without audio distractions
- **Stealth Situations**: Minimize audio signatures
- **Recording/Streaming**: Clean audio for video content
- **Performance**: Quick audio muting during shows

---

## Accessing the Menu

To enter the settings menu:
1. Make sure the HEV suit is **OFF**
2. **Quad-click** either the POWER or AUX button (click 4 times quickly)

## Navigating the Menu

Once in the menu, you can:
- **Hold POWER (medium hold)** to navigate forward through the available settings
- **Hold AUX (medium hold)** to navigate backward through the available settings
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

- **Settings are saved**: Settings are automatically saved to the SD card in `hev.ini` (or `hev.tmp`) and persist across power cycles
- **Menu access**: The menu can only be accessed when the suit is OFF
- **No impact on performance**: Disabled features are completely skipped, so disabling features you don't use can be beneficial
- **Storage location**: Settings file is stored in the root directory of the SD card, similar to `global.ini` and `presets.ini`

## Technical Details

### For Developers

The settings are stored in a global namespace `hev_settings` defined in `props/hev.h`:

```cpp
namespace hev_settings {
  bool hazards_enabled = true;
  bool health_alerts_enabled = true;
  bool armor_alerts_enabled = true;
  bool clash_damage_enabled = true;
  
  // Persistent storage
  HevSettingsFile saved_settings;
  void SaveSettings();  // Writes to hev.ini
  void LoadSettings();  // Reads from hev.ini
}
```

**Persistence Implementation:**
- Settings are saved to `hev.ini` (or `hev.tmp`) on the SD card root directory
- Uses ProffieOS's `ConfigFile` system (same as `global.ini` and `presets.ini`)
- Settings are automatically saved when changed via menu
- Settings are automatically loaded on prop initialization
- Uses alternating `.ini` and `.tmp` files for data integrity

The menu system is implemented using ProffieOS's mode system:
- Menu specification: `modes/hev_menu.h`
- BoolSetting classes for each toggleable feature
- Integration with prop file via pushMode/popMode
- Save/Load hooks integrated into setting change handlers

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
- Make sure you're holding the button long enough (medium hold)
- Try holding POWER to go forward or AUX to go backward
- The board is in a static position, so button holds are used instead of rotation

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
3. Navigate to "Health Alerts" (hold POWER once)
4. Toggle OFF (single-click POWER)
5. Navigate to "Armor Alerts" (hold POWER once more)
6. Toggle OFF (single-click POWER)
7. Exit menu (single-click AUX)

### Scenario 3: No Damage Mode for Practice
If you want to practice movements without worrying about damage:
1. Turn suit OFF
2. Enter menu (quad-click)
3. Navigate through to "Clash Damage" (hold POWER 3 times)
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
