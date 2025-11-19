
#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 9
#define NUM_BUTTONS 2
#define VOLUME 1750
const unsigned int maxLedsPerStrip = 700;
#define EXTRA_COLOR_BUFFER_SPACE 70
#define SHARED_POWER_PINS
#define CLASH_THRESHOLD_G 2.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL //BT
#define ENABLE_SSD1306 //OLED display
//#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
 
#define SAVE_VOLUME
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 4
 
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin4>
//#define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin>
#define BLADE_ID_SCAN_MILLIS 1000
//#define BLADE_ID_TIMES 15
#define SPEAK_BLADE_ID //SAY IT!
#define BLADE_DETECT_PIN blade5Pin //free 1
#define SHARED_POWER_PINS 
 
//#define DISABLE_DIAGNOSTIC_COMMANDS
#define NO_PRESET_SWAP
#define NO_STYLE_EDIT
#define FETT263_MULTI_PHASE
 
#define FETT263_TWIST_ON_NO_BM 
#define FETT263_TWIST_ON 
#define FETT263_TWIST_OFF    
//#define FETT263_THRUST_ON
//#define FETT263_THRUST_OFF
//#define FETT263_STAB_ON_NO_BM                                              
//#define FETT263_STAB_ON                                
 
#define FETT263_SWING_ON_SPEED 500
#define FETT263_SWING_ON_NO_BM
#define FETT263_SWING_ON
#define FETT263_SWING_OFF
 
#define IDLE_OFF_TIME 60 * 0.75 * 1000 //eventually turn off the buttons
#define MOTION_TIMEOUT 60 * 3 * 1000  
 
#endif
 
#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif
 
#ifdef CONFIG_PRESETS
Preset no_blade_presets[] = {  //emitter; crystal chamber; fauxbar; button; bluetooth; mainblade 1,2,3,4
     { "Mundi;common/common_narator", "tracks/Gen'Dai.wav",
     StylePtr<Canon1>("0,65535,0 ~ 2"), //blue emitter
     StylePtr<Canon1>("0,65535,0 ~ 2"), //CC
     StylePtr<Canon1>("0,65535,0 ~ 2"), //CC
     StylePtr<Canon1>("0,65535,0 ~ 2"), //batterymeter  bargraph
     StylePtr<Pulsing<Blue,Green,3000>>(),  //button 
     StylePtr<Canon1>("0,65535,0 ~ 3"),  //green main blade
     StylePtr<Canon1>("0,65535,0 ~ 3"), //green 
     StylePtr<Canon1>("0,65535,0 ~ 3"), //green 
     StylePtr<Canon1>("0,65535,0 ~ 3"), //green 
     "ki adi\nmundi"},
};
 
Preset dual_presets[] = {  //emitter; crystal chamber; fauxbar; button; bluetooth; mainblade 1,2,3,4
    { "Mundi;common/common_narator", "tracks/Gen'Dai.wav",
     StylePtr<Canon1>("0,0,65535 ~ 2"), //blue emitter
     StylePtr<Canon1>("0,0,65535 ~ 2"), //CC
     StylePtr<Canon1>("0,0,65535 ~ 2"), //CC 
     StylePtr<Canon1>("0,0,65535 ~ 2"), //CC
     StylePtr<Canon1>("0,0,65535 ~ 2"), //CC
     StylePtr<Canon1>("0,0,65535 ~ 3"),  //blue main blade
     StylePtr<Canon1>("0,0,65535 ~ 3"), //blue 
     StylePtr<Canon1>("0,0,65535 ~ 3"), //blue 
     StylePtr<Canon1>("0,0,65535 ~ 3"), //blue 
     "ki adi\nmundi"},
};
 
Preset quad_presets[] = {  //emitter; crystal chamber; fauxbar; button; bluetooth; mainblade 1,2,3,4
    { "Mundi;common/common_narator", "tracks/Gen'Dai.wav",
     StylePtr<Canon1>("65535,0,0 ~ 2"), //blue emitter
     StylePtr<Canon1>("65535,0,0 ~ 2"), //CC
     StylePtr<Canon1>("65535,0,0 ~ 2"), //CC 
     StylePtr<Canon1>("65535,0,0 ~ 2"), //CC
     StylePtr<Canon1>("65535,0,0 ~ 2"), //CC
     StylePtr<Canon1>("65535,0,0 ~ 3"),  //blue main blade
     StylePtr<Canon1>("65535,0,0 ~ 3"), //blue 
     StylePtr<Canon1>("65535,0,0 ~ 3"), //blue 
     StylePtr<Canon1>("65535,0,0 ~ 3"), //blue 
     "ki adi\nmundi"},
};
 
BladeConfig blades[] = {
{ NO_BLADE, 
    SubBlade(1, 16, WS281XBladePtr<17, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin4> >()), //emitter
    SubBlade(0, 0, NULL),  //upper crystal chamber 1
    WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(), //upper crystal chamber 2 and lower crystal chambers in parallel
    SubBlade(0, 9, WS281XBladePtr<11, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >()), //faux-bar graph
    SubBlade(10, 10, NULL),  //button 1 
    SubBlade(0, 140, WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin4> >()), //main blade, irrelevant with NO BLADE
    SubBlade(141, 141, NULL),  //null blade
    SubBlade(142, 142, NULL),
    SubBlade(143, 143, NULL),
    CONFIGARRAY(no_blade_presets) },
 { 0,   //single blade config, 128 pixels
    SubBlade(1, 16, WS281XBladePtr<17, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin4> >()), //emitter
    SubBlade(0, 0, NULL),  //upper crystal chamber 1
    WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(), //upper crystal chamber 2 and lower crystal chambers in parallel
    SubBlade(0, 9, WS281XBladePtr<11, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >()), //faux-bar graph
    SubBlade(10, 10, NULL),  //button 1 
    SubBlade(0, 127, WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin4> >()), //main blade, one strip
    SubBlade(128, 129, NULL),  //null blades
    SubBlade(130, 130, NULL),
    SubBlade(131, 131, NULL),
    CONFIGARRAY(dual_presets)  },
{ 1000,   //single blade config, 128 pixels
    WS281XBladePtr<17, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin4> >(), //emitter
    WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(), //upper crystal chamber 2 and lower crystal chambers in parallel
    WS281XBladePtr<11, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(), //faux-bar graph 
    WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin4> >(), //main blade, one strip
    SubBlade(0, 1, WS281XBladePtr<22, blade6Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin4> >()),
    SubBlade(2, 3, NULL),  //null blades
    SubBlade(4, 5, NULL),
    SubBlade(6, 7, NULL),
    SubBlade(8, 21, NULL),
    CONFIGARRAY(quad_presets)  },
};
#endif
 
#ifdef CONFIG_BUTTONS
Button AuxButton(BUTTON_AUX, powerButtonPin, "aux"); //flipped the buttons due to wiring
Button PowerButton(BUTTON_POWER, auxPin, "pow");
#endif
 
#ifdef CONFIG_STYLES
/*--------------------------------- MainRotoscopeSingleColorOriginalTrilogyBaseColor renamed Canon1-------------------------
copyright Fett263 Rotoscope (Primary Blade) OS7 Style
https://fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.13 v1.018-p
This Style Contains 6 Unique Combinations
Style Options:
Default (0): Rotoscope - Single Color (Original Trilogy)
1: Rotoscope - Two Color (Original Trilogy)
2: Audio Rotoscope - Single Color (Original Trilogy)
3: Hyper Responsive Rotoscope (Original Trilogy)
4: Rotoscope (Subtle)
5: Rotoscope (Light)
 
 
--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Battery Level: Full Blade (Green to Red)
Battery Monitor: Passive Battery Monitor (Retraction)
*/
using Canon1 = Layers<ColorSelect<IntArg<STYLE_OPTION_ARG,0>,TrInstant,RandomFlicker<Stripes<10000,-2600,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RandomFlicker<Stripes<10000,-2600,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,AudioFlicker<Stripes<10000,-2600,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Sin<Int<16>,Int<32768>,Int<18000>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Stripes<12000,-200,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<20000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,Stripes<15000,-400,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Stripes<12000,-200,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<20000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<100>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowInvX<RetractionTime<300>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,Mix<BatteryLevel,Red,Green>,TrFade<300>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFade<300>>,EFFECT_RETRACTION>>;
/*
Add to preset as StylePtr<Canon1>()
--------------------------------------------------------------------------*/
#endif