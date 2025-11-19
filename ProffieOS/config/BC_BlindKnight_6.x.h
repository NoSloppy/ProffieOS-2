// BC_BlindKnight_6.x Kanan Jarrus
// Sketch uses 83%
// AudioFlicker<Rgb16<5845,16975,65535>,Blue>

#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 1
#define VOLUME 1600
#define BOOT_VOLUME 100
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define SAVE_STATE
#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
#define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 1 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
#define VOLUME_MENU_CYCLE
#define NO_REPEAT_RANDOM

// ------- Gesture stuff -------

//#define BC_SWING_ON
//#define BC_STAB_ON
#define BC_THRUST_ON
//#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 8
#define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS 
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200

// ------- Custom / Experimental stuff ---------

#define DISABLE_BASIC_PARSER_STYLES               // Standard, Advanced, etc...
#define ENABLE_AUTO_SPINS_BLAST                   // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8

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

Preset dume[] = {


{ "a_KANAN/BlndNite;common;commonBU", "tracks/Kanan2.wav",
  StylePtr<Layers<
	  // AudioFlicker<Rgb16<5845,16975,65535>,Blue>,
    BC_12color_8effect_SS, // 1. AudioFlicker 8.DeepSkyBlue
    BC_effects_1,
		InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "blind\nknight"
},

{ "a_KANAN/BlndCwby;common;commonBU", "tracks/Kanan.wav",
 	StylePtr<Layers<
    // AudioFlicker<Rgb16<5845,16975,65535>,Blue>,
    BC_12color_8effect_SS, // 1. AudioFlicker 8.DeepSkyBlue
    BC_effects_1,
		InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "blind\ncowboy"
},

{ "a_EZRA/StapleSword;common;commonBU", "tracks/EzraTheme.wav",
	StylePtr<Layers<
	  // AudioFlicker<Rgb<0,200,0>,Rgb16<11805,52226,29351>>,
    BC_12color_8effect_SS, // 1. AudioFlicker 9.Blue
    BC_effects_1,
    InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // On-Demand Battery Level
  AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "staple\nsword"
},

{ "a_KANAN/BlindMaster;common;commonBU", "tracks/Kanan.wav",
  StylePtr<Layers<
	  // AudioFlicker<Rgb<0,20,128>,Blue>,
    BC_12color_8effect_SS, // 1. AudioFlicker 9.Blue
	  BC_effects_1,
		InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "blind\nmaster"
},

{ "a_KANAN/CalbDume;common;commonBU", "tracks/Kanan.wav",
 	StylePtr<Layers<
    // AudioFlicker<Rgb<0,60,200>,Blue>,
    BC_12color_8effect_SS, // 1. AudioFlicker 9.Blue
	  BC_effects_1,
		InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "caleb\ndume"
},

{ "a_AHSOKA/AhsokaUltimate;common;commonBU", "a_AHSOKA/AhsokaUltimate/tracks/ItsOverNow.wav", // AudioFlicker Bright Swing Color Wheel Changeable - Default = Silver White
  StylePtr<Layers<
    Mix<SwingSpeed<500>,AudioFlicker<RotateColorsX<Variation,Rgb<110,150,255>>,RotateColorsX<Variation,Rgb<80,90,130>>>,Mix<SwingSpeed<800>,AudioFlicker<RotateColorsX<Variation,Rgb<110,150,255>>,RotateColorsX<Variation,White>>,RotateColorsX<Variation,White>>>,
    BC_effects_White,
    InOutTrL<TrWipeSparkTip<White,400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "ahsoka\nultimate"
},

{ "a_INQUISITOR/GrandHunter;common;commonBU", "tracks/RebelsTheme.wav",
/*------------------ Responsive RealFlame Red ---------------------
copyright Fett263 ResponsiveFlame (Primary Blade) OS6 Style
https://fett263.com/fett263-proffieOS6-style-library.html#ResponsiveFlame
OS6.6 v4.014
Single Style
Base Style: Responsive Flame (Real Flame Gradient)


--Effects Included--
Ignition Effect: Standard Wipe Ignition
Retraction Effect: Standard WipeIn Retraction - WavLen
Clash Effect: Real Clash V1
BC_effects_1 sans clash
*/
  StylePtr<Mix<SmoothStep<Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<36000>,Scale<BladeAngle<>,Int<10924>,Int<54000>>>,Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<-1>,Scale<BladeAngle<>,Int<-10000>,Int<-1>>>>,Black,Remap<Scale<RampF,Int<0>,Scale<IsLessThan<BladeAngle<>,Int<15000>>,Int<32768>,Scale<BladeAngle<0,15000>,Int<60000>,Int<32768>>>>,
    Layers<
      Mix<BladeAngle<>,StaticFire<Gradient<RotateColorsX<Int<1600>,RgbArg<BASE_COLOR_ARG,Red>>,RotateColorsX<Int<1000>,RgbArg<BASE_COLOR_ARG,Red>>,RotateColorsX<Int<400>,RgbArg<BASE_COLOR_ARG,Red>>,RgbArg<BASE_COLOR_ARG,Red>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Red>>,0,2,0,1800,10>,StaticFire<Gradient<RotateColorsX<Int<1600>,RgbArg<BASE_COLOR_ARG,Red>>,RotateColorsX<Int<1200>,RgbArg<BASE_COLOR_ARG,Red>>,RotateColorsX<Int<600>,RgbArg<BASE_COLOR_ARG,Red>>,RgbArg<BASE_COLOR_ARG,Red>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Red>>,0,4,0,2200,2>>,
      // fett263 dynamic clash
      Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,White>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
      // Force Choke / lightning
      TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<>,20>>,Strobe<Black,Rgb<80,0,0>,30,30>,TrFadeX<Percentage<WavLen<>,60>>,StaticFire<Red,Strobe<Black,Cyan,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<>,20>>>,EFFECT_FORCE>,
      EffectSequence<EFFECT_POWERSAVE,
        AlphaL<Black,Int<16384>>,
        AlphaL<Black,Int<0>>>,
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
      //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
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
      //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
      AlphaL<Black,Int<16000>>,
      AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
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
    InOutTrL<TrWipe<300>,TrWipeInX<RetractionTime<>>>>>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "grand\ninquisitor"
},

{ "Paradigm;common;commonBU", "tracks/FallenOrderTracks/JFO15.wav",
  // The ol' ThirteenColorTenEffect for OS6 now
  StylePtr<Layers<
    BC_12color_8effect_SS, // 96 possible blade combos in one style. Uses BC_SWAP.
    BC_effects_Red,
    InOutTrL<TrJoin<TrWipeX<WavLen<EFFECT_IGNITION>>,TrSparkX<White,Int<400>,WavLen<EFFECT_IGNITION>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "paradigm"
},
  
{ "a_PONG_KRELL/PongKrll;common;commonBU", "tracks/RebelsTheme.wav",
  StylePtr<Layers<
    Pulsing<Yellow,Chartreuse,20>,
    BC_effects_1,
    InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "pong\nkrell"
},

{ "a_TEMPLE_GUARD/TempleGuard;common;commonBU", "a_TEMPLE_GUARD/tracks/TempleGuard.wav",
  StylePtr<Layers<
    BC_12color_8effect_SS, // 4. Pulsing 3.Golden Yellow
      BC_effects_1,
  InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "Temple\nGuard"
},

{ "a_TEMPLE_GUARD/TempleGuardian;common;commonBU", "a_TEMPLE_GUARD/tracks/TempleGuard.wav",
  StylePtr<Layers<
    BC_12color_8effect_SS, // 4. Pulsing 3.Golden Yellow
	  BC_effects_1,
		InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "temple\nguardian"
},

{ "aa_NoSloppy/Crushed;common;commonBU", "",
	StylePtr<Layers<
	  BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
	  Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>,
	  AlphaL<StaticFire<Black,BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,600>,0,4,2,4000,0>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<500>,Int<-19300>,Int<32768>>,Int<0>>>,
	   BC_effects_Red,
	  InOutTrL<TrWipeSparkTip<White,600>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
	  AlphaL<ColorSelect<WavNum<EFFECT_PREON>,TrInstant,
	  Layers<
	    TransitionEffectL<TrConcat<TrDelay<200>,AlphaL<Black,Int<0>>,TrFade<1300>,Layers<
	    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<180,0,0>>,RotateColorsX<Variation,Rgb<15,0,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>>,RotateColorsX<Variation,Rgb<40,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<36,0,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<180,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<90,0,0>>,RotateColorsX<Variation,Rgb<5,2,0>>,3000>>,
	    AlphaL<StyleFire<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<2,1,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>>,TrDelay<1000>>,EFFECT_PREON>,
	    TransitionEffectL<TrConcat<TrFade<1500>,SparkleL<ColorSelect<Sin<Int<1>,Int<68>>,TrFade<300>,Red,Rgb16<22863,5695,53231>,White>,200,500>,TrDelay<1000>>,EFFECT_PREON>,
	    TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<Black,Int<0>>,TrFade<800>,AlphaL<StaticFire<Black,Rgb16<22863,5695,53231>,0,3,0,6000>,Bump<Int<0>,Int<5000>>>,TrInstant,AlphaL<AlphaL<White,NoisySoundLevelCompat>,Bump<Int<0>,Int<25000>>>,TrDelay<700>>,EFFECT_PREON>,
	    TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<Black,Int<0>>,TrFade<700>,AlphaL<StaticFire<Black,Rgb16<22863,5695,53231>,0,3,0,3000>,Int<16000>>,TrDelay<700>>,EFFECT_PREON>>,
	  Layers<
	    TransitionEffectL<TrConcat<TrInstant,AlphaL<Layers<
	    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
	    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<5000>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
	    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
	    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<9830>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
	    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
	    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<14745>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
	    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
	    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<19660>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
	    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
	    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<24576>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
	    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
	    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<29491>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
	    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
	    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<32768>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>>,EFFECT_PREON>>>,Ifon<Int<0>,Int<32768>>>
	>>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "crushed"
},

{ "aa_Blueforce/LiquidStatic;common;commonBU", "",
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
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "liquid\nstatic"
},


{ "aa_HarrySolo/WORKBENCH;common;commonBU", "",
StylePtr<
Layers<Black,
    AlphaL<Layers< //Swing color
      AlphaL<HumpFlicker<Blue,Rgb<0,0,100>,50>,SmoothStep<Int<8000>,Int<-3000>>>,
      AlphaL<HumpFlicker<Cyan,Rgb<0,120,200>,50>,SmoothStep<Int<2500>,Int<-6000>>>>,
    SmoothStep<Scale<SwingSpeed<250>,Int<-2000>,Int<16000>>,Int<-2000>>>,
  TransitionLoopL<TrConcat<TrFade<1000>,AlphaL<RotateColorsX<Variation,Rgb<100,90,150>>,Bump<Int<0>,ChangeSlowly<NoisySoundLevel,Int<50000>>>>,TrDelay<3000>,AlphaL<RotateColorsX<Variation,Rgb<100,90,150>>,Bump<Int<0>,ChangeSlowly<NoisySoundLevel,Int<50000>>>>,TrFade<1000>,AlphaL<Black,Int<0>>,TrDelay<2000>>>,
ColorSelect<WavNum<EFFECT_CLASH>,TrInstant,
  //clsh01.wav handle with care
  Layers<
  TransitionEffectL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrWipeIn<560>>,EFFECT_CLASH>,
  TransitionEffectL<TrConcat<TrDelay<70>,AlphaL<Red,SmoothStep<Int<5000>,Int<-1>>>,TrFade<250>,Black,TrInstant,AlphaL<Red,SmoothStep<Int<5000>,Int<-1>>>,TrFade<250>,Black,TrInstant,AlphaL<Red,SmoothStep<Int<5000>,Int<-1>>>,TrFade<250>>,EFFECT_CLASH>>,
  // clsh02.wav excessive impact
  TransitionEffectL<TrConcat<TrInstant,White,TrDelay<20>,Blinking<AlphaL<BrownNoiseFlicker<Red,DarkOrange,500>,Bump<Int<0>,Int<60000>>>,Black,100,500>,TrJoin<TrFade<1200>,TrWipeIn<1200>>>,EFFECT_CLASH>,
  // clash03.wav please stop
  Layers<
  TransitionEffectL<TrJoin<TrSparkX<BrownNoiseFlicker<Red,DarkOrange,500>,Int<100>,Int<800>,Int<0>>,TrConcat<TrDelay<300>,AlphaL<Black,Int<0>>,TrFade<300>,AlphaL<White,Bump<Int<0>,Int<30000>>>,TrFade<500>>>,EFFECT_CLASH>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<3000>>>,TrDelay<500>,AlphaL<Black,Int<0>>,TrDelay<350>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<3000>>>,TrDelay<500>,AlphaL<Black,Int<0>>,TrDelay<350>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<3000>>>,TrDelay<500>,AlphaL<Black,Int<0>>,TrInstant>,EFFECT_CLASH>>,
  // clsh04.wav dueling prohibited
  Layers<
  TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<3000>>>,TrDelay<500>,AlphaL<Black,Int<0>>,TrDelay<716>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<3000>>>,TrDelay<500>,AlphaL<Black,Int<0>>,TrDelay<716>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<3000>>>,TrDelay<500>,AlphaL<Black,Int<0>>,TrInstant>,EFFECT_CLASH>,
  TransitionEffectL<TrJoin<TrSparkX<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,DarkOrange>,500>,Int<100>,Int<800>,Int<0>>,TrConcat<TrDelay<266>,AlphaL<Black,Int<0>>,TrBoing<250,1>,AlphaL<Red,Bump<Int<0>>>,TrWipeIn<250>>>,EFFECT_CLASH>>,
  // clash05.wav not best idea
  Layers<
  TransitionEffectL<TrConcat<TrDelay<100>,AlphaL<Black,Int<0>>,TrFade<100>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,DarkOrange>,500>,SmoothStep<Int<6000>,Int<-5000>>>,TrFade<100>,AlphaL<OrangeRed,SmoothStep<Int<1000>,Int<-5000>>>,TrFade<200>>,EFFECT_CLASH>,
  TransitionEffectL<TrJoin<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<8000>>>,TrFade<200>>,TrSparkX<White,Int<500>,Int<300>,Int<0>>>,EFFECT_CLASH>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Black,SmoothStep<Int<8000>,Int<6000>>>,TrDelay<300>>,EFFECT_CLASH>>>,
  ColorSelect<WavNum<EFFECT_BLAST>,TrInstant,
    // blst01.wav repair completed
    TransitionEffectL<TrConcat<TrBoing<1300,8>,AlphaL<PulsingL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,40,255>>,50>,Int<800>>,LinearSectionF<Bump<Int<16384>>,Sin<Int<100>>>>,TrWipe<460>,HumpFlickerL<RotateColorsX<Variation,Rgb<0,40,255>>,50>,TrDelay<300>>,EFFECT_BLAST>,
    // blst02.wav repair failed
    TransitionEffectL<TrConcat<TrBoing<250,3>,AlphaL<BlinkingL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,40,255>>,50>,Int<160>,Int<500>>,LinearSectionF<Sin<Int<500>,Int<8000>,Int<-10000>>,Int<25000>>>,TrWipeInSparkTip<Red,300>,BlinkingL<AlphaL<HumpFlickerL<Red,50>,SmoothStep<Int<1000>,Int<-1>>>,Int<500>,Int<500>>,TrDelay<1530>>,EFFECT_BLAST>,
    // blst03.wav repair interrupted
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Blinking<RotateColorsX<Variation,Rgb<128,128,200>>,Blue,400,500>,LinearSectionF<Sin<Int<400>,Int<32768>,Int<-500>>,Scale<RandomF,Int<100>,Int<1000>>>>,TrDelay<2000>,AlphaL<Black,Int<0>>,TrBoing<300,1>,AlphaL<White,Bump<Int<0>>>,TrInstant>,EFFECT_BLAST>,
    // blst04.wav no deflecting please
    TransitionEffectL<TrConcat<TrBoing<300,1>,AlphaL<Red,Bump<Int<0>>>,TrWipeIn<100>,PulsingL<AlphaL<HumpFlickerL<Red,50>,SmoothStep<Int<1000>,Int<-1>>>,Int<800>>,TrDelay<4380>,AlphaL<White,LinearSectionF<Sin<Int<300>>,Sin<Int<200>,Int<1000>>>>,TrDelay<450>>,EFFECT_BLAST>>,
  // force
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Blinking<RotateColorsX<Variation,Rgb<128,128,200>>,Blue,400,500>,LinearSectionF<Sin<Int<300>,Int<32768>,Int<-500>>,Scale<RandomF,Int<300>,Int<1000>>>>,TrFade<1075>,AlphaL<Black,Int<0>>,TrJoin<TrCenterWipeX<Int<1000>>,TrWaveX<White,Int<1000>,Int<200>,Int<2000>>>,Layers<
    AlphaL<White,LayerFunctions<SmoothStep<Scale<RandomF,Int<-5000>,Int<2000>>,Int<-1>>,SmoothStep<Scale<RandomF,Int<37768>,Int<30768>>,Int<1>>>>,
    AlphaL<ColorSequence<500,DarkOrange,Green,Blue>,LinearSectionF<Sin<Int<100>,Int<32768>,Int<-500>>,Scale<RandomF,Int<300>,Int<2000>>>>>,TrDelay<2750>,AlphaL<Black,Int<0>>,TrConcat<TrBoing<650,5>,AlphaL<HumpFlickerL<Green,50>,LayerFunctions<SmoothStep<Int<30768>,Int<1>>,SmoothStep<Int<2000>,Int<-1>>>>,TrInstant>>,EFFECT_FORCE>,
  LockupTrL<Layers<
    AudioFlicker<RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,Rgb16<0,43202,44565>>>,
    TransitionLoopL<TrConcat<TrDelayX<Scale<RandomF,Int<700>,Int<4000>>>,AlphaL<White,LinearSectionF<RandomF,Int<500>>>,TrDelay<400>>>,
    Layers<
      TransitionEffectL<TrConcat<TrDelayX<Int<8738>>,AlphaL<RotateColorsX<Variation,Cyan>,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,TrBoing<735,3>,AlphaL<Black,Int<0>>,TrDelay<7118>,AlphaL<RotateColorsX<Variation,Cyan>,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,TrBoing<951,3>,AlphaL<Black,Int<0>>,TrDelay<6273>,AlphaL<RotateColorsX<Variation,Cyan>,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,TrBoing<735,3>,AlphaL<Black,Int<0>>,TrDelay<7118>,AlphaL<RotateColorsX<Variation,Cyan>,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,TrBoing<951,3>,AlphaL<Black,Int<0>>,TrDelay<4546>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrDelay<10300>,AlphaL<Black,Int<0>>,TrFade<400>,BrownNoiseFlicker<RotateColorsX<Variation,Cyan>,Black,500>,TrFade<300>,AlphaL<Black,Int<0>>,TrDelay<7767>,AlphaL<Black,Int<0>>,TrFade<400>,BrownNoiseFlicker<RotateColorsX<Variation,Cyan>,Black,500>,TrFade<300>,AlphaL<Black,Int<0>>,TrDelay<5990>,AlphaL<Black,Int<0>>,TrFade<400>,BrownNoiseFlicker<RotateColorsX<Variation,Cyan>,Black,500>,TrFade<300>,AlphaL<Black,Int<0>>,TrDelay<7784>,AlphaL<Black,Int<0>>,TrFade<400>,BrownNoiseFlicker<RotateColorsX<Variation,Cyan>,Black,500>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>>>,TrConcat<TrBoing<300,2>,AlphaL<AudioFlicker<RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,Rgb16<0,43202,44565>>>,Bump<Int<0>>>,TrWipe<275>>,TrWipeIn<500>,SaberBase::LOCKUP_NORMAL>,
    ColorSelect<WavNum<EFFECT_LOCKUP_END>,TrInstant,
      // endlock1.wav success
      TransitionEffectL<TrConcat<TrWipeIn<500>,Black,TrInstant,White,TrDelay<25>,Black,TrFade<500>,HumpFlickerL<RotateColorsX<Variation,Rgb<0,40,255>>,100>,TrDelay<100>>,EFFECT_LOCKUP_END>,
      // endlock2.wav fail
      TransitionEffectL<TrConcat<TrWipeInSparkTip<White,460>,Black,TrBoing<250,2>,AlphaL<RotateColorsX<Variation,DodgerBlue>,SmoothStep<Int<12000>,Int<-1>>>,TrInstant,AlphaL<ColorSequence<75,Cyan,Black,Red,Black,Blue,DodgerBlue,Rgb<50,50,0>,Black>,SmoothStep<Scale<RandomF,Int<0>,Int<1500>>,Int<-1>>>,TrDelay<2673>>,EFFECT_LOCKUP_END>>,
  InOutTrL<TrJoin<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>>>,TrFade<200>>,TrSparkX<White,Int<300>,Int<200>,Int<0>>>,TrConcat<TrBoing<2737,31>,AlphaL<AlphaL<DodgerBlue,Bump<Int<0>,Scale<Trigger<EFFECT_RETRACTION,Int<2737>,Int<1000>,Int<500>>,Int<65000>,Int<0>>>>,Scale<Trigger<EFFECT_RETRACTION,Int<2737>,Int<1000>,Int<500>>,Int<32768>,Int<0>>>,TrInstant>>,
  TransitionEffectL<TrConcat<TrDelay<150>,AlphaL<Black,Int<0>>,TrBoing<300,2>,AlphaL<HumpFlickerL<White,50>,Bump<Int<0>,Int<16000>>>,TrDelay<400>,AlphaL<HumpFlickerL<White,50>,Bump<Int<0>,Int<16000>>>,TrConcat<TrFade<407>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,40,255>>,50>,Bump<Int<0>,Int<25000>>>,TrInstant>>,EFFECT_PREON>,
  TransitionEffectL<TrJoin<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<8000>>>,TrFade<200>>,TrSparkX<White,Int<500>,Int<300>,Int<0>>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Black,SmoothStep<Int<8000>,Int<6000>>>,TrDelay<300>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,DodgerBlue>,Bump<Int<0>,ChangeSlowly<NoisySoundLevel,Int<50000>>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<ColorSequence<75,Cyan,Black,Green,Black,Blue,Black,Rgb<50,50,0>,Black>,SmoothStep<Sin<Int<300>,Int<0>,Int<12000>>,Int<-1>>>,TrDelay<700>,AlphaL<RandomFlicker<Rgb<70,100,200>,ColorSequence<350,Cyan,Green,Blue,Rgb<50,50,0>,Black>>,SmoothStep<Scale<Trigger<EFFECT_BOOT,Int<4000>,Int<1000>,Int<500>>,Int<20000>,Int<0>>,Int<-1>>>,TrDelay<4300>>,EFFECT_BOOT>,
  TransitionEffectL<TrConcat<TrDelay<1000>,BlinkingL<AlphaL<HumpFlickerL<Red,50>,SmoothStep<Int<1000>,Int<-1>>>,Int<500>,Int<500>>,TrFade<4026>>,EFFECT_BOOT>,
    TransitionEffectL<TrConcat<TrFade<1000>,AlphaL<AudioFlicker<Rgb<100,90,150>,Black>,Bump<Int<0>,ChangeSlowly<NoisySoundLevel,Int<50000>>>>,TrFade<250>,AlphaL<DodgerBlue,Bump<Int<0>,Int<60000>>>,TrWipeIn<100>>,EFFECT_NEWFONT>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "workbench"
},

{ "testfont2b;common", "tracks/StarWarsTheme.wav",
  StylePtr<LengthFinder<>>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "blade\nlengthfinder"
}

};


struct AccentsLED {
static constexpr float MaxAmps = 0.02;
static constexpr float MaxVolts = 3.3;
static constexpr float P2Amps = 0.015;
static constexpr float P2Volts = 3.2;
static constexpr float R = 0; // Resistor value
static const int Red = 255;
static const int Green = 255;
static const int Blue = 255;
};

BladeConfig blades[] = {
{ 0, WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin1, bladePowerPin2> >(),  // 7/8 BC Grey PCB holder
SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),
SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>(),
CONFIGARRAY(dume),
"00_DumeSave"},
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif