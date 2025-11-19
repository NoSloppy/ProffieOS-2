// This is a sample configuration file.
// This saber has:
//   o Proffieboard V1 hardware.
//   o Two buttons
//   o An XP-E2 RGB LED star on LED 4-5-6
//   o A neopixel blade on LED 1-2-3 and neopixel data 1.
// If you have a saber similar to this one, make a copy and use the copy.
// This is also the default configuration file. Pre-programmed boards will
// use this configuration file.

#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 2
#define VOLUME 100
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define SAVE_STATE
#define ENABLE_ALL_EDIT_OPTIONS
#define IDLE_OFF_TIME  5 * 1 * 1000

//#define SHARED_POWER_PINS
#endif
// #ifdef CONFIG_TOP
// #include "proffieboard_v3_config.h"
// #define NUM_BLADES 5
// #define NUM_BUTTONS 1
// #define VOLUME 100
// const unsigned int maxLedsPerStrip = 144;
// // #define EXTRA_COLOR_BUFFER_SPACE 30               // New define that can speed up processing a bit. Basically, it can calculate the colors for the next blade (or the next frame for the same blade) even though it's not done feeding out the data for the data in the color buffer yet.
// #define CLASH_THRESHOLD_G 3.5
// #define ENABLE_AUDIO
// #define ENABLE_MOTION
// #define ENABLE_WS2811
// #define ENABLE_SD
// #define ENABLE_SERIAL // Bluetooth
// // #define ENABLE_SSD1306 //OLED
// // #define DISABLE_COLOR_CHANGE
// #define SHARED_POWER_PINS
// #define SAVE_STATE
//     // #define SAVE_VOLUME
//     // #define SAVE_PRESET
//     // #define SAVE_COLOR_CHANGE
//     // #define SAVE_BLADE_DIMMING
// // #define KEEP_SAVEFILES_WHEN_PROGRAMMING        // upload overwrites presets.ini/tmp unless this is defined
// #define BLADE_DETECT_PIN 10
// #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// // #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> // This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors 
// // #define SPEAK_BLADE_ID
// // #define ENABLE_I2S_OUT
// // #define ENABLE_SPDIF_OUT
// // #define LINE_OUT_VOLUME 2000                   // SPDIF out
// #define ENABLE_DEVELOPER_COMMANDS
// //#define DISABLE_DIAGNOSTIC_COMMANDS
// #define IDLE_OFF_TIME 60 * 1 * 1000
// #define MOTION_TIMEOUT 60 * 5 * 1000
// // #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// // #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// // #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// // #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// // #define ORIENTATION ORIENTATION_SDA_TOWARDS_BLADE
// // #define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE
// // #define ORIENTATION_ROTATION 0,-20,0
// //changes the angle required to register twists on curved hilts
// //example is for assaj ventress curved hit install
// // #define CONFIG_STARTUP_DELAY 15000             // BC now canon
// // #define OLED_FLIP_180                          // BC now canon
// // #define USE_AUREBESH_FONT                      // BC now canon
// #define FEMALE_TALKIE_VOICE                    // BC now canon
// #define VOLUME_MENU_CYCLE                         // BC now canon
// #define NO_REPEAT_RANDOM                          // BC now canon

// // ------- Gesture stuff -------

// // #define BC_SWING_ON                               // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
// // #define BC_STAB_ON
// #define BC_THRUST_ON
// #define BC_TWIST_ON
// #define BC_TWIST_OFF
// // #define BC_FORCE_PUSH
// // #define BC_FORCE_PUSH_LENGTH 5
// #define ENABLE_SPINS
// // #define GESTURE_AUTO_BATTLE_MODE
// #define BC_LOCKUP_DELAY 200

// // ------- Custom / Experimental / Alpha-Beta stuff ---------
// #define NO_VOLUME_MENU                            // self evident
// #define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second. 
// #define DISABLE_BASIC_PARSER_STYLES               // Standard, Advanced, etc...
// // *********** #define USE_WAVS_FOR_TALKIE        // WAS BC Personal only because delay() is not great. Now sound_library
// // *********** #define PREONS_MATCH_BLADE_EFFECTS // has become official as WavNum function (pass to ColorSelect and list the preons)
// // *********** #define PREONS_MATCH_OUTS          // has become config.ini entry ProffieOS.SFX.EFFECTNAME.paired=0 Where EFFECTNAME can be “preon”, “out”, “pstoff”, etc. SAME NUMBER to activate.
// // *********** #define PSTOFFS_MATCH_INS
// #define NO_BLADE_NO_GEST_ONOFF                    // If using blade detect, No Blade = No Gesture ignitions or retractions
// #define AUTO_HUMSTART                             // 200ms delay from on.wav beginning all the time.             **Requires modified hybrid_font.h file.
// #define ENABLE_AUTO_SPINS_BLAST                   // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// // #define LOW_BATT_ONCE                          // No repeated warnings
// // #define LOW_BATT_WARNINGS_TIERED                // meh...just annoying if not accurate..likely.                                                            **Requires modified hybrid_font.h file.
// // #define FILTER_CUTOFF_FREQUENCY 100
// // #define FILTER_ORDER 8
// // #define ENABLE_GESTURE_MENU                    // PSISTORM prop - cool stuff! the TrySound else beep void.

//  #define ENABLE_ALL_EDIT_OPTIONS                   // Fett263 OS 6
//     // #define DYNAMIC_BLADE_LENGTH
//     // #define DYNAMIC_BLADE_DIMMING
//     // #define DYNAMIC_CLASH_THRESHOLD
//     // #define SAVE_VOLUME
//     // #define SAVE_BLADE_DIMMING
//     // #define SAVE_CLASH_THRESHOLD
//     // #define SAVE_COLOR_CHANGE

// #endif
#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h" // Lately, preferring #define NUM_BUTTONS 1
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
{ "a_DARKSABER/DarkV3;common;commonBU", "a_DARKSABER/DarkV3/tracks/Mandalorian.wav",
  StylePtr<Red>(),
    StylePtr<Red>(),
      StylePtr<Red>(),
        StylePtr<Red>(),    // StyleNormalPtr<CYAN, WHITE, 300, 800>(),
    // StyleNormalPtr<CYAN, WHITE, 300, 800>(),
    // StyleNormalPtr<CYAN, WHITE, 300, 800>(),
    // StyleNormalPtr<CYAN, WHITE, 300, 800>(),
//Bluetooth
  StylePtr<Blue>(), "cyan"},
//  { "testfont2a;common;commonBU", "testfont2a/tracks/track3.wav", // Accel out and in.
//     StylePtr<InOutSparkTip<EASYBLADE(BLUE, WHITE), 300, 800> >(),
//     StylePtr<InOutSparkTip<EASYBLADE(BLUE, WHITE), 300, 800> >(),
//     StylePtr<InOutSparkTip<EASYBLADE(BLUE, WHITE), 300, 800> >(),
//     StylePtr<InOutSparkTip<EASYBLADE(BLUE, WHITE), 300, 800> >(),
// // Bluetooth
//   StylePtr<Blue>(), "blue"},
// preset 1
{ "testfont2a;common;commonBU", "testfont2a/tracks/track1.wav",
// Main Blade
 //   StylePtr<LengthFinder<>>(),
StylePtr<Blue>(),
// Hilt PCB
  // StylePtr<Layers<
  //   Pulsing<Blue,Black,200>,
  //   InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
 StylePtr<Rainbow>(),

// Switches
StylePtr<Blue>(),
// Pommel
StylePtr<Blue>(),
  // StylePtr<Layers<
  //   Pulsing<Blue,Black,200>,
  //   InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// Bluetooth
  StylePtr<Blue>(),
"testfont2a"},

{ "a_BANE/RuleOfTwo;common;commonBU", "a_BANE/tracks/track3.wav", // Testing IceForce monosfx
  StylePtr<Green>(),
    StylePtr<Green>(),
      StylePtr<Green>(),
        StylePtr<Green>(),    // StyleFirePtr<RED, YELLOW, 0>(),
    // StyleFirePtr<RED, YELLOW, 0>(),
    // StyleFirePtr<RED, YELLOW, 0>(),
    // StyleFirePtr<RED, YELLOW, 0>(),
// Bluetooth
  StylePtr<Blue>(), "fire"}
  
};

struct AccentsLED {
static constexpr float MaxAmps = 0.02;
static constexpr float MaxVolts = 3.2;
static constexpr float P2Amps = 0.10;
static constexpr float P2Volts = 3.0;
static constexpr float R = 0; // Resistor value
static const int Red = 0;
static const int Green = 0;
static const int Blue = 255;
};

BladeConfig blades[] = {
{ NO_BLADE,                                      // D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<10, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches 
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(presets),
"00_NO_BLADE_save"}, 
  };
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
