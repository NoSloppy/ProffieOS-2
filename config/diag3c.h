// ProffieOS7 Config File
#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 1
const unsigned int maxLedsPerStrip = 144;
#define VOLUME 1000
#define CLASH_THRESHOLD_G 3
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#endif
#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif
#ifdef CONFIG_PRESETS
Preset presets[] = {
{ "jayblaster", "jayblaster/tracks/mando.wav",
StylePtr<Layers<
StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,Gradient<Red,Black,Black,Black>,RotateColorsX<Variation,Black>,Pulsing<RotateColorsX<Variation,Black>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Black>,Black>,2000>,Pulsing<RotateColorsX<Variation,Black>,RotateColorsX<Variation,Rgb<5,0,0>>,3000>>,
LockupTrL<Cylon<DodgerBlue,5,1,DodgerBlue,20,175,1>,TrConcat<TrFade<100>,LightCyan,TrFade<100>>,TrWipeSparkTip<White,250,40>,SaberBase::LOCKUP_NORMAL>,
ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<-100>,Int<30000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
MultiTransitionEffectL<TrConcat<TrDelay<300>,AlphaL<AudioFlickerL<Magenta>,SmoothStep<Int<6000>,Int<-4000>>>,TrDelay<250>,AlphaL<AudioFlickerL<OrangeRed>,SmoothStep<Int<6000>,Int<-4000>>>,TrFade<350>>,EFFECT_BLAST>,
AlphaL<Mix<IsLessThan<BladeAngle<>,Int<26000>>,MultiTransitionEffectL<TrConcat<TrWipeIn<100>,White,TrWipeIn<200>>,EFFECT_STAB,2>,MultiTransitionEffectL<TrConcat<TrWipe<150>,LightCyan,TrWipe<200>>,EFFECT_BLAST>>,Int<32768>>,
AlphaL<Mix<IsLessThan<BladeAngle<>,Int<26000>>,MultiTransitionEffectL<TrConcat<TrWipeIn<-350>,White,TrWipeIn<350>>,EFFECT_STAB,2>,MultiTransitionEffectL<TrConcat<TrWipe<175>,Red,TrWipe<175>>,EFFECT_BLAST>>,Int<32768>>,
ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,Int<20000>>,
LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<20000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
LockupTrL<StyleFire<Black,Cyan,0,3,FireConfig<3000,3000,1>,FireConfig<2200,0,0>,FireConfig<10,2000,0>,FireConfig<0,0,5>>,TrWipeSparkTipX<Red,Int<250>,Int<2000>>,TrFade<300>,SaberBase::LOCKUP_MELT>,
InOutTrL<TrWipe<300>,TrWipeInSparkTip<White,300>,Black,2>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Black>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,TrDelay<2000>>,EFFECT_RETRACTION>,
TransitionEffectL<TrConcat<TrFade<750>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Blue>,10>,Bump<Int<0>,Int<4000>>>,TrFade<700>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Red>,15>,Bump<Int<0>,Int<5000>>>,TrFade<500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,White>,20>,Bump<Int<0>,Int<6000>>>,TrBoing<300,3>>,EFFECT_PREON>>>()},
};
BladeConfig blades[] = {
{ 0, WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), CONFIGARRAY(presets) },
};
#endif
#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
#endif