# HEV Settings Menu - Flow Diagram

```
┌─────────────────────────────────────────────────────────────────┐
│                         HEV SUIT OFF                            │
│                                                                 │
│                  Quad-click POWER or AUX                        │
│                            ↓                                    │
└─────────────────────────────────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                      ENTER SETTINGS MENU                        │
│                    (Audio: Select sound)                        │
└─────────────────────────────────────────────────────────────────┘
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│  ┌───────────────────────────────────────────────────────┐      │
│  │  Setting 1: HAZARDS          [Currently: ON/OFF]      │      │
│  └───────────────────────────────────────────────────────┘      │
│                                                                 │
│  Navigation:                                                    │
│  • Hold POWER (medium)       → Next setting                     │
│  • Hold AUX (medium)         → Previous setting                 │
│  • Single-click POWER        → Toggle current setting           │
│  • Single-click AUX          → Exit menu                        │
└─────────────────────────────────────────────────────────────────┘
                             ↓
                     (Hold POWER Medium)
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│  ┌───────────────────────────────────────────────────────┐      │
│  │  Setting 2: HEALTH ALERTS    [Currently: ON/OFF]      │      │
│  └───────────────────────────────────────────────────────┘      │
│                    (Audio: Tick sound)                          │
└─────────────────────────────────────────────────────────────────┘
                             ↓
                     (Hold POWER Medium)
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│  ┌───────────────────────────────────────────────────────┐      │
│  │  Setting 3: ARMOR ALERTS     [Currently: ON/OFF]      │      │
│  └───────────────────────────────────────────────────────┘      │
│                    (Audio: Tick sound)                          │
└─────────────────────────────────────────────────────────────────┘
                             ↓
                     (Hold POWER Medium)
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│  ┌───────────────────────────────────────────────────────┐      │
│  │  Setting 4: CLASH DAMAGE     [Currently: ON/OFF]      │      │
│  └───────────────────────────────────────────────────────┘      │
│                    (Audio: Tick sound)                          │
└─────────────────────────────────────────────────────────────────┘
                             ↓
                   (Single-click POWER)
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                    TOGGLE CURRENT SETTING                       │
│              (Audio: "Enabled" or "Disabled")                   │
│                                                                 │
│  Setting changes immediately!                                   │
│  • If ON  → Turns OFF                                           │
│  • If OFF → Turns ON                                            │
└─────────────────────────────────────────────────────────────────┘
                             ↓
          (Can continue navigating or exit)
                             ↓
                    (Single-click AUX)
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│                        EXIT MENU                                │
│                  (Audio: Exit/Cancel sound)                     │
│                                                                 │
│           All changes are active immediately!                   │
│       (Changes reset to defaults on next power-on)              │
└─────────────────────────────────────────────────────────────────┘
```

## Quick Reference Card

### Menu Access
```
Suit Status: OFF
Action:      Quad-click POWER or AUX (4 rapid clicks)
Result:      Enter settings menu
```

### Menu Navigation
```
Action              | Result
--------------------|----------------------------------
Hold POWER (medium) | Next setting (with tick sound)
Hold AUX (medium)   | Previous setting (with tick sound)
Click POWER         | Toggle setting ON/OFF
Click AUX           | Exit menu
Double-click POWER  | Exit menu (alternate)
```

### Settings Overview
```
#  | Setting        | Controls              | Default | Saved
---|----------------|-----------------------|---------|-------
1  | Hazards        | Random hazard events  | ON      | Yes
2  | Health Alerts  | Health voice warnings | ON      | Yes
3  | Armor Alerts   | Armor voice warnings  | ON      | Yes
4  | Clash Damage   | Physical damage       | ON      | Yes

Settings are saved to hev.ini on SD card and persist across power cycles.
```

## Button Summary

```
┌──────────────┬─────────────────────────────────────────────┐
│ Button       │ Action                                      │
├──────────────┼─────────────────────────────────────────────┤
│ POWER        │ Long-click:    ON/OFF                       │
│              │ Hold:          Recharge Armor               │
│              │ Double-click:  Toggle track                 │
│              │ Triple-click:  Next preset                  │
│              │ Quad-click:    Enter Settings Menu (OFF)    │
│              │                                             │
│              │ IN MENU:                                    │
│              │ Hold (medium): Navigate forward             │
│              │ Single-click:  Toggle setting               │
│              │ Double-click:  Exit menu                    │
├──────────────┼─────────────────────────────────────────────┤
│ AUX          │ Hold:          Recharge Health              │
│              │ Single-click:  Deactivate Hazard            │
│              │ Double-click:  Armor Readout                │
│              │ Triple-click:  Previous preset              │
│              │ Quad-click:    Enter Settings Menu (OFF)    │
│              │                                             │
│              │ IN MENU:                                    │
│              │ Hold (medium): Navigate backward            │
│              │ Single-click:  Exit menu                    │
├──────────────┼─────────────────────────────────────────────┤
│ SIMULTANEOUS │ Hold POWER + Click AUX (ON):                │
│              │   Toggle Combat Mode (real-time)            │
│              │   Disables all voice/effects                │
└──────────────┴─────────────────────────────────────────────┘
```

## Combat Mode

Combat Mode is a real-time toggle available while the suit is ON:

```
┌─────────────────────────────────────────────────────────┐
│                    COMBAT MODE                          │
├─────────────────────────────────────────────────────────┤
│ Activation:  Hold POWER + Click AUX (while ON)         │
│ Effect:      Disables all voice lines and effects      │
│ Duration:    Until toggled off or suit powers off      │
│ Preserves:   Damage tracking, visual effects, clash    │
└─────────────────────────────────────────────────────────┘
```

## Audio Feedback

```
Action                  | Sound Played
------------------------|----------------------------------
Enter Menu              | Select sound
Navigate to Setting     | Tick sound
Toggle Setting ON       | "Enabled" sound
Toggle Setting OFF      | "Disabled" sound
Exit Menu               | Cancel/Exit sound
```

## State Diagram

```
                    ┌─────────────┐
                    │  Suit OFF   │
                    └──────┬──────┘
                           │ quad-click
                           ↓
    ┌──────────────────────────────────────────┐
    │         Settings Menu Active             │
    │                                          │
    │  ┌────────────────────────────────┐     │
    │  │   Current Setting Display      │     │
    │  │   [Hazards / Health / etc.]    │     │
    │  └────────────────────────────────┘     │
    │                                          │
    │  Hold POWER ⚡ → Next setting            │
    │  Hold AUX ⚡ → Previous setting          │
    │  Click ⚡ → Toggle setting               │
    │  Click ✕ → Exit menu                    │
    └──────────────────────────────────────────┘
                           │ click AUX
                           ↓
                    ┌─────────────┐
                    │  Suit OFF   │
                    │ (settings   │
                    │  applied)   │
                    └─────────────┘
```
