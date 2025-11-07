#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 2
#define VOLUME 2000
#define BOOT_VOLUME 100
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 3.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define COLOR_CHANGE_DIRECT
#define ENABLE_SD
//#define SAVE_STATE
#define DISABLE_DIAGNOSTIC_COMMANDS
#define WS_SWING_ON
#define WS_SWING_ON_SPEED 250
#define WS_TWIST_ON
#define WS_TWIST_OFF
#define WS_THRUST_ON
#define WS_AUTO_SWING_BLAST
#define WS_ROTATE_TO_CHANGE_PRESET
#define WS_ROTATE_TO_CHANGE_VOLUME
#define IDLE_OFF_TIME 60 * 5 * 1000

#define DISABLE_BASIC_PARSER_STYLES
#define NO_REPEAT_RANDOM 
#define KILL_OLD_PLAYERS
/*
-- BladeID with constant monitoring --
 
Main blade must be wired to data1
Have a Presets array for each blade,
and match those names to the CONFIGARRAY for the given blade.
Arrays should be named differently like blade_1, blade_2, no_blade etc...
Blades can use the same set of presets, or different ones for different blades.

Open Serial Monitor in Arduino and type `id` to get read value.
Use that value in the blade definition in the BladeConfig.
* Note * It is recommended to use a Blade ID resistor in each blade 
to ensure different resistance vales between blades. 
However, in testing, values reported for a chassis alone,
chassis inserted into the hilt (connected to emitter PCB)
and then main blade inserted all gave different enough values on their own
without added resistors that it worked fine. YMMV.
*/
// Specify the LED pad(s) that the main blade uses.
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>

// Required when blades on different data pads use common LED power pads.
// and/or when BLADE_ID_SCAN_MILLIS is used with Blade ID.
#define SHARED_POWER_PINS

// Choose how often to check for new blade (milliseconds).
// Larger values will be a longer delay before a blade is recognized.
#define BLADE_ID_SCAN_MILLIS 1000
//    How many Blade ID scans to average (default is 10, works well)
#define BLADE_ID_TIMES 10

// Use Blade Detect for simple 2 way toggle. Requires wiring a pad to a switched GND
// (floating pogo pin until grounded via blade-side PCB ring)
// #define BLADE_DETECT_PIN 10 
#endif

#ifdef CONFIG_PROP
#include "../props/saber_WS_buttons.h"
#endif


#ifdef CONFIG_PRESETS

Preset blade_1[] = {

// { "Reliant;common", "",
{ "testfont2b;common;commonBU", "",

StylePtr<Layers<
  StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<30,0,66>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<7,0,16>>,RotateColorsX<Variation,Rgb<95,0,210>>>,
  TransitionEffectL<TrConcat<TrFade<400>,RotateColorsX<Variation,Rgb<160,60,255>>,TrDelay<7000>,RotateColorsX<Variation,Rgb<160,60,255>>,TrFade<800>>,EFFECT_FORCE>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Stripes<6,-1600,Mix<Sin<Int<30>>,White,White>,Mix<Sin<Int<30>>,White,White>,Mix<Sin<Int<26>>,White,White>,Mix<Sin<Int<24>>,White,White>>,Bump<Scale<SwingSpeed<400>,Int<1000>,Int<34000>>,Int<20000>>>,TrDelay<7000>>,EFFECT_FORCE>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Yellow>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  MultiTransitionEffectL<TrConcat<TrFade<3000>,RotateColorsX<Variation,Rgb<95,0,210>>,TrDelay<5000>,RotateColorsX<Variation,Rgb<95,0,210>>,TrFade<3000>>,EFFECT_STAB,4>,
  MultiTransitionEffectL<TrConcat<TrWipe<3000>,MultiTransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Rgb<100,150,230>,TrFade<3000>,TrDelay<3000>,EFFECT_STAB,4>,TrDelay<3000>,Rgb<100,150,230>,TrWipe<3000>>,EFFECT_STAB,4>,
  MultiTransitionEffectL<TrConcat<TrWaveX<BrownNoiseFlicker<White,SteelBlue,60>,Int<3000>,Int<400>,Int<3000>,Int<0>>,AlphaL<White,Int<0>>,TrDelay<3000>,AlphaL<White,Int<0>>,TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,Int<10000>,Int<400>,Int<3000>,Int<0>>>,EFFECT_STAB,4>,
  ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<300>,TrWipeInSparkTip<White,1096,200>>,
  TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RandomPerLEDFlickerL<White>,SmoothStep<Int<6000>,Int<-4000>>>,TrDelay<7700>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrColorCycle<1000,0,1000>,GhostWhite,TrFade<100>>,EFFECT_PREON>>>(),

//led 1
StylePtr<Layers<RandomPerLEDFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,RgbArg<ALT_COLOR_ARG,Rgb<50,185,255>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30000>,TrFade<300>>,AlphaL<RandomBlink<10000,RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>,Black>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,TrFade<300>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Int<0>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrSparkX<Remap<CenterDistF<>,Stripes<1200,-3600,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,Int<30>,Scale<Sum<ClashImpactF<>,SwingSpeed<600>>,Int<100>,Int<400>>,Int<16384>>,SaberBase::LOCKUP_NORMAL>,LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrInstant,TrConcat<TrInstant,Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrFade<1000>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<OFF_COLOR_ARG,Rgb<115,15,240>>,2000>>>>(),


// led 2

StylePtr<Layers<TransitionLoop<Black,TrConcat<TrWipe<200>,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>,TrWipe<200>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30000>,TrFade<300>>,AlphaL<RandomBlink<10000,RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>,Black>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,TrFade<300>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Int<0>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrSparkX<Remap<CenterDistF<>,Stripes<1200,-3600,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,Int<30>,Scale<Sum<ClashImpactF<>,SwingSpeed<600>>,Int<100>,Int<400>>,Int<16384>>,SaberBase::LOCKUP_NORMAL>,LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrInstant,TrConcat<TrInstant,Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrFade<1000>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,InOutTrL<TrInstant,TrInstant,Blinking<RgbArg<OFF_COLOR_ARG,Rgb<255,68,0>>,Black,500,500>>>>(),
"Reliant"},


{ "Plasma_Kyber;common", "",

StylePtr<Layers<
  StyleFire<Stripes<4200,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,RotateColorsX<Variation,Rgb<10,0,0>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,25>>,70>,RotateColorsX<Variation,Rgb<128,0,0>>>,RotateColorsX<Variation,Rgb<80,0,0>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<Orange>,
  ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<800>>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,150,150>>,40>,TrFade<500>>,EFFECT_RETRACTION>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<400>,TrWipeInSparkTip<White,500>>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<500>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<500>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<500>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<500>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<500>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<500>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<2000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Blue>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,White>,Rgb<50,50,50>>
,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Snow>,RotateColorsX<Int<4000>,RotateColorsX<Variation,White>>>,White,50>>,
SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelay<1394>>,EFFECT_PREON>>>(),

//  led 1

StylePtr<Layers<TransitionLoop<Black,TrConcat<TrDelay<3000>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,TrBoing<2000,5>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30000>,TrFade<300>>,AlphaL<RandomBlink<10000,RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>,Black>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,TrFade<300>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Int<0>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrSparkX<Remap<CenterDistF<>,Stripes<1200,-3600,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,Int<30>,Scale<Sum<ClashImpactF<>,SwingSpeed<600>>,Int<100>,Int<400>>,Int<16384>>,SaberBase::LOCKUP_NORMAL>,LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrInstant,TrConcat<TrInstant,Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrFade<1000>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<OFF_COLOR_ARG,Rgb<0,255,0>>,2000>>>>(),


// led 2

StylePtr<Layers<TransitionLoop<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,TrConcat<TrBoing<3000,9>,Black,TrDelay<2000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30000>,TrFade<300>>,AlphaL<RandomBlink<10000,RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>,Black>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,TrFade<300>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Int<0>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrSparkX<Remap<CenterDistF<>,Stripes<1200,-3600,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,Int<30>,Scale<Sum<ClashImpactF<>,SwingSpeed<600>>,Int<100>,Int<400>>,Int<16384>>,SaberBase::LOCKUP_NORMAL>,LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrInstant,TrConcat<TrInstant,Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrFade<1000>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<OFF_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),
"plasma_kyber"},

};

//----------------------------------------------------------------------------------------

Preset blade_2[] = {

// { "Reliant;common", "",
    { "Dooku_CW;common;commonBU", "",

StylePtr<Layers<
  StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<30,0,66>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<7,0,16>>,RotateColorsX<Variation,Rgb<95,0,210>>>,
  TransitionEffectL<TrConcat<TrFade<400>,RotateColorsX<Variation,Rgb<160,60,255>>,TrDelay<7000>,RotateColorsX<Variation,Rgb<160,60,255>>,TrFade<800>>,EFFECT_FORCE>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Stripes<6,-1600,Mix<Sin<Int<30>>,White,White>,Mix<Sin<Int<30>>,White,White>,Mix<Sin<Int<26>>,White,White>,Mix<Sin<Int<24>>,White,White>>,Bump<Scale<SwingSpeed<400>,Int<1000>,Int<34000>>,Int<20000>>>,TrDelay<7000>>,EFFECT_FORCE>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Yellow>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  MultiTransitionEffectL<TrConcat<TrFade<3000>,RotateColorsX<Variation,Rgb<95,0,210>>,TrDelay<5000>,RotateColorsX<Variation,Rgb<95,0,210>>,TrFade<3000>>,EFFECT_STAB,4>,
  MultiTransitionEffectL<TrConcat<TrWipe<3000>,MultiTransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Rgb<100,150,230>,TrFade<3000>,TrDelay<3000>,EFFECT_STAB,4>,TrDelay<3000>,Rgb<100,150,230>,TrWipe<3000>>,EFFECT_STAB,4>,
  MultiTransitionEffectL<TrConcat<TrWaveX<BrownNoiseFlicker<White,SteelBlue,60>,Int<3000>,Int<400>,Int<3000>,Int<0>>,AlphaL<White,Int<0>>,TrDelay<3000>,AlphaL<White,Int<0>>,TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,Int<10000>,Int<400>,Int<3000>,Int<0>>>,EFFECT_STAB,4>,
  ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<300>,TrWipeInSparkTip<White,1096,200>>,
  TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RandomPerLEDFlickerL<White>,SmoothStep<Int<6000>,Int<-4000>>>,TrDelay<7700>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrColorCycle<1000,0,1000>,GhostWhite,TrFade<100>>,EFFECT_PREON>>>(),

//led 1
StylePtr<Layers<RandomPerLEDFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,RgbArg<ALT_COLOR_ARG,Rgb<50,185,255>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30000>,TrFade<300>>,AlphaL<RandomBlink<10000,RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>,Black>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,TrFade<300>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Int<0>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrSparkX<Remap<CenterDistF<>,Stripes<1200,-3600,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,Int<30>,Scale<Sum<ClashImpactF<>,SwingSpeed<600>>,Int<100>,Int<400>>,Int<16384>>,SaberBase::LOCKUP_NORMAL>,LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrInstant,TrConcat<TrInstant,Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrFade<1000>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<OFF_COLOR_ARG,Rgb<115,15,240>>,2000>>>>(),


// led 2

StylePtr<Layers<TransitionLoop<Black,TrConcat<TrWipe<200>,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>,TrWipe<200>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30000>,TrFade<300>>,AlphaL<RandomBlink<10000,RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>,Black>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,TrFade<300>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Int<0>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrSparkX<Remap<CenterDistF<>,Stripes<1200,-3600,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,Int<30>,Scale<Sum<ClashImpactF<>,SwingSpeed<600>>,Int<100>,Int<400>>,Int<16384>>,SaberBase::LOCKUP_NORMAL>,LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrInstant,TrConcat<TrInstant,Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrFade<1000>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,InOutTrL<TrInstant,TrInstant,Blinking<RgbArg<OFF_COLOR_ARG,Rgb<255,68,0>>,Black,500,500>>>>(),
"Reliant"},


{ "Plasma_Kyber;common", "",

StylePtr<Layers<
  StyleFire<Stripes<4200,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,RotateColorsX<Variation,Rgb<10,0,0>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,25>>,70>,RotateColorsX<Variation,Rgb<128,0,0>>>,RotateColorsX<Variation,Rgb<80,0,0>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<Orange>,
  ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<800>>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,150,150>>,40>,TrFade<500>>,EFFECT_RETRACTION>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<400>,TrWipeInSparkTip<White,500>>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<500>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<500>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<500>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<500>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<500>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<500>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<2000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Blue>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,White>,Rgb<50,50,50>>
,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Snow>,RotateColorsX<Int<4000>,RotateColorsX<Variation,White>>>,White,50>>,
SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelay<1394>>,EFFECT_PREON>>>(),

//  led 1

StylePtr<Layers<TransitionLoop<Black,TrConcat<TrDelay<3000>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,TrBoing<2000,5>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30000>,TrFade<300>>,AlphaL<RandomBlink<10000,RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>,Black>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,TrFade<300>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Int<0>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrSparkX<Remap<CenterDistF<>,Stripes<1200,-3600,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,Int<30>,Scale<Sum<ClashImpactF<>,SwingSpeed<600>>,Int<100>,Int<400>>,Int<16384>>,SaberBase::LOCKUP_NORMAL>,LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrInstant,TrConcat<TrInstant,Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrFade<1000>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<OFF_COLOR_ARG,Rgb<0,255,0>>,2000>>>>(),


// led 2

StylePtr<Layers<TransitionLoop<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,TrConcat<TrBoing<3000,9>,Black,TrDelay<2000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30000>,TrFade<300>>,AlphaL<RandomBlink<10000,RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>,Black>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,TrFade<300>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Int<0>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrSparkX<Remap<CenterDistF<>,Stripes<1200,-3600,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,Int<30>,Scale<Sum<ClashImpactF<>,SwingSpeed<600>>,Int<100>,Int<400>>,Int<16384>>,SaberBase::LOCKUP_NORMAL>,LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrInstant,TrConcat<TrInstant,Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrFade<1000>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<OFF_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),
"plasma_kyber"},

};

//----------------------------------------------------------------------------------------

BladeConfig blades[] = {  
{ 0,
  WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2,bladePowerPin3> >(),
  WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
  WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
CONFIGARRAY(blade_1) },

{ 750000,
  WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2,bladePowerPin3> >(),
  WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
  WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
CONFIGARRAY(blade_2) }
};

#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
