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
│  • Rotate Board Clockwise    → Next setting                     │
│  • Rotate Board Counter-CW   → Previous setting                 │
│  • Single-click POWER        → Toggle current setting           │
│  • Single-click AUX          → Exit menu                        │
└─────────────────────────────────────────────────────────────────┘
                             ↓
                     (Rotate Board)
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│  ┌───────────────────────────────────────────────────────┐      │
│  │  Setting 2: HEALTH ALERTS    [Currently: ON/OFF]      │      │
│  └───────────────────────────────────────────────────────┘      │
│                    (Audio: Tick sound)                          │
└─────────────────────────────────────────────────────────────────┘
                             ↓
                     (Rotate Board)
                             ↓
┌─────────────────────────────────────────────────────────────────┐
│  ┌───────────────────────────────────────────────────────┐      │
│  │  Setting 3: ARMOR ALERTS     [Currently: ON/OFF]      │      │
│  └───────────────────────────────────────────────────────┘      │
│                    (Audio: Tick sound)                          │
└─────────────────────────────────────────────────────────────────┘
                             ↓
                     (Rotate Board)
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
Rotate Clockwise    | Next setting (with tick sound)
Rotate Counter-CW   | Previous setting (with tick sound)
Click POWER         | Toggle setting ON/OFF
Click AUX           | Exit menu
Double-click POWER  | Exit menu (alternate)
```

### Settings Overview
```
#  | Setting        | Controls              | Default
---|----------------|-----------------------|--------
1  | Hazards        | Random hazard events  | ON
2  | Health Alerts  | Health voice warnings | ON
3  | Armor Alerts   | Armor voice warnings  | ON
4  | Clash Damage   | Physical damage       | ON
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
│              │ Single-click:  Exit menu                    │
└──────────────┴─────────────────────────────────────────────┘
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
    │  Rotate ↻ → Next setting                │
    │  Rotate ↺ → Previous setting            │
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
