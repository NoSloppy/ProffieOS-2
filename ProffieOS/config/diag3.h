#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
const unsigned int maxLedsPerStrip = 144;
#define EXTRA_COLOR_BUFFER_SPACE 60
#define VOLUME 1500
#define CLASH_THRESHOLD_G 5
#define AUDIO_CLASH_SUPPRESSION_LEVEL 10
#define PROFFIEOS_DONT_USE_GYRO_FOR_CLASH
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define MOTION_TIMEOUT 60 * 15 * 1000
#define IDLE_OFF_TIME 60 * 15 * 1000
#define DISABLE_BASIC_PARSER_STYLES
#define DISABLE_DIAGNOSTIC_COMMANDS
#define SHARED_POWER_PINS
#define NO_REPEAT_RANDOM
#define DISABLE_COLOR_CHANGE
#endif
 
 
#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif
 
 
#ifdef CONFIG_PRESETS
 
Preset presets[] = {

{ "Dark Saber;common", "tracks/Darksaber.wav",
StylePtr<Layers<
  AudioFlicker<BrownNoiseFlicker<Mix<SwingSpeed<400>,RotateColorsX<Variation,Rgb16<21919,21919,50739>>,RotateColorsX<Variation,Rgb16<20693,20693,49761>>>,Stripes<5000,-300,RotateColorsX<Variation,Rgb16<148,681,2521>>,RotateColorsX<Variation,Rgb16<148,681,2521>>,RotateColorsX<Variation,Rgb<10,10,20>>,RotateColorsX<Variation,Rgb<50,50,75>>>,300>,RotateColorsX<Variation,Rgb<35,35,75>>>,
  LockupTrL<Layers<
    AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<LightCyan,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<LightCyan,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<LightCyan,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveStabL<SteelBlue>,
  ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
  ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
  LockupTrL<AlphaL<BrownNoiseFlickerL<SteelBlue,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,SteelBlue,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"dark saber" },


{ "Obi-Wan - TPM;common", "tracks/TPM.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"obi wan - tpm" },


{ "Qui-Gon - TPM;common", "tracks/TPM.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb16<0,39252,0>>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"qui gon - tpm" },


{ "Maul;common", "tracks/TPM.wav",
  StylePtr<Layers<
    Stripes<16000,-1000,RotateColorsX<Variation,Rgb16<47835,0,0>>,Pulsing<RotateColorsX<Variation,Rgb16<65535,4975,4975>>,RotateColorsX<Variation,Rgb16<47835,0,0>>,800>,RotateColorsX<Variation,Rgb16<47835,0,0>>>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<30000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"maul" },
 
 
{ "Obi-Wan - AOTC;common", "tracks/Anakin_AOTC.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"obi-wan - aotc" },


{ "Anakin - AOTC;common", "tracks/Anakin_AOTC.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb16<0,7816,35507>>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
    ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"anakin - aotc" },


{ "Dooku - AOTC;common", "tracks/Dooku.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"dooku - aotc" },


{ "Obi-Wan - ROTS;common", "tracks/ROTS.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"obi-wan - rots" },


{ "Anakin - ROTS;common", "tracks/Anakin_ROTS.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb16<0,7816,35507>>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
    ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"anakin - rots" },


{ "Yoda - ROTS;common", "tracks/Yoda.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb16<0,39252,0>>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"yoda - rots" },


{ "Mace - ROTS;common", "tracks/ROTS.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Rgb16<14386,0,65535>>,RotateColorsX<Variation,Rgb16<8729,0,40112>>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"mace - rots" },


{ "Dooku - ROTS;common", "tracks/Dooku.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"dooku - rots" },


{ "Luke - ANH;common", "tracks/Luke_ANH.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb16<0,7816,35507>>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
    ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"luke - anh" },


{ "Palpatine;common", "tracks/Palpatine.wav",
  StylePtr<Layers<
    Stripes<16000,-1000,RotateColorsX<Variation,Rgb16<47835,0,0>>,Pulsing<RotateColorsX<Variation,Rgb16<65535,4975,4975>>,RotateColorsX<Variation,Rgb16<47835,0,0>>,800>,RotateColorsX<Variation,Rgb16<47835,0,0>>>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<30000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"Palpatine" },


{ "Luke - ESB;common", "tracks/Luke_ESB.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb16<0,7816,35507>>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
    ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"luke - esb" },


{ "Luke - ROTJ;common", "tracks/Luke_ROTJ.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb16<0,39252,0>>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"luke - rotj" },


{ "Vader - ROTJ;common", "tracks/Vader.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"vader - rotj" },


{ "Kylo;common", "tracks/Kylo.wav",
  StylePtr<Layers<
    Stripes<2000,-2500,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<30,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<30,0,0>>>>,
    TransitionLoopL<TrConcat<TrWaveX<RandomFlicker<RotateColorsX<Variation,Red>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,Black,300>>,Int<400>,Int<100>,Int<200>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1500>>,Int<200>,Int<1200>>>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Orange>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Red>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,TrDelay<300>>,EFFECT_PREON>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"kylo" },


{ "Rey;common", "tracks/Rey.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<90,65,0>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Green,Bump<Int<0>,Int<4000>>>,TrFade<300>,AlphaL<DodgerBlue,Bump<Int<0>,Int<4000>>>,TrFade<300>,AlphaL<DeepSkyBlue,Bump<Int<0>,Int<4000>>>,TrDelay<350>>,EFFECT_PREON>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"rey" },


{ "Shin Hati;common", "tracks/Ahsoka_2.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Rgb16<65535,10936,1442>>,RotateColorsX<Variation,Rgb16<49761,4182,0>>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"shin hati" },


{ "Marrok;common", "tracks/Ahsoka_2.wav",
  StylePtr<Layers<
    Mix<SwingSpeed<100>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<800>>,EFFECT_LOCKUP_END>,
    ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Blue,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    AlphaL<RotateColorsX<Variation,OrangeRed>,Bump<Int<0>,Int<8000>>>,
    ResponsiveStabL<Orange>,
    ResponsiveBlastFadeL<White,Scale<SwingSpeed<200>,Int<8000>,Int<16000>>>,
    ResponsiveBlastWaveL<White,Int<300>,Int<100>,Int<300>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,EFFECT_CLASH>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<500>,TrWipeIn<800>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"marrok" },


{ "Ahsoka - White Sabers;common", "tracks/Ahsoka.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<50,50,75>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    AlphaL<White,Bump<Int<0>,Int<8000>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"ahsoka - white sabers" },


{ "Ahsoka - CW;common", "tracks/CW.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
    ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"ahsoka - cw" },


{ "Ezra - Rebels (Blue);common", "tracks/Ezra.wav",    
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,DodgerBlue>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"ezra - rebels (blue)" },


{ "Ezra - Rebels (Green);common", "tracks/Ezra.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb16<0,39252,0>>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"ezra - rebels (green)" },


{ "Kanan - Rebels;common", "tracks/Kanan.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb16<0,7816,35507>>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
    ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"kanan - rebels" },


{ "Asajj Ventress - BB (Yellow);common", "tracks/Asajj.wav",
  StylePtr<Layers<
    HumpFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<120,120,0>>,50>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    AlphaL<RotateColorsX<Variation,Rgb<250,250,0>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<100>,Int<4000>>,Int<-4000>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"asajj ventress - bb (yellow)" },


{ "Arcann;common", "tracks/Arcann.wav",
  StylePtr<Layers<
    StripesX<Int<3500>,Int<1600>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb16<40112,40112,0>>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb16<25487,25487,0>>,RotateColorsX<Variation,Rgb16<40112,40112,0>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb16<57353,57353,0>>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb16<37562,37562,0>>,RotateColorsX<Variation,Rgb16<49761,49761,0>>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<DarkOrange,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<20000>>>,TrFade<400>>,TrConcat<TrInstant,Coral,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Rgb16<41421,26168,1662>,AudioFlicker<Rgb16<41421,26168,1662>,DarkOrange>,50,1>,TrConcat<TrInstant,AlphaL<DarkOrange,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<DarkOrange,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Orange>,
    ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,Orange,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<Orange,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"arcann" },


{ "Malak;common", "tracks/Malak.wav",
  StylePtr<Layers<
    StripesX<Int<3500>,Int<1600>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,0,0>>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<30,0,0>>,RotateColorsX<Variation,Rgb<128,0,0>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Rgb<255,25,25>>,RotateColorsX<Variation,Red>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Rgb<80,0,0>>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<DarkOrange,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<20000>>>,TrFade<400>>,TrConcat<TrInstant,Coral,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Rgb16<41421,26168,1662>,AudioFlicker<Rgb16<41421,26168,1662>,DarkOrange>,50,1>,TrConcat<TrInstant,AlphaL<DarkOrange,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<DarkOrange,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Orange>,
    ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,Orange,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<Orange,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"malak" },


{ "Malgus;common", "tracks/Malgus.wav",
  StylePtr<Layers<
    StripesX<Int<5000>,Int<-1400>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,0,0>>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<30,0,0>>,RotateColorsX<Variation,Rgb<128,0,0>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Rgb<255,25,25>>,RotateColorsX<Variation,Red>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Rgb<80,0,0>>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<DarkOrange,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<20000>>>,TrFade<400>>,TrConcat<TrInstant,Coral,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Rgb16<41421,26168,1662>,AudioFlicker<Rgb16<41421,26168,1662>,DarkOrange>,50,1>,TrConcat<TrInstant,AlphaL<DarkOrange,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<DarkOrange,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Orange>,
    ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,Orange,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<Orange,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"malgus" },


{ "Mara (Darkside);common", "tracks/Mara.wav",
  StylePtr<Layers<
    StripesX<Int<6000>,Scale<SlowNoise<Int<2000>>,Int<-1600>,Int<-3200>>,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<10,0,0>>>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<10,0,0>>,RotateColorsX<Variation,Rgb<128,0,0>>,300>,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<Black,RotateColorsX<Variation,Rgb<128,0,0>>>,RotateColorsX<Variation,Red>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"mara (darkside)" },


{ "Mara (Lightside);common", "tracks/Mara.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Rgb16<14386,0,65535>>,RotateColorsX<Variation,Rgb16<8729,0,40112>>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"mara (lightside)" },


{ "Revan (Lightside);common", "tracks/KOTOR.wav",
  StylePtr<Layers<
    Stripes<5000,-1500,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<30,0,50>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,110>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<Magenta>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<Magenta,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,Magenta,TrFade<400>>,TrConcat<TrInstant,Magenta,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Magenta,AudioFlicker<DeepPink,Magenta>,50,1>,TrConcat<TrInstant,AlphaL<Magenta,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<Magenta,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Magenta>,
    ResponsiveBlastL<Magenta,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<DeepPink,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<Magenta,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Magenta,DeepPink>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTip<Red,700>,TrWipeInSparkTip<Red,300>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"revan (lightside)" },


{ "Revan (Darkside);common", "tracks/KOTOR2.wav",
  StylePtr<Layers<
    Stripes<6000,-1750,RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<21301,0,0>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<DarkOrange>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<DarkOrange,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,Orange,TrFade<400>>,TrConcat<TrInstant,AlphaL<Mix<SmoothStep<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<1000>>,Stripes<1500,2000,DarkOrange,Red>,Stripes<1500,-2500,DarkOrange,Red>>,Int<18000>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<DarkOrange,AudioFlicker<DarkOrange,Orange>,50,1>,TrConcat<TrInstant,AlphaL<Orange,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<Orange,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Orange>,
    ResponsiveBlastL<Orange,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<Orange,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<Orange,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTip<Magenta,700>,TrWipeInSparkTip<Magenta,1000>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"revan (darkside)" },


{ "Satele;common", "tracks/KOTOR.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,SteelBlue>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"satele" },


{ "Trooper Saber;common", "tracks/Vader.wav",
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,SteelBlue>,RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,Cyan>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<400>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"trooper saber" },


{ "Cal Kestis;common", "tracks/Fallen.wav",
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
    InOutTrL<TrWipe<600>,TrWipeIn<600>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"cal kestis" },


{ "Trilla;common", "tracks/Trilla.wav",
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
    InOutTrL<TrWipeSparkTip<White,300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"trilla" },


{ "Galen Marek (Starkiller) TFU;common", "tracks/Starkiller.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
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

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"galen marek (starkiller) tfu" },


{ "Kyle Katarn - Jedi Outcast;common", "tracks/Katarn.wav",
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb16<0,7816,35507>>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
    ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<16000>>>,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"kyle katarn - jedi outcast" },

{ "Acolyte's Wrath;common", "tracks/KOTOR.wav",
  StylePtr<Layers<
    StripesX<Int<3500>,Int<1600>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,0,0>>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<30,0,0>>,RotateColorsX<Variation,Rgb<128,0,0>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Rgb<255,25,25>>,RotateColorsX<Variation,Red>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Rgb<80,0,0>>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<DarkOrange,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<20000>>>,TrFade<400>>,TrConcat<TrInstant,Coral,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Rgb16<41421,26168,1662>,AudioFlicker<Rgb16<41421,26168,1662>,DarkOrange>,50,1>,TrConcat<TrInstant,AlphaL<DarkOrange,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<DarkOrange,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Orange>,
    ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,DarkOrange,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,Orange,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<Orange,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"acolyte's wrath" },


{ "Arbiter;common", "tracks/Halo.wav",
  StylePtr<Layers<
    StyleFire<Strobe<RotateColorsX<Variation,DeepSkyBlue>,Strobe<Rgb<100,100,150>,RandomPerLEDFlicker<RotateColorsX<Variation,DeepSkyBlue>,Black>,50,1>,100,1>,RotateColorsX<Variation,Rgb<0,0,60>>,0,5,FireConfig<2,1000,5>,FireConfig<2,1000,5>,FireConfig<2,1000,5>,FireConfig<2,1000,5>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"arbiter" },


{ "Blood;common", "tracks/KOTOR.wav",
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<120,0,0>>,Rgb16<24816,0,0>>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<25,0,0>>,3000>>,
    AlphaL<StyleFire<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<22,0,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Orange>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrBoing<500,3>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"blood" },


{ "Bone Faction;common", "tracks/KOTOR.wav",
  StylePtr<Layers<
    StyleFire<Strobe<RotateColorsX<Variation,Rgb16<30830,30830,30830>>,Strobe<Rgb<100,100,150>,RandomPerLEDFlicker<RotateColorsX<Variation,Ivory>,Black>,50,1>,100,1>,RotateColorsX<Variation,Rgb16<14634,14634,14634>>,0,5,FireConfig<2,1000,5>,FireConfig<2,1000,5>,FireConfig<2,1000,5>,FireConfig<2,1000,5>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"bone" },


{ "Earth Bending;common", "tracks/Avatar.wav",
  StylePtr<Layers<
    StripesX<Int<3500>,Int<1600>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,200,0>>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<0,30,0>>,RotateColorsX<Variation,Rgb<0,128,0>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Rgb<25,255,25>>,RotateColorsX<Variation,Green>>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<0,20,0>>,RotateColorsX<Variation,Rgb<0,80,0>>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrWaveX<RotateColorsX<Variation,Green>,Int<150>,Int<300>,Int<150>,Int<32768>>,Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Green>>,TrWaveX<RotateColorsX<Variation,Green>,Int<125>,Int<300>,Int<125>,Int<32768>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Green>>,TrWaveX<RotateColorsX<Variation,Green>,Int<100>,Int<300>,Int<100>,Int<32768>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Green>>,TrWaveX<RotateColorsX<Variation,Green>,Int<75>,Int<300>,Int<75>,Int<32768>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Green>>,TrWaveX<RotateColorsX<Variation,Green>,Int<50>,Int<300>,Int<50>,Int<32768>>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Green>>,TrWipeIn<200>,Mix<SmoothStep<Int<33000>,Int<-2000>>,Black,RotateColorsX<Variation,Green>>,TrFade<300>>,TrConcat<TrWipe<50>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Green>>,TrWaveX<RotateColorsX<Variation,Green>,Int<50>,Int<300>,Int<50>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Green>>,TrWaveX<RotateColorsX<Variation,Green>,Int<75>,Int<300>,Int<75>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Green>>,TrWaveX<RotateColorsX<Variation,Green>,Int<100>,Int<300>,Int<100>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Green>>,TrWaveX<RotateColorsX<Variation,Green>,Int<100>,Int<300>,Int<100>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Green>>,TrWaveX<RotateColorsX<Variation,Green>,Int<125>,Int<300>,Int<125>,Int<0>>,Black,TrWaveX<RotateColorsX<Variation,Green>,Int<150>,Int<300>,Int<150>,Int<0>>,Black,TrInstant>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"earth bending" },


{ "Fire Bending;common", "tracks/Avatar.wav",
  StylePtr<Layers<
    Mix<BladeAngle<>,StyleFire<Gradient<RotateColorsX<Variation,Orange>,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,3,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,StyleFire<Gradient<RotateColorsX<Variation,Orange>,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,6,FireConfig<100,2000,5>,FireConfig<100,2000,5>,FireConfig<100,2000,5>,FireConfig<0,2000,5>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Orange>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<255,150,150>>>,TrFade<1200>>,EFFECT_RETRACTION>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<200>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"fire bending" },


{ "Flesh Faction;common", "tracks/KOTOR.wav",
  StylePtr<Layers<
    StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<TwistAngle<7>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Scale<TwistAngle<7>,Int<25>,Int<80>>,Pulsing<RotateColorsX<Variation,Rgb16<13655,882,329>>,RotateColorsX<Variation,Rgb<20,0,0>>,3000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Rgb<10,0,0>>>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<255,50,50>>>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<50,0,0>>,3000>>,
    AlphaL<StripesX<Sin<Int<8>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<60>,Int<140>>,StripesX<Sin<Int<6>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<-25>,Int<-80>>,Pulsing<Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<255,50,50>>>,RotateColorsX<Variation,Rgb<20,0,0>>,4000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb<255,50,50>>,Black>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<-25>,Int<-75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<255,50,50>>>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,Black,3000>>,Int<10000>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<Coral>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<Coral,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,DarkOrange,TrFade<400>>,TrConcat<TrInstant,DarkOrange,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Rgb16<13655,882,329>,AudioFlicker<DarkOrange,Coral>,50,1>,TrConcat<TrInstant,AlphaL<Coral,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<DarkOrange,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<DarkOrange>,
    ResponsiveBlastL<DarkOrange,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<DarkOrange,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<DarkOrange,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTip<OrangeRed,300>,TrWipeInSparkTip<OrangeRed,500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"flesh faction" },


{ "Glitch;common", "tracks/KOTOR.wav",
  StylePtr<Layers<
    StripesX<Int<6000>,Scale<SlowNoise<Int<2000>>,Int<-1600>,Int<-3200>>,RotateColorsX<Variation,Rgb<95,0,210>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<30,0,66>>,RotateColorsX<Variation,Rgb<4,0,8>>>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<4,0,8>>,RotateColorsX<Variation,Rgb<48,0,105>>,300>,RotateColorsX<Variation,Rgb<95,0,210>>,RandomPerLEDFlicker<Black,RotateColorsX<Variation,Rgb<48,0,105>>>,RotateColorsX<Variation,Rgb<95,0,210>>>,
    TransitionEffectL<TrConcat<TrFade<400>,AudioFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>>,TrDelay<30000>,AudioFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>>,TrFade<800>>,EFFECT_FORCE>,
    AlphaL<StrobeL<Black,Int<20>,Int<1>>,SwingSpeed<600>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<HotPink,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrJoinR<TrWipe<100>,TrWipeIn<100>>,HotPink,TrFade<300>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<Stripes<3000,-2000,RandomBlink<30000,Strobe<Rgb<102,0,204>,White,50,1>,Rgb<75,75,150>>,RandomPerLEDFlicker<Rgb<20,20,100>,Rgb<100,100,150>>>,TrWipe<200>,TrWipe<200>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    MultiTransitionEffectL<TrConcat<TrDelay<300>,SparkleL<>,TrDelay<15000>,AlphaL<SparkleL<>,SmoothStep<Int<6000>,Int<-4000>>>,TrFade<500>>,EFFECT_STAB>,
    AlphaL<Mix<IsLessThan<BladeAngle<>,Int<26000>>,MultiTransitionEffectL<TrConcat<TrWipeIn<200>,White,TrWipeIn<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrConcat<TrWipe<200>,White,TrWipe<200>>,EFFECT_STAB>>,Int<32768>>,
    EffectSequence<EFFECT_BLAST,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,BlastF<200,200>>,TrFade<300>>,EFFECT_BLAST>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,Int<20000>>,
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,60,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,60,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFade<1200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTip<Magenta,1000>,TrWipeInSparkTip<Magenta,1400>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<2000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<95,0,210>>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Rgb<50,50,50>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Rgb<95,0,210>>>>,White,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelay<6000>>,EFFECT_PREON>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"glitch" },


{ "Harmony;common", "tracks/KOTOR.wav",
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<0,190,190>>,RotateColorsX<Variation,Rgb<0,4,20>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<0,20,120>>,Black>>,RotateColorsX<Variation,Rgb<0,10,60>>,Pulsing<RotateColorsX<Variation,Rgb<0,9,50>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<0,190,190>>,RotateColorsX<Variation,Rgb<0,18,96>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<0,21,128>>,RotateColorsX<Variation,Rgb<0,2,5>>,3000>>,
    AlphaL<StyleFire<RotateColorsX<Variation,Rgb<0,190,190>>,RotateColorsX<Variation,Rgb<0,1,2>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
    TransitionEffectL<TrConcat<TrFade<400>,AudioFlickerL<RotateColorsX<Variation,Rgb<90,180,255>>>,TrDelay<5000>,RandomPerLEDFlickerL<Rgb<100,100,100>>,TrFade<800>>,EFFECT_FORCE>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Rgb<128,128,128>,AudioFlicker<Rgb<190,190,190>,DeepSkyBlue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    SparkleL<White,100,400>,
    ResponsiveStabL<Red>,
    ResponsiveBlastWaveL<TransitionEffect<Rgb<128,128,128>,Rgb<128,128,128>,TrInstant,TrFade<100>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveBlastWaveL<Rgb<128,128,128>,Int<300>,Int<100>,Int<300>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,EFFECT_CLASH>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<Rgb<128,128,128>,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Green,Aquamarine>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrColorCycle<1000>,TrColorCycle<1350>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"harmony" },


{ "Infection;common", "tracks/Halo.wav",
  StylePtr<Layers<
    StyleFire<Strobe<RotateColorsX<Variation,Rgb16<65,40112,242>>,Strobe<SpringGreen,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb16<65,40112,242>>,Black>,50,1>,100,1>,RotateColorsX<Variation,Rgb16<11,6957,52>>,0,5,FireConfig<2,1000,5>,FireConfig<2,1000,5>,FireConfig<2,1000,5>,FireConfig<2,1000,5>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<Green>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<Green,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,Chartreuse,TrFade<400>>,TrConcat<TrInstant,Chartreuse,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Cyan,AudioFlicker<SpringGreen,Cyan>,50,1>,TrConcat<TrInstant,AlphaL<Chartreuse,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<Chartreuse,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<SpringGreen>,
    ResponsiveBlastL<Aquamarine,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<Chartreuse,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<Chartreuse,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Chartreuse,Cyan>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"infection" },


{ "Sacrifice;common", "tracks/KOTOR.wav",
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<0,190,190>>,RotateColorsX<Variation,Rgb<0,4,20>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<0,20,120>>,Black>>,RotateColorsX<Variation,Rgb<0,10,60>>,Pulsing<RotateColorsX<Variation,Rgb<0,9,50>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<0,190,190>>,RotateColorsX<Variation,Rgb<0,18,96>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<0,21,128>>,RotateColorsX<Variation,Rgb<0,2,5>>,3000>>,
    AlphaL<StyleFire<RotateColorsX<Variation,Rgb<0,190,190>>,RotateColorsX<Variation,Rgb<0,1,2>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
    TransitionEffectL<TrConcat<TrFade<400>,AudioFlickerL<RotateColorsX<Variation,Rgb<90,180,255>>>,TrDelay<5000>,RandomPerLEDFlickerL<Rgb<100,100,100>>,TrFade<800>>,EFFECT_FORCE>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Rgb<128,128,128>,AudioFlicker<Rgb<190,190,190>,DeepSkyBlue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    SparkleL<White,100,400>,
    ResponsiveStabL<Red>,
    ResponsiveBlastWaveL<TransitionEffect<Rgb<128,128,128>,Rgb<128,128,128>,TrInstant,TrFade<100>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveBlastWaveL<Rgb<128,128,128>,Int<300>,Int<100>,Int<300>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,EFFECT_CLASH>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<Rgb<128,128,128>,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Green,Aquamarine>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrColorCycle<1000>,TrColorCycle<1350>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"sacrifice" },


{ "Son of Odin;common", "tracks/Thor.wav",
  StylePtr<Layers<
    TransitionLoop<RotateColorsX<Variation,DeepSkyBlue>,TrConcat<TrBoing<500,3>,Layers<
      Stripes<10000,100,RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,8,30>>,RotateColorsX<Variation,Rgb<0,63,200>>>,
      AlphaL<Stripes<8000,-200,RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,19,60>>>,Int<16384>>>,TrDelayX<Scale<SlowNoise<Int<3000>>,Int<100>,Int<2000>>>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>,
    TransitionEffectL<TrConcat<TrDelay<1050>,AlphaL<RandomPerLEDFlickerL<DeepSkyBlue>,SmoothStep<Int<6000>,Int<-7000>>>,TrDelay<7700>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrWipeIn<750>,BrownNoiseFlickerL<DeepSkyBlue,Int<200>>,TrWipeIn<500>>,EFFECT_PREON>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"son of odin" },


{ "Spirit Faction;common", "tracks/KOTOR.wav",
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<5,5,20>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<45,45,70>>,Black>>,RotateColorsX<Variation,Rgb<20,20,30>>,Pulsing<RotateColorsX<Variation,Rgb<25,25,40>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<40,40,60>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<2,2,5>>,3000>>,
    AlphaL<StyleFire<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<1,1,2>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<Rgb16<591,11805,9899>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<Rgb16<1053,21609,18076>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,Rgb16<16439,49761,45951>,TrFade<400>>,TrConcat<TrInstant,Rgb16<16439,49761,45951>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Rgb16<16439,49761,45951>,AudioFlicker<Rgb16<468,10102,8542>,Rgb16<1442,30086,25151>>,50,1>,TrConcat<TrInstant,AlphaL<Rgb16<468,10102,8542>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<Rgb16<1442,33908,28268>,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Rgb16<1442,33908,28268>>,
    ResponsiveBlastL<Rgb16<829,20393,16975>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<Rgb16<829,20393,16975>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<Rgb16<829,20393,16975>,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,LightCyan,Rgb16<829,20393,16975>>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrJoinR<TrWipe<300>,TrWipeIn<300>>,TrJoin<TrWipe<500>,TrWipeIn<500>>>,
    TransitionEffectL<TrConcat<TrInstant,Layers<
      AlphaL<TransitionLoopL<TrConcat<TrWaveX<RotateColorsX<Variation,Rgb<100,100,150>>,Int<900>,Int<80>,Int<900>,Int<0>>,Black,TrDelay<300>>>,SmoothStep<Int<16384>,Int<-100>>>,
      AlphaL<TransitionLoopL<TrConcat<TrWaveX<RotateColorsX<Variation,Rgb<100,100,150>>,Int<900>,Int<80>,Int<900>,Int<32768>>,Black,TrDelay<300>>>,SmoothStep<Int<16384>,Int<100>>>>,TrDelay<3200>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<700>,AlphaL<RotateColorsX<Variation,Rgb<50,50,75>>,Bump<Int<16384>,Int<4000>>>,TrFade<3200>,AlphaL<AudioFlickerL<RotateColorsX<Variation,Rgb<100,100,150>>>,Bump<Int<16384>,Int<16000>>>,TrDelay<700>>,EFFECT_PREON>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"spirit faction" },


{ "Terentatek Slayer;common", "tracks/KOTOR.wav",
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,80,0>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,20,0>>,RotateColorsX<Variation,Green>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<400>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"terentatek slayer" },


{ "Venom;common", "tracks/Venom.wav",
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,80,0>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,20,0>>,RotateColorsX<Variation,Green>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<400>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"venom" },


{ "Water Bending;common", "tracks/Avatar.wav",
  StylePtr<Layers<
    StripesX<Sin<Int<10>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Aquamarine>,1500>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Blue>,Cyan>>,RotateColorsX<Variation,Rgb16<0,7465,33908>>,Pulsing<RotateColorsX<Variation,Rgb16<0,10102,46888>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,96>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<0,0,128>>,RotateColorsX<Variation,Rgb16<0,7465,33908>>,3000>>,
    AlphaL<StyleFire<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,SteelBlue>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<Cyan>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<Cyan,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,Cyan,TrFade<400>>,TrConcat<TrInstant,Cyan,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Cyan,AudioFlicker<SteelBlue,Cyan>,50,1>,TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<DodgerBlue>,
    ResponsiveBlastL<Cyan,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<Cyan,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<Cyan,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,DodgerBlue,SteelBlue>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTip<Cyan,500,600>,TrWipe<1200>>>>(),

  StylePtr<Layers<
    White,
    InOutTrL<TrInstant,TrInstant>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>>(),
"water bending" },


};

BladeConfig blades[] = {
 { 0, 
   WS281XBladePtr<133, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
   SimpleBladePtr<CreeXPE2WhiteTemplate<550>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),
   CONFIGARRAY(presets) },

};

#endif
 
#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif