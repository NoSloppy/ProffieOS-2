// BC_12color_8effect = alias for base blade color.
// 96 possible blade combos in one style. Uses BC_SWAP.
// No Swing color. Use SS version instead for Bright Color Enhanced Swing Speed Color

using BC_12color_8effect =  
Layers<
EffectSequence<EFFECT_USER1,

// Fett263 Unstable
StaticFire<
	BrownNoiseFlicker<
		ColorChange<TrFade<300>,    Red,        DarkOrange,  Rgb<180,130,0>,GreenYellow, Green,      Aquamarine,  Cyan,        DeepSkyBlue,Blue,       Rgb<125,30,255>,Magenta,     White>,
		RandomPerLEDFlicker<
			ColorChange<TrFade<300>,Rgb<25,0,0>,OrangeRed,   Rgb<15,15,0>,  Rgb<10,15,0>,Rgb<0,25,0>,Rgb<0,15,10>,Rgb<0,0,25>, Rgb<0,0,25>,Rgb<0,0,25>,Rgb<15,0,10>,   Rgb<10,0,15>,Rgb<15,15,30>>,
			ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,  Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,   Rgb<30,0,30>,Rgb<60,60,100>>>,200>,
	ColorChange<TrFade<300>,        Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,  Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,   Rgb<40,0,40>,Rgb<80,80,150>>,0,6,10,1000,2>,

// HumpFlicker
HumpFlicker<
	ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,        Rgb<95,0,225>,Magenta,     White>,
	ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,  Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>,20>,

// Pulsing
Pulsing<
              ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
AudioFlickerL<ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,1000>,

// Simple BrownNoiseFlicker
BrownNoiseFlicker<
	ColorChange<TrFade<300>,Red,        DarkOrange,  Rgb<180,130,0>,GreenYellow, Green,      Aquamarine,  Cyan,        DeepSkyBlue,Blue,       Rgb<95,0,225>,Magenta,       White>,
	ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,  Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>, Rgb<30,0,30>,  Rgb<60,60,100>>,200>,

// BrownNoiseFlicker Unstable
BrownNoiseFlicker<
	RandomPerLEDFlicker<
		ColorChange<TrFade<300>,Red,        DarkOrange,  Rgb<180,130,0>,GreenYellow, Green,      Aquamarine,  Cyan,        DeepSkyBlue,Blue,       Rgb<95,0,225>,Magenta,     White>,
		ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,  Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>, Rgb<30,0,30>,Rgb<60,60,100>>>,
	ColorChange<TrFade<300>,    Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,  Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>, Rgb<40,0,40>,Rgb<80,80,150>>,	200>,

// Normal Fireblade
StaticFire<
	ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
	ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,

// Fast Fireblade
StaticFire<
	ColorChange<TrFade<300>,Red,        DarkOrange,  Rgb<180,130,0>,GreenYellow, Green,      Aquamarine,  Cyan,        DeepSkyBlue,Blue,       Rgb<95,0,225>,Magenta,     White>,
	ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,  Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>, Rgb<30,0,30>,Rgb<60,60,100>>,0,4>,

// Rain Blade
Sparkle<
	AudioFlicker<
		ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
		ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,
	White>,

// AudioFlicker
AudioFlicker<
ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>

> // EffectSequence
>;