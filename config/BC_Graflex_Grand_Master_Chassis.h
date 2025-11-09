#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 7
#define NUM_BUTTONS 2
#define VOLUME 900
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 2.7
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SSD1306
#define ENABLE_SERIAL
#define SHARED_POWER_PINS
#define BLADE_DETECT_PIN blade4Pin
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2,bladePowerPin3>
#define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin>
#define MOTION_TIMEOUT 60 * 15 * 1000
#define IDLE_TIME_OFF 60 * 5 * 1000
#define PLI_OFF_TIME 60 * 5 * 1000
#define ENABLE_SPINS
#endif
 
// Blade 1 - Main Blade
// Blade 2 - Crystal Top
// Blade 4 - LED strips
// Blade 5 - Arc Reactor
// Blade 6 - Speaker 3mm
// Blade 7 - Motor

#ifdef CONFIG_PRESETS
 
Preset crystal_1_in[] = {

{ "TeensySF;common", "", // ANH Luke blade, blue based crystals and accents.
// Main Blade
   StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    // Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
        AlphaL<Black,Int<16384>>,
        AlphaL<Black,Int<0>>>,
    // Clash 1 - BladeAngle responsive. Yellowish impact
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
    // Stab - OrangeRed stripes
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
    // Blast
    TransitionEffectL<TrConcat<
        // Impact Flash - BC always
        TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
        // Waves
        BlastL<White,850,250,351>,
        // Impact point afterimage
        //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
        AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<255,70,70>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
        // Impact point
        //BlastL<White,500,350,100000>,
        BlastL<White,300,350,100000>,
    // Lockup 1 - BC custom range mid-blade to hilt w/random strobe flash
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
        //Random Strobe Flash no dimming
        AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
        //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
        // Bottom Layer Bump - random width
        AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
        // Top Layer Bump - fixed width
        AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,          Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,
        // Begin Lockup Transition
        TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
        // End Lockup Transition
        TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
    // Non-Responsive Drag - BC custom drag fadeout
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
    LockupTrL<Layers<
        //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
        AlphaL<Black,Int<16000>>,
        AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
        AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<
        Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
        // Begin Lightning Transition
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
        // End Lightning Transition    
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    // Melt - BC custom melt effects, uses twistangle<>
    LockupTrL<
        // OS 5.9
        // AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
        // OS 6 (Based on "Intenity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
        AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
        // Melt Shape
        SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
        // Melt Begin and End transitions
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTip<White,400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Green,Bump<Int<0>,Int<1000>>>,TrDelay<90>,AlphaL<DodgerBlue,Bump<Int<0>,Int<1000>>>,TrFade<100>,AlphaL<DeepSkyBlue,Bump<Int<0>,Int<1000>>>,TrDelay<200>>,EFFECT_PREON>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),     
// Crystal Top
  StylePtr<Layers<
    // Jedi Crystal Blue
    Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Blue,Black,2500>>>
  >>(),
// Crystal Bot
  StylePtr<Layers<
    // Jedi Crystal Blue
    Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Blue,Black,2000>>>
  >>(),
// LED Strips
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<Blue,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<
    // Jedi Crystal Blue
    Stripes<1000,-2000,Black,RotateColorsX<Variation,Rgb<0,0,128>>,RotateColorsX<Variation,Blue>>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Blue,Black,2000>>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<InOutHelper<Rgb<128,128,128>,300,800>>(),
"anh\ntraining"},
 
};

//---------------------------------------------------------------------------------------------------------------------------------

Preset crystal_2_in[] = {

{ "SmthGrey;common", "",
// Main Blade
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
    // Force Choke / lightning
    TransitionEffectL<TrConcat<TrSmoothFade<1000>,Strobe<Black,Rgb<80,0,0>,30,30>,TrFade<1500>,StyleFire<Red,Strobe<Black,White,30,30>,0,3,FireConfig<300,2000,5>>,TrFade<400>>,EFFECT_FORCE>,
    // Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
        AlphaL<Black,Int<16384>>,
        AlphaL<Black,Int<0>>>,
    // Clash 2 - for red blades
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
    // Stab - OrangeRed stripes
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
    // Blast v1
    TransitionEffectL<TrConcat<
        // Impact Flash - BC always
        TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
        // Waves
        BlastL<Rgb<100,200,255>,850,250,351>,
        // Impact point afterimage
        //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
        AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
        // Impact point
        //BlastL<Rgb<100,200,255>,500,350,100000>,
        BlastL<Rgb<100,200,255>,300,350,100000>,
    // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
        //Random Strobe Flash no dimming
        AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
        //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
        // Bottom Layer Bump - random width
        AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
        // Top Layer Bump - fixed width
        AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                              Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
        // Begin Lockup Transition
        TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,   Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
        // End Lockup Transition
        TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                  Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
    // Non-Responsive Drag - BC custom drag fadeout
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
    LockupTrL<Layers<
        //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
        AlphaL<Black,Int<16000>>,
        AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
        AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
        Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
        // Begin Lightning Transition
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
        // End Lightning Transition    
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    // Melt - BC custom melt effects, uses twistangle<>
    LockupTrL<
        AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
        // Melt Shape
        SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
        // Melt Begin and End transitions
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
        InOutTrL<TrWipeSparkTip<White,500>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
        // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
// Crystal Top
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<130,0,0>>>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Red,Black,2500>>
    >>(),
// Crystal Bottom
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Rgb<130,0,0>>,RotateColorsX<Variation,Red>>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Red,Black,2500>>
    >>(),
// LED Strips
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,Black>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,ColorCycle<Red,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<
    RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<130,0,0>>>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Red,Black,2500>>
    >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
StylePtr<InOutHelper<Rgb<128,128,128>,300,800>>(),
"darth\vader"}

};

//---------------------------------------------------------------------------------------------------------------------------------

Preset crystal_out[] = {

{ "RootCore;common", "tracks/RC.wav",
// Main Blade
  StylePtr<Black>(), // Blade "doesn't work" without crystal inserted...?
// Crystal Top
  StylePtr<Black>(),
// Crystal Bottom
  StylePtr<Black>(),
// Led Strips
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<128,128,0>>,Black>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<Orange,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<128,128,0>>>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Orange,Black,2500>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<IgnitionDelay<2000,InOutHelper<Rgb<128,128,128>,300,800>
  >>(),
"root\ncore"}

};


BladeConfig blades[] = {
 { 100000, // Crystal #1 ID resistor value as per Serial Monitor
// Main Blade 122 LEDs Data 3 Power 2&3
    WS281XBladePtr<122, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
// Crystals - 2 discrete blades for the 2 LEDS Data 1 Power 4
    SubBlade(1, 1, WS281XBladePtr<2, bladePin, Color8::GRB, PowerPINS<bladePowerPin4> >()),
    SubBlade(0, 0, NULL),
// LED strip (parallel w/ 2nd strip) and Arc reactor 1 LEDs Data 2 Power 6
    SubBlade(1, 6, WS281XBladePtr<7, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin6> >()),
    SubBlade(0, 0, NULL),
// Speaker 3mm White LED Data NA Power 1
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),
// Motor Data NA Power 5
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>(),
 CONFIGARRAY(crystal_1_in), "01_crystal_1_in_save", }, 


 {47000, // Crystal #2 ID resistor value as per Serial Monitor
// Main Blade 122 LEDs Data 3 Power 2&3
    WS281XBladePtr<122, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
// Crystals - 2 discrete blades for the 2 LEDS Data 1 Power 4
    SubBlade(1, 1, WS281XBladePtr<2, bladePin, Color8::GRB, PowerPINS<bladePowerPin4> >()),
    SubBlade(0, 0, NULL),
// LED strip (parallel w/ 2nd strip) and Arc reactor 1 LEDs Data 2 Power 6
    SubBlade(1, 6, WS281XBladePtr<7, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin6> >()),
    SubBlade(0, 0, NULL),
// Speaker 3mm White LED Data NA Power 1
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),
// Motor Data NA Power 5
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>(),
 CONFIGARRAY(crystal_2_in), "02_crystal_2_in_save", }, 



 { 200000,
 // Main Blade 122 LEDs Data 3 Power 2&3
    WS281XBladePtr<122, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
// Crystals - 2 discrete blades for the 2 LEDS Data 1 Power 4
    SubBlade(1, 1, WS281XBladePtr<2, bladePin, Color8::GRB, PowerPINS<bladePowerPin4> >()),
    SubBlade(0, 0, NULL),
// LED strip (parallel w/ 2nd strip) and Arc reactor 1 LEDs Data 2 Power 6
    SubBlade(1, 6, WS281XBladePtr<7, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin6> >()),
    SubBlade(0, 0, NULL),
// Speaker 3mm White LED Data NA Power 1
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),
// Motor Data NA Power 5
    SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>(),
 CONFIGARRAY(crystal_out), "03_crystal_out_save" },
 
 
};
#endif
 
 
#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif