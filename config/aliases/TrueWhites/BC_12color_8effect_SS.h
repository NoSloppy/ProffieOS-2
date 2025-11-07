// BC_12color_8effect_SS = alias for base blade color.
// 96 possible blade combos in one style. Uses EFFECT_USER1.
// SS version has Bright Color Enhanced Swing Speed swing.

using BC_12color_8effect_SS =  
Layers<
EffectSequence<EFFECT_USER1,

// Fett263 Unstable
Layers<
StaticFire<
	BrownNoiseFlicker<
		ColorChange<TrFade<300>,    Red,        DarkOrange,  Rgb<180,130,0>,GreenYellow, Green,      Aquamarine,  Cyan,        DeepSkyBlue,Blue,       Rgb<125,30,255>,Magenta,     White>,
		RandomPerLEDFlicker<
			ColorChange<TrFade<300>,Rgb<25,0,0>,OrangeRed,   Rgb<15,15,0>,  Rgb<10,15,0>,Rgb<0,25,0>,Rgb<0,15,10>,Rgb<0,0,25>, Rgb<0,0,25>,Rgb<0,0,25>,Rgb<15,0,10>,   Rgb<10,0,15>,Rgb<15,15,30>>,
			ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,  Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,   Rgb<30,0,30>,Rgb<60,60,100>>>,200>,
	ColorChange<TrFade<300>,        Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,  Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,   Rgb<40,0,40>,Rgb<80,80,150>>,0,6,10,1000,2>,
AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,
	Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>
>,

// HumpFlicker
Layers<
HumpFlicker<
	ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,        Rgb<95,0,225>,Magenta,     White>,
	ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,  Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>,20>,
AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,
	Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>
>,

// Pulsing
Layers<
Pulsing<
              ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
AudioFlickerL<ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,1000>,
AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,
	Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>
>,

// Simple BrownNoiseFlicker
Layers<
BrownNoiseFlicker<
	ColorChange<TrFade<300>,Red,        DarkOrange,  Rgb<180,130,0>,GreenYellow, Green,      Aquamarine,  Cyan,        DeepSkyBlue,Blue,       Rgb<95,0,225>,Magenta,       White>,
	ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,  Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>, Rgb<30,0,30>,  Rgb<60,60,100>>,200>,
AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,
	Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>
>,

// BrownNoiseFlicker Unstable
Layers<
BrownNoiseFlicker<
	RandomPerLEDFlicker<
		ColorChange<TrFade<300>,Red,        DarkOrange,  Rgb<180,130,0>,GreenYellow, Green,      Aquamarine,  Cyan,        DeepSkyBlue,Blue,       Rgb<95,0,225>,Magenta,     White>,
		ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,  Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>, Rgb<30,0,30>,Rgb<60,60,100>>>,
	ColorChange<TrFade<300>,    Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,  Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>, Rgb<40,0,40>,Rgb<80,80,150>>,	200>,
AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,
	Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>
>,

// Normal Fireblade
Layers<
StaticFire<
	ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
	ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,
AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,
	Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>
>,

// Fast Fireblade
Layers<
StaticFire<
	ColorChange<TrFade<300>,Red,        DarkOrange,  Rgb<180,130,0>,GreenYellow, Green,      Aquamarine,  Cyan,        DeepSkyBlue,Blue,       Rgb<95,0,225>,Magenta,     White>,
	ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,  Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>, Rgb<30,0,30>,Rgb<60,60,100>>,0,4>,
AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,
	Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>
>,


// Rain Blade
Layers<
Sparkle<
	AudioFlicker<
		ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
		ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,
	White>,
AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,
	Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>
>,

// AudioFlicker
Layers<
AudioFlicker<
ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,
ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,
AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,
	Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>
>

>  // EffectSequence
>; // Layers 