// BC_VenZallow_8.x.h

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 1

// ------ Audio Stuff --------

#define VOLUME 2000
#define BOOT_VOLUME 100
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8
#define ENABLE_FASTON

// ------ Blade Stuff ------

const unsigned int maxLedsPerStrip = 144;
#define EXTRA_COLOR_BUFFER_SPACE 30
#define DYNAMIC_BLADE_LENGTH
// #define SHARED_POWER_PINS

// ------ SD Card Stuff -------

#define MOUNT_SD_SETTING
#define SAVE_COLOR_CHANGE

// ------ System Stuff --------

//#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define CONFIG_STARTUP_DELAY 3000
 // #define PROFFIEOS_LOG_LEVEL 500

// ------- Motion and Gesture stuff -------

#define CLASH_THRESHOLD_G 3.5
#define ENABLE_SPINS

// --- BC prop stuff -----

#define BC_SWING_ON
#define BC_SWING_ON_SPEED 400 // Default 250
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
#define BC_FORCE_PUSH
#define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second. 
//#define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200

#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"     // For Red, Green, light Blue, ...light colored blades
#include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"
// #include "aliases/TrueWhites/BC_effects_2.h"     // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"   // For Red or dark blades
// #include "aliases/TrueWhites/BC_effects_White.h" // For White blades

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrSmoothFade<200>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrDelay<1000>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;


/*
1. a_VEN_ZALLOW/LastLineofDefense         // Fett263 Rotoscope with Emitter Spark (Primary Blade) OS6 Style (Edit Mode compliant)
// aa_HarrySolo/DESTABILIZE               // BC custom preon   
2. aa_Fourzze/GrandLegacy                 // Leia's style
3. aa_LINK/Purged                         // ShockBaton
4. a_ARCANN/EternalPrince                 // Custom Yellow-Orange
5. a_CAL_KESTIS/AllThatRemains            // Fallen Order Blue
6. aa_Fourzze/Betrayal                    // Fallen Order Purple
7. a_SAVAGE/Mauls_Brother                 // Yellow HumpFlicker
8. aa_KYBERPHONIC/Metamorphose            // Custom Morphing colors (Sin)
9. Mortal_Kombat_Raiden                   // Jason Sawyer's custom blade style
10. aa_Greyscale/Galvanic_Greyscale       // KidsTryThisAtHome custom for Greyscale Galvanic (BC Effects)
//. aa_JayDalorian/LightsaberOfTheBells   // JayDalorian's style (BC Effects)
11. Proxima                               // Nathan Donovan's IT 2017 SmokeBlade (BC Effects)
*/


Preset VenZallow [] = {

{ "a_VEN_ZALLOW/LastLineofDefense;common;commonBU", "",
  StylePtr<Layers<
    AudioFlicker<Stripes<10000,-2600,Green,Green,Mix<Int<7710>,Black,Green>,Green,Mix<Int<16448>,Black,Green>>,Green>,
    AlphaL<AudioFlickerL<White>,SmoothStep<Int<3000>,Int<-2000>>>,
    AlphaL<AudioFlickerL<White>,SmoothStep<Int<3000>,Int<-2000>>>,
    AlphaL<Rgb<125,125,125>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    TransitionEffectL<TrConcat<TrExtendX<IgnitionTime<>,TrInstant>,Stripes<3000,-3500,White,RandomPerLEDFlicker<Mix<Int<7710>,Black,White>,Black>,BrownNoiseFlicker<White,Mix<Int<3855>,Black,White>,200>,RandomPerLEDFlicker<Mix<Int<10280>,Black,White>,Mix<Int<3855>,Black,White>>>,TrFadeX<IgnitionTime<>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrDelayX<RetractionTime<>>>,EFFECT_RETRACTION>,
    BC_effects_1,
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    TransitionEffectL<TrConcat<TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Green>,10>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Green>,15>,SmoothStep<Sum<Int<2000>,IntArg<PREON_SIZE_ARG,2000>>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Green>,20>,SmoothStep<Sum<Int<4000>,IntArg<PREON_SIZE_ARG,2000>>,Int<-4000>>>,TrBoingX<Mult<Int<8192>,WavLen<EFFECT_PREON>>,3>>,EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Blinking<Green,Black,500,500>,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>
  >>(),
  StylePtr<Layers<
    Blinking<Red,Black,1000,500>,
    InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>
  >>(),
"ven\nzallow"},

// { "aa_HarrySolo/DESTABILIZE;common;commonBU", "",
//   StylePtr<Layers<
//     Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,StyleFire<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>,0,6,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,Stripes<5000,-1500,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,105>>>>,
//     BC_effects_1,
//     InOutTrL<TrConcat<TrWipe<200>,Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,StyleFire<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>,0,6,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,Stripes<5000,-1500,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,105>>>>,TrWipe<100>,Black,TrBoing<300,3>>,TrWipeInSparkTipX<White,WavLen<EFFECT_RETRACTION>>>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<HumpFlickerL<Rgb<120,120,165>,10>,Bump<Int<0>,Int<50000>>>,TrFade<300>,AlphaL<HumpFlickerL<Rgb<120,120,165>,20>,Bump<Int<0>,Int<6000>>>,TrInstant,AlphaL<Strobe<Black,Rgb<100,100,255>,20,20>,Bump<Int<0>,Int<5000>>>,TrDelay<400>,AlphaL<ColorCycle<Gradient<RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,105>>>,50,200,Cyan,100,300,5000>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<2370>,Int<1>,Int<1>>,Int<-10000>,Int<30000>>,Int<-2000>>>,TrDelay<1677>,Black,TrFade<500>,Strobe<Black,RotateColorsX<Variation,DeepSkyBlue>,20,20>,TrDelay<200>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<>,50>>,AlphaL<StyleFire<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>,0,6,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,Bump<Int<0>,Int<30000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
// // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
//   StylePtr<Layers<
//     Blinking<Green,Black,500,500>,
//     InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
//   StylePtr<Layers<
//     Blinking<Red,Black,1000,500>,
//     InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
// "destabilize"},

{ "aa_Fourzze/GrandLegacy;common;commonBU", "",
    StylePtr<Layers<
      AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
      BC_effects_1,
      InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Blinking<Green,Black,500,500>,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
  StylePtr<Layers<
    Blinking<Red,Black,1000,500>,
    InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
"Satele"},

{ "aa_LINK/Purged;common;commonBU", "tracks/FallenOrderTracks/JFO5.wav",
StylePtr<Layers<
// Main base blade color
    Layers<
RotateColorsX<Variation,Rgb16<5695,7,20095>>,
  BrownNoiseFlickerL<Black,Int<38400>>,
  BrownNoiseFlickerL<Stripes<3000,-4000,Rgb<39,5,71>,Rgb<100,70,150>,Rgb<10,10,15>,Rgb<95,0,225>>,Int<25600>>,
// Random occasional surge, tip to center
    TransitionLoopL<TrConcat<
      TrJoin<TrWipeInX<Scale<SlowNoise<Int<2500>>,Int<200>,Int<500>>>,TrWipeX<Scale<SlowNoise<Int<2500>>,Int<200>,Int<500>>>>,StrobeL<RandomPerLEDFlickerL<Rgb<175,175,175>>,Int<50>,Int<125>>,TrDelayX<Scale<SlowNoise<Int<1200>>,Int<80>,Int<200>>>,AlphaL<White,Int<0>>,TrDelayX<Scale<SlowNoise<Int<3000>>,Int<1300>,Int<3000>>>>>>,
// Tip and Emitter flares
    AlphaL<Rgb<95,0,225>,LayerFunctions<SmoothStep<Scale<NoisySoundLevel,Int<1000>,Int<4000>>,Int<-4000>>,SmoothStep<Scale<NoisySoundLevel,Int<31768>,Int<28768>>,Int<4000>>>>,
// Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
    AlphaL<Black,Int<16384>>,
    AlphaL<Black,Int<0>>>,
// Clash - 3 stage fading impact spot
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// Stab 
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,DarkOrange,Rgb<80,60,0>,Orange,Rgb<60,30,0>,Black,DarkOrange,Orange>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// Blast - for white blades
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
    BlastL<EffectSequence<EFFECT_BLAST,Red,Green,Blue,White,Black>,850,250,351>,
    AlphaL<TransitionEffectL<TrConcat<TrDelay<300>,Red,TrFade<500>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
    BlastL<White,500,300,100000>,
// Lockup - BC custom range mid-blade
    LockupTrL<Layers<
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
      AlphaL<BrownNoiseFlicker<Yellow,Black,50>,                                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
      TrConcat<TrInstant,
      AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<100>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// Non-Responsive Drag
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// Lightning Block Non-Responsive    
    LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
    Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
    Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
    Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
    //Begin Lightning Transition
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
    //End Lightning Transition    
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,  
//Melt
    LockupTrL<
    AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
      // Melt Shape
    SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
    // Melt Begin and End transitions
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
// Ignition Powerup
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<175,175,225>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
 
    InOutTrL<TrJoin<TrWipe<300>,TrWipeIn<300>>,TrJoin<TrWipeX<WavLen<EFFECT_RETRACTION>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>>,
// Cooldown tips fizzle out     
    TransitionEffectL<TrConcat<
         TrInstant,    AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<100,100,150>>,Int<30>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,
         TrDelay<1000>,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<100,100,150>>,Int<30>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,
         TrSmoothFade<1000>,Black,
         TrDelay<100>, AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<150,150,250>>,Int<30>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelay<50>>,EFFECT_RETRACTION>,
// Ignition pilot spark/light
    TransitionEffectL<TrConcat<
        TrInstant,Blinking<AlphaL<RotateColorsX<Variation,Rgb<150,150,250>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,Black,50,500>,
        TrDelay<150>,AlphaL<RotateColorsX<Variation,Rgb<100,100,150>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelay<800>>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Blinking<Green,Black,500,500>,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
  StylePtr<Layers<
    Blinking<Red,Black,1000,500>,
    InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
  "purged"},


{ "a_ARCANN/EternalPrince;common;commonBU", "",
   StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Rgb<180,70,0>>,RotateColorsX<Variation,Rgb<100,30,0>>>,
    BC_effects_1,
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Blinking<Green,Black,500,500>,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
  StylePtr<Layers<
    Blinking<Red,Black,1000,500>,
    InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
"arcann"},


{ "a_CAL_KESTIS/AllThatRemains;common;commonBU", "tracks/FallenOrderTracks/JFO2.wav",
  StylePtr<Layers<
// Main Blade
    // Jedi base Blue
    StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,
    // Jedi Force Blue
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    // Jedi Swing Blue
    AlphaL<RotateColorsX<Variation,Rgb<70,70,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_1,
// Ignition and Retraction
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Blinking<Green,Black,500,500>,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
  StylePtr<Layers<
    Blinking<Red,Black,1000,500>,
    InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
  "allthat\nremains"},


{ "aa_Fourzze/Betrayal;common;commonBU", "aa_Fourzze/Betrayal/tracks/traya.wav",
  StylePtr<Layers<
// Main Blade
    // Jedi base Purple
    StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<95,0,225>>,Pulsing<RotateColorsX<Variation,Rgb<39,5,71>>,RotateColorsX<Variation,Rgb<95,0,225>>,800>,RotateColorsX<Variation,Rgb<95,0,225>>>,
    // Jedi Force Purple
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<95,0,225>>,TrFade<800>>,EFFECT_FORCE>,
    // Jedi Swing Purple
    AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_1,
// Ignition and Retraction
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Blinking<Green,Black,500,500>,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
  StylePtr<Layers<
    Blinking<Red,Black,1000,500>,
    InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
  "betrayal"},


{ "a_SAVAGE/Mauls_Brother;common;commonBU", "",
  StylePtr<Layers<
      HumpFlicker<RotateColorsX<Variation,Rgb<255,160,0>>,RotateColorsX<Variation,Rgb<84,60,0>>,40>,
      BC_effects_1,
      TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,AlphaL<White,Bump<Int<0>,Int<4000>>>,TrInstant>,EFFECT_RETRACTION>,
      InOutTrL<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<175000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Blinking<Green,Black,500,500>,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
  StylePtr<Layers<
    Blinking<Red,Black,1000,500>,
    InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
  "maul's\nbrother"},


{ "aa_KYBERPHONIC/Metamorphose;common;commonBU", "",
   StylePtr<Layers<
  // Ice blue audioflicker
    AudioFlicker<RotateColorsX<Sin<Int<2>>,Red>,RotateColorsX<Sin<Int<2>>,DodgerBlue>>,
  // Bright cyan color swing 
    AlphaL<RotateColorsX<Variation,Rgb<4,255,121>>,SwingSpeed<500>>,
  // Hard swing ripple effect
    AlphaL<Stripes<2500,-4000,RotateColorsX<Variation,Rgb<0,149,255>>,RotateColorsX<Variation,Rgb<0,26,60>>,Pulsing<RotateColorsX<Variation,Rgb<0,13,30>>,Black,800>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
  // Sparking emitter flare
    AlphaL<RotateColorsX<Variation,Rgb<0,255,117>>,SmoothStep<Scale<SlowNoise<Int<2300>>,Int<1200>,Int<4500>>,Int<-4000>>>,
    BC_effects_1,
  // Bright HumpFlicker ignition effect 
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<1000>>,EFFECT_IGNITION>,
  // Bright HumpFlicker retraction effect
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<90,180,255>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
  // Glitch out ignition and cycle down retraction 
    InOutTrL<TrConcat<TrWipe<200>,AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,TrWipe<100>,Black,TrBoing<550,2>>,TrColorCycle<790>>,
  // Retraction cool down effect
    TransitionEffectL<TrConcat<TrInstant,
    AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<0,149,255>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2200>>,Int<1500>,Int<5000>>,Int<-4000>>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,30> >,
    AlphaL<RotateColorsX<Variation,Rgb<0,43,82>>,Bump<Int<0>,Int<10000>>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,30> >,
    AlphaL<Rgb<80,80,80>,Bump<Int<0>,Int<7000>>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,30> >>,EFFECT_RETRACTION>,
  // Clickity preon
    TransitionEffectL<TrConcat<TrFade<100>,AlphaL<Pulsing<Rgb<120,120,165>,Rgb<50,50,80>,500>,Bump<Int<0>,Int<6000>>>,TrBoing<600,9>>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Blinking<Green,Black,500,500>,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
  StylePtr<Layers<
    Blinking<Red,Black,1000,500>,
    InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
  "metamorphose"},


{ "Mortal_Kombat_Raiden;common;commonBU", "Mortal_Kombat_Raiden/tracks/Mortal_Kombat_Theme.wav",
  StylePtr< Layers<
      RotateColorsX<Variation,Blue>,
      TransitionLoopL<TrConcat<TrBoing<500,3>,Layers<
        Stripes<10000,100,RotateColorsX<Variation,Rgb<0,0,128>>,RotateColorsX<Variation,Rgb<0,0,30>>,RotateColorsX<Variation,Rgb<0,0,200>>>,
        AlphaL<Stripes<8000,-200,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,60>>>,Int<16384>>>,TrDelayX<Scale<SlowNoise<Int<3000>>,Int<100>,Int<2000>>>>>,
      TransitionLoopL<TrConcat<TrWipe<200>,RandomBlinkL<Int<30000>,White>,TrWipe<200>,AlphaL<White,Int<0>>,TrDelayX<Scale<SlowNoise<Int<3000>>,Int<300>,Int<3000>>>>>,
    TransitionEffectL<TrConcat<TrFade<10000>,RotateColorsX<Variation,Blue>,TrDelay<30000>,RotateColorsX<Variation,Blue>,TrFade<10000>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrWipe<10000>,TransitionEffect<Stripes<10000,-1000,Red,Yellow,Orange,Yellow>,Stripes<10000,-1000,Red,Yellow,Orange,Yellow>,TrFade<15000>,TrDelay<30000>,EFFECT_FORCE>,TrDelay<30000>,Stripes<10000,-1000,Red,Yellow,Orange,Yellow>,TrWipe<10000>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrWaveX<BrownNoiseFlicker<Yellow,Orange,60>,Int<20000>,Int<400>,Int<10000>,Int<0>>,AlphaL<Yellow,Int<0>>,TrDelay<20000>,AlphaL<Yellow,Int<0>>,TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,Int<20000>,Int<400>,Int<10000>,Int<0>>>,EFFECT_FORCE>,
    BC_effects_1,
    InOutTrL<TrConcat<TrWipeIn<200>,RandomBlink<30000>,TrWipeIn<200>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,Int<1000>,Int<6000>>,Int<-3000>>,Black,White>,TrDelay<400>,Mix<SmoothStep<Int<4000>,Int<-3000>>,Black,White>,TrWipe<300>>,TrJoin<TrWipeInX<Int<1588>>,TrWaveX<White,Int<1588>,Int<400>,Int<1588>,Int<32768>>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,TrDelayX<Int<1588>>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RandomPerLEDFlickerL<White>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<1140>,Int<300>,Int<1200>>,Int<-5000>,Int<6000>>,Int<-4000>>>,TrDelayX<Int<1140>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrWipeIn<200>,BrownNoiseFlickerL<White,Int<200>>,TrWipeIn<200>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<3000>,Mix<Int<16384>,SparkleL<Red,70,40096>,SparkleL<Red,90,1024>>,TrSmoothFade<1700>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrDelay<1588>,AlphaL<RandomPerLEDFlickerL<White>,Bump<Int<0>,Int<6000>>>,TrFade<1145>,Black,TrInstant,AlphaL<White,Int<32684>>,TrDelay<20>,AlphaL<BrownNoiseFlicker<Red,Black,50>,Int<32684>>,TrDelay<50>,AlphaL<RandomPerLEDFlickerL<Red>,Bump<Int<20000>,Int<30000>>>,TrSmoothFade<500>>,EFFECT_RETRACTION>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Blinking<Green,Black,500,500>,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
  StylePtr<Layers<
    Blinking<Red,Black,1000,500>,
    InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
  "raiden"},



// // Kachow by Bren Glen.
// // Bladestyle BC
// // Preset format for basic use, modify as needed

// { "Kachow;common", "Kachow/tracks/realgone.wav",
//   StylePtr<Layers<
//     Stripes<10000,-3000,Red,Black,Black>,
//     AlphaL<RotateColorsX<Variation,Rgb<255,150,150>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     // Force Choke / lightning
//       TransitionEffectL<TrConcat<TrSmoothFade<1000>,Rgb<80,0,0>,TrFade<1500>,StyleFire<Red,Red,0,3,FireConfig<300,2000,5>>,TrFade<400>>,EFFECT_FORCE>,
//   // Dim Blade 50% "Power Save" button combo
//       EffectSequence<EFFECT_POWERSAVE,
//           AlphaL<Black,Int<16384>>,
//           AlphaL<Black,Int<0>>>,
//   // Clash 2 - for red blades
//       TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//   // Stab - OrangeRed stripes
//       TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//   // Blast v1
//       TransitionEffectL<TrConcat<
//           // Impact Flash - BC always
//           TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//           // Waves
//           BlastL<Rgb<100,200,255>,850,250,351>,
//           // Impact point afterimage
//           //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//           AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//           // Impact point
//           //BlastL<Rgb<100,200,255>,500,350,100000>,
//           BlastL<Rgb<100,200,255>,300,350,100000>,
//   // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
//       TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//       LockupTrL<Layers<
//           //Random Strobe Flash no dimming
//           AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//           //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//           // Bottom Layer Bump - random width
//           AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
//           // Top Layer Bump - fixed width
//           AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                              Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//           // Begin Lockup Transition
//           TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,   Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//           // End Lockup Transition
//           TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//       TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                  Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//       TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//   // Non-Responsive Drag - BC custom drag fadeout
//       LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
//       LockupTrL<Layers<
//           //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
//           AlphaL<Black,Int<16000>>,
//           AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//           AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//           Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//           Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//           Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//           // Begin Lightning Transition
//           TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//           // End Lightning Transition    
//           TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Melt - BC custom melt effects, uses twistangle<>
//       LockupTrL<
//           AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//           // Melt Shape
//           SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//           // Melt Begin and End transitions
//           TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrWipeSparkTip<White,300>,BrownNoiseFlicker<Red,Black,150>,TrFade<500>,Red,TrJoin<TrWipeX<Int<400>>,TrWaveX<Rgb<255,100,0>,Int<1000>,Int<200>,Int<500>,Int<0>>>,Stripes<10000,-3000,Red,Black,Black>,TrFade<800>>,TrConcat<TrFade<300>,Red,TrJoin<TrWipeIn<1879>,TrWaveX<Rgb<255,100,0>,Int<2300>,Int<200>,Int<1879>,Int<32768>>>>>,
//     TransitionEffectL<TrConcat<TrDelay<2179>,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<500>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<900>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<1000>>,EFFECT_RETRACTION>,
// // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

//   StylePtr<Layers<
//     Blinking<Green,Black,500,500>,
//     InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
//   StylePtr<Layers<
//     Blinking<Red,Black,1000,500>,
//     InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
// "kachow"},




{ "aa_Greyscale/Galvanic_Greyscale;common;commonBU", "",
  StylePtr<Layers<
  //Base "water" blade, an edited blue lava blade
    StripesX<Sin<Int<4>,Int<800>,Int<2000>>,Scale<TwistAngle<>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<500>,Int<1500>>,Scale<TwistAngle<>,Int<25>,Int<80>>,Pulsing<RotateColorsX<Variation,Rgb<50,130,255>>,RotateColorsX<Variation,Rgb<0,73,225>>,3000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb<0,73,225>>,RotateColorsX<Variation,Rgb<80,100,150>>>>,RotateColorsX<Variation,Rgb<0,75,195>>,Pulsing<RotateColorsX<Variation,Rgb<0,56,90>>,StripesX<Sin<Int<2>,Int<900>,Int<1750>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<50,130,255>>>,RotateColorsX<Variation,Rgb<0,50,115>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<20,86,150>>,3000>>,
    AlphaL<StripesX<Sin<Int<8>,Int<800>,Int<2000>>,Scale<TwistAngle<>,Int<60>,Int<140>>,StripesX<Sin<Int<6>,Int<500>,Int<1500>>,Scale<TwistAngle<>,Int<-25>,Int<-80>>,Pulsing<Mix<Sin<Int<4>>,RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,130,255>>>,RotateColorsX<Variation,Rgb<20,100,150>>,4000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb<0,130,255>>,Black>>,RotateColorsX<Variation,Rgb<20,100,175>>,Pulsing<RotateColorsX<Variation,Rgb<0,36,80>>,StripesX<Sin<Int<2>,Int<900>,Int<1750>>,Sin<Int<2>,Int<-25>,Int<-75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,130,255>>>,RotateColorsX<Variation,Rgb<0,30,96>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<0,80,148>>,RotateColorsX<Variation,Rgb<0,16,50>>,3000>>,Int<10000>>,
  //Unstable swing
    AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<17521,5115,65535>>,Black,300>,SwingSpeed<315>>,
  //Ripple hard swing effect - swing hard enough to trigger an accent swing and cyan ripples up the top half of the blade
    AlphaL<AlphaL<Stripes<2000,-4500,RotateColorsX<Variation,Rgb16<7465,49761,65535>>,RotateColorsX<Variation,Rgb<0,36,60>>,Pulsing<RotateColorsX<Variation,Rgb<0,17,30>>,Black,800>>,Scale<IsLessThan<SwingSpeed<850>,Int<13600>>,Scale<SwingSpeed<700>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Int<13333>,Int<16000>>>,
    BC_effects_1_BlastRotate,
  // End lockup transition
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<250>,AlphaL<Strobe<White,AudioFlicker<White,Blue>,50,1>,LayerFunctions<Bump<Scale<SlowNoise<Scale<BladeAngle<24000>,Int<2100>,Int<1000>>>,Scale<BladeAngle<24000>,Int<3000>,Int<10000>>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Scale<TwistAngle<>,Int<4000>,Int<10000>>,Scale<TwistAngle<>,Int<9000>,Int<14000>>>>,Bump<Scale<SlowNoise<Int<2200>>,Scale<BladeAngle<24000>,Int<26000>,Int<18000>>,Int<8000>>,Scale<NoisySoundLevel,Scale<TwistAngle<>,Int<6000>,Int<10000>>,Scale<TwistAngle<>,Int<10000>,Int<14000>>>>,Bump<Scale<SlowNoise<Int<2300>>,Scale<BladeAngle<24000>,Int<20000>,Int<16000>>,Scale<BladeAngle<24000>,Int<30000>,Int<24000>>>,Scale<IsLessThan<SlowNoise<Int<2000>>,Int<12000>>,Scale<NoisySoundLevel,Scale<TwistAngle<>,Int<9000>,Int<5000>>,Int<0>>,Int<0>>>>>,TrFade<375>>,EFFECT_LOCKUP_END>,
  //Bright sparking emitter flare
    AlphaL<RotateColorsX<Variation,Rgb<90,180,255>>,SmoothStep<Scale<SlowNoise<Int<300>>,Int<1500>,Int<5000>>,Int<-4000>>>,
  //Sparky blast
    BlastL<SparkleL<White,750,750>,1100,250,10000>,
  //Bright humpflicker ignition effect
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<500>,HumpFlickerL<Rgb<100,100,150>,20>,TrFade<1300>,Rgb<75,80,110>,TrFade<400>>,EFFECT_IGNITION>,
  //Bright retraction effect
    TransitionEffectL<TrConcat<TrFade<1000>,Rgb<100,100,150>,TrInstant>,EFFECT_RETRACTION>,
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
   StylePtr<Layers<
    Blinking<Green,Black,500,500>,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
  StylePtr<Layers<
    Blinking<Red,Black,1000,500>,
    InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
  "galvanic"},


// { "aa_JayDalorian/LightsaberOfTheBells;common;commonBU", "",
//   StylePtr<Layers<
//     StyleFire<StripesX<Int<3000>,Scale<SlowNoise<Int<2000>>,Int<-1000>,Int<-5000>>,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,0,60>>,RotateColorsX<Variation,Rgb<0,0,10>>>,RotateColorsX<Variation,Rgb<25,25,255>>,RotateColorsX<Variation,Rgb<0,0,128>>>,RotateColorsX<Variation,Rgb<0,0,80>>,0,5,FireConfig<3,3000,0>,FireConfig<3,3000,0>,FireConfig<3,3000,0>,FireConfig<3,3000,0>>,
//     AlphaL<Stripes<2500,-3000,Red,Rgb<60,0,0>,Pulsing<Rgb<30,0,0>,Black,800>>,SwingSpeed<600>>,
//     BC_effects_1,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrDelay<1500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Blue>,30>,Bump<Int<0>,Int<3000>>>,TrFade<500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Blue>,30>,Bump<Int<0>,Int<4000>>>,TrFade<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Blue>,30>,Bump<Int<0>,Int<5000>>>,TrBoing<1950,7>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Blue>,Int<500>,Int<200>,Int<500>,Int<40>>>,TrDelay<1000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Blue>,Int<300>,Int<300>,Int<300>,Int<40>>>,TrDelay<1300>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Blue>,Int<100>,Int<400>,Int<100>,Int<32768>>>,TrDelay<2000>,AlphaL<RotateColorsX<Variation,Blue>,Bump<Int<0>,Int<6000>>>,TrBoing<1450,5>>,EFFECT_PREON>,
// // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
//    StylePtr<Layers<
//     Blinking<Green,Black,500,500>,
//     InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
//   StylePtr<Layers<
//     Blinking<Red,Black,1000,500>,
//     InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
//   "Lightsaber\nOf The Bells"},

{ "Proxima;common;commonBU", "",
//smoke blade
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<20,6,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<120,30,0>>,Black>>,RotateColorsX<Variation,Rgb<60,18,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,14,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<96,24,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,34,0>>,RotateColorsX<Variation,Rgb<5,2,0>>,3000>>,
    AlphaL<StyleFire<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<2,1,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
    TransitionEffectL<TrConcat<TrFade<400>,Blinking<Rgb<60,0,0>,Strobe<Red,Black,15,30>,60,500>,TrDelay<499>,Blinking<Rgb<60,0,0>,Strobe<Red,Black,15,30>,60,500>,TrFade<800>>,EFFECT_FORCE>,
    BC_effects_Red,
    InOutTrL<TrColorCycle<4200>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<201>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
   StylePtr<Layers<
    Blinking<Green,Black,500,500>,
    InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
  StylePtr<Layers<
    Blinking<Red,Black,1000,500>,
    InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
  "proxima"},


  // { "aa_KSith/Induction;common;commonBU", "tracks/darkrey.wav",
//   StylePtr<Layers<
//     StripesX<Int<5000>,Int<-1500>,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb<0,30,60>>,RotateColorsX<Variation,Rgb<50,50,255>>,RotateColorsX<Variation,Rgb<0,80,128>>>,
//     AlphaL<White,Bump<Int<0>,Int<8000>>>,
//     BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,450>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//     >>(),
//   StylePtr<Layers<
//     Blinking<Green,Black,500,500>,
//     InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
//   StylePtr<Layers<
//     Blinking<Red,Black,1000,500>,
//     InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
// "induction"},

// { "aa_Blueforce/Dangerous;common;commonBU", "tracks/order66.wav",
//   StylePtr<Layers<
//     StripesX<Int<5000>,Int<-1500>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,50,0>>,RotateColorsX<Variation,Tomato>>,
//     AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,50>,Bump<Int<0>,Int<8000>>>,
//     BC_effects_Red,
//     InOutTrL<TrJoinR<TrColorCycle<1900,0,3000>,TrJoin<TrWipe<500>,TrWaveX<White,Int<800>,Int<400>,Int<500>,Int<0>>>>,TrJoin<TrColorCycle<800,1000,300>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<400>,Percentage<WavLen<EFFECT_RETRACTION>,90>,Int<32768>>>>>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlickerL<Rgb<255,100,100>>,Bump<Int<0>,Int<8000>>>,TrDelay<600>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// >>(),
//   StylePtr<Layers<
//     Blinking<Green,Black,500,500>,
//     InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
//   StylePtr<Layers<
//     Blinking<Red,Black,1000,500>,
//     InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
// "dangerous"},

// { "aa_KSith/Ascension;common;commonBU", "tracks/battleofheros.wav",
//   StylePtr<Layers<
//     StripesX<Int<3000>,Int<-3000>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,60>>,RotateColorsX<Variation,Rgb<50,50,255>>,RotateColorsX<Variation,Rgb<0,0,128>>>,
//     AlphaL<Rgb<100,100,255>,SwingSpeed<600>>,
//     BC_effects_1,
//     InOutTrL<TrJoinR<TrWipeSparkTip<White,1000>,TrColorCycle<2000,0,3000>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//     >>(),
//   StylePtr<Layers<
//     Blinking<Green,Black,500,500>,
//     InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
//   StylePtr<Layers<
//     Blinking<Red,Black,1000,500>,
//     InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
// "ascension"},

// { "aa_KSith/Proto;common;commonBU", "tracks/order66.wav",
//   StylePtr<Layers<
//     RandomBlink<30000>,
//     Mix<SwingSpeed<400>,AlphaL<Black,Int<0>>,RotateColorsX<Variation,Rgb<150,150,225>>>,
//     AlphaL<RotateColorsX<Variation,Rgb<35,35,75>>,Int<10000>>,
//     BC_effects_1,
//     InOutTrL<TrWipeSparkTipX<White,Int<800>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//     TransitionEffectL<TrConcat<TrFade<500>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,Int<1000>,Int<6000>>,Int<-3000>>,Black,RandomBlink<30000>>,TrDelay<100>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//     >>(),
//   StylePtr<Layers<
//     Blinking<Green,Black,500,500>,
//     InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
//   StylePtr<Layers<
//     Blinking<Red,Black,1000,500>,
//     InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
// "proto"},

// { "aa_Blueforce/IgnitionUltimate;common;commonBU", "tracks/duelofthefates.wav",
//   StylePtr<Layers<
//     Stripes<2000,-2500,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<30,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<30,0,0>>>>,
//     TransitionLoopL<TrConcat<TrWaveX<RandomFlicker<RotateColorsX<Variation,Red>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,Black,300>>,Int<400>,Int<100>,Int<200>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1500>>,Int<200>,Int<1200>>>>>,
//     AlphaL<BrownNoiseFlicker<Red,Black,300>,SwingSpeed<400>>,
//   // Auto 50% bladae dim base blade color when low battery. Effects remain bright.
//     AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
//     BC_effects_1,
//     TransitionEffectL<TrConcat<TrDelay<150>,AlphaL<Black,Int<0>>,TrFade<500>,AlphaL<Strobe<White,Black,40,40>,Bump<Int<0>,Int<80000>>>,TrDelay<350>>,EFFECT_RETRACTION>,
//     // Cooling tip - meh
//     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>,
//   InOutTrL<
//     TrConcat<TrInstant,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrWipe<300>,Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,Black,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<255,20,0>>,White>,RotateColorsX<Variation,Rgb<128,34,0>>>,TrFade<300>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,TrBoing<300,3>>,
//     TrConcat<TrInstant,BrownNoiseFlicker<White,DarkOrange,300>,TrFade<250>,AlphaL<Black,Int<0>>,TrJoin<TrWipeInX<Int<850>>,TrWaveX<White,Int<800>,Int<400>,Int<850>,Int<32768>>>>>,
// // Comment out this following line for non-stutter on actual ignition
//   //TransitionEffectL<TrConcat<TrWaveX<White,Int<800>,Int<200>,Int<300>,Int<0>>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrDelay<650>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrDelay<100>,BrownNoiseFlicker<White,Red,70>,TrFade<500>,Black,TrInstant>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrDelay<1100>,AlphaL<White,Bump<Int<0>,Int<66000>>>,TrDelay<25>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<
//       TrInstant,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrFade<100>,Black,
//       TrDelay<50>,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<50000>>>,TrDelay<150>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<70000>>>,TrFade<150>,Black,
//       TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<400>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<450>,Black,
      
//       TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<70000>>>,TrDelay<250>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<50000>>>,TrFade<200>,Black,
//       TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<500>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<600>,Black,

//       TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<10000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<5000>>>,TrFade<150>,Black,
//       TrDelay<350>,Black,
//       TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<10000>>>,TrDelay<70>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<5000>>>,TrFade<40>,Black,
//       TrDelay<20>,Black,

//       TrInstant,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrDelay<50>,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrFade<50>,Black,
//       TrDelay<50>,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<50000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<70000>>>,TrFade<150>,Black,
//       TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<300>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<400>,

//       AlphaL<BrownNoiseFlicker<White,Red,100>,Bump<Int<0>,Int<10000>>>,
//       TrFade<175>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<20000>>>,TrFade<175>,AlphaL<BrownNoiseFlicker<White,Red,100>,Bump<Int<0>,Int<10000>>>,
//       TrFade<115>,AlphaL<BrownNoiseFlicker<White,DarkOrange,100>,Bump<Int<0>,Int<40000>>>,TrFade<115>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<20000>>>,
//       TrFade<100>,AlphaL<BrownNoiseFlicker<White,DarkOrange,100>,Bump<Int<0>,Int<60000>>>,TrFade<100>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<40000>>>,
//       TrFade<75>,BrownNoiseFlicker<White,DarkOrange,300>,TrFade<50>,Black,TrFade<50>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Rgb<200,150,150>,20>,
//       TrSmoothFade<100>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//     >>(),
//   StylePtr<Layers<
//     Blinking<Green,Black,500,500>,
//     InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
//   StylePtr<Layers<
//     Blinking<Red,Black,1000,500>,
//     InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
// "ignition\nultimate"},


// { "aa_Kyberphonic/DeathStar;common;commonBU", "aa_Kyberphonic/DeathStar/tracks/track3.wav",
//   StylePtr<Layers<
//     StripesX<Int<3500>,Int<-3000>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,60,0>>,RotateColorsX<Variation,Rgb<50,255,50>>,RotateColorsX<Variation,Rgb<0,128,0>>>,
//     BC_effects_1,
//     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<150,255,150>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,60,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<150,255,150>>,RotateColorsX<Variation,Rgb<0,60,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,60,0>>>>,TrFade<1200>>,EFFECT_IGNITION>,
//     InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//     TransitionEffectL<TrConcat<
//       TrWipe<50>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,60,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrDelay<100>,
//       AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,128,0>>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrWipe<50>,
//       AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,190,0>>,30>,SmoothStep<Int<6000>,Int<-500>>>,TrDelay<100>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//     >>(),
//   StylePtr<Layers<
//     Blinking<Green,Black,500,500>,
//     InOutTrL<TrFade<300>,TrFade<300>,Pulsing<Black,Rgb<180,130,0>,3000>>>>(),
//   StylePtr<Layers<
//     Blinking<Red,Black,1000,500>,
//     InOutTrL<TrInstant,TrInstant,Blinking<Red,Black,2000,500>>>>(),
//   "death\nstar"}

};

BladeConfig blades[] = {
 { 0, WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // BC_A 123
    WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
    WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >()
  , CONFIGARRAY(VenZallow) }
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
#endif

