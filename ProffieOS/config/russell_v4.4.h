#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 7
#define NUM_BUTTONS 2
#define VOLUME 1800
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SSD1306
#define ENABLE_SERIAL
#define SHARED_POWER_PINS
#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define BLADE_DETECT_PIN blade4Pin
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2,bladePowerPin3>
#define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin>
#define MOTION_TIMEOUT 60 * 15 * 1000
#define IDLE_TIME_OFF 60 * 5 * 1000
#define PLI_OFF_TIME 60 * 5 * 1000
#define ENABLE_SPINS
#define SAVE_STATE
#endif


#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons.h"
#endif
 
// Blade 1 - Main Blade
// Blade 2 - Crystal Top
// Blade 3 - Crystal Bottom
// Blade 4 - LED strips
// Blade 5 - Arc Reactor
// Blade 6 - Speaker 3mm
// Blade 7 - Motor

#ifdef CONFIG_PRESETS


Preset crystal[] = {

{ "Boonta_Champ;common", "tracks/The_Pod_Race.wav",
// Main Blade
  StylePtr<Layers<
    // Base Orange
    StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,DarkOrange>,Pulsing<RotateColorsX<Variation,Rgb<90,24,0>>,RotateColorsX<Variation,DarkOrange>,800>,RotateColorsX<Variation,DarkOrange>>,
    // Force Orange
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<160,43,0>>>,TrDelay<3000>,RotateColorsX<Variation,DarkOrange>,TrFade<800>>,EFFECT_FORCE>,
    // Swing Orange
    AlphaL<RotateColorsX<Variation,Rgb<255,178,110>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
  // Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
        AlphaL<Black,Int<16384>>,
        AlphaL<Black,Int<0>>>,
  // Clash 1 - BladeAngle responsive. Yellowish impact
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
  // Stab - OrangeRed stripes
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Red,Rgb<150,20,0>,Rgb<60,10,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,  // Blast - Blaster reflect cycles through different responsive effects
    // Impact Flash - BC always
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
    EffectSequence<EFFECT_BLAST,
    //ResponsiveBlastL
    AlphaL<MultiTransitionEffectL<TrWaveX<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<24000>>>,
    LocalizedClashL<White,80,30,EFFECT_BLAST>,
    // ResponsiveBlastWaveL
    MultiTransitionEffectL<TrWaveX<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>,Int<401>,Scale<BladeAngle<>,Int<28001>,Int<8001>>>,EFFECT_BLAST,3>,
    BlastL<White,200,200>,
    // ResponsiveBlastFadeL
    MultiTransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>>>,TrFadeX<Scale<SwingSpeed<400>,Int<400>,Int<100>>>>,EFFECT_BLAST,3>,
    // ResponsiveBlastL
    AlphaL<MultiTransitionEffectL<TrWaveX<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<24000>>>>,
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
        AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
        // Melt Shape
        SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
        // Melt Begin and End transitions
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
  // Ignition and Retraction
    InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<600>,Int<400>,Int<400>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(), 
// Crystal Top 
  StylePtr<Layers<
    // Crystal Orange
    PulsingX<Stripes<1000,-2000,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<90,24,0>>,Black>,DarkOrange,NoisySoundLevel>,
    // Force Orange
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<160,43,0>>>,TrDelay<3000>,RotateColorsX<Variation,DarkOrange>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<RotateColorsX<Variation,DarkOrange>,Black,3000>>
  >>(),
// Crystal Bottom 
  StylePtr<Layers<
    // Crystal Orange
    PulsingX<Stripes<1000,-2000,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<90,24,0>>,Black>,DarkOrange,NoisySoundLevel>,
    // Force Orange
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<160,43,0>>>,TrDelay<3000>,RotateColorsX<Variation,DarkOrange>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Black,RotateColorsX<Variation,DarkOrange>,3000>>
  >>(),
// LED Strips
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<90,24,0>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,DarkOrange>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,DarkOrange>,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<Black,
    Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<160,43,0>>>,TrDelay<3000>,RotateColorsX<Variation,DarkOrange>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
  >(),
   "boonta\nchamp"},



{ "Cantina;common", "tracks/Cantina.wav",
// Main Blade
  StylePtr<Layers<
    // Base Blue
    Mix<SwingSpeed<400>,AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,Mix<SwingSpeed<600>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<150,150,255>>>>,
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
        // OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
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
    // Crystal Blue
    Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<RotateColorsX<Variation,Blue>,Black,3000>>
  >>(),
// Crystal Bot
  StylePtr<Layers<
    // Crystal Blue
    Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Black,RotateColorsX<Variation,Blue>,3000>>
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
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Blue>,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<Black,
    Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<InOutHelper<Rgb<128,128,128>,300,800>>(),
"cantina"},



// { "PURPLE;common", "tracks/Uranus.wav",
// // Main Blade
//   StylePtr<Layers<
//     // Base Purple
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<95,0,225>>,Pulsing<RotateColorsX<Variation,Rgb<39,5,71>>,RotateColorsX<Variation,Rgb<95,0,225>>,800>,RotateColorsX<Variation,Rgb<95,0,225>>>,
//     // Force Purple
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<95,0,225>>,TrFade<800>>,EFFECT_FORCE>,
//     // Swing Purple
//     AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//         AlphaL<Black,Int<16384>>,
//         AlphaL<Black,Int<0>>>,
//   // Clash 1 - BladeAngle responsive. Yellowish impact
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//   // Stab - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//   // Blast
//     TransitionEffectL<TrConcat<
//         // Impact Flash - BC always
//         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//         // Waves
//         BlastL<White,850,250,351>,
//         // Impact point afterimage
//         //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<255,70,70>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         // Impact point
//         //BlastL<White,500,350,100000>,
//         BlastL<White,300,350,100000>,
//   // Lockup 1 - BC custom range mid-blade to hilt w/random strobe flash
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//         //Random Strobe Flash no dimming
//         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//         //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         // Bottom Layer Bump - random width
//         AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//         // Top Layer Bump - fixed width
//         AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,          Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,
//         // Begin Lockup Transition
//         TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//         // End Lockup Transition
//         TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//   // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
//     LockupTrL<Layers<
//         //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
//         AlphaL<Black,Int<16000>>,
//         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<
//         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//         // Begin Lightning Transition
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
//         // End Lightning Transition    
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//         // OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
//         AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
//         // Melt Shape
//         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
//         // Melt Begin and End transitions
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
//   // Ignition and Retraction
//     InOutTrL<TrJoin<TrWipeX<Int<500>>,TrWaveX<White,Int<1000>,Int<400>,Int<400>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(), 
// // Crystal Top
//   StylePtr<Layers<
//     // Crystal Purple
//     Stripes<1000,-2000,RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<39,5,71>>,Black>,
//     // Force Purple
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<95,0,225>>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<RotateColorsX<Variation,Rgb<95,0,225>>,Black,2000>>>
//   >(),
// // Crystal Bottom
//   StylePtr<Layers<
//     // Crystal Purple
//     Stripes<1000,-2000,RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<39,5,71>>,Black>,
//     // Force Purple
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<95,0,225>>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Black,RotateColorsX<Variation,Rgb<95,0,225>>,2000>>>
//   >(),
// // LED Strips
//   StylePtr<Layers<
//     Stripes<1000,-2000,RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<39,5,71>>,Black>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<95,0,225>>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Blue>,10,30,Black,100,3000,1>>
//   >>(),
// // Arc Reactor
//   StylePtr<Layers<Black,
//     Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<95,0,225>>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
//     InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
//   >>(),
// // Speaker 3mm White LED Data NA Power 6
//   StylePtr<Layers<
//     Blinking<Black,White,1500,500>,
//     InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
//   >>(),
// // Motor Data NA Power 5
//   StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
//   >(),
//  "purple}"},


// {"BLUE;common", "tracks/Force.wav",
// // Main Blade
//   StylePtr<Layers<
//   // Base Blue
//     Mix<SwingSpeed<400>,AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,Mix<SwingSpeed<600>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<150,150,255>>>>,
//   // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//         AlphaL<Black,Int<16384>>,
//         AlphaL<Black,Int<0>>>,
//   // Clash 1 - BladeAngle responsive. Yellowish impact
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//   // Stab - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//   // Blast
//     TransitionEffectL<TrConcat<
//         // Impact Flash - BC always
//         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//         // Waves
//         BlastL<White,850,250,351>,
//         // Impact point afterimage
//         //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<255,70,70>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         // Impact point
//         //BlastL<White,500,350,100000>,
//         BlastL<White,300,350,100000>,
//   // Lockup 1 - BC custom range mid-blade to hilt w/random strobe flash
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//         //Random Strobe Flash no dimming
//         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//         //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         // Bottom Layer Bump - random width
//         AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//         // Top Layer Bump - fixed width
//         AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,          Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,
//         // Begin Lockup Transition
//         TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//         // End Lockup Transition
//         TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//   // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
//     LockupTrL<Layers<
//         //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
//         AlphaL<Black,Int<16000>>,
//         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<
//         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//         // Begin Lightning Transition
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
//         // End Lightning Transition    
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//         // OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
//         AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
//         // Melt Shape
//         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
//         // Melt Begin and End transitions
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrWipeSparkTip<White,400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Green,Bump<Int<0>,Int<1000>>>,TrDelay<90>,AlphaL<DodgerBlue,Bump<Int<0>,Int<1000>>>,TrFade<100>,AlphaL<DeepSkyBlue,Bump<Int<0>,Int<1000>>>,TrDelay<200>>,EFFECT_PREON>,
//     // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // Crystal Top
//   StylePtr<Layers<
//     // Crystal Blue
//     Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<RotateColorsX<Variation,Blue>,Black,3000>>
//   >>(),
// // Crystal Bot
//   StylePtr<Layers<
//     // Crystal Blue
//     Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Black,RotateColorsX<Variation,Blue>,3000>>
//   >>(),
// // LED Strips
//   StylePtr<Layers<
//     Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Blue>,10,30,Black,100,3000,1>>
//   >>(),
// // Arc Reactor
//   StylePtr<Layers<Black,
//     Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
//     InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
//   >>(),
// // Speaker 3mm White LED Data NA Power 6
//   StylePtr<Layers<
//     Blinking<Black,White,1500,500>,
//     InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
//   >>(),
// // Motor Data NA Power 5
//   StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
//   >(),
// "blue"},


// // { "GREEN;common", "tracks/Mars.wav",
// // // Main Blade
// //   StylePtr<Layers<
// //     Mix<SwingSpeed<400>,AudioFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,Mix<SwingSpeed<600>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<150,255,150>>>>,
// //   // Dim Blade 50% "Power Save" button combo
// //     EffectSequence<EFFECT_POWERSAVE,
// //         AlphaL<Black,Int<16384>>,
// //         AlphaL<Black,Int<0>>>,
// //   // Clash 1 - BladeAngle responsive. Yellowish impact
// //     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// //   // Stab - OrangeRed stripes
// //     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// //   // Blast
// //     TransitionEffectL<TrConcat<
// //         // Impact Flash - BC always
// //         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
// //         // Waves
// //         BlastL<White,850,250,351>,
// //         // Impact point afterimage
// //         //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
// //         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<255,70,70>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
// //         // Impact point
// //         //BlastL<White,500,350,100000>,
// //         BlastL<White,300,350,100000>,
// //   // Lockup 1 - BC custom range mid-blade to hilt w/random strobe flash
// //     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// //     LockupTrL<Layers<
// //         //Random Strobe Flash no dimming
// //         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
// //         //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
// //         // Bottom Layer Bump - random width
// //         AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
// //         // Top Layer Bump - fixed width
// //         AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,          Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,
// //         // Begin Lockup Transition
// //         TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
// //         // End Lockup Transition
// //         TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
// //     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
// //   // Non-Responsive Drag - BC custom drag fadeout
// //     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// //   // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
// //     LockupTrL<Layers<
// //         //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
// //         AlphaL<Black,Int<16000>>,
// //         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
// //         AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<
// //         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
// //         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
// //         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
// //         // Begin Lightning Transition
// //         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
// //         // End Lightning Transition    
// //         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// //   // Melt - BC custom melt effects, uses twistangle<>
// //     LockupTrL<
// //         // OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
// //         AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
// //         // Melt Shape
// //         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
// //         // Melt Begin and End transitions
// //         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
// //     InOutTrL<TrWipeSparkTip<White,400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<Green,Bump<Int<0>,Int<1000>>>,TrDelay<90>,AlphaL<DodgerBlue,Bump<Int<0>,Int<1000>>>,TrFade<100>,AlphaL<DeepSkyBlue,Bump<Int<0>,Int<1000>>>,TrDelay<200>>,EFFECT_PREON>,
// //     // On-Demand Battery Level
// //     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// //   >>(),
// // // Crystal Top
// //   StylePtr<Layers<
// //     // Crystal Blue
// //     Stripes<1000,-2000,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>,Black>,
// //     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
// //     LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
// //     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
// //     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<RotateColorsX<Variation,Green>,Black,3000>>
// //   >>(),
// // // Crystal Bot
// //   StylePtr<Layers<
// //     // Crystal Blue
// //     Stripes<1000,-2000,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>,Black>,
// //     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
// //     LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
// //     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
// //     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Black,RotateColorsX<Variation,Green>,3000>>
// //   >>(),
// // // LED Strips
// //   StylePtr<Layers<
// //     Stripes<1000,-2000,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>,Black>,
// //     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
// //     LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
// //     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
// //     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
// //     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Green>,10,30,Black,100,3000,1>>
// //   >>(),
// // // Arc Reactor
// //   StylePtr<Layers<Black,
// //     Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
// //     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
// //     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
// //     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
// //     LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
// //     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
// //     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
// //     InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
// //   >>(),
// // // Speaker 3mm White LED Data NA Power 6
// //   StylePtr<Layers<
// //     Blinking<Black,White,1500,500>,
// //     InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
// //   >>(),
// // // Motor Data NA Power 5
// //   StylePtr<InOutHelper<Rgb<128,128,128>,300,800>>(),
// // "green"},



{ "Jedi_Mantra;common", "tracks/Way_Of_The_Jedi",
// Main Blade
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
// Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
    AlphaL<Black,Int<16384>>,
    AlphaL<Black,Int<0>>>,
// Clash
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// Stab 
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,DarkOrange,Rgb<80,60,0>,Orange,Rgb<60,30,0>,Black,DarkOrange,Orange>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// Blast - white to red for blue and green blades
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
    BlastL<Red,850,250,351>,
    AlphaL<TransitionEffectL<TrConcat<TrDelay<300>,Red,TrFade<500>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
    BlastL<White,500,300,100000>,
// Lockup
    LockupTrL<Layers<       
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
      AlphaL<BrownNoiseFlicker<Yellow,Black,50>,                                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
      TrConcat<TrInstant,
      AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// Non-Responsive Drag
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// Lightning Block Non-Responsive    
    LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
    Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
    Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
    Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
    //Begin Lightning Transition
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
    //End Lightning Transition    
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,       
// Melt    
    LockupTrL<
    AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
    // Melt Shape
    SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
    //Melt Begin and End transitions
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_FORCE>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Crystal Top
  StylePtr<Layers<
    // Crystal Blue
    Stripes<1000,-2000,RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,TrDelay<3000>,RotateColorsX<Variation,DeepSkyBlue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<RotateColorsX<Variation,DeepSkyBlue>,Black,3000>>
  >>(),
// Crystal Bot
  StylePtr<Layers<
    // Crystal Blue
    Stripes<1000,-2000,RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,TrDelay<3000>,RotateColorsX<Variation,DeepSkyBlue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Black,RotateColorsX<Variation,DeepSkyBlue>,3000>>
  >>(),
// LED Strips
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,TrDelay<3000>,RotateColorsX<Variation,DeepSkyBlue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,DeepSkyBlue>,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<Black,
    Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,TrDelay<3000>,RotateColorsX<Variation,DeepSkyBlue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
  >(),
"jedi\nmantra"},



{ "Lone_Outcast", "tracks/Rain.wav",
// Main Blade
  StylePtr<Layers<
    Layers<AudioFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,200,0>>>,
    TransitionLoopL<TrWaveX<HumpFlickerL<RotateColorsX<Variation,Rgb<50,255,50>>,40>,Int<250>,Int<100>,Int<200>,Int<0>>>,
    TransitionLoopL<TrWaveX<HumpFlickerL<RotateColorsX<Variation,Green>,40>,Int<350>,Int<100>,Int<300>,Int<0>>>>,
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
        // OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
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
    // Crystal Blue
    Stripes<1000,-2000,RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,200,0>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,200,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<RotateColorsX<Variation,Green>,Black,3000>>
  >>(),
// Crystal Bot
  StylePtr<Layers<
    // Crystal Blue
    Stripes<1000,-2000,RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,200,0>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,200,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Black,RotateColorsX<Variation,Green>,3000>>
  >>(),
// LED Strips
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,200,0>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,200,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Green>,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<Black,
    Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,200,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
  >(),
"lone\noutcast"},

//};















//---------------------------------------------------------------------------------------------------------------------------------

//Preset cracked[] = {

// { "YELLOW;common", "tracks/Venus.wav",
// // Main Blade
//   StylePtr<Layers<
//     // Base Yellow
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<180,180,0>>,Pulsing<RotateColorsX<Variation,Rgb<64,64,0>>,RotateColorsX<Variation,Rgb<180,180,0>>,800>,RotateColorsX<Variation,Rgb<180,180,0>>>,
//     // Force Yellow
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<113,113,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<180,180,0>>,TrFade<800>>,EFFECT_FORCE>,
//     // Swing Yellow
//     AlphaL<RotateColorsX<Variation,Rgb<230,180,80>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     // Force Choke / lightning
//     TransitionEffectL<TrConcat<TrSmoothFade<1000>,Strobe<Black,Rgb<80,0,0>,30,30>,TrFade<1500>,StyleFire<Red,Strobe<Black,White,30,30>,0,3,FireConfig<300,2000,5>>,TrFade<400>>,EFFECT_FORCE>,
//   // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//         AlphaL<Black,Int<16384>>,
//         AlphaL<Black,Int<0>>>,
//   // Clash 2 - for red blades
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//   // Stab - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//   // Blast v1
//     TransitionEffectL<TrConcat<
//         // Impact Flash - BC always
//         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//         // Waves
//         BlastL<Rgb<100,200,255>,850,250,351>,
//         // Impact point afterimage
//         //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         // Impact point
//         //BlastL<Rgb<100,200,255>,500,350,100000>,
//         BlastL<Rgb<100,200,255>,300,350,100000>,
//   // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//         //Random Strobe Flash no dimming
//         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//         //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         // Bottom Layer Bump - random width
//         AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
//         // Top Layer Bump - fixed width
//         AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                              Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//         // Begin Lockup Transition
//         TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,   Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//         // End Lockup Transition
//         TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                  Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//   // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
//     LockupTrL<Layers<
//         //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
//         AlphaL<Black,Int<16000>>,
//         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//         // Begin Lightning Transition
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//         // End Lightning Transition    
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//         AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//         // Melt Shape
//         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//         // Melt Begin and End transitions
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrWipeSparkTip<White,400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Green,Bump<Int<0>,Int<1000>>>,TrDelay<90>,AlphaL<DodgerBlue,Bump<Int<0>,Int<1000>>>,TrFade<100>,AlphaL<DeepSkyBlue,Bump<Int<0>,Int<1000>>>,TrDelay<200>>,EFFECT_PREON>,
//     // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // Crystal Top
//   StylePtr<Layers<
//     // Crystal Yellow
//     Stripes<1000,-2000,RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<64,64,0>>,Black>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<64,64,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<180,180,0>>,TrFade<800>>,EFFECT_FORCE>,
//      TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
//     LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
//     LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<RotateColorsX<Variation,Rgb<180,180,0>>,Black,3000>>
//   >>(),
// // Crystal Bot
//   StylePtr<Layers<
//     // Crystal Yellow
//     Stripes<1000,-2000,RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<64,64,0>>,Black>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<64,64,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<180,180,0>>,TrFade<800>>,EFFECT_FORCE>,
//      TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
//     LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
//     LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Black,RotateColorsX<Variation,Rgb<180,180,0>>,3000>>
//   >>(),
// // LED Strips
//   StylePtr<Layers<
//     Stripes<1000,-2000,RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<64,64,0>>,Black>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<64,64,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<180,180,0>>,TrFade<800>>,EFFECT_FORCE>,
//      TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
//     LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
//     LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Rgb<180,180,0>>,10,30,Black,100,3000,1>>
//   >>(),
// // Arc Reactor
//   StylePtr<Layers<Black,
//     Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<64,64,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<180,180,0>>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
//     InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
//   >>(),
// // Speaker 3mm White LED Data NA Power 6
//   StylePtr<Layers<
//     Blinking<Black,White,1500,500>,
//     InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
//   >>(),
// // Motor Data NA Power 5
//   StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
//   >(),
// "yellow"},



// { "RED;common", "tracks/Daddy.wav",
// // Main Blade
//   StylePtr<Layers<
//     // Base Red
//     Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
//     // Force Red
//     TransitionEffectL<TrConcat<TrFade<200>,Rgb<255,50,50>,TrFade<400>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<255,50,50>>,TrFade<800>>,EFFECT_FORCE>,
//     // Force Choke / lightning
//     TransitionEffectL<TrConcat<TrSmoothFade<1000>,Strobe<Black,Rgb<80,0,0>,30,30>,TrFade<1500>,StyleFire<Red,Strobe<Black,White,30,30>,0,3,FireConfig<300,2000,5>>,TrFade<400>>,EFFECT_FORCE>,
//   // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//         AlphaL<Black,Int<16384>>,
//         AlphaL<Black,Int<0>>>,
//   // Clash 2 - for red blades
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//   // Stab - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//   // Blast v1
//     TransitionEffectL<TrConcat<
//         // Impact Flash - BC always
//         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//         // Waves
//         BlastL<Rgb<100,200,255>,850,250,351>,
//         // Impact point afterimage
//         //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         // Impact point
//         //BlastL<Rgb<100,200,255>,500,350,100000>,
//         BlastL<Rgb<100,200,255>,300,350,100000>,
//   // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//         //Random Strobe Flash no dimming
//         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//         //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         // Bottom Layer Bump - random width
//         AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
//         // Top Layer Bump - fixed width
//         AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                              Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//         // Begin Lockup Transition
//         TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,   Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//         // End Lockup Transition
//         TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                  Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//   // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
//     LockupTrL<Layers<
//         //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
//         AlphaL<Black,Int<16000>>,
//         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//         // Begin Lightning Transition
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//         // End Lightning Transition    
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//         AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//         // Melt Shape
//         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//         // Melt Begin and End transitions
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
//     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
//     InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // Crystal Top
//   StylePtr<Layers<
//     // Crystal Red
//     Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
//     // Force Red
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
//     LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
//     LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
//   >>(),
// // Crystal Bottom
//   StylePtr<Layers<
//     // Crystal Red
//     Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
//     // Force Red
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
//     LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
//     LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<Black,ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,2000>,Black>>
//   >>(),
// // LED Strips
//   StylePtr<Layers<
//     Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
//      TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
//     LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
//     LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Rgb<180,180,0>>,10,30,Black,100,3000,1>>
//   >>(),
// // Arc Reactor
//   StylePtr<Layers<Black,
//     Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
//     LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
//     InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
//   >>(),
// // Speaker 3mm White LED Data NA Power 6
//   StylePtr<Layers<
//     Blinking<Black,White,1500,500>,
//     InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
//   >>(),
// // Motor Data NA Power 5
//   StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
//   >(),
// "red"},



{ "Fire;common", "tracks/Jupiter.wav",
  /* copyright Fett263 ResponsiveFlame (Primary Blade) OS6 Style
https://fett263.com/fett263-proffieOS6-style-library.html#ResponsiveFlame
OS6.6 v3.04
Single Style
Base Style: Responsive Flame (Real Flame Gradient)


--Effects Included--
Ignition Effect: Standard Ignition
Retraction Effect: Standard Retraction
PostOff Effect: Emitter Cool Off (Emitter Size)
Lockup Effect: Intensity Lockup V1
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Intensity Melt
Blast Effect: Blast Wave (Random)
Clash Effect: Real Clash V1
*/
// Main Blade
  StylePtr<Layers<Mix<SmoothStep<Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<36000>,Scale<BladeAngle<>,Int<10924>,Int<54000>>>,Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<-1>,Scale<BladeAngle<>,Int<-10000>,Int<-1>>>>,Black,Remap<Scale<RampF,Int<0>,Scale<IsLessThan<BladeAngle<>,Int<15000>>,Int<32768>,Scale<BladeAngle<0,15000>,Int<60000>,Int<32768>>>>,Layers<Mix<BladeAngle<>,
    StaticFire<Gradient<RotateColorsX<Variation,Rgb<255,75,0>>,RotateColorsX<Variation,Rgb<255,50,0>>,RotateColorsX<Int<400>,Red>,Red>,Mix<Int<16384>,Black,Red>,0,2,0,1800,10>,StaticFire<Gradient<RotateColorsX<Variation,Rgb<255,75,0>>,RotateColorsX<Int<1200>,Red>,RotateColorsX<Int<600>,Red>,Red>,Mix<Int<16384>,Black,Red>,0,4,0,2200,2>>>>>,
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
  InOutTrL<TrConcat<TrWipe<100>,White,TrWipe<30>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<255,75,0>>,RotateColorsX<Variation,Yellow>,500>,TrJoin<TrFade<300>,TrWipeIn<500>>>,TrWipeInX<RetractionTime<>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Crystal Top
  StylePtr<Layers<
    // Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
// Crystal Bottom
  StylePtr<Layers<
    // Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<Black,ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,2000>,Black>>
  >>(),
// LED Strips
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Rgb<180,180,0>>,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<Black,
    Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
  >(),
"fire"},



{ "First_Apprentice;common", "tracks/Maul_Of_The_Fates.wav",
// Main Blade
 StylePtr<Layers<
    AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
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
    InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Crystal Top
  StylePtr<Layers<
    // Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
// Crystal Bottom
  StylePtr<Layers<
    // Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<Black,ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,2000>,Black>>
  >>(),
// LED Strips
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Rgb<180,180,0>>,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<Black,
    Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
  >(),
"first\napprentice"},



{ "Hish-Qu-Ten_Blooded", "tracks/Predator_Theme.wav",
// Main Blade - Multicolor
  StylePtr<Layers<
    Layers<
      Red,
      AlphaL<Stripes<3100,0,Mix<Sin<Int<12>>,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Yellow>>,RotateColorsX<Variation,SpringGreen>,RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,DarkOrange>>,SmoothStep<Scale<BladeAngle<>,Int<16000>,Int<10000>>,Int<1600>>>,
      AlphaL<Stripes<3100,0,Mix<Sin<Int<12>>,RotateColorsX<Variation,SpringGreen>,RotateColorsX<Variation,Yellow>>,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,DodgerBlue>>,SmoothStep<Scale<BladeAngle<>,Int<22768>,Int<16768>>,Int<-1600>>>,
      AlphaL<Rgb16<52226,0,7>,Bump<Scale<BladeAngle<>,Int<22768>,Int<10000>>,Int<41000>>>>,
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
    InOutTrL<TrJoinR<TrWipe<100>,TrWipeIn<100>>,TrJoin<TrWipeX<WavLen<EFFECT_RETRACTION>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>>
    >>(),
// Crystal Top
  StylePtr<Layers<
    // Crystal Multicolor
    Stripes<3100,500,Mix<Sin<Int<12>>,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Yellow>>,RotateColorsX<Variation,SpringGreen>,RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,DarkOrange>>,
    // Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
// Crystal Bottom
  StylePtr<Layers<
    // Crystal Multicolor
  Stripes<3100,-500,Mix<Sin<Int<12>>,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Yellow>>,RotateColorsX<Variation,SpringGreen>,RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,DarkOrange>>,
    // Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<Black,ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,2000>,Black>>
  >>(),
// LED Strips
  StylePtr<Layers<
    Stripes<3100,500,Mix<Sin<Int<12>>,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Yellow>>,RotateColorsX<Variation,SpringGreen>,RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,DarkOrange>>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Rgb<180,180,0>>,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<Black,
    Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
  >(),
"hish-qu-ten\nblooded"},



{ "Marek_Unleashed;common", "tracks/TFU_Theme.wav",
// Main Blade - Red smoke blade
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<120,0,0>>,Black>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<5,0,0>>,3000>>,
    AlphaL<StyleFire<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<2,0,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
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
    InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Crystal Top
  StylePtr<Layers<
    // Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
// Crystal Bottom
  StylePtr<Layers<
    // Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<Black,ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,2000>,Black>>
  >>(),
// LED Strips
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Rgb<180,180,0>>,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<Black,
    Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
  >(),
"first\napprentice"},
 

{ "Dark_Jedi;common", "tracks/Sith_Tribute.wav",
// Main Blade
  StylePtr<Layers<
    Mix<SwingSpeed<400>,BrownNoiseFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,100,0>>,500>,Mix<SwingSpeed<600>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<150,255,150>>>>,
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
        // OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
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
    // Crystal Blue
    Stripes<1000,-2000,BrownNoiseFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,100,0>>,500>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<RotateColorsX<Variation,Green>,Black,3000>>
  >>(),
// Crystal Bot
  StylePtr<Layers<
    // Crystal Blue
    Stripes<1000,-2000,BrownNoiseFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,100,0>>,500>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Black,RotateColorsX<Variation,Green>,3000>>
  >>(),
// LED Strips
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Green>,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<Black,
    Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
  >(),
"dark\njedi"},



{ "Vader_Strikes_Back", "tracks/March.wav",
// Main Blade
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<190,0,0>>>,
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
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Pulsing<Black,Red,2500>>
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
  StylePtr<Layers<Black,
    Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
  >(),
"vader\nstrikes back"},



{ "Sith_Chant", "tracks/Music_From_The_Dark_Side",
// Main Blade
  StylePtr<Layers<
    StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
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
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,150,150>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
    InOutTrL<TrWipe<400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Crystal Top
  StylePtr<Layers<
    // Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
// Crystal Bottom
  StylePtr<Layers<
    // Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<Black,ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,2000>,Black>>
  >>(),
// LED Strips
  StylePtr<Layers<
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrInstant>,ColorCycle<RotateColorsX<Variation,Rgb<180,180,0>>,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<Black,
    Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<InOutHelper<Rgb<128,128,128>,300,800>
  >(),
"sith\nchant"},

};

//---------------------------------------------------------------------------------------------------------------------------------

Preset crystal_out[] = {

{ "WHITE;common", "tracks/Tron.wav",
// Main Blade - Blade is plain without crystal inserted...?
  StylePtr<Layers<
    HumpFlicker<White,SteelBlue,200>,
  // Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
    AlphaL<Black,Int<16384>>,
    AlphaL<Black,Int<0>>>,
  // Clash
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
  // Stab - OrangeRed stripes
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
  // Blast - for white blades
    TransitionEffectL<TrConcat<
    // Impact Flash - BC always
    TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
    // Waves
    BlastL<EffectSequence<EFFECT_BLAST,Red,Green,Blue,Black>,850,250,351>,
    // Impact point afterimage
    AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Red,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
    // Impact point
    BlastL<Black,300,350,100000>,
  // Lockup - BC custom range mid-blade
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
      //Random Strobe Flash no dimming
      AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
      //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
      // Bottom Layer Bump - random width
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
      // Top Layer Bump - fixed width
      AlphaL<BrownNoiseFlicker<Yellow,Black,50>,                                                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
      // Begin Lockup Transition
      TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>, Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
      // End Lockup Transition
      TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                             Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
    // Non-Responsive Drag
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
  // Lightning Block Non-Responsive    
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
  // Melt    
    LockupTrL<
    AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
    // Melt Shape
    SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
    //Melt Begin and End transitions
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTip<White,400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Crystal Top
  StylePtr<Black>(),
// Crystal Bottom
  StylePtr<Black>(),
// Led Strips
  StylePtr<Layers<
    Stripes<1000,-2000,HumpFlicker<White,SteelBlue,200>,Black>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Strobe<BrownNoiseFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Strobe<BrownNoiseFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>>,TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrInstant>,ColorCycle<White,10,30,Black,100,3000,1>>
  >>(),
// Arc Reactor
  StylePtr<Layers<Black,
    Pulsing<AlphaL<BrownNoiseFlicker<White,SteelBlue,10>,Int<16000>>,BrownNoiseFlicker<White,SteelBlue,200>,1500>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrFade<500>>,EFFECT_DRAG_END>,
    InOutTrL<TrConcat<TrInstant,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,TrSmoothFade<500>>,Pulsing<Rgb<70,70,70>,Rgb<20,20,20>,2000>>
  >>(),
// Speaker 3mm White LED Data NA Power 6
  StylePtr<Layers<
    Blinking<Black,White,1500,500>,
    InOutTrL<TrInstant,TrInstant,Sequence<White,Black,200,30,0b0,0b10101010101000>>
  >>(),
// Motor Data NA Power 5
  StylePtr<Black>(),
"root\ncore"}

};


BladeConfig blades[] = {
 { 700, // clean ID resistor value as per Serial Monitor (blue)
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
 CONFIGARRAY(crystal), "01_clean_save", }, 


 {830, // cracked ID resistor value as per Serial Monitor (red)
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
 CONFIGARRAY(crystal), "02_cracked_save", }, 



 { NO_BLADE,
 // Main Blade 122 LEDs Data 3 Power 2&3 (orange)
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