// BC_SinisterProphecy_8.x

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 1

// ------ Audio Stuff --------

#define VOLUME 1800
#define BOOT_VOLUME 300
#define ENABLE_AUDIO
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8
#define ENABLE_FASTON

// ------ Blade Stuff ------

const unsigned int maxLedsPerStrip = 144;
#define DYNAMIC_BLADE_LENGTH
#define SHARED_POWER_PINS

// ------ SD Card Stuff -------

// #define MOUNT_SD_SETTING
#define SAVE_COLOR_CHANGE

// ------ System Stuff --------

#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define CONFIG_STARTUP_DELAY 3000
// #define PROFFIEOS_LOG_LEVEL 500

// ------- Motion and Gesture stuff -------

#define CLASH_THRESHOLD_G 3.5
#define ENABLE_SPINS
#define BC_SWING_ON
#define BC_SWING_ON_SPEED 600 // Default 250
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

#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"
#include "aliases/TrueWhites/BC_effects_2.h"
#include "aliases/TrueWhites/BC_effects_Red.h"
// #include "aliases/TrueWhites/BC_effects_White.h"

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

/* ---- Presets list ---- /*

a_INQUISITOR/2ndSistr
a_INQUISITOR/9thSistr
a_BANE/TheBane w/ice monosfx
// a_BANE/RuleOfTwo
a_SIDIOUS/TheReturn
a_ASAJJ/NiteSist
a_DOOKU/Duke // Matched Preons/outs
a_DOOKU/Dooku_CW
a_SAVAGE/Savage_Opress
a_DARTH_MAUL/CrimsonMenace
a_INQUISITOR/RevaUltimate
aa_Syndicate/SithChant // ------------- check it
a_STARKILLER/Secret_Apprentice w/ice monosfx - broken out fx because force choke anim
aa_KSith/Aggression w/ colorchange 2 colors
a_KYLO/KyloUltimate
a_REY/Empress
a_VADER/Father_V2/ANH
aa_Greyscale/Seethe_Greyscale
aa_Juansith/HATE
aa_Blueforce/IgnitionUltimate
aa_HarrySolo/AGONY
aa_KSith/Proto
aa_KSith/Desolation
aa_KSith/Ascension
Arcane
aa_KSith/Traveler
GhostsOfTheGrey
aa_LordBlako/PitchBlk
a_PONG_KRELL/PongKrll
Proto2
PsyBorg
a_DARKSABER/DarkV3
aa_Blueforce/LiquidStatic
*/



Preset Sinister [] = {
 
{ "a_INQUISITOR/2ndSistr;common;commonBU", "tracks/FallenOrderTracks/JFO5.wav",
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Red>,AudioFlicker<Yellow,Red>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"second\nsister"},



{ "a_INQUISITOR/9thSistr;common;commonBU", "tracks/FallenOrderTracks/JFO7.wav",
//Second Sister Base Red
  StylePtr<Layers<
Mix<SwingSpeed<500>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<150,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<180,0,0>>,0,2,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Red>,AudioFlicker<Yellow,Red>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"ninth\nsister"},



{ "a_BANE/TheBane;common;commonBU", "a_BANE/tracks/track2.wav", // AudioFlicker Red Base Color Wheel Changeable
   
  StylePtr<Layers<
    AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
        // Ice Force
    TransitionEffectL< 
      TrConcat<TrFade<7000>,Rgb<10,0,75>,// blade turns solid cold 1000ms before ice full coverage
      TrDelay<1000>>,EFFECT_USER2>,  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to Base color
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
    // Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
        AlphaL<Black,Int<16384>>,
        AlphaL<Black,Int<0>>>,
    // Clash 2 - for red blades
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
    // Stab - OrangeRed stripes
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
    // Blast v1
    TransitionEffectL<TrConcat<
        // Impact Flash - BC always
        TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
        // Waves
        BlastL<Rgb<100,200,255>,850,250,351>,
        // Impact point afterimage
        //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
        AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
        // Impact point
        //BlastL<Rgb<100,200,255>,500,350,100000>,
        BlastL<Rgb<100,200,255>,300,350,100000>,
    // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
        //Random Strobe Flash no dimming
        AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
        //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<2>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
        // Bottom Layer Bump - random width
        AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
        // Top Layer Bump - fixed width
        AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                              Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
        // Begin Lockup Transition
        TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,   Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
        // End Lockup Transition
        TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                  Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
    // Non-Responsive Drag - BC custom drag fadeout
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
    LockupTrL<Layers<
       //Random Strobe Flash and 16000 = 50% Base blade dimming to make lb pop
        AlphaL<Black,Int<16000>>,
        AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
        AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
        Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
        // Begin Lightning Transition
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
        // End Lightning Transition    
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    // Melt - BC custom melt effects, uses twistangle<>
    LockupTrL<
        AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
        // Melt Shape
        SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
        // Melt Begin and End transitions
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>, 
// standard
    // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"the\nbane"},



// { "a_BANE/RuleOfTwo;common;commonBU", "a_BANE/tracks/track3.wav", // AudioFlicker Red Base Color Wheel Changeable
   
//   StylePtr<Layers<
//     AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//     BC_effects_Red, 
// // standard
//     // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// // Crystal Chamber
//   StylePtr<Layers<
//     // Sith Crystal Red
//     Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
//     // Sith Force Red
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
//     BC_effects_2,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
//   >>(),
// "rule of\ntwo"},



{ "a_SIDIOUS/TheReturn;common;commonBU", "tracks/Palpatheme_SHORT.wav",
  StylePtr<Layers<
    Mix<SwingSpeed<500>,AudioFlicker<Gradient<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red>,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,
    BC_effects_Red,       
      InOutTrL<TrConcat<TrWipe<200>,Strobe<Black,Rgb<100,100,155>,45,60>,TrJoinR<TrSmoothFade<190>,TrWipe<200>>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),    
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"the return\nof the sith"},



{ "a_ASAJJ/NiteSist;common;commonBU", "tracks/Sister1.wav",
  StylePtr<Layers<
    HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Red>,AudioFlicker<Yellow,Red>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"assaj\nventress"}, 




{ "a_DOOKU/Duke;common;commonBU", "a_DOOKU/tracks/Duke1_Short.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Red>,AudioFlicker<Yellow,Red>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"dooku"},



{ "a_DOOKU/Dooku_CW;common;commonBU", "a_DOOKU/tracks/Duke2_Short.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,BrownNoiseFlickerL<Rgb<100,50,50>,Int<100>>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Rgb<100,50,50>>,TrFade<500>>,EFFECT_RETRACTION>,
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    // AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Red>,AudioFlicker<Yellow,Red>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"clone wars\ndooku"}, 



{ "a_SAVAGE/Savage_Opress;common;commonBU", "tracks/Sister2_short.wav",
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    // AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Red>,AudioFlicker<Yellow,Red>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"savage\nopress"},



{ "a_DARTH_MAUL/CrimsonMenace;common;commonBU", "a_DARTH_MAUL/tracks/Maul_Solo_Theme.wav", // AudioFlicker Red Base Color Wheel Changeable
   
  StylePtr<Layers<
    AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
    BC_effects_Red, 
// standard
    // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"darth\nmaul"},



{ "a_INQUISITOR/RevaUltimate;common;commonBU", "tracks/FallenOrderTracks/JFO9.wav",
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<600>>,EFFECT_IGNITION>,
    InOutTrL<TrWipeSparkTip<Rgb<200,100,100>,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Red>,AudioFlicker<Yellow,Red>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"reva\nultimate"},



{ "aa_Syndicate/SithChant;common;commonBU", "aa_Syndicate/SithChant/tracks/music_from_the_dark_side_edit.wav",
  StylePtr<Layers<
    Stripes<6000,-3000,RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<150,0,0>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Rgb<128,128,128>>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Red,Black,500>,TrJoin<TrFade<1000>,TrWipe<800>>>,EFFECT_IGNITION>,
    AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<228,128,128>,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
    // AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Red>,AudioFlicker<Yellow,Red>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"sith\nchant"},



{ "a_STARKILLER/Secret_Apprentice;common;commonBU", "a_STARKILLER/tracks/SKT4.wav", // AudioFlicker Red Base Color Wheel Changeable
   
  StylePtr<Layers<
    AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
        // Ice Force
    TransitionEffectL< 
      TrConcat<TrFade<7000>,Rgb<10,0,75>,// blade turns solid cold 1000ms before ice full coverage
      TrDelay<1000>>,EFFECT_USER2>,  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to Base color
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
    // Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
        AlphaL<Black,Int<16384>>,
        AlphaL<Black,Int<0>>>,
    // Clash 2 - for red blades
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
    // Stab - OrangeRed stripes
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
    // Blast v1
    TransitionEffectL<TrConcat<
        // Impact Flash - BC always
        TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
        // Waves
        BlastL<Rgb<100,200,255>,850,250,351>,
        // Impact point afterimage
        //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
        AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
        // Impact point
        //BlastL<Rgb<100,200,255>,500,350,100000>,
        BlastL<Rgb<100,200,255>,300,350,100000>,
    // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
        //Random Strobe Flash no dimming
        AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
        //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<2>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
        // Bottom Layer Bump - random width
        AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
        // Top Layer Bump - fixed width
        AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                              Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
        // Begin Lockup Transition
        TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,   Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
        // End Lockup Transition
        TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                  Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
    // Non-Responsive Drag - BC custom drag fadeout
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
    LockupTrL<Layers<
       //Random Strobe Flash and 16000 = 50% Base blade dimming to make lb pop
        AlphaL<Black,Int<16000>>,
        AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
        AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
        Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
        // Begin Lightning Transition
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
        // End Lightning Transition    
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    // Melt - BC custom melt effects, uses twistangle<>
    LockupTrL<
        AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
        // Melt Shape
        SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
        // Melt Begin and End transitions
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>, 
// standard
    // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"starkiller"},



{ "aa_KSith/Aggression;common;commonBU", "tracks/FallenOrderTracks/JFO11a.wav", // colorchange 2 colors
  StylePtr<Layers<
    ColorChange<TrWipe<500>,StyleFire<BrownNoiseFlicker<Rgb<95,0,210>,RandomPerLEDFlicker<Rgb<42,0,105>,Rgb<21,0,52>>,300>,Rgb<10,0,26>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,StyleFire<Red,Rgb<60,0,0>,0,6,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>>,TrFade<1200>>,EFFECT_IGNITION>,
// standard
    // InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<100,200,255>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    ColorChange<TrWipe<500>,StyleFire<BrownNoiseFlicker<Rgb<95,0,210>,RandomPerLEDFlicker<Rgb<42,0,105>,Rgb<21,0,52>>,300>,Rgb<10,0,26>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,StyleFire<Red,Rgb<60,0,0>,0,6,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"starkiller"},



{ "a_KYLO/KyloUltimate;common;commonBU", "a_KYLO/KyloUltimate/tracks/Kylo1.wav",
  StylePtr<Layers<
    StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,150,150>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
    InOutTrL<TrWipe<400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"kylo\nultimate"},    



{ "a_REY/Empress;common;commonBU", "a_REY/tracks/DarkReyBC.wav",
  StylePtr<Layers<
    HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
    InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Red>,AudioFlicker<Yellow,Red>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"empress"}, 



{ "a_VADER/Father_V2/ANH;common;commonBU", "a_VADER/Father_V2/tracks/track1.wav",
  StylePtr<Layers<
    AudioFlicker<Red,Rgb<128,0,0>>,
    BC_effects_Red,
    InOutTrL<TrWipe<1000>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"father_v2\nanh"},



{ "aa_Greyscale/Seethe_Greyscale;common;commonBU", "",
  StylePtr<Layers<
  // Red audioflicker
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,0,0>>>,
  // Force effect, temporarily allows a swing effect where solid dark orange takes over the blade when swinging
    TransitionEffectL<TrConcat<TrFade<200>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,SwingSpeed<500>>,TrDelay<30000>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,SwingSpeed<500>>,TrFade<800>>,EFFECT_FORCE>,
  // Unstable swing
    AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>,SwingSpeed<315>>,
  // Timed "breathing" emitter flare
    Mix<Sin<Int<8>>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,Bump<Int<0>,Int<6000>>>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,Bump<Int<0>,Int<22000>>>>,
    BC_effects_Red,
// standard
  // Wipe out ignition, wipe in retraction
    // InOutTrL<TrWipe<2650>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// bend with surge
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"seethe"},


{ "aa_Juansith/HATE;common;commonBU", "",
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Switch
  StylePtr<Layers<
    Rgb<100,100,100>,
    InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
  >>(),
"hate"},



{ "aa_Blueforce/IgnitionUltimate;common;commonBU", "",
StylePtr<Layers<
  Stripes<2000,-2500,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<30,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<30,0,0>>>>,
  TransitionLoopL<TrConcat<TrWaveX<RandomFlicker<RotateColorsX<Variation,Red>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,Black,300>>,Int<400>,Int<100>,Int<200>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1500>>,Int<200>,Int<1200>>>>>,
  AlphaL<BrownNoiseFlicker<Red,Black,300>,SwingSpeed<400>>,
  BC_effects_Red,
  InOutTrL<
    TrConcat<TrInstant,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrWipe<300>,Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,Black,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<255,20,0>>,White>,RotateColorsX<Variation,Rgb<128,34,0>>>,TrFade<300>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,TrBoing<300,3>>,
    TrConcat<TrInstant,BrownNoiseFlicker<White,DarkOrange,300>,TrFade<250>,AlphaL<Black,Int<0>>,TrJoin<TrWipeInX<Int<850>>,TrWaveX<White,Int<800>,Int<400>,Int<850>,Int<32768>>>>>,
// Comment out this following line for non-stutter on actual ignition
  //TransitionEffectL<TrConcat<TrWaveX<White,Int<800>,Int<200>,Int<300>,Int<0>>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrDelay<650>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrDelay<100>,BrownNoiseFlicker<White,Red,70>,TrFade<500>,Black,TrInstant>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrDelay<1100>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<50>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<
    TrInstant,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrFade<100>,Black,
    TrDelay<50>,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<50000>>>,TrDelay<150>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<70000>>>,TrFade<150>,Black,
    TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<400>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<450>,Black,
    
    TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<70000>>>,TrDelay<250>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<50000>>>,TrFade<200>,Black,
    TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<500>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<600>,Black,

    TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<10000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<5000>>>,TrFade<150>,Black,
    TrDelay<350>,Black,
    TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<10000>>>,TrDelay<70>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<5000>>>,TrFade<40>,Black,
    TrDelay<20>,Black,

    TrInstant,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrDelay<50>,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrFade<50>,Black,
    TrDelay<50>,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<50000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<70000>>>,TrFade<150>,Black,
    TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<300>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<400>,

    AlphaL<BrownNoiseFlicker<White,Red,100>,Bump<Int<0>,Int<10000>>>,
    TrFade<175>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<20000>>>,TrFade<175>,AlphaL<BrownNoiseFlicker<White,Red,100>,Bump<Int<0>,Int<10000>>>,
    TrFade<115>,AlphaL<BrownNoiseFlicker<White,DarkOrange,100>,Bump<Int<0>,Int<40000>>>,TrFade<115>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<20000>>>,
    TrFade<100>,AlphaL<BrownNoiseFlicker<White,DarkOrange,100>,Bump<Int<0>,Int<60000>>>,TrFade<100>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<40000>>>,
    TrFade<75>,BrownNoiseFlicker<White,DarkOrange,300>,TrFade<50>,Black,TrFade<50>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Rgb<200,150,150>,20>,
    TrSmoothFade<100>>,EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Switch
  StylePtr<Layers<
    Rgb<100,100,100>,
    InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
  >>(),
"ignition\nultimate"},


{ "aa_HarrySolo/AGONY;common;commonBU", "",
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
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"agony"},


{ "aa_KSith/Proto;common;commonBU", "",
  StylePtr<Layers<
// Main Blade
    // Jedi Base Orange
    StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,DarkOrange>,Pulsing<RotateColorsX<Variation,Rgb<90,24,0>>,RotateColorsX<Variation,DarkOrange>,800>,RotateColorsX<Variation,DarkOrange>>,
    // Jedi Force Orange
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<160,43,0>>>,TrDelay<3000>,RotateColorsX<Variation,DarkOrange>,TrFade<800>>,EFFECT_FORCE>,
    // Jedi Swing Orange
    AlphaL<RotateColorsX<Variation,Rgb<255,178,110>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    BC_effects_1,
// Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Jedi Base Red
    Stripes<1000,-2000,RotateColorsX<Variation,DarkOrange>,Pulsing<RotateColorsX<Variation,Rgb<90,24,0>>,RotateColorsX<Variation,DarkOrange>,800>,RotateColorsX<Variation,DarkOrange>>,
    // Jedi Force Orange
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<160,43,0>>>,TrDelay<3000>,RotateColorsX<Variation,DarkOrange>,TrFade<800>>,EFFECT_FORCE>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"proto"},




{ "aa_KSith/Desolation;common", "tracks/FallenOrderTracks/JFO12.wav",
  StylePtr<Layers<
// Main Blade
    // Jedi base Yellow
    StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<180,180,0>>,Pulsing<RotateColorsX<Variation,Rgb<64,64,0>>,RotateColorsX<Variation,Rgb<180,180,0>>,800>,RotateColorsX<Variation,Rgb<180,180,0>>>,
    // Jedi Force Yellow
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<113,113,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<180,180,0>>,TrFade<800>>,EFFECT_FORCE>,
    // Jedi Swing Yellow
    AlphaL<RotateColorsX<Variation,Rgb<230,180,80>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_Red,
// Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Yellow,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Switch
  StylePtr<Layers<
    Rgb<100,100,100>,
    InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
  >>(),
"desolation"},




{ "aa_KSith/Ascension;common;commonBU", "tracks/battleofheros.wav",
  StylePtr<Layers<
    StripesX<Int<3000>,Int<-3000>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,60>>,RotateColorsX<Variation,Rgb<50,50,255>>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    AlphaL<Rgb<100,100,255>,SwingSpeed<600>>,
    BC_effects_1,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<100,200,255>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Switch
  StylePtr<Layers<
    Rgb<100,100,100>,
    InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
  >>(),
"ascension"},



// { "Arcane;common;commonBU", "",
//   StylePtr<Layers<
//     HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// // Crystal Chamber
//   StylePtr<Layers<
//     // Sith Crystal Red
//     Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
//     // Sith Force Red
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<White,Red>,AudioFlicker<Yellow,Red>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
//   >>(),
// "arcane"}, 



// { "aa_KSith/Traveler;common;commonBU", "tracks/FallenOrderTracks/JFO3.wav",
//   StylePtr<Layers<
//     Mix<SwingSpeed<500>,AudioFlicker<Gradient<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red>,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,
//     BC_effects_Red,       
//     InOutTrL<TrConcat<TrWipe<200>,Strobe<Black,Rgb<100,100,155>,45,60>,TrJoinR<TrSmoothFade<190>,TrWipe<200>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// // Crystal Chamber
//   StylePtr<Layers<
//     // Sith Crystal Red
//     Stripes<1000,-2000,Red,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,Black>,
//     // Sith Force Red
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
//     BC_effects_2,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
//   >>(),
// "traveler"},




// { "GhostsOfTheGrey;common;commonBU", "", 
//   StylePtr<Layers<
//     StripesX<Int<6000>,Int<-1000>,RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<24,24,35>>>,AlphaL<White,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     AlphaL<Stripes<4000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Black>,White,RotateColorsX<Variation,Rgb<100,100,150>>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     BC_effects_White,  
//     InOutTrL<TrWipe<400>,TrConcat<TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,50>>,Stripes<3000,2000,White,Rgb<100,100,100>>,TrFadeX< Percentage<WavLen<EFFECT_RETRACTION>,50> >>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// // Crystal Chamber
//   StylePtr<Layers<Black,
//     AlphaL<StrobeX<Black,White,Scale<SlowNoise<Int<1000>>,Int<0>,Int<4>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>,Int<16000>>,
//     BC_effects_2,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<StripesX<Int<6000>,Int<-200>,RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<24,24,35>>>,Black,2000>,Black>>
//   >>(),
// "ghosts of\nthe grey"},   


{ "aa_LordBlako/PitchBlk;common;commonBU", "tracks/MSV.wav",

//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,Black>,300>,RotateColorsX<Variation,Rgb<40,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,AudioFlicker<RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Rgb<20,0,0>>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Rgb<100,200,255>>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Rgb<100,200,255>,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<100,200,255>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
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
// Crystal Chamber
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Red,Black,2500>>>>(),
"pitch\nblack"},



// { "a_PONG_KRELL/PongKrll;common;commonBU", "a_PONG_KRELL/tracks/Krell.wav",
//   StylePtr<Layers<
//     Pulsing<Yellow,Chartreuse,20>,
//     BC_effects_1,
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// // Switch
//   StylePtr<Layers<
//     Rgb<100,100,100>,
//     InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
//   >>(),
//   "pong\nkrell"},


// { "Proto2;common;commonBU", "Proto2/tracks/proto2.wav", // Color Cycle to Glitchy Pulsing Blade Default = Green
//   StylePtr<Layers<   
//       ColorCycle<RotateColorsX<Variation,Rgb<0,128,0>>,100,-3250,RotateColorsX<Variation,BlinkingX<RandomFlicker<RandomBlink<13000,RotateColorsX<Variation,Rgb<128,200,128>>,RotateColorsX<Variation,Black>>,RotateColorsX<Variation,Green>>,RandomFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<30,30,30>>>,Scale<SlowNoise<Int<16000>>,Int<300>,Int<1000>>,Scale<SlowNoise<Int<16000>>,Int<200>,Int<650>>>>,50,3000,3000>,
//       BC_effects_1,
//       TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//       TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//       InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// // Crystal Chamber
//   StylePtr<Layers<
//     RandomFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<30,30,30>>>,
//     BC_effects_2,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<RandomFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<30,30,30>>>,Black,2500>>>>(),
// "proto 2"},




{ "PsyBorg;common;commonBU", "tracks/FallenOrderTracks/JFO7.wav",
  StylePtr<Layers<
// Main Blade - variation applied 21844 (green)
    // Jedi base Blue
StripesX<Int<16000>,Int<-1000>,RotateColorsX<Int<21844>,Blue>,Pulsing<RotateColorsX<Int<21844>,Rgb<0,0,90>>,RotateColorsX<Int<21844>,Blue>,800>,RotateColorsX<Int<21844>,Blue>>,
    // Jedi Force Blue
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    // Jedi Swing Blue
    AlphaL<RotateColorsX<Variation,Rgb<70,70,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_1,
// Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Switch
  StylePtr<Layers<
    Rgb<100,100,100>,
    InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
  >>(),
"psyborg"},



// { "a_DARKSABER/DarkV3;common;commonBU", "a_DARKSABER/DarkV3/tracks/Mandalorian.wav",
//   StylePtr<Layers<
//     Mix<SwingSpeed<400>,RotateColorsX<Variation,Rgb<80,100,150>>,RotateColorsX<Variation,Rgb<130,150,225>>>,
//     BrownNoiseFlickerL<Stripes<5000,-300,RotateColorsX<Variation,Rgb<15,25,55>>,RotateColorsX<Variation,Rgb<60,75,120>>,RotateColorsX<Variation,Rgb<0,10,20>>,RotateColorsX<Variation,Rgb<40,50,75>>>,Int<38400>>,
//     AudioFlickerL<RotateColorsX<Variation,Rgb<25,35,75>>>,
//     AlphaL<RotateColorsX<Variation,Rgb<155,175,225>>,SwingSpeed<600>>,
//     BC_effects_White,
//    // InOutTrL<TrWipeSparkTipX<White,BendTimePowInvX<Int<1000>,Int<180000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//      // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// // Switch
//   StylePtr<Layers<
//     Rgb<100,100,100>,
//     InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
//   >>(),
// "   dark\n    v3"},



// { "aa_Blueforce/LiquidStatic;common;commonBU", "",
//   StylePtr<Layers<
//     StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Blue,Mix<Int<2570>,Black,Blue>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Blue>,Black>>,Mix<Int<7710>,Black,Blue>,Pulsing<Mix<Int<6425>,Black,Blue>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Blue,Mix<Int<12000>,Black,Blue>>,2000>,Pulsing<Mix<Int<16448>,Black,Blue>,Mix<Int<642>,Black,Blue>,3000>>,
//     AlphaL<StaticFire<Blue,Mix<Int<256>,Black,Blue>,0,1,10,2000,2>,Int<10000>>,
//     AlphaL<LightCyan,SmoothStep<Int<2000>,Int<-6000>>>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1200>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Blue,RandomPerLEDFlicker<Mix<Int<7710>,Black,Blue>,Black>,BrownNoiseFlicker<Blue,Mix<Int<3855>,Black,Blue>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Blue>,Mix<Int<3855>,Black,Blue>>>,TrInstant>,EFFECT_RETRACTION>,
//     BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTipX<LightCyan,WavLen<EFFECT_RETRACTION>,Int<401>>>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// // Switch
//   StylePtr<Layers<
//     Rgb<100,100,100>,
//     InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
//   >>(),
// "liquid\nstatic"},

};


BladeConfig blades[] = {
{ 123,    // CTB? NEED Main Blade for this hilt D1_data_line = proffie_D1---> KimCanamaCC_PCB ctrpin parallel to onboards---> bladePCB 330ohm--->Main blade strips
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin4, bladePowerPin5> >(),                                   // Main Blade
  WS281XBladePtr<4, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4, bladePowerPin5> >(),                                    // Enclosed Chamber
CONFIGARRAY(Sinister), 
"01_Sinister_save"}, 

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

// // Button connect to 3.3v instead of GND. Up to 5v is OK
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

