#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 14
#define NUM_BUTTONS 2
#define VOLUME 1500
const unsigned int maxLedsPerStrip = 174;
#define CLASH_THRESHOLD_G 3.0
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
 
   {"owk4", "tracks/owk4.wav",

//D1 0-0 1 Side Strip Left
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Green>,500,500>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Green>,500,500>>>>(),

//D1 1-8 2 Side Strip Left
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Blue>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Blue>>>>>(),

//D1 9-9 3 Side Strip Left
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Red>,Black,500,500>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Red>,Black,500,500>>>>(),
  
//D1 10-17 4 Hilt Side 1 Inner Ring
StylePtr<Layers<
  RotateColorsX<Variation,Sparkle<Red,Blue>>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Red>,5000>>>>(),

//D1 18-25 5 Hitl Side 1 Outer Ring
StylePtr<Layers<
  ColorCycle<RotateColorsX<Variation,Blue>,25,100,RotateColorsX<Variation,Blue>,25,300,4000>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,ColorCycle<RotateColorsX<Variation,Blue>,25,100,RotateColorsX<Variation,Blue>,25,300,4000>>>>(),
  
  //D1 26-33 6  Hilt Side 2 Inner RIng
StylePtr<Layers<
  ColorCycle<RotateColorsX<Variation,Red>,25,100,RotateColorsX<Variation,DeepSkyBlue>,25,300,4000>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,ColorCycle<RotateColorsX<Variation,Red>,25,100,RotateColorsX<Variation,DeepSkyBlue>,25,300,4000>>>>(),

//D1 34-41 7 Hilt Side 2 Outer Ring
StylePtr<Layers<
  RotateColorsX<Variation,Sparkle<Blue>>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Blue,RotateColorsX<Variation,Black>,5000>>>>(),


//D1 42-173 8 Blade
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
  InOutTrL<TrWipeX<Scale<BladeAngle<>,Int<500>,Int<200>>>,TrWipeInX<Scale<BladeAngle<>,Int<800>,Int<300>>>>>>(),

//D2 0-0 9 side strip right
StylePtr<Layers<
  Blinking<Black,RotateColorsX<Variation,Green>,500,500>,
  InOutTrL<TrInstant,TrInstant,Blinking<Black,RotateColorsX<Variation,Green>,500,500>>>>(),

//D2 1-8 10 side strip right
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipe<250>,RotateColorsX<Variation,Blue>,TrWipe<300>>>,
  InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<50>>,Int<9000>>,Black,RotateColorsX<Variation,Blue>>>>>(),

//D2 9-9 11 side strip right
StylePtr<Layers<
  Blinking<RotateColorsX<Variation,Red>,Black,500,500>,
  InOutTrL<TrInstant,TrInstant,Blinking<RotateColorsX<Variation,Red>,Black,500,500>>>>(),

//D4 0-8 12 chamber
StylePtr<Layers<
  Sparkle<Blue,Cyan,100,700>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Blue>,5000>>>>(),

//D4 9-27 13 speaker led ring
StylePtr<Layers<
  RotateColorsX<Variation,Sparkle<Blue,White,200,400>>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  InOutTrL<TrInstant,TrInstant,ColorCycle<RotateColorsX<Variation,Blue>,25,100,RotateColorsX<Variation,Blue>,25,300,4000>>>>(),


//spinny
  StylePtr<Layers<
  Rgb<128,128,128>,
  InOutTrL<TrFade<300>,TrFade<800>,Black>>>()},






};
BladeConfig blades[] = {

 { 0, 

//data 1
SubBlade (0, 0, WS281XBladePtr<174, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >()),
SubBlade (1, 8, NULL),
SubBlade (9, 9, NULL),
SubBlade (10, 17, NULL),
SubBlade (18, 25, NULL),
SubBlade (26, 33, NULL),
SubBlade (34, 41, NULL),
SubBlade (42, 173, NULL),


//data 2
SubBlade (0, 0, WS281XBladePtr<10, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >()),
SubBlade (1, 8, NULL),
SubBlade (9, 9, NULL),


//data 4
SubBlade (0, 8, WS281XBladePtr<28, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin5> >()),
SubBlade (9, 27, NULL),


//spinny
SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),



CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

