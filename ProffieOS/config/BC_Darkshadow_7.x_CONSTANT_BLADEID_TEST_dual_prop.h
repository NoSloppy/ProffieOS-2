// Darkshadow_7.x_CONSTANT_BLADEID_TEST

#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 1
// #define DUAL_POWER_BUTTONS   ****not working fully, only power     // BC Make both buttons identical for 1-btn use... useful?

// ------ Audio Stuff --------

#define VOLUME 2000
#define BOOT_VOLUME 50
#define ENABLE_AUDIO
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                    // SPDIF out
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
//#define FEMALE_TALKIE_VOICE                        // BC now canon OS6
#define NO_REPEAT_RANDOM                          // BC now canon
#define KILL_OLD_PLAYERS                          // BC now canon
 #define DISABLE_TALKIE                            // I feel I'm not gonna like this

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet. Equivalent to just increasing maxLedsPerStrip.
// #define EXTRA_COLOR_BUFFER_SPACE 30

// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000> // resistor value used

// BridgedPullupBladeID is the default Proffieboard V3 BLADE_ID_CLASS, so it doesn't need to defined explicitly with a V3.
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9> // PBv2.2 TX pad for example

/*  SnapshotBladeID is the default Proffieboard V1.5 and V2.2 BLADE_ID_CLASS, so it doesn't need to defined explicitly.
    It will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value,
    so using something like 200000 instead of NO_BLADE is best. */
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin>

/*
-- Real Time BladeID --
 
Main blade must be wired to data1
Blades can use the same set of presets, or have a Presets array for each blade.
Arrays should be named differently like no_blade, blade_1, blade_2,  etc...
Match Preset array names names to the CONFIGARRAY for the given blade.

Open Serial Monitor in Arduino and type `id` to read the resistance value.
It will display "BLADE ID: (some number)"
Use that value in the blade definition in the BladeConfig.
* Note * It is recommended to use a Blade ID resistor in each blade 
to ensure different and distant enough resistance values between blades. 
However, in testing, values reported for a chassis alone,
chassis inserted into the hilt (connected to emitter PCB)
and then main blade inserted all gave different enough values on their own
without added resistors and it worked fine. YMMV.
*/

//    Blanket define to cover the following 4
// #define REAL_TIME_BLADE_ID_POWER_PINS 2, 3

                //    Use with Blade ID. Specify the LED pad(s) that the main blade uses.
                // #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>

                //    Required when blades on different data pads use common LED power pads.
                //    and/or when BLADE_ID_SCAN_MILLIS is used with Blade ID.
                // #define SHARED_POWER_PINS

                //    Choose how often to check for new blade (milliseconds).
                //    Larger values will be a longer delay before a blade is recognized.
                // #define BLADE_ID_SCAN_MILLIS 1000

                //    How many Blade ID scans to average (default is 10, works well)
                // #define BLADE_ID_TIMES 15


                // Not blanketed. This will make the blade ID class for that range return NO_BLADE (use NO_BLADE as the blade definition value.)
                // #define NO_BLADE_ID_RANGE 685000,1000000000


/////////////////////////////////// KILL ME ///////////////////////    Add this when using dual_prop

                                                                    //, and make sure the blaster preset (no blade) is first in the config file.
                                                                    //    Can be used with Blade Detect or Blade ID (including Real Time Blade ID)
                                                                     // #define DUAL_PROP_CONDITION (current_config != blades)
                                                                    // #define DUAL_PROP_CONDITION (!current_config || current_config->ohm >= NO_BLADE) // FH suggestion with NoBladeBladeId<>, but inverse dual prop behavior
                                                                    //#define DUAL_PROP_CONDITION (current_config && current_config->ohm < NO_BLADE) - WIP with NoBladeBladeId<>



//    Use Blade Detect for simple 2 way toggle. (NOPE, not 2 way only. Apparently Blade Detect can work with multiple blades too. measure each blade (and noblade) and set up> works just like blade id?!

//    Requires wiring a pad to a switched GND
//    (floating pogo pin until grounded via blade-side PCB ring)
 #define BLADE_DETECT_PIN 10 
// #define NO_BLADE_RANGE_MIN 700000 // see, had the idea back then... this is old version of NO_BLADE_ID_RANGE
// #define NO_BLADE_RANGE_MAX 800000
/* 
Blade Detect / Blade ID Tests - 2 blades + no blade in hilt.

V3 board:
Measurements using default BLADE_ID_CLASS BridgedPullupBladeID
No blade = ~750000
Blade 1 = ~650000
Blade 2 = ~40000

Using NO_BLADE for no blade instead of measured resistance
  Blade Detect - Only 40000 blade2 triggers a change. 650000 does not.
  Blade ID Constant Monitoring - Only 40000 blade2 triggers a change. 650000 does not.
  Blade ID original recipe*  - Only 40000 blade2 triggers a change. 650000 does not.
  * (no BLADE_ID_SCAN_MILLIS, read only at boot or "scanid")

Using measured value for no blade
  Blade Detect - Works great, and with more than one blade too!
  Blade ID Constant Monitoring - Works great! Blade1, blade 2, no blade, all correct.
  Blade ID original recipe - Works great.

Summary - Using NO_BLADE mistakenly chooses blade 2 because 650000 is closer to 750000 than NO_BLADE (1 billion) is.
        - Surprise! Blade Detect can use multiple blades too!
        - Of course Blade Detect has the bonus of playing bladein and bladeout sounds, which is nice.
        - Same results using dual_prop.h

V2.2  board w/ no Blade Detect wired.
Measurements using default BLADE_ID_CLASS SnapshotBladeID
Chassis only = ~595 
Chassis in hilt =  ~731
Blade 1 = ~135
Blade 2 = ~814

Measurements using BLADE_ID_CLASS BridgedPullupBladeID to TX pad.
Chassis only = ~730000
Chassis in hilt (no blade) = ~600000
Blade 1 = ~hmmm same ~600000 unfortunate. If it had ID resistor would be fine I'm sure.
Blade 2 = ~40000


Using measured value for no blade
  Blade Detect - need hilt wired BD to test
  Blade ID Constant Monitoring - Works perfectly
  Blade ID original recipe - Works great.



Conclusion:

Works on both v2.2 and V3 boards, neither requiring a BLADE_ID_CLASS manually defined (defaults worked great),
but of course bridging data1<->TX pad and using BridgedPullupBladeID is much better with a V2.2 board.
No need to use NO_BLADE in the BladeConfig. 
No real need to wire for Blade Detect anymore.
AND all of this with NO BLADE ID RESISTORS installed at all.






8/19----retest.
dual prop - blade detect. 
Given: bladein bladeout sounds only play, no boot or font wavs played.
Boot not played if blade is in.

Goal: Don't play bladein if boot plays Play font (SetPreset(0, true)) after bladein bladeout. 
Is that even a good idea?





-----Blade Detect - same results as Blade Detect dual prop
Using NO_BLADE in blade def

  Booting with blade in:
BLADE ID: 594466.69
NO Blade Detected
Blade detected or not, new value returned: 1000594496.00
blade = 0
Scanning sound font: testfont2b
 done
Scanning sound font: common
 done
Scanning sound font: commonBU
 done

unit = 0 vol = 0.50, Playing testfont2b/boot01.wav

Welcome to ProffieOS $Id: ce12a06a1e236b5101ec60c950530a9a4719a74d $

EVENT: Select-On millis=3565  // latch ON detected
BLADE ID: 639571.25
Blade Detected
Blade detected or not, new value returned: 639571.25
blade = 1

Scanning sound font: Savant01
 done
Scanning sound font: common
 done
Scanning sound font: commonBU
 done

unit = 0 vol = 0.50, Playing commonBU/bladein.wav


-----Blade ID

-----Real Time Blade ID

-----Blade Detect dual prop
After boot, it works w/ orig code 
But at boot, always starts in no-blade preset and plays boot from no-blade font.
At boot, ProffieOS.ino calls FindBlade()->FindBestConfig()->id().
Then it does SaberBase::DoBoot(); and plays boot.wav.
blade_detected_ is initialized false and id() runs before any change to the var occur.
Because !blade_detected_ is true, the returned ID get's NO_BLADE added to it.

So then if blade is in at boot, no-blade preset's font's boot wants to play, but bladein interrupts it as the prop detects LATCH_ON.
Editing hybrid_font SB_Effect case EFFECT_BOOT to wait for boot to finish using 
`while (GetWavPlayerPlaying(&SFX_boot))`
allows boot to indeed play in full, but it's still the no-blade preset's boot, followed by bladein of the bladein preset's font.
Ideally, bladein wouldn't play, because the id() is just read correctly,
 not ret += NO_BLADE,  (if Boot without a blade in, it's fine. Plays no-blade preset's font's boot.wav and done.)

goal : if no blade is in when booting, just play the boot wav. the first blade detection (bladein) should trigger SB_BladeDetect (true).
If there is a blade already present when booting, LATCH_ON from my prop is going to call SB_BladeDetect after boot plays, so i want that to skip, but function normally afterwards.
The way it works now is good, but the no-blade-at-boot scenario causes the first blade insertion to skip the sound


 So the question is - is NO_BLADE really required if the user can always just type "id" and set the 
 no-blade blade to that value? I suppose it is because if using default SnapshotBladeID on V2 and a BLADE_DETECT_PIN is defined,
 ,the results would be too irregular?

----- Blade ID dual prop

----- Real Time Blade ID dual prop


*/
// ------ SD Card Stuff -------

#define ENABLE_SD
//#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//    presets.ini/tmp is ignored after reprogramming unless this is defined.
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING

// ------- OLED stuff ----------

// #define ENABLE_SSD1306                         // OLED display. also defines ENABLE_DISPLAY_CODE
// #define OLED_FLIP_180                          // BC now canon
// #define OLED_MIRRORED                          // BC now canon
// #define USE_AUREBESH_FONT                      // BC now canon
// #define OLED_SYNCED_EFFECTS
// #define PLI_OFF_TIME 60 * 5 * 1000
// #define OLED_USE_BLASTER_IMAGES
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144_SC_POV_data.h"
// #define POV_INCLUDE_FILE "Raiden_123_FC_POV_data.h"
// #define POV_INCLUDE_FILE "JohnCena_144_8b_POV_data.h"

// ------ System Stuff --------

// #define ENABLE_DEBUG
// #define PROFFIEOS_LOG_LEVEL 300
//    PVLOG_ERROR 100 = errors
//    PVLOG_STATUS 200 = things you should probably know, like blade ID
//    PVLOG_NORMAL 300 = normal information about what is happening (default level)
//    PVLOG_DEBUG 400 = information helpful for debugging
//    PVLOG_VERBOSE 500 = repeated, spammy information you don't normally want
// #define PROFFIEOS_LOG_LEVEL 300

// #define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
// #define ENABLE_DEVELOPER_COMMANDS
// #define DISABLE_DIAGNOSTIC_COMMANDS
//    Disable Old School original templated styles, like StyleNormalPtr<CYAN, WHITE, 300, 800>()
#define DISABLE_BASIC_PARSER_STYLES
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_CCW_FROM_BLADE
// #define ORIENTATION ORIENTATION_USB_CW_FROM_BLADE
//    The following changes the angle required to register twists on curved hilts.
//    Example is for Assaj Ventress curved hilt install.
// #define ORIENTATION_ROTATION 0,-20,0

// #define CONFIG_STARTUP_DELAY 15000               // BC now canon

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3.5
#define BC_SWING_ON
#define BC_SWING_ON_SPEED 600 // Default 250
// #define BC_STAB_ON
#define BC_THRUST_ON
//#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
//    BC Multiblast continues as long as swinging within 1 second. 
#define BC_ENABLE_AUTO_SWING_BLAST
#define ENABLE_SPINS
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
/*    If using blade detect, Gesture ignitions or retractions are 
      disabled when no blade is used. BC prop.
      **NOTE** Only works when a BLADE_DETECT_PIN is defined.*/
//#define NO_BLADE_NO_GEST_ONOFF

// ------- Custom / Experimental / Alpha-Beta stuff ---------

//    BC - THIS NEEDS TO BE CheckLowBattry(), see PR     **Requires modified hybrid_font.h file.
// #define LOW_BATT_ONCE
//    This can save some RAM, but it's not compatible with IntArg/RgbArg (Edit Mode compatible stuff)
// #define OPTIMIZE_TRCONCAT
#define DIAGNOSTIC_STARTUP_DELAY_FOR_SERIAL_MONITOR // BC 3000ms delay to catch all messages.

// -------- BC Prop Other Stuff --------

// #define NO_VOLUME_MENU                         // BC prop. Self evident, but why?

// -------- Blaster Stuff ----------

#define BLASTER_ENABLE_AUTO
#define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
#define BLASTER_JAM_PERCENTAGE 4     // if not defined, random.
#define BLASTER_DEFAULT_MODE MODE_KILL

// -------- Fett263 Stuff ----------
// #define ENABLE_ALL_MENU_OPTIONS
    //#define DYNAMIC_BLADE_DIMMING
    //#define DYNAMIC_CLASH_THRESHOLD
    //#define SAVE_VOLUME
    //#define SAVE_BLADE_DIMMING
    //#define SAVE_CLASH_THRESHOLD
    //#define SAVE_COLOR_CHANGE

#endif

#ifdef CONFIG_PROP // Leave buttons as POW and AUX down in CONFIG_BUTTONS
#include "../props/dual_prop.h"
#include "../props/saber_BC_buttons_personal.h"
#undef PROP_TYPE
#include "../props/blaster_BC_buttons.h"
#undef PROP_TYPE
#define PROP_TYPE SaberBlasterProp<SaberBCButtons, BlasterBCButtons>
#endif
// #ifdef CONFIG_PROP // Leave buttons as POW and AUX down in CONFIG_BUTTONS
// #include "../props/dual_prop.h"
// #include "../props/saber.h"
// #undef PROP_TYPE
// #include "../props/blaster.h"
// #undef PROP_TYPE
// #define PROP_TYPE SaberBlasterProp<Saber, Blaster>
// #endif
#ifdef CONFIG_PRESETS
// #include "aliases/TrueWhites/BC_effects_1.h"              // For Red, Green, light Blue, ...light colored blades
// #include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"  // EffectSequence driven different blast animations
// #include "aliases/TrueWhites/BC_effects_2.h"              // for crystals chambers or accents
// #include "aliases/TrueWhites/BC_effects_Red.h"            // For Red or dark blades
// #include "aliases/TrueWhites/BC_effects_White.h"          // For White blades
// #include "aliases/TrueWhites/BC_12color_8effect_SS.h"     // All in one blade style from CC Fork. SS = SwingSpeed included 


Preset blade_0 [] = {

{ "blade0;testblaster;common;commonB", "testblaster/tracks/track1.wav",

  StylePtr<Layers<
  Blue,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Blue,800>>>>(),
    StylePtr<Layers<
  Blue,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Blue,800>>>>(),
    StylePtr<Layers<
  Blue,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Blue,800>>>>(),
    StylePtr<Layers<
  Blue,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Blue,800>>>>(),
  //   StylePtr<Layers<
  // Blue,
  // InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Blue,800>>>>(),
StylePtr<Blue>(),
  "************ NO BLADE INSERTED"}


};

//----------------------------------------------------------------------------------------------------------------------------------------

Preset blade_1 [] = {

{ "blade1;Savant01;common;commonBU", "aa_JayDalorian/nobunaga/tracks/sharingan.wav",
  StylePtr<Layers<
  Red,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Red,800>>>>(),
    StylePtr<Layers<
  Red,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Red,800>>>>(),
    StylePtr<Layers<
  Red,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Red,800>>>>(),
    StylePtr<Layers<
  Red,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Red,800>>>>(),
StylePtr<Blue>(),
"************ blade_1 INSERTED"}

};


//----------------------------------------------------------------------------------------------------------------------------------------

Preset blade_2 [] = {

{ "blade2;Dooku_CW;common;commonBU", "",
  StylePtr<Layers<
  Green,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Green,800>>>>(),
    StylePtr<Layers<
  Green,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Green,800>>>>(),
    StylePtr<Layers<
  Green,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Green,800>>>>(),
    StylePtr<Layers<
  Green,
  InOutTrL<TrWipe<300>,TrWipeIn<500>,Pulsing<Black,Green,800>>>>(),
StylePtr<Blue>(),
"*********** blade_2 INSERTED"}

};


//----------------------------------------------------------------------------------------------------------------------------------------

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


{ NO_BLADE, // for Blade Detect // blade = 0
// { 750000, // for Blade ID...or just fine for both?
  WS281XBladePtr<0, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(blade_0)},

{ 650000,                       // blade = 1
  WS281XBladePtr<100, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(blade_1)},

{ 40000,                       // blade = 2
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(blade_2)},

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
