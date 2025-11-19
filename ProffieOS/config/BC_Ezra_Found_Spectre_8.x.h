// BC_Ezra_Found_Spectre_8.x.h


#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BUTTONS 1
#define NUM_BLADES 3

// ------ Audio Stuff --------

#define VOLUME 2000
#define BOOT_VOLUME 100
// #define ENABLE_AUDIO     defaulted OS8
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                   // SPDIF out
#define FILTER_CUTOFF_FREQUENCY 90
#define FILTER_ORDER 8
// #define FEMALE_TALKIE_VOICE
// #define NO_REPEAT_RANDOM     defaulted OS8
// #define KILL_OLD_PLAYERS     defaulted OS8
// #define DISABLE_TALKIE
#define ENABLE_FASTON

// ------ Blade Stuff ------

// #define ENABLE_WS2811     defaulted OS8
const unsigned int maxLedsPerStrip = 144;
//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet. Equivalent to just increasing maxLedsPerStrip.
#define EXTRA_COLOR_BUFFER_SPACE 30

// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000> // resistor value used

// BridgedPullupBladeID is the default Proffieboard V3 BLADE_ID_CLASS, so it doesn't need to defined explicitly with a V3.
//#define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9> // PBv2.2 TX pad for example

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
#define REAL_TIME_BLADE_ID_POWER_PINS 2, 3

                //    Use with Blade ID. Specify the LED pad(s) that the main blade uses.
                 // #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>

                //    Required when blades on different data pads use common LED power pads.
                //    and/or when BLADE_ID_SCAN_MILLIS is used with Blade ID.
                 // #define SHARED_POWER_PINS

                //    Choose how often to check for new blade (milliseconds).
                //    Larger values will be a longer delay before a blade is recognized.
                 // #define BLADE_ID_SCAN_MILLIS 1000

                //    How many Blade ID scans to average (default is 10, works well)
                 // #define BLADE_ID_TIMES 10

                // Not blanketed. This will make the blade ID class for that range return NO_BLADE (use NO_BLADE as the blade definition value.)
                 #define NO_BLADE_ID_RANGE 400,600

// Show blade ID value every BLADE_ID_SCAN_MILLIS
// #define SCAN_BLADE_ID_MONITORING

//    Requires wiring a pad to a switched GND
//    (floating pogo pin until grounded via blade-side PCB ring)
// #define BLADE_DETECT_PIN 10 

#define DYNAMIC_BLADE_LENGTH

// #define BC_DUAL_BLADES
// BLADE # corresponds to the blades list in the BladeConfig section of the config file.
// Defaults are BLADE 1 and BLADE 2 as MAIN and SECOND blades respectively.
// Optionally, you can also manually define custom dual blades if different than 1 and 2, for example:
// #define BC_MAIN_BLADE 2
// #define BC_SECOND_BLADE 4

// ------ SD Card Stuff -------

//#define ENABLE_SD     defaulted OS8
#define MOUNT_SD_SETTING  // This define will allow manual control of when to allow the SD to mount to the computer when Mass Storage is enabled by issuing "sd 1" in Serial Monitor.
// First let's review how Mass Storage works. Having the Arduino setting Tools>USB Type> Serial + Mass Storage selected allows the SD card to be accessed over USB (using the Proffieboard as a card reader).  
// The way it used to work before OS8 and this define was after the boot sound played, the SD card would immediately mount to the computer as an external USB drive. File transfers could take place then, and when finished, you would eject the SD from the computer. From then, the Proffieboard would use it as normal.
// This meant that you always had to wait for the SD card to mount, and then eject it before uploading or using Serial Monitor. It also meant that to re-access the SD, you'd need to either reboot, or unplug and then re-plug the USB cable.
// Now here's how it can work in OS8 using #define MOUNT_SD_SETTING.  
// Even though Mass Storage was selected and uploaded, this define prevents the SD card from mounting until manually "allowed" by the user.
// To allow the SD to mount, send the command "sd 1" in Serial Monitor. When you finish accessing the SD card and "eject" it from the computer, the Proffieboard will use it as normal and set the permission back to FALSE.
// If you want to access the SD again, you can just issue the  "sd 1" command again, and repeat as above.

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
// #define OLED_MIRRORED                          // BC now canon
// #define USE_AUREBESH_FONT                      // BC now canon
// #define OLED_SYNCED_EFFECTS
// #define PLI_OFF_TIME 60 * 5 * 1000
// #define OLED_USE_BLASTER_IMAGES
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144_SC_POV_data.h"

// ------ System Stuff --------

 //#define ENABLE_DEBUG
//    PVLOG_ERROR 100 = errors
//    PVLOG_STATUS 200 = things you should probably know, like blade ID
//    PVLOG_NORMAL 300 = normal information about what is happening (default level)
//    PVLOG_DEBUG 400 = information helpful for debugging
//    PVLOG_VERBOSE 500 = repeated, spammy information you don't normally want
// #define PROFFIEOS_LOG_LEVEL 300

// #define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
// #define COLOR_CHANGE_DIRECT
// #define ENABLE_DEVELOPER_COMMANDS
#define DISABLE_DIAGNOSTIC_COMMANDS
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

// #define CONFIG_STARTUP_DELAY 3000               // BC now canon

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_SPINS
// --- BC prop stuff -----
#define BC_SWING_ON
#define BC_SWING_ON_SPEED 300 // Default 250
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 10
//    BC Multiblast continues as long as swinging within 1 second. 
#define BC_ENABLE_AUTO_SWING_BLAST
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
/*    If using blade detect, Gesture ignitions or retractions are 
      disabled when no blade is used. BC prop.
      **NOTE** Only works when a BLADE_DETECT_PIN is defined.*/
//#define NO_BLADE_NO_GEST_ONOFF

// ------- Custom / Experimental / Alpha-Beta stuff ---------

// #define LOW_BATT_ONCE                            // BC - THIS NEEDS TO BE CheckLowBattry(), see PR     **Requires modified hybrid_font.h file.
// #define LOW_BATT_WARNINGS_TIERED                 // meh...just annoying if not accurate..likely.       **Requires modified hybrid_font.h file.
// #define ENABLE_GESTURE_MENU                      // PSISTORM prop - cool stuff! the TrySound else beep void.
// #define OPTIMIZE_TRCONCAT                       // this TRCONCAT can save some RAM, but it's not compatible with IntArg/RgbArg

// -------- BC Prop Other Stuff --------

// As of OS8, a System Menu is available to edit presets, colors and more. Also, Edit Settings menu to edit volume or blade length
//#define MENU_SPEC_TEMPLATE DefaultMenuSpec

// For Dynamic Blade Length adjustment, the menu system will default to 1 removable blade. If there are more, use this define
// with the blades numbers based on the BladeConfig array entry order, separated by a commas 
// #define REMOVABLE_BLADES 1, 2

// -------- Blaster Stuff ----------

// #define BLASTER_ENABLE_AUTO
// #define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
// #define BLASTER_JAM_PERCENTAGE 4     // if not defined, random.
// #define BLASTER_DEFAULT_MODE MODE_KILL

#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"                 // For Red, Green, light Blue, ...light colored blades
// #include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"     // EffectSequence driven different blast animations
#include "aliases/TrueWhites/BC_effects_2.h"                 // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"               // For Red or dark blades
// #include "aliases/TrueWhites/BC_effects_White.h"             // For White blades
#include "aliases/TrueWhites/BC_12color_8effect_SS.h"        // All in one blade style from CC Fork. SS = SwingSpeed included 

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrSmoothFade<200>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrDelay<1000>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

// // BC_Bend2
//     InOutTrL<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<175000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,

// // BC_SparkTipOut_Bend2
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,

// // BC_SparkTipOUTandIN_Bend2 (50% White OUT, LightCyan IN)
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInSparkTipX<LightCyan,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInSparkTipX<LightCyan,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>,


/* ---- Presets list ---- /*

1. a_EZRA/Nomad
2. a_EZRA/LothHero
3. a_EZRA/Spectre6
4. a_KANAN/BlindMaster2
5. a_KANAN/CalbDume
6. aa_NoSloppy/Crushed
7. aa_Blueforce/DarkSpace
8. aa_Blueforce/LiquidStatic
9. aa_JayDalorian/Parsec1

{ "a_EZRA/Nomad;ProffieOS_Voicepack_Ezra/common;commonBU", "a_EZRA/Nomad/tracks/track2.wav",
{ "a_EZRA/LothHero;ProffieOS_Voicepack_Ezra/common;commonBU", "a_EZRA/LothHero/tracks/track1.wav",
{ "a_EZRA/Spectre6;ProffieOS_Voicepack_Ezra/common;commonBU", "a_EZRA/LothHero/tracks/track1.wav",
{ "a_KANAN/BlindMaster2;ProffieOS_Voicepack_Ezra/common;commonBU", "a_KANAN/tracks/CantProtectEzraForever.wav",
{ "a_KANAN/CalbDume;ProffieOS_Voicepack_Ezra/common;commonBU", "a_KANAN/tracks/CantProtectEzraForever.wav",
{ "aa_NoSloppy/Crushed;ProffieOS_Voicepack_Ezra/common;commonBU", "",
{"aa_Blueforce/DarkSpace;ProffieOS_Voicepack_Ezra/common;commonBU", "Proto2/tracks/proto1.wav", 
{ "aa_Blueforce/LiquidStatic;ProffieOS_Voicepack_Ezra/common;commonBU", "",
{ "aa_JayDalorian/Parsec1;ProffieOS_Voicepack_Ezra/common;commonBU", "",
*/


Preset Found [] = {


{ "a_EZRA/Nomad;ProffieOS_Voicepack_Ezra/common;commonBU", "a_EZRA/Nomad/tracks/track2.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,Mix<Int<8000>,RotateColorsX<Variation,DeepSkyBlue>,Black>>,
BC_effects_1,
  // BC_Bend2
    InOutTrL<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<175000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Top
  StylePtr<Layers<
    ColorCycle<
      Pulsing<RotateColorsX<Variation,DeepSkyBlue>,Mix<Int<25000>,RotateColorsX<Variation,DeepSkyBlue>,Black>,2000>,15,30,  // OFF
      Pulsing<RotateColorsX<Variation,DeepSkyBlue>,Mix<Int<18000>,RotateColorsX<Variation,DeepSkyBlue>,Black>,300>,25,100,  // ON
    1000>,  // transition time
BC_effects_2,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Bottom
  StylePtr<Layers<
    Pulsing<RotateColorsX<Variation,DeepSkyBlue>,Mix<Int<18000>,RotateColorsX<Variation,DeepSkyBlue>,Black>,300>,
BC_effects_2,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,RotateColorsX<Variation,DeepSkyBlue>,4000>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"nomad"},


{ "a_EZRA/LothHero;ProffieOS_Voicepack_Ezra/common;commonBU", "a_EZRA/LothHero/tracks/track1.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Green>,Mix<Int<8000>,RotateColorsX<Variation,Green>,Black>>,
BC_effects_1,
  // BC_Bend2
    InOutTrL<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<175000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Top
  StylePtr<Layers<
    ColorCycle<
      Pulsing<RotateColorsX<Variation,Green>,Mix<Int<25000>,RotateColorsX<Variation,Green>,Black>,2000>,15,30,  // OFF
      Pulsing<RotateColorsX<Variation,Green>,Mix<Int<18000>,RotateColorsX<Variation,Green>,Black>,300>,25,100,  // ON
    1000>,  // transition time
BC_effects_2,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Bottom
  StylePtr<Layers<
    Pulsing<RotateColorsX<Variation,Green>,Mix<Int<18000>,RotateColorsX<Variation,Green>,Black>,300>,
BC_effects_2,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,RotateColorsX<Variation,Green>,4000>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"loth\nhero"},


{ "a_EZRA/Spectre6;ProffieOS_Voicepack_Ezra/common;commonBU", "a_EZRA/LothHero/tracks/track1.wav",
  StylePtr<Layers<
    BC_12color_8effect_SS,
BC_effects_Red,
  // BC_SparkTipOut_Bend2
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Top
  StylePtr<Layers<
    ColorCycle<
      Pulsing<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,Mix<Int<25000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,Black>,2000>,15,30,  // OFF
      Pulsing<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,Mix<Int<25000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,Black>,300>,25,100,  // ON
    1000>,  // transition time
BC_effects_2,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Bottom
  StylePtr<Layers<
    Pulsing<
                     ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
      Mix<Int<18000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,Black>,300>,
BC_effects_2,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,4000>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"loth\nhero"},


{ "a_KANAN/BlindMaster2;ProffieOS_Voicepack_Ezra/common;commonBU", "a_KANAN/tracks/CantProtectEzraForever.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,Mix<Int<8000>,RotateColorsX<Variation,DeepSkyBlue>,Black>>,
BC_effects_1,
  // BC_Bend2
    InOutTrL<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<175000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Top
  StylePtr<Layers<
    ColorCycle<
      Pulsing<RotateColorsX<Variation,DeepSkyBlue>,Mix<Int<25000>,RotateColorsX<Variation,DeepSkyBlue>,Black>,2000>,15,30,  // OFF
      Pulsing<RotateColorsX<Variation,DeepSkyBlue>,Mix<Int<18000>,RotateColorsX<Variation,DeepSkyBlue>,Black>,300>,25,100,  // ON
    1000>,  // transition time
BC_effects_2,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Bottom
  StylePtr<Layers<
    Pulsing<RotateColorsX<Variation,DeepSkyBlue>,Mix<Int<18000>,RotateColorsX<Variation,DeepSkyBlue>,Black>,300>,
BC_effects_2,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,RotateColorsX<Variation,DeepSkyBlue>,4000>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"blind\nmaster"},

{ "a_KANAN/CalbDume;ProffieOS_Voicepack_Ezra/common;commonBU", "a_KANAN/tracks/CantProtectEzraForever.wav",
  StylePtr<Layers<
    // AudioFlicker<Rgb<0,60,200>,Blue>,
    BC_12color_8effect_SS, // 1. AudioFlicker 9.Blue
BC_effects_1,
  // BC_SparkTipOut_Bend2
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Top
  StylePtr<Layers<
    ColorCycle<
      Pulsing<RotateColorsX<Variation,DeepSkyBlue>,Mix<Int<25000>,RotateColorsX<Variation,DeepSkyBlue>,Black>,2000>,15,30,  // OFF
      Pulsing<RotateColorsX<Variation,DeepSkyBlue>,Mix<Int<18000>,RotateColorsX<Variation,DeepSkyBlue>,Black>,300>,25,100,  // ON
    1000>,  // transition time
BC_effects_2,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Bottom
  StylePtr<Layers<
    Pulsing<RotateColorsX<Variation,DeepSkyBlue>,Mix<Int<18000>,RotateColorsX<Variation,DeepSkyBlue>,Black>,300>,
BC_effects_2,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,RotateColorsX<Variation,DeepSkyBlue>,4000>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  "caleb\ndume"
},

{ "aa_NoSloppy/Crushed;ProffieOS_Voicepack_Ezra/common;commonBU", "",
// NoSloppy 06/2022
  StylePtr<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>,
    AlphaL<StaticFire<Black,BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,600>,0,4,2,4000,0>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<500>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_Red,
// BC_SparkTipOut_Bend2
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // Postoff Emitter Cooldown
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb16<22863,5695,53231>,Bump<Int<0>,Int<3500>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Rgb<100,0,0>,Bump<Int<0>,Int<1000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
  // Preon effects - auto matched to which wav file is chosen
    ColorSelect<WavNum<EFFECT_PREON>,TrInstant,
      Layers<
        TransitionEffectL<TrConcat<TrDelay<200>,AlphaL<Black,Int<0>>,TrFade<1300>,Layers<
        StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<180,0,0>>,RotateColorsX<Variation,Rgb<15,0,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>>,RotateColorsX<Variation,Rgb<40,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<36,0,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<180,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<90,0,0>>,RotateColorsX<Variation,Rgb<5,2,0>>,3000>>,
        AlphaL<StyleFire<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<2,1,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>>,TrDelay<1000>>,EFFECT_PREON>,
        TransitionEffectL<TrConcat<TrFade<1500>,SparkleL<ColorSelect<Sin<Int<1>,Int<68>>,TrFade<300>,Red,Rgb16<22863,5695,53231>,White>,200,500>,TrDelay<1000>>,EFFECT_PREON>,
        TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<Black,Int<0>>,TrFade<800>,AlphaL<StaticFire<Black,Rgb16<22863,5695,53231>,0,3,0,6000>,Bump<Int<0>,Int<5000>>>,TrInstant,AlphaL<AlphaL<White,NoisySoundLevelCompat>,Bump<Int<0>,Int<25000>>>,TrDelay<700>>,EFFECT_PREON>,
        TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<Black,Int<0>>,TrFade<700>,AlphaL<StaticFire<Black,Rgb16<22863,5695,53231>,0,3,0,3000>,Int<16000>>,TrDelay<700>>,EFFECT_PREON>>,
Layers<
  TransitionEffectL<TrConcat<TrInstant,Pulsing<BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,Red,800>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrInstant,
    AlphaL<Black,SmoothStep<Int<5000>,Int<1>>>,TrDelay<55>,Black,TrDelay<56>,
    AlphaL<Black,SmoothStep<Int<9830>,Int<1>>>,TrDelay<55>,Black,TrDelay<56>,
    AlphaL<Black,SmoothStep<Int<14745>,Int<1>>>,TrDelay<55>,Black,TrDelay<56>,
    AlphaL<Black,SmoothStep<Int<19660>,Int<1>>>,TrDelay<55>,Black,TrDelay<56>,
    AlphaL<Black,SmoothStep<Int<24576>,Int<1>>>,TrDelay<55>,Black,TrDelay<56>,
    AlphaL<Black,SmoothStep<Int<29491>,Int<1>>>,TrDelay<55>,Black,TrDelay<56>,
    AlphaL<Black,SmoothStep<Int<32768>,Int<1>>>,TrDelay<55>,Black,TrDelay<56>>,EFFECT_PREON>>>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Top
  StylePtr<Layers<
    ColorCycle<
      Pulsing<Rgb16<22863,5695,53231>,Mix<Int<25000>,Rgb16<22863,5695,53231>,Black>,2000>,15,30,  // OFF
      Pulsing<Rgb<180,0,0>,Mix<Int<16384>,Rgb16<22863,5695,53231>,Black>,1000>,25,100,  // ON
    1000>,  // transition time
BC_effects_2,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  // Crystal Chanmber Bottom
  StylePtr<Layers<
    Pulsing<RandomFlicker<Rgb<180,0,0>,Rgb16<22863,5695,53231>>,Black,800>,
BC_effects_2,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Rgb<180,0,0>,Mix<Int<16384>,Rgb16<22863,5695,53231>,Black>,4000>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"crushed"},

{"aa_Blueforce/DarkSpace;ProffieOS_Voicepack_Ezra/common;commonBU", "Proto2/tracks/proto1.wav", 
  StylePtr<Layers<
    StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<Sin<Int<8>,Int<6000>,Int<3000>>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Sin<Int<5>,Int<-400>,Int<-1000>>,Pulsing<Black,RotateColorsX<Variation,Rgb<75,0,165>>,3000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb<75,0,165>>,Black>>,RotateColorsX<Variation,Rgb<22,0,49>>,Pulsing<RotateColorsX<Variation,Rgb<19,0,41>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,Black,RotateColorsX<Variation,Rgb<130,40,230>>>,RotateColorsX<Variation,Rgb<36,0,79>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<48,0,105>>,RotateColorsX<Variation,Rgb<19,0,41>>,3000>>,
    AlphaL<StripesX<Sin<Int<8>,Int<3000>,Int<6000>>,Int<140>,StripesX<Sin<Int<6>,Int<1000>,Int<3000>>,Int<-55>,Pulsing<Mix<Sin<Int<4>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<130,40,230>>>,RotateColorsX<Variation,Rgb<7,0,16>>,4000>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Rgb<130,40,230>>,Black>>,RotateColorsX<Variation,Rgb<22,0,49>>,Pulsing<RotateColorsX<Variation,Rgb<19,0,41>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<-25>,Int<-75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<130,40,230>>>,RotateColorsX<Variation,Rgb<36,0,79>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<48,0,105>>,RotateColorsX<Variation,Rgb<19,0,41>>,3000>>,Int<10000>>,
    AlphaL<StrobeL<RotateColorsX<Variation,Rgb<95,0,210>>,Int<200>,Int<100>>,Sin<Int<15>,Int<20000>,Int<1000>>>,
BC_effects_Red,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
  // BC_SparkTipOut_Bend2
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<>,70>>,HumpFlicker<Rgb<95,0,210>,Black,5>,TrJoin<TrWipeInX<Int<300>>,TrWaveX<Rgb<95,0,210>,Int<300>,Int<200>,Int<300>,Int<32768>>>,Black,TrInstant>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Top
  StylePtr<Layers<
    ColorCycle<
      Pulsing<RotateColorsX<Variation,Rgb<75,0,165>>,Mix<Int<25000>,RotateColorsX<Variation,Rgb<75,0,165>>,Black>,2000>,15,30,  // OFF
      Pulsing<RotateColorsX<Variation,Rgb<75,0,165>>,Mix<Int<18000>,RotateColorsX<Variation,Rgb<75,0,165>>,Black>,300>,25,100,  // ON
    1000>,  // transition time
BC_effects_2,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Bottom
  StylePtr<Layers<
    Pulsing<RandomFlicker<RotateColorsX<Variation,Rgb<22,0,49>>,RotateColorsX<Variation,Rgb<130,40,230>>>,Black,800>,
BC_effects_2,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<RotateColorsX<Variation,Rgb<130,40,230>>,Black,4000>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
 "dark space"},

{ "aa_Blueforce/LiquidStatic;ProffieOS_Voicepack_Ezra/common;commonBU", "",
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Blue,Mix<Int<2570>,Black,Blue>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Blue>,Black>>,Mix<Int<7710>,Black,Blue>,Pulsing<Mix<Int<6425>,Black,Blue>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Blue,Mix<Int<12000>,Black,Blue>>,2000>,Pulsing<Mix<Int<16448>,Black,Blue>,Mix<Int<642>,Black,Blue>,3000>>,
    AlphaL<StaticFire<Blue,Mix<Int<256>,Black,Blue>,0,1,10,2000,2>,Int<10000>>,
    AlphaL<LightCyan,SmoothStep<Int<2000>,Int<-6000>>>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Blue,RandomPerLEDFlicker<Mix<Int<7710>,Black,Blue>,Black>,BrownNoiseFlicker<Blue,Mix<Int<3855>,Black,Blue>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Blue>,Mix<Int<3855>,Black,Blue>>>,TrInstant>,EFFECT_RETRACTION>,
BC_effects_1,
  // BC_SparkTipOUTandIN_Bend2
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInSparkTipX<LightCyan,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Top
  StylePtr<Layers<
    ColorCycle<
      Pulsing<Blue,Mix<Int<25000>,Blue,Black>,2000>,15,30,  // OFF
      Pulsing<Blue,Mix<Int<18000>,Blue,Black>,300>,25,100,  // ON
    1000>,  // transition time
BC_effects_2,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal
  StylePtr<Layers<
    Pulsing<Blue,Black,800>,
BC_effects_2,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Blue,Black,4000>>
  >>(),
"liquid\nstatic"},

{ "aa_JayDalorian/Parsec1;ProffieOS_Voicepack_Ezra/common;commonBU", "",
  // Main Blade
  StylePtr<Layers<
    StyleFire<Stripes<2500,-8000,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,20>,RotateColorsX<Variation,DeepSkyBlue>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Blue>,70>,RotateColorsX<Variation,SteelBlue>>,RotateColorsX<Variation,DodgerBlue>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
BC_effects_1,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,150,150>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,150,150>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
  // BC_SparkTipOUTandIN_Bend2
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInSparkTipX<LightCyan,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>,
    TransitionEffectL<TrConcat<TrColorCycle<1000>,DeepSkyBlue,TrWipeIn<200>>,EFFECT_PREON>,
    TransitionEffectL<TrSparkX<White,Int<100>,Int<300>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber Top
  StylePtr<Layers<
    ColorCycle<
      Pulsing<Blue,Mix<Int<25000>,Green,Black>,2000>,15,30,  // OFF
      Pulsing<Blue,Mix<Int<18000>,Green,Black>,300>,25,100,  // ON
    1000>,  // transition time
BC_effects_2,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal
  StylePtr<Layers<
    Pulsing<RandomFlicker<Blue,Green>,Black,800>,
BC_effects_2,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Cyan,Black,4000>>
  >>(),
"parsec1"},

};


BladeConfig blades[] = {

{ NO_BLADE,
// { 542,
  // BC Emitter PCB only
  WS281XBladePtr<5, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<4, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),
  CONFIGARRAY(Found),
"00_noblade_save"},

// { 6500,
//   // Carl Chen Emitter PCB and Main Blade in parallel
//   WS281XBladePtr<128, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
//   CONFIGARRAY(Ronin),
// "01_Ronin_save"},


{ 670,  // Darkwolf courtesy blade
  // BC Emitter PCB and Main Blade in parallel
  WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<4, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),
  CONFIGARRAY(Found),
"01_Found_save"},

{ 25,  // Sabertec 7/8" Quad edge Quantum Strip blade. still shadowing.
  // BC Emitter PCB and Main Blade in parallel
  WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<4, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),
  CONFIGARRAY(Found),
"01_Found_save"},

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
#endif
// 1000721280
// 1000973568
// #ifdef CONFIG_BOTTOM
// struct Script : Looper, StateMachine {
//   const char* name() override { return "script"; }
//   void Loop() override {
//     STATE_MACHINE_BEGIN();
//     while (true) {
//       CommandParser::DoParse("on", nullptr);
//       SLEEP(3000);
//       CommandParser::DoParse("clash", nullptr);
//       SLEEP(1000);
//       CommandParser::DoParse("clash", nullptr);
//       SLEEP(4000);
//       CommandParser::DoParse("blast", nullptr);
//       SLEEP(400);
//       CommandParser::DoParse("blast", nullptr);
//       SLEEP(400);
//       CommandParser::DoParse("blast", nullptr);
//       SLEEP(400);
//       CommandParser::DoParse("blast", nullptr);
//       SLEEP(4000);
//       CommandParser::DoParse("lock", nullptr);
//       SLEEP(2500);
//       CommandParser::DoParse("lock", nullptr);
//       SLEEP(4000);
//       CommandParser::DoParse("off", nullptr);
//       SLEEP(4000);
//     }
//     STATE_MACHINE_END();
//   }
// };
// Script script;
// #endif


// // Button connect to 3.3v(+) instead of GND. Up to 5v is OK
// PullDownButton PowerButton(BUTTON_POWER, powerButtonPin, "pow"); // isn't this backwards?

// // Analog Potentiometer 
// ChangeVolumeAnalogReceiver volume_function;
// PotClass pot(0, &volume_function);

// // Or, you can use it to change the variation (color):

// ChangeVariationAnalogReceiver variation_function;
// PotClass pot(0, &variation_function);

// // Rotary Encoder

// ChangePresetRotaryReceiver rotary_receiver;
// Rotary<8, 9> rotary(&rotary_receiver);
/*
The receiver decides what the rotary events do.
There are currently receivers for changing presets, 
changing variation and one that just prints things out. 
More receivers can be added as needed. 
(I should probably create one for changing the volume.)
*/

// Support for 128x64 OLED
// #ifdef CONFIG_BOTTOM
// SSD1306Template<128, uint64_t> display(0x3C);
// #endif

