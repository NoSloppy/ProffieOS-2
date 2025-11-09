#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 6
#define NUM_BUTTONS 2
#define VOLUME 2000
const unsigned int maxLedsPerStrip = 148;
#define CLASH_THRESHOLD_G 2.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define SHARED_POWER_PINS
#define MOTION_TIMEOUT 60 * 10 * 1000
#define IDLE_OFF_TIME 60 * 10 * 1000
#define DISABLE_BASIC_PARSER_STYLES
#define DISABLE_DIAGNOSTIC_COMMANDS
#define ENABLE_ALL_EDIT_OPTIONS
#define SAVE_PRESET
#define KEEP_SAVEFILES_WHEN_PROGRAMMING
#define NO_REPEAT_RANDOM
#define COLOR_CHANGE_DIRECT
#define FETT263_EDIT_MODE_MENU
//#define FETT263_SAY_COLOR_LIST
//#define FETT263_SAY_COLOR_LIST_CC
#define FETT263_SAY_BATTERY_PERCENT
#define FETT263_MOTION_WAKE_POWER_BUTTON
#define FETT263_TRACK_PLAYER_NO_PROMPTS
#define FETT263_DISABLE_COPY_PRESET
#define FETT263_RANDOMIZE_QUOTE_PLAYER
#define FETT263_BATTLE_MODE
#define FETT263_LOCKUP_DELAY 200
#define FETT263_BM_CLASH_DETECT 6
#define FETT263_THRUST_ON
//#define FETT263_TWIST_ON
//#define FETT263_TWIST_ON_NO_BM
#define FETT263_TWIST_OFF
//#define FETT263_MULTI_PHASE
#define FETT263_SPECIAL_ABILITIES
#define DISABLE_TALKIE
#define FILTER_CUTOFF_FREQUENCY 90
#define FILTER_ORDER 8
//#define FETT263_FORCE_PUSH
#define FETT263_HOLD_BUTTON_LOCKUP
#define DISABLE_COLOR_CHANGE
#define FETT263_DISABLE_CHANGE_STYLE

#define ENABLE_ALL_EDIT_OPTIONS
#define MOUNT_SD_SETTING

#endif

#ifdef CONFIG_PROP
// #include "../props/saber_fett263_buttons_next_E.h"
#include "../props/saber_fett263_buttons.h"
#endif

/*
#ifdef CONFIG_STYLES


#define STYLE_DISPLAY_H
#define DISPLAY_LAYER_CONTROLLER_H

	InMemoryDisplay<9, 9, 3> my_small_display;
	StandarColorDisplayController<9, 9> my_small_display_controller(&my_small_display);
	NAME_INSTANCE(my_small_display, MYDISPLAY);
		
#endif
*/

#ifdef CONFIG_PRESETS



Preset p1[] = {

	{ "Survivor_Party;common", "tracks/SW_main_theme.wav",
		//MAIN BLADE
			/* copyright Fett263 CustomBlade (Primary Blade) OS7 Style
			https://fett263library.com/early-access/#CustomBlade
			OS7.8 v1.014
			Single Style 
			Multi Phase (Special Abilities*)
			Default: Cal Kestis Survivor Blue [BaseColorArg]
			1: Cal Kestis Survivor Cyan [AltColorArg]
			2: Cal Kestis Survivor Green [AltColor2Arg]
			3: Cal Kestis Survivor Indigo [AltColor3Arg]
			4: Cal Kestis Survivor Magenta [Rgb<255,0,255>]
			5: Cal Kestis Survivor Orange [Rgb<255,68,0>]
			6: Cal Kestis Survivor Purple [Rgb<115,15,240>]
			7: Cal Kestis Survivor Silver [Rgb<100,100,150>]
			8: Cal Kestis Survivor Yellow [Rgb<180,130,0>]
			9: Fallen Order Second Sister [Rgb<255,0,0>]

			Multi Phase Control: use Special Abilities controls to change Phase. Requires Alt Font. 

			NOTE:This style includes Control Layer. Only one Control Layer should be used per preset.

			*This style REQUIRES Alt Fonts alt000/ to alt009/ to be set up. Uses altchng.wav on change.
			See https://pod.hubbe.net/sound/alt_sounds.html for more information.
			--Effects Included--
			Ignition Effects: 0: Standard Ignition [MILLIS: 300, BEND: 16384] 1: Standard Ignition [MILLIS: 300, BEND: 16384] 2: SparkTip Ignition [MILLIS: 300, BEND: 16384] 3: Standard Ignition [MILLIS: 300, BEND: 16384] 4: Standard Ignition [MILLIS: 300, BEND: 16384] 5: SparkTip Ignition [MILLIS: 300, BEND: 16384] 6: Standard Ignition [MILLIS: 300, BEND: 16384] 7: Cycle Up [MILLIS: 600, BEND: 19384] 8: Standard Ignition [MILLIS: 300, BEND: 16384] 9: SparkTip Ignition [MILLIS: 300, BEND: 16384] [Color:IgnitionColorArg]
			PowerUp Effects: 0: Disable 1: Disable 2: Disable 3: Disable 4: Disable 5: Power Surge (Stable) 6: Disable 7: Power Flash 8: Power Flash 9: Power Burst Forward [Color:IgnitionColorArg]
			Retraction Effect: Standard Retraction [Color: RetractionColorArg]
			Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb [Color: LockupColorArg]
			LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
			Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
			Melt Effect: Intensity Melt [Color: StabColorArg]
			Stab Effect: Sparking Stab [Color: StabColorArg]
			Blast Effect (Randomly Selected): Responsive Blast Wave (Random), Responsive Blast Ripple [Color: BlastColorArg]
			Clash Effect: Real Clash V1 [Color: ClashColorArg]
			Special Ability 1: Next Phase 
			Special Ability 2: Previous Phase 
			Special Ability 3: Select Random Phase 
			Special Ability 4: Toggle Swing Change (Random / Party Mode) Uses tr.wav #0 on toggle

			*/
			StylePtr<Layers<
			ColorSelect<AltF,TrInstant,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<8000>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,1400>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<10000>,Int<5000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2000>,Int<-3000>>,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<12000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>>,Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<8000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,255,255>>>,1400>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<4000>,Int<1800>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2800>,Int<-4000>>,Mix<Int<16000>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>>,Mix<Int<8000>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<9000>,Int<4000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2400>,Int<-3000>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Mix<Int<15000>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>>,Pulsing<RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Mix<Int<10000>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>>,600>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<9000>,Int<4000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2000>,Int<-3000>>,Rgb<255,0,255>,Mix<Int<12000>,Black,Rgb<255,0,255>>,Pulsing<Rgb<255,0,255>,Mix<Int<8000>,Black,Rgb<255,0,255>>,800>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<4000>,Int<1800>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2800>,Int<-4000>>,Mix<Int<16000>,Black,Rgb<255,68,0>>,Mix<Sin<Int<20>,Int<20000>,Int<32768>>,Black,Rgb<255,68,0>>,Mix<Int<10000>,Black,Rgb<255,68,0>>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Sin<Int<20>,Int<10000>,Int<7000>>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2300>,Int<-4000>>,Rgb<115,15,240>,Mix<Int<12000>,Black,Rgb<115,15,240>>,Pulsing<Rgb<115,15,240>,Mix<Int<20000>,Black,Rgb<115,15,240>>,2000>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<4000>,Int<1800>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-3000>,Int<-4500>>,Mix<Int<16000>,Black,Rgb<100,100,150>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,Rgb<100,100,150>>,Mix<Int<8000>,Black,Rgb<100,100,150>>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<3600>,Int<1600>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2700>,Int<-4100>>,Mix<Int<16000>,Black,Rgb<180,130,0>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,Rgb<180,130,0>>,Mix<Int<8000>,Black,Rgb<180,130,0>>>,StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,Rgb<255,0,0>,Mix<Int<10280>,Black,Rgb<255,0,0>>,Rgb<255,0,0>,Mix<Int<2570>,Black,Rgb<255,0,0>>,Rgb<255,0,0>>>,
			TransitionEffectL<TrSelect<AltF,TrInstant,TrInstant,TrInstant,TrInstant,TrInstant,TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrFade<1200>>,TrInstant,TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,Stripes<5000,-2500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<800>>>,EFFECT_IGNITION>,
			TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<10>>,Int<-1>>,EFFECT_USER1>,
			TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<-1>>,Int<10>>,Int<-1>>,EFFECT_USER2>,
			TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<9>>>,Int<10>>,Int<-1>>,EFFECT_USER3>,
			TransitionPulseL<TrSelect<IncrementModuloF<EffectPulseF<EFFECT_USER4>,Int<2>>,TrInstant,TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<9>>>,Int<10>>,Int<-1>>>,ThresholdPulseF<SwingSpeed<320>,Int<31000>>>,
			TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>,Int<-1>>,EFFECT_USER4>,
			TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RandomPerLEDFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
			TransitionEffectL<TrRandom<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>,Remap<CenterDistF<Scale<BladeAngle<>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>>>,EFFECT_BLAST>,
			Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
			LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
			ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,
			LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
			LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
			InOutTrL<TrSelect<AltF,TrWipeX<BendTimePowInvX<Int<300>,Int<16384>>>,TrWipeX<BendTimePowInvX<Int<300>,Int<16384>>>,TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<Int<300>,Int<16384>>>,TrWipeX<BendTimePowInvX<Int<300>,Int<16384>>>,TrWipeX<BendTimePowInvX<Int<300>,Int<16384>>>,TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<Int<300>,Int<16384>>>,TrWipeX<BendTimePowInvX<Int<300>,Int<16384>>>,TrColorCycleX<BendTimePowInvX<Int<600>,Int<19384>>>,TrWipeX<BendTimePowInvX<Int<300>,Int<16384>>>,TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<Int<300>,Int<16384>>>>,TrWipeInX<BendTimePowInvX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
	
 
   		//Emitter Mid Ring A (make sure to match styles A & B)
   		    StylePtr<Layers<
   		   	  TransitionLoop<Black,TrConcat<TrDelay<400>,Black,TrConcat<TrFade<100>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,TrFade<300>>,Black,TrDelay<800>>>,
   		   	  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
   		   	  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
   		   	  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
   		   	  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
   		   	  TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<255,255,255>>,Int<100>>,TrFade<1200>>,EFFECT_IGNITION>,
   		   	  InOutTrL<TrInstant,TrFade<300>,TransitionLoop<Black,TrConcat<TrDelay<750>,Black,TrConcat<TrFade<250>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,TrFade<500>>,Black,TrDelay<1500>>>>
   		   	>>(),

   		//Emitter Center Ring
   			StylePtr<Layers<
   			  TransitionLoop<Black,TrConcat<TrFade<100>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,TrFade<300>,Black,TrDelay<1200>>>,
   	   	   	  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
   	   	   	  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
   	   	   	  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
   	   	   	  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
   	   	   	  TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<255,255,255>>,Int<100>>,TrFade<1200>>,EFFECT_IGNITION>,
   	   	   	  InOutTrL<TrInstant,TrFade<300>,TransitionLoop<Black,TrConcat<TrDelay<1500>,Black,TrConcat<TrFade<250>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,TrFade<500>>,Black,TrDelay<750>>>>
      			>>(),
	
	//Crystal Chamber		  
	  		//Crystal Bottom
	  		/* copyright Fett263 CustomBlade (Crystal Chamber) OS7 Style
	  		https://fett263library.com/early-access/#CustomBlade
	  		OS7.14 v3.4
	  		This Style Contains 36 Unique Combinations
	  		Multi Phase (Special Abilities*) Transition: Fade, Time: 1000

	  		Default: Cal Kestis Survivor Blue [BaseColorArg]
	  		1: Cal Kestis Survivor Cyan [AltColorArg]
	  		2: Cal Kestis Survivor Green [AltColor2Arg]
	  		3: Cal Kestis Survivor Indigo [AltColor3Arg]
	  		4: Cal Kestis Survivor Magenta [Rgb<255,0,255>]
	  		5: Cal Kestis Survivor Orange [Rgb<255,68,0>]
	  		6: Cal Kestis Survivor Purple [Rgb<115,15,240>]
	  		7: Cal Kestis Survivor Silver [Rgb<100,100,150>]
	  		8: Cal Kestis Survivor Yellow [Rgb<180,130,0>]
	  		9: Fallen Order Second Sister [Rgb<255,0,0>]

	  		Off Behavior Options: Default (0): Slow Pulse Off-On, 1: Heart Beat, 2: Fast Pulse Dim-On [Color: Multi Phase]

	  		Multi Phase Control: use Special Abilities controls to change Phase. Requires Alt Font.

	  		*This style REQUIRES Alt Fonts alt000/ to alt009/ to be set up. Uses altchng.wav on change.
	  		See https://pod.hubbe.net/sound/alt_sounds.html for more information.
	  		--Effects Included--
	  		Ignition Effect: Instant [Color: IgnitionColorArg]
	  		PowerUp Effect Options: Default (0): Disable, 1: Power Burst Forward, 2: Power Flash [Color: IgnitionColorArg]
	  		Retraction Effect Options: Default (0): Instant, 1: Standard Retraction, 2: Fade Out, 3: Blink Off [Color: RetractionColorArg]
	  		Lockup Effect:
	  		0: crystalLockMulti0Shape - Begin: 0 - Style: Intensity AudioFlicker - End: Full Blade Absorb
	  		[Color: LockupColorArg]
	  		Lightning Block Effect:
	  		0: crystalLBMulti0Shape - Begin: 0 - Style: Strobing AudioFlicker - End: Full Blade Absorb
	  		[Color: LBColorArg]
	  		Drag Effect:
	  		0: crystalDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
	  		[Color: DragColorArg]
	  		Melt Effect:
	  		0: crystalMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
	  		[Color: StabColorArg]
	  		Blast Effect: Full Blade Blast Fade [Color: BlastColorArg]
	  		Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
	  		Special Ability 1: Next Phase
	  		Special Ability 2: Previous Phase
	  		Special Ability 3: Select Random Phase
	  		Special Ability 4: Toggle Swing Change (Random / Party Mode) Uses tr00.wav or tr/000/000.wav on toggle (mechanical or menu sound)

	  		*/
	  		StylePtr<Layers<Black,ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrFadeX<Int<1000>>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<8000>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,1400>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<10000>,Int<5000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2000>,Int<-3000>>,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<12000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,Pulsing<RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<8000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,1400>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<4000>,Int<1800>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2800>,Int<-4000>>,Mix<Int<16000>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>>,Mix<Int<8000>,Black,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<9000>,Int<4000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2400>,Int<-3000>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Mix<Int<15000>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>>,Pulsing<RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Mix<Int<10000>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>>,600>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<9000>,Int<4000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2000>,Int<-3000>>,Rgb<255,0,255>,Mix<Int<12000>,Black,Rgb<255,0,255>>,Pulsing<Rgb<255,0,255>,Mix<Int<8000>,Black,Rgb<255,0,255>>,800>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<4000>,Int<1800>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2800>,Int<-4000>>,Mix<Int<16000>,Black,Rgb<255,68,0>>,Mix<Sin<Int<20>,Int<20000>,Int<32768>>,Black,Rgb<255,68,0>>,Mix<Int<10000>,Black,Rgb<255,68,0>>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Sin<Int<20>,Int<10000>,Int<7000>>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2300>,Int<-4000>>,Rgb<115,15,240>,Mix<Int<12000>,Black,Rgb<115,15,240>>,Pulsing<Rgb<115,15,240>,Mix<Int<20000>,Black,Rgb<115,15,240>>,2000>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<4000>,Int<1800>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-3000>,Int<-4500>>,Mix<Int<16000>,Black,Rgb<100,100,150>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,Rgb<100,100,150>>,Mix<Int<8000>,Black,Rgb<100,100,150>>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<3600>,Int<1600>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2700>,Int<-4100>>,Mix<Int<16000>,Black,Rgb<180,130,0>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,Rgb<180,130,0>>,Mix<Int<8000>,Black,Rgb<180,130,0>>>,StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,Rgb<255,0,0>,Mix<Int<10280>,Black,Rgb<255,0,0>>,Rgb<255,0,0>,Mix<Int<2570>,Black,Rgb<255,0,0>>,Rgb<255,0,0>>>,TransitionEffectL<TrSelect<IntArg<IGNITION_POWER_UP_ARG,0>,TrInstant,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,Stripes<5000,-2500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<800>>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<TransitionEffect<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrInstant,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,LockupTrL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrInstant,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_LIGHTNING_BLOCK,Int<1>>,LockupTrL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrInstant,TrSelect<IntArg<RETRACTION_OPTION_ARG,0>,TrInstant,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrJoin<TrBoingX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>,3>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Pulsing<Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>,Rgb<255,0,0>>,8000>,TransitionLoop<ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>,Rgb<255,0,0>>,TrConcat<TrBoing<1200,2>,Mix<Int<1285>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>,Rgb<255,0,0>>>,TrFade<1200>>>,Pulsing<Mix<Int<8192>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>,Rgb<255,0,0>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,RgbArg<ALT_COLOR2_ARG,Rgb<0,255,0>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Rgb<255,0,255>,Rgb<255,68,0>,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>,Rgb<255,0,0>>,2000>>>>>(),
    
	     // chassis strip right
	      	StylePtr<Layers<
	  		TransitionLoop<RgbArg<BASE_COLOR_ARG,Black>,TrConcat<TrWipe<200>,Rgb<95,0,210>,TrWipe<200>>>,
	  		TransitionEffectL<TrConcat<TrInstant,RgbArg<BLAST_COLOR_ARG,DarkOrange>,TrFade<400>>,EFFECT_BLAST>,
	  		LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,LemonChiffon>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
	  		LockupTrL<AudioFlickerL<RgbArg<LB_COLOR_ARG,AliceBlue>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
	  		TransitionEffectL<TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Red>,TrFade<400>>,EFFECT_CLASH>,
	  		TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrFade<1200>>,EFFECT_IGNITION>,
	  		InOutTrL<TrInstant,TrInstant,TransitionLoop<Black,TrConcat<TrJoinR<TrWipe<1250>,TrWipeIn<1250>>,RgbArg<OFF_COLOR_ARG,Rgb<95,0,210>>,TrJoinR<TrWipe<1250>,TrWipeIn<1250>>>>>>>(),

	     // chassis strip left
	      	StylePtr<Layers<
	  		TransitionLoop<RgbArg<BASE_COLOR_ARG,Black>,TrConcat<TrWipe<200>,Rgb<95,0,210>,TrWipe<200>>>,
	  		TransitionEffectL<TrConcat<TrInstant,RgbArg<BLAST_COLOR_ARG,DarkOrange>,TrFade<400>>,EFFECT_BLAST>,
	  		LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,LemonChiffon>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
	  		LockupTrL<AudioFlickerL<RgbArg<LB_COLOR_ARG,AliceBlue>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
	  		TransitionEffectL<TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Red>,TrFade<400>>,EFFECT_CLASH>,
	  		TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrFade<1200>>,EFFECT_IGNITION>,
	  		InOutTrL<TrInstant,TrInstant,TransitionLoop<Black,TrConcat<TrJoinR<TrWipe<1250>,TrWipeIn<1250>>,RgbArg<OFF_COLOR_ARG,Rgb<95,0,210>>,TrJoinR<TrWipe<1250>,TrWipeIn<1250>>>>>>>(),


   "party" },


{ "OSHA;common", "tracks/SOL.wav",
   /* copyright Fett263 Acolyte "Path to the Dark side Corruption and Cortosis" (Primary Blade) OS7 Style
   https://fett263library.com/early-access/#CustomBlade
   OS7.14 v3.4
   Single Style
   Multi Phase (Special Abilities*) Transition: Wipe, Time: 500

   Default: Master Sol [BaseColorArg]
   1: Osha (Dark Side) [AltColorArg]

   Multi Phase Control: use Special Abilities controls to change Phase. Requires Alt Font.

   NOTE:This style includes Control Layer. Only one Control Layer should be used per preset.

   *This style REQUIRES Alt Fonts alt000/ to alt001/ to be set up. Uses altchng.wav on change.
   See https://pod.hubbe.net/sound/alt_sounds.html for more information.
   --Effects Included--
   Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
   Retraction Effect: Standard Retraction [Color: RetractionColorArg]
   Lockup Effect:
   0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
   [Color: LockupColorArg]
   Lightning Block Effect:
   0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
   [Color: LBColorArg]
   Drag Effect:
   0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
   [Color: DragColorArg]
   Melt Effect:
   0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
   [Color: StabColorArg]
   Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
   Clash Effect: Real Clash V1 [Color: ClashColorArg]
   Special Ability 1: Change Phase (Corruption: Rotoscope - Time: 14000 ms) Uses tr00.wav or or tr/000/000.wav (blade corruption sound)
   Special Ability 2: Toggle Cortosis Clash V2 mode, if blade Clashes within 3000 ms, blade will be shorted out and sparking and will not be able to reignite when pressing the Power Button for 7500 ms. (Spark Size: 1000).
   Saber will automatically re-ignite with a partial 'flame up' followed by a full ignition after shorted out period completes.
   Uses tr01.wav or tr/001/000.wav for toggle, tr02.wav or tr/002/000.wav for cortosis (metallic sound on clash), tr03.wav or tr/003/000.wav for shorted out / disabled period (sparking sound)(7500 ms) and tr04.wav or tr/004/000.wav for partial 'flame' ignition
   Special Ability 3: Next Phase
   Special Ability 5: Ignite + Change Phase (Corruption: Rotoscope - Delay: 1000 ms - Time: 14000 ms) Uses tr05.wav or or tr/005/000.wav (blade corruption sound)

   */
   StylePtr<Layers<Black,ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrWipeX<Int<500>>>,AudioFlicker<Stripes<22000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<10000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,AudioFlicker<Stripes<25000,-1500,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10640>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<18460>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,TransitionEffectL<TrConcat<TrExtend<16000,TrDoEffectAlwaysX<TrDelay<10>,EFFECT_TRANSITION_SOUND,Int<0>>>,AlphaL<White,Int<0>>,TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<2>>,Int<-1>>>,EFFECT_USER1>,TransitionPulseL<TrConcat<TrExtend<300,TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<2>>>,TrDoEffect<TrWipeIn<100>,EFFECT_FAST_OFF>,TrDelay<1000>>,Mult<EffectPulseF<EFFECT_CLASH>,HoldPeakF<EffectPulseF<EFFECT_USER2>,Int<3000>,Int<32768>>>>,TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<1>>,EFFECT_USER2>,TransitionPulseL<TrConcat<TrExtend<500,TrFade<100>>,TrFade<500>>,ThresholdPulseF<Mult<Sum<EffectPulseF<EFFECT_RETRACTION>,EffectPulseF<EFFECT_CLASH>>,HoldPeakF<EffectPulseF<EFFECT_FAST_OFF>,Int<10500>,Int<32768>>>>>,TransitionEffectL<TrConcat<TrDelay<1000>,TrExtendX<Int<7500>,TrDoEffectAlwaysX<TrInstant,EFFECT_TRANSITION_SOUND,Int<3>>>,TrExtend<500,TrDoEffectAlwaysX<TrWipe<300>,EFFECT_TRANSITION_SOUND,Int<4>>>,TrDoEffectAlways<TrFade<300>,EFFECT_FAST_ON>>,EFFECT_FAST_OFF>,TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<2>>,Int<-1>>,EFFECT_USER3>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,TransitionEffectL<TrConcat<TrDelay<10>,Black,TrExtendX<Int<1000>,TrWipeX<Int<300>>>,AlphaL<White,Int<0>>,TrExtend<11900,TrInstant>,AlphaL<RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Scale<Percentage<Subtract<TimeSinceEffect<EFFECT_USER5>,Sum<Int<300>,Int<1000>>>,234>,Int<0>,Int<28000>>,Scale<Percentage<Subtract<TimeSinceEffect<EFFECT_USER5>,Sum<Int<300>,Int<1000>,Int<10>>>,234>,Int<2000>,Int<31000>>>,Int<-2000>>>,TrExtend<3100,TrWipe<1000>>,AlphaL<RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,SmoothStep<Scale<SlowNoise<Int<3000>>,Int<27000>,Int<31000>>,Int<-2000>>>,TrInstant,RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,TrExtend<1000,TrInstant>,RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,TrFade<1000>>,EFFECT_USER5>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrExtend<11900,TrInstant>,AlphaL<RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Scale<Percentage<TimeSinceEffect<EFFECT_USER1>,234>,Int<0>,Int<28000>>,Scale<Percentage<TimeSinceEffect<EFFECT_USER1>,234>,Int<2000>,Int<31000>>>,Int<-2000>>>,TrExtend<3100,TrWipe<1000>>,AlphaL<RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,SmoothStep<Scale<SlowNoise<Int<3000>>,Int<27000>,Int<31000>>,Int<-2000>>>,TrInstant,RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,TrExtend<1000,TrInstant>,RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,TrFade<1000>>,EFFECT_USER1>,TransitionPulseL<TrConcat<TrExtend<300,TrInstant>,BrownNoiseFlicker<ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrWipeX<Int<500>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Black,300>,TrWipeIn<100>,Mix<SmoothStep<Int<1000>,Int<-500>>,Black,BrownNoiseFlickerL<ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrWipeX<Int<500>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Int<300>>>,TrDelay<1000>>,Mult<EffectPulseF<EFFECT_CLASH>,HoldPeakF<EffectPulseF<EFFECT_USER2>,Int<3000>,Int<32768>>>>,TransitionPulseL<TrConcat<TrExtend<500,TrFade<100>>,RandomPerLEDFlickerL<Black>,TrFade<500>>,ThresholdPulseF<Mult<Sum<EffectPulseF<EFFECT_RETRACTION>,EffectPulseF<EFFECT_CLASH>>,HoldPeakF<EffectPulseF<EFFECT_FAST_OFF>,Int<10500>,Int<32768>>>>>,TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<BrownNoiseFlickerL<ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrWipeX<Int<500>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Int<300>>,SmoothStep<Int<1000>,Int<-500>>>,TrExtendX<Int<7500>,TrInstant>,AlphaL<RandomFlicker<Black,BrownNoiseFlickerL<ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrWipeX<Int<500>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Int<300>>>,SmoothStep<Int<1000>,Int<-500>>>,TrExtend<500,TrWipe<300>>,Layers<ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrWipeX<Int<500>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,AlphaL<Gradient<AlphaL<White,Int<0>>,RandomPerLEDFlickerL<Black>,Black,Black>,SmoothStep<Scale<SlowNoise<Int<4000>>,Int<8000>,Int<16000>>,Scale<SlowNoise<Int<2000>>,Int<10000>,Int<4000>>>>>,TrFade<300>>,EFFECT_FAST_OFF>,TransitionEffectL<TrConcat<TrDoEffectAlwaysX<TrInstant,EFFECT_FAST_ON,Int<-1>,Int<-1>>,AlphaL<White,Int<0>>,TrDelayX<Sum<Int<300>,Int<1000>>>,AlphaL<White,Int<0>>,TrExtend<16000,TrDoEffectAlwaysX<TrInstant,EFFECT_TRANSITION_SOUND,Int<5>>>,AlphaL<White,Int<0>>,TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<2>>,Int<-1>>>,EFFECT_USER5>>>(),

//Emitter Outer Ring
	StylePtr<Layers<
	  TransitionLoop<Black,TrConcat<TrDelay<800>,Black,TrConcat<TrFade<100>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,TrFade<300>>,Black,TrDelay<400>>>,
	  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
	  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
	  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
	  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
	  TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<255,255,255>>,Int<100>>,TrFade<1200>>,EFFECT_IGNITION>,
	  InOutTrL<TrInstant,TrFade<300>,TransitionLoop<Black,TrConcat<TrFade<250>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,TrFade<500>,Black,TrDelay<2250>>>>
	>>(),

//Emitter Mid Ring A (make sure to match styles A & B)
    StylePtr<Layers<
  	  TransitionLoop<Black,TrConcat<TrDelay<400>,Black,TrConcat<TrFade<100>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,TrFade<300>>,Black,TrDelay<800>>>,
  	  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
  	  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
  	  LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  	  TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
  	  TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<255,255,255>>,Int<100>>,TrFade<1200>>,EFFECT_IGNITION>,
  	  InOutTrL<TrInstant,TrFade<300>,TransitionLoop<Black,TrConcat<TrDelay<750>,Black,TrConcat<TrFade<250>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,TrFade<500>>,Black,TrDelay<1500>>>>
  	>>(),

	  //crystal
	  
		/* copyright Fett263 CustomBlade (Accent LED / PCB) OS7 Style
		https://www.fett263.com/fett263-proffieOS7-style-library.html#CustomBlade
		OS7.14 v2.25p
		Single Style
		Multi Phase (Special Abilities*)
		Default: Hyper Responsive Rotoscope (Original Trilogy) [BaseColorArg]
		1: Unstable Rage [AltColorArg]

		Off Behavior: Fast Pulse Off-On [Color: Multi Phase]

		Multi Phase Control: use Special Abilities controls to change Phase. Requires Alt Font.

		*This style REQUIRES Alt Fonts alt000/ to alt001/ to be set up. Uses altchng.wav on change.
		See https://pod.hubbe.net/sound/alt_sounds.html for more information.
		--Effects Included--
		Ignition Effect: Instant [Color: IgnitionColorArg]
		Retraction Effect: Instant [Color: RetractionColorArg]
		Lockup Effect: NoneLightning Block Effect: NoneDrag Effect:
		0: accentDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
		[Color: DragColorArg]
		Melt Effect:
		0: accentMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
		[Color: StabColorArg]
		Special Ability 1: Next Phase
		Special Ability 8: Next Phase

		*/
		StylePtr<Layers<Black,ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrFadeX<Int<1000>>>,Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Stripes<3000,-3500,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Black>,BrownNoiseFlicker<RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,200>,RandomPerLEDFlicker<Mix<Int<10280>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,31000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrInstant,TrInstant,Pulsing<Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,2000>>>>(),
	  
     // chassis strip right
      	StylePtr<Layers<
      	Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,Gradient<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<255,255,0>>>>,
      	TransitionEffectL<TrConcat<TrInstant,RgbArg<BLAST_COLOR_ARG,Yellow>,TrFade<400>>,EFFECT_BLAST>,
      	LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,White>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
      	LockupTrL<AudioFlickerL<RgbArg<LB_COLOR_ARG,White>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
      	TransitionEffectL<TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,White>,TrFade<400>>,EFFECT_CLASH>,
      	InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<18>>,Int<20000>>,Black,RgbArg<OFF_COLOR_ARG,Rgb<95,0,210>>>>>>(),

     // chassis strip left
      	StylePtr<Layers<
      	Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,Gradient<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<255,255,0>>>>,
      	TransitionEffectL<TrConcat<TrInstant,RgbArg<BLAST_COLOR_ARG,Yellow>,TrFade<400>>,EFFECT_BLAST>,
      	LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,White>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
      	LockupTrL<AudioFlickerL<RgbArg<LB_COLOR_ARG,White>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
      	TransitionEffectL<TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,White>,TrFade<400>>,EFFECT_CLASH>,
      	InOutTrL<TrInstant,TrInstant,Mix<Bump<Sin<Int<18>>,Int<20000>>,Black,RgbArg<OFF_COLOR_ARG,Rgb<95,0,210>>>>>>(),
  

  "OSHA" },



  { "STARFALL;common", "tracks/DOF.wav",
     // main blade
		//StylePtr<DisplayStyle<MYDISPLAY>>(),     	
	    StylePtr<Layers<Black,ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrWipeX<Int<500>>>,AudioFlicker<Stripes<22000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<10000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,AudioFlicker<Stripes<25000,-1500,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10640>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<18460>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,TransitionEffectL<TrConcat<TrExtend<16000,TrDoEffectAlwaysX<TrDelay<10>,EFFECT_TRANSITION_SOUND,Int<0>>>,AlphaL<White,Int<0>>,TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<2>>,Int<-1>>>,EFFECT_USER1>,TransitionPulseL<TrConcat<TrExtend<300,TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<2>>>,TrDoEffect<TrWipeIn<100>,EFFECT_FAST_OFF>,TrDelay<1000>>,Mult<EffectPulseF<EFFECT_CLASH>,HoldPeakF<EffectPulseF<EFFECT_USER2>,Int<3000>,Int<32768>>>>,TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<1>>,EFFECT_USER2>,TransitionPulseL<TrConcat<TrExtend<500,TrFade<100>>,TrFade<500>>,ThresholdPulseF<Mult<Sum<EffectPulseF<EFFECT_RETRACTION>,EffectPulseF<EFFECT_CLASH>>,HoldPeakF<EffectPulseF<EFFECT_FAST_OFF>,Int<10500>,Int<32768>>>>>,TransitionEffectL<TrConcat<TrDelay<1000>,TrExtendX<Int<7500>,TrDoEffectAlwaysX<TrInstant,EFFECT_TRANSITION_SOUND,Int<3>>>,TrExtend<500,TrDoEffectAlwaysX<TrWipe<300>,EFFECT_TRANSITION_SOUND,Int<4>>>,TrDoEffectAlways<TrFade<300>,EFFECT_FAST_ON>>,EFFECT_FAST_OFF>,TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<2>>,Int<-1>>,EFFECT_USER3>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,TransitionEffectL<TrConcat<TrDelay<10>,Black,TrExtendX<Int<1000>,TrWipeX<Int<300>>>,AlphaL<White,Int<0>>,TrExtend<11900,TrInstant>,AlphaL<RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Scale<Percentage<Subtract<TimeSinceEffect<EFFECT_USER5>,Sum<Int<300>,Int<1000>>>,234>,Int<0>,Int<28000>>,Scale<Percentage<Subtract<TimeSinceEffect<EFFECT_USER5>,Sum<Int<300>,Int<1000>,Int<10>>>,234>,Int<2000>,Int<31000>>>,Int<-2000>>>,TrExtend<3100,TrWipe<1000>>,AlphaL<RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,SmoothStep<Scale<SlowNoise<Int<3000>>,Int<27000>,Int<31000>>,Int<-2000>>>,TrInstant,RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,TrExtend<1000,TrInstant>,RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,TrFade<1000>>,EFFECT_USER5>,InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,TransitionEffectL<TrConcat<TrExtend<11900,TrInstant>,AlphaL<RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Scale<Percentage<TimeSinceEffect<EFFECT_USER1>,234>,Int<0>,Int<28000>>,Scale<Percentage<TimeSinceEffect<EFFECT_USER1>,234>,Int<2000>,Int<31000>>>,Int<-2000>>>,TrExtend<3100,TrWipe<1000>>,AlphaL<RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,SmoothStep<Scale<SlowNoise<Int<3000>>,Int<27000>,Int<31000>>,Int<-2000>>>,TrInstant,RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,ColorSelect<AltF,TrInstant,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,TrExtend<1000,TrInstant>,RandomFlicker<Stripes<24000,-1400,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<11565>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<16448>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,TrFade<1000>>,EFFECT_USER1>,TransitionPulseL<TrConcat<TrExtend<300,TrInstant>,BrownNoiseFlicker<ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrWipeX<Int<500>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Black,300>,TrWipeIn<100>,Mix<SmoothStep<Int<1000>,Int<-500>>,Black,BrownNoiseFlickerL<ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrWipeX<Int<500>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Int<300>>>,TrDelay<1000>>,Mult<EffectPulseF<EFFECT_CLASH>,HoldPeakF<EffectPulseF<EFFECT_USER2>,Int<3000>,Int<32768>>>>,TransitionPulseL<TrConcat<TrExtend<500,TrFade<100>>,RandomPerLEDFlickerL<Black>,TrFade<500>>,ThresholdPulseF<Mult<Sum<EffectPulseF<EFFECT_RETRACTION>,EffectPulseF<EFFECT_CLASH>>,HoldPeakF<EffectPulseF<EFFECT_FAST_OFF>,Int<10500>,Int<32768>>>>>,TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<BrownNoiseFlickerL<ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrWipeX<Int<500>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Int<300>>,SmoothStep<Int<1000>,Int<-500>>>,TrExtendX<Int<7500>,TrInstant>,AlphaL<RandomFlicker<Black,BrownNoiseFlickerL<ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrWipeX<Int<500>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,Int<300>>>,SmoothStep<Int<1000>,Int<-500>>>,TrExtend<500,TrWipe<300>>,Layers<ColorSelect<AltF,TrSelect<Ifon<Int<1>,Int<0>>,TrInstant,TrWipeX<Int<500>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,AlphaL<Gradient<AlphaL<White,Int<0>>,RandomPerLEDFlickerL<Black>,Black,Black>,SmoothStep<Scale<SlowNoise<Int<4000>>,Int<8000>,Int<16000>>,Scale<SlowNoise<Int<2000>>,Int<10000>,Int<4000>>>>>,TrFade<300>>,EFFECT_FAST_OFF>,TransitionEffectL<TrConcat<TrDoEffectAlwaysX<TrInstant,EFFECT_FAST_ON,Int<-1>,Int<-1>>,AlphaL<White,Int<0>>,TrDelayX<Sum<Int<300>,Int<1000>>>,AlphaL<White,Int<0>>,TrExtend<16000,TrDoEffectAlwaysX<TrInstant,EFFECT_TRANSITION_SOUND,Int<5>>>,AlphaL<White,Int<0>>,TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<2>>,Int<-1>>>,EFFECT_USER5>>>(),
     
    // emitter inner
     	StylePtr<Layers<
 		RgbArg<BASE_COLOR_ARG,Red>,
 		TransitionEffectL<TrConcat<TrInstant,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,EFFECT_BLAST>,
 		LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
 		LockupTrL<AudioFlickerL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
 		TransitionEffectL<TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,EFFECT_CLASH>,
 		InOutTrL<TrInstant,TrFadeX<RetractionTime<>>,Pulsing<Black,RgbArg<OFF_COLOR_ARG,Red>,5000>>>>(),

    // emitter outer
     	StylePtr<Layers<
 		ColorCycle<RgbArg<OFF_COLOR_ARG,Red>,35,100,RgbArg<BASE_COLOR_ARG,Red>,35,250,5000>,
 		TransitionEffectL<TrConcat<TrInstant,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,EFFECT_BLAST>,
 		LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
 		LockupTrL<AudioFlickerL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
 		TransitionEffectL<TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,EFFECT_CLASH>,
 		InOutTrL<TrFadeX<IgnitionTime<0>>,TrFadeX<RetractionTime<>>>>>(),

    // crystal chamber
     	StylePtr<Layers<
 		Sparkle<RandomPerLEDFlicker<RgbArg<BASE_COLOR_ARG,Red>,Mix<Int<10560>,Black,RgbArg<BASE_COLOR_ARG,Red>>>,Moccasin,25,999>,
 		TransitionEffectL<TrConcat<TrInstant,RgbArg<BLAST_COLOR_ARG,White>,TrFade<400>>,EFFECT_BLAST>,
 		LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,White>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
 		LockupTrL<AudioFlickerL<RgbArg<LB_COLOR_ARG,White>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
 		TransitionEffectL<TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,White>,TrFade<400>>,EFFECT_CLASH>,
 		TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RgbArg<IGNITION_COLOR_ARG,White>,40>,TrFade<1200>>,EFFECT_IGNITION>,
 		InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<OFF_COLOR_ARG,Red>,5000>>>>(),

    // chassis strip right
     	StylePtr<Layers<
 		TransitionLoop<RgbArg<BASE_COLOR_ARG,Black>,TrConcat<TrWipe<200>,Rgb<95,0,210>,TrWipe<200>>>,
 		TransitionEffectL<TrConcat<TrInstant,RgbArg<BLAST_COLOR_ARG,DarkOrange>,TrFade<400>>,EFFECT_BLAST>,
 		LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,LemonChiffon>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
 		LockupTrL<AudioFlickerL<RgbArg<LB_COLOR_ARG,AliceBlue>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
 		TransitionEffectL<TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Red>,TrFade<400>>,EFFECT_CLASH>,
 		TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrFade<1200>>,EFFECT_IGNITION>,
 		InOutTrL<TrInstant,TrInstant,TransitionLoop<Black,TrConcat<TrJoinR<TrWipe<1250>,TrWipeIn<1250>>,RgbArg<OFF_COLOR_ARG,Rgb<95,0,210>>,TrJoinR<TrWipe<1250>,TrWipeIn<1250>>>>>>>(),

    // chassis strip left
     	StylePtr<Layers<
 		TransitionLoop<RgbArg<BASE_COLOR_ARG,Black>,TrConcat<TrWipe<200>,Rgb<95,0,210>,TrWipe<200>>>,
 		TransitionEffectL<TrConcat<TrInstant,RgbArg<BLAST_COLOR_ARG,DarkOrange>,TrFade<400>>,EFFECT_BLAST>,
 		LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,LemonChiffon>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
 		LockupTrL<AudioFlickerL<RgbArg<LB_COLOR_ARG,AliceBlue>>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
 		TransitionEffectL<TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Red>,TrFade<400>>,EFFECT_CLASH>,
 		TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrFade<1200>>,EFFECT_IGNITION>,
 		InOutTrL<TrInstant,TrInstant,TransitionLoop<Black,TrConcat<TrJoinR<TrWipe<1250>,TrWipeIn<1250>>,RgbArg<OFF_COLOR_ARG,Rgb<95,0,210>>,TrJoinR<TrWipe<1250>,TrWipeIn<1250>>>>>>>(),

  "starfall"},
  
    
};	
			

BladeConfig blades[] = {
	{ 0,
 	   SubBladeWithList 
 	     // Row 1 (left-to-right)
 	     <16, 17, 18, 19, 20, 
 	     // Row 2 (right-to-left)
 	      27, 26, 25, 24, 23, 22, 21,
 	     // Row 3 (left-to-right)
 	     28, 29, 30, 31, 32, 33, 34, 35, 36, 
 	     // Row 4 (right-to-left)
 	      45, 44, 43, 42, 41, 40, 39, 38, 37,
 	     // Row 5 (left-to-right)
 	     46, 47, 48, 49, 50, 51, 52, 53, 54, 
 	     // Row 6 (right-to-left)
 	     63, 62, 61, 60, 59, 58, 57, 56, 55,
 	     // Row 7 (left-to-right)
 	     64, 65, 66, 67, 68, 69, 70, 71, 72, 
 	     // Row 8 (right-to-left)
 	     79, 78, 77, 76, 75, 74, 73,
 	     // Row 9 (left-to-right)
 	     80, 81, 82, 83, 84>
 	   (WS281XBladePtr<85, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ), /* proffie blade plug */
	    SubBladeWithStride (0, 14, 2, NULL), /* emitter inner ring 8px */
	    SubBladeWithStride (1, 15, 2, NULL), /* emitter outer ring 8px */

	    WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), /* crystal chamber 11px */

	    WS281XBladePtr<15, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(), /* chassis strip right 15px */

	    WS281XBladePtr<15, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(), /* chassis strip left 15px */

	    CONFIGARRAY(p1), "1savep" },
	{ 1,
	    SubBlade(16, 93,WS281XBladePtr<148, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ), /* 20in main blade 78px */
	    SubBladeWithStride (0, 14, 2, NULL), /* emitter inner ring 8px */
	    SubBladeWithStride (1, 15, 2, NULL), /* emitter outer ring 8px */

	    WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), /* crystal chamber 11px */

	    WS281XBladePtr<15, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(), /* chassis strip right 15px */

	    WS281XBladePtr<15, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(), /* chassis strip left 15px */

	    CONFIGARRAY(p1), "1savep" },
 	  
	{ 2,
		    SubBlade(16, 105,WS281XBladePtr<148, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ), /* 24in main blade 90px */
		    SubBladeWithStride (0, 14, 2, NULL), /* emitter inner ring 8px */
		    SubBladeWithStride (1, 15, 2, NULL), /* emitter outer ring 8px */

		    WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), /* crystal chamber 11px */

		    WS281XBladePtr<15, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(), /* chassis strip right 15px */

		    WS281XBladePtr<15, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(), /* chassis strip left 15px */

		    CONFIGARRAY(p1), "1savep" },

	{ 3,
		    SubBlade(16, 132,WS281XBladePtr<148, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ), /* 32in main blade 117px */
		    SubBladeWithStride (0, 14, 2, NULL), /* emitter inner ring 8px */
		    SubBladeWithStride (1, 15, 2, NULL), /* emitter outer ring 8px */

		    WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), /* crystal chamber 11px */

		    WS281XBladePtr<15, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(), /* chassis strip right 15px */

		    WS281XBladePtr<15, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(), /* chassis strip left 15px */

		    CONFIGARRAY(p1), "1savep" },
 
	{ 4,
		    SubBlade(16, 147,WS281XBladePtr<148, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ), /* 36in main blade 132px */
		    SubBladeWithStride (0, 14, 2, NULL), /* emitter inner ring 8px */
		    SubBladeWithStride (1, 15, 2, NULL), /* emitter outer ring 8px */

		    WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), /* crystal chamber 11px */

		    WS281XBladePtr<15, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(), /* chassis strip right 15px */

		    WS281XBladePtr<15, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(), /* chassis strip left 15px */

		    CONFIGARRAY(p1), "1savep" },
   
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, auxPin, "pow");
Button AuxButton(BUTTON_AUX, powerButtonPin, "aux");
#endif