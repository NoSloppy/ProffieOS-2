#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
// #define NUM_BLADES 6
#define NUM_BLADES 1
#define NUM_BUTTONS 2
#define VOLUME 150
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 2.0
//If not disabled, Armor Readout play back floats around current Armor value.
#define DISABLE_NO_REPEAT_RANDOM
#define IDLE_OFF_TIME 9999999
// #define HEV_RANDOM_EVENT_INTERVAL_MS 10000
// #define HEV_RANDOM_HAZARD_CHANCE 95
#define MOUNT_SD_SETTING

#endif

#ifdef CONFIG_PROP
#include "../props/hev.h"
#endif

// All HALF-LIFE sfx audio can be found in the game's "sound" directory.
// Specifically, HEV Suit voice lines can be found within the "fvox" dir.
// The music tracks can be found in the "media" dir in the root folder.

#ifdef CONFIG_PRESETS
Preset armor[] = {

{ "hev;HEVcommon", "HEVcommon/tracks/hl1_ost/10 Valve Theme [Extended].wav",
// Left front (inner LED =1)
StylePtr<Layers<
  ColorSelect<AltF,TrFade<300>,Mix<Int<16384>,Moccasin,Black>,TransitionLoop<Black,TrConcat<TrInstant,AlphaL<ImperialYellow,LayerFunctions<LinearSectionF<Int<5400>,Int<10900>>,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<333>,AlphaL<ImperialYellow,LinearSectionF<Int<16384>,Int<10900>>>,TrDelay<333>>>,RandomBlink<3000,Sparkle<Black,Green,3000,900>>,Pulsing<Mix<Int<16384>,Red,Black>,Black,800>,Pulsing<Gradient<Yellow,Black>,Gradient<Black,Black,Yellow>,800>,Pulsing<Gradient<Orange,Orange,Red,Red>,Gradient<Red,Red,Orange>,800>,Pulsing<Mix<Int<16384>,Black,Blue>,Black,800>>,
  // Physical Damage
  TransitionEffectL<TrSelect<EffectRandomF<EFFECT_CLASH>,TrConcat<TrSparkX<Red,Int<100>,Int<200>>,TrSparkX<Red,Int<100>,Int<300>>>,TrConcat<TrInstant,BrownNoiseFlicker<Black,Red,50>,TrFadeX<WavLen<EFFECT_CLASH>>>,TrConcat<TrInstant,BlinkingX<Red,Black,Scale<RandomF,Int<300>,Int<700>>,Scale<RandomF,Int<0>,Int<1000>>>,TrFadeX<WavLen<EFFECT_CLASH>>>>,EFFECT_CLASH>,
  // Environmental Damage
  TransitionEffectL<TrConcat<TrInstant,ColorSelect<AltF,TrInstant,Mix<Int<16384>,Moccasin,Black>,Blinking<Black,Green,200,400>,Blinking<Yellow,Black,180,400>,Blinking<Yellow,Orange,200,400>,Blinking<ViolentViolet,Flamingo,200,400>,Blinking<SafetyOrange,Red,200,400>,Blinking<Cyan,BlueRibbon,200,400>>,TrJoin<TrFade<500>,TrBoing<500,4>>>,EFFECT_STUN>,

  // Armor Readout
  TransitionEffectL<TrConcat<TrInstant,Orange,TrFade<240>,Black,TrInstant,Orange,TrFade<240>,Black,TrFade<1000>,
    Layers<Black,AlphaL<Gradient<Orange,Blue>,SmoothStep<Variation,Int<-1>>>>,TrFade<1000>,Black,TrFade<1000>,
    Layers<Black,AlphaL<Gradient<Orange,Blue>,SmoothStep<Variation,Int<-1>>>>,TrFade<1000>>,EFFECT_USER8>,
  // Health Warning Beeps
  TransitionEffectL<TrConcat<TrInstant,Red,TrDelay<400>,Black,TrDelay<50>,Yellow,TrDelay<400>,Black,TrDelay<50>,Red,TrDelay<400>,Black,TrDelay<100>>,EFFECT_USER1_STEP2>,
  // Health Alert
  // TransitionEffectL<TrConcat<TrDelay<1400>,Black,TrFade<300>,Cylon<Red,5,20,Gradient<Red,Red,Green>,33,50,1>,TrDelayX<Int<4000>>,TrFade<300>,Black,TrFade<300>>,EFFECT_USER1>,
  TransitionEffectL<TrConcat<TrDelay<1400>,Black,TrFade<300>,Cylon<Red,5,20,Gradient<Red,Red,Green>,33,50,1>,TrDelayX<Percentage<WavLen<EFFECT_USER1_STEP2>,70>>,TrFade<300>,Black,TrFade<300>>,EFFECT_USER1_STEP2>,
  // Armor Compromised
  // TransitionEffectL<TrConcat<TrInstant,Cylon<Red,20,150,Red,20,150,1>,TrDelayX<Int<2500>>>,EFFECT_USER2>,
  TransitionEffectL<TrConcat<TrInstant,Cylon<Red,20,150,Red,20,150,1>,TrDelayX<WavLen<EFFECT_USER2_STEP2>>>,EFFECT_USER2_STEP2>,
  // Healing
  LockupTrL<StripesX<Int<200>,Int<3000>,
      White,White,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,
      Green,Green,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>>,
    TrConcat<TrInstant,
    Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
    Black,TrDelay<25>,
    Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
    Black,TrDelay<100>,
    TrWipeInSparkTip<White,350,100>,Cyan,TrWipeIn<200>,Black,TrInstant,
    StripesX<Int<200>,Scale<Trigger<EFFECT_LOCKUP_BEGIN,Int<10000>,Int<1000>,Int<1>>,Int<300>,Int<3000>>,
    White,White,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,
    Green,Green,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>>,
    TrDelay<10000>>,TrInstant,SaberBase::LOCKUP_NORMAL>,
  TransitionEffectL<TrConcat<TrInstant,Pulsing<Green,Cyan,400>,TrFade<2000>>,EFFECT_LOCKUP_END>,
  //Armor fill
  LockupTrL<Stripes<200,1000,Black,Black,DeepSkyBlue,Black,Black,Orange>,
    TrConcat<TrInstant,
    Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
    Layers<Black,AlphaL<Orange,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
    Layers<Black,AlphaL<White,LinearSectionF<Int<16384>,Int<10900>>>>,TrDelay<50>,
    Layers<Black,AlphaL<Orange,LinearSectionF<Int<16384>,Int<10900>>>>,TrDelay<50>,
    Layers<Black,AlphaL<White,LinearSectionF<Int<5400>,Int<10900>>>>,TrDelay<50>,
    Layers<Black,AlphaL<Orange,LinearSectionF<Int<5400>,Int<10900>>>>,TrDelay<50>,
    Black,TrDelay<100>,White,TrFade<500>,Orange,TrFade<500>>,
    TrConcat<TrInstant,Strobe<Black,Orange,15,20>,TrDelay<200>,DeepSkyBlue,TrFade<150>,Black,TrInstant,Orange,TrFade<200>,Black,TrInstant>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    InOutTrL<TrConcat<TrInstant,White,TrDelay<800>,TrSmoothFade<1200>>,TrInstant>
>>(),

// // Left shoulder (inner LED =1)
// StylePtr<Layers<
//   ColorSelect<AltF,TrFade<300>,Mix<Int<16384>,Moccasin,Black>,TransitionLoop<Black,TrConcat<TrInstant,AlphaL<ImperialYellow,LayerFunctions<LinearSectionF<Int<5400>,Int<10900>>,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<333>,AlphaL<ImperialYellow,LinearSectionF<Int<16384>,Int<10900>>>,TrDelay<333>>>,RandomBlink<3000,Sparkle<Black,Green,3000,900>>,Pulsing<Mix<Int<16384>,Red,Black>,Black,800>,Pulsing<Gradient<Yellow,Black>,Gradient<Black,Yellow>,800>,Pulsing<Gradient<Red,Orange>,Gradient<Orange,Red>,800>,Pulsing<Mix<Int<16384>,Black,Blue>,Black,800>>,
//   TransitionEffectL<TrSelect<EffectRandomF<EFFECT_CLASH>,TrConcat<TrSparkX<Red,Int<100>,Int<200>>,TrSparkX<Red,Int<100>,Int<300>>>,TrConcat<TrInstant,BrownNoiseFlicker<Black,Red,50>,TrFadeX<WavLen<EFFECT_CLASH>>>,TrConcat<TrInstant,BlinkingX<Red,Black,Scale<RandomF,Int<300>,Int<700>>,Scale<RandomF,Int<0>,Int<1000>>>,TrFadeX<WavLen<EFFECT_CLASH>>>>,EFFECT_CLASH>,
//   TransitionEffectL<TrConcat<TrInstant,ColorSelect<AltF,TrInstant,Mix<Int<16384>,Moccasin,Black>,Blinking<Black,Green,200,400>,Blinking<Yellow,Black,180,400>,Blinking<Yellow,Orange,200,400>,Blinking<ViolentViolet,Flamingo,200,400>,Blinking<SafetyOrange,Red,200,400>,Blinking<Cyan,BlueRibbon,200,400>>,TrJoin<TrFade<500>,TrBoing<500,4>>>,EFFECT_STUN>,
//   // Healing
//   LockupTrL<StripesX<Int<200>,Int<3000>,
//       White,White,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,
//       Green,Green,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>>,
//     TrConcat<TrInstant,
//     Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
//     Black,TrDelay<25>,
//     Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
//     Black,TrDelay<100>,
//     TrWipeInSparkTip<White,350,100>,Cyan,TrWipeIn<200>,Black,TrInstant,
//     StripesX<Int<200>,Scale<Trigger<EFFECT_LOCKUP_BEGIN,Int<10000>,Int<1000>,Int<1>>,Int<300>,Int<3000>>,
//     White,White,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,
//     Green,Green,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>>,
//     TrDelay<10000>>,TrInstant,SaberBase::LOCKUP_NORMAL>,
//   TransitionEffectL<TrConcat<TrInstant,Pulsing<Green,Cyan,400>,TrFade<2000>>,EFFECT_LOCKUP_END>,
//   //Armor fill
//   LockupTrL<Stripes<200,1000,Black,Black,DeepSkyBlue,Black,Black,Orange>,TrConcat<TrInstant,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<16384>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<16384>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<5400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<5400>,Int<10900>>>>,TrDelay<50>,Black,TrDelay<100>,White,TrFade<500>,ImperialYellow,TrInstant,Orange,TrFade<500>>,TrFade<100>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Armor Compromised
//   TransitionEffectL<TrConcat<TrInstant,Cylon<Red,20,150,Red,20,150,1>,TrDelay<2000>>,EFFECT_USER2>,
//   // Armor Readout
//   TransitionEffectL<TrConcat<TrInstant,Orange,TrDelay<400>,Black,TrDelay<50>,Blue,TrDelay<400>,Black,TrDelay<50>,Orange,TrDelay<400>,Black,TrDelay<50>,TrJoin<TrConcat<TrDelayX<WavLen<EFFECT_USER8>>,TrDoEffect<TrInstant,EFFECT_RELOAD>>,TrLoopUntil<EffectPulseF<EFFECT_RELOAD>,TrConcat<TrFade<200>,AlphaL<Gradient<Blue,Blue,Orange>,SmoothStep<Variation,Int<-1>>>,TrBoing<2000,2>>,TrFade<100>>>>,EFFECT_USER8>,
//   InOutTrL<TrConcat<TrInstant,White,TrDelay<800>,TrSmoothFade<1200>>,TrInstant>
// >>(),

// // Left back (bottom = LED 1)
// StylePtr<Layers<
//   ColorSelect<AltF,TrFade<300>,Mix<Int<16384>,Red,Black>,TransitionLoop<Black,TrConcat<TrInstant,AlphaL<ImperialYellow,LayerFunctions<LinearSectionF<Int<5400>,Int<10900>>,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<333>,AlphaL<ImperialYellow,LinearSectionF<Int<16384>,Int<10900>>>,TrDelay<333>>>,RandomBlink<3000,Sparkle<Black,Green,3000,900>>,Pulsing<Mix<Int<16384>,Red,Black>,Black,800>,Pulsing<Gradient<Yellow,Black>,Gradient<Black,Yellow>,800>,Pulsing<Gradient<Red,Orange>,Gradient<Orange,Red>,800>,Pulsing<Mix<Int<16384>,Black,Blue>,Black,800>>,
//   TransitionEffectL<TrSelect<EffectRandomF<EFFECT_CLASH>,TrConcat<TrSparkX<Red,Int<100>,Int<200>>,TrSparkX<Red,Int<100>,Int<300>>>,TrConcat<TrInstant,BrownNoiseFlicker<Black,Red,50>,TrFadeX<WavLen<EFFECT_CLASH>>>,TrConcat<TrInstant,BlinkingX<Red,Black,Scale<RandomF,Int<300>,Int<700>>,Scale<RandomF,Int<0>,Int<1000>>>,TrFadeX<WavLen<EFFECT_CLASH>>>>,EFFECT_CLASH>,
//   TransitionEffectL<TrConcat<TrInstant,ColorSelect<AltF,TrInstant,Mix<Int<16384>,Moccasin,Black>,Blinking<Black,Green,200,400>,Blinking<Yellow,Black,180,400>,Blinking<Yellow,Orange,200,400>,Blinking<ViolentViolet,Flamingo,200,400>,Blinking<SafetyOrange,Red,200,400>,Blinking<Cyan,BlueRibbon,200,400>>,TrJoin<TrFade<500>,TrBoing<500,4>>>,EFFECT_STUN>,
//   // Healing
//   LockupTrL<StripesX<Int<200>,Int<3000>,
//       White,White,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,
//       Green,Green,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>>,
//     TrConcat<TrInstant,
//     Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
//     Black,TrDelay<25>,
//     Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
//     Black,TrDelay<100>,
//     TrWipeInSparkTip<White,350,100>,Cyan,TrWipeIn<200>,Black,TrInstant,
//     StripesX<Int<200>,Scale<Trigger<EFFECT_LOCKUP_BEGIN,Int<10000>,Int<1000>,Int<1>>,Int<300>,Int<3000>>,
//     White,White,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,
//     Green,Green,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>>,
//     TrDelay<10000>>,TrInstant,SaberBase::LOCKUP_NORMAL>,
//   TransitionEffectL<TrConcat<TrInstant,Pulsing<Green,Cyan,400>,TrFade<2000>>,EFFECT_LOCKUP_END>,
//   //Armor fill
//   LockupTrL<Stripes<200,1000,Black,Black,DeepSkyBlue,Black,Black,Orange>,TrConcat<TrInstant,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<16384>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<16384>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<5400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<5400>,Int<10900>>>>,TrDelay<50>,Black,TrDelay<100>,White,TrFade<500>,ImperialYellow,TrInstant,Orange,TrFade<500>>,TrFade<100>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Armor Compromised
//   TransitionEffectL<TrConcat<TrInstant,Cylon<Red,20,150,Red,20,150,1>,TrDelay<2000>>,EFFECT_USER2>,
//   // Armor Readout
//   TransitionEffectL<TrConcat<TrInstant,Orange,TrDelay<400>,Black,TrDelay<50>,Blue,TrDelay<400>,Black,TrDelay<50>,Orange,TrDelay<400>,Black,TrDelay<50>,TrJoin<TrConcat<TrDelayX<WavLen<EFFECT_USER8>>,TrDoEffect<TrInstant,EFFECT_RELOAD>>,TrLoopUntil<EffectPulseF<EFFECT_RELOAD>,TrConcat<TrFade<200>,AlphaL<Gradient<Blue,Blue,Orange>,SmoothStep<Variation,Int<-1>>>,TrBoing<2000,2>>,TrFade<100>>>>,EFFECT_USER8>,
//   InOutTrL<TrConcat<TrInstant,White,TrDelay<800>,TrSmoothFade<1200>>,TrInstant>
// >>(),

// // Right back (bottom = LED 1)
// StylePtr<Layers<
//   ColorSelect<AltF,TrFade<300>,Mix<Int<16384>,Red,Black>,TransitionLoop<Black,TrConcat<TrInstant,AlphaL<ImperialYellow,LayerFunctions<LinearSectionF<Int<5400>,Int<10900>>,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<333>,AlphaL<ImperialYellow,LinearSectionF<Int<16384>,Int<10900>>>,TrDelay<333>>>,RandomBlink<3000,Sparkle<Black,Green,3000,900>>,Pulsing<Mix<Int<16384>,Red,Black>,Black,800>,Pulsing<Gradient<Yellow,Black>,Gradient<Black,Yellow>,800>,Pulsing<Gradient<Red,Orange>,Gradient<Orange,Red>,800>,Pulsing<Mix<Int<16384>,Black,Blue>,Black,800>>,
//   TransitionEffectL<TrSelect<EffectRandomF<EFFECT_CLASH>,TrConcat<TrSparkX<Red,Int<100>,Int<200>>,TrSparkX<Red,Int<100>,Int<300>>>,TrConcat<TrInstant,BrownNoiseFlicker<Black,Red,50>,TrFadeX<WavLen<EFFECT_CLASH>>>,TrConcat<TrInstant,BlinkingX<Red,Black,Scale<RandomF,Int<300>,Int<700>>,Scale<RandomF,Int<0>,Int<1000>>>,TrFadeX<WavLen<EFFECT_CLASH>>>>,EFFECT_CLASH>,
//   TransitionEffectL<TrConcat<TrInstant,ColorSelect<AltF,TrInstant,Mix<Int<16384>,Moccasin,Black>,Blinking<Black,Green,200,400>,Blinking<Yellow,Black,180,400>,Blinking<Yellow,Orange,200,400>,Blinking<ViolentViolet,Flamingo,200,400>,Blinking<SafetyOrange,Red,200,400>,Blinking<Cyan,BlueRibbon,200,400>>,TrJoin<TrFade<500>,TrBoing<500,4>>>,EFFECT_STUN>,
//   // Healing
//   LockupTrL<StripesX<Int<200>,Int<3000>,
//       White,White,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,
//       Green,Green,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>>,
//     TrConcat<TrInstant,
//     Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
//     Black,TrDelay<25>,
//     Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
//     Black,TrDelay<100>,
//     TrWipeInSparkTip<White,350,100>,Cyan,TrWipeIn<200>,Black,TrInstant,
//     StripesX<Int<200>,Scale<Trigger<EFFECT_LOCKUP_BEGIN,Int<10000>,Int<1000>,Int<1>>,Int<300>,Int<3000>>,
//     White,White,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,
//     Green,Green,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>>,
//     TrDelay<10000>>,TrInstant,SaberBase::LOCKUP_NORMAL>,
//   TransitionEffectL<TrConcat<TrInstant,Pulsing<Green,Cyan,400>,TrFade<2000>>,EFFECT_LOCKUP_END>,
//   //Armor fill
//   LockupTrL<Stripes<200,1000,Black,Black,DeepSkyBlue,Black,Black,Orange>,TrConcat<TrInstant,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<16384>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<16384>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<5400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<5400>,Int<10900>>>>,TrDelay<50>,Black,TrDelay<100>,White,TrFade<500>,ImperialYellow,TrInstant,Orange,TrFade<500>>,TrFade<100>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Armor Compromised
//   TransitionEffectL<TrConcat<TrInstant,Cylon<Red,20,150,Red,20,150,1>,TrDelay<2000>>,EFFECT_USER2>,
//   // Armor Readout
//   TransitionEffectL<TrConcat<TrInstant,Orange,TrDelay<400>,Black,TrDelay<50>,Blue,TrDelay<400>,Black,TrDelay<50>,Orange,TrDelay<400>,Black,TrDelay<50>,TrJoin<TrConcat<TrDelayX<WavLen<EFFECT_USER8>>,TrDoEffect<TrInstant,EFFECT_RELOAD>>,TrLoopUntil<EffectPulseF<EFFECT_RELOAD>,TrConcat<TrFade<200>,AlphaL<Gradient<Blue,Blue,Orange>,SmoothStep<Variation,Int<-1>>>,TrBoing<2000,2>>,TrFade<100>>>>,EFFECT_USER8>,
//   InOutTrL<TrConcat<TrInstant,White,TrDelay<800>,TrSmoothFade<1200>>,TrInstant>
// >>(),

// // Right shoulder (inner LED =1)
// StylePtr<Layers<
//   ColorSelect<AltF,TrFade<300>,Mix<Int<16384>,Moccasin,Black>,TransitionLoop<Black,TrConcat<TrInstant,AlphaL<ImperialYellow,LayerFunctions<LinearSectionF<Int<5400>,Int<10900>>,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<333>,AlphaL<ImperialYellow,LinearSectionF<Int<16384>,Int<10900>>>,TrDelay<333>>>,RandomBlink<3000,Sparkle<Black,Green,3000,900>>,Pulsing<Mix<Int<16384>,Red,Black>,Black,800>,Pulsing<Gradient<Yellow,Black>,Gradient<Black,Yellow>,800>,Pulsing<Gradient<Red,Orange>,Gradient<Orange,Red>,800>,Pulsing<Mix<Int<16384>,Black,Blue>,Black,800>>,
//   TransitionEffectL<TrSelect<EffectRandomF<EFFECT_CLASH>,TrConcat<TrSparkX<Red,Int<100>,Int<200>>,TrSparkX<Red,Int<100>,Int<300>>>,TrConcat<TrInstant,BrownNoiseFlicker<Black,Red,50>,TrFadeX<WavLen<EFFECT_CLASH>>>,TrConcat<TrInstant,BlinkingX<Red,Black,Scale<RandomF,Int<300>,Int<700>>,Scale<RandomF,Int<0>,Int<1000>>>,TrFadeX<WavLen<EFFECT_CLASH>>>>,EFFECT_CLASH>,
//   TransitionEffectL<TrConcat<TrInstant,ColorSelect<AltF,TrInstant,Mix<Int<16384>,Moccasin,Black>,Blinking<Black,Green,200,400>,Blinking<Yellow,Black,180,400>,Blinking<Yellow,Orange,200,400>,Blinking<ViolentViolet,Flamingo,200,400>,Blinking<SafetyOrange,Red,200,400>,Blinking<Cyan,BlueRibbon,200,400>>,TrJoin<TrFade<500>,TrBoing<500,4>>>,EFFECT_STUN>,
//   // Healing
//   LockupTrL<StripesX<Int<200>,Int<3000>,
//       White,White,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,
//       Green,Green,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>>,
//     TrConcat<TrInstant,
//     Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
//     Black,TrDelay<25>,
//     Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
//     Black,TrDelay<100>,
//     TrWipeInSparkTip<White,350,100>,Cyan,TrWipeIn<200>,Black,TrInstant,
//     StripesX<Int<200>,Scale<Trigger<EFFECT_LOCKUP_BEGIN,Int<10000>,Int<1000>,Int<1>>,Int<300>,Int<3000>>,
//     White,White,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,
//     Green,Green,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>>,
//     TrDelay<10000>>,TrInstant,SaberBase::LOCKUP_NORMAL>,
//   TransitionEffectL<TrConcat<TrInstant,Pulsing<Green,Cyan,400>,TrFade<2000>>,EFFECT_LOCKUP_END>,
//   //Armor fill
//   LockupTrL<Stripes<200,1000,Black,Black,DeepSkyBlue,Black,Black,Orange>,TrConcat<TrInstant,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<16384>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<16384>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<5400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<5400>,Int<10900>>>>,TrDelay<50>,Black,TrDelay<100>,White,TrFade<500>,ImperialYellow,TrInstant,Orange,TrFade<500>>,TrFade<100>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Armor Compromised
//   TransitionEffectL<TrConcat<TrInstant,Cylon<Red,20,150,Red,20,150,1>,TrDelay<2000>>,EFFECT_USER2>,
//   // Armor Readout
//   TransitionEffectL<TrConcat<TrInstant,Orange,TrDelay<400>,Black,TrDelay<50>,Blue,TrDelay<400>,Black,TrDelay<50>,Orange,TrDelay<400>,Black,TrDelay<50>,TrJoin<TrConcat<TrDelayX<WavLen<EFFECT_USER8>>,TrDoEffect<TrInstant,EFFECT_RELOAD>>,TrLoopUntil<EffectPulseF<EFFECT_RELOAD>,TrConcat<TrFade<200>,AlphaL<Gradient<Blue,Blue,Orange>,SmoothStep<Variation,Int<-1>>>,TrBoing<2000,2>>,TrFade<100>>>>,EFFECT_USER8>,
//   InOutTrL<TrConcat<TrInstant,White,TrDelay<800>,TrSmoothFade<1200>>,TrInstant>
// >>(),

// // Right front (inner LED =1)
// StylePtr<Layers<
//   ColorSelect<AltF,TrFade<300>,Mix<Int<16384>,Moccasin,Black>,TransitionLoop<Black,TrConcat<TrInstant,AlphaL<ImperialYellow,LayerFunctions<LinearSectionF<Int<5400>,Int<10900>>,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<333>,AlphaL<ImperialYellow,LinearSectionF<Int<16384>,Int<10900>>>,TrDelay<333>>>,RandomBlink<3000,Sparkle<Black,Green,3000,900>>,Pulsing<Mix<Int<16384>,Red,Black>,Black,800>,Pulsing<Gradient<Yellow,Black>,Gradient<Black,Yellow>,800>,Pulsing<Gradient<Red,Orange>,Gradient<Orange,Red>,800>,Pulsing<Mix<Int<16384>,Black,Blue>,Black,800>>,
//   TransitionEffectL<TrSelect<EffectRandomF<EFFECT_CLASH>,TrConcat<TrSparkX<Red,Int<100>,Int<200>>,TrSparkX<Red,Int<100>,Int<300>>>,TrConcat<TrInstant,BrownNoiseFlicker<Black,Red,50>,TrFadeX<WavLen<EFFECT_CLASH>>>,TrConcat<TrInstant,BlinkingX<Red,Black,Scale<RandomF,Int<300>,Int<700>>,Scale<RandomF,Int<0>,Int<1000>>>,TrFadeX<WavLen<EFFECT_CLASH>>>>,EFFECT_CLASH>,
//   TransitionEffectL<TrConcat<TrInstant,ColorSelect<AltF,TrInstant,Mix<Int<16384>,Moccasin,Black>,Blinking<Black,Green,200,400>,Blinking<Yellow,Black,180,400>,Blinking<Yellow,Orange,200,400>,Blinking<ViolentViolet,Flamingo,200,400>,Blinking<SafetyOrange,Red,200,400>,Blinking<Cyan,BlueRibbon,200,400>>,TrJoin<TrFade<500>,TrBoing<500,4>>>,EFFECT_STUN>,
//   // Healing
//   LockupTrL<StripesX<Int<200>,Int<3000>,
//       White,White,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,
//       Green,Green,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>>,
//     TrConcat<TrInstant,
//     Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
//     Black,TrDelay<25>,
//     Layers<Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,
//     Black,TrDelay<100>,
//     TrWipeInSparkTip<White,350,100>,Cyan,TrWipeIn<200>,Black,TrInstant,
//     StripesX<Int<200>,Scale<Trigger<EFFECT_LOCKUP_BEGIN,Int<10000>,Int<1000>,Int<1>>,Int<300>,Int<3000>>,
//     White,White,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,
//     Green,Green,Green,Green,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>,Mix<Int<26000>,Cyan,Black>>,
//     TrDelay<10000>>,TrInstant,SaberBase::LOCKUP_NORMAL>,
//   TransitionEffectL<TrConcat<TrInstant,Pulsing<Green,Cyan,400>,TrFade<2000>>,EFFECT_LOCKUP_END>,
//   //Armor fill
//   LockupTrL<Stripes<200,1000,Black,Black,DeepSkyBlue,Black,Black,Orange>,TrConcat<TrInstant,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<27400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<16384>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<16384>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<White,LinearSectionF<Int<5400>,Int<10900>>>>,TrDelay<50>,Layers<
//   Black,AlphaL<ImperialYellow,LinearSectionF<Int<5400>,Int<10900>>>>,TrDelay<50>,Black,TrDelay<100>,White,TrFade<500>,ImperialYellow,TrInstant,Orange,TrFade<500>>,TrFade<100>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Armor Compromised
//   TransitionEffectL<TrConcat<TrInstant,Cylon<Red,20,150,Red,20,150,1>,TrDelay<2000>>,EFFECT_USER2>,
//   // Armor Readout
//   TransitionEffectL<TrConcat<TrInstant,Orange,TrDelay<400>,Black,TrDelay<50>,Blue,TrDelay<400>,Black,TrDelay<50>,Orange,TrDelay<400>,Black,TrDelay<50>,TrJoin<TrConcat<TrDelayX<WavLen<EFFECT_USER8>>,TrDoEffect<TrInstant,EFFECT_RELOAD>>,TrLoopUntil<EffectPulseF<EFFECT_RELOAD>,TrConcat<TrFade<200>,AlphaL<Gradient<Blue,Blue,Orange>,SmoothStep<Variation,Int<-1>>>,TrBoing<2000,2>>,TrFade<100>>>>,EFFECT_USER8>,
//   InOutTrL<TrConcat<TrInstant,White,TrDelay<800>,TrSmoothFade<1200>>,TrInstant>
// >>(),
"test_for_LED1"
},

// storage:
// - Old shock state for alt006
// TransitionLoop<Black,TrConcat<TrDelay<1000>,BlueRibbon,TrBoing<600,3>>>


// stun



//006
//TrConcat<TrInstant,Blinking<Cyan,BlueRibbon,200,300>,TrJoin<TrFade<1000>,TrBoing<1000,6>>>

// LED1
// LinearSectionF<Int<5400>,Int<10900>>

// LED2
// LinearSectionF<Int<16384>,Int<10900>>

// LED3
// LinearSectionF<Int<27400>,Int<10900>>


};

BladeConfig blades[] = {
{0, DimBlade(20.0, WS281XBladePtr<12, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ),
CONFIGARRAY(armor)}
// { 0,
//   SubBlade (15, 17, WS281XBladePtr<18, bladePin, Color8::RGB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ),  // // Left front (inner LED =1)
//   SubBlade (12, 14, NULL),  // Left shoulder (inner LED =1)
//   SubBlade (9, 11, NULL),  // Left back (bottom = LED 1)
//   SubBlade (6, 8, NULL),  // Right back (bottom = LED 1)
//   SubBladeReverse (3, 5, NULL),  // Right shoulder (inner LED =1)
//   SubBladeReverse (0, 2, NULL),  // Right front (inner LED =1)
// CONFIGARRAY(armor),
// "HEV_Suit_Save"}
};



#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif




