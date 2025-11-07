// BC_EvoFlex_8.x.h
//   5050s pixels - white is too RED. Use Rgb<100,200,255> // not using
// Latest upload: 8/30/24 OS78.x 
// use BLADE_ID_SCAN_MILLIS

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 1

// ------ Audio Stuff --------

#define VOLUME 1800
#define BOOT_VOLUME 200
// #define ENABLE_AUDIO     defaulted OS8
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                    // SPDIF out
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

#define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000> // resistor value used

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
                 // #define BLADE_ID_TIMES 10

                // Not blanketed. This will make the blade ID class for that range return NO_BLADE (use NO_BLADE as the blade definition value.)
                // #define NO_BLADE_ID_RANGE 400,600

// Show blade ID value every BLADE_ID_SCAN_MILLIS
// #define SCAN_BLADE_ID_MONITORING

//    Requires wiring a pad to a switched GND
//    (floating pogo pin until grounded via blade-side PCB ring)
#define BLADE_DETECT_PIN blade3Pin

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

// #define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//    presets.ini/tmp is ignored after reprogramming unless this is defined.
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING 

// ------- OLED stuff ----------

// #define ENABLE_SSD1306                         // OLED display. also defines ENABLE_DISPLAY_CODE
// #define OLED_FLIP_180                          // BC now canon
// #define USE_AUREBESH_FONT                      // BC now canon
// #define OLED_SYNCED_EFFECTS
// #define PLI_OFF_TIME 60 * 5 * 1000
// #define OLED_USE_BLASTER_IMAGES
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144_SC_POV_data.h"

// ------ System Stuff --------

// #define ENABLE_DEBUG
//    PVLOG_ERROR 100 = errors
//    PVLOG_STATUS 200 = things you should probably know, like blade ID
//    PVLOG_NORMAL 300 = normal information about what is happening (default level)
//    PVLOG_DEBUG 400 = information helpful for debugging
//    PVLOG_VERBOSE 500 = repeated, spammy information you don't normally want
//#define PROFFIEOS_LOG_LEVEL 300

//#define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
// #define COLOR_CHANGE_DIRECT
// #define ENABLE_DEVELOPER_COMMANDS
#define DISABLE_DIAGNOSTIC_COMMANDS
//    Disable Old School original templated styles, like StyleNormalPtr<CYAN, WHITE, 300, 800>()
#define DISABLE_BASIC_PARSER_STYLES
#define IDLE_OFF_TIME 60 * 2 * 1000
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

#define CONFIG_STARTUP_DELAY 5000                 // BC now canon

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 5.5
#define ENABLE_SPINS 
// --- BC prop stuff -----
#define BC_SWING_ON
#define BC_SWING_ON_SPEED 250 // Default 250
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
//    BC Multiblast continues as long as swinging within 1 second. 
#define BC_ENABLE_AUTO_SWING_BLAST
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
/*    If using blade detect, Gesture ignitions or retractions are 
      disabled when no blade is used. BC prop.
      **NOTE** Only works when a BLADE_DETECT_PIN is defined.*/
// #define NO_BLADE_NO_GEST_ONOFF


// -------- BC Prop Other Stuff --------

// As of OS8, a System Menu is available to edit presets, colors and more. Also, Edit Settings menu to edit volume or blade length
//#define MENU_SPEC_TEMPLATE DefaultMenuSpec

// For Dynamic Blade Length adjustment, the menu system will default to 1 removable blade. If there are more, use this define
// with the blades numbers based on the BladeConfig array entry order, separated by a commas 
// #define REMOVABLE_BLADES 1, 2

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
// #include "aliases/TrueWhites/BC_12color_8effect_SS.h"        // All in one blade style from CC Fork. SS = SwingSpeed included 

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrSmoothFade<200>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrDelay<1000>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

// // BC_Bend2
//     InOutTrL<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<175000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,

// // BC_SparkTipOut_Bend2
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,

// // BC_SparkTipOUTandIN_Bend2 (50% White OUT, LightCyan IN)
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInSparkTipX<LightCyan,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInSparkTipX<LightCyan,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>,

/*
EvoFlex Blades config order:
Main Blade
NPXL
Chamber Top
Chamber Crystal
Accents

Presets:
0. BlackBishop
1. TheMaw - w/ ice blade using alt sounds EFFECT_USER2
2. SenateMajority2
3. Photonblade
4. PitchBlk
5. KyloUltimate
6. Reboot_Redux
7. Chaos
8. RootCore

{ "BlackBishop;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "BlackBishop/tracks/track04.wav",
{"aa_NoSloppy/TheMaw;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "",
{"a_SIDIOUS/SenateMajority2;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "tracks/Palpatheme_SHORT.wav",
{"aa_Blueforce/Photonblade;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "",
{ "PitchBlk;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "MSV.wav",
{"a_KYLO/KyloUltimate;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "a_KYLO/KyloUltimate/tracks/Kylo1.wav", 
{ "Reboot_Redux;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "Reboot_Redux/tracks/binaire.wav", 
{ "aa_NoSloppy/Chaos;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "", 
{ "RootCore;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "RootCore/tracks/root.wav", 

*/


Preset AllBlades [] = {

{ "BlackBishop;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "BlackBishop/tracks/track04.wav",
// Main Blade
  StylePtr<
    Layers<
    Mix<SwingSpeed<400>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    Mix<SwingSpeed<800>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<150,150,255>>>>,
BC_effects_1,
// Ignition and Retraction
    TransitionEffectL<TrConcat<TrInstant,StyleFire<Rgb<100,200,255>,Rgb<60,60,60>,0,8>,TrFadeX<Int<500>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<Black,Int<0>>,TrFade<300>,HumpFlickerL<Rgb<100,100,100>,25>,TrFade<500>>,EFFECT_IGNITION>,
// BC_SparkTipOut_Bend2
  InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    TransitionEffectL<TrConcat<TrWipe<400>,Sparkle<AlphaL<Black,Int<0>>,Blue,1000,300>,TrDelayX<Int<1000>>>,EFFECT_PREON>,
// Emitter cooldown
    TransitionEffectL<TrConcat<TrSmoothFade<1500>,StyleFire<Rgb<100,100,100>,Rgb<100,100,100>,0,1,FireConfig<0,2000,15>,FireConfig<0,2000,15>,FireConfig<0,2000,15>,FireConfig<0,2000,15>>,TrFade<4000>>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Hilt PCB
  StylePtr<
    Layers<
    Mix<SwingSpeed<400>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    Mix<SwingSpeed<800>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<150,150,255>>>>,
BC_effects_1,
// Ignition and Retraction
    TransitionEffectL<TrConcat<TrInstant,StyleFire<Rgb<100,200,255>,Rgb<60,60,60>,0,8>,TrFadeX<Int<500>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<Black,Int<0>>,TrFade<300>,HumpFlickerL<Rgb<100,100,100>,25>,TrFade<500>>,EFFECT_IGNITION>,
// BC_SparkTipOut_Bend2
  InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    TransitionEffectL<TrConcat<TrWipe<400>,Sparkle<AlphaL<Black,Int<0>>,Blue,1000,300>,TrDelayX<Int<1000>>>,EFFECT_PREON>,
// Emitter cooldown
    TransitionEffectL<TrConcat<TrSmoothFade<1500>,StyleFire<Rgb<100,100,100>,Rgb<100,100,100>,0,1,FireConfig<0,2000,15>,FireConfig<0,2000,15>,FireConfig<0,2000,15>,FireConfig<0,2000,15>>,TrFade<4000>>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Chamber Top
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,130>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Blue,Black,2500>>>>(),
// Chamber Bot
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,130>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Blue,Black,2500>>>>(),
// Accent Ring   
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<Blue,10,30,Black,100,3000,1>>>>(),
"black\nbishop"},


{"aa_NoSloppy/TheMaw;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "",  
// Main Blade
  StylePtr<Layers<
    Mix<SmoothStep<Int<16000>,Int<10000>>,
      StripesX<Scale<TwistAngle<1>,Int<1500>,Int<3000>>,Int<-2000>,Rgb<60,0,255>,Black>,
      StripesX<Scale<TwistAngle<1>,Int<1500>,Int<3000>>,Int<2000>,Rgb<60,0,255>,Black>>,
  // Ice Force
  // Made same hum in alt000 and alt001. chhum is the ice takeover and melt away sound. should play seamlessly for duration of effect?
  // Instead of making new sound (just ice sound, no hum fade in/out mixed in), used the old monosfx sound,
  // and by omitting an altchg.wav sound intentionally, files that were made seamlessly sould sound right now doing hum->chhum->hum.
    TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,EffectIncrementF<EFFECT_USER2,Int<2>>>,EFFECT_USER2>, 
    TransitionEffectL<
      TrConcat<TrFade<7000>,Rgb<10,0,75>,// blade turns solid cold 1000ms before ice full coverage
      TrDelay<1000>>,EFFECT_USER2>,  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to base color
    TransitionEffectL< TrConcat<TrWipe<8000>, //wipe in stripes ice freezing effect
    TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>,TrFade<11500>,TrDelay<20000>,EFFECT_USER2>, // Stripes fade to solid over remaining 4 seconds from freezing edge's finish until 12000 then hold for next joined delay to end at 15000, so 3000 more.
      TrDelay<7000>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>, //after 15000 (TrConcat makes it 8000 + 7000) from effect start, full blade to this shade of white for wiping away (seamless color from end of stripes fade to solid)
      TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>, // wipe ice away and melt to thinner opacity , but not 100%, leave like 30% by using longer fade duration than the wipe takes. 
    TransitionEffectL<TrConcat<
      TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,     Int<400>,  Int<50>, Int<1000>,Int<0>>,    // burst
        TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,      Int<15000>,Int<400>,Int<8000>,Int<0>>,         // leading freeze edge
        TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,    // crystalizing in edge's wake
    AlphaL<Rgb<100,200,255>,Int<0>>,
      TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,    Int<300>,  Int<50>, Int<1000>,Int<0>>,  // burst
        TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>, // crystalizing in thaw's path
        TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,     Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>, // leading thawing edge
BC_effects_1,
  // Ignition and Retraction
    InOutTrL<TrCenterWipeInSpark<Rgb<80,100,255>,1000>,TrCenterWipeInSpark<Rgb<100,100,255>,1000>>,
    TransitionEffectL<TrConcat<TrDelay<200>,Strobe<Black,Rgb<100,100,150>,15,40>,TrCenterWipeInSpark<Rgb<100,200,255>,600>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,Rgb<80,100,255>,TrFade<50>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrDelay<1100>,Rgb<80,100,255>,TrFade<50>>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Hilt PCB
  StylePtr<Layers<
    Mix<SmoothStep<Int<16000>,Int<10000>>,
      StripesX<Scale<TwistAngle<1>,Int<1500>,Int<3000>>,Int<-2000>,Rgb<60,0,255>,Black>,
      StripesX<Scale<TwistAngle<1>,Int<1500>,Int<3000>>,Int<2000>,Rgb<60,0,255>,Black>>,
  // Ice Force
  // Made same hum in alt000 and alt001. chhum is the ice takeover and melt away sound. should play seamlessly for duration of effect?
  // Instead of making new sound (just ice sound, no hum fade in/out mixed in), used the old monosfx sound,
  // and by omitting an altchg.wav sound intentionally, files that were made seamlessly sould sound right now doing hum->chhum->hum.
    TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,EffectIncrementF<EFFECT_USER2,Int<2>>>,EFFECT_USER2>, 
    TransitionEffectL<
      TrConcat<TrFade<7000>,Rgb<10,0,75>,// blade turns solid cold 1000ms before ice full coverage
      TrDelay<1000>>,EFFECT_USER2>,  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to base color
    TransitionEffectL< TrConcat<TrWipe<8000>, //wipe in stripes ice freezing effect
    TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>,TrFade<11500>,TrDelay<20000>,EFFECT_USER2>, // Stripes fade to solid over remaining 4 seconds from freezing edge's finish until 12000 then hold for next joined delay to end at 15000, so 3000 more.
      TrDelay<7000>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>, //after 15000 (TrConcat makes it 8000 + 7000) from effect start, full blade to this shade of white for wiping away (seamless color from end of stripes fade to solid)
      TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>, // wipe ice away and melt to thinner opacity , but not 100%, leave like 30% by using longer fade duration than the wipe takes. 
    TransitionEffectL<TrConcat<
      TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,     Int<400>,  Int<50>, Int<1000>,Int<0>>,    // burst
        TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,      Int<15000>,Int<400>,Int<8000>,Int<0>>,         // leading freeze edge
        TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,    // crystalizing in edge's wake
    AlphaL<Rgb<100,200,255>,Int<0>>,
      TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,    Int<300>,  Int<50>, Int<1000>,Int<0>>,  // burst
        TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>, // crystalizing in thaw's path
        TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,     Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>, // leading thawing edge
BC_effects_1,
  // Ignition and Retraction
    InOutTrL<TrCenterWipeInSpark<Rgb<80,100,255>,1000>,TrCenterWipeInSpark<Rgb<100,100,255>,1000>>,
    TransitionEffectL<TrConcat<TrDelay<200>,Strobe<Black,Rgb<100,100,150>,15,40>,TrCenterWipeInSpark<Rgb<100,200,255>,600>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,Rgb<80,100,255>,TrFade<50>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrDelay<1100>,Rgb<80,100,255>,TrFade<50>>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Chamber Top
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Rgb<60,0,255>>,RotateColorsX<Variation,Rgb<30,0,128>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<Rgb<30,0,128>,10,30,Black,100,3000,1>>>>(),
// Chamber Bot
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Rgb<60,0,255>>,RotateColorsX<Variation,Rgb<30,0,128>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<Rgb<30,0,128>,10,30,Black,100,3000,1>>>>(),
// Accent Ring    
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Rgb<60,40,200>>,RotateColorsX<Variation,Rgb<30,0,128>>,Black>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<Rgb<30,0,128>,10,30,Black,100,3000,1>>>>(),
"the maw"},


{"a_SIDIOUS/SenateMajority2;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "tracks/Palpatheme_SHORT.wav",
  StylePtr<Layers<
    Mix<SwingSpeed<500>,AudioFlicker<Gradient<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red>,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,
BC_effects_Red,
    InOutTrL<TrConcat<TrColorCycle<80,-400,-1000>,Rgb<100,200,255>,TrWipeIn<50>,Black,TrDelay<450>,Strobe<Black,Rgb<100,200,255>,45,60>,TrJoinR<TrSmoothFade<190>,TrWipe<200>>>,TrConcat<TrInstant,Rgb<100,200,255>,TrJoin<TrJoin<TrJoin<TrColorCycle<2050,-1500,-1>,TrBoing<2050,15>>,TrBoing<2050,18>>,TrSmoothFade<2050>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Hilt PCB
  StylePtr<Layers<
    Mix<SwingSpeed<500>,AudioFlicker<Gradient<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red>,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,
  BC_effects_Red,
    InOutTrL<TrConcat<TrColorCycle<80,-400,-1000>,Rgb<100,200,255>,TrWipeIn<50>,Black,TrDelay<450>,Strobe<Black,Rgb<100,200,255>,45,60>,TrJoinR<TrSmoothFade<190>,TrWipe<200>>>,TrConcat<TrInstant,Rgb<100,200,255>,TrJoin<TrJoin<TrJoin<TrColorCycle<2050,-1500,-1>,TrBoing<2050,15>>,TrBoing<2050,18>>,TrSmoothFade<2050>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Chamber Top
StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<130,0,0>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Red,Black,2500>>>>(),
// Chamber Bottom
StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<130,0,0>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Red,Black,2500>>>>(),
// Accent Ring 
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,Black>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,ColorCycle<Red,10,30,Black,100,3000,1>>>>(),
"senate\nmajority2"},


{"aa_Blueforce/Photonblade;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "",
// Main Blade FINAL ORIGINAL VERSION for 2000ms wav
  StylePtr<Layers<
    Mix<SwingSpeed<400>,HumpFlicker<RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<60,15,0>>,50>,Mix<SwingSpeed<600>,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<255,150,60>>>>,
  // Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
      AlphaL<Black,Int<16384>>,
      AlphaL<Black,Int<0>>>,
  // Clash - Photoblade Custom
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Rgb<60,0,255>,20,20>,BrownNoiseFlicker<Rgb<60,0,255>,Rgb<100,200,255>,500>,TrInstant,TrFade<300>,EFFECT_CLASH>,White,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
  // Stab
    TransitionEffectL<TrConcat<TrWipeIn<350>,Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,Rgb<60,0,255>,400>,Rgb<60,0,255>,Rgb<60,0,255>,Blue,DeepSkyBlue,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Blue,White,15,20>,GreenYellow,10,10>,500>>,TrFade<800>>,EFFECT_STAB>,

  // Blast
    MultiTransitionEffectL<TrJoin<
      // Impact Flash - BC always
      TrConcat<TrInstant,GreenYellow,TrDelay<25>>,
      // Waves
      TrSparkX<Mix<Int<16384>,BrownNoiseFlicker<Rgb<60,0,255>,Rgb<100,200,255>,500>,Black>,Int<250>,Int<350>>>,EFFECT_BLAST,5>,
    // Impact point and afterimage
    MultiTransitionEffectL<TrConcat<TrInstant,AlphaL<MultiTransitionEffect<BrownNoiseFlicker<Rgb<60,0,255>,Rgb<100,200,255>,500>,White,TrInstant,TrConcat<TrDelay<150>,TrFade<150>>,EFFECT_BLAST,5>,Bump<EffectPosition<EFFECT_BLAST>,Int<7000>>>,TrDelay<300>,TrFade<300>>,EFFECT_BLAST,5>,

  // Lockup - BC custom range mid-blade - Photonblade custom
    LockupTrL<AlphaL<RandomBlink<19000,Red,Strobe<Black,Rgb<60,0,255>,30,30>>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    
  // Non-Responsive Drag - Photoblade Custom
    LockupTrL<AlphaL<Gradient<Black,Black,Black,Black,Black,Stripes<500,4000,Rgb<60,0,255>,Black,Black>,RandomBlink<6000,Red,Strobe<Black,Yellow,15,30>>>,SmoothStep<Int<30000>,Int<30000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
  // Lightning Block Non-Responsive
    LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
      Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
      Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
      Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
    // Begin Lightning Transition
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
    // End Lightning Transition    
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,

  // Melt - Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions, uses TwistAngle<>
    LockupTrL<
      AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
      // Melt Shape
      SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
      // Melt Begin and End transitions
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrInstant,StyleFire<Red,Rgb<100,200,255>,0,6,FireConfig<200,3000,5>>,TrFade<500>>,EFFECT_IGNITION>,
    InOutTrL<TrWipeSparkTip<Rgb<100,200,255>,150>,
      TrConcat<TrInstant,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<200>,Int<300>,Int<200>,Int<32768>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<250>,Int<300>,Int<250>,Int<32768>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<300>,Int<300>,Int<300>,Int<32768>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<350>,Int<300>,Int<350>,Int<32768>>,Mix<SmoothStep<Int<24500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<400>,Int<300>,Int<400>,Int<32768>>,Black,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<400>,Int<300>,Int<400>,Int<32768>>,Rgb<100,200,255>,TrFade<50>>>,
    TransitionEffectL<TrConcat<
      TrWaveX<RotateColorsX<Variation,Orange>,Int<400>,Int<300>,Int<400>,Int<0>>,Mix<SmoothStep<Int<27500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<350>,Int<300>,Int<350>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<300>,Int<300>,Int<300>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<250>,Int<300>,Int<250>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<200>,Int<300>,Int<200>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrDelay<100>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWipe<100>,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrFade<100>,Rgb<100,200,255>,TrInstant>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Rgb<100,200,255>,40>,TrFade<300>>,EFFECT_RETRACTION>,
  // Emitter cooldown
    TransitionEffectL<TrConcat<TrInstant,
      AlphaL<Rgb<100,200,255>,Bump<Int<0>,Int<6000>>>,TrFade<1000>,
      AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFade<1000>,
      AlphaL<OrangeRed,Bump<Int<0>,Int<2800>>>,TrFade<1000>,
      AlphaL<Red,Bump<Int<0>,Int<1700>>>,TrFade<2000>>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Hilt PCB
  StylePtr<Layers<
    Mix<SwingSpeed<400>,HumpFlicker<RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<60,15,0>>,50>,Mix<SwingSpeed<600>,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<255,150,60>>>>,
  // Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
      AlphaL<Black,Int<16384>>,
      AlphaL<Black,Int<0>>>,
  // Clash - Photoblade Custom
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Rgb<60,0,255>,20,20>,BrownNoiseFlicker<Rgb<60,0,255>,Rgb<100,200,255>,500>,TrInstant,TrFade<300>,EFFECT_CLASH>,White,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
  // Stab
    TransitionEffectL<TrConcat<TrWipeIn<350>,Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,Rgb<60,0,255>,400>,Rgb<60,0,255>,Rgb<60,0,255>,Blue,DeepSkyBlue,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Blue,White,15,20>,GreenYellow,10,10>,500>>,TrFade<800>>,EFFECT_STAB>,

  // Blast
    MultiTransitionEffectL<TrJoin<
      // Impact Flash - BC always
      TrConcat<TrInstant,GreenYellow,TrDelay<25>>,
      // Waves
      TrSparkX<Mix<Int<16384>,BrownNoiseFlicker<Rgb<60,0,255>,Rgb<100,200,255>,500>,Black>,Int<250>,Int<350>>>,EFFECT_BLAST,5>,
    // Impact point and afterimage
    MultiTransitionEffectL<TrConcat<TrInstant,AlphaL<MultiTransitionEffect<BrownNoiseFlicker<Rgb<60,0,255>,Rgb<100,200,255>,500>,White,TrInstant,TrConcat<TrDelay<150>,TrFade<150>>,EFFECT_BLAST,5>,Bump<EffectPosition<EFFECT_BLAST>,Int<7000>>>,TrDelay<300>,TrFade<300>>,EFFECT_BLAST,5>,

  // Lockup - BC custom range mid-blade - Photonblade custom
    LockupTrL<AlphaL<RandomBlink<19000,Red,Strobe<Black,Rgb<60,0,255>,30,30>>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    
  // Non-Responsive Drag - Photoblade Custom
    LockupTrL<AlphaL<Gradient<Black,Black,Black,Black,Black,Stripes<500,4000,Rgb<60,0,255>,Black,Black>,RandomBlink<6000,Red,Strobe<Black,Yellow,15,30>>>,SmoothStep<Int<30000>,Int<30000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
  // Lightning Block Non-Responsive
    LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
      Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
      Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
      Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
    // Begin Lightning Transition
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
    // End Lightning Transition    
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,

  // Melt - Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions, uses TwistAngle<>
    LockupTrL<
      AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
      // Melt Shape
      SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
      // Melt Begin and End transitions
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrInstant,StyleFire<Red,Rgb<100,200,255>,0,6,FireConfig<200,3000,5>>,TrFade<500>>,EFFECT_IGNITION>,
    InOutTrL<TrWipeSparkTip<Rgb<100,200,255>,150>,
      TrConcat<TrInstant,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<200>,Int<300>,Int<200>,Int<32768>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<250>,Int<300>,Int<250>,Int<32768>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<300>,Int<300>,Int<300>,Int<32768>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<350>,Int<300>,Int<350>,Int<32768>>,Mix<SmoothStep<Int<24500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<400>,Int<300>,Int<400>,Int<32768>>,Black,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<400>,Int<300>,Int<400>,Int<32768>>,Rgb<100,200,255>,TrFade<50>>>,
    TransitionEffectL<TrConcat<
      TrWaveX<RotateColorsX<Variation,Orange>,Int<400>,Int<300>,Int<400>,Int<0>>,Mix<SmoothStep<Int<27500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<350>,Int<300>,Int<350>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<300>,Int<300>,Int<300>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<250>,Int<300>,Int<250>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWaveX<RotateColorsX<Variation,Orange>,Int<200>,Int<300>,Int<200>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrDelay<100>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrWipe<100>,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Orange,Rgb<60,15,0>,200>>>,
      TrFade<100>,Rgb<100,200,255>,TrInstant>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Rgb<100,200,255>,40>,TrFade<300>>,EFFECT_RETRACTION>,
  // Emitter cooldown
    TransitionEffectL<TrConcat<TrInstant,
      AlphaL<Rgb<100,200,255>,Bump<Int<0>,Int<6000>>>,TrFade<1000>,
      AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFade<1000>,
      AlphaL<OrangeRed,Bump<Int<0>,Int<2800>>>,TrFade<1000>,
      AlphaL<Red,Bump<Int<0>,Int<1700>>>,TrFade<2000>>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Chamber Top
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<128,128,0>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Orange,Black,2500>>>>(),
// Chamber Bot
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<128,128,0>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Orange,Black,2500>>>>(),
// Accent Ring
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<128,128,0>>,Black>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<Orange,10,30,Black,100,3000,1>>>>(),
"photon\nblade"},


{ "PitchBlk;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "MSV.wav",
//Second Sister base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
  // Second Sister Force Red
    TransitionEffectL<TrConcat<TrFade<200>,Rgb<255,50,50>,TrFade<400>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<255,50,50>>,TrFade<800>>,EFFECT_FORCE>,
BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Rgb<100,200,255>>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Rgb<100,200,255>,50>,TrFade<1000>>,EFFECT_IGNITION>,
  // BC_Bend2
    InOutTrL<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<175000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // Emitter cooldown
    TransitionEffectL<TrConcat<TrInstant,
      AlphaL<Rgb<100,200,255>,Bump<Int<0>,Int<6000>>>,TrFadeX<  Int<1000> >,
      AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFadeX<  Int<1000> >,
      AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX< Int<2000> >>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Hilt PCB
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
  // Second Sister Force Red
    TransitionEffectL<TrConcat<TrFade<200>,Rgb<255,50,50>,TrFade<400>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<255,50,50>>,TrFade<800>>,EFFECT_FORCE>,
BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Rgb<100,200,255>>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Rgb<100,200,255>,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
  // BC_Bend2
    InOutTrL<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<175000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // Emitter cooldown
    TransitionEffectL<TrConcat<TrInstant,
      AlphaL<Rgb<100,200,255>,Bump<Int<0>,Int<6000>>>,TrFadeX<  Int<1000> >,
      AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFadeX<  Int<1000> >,
      AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX< Int<2000> >>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Chamber Top
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Red,Black,2500>>>>(),
// Chamber Bottom
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Red,Black,2500>>>>(),
// Accent Ring
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,Black>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<Red,10,30,Black,100,3000,1>>>>(),
"pitch\nblack"},


{"a_KYLO/KyloUltimate;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "a_KYLO/KyloUltimate/tracks/Kylo1.wav", 
  StylePtr<Layers<
      StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
BC_effects_Red,
  // BC_SparkTipOut_Bend2
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Hilt PCB
  StylePtr<Layers<
      StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
  BC_effects_Red,
  // BC_SparkTipOut_Bend2
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Chamber Top
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<130,0,0>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Red,Black,2500>>>>(),
// Chamber Bottom
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<130,0,0>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Red,Black,2500>>>>(),
// Accent Ring 
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,Black>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,ColorCycle<Red,10,30,Black,100,3000,1>>>>(),
"kylo\nren"},


{ "Reboot_Redux;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "Reboot_Redux/tracks/binaire.wav",
  StylePtr<Layers<
    Mix<SmoothStep<Int<16000>,Int<10000>>,RotateColorsX<Variation,Blue>,StyleFire<RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,0,3,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,
  // Emitter Flare
      AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,
BC_effects_1,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
  // BC_SparkTipOut_Bend2
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrDelay<1500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<3000>>>,TrFade<2000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<4000>>>,TrFade<2500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<5000>>>,TrBoing<1950,7>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<500>,Int<200>,Int<500>,Int<32768>>>,TrDelay<1500>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<300>,Int<300>,Int<32768>>>,TrDelay<2000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<100>,Int<400>,Int<100>,Int<32768>>>,TrDelay<3000>,AlphaL<RotateColorsX<Variation,Rgb<95,0,210>>,Bump<Int<0>,Int<6000>>>,TrBoing<1450,5>>,EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Hilt PCB
  StylePtr<Layers<
    Mix<SmoothStep<Int<16000>,Int<10000>>,RotateColorsX<Variation,Blue>,StyleFire<RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,0,3,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,
  // Emitter Flare
      AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,
  BC_effects_1,   
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
  // BC_SparkTipOut_Bend2
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrDelay<1500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<3000>>>,TrFade<2000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<4000>>>,TrFade<2500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<5000>>>,TrBoing<1950,7>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<500>,Int<200>,Int<500>,Int<32768>>>,TrDelay<1500>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<300>,Int<300>,Int<32768>>>,TrDelay<2000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<100>,Int<400>,Int<100>,Int<32768>>>,TrDelay<3000>,AlphaL<RotateColorsX<Variation,Rgb<95,0,210>>,Bump<Int<0>,Int<6000>>>,TrBoing<1450,5>>,EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Chamber Top
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<130,40,230>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Rgb<0,0,100>,Rgb<130,40,230>,2500>>>>(),
// Chamber Bot
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<130,40,230>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Rgb<0,0,100>,Rgb<130,40,230>,2500>>>>(),
    
// Accent Ring 
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<130,40,230>>,Black>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,ColorCycle<Blinking<Blue,Rgb<130,40,230>,600,500>,10,30,Black,100,3000,1>>>>(),
"reboot\nredux"},

// preset 7
{ "aa_NoSloppy/Chaos;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "", 

  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Mix<LayerFunctions<Bump<SlowNoise<Int<1000>>,Int<12000>>,Bump<SlowNoise<Int<1000>>,Int<18000>>,Bump<SlowNoise<Int<3000>>,Int<22000>>,Bump<SlowNoise<Int<1000>>,Int<5000>>,Bump<SlowNoise<Int<1000>>,Int<25000>>,Bump<SlowNoise<Int<1000>>>>,RotateColorsX<SlowNoise<Int<1000>>,Red>,Black,RotateColorsX<Sin<Int<20>>,Red>,StyleFire<RotateColorsX<SlowNoise<Int<3000>>,Red>,Cyan>,Black>,Black>,   
    AlphaL<Mix<Sin<Int<40>>,AlphaL<RotateColorsX<SlowNoise<Int<1000>>,Red>,SparkleF<>>,Gradient<RotateColorsX<SlowNoise<Int<1000>>,Red>,RotateColorsX<SlowNoise<Int<5000>>,Red>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_1,
    TransitionEffectL<TrConcat<TrInstant,Gradient<RotateColorsX<SlowNoise<Int<1000>>,Red>,RotateColorsX<SlowNoise<Int<5000>>,Red>>,TrFade<500>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFade<2000>,Gradient<RotateColorsX<SlowNoise<Int<1000>>,Red>,RotateColorsX<SlowNoise<Int<5000>>,Red>>,TrInstant>,EFFECT_RETRACTION>,
    InOutTrL<TrInstant,TrWipeInSparkTip<White,1300>>,
   TransitionEffectL<TrConcat<TrInstant,AlphaL<BlinkingX<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,Scale<Trigger<EFFECT_RETRACTION,Int<6162>,Int<1>,Int<500>>,Int<300>,Int<1000>>,Int<500>>,Bump<Int<0>,Scale<Trigger<EFFECT_RETRACTION,Int<6162>,Int<1>,Int<500>>,Int<10000>,Int<0>>>>,TrFade<6162>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Blinking<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,200,500>,Bump<Int<0>,Int<3000>>>,TrFade<500>,AlphaL<Blinking<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,200,500>,Bump<Int<0>,Int<4000>>>,TrFade<500>,AlphaL<Blinking<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,200,500>,Bump<Int<0>,Int<5000>>>,TrBoing<1700,15>>,EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Hilt PCB
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Mix<LayerFunctions<Bump<SlowNoise<Int<1000>>,Int<12000>>,Bump<SlowNoise<Int<1000>>,Int<18000>>,Bump<SlowNoise<Int<3000>>,Int<22000>>,Bump<SlowNoise<Int<1000>>,Int<5000>>,Bump<SlowNoise<Int<1000>>,Int<25000>>,Bump<SlowNoise<Int<1000>>>>,RotateColorsX<SlowNoise<Int<1000>>,Red>,Black,RotateColorsX<Sin<Int<20>>,Red>,StyleFire<RotateColorsX<SlowNoise<Int<3000>>,Red>,Cyan>,Black>,Black>,   
    AlphaL<Mix<Sin<Int<40>>,AlphaL<RotateColorsX<SlowNoise<Int<1000>>,Red>,SparkleF<>>,Gradient<RotateColorsX<SlowNoise<Int<1000>>,Red>,RotateColorsX<SlowNoise<Int<5000>>,Red>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_1,
    TransitionEffectL<TrConcat<TrInstant,Gradient<RotateColorsX<SlowNoise<Int<1000>>,Red>,RotateColorsX<SlowNoise<Int<5000>>,Red>>,TrFade<500>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFade<2000>,Gradient<RotateColorsX<SlowNoise<Int<1000>>,Red>,RotateColorsX<SlowNoise<Int<5000>>,Red>>,TrInstant>,EFFECT_RETRACTION>,
    InOutTrL<TrInstant,TrWipeInSparkTip<White,1300>>,
   TransitionEffectL<TrConcat<TrInstant,AlphaL<BlinkingX<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,Scale<Trigger<EFFECT_RETRACTION,Int<6162>,Int<1>,Int<500>>,Int<300>,Int<1000>>,Int<500>>,Bump<Int<0>,Scale<Trigger<EFFECT_RETRACTION,Int<6162>,Int<1>,Int<500>>,Int<10000>,Int<0>>>>,TrFade<6162>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Blinking<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,200,500>,Bump<Int<0>,Int<3000>>>,TrFade<500>,AlphaL<Blinking<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,200,500>,Bump<Int<0>,Int<4000>>>,TrFade<500>,AlphaL<Blinking<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,200,500>,Bump<Int<0>,Int<5000>>>,TrBoing<1700,15>>,EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Chamber Top
  StylePtr<Layers<
    Blinking<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,200,500>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Rgb<0,0,100>,Rgb<130,40,230>,2500>>>>(),
// Chamber Bot
  StylePtr<Layers<
    Blinking<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,200,500>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Rgb<0,0,100>,Rgb<130,40,230>,2500>>>>(),
    
// Accent Ring 
  StylePtr<Layers<
    Blinking<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,200,500>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,ColorCycle<Blinking<Blue,Rgb<130,40,230>,600,500>,10,30,Black,100,3000,1>>>>(),
"chaos"},

{ "RootCore;ProffieOS_V2_Voicepack_Black_Bishop/common;commonBU", "RootCore/tracks/root.wav", 
// Main Blade
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,Black>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,ColorCycle<Red,10,30,Black,100,3000,1>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Hilt PCB
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,Black>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,ColorCycle<Red,10,30,Black,100,3000,1>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Chamber Top
  StylePtr<Layers<
    Black,
    PulsingL<RotateColorsX<Variation,Red>,Int<500>>,
    BlastFadeoutL<White>,
    LockupL<AudioFlicker<White,RotateColorsX<Variation,Red>>,AudioFlicker<White,RotateColorsX<Variation,Red>>,Int<32768>,Int<32768>,Int<32768>>,
    SimpleClashL<White,100,EFFECT_CLASH,SmoothStep<Int<0>,Int<24000>>>,
    InOutTrL<TrWipeSparkTipX<White,Int<300>>,TrInstant,Pulsing<Black,RotateColorsX<Variation,Red>,3000>>>>(),
 // Chamber Bot
  StylePtr<Layers<
    Black,
    PulsingL<RotateColorsX<Variation,Red>,Int<500>>,
    BlastFadeoutL<White>,
    LockupL<AudioFlicker<White,RotateColorsX<Variation,Red>>,AudioFlicker<White,RotateColorsX<Variation,Red>>,Int<32768>,Int<32768>,Int<32768>>,
    SimpleClashL<White,100,EFFECT_CLASH,SmoothStep<Int<0>,Int<24000>>>,
    InOutTrL<TrWipeSparkTipX<White,Int<300>>,TrInstant,Pulsing<Black,RotateColorsX<Variation,Red>,3000>>>>(),
// Accent Ring
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,Black>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,ColorCycle<Red,10,30,Black,100,3000,1>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"root\ncore"},

};


BladeConfig blades[] = {

{ NO_BLADE, // blade = 0  // proffie_D1_pad--->white_30AWG--->HiltPCB_ctrpin---> 
                        // proffie_D2_pad--->green_30AWG--->330ohm---->chamberBOT--->chamberTOP--->HiltPCB_D2pin--->330ohm--->5LEDs.
                        // proffie_D4_pad--->yellow_30AWG--->330ohm--->ACCENT LED MINI STRIP
  WS281XBladePtr<0, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (2, 6, WS281XBladePtr<7, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin4> >() ), // HiltPCB_LEDs
  SubBlade (1, 1, NULL),  // Chamber Top
  SubBlade (0, 0, NULL),  // Chamber Crystal 
  WS281XBladePtr<9, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), // Accents
  CONFIGARRAY(AllBlades),
"00_NO_BLADEsave"}, 

// 1" BC_A       123 apa105    
{ 660000,    // blade = 1  // proffie_D1_pad--->white_30AWG--->HiltPCB_ctrpin---> 
                        // proffie_D2_pad--->green_30AWG--->330ohm---->chamberBOT--->chamberTOP--->HiltPCB_D2pin--->330ohm--->5LEDs.
                        // proffie_D4_pad--->yellow_30AWG--->330ohm--->ACCENT LED MINI STRIP
  WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), //Main Blade
  SubBlade (2, 6, WS281XBladePtr<7, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin4> >() ), // HiltPCB_LEDs
  SubBlade (1, 1, NULL),  // Chamber Top
  SubBlade (0, 0, NULL),  // Chamber Crystal 
  WS281XBladePtr<9, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), // Accents
  CONFIGARRAY(AllBlades), 
"01_AllBladessave"}, 

{ 41596,    // blade = 2 // 1" Ciel_Tan_A 132
  WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), //   D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
// CONFIGARRAY(bladeCT_A),
// "bladeCT_Asave", }, 
   CONFIGARRAY(AllBlades), 
"02_AllBladessave", }, 

{ 5096,     // blade = 3 //   1" BC_B     131 5050s     D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
            //                                                                                 \-->33k>BP pin (--->LED NEG when blade in....4380.53ish?
   
  WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
// // CONFIGARRAY(bladeBC_B),
// // "bladeBC_Bsave"}, 
  CONFIGARRAY(AllBlades), 
"03_AllBladessave"}, 

{ 57328,     //blade = 4 // 7/8" Ciel_Tan_B             D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
            //                                                                                 \-->33k>BP pin (--->LED NEG when blade in....21067.20ish?
   
  WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
// // CONFIGARRAY(bladeCT_B),
// // "bladeCT_Bsave", },
  CONFIGARRAY(AllBlades), 
"05_AllBladessave"}, 

// { 7800,     // blade = 5 //   1" BC_C     123 APA105 10mm     D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
//             //                                                                                 \-->33k>BP pin (--->LED NEG when blade in....XXXXXish?
   
//   WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
//   SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
//   SubBlade (7, 7, NULL),  // Chamber Top
//   SubBlade (6, 6, NULL),  // Chamber Crystal
//   SubBlade (0, 5, NULL),  // Accents
// // CONFIGARRAY(bladeBC_C),
// // "bladeBC_Csave", }, 
//    CONFIGARRAY(AllBlades), 
// "04_AllBladessave", }, 




};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
