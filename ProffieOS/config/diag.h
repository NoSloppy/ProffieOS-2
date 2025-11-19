
#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 14
#define NUM_BUTTONS 2
#define VOLUME 1500
const unsigned int maxLedsPerStrip = 159;
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
#endif
 
#ifdef CONFIG_PROP 
#include "../props/saber_fett263_buttons.h" 
#endif
 
 
#ifdef CONFIG_PRESETS
Preset presets[] = {
 
{"terentatek", "tracks/terentatek.wav",
 
//lower chamber data 1
StylePtr<Layers<
  RotateColorsX<Variation,Sparkle<Red,Blue,50,500>>,
  InOutTrL<TrInstant,TrInstant,Sparkle<Red,Black,100,2000>>>>(),
 
//upper champer data 1
StylePtr<Layers<
  Sparkle<Blue,Red,25,700>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,DeepSkyBlue>,3000>>>>(),
 
//Hilt Side Pcb inner ring data 1
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Red>,Black,200,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Red>,3000>>>>(),
 
//Hilt Side Pcb inner outer ring data 1
StylePtr<Layers<
  ColorCycle<RotateColorsX<Variation,Cyan>,25,100,RotateColorsX<Variation,Blue>,25,300,4000>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,ColorCycle<RotateColorsX<Variation,DeepSkyBlue>,25,100,RotateColorsX<Variation,DeepSkyBlue>,25,300,4000>>>>(),
 
//Blade data 1
StylePtr<Layers<
  Stripes<10000,-1700,RotateColorsX<Variation,Rgb<0,0,80>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,RotateColorsX<Variation,Rgb<0,0,50>>,RotateColorsX<Variation,Blue>>,
  AlphaL<Stripes<2500,-3000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,60>>,Pulsing<RotateColorsX<Variation,Rgb<0,0,30>>,Red,800>>,SwingSpeed<600>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Red>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<Red,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,Red,TrFade<400>>,TrConcat<TrInstant,OrangeRed,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<OrangeRed,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<OrangeRed,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<Red,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<Red>,
  ResponsiveBlastL<Red,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<Red,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeSparkTip<Red,500>,TrWipeInSparkTip<Red,800>>>>(),
 
  //center strip 1 data 2
StylePtr<Layers<
  Blinking<Blue,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Blue,Black,500,500>>>>(),
 
//center strip 2 data 2
StylePtr<Layers<Mix<BatteryLevel,Red,Green>,InOutTrL<TrInstant,TrInstant,Mix<BatteryLevel,Red,Green>>>>(),
 
//center strip 3 data 2
StylePtr<Layers<
  Blinking<Blue,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Blue,Black,500,500>>>>(),
 
//right strip 1 data 3
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Blue>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Blue>,500,500>>>>(),
 
//right strip 2-9 data 3
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Red>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Red>>>>>(),
 
//right strip 10 data 3
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Green>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Green>,Black,500,500>>>>(),
 
//left strip 1 data 4
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Blue>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Blue>,500,500>>>>(),
 
//left strip 2-9 data 4
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Red>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Red>>>>>(),
 
//left strip 10 data 4
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Green>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Green>,Black,500,500>>>>()},
 
 
{"cal", "tracks/cal.wav",
 
//lower chamber data 1
StylePtr<Layers<
  RotateColorsX<Variation,Sparkle<Blue,LightCyan,50,500>>,
  InOutTrL<TrInstant,TrInstant,Sparkle<Blue,Black,100,2000>>>>(),
 
//upper champer data 1
StylePtr<Layers<
  Sparkle<DeepSkyBlue,LightCyan,25,700>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,DeepSkyBlue>,3000>>>>(),
 
//Hilt Side Pcb inner ring data 1
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Blue>,Black,200,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Blue>,3000>>>>(),
 
//Hilt Side Pcb outer ring data 1
StylePtr<Layers<
  ColorCycle<RotateColorsX<Variation,Cyan>,25,100,RotateColorsX<Variation,Cyan>,25,300,4000>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,ColorCycle<RotateColorsX<Variation,DeepSkyBlue>,25,100,RotateColorsX<Variation,DeepSkyBlue>,25,300,4000>>>>(),
 
//Blade data 1
StylePtr<Layers<
  Stripes<16000,-1000,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,
  TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<30000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<Red>,
  ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),
 
  //center strip 1 data 2
StylePtr<Layers<
  Blinking<Blue,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Blue,Black,500,500>>>>(),
 
//center strip 2 data 2
StylePtr<Layers<Mix<BatteryLevel,Red,Green>,InOutTrL<TrInstant,TrInstant,Mix<BatteryLevel,Red,Green>>>>(),
 
//center strip 3 data 2
StylePtr<Layers<
  Blinking<Blue,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Blue,Black,500,500>>>>(),
 
//right strip 1 data 3
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Red>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Red>,500,500>>>>(),
 
//right strip 2-9 data 3
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Blue>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Blue>>>>>(),
 
//right strip 10 data 3
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Green>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Green>,Black,500,500>>>>(),
 
//left strip 1 data 4
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Red>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Red>,500,500>>>>(),
 
//left strip 2-9 data 4
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Blue>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Blue>>>>>(),
 
//left strip 10 data 4
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Green>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Green>,Black,500,500>>>>()},
 
{"vader", "tracks/vader.wav",
 
//lower chamber data 1
StylePtr<Layers<
  RotateColorsX<Variation,Sparkle<Red,DeepSkyBlue,50,500>>,
  InOutTrL<TrInstant,TrInstant,Sparkle<Red,Black,100,2000>>>>(),
 
//upper champer data 1
StylePtr<Layers<
  Sparkle<Red,DeepSkyBlue,25,700>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Red>,3000>>>>(),
 
//Hilt Side Pcb inner ring data 1
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Orange>,Black,200,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Orange>,3000>>>>(),
 
//Hilt Side Pcb outer ring data 1
StylePtr<Layers<
  ColorCycle<RotateColorsX<Variation,DarkOrange>,25,100,RotateColorsX<Variation,Red>,25,300,4000>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,ColorCycle<RotateColorsX<Variation,Red>,25,100,RotateColorsX<Variation,DarkOrange>,25,300,4000>>>>(),
 
//Blade data 1
StylePtr<Layers<
  Stripes<10000,-1700,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<50,0,0>>,RotateColorsX<Variation,Red>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<Orange>,
  ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),
 
  //center strip 1 data 2
StylePtr<Layers<
  Blinking<Blue,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Blue,Black,500,500>>>>(),
 
//center strip 2 data 2
StylePtr<Layers<Mix<BatteryLevel,Red,Green>,InOutTrL<TrInstant,TrInstant,Mix<BatteryLevel,Red,Green>>>>(),
 
//center strip 3 data 2
StylePtr<Layers<
  Blinking<Blue,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Blue,Black,500,500>>>>(),
 
//right strip 1 data 3
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Blue>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Blue>,500,500>>>>(),
 
//right strip 2-9 data 3
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Red>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Red>>>>>(),
 
//right strip 10 data 3
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Green>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Green>,Black,500,500>>>>(),
 
//left strip 1 data 4
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Blue>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Blue>,500,500>>>>(),
 
//left strip 2-9 data 4
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Red>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Red>>>>>(),
 
//left strip 10 data 4
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Green>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Green>,Black,500,500>>>>()},
 
 
{"graflex", "tracks/graflex.wav",
 
//lower chamber data 1
StylePtr<Layers<
  RotateColorsX<Variation,Sparkle<Green,Cyan,50,500>>,
  InOutTrL<TrInstant,TrInstant,Sparkle<Green,Black,100,2000>>>>(),
 
//upper champer data 1
StylePtr<Layers<
  Sparkle<Chartreuse,Cyan,25,700>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Chartreuse>,3000>>>>(),
 
//Hilt Side Pcb inner ring data 1
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Green>,Black,200,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Green>,3000>>>>(),
 
//Hilt Side Pcb outer ring data 1
StylePtr<Layers<
  ColorCycle<RotateColorsX<Variation,GreenYellow>,25,100,RotateColorsX<Variation,Chartreuse>,25,300,4000>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,ColorCycle<RotateColorsX<Variation,GreenYellow>,25,100,RotateColorsX<Variation,Chartreuse>,25,300,4000>>>>(),
 
//Blade data 1
StylePtr<Layers<
  Stripes<16000,-1000,RotateColorsX<Variation,Green>,Pulsing<RotateColorsX<Variation,Rgb<0,90,0>>,RotateColorsX<Variation,Green>,800>,RotateColorsX<Variation,Green>>,
  TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<30000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<Red>,
  ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>>>>(),
 
  //center strip 1 data 2
StylePtr<Layers<
  Blinking<Blue,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Blue,Black,500,500>>>>(),
 
//center strip 2 data 2
StylePtr<Layers<Mix<BatteryLevel,Red,Green>,InOutTrL<TrInstant,TrInstant,Mix<BatteryLevel,Red,Green>>>>(),
 
//center strip 3 data 2
StylePtr<Layers<
  Blinking<Blue,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Blue,Black,500,500>>>>(),
 
//right strip 1 data 3
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Blue>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Blue>,500,500>>>>(),
 
//right strip 2-9 data 3
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Green>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Green>>>>>(),
 
//right strip 10 data 3
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Red>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Red>,Black,500,500>>>>(),
 
//left strip 1 data 4
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Blue>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Blue>,500,500>>>>(),
 
//left strip 2-9 data 4
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Green>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Green>>>>>(),
 
//left strip 10 data 4
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Red>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Red>,Black,500,500>>>>()},
 
 
  {"marajade", "tracks/marajade.wav",
 
//lower chamber data 1
StylePtr<Layers<
  RotateColorsX<Variation,Sparkle<Rgb<110,15,200>,Cyan,50,500>>,
  InOutTrL<TrInstant,TrInstant,Sparkle<Rgb<110,15,200>,Black,100,2000>>>>(),
 
//upper champer data 1
StylePtr<Layers<
  Sparkle<Rgb<110,15,200>,Cyan,25,700>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Rgb<110,15,200>>,3000>>>>(),
 
//Hilt Side Pcb inner ring data 1
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Rgb<110,15,200>>,Black,200,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Rgb<110,15,200>>,3000>>>>(),
 
//Hilt Side Pcb outer ring data 1
StylePtr<Layers<
  ColorCycle<RotateColorsX<Variation,Red>,25,100,RotateColorsX<Variation,Magenta>,25,300,4000>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,ColorCycle<RotateColorsX<Variation,Magenta>,25,100,RotateColorsX<Variation,Red>,25,300,4000>>>>(),
 
//Blade data 1
StylePtr<Layers<
  StyleFire<Mix<Bump<Int<0>,Scale<TwistAngle<>,Int<14000>,Int<4000>>>,StripesX<Scale<TwistAngle<>,Int<800>,Int<40>>,Scale<TwistAngle<>,Int<800>,Int<500>>,HumpFlicker<Red,OrangeRed,20>,HumpFlicker<OrangeRed,Blinking<Blue,Magenta,500,500>,50>,HumpFlicker<ColorChange<TrInstant,Red>,OrangeRed,20>>,Strobe<White,LightYellow,50,1>>,Stripes<40,-500,HumpFlicker<Red,OrangeRed,20>,HumpFlicker<OrangeRed,Blue,50>,HumpFlicker<Red,OrangeRed,20>>,0,8,FireConfig<10,2000,5>,FireConfig<10,2000,5>,FireConfig<10,2000,5>,FireConfig<10,2000,5>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<Orange>,
  ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),
 
  //center strip 1 data 2
StylePtr<Layers<
  Blinking<Blue,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Blue,Black,500,500>>>>(),
 
//center strip 2 data 2
StylePtr<Layers<Mix<BatteryLevel,Red,Green>,InOutTrL<TrInstant,TrInstant,Mix<BatteryLevel,Red,Green>>>>(),
 
//center strip 3 data 2
StylePtr<Layers<
  Blinking<Blue,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Blue,Black,500,500>>>>(),
 
//right strip 1 data 3
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Green>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Green>,500,500>>>>(),
 
//right strip 2-9 data 3
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Rgb<110,15,200>>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Rgb<110,15,200>>>>>>(),
 
//right strip 10 data 3
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Blue>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Blue>,Black,500,500>>>>(),
 
//left strip 1 data 4
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Green>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Green>,500,500>>>>(),
 
//left strip 2-9 data 4
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Rgb<110,15,200>>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Rgb<110,15,200>>>>>>(),
 
//left strip 10 data 4
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Blue>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Blue>,Black,500,500>>>>()},
 
 
{"cantina", "tracks/cantina.wav",
 
//lower chamber data 1
StylePtr<Layers<
  RotateColorsX<Variation,Sparkle<Rainbow,White,50,500>>,
  InOutTrL<TrInstant,TrInstant,Sparkle<Rainbow,Black,100,2000>>>>(),
 
//upper champer data 1
StylePtr<Layers<
  Sparkle<Rainbow,White,25,700>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Rainbow>,3000>>>>(),
 
//Hilt Side Pcb inner ring data 1
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Rainbow>,Black,200,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Rainbow>,3000>>>>(),
 
//Hilt Side Pcb outer ring data 1
StylePtr<Layers<
  ColorCycle<RotateColorsX<Variation,Rainbow>,25,100,RotateColorsX<Variation,Rainbow>,25,300,4000>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,ColorCycle<RotateColorsX<Variation,Rainbow>,25,100,RotateColorsX<Variation,Rainbow>,25,300,4000>>>>(),
 
//Blade data 1
StylePtr<Layers<
  StyleFire<Gradient<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Magenta>>,Red,0,3,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<Red>,
  ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<1000>,TrWipeIn<1000>>>>(),
 
  //center strip 1 data 2
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Yellow>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Yellow>,Black,500,500>>>>(),
 
//center strip 2 data 2
StylePtr<Layers<Mix<BatteryLevel,Red,Green>,InOutTrL<TrInstant,TrInstant,Mix<BatteryLevel,Red,Green>>>>(),
 
//center strip 3 data 2
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,DeepPink>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Magenta>,500,500>>>>(),
 
//right strip 1 data 3
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Yellow>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Yellow>,500,500>>>>(),
 
//right strip 2-9 data 3
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Rainbow>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Rainbow>>>>>(),
 
//right strip 10 data 3
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Magenta>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Magenta>,Black,500,500>>>>(),
 
//left strip 1 data 4
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Yellow>,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Yellow>,500,500>>>>(),
 
//left strip 2-9 data 4
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Rainbow>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Rainbow>>>>>(),
 
//left strip 10 data 4
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Magenta>,Black,500,500>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Magenta>,Black,500,500>>>>()},
 
 
 
 
};
BladeConfig blades[] = {
 
 { 0, 
 
//data 1
SubBlade (0, 3, WS281XBladePtr<159, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >()),
SubBlade (4, 7, NULL),
SubBlade (8, 15, NULL),
SubBlade (16, 23, NULL),
SubBlade (24, 158, NULL),
 
 
//data 2
SubBlade (0, 0, WS281XBladePtr<3, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >()),
SubBlade (1, 1, NULL),
SubBlade (2, 2, NULL),
 
 
//data 3
SubBlade (0, 0, WS281XBladePtr<10, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >()),
SubBlade (1, 8, NULL),
SubBlade (9, 9, NULL),
 
 
//data 4
SubBlade (0, 0, WS281XBladePtr<10, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin6> >()),
SubBlade (1, 8, NULL),
SubBlade (9, 9, NULL),
 
 
CONFIGARRAY(presets) },
};
#endif
 
#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif