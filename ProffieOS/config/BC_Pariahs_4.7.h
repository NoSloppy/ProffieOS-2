// BC_Pariahs_4.7.h


#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
#define VOLUME 1600
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
#define KEEP_SAVEFILES_WHEN_PROGRAMMING
#define IDLE_OFF_TIME 60*5*1000
#define SA22C_NO_LOCKUP_HOLD
//    #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
//    #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
    #define BLADE_DETECT_PIN blade3Pin
#define DISABLE_DIAGNOSTIC_COMMANDS
// #define ORIENTATION_ROTATION 0,20,0 // -20 is USB  leaning down
// For Curved hilts, or where the board is not parallel with the blade. For Twist on/off particularly.
//This will rotate the orientation of the board 20 degrees around the Y axis.
// Depending on the orientation of the board, you might need -20 degrees instead. (Or 15 degrees? or 30?)
#endif


#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons4x.h"

#endif

#ifdef CONFIG_PRESETS

///StylePtr<PulsingX<Mix<BatteryLevel,Red,Yellow,Green>,Black,BatteryLevel>>()
using BatteryLevelStyle =Mix<Sin<Int<20>,Int<8192>,Int<32768>>,Black,Mix<BatteryLevel,Red,Red,Orange,Orange,Yellow,Yellow,Green,Green,Green,Blue,Blue,Blue>>;
//using SoundLevelStyle =Mix<Sin<Int<20>,Int<8192>,Int<32768>>,Black,Mix<NoisySoundLevel,Red,Red,Orange,Orange,Yellow,Yellow,Green,Green,Green,Blue,Blue,Blue>>;

Preset AllBlades [] = {

{ "2ndSistr;common", "tracks/Sister1.wav", 
    StylePtr<   // Sith Red os4
        InOutSparkTip<  
            Layers< 
                OnSpark<    
                    Blast<  
                        LocalizedClash< 
                            TransitionEffect<
                                TransitionEffect<
                                    TransitionEffect<   
                                        TransitionEffect<     
                                            HumpFlicker<Red,Rgb<128,0,0>,15>,
                                        Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                                    Mix<Bump<Int<0>,Int<4000>>,HumpFlicker<Red,Rgb<128,0,0>,15>,White>,TrConcat<TrDelay<200>,HumpFlicker<Red,Rgb<128,0,0>,15>,TrSmoothFade<300>>,TrWipeIn<180>,EFFECT_RETRACTION>,
                                Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
                            Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<70>,EFFECT_BLAST>,
                        BrownNoiseFlicker<BrownNoiseFlicker<Yellow,DeepSkyBlue,1000>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,200>,120,50,EFFECT_CLASH>,//color more yellow
                    TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                White,225>,                                     
            BCResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,300>>,
            BCResponsiveDragL<Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>>,
            BCResponsiveMeltL<  Mix<TwistAngle<>, Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Rgb<150,0,0>,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,OrangeRed,Orange,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>,Mix<Int<16000>,Gradient<Orange,Red>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>> > >,
            ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>, 
        300,500,White>
    >(),
    StylePtr<Black>(),
"second\nsister"}, 



{ "AchluSS;common", "tracks/Sister1.wav", 
    StylePtr<   
        InOutSparkTip<  
            Layers< 
                OnSpark<    
                    Blast<  
                        LocalizedClash< 
                            TransitionEffect<
                                TransitionEffect<
                                    TransitionEffect<   
                                        TransitionEffect<     
                                            HumpFlicker<Red,Rgb<128,0,0>,15>,
                                        Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                                    Mix<Bump<Int<0>,Int<4000>>,HumpFlicker<Red,Rgb<128,0,0>,15>,White>,TrConcat<TrDelay<300>,HumpFlicker<Red,Rgb<128,0,0>,15>,TrSmoothFade<350>>,TrWipeIn<180>,EFFECT_RETRACTION>,
                                Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
                            Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<70>,EFFECT_BLAST>,
                        BrownNoiseFlicker<BrownNoiseFlicker<Yellow,DeepSkyBlue,1000>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,200>,120,50,EFFECT_CLASH>,//color more yellow
                    TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                White,225>,                                     
            BCResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,300>>,
            BCResponsiveDragL<Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>>,
            BCResponsiveMeltL<  Mix<TwistAngle<>, Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Rgb<150,0,0>,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,OrangeRed,Orange,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>,Mix<Int<16000>,Gradient<Orange,Red>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>> > >,
            ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>, 
        300,660,White>
    >(),
    StylePtr<Black>(),
"achluophobia"}, 

{ "BlakStar;common", "tracks/Sister1.wav", 
    StylePtr<   // Sith Red os4
        InOutSparkTip<  
            Layers< 
                OnSpark<    
                    Blast<  
                        LocalizedClash< 
                            TransitionEffect<
                                TransitionEffect<
                                    TransitionEffect<   
                                        TransitionEffect<     
                                            HumpFlicker<Red,Rgb<128,0,0>,15>,
                                        Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                                    Mix<Bump<Int<0>,Int<4000>>,HumpFlicker<Red,Rgb<128,0,0>,15>,White>,TrConcat<TrDelay<350>,HumpFlicker<Red,Rgb<128,0,0>,15>,TrSmoothFade<400>>,TrWipeIn<180>,EFFECT_RETRACTION>,
                                Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
                            Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<70>,EFFECT_BLAST>,
                        BrownNoiseFlicker<BrownNoiseFlicker<Yellow,DeepSkyBlue,1000>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,200>,120,50,EFFECT_CLASH>,//color more yellow
                    TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                White,225>,                                     
            BCResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,300>>,
            BCResponsiveDragL<Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>>,
            BCResponsiveMeltL<  Mix<TwistAngle<>, Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Rgb<150,0,0>,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,OrangeRed,Orange,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>,Mix<Int<16000>,Gradient<Orange,Red>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>> > >,
            ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>, 
        300,750,White>
    >(),
    StylePtr<Black>(),
"blakstar"},

//   { "EmperorP;common", "tracks/Palpatheme_SHORT.wav",      // Troy Huang Palpatine / Sidiuos
//     StylePtr<      
//         InOutSparkTip<  
//             Layers< 
//                 OnSpark<    
//                     Blast<  
//                         LocalizedClash< 
//                             TransitionEffect<
//                                 TransitionEffect< 
//                                     TransitionEffect< 
//                                         TransitionEffect<  
//                                                 Mix<SwingSpeed<800>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,
//                                                 AudioFlicker<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red,Red,Red,Red,Red,Red,Red,Red>,Rgb<100,0,0>>>,                                                                                                                                                                    
//                                         Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
//                                     Mix<Bump<Int<0>,Int<6000>>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,White>,TrConcat<TrDelay<175>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,TrSmoothFade<250>>,TrWipeIn<180>,EFFECT_RETRACTION>,
//                                 Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
//                             Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<80>,EFFECT_BLAST>,
//                         BrownNoiseFlicker<White,DarkOrange,400>,100,75,EFFECT_CLASH>,
//                     TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
//                 BrownNoiseFlicker<Black,Orange,400>,500>,
//             BCResponsiveLockupL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe< Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>>>,
//             BCResponsiveDragL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>>>,
//             BCResponsiveMeltL<   Mix<TwistAngle<>, Gradient<AudioFlicker<Red,Rgb<128,0,0>>,RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,White,15,10>,300>,50,1>>,Gradient<RandomFlicker<OrangeRed,Red>,RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,BrownNoiseFlicker<AudioFlicker<Yellow,Red>,White,500>>   >>,
//             ResponsiveLightningBlockL<BrownNoiseFlicker<Strobe<Rgb<60,0,255>,White,15,1>,DeepSkyBlue,500>>>,
//         300,520,White>
//     >(),
//     StylePtr<Black>(),
// "emperor\npalpatine"},


// { "EtaanCrs;common", "balmorra_short.wav", //colorchange to something, uses swing to color darkorange = Rgb<255,68,0> Rgb<128,34,0> crappy . 
// StylePtr<      
//         InOutSparkTip<  
//             Layers< 
//                 OnSpark<
//                     Blast<
//                         LocalizedClash<
//                             TransitionEffect<
//                                 TransitionEffect<
//                                     TransitionEffect<
//                                         TransitionEffect<
//                                             Mix<SwingSpeed<400>,AudioFlicker<Rgb<255,90,0>,Rgb<84,60,0>>,
//                                             Mix<SwingSpeed<600>,Rgb<255,90,0>,BlanchedAlmond>>,
//                                         Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,Orange,400>,Red,AudioFlicker<Rgb<255,90,0>,Rgb<84,60,0>>,Orange,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
//                                     Gradient<White,AudioFlicker<Rgb<255,90,0>,Rgb<84,60,0>>,AudioFlicker<Rgb<255,90,0>,Rgb<84,60,0>>,Rgb<255,90,0>,Rgb<255,90,0>,Rgb<255,90,0>>,TrConcat<TrDelay<175>,AudioFlicker<Rgb<255,90,0>,Rgb<84,60,0>>,TrSmoothFade<250>>,TrWipeIn<180>,EFFECT_RETRACTION>,
//                                 Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<80>,EFFECT_BLAST>,
//                             Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
//                         BrownNoiseFlicker<White,DarkOrange,400>,100,75,EFFECT_CLASH>,
//                     TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
//                 BrownNoiseFlicker<Black,Orange,400>,500>,
//             BCResponsiveLockupL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe< Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>>>,
//             BCResponsiveDragL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>>>,
//             BCResponsiveMeltL<   Mix<TwistAngle<>, Gradient<AudioFlicker<Red,Rgb<128,0,0>>,RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,White,15,10>,300>,50,1>>,Gradient<RandomFlicker<OrangeRed,Red>,RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,BrownNoiseFlicker<AudioFlicker<Yellow,Red>,White,500>>   >>,
//             ResponsiveLightningBlockL<BrownNoiseFlicker<Strobe<Rgb<60,0,255>,White,15,1>,DeepSkyBlue,500>>>,
//         300,520,White>
//     >(),
//     StylePtr<Black>(),
// "etaan\ncrystal"},

// { "FinalSteps;common", "tracks/mars.wav",
//     StylePtr<InOutHelper<AudioFlicker<DodgerBlue,DeepSkyBlue>,300,500>>(),                  
//     StylePtr<Black>(),
// "final\nsteps"},

// { "GeneralPrincess;common", "tracks/Tales of a Jedi Knight 1.wav",
//     StylePtr<InOutHelper<AudioFlicker<Green,MintCream>,300,500>>(),                  
//     StylePtr<Black>(),
// "general\nprincess"},


//  { "Inquisitor;common", "tracks/balmorra_short.wav",     
//      StylePtr<   // Sith Red os4
//         InOutSparkTip<  
//             Layers< 
//                 OnSpark<    
//                     Blast<  
//                         LocalizedClash< 
//                             TransitionEffect<
//                                 TransitionEffect<
//                                     TransitionEffect<   
//                                         TransitionEffect<     
//                                             HumpFlicker<Red,Rgb<128,0,0>,15>,
//                                         Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
//                                     Mix<Bump<Int<0>,Int<4000>>,HumpFlicker<Red,Rgb<128,0,0>,15>,White>,TrConcat<TrDelay<175>,HumpFlicker<Red,Rgb<128,0,0>,15>,TrSmoothFade<250>>,TrWipeIn<180>,EFFECT_RETRACTION>,
//                                 Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
//                             Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<70>,EFFECT_BLAST>,
//                         BrownNoiseFlicker<BrownNoiseFlicker<White,DeepSkyBlue,50>,Strobe<Strobe<Red,White,15,20>,White,15,10>,75>,110,60,EFFECT_CLASH>,
//                     TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
//                 White,225>,                                     
//             BCResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,300>>,
//             BCResponsiveDragL<Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>>,
//             BCResponsiveMeltL<  Mix<TwistAngle<>, Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Rgb<150,0,0>,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,OrangeRed,Orange,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>,Mix<Int<16000>,Gradient<Orange,Red>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>> > >,
//             ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>, 
//         300,950,White>
//     >(),
//     StylePtr<Black>(),
// "Grand\nInquisitor"},  

{ "Knighthood;common", "tracks/mars.wav", 
    StylePtr< // purple 
        InOutSparkTip<                                                  // retractoion color instead of gradient Mix<Bump<Int<0>,Int<16000>>,HumpFlicker<White,Rgb<50,20,255>,3>,White>
            Layers< 
                OnSpark<
                    Blast<
                        LocalizedClash<
                            TransitionEffect<
                                TransitionEffect<
                                    TransitionEffect<
                                        TransitionEffect<
                                            Mix<SwingSpeed<400>,HumpFlicker<Rgb<50,20,255>,Rgb<20,0,120>,5>,HumpFlicker<White,Rgb<50,20,255>,10>>,
                                        Mix<Bump<Int<32768>,Int<30000>>,BrownNoiseFlicker<Rgb<120,40,255>,RandomPerLEDFlicker<Rgb<15,2,50>,Rgb<30,5,85>>,200>,RandomPerLEDFlicker<Strobe<OrangeRed,White,30,10>,Yellow>>,TrWipeIn<500>,TrFade<600>,EFFECT_STAB>,
                                    Mix<Bump<Int<0>,Int<16000>>,HumpFlicker<White,Rgb<50,20,255>,3>,White>,TrConcat<TrDelay<350>,HumpFlicker<White,Rgb<50,20,255>,3>,TrSmoothFade<600>>,TrWipeIn<180>,EFFECT_RETRACTION>,
                                Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
                            Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<80>,EFFECT_BLAST>,
                        BrownNoiseFlicker<Yellow,DarkOrange,400>,100,50,EFFECT_CLASH>,          
                    TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                Mix<Bump<Int<0>,Int<16000>>,HumpFlicker<White,Rgb<50,20,255>,3>,White>,500>,
            BCResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,OrangeRed,50>,10>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,300>>,
            BCResponsiveDragL<RandomPerLEDFlicker<Strobe<OrangeRed,White,30,10>,Yellow>>,
            //BCResponsiveMeltL<  Mix<TwistAngle<>, Mix<Bump<Int<32768>,Int<30000>>,BrownNoiseFlicker<Rgb<120,40,255>,RandomPerLEDFlicker<Rgb<15,2,50>,Rgb<30,5,85>>,200>,RandomPerLEDFlicker<Strobe<OrangeRed,White,30,10>,Yellow>>,Mix<Bump<Int<25000>,Int<60000>>,BrownNoiseFlicker<Rgb<120,40,255>,RandomPerLEDFlicker<Rgb<15,2,50>,Rgb<30,5,85>>,200>,RandomPerLEDFlicker<Strobe<OrangeRed,White,30,10>,Yellow>> > >,
            BCResponsiveMeltL< >,
            ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>,
        300,750,White>
    >(),                  
    StylePtr<Black>(),
"knighthood"},


// // { "KrossGrd;common", "tracks/Kylo1.wav",
// //     // Fully Responsive Kylo Ren Unstable (Unstable Swing) Styles - Sith Red - OS4.x
// // // StylePtr<    InOutTr<    Layers< 
// // //                                  Mix<SwingSpeed<310>,
// // //                                      StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
// // //                                      StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<25,0,0>>,300>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<10,0,0>>>,0,8,FireConfig<10,1200,1>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>>,
// // //                          ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,
// // //                              TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
// // //                          ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Blue,300>,50,1>,TrConcat<TrInstant,White,TrFade<200>>,TrFade<400>>,
// // //                          ResponsiveDragL<BrownNoiseFlickerL<White,Int<300>>,TrWipeIn<400>,TrFade<400>>,
// // //                          ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
// // //                          ResponsiveMeltL<Mix<TwistAngle<>,OrangeRed,Orange>,TrWipeIn<600>,TrSmoothFade<600>>,
// // //                          ResponsiveBlastFadeL<White>,
// // //                          ResponsiveClashL<White>,
// // //                              TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<800>>,EFFECT_IGNITION>,
// // //                              TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>>,
// // //                          TrWipe<300>,TrWipeIn<500>,
// // //              Layers<
// // //                      Black,
// // //                     TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>>>
// // //     >(),
    
// //     // "Flame Control" Fire Blade Responsive Style. down makes flame smaller / slower. Up = larger faster
// //     StylePtr<   
// //         Layers<
// //                 Mix<SmoothStep<Scale<BladeAngle<0,24000>,Int<10000>,Int<40000>>,Int<20000>>,
// //                     TransitionEffect<
// //                         Mix<Scale<BladeAngle<>,Int<32768>,Int<0>>,
// //                             StyleFire<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,0,4,FireConfig<0,1500,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>>,
// //                             StyleFire<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Black>,0,2,FireConfig<0,1600,30>,FireConfig<0,0,0>,FireConfig<0,2000,5>>>,
// //                     HumpFlickerL<White,40>,TrInstant,TrFade<800>,EFFECT_LOCKUP_END>,
// //         Black>,
// //         LockupTrL<AlphaL<Strobe<White,BrownNoiseFlicker<White,Blue,300>,50,1>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<4000>>,Int<10000>>>,TrConcat<TrInstant,White,TrFade<200>>,TrFade<400>,SaberBase::LOCKUP_NORMAL>,
// //         LockupTrL<AlphaL<HumpFlickerL<White,50>,Bump<Int<0>,Int<8000>>>,TrInstant,TrFade<400>,SaberBase::LOCKUP_DRAG>,
// //         TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<4000>>,Int<10000>>>,TrFade<200>>,EFFECT_CLASH>,
// //         TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<8000>,Int<28000>>,Int<8000>>,Int<10000>>>,TrFade<200>>,EFFECT_BLAST>,Mix<IsLessThan<BladeAngle<>,Int<12000>>,
// //         ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,AlphaL<White,Int<0>>>,
// //         ResponsiveMeltL<Mix<TwistAngle<>,OrangeRed,Orange>,TrWipeIn<600>,TrSmoothFade<600>>>
// //     >(),
  
// //     StylePtr<Black>(),
// // "kylo"},




  
// // { "Mauler;common", "tracks/DuelOfTheFates.wav",  
// // StylePtr<   
// //         InOutSparkTip<  
// //             Layers< 
// //                 OnSpark<    
// //                     Blast<  
// //                         LocalizedClash<
// //                             TransitionEffect<
// //                                 TransitionEffect< 
// //                                     TransitionEffect<   
// //                                         TransitionEffect<     
// //                                             HumpFlicker<Rgb16<65535,507,7>,HumpFlicker<Red,Rgb16<36732,1587,1>,15>,30>,
// //                                         Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
// //                                     Gradient<Gradient<White,Red,Red,Red,Red,Red>,Red,Red>,TrConcat<TrDelay<175>,HumpFlicker<Rgb16<65535,507,7>,HumpFlicker<Red,Rgb16<36732,1587,1>,15>,30>,TrSmoothFade<250>>,TrWipeIn<180>,EFFECT_RETRACTION>,
// //                                 Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<80>,EFFECT_BLAST>,
// //                             Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
// //                         BrownNoiseFlicker<BrownNoiseFlicker<White,DeepSkyBlue,50>,Strobe<Strobe<Red,White,15,20>,White,15,10>,75>,90,60,EFFECT_CLASH>,
// //                     TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
// //                 White,250>,                                     
// //             BCResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,300>>,
// //             BCResponsiveDragL<Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>>,
// //             BCResponsiveMeltL<  Mix<TwistAngle<>, Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Rgb<150,0,0>,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,OrangeRed,Orange,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>,Mix<Int<16000>,Gradient<Orange,Red>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>> > >,
// //             ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>,
// //         300,500,White>
// //     >(),
// //     StylePtr<Black>(),
// // "darth\nmaul"},


// { "NebulaSS;common", "tracks/RebelsTheme.wav",  ///font sucks

//     StylePtr< // purple 
//         InOutSparkTip<
//             Layers< 
                
//                     Blast<
//                         LocalizedClash<
//                             TransitionEffect<
//                                 TransitionEffect<
//                                     TransitionEffect<
//                                         TransitionEffect<
//                                             TransitionEffect<
//                                                 HumpFlicker<Rgb<125,30,255>, Rgb<60,0,255>,50>,
//                                             StyleFire<White,Rgb<120,40,255>,0,6>,TrInstant,TrSmoothFade<1600>,EFFECT_IGNITION>,
//                                         Mix<Bump<Int<32768>,Int<30000>>,BrownNoiseFlicker<Rgb<120,40,255>,RandomPerLEDFlicker<Rgb<15,2,50>,Rgb<30,5,85>>,200>,RandomPerLEDFlicker<Strobe<OrangeRed,White,30,10>,Yellow>>,TrWipeIn<500>,TrFade<600>,EFFECT_STAB>,
//                                     Black,TrConcat<TrInstant,HumpFlicker<White,Rgb<120,40,255>,40>,TrColorCycle<600>>,TrInstant,EFFECT_RETRACTION>,
//                                 Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
//                             Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<80>,EFFECT_BLAST>,
//                         BrownNoiseFlicker<Yellow,DarkOrange,400>,100,50,EFFECT_CLASH>,         
//                     TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                
//             BCResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,OrangeRed,50>,10>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,300>>,
//             BCResponsiveDragL<Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>>,
//             BCResponsiveMeltL<  Mix<TwistAngle<>, Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Rgb<150,0,0>,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,OrangeRed,Orange,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>,Mix<Int<16000>,Gradient<Orange,Red>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>> > >,
//             ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>,
//         300,800,White>
//     >(),                 
//     // StylePtr<
//     //     InOutHelper<
//     //         Blast<
//     //             LocalizedClash<
//     //                 Lockup<
                        
//     //                         TransitionEffect<
//     //                             TransitionEffect<
//     //                                 TransitionEffect<
//     //                                     TransitionEffect<
//     //                                         TransitionEffect<    
//     //                                             TransitionEffect<
//     //                                                 HumpFlicker<Rgb<125,30,255>, Rgb<60,0,255>,50>,
//     //                                             Mix<Bump<Int<32768>,Int<30000>>,BrownNoiseFlicker<Rgb<120,40,255>,RandomPerLEDFlicker<Rgb<15,2,50>,Rgb<30,5,85>>,200>,RandomPerLEDFlicker<OrangeRed,White>>,TrConcat<TrWipeIn<500>,Mix<Bump<Int<32768>,Int<30000>>,BrownNoiseFlicker<Rgb<120,40,255>,RandomPerLEDFlicker<Rgb<15,2,50>,Rgb<30,5,85>>,100>,RandomPerLEDFlicker<Orange,White>>,TrInstant>,TrFade<450>,EFFECT_STAB>,
//     //                                         Black,TrConcat<TrInstant,HumpFlicker<White,Rgb<120,40,255>,40>,TrColorCycle<600>>,TrInstant,EFFECT_RETRACTION>,
//     //                                     White,TrInstant,TrSmoothFade<200>,EFFECT_LOCKUP_BEGIN>,
//     //                                 StyleFire<Rgb<120,40,255>,White,0,6>,TrInstant,TrSmoothFade<500>,EFFECT_LOCKUP_END>,
//     //                             Mix<Bump<Int<32768>,Int<10000>>,StyleFire<BrownNoiseFlicker<Rgb<120,40,255>,RandomPerLEDFlicker<Rgb<15,2,50>,Rgb<30,5,85>>,200>,Rgb<40,8,100>,0,6,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,White>,TrInstant,TrFade<200>,EFFECT_DRAG_BEGIN>,
//     //                         Mix<Bump<Int<32768>,Int<10000>>,StyleFire<BrownNoiseFlicker<Rgb<120,40,255>,RandomPerLEDFlicker<Rgb<15,2,50>,Rgb<30,5,85>>,200>,Rgb<40,8,100>,0,6,FireConfig<10,1000,2>,FireConfig<4000,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>,White>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,
                        
//     //                 Pulsing<Gradient<Rgb<120,40,255>,BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>>,Gradient<BrownNoiseFlicker<White,Strobe<Blue,White,50,1>,100>,Rgb<120,40,255>>,3500>,RandomPerLEDFlicker<Rgb<120,40,255>,White>,Bump<Int<16000>,Int<20000>>,Bump<Int<32768>,Int<10000>>>,
//     //             BrownNoiseFlicker<White,DarkOrange,400>,100,75,EFFECT_CLASH>,
//     //         TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
//     //     300,800,Black>
//     // >(),
    
//     StylePtr<Black>(),
// "nebula"},



{ "Nextor;common", "tracks/StarWarsTheme.wav", 

  // Fett263 Fully Responsive AudioFlicker (Color Swing) Jedi/Sith Neopixel Lightsaber Styles Jedi DarkOrange Default

StylePtr<
    InOutTr<
        Layers<
            Blast<
                LocalizedClash<
                    TransitionEffect<
                        TransitionEffect<   
                            TransitionEffect<
                                TransitionEffect<    
                                    TransitionEffect<
                                            Mix<SwingSpeed<400>,AudioFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<128,34,0>>>,
                                            Mix<SwingSpeed<600>,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Orange>>>,
                                    Mix<Bump<Int<32768>,Int<30000>>,BrownNoiseFlicker<Rgb<120,40,255>,RandomPerLEDFlicker<Rgb<15,2,50>,Rgb<30,5,85>>,200>,RandomPerLEDFlicker<Strobe<OrangeRed,White,30,10>,Yellow>>,TrWipeIn<500>,TrFade<600>,EFFECT_STAB>,
                                StyleFire<White,Rgb<120,40,255>,0,6>,TrInstant,TrSmoothFade<1600>,EFFECT_IGNITION>,
                            Black,TrConcat<TrInstant,HumpFlicker<White,Rgb<120,40,255>,40>,TrColorCycle<600>>,TrInstant,EFFECT_RETRACTION>,
                        Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<80>,EFFECT_BLAST>,
                    Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
                BrownNoiseFlicker<White,DarkOrange,400>,100,75,EFFECT_CLASH>,
            TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
        
        TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
        ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,White,TrFade<200>>,TrFade<400>>,
        BCResponsiveDragL<BrownNoiseFlickerL<White,Int<300>>,TrWipeIn<400>,TrFade<400>>,
        ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
        BCResponsiveMeltL<Mix<TwistAngle<>,OrangeRed,Orange>,TrWipeIn<600>,TrSmoothFade<600>>>,
    TrWipeSparkTip<White,300>,TrWipeIn<500>,
    Layers<Black,TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,
        AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
        TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>>>
>(),
    StylePtr<Black>(),
"nextor"}, 


{ "NiteSist;common", "tracks/Sister1.wav", 
  StylePtr<   // Sith Red os4
        InOutSparkTip<  
            Layers< 
                OnSpark<    
                    Blast<  
                        LocalizedClash< 
                            TransitionEffect<
                                TransitionEffect<
                                    TransitionEffect<   
                                        TransitionEffect<     
                                            HumpFlicker<Red,Rgb<128,0,0>,15>,
                                        Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                                    Mix<Bump<Int<0>,Int<4000>>,HumpFlicker<Red,Rgb<128,0,0>,15>,White>,TrConcat<TrDelay<175>,HumpFlicker<Red,Rgb<128,0,0>,15>,TrSmoothFade<250>>,TrWipeIn<180>,EFFECT_RETRACTION>,
                                Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
                            Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<70>,EFFECT_BLAST>,
                        BrownNoiseFlicker<BrownNoiseFlicker<White,DeepSkyBlue,50>,Strobe<Strobe<Red,White,15,20>,White,15,10>,75>,110,60,EFFECT_CLASH>,
                    TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                White,225>,                                     
            BCResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,300>>,
            BCResponsiveDragL<Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>>,
            BCResponsiveMeltL<  Mix<TwistAngle<>, Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Rgb<150,0,0>,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,OrangeRed,Orange,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>,Mix<Int<16000>,Gradient<Orange,Red>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>> > >,
            ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>, 
        300,500,White>
    >(),
    StylePtr<Black>(),
"assaj\nventress"},   
  

{ "PitchBlk;common", "MSV.wav", //Fernando offer1

    StylePtr<   
        InOutTr<    
            Layers<
                Blast<
                    TransitionEffect<
                        TransitionEffect<
                            TransitionEffect<
                                LocalizedClash<
                                                Blue, 
                                BrownNoiseFlicker<Yellow,White,500>, 110,50>,
                            Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
                        Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<70>,EFFECT_BLAST>,                                
                    Mix<Bump<Int<32768>,Int<16000>>,Gradient<Blue,Blue,DodgerBlue,DeepSkyBlue,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Blue,White,15,20>,GreenYellow,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                TransitionEffect<GreenYellow,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,800>,
            AudioFlickerL<Rgb<0,0,128>>,
            BCResponsiveLockupL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>>>,
            BCResponsiveDragL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>>>,
            BCResponsiveMeltL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1> >>,
            ResponsiveLightningBlockL<BrownNoiseFlicker<Strobe<Rgb<60,0,255>,White,15,1>,DeepSkyBlue,500>>>,
        TrWipe<300>,TrWipeIn<450>,TransitionEffect<Black,Black,TrConcat<TrSmoothFade<100>,
        Mix<Bump<Int<0>,Int<1500>>,Black,Sparkle<Rgb<128,128,128>>>,TrSmoothFade<2500>,
        Mix<Bump<Int<0>,Int<1600>>,Black,Sparkle<Orange>>,TrSmoothFade<2200>,
        Mix<Bump<Int<0>,Int<1350>>,Black,Sparkle<OrangeRed,White,200>>,TrSmoothFade<1700>,
        Mix<Bump<Int<0>,Int<1100>>,Black,Sparkle<Rgb<100,0,0>,White,200>>,TrSmoothFade<1300>>,TrInstant,EFFECT_RETRACTION>>           //emitter cooldown
    >(),
  StylePtr<Black>(),
"pitch\nblack"},

{ "Proto1;common", "tracks/venus.wav",    
    // Fully Responsive Kylo Ren Unstable (Unstable Swing) Styles - Jedi Silver - OS4.x
    StylePtr<
        InOutTr<
            Layers<
                Blast<
                    Mix<SwingSpeed<310>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<7,7,15>>,RotateColorsX<Variation,Rgb<17,17,36>>>,300>,RotateColorsX<Variation,Rgb<22,22,47>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
                                        StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<7,7,15>>,300>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<10,0,0>>>,0,8,FireConfig<10,1200,1>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>>,
                TransitionEffect<GreenYellow,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,800>,
            ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
            ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,White,TrFade<200>>,TrFade<400>>,
            ResponsiveDragL<BrownNoiseFlickerL<White,Int<300>>,TrWipeIn<400>,TrFade<400>>,
            ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
            ResponsiveMeltL<Mix<TwistAngle<>,OrangeRed,Orange>,TrWipeIn<600>,TrSmoothFade<600>>,AlphaL<TransitionEffect<White,Rgb<128,0,0>,TrInstant,TrConcat<TrFade<1500>,Red,TrFade<2000>,Orange,TrFade<2500>>,EFFECT_IGNITION>,
            Bump<Int<0>,Int<6000>>>,
            
            
        TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<800>>,EFFECT_IGNITION>,
        TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>>,
        TrWipe<300>,TrWipeIn<500>,Layers<Black,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<800>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<800>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<800>>,EFFECT_RETRACTION>>>
    >(),
    StylePtr<Black>(),
"proto 1"},


{ "Savage;common", "tracks/Sister2.wav", 
     StylePtr<InOutHelper<RotateColorsX<Variation,Rgb<255,0,0>>,300,500>>(),
    StylePtr<Black>(),
"savage\nopress"},


{ "SavageKsith;common", "tracks/Sister2.wav", 
    StylePtr<   // Sith Red os4
        InOutSparkTip<  
            Layers< 
                OnSpark<    
                    Blast<  
                        LocalizedClash< 
                            TransitionEffect<
                                TransitionEffect<
                                    TransitionEffect<   
                                        TransitionEffect<     
                                            HumpFlicker<
                                                RotateColorsX<Variation,Rgb<255,160,0>>,RotateColorsX<Variation,Rgb<84,60,0>>,40>,
                                        Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                                    Mix<Bump<Int<0>,Int<4000>>,HumpFlicker<Red,Rgb<128,0,0>,15>,White>,TrConcat<TrDelay<175>,HumpFlicker<Red,Rgb<128,0,0>,15>,TrSmoothFade<250>>,TrWipeIn<180>,EFFECT_RETRACTION>,
                                Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
                            Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<70>,EFFECT_BLAST>,
                        BrownNoiseFlicker<BrownNoiseFlicker<White,DeepSkyBlue,50>,Strobe<Strobe<Red,White,15,20>,Yellow,15,10>,75>,120,50,EFFECT_CLASH>,//color more yellow
                    TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                White,225>,                                     
            BCResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,300>>,
            BCResponsiveDragL<Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>>,
            BCResponsiveMeltL<  Mix<TwistAngle<>, Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Rgb<150,0,0>,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,OrangeRed,Orange,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>,Mix<Int<16000>,Gradient<Orange,Red>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>> > >,
            ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>, 
        300,666,White>
    >(),
    StylePtr<Black>(),
"savage\nksith"},


//   { "SenatMaj;common", "tracks/Palpatheme_SHORT.wav",      // Troy Huang Palpatine / Sidiuos
//     //StylePtr<InOutSparkTip<OnSpark<Blast<LocalizedClash<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<Lockup<Mix<SwingSpeed<500>,AudioFlicker<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,Pulsing<Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,RandomFlicker<Red,OrangeRed>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<OrangeRed,Red>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,2000>,RandomPerLEDFlicker<Red,Yellow>>,Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Red,Rgb<128,0,0>>,Yellow>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,Gradient<Orange,Orange,White>,TrSmoothFade<50>,TrWipeIn<50>,EFFECT_DRAG_BEGIN>,Gradient<White,DeepSkyBlue,LightPink,DeepSkyBlue,White>,TrJoinR<TrWipe<100>,TrWipeIn<100>>,TrSmoothFade<100>,EFFECT_LOCKUP_END>,White,TrBoing<50,2>,TrFade<30>,EFFECT_LOCKUP_BEGIN>,Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,BrownNoiseFlicker<White,DarkOrange,400>,100,75>,TransitionEffect<Blue,White,TrWipe<1>,TrWipe<75>,EFFECT_BLAST>,400,250,800>,BrownNoiseFlicker<Black,Orange,400>,500>,300,800>>(),
//     //Layer ver
//     StylePtr<   
//         RetractionDelay<1100,   
//             InOutSparkTip<  
//                 Layers< 
//                     OnSpark<    
//                         Blast<  
//                             LocalizedClash<
//                                 TransitionEffect<
//                                     TransitionEffect<
//                                         TransitionEffect<
//                                             TransitionEffect<  
//                                                     Mix<SwingSpeed<800>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,
//                                                     AudioFlicker<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red,Red,Red,Red,Red,Red,Red,Red>,Rgb<100,0,0>>>,                                                                                                                                                                    
//                                             Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
//                                         Mix<Bump<Int<0>,Int<6000>>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,White>,TrConcat<TrDelay<175>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,TrSmoothFade<250>>,TrWipeIn<180>,EFFECT_RETRACTION>,
//                                     Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
//                                 Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<70>,EFFECT_BLAST>,
//                             BrownNoiseFlicker<White,DarkOrange,400>,100,75,EFFECT_CLASH>,
//                         TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
//                     BrownNoiseFlicker<Black,Orange,400>,500>,
//                 BCResponsiveLockupL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe< Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>>>,
//                 BCResponsiveDragL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>>>,
//                 BCResponsiveMeltL<Gradient<RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>>>,
//                 ResponsiveLightningBlockL<BrownNoiseFlicker<Strobe<Rgb<60,0,255>,White,15,1>,DeepSkyBlue,500>>>,
//             300,800,White>
//         >
//     >(),
//     StylePtr<Black>(),
// "senate\nmajority"},  


{ "SHATTERPOINT;common", "tracks/mars.wav",
        StylePtr<InOutHelper<RotateColorsX<Variation,Rgb<255,0,0>>,300,500>>(),
   
    StylePtr<Black>(),
"shatter\npoint"},


{ "Strkllr1;common", "tracks/Starkillers_Theme.wav", // 666 in
     StylePtr<   // Sith Red os4
        InOutSparkTip<  
            Layers< 
                OnSpark<    
                    Blast<  
                        LocalizedClash< 
                            TransitionEffect<
                                TransitionEffect<
                                    TransitionEffect<   
                                        TransitionEffect<     
                                            HumpFlicker<Red,Rgb<128,0,0>,15>,
                                        Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                                    Mix<Bump<Int<0>,Int<4000>>,HumpFlicker<Red,Rgb<128,0,0>,15>,White>,TrConcat<TrDelay<175>,HumpFlicker<Red,Rgb<128,0,0>,15>,TrSmoothFade<250>>,TrWipeIn<180>,EFFECT_RETRACTION>,
                                Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
                            Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<70>,EFFECT_BLAST>,
                        BrownNoiseFlicker<BrownNoiseFlicker<White,DeepSkyBlue,50>,Strobe<Strobe<Red,White,15,20>,Yellow,15,10>,75>,120,50,EFFECT_CLASH>,//color more yellow
                    TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                White,225>,                                     
            BCResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,300>>,
            BCResponsiveDragL<Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>>,
            BCResponsiveMeltL<  Mix<TwistAngle<>, Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Rgb<150,0,0>,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,OrangeRed,Orange,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>,Mix<Int<16000>,Gradient<Orange,Red>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>> > >,
            ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>, 
        300,666,White>
    >(),
    StylePtr<Black>(),
"starkiller"},



// { "ScavngrsDstny;common", "ScavngrsDstny/tracks/track4edit",
// // // Fett263 Light-Side AudioFlicker Style with "Responsive Blade" and Full Transitions
// // // Gold main blade:
// // // V1 
// // // StylePtr<   IgnitionDelay<300,InOutHelper<  Blast<  LocalizedClash< Lockup< TransitionEffect<   TransitionEffect<   TransitionEffect<   TransitionEffect<   TransitionEffect<   TransitionEffect<   TransitionEffect<
// // //                                                                                                                                                                                                                     Mix<SwingSpeed<400>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,
// // //                                                                                                                                                                                                                     Mix<SwingSpeed<600>,Rgb<255,160,0>,BlanchedAlmond>>,StyleFire<Rgb<255,160,0>,BlanchedAlmond,0,6>,TrInstant,TrSmoothFade<800>,EFFECT_IGNITION>,
// // //     Mix<Bump<Int<32768>,Int<16000>>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,RandomPerLEDFlicker<OrangeRed,White>>,TrConcat<TrWipeIn<600>,Mix<Bump<Int<32768>,Int<16000>>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,RandomPerLEDFlicker<Orange,White>>,TrWipe<600>>,TrInstant,EFFECT_STAB>,
// // //     Mix<Bump<Int<0>,Int<48000>>,Stripes<1000,1500,Rgb<255,160,0>,BrownNoiseFlicker<White,Rgb<255,160,0>,300>>,Stripes<1000,-1500,Rgb<255,160,0>,BrownNoiseFlicker<White,Rgb<255,160,0>,300>>>,TrInstant,TrSmoothFade<500>,EFFECT_LOCKUP_BEGIN>,
// // //     Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,White>,TrInstant,TrFade<200>,EFFECT_DRAG_BEGIN>,
// // //     Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,White>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,
// // //     Black,TrConcat<TrInstant,HumpFlicker<White,BrownNoiseFlicker<Rgb<255,160,0>,Rgb<0,0,40>,400>,40>,TrColorCycle<600>>,TrInstant,EFFECT_RETRACTION>,
// // //     Mix<Bump<Int<0>,Int<44000>>,Mix<Bump<Int<32768>,Int<44000>>,TransitionEffect<Rgb<255,160,0>,White,TrInstant,TrFade<300>,EFFECT_LOCKUP_END>,
// // //     Stripes<1000,-1500,Rgb<255,160,0>,BrownNoiseFlicker<White,Rgb<255,160,0>,300>>>,Stripes<1000,1500,Rgb<255,160,0>,BrownNoiseFlicker<White,Rgb<255,160,0>,300>>>,TrInstant,TrSmoothFade<800>,EFFECT_LOCKUP_END>,
// // //     Pulsing<Gradient<AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>>,Gradient<BrownNoiseFlicker<White,Strobe<Red,White,50,1>,100>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>>,3500>,RandomPerLEDFlicker<AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,White>,Bump<Int<16000>,Int<16000>>,Bump<Int<32768>,Int<10000>>>,White>,White>,
// // //                         150,300,Black>>
// // // >(),
// // // V2
// // StylePtr<   
// //     IgnitionDelay<300,  
// //         InOutHelper<    
// //             Layers< 
// //                 LocalizedClash< 
// //                     Blast<  
// //                         TransitionEffect<
// //                             TransitionEffect<   
// //                                 TransitionEffect<
// //                                    Mix<SwingSpeed<400>,AudioFlicker<Rgb<255,160,0>,Rgb<84,60,0>>,Mix<SwingSpeed<600>,Rgb<255,160,0>,BlanchedAlmond>>,
// //                                 StyleFire<Rgb<255,160,0>,BlanchedAlmond,0,6>,TrInstant,TrSmoothFade<800>,EFFECT_IGNITION>,
// //                             Mix<Bump<Int<32768>,Int<16000>>,Gradient<BlanchedAlmond,Rgb<255,160,0>,Rgb<200,120,0>,LightYellow,White>,RandomPerLEDFlicker<AudioFlicker<Rgb<255,160,0>,White>,DarkOrange>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
// //                         Gradient<White,LightYellow,Rgb<255,160,0>,Rgb<255,160,0>,Rgb<255,160,0>,Rgb<255,160,0>,Rgb<255,160,0>,Rgb<255,160,0>,Rgb<255,160,0>>,TrSmoothFade<800>,TrWipeIn<180>,EFFECT_RETRACTION>,
// //                     TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
// //                 BrownNoiseFlicker<DarkOrange,White,200>,90,60>,
// //             BCResponsiveLockupL<Gradient<Red,RandomFlicker<OrangeRed,Red>,Strobe<BrownNoiseFlicker<Red,White,300>,BrownNoiseFlicker<Red,Strobe<Black,Orange,25,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>,Red>>,
// //             BCResponsiveDragL<BrownNoiseFlicker<Red,Strobe<Orange,White,15,10>,500>>,
// //             BCResponsiveMeltL<BrownNoiseFlicker<Red,Strobe<Orange,White,15,10>,500>>,
// //             ResponsiveLightningBlockL<BrownNoiseFlicker<Strobe<Rgb<60,0,255>,White,15,1>,DeepSkyBlue,500>>>,
// //         150,300,Black>
// //     >
// // >(),
// // V3 Fully Responsive Rey's Gold Blade with Emitter Spark (Color Swing)
// StylePtr<InOutTr<Layers<Mix<SwingSpeed<400>,AudioFlicker<RotateColorsX<Variation,Rgb<255,160,0>>,RotateColorsX<Variation,Rgb<84,60,0>>>,Mix<SwingSpeed<600>,RotateColorsX<Variation,Rgb<255,160,0>>,RotateColorsX<Variation,BlanchedAlmond>>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Blue,SteelBlue>,Bump<Int<0>,Int<9000>>>,TrFade<600>>,EFFECT_IGNITION>,ResponsiveBlastL<White>,ResponsiveClashL<White,TrInstant,TrFade<400>>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,White,TrFade<200>>,TrFade<400>>,ResponsiveDragL<BrownNoiseFlickerL<White,Int<300>>,TrWipeIn<400>,TrFade<400>>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveMeltL<Mix<TwistAngle<>,OrangeRed,Orange>,TrWipeIn<600>,TrSmoothFade<600>>>,TrWipe<150>,TrWipeIn<300>,Black>>(),   
// // Rey yellow NPXL startup cycle
//     StylePtr<ColorCycle<TransitionEffect<Blue,Green,TrWipe<400>,TrWipe<5000>,EFFECT_IGNITION>,0,1,AudioFlicker<Rgb16<64410,48313,1>,Yellow>,100,3000,500>>(), 
// "scavengers\ndestiny"},




{ "Vader;common", "tracks/Imperial March ROTJ 3_long.wav", 
    StylePtr<   //Sith Red Vader style
        InOutHelper<  
            Layers<
                OnSpark<
                    Blast<  
                        LocalizedClash< 
                            TransitionEffect<    
                                TransitionEffect<
                                    TransitionEffect<
                                        TransitionEffect<
                                            HumpFlicker<Red,Rgb<128,0,0>,15>,                 
                                        Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,
                                    Mix<Bump<Int<0>,Int<4000>>,HumpFlicker<Red,Rgb<128,0,0>,15>,White>,TrConcat<TrDelay<175>,HumpFlicker<Red,Rgb<128,0,0>,15>,TrSmoothFade<250>>,TrWipeIn<180>,EFFECT_RETRACTION>,
                                Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<50>,EFFECT_CLASH>,
                            Strobe<GreenYellow,Black,20,30>,TrInstant,TrFade<70>,EFFECT_BLAST>,
                        Strobe<Yellow,Black,20,15>,110,60,EFFECT_CLASH>,
                    TransitionEffect<Blue,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,500>,
                White,250>, 
            BCResponsiveLockupL<BrownNoiseFlicker<HumpFlicker<BrownNoiseFlicker<White,Black,900>,BrownNoiseFlicker<White,DeepSkyBlue,50>,10>,Strobe<Strobe<Red,Yellow,15,20>,Yellow,15,10>,300>>,
            BCResponsiveDragL<Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>>,
            BCResponsiveMeltL<  Mix<TwistAngle<>, Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Rgb<150,0,0>,OrangeRed,Orange,Mix<Int<25000>,White,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,OrangeRed,Orange,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>,Mix<Int<16000>,Gradient<Orange,Red>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>> > >,
            ResponsiveLightningBlockL<BrownNoiseFlicker<White,Pulsing<Blue,Rgb<125,30,255>,200>,500>>>, 
        400,650>
    >(),
 StylePtr<Black>(),
"rogue\nvader"}, 


{ "VnlaDark;common", "tracks/JFO8.wav",  
    //Fully Responsive Darksaber Style with SwingSpeed   
    StylePtr<   InOutTr<    Layers<
                                    AudioFlicker<
                                        BrownNoiseFlicker<
                                            Mix<SwingSpeed<400>,RotateColorsX<Variation,Rgb<120,100,150>>,RotateColorsX<Variation,Rgb<170,150,225>>>,
                                        Stripes<5000,-300,RotateColorsX<Variation,Rgb<35,25,55>>,RotateColorsX<Variation,Rgb<90,75,120>>,RotateColorsX<Variation,Rgb<15,10,20>>,RotateColorsX<Variation,Rgb<60,50,75>>>,300>,RotateColorsX<Variation,Rgb<45,35,75>>>,
                            ResponsiveBlastL<White>,ResponsiveClashL<White,TrInstant,TrFade<400>>,ResponsiveStabL<Orange,TrWipeIn<600>,TrWipe<600>>,
                                TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
                            ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Blue,300>,50,1>,TrConcat<TrInstant,White,TrFade<200>>,TrFade<400>>,
                            ResponsiveDragL<BrownNoiseFlickerL<White,Int<300>>,TrWipeIn<400>,TrFade<400>>,
                            ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
                            ResponsiveMeltL<Mix<TwistAngle<>,OrangeRed,Orange>,TrWipeIn<600>,TrSmoothFade<600>>>,
                TrWipe<300>,TrWipeIn<600>,Black>
    >(),
    StylePtr<Black>(),
"vanilla\ndark"},  



            
// { "testfont;common", "tracks/DuelOfTheFates.wav",
    //StylePtr<InOutHelperX<Gradient<Blue, Blue, Green, Yellow, Orange, Red, Red>, Scale<SmoothSoundLevel,Int<0>,Int<100000>>>>(),                  // VU meter works!
    // StylePtr<Black>(),
    // "testfont"},



{ "BattLevl;common", "",
     &style_charging,
     StylePtr<Black>(),
"battery\nlevel"},

// { "LngthFnd;common", "",
//     StylePtr<LengthFinder<>>(),
//     StylePtr<Black>(),
// "length\nfinder"},
            
{ "testfont;common", "testfont/tracks/track01.wav",
    StylePtr<InOutHelper<Red,300,500>>(),                  
    StylePtr<Black>(),
"testfont\nhi brian"},
            
{ "testfont;common", "testfont/tracks/track01.wav",
    StylePtr<InOutHelper<Hue<1412/3>,300,500>>(),                  
    StylePtr<Black>(),
"testfont\nhi brian"},

};

//----------------------------------------------------------------------------------------------------------------------------------------
Preset noblade[] = {

// // Try Sparkle<Red> as accents style

{ "NiteSist;common", "tracks/Sister1.wav", 
    StylePtr<Black>(),
    StylePtr<SimpleClash<Lockup<Blast<ColorCycle<Red,20,50,BrownNoiseFlicker<Red,Rgb16<14386,0,0>,500>,100,200,800>,White,200,600>,AudioFlicker<Rgb<255,100,100>,White>,AudioFlicker<Rgb<255,100,100>,White>,Int<32768>,Int<32768>>,White,50,EFFECT_CLASH,Int<32768>>>(),
"assaj\nventress"},   


{ "Calibr8;common", "tracks/ObiWan1.wav",    
    StylePtr<Black>(),
    StylePtr<ColorCycle<Pulsing<Blue,Sparkle<Cyan,White,100>,1500>,75,30,Stripes<1000,1000,Cyan,DodgerBlue,White,Black>,60,250,2000>>(),
"calibrate"},  

  
// { "Mauler;common", "tracks/DuelOfTheFates.wav",      // Troy Huang Palpatine / Sidiuos
//     //StylePtr<InOutSparkTip<OnSpark<Blast<LocalizedClash<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<Lockup<Mix<SwingSpeed<500>,AudioFlicker<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,Pulsing<Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,RandomFlicker<Red,OrangeRed>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<OrangeRed,Red>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,2000>,RandomPerLEDFlicker<Red,Yellow>>,Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Red,Rgb<128,0,0>>,Yellow>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,Gradient<Orange,Orange,White>,TrSmoothFade<50>,TrWipeIn<50>,EFFECT_DRAG_BEGIN>,Gradient<White,DeepSkyBlue,LightPink,DeepSkyBlue,White>,TrJoinR<TrWipe<100>,TrWipeIn<100>>,TrSmoothFade<100>,EFFECT_LOCKUP_END>,White,TrBoing<50,2>,TrFade<30>,EFFECT_LOCKUP_BEGIN>,Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,BrownNoiseFlicker<White,DarkOrange,400>,100,75>,TransitionEffect<Blue,White,TrWipe<1>,TrWipe<75>,EFFECT_BLAST>,400,250,800>,BrownNoiseFlicker<Black,Orange,400>,500>,300,800>>(),
//     //Layer ver
//     StylePtr<Black>(),
//     StylePtr<SimpleClash<Lockup<Blast<ColorCycle<Red,20,50,BrownNoiseFlicker<Red,Rgb16<14386,0,0>,500>,100,200,800>,White,200,600>,AudioFlicker<Rgb<255,100,100>,White>,AudioFlicker<Rgb<255,100,100>,White>,Int<32768>,Int<32768>>,White,50,EFFECT_CLASH,Int<32768>>>(),
// "darth\nmaul"},



// { "ObiWan;common", "tracks/ObiWan1.wav",   
//     StylePtr<Black>(),
//    StylePtr<SimpleClash<Lockup<Blast<ColorCycle<Pulsing<DodgerBlue,Rgb16<3,1053,20996>,2500>,15,40,RandomPerLEDFlicker<DodgerBlue,DeepSkyBlue>,100,200,800>,White,200,600>,AudioFlicker<Rgb<255,100,100>,White>,AudioFlicker<Rgb<255,100,100>,White>,Int<32768>,Int<32768>>,White,50,EFFECT_CLASH,Int<32768>>>(),
// "obi-wan\nkenobi"},  

// { "testfont;common", "tracks/uranus.wav",
//     StylePtr<InOutHelper<SimpleClash<Lockup<Blast<RotateColorsX<Sin<Int<10>>,Red>,White>,AudioFlicker<Blue,White>>,White>,300,800>>(),
//     StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
// "testfont"},



{ "BattLevl;common", "tracks/mars.wav",
     StylePtr<Black>(),
     &style_charging,     
"battery\nlevel"},

};


BladeConfig blades[] = {

{ NO_BLADE, // blade=0 //                               D1_data_line = proffie_D1 ---> NPXL ctrpin ---> Open when no blade 
            //                                          D3_data_line = proffie_D3 ---> BP pin --->LED NEG when blade in        
  WS281XBladePtr<0, bladePin,  Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs
CONFIGARRAY(noblade),
"00_NO_BLADEsave", }, // Make NPXL do cool shit when no blade in.


{ 0,     //blade=1 // 7/8" Ventress_A                D1_data_line = proffie_D1 ---> Switch ---> NPXL ctrpin---> bladePCB 330ohm ---> Main blade strips
            //                                                                             \ Battery NEG for charging
            //                                          D3_data_line = proffie_D3 ---> BP pin --->LED NEG when blade in
  WS281XBladePtr<130, bladePin,  Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                 ////////////////////////////////////////////CHANGE WHEN BC MADE BLADE.....IS MADE.
  WS281XBladePtr<5,   blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // D2_data_line = proffie_D2 ---> NPXL_D2pin---> 470ohm---> 5LEDs
CONFIGARRAY(AllBlades),
"01_AllBladessave", }, 


};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
