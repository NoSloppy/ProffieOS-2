#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
const unsigned int maxLedsPerStrip = 144;
#define EXTRA_COLOR_BUFFER_SPACE 60
#define VOLUME 1500
 
#define CLASH_THRESHOLD_G 3.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define MOTION_TIMEOUT 60 * 15 * 1000
#define IDLE_OFF_TIME 60 * 15 * 1000
#define DISABLE_BASIC_PARSER_STYLES
#define DISABLE_DIAGNOSTIC_COMMANDS
#define SHARED_POWER_PINS
#define ENABLE_ALL_EDIT_OPTIONS
#define SAVE_PRESET
#define NO_REPEAT_RANDOM
#define COLOR_CHANGE_DIRECT
#define FETT263_RANDOMIZE_QUOTE_PLAYER
#define FETT263_LOCKUP_DELAY 200
#define FETT263_BM_CLASH_DETECT 6
#define FETT263_SWING_ON_SPEED 250
#define FETT263_SWING_ON
#define FETT263_SWING_ON_NO_BM
#define FETT263_TWIST_ON_PREON
#define FETT263_TWIST_ON_NO_BM
#define FETT263_TWIST_OFF
#define FETT263_FORCE_PUSH_ALWAYS_ON
#define FETT263_FORCE_PUSH_LENGTH 5
#define FETT263_SPECIAL_ABILITIES
#define FETT263_MULTI_BLAST
#define FETT263_CIRCULAR_VOLUME_MENU
#endif
 
#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif
 
#ifdef CONFIG_PRESETS
Preset presets[] = {
 { "Binary Dark;common", "tracks/mars.wav", //1--
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
  
  //Red
  Layers<
    
    //Fett263 Humpflicker
        HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,50>,
    
    //Fett263 unstable swing
    AlphaL<AudioFlickerL<Stripes<1000,-1500,RandomPerLEDFlicker<RotateColorsX<Variation,DarkOrange>,Black>,Black,RotateColorsX<Variation,Red>,Black>>,SwingSpeed<350>>,
    
    //Ripple swing effect using Fett263's scaled responsive swing
    AlphaL<AlphaL<Stripes<2000,-2250,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<60,30,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,15,0>>,Black,800>>,HoldPeakF<Scale<IsLessThan<SwingSpeed<850>,Int<13600>>,Scale<SwingSpeed<850>,Int<-19300>,Int<32768>>,Int<0>>,Int<550>,Scale<SwingAcceleration<100>,Int<20000>,Int<10000>>>>,SmoothStep<Scale<Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>,Int<15000>,Int<5000>>,Int<16000>>>,
    
    //Fett263 unstable ignition with slow fade from deep sky blue to red
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-1550,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<3000>,HumpFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,50,120>>,50>,TrDelay<5000>,HumpFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,50,120>>,50>,TrFade<5000>>,EFFECT_IGNITION>>>,
  
  //Fett263 unstable force effect with sizzle emitter ending - Toggles the base saber colors between red and blue.
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<150>,StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,20>,RotateColorsX<Variation,Rgb<10,0,10>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,255>>,70>,RotateColorsX<Variation,Rgb<128,0,128>>>,RotateColorsX<Variation,Rgb<80,0,80>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrDelay<1000>,StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,20>,RotateColorsX<Variation,Rgb<10,0,10>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,255>>,70>,RotateColorsX<Variation,Rgb<128,0,128>>>,RotateColorsX<Variation,Rgb<80,0,80>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrFade<1000>,AlphaL<StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,20>,RotateColorsX<Variation,Rgb<10,0,10>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,255>>,70>,RotateColorsX<Variation,Rgb<128,0,128>>>,RotateColorsX<Variation,Rgb<80,0,80>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,Bump<Int<3500>,Int<23384>>>,TrFade<600>>,EFFECT_FORCE>,
  
  //Fett263 Responsive Intensity Lockup effect with absorb endlock
  LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<0>>,TrWaveX<RgbArg<LOCKUP_COLOR_ARG,White>,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<HumpFlicker<White,Rgb<40,60,60>,50>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>>,TrFade<350>>,SaberBase::LOCKUP_NORMAL>,
  
  //Fett263 Responsive Intensity Lockup effect
  //LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<0>>,TrWaveX<RgbArg<LOCKUP_COLOR_ARG,White>,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>>,SaberBase::LOCKUP_NORMAL>,
  
  //Fett263 Responsive Lightning Block
  ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,White>,Int<16000>>,30>,TrSmoothFade<600>>>,
  
  //Responsive Stab
  ResponsiveStabL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Yellow>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,50>>,TrFadeX<Percentage<WavLen<EFFECT_STAB>,50>>>,
  
  //Blast selection based on absorb effect
  ColorSelect<WavNum<EFFECT_BLAST>,TrInstant,
    
    //Fett263 Responsive Blast Wave
    TransitionEffectL<TrConcat<TrInstant,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,TrDelay<500>>,EFFECT_BLAST>,
    
    //Fett263 Responsive Blast Wave with absorb effect
    TransitionEffectL<TrConcat<TrInstant,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,TrFade<500>,AlphaL<HumpFlicker<White,Rgb<40,60,60>,50>,Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>>>,TrFade<350>>,EFFECT_BLAST>>,
  
  //Fett263 Responsive Blast Wave
  //ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,
  
  //OS6 Random Fett263 Responsive Multi-Blast
  //ColorSelect<RandomF,TrInstant,ResponsiveBlastL<RgbArg<BLAST_COLOR_ARG,White>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<RgbArg<BLAST_COLOR_ARG,White>,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<RgbArg<BLAST_COLOR_ARG,White>,200,200>,ResponsiveBlastFadeL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
  
  //OS6 Fett263 Random Responsive Blast
  //MultiTransitionEffectL<TrRandom<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<28000>,Int<8000>>>,TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<16384>,Int<6000>>>,TrFade<50>,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrSparkX<Remap<CenterDistF<EffectPosition<>>,Stripes<2000,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Int<300>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>>,TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<16384>,Int<6000>>>,TrFade<50>,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrWaveX<Remap<CenterDistF<EffectPosition<>>,Stripes<1500,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>>,Int<160>,Int<100>,Int<300>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>>,TrConcat<TrInstant,AlphaMixL<Bump<EffectPosition<>,Scale<WavLen<>,Int<9000>,Int<12000>>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>,TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<000>>,Scale<WavLen<>,Int<9000>,Int<13000>>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>>,EFFECT_BLAST>,
  
  //OS5 Fett263 Multi-Blast, blaster reflect cycles through different responsive effects (I like the look of this one the best even with the new OS6 stuff)
  //EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
  
  //Fett263 Real Clash with absorb effect
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
 
  //Fett263 On-Demand Battery Level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
  
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
  TransitionEffectL<TrConcat<TrInstant,AlphaL<White,SmoothStep<Scale<NoisySoundLevel,Int<150>,Int<10000>>,Int<-4000>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>
  >>(),  "binary dark"},
 
{ "Deflect;common", "tracks/mercury.wav",//2--
StylePtr<Layers<
    
  //Fett263 HumpFlicker with Erratic Swing
  Mix<SwingSpeed<400>,HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,50>,HumpFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<128,0,0>>,30>>,
  
  //Ripple swing effect using Fett263's scaled responsive swing
  AlphaL<AlphaL<Stripes<2000,-2250,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<60,30,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,15,0>>,Black,800>>,HoldPeakF<Scale<IsLessThan<SwingSpeed<850>,Int<13600>>,Scale<SwingSpeed<850>,Int<-19300>,Int<32768>>,Int<0>>,Int<550>,Scale<SwingAcceleration<100>,Int<20000>,Int<10000>>>>,SmoothStep<Scale<Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>,Int<15000>,Int<5000>>,Int<-16000>>>, 
  
  //Fett263 Unstable Ignition
  TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-1550,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFadeX<Percentage<WavLen<EFFECT_IGNITION>,15>>>,EFFECT_IGNITION>,
  
  //HumpFlicker Bright Retraction
  TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<RotateColorsX<Variation,Rgb16<65535,42753,42753>>,RotateColorsX<Variation,White>,50>,TrInstant>,EFFECT_RETRACTION>,
  
  //Fett263 Responsive Intensity Lockup with Unstable End
  LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>,RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>>,
  TrConcat<TrExtend<50,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,White>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrExtend<3000,TrFade<300>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrFade<3000>>,
  TrConcat<TrInstant,White,TrFade<650>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,11439,0>>,Black,300>,TrFade<1000>,AudioFlickerL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>>,TrFade<1200>>,SaberBase::LOCKUP_NORMAL>,
  
  //Fett263 Responsive Lightning Block
  ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,White>,Int<16000>>,30>,TrSmoothFade<600>>>,
  
  //Fett263 Responsive flame emitter effect, point the blade up to speed up the flame
  AlphaL<Mix<Scale<BladeAngle<19000>,Int<32768>,Int<0>>,StyleFire<Gradient<RotateColorsX<Variation,White>,RotateColorsX<Variation,Rgb16<65535,42753,42753>>,RotateColorsX<Variation,Rgb16<65535,42753,42753>>,RotateColorsX<Variation,Rgb16<65535,42753,42753>>>,RotateColorsX<Variation,Rgb<30,30,30>>,0,2,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,42753,42753>>,RotateColorsX<Variation,White>,RotateColorsX<Variation,White>,RotateColorsX<Variation,White>>,RotateColorsX<Variation,Rgb<30,30,30>>,0,1,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,SmoothStep<Scale<SlowNoise<Int<3000>>,Int<1750>,Int<4125>>,Int<-3500>>>,
  
  //Responsive Stab
  ResponsiveStabL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Yellow>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,50>>,TrFadeX<Percentage<WavLen<EFFECT_STAB>,50>>>,
  
  //Fett263 Multi-blast, blaster reflect cycles through different responsive effects
  EffectSequence<EFFECT_BLAST,ResponsiveBlastL<RgbArg<BLAST_COLOR_ARG,White>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<RgbArg<BLAST_COLOR_ARG,White>,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<RgbArg<BLAST_COLOR_ARG,White>,200,200>,ResponsiveBlastFadeL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
  
  //Fett263 Real Clash
  Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
  
  //Fett263 Intensity Drag
  LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,White>>,SmoothStep<IntArg<DRAG_SIZE_ARG,27500>,Int<5000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,29250>,Int<5000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  
  //Fett263 Responsive Intensity Melt
  LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,26000>,Int<6000>>>,TrConcat<TrWipeIn<100>,AlphaL<Red,SmoothStep<Int<29000>,Int<8000>>>,TrExtend<2000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<29000>,Int<8000>>>,TrFade<3000>>,TrFade<250>,SaberBase::LOCKUP_MELT>,
  
  //Fett263 Power Save, if using his prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
  EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
 
  //Fett263 Spark Tip Ignition and Retraction
  InOutTrL<TrJoin<TrWipeX<Percentage<WavLen<EFFECT_IGNITION>,5>>,TrSparkX<White,Int<400>,Percentage<WavLen<EFFECT_IGNITION>,5>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrSparkX<White,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
  
  //Noise Responsive Sparky Hilt Postoff
  TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb16<65535,42753,42753>>,150>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<9500>>,Int<-7000>>>,TrFadeX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
  
  //Fett263 optional/alternate Passive Battery Monitor: on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
  //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
  //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
  
  //Fett263 On-Demand Battery Level: if using Fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
  
  //Ripple Out Preon
  TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_PREON>,10>>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb16<65535,42753,42753>>,Int<125>,Int<350>,Int<315>,Int<0>>>,TrDelayX<Percentage<WavLen<EFFECT_PREON>,90>>>,EFFECT_PREON>,
  
  //Noise Responsive Charge Up Preon
  TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb16<65535,42753,42753>>,150>,SmoothStep<Scale<NoisySoundLevel,Int<-1500>,Trigger<EFFECT_PREON,WavLen<EFFECT_PREON>,Int<0>,Int<0>>>,Int<-8000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>
  >>(),  "deflect"},
 
{ "FALLENORDERCALBUNDLE;common", "tracks/uranus.wav",//3--
StylePtr<Layers<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<4096>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,White>,2000>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>>(),"FALLENORDERCALBUNDLE"},
 
 "Null;common", "tracks/mars.wav", //4--
StylePtr<Layers<
 
  //'Heartbeat Pulse' (based on Fett263's Unstable Pulse Silver/Purple)
  StripesX<Int<10000>,Scale<SlowNoise<Int<50000>>,Int<-50>,Int<-1000>>,RgbArg<BASE_COLOR_ARG,Rgb<100,100,240>>,RandomPerLEDFlicker<Mix<Int<20000>,White,RgbArg<BASE_COLOR_ARG,Rgb<100,50,240>>>,Mix<Int<20000>,White,RgbArg<BASE_COLOR_ARG,Rgb<100,50,240>>>>,BrownNoiseFlicker<Mix<Int<1285>,White,RgbArg<BASE_COLOR_ARG,Rgb<100,50,240>>>,Mix<Int<16448>,White,RgbArg<BASE_COLOR_ARG,Rgb<100,50,240>>>,300>,RgbArg<BASE_COLOR_ARG,Rgb<100,50,240>>,RandomPerLEDFlicker<White,Mix<Int<16448>,White,RgbArg<BASE_COLOR_ARG,Rgb<100,100,240>>>>,RgbArg<BASE_COLOR_ARG,Rgb<100,100,240>>>,
 
  //Fett263 Silver Purple Humpflicker Swing
  AlphaL<HumpFlicker<RotateColorsX<Variation,Rgb16<64000,8000,0>>,RotateColorsX<Variation,Rgb16<12000,1818,0>>,50>,SwingSpeed<365>>,
  
  //Fett263 Responsive Intensity Lockup
  LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>,RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>>,
  TrConcat<TrExtend<50,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,White>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrExtend<3000,TrFade<300>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrFade<3000>>,
  TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,White>,TrFadeX<Percentage<WavLen<EFFECT_LOCKUP_END>,85>>>,SaberBase::LOCKUP_NORMAL>,
  
  //Fett263 Responsive Lightning Block
  ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,White>,Int<16000>>,30>,TrSmoothFade<600>>>,
  
  //Responsive Stab
  ResponsiveStabL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Magenta>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,50>>,TrFadeX<Percentage<WavLen<EFFECT_STAB>,50>>>,
  
  //Fett263 Multi-blast, blaster reflect cycles through different responsive effects
  EffectSequence<EFFECT_BLAST,ResponsiveBlastL<RgbArg<BLAST_COLOR_ARG,White>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<RgbArg<BLAST_COLOR_ARG,White>,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<RgbArg<BLAST_COLOR_ARG,White>,200,200>,ResponsiveBlastFadeL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
  
  //Fett263 Real Clash
  Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
  
  //Fett263 White Unstable Ignition Effect
  TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-2500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<2950>>,EFFECT_IGNITION>,
  
  //Bright Humpflicker Retraction Effect
  TransitionEffectL<TrConcat<TrInstant,HumpFlicker<RotateColorsX<Variation,Rgb<125,85,175>>,RotateColorsX<Variation,Rgb16<24485,13179,65535>>,50>,TrFadeX<WavLen<EFFECT_RETRACTION>>>,EFFECT_RETRACTION>,
  
  //Fett263 Intensity Drag
  LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,White>>,SmoothStep<IntArg<DRAG_SIZE_ARG,27500>,Int<5000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,29250>,Int<5000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  
  //Fett263 Responsive Intensity Melt
  LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,26000>,Int<6000>>>,TrConcat<TrWipeIn<100>,AlphaL<Red,SmoothStep<Int<29000>,Int<8000>>>,TrExtend<2000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<29000>,Int<8000>>>,TrFade<3000>>,TrFade<250>,SaberBase::LOCKUP_MELT>,
  
  //Fett263 Power Save, if using his prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
  EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
 
  //Fett263 Spark Tip Ignition and Retraction
  InOutTrL<TrJoin<TrWipeX<Percentage<WavLen<EFFECT_IGNITION>,4>>,TrSparkX<White,Int<400>,Percentage<WavLen<EFFECT_IGNITION>,4>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrSparkX<White,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
  
  //Fett263 optional/alternate Passive Battery Monitor: on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
  //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
  //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
  
  //Fett263 On-Demand Battery Level: if using Fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
  
  //False start preon effect
  TransitionEffectL<TrConcat<TrWipeX<Percentage<WavLen<EFFECT_PREON>,26>>,StaticFire<RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>>,0,1,0,2000,2>,TrFadeX<Percentage<WavLen<EFFECT_PREON>,40>>,StaticFire<RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>>,0,1,0,2000,2>,TrFadeX<Percentage<WavLen<EFFECT_PREON>,13>>,AlphaL<HumpFlicker<RotateColorsX<Variation,Rgb16<24155,12712,65535>>,RotateColorsX<Variation,Rgb16<8024,1818,23182>>,50>,SmoothStep<Scale<NoisySoundLevel,Int<-2500>,Int<9500>>,Int<-11500>>>,TrDelayX<Percentage<WavLen<EFFECT_PREON>,50>>>,EFFECT_PREON>>>(),  "Null"},
 
"JUMPBIKE;common", "tracks/mars.wav", //5--
StylePtr<Layers<
  Layers<
    RotateColorsX<Variation,Green>,
    AudioFlickerL<RotateColorsX<Variation,Rgb<0,128,0>>>>,
  TransitionEffectL<TrConcat<TrFade<400>,AudioFlickerL<RotateColorsX<Variation,Rgb<150,255,150>>>,TrDelay<30000>,AudioFlickerL<RotateColorsX<Variation,Rgb<150,255,150>>>,TrFade<800>>,EFFECT_FORCE>,
  AlphaL<Stripes<2500,-3000,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,60,0>>,Pulsing<RotateColorsX<Variation,Rgb<0,30,0>>,Black,800>>,SwingSpeed<600>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<Mix<SmoothStep<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<1000>>,Stripes<1500,2000,White,Green>,Stripes<1500,-2500,White,Green>>,Int<18000>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<Blue,AudioFlicker<Blue,White>,50,1>,TrConcat<TrInstant,AlphaL<Blue,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<Blue,Int<16000>>,30>,TrSmoothFade<600>>>,
  AlphaL<White,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,
  ResponsiveStabL<Red>,
  ResponsiveBlastL<OriginalBlastL<ResponsiveBlastWaveL<Red>>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,Int<20000>>,
  TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<800>>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<1500>>,EFFECT_RETRACTION>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<300>,TrWipeInSparkTip<White,1000>>,
  TransitionEffectL<TrConcat<TrFade<2000>,AlphaL<HumpFlickerL<Red,10>,Bump<Int<0>,Int<4000>>>,TrFade<2950>,AlphaL<HumpFlickerL<Orange,15>,Bump<Int<0>,Int<5000>>>,TrFade<3000>,AlphaL<HumpFlickerL<White,20>,Bump<Int<0>,Int<6000>>>,TrBoing<1000,3>>,EFFECT_PREON>>>(),  "JUMPBIKE"},
 
 
  
};
    
 
BladeConfig blades[] = {
 { 0, WS281XBladePtr<116, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), CONFIGARRAY(presets) }
};
#endif
 
#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
 
 /* Generated with Fett263 Config Helper v3.0 */