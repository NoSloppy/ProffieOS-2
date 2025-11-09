// BC_Scoundrel_7.x 

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
// #define LINE_OUT_VOLUME 2000                   // SPDIF out
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
#define FEMALE_TALKIE_VOICE                       // BC now canon
#define NO_REPEAT_RANDOM                          // BC now canon
#define KILL_OLD_PLAYERS                          // BC now canon
 #define DISABLE_TALKIE                           // I feel I'm not gonna like this

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet. Equivalent to just increasing maxLedsPerStrip.
#define EXTRA_COLOR_BUFFER_SPACE 30
// #define SHARED_POWER_PINS
// #define BLADE_DETECT_PIN blade3Pin
// #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9>         // TX pad
//    This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
//    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value, so I would recommend using something like 200000 instead of NO_BLADE.
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> 
//    Millis is Blade ID scan interval. If the blade ID comes out the same as before, it will do nothing.
//    If it comes out different, it will do FindBladeAgain(), which will basically initialize the saber from scratch and load the right settings for the new id().
//    It will only work with neopixel blades, and it probably requires SHARED_POWER_PINS to work.
// #define BLADE_ID_SCAN_MILLIS 1000
//    How many Blade ID scans to average
// #define BLADE_ID_TIMES 10

// ------ SD Card Stuff -------

#define ENABLE_SD
// #define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//    Upload overwrites presets.ini/tmp unless this is defined
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING      

// ------- OLED stuff ----------

// #define ENABLE_SSD1306                         // OLED display. also defines ENABLE_DISPLAY_CODE
// #define OLED_FLIP_180                          // BC now canon
// #define OLED_MIRRORED
// #define USE_AUREBESH_FONT                      // BC now canon
// #define PLI_OFF_TIME 60 * 5 * 1000
// #define OLED_USE_BLASTER_IMAGES
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144_SC_POV_data.h"
// #define POV_INCLUDE_FILE "Raiden_123_FC_POV_data.h"
// #define POV_INCLUDE_FILE "JohnCena_144_8b_POV_data.h"
//    Turns power to the OLED display off once SCREEN_OFF state. (Either IDLE_OFF_TIME or PLI_OFF_TIME)
// #define DISPLAY_POWER_PINS PowerPINS<bladePowerPin6> 

// ------ System Stuff --------

// #define ENABLE_DEBUG
// #define NO_BATTERY_MONITOR
// #define ENABLE_SERIAL // Bluetooth
// #define DISABLE_COLOR_CHANGE
 #define ENABLE_DEVELOPER_COMMANDS
//#define DISABLE_DIAGNOSTIC_COMMANDS
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
#define DISABLE_BASIC_PARSER_STYLES                 // Standard, Advanced, Old School original templated styles etc...

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3.5
// #define BC_SWING_ON                               // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
// #define BC_STAB_ON
#define BC_THRUST_ON
//#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second.
#define ENABLE_SPINS
#define ENABLE_AUTO_SPINS_BLAST                     // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
// #define NO_BLADE_NO_GEST_ONOFF                   // If using blade detect, No Blade = No Gesture ignitions or retractions

// ------- Custom / Experimental / Alpha-Beta stuff ---------

// #define AUTO_HUMSTART  ******  DEAD              // BC now canon as ProffieOSHumDelay in config.ini. BC likes 200ms delay from on.wav beginning all the time.
// #define LOW_BATT_ONCE                            // No repeated warnings
// #define ENABLE_GESTURE_MENU                      // PSISTORM prop - cool stuff! the TrySound else beep void.  

// -------- BC Prop Other Stuff --------

// #define NO_VOLUME_MENU                           // self evident. But why?

// -------- Blaster Stuff ----------

// #define ENABLE_BLASTER_AUTO
// #define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
// #define BLASTER_JAM_PERCENTAGE 10     // if not defined, random.
// #define DEFAULT_BLASTER_MODE MODE_KILL

#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h" // Lately, preferring #define NUM_BUTTONS 1
//#include "../scripts/motion_startup_recorder.h"
#endif

#ifdef CONFIG_PRESETS
// save mem by disabling unused aliases.
#include "aliases/TrueWhites/BC_effects_1.h"              // For Green, light Blue, ...light colored blades
#include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"  // EffectSequence driven different blast animations
// #include "aliases/TrueWhites/BC_effects_2.h"              // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"            // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_White.h"          // For White blades
// #include "aliases/TrueWhites/BC_12color_8effect_SS.h"     // All in one blade style from CC Fork. SS = SwingSpeed included 

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;


/*
1. a_SHIPS/FALCON
2. a_LEIA/Royalty
3. a_LUKE/LS6
4. a_KYLO/KyloUltimate
5. a_REY/ScavngrsDstny
6. a_AHSOKA/AhsokaUltimate
7. aa_Kyberphonic/ShockBaton
8. aa_Blueforce/IgnitionUltimate
9. GhostsOfTheGrey
10. aa_Greyscale/Apocalypse_Greyscale
11. aa_Greyscale/Behemoth_Greyscale
12. aa_Greyscale/Coda_Greyscale
13. aa_Greyscale/Endure_Greyscale
14. aa_Blueforce/DarkSpace
15. aa_JayDalorian/Decimate
16. aa_BK/MysticMaster
// 17. aa_JayDalorian/LightsaberOfTheBells
*/


Preset Scoundrel [] = {
// test slave 1 for error in font directory

    {"slave1", "",
 StylePtr<Layers<
  StyleFire<StripesX<Int<3000>,Scale<SlowNoise<Int<2000>>,Int<-1000>,Int<-5000>>,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,0,60>>,RotateColorsX<Variation,Rgb<0,0,10>>>,RotateColorsX<Variation,Rgb<25,25,255>>,RotateColorsX<Variation,Rgb<0,0,128>>>,RotateColorsX<Variation,Rgb<0,0,80>>,0,5,FireConfig<3,3000,0>,FireConfig<3,3000,0>,FireConfig<3,3000,0>,FireConfig<3,3000,0>>,
  AlphaL<Stripes<2500,-3000,Red,Rgb<60,0,0>,Pulsing<Rgb<30,0,0>,Black,800>>,SwingSpeed<600>>,
  BC_effects_1,
  InOutTrL<TrWipeSparkTip<White,1200>,TrWipeInSparkTip<White,1063>>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrDelay<1500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Blue>,30>,Bump<Int<0>,Int<3000>>>,TrFade<500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Blue>,30>,Bump<Int<0>,Int<4000>>>,TrFade<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Blue>,30>,Bump<Int<0>,Int<5000>>>,TrBoing<1950,7>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Blue>,Int<500>,Int<200>,Int<500>,Int<40>>>,TrDelay<1000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Blue>,Int<300>,Int<300>,Int<300>,Int<40>>>,TrDelay<1300>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Blue>,Int<100>,Int<400>,Int<100>,Int<32768>>>,TrDelay<2000>,AlphaL<RotateColorsX<Variation,Blue>,Bump<Int<0>,Int<6000>>>,TrBoing<1450,5>>,EFFECT_PREON>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  "slave1"},


//   { "aa_MeatySmurf/domo;common;commonBU", "tracks/mars.wav",
// /* copyright Fett263 CustomBlade (Primary Blade) OS6 Style
// https://fett263.com/fett263-proffieOS6-style-library.html#CustomBlade
// OS6.7 v4.011
// Single Style
// Interactive Impact Instability
// Default: Kylo Ren Unstable (Supreme Leader)
// 1: Power Wave High

// Base Color: Rgb<255,0,0> (0)
// Each Blast, Clash or Lockup with apply Style 2 (Instability) in increasing levels based on strength of the clash, allowing time to pass between impacts allows the blade to re-stabilize. (approx 5 seconds)

// --Effects Included--
// Preon Effect: Pulsing (PreOn Color)
// Ignition Effect: SparkTip Ignition
// PowerUp Effect: Power Surge (Stable)
// Retraction Effect: Standard Retraction
// CoolDown Effect: Unstable Cool Down Reverse
// Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb
// LightningBlock Effect: Responsive Lightning Block
// Drag Effect: Intensity Sparking Drag
// Melt Effect: Intensity Melt
// Blast Effect: Blast Wave (Random)
// Clash Effect: Random Clash
// Swing Effect: Interactive Ice Blade (Force Effect)
// Emitter Effect: Unstable Flare

// Swing Option 0- Interactive Ice Blade (Force Effect) Interactive Control: Force to freeze blade, clashes will break ice.
// */
//   StylePtr<Layers<
//     Mix<HoldPeakF<IncrementWithReset<Sum<EffectPulseF<EFFECT_BLAST>,EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_LOCKUP_BEGIN>>,ThresholdPulseF<IncrementWithReset<ThresholdPulseF<BlinkingF<Int<1000>,Int<500>>,Int<32000>>,Sum<EffectPulseF<EFFECT_BLAST>,EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_LOCKUP_BEGIN>>,Int<32768>,Int<8000>>,Int<32000>>,Int<32768>,Scale<ClashImpactF<>,Int<2000>,Int<8000>>>,Int<2000>,Int<10000>>,StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RgbArg<BASE_COLOR_ARG,Blue>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,RgbArg<BASE_COLOR_ARG,Blue>,Mix<Int<2570>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,RgbArg<BASE_COLOR_ARG,Blue>>,Stripes<12000,-1800,RgbArg<ALT_COLOR_ARG,Rgb<30,60,200>>,Mix<Int<6000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<30,60,200>>>,RgbArg<ALT_COLOR_ARG,Rgb<30,60,200>>,Mix<Int<14000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<30,60,200>>>>>,
//     AlphaL<RandomPerLEDFlickerL<RgbArg<EMITTER_COLOR_ARG,Magenta>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<6000>>>,Int<-6000>>>,
//     ColorSelect<IncrementWithReset<EffectPulseF<EFFECT_FORCE>,ThresholdPulseF<IncrementWithReset<Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_STAB>>,EffectPulseF<EFFECT_FORCE>,Int<32768>,Scale<ClashImpactF<>,Int<3000>,Int<14000>>>,Int<32600>>,Int<1>>,TrSmoothFadeX<Int<2000>>,AlphaL<RgbArg<BASE_COLOR_ARG,Red>,Int<0>>,RgbArg<BASE_COLOR_ARG,Red>>,
//     ColorSelect<IncrementWithReset<EffectPulseF<EFFECT_FORCE>,ThresholdPulseF<IncrementWithReset<Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_STAB>>,EffectPulseF<EFFECT_FORCE>,Int<32768>,Scale<ClashImpactF<>,Int<3000>,Int<14000>>>,Int<32600>>,Int<1>>,TrSelect<IncrementWithReset<EffectPulseF<EFFECT_FORCE>,Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_STAB>>,Int<1>>,TrSmoothFadeX<Int<3000>>,TrWipeSparkTipX<BrownNoiseFlicker<RgbArg<SWING_COLOR_ARG,Rgb<100,100,150>>,White,200>,WavLen<EFFECT_FORCE>>>,AlphaL<RgbArg<BASE_COLOR_ARG,Red>,Int<0>>,AlphaL<Stripes<22000,-20,RgbArg<SWING_COLOR_ARG,Rgb<100,100,150>>,Mix<Int<18000>,Black,RgbArg<SWING_COLOR_ARG,Rgb<100,100,150>>>>,SmoothStep<Sum<Int<33000>,IncrementWithReset<Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_STAB>>,EffectPulseF<EFFECT_FORCE>,Int<33000>,Scale<Scale<ClashImpactF<>,Int<3000>,Int<14000>>,Int<-3000>,Int<-14000>>>>,Int<-1>>>>,
//     TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Magenta>>,TrFade<1200>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<>>,TrInstant>,Stripes<3000,3500,RgbArg<RETRACTION_COLOR_ARG,Magenta>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Magenta>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Magenta>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Magenta>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Magenta>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Magenta>>>>,TrFade<800>>,EFFECT_RETRACTION>,
//     MultiTransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Yellow>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<EffectRandomF<EFFECT_CLASH>,Scale<ClashImpactF<>,Int<9000>,Int<12000>>>,RgbArg<CLASH_COLOR_ARG,Orange>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Orange>>>,TrFade<300>>,EFFECT_CLASH>,
//     LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,DarkOrange>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,DarkOrange>>,RgbArg<LOCKUP_COLOR_ARG,DarkOrange>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,DarkOrange>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,DarkOrange>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,DarkOrange>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,DarkOrange>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,DarkOrange>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,DarkOrange>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
//     ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,White>,Int<16000>>,30>,TrSmoothFade<600>>>,
//     LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,White>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
//     LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Magenta>,IgnitionTime<>>,TrWipeInX<RetractionTime<>>>,
//     TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<PREON_COLOR_ARG,Orange>,Int<800>>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>,
//   // BC Postoff
//     TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrSparkX<RandomPerLEDFlickerL<RgbArg<EMITTER_COLOR_ARG,Magenta>>,Int<200>,Int<423>,Int<32768>>>,TrSmoothFadeX<WavLen<>>>,EFFECT_POSTOFF>,
//   // Volume Level - gradient Blue -> Green
//     OnDemandVolumeLevel,
//   // On-Demand Battery Level
//     OnDemandBatteryLevel
//   >>(),
// "domo"},

{ "testfont2b;common;commonBU", "",
// demo style
StylePtr<Layers<Black,
TransitionEffectL<
TrConcat<TrDelay<2000>,
Red,TrExtend<1000,TrDoEffect<TrInstant,EFFECT_CLASH>>,
Red,TrExtend<400,TrDoEffect<TrInstant,EFFECT_CLASH>>,
Red,TrExtend<1000,TrDoEffect<TrInstant,EFFECT_CLASH>>,
Red,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_CLASH>>,

Orange,TrExtend<300,TrDoEffect<TrInstant,EFFECT_BLAST>>,
Orange,TrExtend<500,TrDoEffect<TrInstant,EFFECT_BLAST>>,
Orange,TrExtend<1000,TrDoEffect<TrInstant,EFFECT_BLAST>>,
Orange,TrExtend<200,TrDoEffect<TrInstant,EFFECT_BLAST>>,


Yellow,TrExtend<1200,TrDoEffect<TrInstant,EFFECT_STAB>>,
Yellow,TrExtend<1200,TrDoEffect<TrInstant,EFFECT_STAB>>,
Yellow,TrExtend<1200,TrDoEffect<TrInstant,EFFECT_STAB>>,

Green,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_FORCE>>,
Green,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_FORCE>>,

Blue,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_QUOTE>>,
Blue,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_QUOTE>>,

Rgb<0,200,200>,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_LOCKUP_BEGIN>>,
Rgb<0,200,200>,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_LOCKUP_END>>,
Rgb<0,200,200>,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_LOCKUP_BEGIN>>,
Rgb<0,200,200>,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_LOCKUP_END>>,

GreenYellow,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_DRAG_BEGIN>>,
GreenYellow,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_DRAG_END>>,
GreenYellow,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_ERROR_IN_FONT_DIRECTORY>>,

GreenYellow,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_VOLUME_LEVEL>>,



Magenta,TrExtend<3000,TrDoEffect<TrInstant,EFFECT_RETRACTION>>,
GreenYellow,TrExtend<2000,TrDoEffect<TrInstant,EFFECT_BATTERY_LEVEL>>>,
EFFECT_IGNITION>,
BC_effects_Red,
InOutTrL<TrWipe<400>,TrWipeInX<BendTimePowX<WavLen<>,Int<180000>>>>>>(),

//   StylePtr<Layers<EffectSequence<EFFECT_USER1,Black,Green>,
//   BC_effects_1,
// TransitionEffectL<TrConcat<TrInstant,Rainbow,TrFade<2000>>,EFFECT_QUOTE>,
// InOutTrL<TrWipeX<BendTimePowInvX<Int<1000>,Int<180000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>, 
// TransitionEffectL<TrConcat<TrInstant,Strobe<Black,White,15,81>,TrCenterWipeInSpark<White,5000>>,EFFECT_FAST_ON>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb<100,200,255>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
// // Volume Level - stepped blue "stripes"
//   TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,
// AlphaL<Layers<
//   AlphaL<Blue,LinearSectionF<Int<1638>,Int<3276>>>,
//   AlphaL<SteelBlue,LinearSectionF<Int<4914>,Int<3276>>>,
//   AlphaL<Blue,LinearSectionF<Int<8190>,Int<3276>>>,
//   AlphaL<SteelBlue,LinearSectionF<Int<11466>,Int<3276>>>,
//   AlphaL<Blue,LinearSectionF<Int<14742>,Int<3276>>>,
//   AlphaL<SteelBlue,LinearSectionF<Int<18018>,Int<3276>>>,
//   AlphaL<Blue,LinearSectionF<Int<21294>,Int<3276>>>,
//   AlphaL<SteelBlue,LinearSectionF<Int<24570>,Int<3276>>>,
//   AlphaL<Blue,LinearSectionF<Int<27846>,Int<3276>>>,
//   AlphaL<SteelBlue,LinearSectionF<Int<31122>,Int<3276>>>>,
// SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>,
  // // Volume Level - gradient Blue -> Green
  //   OnDemandVolumeLevel,
  // // On-Demand Battery Level
  //   OnDemandBatteryLevel
  // >>(),
"testfont2b"},


// { "Pman;common", "Pman/tracks/pman.wav",
// StylePtr<Layers<Black,
//   Layers<
//    TransitionLoopL<TrConcat<TrDelay<3000>,Stripes<200,1,Black,Black,Black,Black,White>,TrWipeSparkTipX<Blinking<Yellow,Rgb<128,128,0>,300,500>,Int<3000>,Int<300>>>>,
//   TransitionLoopL<TrConcat<TrInstant,Stripes<200,1,Black,Black,Black,Black,White>,TrWipeInSparkTipX<Blinking<Yellow,Rgb<128,128,0>,300,500>,Int<3000>,Int<300>>,AlphaL<Black,Int<0>>,TrDelay<3000>>>>,
//   TransitionEffectL<TrConcat<TrCenterWipeSpark<Yellow,200>,Pulsing<Yellow,Black,800>,TrFade<150>>,EFFECT_IGNITION>,
//   TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<>>,TrInstant>,Remap<CenterDistF<>,Stripes<5000,-2500,RgbArg<RETRACTION_COLOR_ARG,Yellow>,Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Yellow>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Yellow>>>>,TrFade<800>>,EFFECT_RETRACTION>,
//   TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Red>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
//   MultiTransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<BLAST_COLOR_ARG,Yellow>,TrFade<300>>,EFFECT_BLAST>,
//   TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Blue>,TrFade<300>>,EFFECT_CLASH>,
//   LockupTrL<Layers<
//     Black,
//     TransitionLoopL<TrConcat<TrJoin<TrConcat<TrDelay<1200>,AlphaL<Black,Int<0>>,TrSparkX<Blinking<Yellow,Rgb<128,128,0>,300,500>,Int<300>,Int<3000>,Int<32768>>>,TrSparkX<Blue,Int<350>,Int<2500>,Int<18000>>,TrSparkX<Blue,Int<350>,Int<2800>,Int<32768>>,TrSparkX<Blue,Int<350>,Int<3500>,Int<32768>>>,Black,TrJoin<TrConcat<TrDelay<1200>,AlphaL<Black,Int<0>>,TrSparkX<Blinking<Yellow,Rgb<128,128,0>,300,500>,Int<300>,Int<3000>,Int<0>>>,TrSparkX<Blue,Int<350>,Int<2500>,Int<0>>,TrSparkX<Blue,Int<350>,Int<2800>,Int<0>>,TrSparkX<Blue,Int<350>,Int<3500>,Int<0>>>>>>,TrFade<100>,TrFade<100>,SaberBase::LOCKUP_NORMAL>,
//   ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,White>,Int<16000>>,30>,TrSmoothFade<600>>>,
//   LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,White>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
//   LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
//   InOutTrL<TrCenterWipeSpark<Yellow,523>,TrCenterWipeSpark<Yellow,777>>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Blinking<Yellow,Rgb<128,128,0>,300,500>,Bump<Int<16384>,Int<6000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrCenterWipeX<Int<200>>,AlphaL<AudioFlicker<RotateColorsX<Int<200>,RgbArg<BASE_COLOR_ARG,Yellow>>,RotateColorsX<Int<600>,RgbArg<BASE_COLOR_ARG,Yellow>>>,Bump<Int<16384>,Scale<NoisySoundLevel,Int<14000>,Int<20000>>>>,TrJoin<TrDelayX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<16384>>>,TrCenterWipeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8000>>>>,Layers<
//     AlphaL<AudioFlicker<RotateColorsX<Int<200>,RgbArg<BASE_COLOR_ARG,Yellow>>,RotateColorsX<Int<600>,RgbArg<BASE_COLOR_ARG,Yellow>>>,Bump<Int<16384>,Scale<NoisySoundLevel,Int<14000>,Int<20000>>>>,
//     AlphaL<Black,LinearSectionF<Int<16384>,Scale<NoisySoundLevel,Int<4000>,Int<8000>>>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10000>>>>,EFFECT_POSTOFF>
//     >>(),
//        "pac attack"},

// { "aa_JayDalorian/Kyber_Dark;common;commonBU", "",
// // StylePtr<Layers<
 
// //     Magenta,
    
// //   InOutTrL<TrInstant,TrWipeIn<500>>,
// // AlphaL<Black,HumpFlickerFX<Scale<Trigger<EFFECT_IGNITION,Int<2000>,Int<1000>,Int<500>>,Int<1>,Int<40>>>>>>(),"testHumpFlickerFX"},


   
// StylePtr<Layers< // 3 selectable preons and force using WavNum
//   StripesX<Int<3500>,Int<1600>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<75,0,165>>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<10,0,26>>,RotateColorsX<Variation,Rgb<42,0,105>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Rgb<115,15,220>>,RotateColorsX<Variation,Rgb<95,0,210>>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<7,0,16>>,RotateColorsX<Variation,Rgb<30,0,66>>>>,
//   AlphaL<Stripes<10000,-2000,HumpFlicker<Rgb<0,0,40>,Rgb<20,30,0>,50>,HumpFlicker<Blue,NavajoWhite,50>,HumpFlicker<Rgb<0,0,80>,Rgb<40,60,0>,50>>,SwingSpeed<600>>,
//   // Force effect powerup - WavLen duration sync.
//   ColorSelect<WavNum<EFFECT_FORCE>,TrInstant,
//     TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,StaticFire<Red,Strobe<Black,Orange,30,30>,0,3,300>,TrDelayX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Red,Strobe<Black,Orange,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,StaticFire<Blue,Strobe<Black,Cyan,30,30>,0,3,300>,TrDelayX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Blue,Strobe<Black,Cyan,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,StaticFire<Green,Strobe<Black,GreenYellow,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Green,Strobe<Black,GreenYellow,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>>,
//   // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//     AlphaL<Black,Int<16384>>,
//     AlphaL<Black,Int<0>>>,
//   // Clash - Flash at impact. WavLen duration sync. Now Clash impact sensitive.
// TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFadeX<Percentage<WavLen<>,35>>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,
//   Scale<ClashImpactF<>,Int<1>,Int<32768>>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_CLASH>,
//    // Stab - OrangeRed stripes. WavLen duration sync.
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,30>>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFadeX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeX<Percentage<WavLen<EFFECT_STAB>,70>>>>,EFFECT_STAB>,
//   // Blast v1
//     TransitionEffectL<TrConcat<
//         // Impact Flash - BC always
//         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//         // Waves
//         BlastL<Rgb<100,200,255>,850,250,351>,
//         // Impact point afterimage
//         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         // Impact point
//         BlastL<Rgb<100,200,255>,300,350,100000>,
//   // Lockup - BC custom range mid-blade
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//       //Random Strobe Flash no dimming
//       AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//       // Bottom Layer Bump - random width
//       AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//       // Top Layer Bump - fixed width
//       AlphaL<BrownNoiseFlicker<Yellow,Black,50>,                                                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//       // Begin Lockup Transition
//       TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>, Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//       // End Lockup Transition
//       TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//       TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                             Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
//   // Non-Responsive Drag
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block Non-Responsive    
//     LockupTrL<Layers<
//         //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
//         AlphaL<Black,Int<16000>>,
//         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<
//         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//         // Begin Lightning Transition
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
//         // End Lightning Transition    
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//         // OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
//         AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
//         // Melt Shape
//         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
//         // Melt Begin and End transitions
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
//   TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<800>>,EFFECT_IGNITION>,
//   TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,

//   InOutTrL<TrWipeSparkTipX<White,BendTimePowInvX<Int<1000>,Int<180000>>>,TrWipeInSparkTipX<White,BendTimePowX<Int<600>,Int<180000>>>>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<1287>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<643>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<643>>,EFFECT_RETRACTION>,
// ColorSelect<WavNum<EFFECT_PREON>,TrInstant,
// TransitionEffectL<TrConcat<TrInstant,AlphaL<AlphaL<Mix<Scale<Trigger<EFFECT_PREON,Int<1983>,Int<1>,Int<1>>,Int<0>,Int<30000>>,HumpFlicker<White,Black,20>,HumpFlicker<White,Black,100>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,100>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Strobe<Black,White,15,50>,500>>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<1983>,Int<1>,Int<1>>,Int<2000>,Int<16000>>,Int<-500>>>,Scale<Trigger<EFFECT_PREON,Int<1983>,Int<1>,Int<1>>,Int<2000>,Int<32768>>>,TrDelayX<Int<1983>>,AlphaL<BrownNoiseFlicker<White,Black,500>,SmoothStep<Int<16000>,Int<-500>>>,TrWipeInSparkTipX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<350>,Int<90>>,White,TrWipeIn<150>,Black,TrInstant,AlphaL<HumpFlicker<White,Black,50>,SmoothStep<Int<2000>,Int<-500>>>,TrDelay<450>,AlphaL<HumpFlicker<White,Black,50>,SmoothStep<Int<8000>,Int<-500>>>,TrFade<200>,Black,TrDelay<128>,AlphaL<HumpFlicker<White,Black,50>,SmoothStep<Int<6000>,Int<-500>>>,TrFade<200>,Black,TrDelay<373>,AlphaL<HumpFlicker<White,Black,50>,SmoothStep<Int<1500>,Int<-500>>>,TrFade<222>,AlphaL<HumpFlicker<White,Black,50>,SmoothStep<Int<1500>,Int<-500>>>,TrFade<222>,Black,TrDelay<733>>,EFFECT_PREON>,
// AlphaL<TransitionEffectL<TrConcat<TrFade<300>,HumpFlicker<White,RotateColorsX<Variation,Rgb<95,0,210>>,10>,TrDelay<500>,HumpFlicker<White,RotateColorsX<Variation,Rgb<95,0,210>>,10>,TrFade<984>,HumpFlicker<White,Black,200>,TrWipeIn<150>>,EFFECT_PREON>,Scale<Trigger<EFFECT_PREON,Int<1450>,Int<484>,Int<1>>,Int<6000>,Int<32768>>>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<AlphaL<Mix<Scale<Trigger<EFFECT_PREON,Int<13989>,Int<1>,Int<1>>,Int<0>,Int<30000>>,HumpFlicker<White,Black,20>,HumpFlicker<White,Black,100>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,100>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Strobe<Black,White,15,50>,500>>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<13989>,Int<1>,Int<1>>,Int<2000>,Int<16000>>,Int<-500>>>,Scale<Trigger<EFFECT_PREON,Int<13989>,Int<1>,Int<1>>,Int<2000>,Int<32768>>>,TrDelayX<Int<13989>>,AlphaL<BrownNoiseFlicker<White,Black,500>,SmoothStep<Int<16000>,Int<-500>>>,TrWipeInSparkTipX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<350>,Int<90>>,White,TrWipeIn<150>,Black,TrInstant,AlphaL<HumpFlicker<White,Black,50>,SmoothStep<Int<2000>,Int<-500>>>,TrDelay<450>,AlphaL<HumpFlicker<White,Black,50>,SmoothStep<Int<8000>,Int<-500>>>,TrFade<200>,Black,TrDelay<128>,AlphaL<HumpFlicker<White,Black,50>,SmoothStep<Int<6000>,Int<-500>>>,TrFade<200>,Black,TrDelay<373>,AlphaL<HumpFlicker<White,Black,50>,SmoothStep<Int<1500>,Int<-500>>>,TrFade<222>,AlphaL<HumpFlicker<White,Black,50>,SmoothStep<Int<1500>,Int<-500>>>,TrFade<222>,Black,TrDelay<733>>,EFFECT_PREON>>,
//   TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>,
//   AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// >>(),
// "kyber\ndark"},




//   { "aa_Kyberphonic/Praetorian_Elite/Vibro-arbir_blade;aa_Kyberphonic/Praetorian_Elite;common;commonBU", "aa_Kyberphonic/Praetorian_Elite/tracks/A_New_Alliance_1.wav",
// //Second Sister Base Red
//   StylePtr<Layers<
//     Mix<SwingSpeed<300>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
//     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
//     InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // Volume Level - gradient Blue -> Green
//     OnDemandVolumeLevel,
//   // On-Demand Battery Level
//     OnDemandBatteryLevel
//   >>(),
// "vibro-arbir"},

//  { "aa_Kyberphonic/Praetorian_Elite/Bilari_electro-chain_whip;aa_Kyberphonic/Praetorian_Elite;common;commonBU", "aa_Kyberphonic/Praetorian_Elite/tracks/A_New_Alliance_1.wav",

// StylePtr<Layers<
//   Stripes<1000,-100,Stripes<100,2000,Red,Black,RandomPerLEDFlicker<Mix<Int<10280>,Black,Red>,Mix<Int<3855>,Black,Red>>>,Stripes<200,-3000,Red,RandomPerLEDFlicker<Mix<Int<7710>,Black,Red>,Black>,RandomPerLEDFlicker<Mix<Int<10280>,Black,Red>,Mix<Int<3855>,Black,Red>>>>,
//   Mix<LayerFunctions<LinearSectionF<Int<4000>,Int<1000>>,LinearSectionF<Int<9000>,Int<1000>>,LinearSectionF<Int<14000>,Int<1000>>,LinearSectionF<Int<19000>,Int<1000>>,LinearSectionF<Int<24000>,Int<1000>>,LinearSectionF<Int<29000>,Int<1000>>,LinearSectionF<Int<34000>,Int<1000>>>,Black,
//   Layers<BC_effects_Red,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrInstant,TrConcat<TrFadeX<RetractionTime<>>,HumpFlickerL<White,50>,TrInstant>>>>,
//   // Volume Level - gradient Blue -> Green
//     OnDemandVolumeLevel,
//   // On-Demand Battery Level
//     OnDemandBatteryLevel
//   >>(),
// "bilari"},

// { "aa_JayDalorian/Blastermode;common;commonBU", "",
// // no effects because... blaster. But....... make toggle to stun and use stun sounds instead using alt sounds? WAITING ON FERNANDO TO GET UP TO EXPLAINING. NM Thanks Fredrik.
// StylePtr<Layers<Black,
//   ColorSelect<AltF,TrInstant,
//     MultiTransitionEffectL<TrConcat<TrWipe<150>,Red,TrWipe<100>>,EFFECT_BLAST>,
//     MultiTransitionEffectL<TrConcat<TrWipe<200>,Stripes<1000,-2000,Cyan,Blue>,TrWipe<100>>,EFFECT_BLAST>>,

// // simplified by only changing the transitions with Altf using TrSelect<>
//     MultiTransitionEffectL<TrSelect<AltF,
//                             TrConcat<TrWipe<150>,Red,TrWipe<100>>,
//                             TrConcat<TrWipe<200>,Stripes<1000,-2000,Cyan,Blue>,TrWipe<100>>>,
//     EFFECT_BLAST>,

//   TransitionEffectL<TrDoEffectX<TrInstant, EFFECT_ALT_SOUND, EffectIncrementF<EFFECT_FORCE, Int<2>, Int<1>>>, EFFECT_FORCE>,
//   AlphaL<Pulsing<Black,ColorSelect<AltF,TrInstant,Red,Cyan>,3000>,Bump<Int<0>,Int<1000>>>,
// // Muzzle flash
//   MultiTransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlickerL<White>,SmoothStep<Int<6000>,Int<-4000>>>,TrFade<100>,AlphaL<ColorSelect<AltF,TrInstant,AudioFlicker<Red,Rgb<100,0,0>>,AudioFlicker<Cyan,Rgb<0,0,100>>>,SmoothStep<Int<3000>,Int<-4000>>>,TrFade<350>>,EFFECT_BLAST>,
// // Clash
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<NavajoWhite,Black>,Bump<Int<0>,Int<12000>>>,TrFadeX<WavLen<>>>,EFFECT_CLASH>,
// // Lockup scanner
//   LockupTrL<Cylon<DodgerBlue,5,1,DodgerBlue,20,175,1>,TrConcat<TrFade<330>,LightCyan,TrFade<330>,AlphaL<RandomBlink<14000>,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>>>,TrDelay<900>,AlphaL<Black,Int<0>>,TrWipe<170>,White,TrWipe<170>,DodgerBlue,TrBoing<500,3>>,TrWipeSparkTip<White,250,40>,SaberBase::LOCKUP_NORMAL>,
// // Melt
//   LockupTrL<StyleFire<Black,Cyan,0,4,FireConfig<3000,3000,1>,FireConfig<2200,0,0>,FireConfig<10,2000,0>,FireConfig<0,0,5>>,TrWipeSparkTipX<Red,Int<250>,Int<2000>>,TrFade<300>,SaberBase::LOCKUP_MELT>,
// // Stab
//   TransitionEffectL<TrConcat<TrWipeIn<50>,LightCyan,TrWipeIn<50>,AlphaL<AudioFlicker<NavajoWhite,Black>,Bump<Int<0>,Int<12000>>>,TrFadeX<WavLen<>>>,EFFECT_STAB>,
//   InOutTrL<TrFade<1000>,TrWipeInSparkTip<White,300>>,
// // Preon muzzle warmup
//   TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<>,33>>,AlphaL<HumpFlickerL<Blue,10>,Bump<Int<0>,Int<4000>>>,TrFadeX<Percentage<WavLen<>,33>>,AlphaL<HumpFlickerL<Red,15>,Bump<Int<0>,Int<5000>>>,TrFadeX<Percentage<WavLen<>,20>>,AlphaL<HumpFlickerL<White,20>,Bump<Int<0>,Int<6000>>>,TrBoingX<Percentage<WavLen<>,14>,3>>,EFFECT_PREON>,
//   // Volume Level - gradient Blue -> Green
//     OnDemandVolumeLevel,
//   // On-Demand Battery Level
//     OnDemandBatteryLevel
//   >>(),
// "blastermode"},



// { "aa_NoSloppy/Crushed;common;commonBU", "",
// // NoSloppy 06/2022
// StylePtr<Layers<
//   BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//   Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>,
//   AlphaL<StaticFire<Black,BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,600>,0,4,2,4000,0>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<500>,Int<-19300>,Int<32768>>,Int<0>>>,
//   BC_effects_Red,
//   // Ignition and Retraction effect
//   InOutTrL<TrJoin<TrWipeX<BendTimePowX<Int<1300>,Int<16384>>>,TrSparkX<White,Int<400>,BendTimePowX<Int<1300>,Int<16384>>,Int<0>>>,
//                   TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<150000>>>>,
//   // Postoff Emitter Cooldown
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb16<22863,5695,53231>,Bump<Int<0>,Int<3500>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Rgb<100,0,0>,Bump<Int<0>,Int<1000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
//   // Preon effects - auto matched to which wav file is chosen
//  AlphaL<ColorSelect<WavNum<EFFECT_PREON>,TrInstant,
//   Layers<
//     TransitionEffectL<TrConcat<TrDelay<200>,AlphaL<Black,Int<0>>,TrFade<1300>,Layers<
//     StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<180,0,0>>,RotateColorsX<Variation,Rgb<15,0,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>>,RotateColorsX<Variation,Rgb<40,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<36,0,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<180,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<90,0,0>>,RotateColorsX<Variation,Rgb<5,2,0>>,3000>>,
//     AlphaL<StyleFire<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<2,1,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>>,TrDelay<1000>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrFade<1500>,SparkleL<ColorSelect<Sin<Int<1>,Int<68>>,TrFade<300>,Red,Rgb16<22863,5695,53231>,White>,200,500>,TrDelay<1000>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<Black,Int<0>>,TrFade<800>,AlphaL<StaticFire<Black,Rgb16<22863,5695,53231>,0,3,0,6000>,Bump<Int<0>,Int<5000>>>,TrInstant,AlphaL<AlphaL<White,NoisySoundLevelCompat>,Bump<Int<0>,Int<25000>>>,TrDelay<700>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<Black,Int<0>>,TrFade<700>,AlphaL<StaticFire<Black,Rgb16<22863,5695,53231>,0,3,0,3000>,Int<16000>>,TrDelay<700>>,EFFECT_PREON>>,
//   Layers<
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Layers<
//     BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//     Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<5000>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
//     BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//     Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<9830>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
//     BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//     Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<14745>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
//     BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//     Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<19660>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
//     BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//     Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<24576>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
//     BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//     Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<29491>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
//     BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
//     Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<32768>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>>,EFFECT_PREON>>>,Ifon<Int<0>,Int<32768>>>,
// // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//     >>(),
// "crushed"},

// { "aa_NoSloppy/PoliceSirenV1;common;commonBU", "",
// //  A quick police car blade style for ProffieOS 6.x and up.
// //  Use with PoliceSirenV1 sound font :)
// //  NoSloppy - 2022

//   StylePtr<Layers<
//     Black,
//     AlphaL<Blue,LinearSectionF<Int<1>,Sin<Int<200>,Int<5000>,Int<1>>>>,
//     AlphaL<White,LinearSectionF<Int<32767>,Sin<Int<200>,Int<5000>,Int<1>>>>,
//     AlphaL<AlphaL<White,LinearSectionF<Sin<Int<30>,Int<16238>,Int<1>>,Sin<Int<200>,Int<8000>,Int<10>>>>,Int<16000>>,
//     AlphaL<Blue,LinearSectionF<Sin<Int<40>,Int<32768>,Int<16328>>,Sin<Int<200>,Int<8000>,Int<1>>>>,

//     AlphaL<Red,LinearSectionF<Sin<Int<100>>,Int<11000>>>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Blue,100,500>,TrDelayX<Percentage<WavLen<EFFECT_BLAST>,50>>>,EFFECT_BLAST>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<Yellow,Blue,100,500>,TrDelayX<WavLen<EFFECT_CLASH>>>,EFFECT_CLASH>,
//     LockupL<ColorSequence<100,Red,White,Blue>,ColorSequence<100,Red,White,Blue>,Int<32768>,Int<32768>,Int<32768>>,
//     InOutTrL<TrJoin<TrCenterWipeX<WavLen<EFFECT_IGNITION>>,TrWaveX<ColorSequence<100,Red,White,Blue>,Sum<WavLen<EFFECT_IGNITION>,WavLen<EFFECT_IGNITION>,WavLen<EFFECT_IGNITION>,WavLen<EFFECT_IGNITION>>,Int<200>,Sum<WavLen<EFFECT_IGNITION>,WavLen<EFFECT_IGNITION>>>>,TrJoin<TrCenterWipeInX<WavLen<EFFECT_RETRACTION>>,TrJoin<TrWaveX<ColorSequence<100,Red,White,Blue>,WavLen<EFFECT_RETRACTION>,Int<200>,Sum<WavLen<EFFECT_RETRACTION>,WavLen<EFFECT_RETRACTION>>,Int<0>>,TrWaveX<ColorSequence<100,Red,White,Blue>,WavLen<EFFECT_RETRACTION>,Int<200>,Sum<WavLen<EFFECT_RETRACTION>,WavLen<EFFECT_RETRACTION>>,Int<32768>>>>>,
//     // On-Demand Battery Level
//       AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//     >>(),
//   "policesiren"},















  //  { "johnCena", "",
  //  StylePtr<StylePOV<>>(),
  // "StylePOV"},

  //  { "johnCena", "",
  //  StylePtr<ContinuousPOV<>>(),
  // "ContinuousPOV"},


// { "Mortal_Kombat_Raiden", "Mortal_Kombat_Raiden/tracks/Mortal_Kombat_Theme.wav",
//  StylePtr< Layers<
//     RotateColorsX<Variation,Blue>,
//     TransitionLoopL<TrConcat<TrBoing<500,3>,Layers<
//         Stripes<10000,100,RotateColorsX<Variation,Rgb<0,0,128>>,RotateColorsX<Variation,Rgb<0,0,30>>,RotateColorsX<Variation,Rgb<0,0,200>>>,
//         AlphaL<Stripes<8000,-200,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,60>>>,Int<16384>>>,TrDelayX<Scale<SlowNoise<Int<3000>>,Int<100>,Int<2000>>>>>,
//       TransitionLoopL<TrConcat<TrWipe<200>,RandomBlinkL<Int<30000>,White>,TrWipe<200>,AlphaL<White,Int<0>>,TrDelayX<Scale<SlowNoise<Int<3000>>,Int<300>,Int<3000>>>>>,
//     TransitionEffectL<TrConcat<TrFade<10000>,RotateColorsX<Variation,Blue>,TrDelay<30000>,RotateColorsX<Variation,Blue>,TrFade<10000>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrWipe<10000>,TransitionEffect<Stripes<10000,-1000,Red,Yellow,Orange,Yellow>,Stripes<10000,-1000,Red,Yellow,Orange,Yellow>,TrFade<15000>,TrDelay<30000>,EFFECT_FORCE>,TrDelay<30000>,Stripes<10000,-1000,Red,Yellow,Orange,Yellow>,TrWipe<10000>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrWaveX<BrownNoiseFlicker<Yellow,Orange,60>,Int<20000>,Int<400>,Int<10000>,Int<0>>,AlphaL<Yellow,Int<0>>,TrDelay<20000>,AlphaL<Yellow,Int<0>>,TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,Int<20000>,Int<400>,Int<10000>,Int<0>>>,EFFECT_FORCE>,  
// // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//         AlphaL<Black,Int<16384>>,
//         AlphaL<Black,Int<0>>>,
// // Clash 1 - BladeAngle responsive. Yellowish impact
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// // Stab - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// // Blast
//     TransitionEffectL<TrConcat<
//         // Impact Flash - BC always
//         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//         // Waves
//         BlastL<White,850,250,351>,
//         // Impact point afterimage
//         //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<255,70,70>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         // Impact point
//         //BlastL<White,500,350,100000>,
//         BlastL<White,300,350,100000>,
// // Lockup 1 - BC custom range mid-blade to hilt w/random strobe flash
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//         //Random Strobe Flash no dimming
//         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//         //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         // Bottom Layer Bump - random width
//         AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//         // Top Layer Bump - fixed width
//         AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,          Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,
//         // Begin Lockup Transition
//         TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//         // End Lockup Transition
//         TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
// // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
//     LockupTrL<Layers<
//         //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
//         AlphaL<Black,Int<16000>>,
//         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<
//         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//         // Begin Lightning Transition
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
//         // End Lightning Transition    
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//         AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//         // Melt Shape
//         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//         // Melt Begin and End transitions
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
//     AlphaL<Black,SwingSpeed<400>>,
//     AlphaL<ContinuousPOV<>,SwingSpeed<400>>,
//     InOutTrL<TrConcat<TrWipeIn<200>,RandomBlink<30000>,TrWipeIn<200>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,Int<1000>,Int<6000>>,Int<-3000>>,Black,White>,TrDelay<400>,Mix<SmoothStep<Int<4000>,Int<-3000>>,Black,White>,TrWipe<300>>,TrJoin<TrWipeInX<Int<1588>>,TrWaveX<White,Int<1588>,Int<400>,Int<1588>,Int<32768>>>>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,TrDelayX<Int<1588>>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RandomPerLEDFlickerL<White>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<1140>,Int<300>,Int<1200>>,Int<-5000>,Int<6000>>,Int<-4000>>>,TrDelayX<Int<1140>>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrWipeIn<200>,BrownNoiseFlickerL<White,Int<200>>,TrWipeIn<200>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrDelay<3000>,Mix<Int<16384>,SparkleL<Red,70,40096>,SparkleL<Red,90,1024>>,TrSmoothFade<1700>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrDelay<1588>,AlphaL<RandomPerLEDFlickerL<White>,Bump<Int<0>,Int<6000>>>,TrFade<1145>,Black,TrInstant,AlphaL<White,Int<32684>>,TrDelay<20>,AlphaL<BrownNoiseFlicker<Red,Black,50>,Int<32684>>,TrDelay<50>,AlphaL<RandomPerLEDFlickerL<Red>,Bump<Int<20000>,Int<30000>>>,TrSmoothFade<500>>,EFFECT_RETRACTION>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),

// "Mortal_Kombat_Raiden"},



































// {"a_SHIPS/Falcon;common;commonBU", "a_SHIPS/Falcon/tracks/Falcon.wav", // 11 Stripes based Pulse - Default = Blue Color Wheel Changeable   

//     StylePtr<Layers< // Hyperspace
//       Layers<
//         HumpFlicker<Rgb<100,100,150>,RotateColorsX<Variation,SteelBlue>,20>,
//         AlphaL<Mix<SmoothStep<Int<16384>,Int<0>>,Stripes<2000,3000,AudioFlicker<White,RotateColorsX<Variation,Blue>>,RotateColorsX<Variation,Rgb<0,0,30>>,AudioFlicker<RotateColorsX<Variation,Blue>,White>,Rgb<50,50,75>>,Stripes<2000,-3000,AudioFlicker<White,RotateColorsX<Variation,Blue>>,Rgb<0,0,30>,AudioFlicker<RotateColorsX<Variation,Blue>,White>,Rgb<50,50,75>>>,Int<18000>>,
//         AlphaL<AudioFlickerL<Rgb<100,100,150>>,Bump<Int<16384>,Int<4000>>>>,
//       TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
//       BC_effects_1,
//       InOutTrL<TrJoinR<TrWipe<500>,TrWipeIn<500>>,TrJoinR<TrWipe<500>,TrWipeIn<500>>>,
//       TransitionEffectL<TrConcat<TrJoinR<TrWipe<500>,TrWipeIn<500>>,Mix<SmoothStep<Int<16384>,Int<0>>,Stripes<2000,1500,Black,Rgb<100,100,150>>,Stripes<2000,-1500,Black,Rgb<100,100,150>>>,TrFade<3000>,Mix<SmoothStep<Int<16384>,Int<0>>,Stripes<1000,500,Black,Rgb<100,100,150>,Black>,Stripes<1000,-500,Black,Rgb<100,100,150>,Black>>,TrFade<2500>>,EFFECT_RETRACTION>,
//       TransitionEffectL<TrConcat<TrJoinR<TrWipe<500>,TrWipeIn<500>>,Mix<SmoothStep<Int<16384>,Int<0>>,Stripes<1000,250,Black,Rgb<100,100,150>,Black>,Stripes<1000,-250,Black,Rgb<100,100,150>,Black>>,TrFade<2500>,Mix<SmoothStep<Int<16384>,Int<0>>,Stripes<2000,1500,Black,Rgb<100,100,150>>,Stripes<2000,-1500,Black,Rgb<100,100,150>>>,TrFade<3000>,Mix<SmoothStep<Int<16384>,Int<0>>,Stripes<2000,3000,AudioFlicker<White,Blue>,Rgb<0,0,30>,AudioFlicker<Blue,White>,Rgb<50,50,75>>,Stripes<2000,-3000,AudioFlicker<White,Blue>,Rgb<0,0,30>,AudioFlicker<Blue,White>,Rgb<50,50,75>>>,TrDelay<2000>>,EFFECT_PREON>,
//     // On-Demand Battery Level
//         AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//     >>(),  
// "millenium\nfalcon"}, 


// { "a_LEIA/Royalty;common;commonBU", "a_LEIA/Royalty/tracks/Leia1.wav", 
//    StylePtr<Layers<
//             AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
// BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// "general\nprincess"},


// { "a_LUKE/LS6;common;commonBU", "a_LUKE/LS6/tracks/jabba_scene.wav", // 1 AudioFlicker Green Color Wheel Changeable
   
//    StylePtr<Layers<
// // Main Blade
//       AudioFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,
// BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// "luke\nskywalker"},


// { "a_KYLO/KyloUltimate;common;commonBU", "a_KYLO/KyloUltimate/tracks/Kylo1.wav", // 4 BrownNoiseFlicker Red base Color Wheel Changeable
   
//    StylePtr<Layers<
//     StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
//     BC_effects_Red,
//     InOutTrL<TrWipeSparkTip<White,500>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//  // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// "kylo ren"},


// { "a_REY/ScavngrsDstny;common;commonBU", "a_REY/ScavngrsDstny/tracks/ReyEp9End", // 5 AudioFlicker Default = Golden Yellow Color Wheel Changeable
   
//    StylePtr<Layers<
//     AudioFlicker<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<90,65,0>>>,
//     BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Green,Bump<Int<0>,Int<1000>>>,TrDelay<90>,AlphaL<DodgerBlue,Bump<Int<0>,Int<1000>>>,TrFade<100>,AlphaL<DeepSkyBlue,Bump<Int<0>,Int<1000>>>,TrDelay<200>>,EFFECT_PREON>,
// // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(), 
// "scavenger's\ndestiny"},   


// { "a_AHSOKA/AhsokaUltimate;common;commonBU", "a_AHSOKA/AhsokaUltimate/tracks/ItsOverNow.wav", // 8 AudioFlicker Bright Swing Color Wheel Changeable - Default = Silver White
   
//    StylePtr<Layers<
//     Mix<SwingSpeed<500>,AudioFlicker<RotateColorsX<Variation,Rgb<110,150,255>>,RotateColorsX<Variation,Rgb<80,90,130>>>,Mix<SwingSpeed<800>,AudioFlicker<RotateColorsX<Variation,Rgb<110,150,255>>,RotateColorsX<Variation,White>>,RotateColorsX<Variation,White>>>,
//     BC_effects_White,
//     InOutTrL<TrWipeSparkTip<White,400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// "ahsoka\nultimate"},   


// { "aa_Kyberphonic/ShockBaton;common;commonBU", "aa_Kyberphonic/ShockBaton/tracks/BattleAtMazs.wav",
// StylePtr<Layers<
// // Main base blade color
//     Layers<
//     RotateColorsX<Variation,SteelBlue>,
//     BrownNoiseFlickerL<Black,Int<38400>>,
//     BrownNoiseFlickerL<Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,Int<25600>>,
// // Random occasional surge, tip to center
//     TransitionLoopL<TrConcat<
//       TrJoin<TrWipeInX<Scale<SlowNoise<Int<2500>>,Int<200>,Int<500>>>,TrWipeX<Scale<SlowNoise<Int<2500>>,Int<200>,Int<500>>>>,StrobeL<RandomPerLEDFlickerL<Rgb<175,175,175>>,Int<50>,Int<125>>,TrDelayX<Scale<SlowNoise<Int<1200>>,Int<80>,Int<200>>>,AlphaL<White,Int<0>>,TrDelayX<Scale<SlowNoise<Int<3000>>,Int<1300>,Int<3000>>>>>>,
// // Tip and Emitter flares
//     AlphaL<White,LayerFunctions<SmoothStep<Scale<NoisySoundLevel,Int<1000>,Int<4000>>,Int<-4000>>,SmoothStep<Scale<NoisySoundLevel,Int<31768>,Int<28768>>,Int<4000>>>>,
// // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//     AlphaL<Black,Int<16384>>,
//     AlphaL<Black,Int<0>>>,
// // Clash - 3 stage fading impact spot
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// // Stab 
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,DarkOrange,Rgb<80,60,0>,Orange,Rgb<60,30,0>,Black,DarkOrange,Orange>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// // Blast - for white blades
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//     BlastL<EffectSequence<EFFECT_BLAST,Red,Green,Blue,White,Black>,850,250,351>,
//     AlphaL<TransitionEffectL<TrConcat<TrDelay<300>,Red,TrFade<500>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//     BlastL<White,500,300,100000>,
// // Lockup - BC custom range mid-blade
//     LockupTrL<Layers<
//       AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//       AlphaL<BrownNoiseFlicker<Yellow,Black,50>,                                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//       TrConcat<TrInstant,
//       AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<100>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// // Non-Responsive Drag
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// // Lightning Block Non-Responsive    
//     LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//     Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//     Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//     Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
//     //Begin Lightning Transition
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//     //End Lightning Transition    
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,  
// //Melt
//     LockupTrL<
//     AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//       // Melt Shape
//     SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//     // Melt Begin and End transitions
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
// // Ignition Powerup
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<175,175,225>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
 
//     InOutTrL<TrJoin<TrWipe<300>,TrWipeIn<300>>,TrJoin<TrWipeX<WavLen<EFFECT_RETRACTION>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>>,
// // Cooldown tips fizzle out     
//     TransitionEffectL<TrConcat<
//          TrInstant,    AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<100,100,150>>,Int<30>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,
//          TrDelay<1000>,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<100,100,150>>,Int<30>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,
//          TrSmoothFade<1000>,Black,
//          TrDelay<100>, AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<150,150,250>>,Int<30>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelay<50>>,EFFECT_RETRACTION>,
// // Ignition pilot spark/light
//     TransitionEffectL<TrConcat<
//         TrInstant,Blinking<AlphaL<RotateColorsX<Variation,Rgb<150,150,250>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,Black,50,500>,
//         TrDelay<150>,AlphaL<RotateColorsX<Variation,Rgb<100,100,150>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelay<800>>,EFFECT_PREON>,
// // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
//   "shock\nbaton"},   



// { "aa_Blueforce/IgnitionUltimate;common;commonBU", "",
// StylePtr<
//  Layers<
//   Stripes<2000,-2500,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<30,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<30,0,0>>>>,
//   TransitionLoopL<TrConcat<TrWaveX<RandomFlicker<RotateColorsX<Variation,Red>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,Black,300>>,Int<400>,Int<100>,Int<200>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1500>>,Int<200>,Int<1200>>>>>,
//   AlphaL<BrownNoiseFlicker<Red,Black,300>,SwingSpeed<400>>,
//   BC_effects_Red,
//   InOutTrL<
//     TrConcat<TrInstant,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrWipe<300>,Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,Black,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<255,20,0>>,White>,RotateColorsX<Variation,Rgb<128,34,0>>>,TrFade<300>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,TrBoing<300,3>>,
//     TrConcat<TrInstant,BrownNoiseFlicker<White,DarkOrange,300>,TrFade<250>,AlphaL<Black,Int<0>>,TrJoin<TrWipeInX<Int<850>>,TrWaveX<White,Int<800>,Int<400>,Int<850>,Int<32768>>>>>,
// // Comment out this following line for non-stutter on actual ignition
//   //TransitionEffectL<TrConcat<TrWaveX<White,Int<800>,Int<200>,Int<300>,Int<0>>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrDelay<650>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrDelay<100>,BrownNoiseFlicker<White,Red,70>,TrFade<500>,Black,TrInstant>,EFFECT_IGNITION>,
//   TransitionEffectL<TrConcat<TrDelay<1100>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<50>>,EFFECT_RETRACTION>,
//   TransitionEffectL<TrConcat<
//     TrInstant,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrFade<100>,Black,
//     TrDelay<50>,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<50000>>>,TrDelay<150>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<70000>>>,TrFade<150>,Black,
//     TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<400>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<450>,Black,
    
//     TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<70000>>>,TrDelay<250>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<50000>>>,TrFade<200>,Black,
//     TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<500>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<600>,Black,

//     TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<10000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<5000>>>,TrFade<150>,Black,
//     TrDelay<350>,Black,
//     TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<10000>>>,TrDelay<70>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<5000>>>,TrFade<40>,Black,
//     TrDelay<20>,Black,

//     TrInstant,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrDelay<50>,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrFade<50>,Black,
//     TrDelay<50>,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<50000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<70000>>>,TrFade<150>,Black,
//     TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<300>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<400>,

//     AlphaL<BrownNoiseFlicker<White,Red,100>,Bump<Int<0>,Int<10000>>>,
//     TrFade<175>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<20000>>>,TrFade<175>,AlphaL<BrownNoiseFlicker<White,Red,100>,Bump<Int<0>,Int<10000>>>,
//     TrFade<115>,AlphaL<BrownNoiseFlicker<White,DarkOrange,100>,Bump<Int<0>,Int<40000>>>,TrFade<115>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<20000>>>,
//     TrFade<100>,AlphaL<BrownNoiseFlicker<White,DarkOrange,100>,Bump<Int<0>,Int<60000>>>,TrFade<100>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<40000>>>,
//     TrFade<75>,BrownNoiseFlicker<White,DarkOrange,300>,TrFade<50>,Black,TrFade<50>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Rgb<200,150,150>,20>,
//     TrSmoothFade<100>>,EFFECT_PREON>,
// // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
//   "ignition\nultimate"}, 


//  { "GhostsOfTheGrey;common;commonBU", "", 
// StylePtr<Layers<
//   StripesX<Int<6000>,Int<-1000>,RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<24,24,35>>>,AlphaL<White,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   AlphaL<Stripes<4000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Black>,White,RotateColorsX<Variation,Rgb<100,100,150>>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// BC_effects_White,  
//   InOutTrL<TrWipe<400>,TrConcat<TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,50>>,Stripes<3000,2000,White,Rgb<100,100,100>>,TrFadeX< Percentage<WavLen<EFFECT_RETRACTION>,50> >>>,
// // On-Demand Battery Level
//   AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// >>(),
// "ghosts of\nthe grey"},   


//  { "aa_Greyscale/Apocalypse_Greyscale;common;commonBU", "",
// StylePtr<Layers<
//   // Swing responsive humpflicker/rotating red/orange unstable base, unstable takes over the blade the harder you swing.
//   Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,Mix<Sin<Int<30>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<30,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,25,0>>,RotateColorsX<Variation,Rgb<60,15,0>>>,300>,RotateColorsX<Variation,Rgb<30,2,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<125,0,0>>,40>>,
//   // Alternate plain humpflicker
//   // HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,50>,
//   // Responsive edge audioflicker swing - starts at the tip and takes over the blade the harder you swing.
//   AlphaL<AlphaL<AudioFlickerL<RotateColorsX<Variation,Rgb16<65535,8729,0>>>,SwingSpeed<350>>,SmoothStep<Scale<SwingSpeed<450>,Int<29000>,Int<9500>>,Int<16000>>>,
//   BC_effects_1_BlastRotate,
//   // Unstable ignition
//   TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Orange>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<70,25,5>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Rgb<75,20,5>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<155,25,0>>,RotateColorsX<Variation,Rgb<65,15,0>>>>,TrFade<2500>,Stripes<3000,-2250,RotateColorsX<Variation,DarkOrange>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<195,15,0>>,RotateColorsX<Variation,Rgb<50,15,0>>>,BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Rgb<85,15,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<155,25,0>>,RotateColorsX<Variation,Rgb<95,15,0>>>>,TrFade<1000>,Stripes<3000,-1500,RotateColorsX<Variation,Rgb16<65535,8729,0>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<195,10,0>>,RotateColorsX<Variation,Rgb<55,5,0>>>,BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Rgb<185,10,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<255,13,0>>,RotateColorsX<Variation,Rgb<105,3,0>>>>,TrFade<2500>>,EFFECT_IGNITION>,
//   // Humpflicker retraction
//   TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,75,0>>,40>,TrFade<500>>,EFFECT_RETRACTION>,
//   // Spark tip ignition, cycle down retraction
//   InOutTrL<TrWipeSparkTip<White,175,250>,TrColorCycle<500>>,
//   // White flicker retraction effect
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<500>,Int<5500>>,Int<-4000>>>,TrFade<1100>>,EFFECT_RETRACTION>,
//   // Emitter cool off retraction effect
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<1600>,AlphaL<RotateColorsX<Variation,Orange>,Bump<Int<0>,Int<8000>>>,TrFade<1400>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<6000>>>,TrFade<1000>>,EFFECT_RETRACTION>,
//   // Noise responsive preon
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<2000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<14386,0,0>>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Red>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Red>>>,DarkOrange,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<25000>>,Int<-4000>>>,TrDelay<6500>>,EFFECT_PREON>,
//   // Charge up, wave out preon
//   TransitionEffectL<TrConcat<TrDelay<3000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Red>,Int<115>,Int<400>,Int<250>,Int<0>>>,TrDelay<1000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Red>,Int<215>,Int<300>,Int<395>,Int<0>>>,TrDelay<1500>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Red>,Int<345>,Int<200>,Int<500>,Int<0>>>,TrDelay<1500>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<6000>>>,TrBoing<500,2>>,EFFECT_PREON>,
//   // Emitter heat up preon
//   TransitionEffectL<TrConcat<TrFade<1500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Red>,10>,Bump<Int<0>,Int<4000>>>,TrFade<2000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Orange>,15>,Bump<Int<0>,Int<5000>>>,TrFade<2500>,AlphaL<HumpFlickerL<White,20>,Bump<Int<0>,Int<6000>>>,TrBoing<500,2>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//   AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// >>(),
// "apocalypse"},  


//  { "aa_Greyscale/Behemoth_Greyscale;common;commonBU", "",
// StylePtr<Layers<
//   // White pulse
//   Stripes<16000,-1200,RotateColorsX<Variation,Rgb<100,100,150>>,Pulsing<Rgb16<45025,45025,45025>,RotateColorsX<Variation,Rgb<50,50,75>>,300>,RotateColorsX<Variation,Rgb<100,100,150>>>,
//   // Swing effect, cycles between bright green and blue
//   AlphaL<Mix<Sin<Int<10>>,RotateColorsX<Variation,Rgb16<20393,20393,65535>>,RotateColorsX<Variation,Rgb16<20393,65535,20393>>>,SwingSpeed<325>>,
//   // Enhanced swing effect, harder swings cause bright white to ripple up the top half of the blade
//   AlphaL<AlphaL<Stripes<2500,-2750,Pulsing<White,Rgb<128,128,128>,200>,Rgb<60,60,60>,Pulsing<Rgb<30,30,30>,Black,800>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Int<13000>,Int<16000>>>,
//   // Sparking emitter flare
//   AlphaL<White,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<3750>>,Int<-4000>>>,
//   BC_effects_1_BlastRotate,
//   // Bright blue/green unstable ignition
//   TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb16<38402,38402,65535>>,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<38402,65535,38402>>,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<1000>>,EFFECT_IGNITION>,
//   // White HumpFlicker retraction
//   TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>,
//   // Ignition and retraction
//   InOutTrL<TrWipe<150>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//   AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// >>(),
// "behemoth"},  


//  { "aa_Greyscale/Coda_Greyscale;common;commonBU", "",
// StylePtr<Layers<
//   //Rotates   ^3 times per minute between DodgerBlue and DeepSkyBlue with subtle Cyan/Blue audioflicker
//   Mix<Sin<Int<3>>,AudioFlicker<RotateColorsX<Variation,DodgerBlue>,Stripes<5000,-90,RotateColorsX<Variation,Rgb<0,55,165>>,RotateColorsX<Variation,Rgb<0,85,115>>,RotateColorsX<Variation,Rgb<0,65,145>>,RotateColorsX<Variation,Rgb<0,30,185>>>>,AudioFlicker<RotateColorsX<Variation,Rgb<0,155,255>>,Stripes<5000,-90,RotateColorsX<Variation,Rgb<0,95,170>>,RotateColorsX<Variation,Rgb<0,115,215>>,RotateColorsX<Variation,Rgb<0,145,145>>,RotateColorsX<Variation,Rgb<0,65,225>>>>>,
//   //Alternate DeepSkyBlue with very subtle audioflicker
//   //AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,95,195>>>,
//   //Unstable swing
//   AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,DeepSkyBlue>,Black,300>,SwingSpeed<400>>,
//   //Unstable ripple swing
//   AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,DeepSkyBlue>,Black>,Black,RotateColorsX<Variation,DeepSkyBlue>,Black>,SwingSpeed<525>>,
//   BC_effects_1_BlastRotate,
//   //Stabilize ignition effect
//   TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<90,180,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,26,60>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<90,180,255>>,RotateColorsX<Variation,Rgb<0,26,60>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,42,128>>,RotateColorsX<Variation,Rgb<0,26,60>>>>,TrFade<400>,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<90,180,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,26,60>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<90,180,255>>,RotateColorsX<Variation,Rgb<0,26,60>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,42,128>>,RotateColorsX<Variation,Rgb<0,26,60>>>>,TrFade<450>,HumpFlickerL<AlphaL<RotateColorsX<Variation,Rgb<90,180,255>>,Int<19000>>,25>,TrFade<2875>>,EFFECT_IGNITION>,
//   //Slow brighten retraction effect
//   TransitionEffectL<TrConcat<TrFade<1125>,RotateColorsX<Variation,Rgb<90,180,255>>,TrInstant>,EFFECT_RETRACTION>,
//   //Standard ignition/retraction
//   InOutTrL<TrWipe<500>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   //Overload preon effect
//   TransitionEffectL<TrConcat<TrFade<450>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,10>,Bump<Int<0>,Int<3000>>>,TrFade<350>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,15>,Bump<Int<0>,Int<5000>>>,TrFade<450>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,20>,Bump<Int<0>,Int<7000>>>,TrFade<500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,25>,Bump<Int<0>,Int<10500>>>,TrBoing<150,1>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//   AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// >>(),
// "coda"},


//  { "aa_Greyscale/Endure_Greyscale;common;commonBU", "",
// StylePtr<Layers<
//   // Heart beat humpflicker - point the blade up to blend in a subtle heart beat - NOTE: Due to the way Proffie works, this isn't always "lined up" and might be slightly ahead or slightly behind the heart beat. Personally, I don't mind this, as it seems like it's just part of the beat. But if you want to fix this you can either change to another preset then change back or turn the saber off and back on until it's lined up.
//   Mix<Scale<BladeAngle<19000>,Int<32768>,Int<0>>,Blinking<HumpFlicker<RotateColorsX<Variation,Red>,AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb16<11585,0,0>>>,35>,RotateColorsX<Variation,Red>,918,900>,HumpFlicker<RotateColorsX<Variation,Red>,AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb16<11585,0,0>>>,35>>,
//   // Alternate humpflicker, no heart beat
//   // HumpFlicker<RotateColorsX<Variation,Red>,AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,Rgb16<11585,0,0>>,35>,
//   // Charge up Force effect. I recommend commenting this out if you'll be using the included Quotes instead of Force sounds (Or wait for Proffie OS6!)
//   TransitionEffectL<TrConcat<TrDelay<1200>,HumpFlicker<RotateColorsX<Variation,Red>,AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb16<11585,0,0>>>,35>,TrFade<450>,RotateColorsX<Variation,Rgb16<26858,591,0>>,TrFade<300>,RotateColorsX<Variation,Rgb16<65535,11439,0>>,TrFade<50>>,EFFECT_FORCE>,
//   // Audio responsive unstable/stripey swing effect
//   AlphaL<AudioFlickerL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,Black>,Black,RotateColorsX<Variation,Red>,Black>>,SwingSpeed<265>>,
//   // Unstable swing effect
//   AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>,SwingSpeed<350>>,
//   // Bright ripple hard swing effect - swing hard enough to trigger an accent swing and blood orange ripples up the blade
//   AlphaL<Mix<Scale<BladeAngle<19000>,Int<32768>,Int<0>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,2,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,1,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,SmoothStep<Scale<SlowNoise<Int<3000>>,Int<1750>,Int<4125>>,Int<-4000>>>,
//   // Responsive flame emitter effect, point the blade up to speed up the flame
//   AlphaL<AlphaL<Stripes<2000,-3750,RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,0,0>>,Black,800>>,Scale<IsLessThan<SwingSpeed<850>,Int<13600>>,Scale<SwingSpeed<850>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Int<14500>,Int<16000>>>,
//   BC_effects_Red,
//   // Unstable ripple ignition effect
//   TransitionEffectL<TrConcat<TrInstant,Stripes<1900,-2350,RotateColorsX<Variation,Rgb16<65535,5115,0>>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,8357,0>>,RotateColorsX<Variation,Orange>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<75,0,0>>>>,TrFade<2350>>,EFFECT_IGNITION>,
//   // Retraction effect, bright humpflicker fades to unstable
//   TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb16<65535,1899,0>>,40>,TrFade<1750>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,1899,0>>,Black,300>,TrInstant>,EFFECT_RETRACTION>,
//   // Spark tip ignition/retraction
//   InOutTrL<TrJoin<TrWipe<2000>,TrWaveX<White,Int<2150>,Int<400>,Int<2000>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,WavLen<EFFECT_RETRACTION>,Int<400>,Int<1750>,Int<32768>>>>,
//   // Audio responsive cooldown retraction effect
//   TransitionEffectL<TrConcat<TrDelay<1750>,AlphaL<Mix<Trigger<EFFECT_RETRACTION,Int<4250>,Int<6000>,Int<2500>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<14386,0,0>>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,1,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,SmoothStep<Scale<NoisySoundLevel,Int<-1125>,Int<20000>>,Int<-4000>>>,TrDelay<5000>>,EFFECT_RETRACTION>,
//   // Audio responsive charge-up preon effect
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<1750>,Int<250>,Int<3000>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,1,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<14386,0,0>>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,100>>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<25000>>,Int<-4000>>>,TrDelay<2000>>,EFFECT_PREON>,
//   // Ripple out preon effect
//   TransitionEffectL<TrConcat<TrDelay<1150>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Red>,Int<125>,Int<350>,Int<315>,Int<0>>>,TrDelay<850>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//   AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// >>(),
// "endure"},


// {"aa_Blueforce/DarkSpace;common;commonBU", "Proto2/tracks/proto1.wav", 
// StylePtr<Layers<
//   StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<Sin<Int<8>,Int<6000>,Int<3000>>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Sin<Int<5>,Int<-400>,Int<-1000>>,Pulsing<Black,RotateColorsX<Variation,Rgb<75,0,165>>,3000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb<75,0,165>>,Black>>,RotateColorsX<Variation,Rgb<22,0,49>>,Pulsing<RotateColorsX<Variation,Rgb<19,0,41>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,Black,RotateColorsX<Variation,Rgb<130,40,230>>>,RotateColorsX<Variation,Rgb<36,0,79>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<48,0,105>>,RotateColorsX<Variation,Rgb<19,0,41>>,3000>>,
//   AlphaL<StripesX<Sin<Int<8>,Int<3000>,Int<6000>>,Int<140>,StripesX<Sin<Int<6>,Int<1000>,Int<3000>>,Int<-55>,Pulsing<Mix<Sin<Int<4>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<130,40,230>>>,RotateColorsX<Variation,Rgb<7,0,16>>,4000>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Rgb<130,40,230>>,Black>>,RotateColorsX<Variation,Rgb<22,0,49>>,Pulsing<RotateColorsX<Variation,Rgb<19,0,41>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<-25>,Int<-75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<130,40,230>>>,RotateColorsX<Variation,Rgb<36,0,79>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<48,0,105>>,RotateColorsX<Variation,Rgb<19,0,41>>,3000>>,Int<10000>>,
//   AlphaL<StrobeL<RotateColorsX<Variation,Rgb<95,0,210>>,Int<200>,Int<100>>,Sin<Int<15>,Int<20000>,Int<1000>>>,
//   BC_effects_Red,
//   TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
//   InOutTrL<TrWipe<300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<>,70>>,HumpFlicker<Rgb<95,0,210>,Black,5>,TrJoin<TrWipeInX<Int<300>>,TrWaveX<Rgb<95,0,210>,Int<300>,Int<200>,Int<300>,Int<32768>>>,Black,TrInstant>,EFFECT_PREON>,
//   // On-Demand Battery Level
//   AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// >>(),
// "dark space"},


// {"aa_JayDalorian/Decimate;common;commonBU", "", 
// StylePtr<Layers<
//   StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,20>,RotateColorsX<Variation,Rgb<4,0,8>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,RotateColorsX<Variation,Rgb<42,0,105>>>,RotateColorsX<Variation,Rgb<30,0,66>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
//   BC_effects_1,
//   TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>>,TrFade<1200>>,EFFECT_RETRACTION>,
//   InOutTrL<TrWipeSparkTip<White,800>,TrWipeInSparkTip<White,880>>,
//   TransitionEffectL<TrConcat<TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<21,0,52>>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<21,0,52>>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<42,0,105>>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<42,0,105>>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<64,0,145>>,30>,SmoothStep<Int<6000>,Int<-500>>>,TrDelay<5100>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//   AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// >>(),
// "decimate"},


// { "aa_BK/MysticMaster;common;commonBU", "",
//   StylePtr<Layers<
//     StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<5,5,20>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<45,45,70>>,Black>>,RotateColorsX<Variation,Rgb<20,20,30>>,Pulsing<RotateColorsX<Variation,Rgb<25,25,40>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<40,40,60>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<2,2,5>>,3000>>,
//     AlphaL<StyleFire<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<1,1,2>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
//   // Swing Color
//     AlphaL<Stripes<9000,-1500,RotateColorsX<Variation,Rgb<175,175,225>>,RotateColorsX<Variation,Rgb<25,25,38>>,Pulsing<RotateColorsX<Variation,Rgb<12,12,19>>,Black,800>>,SwingSpeed<600>>,
//   // Emitter Flare
//     AlphaL<RotateColorsX<Variation,Rgb<175,175,225>>,Bump<Int<0>,Int<8000>>>,
//     BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,500>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,WavLen<EFFECT_RETRACTION>,Int<400>,Int<1000>,Int<32768>>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// "mystic\nmaster"},

// {"aa_JayDalorian/LightsaberOfTheBells;common;commonBU", "",
//  StylePtr<Layers<
//   StyleFire<StripesX<Int<3000>,Scale<SlowNoise<Int<2000>>,Int<-1000>,Int<-5000>>,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,0,60>>,RotateColorsX<Variation,Rgb<0,0,10>>>,RotateColorsX<Variation,Rgb<25,25,255>>,RotateColorsX<Variation,Rgb<0,0,128>>>,RotateColorsX<Variation,Rgb<0,0,80>>,0,5,FireConfig<3,3000,0>,FireConfig<3,3000,0>,FireConfig<3,3000,0>,FireConfig<3,3000,0>>,
//   AlphaL<Stripes<2500,-3000,Red,Rgb<60,0,0>,Pulsing<Rgb<30,0,0>,Black,800>>,SwingSpeed<600>>,
//   BC_effects_1,
//   InOutTrL<TrWipeSparkTip<White,1200>,TrWipeInSparkTip<White,1063>>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,
//   TransitionEffectL<TrConcat<TrDelay<1500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Blue>,30>,Bump<Int<0>,Int<3000>>>,TrFade<500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Blue>,30>,Bump<Int<0>,Int<4000>>>,TrFade<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Blue>,30>,Bump<Int<0>,Int<5000>>>,TrBoing<1950,7>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Blue>,Int<500>,Int<200>,Int<500>,Int<40>>>,TrDelay<1000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Blue>,Int<300>,Int<300>,Int<300>,Int<40>>>,TrDelay<1300>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Blue>,Int<100>,Int<400>,Int<100>,Int<32768>>>,TrDelay<2000>,AlphaL<RotateColorsX<Variation,Blue>,Bump<Int<0>,Int<6000>>>,TrBoing<1450,5>>,EFFECT_PREON>,
// // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
//   "saber of\nthe bells"},

};


BladeConfig blades[] = {

{ 0, // CT_A 132
  WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // HiltPCB and Main Blade in parallel
  CONFIGARRAY(Scoundrel),
"00_Scoundrel_save" }


};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
#endif
