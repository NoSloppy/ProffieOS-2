#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 6
#define NUM_BUTTONS 2
#define VOLUME 1250
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 7
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
// #define ENABLE_SSD1306
#define COLOR_CHANGE_DIRECT
   // this enables "click to change"
#define SA22C_SWING_ON
#define SA22C_TWIST_OFF
#define SA22C_FORCE_PUSH
// #define GESTURE_AUTO_BATTLE_MODE
#define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
#define ENABLE_SPINS
#define NO_REPEAT_RANDOM
#define DISABLE_BASIC_PARSER_STYLES
// #define SAVE_STATE
#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE

#endif
 
#ifdef CONFIG_PROP
#include "../props/saber_sa22c_buttons.h"
#endif

//FET 1- Bottom Strip
//FET 2- Main Blade & CC
//FET 3- Main Blade & CC
//FET 4- Yellow Accent LED
//FET 5- YellowGreen Accent LED
//FET 6- Green Accent LED
 
//Data 1- Npx CC 5px
//Data 2- Main Blade
 
#ifdef CONFIG_PRESETS
Preset presets[] = {
{ "Ezra", "tracks/track1.wav",
  // Main Blade
  StylePtr<Layers<Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<24000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-1400>,Int<-100>>,RgbArg<BASE_COLOR_ARG,Rgb<30,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<30,255,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<30,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<30,255,0>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<30,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<30,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<30,255,0>>>,TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrFade<1200>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<85,85,200>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<85,85,200>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<85,85,200>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<85,85,200>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>>>(),
  // Crystal
  StylePtr<Layers<
    StyleFire<RgbArg<BASE_COLOR_ARG,Green>,Rgb<100,255,100>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,1500,0>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,RgbArg<BLAST_COLOR_ARG,White>,TrFade<200>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<OnSpark<StyleFire<RgbArg<LOCKUP_COLOR_ARG,Green>,Rgb<100,255,100>,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>>,White>>,
    TransitionEffectL<TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,White>,TrDelay<40>>,EFFECT_CLASH>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrFade<1000>,TrFade<500>,Sparkle<Black,White,7>>>>(),
  // Bottom Strip
  StylePtr<Layers<Mix<Bump<Sin<Int<180>>,Int<20000>>,Black,RotateColorsX<Variation,DarkOrange>>,LockupTrL<AudioFlickerL<DarkOrange>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,InOutTrL<TrFade<500>,TrFade<500>,Mix<Bump<Sin<Int<18>>,Int<20000>>,Black,RotateColorsX<Variation,DarkOrange>>>>>(),
  // 3mm Yellow
  StylePtr<Layers<
    Sequence<Black,White,400,4,0b111000000000000>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Black,White,4000>>>>(),
  // 3mm YellowGreen
  StylePtr<Layers<
    Sequence<Black,White,400,4,0b0011000000000000>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Black,White,4000>>>>(),
  // 3mm Green
  StylePtr<Layers<
    Sequence<Black,White,400,4,0b0001000000000000>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Black,White,4000>>>>()
}
};

BladeConfig blades[] = {
{ 0, // blade ID resistor not used
  //Main Blade & Crystal Sub 123 LEDs Data 1 Power 2/3
  SubBlade(1, 122, WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >()),
  SubBlade(0, 0, NULL),    
  // Bottom Strip 10 LEDs Data 2 Power 1
  WS281XBladePtr<10, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(),
  // 3mm Yellow LED Data NA Power 4
  SimpleBladePtr<CreeXPE2WhiteTemplate<36>, NoLED, NoLED, NoLED, bladePowerPin4, -1, -1, -1>(),
  // 3mm YellowGreen LED Data NA Power 5
  SimpleBladePtr<CreeXPE2WhiteTemplate<36>, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>(),
  // 3mm Green LED Data NA Power 6
  SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),
  CONFIGARRAY(presets)
}
};
#endif
 
#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif