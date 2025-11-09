// BC_Darkshadow_7.x_Travel_Dual_Blade.h

#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 1

// ------ Audio Stuff --------

#define VOLUME 800
#define BOOT_VOLUME 200
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000  // SPDIF out
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
#define FEMALE_TALKIE_VOICE
// #define DISABLE_TALKIE

// ------ Blade Stuff ------

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
                // #define NO_BLADE_ID_RANGE 15000,999999999

//    Requires wiring a pad to a switched GND
//    (floating pogo pin until grounded via blade-side PCB ring)
// #define BLADE_DETECT_PIN 10 

// ------ SD Card Stuff -------

// #define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//    Upload overwrites presets.ini/tmp unless this is defined
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING

// ------- OLED stuff ----------

// #define ENABLE_SSD1306
// #define OLED_FLIP_180
// #define OLED_MIRRORED
// #define USE_AUREBESH_FONT
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
 #define PROFFIEOS_LOG_LEVEL 400

// #define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
#define ENABLE_DEVELOPER_COMMANDS
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

// #define CONFIG_STARTUP_DELAY 15000               // BC now canon

// ------- Motion and Gesture stuff -------

#define CLASH_THRESHOLD_G 3.5
#define ENABLE_SPINS
#define BC_SWING_ON                                 // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
#define BC_SWING_ON_SPEED 300 // Default 250
// #define BC_STAB_ON
#define BC_THRUST_ON
// #define BC_TWIST_ON
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
#define DIAGNOSTIC_STARTUP_DELAY_FOR_SERIAL_MONITOR // BC 3000ms delay to catch all messages.

// -------- BC Prop Other Stuff --------

// #define NO_VOLUME_MENU                           // self evident. But why?
#define DUAL_BLADES
// BLADE # corresponds to the blades list in the BladeConfig section of the config file.
// Defaults are BLADE 1 and BLADE 2 as MAIN and SECOND blades respectively.
// Optionally, you can also manually define custom dual blades if different than 1 and 2, for example:
// #define MAIN_BLADE 2
// #define SECOND_BLADE 3


#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS
// #include "aliases/TrueWhites/BC_effects_1.h"                 // For Red, Green, light Blue, ...light colored blades
#include "aliases/TrueWhites/BC_effects_1_Main.h"               // For Red, Green, light Blue, ...light colored blades
#include "aliases/TrueWhites/BC_effects_1_Alt.h"                // For Red, Green, light Blue, ...light colored blades
// #include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"     // EffectSequence driven different blast animations
// #include "aliases/TrueWhites/BC_effects_2.h"                 // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red_Main.h"             // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_Red_Alt.h"              // For Red or dark blades
// #include "aliases/TrueWhites/BC_effects_White.h"             // For White blades
#include "aliases/TrueWhites/BC_12color_8effect_SS.h"           // All in one blade style from CC Fork. SS = SwingSpeed included 

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

/* Presets:
00. a_INQUISITOR/2ndSister                                      // rotatable Red
01. a_INQUISITOR/VengefulYoungling (Reva: Third Sister)         // rotatable Red
02. a_INQUISITOR/GrandHunter (Grand Inquisitor)                 // rotatable Red
03. a_INQUISITOR/9thSistr                                       // rotatable Red
04. aa_Blueforce/LiquidStatic                                   // custom Blue (Setup SWAP to use BC_12color_8effect_SS?)
05. aa_Blueforce/CyberAssassin2                                 // custom Green (Setup SWAP to use BC_12color_8effect_SS?)
06. aa_Blueforce/TempleGuardian                                 // BC_12color_8effect_SS
07. aa_Greyscale/Omen_Greyscale                                 // custom Greyscale style by KidsTryThisAtHome BC mod
08. aa_Greyscale/BinaryDark_Greyscale                           // Same as Omen, but use RotateColorsX
09. aa_Greyscale/BinaryLight_Greyscale                          // Same as Omen, but use RotateColorsX
// aa_Greyscale/AwakenV2_Greyscale                              // custom Greyscale stlye by KidsTryThisAtHome BC mod 
10. aa_HarrySolo/DESTABILIZE                                    // custom Cyan->Purple fire w/ BC_effects_1
11. aa_JayDalorian/Decimate                                     // Purple Fire w/ BC_effects_Red
12. aa_Juansith/HATE                                            // rotatable Red


*/


Preset preset[] = {

// Preset 0
{ "a_INQUISITOR/2ndSistr;common;commonBU", "a_INQUISITOR/tracks/Enter_The_Inquisitor.wav",
 // Blade 1
  StylePtr<Layers<
    Mix<SwingSpeed<300>,StaticFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,10,1000,2>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>>,
    BC_effects_Red_Main,
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
    BC_effects_Red_Alt,
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
  StylePtr<Blue>(), // Pommel static blue 3mm LED
  StylePtr<Blue>(), // Bluetooth
"2nd\nsister"},



// Preset 1
{ "a_INQUISITOR/RevaUltimate;common;commonBU", "a_INQUISITOR/tracks/Inquisitor_Theme.wav",
 // Blade 1
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<255,20,20>>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
    BC_effects_Red_Main,
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
    BC_effects_Red_Alt,
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
  StylePtr<Blue>(), // Pommel static blue 3mm LED
  StylePtr<Blue>(), // Bluetooth
"reva\nultimate"},


// Preset 2
{ "a_INQUISITOR/GrandHunter;common;commonBU", "a_INQUISITOR/GrandHunter/tracks/track1.wav",
 // Blade 1
  StylePtr<Layers<
    Mix<SwingSpeed<300>,StaticFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,10,1000,2>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>>,
    BC_effects_Red_Main,
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
    BC_effects_Red_Alt,
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
  StylePtr<Blue>(), // Pommel static blue 3mm LED
  StylePtr<Blue>(), // Bluetooth
"grand\ninquisitor"},


// Preset 3
{ "a_INQUISITOR/9thSistr;common;commonBU", "a_INQUISITOR/tracks/Inquisitor_Theme.wav",
// Blade 1
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<255,50,50>>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
    BC_effects_Red_Main,
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
    BC_effects_Red_Alt,
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
  StylePtr<Blue>(), // Pommel static blue 3mm LED
  StylePtr<Blue>(), // Bluetooth
"9th\nsister"},


// Preset 4 
{ "aa_Blueforce/LiquidStatic;common;commonBU", "",
// Blade 1
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Blue,Mix<Int<2570>,Black,Blue>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Blue>,Black>>,Mix<Int<7710>,Black,Blue>,Pulsing<Mix<Int<6425>,Black,Blue>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Blue,Mix<Int<12000>,Black,Blue>>,2000>,Pulsing<Mix<Int<16448>,Black,Blue>,Mix<Int<642>,Black,Blue>,3000>>,
    AlphaL<StaticFire<Blue,Mix<Int<256>,Black,Blue>,0,1,10,2000,2>,Int<10000>>,
    AlphaL<AudioFlicker<DeepSkyBlue,BlueRibbon>,Bump<Int<0>,Int<5000>>>,
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,Blue,RandomPerLEDFlicker<Mix<Int<7710>,Black,Blue>,Black>,BrownNoiseFlicker<Blue,Mix<Int<3855>,Black,Blue>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Blue>,Mix<Int<3855>,Black,Blue>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<DeepSkyBlue,BlueRibbon>,Bump<Int<0>,Int<28000>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Blue,RandomPerLEDFlicker<Mix<Int<7710>,Black,Blue>,Black>,BrownNoiseFlicker<Blue,Mix<Int<3855>,Black,Blue>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Blue>,Mix<Int<3855>,Black,Blue>>>,TrInstant>,EFFECT_RETRACTION>,
      BC_effects_1_Main,
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
      BC_effects_1_Alt,
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
  StylePtr<Blue>(), // Pommel static blue 3mm LED
  StylePtr<Blue>(), // Bluetooth
"liquid\nstatic"},


// Preset 5
{ "aa_Blueforce/CyberAssassin2;common;commonBU", "",
// Blade 1
    StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Green,Mix<Int<2570>,Black,Green>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Green>,Black>>,Mix<Int<7710>,Black,Green>,Pulsing<Mix<Int<6425>,Black,Green>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Green,Mix<Int<12000>,Black,Green>>,2000>,Pulsing<Mix<Int<16448>,Black,Green>,Mix<Int<642>,Black,Green>,3000>>,
    AlphaL<StaticFire<Green,Mix<Int<256>,Black,Green>,0,1,10,2000,2>,Int<10000>>,
    AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,Bump<Int<0>,Int<5000>>>,
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,Green,RandomPerLEDFlicker<Mix<Int<7710>,Black,Green>,Black>,BrownNoiseFlicker<Green,Mix<Int<3855>,Black,Green>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Green>,Mix<Int<3855>,Black,Green>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,Bump<Int<0>,Int<28000>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Green,RandomPerLEDFlicker<Mix<Int<7710>,Black,Green>,Black>,BrownNoiseFlicker<Green,Mix<Int<3855>,Black,Green>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Green>,Mix<Int<3855>,Black,Green>>>,TrInstant>,EFFECT_RETRACTION>,
      BC_effects_1_Main,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrJoin<TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>,TrSparkX<Mix<Int<16384>,Chartreuse,Black>,Int<401>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<34000>>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Blade 2
    StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Green,Mix<Int<2570>,Black,Green>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Green>,Black>>,Mix<Int<7710>,Black,Green>,Pulsing<Mix<Int<6425>,Black,Green>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Green,Mix<Int<12000>,Black,Green>>,2000>,Pulsing<Mix<Int<16448>,Black,Green>,Mix<Int<642>,Black,Green>,3000>>,
    AlphaL<StaticFire<Green,Mix<Int<256>,Black,Green>,0,1,10,2000,2>,Int<10000>>,
    AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,Bump<Int<0>,Int<5000>>>,
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,Green,RandomPerLEDFlicker<Mix<Int<7710>,Black,Green>,Black>,BrownNoiseFlicker<Green,Mix<Int<3855>,Black,Green>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Green>,Mix<Int<3855>,Black,Green>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,Bump<Int<0>,Int<28000>>>,TrFadeX<WavLen<EFFECT_IGNITION>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Green,RandomPerLEDFlicker<Mix<Int<7710>,Black,Green>,Black>,BrownNoiseFlicker<Green,Mix<Int<3855>,Black,Green>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Green>,Mix<Int<3855>,Black,Green>>>,TrInstant>,EFFECT_RETRACTION>,
      BC_effects_1_Alt,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrJoin<TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>,TrSparkX<Mix<Int<16384>,Chartreuse,Black>,Int<401>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<34000>>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Chartreuse,Mix<Int<16384>,Chartreuse,Black>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Crystal Chamber
  StylePtr<Layers<
    StyleFire<Green,Mix<Int<8000>,Chartreuse,White>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<OnSpark<StyleFire<Green,Mix<Int<8000>,Chartreuse,White>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
    LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
      AlphaL<Green,CircularSectionF<Saw<Int<20>>,Int<3000>>>,
      SparkleL<White,7>>,Green,3000>>
  >>(),
  StylePtr<Blue>(), // Pommel static blue 3mm LED
  StylePtr<Blue>(), // Bluetooth
"cyber\nassassin2"},


// Preset 6
{ "aa_Blueforce/TempleGuardian;common;commonBU", "",
// Blade 1
  StylePtr<Layers<
    BC_12color_8effect_SS,
    BC_effects_1_Main,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>>>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<600>>,EFFECT_IGNITION>,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Blade 2
  StylePtr<Layers<
    BC_12color_8effect_SS,
    BC_effects_1_Alt,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>>>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<600>>,EFFECT_IGNITION>,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

// Crystal Chamber
StylePtr<Layers<
    StyleFire<
    ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
    ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<OnSpark<StyleFire<
    ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
    ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelay<40>>,EFFECT_CLASH>,
    LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Layers<
      AlphaL<
      ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
      CircularSectionF<Saw<Int<20>>,Int<3000>>>,
      SparkleL<White,7>>,
      ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
      3000>>
  >>(),
  StylePtr<Blue>(), // Pommel static blue 3mm LED
  StylePtr<Blue>(), // Bluetooth
"temple\nguardian"},


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
{ 0,
  // WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),   // Main Blade 1
  // WS281XBladePtr<123, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4, bladePowerPin5> >(),  // Main Blade 2
  // WS281XBladePtr<4, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(),                    // Crystals
  // WS281XBladePtr<5, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(),                    // Sides
  WS281XBladePtr<100, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(preset),
"00_2ndSisterSave"}, 
};
#endif

#ifdef CONFIG_BUTTONS
// For saber or dual_prop:
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
