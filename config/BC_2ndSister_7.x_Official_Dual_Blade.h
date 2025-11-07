// BC_2ndSister_7.x_Official_Dual_Blade.h
// Dual_Blade_Example - https://pastebin.com/Hny8XuC5

#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 4
#define NUM_BUTTONS 2

// ------ Audio Stuff --------

#define VOLUME 2200
#define BOOT_VOLUME 200
// #define ENABLE_AUDIO     defaulted OS8
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                    // SPDIF out
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
#define FEMALE_TALKIE_VOICE                        // BC now canon OS6
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
#define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9> // PBv2.2 TX pad for example

/*  SnapshotBladeID is the default Proffieboard V1.5 and V2.2 BLADE_ID_CLASS, so it doesn't need to defined explicitly.
    It will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value,
    so using something like 200000 instead of NO_BLADE is best. */
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> // This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.

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

//    Blanket define to cover the following 4 // BC Personal Only
 #define REAL_TIME_BLADE_ID_POWER_PINS 2, 3

                //    Use with Blade ID. Specify the LED pad(s) that the main blade uses.
                // #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>

                //    Required when blades on different data pads use common LED power pads.
                //    and/or when BLADE_ID_SCAN_MILLIS is used with Blade ID.
                //#define SHARED_POWER_PINS

                //    Choose how often to check for new blade (milliseconds).
                //    Larger values will be a longer delay before a blade is recognized.
                //#define BLADE_ID_SCAN_MILLIS 1000

                //    How many Blade ID scans to average (default is 10, works well)
                //#define BLADE_ID_TIMES 15

                // Not blanketed. This will make the blade ID class for that range return NO_BLADE (use NO_BLADE as the blade definition value.)
                #define NO_BLADE_ID_RANGE 15000,999999999


// Show blade ID value every BLADE_ID_SCAN_MILLIS
 #define SCAN_BLADE_ID_MONITORING

//    Requires wiring a pad to a switched GND
//    (floating pogo pin until grounded via blade-side PCB ring)
// #define BLADE_DETECT_PIN 10

#define DYNAMIC_BLADE_LENGTH

#define BC_DUAL_BLADES
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

// #define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//    Upload overwrites presets.ini/tmp unless this is defined
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING

// ------- OLED stuff ----------

// #define ENABLE_SSD1306
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
//    PVLOG_ERROR 100 = errors
//    PVLOG_STATUS 200 = things you should probably know, like blade ID
//    PVLOG_NORMAL 300 = normal information about what is happening (default level)
//    PVLOG_DEBUG 400 = information helpful for debugging
//    PVLOG_VERBOSE 500 = repeated, spammy information you don't normally want
 #define PROFFIEOS_LOG_LEVEL 300

// #define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
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

// #define CONFIG_STARTUP_DELAY 3000

// ------- Motion and Gesture stuff -------

// #define ENABLE_MOTION     defaulted OS8
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_SPINS
// --- BC prop stuff -----
#define BC_SWING_ON                                 // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
//#define BC_SWING_ON_SPEED 300 // Default 250
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                     // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
/*    If using blade detect, Gesture ignitions or retractions are 
      disabled when no blade is used. BC prop.
      **NOTE** Only works when a BLADE_DETECT_PIN is defined.*/
//#define NO_BLADE_NO_GEST_ONOFF

// ------- Custom / Experimental / Alpha-Beta stuff ---------

// #define LOW_BATT_ONCE                            // BC - THIS NEEDS TO BE CheckLowBattry(), see PR     **Requires modified hybrid_font.h file.
// #define OPTIMIZE_TRCONCAT                       // this TRCONCAT can save some RAM, but it's not compatible with IntArg/RgbArg

// -------- BC Prop Other Stuff --------

// As of OS8, a System Menu is available to edit presets, colors and more. Also, Edit Settings menu to edit volume or blade length
// #define MENU_SPEC_TEMPLATE DefaultMenuSpec

// For Dynamic Blade Length adjustment, the menu system will default to 1 removable blade. If there are more, use this define
// with the blades numbers based on the BladeConfig array entry order, separated by a commas 
// #define REMOVABLE_BLADES 1,2

// -------- Blaster Stuff ----------

// #define BLASTER_ENABLE_AUTO // was #define ENABLE_BLASTER_AUTO
// #define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
// #define BLASTER_JAM_PERCENTAGE 10     // if not defined, random.
// #define BLASTER_DEFAULT_MODE MODE_KILL

#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif


#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"                       // For Red, Green, light Blue, ...light colored blades
// #include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"        // EffectSequence driven different blast animations
// #include "aliases/TrueWhites/BC_effects_2.h"                    // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"                     // For Red or dark blades
// #include "aliases/TrueWhites/BC_effects_White.h"                // For White blades
#include "aliases/TrueWhites/BC_12color_8effect_SS.h"              // All in one blade style from CC Fork. SS = SwingSpeed included 

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrSmoothFade<200>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrDelay<1000>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

/* Presets:
00. a_INQUISITOR/2ndSister                                      // rotatable Red
01. a_INQUISITOR/VengefulYoungling (Reva: Third Sister)         // rotatable Red
02. a_INQUISITOR/GrandHunter (Grand Inquisitor)                 // rotatable Red
03. a_INQUISITOR/9thSistr                                       // rotatable Red
04. aa_Blueforce/LiquidStatic                                   // custom Blue
05. aa_Blueforce/CyberAssassin2                                 // custom Green
06. aa_Blueforce/TempleGuardian                                 // BC_12color_8effect_SS on EFFECT_USER1
07. aa_Greyscale/Omen_Greyscale                                 // custom Greyscale style by KidsTryThisAtHome BC mod
08. aa_Greyscale/BinaryDark_Greyscale                           // Same as Omen, but use RotateColorsX
09. aa_Greyscale/BinaryLight_Greyscale                          // Same as Omen, but use RotateColorsX
// aa_Greyscale/AwakenV2_Greyscale                              // custom Greyscale stlye by KidsTryThisAtHome BC mod 
10. aa_HarrySolo/DESTABILIZE                                    // custom Cyan->Purple fire w/ BC_effects_1
11. aa_JayDalorian/Decimate                                     // Purple Fire w/ BC_effects_Red
12. aa_Juansith/HATE                                            // rotatable Red


// /* master template - BC hack way before Effect_Location and Bitwise operations*/
// /* Dual Blade */ 
// StylePtr<Layers<
// /* Used to toggle Dual Blade on-off. Int<100> could be anything up to 16383 */
//     Mix<IsGreaterThan<EffectIncrementF<EFFECT_USER4,Int<32768>,Int<16384>>,Int<100>>,

// /* off layers */
//   Layers<
//     Black,
//     // pseudo EFFECT_RETRACTION
//     TransitionEffectL<TrConcat<TrInstant,
// /* This color should be the same as the main blade base color layer. Shown instantly and wipes to black */
// // -------------------
// (( main blade base color layer goes here ))
// // -------------------  
//     TrWipeInX<BendTimePowX<WavLen<>,Int<180000>>>>,EFFECT_USER4>,
// /* EFFECT_RETRACTION effects from the style can be added as well, just use EFFECT_USER4 instead */
//     (( any TransitionEffectL layers that end with EFFECT_RETRACTION go here, but swap the "EFFECT_RETRACTION" for "EFFECT_USER4" instead ))
//   >,  // off layers

// /* on layers */
// /* main blade base color and effects down to, but not including, the InOutTrL, and minus any  EFFECT_RETRACTION layers.
//    Pseudo EFFECT_IGNITION effects can be added as well, just use EFFECT_USER4 instead */
//   Layers<
// // ------------------
// (( layers for main blade base color and effects like lockup, melt, drag, stab, etc... down to, but not including, the InOutTrL, and minus any EFFECT_IGNITION and EFFECT_RETRACTION layers go here))
// // ------------------
// /* pseudo EFFECT_IGNITION */
//     (( any TransitionEffectL layers that end with EFFECT_IGNITION go here, but swap the "EFFECT_IGNITION" for "EFFECT_USER4" instead ))
// /* In-Out extension wipe mimicking */
//     TransitionEffectL<TrConcat<TrInstant,Black,TrWipeX<BendTimePowInvX<WavLen<>,Int<196608>>>>,EFFECT_USER4>
//   >  // on layers
// >,  // Mix
//     InOutTrL<
// /* In-Out: Nothing to do here. Showing Black base in Off Layers */
//     TrInstant,
// /* Give time to let Pseudo Retraction Finish if dual blade left on and POW button used for Off() */
//     TrDelayX<WavLen<EFFECT_RETRACTION>>
//     >
//   >>(),



Preset preset[] = {

// Preset 0
{ "a_INQUISITOR/2ndSistr;common;commonBU", "a_INQUISITOR/tracks/Enter_The_Inquisitor.wav",
 // Blade 1
  StylePtr<Layers<
    Mix<SwingSpeed<300>,StaticFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,10,1000,2>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,50>>,TrFadeX<Percentage<WavLen<>,30>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_IGNITION>,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  // Blade 2
  StylePtr<Layers<
    Mix<SwingSpeed<300>,StaticFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,10,1000,2>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,50>>,TrFadeX<Percentage<WavLen<>,30>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_IGNITION>,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Crystal Chamber
  StylePtr<Layers<
    StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<OnSpark<StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
    LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
      AlphaL<Red,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
      SparkleL<White,7>>,Red,3000>>
  >>(),
// Sides
  StylePtr<Layers<
    Stripes<1000,-300,Red,Rgb<128,0,0>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<90,0,0>,Red,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<Red,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<Red,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,Red,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"2nd\nsister"},


// Preset 1
{ "a_INQUISITOR/RevaUltimate;common;commonBU", "a_INQUISITOR/tracks/Inquisitor_Theme.wav",
 // Blade 1
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<255,20,20>>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
    BC_effects_Red,
     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,50>>,TrFadeX<Percentage<WavLen<>,30>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_IGNITION>,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Blade 2
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<255,20,20>>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
    BC_effects_Red,
     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,50>>,TrFadeX<Percentage<WavLen<>,30>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_IGNITION>,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Crystal Chamber
  StylePtr<Layers<
    StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<OnSpark<StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
    LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
      AlphaL<Red,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
      SparkleL<White,7>>,Red,3000>>
  >>(),
// Sides
  StylePtr<Layers<
    Stripes<1000,-300,Red,Rgb<128,0,0>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<90,0,0>,Red,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<Red,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<Red,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,Red,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"reva\nultimate"},


// Preset 2
{ "a_INQUISITOR/GrandHunter;common;commonBU", "a_INQUISITOR/GrandHunter/tracks/track1.wav",
 // Blade 1
  StylePtr<Layers<
    Mix<SwingSpeed<300>,StaticFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,10,1000,2>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,50>>,TrFadeX<Percentage<WavLen<>,30>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_IGNITION>,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Blade 2
  StylePtr<Layers<
    Mix<SwingSpeed<300>,StaticFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,10,1000,2>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,50>>,TrFadeX<Percentage<WavLen<>,30>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_IGNITION>,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Crystal Chamber
  StylePtr<Layers<
    StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<OnSpark<StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
    LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
      AlphaL<Red,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
      SparkleL<White,7>>,Red,3000>>
  >>(),
// Sides
  StylePtr<Layers<
    Stripes<1000,-300,Red,Rgb<128,0,0>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<90,0,0>,Red,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<Red,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<Red,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,Red,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"grand\ninquisitor"},


// Preset 3
{ "a_INQUISITOR/9thSistr;common;commonBU", "a_INQUISITOR/tracks/Inquisitor_Theme.wav",
// Blade 1
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<255,50,50>>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,50>>,TrFadeX<Percentage<WavLen<>,30>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_IGNITION>,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Blade 2
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<255,50,50>>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,50>>,TrFadeX<Percentage<WavLen<>,30>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_IGNITION>,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Crystal Chamber
  StylePtr<Layers<
    StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<OnSpark<StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
    LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
      AlphaL<Red,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
      SparkleL<White,7>>,Red,3000>>
  >>(),
// Sides
  StylePtr<Layers<
    Stripes<1000,-300,Red,Rgb<128,0,0>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<90,0,0>,Red,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<Red,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<Red,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,Red,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"9th\nsister"},


// Preset 4 
{ "aa_Blueforce/LiquidStatic;ProffieOS_V2_Voicepack_Stranger/common;commonBU", "tracks/track1.wav",
// Blade 1
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Blue,Mix<Int<2570>,Black,Blue>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Blue>,Black>>,Mix<Int<7710>,Black,Blue>,Pulsing<Mix<Int<6425>,Black,Blue>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Blue,Mix<Int<12000>,Black,Blue>>,2000>,Pulsing<Mix<Int<16448>,Black,Blue>,Mix<Int<642>,Black,Blue>,3000>>,
    AlphaL<StaticFire<Blue,Mix<Int<256>,Black,Blue>,0,1,10,2000,2>,Int<10000>>,
    AlphaL<AudioFlicker<DeepSkyBlue,BlueRibbon>,Bump<Int<0>,Int<5000>>>,
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,Blue,RandomPerLEDFlicker<Mix<Int<7710>,Black,Blue>,Black>,BrownNoiseFlicker<Blue,Mix<Int<3855>,Black,Blue>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Blue>,Mix<Int<3855>,Black,Blue>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<DeepSkyBlue,BlueRibbon>,Bump<Int<0>,Int<28000>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Blue,RandomPerLEDFlicker<Mix<Int<7710>,Black,Blue>,Black>,BrownNoiseFlicker<Blue,Mix<Int<3855>,Black,Blue>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Blue>,Mix<Int<3855>,Black,Blue>>>,TrInstant>,EFFECT_RETRACTION>,
      BC_effects_1,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrJoin<TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>,TrSparkX<BlueRibbon,Int<401>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<34000>>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<DeepSkyBlue,BlueRibbon>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<DeepSkyBlue,BlueRibbon>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Blade 2
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Blue,Mix<Int<2570>,Black,Blue>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Blue>,Black>>,Mix<Int<7710>,Black,Blue>,Pulsing<Mix<Int<6425>,Black,Blue>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Blue,Mix<Int<12000>,Black,Blue>>,2000>,Pulsing<Mix<Int<16448>,Black,Blue>,Mix<Int<642>,Black,Blue>,3000>>,
    AlphaL<StaticFire<Blue,Mix<Int<256>,Black,Blue>,0,1,10,2000,2>,Int<10000>>,
    AlphaL<AudioFlicker<DeepSkyBlue,BlueRibbon>,Bump<Int<0>,Int<5000>>>,
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,Blue,RandomPerLEDFlicker<Mix<Int<7710>,Black,Blue>,Black>,BrownNoiseFlicker<Blue,Mix<Int<3855>,Black,Blue>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Blue>,Mix<Int<3855>,Black,Blue>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<DeepSkyBlue,BlueRibbon>,Bump<Int<0>,Int<28000>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Blue,RandomPerLEDFlicker<Mix<Int<7710>,Black,Blue>,Black>,BrownNoiseFlicker<Blue,Mix<Int<3855>,Black,Blue>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Blue>,Mix<Int<3855>,Black,Blue>>>,TrInstant>,EFFECT_RETRACTION>,
      BC_effects_1,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrJoin<TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>,TrSparkX<BlueRibbon,Int<401>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<34000>>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<DeepSkyBlue,BlueRibbon>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<DeepSkyBlue,BlueRibbon>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Crystal Chamber
  StylePtr<Layers<
    StyleFire<Blue,Cyan,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<OnSpark<StyleFire<Blue,Cyan,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
    LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
      AlphaL<Blue,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
      SparkleL<White,7>>,Blue,3000>>
  >>(),
// Sides
  StylePtr<Layers<
    Stripes<1000,-300,RareBlue,Mix<Int<16384>,RareBlue,Black>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Mix<Int<16384>,RareBlue,Black>,RareBlue,400>,TrDelayX<Percentage<WavLen<>,80>>,Mix<Int<6000>,RareBlue,White>,TrFade<800>>,EFFECT_FORCE>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<RareBlue,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<RareBlue,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,RareBlue,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,RareBlue,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,RareBlue,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"liquid\nstatic"},


// // Preset 5
// { "aa_Blueforce/CyberAssassin2;common;commonBU", "",
// // Blade 1
//     StylePtr<Layers<
//     StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Green,Mix<Int<2570>,Black,Green>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Green>,Black>>,Mix<Int<7710>,Black,Green>,Pulsing<Mix<Int<6425>,Black,Green>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Green,Mix<Int<12000>,Black,Green>>,2000>,Pulsing<Mix<Int<16448>,Black,Green>,Mix<Int<642>,Black,Green>,3000>>,
//     AlphaL<StaticFire<Green,Mix<Int<256>,Black,Green>,0,1,10,2000,2>,Int<10000>>,
//     AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,Bump<Int<0>,Int<5000>>>,
//     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,Green,RandomPerLEDFlicker<Mix<Int<7710>,Black,Green>,Black>,BrownNoiseFlicker<Green,Mix<Int<3855>,Black,Green>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Green>,Mix<Int<3855>,Black,Green>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,Bump<Int<0>,Int<28000>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Green,RandomPerLEDFlicker<Mix<Int<7710>,Black,Green>,Black>,BrownNoiseFlicker<Green,Mix<Int<3855>,Black,Green>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Green>,Mix<Int<3855>,Black,Green>>>,TrInstant>,EFFECT_RETRACTION>,
//       BC_effects_1,
//     InOutTrL<
//       TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
//       TrJoin<TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>,TrSparkX<Mix<Int<16384>,Chartreuse,Black>,Int<401>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<34000>>>>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Blade 2
//     StylePtr<Layers<
//     StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Green,Mix<Int<2570>,Black,Green>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Green>,Black>>,Mix<Int<7710>,Black,Green>,Pulsing<Mix<Int<6425>,Black,Green>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Green,Mix<Int<12000>,Black,Green>>,2000>,Pulsing<Mix<Int<16448>,Black,Green>,Mix<Int<642>,Black,Green>,3000>>,
//     AlphaL<StaticFire<Green,Mix<Int<256>,Black,Green>,0,1,10,2000,2>,Int<10000>>,
//     AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,Bump<Int<0>,Int<5000>>>,
//     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,Green,RandomPerLEDFlicker<Mix<Int<7710>,Black,Green>,Black>,BrownNoiseFlicker<Green,Mix<Int<3855>,Black,Green>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Green>,Mix<Int<3855>,Black,Green>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,Bump<Int<0>,Int<28000>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Green,RandomPerLEDFlicker<Mix<Int<7710>,Black,Green>,Black>,BrownNoiseFlicker<Green,Mix<Int<3855>,Black,Green>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Green>,Mix<Int<3855>,Black,Green>>>,TrInstant>,EFFECT_RETRACTION>,
//       BC_effects_1,
//     InOutTrL<
//       TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
//       TrJoin<TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>,TrSparkX<Mix<Int<16384>,Chartreuse,Black>,Int<401>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<34000>>>>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Crystal Chamber
//   StylePtr<Layers<
//     StyleFire<Green,Mix<Int<8000>,Chartreuse,White>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<OnSpark<StyleFire<Green,Mix<Int<8000>,Chartreuse,White>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
//     LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
//       AlphaL<Green,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
//       SparkleL<White,7>>,Green,3000>>
//   >>(),
// // Sides
//   StylePtr<Layers<
//     Stripes<1000,-300,Green,Mix<Int<16384>,Green,Black>,Black>,
//     TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Mix<Int<16384>,Green,Black>,Green,400>,TrDelayX<Percentage<WavLen<>,80>>,Mix<Int<6000>,Green,White>,TrFade<800>>,EFFECT_FORCE>,
//     InOutTrL<TrConcat<TrInstant,HumpFlicker<Green,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<Green,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,Green,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Green,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Green,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "cyber\nassassin2"},





















// // Preset 6
// { "aa_Blueforce/TempleGuardian;common;commonBU", "",
// // Blade 1
//   StylePtr<Layers<
//     BC_12color_8effect_SS,  // EFFECT_USER1
//     BC_effects_1,
//     TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>>>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<600>>,EFFECT_IGNITION>,
//     InOutTrL<
//       TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
//       TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Blade 2
//   StylePtr<Layers<
//     BC_12color_8effect_SS, // EFFECT_USER1
//     BC_effects_1,
//     TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>>>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<600>>,EFFECT_IGNITION>,
//     InOutTrL<
//       TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
//       TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Crystal Chamber - broken out because don't have a BC_12color_8effect_SS_ for accents...yet
// StylePtr<Layers<
//     StyleFire<
//     ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
//     ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<OnSpark<StyleFire<
//     ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
//     ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
//     LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
//       AlphaL<
//       ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
//       CircularSectionF<Saw<Int<20>>,Int<3000>>>,
//       SparkleL<White,7>>,
//       ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
//       3000>>
//   >>(),
// // Sides
//   StylePtr<Layers<
//     Stripes<1000,-300,
//     ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
//     ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>,Black>,
//     TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<
//     ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>,
//     ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
//     400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
//     InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,
//     ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,
//     ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,
//     ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "temple\nguardian"},


























// // Preset 7
// { "aa_Greyscale/Omen_Greyscale;ProffieOS_V2_Voicepack_Stranger/common;commonBU", "",
// // Blade 1
//   StylePtr<Layers<
//     //OS6 Magenta AudioFlicker
//     AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,
//     //OS6 Unstable Deep Pink Swing
//     AlphaL<Stripes<2500,2000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,300>,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,300>,RotateColorsX<Variation,DeepPink>,BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,Black,300>>,SwingSpeed<365>>,
//     //OS6 Deep Pink Noise Responsive Sparking Emitter
//     AlphaL<RotateColorsX<Variation,DeepPink>,SmoothStep<Scale<NoisySoundLevel,Int<1500>,Int<7500>>,Int<-4000>>>,
//     BC_effects_1,
//     //OS6 Erratic Unstable Pink Ignition Effect
//     TransitionEffectL<TrConcat<TrInstant,HumpFlicker<BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,Black,225>,AudioFlicker<RotateColorsX<Variation,Rgb<125,0,205>>,RotateColorsX<Variation,Rgb<53,0,101>>>,35>,TrDelayX<Percentage<WavLen<>,49>>>,EFFECT_IGNITION>,
//     //OS6 Unstable Purple Ignition Effect
//     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,60,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,60,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFadeX<Percentage<WavLen<>,49>>>,EFFECT_IGNITION>,
//     //OS6 Bright Retraction Effect
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFadeX<Percentage<WavLen<>,200>>>,EFFECT_RETRACTION>,
//     //OS6 Reversed Ignition/Retraction
//     InOutTrL<TrWipeInX<Percentage<WavLen<EFFECT_IGNITION>,4>>,TrWipeX<WavLen<EFFECT_RETRACTION>>>,
//     //OS6 Noise Responsive Sparky Hilt Retraction
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<125,0,205>>,150>,SmoothStep<Scale<NoisySoundLevel,Int<-1500>,Int<20000>>,Int<-4000>>>,TrFadeX<WavLen<EFFECT_POSTOFF>>>,EFFECT_RETRACTION>,
//     //OS6 Spark-In Retraction
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb<125,0,205>>,Bump<Scale<Trigger<EFFECT_POSTOFF,Int<0>,Int<0>,Percentage<WavLen<EFFECT_POSTOFF>,4>>,Int<0>,Int<32768>>,Int<15000>>>,TrFadeX<Percentage<WavLen<EFFECT_POSTOFF>,15>>>,EFFECT_RETRACTION>,
//     //OS6 Noise Responsive Charge-Up Preon
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Percentage<WavLen<>,110>,Percentage<WavLen<>,50>,Percentage<WavLen<>,50>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<125,0,205>>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb16<14386,0,14386>>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb<125,0,205>>,RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,DeepPink>>,RotateColorsX<Variation,Rgb<60,0,100>>,0,2,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<20000>>,Int<-4000>>>,TrDelayX<Percentage<WavLen<>,110>>>,EFFECT_PREON>,
//     //OS6 Spark-Out Preon
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb<125,0,205>>,Bump<Scale<Trigger<EFFECT_PREON,WavLen<>,Percentage<WavLen<>,50>,Percentage<WavLen<>,50>>,Int<0>,Int<33768>>,Int<8000>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Blade 2
//   StylePtr<Layers<
//     //OS6 Magenta AudioFlicker
//     AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,
//     //OS6 Unstable Deep Pink Swing
//     AlphaL<Stripes<2500,2000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,300>,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,300>,RotateColorsX<Variation,DeepPink>,BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,Black,300>>,SwingSpeed<365>>,
//     //OS6 Deep Pink Noise Responsive Sparking Emitter
//     AlphaL<RotateColorsX<Variation,DeepPink>,SmoothStep<Scale<NoisySoundLevel,Int<1500>,Int<7500>>,Int<-4000>>>,
//     BC_effects_1,
//     //OS6 Erratic Unstable Pink Ignition Effect
//     TransitionEffectL<TrConcat<TrInstant,HumpFlicker<BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,Black,225>,AudioFlicker<RotateColorsX<Variation,Rgb<125,0,205>>,RotateColorsX<Variation,Rgb<53,0,101>>>,35>,TrDelayX<Percentage<WavLen<>,49>>>,EFFECT_IGNITION>,
//     //OS6 Unstable Purple Ignition Effect
//     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,60,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,60,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFadeX<Percentage<WavLen<>,49>>>,EFFECT_IGNITION>,
//     //OS6 Bright Retraction Effect
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFadeX<Percentage<WavLen<>,200>>>,EFFECT_RETRACTION>,
//     //OS6 Reversed Ignition/Retraction
//     InOutTrL<TrWipeInX<Percentage<WavLen<EFFECT_IGNITION>,4>>,TrWipeX<WavLen<EFFECT_RETRACTION>>>,
//     //OS6 Noise Responsive Sparky Hilt Retraction
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<125,0,205>>,150>,SmoothStep<Scale<NoisySoundLevel,Int<-1500>,Int<20000>>,Int<-4000>>>,TrFadeX<WavLen<EFFECT_POSTOFF>>>,EFFECT_RETRACTION>,
//     //OS6 Spark-In Retraction
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb<125,0,205>>,Bump<Scale<Trigger<EFFECT_POSTOFF,Int<0>,Int<0>,Percentage<WavLen<EFFECT_POSTOFF>,4>>,Int<0>,Int<32768>>,Int<15000>>>,TrFadeX<Percentage<WavLen<EFFECT_POSTOFF>,15>>>,EFFECT_RETRACTION>,
//     //OS6 Noise Responsive Charge-Up Preon
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Percentage<WavLen<>,110>,Percentage<WavLen<>,50>,Percentage<WavLen<>,50>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<125,0,205>>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb16<14386,0,14386>>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb<125,0,205>>,RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,DeepPink>>,RotateColorsX<Variation,Rgb<60,0,100>>,0,2,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<20000>>,Int<-4000>>>,TrDelayX<Percentage<WavLen<>,110>>>,EFFECT_PREON>,
//     //OS6 Spark-Out Preon
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb<125,0,205>>,Bump<Scale<Trigger<EFFECT_PREON,WavLen<>,Percentage<WavLen<>,50>,Percentage<WavLen<>,50>>,Int<0>,Int<33768>>,Int<8000>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Crystal Chamber
//   StylePtr<Layers<
//     StyleFire<Rgb<130,0,215>,Rgb<78,0,131>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<OnSpark<StyleFire<Rgb<130,0,215>,Rgb<78,0,131>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
//     LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
//       AlphaL<Rgb<130,0,215>,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
//       SparkleL<White,7>>,Rgb<130,0,215>,3000>>
//   >>(),
// // Sides
//   StylePtr<Layers<
//     Stripes<1000,-300,Black,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,Black>>,
//     TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<78,0,131>,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
//     InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,
//     TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,
//     TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,
//     TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "omen"},





















// // Preset 8
// { "aa_Greyscale/BinaryDark_Greyscale;common;commonBU", "",
// // Blade 1
//   StylePtr<Layers<
//     //OS6 Magenta AudioFlicker
//     AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,
//     //OS6 Unstable Deep Pink Swing
//     AlphaL<Stripes<2500,2000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,300>,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,300>,RotateColorsX<Variation,DeepPink>,BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,Black,300>>,SwingSpeed<365>>,
//     //OS6 Deep Pink Noise Responsive Sparking Emitter
//     AlphaL<RotateColorsX<Variation,DeepPink>,SmoothStep<Scale<NoisySoundLevel,Int<1500>,Int<7500>>,Int<-4000>>>,
//     BC_effects_1,
//     //OS6 Erratic Unstable Pink Ignition Effect
//     TransitionEffectL<TrConcat<TrInstant,HumpFlicker<BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,Black,225>,AudioFlicker<RotateColorsX<Variation,Rgb<125,0,205>>,RotateColorsX<Variation,Rgb<53,0,101>>>,35>,TrDelayX<Percentage<WavLen<>,49>>>,EFFECT_IGNITION>,
//     //OS6 Unstable Purple Ignition Effect
//     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,60,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,60,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFadeX<Percentage<WavLen<>,49>>>,EFFECT_IGNITION>,
//     //OS6 Bright Retraction Effect
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFadeX<Percentage<WavLen<>,200>>>,EFFECT_RETRACTION>,
//     //OS6 Reversed Ignition/Retraction
//     InOutTrL<TrWipeInX<Percentage<WavLen<EFFECT_IGNITION>,4>>,TrWipeX<WavLen<EFFECT_RETRACTION>>>,
//     //OS6 Noise Responsive Sparky Hilt Retraction
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<125,0,205>>,150>,SmoothStep<Scale<NoisySoundLevel,Int<-1500>,Int<20000>>,Int<-4000>>>,TrFadeX<WavLen<EFFECT_POSTOFF>>>,EFFECT_RETRACTION>,
//     //OS6 Spark-In Retraction
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb<125,0,205>>,Bump<Scale<Trigger<EFFECT_POSTOFF,Int<0>,Int<0>,Percentage<WavLen<EFFECT_POSTOFF>,4>>,Int<0>,Int<32768>>,Int<15000>>>,TrFadeX<Percentage<WavLen<EFFECT_POSTOFF>,15>>>,EFFECT_RETRACTION>,
//     //OS6 Noise Responsive Charge-Up Preon
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Percentage<WavLen<>,110>,Percentage<WavLen<>,50>,Percentage<WavLen<>,50>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<125,0,205>>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb16<14386,0,14386>>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb<125,0,205>>,RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,DeepPink>>,RotateColorsX<Variation,Rgb<60,0,100>>,0,2,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<20000>>,Int<-4000>>>,TrDelayX<Percentage<WavLen<>,110>>>,EFFECT_PREON>,
//     //OS6 Spark-Out Preon
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb<125,0,205>>,Bump<Scale<Trigger<EFFECT_PREON,WavLen<>,Percentage<WavLen<>,50>,Percentage<WavLen<>,50>>,Int<0>,Int<33768>>,Int<8000>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Blade 2
//   StylePtr<Layers<
//     //OS6 Magenta AudioFlicker
//     AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,
//     //OS6 Unstable Deep Pink Swing
//     AlphaL<Stripes<2500,2000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,300>,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,300>,RotateColorsX<Variation,DeepPink>,BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,Black,300>>,SwingSpeed<365>>,
//     //OS6 Deep Pink Noise Responsive Sparking Emitter
//     AlphaL<RotateColorsX<Variation,DeepPink>,SmoothStep<Scale<NoisySoundLevel,Int<1500>,Int<7500>>,Int<-4000>>>,
//     BC_effects_1,
//     //OS6 Erratic Unstable Pink Ignition Effect
//     TransitionEffectL<TrConcat<TrInstant,HumpFlicker<BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,Black,225>,AudioFlicker<RotateColorsX<Variation,Rgb<125,0,205>>,RotateColorsX<Variation,Rgb<53,0,101>>>,35>,TrDelayX<Percentage<WavLen<>,49>>>,EFFECT_IGNITION>,
//     //OS6 Unstable Purple Ignition Effect
//     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,60,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,60,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFadeX<Percentage<WavLen<>,49>>>,EFFECT_IGNITION>,
//     //OS6 Bright Retraction Effect
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFadeX<Percentage<WavLen<>,200>>>,EFFECT_RETRACTION>,
//     //OS6 Reversed Ignition/Retraction
//     InOutTrL<TrWipeInX<Percentage<WavLen<EFFECT_IGNITION>,4>>,TrWipeX<WavLen<EFFECT_RETRACTION>>>,
//     //OS6 Noise Responsive Sparky Hilt Retraction
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<125,0,205>>,150>,SmoothStep<Scale<NoisySoundLevel,Int<-1500>,Int<20000>>,Int<-4000>>>,TrFadeX<WavLen<EFFECT_POSTOFF>>>,EFFECT_RETRACTION>,
//     //OS6 Spark-In Retraction
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb<125,0,205>>,Bump<Scale<Trigger<EFFECT_POSTOFF,Int<0>,Int<0>,Percentage<WavLen<EFFECT_POSTOFF>,4>>,Int<0>,Int<32768>>,Int<15000>>>,TrFadeX<Percentage<WavLen<EFFECT_POSTOFF>,15>>>,EFFECT_RETRACTION>,
//     //OS6 Noise Responsive Charge-Up Preon
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Percentage<WavLen<>,110>,Percentage<WavLen<>,50>,Percentage<WavLen<>,50>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<125,0,205>>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb16<14386,0,14386>>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb<125,0,205>>,RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,DeepPink>>,RotateColorsX<Variation,Rgb<60,0,100>>,0,2,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<20000>>,Int<-4000>>>,TrDelayX<Percentage<WavLen<>,110>>>,EFFECT_PREON>,
//     //OS6 Spark-Out Preon
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb<125,0,205>>,Bump<Scale<Trigger<EFFECT_PREON,WavLen<>,Percentage<WavLen<>,50>,Percentage<WavLen<>,50>>,Int<0>,Int<33768>>,Int<8000>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Crystal Chamber
//   StylePtr<Layers<
//     StyleFire<Rgb<130,0,215>,Rgb<78,0,131>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<OnSpark<StyleFire<Rgb<130,0,215>,Rgb<78,0,131>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
//     LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
//       AlphaL<Rgb<130,0,215>,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
//       SparkleL<White,7>>,Rgb<130,0,215>,3000>>
//   >>(),
// // Sides
//   StylePtr<Layers<
//     Stripes<1000,-300,Black,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,Black>>,
//     TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<78,0,131>,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
//     InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<White,Black,50>,TrInstant>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "binary\ndark"},


// // // Preset 9
// // { "aa_Greyscale/BinaryLight_Greyscale;common;commonBU", "",
// // // Blade 1
// //   StylePtr<Layers<
// //     //OS6 Magenta AudioFlicker
// //     AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,
// //     //OS6 Unstable Deep Pink Swing
// //     AlphaL<Stripes<2500,2000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,300>,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,300>,RotateColorsX<Variation,DeepPink>,BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,Black,300>>,SwingSpeed<365>>,
// //     //OS6 Deep Pink Noise Responsive Sparking Emitter
// //     AlphaL<RotateColorsX<Variation,DeepPink>,SmoothStep<Scale<NoisySoundLevel,Int<1500>,Int<7500>>,Int<-4000>>>,
// //     BC_effects_1,
// //     //OS6 Erratic Unstable Pink Ignition Effect
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlicker<BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,Black,225>,AudioFlicker<RotateColorsX<Variation,Rgb<125,0,205>>,RotateColorsX<Variation,Rgb<53,0,101>>>,35>,TrDelayX<Percentage<WavLen<>,49>>>,EFFECT_IGNITION>,
// //     //OS6 Unstable Purple Ignition Effect
// //     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,60,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,60,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFadeX<Percentage<WavLen<>,49>>>,EFFECT_IGNITION>,
// //     //OS6 Bright Retraction Effect
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFadeX<Percentage<WavLen<>,200>>>,EFFECT_RETRACTION>,
// //     //OS6 Reversed Ignition/Retraction
// //     InOutTrL<TrWipeInX<Percentage<WavLen<EFFECT_IGNITION>,4>>,TrWipeX<WavLen<EFFECT_RETRACTION>>>,
// //     //OS6 Noise Responsive Sparky Hilt Retraction
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<125,0,205>>,150>,SmoothStep<Scale<NoisySoundLevel,Int<-1500>,Int<20000>>,Int<-4000>>>,TrFadeX<WavLen<EFFECT_POSTOFF>>>,EFFECT_RETRACTION>,
// //     //OS6 Spark-In Retraction
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb<125,0,205>>,Bump<Scale<Trigger<EFFECT_POSTOFF,Int<0>,Int<0>,Percentage<WavLen<EFFECT_POSTOFF>,4>>,Int<0>,Int<32768>>,Int<15000>>>,TrFadeX<Percentage<WavLen<EFFECT_POSTOFF>,15>>>,EFFECT_RETRACTION>,
// //     //OS6 Noise Responsive Charge-Up Preon
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Percentage<WavLen<>,110>,Percentage<WavLen<>,50>,Percentage<WavLen<>,50>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<125,0,205>>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb16<14386,0,14386>>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb<125,0,205>>,RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,DeepPink>>,RotateColorsX<Variation,Rgb<60,0,100>>,0,2,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<20000>>,Int<-4000>>>,TrDelayX<Percentage<WavLen<>,110>>>,EFFECT_PREON>,
// //     //OS6 Spark-Out Preon
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb<125,0,205>>,Bump<Scale<Trigger<EFFECT_PREON,WavLen<>,Percentage<WavLen<>,50>,Percentage<WavLen<>,50>>,Int<0>,Int<33768>>,Int<8000>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),

// // // Blade 2
// // /* Dual Blade */ 
// //   StylePtr<Layers<
// //     Mix<IsGreaterThan<EffectIncrementF<EFFECT_USER4,Int<32768>,Int<16384>>,Int<100>>,
// //   Layers<
// //     Black,
// //     TransitionEffectL<TrConcat<TrInstant,
// //     AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,
// //         TrWipeX<WavLen<EFFECT_RETRACTION>>>,EFFECT_USER4>,
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFadeX<Percentage<WavLen<>,200>>>,EFFECT_USER4>>,
// //   Layers<
// //     AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,
// //     AlphaL<Stripes<2500,2000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,300>,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,300>,RotateColorsX<Variation,DeepPink>,BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,Black,300>>,SwingSpeed<365>>,
// //     AlphaL<RotateColorsX<Variation,DeepPink>,SmoothStep<Scale<NoisySoundLevel,Int<1500>,Int<7500>>,Int<-4000>>>,
// //     BC_effects_1,
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlicker<BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,Black,225>,AudioFlicker<RotateColorsX<Variation,Rgb<125,0,205>>,RotateColorsX<Variation,Rgb<53,0,101>>>,35>,TrDelayX<Percentage<WavLen<>,49>>>,EFFECT_USER4>,
// //     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,60,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,60,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFadeX<Percentage<WavLen<>,49>>>,EFFECT_USER4>,
// //     TransitionEffectL<TrConcat<TrInstant,Black,
// //     TrWipeInX<Percentage<WavLen<>,4>>>,EFFECT_USER4>>>,
// //     InOutTrL<TrInstant,TrDelayX<WavLen<EFFECT_RETRACTION>>>,
// //     Mix<IsGreaterThan<EffectIncrementF<EFFECT_USER4,Int<32768>,Int<16384>>,Int<100>>,
// //       Layers<
// //         TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<125,0,205>>,150>,SmoothStep<Scale<NoisySoundLevel,Int<-1500>,Int<20000>>,Int<-4000>>>,TrFadeX<WavLen<EFFECT_POSTOFF>>>,EFFECT_RETRACTION>,
// //         TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb<125,0,205>>,Bump<Scale<Trigger<EFFECT_POSTOFF,Int<0>,Int<0>,Percentage<WavLen<EFFECT_POSTOFF>,4>>,Int<0>,Int<32768>>,Int<15000>>>,TrFadeX<Percentage<WavLen<EFFECT_POSTOFF>,15>>>,EFFECT_RETRACTION>>,
// //       AlphaL<Black,Int<0>>>
// //   >>(),

// // // Crystal Chamber
// //   StylePtr<Layers<
// //     StyleFire<Rgb<130,0,215>,Rgb<78,0,131>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
// //     LockupL<AudioFlicker<OnSpark<StyleFire<Rgb<130,0,215>,Rgb<78,0,131>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
// //     LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
// //     InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
// //       AlphaL<Rgb<130,0,215>,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
// //       SparkleL<White,7>>,Rgb<130,0,215>,3000>>
// //   >>(),
// // // Sides
// //   StylePtr<Layers<
// //     Stripes<1000,-300,Black,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,Black>>,
// //     TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<78,0,131>,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
// //     InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<White,Black,50>,TrInstant>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,AudioFlicker<RotateColorsX<Variation,Rgb<130,0,215>>,RotateColorsX<Variation,Rgb<78,0,131>>>,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "binary\nlight"},




// // { "aa_Greyscale/AwakenV2_Greyscale;common;commonBU", "",
// //   // Blade 1
// //   StylePtr<Layers<
// //     //Base lava ^lamp style, has a very subtle dim 25 times a minute
// //     Mix<Sin<Int<25>>,StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<25>,Int<80>>,Pulsing<RotateColorsX<Variation,Rgb16<65535,10514,0>>,RotateColorsX<Variation,OrangeRed>,3000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb16<19800,937,0>>,RotateColorsX<Variation,Rgb16<19800,298,0>>>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<65535,6467,0>>>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<50,0,0>>,3000>>,StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<25>,Int<80>>,Pulsing<RotateColorsX<Variation,Rgb16<33514,4569,0>>,RotateColorsX<Variation,Rgb16<33514,2426,0>>,3000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb16<19800,937,0>>,RotateColorsX<Variation,Rgb16<19800,298,0>>>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<35913,52,0>>>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<50,0,0>>,3000>>>,
// //     //Underlying lava lamp layer
// //     AlphaL<StripesX<Sin<Int<8>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<60>,Int<140>>,StripesX<Sin<Int<6>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<-25>,Int<-80>>,Pulsing<Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,OrangeRed>>,RotateColorsX<Variation,Rgb<20,0,0>>,4000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,DarkOrange>,Black>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<-25>,Int<-75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<65535,6467,0>>>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,Black,3000>>,Int<10000>>,
// //     //Swing effect, fades from red at slow swings to dark orange at slightly harder swings
// //     AlphaL<AudioFlickerL<Mix<SwingSpeed<600>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Rgb16<65535,10514,0>>>>,Scale<SwingSpeed<405>,Int<0>,Int<32768>>>,
// //     //Hard swing effect, hard swings cause dark orange to ripple up the blade
// //     AlphaL<Stripes<2500,-2700,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<60,10,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,5,0>>,Black,800>>,Scale<IsLessThan<SwingSpeed<625>,Int<13600>>,Scale<SwingSpeed<625>,Int<-19300>,Int<32768>>,Int<0>>>,
// //     //Sparking emitter flare
// //     AlphaL<RotateColorsX<Variation,Rgb16<65535,10514,0>>,SmoothStep<Scale<SlowNoise<Int<2750>>,Int<1750>,Int<3750>>,Int<-4000>>>,
// //     BC_effects_1,
// //     //Unstable orange ignition effect
// //     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Orange>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,6467,0>>,RotateColorsX<Variation,Rgb<60,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>>,TrFade<895>>,EFFECT_IGNITION>,
// //     //Sparkle beep ignition effect
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<White,SparkleF<200>>,TrFade<1000>>,EFFECT_IGNITION>,
// //     //Orange humpflicker retraction effect
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,DarkOrange>,40>,TrFade<1750>>,EFFECT_RETRACTION>,
// //     //White spark tip ignition and retraction
// //     InOutTrL<TrJoin<TrWipe<150>,TrWaveX<White,Int<400>,Int<400>,Int<150>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,WavLen<EFFECT_RETRACTION>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
// //     //Clicky retraction "post off" effect
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<Pulsing<Rgb<120,120,165>,Rgb<50,50,80>,60>,Bump<Int<0>,Int<6000>>>,TrFadeX<WavLen<>>>,EFFECT_POSTOFF>,
// //     //Sparkle beep charge-up preon
// //     TransitionEffectL<TrConcat<TrFade<350>,Black,TrFade<2150>,AlphaL<PulsingX<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,Int<50>>,Bump<Int<0>,Int<7750>>>,TrBoing<1500,5>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb16<65535,6467,0>>,RotateColorsX<Variation,Rgb16<65535,6467,0>>,500>,Bump<Int<0>,Int<9750>>>,TrBoing<1250,7>,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,OrangeRed>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<3750>>,Int<1500>,Int<4200>>,Int<-4000>>>,TrDelay<2850>,AlphaL<Pulsing<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb16<10724,1739,0>>,60>,Bump<Int<0>,Int<17500>>>,TrDelay<800>>,EFFECT_PREON>,
// //     TransitionEffectL<TrConcat<TrDelay<4250>,AlphaL<Mix<Trigger<EFFECT_PREON,Int<1000>,Int<1000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb16<65535,10514,0>>,Rgb16<26168,0,0>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Red>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Red>>>,Rgb16<65535,10514,0>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-350>,Int<25250>>,Int<-4000>>>,TrDelay<4750>>,EFFECT_PREON>,
// //     TransitionEffectL<TrConcat<TrDelay<8500>,AlphaL<White,SparkleF<200>>,TrFade<500>>,EFFECT_PREON>,
// //     // On-Demand Battery Level
// //     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// //   >>(),

// // // Blade 2
// //   StylePtr<Layers<
// //     //Base lava ^lamp style, has a very subtle dim 25 times a minute
// //     Mix<Sin<Int<25>>,StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<25>,Int<80>>,Pulsing<RotateColorsX<Variation,Rgb16<65535,10514,0>>,RotateColorsX<Variation,OrangeRed>,3000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb16<19800,937,0>>,RotateColorsX<Variation,Rgb16<19800,298,0>>>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<65535,6467,0>>>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<50,0,0>>,3000>>,StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<25>,Int<80>>,Pulsing<RotateColorsX<Variation,Rgb16<33514,4569,0>>,RotateColorsX<Variation,Rgb16<33514,2426,0>>,3000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb16<19800,937,0>>,RotateColorsX<Variation,Rgb16<19800,298,0>>>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<35913,52,0>>>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<50,0,0>>,3000>>>,
// //     //Underlying lava lamp layer
// //     AlphaL<StripesX<Sin<Int<8>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<60>,Int<140>>,StripesX<Sin<Int<6>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<-25>,Int<-80>>,Pulsing<Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,OrangeRed>>,RotateColorsX<Variation,Rgb<20,0,0>>,4000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,DarkOrange>,Black>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<-25>,Int<-75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<65535,6467,0>>>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,Black,3000>>,Int<10000>>,
// //     //Swing effect, fades from red at slow swings to dark orange at slightly harder swings
// //     AlphaL<AudioFlickerL<Mix<SwingSpeed<600>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Rgb16<65535,10514,0>>>>,Scale<SwingSpeed<405>,Int<0>,Int<32768>>>,
// //     //Hard swing effect, hard swings cause dark orange to ripple up the blade
// //     AlphaL<Stripes<2500,-2700,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<60,10,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,5,0>>,Black,800>>,Scale<IsLessThan<SwingSpeed<625>,Int<13600>>,Scale<SwingSpeed<625>,Int<-19300>,Int<32768>>,Int<0>>>,
// //     //Sparking emitter flare
// //     AlphaL<RotateColorsX<Variation,Rgb16<65535,10514,0>>,SmoothStep<Scale<SlowNoise<Int<2750>>,Int<1750>,Int<3750>>,Int<-4000>>>,
// //     BC_effects_1,
// //     //Unstable orange ignition effect
// //     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Orange>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,6467,0>>,RotateColorsX<Variation,Rgb<60,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>>,TrFade<895>>,EFFECT_IGNITION>,
// //     //Sparkle beep ignition effect
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<White,SparkleF<200>>,TrFade<1000>>,EFFECT_IGNITION>,
// //     //Orange humpflicker retraction effect
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,DarkOrange>,40>,TrFade<1750>>,EFFECT_RETRACTION>,
// //     //White spark tip ignition and retraction
// //     InOutTrL<TrJoin<TrWipe<150>,TrWaveX<White,Int<400>,Int<400>,Int<150>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,WavLen<EFFECT_RETRACTION>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
// //     //Clicky retraction "post off" effect
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<Pulsing<Rgb<120,120,165>,Rgb<50,50,80>,60>,Bump<Int<0>,Int<6000>>>,TrFadeX<WavLen<>>>,EFFECT_POSTOFF>,
// //     //Sparkle beep charge-up preon
// //     TransitionEffectL<TrConcat<TrFade<350>,Black,TrFade<2150>,AlphaL<PulsingX<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,Int<50>>,Bump<Int<0>,Int<7750>>>,TrBoing<1500,5>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb16<65535,6467,0>>,RotateColorsX<Variation,Rgb16<65535,6467,0>>,500>,Bump<Int<0>,Int<9750>>>,TrBoing<1250,7>,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,OrangeRed>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<3750>>,Int<1500>,Int<4200>>,Int<-4000>>>,TrDelay<2850>,AlphaL<Pulsing<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb16<10724,1739,0>>,60>,Bump<Int<0>,Int<17500>>>,TrDelay<800>>,EFFECT_PREON>,
// //     TransitionEffectL<TrConcat<TrDelay<4250>,AlphaL<Mix<Trigger<EFFECT_PREON,Int<1000>,Int<1000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb16<65535,10514,0>>,Rgb16<26168,0,0>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Red>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Red>>>,Rgb16<65535,10514,0>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-350>,Int<25250>>,Int<-4000>>>,TrDelay<4750>>,EFFECT_PREON>,
// //     TransitionEffectL<TrConcat<TrDelay<8500>,AlphaL<White,SparkleF<200>>,TrFade<500>>,EFFECT_PREON>,
// //     // On-Demand Battery Level
// //     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// //   >>(),
// // // Crystal Chamber
// //   StylePtr<Layers<
// //     StyleFire<RotateColorsX<Variation,Rgb16<65535,10514,0>>,RotateColorsX<Variation,OrangeRed>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
// //     LockupL<AudioFlicker<OnSpark<StyleFire<RotateColorsX<Variation,Rgb16<65535,10514,0>>,RotateColorsX<Variation,OrangeRed>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
// //     LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
// //     InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
// //       AlphaL<RotateColorsX<Variation,Rgb16<65535,10514,0>>,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
// //       SparkleL<White,7>>,RotateColorsX<Variation,Rgb16<65535,10514,0>>,3000>>
// //   >>(),
// // // Sides
// //   StylePtr<Layers<
// //     Stripes<1000,-300,Black,AudioFlicker<RotateColorsX<Variation,Rgb16<65535,10514,0>>,Black>>,
// //     TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<RotateColorsX<Variation,OrangeRed>,AudioFlicker<RotateColorsX<Variation,Rgb16<65535,10514,0>>,RotateColorsX<Variation,RotateColorsX<Variation,OrangeRed>>>,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
// //     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
// //     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
// //     LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
// //     LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// //     LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Red,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_DRAG>,
// //     LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
// //     InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<White,Black,50>,TrInstant>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,AudioFlicker<RotateColorsX<Variation,Rgb16<65535,10514,0>>,RotateColorsX<Variation,RotateColorsX<Variation,OrangeRed>>>,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,AudioFlicker<RotateColorsX<Variation,Rgb16<65535,10514,0>>,RotateColorsX<Variation,RotateColorsX<Variation,OrangeRed>>>,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,AudioFlicker<RotateColorsX<Variation,Rgb16<65535,10514,0>>,RotateColorsX<Variation,RotateColorsX<Variation,OrangeRed>>>,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>
// //   >>(),
// // "awaken\nv2"},


// // Preset 10
// { "aa_HarrySolo/DESTABILIZE;common;commonBU", "",
// // Blade 1
//   StylePtr<Layers<
//     Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,StaticFire<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>,0,6>,Stripes<5000,-1500,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,105>>>>,
//     BC_effects_1,
//     InOutTrL<TrConcat<TrWipe<200>,Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,StaticFire<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>,0,6>,Stripes<5000,-1500,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,105>>>>,TrWipe<100>,Black,TrBoing<300,3>>,TrBoing<500,3>>,
//     TransitionEffectL<TrConcat<TrFade<2000>,AlphaL<HumpFlickerL<Rgb<120,120,165>,10>,Bump<Int<0>,Int<4000>>>,TrFade<2950>,AlphaL<HumpFlickerL<Rgb<120,120,165>,15>,Bump<Int<0>,Int<5000>>>,TrFade<3000>,AlphaL<HumpFlickerL<Rgb<120,120,165>,20>,Bump<Int<0>,Int<6000>>>,TrBoing<1000,3>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Blade 2
//   StylePtr<Layers<
//     Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,StaticFire<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>,0,6>,Stripes<5000,-1500,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,105>>>>,
//     BC_effects_1,
//     InOutTrL<TrConcat<TrWipe<200>,Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,StaticFire<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>,0,6>,Stripes<5000,-1500,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,105>>>>,TrWipe<100>,Black,TrBoing<300,3>>,TrBoing<500,3>>,
//     TransitionEffectL<TrConcat<TrFade<2000>,AlphaL<HumpFlickerL<Rgb<120,120,165>,10>,Bump<Int<0>,Int<4000>>>,TrFade<2950>,AlphaL<HumpFlickerL<Rgb<120,120,165>,15>,Bump<Int<0>,Int<5000>>>,TrFade<3000>,AlphaL<HumpFlickerL<Rgb<120,120,165>,20>,Bump<Int<0>,Int<6000>>>,TrBoing<1000,3>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Crystal Chamber
//   StylePtr<Layers<
//     StyleFire<DeepSkyBlue,DodgerBlue,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<OnSpark<StyleFire<DeepSkyBlue,DodgerBlue,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
//     LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
//       AlphaL<DeepSkyBlue,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
//       SparkleL<White,7>>,DeepSkyBlue,3000>>
//   >>(),
// // Sides
//   StylePtr<Layers<
//     Stripes<1000,-300,DeepSkyBlue,Rgb<0,40,90>,Black>,
//     TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<0,40,90>,DeepSkyBlue,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<0,200,200>,TrFade<800>>,EFFECT_FORCE>,
//     InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<White,Black,50>,TrInstant>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,DeepSkyBlue,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,DeepSkyBlue,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,DeepSkyBlue,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "destabilize"},


// // Preset 11
// { "aa_JayDalorian/Decimate;common;commonBU", "",
// // Blade 1
//   StylePtr<Layers<
//     StaticFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,20>,RotateColorsX<Variation,Rgb<4,0,8>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,RotateColorsX<Variation,Rgb<42,0,105>>>,RotateColorsX<Variation,Rgb<30,0,66>>,0,5,2,3000,0>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>>,TrFade<1200>>,EFFECT_RETRACTION>,
//     InOutTrL<TrWipeSparkTip<White,800>,TrWipeInSparkTip<White,880>>,
//     TransitionEffectL<TrConcat<TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<21,0,52>>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<21,0,52>>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<42,0,105>>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<42,0,105>>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<64,0,145>>,30>,SmoothStep<Int<6000>,Int<-500>>>,TrDelay<5100>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Blade 2
//   StylePtr<Layers<
//     StaticFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,20>,RotateColorsX<Variation,Rgb<4,0,8>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,RotateColorsX<Variation,Rgb<42,0,105>>>,RotateColorsX<Variation,Rgb<30,0,66>>,0,5,2,3000,0>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>>,TrFade<1200>>,EFFECT_RETRACTION>,
//     InOutTrL<TrWipeSparkTip<White,800>,TrWipeInSparkTip<White,880>>,
//     TransitionEffectL<TrConcat<TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<21,0,52>>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<21,0,52>>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<42,0,105>>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<42,0,105>>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<64,0,145>>,30>,SmoothStep<Int<6000>,Int<-500>>>,TrDelay<5100>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),


// // Crystal Chamber
//   StylePtr<Layers<
//     StyleFire<RotateColorsX<Variation,Rgb<95,0,210>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<OnSpark<StyleFire<RotateColorsX<Variation,Rgb<95,0,210>>,Yellow,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
//     LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
//       AlphaL<RotateColorsX<Variation,Rgb<95,0,210>>,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
//       SparkleL<White,7>>,RotateColorsX<Variation,Rgb<95,0,210>>,3000>>
//   >>(),
// // Sides
//   StylePtr<Layers<
//     Stripes<1000,-300,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,RotateColorsX<Variation,Rgb<30,0,66>>,Black>,
//     TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<RotateColorsX<Variation,Rgb<30,0,66>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
//     InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<White,Black,50>,TrInstant>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "decimate"},


// // Preset 12
// { "aa_Juansith/HATE;common;commonBU", "",
//  // Blade 1
//   StylePtr<Layers<
//     Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>>>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<600>>,EFFECT_IGNITION>,
//     InOutTrL<
//       TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
//       TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Blade 2
//   StylePtr<Layers<
//     Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>>>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<600>>,EFFECT_IGNITION>,
//     InOutTrL<
//       TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
//       TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // Crystal Chamber
// StylePtr<Layers<
//     StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<OnSpark<StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
//     LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
//       AlphaL<Red,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
//       SparkleL<White,7>>,Red,3000>>
//   >>(),
// // Sides
//   StylePtr<Layers<
//     Stripes<1000,-300,Red,Rgb<128,0,0>,Black>,
//     TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<90,0,0>,Red,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
//     InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<White,Black,50>,TrInstant>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,Red,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "hate"},

};



BladeConfig blades[] = {
{ 0,
  WS281XBladePtr<110, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),   // Main Blade 1
  WS281XBladePtr<110, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4, bladePowerPin5> >(),  // Main Blade 2
  WS281XBladePtr<4, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(),                    // Crystals
  WS281XBladePtr<5, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(),                    // Sides
CONFIGARRAY(preset),
"00_2ndSisterSave"}, 
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif



