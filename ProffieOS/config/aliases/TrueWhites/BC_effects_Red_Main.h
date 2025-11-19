// Staff Main Blade effects package for Red (or dark) blades

using BC_effects_Red_Main =
Layers<

AlphaL<Layers< // Only show this Alpha Layer group of effects on staff blade that's pointing up.
  // Clash - Clash Impact sensitive, 
    // TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,
    // AlphaL<TransitionEffect<
    //   TransitionEffect<
    //     Strobe<Black,Yellow,20,20>,
    //     BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,
    //   Rgb<100,200,255>,TrInstant,TrDelayX<Percentage<WavLen<EFFECT_CLASH>,25>>,EFFECT_CLASH>,
    // Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Scale<ClashImpactF<>,Int<4000>,Int<32768>>>>,TrFadeX<Percentage<WavLen<EFFECT_CLASH>,65>>>,EFFECT_CLASH>,
    // Just use this for red too
//Linear TrConcat version, now clash impact sized
        TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFadeX<Percentage<WavLen<>,35>>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,
    Scale<ClashImpactF<200,5000>,Int<1000>,Int<32768>>>>,TrFadeX<Percentage<WavLen<>,45>>>,EFFECT_CLASH>,
  // Blast
    TransitionEffectL<TrConcat<
      // Impact Flash
      TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
      // Waves
      BlastL<Rgb<100,200,255>,850,250,351>,
      // Impact point afterimage
      AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
      // Impact point
      BlastL<Rgb<100,200,255>,300,350,100000>,
  // Lockup - BC custom range mid-blade
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
      //Random Strobe Flash no dimming
      AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
      // Bottom Layer Bump - random width
      AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                 Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
      // Top Layer Bump - fixed width
      AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                           Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
      // Begin Lockup Transition
      TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
      // End Lockup Transition
      TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>>,
IsGreaterThan<BladeAngle<>,Int<16384>>>,

AlphaL< // Only show this Alpha Layer group of effects on staff blade that's pointing down.
  // Non-Responsive Drag - trickle fadeout
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
IsLessThan<BladeAngle<>,Int<16384>>>,

  // Force Choke / lightning - WavLen duration sync.
    TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<80,0,0>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Red,Strobe<Black,Cyan,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>,
  // Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<0>>>,
  // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
    // LockupTrL<Layers<
    //   //Random Strobe Flash and ~50% base blade dimming to make LB pop
    //   AlphaL<Black,Int<16000>>,
    //   AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
    //   AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
    //   Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
    //   Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
    //   Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,

// Bluer version strobe and slower bumps 2024
    LockupTrL<Layers<
      // Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
      AlphaL<Black,Int<16000>>,
      AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<4>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
      AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,
      LayerFunctions<
      Bump<Scale<SlowNoise<Int<1000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
      Bump<Scale<SlowNoise<Int<1500>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
      Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,

      // Begin Lightning Transition
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
      // End Lightning Transition    
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,

  // Stab - OrangeRed stripes. WavLen duration sync.
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,30>>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFadeX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeX<Percentage<WavLen<EFFECT_STAB>,70>>>>,EFFECT_STAB>,
// Melt on Main blade only
  // Melt
    LockupTrL<
      // Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
      AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
      // Melt Shape
      SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
      // Melt Begin and End transitions
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>
>;


