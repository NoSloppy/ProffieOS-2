// BC_Starkiller_6.x.h

// Starkiller hilt

//   5050s pixels - white is too RED. Use Rgb<100,200,255>
// BC_Scoundrel_6.x_CONSTANT_BLADEID_TEST

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 5
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

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
// New define that can speed up processing a bit. Basically, it can calculate the colors for the next
// blade (or the next frame for the same blade) even though it's not done feeding out the data for the
// data in the color buffer yet.Equivalent to just indrasing maxLedsPerStrip.
// #define EXTRA_COLOR_BUFFER_SPACE 30
#define SHARED_POWER_PINS
#define BLADE_DETECT_PIN blade3Pin
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
#define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9> // TX pad
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> // This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
// Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value, so I would recommend using something like 200000 instead of NO_BLADE.

// ------ SD Card Stuff -------

#define ENABLE_SD
#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    // #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING        // upload overwrites presets.ini/tmp unless this is defined

// ------- OLED stuff ----------

// #define ENABLE_SSD1306
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
// #define NO_BATTERY_MONITOR
// #define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
// #define ENABLE_DEVELOPER_COMMANDS
#define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SDA_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE
// The following changes the angle required to register twists on curved hilts
// #define ORIENTATION_ROTATION 0,-20,0
// #define CONFIG_STARTUP_DELAY 15000               // BC now canon
// #define OLED_FLIP_180                            // BC now canon
// #define USE_AUREBESH_FONT
#define VOLUME_MENU_CYCLE                           // BC now canon
#define NO_REPEAT_RANDOM                            // BC now canon
#define DISABLE_BASIC_PARSER_STYLES                 // Standard, Advanced, Old School original templated styles etc...

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3.0
#define BC_SWING_ON                                 // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
// #define BC_STAB_ON
#define BC_THRUST_ON
// #define BC_TWIST_ON
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

#define ENABLE_ALL_MENU_OPTIONS                     // fett263 prop
    // #define DYNAMIC_BLADE_LENGTH
    // #define DYNAMIC_BLADE_DIMMING
    // #define DYNAMIC_CLASH_THRESHOLD
    // #define SAVE_VOLUME
    // #define SAVE_BLADE_DIMMING
    // #define SAVE_CLASH_THRESHOLD
    // #define SAVE_COLOR_CHANGE

// -------- Blaster Stuff ----------

// #define ENABLE_BLASTER_AUTO
// #define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
// #define BLASTER_JAM_PERCENTAGE 10     // if not defined, random.

#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"              // For Red, Green, light Blue, ...light colored blades
#include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"  // EffectSequence driven different blast animations
#include "aliases/TrueWhites/BC_effects_2.h"              // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"            // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_White.h"          // For White blades
#include "aliases/TrueWhites/BC_12color_8effect_SS.h"     // All in one blade style from CC Fork. SS = SwingSpeed included 

// Main Blade
// NPXL
// Chamber Top
// Chamber Crystal
// Accents

/* accel in/out
   InOutTrL<
     TrConcat<TrInstant,Layers<
      TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<1950>>,EFFECT_IGNITION>,
      AlphaL<AudioFlicker<RotateColorsX<Variation,Rgb<0,149,255>>,RotateColorsX<Variation,Rgb<0,85,200>>>,
        SmoothStep<Scale<Trigger<EFFECT_IGNITION,Scale<Trigger<EFFECT_IGNITION,Int<2000>,Int<1>,Int<1>>,Int<300>,Int<2000>>,Int<1>,Int<1>>,Int<-1200>,Int<35000>>,Int<-3000>>>>,TrDelay<5000>>,
     TrConcat<TrInstant,Layers<
     TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<2000>>,EFFECT_RETRACTION>,
     AlphaL<AudioFlicker<RotateColorsX<Variation,Rgb<0,149,255>>,RotateColorsX<Variation,Rgb<0,85,200>>>,
       SmoothStep<Scale<Trigger<EFFECT_RETRACTION,Scale<Trigger<EFFECT_RETRACTION,Int<1000>,Int<1000>,Int<1>>,Int<3000>,Int<10>>,Int<1000>,Int<500>>,Int<35000>,Int<-1200>>,Int<-3000>>>>,TrDelay<1000>>>,

1. a_STARKILLER/DarkAppr
2. a_STARKILLER/Strkllr1
3. aa_Juansith/HATE
4. aa_LordBlako/PitchBlk // BC_12color8effect_SS
5. aa_Greyscale/BinaryDark_Greyscale // 12color ColorChange on crystals and accents
6. aa_SyntheticEpiphany/The_Chain_Saber
7. aa_SyntheticEpiphany/Insurrection // fixed mistimed retraction/postoff
8. aa_SyntheticEpiphany/Balanced_Entropy
9. aa_SyntheticEpiphany/The_Ice_Saber
10. aa_SyntheticEpiphany/The_Magma_Saber
11. aa_SyntheticEpiphany/The_Stone_Saber // BC_12color8effect_SS. BC Accel in/out
12. aa_Blueforce/LiquidStatic

NoBlade:
a_STARKILLER/DarkAppr
*/
Preset AllBlades [] = {


{ "a_STARKILLER/DarkAppr;common;commonBU", "tracks/TFU1.wav", 
// Main Blade
    StylePtr<Layers<
      AudioFlicker<Red,Sparkle<Rgb<150,10,0>,Red,15,5000>>,
      BC_effects_Red,
      TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,AlphaL<White,Bump<Int<0>>>,TrInstant>,EFFECT_RETRACTION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrSmoothFade<300>>,EFFECT_IGNITION>,
      InOutTrL<TrWipeSparkTip<White,250,500>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
      // On-Demand Battery Level
      AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
// NPXL
    StylePtr<Layers<Black,
      AlphaL<Red,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<Black,AlphaL<Red,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>
    >>(),
// Chamber Top
  StylePtr<Layers<
    Pulsing<Black,Red,500>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Black,Red,3000>>
  >>(),
// Chamber Crystal
    StylePtr<Layers<
      StaticFire<Red,OrangeRed,0,2,0,1500,0>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Red,Sparkle<Black,White,7>,3000>>
    >>(),
// Accents
    StylePtr<Layers<
      Mix<Bump<Sin<Int<120>,Int<10>,Int<32000>>,Int<16000>>,Black,Red>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Mix<Bump<Sin<Int<40>,Int<10>,Int<32000>>,Int<10000>>,Black,Red>>
    >>(),
    "dark\napprentice"
},

{ "a_STARKILLER/Strkllr1;common;commonBU", "a_STARKILLER/tracks/SKT4.wav", 
// Main Blade
    StylePtr<Layers<
      AudioFlicker<Red,Sparkle<Rgb<150,10,0>,Red,15,5000>>,
      BC_effects_Red,
      TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,AlphaL<White,Bump<Int<0>>>,TrInstant>,EFFECT_RETRACTION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrSmoothFade<300>>,EFFECT_IGNITION>,
      InOutTrL<TrWipeSparkTip<White,250,500>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
      // On-Demand Battery Level
      AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
// NPXL
    StylePtr<Layers<Black,
      AlphaL<Red,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<Black,AlphaL<Red,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>
    >>(),
// Chamber Top
    StylePtr<Layers<
      Pulsing<Black,Red,500>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Black,Red,3000>>
    >>(),
// Chamber Crystal
    StylePtr<Layers<
      StaticFire<Red,OrangeRed,0,2,0,1500,0>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Red,Sparkle<Black,White,7>,3000>>
    >>(),
// Accents
    StylePtr<Layers<
      Mix<Bump<Sin<Int<120>,Int<10>,Int<32000>>,Int<16000>>,Black,Red>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Mix<Bump<Sin<Int<40>,Int<10>,Int<32000>>,Int<10000>>,Black,Red>>
    >>(),
    "starkiller"
},

{ "aa_Juansith/HATE;common;commonBU", "",
// Main Blade
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<>>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<600>>,EFFECT_IGNITION>,
    InOutTrL<TrWipeSparkTip<Rgb<200,100,100>,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// NPXL
    StylePtr<Layers<Black,
      AlphaL<Red,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<Black,AlphaL<Red,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>
    >>(),
// Chamber Top
    StylePtr<Layers<
      Pulsing<Black,Red,500>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Black,Red,3000>>
    >>(),
// Chamber Crystal
    StylePtr<Layers<
      StaticFire<Red,OrangeRed,0,2,0,1500,0>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Red,Sparkle<Black,White,7>,3000>>
    >>(),
// Accents
    StylePtr<Layers<
      Mix<Bump<Sin<Int<120>,Int<10>,Int<32000>>,Int<16000>>,Black,Red>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Mix<Bump<Sin<Int<40>,Int<10>,Int<32000>>,Int<10000>>,Black,Red>>
    >>(),
    "hate"
},

{ "aa_LordBlako/PitchBlk;common;commonBU", "tracks/MSV.wav",
// Main Blade
  StylePtr<Layers<
    BC_12color_8effect_SS, // 96 possible blade combos in one style. Uses BC_SWAP.
    BC_effects_Red,
   InOutTrL< // accel in/out
     TrConcat<TrInstant,Layers<
      TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<1950>>,EFFECT_IGNITION>,
      AlphaL<AudioFlicker<
          ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
          ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,
        SmoothStep<Scale<Trigger<EFFECT_IGNITION,Scale<Trigger<EFFECT_IGNITION,Int<2000>,Int<1>,Int<1>>,Int<300>,Int<2000>>,Int<1>,Int<1>>,Int<-1200>,Int<35000>>,Int<-3000>>>>,TrDelay<5000>>,
     TrConcat<TrInstant,Layers<
     TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<2000>>,EFFECT_RETRACTION>,
     AlphaL<AudioFlicker<
        ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
        ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,
       SmoothStep<Scale<Trigger<EFFECT_RETRACTION,Scale<Trigger<EFFECT_RETRACTION,Int<1000>,Int<1000>,Int<1>>,Int<3000>,Int<10>>,Int<1000>,Int<500>>,Int<35000>,Int<-1200>>,Int<-3000>>>>,TrDelay<1000>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// NPXL
    StylePtr<Layers<Black,
    AlphaL<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<
        Black,
        AlphaL<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>
    >>(),
// Chamber Top
    StylePtr<InOutTr<Pulsing<Black,AudioFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,800>,TrWipe<300>,TrConcat<TrWipeIn<800>,Black,TrFade<300>>,Pulsing<Black,AudioFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,3000>
    >>(),
// Chamber Crystal
    StylePtr<Layers<
      AudioFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<300>,TrConcat<TrWipeIn<500>,Black,TrFade<300>>,Pulsing<RandomFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,Pulsing<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,60,100>>,800>>,Black,3000>>
    >>(),
// Accents
    StylePtr<Layers<Black,
      TransitionLoopL<TrConcat<TrWipe<200>,Pulsing<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,AudioFlickerL<ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,800>,TrWipeIn<200>>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<300>,TrConcat<TrWipeIn<2000>,Black,TrFade<100>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>
    >>(),
    "pitch\nblack"
},

{ "aa_Greyscale/BinaryDark_Greyscale;common;commonBU", "",
    StylePtr<Layers<        
      //Force effect toggles between Red and Deep Sky Blue. You can still use the color wheel to try out other colors paired together or edit the colors below yourself.
      EffectSequence<EFFECT_FORCE,      
      //Deep Sky Blue
      Layers<      
            //Fett263 Humpflicker
        HumpFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,50,120>>,50>,        
        //Fett263 unstable swing
        AlphaL<AudioFlickerL<Stripes<1000,-1500,RandomPerLEDFlicker<RotateColorsX<Variation,Cyan>,Black>,Black,RotateColorsX<Variation,DeepSkyBlue>,Black>>,SwingSpeed<350>>,        
        //Ripple swing effect using Fett263's scaled responsive swing
        AlphaL<AlphaL<Stripes<2000,-2250,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb<0,50,40>>,Pulsing<RotateColorsX<Variation,Rgb<0,35,20>>,Black,800>>,HoldPeakF<Scale<IsLessThan<SwingSpeed<850>,Int<13600>>,Scale<SwingSpeed<850>,Int<-19300>,Int<32768>>,Int<0>>,Int<550>,Scale<SwingAcceleration<100>,Int<20000>,Int<10000>>>>,SmoothStep<Scale<Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>,Int<15000>,Int<5000>>,Int<16000>>>,
        //Fett263 unstable ignition with slow fade from red to deep sky blue
        TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-1550,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<3000>,HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,50>,TrDelay<5000>,HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,50>,TrFade<5000>>,EFFECT_IGNITION>>,
      // Red
      Layers<        
        // Fett263 Humpflicker
            HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,50>,        
        // Fett263 unstable swing
        AlphaL<AudioFlickerL<Stripes<1000,-1500,RandomPerLEDFlicker<RotateColorsX<Variation,DarkOrange>,Black>,Black,RotateColorsX<Variation,Red>,Black>>,SwingSpeed<350>>,        
        // Ripple swing effect using Fett263's scaled responsive swing
        AlphaL<AlphaL<Stripes<2000,-2250,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<60,30,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,15,0>>,Black,800>>,HoldPeakF<Scale<IsLessThan<SwingSpeed<850>,Int<13600>>,Scale<SwingSpeed<850>,Int<-19300>,Int<32768>>,Int<0>>,Int<550>,Scale<SwingAcceleration<100>,Int<20000>,Int<10000>>>>,SmoothStep<Scale<Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>,Int<15000>,Int<5000>>,Int<16000>>>,
        // Fett263 unstable ignition with slow fade from deep sky blue to red
        TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-1550,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<3000>,HumpFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,50,120>>,50>,TrDelay<5000>,HumpFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,50,120>>,50>,TrFade<5000>>,EFFECT_IGNITION>>>,
      // Fett263 unstable force effect with sizzle emitter ending - Toggles the base saber colors between red and blue.
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<150>,StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,20>,RotateColorsX<Variation,Rgb<10,0,10>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,255>>,70>,RotateColorsX<Variation,Rgb<128,0,128>>>,RotateColorsX<Variation,Rgb<80,0,80>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrDelay<1000>,StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,20>,RotateColorsX<Variation,Rgb<10,0,10>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,255>>,70>,RotateColorsX<Variation,Rgb<128,0,128>>>,RotateColorsX<Variation,Rgb<80,0,80>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrFade<1000>,AlphaL<StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,20>,RotateColorsX<Variation,Rgb<10,0,10>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,255>>,70>,RotateColorsX<Variation,Rgb<128,0,128>>>,RotateColorsX<Variation,Rgb<80,0,80>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,Bump<Int<3500>,Int<23384>>>,TrFade<600>>,EFFECT_FORCE>,
      // Fett263 Responsive Intensity Lockup effect with absorb endlock
      LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<0>>,TrWaveX<RgbArg<LOCKUP_COLOR_ARG,White>,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<HumpFlicker<White,Rgb<40,60,60>,50>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>>,TrFade<350>>,SaberBase::LOCKUP_NORMAL>,
      //Fett263 Responsive Intensity Lockup effect
      //LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<0>>,TrWaveX<RgbArg<LOCKUP_COLOR_ARG,White>,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>>,SaberBase::LOCKUP_NORMAL>,
      // Fett263 Responsive Lightning Block
      ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,White>,Int<16000>>,30>,TrSmoothFade<600>>>,
      // Responsive Stab
      ResponsiveStabL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Yellow>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,50>>,TrFadeX<Percentage<WavLen<EFFECT_STAB>,50>>>,
      // Blast selection based on absorb effect
      ColorSelect<WavNum<EFFECT_BLAST>,TrInstant,
        // Fett263 Responsive Blast Wave
        TransitionEffectL<TrConcat<TrInstant,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,TrDelay<500>>,EFFECT_BLAST>,
        // Fett263 Responsive Blast Wave with absorb effect
        TransitionEffectL<TrConcat<TrInstant,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,TrFade<500>,AlphaL<HumpFlicker<White,Rgb<40,60,60>,50>,Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>>>,TrFade<350>>,EFFECT_BLAST>>,
      // Fett263 Responsive Blast Wave
      //ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,
      // OS6 Random Fett263 Responsive Multi-Blast
      //ColorSelect<RandomF,TrInstant,ResponsiveBlastL<RgbArg<BLAST_COLOR_ARG,White>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<RgbArg<BLAST_COLOR_ARG,White>,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<RgbArg<BLAST_COLOR_ARG,White>,200,200>,ResponsiveBlastFadeL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
      // OS6 Fett263 Random Responsive Blast
      //MultiTransitionEffectL<TrRandom<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<28000>,Int<8000>>>,TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<16384>,Int<6000>>>,TrFade<50>,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrSparkX<Remap<CenterDistF<EffectPosition<>>,Stripes<2000,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Int<300>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>>,TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<16384>,Int<6000>>>,TrFade<50>,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrWaveX<Remap<CenterDistF<EffectPosition<>>,Stripes<1500,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>>,Int<160>,Int<100>,Int<300>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>>,TrConcat<TrInstant,AlphaMixL<Bump<EffectPosition<>,Scale<WavLen<>,Int<9000>,Int<12000>>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>,TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<000>>,Scale<WavLen<>,Int<9000>,Int<13000>>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>>,EFFECT_BLAST>,
      // OS5 Fett263 Multi-Blast, blaster reflect cycles through different responsive effects (I like the look of this one the best even with the new OS6 stuff)
      //EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
      // Fett263 Real Clash with absorb effect
      Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,NavajoWhite>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<300>,Int<200>,Int<940>>>,AlphaL<HumpFlicker<White,Rgb<40,60,60>,50>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>>,TrFade<350>>,EFFECT_CLASH>,TransitionEffectL<TrConcat<TrWaveX<RgbArg<CLASH_COLOR_ARG,NavajoWhite>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,AlphaL<HumpFlicker<White,Rgb<40,60,60>,50>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>>,TrFade<350>>,EFFECT_CLASH>>,
      
      //Fett263 Real Clash
      //Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,

      //Fett263 Intensity Drag
      LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,White>>,SmoothStep<IntArg<DRAG_SIZE_ARG,27500>,Int<5000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,29250>,Int<5000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
        
      //Alternate Responsive Drag
      //LockupTrL<AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeInX<WavLen<EFFECT_DRAG_BEGIN>>,TrFadeX<WavLen<EFFECT_DRAG_END>>,SaberBase::LOCKUP_DRAG>,
      
      //Fett263 Responsive Intensity Melt
      LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,26000>,Int<6000>>>,TrConcat<TrWipeIn<100>,AlphaL<Red,SmoothStep<Int<29000>,Int<8000>>>,TrExtend<2000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<29000>,Int<8000>>>,TrFade<3000>>,TrFade<250>,SaberBase::LOCKUP_MELT>,
      
      //Fett263 Power Save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
      EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
      
      //Spark tip ignition and cycle down retraction
      InOutTrL<TrWipeSparkTip<White,1500>,TrColorCycleX<Int<500>,500>>,
      
      //Force effect toggles between red and deep sky blue
      EffectSequence<EFFECT_FORCE,
        
        //Deep sky blue glowing emitter retraction with fizzle out post off
        TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,DeepSkyBlue>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<1500>>,Int<2000>,Int<4500>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_RETRACTION>>,Black,TrDelay<897>,AlphaL<RandomPerLEDFlicker<RotateColorsX<Variation,DeepSkyBlue>,Black>,Bump<Int<10500>,Int<11500>>>,TrDelay<150>>,EFFECT_RETRACTION>,
        
        //Red glowing emitter retraction with fizzle out post off
        TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Red>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<1500>>,Int<2000>,Int<4500>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_RETRACTION>>,Black,TrDelay<897>,AlphaL<RandomPerLEDFlicker<RotateColorsX<Variation,Red>,Black>,Bump<Int<10500>,Int<11500>>>,TrDelay<150>>,EFFECT_RETRACTION>>,
      
      //Force effect toggles between red and deep sky blue
      EffectSequence<EFFECT_FORCE,
        
        //Unstable deep sky blue noise responsive post off
        TransitionEffectL<TrConcat<TrDelayX<WavLen<EFFECT_RETRACTION>>,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,DeepSkyBlue>,125>,SmoothStep<Scale<NoisySoundLevel,Int<2500>,Int<15000>>,Int<-4000>>>,TrFadeX<WavLen<EFFECT_POSTOFF>>>,EFFECT_RETRACTION>,
        
        //Unstable red noise responsive post off
        TransitionEffectL<TrConcat<TrDelayX<WavLen<EFFECT_RETRACTION>>,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,125>,SmoothStep<Scale<NoisySoundLevel,Int<2500>,Int<15000>>,Int<-4000>>>,TrFadeX<WavLen<EFFECT_POSTOFF>>>,EFFECT_RETRACTION>>,

      //Optional/alternate Fett263 Passive Battery Monitor (fett263 prop file not required), on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.  
      //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
      //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,

      //Force effect toggles between red and deep sky blue
      EffectSequence<EFFECT_FORCE,
        
        //Red false start preon
        TransitionEffectL<TrConcat<TrDelay<500>,Black,TrWaveX<RotateColorsX<Variation,Red>,Int<750>,Int<175>,Int<1575>,Int<-3000>>,Black,TrInstant,AlphaL<RandomPerLEDFlicker<RotateColorsX<Variation,Red>,Black>,Bump<Int<12000>,Int<11500>>>,TrDelay<150>>,EFFECT_PREON>,
        
        //Deep sky blue false start preon
        TransitionEffectL<TrConcat<TrDelay<500>,Black,TrWaveX<RotateColorsX<Variation,DeepSkyBlue>,Int<750>,Int<175>,Int<1575>,Int<-3000>>,Black,TrInstant,AlphaL<RandomPerLEDFlicker<RotateColorsX<Variation,DeepSkyBlue>,Black>,Bump<Int<12000>,Int<11500>>>,TrDelay<150>>,EFFECT_PREON>>,
      
      //Noise responsive sparking emitter preon
      TransitionEffectL<TrConcat<TrInstant,AlphaL<White,SmoothStep<Scale<NoisySoundLevel,Int<150>,Int<10000>>,Int<-4000>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),  
// NPXL
    StylePtr<Layers<Black,
    AlphaL<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<
        Black,
        AlphaL<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>
    >>(),
// Chamber Top
    StylePtr<InOutTr<Pulsing<Black,AudioFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,800>,TrWipe<300>,TrConcat<TrWipeIn<800>,Black,TrFade<300>>,Pulsing<Black,AudioFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,3000>
    >>(),
// Chamber Crystal
    StylePtr<Layers<
      AudioFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<300>,TrConcat<TrWipeIn<500>,Black,TrFade<300>>,Pulsing<RandomFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,Pulsing<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,60,100>>,800>>,Black,3000>>
    >>(),
// Accents
    StylePtr<Layers<Black,
      TransitionLoopL<TrConcat<TrWipe<200>,Pulsing<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,AudioFlickerL<ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,800>,TrWipeIn<200>>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<300>,TrConcat<TrWipeIn<2000>,Black,TrFade<100>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>
    >>(),
    "binary dark"
},


{ "aa_SyntheticEpiphany/The_Chain_Saber;common;commonBU", "", 
// Main Blade
    StylePtr<Layers<
      StyleFire<Stripes<2000,-3000,BrownNoiseFlicker<RotateColorsX<Variation,Black>,Black,20>,RotateColorsX<Variation,Red>,AudioFlicker<Black,Black>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,DarkOrange>,0,5,FireConfig<2,1200,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
      BC_effects_Red,
      TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Red>>,TrFade<1200>>,EFFECT_RETRACTION>,
      InOutTrL<TrWipeSparkTip<White,1200>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrSparkX<White,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
      TransitionEffectL<TrConcat<TrWipeX<Percentage<WavLen<>,5>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Red>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrDelayX<Percentage<WavLen<>,25>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,OrangeRed>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrWipeX<Percentage<WavLen<>,5>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,OrangeRed>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrDelayX<Percentage<WavLen<>,35>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DarkOrange>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrWipeX<Percentage<WavLen<>,5>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DarkOrange>,30>,SmoothStep<Int<6000>,Int<-500>>>,TrDelayX<Percentage<WavLen<>,30>>>,EFFECT_PREON>,
      // On-Demand Battery Level
      AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
// NPXL
    StylePtr<Layers<Black,
      AlphaL<Red,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<Black,AlphaL<Red,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>
    >>(),
// Chamber Top
    StylePtr<Layers<
      Pulsing<Black,Red,500>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Black,Red,3000>>
    >>(),
// Chamber Crystal
    StylePtr<Layers<
      StaticFire<Red,OrangeRed,0,2,0,1500,0>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Red,Sparkle<Black,White,7>,3000>>
    >>(),
// Accents
    StylePtr<Layers<
      Mix<Bump<Sin<Int<120>,Int<10>,Int<32000>>,Int<16000>>,Black,Red>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Mix<Bump<Sin<Int<40>,Int<10>,Int<32000>>,Int<10000>>,Black,Red>>
    >>(),
    "the chain\nsaber"
},


{ "aa_SyntheticEpiphany/Insurrection;common;commonBU", "", 
// Main Blade
    StylePtr<Layers<
      StyleFire<StripesX<Int<3000>,Scale<SlowNoise<Int<2000>>,Int<-1000>,Int<-5000>>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<4,0,8>>>,RotateColorsX<Variation,Rgb<115,15,220>>,RotateColorsX<Variation,Rgb<42,0,105>>>,RotateColorsX<Variation,Rgb<30,0,66>>,0,5,FireConfig<3,3000,0>,FireConfig<3,3000,0>,FireConfig<3,3000,0>,FireConfig<3,3000,0>>,
      AlphaL<Stripes<2500,-3000,Red,Rgb<60,0,0>,Pulsing<Rgb<30,0,0>,Black,800>>,SwingSpeed<600>>,
      BC_effects_Red,
      InOutTrL<TrWipeSparkTip<White,2200,300>,TrColorCycleX<WavLen<EFFECT_RETRACTION>,-100,-600>>,
      TransitionEffectL<TrConcat<TrDelay<1500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<3000>>>,TrFade<2000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<4000>>>,TrFade<2500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<5000>>>,TrBoing<1950,7>>,EFFECT_PREON>,
      TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<500>,Int<200>,Int<500>,Int<32768>>>,TrDelay<1500>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<300>,Int<300>,Int<32768>>>,TrDelay<2000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<100>,Int<400>,Int<100>,Int<32768>>>,TrDelay<3000>,AlphaL<RotateColorsX<Variation,Rgb<95,0,210>>,Bump<Int<0>,Int<6000>>>,TrBoing<1450,5>>,EFFECT_PREON>,
      // On-Demand Battery Level
      AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
// NPXL
    StylePtr<Layers<Black,
      AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,100>,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<Black,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,100>,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>
    >>(),
// Chamber Top
    StylePtr<Layers<
      Pulsing<Black,RotateColorsX<Variation,Rgb<95,0,210>>,500>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Black,RotateColorsX<Variation,Rgb<95,0,210>>,3000>>
    >>(),
// Chamber Crystal
    StylePtr<Layers<
      StaticFire<RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<95,0,210>>,0,2,0,1500,0>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<RotateColorsX<Variation,Rgb<95,0,210>>,Sparkle<Black,White,7>,3000>>
    >>(),
// Accents
    StylePtr<Layers<
      Mix<Bump<Sin<Int<120>,Int<10>,Int<32000>>,Int<16000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Mix<Bump<Sin<Int<40>,Int<10>,Int<32000>>,Int<10000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>>
    >>(),
    "insurrection"
},


{ "aa_SyntheticEpiphany/Balanced_Entropy;common;commonBU", "", 
// Main Blade
    StylePtr<Layers<
      StyleFire<Stripes<2500,-2000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,RotateColorsX<Variation,Red>,AudioFlicker<OrangeRed,DeepPink>,RotateColorsX<Variation,DeepPink>>,RotateColorsX<Variation,Red>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
      BC_effects_Red,
      InOutTrL<TrJoin<TrWipe<2000>,TrSparkX<White,Int<400>,Int<2000>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
      TransitionEffectL<TrConcat<TrWipeX<Percentage<WavLen<>,5>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Red>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrDelayX<Percentage<WavLen<>,25>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,OrangeRed>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrWipeX<Percentage<WavLen<>,5>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,OrangeRed>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrDelayX<Percentage<WavLen<>,35>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DarkOrange>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrWipeX<Percentage<WavLen<>,5>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DarkOrange>,30>,SmoothStep<Int<6000>,Int<-500>>>,TrDelayX<Percentage<WavLen<>,30>>>,EFFECT_PREON>,
      // On-Demand Battery Level
      AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
// NPXL
    StylePtr<Layers<Black,
      AlphaL<Red,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<Black,AlphaL<Red,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>
    >>(),
// Chamber Top
    StylePtr<Layers<
      Pulsing<Black,Red,500>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Black,Red,3000>>
    >>(),
// Chamber Crystal
    StylePtr<Layers<
      StaticFire<Red,OrangeRed,0,2,0,1500,0>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Red,Sparkle<Black,White,7>,3000>>
    >>(),
// Accents
    StylePtr<Layers<
      Mix<Bump<Sin<Int<120>,Int<10>,Int<32000>>,Int<16000>>,Black,Red>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Mix<Bump<Sin<Int<40>,Int<10>,Int<32000>>,Int<10000>>,Black,Red>>
    >>(),
    "balanced\nentropy"
},


{ "aa_SyntheticEpiphany/The_Ice_Saber;common;commonBU", "", 
// Main Blade
    StylePtr<Layers<
      Layers<
        AudioFlicker<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,60,200>>>,
        TransitionLoopL<TrWaveX<HumpFlickerL<RotateColorsX<Variation,Cyan>,40>,Int<250>,Int<100>,Int<200>,Int<0>>>,
        TransitionLoopL<TrWaveX<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,40>,Int<350>,Int<100>,Int<300>,Int<0>>>>,
      TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,25>>,AudioFlickerL<RotateColorsX<Variation,Rgb<90,180,255>>>,TrDelayX<Percentage<WavLen<>,50>>,AudioFlickerL<RotateColorsX<Variation,Rgb<90,180,255>>>,TrFadeX<Percentage<WavLen<>,25>>>,EFFECT_FORCE>,
      AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,DeepSkyBlue>,Black>,Black,RotateColorsX<Variation,DeepSkyBlue>,Black>,SwingSpeed<600>>,
      BC_effects_1,
      InOutTrL<TrWipeSparkTip<White,2100>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrSparkX<White,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Percentage<WavLen<EFFECT_PREON>,30>,Int<2000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,DeepSkyBlue>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,DeepSkyBlue>,Rgb<50,50,50>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Int<4000>,RotateColorsX<Variation,DeepSkyBlue>>>,White,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelayX<Percentage<WavLen<EFFECT_PREON>,60>>>,EFFECT_PREON>,
      // On-Demand Battery Level
      AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
// NPXL
    StylePtr<Layers<Black,
      AlphaL<AudioFlicker<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,60,200>>>,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<Black,AlphaL<AudioFlicker<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,60,200>>>,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>
    >>(),
// Chamber Top
    StylePtr<Layers<
      Pulsing<Black,AudioFlicker<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,60,200>>>,500>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Black,Rgb<0,40,128>,3000>>
    >>(),
// Chamber Crystal
    StylePtr<Layers<
      StaticFire<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,60,200>>,0,2,0,1500,0>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Rgb<0,40,128>,Sparkle<Black,White,7>,3000>>
    >>(),
// Accents
    StylePtr<Layers<
      Mix<Bump<Sin<Int<120>,Int<10>,Int<32000>>,Int<16000>>,Black,RotateColorsX<Variation,Rgb<0,40,128>>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Mix<Bump<Sin<Int<40>,Int<10>,Int<32000>>,Int<10000>>,Black,RotateColorsX<Variation,Rgb<0,40,128>>>>
    >>(),
    "the ice\nsaber"
},

{ "aa_SyntheticEpiphany/The_Magma_Saber;common;commonBU", "", 
// Main Blade
    StylePtr<Layers<
      StyleFire<Stripes<2500,-2000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,RotateColorsX<Variation,Red>,AudioFlicker<OrangeRed,DeepPink>,RotateColorsX<Variation,DeepPink>>,RotateColorsX<Variation,Red>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
      BC_effects_Red,
      InOutTrL<TrJoin<TrWipe<2000>,TrSparkX<White,Int<400>,Int<2000>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrSparkX<White,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
      TransitionEffectL<TrConcat<TrWipeX<Percentage<WavLen<>,5>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Red>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrDelayX<Percentage<WavLen<>,25>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,OrangeRed>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrWipeX<Percentage<WavLen<>,5>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,OrangeRed>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrDelayX<Percentage<WavLen<>,35>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DarkOrange>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrWipeX<Percentage<WavLen<>,5>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DarkOrange>,30>,SmoothStep<Int<6000>,Int<-500>>>,TrDelayX<Percentage<WavLen<>,30>>>,EFFECT_PREON>,
      // On-Demand Battery Level
      AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
// NPXL
    StylePtr<Layers<Black,
      AlphaL<Red,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<Black,AlphaL<Red,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>
    >>(),
// Chamber Top
    StylePtr<Layers<
      Pulsing<Black,Red,500>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Black,Red,3000>>
    >>(),
// Chamber Crystal
    StylePtr<Layers<
      StaticFire<Red,OrangeRed,0,2,0,1500,0>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Red,Sparkle<Black,White,7>,3000>>
    >>(),
// Accents
    StylePtr<Layers<
      Mix<Bump<Sin<Int<120>,Int<10>,Int<32000>>,Int<16000>>,Black,Red>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Mix<Bump<Sin<Int<40>,Int<10>,Int<32000>>,Int<10000>>,Black,Red>>
    >>(),
    "the magma\nsaber"
},

{ "aa_SyntheticEpiphany/The_Stone_Saber;common;commonBU", "", 
// Main Blade
  StylePtr<Layers<
    BC_12color_8effect_SS, // 96 possible blade combos in one style. Uses BC_SWAP.
    BC_effects_Red,
   InOutTrL< // accel in/out
     TrConcat<TrInstant,Layers<
      TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<1950>>,EFFECT_IGNITION>,
      AlphaL<AudioFlicker<
          ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
          ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,
        SmoothStep<Scale<Trigger<EFFECT_IGNITION,Scale<Trigger<EFFECT_IGNITION,Int<2000>,Int<1>,Int<1>>,Int<300>,Int<2000>>,Int<1>,Int<1>>,Int<-1200>,Int<35000>>,Int<-3000>>>>,TrDelay<5000>>,
     TrConcat<TrInstant,Layers<
     TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<2000>>,EFFECT_RETRACTION>,
     AlphaL<AudioFlicker<
        ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
        ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,
       SmoothStep<Scale<Trigger<EFFECT_RETRACTION,Scale<Trigger<EFFECT_RETRACTION,Int<1000>,Int<1000>,Int<1>>,Int<3000>,Int<10>>,Int<1000>,Int<500>>,Int<35000>,Int<-1200>>,Int<-3000>>>>,TrDelay<1000>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// NPXL
    StylePtr<Layers<Black,
    AlphaL<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<
        Black,
        AlphaL<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>
    >>(),
// Chamber Top
    StylePtr<InOutTr<Pulsing<Black,AudioFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,800>,TrWipe<300>,TrConcat<TrWipeIn<800>,Black,TrFade<300>>,Pulsing<Black,AudioFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,3000>
    >>(),
// Chamber Crystal
    StylePtr<Layers<
      AudioFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<300>,TrConcat<TrWipeIn<500>,Black,TrFade<300>>,Pulsing<RandomFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,Pulsing<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,60,100>>,800>>,Black,3000>>
    >>(),
// Accents
    StylePtr<Layers<Black,
      TransitionLoopL<TrConcat<TrWipe<200>,Pulsing<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,AudioFlickerL<ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,800>,TrWipeIn<200>>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<300>,TrConcat<TrWipeIn<2000>,Black,TrFade<100>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>
    >>(),
    "the stone\nsaber"
},

{ "aa_Blueforce/LiquidStatic;common;commonBU", "",
// Main Blade
 StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Blue,Mix<Int<2570>,Black,Blue>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Blue>,Black>>,Mix<Int<7710>,Black,Blue>,Pulsing<Mix<Int<6425>,Black,Blue>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Blue,Mix<Int<12000>,Black,Blue>>,2000>,Pulsing<Mix<Int<16448>,Black,Blue>,Mix<Int<642>,Black,Blue>,3000>>,
    AlphaL<StaticFire<Blue,Mix<Int<256>,Black,Blue>,0,1,10,2000,2>,Int<10000>>,
    AlphaL<LightCyan,SmoothStep<Int<2000>,Int<-6000>>>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<>>,TrInstant>,Stripes<3000,3500,Blue,RandomPerLEDFlicker<Mix<Int<7710>,Black,Blue>,Black>,BrownNoiseFlicker<Blue,Mix<Int<3855>,Black,Blue>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Blue>,Mix<Int<3855>,Black,Blue>>>,TrFade<800>>,EFFECT_RETRACTION>,
    BC_effects_1,
    InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTipX<Blue,Scale<IsLessThan<Int<2100>,Int<1>>,Int<2100>,WavLen<EFFECT_RETRACTION>>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// NPXL
    StylePtr<Layers<Black,
      AlphaL<AudioFlicker<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,60,200>>>,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<Black,AlphaL<AudioFlicker<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,60,200>>>,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>
    >>(),
// Chamber Top
    StylePtr<Layers<
      Pulsing<Black,AudioFlicker<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,60,200>>>,500>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Black,Rgb<0,40,128>,3000>>
    >>(),
// Chamber Crystal
    StylePtr<Layers<
      StaticFire<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,60,200>>,0,2,0,1500,0>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Pulsing<Rgb<0,40,128>,Sparkle<Black,White,7>,3000>>
    >>(),
// Accents
    StylePtr<Layers<
      Mix<Bump<Sin<Int<120>,Int<10>,Int<32000>>,Int<16000>>,Black,RotateColorsX<Variation,Rgb<0,40,128>>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrFade<300>,TrFade<500>,Mix<Bump<Sin<Int<40>,Int<10>,Int<32000>>,Int<10000>>,Black,RotateColorsX<Variation,Rgb<0,40,128>>>>
    >>(),
    "liquid\nstatic"
},

};

//----------------------------------------------------------------------------------------------------------------------------------------
Preset noblade[] = {

// // Try Sparkle<Red> as accents style

{ "a_STARKILLER/DarkAppr;common;commonBU", "tracks/TFU1.wav", 
// Main Blade
    StylePtr<Black>(),
// NPXL
    StylePtr<Layers<Black,
      AlphaL<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,CircularSectionF<Saw<Int<500>>,Int<16000>>>,
      InOutTrL<TrWipe<300>,TrWipe<500>,Layers<
        Black,
        AlphaL<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,CircularSectionF<Saw<Int<20>>,Int<16000>>>>>,
      // On-Demand Battery Level
      AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
// Chamber Top
    StylePtr<InOutTr<Pulsing<Black,AudioFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,800>,TrWipe<300>,TrConcat<TrWipeIn<800>,Black,TrFade<300>>,Pulsing<Black,AudioFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,3000>
    >>(),
// Chamber Crystal
    StylePtr<Layers<
      AudioFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<300>,TrConcat<TrWipeIn<500>,Black,TrFade<300>>,Pulsing<RandomFlicker<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,Pulsing<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,Rgb<30,0,30>,Rgb<60,60,100>>,800>>,Black,3000>>
    >>(),
// Accents
    StylePtr<Layers<Black,
      TransitionLoopL<TrConcat<TrWipe<200>,Pulsing<ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,AudioFlickerL<ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed,Rgb<90,65,0>,Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,DodgerBlue,Rgb<39,5,71>,Rgb<60,0,60>,Rgb<80,80,150>>>,800>,TrWipeIn<200>>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_BLAST>,
      LockupL<AudioFlicker<Pulsing<Black,Red,500>,White>,AudioFlicker<Pulsing<Black,Red,500>,White>,Int<32768>,Int<32768>,Int<32768>>,
      TransitionEffectL<TrConcat<TrInstant,White,TrFade<40>>,EFFECT_CLASH>,
      LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
      InOutTrL<TrWipe<300>,TrConcat<TrWipeIn<2000>,Black,TrFade<100>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,ColorChange<TrFade<300>,Red,DarkOrange,Rgb<180,130,0>,GreenYellow,Green,Aquamarine,Cyan,DeepSkyBlue,Blue,Rgb<95,0,225>,Magenta,White>,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>
    >>(),
  "dark\napprentice"
}   
  
};


BladeConfig blades[] = {

{ NO_BLADE, // blade=0 // D1_data_line = proffie_D1> NPXL ctrpin---> Open when no blade ....65518.96ohm
            //                                                  \--->33k>BP pin 
 
  WS281XBladePtr<0, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
  CONFIGARRAY(noblade),
"00_NO_BLADEsave", },

{ 32000,    // blade=1 // 1" BC_A       123 apa105    D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm---> Main blade strips
            //                                                                              \-->33k>BP pin (--->LED NEG when blade in....31859.89ish?
   
  WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
// CONFIGARRAY(bladeBC_A), 
// "bladeBC_Asave", }, 
  CONFIGARRAY(AllBlades), 
"01_AllBladessave", }, 

{ 18500,    // blade=2 // 1" Ciel_Tan_A 132           D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
            //                                                                                 \-->33k>BP pin (--->LED NEG when blade in....18433.79ish?
   
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
   CONFIGARRAY(AllBlades), 
"02_AllBladessave", }, 

{ 4500,     // blade=3 //   1" BC_B     131 5050s     D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
            //                                                                                 \-->33k>BP pin (--->LED NEG when blade in....4380.53ish?
   
  WS281XBladePtr<131, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
  CONFIGARRAY(AllBlades), 
"03_AllBladessave", }, 

{ 7800,     // blade=4 //   1" BC_C     123 APA105 10mm     D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
            //                                                                                 \-->33k>BP pin (--->LED NEG when blade in....XXXXXish?
   
  WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
// CONFIGARRAY(bladeBC_C),
// "bladeBC_Csave", }, 
   CONFIGARRAY(AllBlades), 
"04_AllBladessave", }, 



};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
