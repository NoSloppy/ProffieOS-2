// BC_EvoFlex_7.x.h
//   5050s pixels - white is too RED. Use Rgb<100,200,255>
// Latest upload: 8/16/23 OS7.x - Refreshed SD
// use BLADE_ID_SCAN_MILLIS

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 1

// ------ Audio Stuff --------

#define VOLUME 1800
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

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
//    Equivalent to just increasing maxLedsPerStrip.
#define EXTRA_COLOR_BUFFER_SPACE 30 
#define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000> // resistor value used
//    BridgedPullupBladeID is the default Proffieboard V3 BLADE_ID_CLASS, so it doesn't need to defined explicitly with a V3.
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9> // PBv2.2 TX pad for example
/*    SnapshotBladeID is the default Proffieboard V1.5 and V2.2 BLADE_ID_CLASS, so it doesn't need to defined explicitly.
      Sometimes works without Blade ID resistors.
      Using something like 200000 instead of NO_BLADE is best. */
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin>
//    Use with Blade ID. Specify the LED pad(s) that the main blade uses.
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
//    Required when blades on different data pads use common LED power pads.
//    and/or when BLADE_ID_SCAN_MILLIS is used with Blade ID.
#define SHARED_POWER_PINS
//    Choose how often to check for new blade (milliseconds).
//    Larger values will be a longer delay before a blade is recognized.
// #define BLADE_ID_SCAN_MILLIS 1000
// //    How many Blade ID scans to average (default is 10, works well)
// #define BLADE_ID_TIMES 10
//    Add this when using dual_prop, and make sure the blaster preset (no blade) is first in the config file.
//    Can be used with Blade Detect or Blade ID (including Blade ID with Constant Monitoring)
// #define DUAL_PROP_CONDITION (current_config != blades)
//    Requires wiring a pad to a switched GND
//    (floating pogo pin until grounded via blade-side PCB ring)
#define BLADE_DETECT_PIN blade3Pin

// ------ SD Card Stuff -------

#define ENABLE_SD
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
#define CLASH_THRESHOLD_G 4.5
#define BC_SWING_ON
#define BC_SWING_ON_SPEED 250 // Default 250
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
// #define NO_BLADE_NO_GEST_ONOFF


// ------- Custom / Experimental stuff ---------

//    BC - THIS NEEDS TO BE CheckLowBattry(), see PR     **Requires modified hybrid_font.h file.
// #define LOW_BATT_ONCE
//    This can save some RAM, but it's not compatible with IntArg/RgbArg (Edit Mode compatible stuff)
// #define OPTIMIZE_TRCONCAT

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

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS
#include "aliases/BC_effects_1_5050.h"
#include "aliases/BC_effects_2_5050.h"
#include "aliases/BC_effects_Red_5050.h"

/*
EvoFlex Blades config order:
Main Blade
NPXL
Chamber Top
Chamber Crystal
Accents

Presets:
0. BlackBishop
1. TheMaw
2. SenateMajority2
3. Photonblade
4. PitchBlk
5. KyloUltimate
6. Reboot_Redux
7. Chaos
-----------
NOBLADE
0. RootCore
*/


Preset AllBlades [] = {


// preset 0

{ "BlackBishop;common;commonBU", "BlackBishop/tracks/track04.wav",
// Main Blade   
  StylePtr<
    Layers<
    Mix<SwingSpeed<400>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    Mix<SwingSpeed<800>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<150,150,255>>>>,
BC_effects_1,
// Ignition and Retraction
    TransitionEffectL<TrConcat<TrInstant,StyleFire<Rgb<100,200,255>,Rgb<60,60,60>,0,8>,TrFadeX<Int<500>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<Black,Int<0>>,TrFade<300>,HumpFlickerL<Rgb<100,100,100>,25>,TrFade<500>>,EFFECT_IGNITION>,
    InOutTrL<TrWipeSparkTip<Rgb<100,200,255>,350>,TrWipeIn<450>>,
    TransitionEffectL<TrConcat<TrWipe<400>,Sparkle<AlphaL<Black,Int<0>>,Blue,1000,300>,TrDelayX<Int<1000>>>,EFFECT_PREON>,
// Emitter cooldown
    TransitionEffectL<TrConcat<TrSmoothFade<1500>,StyleFire<Rgb<100,100,100>,Rgb<100,100,100>,0,1,FireConfig<0,2000,15>,FireConfig<0,2000,15>,FireConfig<0,2000,15>,FireConfig<0,2000,15>>,TrFade<4000>>,EFFECT_RETRACTION>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Hilt PCB    
  StylePtr<Black>(),
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

  
// preset 1

{"aa_NoSloppy/TheMaw;common;commonBU", "",
  
  StylePtr<Layers<
// Main Blade    
    Mix<SmoothStep<Int<16000>,Int<10000>>,
      StripesX<Scale<TwistAngle<1>,Int<1500>,Int<3000>>,Int<-2000>,Rgb<60,0,255>,Black>,
      StripesX<Scale<TwistAngle<1>,Int<1500>,Int<3000>>,Int<2000>,Rgb<60,0,255>,Black>>,
// Ice Force
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
    TransitionEffectL<TrConcat<TrDelay<200>,Strobe<Black,Rgb<100,100,150>,15,40>,TrJoin<TrWipeInSparkTip<Rgb<100,200,255>,800,200>,TrWipeSparkTip<Rgb<100,200,255>,800,200>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrJoin<TrWipe<500>,TrWipeIn<500>>,Mix<SmoothStep<Int<16384>,Int<10000>>,Stripes<2000,-1500,Black,Rgb<60,0,255>>,Stripes<2000,1500,Black,Rgb<60,0,255>>>,TrFade<500>>,EFFECT_RETRACTION>,
    InOutTrL<
      TrJoin<
        TrJoin<TrWipeIn<800>,TrWaveX<Rgb<80,100,255>,Int<800>,Int<200>,Int<800>,Int<32768>>>,
        TrJoin<TrWipe<800>,TrWaveX<Rgb<80,100,255>,Int<400>,Int<200>,Int<800>,Int<0>>>>,
      TrJoin<
        TrJoin<TrWipeInX<Int<2000>>,TrWaveX<Rgb<80,100,255>,Int<1000>,Int<500>,Int<2000>,Int<32768>>>,
        TrJoin<TrWipeX<Int<2000>>,TrWaveX<Rgb<100,100,255>,Int<1000>,Int<500>,Int<2000>,Int<0>>>>>,
    TransitionEffectL<TrConcat<TrInstant,Rgb<80,100,255>,TrFade<50>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrDelay<1100>,Rgb<80,100,255>,TrFade<50>>,EFFECT_RETRACTION>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Hilt PCB
  StylePtr<Black>(),    
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


// preset 2
{"a_SIDIOUS/SenateMajority2;common;commonBU", "tracks/Palpatheme_SHORT.wav",
  StylePtr<Layers<
    Mix<SwingSpeed<500>,AudioFlicker<Gradient<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red>,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,
BC_effects_Red,       
    InOutTrL<TrConcat<TrColorCycle<80,-400,-1000>,Rgb<100,200,255>,TrWipeIn<50>,Black,TrDelay<450>,Strobe<Black,Rgb<100,200,255>,45,60>,TrJoinR<TrSmoothFade<190>,TrWipe<200>>>,TrConcat<TrInstant,Rgb<100,200,255>,TrJoin<TrJoin<TrJoin<TrColorCycle<2050,-1500,-1>,TrBoing<2050,15>>,TrBoing<2050,18>>,TrSmoothFade<2050>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Hilt PCB
  StylePtr<Black>(),   
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

// {"Troy/DualPhze;common;commonBU", "",
//   StylePtr<Layers<Stripes<3500,-3000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,RotateColorsX<Variation,Rgb<255,50,50>>,RotateColorsX<Variation,Rgb<128,0,0>>>,TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,LockupTrL<AlphaL<Strobe<Rgb<100,200,255>,BrownNoiseFlicker<Rgb<100,200,255>,Blue,300>,50,1>,Bump<Sin<Int<10>,Int<10000>,Int<20000>>,Int<12000>>>,TrConcat<TrInstant,Rgb<100,200,255>,TrFade<200>>,TrFade<400>,SaberBase::LOCKUP_NORMAL>,LockupTrL<AlphaL<Rgb<100,200,255>,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<Rgb<100,200,255>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,BlastL<Rgb<100,200,255>>,LocalizedClashL<Rgb<100,200,255>>,TransitionEffectL<TrConcat<TrInstant,StyleFire<RotateColorsX<Variation,Rgb<255,150,150>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,6>,TrFade<1200>>,EFFECT_IGNITION>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,ResponsiveDragL<BrownNoiseFlickerL<Rgb<100,200,255>,Int<300>>,TrWipeIn<400>,TrFade<400>>,ResponsiveMeltL<Mix<TwistAngle<>,OrangeRed,Orange>,TrWipeIn<600>,TrSmoothFade<600>>,InOutTrL<TrWipeSparkTip<Rgb<100,200,255>,300>,TrWipeInSparkTip<Rgb<100,200,255>,500>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<Rgb<100,200,255>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,TrDelay<500>>,EFFECT_RETRACTION>,TransitionEffectL<TrConcat<TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<60,0,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<60,0,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<128,0,0>>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<128,0,0>>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<190,0,0>>,30>,SmoothStep<Int<6000>,Int<-500>>>,TrDelay<5100>>,EFFECT_PREON>>>(),
//   StylePtr<Black>(),
//   StylePtr<Black>(),
//   StylePtr<Black>(),
//   StylePtr<Black>(),
// "dual\nphaze"},


// preset 3

{"aa_Blueforce/Photonblade;common;commonBU", "",
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
// Blast - Photoblade Custom
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<50>>,EFFECT_BLAST>,
    BlastL<BrownNoiseFlicker<Rgb<60,0,255>,Rgb<100,200,255>,500>,400,200,500>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<200>,BrownNoiseFlicker<Rgb<60,0,255>,Rgb<100,200,255>,500>,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
    BlastL<White,500,350,100000>,                                           
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
// Melt    
    LockupTrL<
      AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
      // Melt Shape
      SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
      // Melt Begin and End transitions
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
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
// On-Demand Battery Level  
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Hilt PCB  
  StylePtr<Black>(),
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


// preset 4

{ "PitchBlk;common;commonBU", "MSV.wav",

//Second Sister base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
// Second Sister Force Red
    TransitionEffectL<TrConcat<TrFade<200>,Rgb<255,50,50>,TrFade<400>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<255,50,50>>,TrFade<800>>,EFFECT_FORCE>,
BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Rgb<100,200,255>>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Rgb<100,200,255>,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
    InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<100,200,255>,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// Emitter cooldown
    TransitionEffectL<TrConcat<TrInstant,
      AlphaL<Rgb<100,200,255>,Bump<Int<0>,Int<6000>>>,TrFadeX<  Int<1000> >,
      AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFadeX<  Int<1000> >,
      AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX< Int<2000> >>,EFFECT_RETRACTION>,    
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Hilt PCB  
  StylePtr<Black>(),
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


// preset 5

{"a_KYLO/KyloUltimate;common;commonBU", "a_KYLO/KyloUltimate/tracks/Kylo1.wav", 
  StylePtr<Layers<
      StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
BC_effects_Red,
    InOutTrL<TrWipeSparkTip<Rgb<100,200,255>,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>>>(),
// Hilt PCB
  StylePtr<Black>(),   
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


// preset 6

{ "Reboot_Redux;common;commonBU", "Reboot_Redux/tracks/binaire.wav", 

  StylePtr<Layers<
    Mix<SmoothStep<Int<16000>,Int<10000>>,RotateColorsX<Variation,Blue>,StyleFire<RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,0,3,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,
// Emitter Flare
      AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,
BC_effects_1,   
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
    InOutTrL<TrWipeSparkTip<White,1000>,TrWipeInSparkTip<White,1300>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrDelay<1500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<3000>>>,TrFade<2000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<4000>>>,TrFade<2500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<5000>>>,TrBoing<1950,7>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<500>,Int<200>,Int<500>,Int<32768>>>,TrDelay<1500>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<300>,Int<300>,Int<32768>>>,TrDelay<2000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<100>,Int<400>,Int<100>,Int<32768>>>,TrDelay<3000>,AlphaL<RotateColorsX<Variation,Rgb<95,0,210>>,Bump<Int<0>,Int<6000>>>,TrBoing<1450,5>>,EFFECT_PREON>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Hilt PCB
  StylePtr<Black>(),    
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
{ "aa_NoSloppy/Chaos;common;commonBU", "", 

  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Mix<LayerFunctions<Bump<SlowNoise<Int<1000>>,Int<12000>>,Bump<SlowNoise<Int<1000>>,Int<18000>>,Bump<SlowNoise<Int<3000>>,Int<22000>>,Bump<SlowNoise<Int<1000>>,Int<5000>>,Bump<SlowNoise<Int<1000>>,Int<25000>>,Bump<SlowNoise<Int<1000>>>>,RotateColorsX<SlowNoise<Int<1000>>,Red>,Black,RotateColorsX<Sin<Int<20>>,Red>,StyleFire<RotateColorsX<SlowNoise<Int<3000>>,Red>,Cyan>,Black>,Black>,   
    AlphaL<Mix<Sin<Int<40>>,AlphaL<RotateColorsX<SlowNoise<Int<1000>>,Red>,SparkleF<>>,Gradient<RotateColorsX<SlowNoise<Int<1000>>,Red>,RotateColorsX<SlowNoise<Int<5000>>,Red>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
  
BC_effects_1,
    TransitionEffectL<TrConcat<TrInstant,Gradient<RotateColorsX<SlowNoise<Int<1000>>,Red>,RotateColorsX<SlowNoise<Int<5000>>,Red>>,TrFade<500>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFade<2000>,Gradient<RotateColorsX<SlowNoise<Int<1000>>,Red>,RotateColorsX<SlowNoise<Int<5000>>,Red>>,TrInstant>,EFFECT_RETRACTION>,
    InOutTrL<TrInstant,TrWipeInSparkTip<White,1300>>,
   TransitionEffectL<TrConcat<TrInstant,AlphaL<BlinkingX<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,Scale<Trigger<EFFECT_RETRACTION,Int<6162>,Int<1>,Int<500>>,Int<300>,Int<1000>>,Int<500>>,Bump<Int<0>,Scale<Trigger<EFFECT_RETRACTION,Int<6162>,Int<1>,Int<500>>,Int<10000>,Int<0>>>>,TrFade<6162>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Blinking<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,200,500>,Bump<Int<0>,Int<3000>>>,TrFade<500>,AlphaL<Blinking<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,200,500>,Bump<Int<0>,Int<4000>>>,TrFade<500>,AlphaL<Blinking<RotateColorsX<SlowNoise<Int<10000>>,Red>,Black,200,500>,Bump<Int<0>,Int<5000>>>,TrBoing<1700,15>>,EFFECT_PREON>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Hilt PCB
  StylePtr<Black>(),    
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

};


//----------------------------------------------------------------------------------------------------------------------------------------
Preset noblade[] = {

// // Try Sparkle<Red> as accents style

{ "RootCore;common;commonBU", "RootCore/tracks/root.wav", 
// Main Blade
  StylePtr<Black>(),                                  
// Hilt PCB
// Accent Ring 
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,Black>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,ColorCycle<Red,10,30,Black,100,3000,1>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
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
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
>>(),
"root\ncore"},


// // { "testfont;common;commonBU", "tracks/theforce1.wav",
// //     StylePtr<Black>(),
// //     StylePtr<Black>(),
// //     StylePtr<Black>(),
// //     StylePtr<Black>(),
// //     StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),

// // "testfont"},

// // { "LngthFnd;common;commonBU", "",
// //     StylePtr<LengthFinder<>>(),
// //     StylePtr<Black>(),
// //     StylePtr<Black>(), 
// //     StylePtr<Yellow>(),
// //     StylePtr<Yellow>(),
// // "length\nfinder"},

// // { "BattLevl;common;commonBU", "tracks/theforce1.wav",
// //      StylePtr<Black>(), 
// //      StylePtr<PulsingX<Mix<BatteryLevel,Red,Yellow,Green>,Black,BatteryLevel>>(),
// //      StylePtr<PulsingX<Mix<BatteryLevel,Red,Yellow,Green>,Black,BatteryLevel>>(),
// //      StylePtr<PulsingX<Mix<BatteryLevel,Red,Yellow,Green>,Black,BatteryLevel>>(),
// //      StylePtr<PulsingX<Mix<BatteryLevel,Red,Yellow,Green>,Black,BatteryLevel>>(),
// // "battery\nlevel"}

};


BladeConfig blades[] = {

{ 790000, // blade = 0  // proffie_D1_pad--->white_30AWG--->HiltPCB_ctrpin---> 
                        // proffie_D2_pad--->green_30AWG--->330ohm---->chamberBOT--->chamberTOP--->HiltPCB_D2pin--->330ohm--->5LEDs.
                        // proffie_D4_pad--->yellow_30AWG--->330ohm--->ACCENT LED MINI STRIP
  WS281XBladePtr<0, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (2, 6, WS281XBladePtr<7, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin4> >() ), // HiltPCB_LEDs
  SubBlade (1, 1, NULL),  // Chamber Top
  SubBlade (0, 0, NULL),  // Chamber Crystal 
  WS281XBladePtr<9, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), // Accents
  CONFIGARRAY(noblade),
"00_NO_BLADEsave"}, 

// 1" BC_A       123 apa105    
{ 660000,    // blade = 1  // proffie_D1_pad--->white_30AWG--->HiltPCB_ctrpin---> 
                        // proffie_D2_pad--->green_30AWG--->330ohm---->chamberBOT--->chamberTOP--->HiltPCB_D2pin--->330ohm--->5LEDs.
                        // proffie_D4_pad--->yellow_30AWG--->330ohm--->ACCENT LED MINI STRIP
  WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), //Main Blade
  SubBlade (2, 6, WS281XBladePtr<7, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin4> >() ), // HiltPCB_LEDs
  SubBlade (1, 1, NULL),  // Chamber Top
  SubBlade (0, 0, NULL),  // Chamber Crystal 
  WS281XBladePtr<9, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), // Accents
  CONFIGARRAY(AllBlades), 
"01_AllBladessave"}, 

{ 41596,    // blade = 2 // 1" Ciel_Tan_A 132
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
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
   
  WS281XBladePtr<131, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
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
   
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
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
