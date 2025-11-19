// BC_Scoundrel_6.x_CONSTANT_BLADEID_TEST

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 1
// #define DUAL_POWER_BUTTONS   ****not working fully, only power     // BC Make both buttons identical for 1-btn use... useful?

// ------ Audio Stuff --------

#define VOLUME 2000
#define BOOT_VOLUME 200
#define ENABLE_AUDIO
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                    // SPDIF out
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
#define FEMALE_TALKIE_VOICE                        // BC now canon OS6
#define NO_REPEAT_RANDOM                          // BC now canon
#define KILL_OLD_PLAYERS                          // BC now canon
// #define DISABLE_TALKIE                            // I feel I'm not gonna like this
// #define VOLUME_MENU_CYCLE     **** DEAD          // quick MAX MIN now

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet.Equivalent to just indrasing maxLedsPerStrip.
// #define EXTRA_COLOR_BUFFER_SPACE 30
#define SHARED_POWER_PINS
// #define BLADE_DETECT_PIN blade4Pin
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9>         // TX pad
//    This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
//    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value, so I would recommend using something like 200000 instead of NO_BLADE.
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> 
//    Millis is BladeID scan interval. If the blade ID comes out the same as before, it will do nothing.
//    If it comes out different, it will do FindBladeAgain(), which will basically initialize the saber from scratch and load the right settings for the new id().
//    It will only work with neopixel blades, and it requires SHARED_POWER_PINS to work. Also needs BLADE_ID_TIMES N, which reads blade ID N times and take the average.
#define BLADE_ID_SCAN_MILLIS 1000
//    How many Blade ID scans to average
#define BLADE_ID_TIMES 10
// BC make work with Blade ID const monitoring , not just blade detect
// Need to use the ID values you see reprted in Serial Monitor for the blade definition.
// not NO_BLADE. NO_BLADE only works with Blade Detect.
#define DUAL_PROP_CONDITION (current_config != blades)

// ------ SD Card Stuff -------

#define ENABLE_SD
//#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
     #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//    Upload overwrites presets.ini/tmp unless this is defined
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING 

// ------- OLED stuff ----------

// #define ENABLE_SSD1306                         // OLED display. also defines ENABLE_DISPLAY_CODE
// #define OLED_FLIP_180                          // BC now canon
// #define USE_AUREBESH_FONT                      // BC now canon
// #define OLED_SYNCED_EFFECTS
// #define PLI_OFF_TIME 60 * 5 * 1000
//#define OLED_USE_BLASTER_IMAGES
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144_SC_POV_data.h"
// #define POV_INCLUDE_FILE "Raiden_123_FC_POV_data.h"
// #define POV_INCLUDE_FILE "JohnCena_144_8b_POV_data.h"

// ------ System Stuff --------

// #define ENABLE_DEBUG
// #define NO_BATTERY_MONITOR
// #define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
// #define ENABLE_DEVELOPER_COMMANDS
// #define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES                 // Standard, Advanced, Old School original templated styles etc...
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SDA_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE
//    The following changes the angle required to register twists on curved hilts.
//    Example is for Assaj Ventress curved hilt install.
// #define ORIENTATION_ROTATION 0,-20,0

// #define CONFIG_STARTUP_DELAY 15000               // BC now canon
#define NO_REPEAT_RANDOM
#define KILL_OLD_PLAYERS

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3.5
//#define BC_SWING_ON                                 // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
// #define BC_STAB_ON
#define BC_THRUST_ON
//#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                     // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS
#define ENABLE_AUTO_SPINS_BLAST                     // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
// #define NO_BLADE_NO_GEST_ONOFF                   // If using blade detect, No Blade = No Gesture ignitions or retractions

// ------- Custom / Experimental / Alpha-Beta stuff ---------

// #define LOW_BATT_ONCE                            // BC - THIS NEEDS TO BE CheckLowBattry(), see PR     **Requires modified hybrid_font.h file.
// #define LOW_BATT_WARNINGS_TIERED                 // meh...just annoying if not accurate..likely.       **Requires modified hybrid_font.h file.
// #define ENABLE_GESTURE_MENU                      // PSISTORM prop - cool stuff! the TrySound else beep void.

// -------- BC Prop Other Stuff --------

// #define NO_VOLUME_MENU                           // self evident. But why?

// -------- Blaster Stuff ----------

#define BLASTER_ENABLE_AUTO
#define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
#define BLASTER_JAM_PERCENTAGE 4     // if not defined, random.
#define BLASTER_DEFAULT_MODE MODE_KILL

#endif

#ifdef CONFIG_PROP // Leave buttons as POW and AUX down in CONFIG_BUTTONS
#include "../props/dual_prop.h"
#include "../props/saber_BC_buttons_personal.h"
#undef PROP_TYPE
#include "../props/blaster_BC_buttons.h"
#undef PROP_TYPE
#define PROP_TYPE SaberBlasterProp<SaberBCButtons, BlasterBC>
#endif

// #ifdef CONFIG_PROP

// #include "../props/blaster_BC_buttons.h"

// #endif

#ifdef CONFIG_PRESETS
// #include "aliases/TrueWhites/BC_effects_1.h"              // For Red, Green, light Blue, ...light colored blades
// #include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"  // EffectSequence driven different blast animations
// #include "aliases/TrueWhites/BC_effects_2.h"              // for crystals chambers or accents
// #include "aliases/TrueWhites/BC_effects_Red.h"            // For Red or dark blades
// #include "aliases/TrueWhites/BC_effects_White.h"          // For White blades
// #include "aliases/TrueWhites/BC_12color_8effect_SS.h"     // All in one blade style from CC Fork. SS = SwingSpeed included 


Preset nothing [] = {


{ "testblaster;common;commonB", "",
  StylePtr<Layers<
  Green,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Green,800>>>>(),
  "************ CHASSIS REMOVED"
}
};
//----------------------------------------------------------------------------------------------------------------------------------------

Preset NPXL [] = {

{ "aa_NoSloppy/KITT;common;commonBU", "",
  StylePtr<Layers<
  Red,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Red,800>>>>(),
  "*********** CHASSIS INSERTED"
}


};

//----------------------------------------------------------------------------------------------------------------------------------------

Preset bladein [] = {

{ "aa_NoSloppy/Crushed;common;commonBU", "",
  StylePtr<Layers<
  Blue,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Blue,800>>>>(),
  "************ BLADE INSERTED"
}

};

//----------------------------------------------------------------------------------------------------------------------------------------



BladeConfig blades[] = {
{ 513, // *********** CHASSIS REMOVED - SnapshotBladeID - not far enough values
  // { 733000, // *********** CHASSIS REMOVED - BridgedPullupBladeID TX pin 9
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
CONFIGARRAY(nothing)}, 

{ 634, // ************ CHASSIS INSERTED - SnapshotBladeID - not far enough values
// { 630000, // ************ CHASSIS INSERTED - BridgedPullupBladeID TX pin 9
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
CONFIGARRAY(NPXL)}, 

{ 720, // ************ BLADE INSERTED - HiltPCB and Main Blade in parallel - SnapshotBladeID - not far enough values
// { 500000, // ************ BLADE INSERTED - HiltPCB and Main Blade in parallel- BridgedPullupBladeID TX pin 9
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
CONFIGARRAY(bladein)}, 


};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

// #ifdef CONFIG_BUTTONS
// Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
// Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");
// #endif

