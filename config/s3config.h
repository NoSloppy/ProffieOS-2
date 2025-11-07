// Sabertrio Proffie Saber - Blade & Sound Font Configuration
#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 4
#define NUM_BUTTONS 2
#define VOLUME 1750
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 3.4
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SSD1306
#define COLOR_CHANGE_DIRECT
#define IDLE_OFF_TIME 60*2*1000
#define MOTION_TIMEOUT 60*10*1000
#define SHARED_POWER_PINS
#define DISABLE_DIAGNOSTIC_COMMANDS
#define BLADE_DETECT_PIN 17
#define SAVE_PRESET
#endif

#ifdef CONFIG_PROP
#include"../props/s3button_config.h"
#endif

#ifdef CONFIG_PRESETS

Preset no_blade[] = {
   { "0-NO_BLADE","",
    StylePtr<Black>(),
	StylePtr<Black>(),
	StylePtr<Black>(),
	StylePtr<Pulsing<White,Black,1200>>()
	, },

   };
   
   
   Preset blade[] = {

	//Fully Responsive RandomFlicker Blade Style ( DodgerBlue ) (animated)
    { "1-SABERTRIO", "",
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,Rgb<0,20,128>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,150,0>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AlphaL<Moccasin,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,150,0>,
	Moccasin,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<Moccasin,Rgb<255,150,0>,TrInstant,TrFade<200>,
	EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,
	Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,
	TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
	SimpleClashL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<100>,EFFECT_CLASH>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,
	SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,
	Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeIn<600>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,
	AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,
	TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,Rgb<0,20,128>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<600>,Black>>>(),	
   
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,Rgb<0,20,128>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<600>,Black>>>(),

StylePtr<WHITE>(), "Sabertrio"},
      
   
	//Fully Responsive RandomFlicker Blade Style ( Red ) (animated)
	{ "2-DARK_EDITION", "",
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,150,0>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AlphaL<Moccasin,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,150,0>,
	Moccasin,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<Moccasin,Rgb<255,150,0>,TrInstant,TrFade<200>,
	EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,
	Scale<SwingSpeed<200>,Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<100>,EFFECT_CLASH>>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,
	Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<600>,Black>,
	TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,
	SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<600>,Black>>>(),
   
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<600>,Black>>>(),
	
StylePtr<WHITE>(), "Dark Edition"},

	
	//Fully Responsive RandomFlicker Blade Style ( Red ) (animated)
	{ "19-The_Return", "",
StylePtr<Layers<Stripes<5000,-1500,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,RotateColorsX<Variation,Rgb<255,50,50>>,
	RotateColorsX<Variation,Rgb<128,0,0>>>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>,SwingSpeed<400>>,TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,
	Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Blue,300>,50,1>,TrConcat<TrInstant,White,TrFade<400>>,TrFade<100>,
	Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,LockupTrL<Stripes<3000,-2000,RandomBlink<30000,Strobe<Rgb<125,
	125,225>,White,50,1>,Rgb<75,75,150>>,RandomPerLEDFlicker<Rgb<20,20,100>,Rgb<100,100,150>>>,TrWipe<200>,TrWipe<200>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,
	ResponsiveBlastWaveL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveBlastWaveL<White,Int<300>,Int<100>,Int<300>,Scale<BladeAngle<0,16000>,
	Int<10000>,Int<30000>>,Int<10000>,EFFECT_CLASH>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	LockupTrL<AlphaL<Mix<TwistAngle<>,Coral,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrConcat<TrWipeIn<200>,RandomBlink<30000,White,Black>,
	TrWipeIn<200>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,Int<1000>,Int<6000>>,Int<-3000>>,Black,White>,TrDelay<400>,Mix<SmoothStep<Int<4000>,Int<-3000>>,Black,White>,TrWipe<300>>,
	TrWipeIn<1100>,Black>,TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RandomPerLEDFlickerL<White>,SmoothStep<Int<6000>,Int<-4000>>>,TrDelay<7700>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrWipeIn<200>,
	BrownNoiseFlickerL<White,Int<200>>,TrWipeIn<200>>,EFFECT_PREON>>>(),
	
StylePtr<WHITE>(), "The Return"},
	
	
	//Fully Responsive RandomFlicker Blade Style ( DeepSkyBlue ) (original)
	{ "3-THE_LIGHT","",
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,20,128>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,240,80>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AlphaL<LemonChiffon,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,
	TransitionEffect<Rgb<255,180,50>,LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<LemonChiffon,
	Rgb<255,180,50>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,
	Scale<SwingSpeed<200>,Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,
	TrWipeIn<800>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,
	AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
   
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,20,128>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<800>,Black>>>(),
   
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,20,128>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<800>,Black>>>(),
   
StylePtr<WHITE>(), "The Light"},
	
	
	//Fully Responsive RandomFlicker Blade Style ( Green ) (prequel)
	{ "4-THE_BALANCE","" ,
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,225,0>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<NavajoWhite,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,225,0>,NavajoWhite,
	TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<NavajoWhite,Rgb<255,225,0>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,
	TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,
	Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,
	ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
	SimpleClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,
	SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,
	Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeIn<900>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,
	AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,
	TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<900>,Black>>>(),
   
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<900>,Black>>>(),
	
StylePtr<WHITE>(), "The Balance"},
	
	
	//Fully Responsive RandomFlicker Blade Style ( Red ) (original)
	{ "5-THE_DARK","" ,
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,240,80>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<LemonChiffon,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,180,50>,
	LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<LemonChiffon,Rgb<255,180,50>,TrInstant,
	TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,
	AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange,
	TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,
	Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,
	SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,
	SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<800>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,
	AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,
	TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<800>,Black>>>(),
   
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<800>,Black>>>(),
	
StylePtr<WHITE>(), "The Dark"},
	
	
	//Fully Responsive RandomFlicker Blade Style ( Red ) (animated)
	{ "6-VENGEANCE","" ,
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,150,0>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<Moccasin,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,150,0>,
	Moccasin,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<Moccasin,Rgb<255,150,0>,TrInstant,TrFade<200>,
	EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,
	AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<50>,EFFECT_BLAST>,
	Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<100>,EFFECT_CLASH>>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipe<300>,TrWipeIn<800>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,
	TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<800>,Black>>>(),
   
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<800>,Black>>>(),
	
StylePtr<WHITE>(), "Vengence"},
	
		
	//Fully Responsive Kylo Ren Unstable Neopixel Lightsaber (Unstable Swing) Styles ( Red ) (sequel)
	{ "7-KROSSGUARD", "",
StylePtr<Layers<Mix<SwingSpeed<310>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<50,0,0>>,
	RotateColorsX<Variation,Rgb<100,0,0>>>,300>,RotateColorsX<Variation,Rgb<180,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,
	FireConfig<10,1000,2>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<25,0,0>>,300>,Mix<SwingSpeed<200>,
	RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<10,0,0>>>,0,8,FireConfig<10,1200,1>,FireConfig<10,1200,1>,FireConfig<10,1200,1>,
	FireConfig<10,1200,1>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Azure>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,
	Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,
	Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Azure,White,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,
	TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,
	TrSmoothFade<600>>>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_BLAST>,
	Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_CLASH>>,
	AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<2400>>,Int<22000>,Int<40000>>,Int<22000>>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,
	SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,
	SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<150 >,TrWipeIn<800>,Black>,
	TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,
	SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),

StylePtr<IgnitionDelay<370,Layers<Mix<SwingSpeed<310>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<50,0,0>>,
	RotateColorsX<Variation,Rgb<100,0,0>>>,300>,RotateColorsX<Variation,Rgb<180,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,
	FireConfig<10,1000,2>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<25,0,0>>,300>,Mix<SwingSpeed<200>,RotateColorsX<Variation,
	Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<10,0,0>>>,0,8,FireConfig<10,1200,1>,FireConfig<10,1200,1>,FireConfig<10,1200,1>,FireConfig<10,1200,1>>>,
	ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,
	HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<2400>>,Int<22000>,Int<40000>>,Int<22000>>>,
	InOutTrL<TrWipe<150>,TrWipeIn<800>,Black>>>>(),	
StylePtr<IgnitionDelay<370,Layers<Mix<SwingSpeed<310>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<50,0,0>>,
	RotateColorsX<Variation,Rgb<100,0,0>>>,300>,RotateColorsX<Variation,Rgb<180,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,
	FireConfig<10,1000,2>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<25,0,0>>,300>,Mix<SwingSpeed<200>,RotateColorsX<Variation,
	Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<10,0,0>>>,0,8,FireConfig<10,1200,1>,FireConfig<10,1200,1>,FireConfig<10,1200,1>,FireConfig<10,1200,1>>>,
	ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,
	HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<2400>>,Int<22000>,Int<40000>>,Int<22000>>>,
	InOutTrL<TrWipe<150>,TrWipeIn<800>,Black>>>>(),
	
StylePtr<WHITE>(), "Krossguard"},
	
	
	
	//Fully Responsive AudioFlicker Canon Jedi/Sith Neopixel Lightsaber Styles ( Silver ) (animated)
    { "8-SNIPPETS", "",
StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<50,50,75>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,150,0>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<Moccasin,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,150,0>,
	Moccasin,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<Moccasin,Rgb<255,150,0>,TrInstant,TrFade<200>,
	EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,
	AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,
	Scale<SwingSpeed<200>,Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<100>,EFFECT_CLASH>>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,
	Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<800>,Black>,
	TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,
	AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<50,50,75>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<800>,Black>>>(),
	
StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<50,50,75>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<800>,Black>>>(),

StylePtr<WHITE>(), "Snippets"},
	
	
	//Fully Responsive RandomFlicker Blade Style ( Red ) (prequel)
    { "9-MENACE", "",
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,225,0>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,
	TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<NavajoWhite,Rgb<255,225,0>,
	TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<50>,EFFECT_BLAST>,
	Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipe<300>,TrWipeIn<600>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,
	TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<600>,Black>>>(),
	
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<600>,Black>>>(),

StylePtr<WHITE>(), "Menace"},
	
	
	//Fully Responsive RandomFlicker Blade Style ( Gold ) (animated)
    { "10-TEMPLE_GUARDIAN", "",
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<90,65,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,150,0>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AlphaL<Moccasin,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,150,0>,
	Moccasin,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<Moccasin,Rgb<255,150,0>,TrInstant,TrFade<200>,
	EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,
	AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,
	Scale<SwingSpeed<200>,Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<100>,EFFECT_CLASH>>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,200>,
	TrWipeIn<600>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,
	AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<90,65,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<200>,TrWipeIn<600>,Black>>>(),

StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<90,65,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<200>,TrWipeIn<600>,Black>>>(),

StylePtr<WHITE>(), "Temple Guardian"},
	
	
	//Shock Baton Neopixel Lightsaber Style ( Shock Baton ) (sequel) (polar spark,center in)
    { "11-SHOCK_BATON", "",
StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RotateColorsX<Variation,SteelBlue>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,
	Rgb<150,150,225>>,200>,LockupTrL<Layers<AlphaL<AudioFlickerL<Azure>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,
	Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,
	Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Azure,White,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,
	TransitionEffect<White,Azure,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,
	ResponsiveBlastL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
	SimpleClashL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_CLASH>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,
	Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,
	TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrJoin<TrWipe<300>,TrWipeIn<300>>,TrJoin<TrWipe<600>,TrWipeIn<600>>,Black>,
	TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,
	AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,
	Bump<Int<32768>,Int<10000>>>>,TrDelay<800>>,EFFECT_PREON>>>(),
	
StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RotateColorsX<Variation,SteelBlue>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,
	Rgb<10,10,15>,Rgb<150,150,225>>,200>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,InOutTrL<TrJoin<TrWipe<300>,TrWipeIn<300>>,TrJoin<TrWipe<600>,TrWipeIn<600>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,
	Bump<Int<32768>,Int<10000>>>>,TrDelay<800>>,EFFECT_PREON>>>(),

StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RotateColorsX<Variation,SteelBlue>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,
	Rgb<10,10,15>,Rgb<150,150,225>>,200>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,InOutTrL<TrJoin<TrWipe<300>,TrWipeIn<300>>,TrJoin<TrWipe<600>,TrWipeIn<600>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,
	Bump<Int<32768>,Int<10000>>>>,TrDelay<800>>,EFFECT_PREON>>>(),

StylePtr<WHITE>(), "Shock Baton"},
	
	
	//Fully Responsive AudioFlicker Canon Jedi/Sith Neopixel Lightsaber Styles ( Red ) (prequel)
	{ "12-THE_TRAGEDY", "",
StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<200>,
	EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<NavajoWhite,Rgb<255,225,0>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,
	SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,
	ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
	SimpleClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>>,TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,
	RotateColorsX<Variation,Rgb<255,150,150>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<255,150,150>>,
	RotateColorsX<Variation,Rgb<60,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>>,
	TrFade<1200>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,
	SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,
	SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<700>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,
	AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,
	SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,
	RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<800>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>,
	InOutTrL<TrWipe<300>,TrWipeIn<700>,Black>>>(),

StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,
	RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<800>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>,
	InOutTrL<TrWipe<300>,TrWipeIn<700>,Black>>>(),
	
StylePtr<WHITE>(), "The Tragedy"},
	
			
	//Fully Responsive RandomFlicker Blade Style ( Cyan ) (prequel)
    { "13-TEENSY_SF", "",
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb<0,20,128>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,225,0>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,225,0>,
	NavajoWhite,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<NavajoWhite,Rgb<255,225,0>,
	TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<50>,EFFECT_BLAST>,
	Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,
	Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeIn<700>,Black>,
	TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,
	SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,20,128>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<700>,Black>>>(),

StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,20,128>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<700>,Black>>>(),
	
StylePtr<WHITE>(), "TeensySF"},
	
	
	//Fully Responsive RandomFlicker Blade Style ( Blue ) (original)
    { "14-SMOOTH_JEDI", "",
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,240,80>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<LemonChiffon,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,180,50>,
	LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<LemonChiffon,Rgb<255,180,50>,TrInstant,TrFade<200>,
	EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,
	AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,
	Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeSparkTip<White,300>,TrWipeIn<700>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,
	SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<700>,Black>>>(),

StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<700>,Black>>>(),
	
StylePtr<WHITE>(), "Smooth Jedi"},
		
		
	//Fully Responsive AudioFlicker Canon Jedi/Sith Neopixel Lightsaber Styles ( Amber/Gold ) (sequel)
	{ "15-SMOOTH_GREY", "",
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb<255,130,0>>,RotateColorsX<Variation,Rgb<90,65,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Azure>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Azure,White,TrInstant,
	TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<White,Azure,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,
	SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,
	TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,
	ResponsiveBlastL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_BLAST>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
	SimpleClashL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_CLASH>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,
	Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,
	TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeIn<700>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,
	Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Rgb<255,130,0>>,RotateColorsX<Variation,Rgb<90,65,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<700>,Black>>>(),

StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Rgb<255,130,0>>,RotateColorsX<Variation,Rgb<90,65,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<700>,Black>>>(),
	
StylePtr<WHITE>(), "Smooth Grey"},
	
	
	//Fully Responsive RandomFlicker Blade Style ( Purple ) (prequel)
	{ "16-SMOOTH_FUZZ", "",
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb<210,0,210>>,RotateColorsX<Variation,Rgb<42,0,110>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,225,0>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<NavajoWhite,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,225,0>,
	NavajoWhite,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<NavajoWhite,Rgb<255,225,0>,TrInstant,TrFade<200>,
	EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,
	AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<50>,EFFECT_BLAST>,
	Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,
	TrWipeIn<900>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,
	TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb<210,0,210>>,RotateColorsX<Variation,Rgb<42,0,110>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<700>,Black>>>(),

StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Rgb<210,0,210>>,RotateColorsX<Variation,Rgb<42,0,110>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<700>,Black>>>(),
	
StylePtr<WHITE>(), "Smooth Fuzz"},
	
	
	//Fully Responsive "Power Surge" Unstable Neopixel Lightsaber Style ( Red ) (original)
	{ "17-ROGUE_COMMANDER", "",
StylePtr<Layers<Layers<AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<200,0,0>>>,
	TransitionLoopL<TrWaveX<HumpFlickerL<RotateColorsX<Variation,Red>,40>,Int<250>,Int<100>,Int<200>,Int<0>>>,
	TransitionLoopL<TrWaveX<HumpFlickerL<RotateColorsX<Variation,Red>,40>,Int<350>,Int<100>,Int<300>,Int<0>>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,240,80>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<LemonChiffon,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,180,50>,
	LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<LemonChiffon,Rgb<255,180,50>,TrInstant,TrFade<200>,
	EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,
	AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,Int<400>,
	Scale<SwingSpeed<200>,Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipe<300>,TrWipeIn<900>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,
	TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<Layers<AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<200,0,0>>>,
	TransitionLoopL<TrWaveX<HumpFlickerL<RotateColorsX<Variation,Tomato>,40>,Int<250>,Int<100>,Int<200>,Int<0>>>,
	TransitionLoopL<TrWaveX<HumpFlickerL<RotateColorsX<Variation,Red>,40>,Int<350>,Int<100>,Int<300>,Int<0>>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<900>,Black>>>(),

StylePtr<Layers<Layers<AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<200,0,0>>>,
	TransitionLoopL<TrWaveX<HumpFlickerL<RotateColorsX<Variation,Tomato>,40>,Int<250>,Int<100>,Int<200>,Int<0>>>,
	TransitionLoopL<TrWaveX<HumpFlickerL<RotateColorsX<Variation,Red>,40>,Int<350>,Int<100>,Int<300>,Int<0>>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<900>,Black>>>(),
	
StylePtr<WHITE>(), "Rogue Commander"},
	
	
	//Fully Responsive RandomFlicker Blade Style ( Green ) (original)
	{ "18-TYTHONIAN_CYRSTAL", "",
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,240,80>>,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<LemonChiffon,
	Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,180,50>,
	LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<LemonChiffon,Rgb<255,180,50>,TrInstant,TrFade<200>,
	EFFECT_LOCKUP_BEGIN>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,
	AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<50>,EFFECT_BLAST>,
	Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,SimpleClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,
	TrWipeIn<800>,Black>,TransitionEffectL<TrConcat<TrWipe<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrDelay<2000>,
	AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>>>(),
	
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<900>,Black>>>(),
StylePtr<Layers<RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,ResponsiveLightningBlockL<AlphaL<Red,Int<0>>,
	TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	InOutTrL<TrWipe<300>,TrWipeIn<900>,Black>>>(),
	
StylePtr<WHITE>(), "Tythonian Crytal"}
   
};



BladeConfig blades[] = {
 { 0, WS281XBladePtr<115, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<20, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
    WS281XBladePtr<20, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),
	SimpleBladePtr<CreeXPE2WhiteTemplate<550>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>()
  , CONFIGARRAY(blade) },
 
 { NO_BLADE, WS281XBladePtr<115, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<20, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
    WS281XBladePtr<20, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),
SimpleBladePtr<CreeXPE2WhiteTemplate<550>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>()
  , CONFIGARRAY(no_blade) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif



