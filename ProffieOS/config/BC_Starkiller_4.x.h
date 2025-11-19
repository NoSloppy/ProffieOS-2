// BC_Starkiller_4.x.h

// Starkiller hilt

//   5050s pixels - white is too RED. Use Rgb<100,200,255>

#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 2
#define VOLUME 100
const unsigned int maxLedsPerStrip = 144; 
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define SHARED_POWER_PINS
//#define ENABLE_SERIAL //Bluetooth
//#define ENABLE_SSD1306 //OLED
#define SAVE_STATE
#define IDLE_OFF_TIME 60*5*1000
#define SA22C_NO_LOCKUP_HOLD
    #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
    #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
    #define BLADE_DETECT_PIN blade3Pin
#define DISABLE_DIAGNOSTIC_COMMANDS
#endif


#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"

#endif

#ifdef CONFIG_PRESETS

//StylePtr<PulsingX<Mix<BatteryLevel,Red,Yellow,Green>,Black,BatteryLevel>>()
using BatteryLevelStyle =Mix<Sin<Int<20>,Int<8192>,Int<32768>>,Black,Mix<BatteryLevel,Red,Red,Orange,Orange,Yellow,Yellow,Green,Green,Green,Blue,Blue,Blue>>;
//using SoundLevelStyle =Mix<Sin<Int<20>,Int<8192>,Int<32768>>,Black,Mix<NoisySoundLevel,Red,Red,Orange,Orange,Yellow,Yellow,Green,Green,Green,Blue,Blue,Blue>>;
//Yellow/White Stab tip to red and red/blk noise @ hilt
//using STAB_COLOR_RWY = Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>;

//Main Blade
// NPXL
// Chamber Top
// Chamber Crystal
// Accents

//Preset bladeBC_A [] = {
Preset AllBlades [] = {

 { "CdeFlcrm;common", "tracks/RebelsTheme.wav",
//  Drag   =   BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>>
// Stab    =   RandomPerLEDFlicker<Red,White>
// Clash   =   AudioFlicker<GreenYellow,BrownNoiseFlicker<Red,Yellow,300>>
// Blast   =   TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,800>,
// LB      =   BrownNoiseFlicker<Strobe<Rgb<60,0,255>,White,15,10>,DeepSkyBlue,500>>
// Lockup  = Gradient<Strobe<Yellow,DarkOrange,25,40>,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,Strobe<Yellow,DarkOrange,30,30>>,
// Main Blade
// V1 HOLY COW WTF
//      StylePtr<InOutHelper<LocalizedClash<Lockup<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<Mix<SwingSpeed<500>,AudioFlicker<Rgb<110,150,255>,Rgb<80,90,130>>,Mix<SwingSpeed<500>,AudioFlicker<Rgb<110,150,255>,White>,White>>,StyleFire<Rgb<110,150,255>,SteelBlue,0,6,FireConfig<500,6000,5>,FireConfig<2000,0,0>>,TrInstant,TrSmoothFade<500>,EFFECT_IGNITION>,Mix<Bump<Int<32768>,Int<16000>>,Rgb<110,150,255>,RandomPerLEDFlicker<OrangeRed,White>>,TrConcat<TrWipeIn<300>,Mix<Bump<Int<32768>,Int<25000>>,AudioFlicker<LightCyan,BrownNoiseFlicker<AudioFlicker<Rgb<110,150,255>,Rgb<80,90,130>>,GhostWhite,500>>,RandomPerLEDFlicker<Orange,White>>,TrWipe<600>>,TrFade<600>,EFFECT_STAB>,Strobe<SteelBlue,White,15,30>,TrInstant,TrSmoothFade<200>,EFFECT_LOCKUP_BEGIN>,Strobe<DeepSkyBlue,White,15,30>,TrInstant,TrSmoothFade<200>,EFFECT_LOCKUP_END>,Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Rgb<110,150,255>,Strobe<Red,DarkOrange,15,50>>,RandomPerLEDFlicker<Orange,White>>,TrInstant,TrFade<200>,EFFECT_DRAG_BEGIN>,Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<BrownNoiseFlicker<Rgb<110,150,255>,Strobe<Black,White,15,70>,50>,Rgb<128,0,0>>,RandomPerLEDFlicker<Orange,White>>,TrInstant,TrFade<600>,EFFECT_DRAG_END>,Black,TrConcat<TrInstant,HumpFlicker<White,Yellow,40>,TrColorCycle<0>>,TrInstant,EFFECT_RETRACTION>,Pulsing<Gradient<LocalizedClash<Lockup<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<Mix<SwingSpeed<500>,AudioFlicker<Rgb<110,150,255>,Rgb<80,90,130>>,Mix<SwingSpeed<500>,AudioFlicker<Rgb<110,150,255>,White>,White>>,StyleFire<Rgb<110,150,255>,SteelBlue,0,6,FireConfig<500,6000,5>,FireConfig<2000,0,0>>,TrInstant,TrSmoothFade<500>,EFFECT_IGNITION>,Mix<Bump<Int<32768>,Int<16000>>,Rgb<110,150,255>,RandomPerLEDFlicker<OrangeRed,White>>,TrConcat<TrWipeIn<300>,Mix<Bump<Int<32768>,Int<25000>>,AudioFlicker<LightCyan,BrownNoiseFlicker<AudioFlicker<Rgb<110,150,255>,Rgb<80,90,130>>,GhostWhite,500>>,RandomPerLEDFlicker<Orange,White>>,TrWipe<600>>,TrFade<600>,EFFECT_STAB>,Strobe<SteelBlue,White,15,30>,TrInstant,TrSmoothFade<200>,EFFECT_LOCKUP_BEGIN>,Strobe<DeepSkyBlue,White,15,30>,TrInstant,TrSmoothFade<200>,EFFECT_LOCKUP_END>,Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Rgb<110,150,255>,Strobe<Red,DarkOrange,15,50>>,White>,TrInstant,TrFade<200>,EFFECT_DRAG_BEGIN>,Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<BrownNoiseFlicker<Rgb<110,150,255>,Strobe<Black,White,15,70>,50>,Rgb<128,0,0>>,White>,TrInstant,TrFade<600>,EFFECT_DRAG_END>,Black,TrConcat<TrInstant,HumpFlicker<White,Yellow,40>,TrColorCycle<0>>,TrInstant,EFFECT_RETRACTION>,Pulsing<Gradient<Strobe<Yellow,DarkOrange,15,50>,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>>,Gradient<BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,Strobe<Yellow,DarkOrange,50,30>>,1000>,RandomPerLEDFlicker<Red,White>,Bump<Int<16000>,Int<20000>>,Bump<Int<32768>,Int<10000>>>,AudioFlicker<GreenYellow,BrownNoiseFlicker<Red,Yellow,300>>,60>,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>>,Gradient<BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,Strobe<Yellow,Strobe<DarkOrange,Black,15,30>,50,30>>,1000>,RandomPerLEDFlicker<Red,White>,Bump<Int<16000>,Int<20000>>,Bump<Int<32768>,Int<10000>>>,AudioFlicker<GreenYellow,BrownNoiseFlicker<Red,Yellow,300>>,60>,250,450>>(),
    StylePtr<                       
        InOutSparkTip<
            Layers<
                LocalizedClash<
                    Blast<
                        TransitionEffect<
                            TransitionEffect<
                                TransitionEffect<
                                        Mix<SwingSpeed<500>,AudioFlicker<Rgb<110,150,255>,Rgb<80,90,130>>,Mix<SwingSpeed<500>,AudioFlicker<Rgb<110,150,255>,White>,White>>,
                                StyleFire<Rgb<110,150,255>,SteelBlue,0,6,FireConfig<500,6000,5>,FireConfig<2000,0,0>>,TrInstant,TrSmoothFade<500>,EFFECT_IGNITION>,
                            Mix<Bump<Int<32768>,Int<16000>>,Gradient<White,Blue,DodgerBlue,DeepSkyBlue,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Blue,White,15,20>,GreenYellow,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                        AudioFlicker<Rgb<110,150,255>,White>,TrSmoothFade<500>,TrWipeIn<180>,EFFECT_RETRACTION>,
                    TransitionEffect<Blue,DeepSkyBlue,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                AudioFlicker<GreenYellow,BrownNoiseFlicker<Red,Yellow,300>>,90,60>,
            ResponsiveLockupL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>>>,
            ResponsiveDragL<BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>>,
            ResponsiveMeltL<RandomPerLEDFlicker<Red,White>>,
            ResponsiveLightningBlockL<BrownNoiseFlicker<Strobe<Rgb<60,0,255>,White,15,1>,DeepSkyBlue,500>>>,    
        250,450,White>
    >(),
// NPXL
    //StylePtr<ColorCycle<TransitionLoop<Rgb<20,30,60>,TrConcat<TrFade<200>,AliceBlue,TrFade<200>>>,10,30,AudioFlicker<White,Blue>,25,500,1000>>(),
    StylePtr<TransitionLoop<Black,TrConcat<TrWipe<5000>,Rgb<50,75,200>,TrConcat<TrInstant,Black,TrFade<1000>>>>>(),
// Chamber Top
    StylePtr<InOutHelper<EasyBlade<Pulsing<Pulsing<Rgb<20,30,60>,Rgb<100,100,125>,400>,Black,1000>,Strobe<Black,White,15,1>,BrownNoiseFlicker<AliceBlue,SteelBlue,300>>,300,800,Pulsing<Pulsing<Rgb<20,30,60>,Rgb<100,100,125>,1500>,Black,3500>>>(),
// Chamber Crystal
    StylePtr<InOutHelper<EasyBlade<Sparkle<HumpFlicker<AliceBlue,Rgb<20,30,60>,5>,Black>,Strobe<Black,White,15,1>,BrownNoiseFlicker<AliceBlue,SteelBlue,300>>,300,800,Stripes<10000,100,Black,Black,Sparkle<White,Rgb<20,30,60>>,Rgb<20,30,60>,Black,Rgb<20,30,60>,Sparkle<Rgb<20,30,60>>>>>(),
// Accents
    StylePtr<InOutHelper<EasyBlade<Sparkle<HumpFlicker<AliceBlue,Rgb<20,30,60>,5>,Black>,Strobe<Black,White,15,1>,BrownNoiseFlicker<AliceBlue,SteelBlue,300>>,300,800,Stripes<10000,100,Black,Black,Sparkle<White,Rgb<20,30,60>>,Rgb<20,30,60>,Black,Rgb<20,30,60>,Sparkle<Rgb<20,30,60>>>>>(),
"code:\nfulcrum"},


 { "DarkAppr;common", "tracks/TFU1.wav", 
// Main Blade
//v5 pulsing old-school lockup      StylePtr<InOutSparkTip<Layers<TransitionEffect<TransitionEffect<SimpleClash<SimpleClash<TransitionEffect<TransitionEffect<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Red,Sparkle<Rgb<150,10,0>,Red,15,5000>>,Pulsing<Gradient<Red,BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,Yellow,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>>,Gradient<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,500>,Yellow,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>,Red>,2000>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>,Bump<Int<17000>,Int<20000>>>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,White,15,10>,75>,90,75>,TransitionEffect<Blue,White,TrWipe<50>,TrWipe<50>,EFFECT_BLAST>,300,250,800>,White,250>,AudioFlicker<Red,Rgb<100,10,0>>,TrConcat<TrFade<50>,Strobe<GreenYellow,Black,30,30>,TrFade<100>,StyleFire<Red,White,0,6,FireConfig<0,800,5>,FireConfig<3000,0,0>,FireConfig<0,800,0>>,TrFade<500>>,TrInstant,EFFECT_LOCKUP_END>,Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Red,Rgb<128,0,0>>,Yellow>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,Strobe<GreenYellow,Black,30,30>,90,EFFECT_LOCKUP_BEGIN>,Strobe<GreenYellow,Black,30,30>,50,EFFECT_DRAG_BEGIN>,Gradient<Gradient<White,Red,Red,Red,Red,Red>,Red,Red>,TrSmoothFade<500>,TrWipeIn<180>,EFFECT_RETRACTION>,Mix<Bump<Int<32768>,Int<16000>>,OrangeRed,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrConcat<TrWipeIn<300>,Mix<Bump<Int<32768>,Int<25000>>,AudioFlicker<OrangeRed,BrownNoiseFlicker<AudioFlicker<DarkOrange,Rgb<80,90,130>>,Rgb<255,20,20>,500>>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipe<600>>,TrFade<600>,EFFECT_STAB>,ResponsiveLightningBlockL<BrownNoiseFlicker<White,DeepSkyBlue,500>>>,300,450>>(),
    // StylePtr<   InOutSparkTip<  Layers<
    //                                 TransitionEffect<   TransitionEffect<   SimpleClash<    SimpleClash<    TransitionEffect<   TransitionEffect<   OnSpark<    Blast<  LocalizedClash<     Lockup< 
    //                                                                                                                                                                                                 AudioFlicker<Red,Sparkle<Rgb<150,10,0>,Red,15,5000>>,
    //                                                                                                                                                                                             Pulsing<
    //                                                                                                                                                                                                 Gradient<Red,BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>>,
    //                                                                                                                                                                                                 Gradient<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,500>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>,Red>,2000>,
    //                                                                                                                                                                                         BrownNoiseFlicker<BrownNoiseFlicker<White,DeepSkyBlue,50>,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>, 
    //                                                                                                                                                                                         Bump<Int<17000>,Int<20000>>,                    
    //                                                                                                                                                                                         SmoothStep<Int<28672>,Int<4097>>>,          
    //                                                                                                                                                                     BrownNoiseFlicker<BrownNoiseFlicker<White,DeepSkyBlue,50>,Strobe<Strobe<Red,White,15,20>,White,15,10>,75>>,
    //                                                                                                                                                             TransitionEffect<Blue,White,TrWipe<50>,TrWipe<50>,EFFECT_BLAST>,300,250,800>,
    //                                                                                                                                                 White,250>,
    //                                                                                                                             AudioFlicker<Red,Rgb<100,10,0>>,TrConcat<TrFade<50>,Strobe<GreenYellow,Black,30,30>,TrFade<100>,StyleFire<Red,White,0,6,FireConfig<0,800,5>,FireConfig<3000,0,0>,FireConfig<0,800,0>>,TrFade<500>>,TrInstant,EFFECT_LOCKUP_END>,
    //                                                                                                         Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Red,Rgb<128,0,0>>,BrownNoiseFlicker<DeepSkyBlue,White,50>>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,
    //                                                                                         Strobe<GreenYellow,Black,30,30>,90,EFFECT_LOCKUP_BEGIN>,
    //                                                                         Strobe<GreenYellow,Black,30,30>,50,EFFECT_DRAG_BEGIN>,
    //                                                     Gradient<Gradient<White,Red,Red,Red,Red,Red>,Red,Red>,TrSmoothFade<500>,TrWipeIn<180>,EFFECT_RETRACTION>,
    //                                 Mix<Bump<Int<32768>,Int<16000>>,OrangeRed,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrConcat<TrWipeIn<300>,Mix<Bump<Int<32768>,Int<25000>>,AudioFlicker<OrangeRed,BrownNoiseFlicker<AudioFlicker<DarkOrange,Rgb<80,90,130>>,Rgb<255,20,20>,500>>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipe<600>>,TrFade<600>,EFFECT_STAB>,
    //                             ResponsiveLightningBlockL<BrownNoiseFlicker<White,DeepSkyBlue,500>>>,
    //             300,450>
    // >(),
    StylePtr<   
        InOutSparkTip<  
            Layers< 
                OnSpark<    
                    Blast<  
                        LocalizedClash< 
                            TransitionEffect<   
                                TransitionEffect<     
                                    AudioFlicker<Red,Sparkle<Rgb<150,10,0>,Red,15,5000>>,
                                Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                            Gradient<Gradient<White,Red,Red,Red,Red,Red>,Red,Red>,TrSmoothFade<500>,TrWipeIn<180>,EFFECT_RETRACTION>,    
                        BrownNoiseFlicker<BrownNoiseFlicker<White,DeepSkyBlue,50>,Strobe<Strobe<Red,White,15,20>,White,15,10>,75>,90,60>, ///BC REUPLOAD THESE CLASH VALUES
                    TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                White,250>,                                     
            ResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>>,
            ResponsiveDragL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>>,
            ResponsiveMeltL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>>,
            ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>,
        300,450,White>
    >(),
// NPXL
    StylePtr<ColorCycle<Cylon<Red,50,20,Red,95,20,2000>,75,200,AudioFlicker<BrownNoiseFlicker<Red,Rgb16<28268,1053,3>,50>,OrangeRed>,20,6000,2000>>(),
// Chamber Top
    StylePtr<InOutHelper<EasyBlade<OnSpark<Pulsing<Black,Red,500>,White,200>,White>,1,1,Pulsing<Black,Red,3000>>>(),
// Chamber Crystal
    StylePtr<InOutHelper<EasyBlade<OnSpark<StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,White,200>,White>,1,1,Pulsing<Red,Sparkle<Black,White,7>,3000>>>(),
// Accents
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Mix<Bump<Sin<Int<120>,Int<10>,Int<32000>>,Int<16000>>,Black,Red>,White>,AudioFlicker<Rgb<255,100,100>,White>,AudioFlicker<Rgb<100,100,100>,White>,Int<32768>,SmoothStep<Int<16000>,Int<32768>>>,White,50,EFFECT_CLASH,SmoothStep<Int<16384>,Int<32768>>>,1,1,Mix<Bump<Sin<Int<40>,Int<10>,Int<32000>>,Int<10000>>,Black,Red>>>(),
"dark\napprentice"},

// { "KrossGrd;common", "tracks/Kylo1.wav",
//    // SHOWCASE - Unstable Blade Style with "Responsive Blade" (Fast Color) with Full Transitions with ColorWheel
//    StylePtr<InOutHelper<Blast<LocalizedClash<Lockup<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<Mix<SwingSpeed<300>,StyleFire<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,Rgb<80,0,0>,0,6,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,Mix<SwingSpeed<500>,BrownNoiseFlicker<OrangeRed,Rgb<80,40,40>,300>,StyleFire<BrownNoiseFlicker<OrangeRed,RandomPerLEDFlicker<Rgb<25,5,5>,Rgb<60,20,20>>,200>,Rgb<80,40,40>,0,6,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>>>,StyleFire<White,Red,0,6>,TrInstant,TrSmoothFade<1600>,EFFECT_IGNITION>,Mix<Bump<Int<32768>,Int<16000>>,StyleFire<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,Rgb<80,0,0>,0,6,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,RandomPerLEDFlicker<OrangeRed,White>>,TrConcat<TrWipeIn<600>,Mix<Bump<Int<32768>,Int<16000>>,StyleFire<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,Rgb<80,0,0>,0,6,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,RandomPerLEDFlicker<Orange,White>>,TrWipe<600>>,TrInstant,EFFECT_STAB>,White,TrInstant,TrSmoothFade<200>,EFFECT_LOCKUP_BEGIN>,StyleFire<Red,White,0,6>,TrInstant,TrSmoothFade<500>,EFFECT_LOCKUP_END>,Mix<Bump<Int<32768>,Int<10000>>,StyleFire<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,Rgb<80,0,0>,0,6,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,White>,TrInstant,TrFade<200>,EFFECT_DRAG_BEGIN>,Mix<Bump<Int<32768>,Int<10000>>,StyleFire<BrownNoiseFlicker<Red,RandomPerLEDFlicker<Rgb<25,0,0>,Rgb<60,0,0>>,200>,Rgb<80,0,0>,0,6,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,White>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,Black,TrConcat<TrInstant,Stripes<1000,6000,Rgb<128,0,0>,Rgb<80,80,80>,Rgb<100,0,0>,Red>,TrWipeIn<500>>,TrInstant,EFFECT_RETRACTION>,Pulsing<Gradient<Red,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>>,Gradient<BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,Red>,3500>,RandomPerLEDFlicker<Red,White>,Bump<Int<16000>,Int<20000>>,Bump<Int<32768>,Int<10000>>>>,White>,300,500>>(),
//     //   StylePtr<InOutSparkTip<OnSpark<Blast<LocalizedClash<Lockup<StyleFire<Red,Rgb<255,100,50>,0,4,FireConfig<10,3000,5>,FireConfig<0,0,10000>,FireConfig<200,1000,50>,FireConfig<200,3500,0>>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,White,15,10>,50>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,White,15,10>,50>,Bump<Int<16384>,Int<32768>>>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,White,15,10>,75>,150,90>,TransitionEffect<Blue,White,TrWipe<50>,TrWipe<50>,EFFECT_BLAST>,300,200,800>,White,200>,300,350>>(),
//    //    StylePtr<ColorCycle<Cylon<Red,20,20,Red,95,20,2000>,95,200,AudioFlicker<BrownNoiseFlicker<Red,Rgb16<28268,1053,3>,50>,OrangeRed>,20,6000,2000>>(),
//    //    StylePtr<InOutHelper<Sparkle<Red>, 1000, 800,Stripes<5,50,Red,Black,TransitionLoop<White,TrConcat<TrFade<200>,Red,TrFade<1000>>>>>>(),
//    //    StylePtr<InOutHelper<Pulsing<Yellow,Red,800>,1000,800,Pulsing<Green,Black,4000>>>(),
//    //    StylePtr<StyleFire<Red,OrangeRed,0,2,FireConfig<20,2000,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<300,3000,0>>>(),
//          StylePtr<ColorCycle<TransitionLoop<Black,TrConcat<TrInstant,Red,TrFade<1100>>>,5,11,StyleFire<Red,Orange,0,2,FireConfig<100,3000,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,25,150,750>>(),
//     // Chamber Top // Chamber Crystal
//          StylePtr<InOutHelper<Pulsing<Sparkle<Black,Yellow,10>,RandomFlicker<Red,Sparkle<Rgb<100,0,0>,Yellow,40>>,100>,1,1,     Pulsing<Sparkle<Black,Yellow,10>,RandomFlicker<Red,Sparkle<Rgb<100,0,0>,Yellow,10>>,4500>>>(),
//     // Crystal - unstablish
//          StylePtr<InOutHelper<Pulsing<Pulsing<BrownNoiseFlicker<Rgb<128,10,0>,Black,300>,Sparkle<BrownNoiseFlicker<Rgb<128,10,0>,Red,500>,White,40>,2600>,Sparkle<Red,Yellow,40,2500>,200>,1,1,Pulsing<RandomFlicker<Rgb<128,10,0>,Red>,Sparkle<Rgb<60,5,9>,White,20,10240>,2600>>>(),
//     // Accents
//          StylePtr<TransitionEffect<InOutHelper<SimpleClash<OnSpark<ColorSequence<50,Gradient<ColorSequence<400,Red,OrangeRed,DarkOrange,DarkOrange,OrangeRed,Red>,Black,Black,Black,Black,Black>,Gradient<Black,ColorSequence<400,Red,OrangeRed,DarkOrange,DarkOrange,OrangeRed,Red>,Black,Black,Black,Black>,Gradient<Black,Black,ColorSequence<400,Red,OrangeRed,DarkOrange,DarkOrange,OrangeRed,Red>,Black,Black,Black>,Gradient<Black,Black,Black,ColorSequence<400,Red,OrangeRed,DarkOrange,DarkOrange,OrangeRed,Red>,Black,Black>,Gradient<Black,Black,Black,Black,ColorSequence<400,Red,OrangeRed,DarkOrange,DarkOrange,OrangeRed,Red>,Black>,Gradient<Black,Black,Black,Black,Black,ColorSequence<400,Red,OrangeRed,DarkOrange,DarkOrange,OrangeRed,Red>>>,Yellow,250>,Yellow,250,EFFECT_RETRACTION>,1,1,ColorSequence<250,Gradient<ColorSequence<400,Red,OrangeRed,DarkOrange,DarkOrange,OrangeRed,Red>,Black,Black,Black,Black,Black>,Gradient<Black,ColorSequence<400,Red,OrangeRed,DarkOrange,DarkOrange,OrangeRed,Red>,Black,Black,Black,Black>,Gradient<Black,Black,ColorSequence<400,Red,OrangeRed,DarkOrange,DarkOrange,OrangeRed,Red>,Black,Black,Black>,Gradient<Black,Black,Black,ColorSequence<400,Red,OrangeRed,DarkOrange,DarkOrange,OrangeRed,Red>,Black,Black>,Gradient<Black,Black,Black,Black,ColorSequence<400,Red,OrangeRed,DarkOrange,DarkOrange,OrangeRed,Red>,Black>,Gradient<Black,Black,Black,Black,Black,ColorSequence<400,Red,OrangeRed,DarkOrange,DarkOrange,OrangeRed,Red>>>>,Yellow,TrFade<10>,TrFade<300>,EFFECT_RETRACTION>>(),
// "kylo"},


// { "Nextor;common", "tracks/mars.wav", //Fernando offer 4
//     //    ColorChange Transition (TrWipe) with Full Transition Effects and Emitter Cool Down
//     //    YELLOW DEFAULT
//     StylePtr<InOutHelper<Blast<LocalizedClash<Lockup<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<AudioFlicker<Yellow,Rgb<60,60,0>>,StyleFire<White,Yellow,0,6>,TrInstant,TrSmoothFade<1600>,EFFECT_IGNITION>,Mix<Bump<Int<32768>,Int<16000>>,AudioFlicker<Yellow,Rgb<60,60,0>>,RandomPerLEDFlicker<Red,White>>,TrConcat<TrWipeIn<600>,Mix<Bump<Int<32768>,Int<16000>>,AudioFlicker<Yellow,Rgb<60,60,0>>,RandomPerLEDFlicker<Orange,White>>,TrWipe<600>>,TrInstant,EFFECT_STAB>,White,TrInstant,TrSmoothFade<200>,EFFECT_LOCKUP_BEGIN>,StyleFire<Yellow,White,0,6>,TrInstant,TrSmoothFade<500>,EFFECT_LOCKUP_END>,Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Yellow,Rgb<60,60,0>>,White>,TrInstant,TrFade<200>,EFFECT_DRAG_BEGIN>,Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Yellow,Rgb<60,60,0>>,White>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,Black,TrConcat<TrInstant,HumpFlicker<White,Yellow,40>,TrColorCycle<600>>,TrInstant,EFFECT_RETRACTION>,Pulsing<Gradient<Yellow,BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>>,Gradient<BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>,Yellow>,3500>,RandomPerLEDFlicker<Yellow,White>,Bump<Int<16000>,Int<20000>>,Bump<Int<32768>,Int<10000>>>,White>,White>,800,500,TransitionEffect<Black,Black,TrConcat<TrSmoothFade<1000>,Mix<Bump<Int<0>,Int<3000>>,Black,White>,TrSmoothFade<4000>,Mix<Bump<Int<0>,Int<3000>>,Black,Orange>,TrSmoothFade<3000>,Mix<Bump<Int<0>,Int<3000>>,Black,OrangeRed>,TrSmoothFade<4000>,Mix<Bump<Int<0>,Int<3000>>,Black,Red>,TrSmoothFade<4000>>,TrInstant,EFFECT_RETRACTION>>>(),
//     StylePtr<TransitionLoop<Black,TrConcat<TrWipe<600>,ColorSequence<600,Red,Orange,Yellow,Green,Blue,Magenta>,TrWipeIn<600>>>>(),
//     StylePtr<InOutHelper<SimpleClash<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<DarkOrange,0,1,AudioFlicker<Orange,DarkOrange>,100,9000,1000>,White,200,100,400>,AudioFlicker<AudioFlicker<Yellow,White>,White>,AudioFlicker<AudioFlicker<Yellow,White>,White>>,Orange,40>,300,800,Black>,White,40>,300,800,Pulsing<Orange,DarkOrange,3000>>>(),
//     StylePtr<InOutHelper<TransitionLoop<BrownNoiseFlicker<OrangeRed,AliceBlue,50>,TrConcat<TrFade<100>,RotateColorsX<Sin<Int<10>>,Red>,TrFade<850>>>,1,800,TransitionLoop<StyleFire<OrangeRed,DarkOrange,0,1,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,2000,0>>,TrConcat<TrFade<100>,RotateColorsX<Sin<Int<10>>,Red>,TrFade<1500>>>>>(),
//     //James Rocco Cycle up and pulse heartbeat when off style for NXPL in hilt LEDs -ColorChangable 3.9
//     StylePtr<InOutHelper<SimpleClash<Lockup<Blast<ColorCycle<Rgb<50,50,200>,0,1,Strobe<Strobe<ColorChange<TrSmoothFade<450>,Rgb<25,255,0>,Rgb<10,0,255>,Rgb<25,25,255>,Rgb<255,10,10>,Rgb<175,100,0>,Rgb<135,135,0>,Rgb<100,0,175>>,Black,7,1>,Strobe<Black,ColorChange<TrSmoothFade<450>,Rgb<25,255,0>,Rgb<10,0,255>,Rgb<25,25,255>,Rgb<255,10,10>,Rgb<175,100,0>,Rgb<135,135,0>,Rgb<100,0,175>>,15,3>,1,1>,100,3000,3000>,Rgb<100,100,255>,350,200,750>,AudioFlicker<ColorChange<TrSmoothFade<450>,Rgb<75,125,200>,Rgb<50,75,200>,Rgb<50,75,200>,Rgb<75,75,225>,Rgb<75,100,200>,Rgb<75,100,200>,Rgb<100,75,200>>,ColorChange<TrSmoothFade<450>,Rgb<50,155,225>,Rgb<25,45,255>,Rgb<25,45,255>,Rgb<125,50,175>,Rgb<50,50,150>,Rgb<50,50,150>,Rgb<100,75,255>>>,Strobe<Strobe<ColorChange<TrSmoothFade<450>,Rgb<25,255,0>,Rgb<10,0,255>,Rgb<25,25,255>,Rgb<255,10,10>,Rgb<175,100,0>,Rgb<135,135,0>,Rgb<100,0,175>>,Black,7,1>,Strobe<Black,ColorChange<TrSmoothFade<450>,Rgb<25,255,0>,Rgb<10,0,255>,Rgb<25,25,255>,Rgb<255,10,10>,Rgb<175,100,0>,Rgb<135,135,0>,Rgb<100,0,175>>,15,3>,1,1>>,AudioFlicker<ColorChange<TrSmoothFade<450>,Rgb<75,125,200>,Rgb<50,75,200>,Rgb<50,75,200>,Rgb<75,75,225>,Rgb<75,100,200>,Rgb<75,100,200>,Rgb<100,75,200>>,ColorChange<TrSmoothFade<450>,Rgb<50,155,225>,Rgb<25,45,255>,Rgb<25,45,255>,Rgb<125,50,175>,Rgb<50,50,150>,Rgb<50,50,150>,Rgb<100,75,255>>>,250>,300,3000,TransitionLoop<Rgb<50,75,200>,TrConcat<TrBoing<370,1>,Black,TrInstant,Rgb<50,75,200>,TrSmoothFade<1665>,Black,TrSmoothFade<1665>>>> >(),
//  "nextor"},


// { "PitchBlk;common", "MSV.wav", //Fernando offer1

//     StylePtr<   
//         InOutTr<    
//             Layers<
//                 TransitionEffect<
//                     Blast<
//                         LocalizedClash<
//                                         Blue, 
//                         BrownNoiseFlicker<Yellow,White,500>, 90,60>,
//                     TransitionEffect<GreenYellow,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,800>,                            
//                 Mix<Bump<Int<32768>,Int<16000>>,Gradient<Blue,Blue,DodgerBlue,DeepSkyBlue,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Blue,White,15,20>,GreenYellow,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
//             AudioFlickerL<Rgb<0,0,128>>,
//             ResponsiveLockupL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>>>,
//             ResponsiveDragL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>>>,
//             ResponsiveMeltL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1> >>,
//             ResponsiveLightningBlockL<BrownNoiseFlicker<Strobe<Rgb<60,0,255>,White,15,1>,DeepSkyBlue,500>>>,
//         TrWipe<300>,TrWipeIn<450>,TransitionEffect<Black,Black,TrConcat<TrSmoothFade<100>,
//         Mix<Bump<Int<0>,Int<1500>>,Black,Sparkle<Rgb<128,128,128>>>,TrSmoothFade<2500>,
//         Mix<Bump<Int<0>,Int<1600>>,Black,Sparkle<Orange>>,TrSmoothFade<2200>,
//         Mix<Bump<Int<0>,Int<1350>>,Black,Sparkle<OrangeRed,White,200>>,TrSmoothFade<1700>,
//         Mix<Bump<Int<0>,Int<1100>>,Black,Sparkle<Rgb<100,0,0>,White,200>>,TrSmoothFade<1300>>,TrInstant,EFFECT_RETRACTION>>           //emitter cooldown
//     >(),
//     StylePtr<ColorCycle<Blue,20,30,Blue,20,300,1000>>(),
//     StylePtr<InOutTr<Pulsing<Black,AudioFlicker<Blue,Rgb<125,30,255>>,800>,TrWipe<300>,TrWipeIn<800>,Pulsing<Black,AudioFlicker<Blue,Rgb<125,30,255>>,3000>>>(),
//     StylePtr<InOutTr<Layers<Blue,AudioFlickerL<Rgb<125,30,255>>>,TrWipe<300>,TrWipeIn<800>,Pulsing<RandomFlicker<Blue,Pulsing<Blue,Rgb<50,30,255>,800>>,Black,3000>>>(),
//     StylePtr<InOutTr<TransitionLoop<Black,TrConcat<TrWipe<200>,Pulsing<Blue,Rgb<50,30,255>,800>,TrWipeIn<200>>>,TrWipe<300>,TrWipeIn<800>,Pulsing<Blue,Black,2000>>>(),
// "pitch\nblack"},


{ "Proto1;common", "tracks/venus.wav",    
    StylePtr<InOutHelper<Rgb16<5997,395,32349>,300,500>>(),
    StylePtr<Rgb16<5997,395,32349>>(),
    StylePtr<Rgb16<5997,395,32349>>(),
    StylePtr<Rgb16<5997,395,32349>>(),
    StylePtr<Rgb16<5997,395,32349>>(),// //StylePtr<InOutHelper<SimpleClash<Lockup<Blast<StyleFire<Blue,Cyan,0,3,FireConfig<200,2000,5>>,White>,Stripes<1000,-8000,StyleFire<Blue,Yellow>,BrownNoiseFlicker<DeepSkyBlue,Yellow,50>,RandomFlicker<DodgerBlue,Red>,StyleFire<Red,Yellow,0,2,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<600,5000,10>>>,AudioFlicker<Blue,White>>,White>,300,800>>()StylePtr<ColorSequence<400,Gradient<ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,Black,Black,Black,Black,Black>,Gradient<ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,Black,Black,Black>,Gradient<ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,Black,Black,Black>,Gradient<ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,Black,Black>,Gradient<ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>,Black>,ColorSequence<400,Red,Orange,Yellow,Green,Blue,Magenta>>>(),
    // StylePtr<InOutHelper<TransitionEffect<TransitionEffect<LocalizedClash<Lockup<Blast<BrownNoiseFlicker<Blue,DeepSkyBlue,50>,White>,BrownNoiseFlicker<RandomPerLEDFlicker<Red,Strobe<Black,White,15,15>>,Yellow,50>,BrownNoiseFlicker<RandomPerLEDFlicker<Red,Strobe<Black,White,15,15>>,Yellow,50>,Bump<Int<16384>>>,BrownNoiseFlicker<Yellow,Red,50>,80,70>,Mix<Bump<Int<32768>,Int<10000>>,BrownNoiseFlicker<Blue,DeepSkyBlue,50>,Yellow>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,Gradient<Gradient<White,BrownNoiseFlicker<Blue,DeepSkyBlue,50>,BrownNoiseFlicker<Blue,DeepSkyBlue,50>,BrownNoiseFlicker<Blue,DeepSkyBlue,50>,BrownNoiseFlicker<Blue,DeepSkyBlue,50>,BrownNoiseFlicker<Blue,DeepSkyBlue,50>>,BrownNoiseFlicker<Blue,DeepSkyBlue,50>,BrownNoiseFlicker<Blue,DeepSkyBlue,50>>,TrSmoothFade<500>,TrWipeIn<180>,EFFECT_RETRACTION>,300,450>>(),
    // StylePtr<TransitionLoop<Black,TrConcat<TrWipe<5000>,Rgb<0,15,200>,TrConcat<TrInstant,Black,TrFade<1000>>>>>(),
    // StylePtr<InOutHelper<BrownNoiseFlicker<Blue,DodgerBlue,50>,300,450,Pulsing<Blue,Black,3000>>>(),
    // StylePtr<InOutHelper<BrownNoiseFlicker<Blue,DodgerBlue,100>,300,450,Pulsing<Rgb<5,15,100>,BrownNoiseFlicker<Blue,DodgerBlue,30>,3000>>>(),
    // StylePtr<TransitionLoop<Black,TrConcat<TrWipe<5000>,Rgb<0,15,200>,TrConcat<TrInstant,Black,TrFade<1000>>>>>(),
    "proto 1"},



 // { "ReyGflx9;common", "tracks/Ep9/Rey_Skywalker.wav",
 //    StylePtr<InOutSparkTip<OnSpark<Blast<LocalizedClash<Lockup<StyleFire<Red,Rgb<255,100,50>,0,4,FireConfig<10,3000,5>,FireConfig<0,0,10000>,FireConfig<200,1000,50>,FireConfig<200,3500,0>>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,White,15,10>,50>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,White,15,10>,50>,Bump<Int<16384>,Int<32768>>>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,White,15,10>,75>,150,90>,TransitionEffect<Blue,White,TrWipe<50>,TrWipe<50>,EFFECT_BLAST>,300,200,800>,White,200>,300,350>>(),
 //    StylePtr<InOutHelper<Sparkle<Red>, 1000, 800,Stripes<5,50,Red,Black,TransitionLoop<White,TrConcat<TrFade<200>,Red,TrFade<1000>>>>>>(),
 //    StylePtr<InOutHelper<Pulsing<Yellow,Red,800>,1000,800,Pulsing<Green,Black,4000>>>(),
 //    StylePtr<StyleFire<Red,OrangeRed,0,2,FireConfig<20,2000,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<300,3000,0>>>(),
 //    StylePtr<ColorCycle<Cylon<Red,20,20,Red,95,20,2000>,95,200,AudioFlicker<BrownNoiseFlicker<Red,Rgb16<28268,1053,3>,50>,OrangeRed>,20,6000,2000>>(), 
 // "rey\nepisode 9"},



{ "ScavngrsDstny;common", "ScavngrsDstny/tracks/track4edit",
// Fett263 Light-Side AudioFlicker Style with "Responsive Blade" and Full Transitions
// Gold main blade:
// V1 
// StylePtr<   IgnitionDelay<300,InOutHelper<  Blast<  LocalizedClash< Lockup< TransitionEffect<   TransitionEffect<   TransitionEffect<   TransitionEffect<   TransitionEffect<   TransitionEffect<   TransitionEffect<
//                                                                                                                                                                                                                     Mix<SwingSpeed<400>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,
//                                                                                                                                                                                                                     Mix<SwingSpeed<600>,Rgb<255,160,0>,BlanchedAlmond>>,StyleFire<Rgb<255,160,0>,BlanchedAlmond,0,6>,TrInstant,TrSmoothFade<800>,EFFECT_IGNITION>,
//     Mix<Bump<Int<32768>,Int<16000>>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,RandomPerLEDFlicker<OrangeRed,White>>,TrConcat<TrWipeIn<600>,Mix<Bump<Int<32768>,Int<16000>>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,RandomPerLEDFlicker<Orange,White>>,TrWipe<600>>,TrInstant,EFFECT_STAB>,
//     Mix<Bump<Int<0>,Int<48000>>,Stripes<1000,1500,Rgb<255,160,0>,BrownNoiseFlicker<White,Rgb<255,160,0>,300>>,Stripes<1000,-1500,Rgb<255,160,0>,BrownNoiseFlicker<White,Rgb<255,160,0>,300>>>,TrInstant,TrSmoothFade<500>,EFFECT_LOCKUP_BEGIN>,
//     Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,White>,TrInstant,TrFade<200>,EFFECT_DRAG_BEGIN>,
//     Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,White>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,
//     Black,TrConcat<TrInstant,HumpFlicker<White,BrownNoiseFlicker<Rgb<255,160,0>,Rgb<0,0,40>,400>,40>,TrColorCycle<600>>,TrInstant,EFFECT_RETRACTION>,
//     Mix<Bump<Int<0>,Int<44000>>,Mix<Bump<Int<32768>,Int<44000>>,TransitionEffect<Rgb<255,160,0>,White,TrInstant,TrFade<300>,EFFECT_LOCKUP_END>,
//     Stripes<1000,-1500,Rgb<255,160,0>,BrownNoiseFlicker<White,Rgb<255,160,0>,300>>>,Stripes<1000,1500,Rgb<255,160,0>,BrownNoiseFlicker<White,Rgb<255,160,0>,300>>>,TrInstant,TrSmoothFade<800>,EFFECT_LOCKUP_END>,
//     Pulsing<Gradient<AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>>,Gradient<BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>>,3500>,RandomPerLEDFlicker<AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,White>,Bump<Int<16000>,Int<16000>>,Bump<Int<32768>,Int<10000>>>,White>,White>,
//                         150,300,Black>>
// >(),
// V2
StylePtr<   
    IgnitionDelay<300,  
        InOutHelper<    
            Layers< 
                LocalizedClash< 
                    Blast<  
                        TransitionEffect<
                            TransitionEffect<   
                                TransitionEffect<
                                   Mix<SwingSpeed<400>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,Mix<SwingSpeed<600>,Rgb<255,160,0>,BlanchedAlmond>>,
                                StyleFire<Rgb<255,160,0>,BlanchedAlmond,0,6>,TrInstant,TrSmoothFade<800>,EFFECT_IGNITION>,
                            Mix<Bump<Int<32768>,Int<16000>>,Gradient<BlanchedAlmond,Rgb<255,160,0>,Rgb<200,120,0>,LightYellow,White>,RandomPerLEDFlicker<AudioFlicker<Rgb<255,160,0>,White>,DarkOrange>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                        Gradient<White,LightYellow,Rgb<255,160,0>,Rgb<255,160,0>,Rgb<255,160,0>,Rgb<255,160,0>,Rgb<255,160,0>,Rgb<255,160,0>,Rgb<255,160,0>>,TrSmoothFade<800>,TrWipeIn<180>,EFFECT_RETRACTION>,
                    TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                BrownNoiseFlicker<DarkOrange,White,200>,90,60>,
            ResponsiveLockupL<Gradient<Red,RandomFlicker<OrangeRed,Red>,Strobe<BrownNoiseFlicker<Red,White,300>,BrownNoiseFlicker<Red,Strobe<Black,Orange,25,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>,Red>>,
            ResponsiveDragL<BrownNoiseFlicker<Red,Strobe<Orange,White,15,10>,500>>,
            ResponsiveMeltL<BrownNoiseFlicker<Red,Strobe<Orange,White,15,10>,500>>,
            ResponsiveLightningBlockL<BrownNoiseFlicker<Strobe<Rgb<60,0,255>,White,15,1>,DeepSkyBlue,500>>>,
        150,300,Black>
    >
>(),
// Rey yellow NPXL startup cycle
    StylePtr<ColorCycle<TransitionEffect<Blue,Green,TrWipe<400>,TrWipe<5000>,EFFECT_IGNITION>,0,1,AudioFlicker<Rgb16<64410,48313,1>,Yellow>,100,3000,500>>(), 
// ReyYello Crystal TOP
    StylePtr<InOutHelper<Pulsing<Yellow,Blue,800>,1000,800,Pulsing<Green,Black,4000>>>(), 
// Goldyellow based crystal with pulse off state
    StylePtr<InOutHelper<EasyBlade<OnSpark<StyleFire<Yellow,White,0,2,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,1200,0>>,White,200>,BrownNoiseFlicker<Cyan,DodgerBlue,500>,BrownNoiseFlicker<Blue,AudioFlicker<Yellow,Blue>,5000>>,1,800,Pulsing<TransitionLoop<Yellow,TrConcat<TrFade<800>,TransitionLoop<AudioFlicker<Pulsing<Yellow,White,800>,StyleFire<Rgb16<829,5115,26511>,Cyan,0,2,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,100,5>>>,TrConcat<TrFade<400>,Rgb<100,100,0>,TrFade<2000>>>,TrFade<2000>>>,Rgb<0,10,20>,3000>>>(),
// Rey Accents
    StylePtr<ColorCycle<ColorCycle<Pulsing<Yellow,DodgerBlue,800>,10,50,Cyan,0,50,200>,30,200,AudioFlicker<Pulsing<Blue,Yellow,800>,Blue>,20,300,100>>(),

"scavengers\ndestiny"},


  { "SenatMaj;common", "tracks/Palpatheme_SHORT.wav",      // Troy Huang Palpatine / Sidiuos
    //StylePtr<InOutSparkTip<OnSpark<Blast<LocalizedClash<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<Lockup<Mix<SwingSpeed<500>,AudioFlicker<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,Pulsing<Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,RandomFlicker<Red,OrangeRed>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<OrangeRed,Red>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,2000>,RandomPerLEDFlicker<Red,Yellow>>,Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Red,Rgb<128,0,0>>,Yellow>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,Gradient<Orange,Orange,White>,TrSmoothFade<50>,TrWipeIn<50>,EFFECT_DRAG_BEGIN>,Gradient<White,DeepSkyBlue,LightPink,DeepSkyBlue,White>,TrJoinR<TrWipe<100>,TrWipeIn<100>>,TrSmoothFade<100>,EFFECT_LOCKUP_END>,White,TrBoing<50,2>,TrFade<30>,EFFECT_LOCKUP_BEGIN>,Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,BrownNoiseFlicker<White,DarkOrange,400>,100,75>,TransitionEffect<Blue,White,TrWipe<1>,TrWipe<75>,EFFECT_BLAST>,400,250,800>,BrownNoiseFlicker<Black,Orange,400>,500>,300,800>>(),
    //Layer ver
    StylePtr<   
        RetractionDelay<1100,   
            InOutSparkTip<  
                Layers< 
                    OnSpark<    
                        Blast<  
                            LocalizedClash< 
                                TransitionEffect<  
                                        Mix<SwingSpeed<800>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,
                                        AudioFlicker<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red,Red,Red,Red,Red,Red,Red,Red>,Rgb<100,0,0>>>,                                                                                                                                                                    
                                Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                            BrownNoiseFlicker<White,DarkOrange,400>,100,75>,
                        TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                    BrownNoiseFlicker<Black,Orange,400>,500>,
                ResponsiveLockupL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe< Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>>>,
                ResponsiveDragL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>>>,
                ResponsiveMeltL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>>>,
                ResponsiveLightningBlockL<BrownNoiseFlicker<Strobe<Rgb<60,0,255>,White,15,1>,DeepSkyBlue,500>>>,
            300,800,White>
        >
    >(),
    StylePtr<InOutHelper<Pulsing<Red,Rgb16<2334,11,14386>,150>,300,800,Pulsing<Red,Sparkle<Rgb16<2334,11,14386>,Rgb<125,30,255>,60,500>,3200>>>(),
    StylePtr<InOutHelper<Pulsing<Red,Rgb<125,30,255>,150>,300,800,Pulsing<Red,Rgb16<2334,11,14386>,3200>>>(),    
    StylePtr<InOutHelper<SimpleClash<AudioFlicker<Red,Rgb<120,0,0>>,White>,300,800,Sparkle<Rgb16<2334,11,14386>,Rgb<125,30,255>,50,500>>>(),
    StylePtr<InOutHelper<TransitionLoop<Black,TrConcat<TrWipe<400>,AudioFlicker<Red,OrangeRed>,TrConcat<TrWipeIn<200>,Black,TrWipe<200>>>>,300,800,TransitionLoop<Black,TrConcat<TrWipe<2000>,AudioFlicker<Red,OrangeRed>,TrConcat<TrInstant,Black,TrFade<1>>>>>>(),
"senate\nmajority"},  

{ "SHATTERPOINT;common", "tracks/mars.wav",
    StylePtr<InOutHelper<Green,300,500>>(),
    StylePtr<
    Sparkle<HotPink,White,1000>>(),
    StylePtr<Green>(),
    StylePtr<Green>(),
    StylePtr<Green>(),
"shatter\npoint"},


 { "Strkllr1;common", "tracks/TFU1.wav", 
// Main Blade
//v5 pulsing old-school lockup      StylePtr<InOutSparkTip<Layers<TransitionEffect<TransitionEffect<SimpleClash<SimpleClash<TransitionEffect<TransitionEffect<OnSpark<Blast<LocalizedClash<Lockup<AudioFlicker<Red,Sparkle<Rgb<150,10,0>,Red,15,5000>>,Pulsing<Gradient<Red,BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,Yellow,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>>,Gradient<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,500>,Yellow,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>,Red>,2000>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>,Bump<Int<17000>,Int<20000>>>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,White,15,10>,75>,90,75>,TransitionEffect<Blue,White,TrWipe<50>,TrWipe<50>,EFFECT_BLAST>,300,250,800>,White,250>,AudioFlicker<Red,Rgb<100,10,0>>,TrConcat<TrFade<50>,Strobe<GreenYellow,Black,30,30>,TrFade<100>,StyleFire<Red,White,0,6,FireConfig<0,800,5>,FireConfig<3000,0,0>,FireConfig<0,800,0>>,TrFade<500>>,TrInstant,EFFECT_LOCKUP_END>,Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Red,Rgb<128,0,0>>,Yellow>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,Strobe<GreenYellow,Black,30,30>,90,EFFECT_LOCKUP_BEGIN>,Strobe<GreenYellow,Black,30,30>,50,EFFECT_DRAG_BEGIN>,Gradient<Gradient<White,Red,Red,Red,Red,Red>,Red,Red>,TrSmoothFade<500>,TrWipeIn<180>,EFFECT_RETRACTION>,Mix<Bump<Int<32768>,Int<16000>>,OrangeRed,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrConcat<TrWipeIn<300>,Mix<Bump<Int<32768>,Int<25000>>,AudioFlicker<OrangeRed,BrownNoiseFlicker<AudioFlicker<DarkOrange,Rgb<80,90,130>>,Rgb<255,20,20>,500>>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipe<600>>,TrFade<600>,EFFECT_STAB>,ResponsiveLightningBlockL<BrownNoiseFlicker<White,DeepSkyBlue,500>>>,300,450>>(),
    // StylePtr<   InOutSparkTip<  Layers<
    //                                 TransitionEffect<   TransitionEffect<   SimpleClash<    SimpleClash<    TransitionEffect<   TransitionEffect<   OnSpark<    Blast<  LocalizedClash<     Lockup< 
    //                                                                                                                                                                                                 AudioFlicker<Red,Sparkle<Rgb<150,10,0>,Red,15,5000>>,
    //                                                                                                                                                                                             Pulsing<
    //                                                                                                                                                                                                 Gradient<Red,BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>>,
    //                                                                                                                                                                                                 Gradient<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,500>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>,Red>,2000>,
    //                                                                                                                                                                                         BrownNoiseFlicker<BrownNoiseFlicker<White,DeepSkyBlue,50>,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>, 
    //                                                                                                                                                                                         Bump<Int<17000>,Int<20000>>,                    
    //                                                                                                                                                                                         SmoothStep<Int<28672>,Int<4097>>>,          
    //                                                                                                                                                                     BrownNoiseFlicker<BrownNoiseFlicker<White,DeepSkyBlue,50>,Strobe<Strobe<Red,White,15,20>,White,15,10>,75>>,
    //                                                                                                                                                             TransitionEffect<Blue,White,TrWipe<50>,TrWipe<50>,EFFECT_BLAST>,300,250,800>,
    //                                                                                                                                                 White,250>,
    //                                                                                                                             AudioFlicker<Red,Rgb<100,10,0>>,TrConcat<TrFade<50>,Strobe<GreenYellow,Black,30,30>,TrFade<100>,StyleFire<Red,White,0,6,FireConfig<0,800,5>,FireConfig<3000,0,0>,FireConfig<0,800,0>>,TrFade<500>>,TrInstant,EFFECT_LOCKUP_END>,
    //                                                                                                         Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Red,Rgb<128,0,0>>,BrownNoiseFlicker<DeepSkyBlue,White,50>>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,
    //                                                                                         Strobe<GreenYellow,Black,30,30>,90,EFFECT_LOCKUP_BEGIN>,
    //                                                                         Strobe<GreenYellow,Black,30,30>,50,EFFECT_DRAG_BEGIN>,
    //                                                     Gradient<Gradient<White,Red,Red,Red,Red,Red>,Red,Red>,TrSmoothFade<500>,TrWipeIn<180>,EFFECT_RETRACTION>,
    //                                 Mix<Bump<Int<32768>,Int<16000>>,OrangeRed,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrConcat<TrWipeIn<300>,Mix<Bump<Int<32768>,Int<25000>>,AudioFlicker<OrangeRed,BrownNoiseFlicker<AudioFlicker<DarkOrange,Rgb<80,90,130>>,Rgb<255,20,20>,500>>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipe<600>>,TrFade<600>,EFFECT_STAB>,
    //                             ResponsiveLightningBlockL<BrownNoiseFlicker<White,DeepSkyBlue,500>>>,
    //             300,450>
    // >(),
    StylePtr<   
        InOutSparkTip<  
            Layers< 
                OnSpark<    
                    Blast<  
                        LocalizedClash< 
                            TransitionEffect<   
                                TransitionEffect<     
                                    AudioFlicker<Red,Sparkle<Rgb<150,10,0>,Red,15,5000>>,
                                Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                            Gradient<Gradient<White,Red,Red,Red,Red,Red>,Red,Red>,TrSmoothFade<500>,TrWipeIn<180>,EFFECT_RETRACTION>,    
                        BrownNoiseFlicker<BrownNoiseFlicker<White,DeepSkyBlue,50>,Strobe<Strobe<Red,White,15,20>,White,15,10>,75>,90,60>, ///BC REUPLOAD THESE CLASH VALUES
                    TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                White,250>,                                     
            ResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>>,
            ResponsiveDragL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>>,
            ResponsiveMeltL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,White,15,20>,White,15,10>,300>>,
            ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>,
        300,450,White>
    >(),
// NPXL
    StylePtr<ColorCycle<Cylon<Red,50,20,Red,95,20,2000>,75,200,AudioFlicker<BrownNoiseFlicker<Red,Rgb16<28268,1053,3>,50>,OrangeRed>,20,6000,2000>>(),
// Chamber Top
    StylePtr<InOutHelper<EasyBlade<OnSpark<Pulsing<Black,Red,500>,White,200>,White>,1,1,Pulsing<Black,Red,3000>>>(),
// Chamber Crystal
    StylePtr<InOutHelper<EasyBlade<OnSpark<StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,White,200>,White>,1,1,Pulsing<Red,Sparkle<Black,White,7>,3000>>>(),
// Accents
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Mix<Bump<Sin<Int<120>,Int<10>,Int<32000>>,Int<16000>>,Black,Red>,White>,AudioFlicker<Rgb<255,100,100>,White>,AudioFlicker<Rgb<100,100,100>,White>,Int<32768>,SmoothStep<Int<16000>,Int<32768>>>,White,50,EFFECT_CLASH,SmoothStep<Int<16384>,Int<32768>>>,1,1,Mix<Bump<Sin<Int<40>,Int<10>,Int<32000>>,Int<10000>>,Black,Red>>>(),
"Starkiller"},



// { "Strkllr1;common", "tracks/TFU2.wav", 
// // compiles, but basic in out    StylePtr<InOutHelperX< Red,ChangeSlowly< Ifon<Int<32768>, Int<0>>, Int<32768>> >>(),
// StylePtr<   InOutHelperX< 
//                         Red, 
//                     InOutFuncX< 
//                             Scale< 
//                                     InOutFuncX<
//                                         Sin<Int<50>>, Sin<Int<1000>>
//                                     >, 
//                                 Sin<Int<50>>, Sin<Int<50>>
//                             >, 
//                             Scale<
//                                     InOutFuncX<
//                                         Int<500>, Int<1000>
//                                     >, 
//                                 Int<1000>, Int<500>
//                             >
//                     >
//             >
//  >(),
// StylePtr<Green>(),
// StylePtr<Green>(),
// StylePtr<Green>(),
// StylePtr<Green>(),

 // "tfu2"},

            
// { "testfont;common", "tracks/DuelOfTheFates.wav",
    //StylePtr<InOutHelperX<Gradient<Blue, Blue, Green, Yellow, Orange, Red, Red>, Scale<SmoothSoundLevel,Int<0>,Int<100000>>>>(),                  // VU meter works!
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // "testfont"},

{ "BattLevl;common", "",
     &style_charging,
     StylePtr<BatteryLevelStyle>(),
     StylePtr<PulsingX<Mix<BatteryLevel,Red,Yellow,Green>,Black,BatteryLevel>>(),
     StylePtr<BatteryLevelStyle>(),
     StylePtr<PulsingX<Mix<BatteryLevel,Red,Yellow,Green>,Black,BatteryLevel>>(),
"battery\nlevel"},

            
// { "testfont;common", "tracks/DuelOfTheFates.wav",
    //StylePtr<InOutHelperX<Gradient<Blue, Blue, Green, Yellow, Orange, Red, Red>, Scale<SmoothSoundLevel,Int<0>,Int<100000>>>>(),                  // VU meter works!
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // "testfont"},

            
{ "testfont;common", "tracks/balmorra.wav",
    StylePtr<InOutHelper<Yellow,300,500>>(),                  
    StylePtr<Yellow>(),
    StylePtr<Yellow>(),
    StylePtr<Yellow>(),
     StylePtr<Yellow>(),
    "etaan\ncrystal"}

            
// { "testfont;common", "tracks/DuelOfTheFates.wav",
    //StylePtr<InOutHelperX<Gradient<Blue, Blue, Green, Yellow, Orange, Red, Red>, Scale<SmoothSoundLevel,Int<0>,Int<100000>>>>(),                  // VU meter works!
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // "testfont"},

            
// { "testfont;common", "tracks/DuelOfTheFates.wav",
    //StylePtr<InOutHelperX<Gradient<Blue, Blue, Green, Yellow, Orange, Red, Red>, Scale<SmoothSoundLevel,Int<0>,Int<100000>>>>(),                  // VU meter works!
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // "testfont"},

            
// { "testfont;common", "tracks/DuelOfTheFates.wav",
    //StylePtr<InOutHelperX<Gradient<Blue, Blue, Green, Yellow, Orange, Red, Red>, Scale<SmoothSoundLevel,Int<0>,Int<100000>>>>(),                  // VU meter works!
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
    // "testfont"},

};

//----------------------------------------------------------------------------------------------------------------------------------------
Preset noblade[] = {

// // Try Sparkle<Red> as accents style

{ "DarkAppr;common", "tracks/TFU1.wav", 
    StylePtr<Black>(),
    StylePtr<ColorCycle<Red,50,50,Red,20,350,1000>>(),
    StylePtr<InOutHelper<EasyBlade<OnSpark<Pulsing<Black,Red,500>,White,200>,White>,1,1,Pulsing<Black,Red,3000>>>(),
    StylePtr<InOutHelper<EasyBlade<OnSpark<StyleFire<Red,OrangeRed,0,2,FireConfig<0,1500,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,0,5>>,White,200>,White>,1,1,Pulsing<Red,Sparkle<Black,White,7>,3000>>>(),
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Mix<Bump<Sin<Int<120>,Int<10>,Int<32000>>,Int<16000>>,Black,Red>,White>,AudioFlicker<Rgb<255,100,100>,White>,AudioFlicker<Rgb<100,100,100>,White>,Int<32768>,SmoothStep<Int<16000>,Int<32768>>>,White,50,EFFECT_CLASH,SmoothStep<Int<16384>,Int<32768>>>,1,1,Mix<Bump<Sin<Int<40>,Int<10>,Int<32000>>,Int<10000>>,Black,Red>>>(),
"tfu1"},   
  
            
// { "testfont;common", "tracks/uranus.wav",
//     StylePtr<InOutHelper<SimpleClash<Lockup<Blast<RotateColorsX<Sin<Int<10>>,Red>,White>,AudioFlicker<Blue,White>>,White>,300,800>>(),
//     StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
//     StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
//     StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
//     StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
// "testfont"},


// { "LngthFnd;common", "",
//     StylePtr<LengthFinder<>>(),
//     StylePtr<Black>(),
//     StylePtr<Black>(), 
//     StylePtr<Yellow>(),
//     StylePtr<Yellow>(),
// "length\nfinder"},

{ "BattLevl;common", "tracks/mars.wav",
     &style_charging,
     StylePtr<BatteryLevelStyle>(),
     StylePtr<BatteryLevelStyle>(),
     StylePtr<BatteryLevelStyle>(),
     StylePtr<BatteryLevelStyle>(),
"battery\nlevel"}

};


BladeConfig blades[] = {

{ NO_BLADE, // blade=0 // D1_data_line = proffie_D1> NPXL ctrpin---> Open when no blade ....65518.96ohm
            //                                                  \--->33k>BP pin 
 
  WS281XBladePtr<0, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
// CONFIGARRAY(noblade),
// "bladeNO_BLADEsave", }, // Make NPXL do cool shit when no blade in.
  CONFIGARRAY(noblade),
"00_NO_BLADEsave", }, // Make NPXL do cool shit when no blade in.

{ 32000,    // blade=1 // 1" BC_A       123 apa105    D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm---> Main blade strips
            //                                                                              \-->33k>BP pin (--->LED NEG when blade in....31859.89ish?
   
  WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
// CONFIGARRAY(bladeBC_A), 
// "bladeBC_Asave", }, 
  CONFIGARRAY(AllBlades), 
"01_AllBladessave", }, 

{ 18500,    // blade=2 // 1" Ciel_Tan_A 132           D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
            //                                                                                 \-->33k>BP pin (--->LED NEG when blade in....18433.79ish?
   
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
// CONFIGARRAY(bladeCT_A),
// "bladeCT_Asave", }, 
   CONFIGARRAY(AllBlades), 
"02_AllBladessave", }, 

{ 4500,     // blade=3 //   1" BC_B     131 5050s     D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
            //                                                                                 \-->33k>BP pin (--->LED NEG when blade in....4380.53ish?
   
  WS281XBladePtr<131, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
// CONFIGARRAY(bladeBC_B),
// "bladeBC_Bsave", }, 
  CONFIGARRAY(AllBlades), 
"03_AllBladessave", }, 

{ 7800,     // blade=4 //   1" BC_C     123 APA105 10mm     D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
            //                                                                                 \-->33k>BP pin (--->LED NEG when blade in....XXXXXish?
   
  WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
  SubBlade (7, 7, NULL),  // Chamber Top
  SubBlade (6, 6, NULL),  // Chamber Crystal
  SubBlade (0, 5, NULL),  // Accents
// CONFIGARRAY(bladeBC_C),
// "bladeBC_Csave", }, 
   CONFIGARRAY(AllBlades), 
"04_AllBladessave", }, 

// { 20000,     //blade=5 // 7/8" Ciel_Tan_B             D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
//             //                                                                                 \-->33k>BP pin (--->LED NEG when blade in....21067.20ish?
   
//   WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
//   SubBlade (8, 12, WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin6> >() ), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs.
//   SubBlade (7, 7, NULL),  // Chamber Top
//   SubBlade (6, 6, NULL),  // Chamber Crystal
//   SubBlade (0, 5, NULL),  // Accents
// // CONFIGARRAY(bladeCT_B),
// // "bladeCT_Bsave", },
//   CONFIGARRAY(AllBlades), 
// "05_AllBladessave", }, 


};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
