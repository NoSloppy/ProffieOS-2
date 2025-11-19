// BC_Pariahs_8.x.h

#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 1

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
// #define DISABLE_TALKIE                            // I feel I'm not gonna like this
#define ENABLE_FASTON
#define ENABLE_IDLE_SOUND

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet.Equivalent to just indrasing maxLedsPerStrip.
 #define EXTRA_COLOR_BUFFER_SPACE 30

// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000> // resistor value used

// BridgedPullupBladeID is the default Proffieboard V3 BLADE_ID_CLASS, so it doesn't need to defined explicitly with a V3.
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9> // TX pad for example

/*  SnapshotBladeID is the default Proffieboard V1.5 and V2.2 BLADE_ID_CLASS, so it doesn't need to defined explicitly.
    It will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value,
    so using something like 200000 instead of NO_BLADE is best. */
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin>

/*
-- BladeID with constant monitoring --
 
Main blade must be wired to data1
Have a Presets array for each blade,
and match those names to the CONFIGARRAY for the given blade.
Arrays should be named differently like blade_1, blade_2, no_blade etc...
Blades can use the same set of presets, or different ones for different blades.

Open Serial Monitor in Arduino and type `scanid` to get read value.
Use that value in the blade definition in the BladeConfig.
* Note * It is recommended to use a Blade ID resistor in each blade 
to ensure different resistance vales between blades. 
However, in testing, values reported for a chassis alone,
chassis inserted into the hilt (connected to emitter PCB)
and then main blade inserted all gave different enough values on their own
without added resistors that it worked fine. YMMV.
*/
//    Blanket define to cover the following 4. BC custom ProffieOS.ino addition.
// #define REAL_TIME_BLADE_ID_POWER_PINS 2, 3

                //    Use with Blade ID. Specify the LED pad(s) that the main blade uses.
                 // #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>

                //    Required when blades on different data pads use common LED power pads.
                //    and/or when BLADE_ID_SCAN_MILLIS is used with Blade ID.
                 #define SHARED_POWER_PINS

                //    Choose how often to check for new blade (milliseconds).
                //    Larger values will be a longer delay before a blade is recognized.
                // #define BLADE_ID_SCAN_MILLIS 1000

                //    How many Blade ID scans to average (default is 10, works well)
                // #define BLADE_ID_TIMES 15

                // Not blanketed. This will make the blade ID class for that range return NO_BLADE (use NO_BLADE as the blade definition value.)
                // #define NO_BLADE_ID_RANGE 15000,99999999

// This define allows you to set a timeout on how long active blade scanning will actually be active for.
// Similar to IDLE_OFF_TIME, but just for the continous blade ID scan.
//#define BLADE_ID_SCAN_TIMEOUT 5 * 60 * 1000

// This define stops ID scanning while the saber is ignited.
// With no scanning there is no chance of getting the ID wrong and re-initialize the saber while using it.
//#define BLADE_ID_STOP_SCAN_WHEN_IGNITED

// Show blade ID value every BLADE_ID_SCAN_MILLIS
// SEE #define PROFFIEOS_LOG_LEVEL 500

// Requires wiring a pad to a switched GND
// (floating pogo pin until grounded via blade-side PCB ring)
    #define BLADE_DETECT_PIN blade3Pin

// To be able to edit blade length on the saber via a menu, use the following define:
#define DYNAMIC_BLADE_LENGTH

// The BC_buttons menu for blade length adjust automatically knows if there is more than one blade, and if so, all are editable.
// The OS System Menu version for Dynamic Blade Length adjustment, the OS menu system will default to 1 removable blade. If there are more, use this define
// with the blades numbers based on the BladeConfig array entry order, separated by a commas 
// #define REMOVABLE_BLADES 1,2

// #define BC_DUAL_BLADES
// BLADE # corresponds to the blades list in the BladeConfig section of the config file.
// Defaults are BLADE 1 and BLADE 2 as MAIN and SECOND blades respectively.
// Optionally, you can also manually define custom dual blades if different than 1 and 2, for example:
// #define BC_MAIN_BLADE 2
// #define BC_SECOND_BLADE 4

// ------ SD Card Stuff -------

#define MOUNT_SD_SETTING  // This define will allow manual control of when to allow the SD to mount to the computer when Mass Storage is enabled by issuing 'sd 1' in Serial Monitor.
// First let's review how Mass Storage works. Having the Arduino setting Tools>USB Type> Serial + Mass Storage selected allows the SD card to be accessed over USB (using the Proffieboard as a card reader).  
// The way it used to work before OS8 and this define was after the boot sound played, the SD card would immediately mount to the computer as an external USB drive. File transfers could take place then, and when finished, you would eject the SD from the computer. From then, the Proffieboard would use it as normal.
// This meant that you always had to wait for the SD card to mount, and then eject it before uploading or using Serial Monitor. It also meant that to re-access the SD, you'd need to either reboot, or unplug and then re-plug the USB cable.
// Now here's how it can work in OS8 using #define MOUNT_SD_SETTING.  
// Even though Mass Storage was selected and uploaded, this define prevents the SD card from mounting until manually "allowed" by the user.
// To allow the SD to mount, send the command "sd 1" in Serial Monitor. When you finish accessing the SD card and "eject" it from the computer, the Proffieboard will use it as normal and set the permission back to FALSE.
// If you want to access the SD again, you can just issue the 'sd 1' command again, and repeat as above.

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
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144_SC_POV_data.h"
// #define POV_INCLUDE_FILE "Raiden_123_FC_POV_data.h"
// #define POV_INCLUDE_FILE "JohnCena_144_8b_POV_data.h"

// ------ System Stuff --------

// #define ENABLE_DEBUG
// PVLOG_ERROR 100 = errors
// PVLOG_STATUS 200 = things you should probably know, like blade ID
// PVLOG_NORMAL 300 = normal information about what is happening (default level)
// PVLOG_DEBUG 400 = information helpful for debugging
// PVLOG_VERBOSE 500 = repeated, spammy information you don't normally want
 #define PROFFIEOS_LOG_LEVEL 100

// #define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
// #define ENABLE_DEVELOPER_COMMANDS
#define DISABLE_DIAGNOSTIC_COMMANDS
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

// #define ORIENTATION_ROTATION 0,20,0 // -20 is USB  leaning down
// For Curved hilts, or where the board is not parallel with the blade. For Twist on/off particularly.
//This will rotate the orientation of the board 20 degrees around the Y axis.
// Depending on the orientation of the board, you might need -20 degrees instead. (Or 15 degrees? or 30?)
//    Example is for Assaj Ventress curved hilt install. (but not for this hilt as board is level with blade anyway)
// #define ORIENTATION_ROTATION 0,-30,0

// Give serial monitor a chance to catchup at boot,
// and/or for waiting until speaker pod is connected on certain chassis etc...
// #define CONFIG_STARTUP_DELAY 15000               // BC now canon

// ------- Motion and Gesture stuff -------

#define CLASH_THRESHOLD_G 3.5
#define ENABLE_SPINS

// Use this define to turn on an optional "iPod® Clickwheel" sound when rotating the hilt in smooth colorchange mode (Color Wheel).
// mclick.wav will play, so the sound should probably be a very subtle "tick" sound.
// The value is the number of ticks per 360 hilt rotation. Higher number = more ticks per angle change.
// Suggested Range 50 - 120. Using zero or not defining will turn ticks off.
#define SMOOTH_COLORCHANGE_TICKS_PER_REVOLUTION 120
// Rotation sensitivity
#define STEPS_PER_REVOLUTION 24

// --- BC prop stuff -----

#define BC_SWING_ON
#define BC_SWING_ON_SPEED 400 // Default 250
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                     // BC Multiblast continues as long as swinging within 1 second. 
// #define ENABLE_AUTO_SPINS_BLAST       // *** DEAD **** Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
/*    If using blade detect, Gesture ignitions or retractions are 
      disabled when no blade is used. BC prop.
      **NOTE** Only works when a BLADE_DETECT_PIN is defined.*/
// #define NO_BLADE_NO_GEST_ONOFF

// ------- Custom / Experimental / Alpha-Beta stuff ---------

// #define LOW_BATT_ONCE                            // BC - THIS NEEDS TO BE CheckLowBattry(), see PR     **Requires modified hybrid_font.h file.

// -------- BC Prop Other Stuff --------

// As of OS8, the default for the BC_buttons prop file are volume level and blade length edit menus.
// A System Menu is available to edit presets, colors settings, and more. To use this menu system instead, use the following define:
// #define MENU_SPEC_TEMPLATE DefaultMenuSpec

#endif


#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_STYLES
#include "aliases/TrueWhites/BC_effects_1.h"                 // For Red, Green, light Blue, ...light colored blades
// #include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"     // EffectSequence driven different blast animations
// #include "aliases/TrueWhites/BC_effects_2.h"                 // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"               // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_White.h"             // For White blades
// #include "aliases/TrueWhites/BC_12color_8effect_SS.h"        // All in one blade style from CC Fork. SS = SwingSpeed included 

#include "aliases/BC_shortcuts.h"
#endif

#ifdef CONFIG_PRESETS
/* --- Presets List --- /*

a_ASAJJ/NiteSist
a_ASAJJ/Ventress
aa_Kyberphonic/Great_Mother_V1
aa_BVM/Cursed_Saber
a_DOOKU/Duke
a_SAVAGE/Savage_Night
a_SAVAGE/SavageKsith
a_INQUISITOR/2ndSistr
aa_LordBlako/AchluSS
BlakStar
Knighthood
aa_SyntheticEpiphany/Balanced_Entropy
a_DARTH_MAUL/FirstApprentice
Nextor
aa_LordBlako/PitchBlk
Proto1
a_SIDIOUS/SenateMajority2
aa_CFX/SHATTERPOINT
a_STARKILLER/Strkllr1 - Ice blade EFFECT_USER2 (right twist)
a_VADER/RogueVader
VnlaDark
aa_JayDalorian/Nexus
aa_Greyscale/Anomaly_Greyscale
// aa_NoSloppy/Crushed
*/

Preset AllBlades [] = {

{ "a_ASAJJ/NiteSist;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/Sister1.wav", 
  StylePtr<Layers<
    HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
    BC_Bend2_Spark_SetOUT_NoSpark_WavIN,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"night\nsister"},



{ "a_ASAJJ/Ventress;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/Sister1.wav", 
  StylePtr<Layers<
    HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
    BC_Bend2_Spark_SetOUT_NoSpark_WavIN,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"ventress"},

{ "aa_Kyberphonic/Great_Mother_V1;ProffieOS_V2_Voicepack_Nightsisters/common;commonBU", "aa_Kyberphonic/Great_Mother_V1/tracks/track5.wav",
  StylePtr<Layers<Black,
    AlphaL<Mix<HoldPeakF<SwingSpeed<100>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<30000>,Int<10000>>>,
      StaticFire<Mix<Int<16000>,Black,Green>,Mix<Int<16000>,Black,Rgb16<0,18927,65535>>,0,1,10,3000,2>,
      StaticFire<Mix<Int<16000>,Black,Green>,Mix<Int<16000>,Black,Rgb16<0,18927,65535>>,0,3,10,3000,2>>,IsGreaterThan<BladeAngle<>,Int<16384>>>,
    AlphaL<Mix<HoldPeakF<SwingSpeed<100>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<30000>,Int<10000>>>,
      Remap<InvertF<RampF>,StaticFire<Mix<Int<16000>,Black,Green>,Mix<Int<16000>,Black,Rgb16<0,18927,65535>>,0,1,10,3000,2>>,
      Remap<InvertF<RampF>,StaticFire<Mix<Int<16000>,Black,Green>,Mix<Int<16000>,Black,Rgb16<0,18927,65535>>,0,3,10,3000,2>>>,IsLessThan<BladeAngle<>,Int<16384>>>,
    AlphaL<Black,LayerFunctions<Bump<Sin<Int<10>,Int<-10000>,Int<33000>>,Sin<Int<10>,Int<58000>,Int<48000>>>,Bump<Sin<Int<7>,Int<-1000>,Int<37000>>,Sin<Int<50>,Int<47000>,Int<38000>>>,Bump<Sin<Int<8>,Int<35000>,Int<-8000>>,Sin<Int<15>,Int<43000>,Int<35000>>>>>,
    SparkleL<SpringGreen,150,50>,
    BC_effects_1,
    InOutTrL<TrWipe<1800>,TrWipe<1000>>,
    TransitionEffectL<TrConcat<TrJoin<TrCenterWipeInX<Int<200>>,TrJoin<TrWaveX<SpringGreen,Int<200>,Int<200>,Sum<Int<200>,Int<200>>,Int<0>>,TrWaveX<SpringGreen,Int<200>,Int<300>,Sum<Int<200>,Int<200>>,Int<32768>>>>,SparkleL<SpringGreen,650,80>,TrFade<3000>>,EFFECT_IGNITION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"great_mother_v1"},


{ "aa_BVM/Cursed_Saber;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/mars.wav",
  StylePtr<Layers<
    Remap<InvertF<RampF>,Stripes<3000,-2400,Red,Rgb<31,0,0>,Red,Rgb<93,0,0>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrInstant,Stripes<5000,2500,White,Rgb<60,60,60>,Rgb<29,29,29>>,TrFade<800>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<>>,TrInstant>,Stripes<5000,2500,Red,Rgb<60,0,0>,Rgb<30,0,0>>,TrFade<800>>,EFFECT_RETRACTION>,
    BC_Bend4_Spark_SetOUT_Spark_WavIN,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"cursed_\nsaber"},


{ "a_DOOKU/Duke;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "a_DOOKU/tracks/Duke1_Short.wav",// Matched Preons/outs
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
    BC_Bend1_NoSpark_SetOUT_NoSpark_WavIN,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"dooku"},


{ "a_SAVAGE/Savage_Night;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/Sister2_short.wav", // Real Flame

  StylePtr<Layers<
    Layers<
    Mix<SmoothStep<Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<36000>,Scale<BladeAngle<>,Int<10924>,Int<54000>>>,Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<-1>,Scale<BladeAngle<>,Int<-10000>,Int<-1>>>>,Black,Remap<Scale<RampF,Int<0>,Scale<IsLessThan<BladeAngle<>,Int<15000>>,Int<32768>,Scale<BladeAngle<0,15000>,Int<60000>,Int<32768>>>>,Layers<
    Mix<BladeAngle<>,StaticFire<Gradient<RotateColorsX<Variation,Rgb<255,75,0>>,RotateColorsX<Variation,Rgb<255,50,0>>,RotateColorsX<Int<400>,Red>,Red>,Mix<Int<16384>,Black,Red>,0,2,0,1800,10>,StaticFire<Gradient<RotateColorsX<Variation,Rgb<255,75,0>>,RotateColorsX<Int<1200>,Red>,RotateColorsX<Int<600>,Red>,Red>,Mix<Int<16384>,Black,Red>,0,4,0,2200,2>>>>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    BC_Bend1_NoSpark_SetOUT_NoSpark_WavIN,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"savage\nopress"},


{ "a_SAVAGE/SavageKsith;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/Sister2.wav",
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,Black>,300>,RotateColorsX<Variation,Rgb<40,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,AudioFlicker<RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Rgb<20,0,0>>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Red>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Red,50>,TrFade<1000>>,EFFECT_IGNITION>,
    BC_Bend7_Spark_WavOUT_NoSpark_WavIN,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// Emitter cooldown
    TransitionEffectL<TrConcat<TrInstant,
      AlphaL<Rgb<100,200,255>,Bump<Int<0>,Int<6000>>>,TrFadeX<  Int<1875> >,
      AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFadeX<  Int<1875> >,
      AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX< Int<3750> >>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"savage\nksith"},


{ "a_INQUISITOR/2ndSistr;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/FallenOrderTracks/JFO5.wav",
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    BC_Bend2_Spark_SetOUT_NoSpark_WavIN,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"second\nsister"}, 


{ "aa_LordBlako/AchluSS;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/Sister1.wav", 
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    BC_Bend2_Spark_SetOUT_NoSpark_WavIN,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"achluophobia"},


{ "BlakStar;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/Sister1.wav", 
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    BC_Bend1_NoSpark_SetOUT_NoSpark_WavIN,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"blakstar"},


{ "Knighthood;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/mars.wav",
  StylePtr<Layers<
    Mix<SwingSpeed<400>,HumpFlicker<RotateColorsX<Variation,Rgb<50,20,255>>,RotateColorsX<Variation,Rgb<20,0,120>>,5>,HumpFlicker<White,RotateColorsX<Variation,Rgb<50,20,255>>,10>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    BC_Bend1_NoSpark_SetOUT_NoSpark_WavIN,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"knighthood"},


{ "aa_SyntheticEpiphany/Balanced_Entropy;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "", 
  StylePtr<Layers<
    HumpFlicker<Rgb<125,30,255>, Rgb<60,0,255>,50>,
    TransitionEffectL<TrConcat<TrInstant,StaticFire<RotateColorsX<Variation,Rgb<120,40,255>>,White,0,6,10,1000,0>,TrSmoothFade<1600>>,EFFECT_IGNITION>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Red>>,TrFade<1200>>,EFFECT_RETRACTION>,
    BC_Bend8_Spark_WavOUT_Spark_WavIN,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
    TransitionEffectL<TrConcat<TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Red>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,OrangeRed>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Tomato>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Yellow>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Red>,30>,SmoothStep<Int<6000>,Int<-500>>>,TrDelay<5100>>,EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"balanced\nentropy"},


{ "a_DARTH_MAUL/FirstApprentice;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "a_DARTH_MAUL/tracks/Maul_Solo_Theme.wav", // AudioFlicker Red Base Color Wheel Changeable
   
  StylePtr<Layers<
    AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
    BC_effects_Red, 
    BC_Bend1_NoSpark_SetOUT_NoSpark_WavIN,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"darth\nmaul"},


{ "Nextor;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/StarWarsTheme.wav", 
  StylePtr<Layers<
    Mix<SwingSpeed<400>,AudioFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<128,34,0>>>,Mix<SwingSpeed<600>,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Orange>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    BC_Bend2_Spark_SetOUT_NoSpark_WavIN,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"nextor"}, 


{ "aa_LordBlako/PitchBlk;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/MSV.wav",
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,Black>,300>,RotateColorsX<Variation,Rgb<40,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,AudioFlicker<RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Rgb<20,0,0>>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Red>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Red,50>,TrFade<1000>>,EFFECT_IGNITION>,
    BC_Bend1_NoSpark_SetOUT_NoSpark_WavIN,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// Emitter cooldown
    TransitionEffectL<TrConcat<TrInstant,
      AlphaL<Rgb<100,200,255>,Bump<Int<0>,Int<6000>>>,TrFadeX<  Int<1875> >,
      AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFadeX<  Int<1875> >,
      AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX< Int<3750> >>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"pitch\nblack"},


{ "Proto1;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/venus.wav",
    // Fully Responsive Kylo Ren Unstable (Unstable Swing) Styles - Jedi Silver - OS4.x
  StylePtr<Layers<
    Mix<SwingSpeed<310>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<7,7,15>>,RotateColorsX<Variation,Rgb<17,17,36>>>,300>,RotateColorsX<Variation,Rgb<22,22,47>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<7,7,15>>,300>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<10,0,0>>>,0,8,FireConfig<10,1200,1>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>>,
 // Force effect. WavLen duration sync.
    EffectSequence<EFFECT_FORCE,
      TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<0,0,80>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Blue,Strobe<Black,Cyan,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>,
      TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<0,80,0>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Green,Strobe<Black,GreenYellow,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>>,

  // Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
      AlphaL<Black,Int<16384>>,
      AlphaL<Black,Int<0>>>,

  // Clash 1 - BladeAngle responsive. Flash at impact, WavLen duration sync, now clash impact sized.
    MultiTransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<MultiTransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFadeX<Percentage<WavLen<>,35>>,EFFECT_CLASH,5>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,
      Scale<ClashImpactF<200,5000>,Int<1000>,Int<32768>>>>,TrFadeX<Percentage<WavLen<>,45>>>,EFFECT_CLASH,5>,

    /* Stab - OrangeRed stripes. WavLen duration sync. */
    TransitionEffectL<TrConcat<TrWipeInX<Percentage<WavLen<EFFECT_STAB>,30>>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFadeX<Percentage<WavLen<EFFECT_STAB>,120>>,TrConcat<TrDelay<100>,TrWipeX<BendTimePowInvX<Percentage<WavLen<EFFECT_STAB>,150>,Int<175000>>>>>>,EFFECT_STAB>,
    /* Stab - Black dimming and pulse at emitter. WavLen duration sync. */
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_STAB>,25>>,AlphaL<Black,SmoothStep<Int<10000>,Int<-10000>>>,TrDelayX<Percentage<WavLen<EFFECT_STAB>,10>>,TrJoin<TrFadeX<WavLen<EFFECT_STAB>>,TrSparkX<Red,Int<100>,WavLen<EFFECT_STAB>,Int<0>>>>,EFFECT_STAB>,
    // TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,30>>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFadeX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeX<Percentage<WavLen<EFFECT_STAB>,70>>>>,EFFECT_STAB>,

  // Blast
    BlastL<TransitionEffect<GreenYellow,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,400>,

  // Lockup 2 - (Same as Red now) BC custom range mid-blade - Red or Yellow blade alt colors
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
        //Random Strobe Flash no dimming
        AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
        /* Bottom Layer Bump - random width */
        AlphaL<Strobe<Rgb<200,175,0>,BrownNoiseFlicker<DarkOrange,Yellow,300>,30,20>,                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
        //AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
        /* Top Layer Bump - fixed width */
        AlphaL<Strobe<White,BrownNoiseFlicker<Yellow,DarkOrange,200>,50,30>,                                        Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
        //AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                              Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
        // Begin Lockup Transition
        TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,   Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
        // End Lockup Transition
        TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,

  // Non-Responsive Drag - BC custom drag fadeout
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,

  // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
  // Bluer version strobe and slower bumps 2024
    LockupTrL<Layers<
      // Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
      AlphaL<Black,Int<16000>>,
      AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<4>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
      AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,
      LayerFunctions<
      Bump<Scale<SlowNoise<Int<1000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
      Bump<Scale<SlowNoise<Int<1500>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
      Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
        // Begin Lightning Transition
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
        // End Lightning Transition    
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,

  // Melt - Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions, uses TwistAngle<>
    LockupTrL<
      AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
      // Melt Shape
      SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
      // Melt Begin and End transitions
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
    AlphaL<TransitionEffect<White,Rgb<128,0,0>,TrInstant,TrConcat<TrFade<1500>,Red,TrFade<2000>,Orange,TrFade<2500>>,EFFECT_IGNITION>,Bump<Int<0>,Int<6000>>>,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<800>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<800>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<800>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<800>>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"proto 1"},


  { "a_SIDIOUS/SenateMajority2;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/Palpatheme_SHORT.wav",      // Troy Huang Palpatine / Sidiuos
  StylePtr<Layers<
    Mix<SwingSpeed<500>,AudioFlicker<Gradient<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red>,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,
    BC_effects_Red,       
      InOutTrL<TrConcat<TrWipe<200>,Strobe<Black,Rgb<100,100,155>,45,60>,TrJoinR<TrSmoothFade<190>,TrWipe<200>>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"senate\nmajority2"},


{ "aa_CFX/SHATTERPOINT;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/mars.wav",
// HarrySolo/AGONY
  StylePtr<Layers<
    HumpFlicker<Blue,Stripes<22000,-100,RotateColorsX<Variation,Rgb<48,0,105>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<22,0,49>>>,10>,
    BC_effects_Red,
    InOutTrL<TrJoin<TrWipeX<Int<600>>,TrWaveX<White,Int<1200>,Int<400>,Int<600>,Int<0>>>,
             TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,150>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
     
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<200>>,EFFECT_IGNITION>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,10>,Bump<Int<0>,Int<4000>>>,TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,15>,Bump<Int<0>,Int<5000>>>,TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,20>,Bump<Int<0>,Int<6000>>>,TrFade<1000>>,EFFECT_PREON>,Ifon<Int<0>,Int<32768>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"shatter\npoint"},


{ "a_STARKILLER/Starkiller1;ProffieOS_V2_Voicepack_Vader_V2/common;commonBU", "a_STARKILLER/tracks/Starkillers_Theme.wav", // 666 in
  StylePtr<Layers<
    AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
// Ice EFFECT_USER2
    TransitionEffectL< 
  // blade turns solid cold 1000ms before ice full coverage
      TrConcat<TrFade<7000>,Rgb<10,0,75>,
  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to Base color
      TrDelay<1000>>,EFFECT_USER2>,
  //wipe in stripes ice freezing effect
    TransitionEffectL< TrConcat<TrWipe<8000>,
  // Stripes fade to solid over remaining 4 seconds from freezing edge's finish until 12000 then hold for next joined delay to end at 15000, so 3000 more.
    TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>,TrFade<11500>,TrDelay<20000>,EFFECT_USER2>,
  //after 15000 (TrConcat makes it 8000 + 7000) from effect start, full blade to this shade of white for wiping away (seamless color from end of stripes fade to solid)
      TrDelay<7000>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>,
  // wipe ice away and melt to thinner opacity , but not 100%, leave like 30% by using longer fade duration than the wipe takes.
      TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>,

// Freeze
    TransitionEffectL<TrConcat<
  // burst
      TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,     Int<400>,  Int<50>, Int<1000>,Int<0>>,
  // leading freeze edge
        TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,      Int<15000>,Int<400>,Int<8000>,Int<0>>,
  // crystalizing in edge's wake
        TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,


// Thaw
    AlphaL<Rgb<100,200,255>,Int<0>>,
  // burst
      TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,    Int<300>,  Int<50>, Int<1000>,Int<0>>,
  // crystalizing in thaw's path
        TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>,
  // leading thawing edge
        TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,     Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>,

// alt sound stuff -------------

  /*** METHOD ONE HERE using tr (polyphonic but silence beneath) doesn't play gapless into hum. use chhum for this monophonic trick instead.

USER2 causes the first tr sound index (tr00.wav or tr01.wav) to play.(old monosfx)
    TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>>,EFFECT_USER2>,

USER2 also causes hum to switch to alt001 (silent) version.
Then when the tr.wav is finished, it resumes playing alt000 version (call is on a delay in style code, not a 2nd button press).
In essence, this causes a monophonic playback effect of the tr sound so it doesn't overlap the hum sound (but isn't gapless, so.....)
    TransitionEffectL<TrConcat<TrDoEffect<TrInstant,EFFECT_ALT_SOUND,1>,TrDelay<22972>,TrDoEffect<TrInstant,EFFECT_ALT_SOUND,0>>,EFFECT_USER2>,

A polyphonic altchng would play on each alt switch, so that doesn't really work.

USE chhum:
  Ice blade sound is made of hum that fades out as freezing happens, fades in as blade thaws.
  By duplicating the hum in both alt000 and alt001, then using chhum for the ice blade sound, it will seamlessly play gapless between the hums.
  Then no need to switch back to first hum (1 back to 0)again as above does, and a single "control layer" line of style code can be used (besides the actual animation):
*/
   TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,EffectIncrementF<EFFECT_USER2,Int<2>>>,EFFECT_USER2>,
// end alt sound stuff -------------

    BC_effects_1,
    BC_Bend2_Spark_SetOUT_NoSpark_WavIN,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"starkiller"},


// { "a_VADER/RogueVader;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/Imperial March ROTJ 3_long.wav",

//   StylePtr<Layers<
//     AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//     BC_effects_Red,
//     BC_Bend1_NoSpark_SetOUT_NoSpark_WavIN,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
//  StylePtr<Black>(),
// "rogue\nvader"}, 


// { "VnlaDark;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/FallenOrderTracks/JFO8.wav",  
//   StylePtr<Layers<
// // Main Blade
//     // Jedi base Purple
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<95,0,225>>,Pulsing<RotateColorsX<Variation,Rgb<39,5,71>>,RotateColorsX<Variation,Rgb<95,0,225>>,800>,RotateColorsX<Variation,Rgb<95,0,225>>>,
//     // Jedi Force Purple
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<95,0,225>>,TrFade<800>>,EFFECT_FORCE>,
//     // Jedi Swing Purple
//     AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     BC_effects_1,
//     BC_Bend2_Spark_SetOUT_NoSpark_WavIN,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
//     StylePtr<Black>(),
// "vanilla\ndark"},


// { "aa_JayDalorian/Nexus;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "", // Ice Stab and scanning Force
//   StylePtr<Layers<
//     StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<30,0,66>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<7,0,16>>,RotateColorsX<Variation,Rgb<95,0,210>>>,
//     BC_effects_White,
//     TransitionEffectL<TrConcat<TrFade<400>,RotateColorsX<Variation,Rgb<160,60,255>>,TrDelay<7000>,RotateColorsX<Variation,Rgb<160,60,255>>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Stripes<6,-1600,Mix<Sin<Int<30>>,White,White>,Mix<Sin<Int<30>>,White,White>,Mix<Sin<Int<26>>,White,White>,Mix<Sin<Int<24>>,White,White>>,Bump<Scale<SwingSpeed<400>,Int<1000>,Int<34000>>,Int<20000>>>,TrDelay<7000>>,EFFECT_FORCE>,
   
//     TransitionEffectL<TrConcat<TrFade<3000>,RotateColorsX<Variation,Rgb<95,0,210>>,TrDelay<5000>,RotateColorsX<Variation,Rgb<95,0,210>>,TrFade<3000>>,EFFECT_STAB>,
//     TransitionEffectL<TrConcat<TrWipe<3000>,TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Rgb<100,150,230>,TrFade<3000>,TrDelay<3000>,EFFECT_STAB>,TrDelay<3000>,Rgb<100,150,230>,TrWipe<3000>>,EFFECT_STAB>,
//     TransitionEffectL<TrConcat<TrWaveX<BrownNoiseFlicker<White,SteelBlue,60>,Int<3000>,Int<400>,Int<3000>,Int<0>>,AlphaL<White,Int<0>>,TrDelay<3000>,AlphaL<White,Int<0>>,TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,Int<10000>,Int<400>,Int<3000>,Int<0>>>,EFFECT_STAB>,
//     BC_Bend2_Spark_SetOUT_NoSpark_WavIN,
//     TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RandomPerLEDFlickerL<White>,SmoothStep<Int<6000>,Int<-4000>>>,TrDelayX<WavNum<EFFECT_PREON>>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrColorCycle<1000,0>,GhostWhite,TrFade<100>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
//  StylePtr<Black>(),
// "nexus"},


// { "aa_Greyscale/Anomaly_Greyscale;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "", // ***** retraction stuck
//   StylePtr<Layers<
//     //Base Fett263 Silver Humpflicker
//     HumpFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<50,50,75>>,50>,
//     //Unstable Bright Audioflicker Swing Effect
//     AlphaL<AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Black,50>,RotateColorsX<Variation,Rgb<65,50,75>>>,SwingSpeed<285>>,
//     //Fett263 Bright Sparking Emitter Flare
//     AlphaL<RotateColorsX<Variation,Rgb16<16975,9110,65535>>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1500>,Int<4500>>,Int<-6000>>>,
//     BC_effects_White,
//     BC_Bend2_Spark_SetOUT_NoSpark_WavIN,
//     TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RandomPerLEDFlickerL<White>,SmoothStep<Int<6000>,Int<-4000>>>,TrDelayX<WavNum<EFFECT_PREON>>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrColorCycle<1000,0>,GhostWhite,TrFade<100>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
//  StylePtr<Black>(),
// "anomaly\ngreyscale"},


// { "aa_NoSloppy/Crushed;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "",
// // NoSloppy 06/2022
//   StylePtr<Layers<
//     BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//     Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>,
//     AlphaL<StaticFire<Black,BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,600>,0,4,2,4000,0>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<500>,Int<-19300>,Int<32768>>,Int<0>>>,
//     BC_effects_Red,
//     BC_Bend2_Spark_SetOUT_NoSpark_WavIN,
//     // Postoff Emitter Cooldown
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb16<22863,5695,53231>,Bump<Int<0>,Int<3500>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Rgb<100,0,0>,Bump<Int<0>,Int<1000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
//     // Preon effects - auto matched to which wav file is chosen
//    AlphaL<ColorSelect<WavNum<EFFECT_PREON>,TrInstant,
//     Layers<
//       TransitionEffectL<TrConcat<TrDelay<200>,AlphaL<Black,Int<0>>,TrFade<1300>,Layers<
//       StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<180,0,0>>,RotateColorsX<Variation,Rgb<15,0,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>>,RotateColorsX<Variation,Rgb<40,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<36,0,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<180,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<90,0,0>>,RotateColorsX<Variation,Rgb<5,2,0>>,3000>>,
//       AlphaL<StyleFire<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<2,1,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>>,TrDelay<1000>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrFade<1500>,SparkleL<ColorSelect<Sin<Int<1>,Int<68>>,TrFade<300>,Red,Rgb16<22863,5695,53231>,White>,200,500>,TrDelay<1000>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<Black,Int<0>>,TrFade<800>,AlphaL<StaticFire<Black,Rgb16<22863,5695,53231>,0,3,0,6000>,Bump<Int<0>,Int<5000>>>,TrInstant,AlphaL<AlphaL<White,NoisySoundLevelCompat>,Bump<Int<0>,Int<25000>>>,TrDelay<700>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<Black,Int<0>>,TrFade<700>,AlphaL<StaticFire<Black,Rgb16<22863,5695,53231>,0,3,0,3000>,Int<16000>>,TrDelay<700>>,EFFECT_PREON>>,
//     Layers<
//       TransitionEffectL<TrConcat<TrInstant,AlphaL<Layers<
//       BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//       Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<5000>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
//       BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//       Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<9830>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
//       BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//       Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<14745>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
//       BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//       Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<19660>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
//       BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//       Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<24576>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
//       BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//       Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<29491>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
//       BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//       Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<32768>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>>,EFFECT_PREON>>>,Ifon<Int<0>,Int<32768>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
//  StylePtr<Black>(),
// "crushed"},

};

//----------------------------------------------------------------------------------------------------------------------------------------
Preset noblade[] = {

// // Try Sparkle<Red> as accents style

{ "a_ASAJJ/Ventress;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/Sister1.wav", 
  StylePtr<Black>(),
  StylePtr<Layers<
    ColorCycle<Red,20,50,BrownNoiseFlicker<Red,Rgb16<14386,0,0>,500>,100,200,800>,
    BlastL<White,200,600>,
    LockupL<AudioFlicker<Rgb<255,100,100>,White>,AudioFlicker<Rgb<255,100,100>,White>,Int<32768>,Int<32768>>,
    SimpleClashL<White,50,EFFECT_CLASH,Int<32768>>
  >>(),
"assaj\nventress"},   


{ "Calibr8;ProffieOS_V2_Voicepack_Ventress/common;commonBU", "tracks/ObiWan1.wav",    
  StylePtr<Black>(),
  StylePtr<ColorCycle<Pulsing<Blue,Sparkle<Cyan,White,100>,1500>,75,30,Stripes<1000,1000,Cyan,DodgerBlue,White,Black>,60,250,2000>>(),
"calibrate"},  

};


BladeConfig blades[] = {

{ NO_BLADE, // blade=0 //                               D1_data_line = proffie_D1 ---> NPXL ctrpin ---> Open when no blade 
            //                                          D3_data_line = proffie_D3 ---> BP pin --->LED NEG when blade in        
  WS281XBladePtr<0, bladePin,  Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs
CONFIGARRAY(noblade),
"00_NO_BLADEsave", }, // Make NPXL do cool shit when no blade in.


{ 0,     //blade=1 // 7/8" Ventress_A                D1_data_line = proffie_D1 ---> Switch ---> NPXL ctrpin---> bladePCB 330ohm ---> Main blade strips
            //                                                                             \ Battery NEG for charging
            //                                          D3_data_line = proffie_D3 ---> BP pin --->LED NEG when blade in
  WS281XBladePtr<130, bladePin,  Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                 ////////////////////////////////////////////CHANGE WHEN BC MADE BLADE.....IS MADE.
  WS281XBladePtr<5,   blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // D2_data_line = proffie_D2 ---> NPXL_D2pin---> 470ohm---> 5LEDs
CONFIGARRAY(AllBlades),
"01_AllBladessave", }, 


};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
