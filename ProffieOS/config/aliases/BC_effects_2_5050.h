// Accent / Pommel / PCB effects

using BC_effects_2 =
Layers<

  TransitionEffectL<TrConcat<TrInstant,Blinking<Rgb<100,200,255>,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
  TransitionEffectL<TrConcat<TrInstant,Blinking<Rgb<100,200,255>,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<Blinking<Rgb<100,200,255>,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<Rgb<100,200,255>,Strobe<BrownNoiseFlicker<Rgb<100,200,255>,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<Rgb<100,200,255>,Strobe<BrownNoiseFlicker<Rgb<100,200,255>,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<Rgb<100,200,255>,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,Rgb<100,200,255>>,TrConcat<TrInstant,Rgb<100,200,255>,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>
     >;
