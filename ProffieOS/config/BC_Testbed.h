// HiltPCB_test
// adjust for either 1.5 or 2.2 board!!

#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 1
#define VOLUME 1000
#define BOOT_VOLUME 100
const unsigned int maxLedsPerStrip = 144;
#define EXTRA_COLOR_BUFFER_SPACE 30               // New define that can speed up processing a bit. Basically, it can calculate the colors for the next blade (or the next frame for the same blade) even though it's not done feeding out the data for the data in the color buffer yet.
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL //Bluetooth or UART TTL (make_default_console if TTL) baud 115200
#define ENABLE_SSD1306 //OLED
#define SHARED_POWER_PINS
#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    // #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING     // upload overwrites presets.ini/tmp unless this is defined
//#define BLADE_DETECT_PIN blade3Pin
// #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000> // if pullup resistor on v2.2 board btw data1 and 3.3v pads
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> // This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors 
//                         Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value, so I would recommend using something like 200000 instead of NO_BLADE.
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                    // SPDIF out
#define ENABLE_DEVELOPER_COMMANDS
// #define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SDA_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE
// #define ORIENTATION_ROTATION 0,-20,0
//changes the angle required to register twists on curved hilts
//example is for assaj ventress curved hit install

// #define CONFIG_STARTUP_DELAY 15000              // BC now canon
#define FEMALE_TALKIE_VOICE                       // BC now canon
// #define VOLUME_MENU_CYCLE                         // BC prop - REMOVED - Quick MAX and MIN instead for OS7. (Jan 2023)
#define NO_REPEAT_RANDOM                          // BC now canon

// ------- OLED stuff ----------

#define ENABLE_SSD1306                            // OLED
//#define OLED_FLIP_180                             // BC now canon
//#define OLED_MIRRORED
// #define USE_AUREBESH_FONT                      // BC now canon
#define OLED_SYNCED_EFFECTS
// #define PLI_OFF_TIME 60 * 5 * 1000

// ------- Gesture stuff -------

#define BC_SWING_ON
#define BC_SWING_ON_SPEED 250
// #define BC_STAB_ON
#define BC_THRUST_ON
// #define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS 
#define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200

// ------- Custom / Experimental / Alpha-Beta stuff ---------

#define DISABLE_BASIC_PARSER_STYLES               // Standard, Advanced, etc...
// #define NO_VOLUME_MENU 
//#define NO_BLADE_NO_GEST_ONOFF                    // If using blade detect, No Blade = No Gesture ignitions or retractions
//#define AUTO_HUMSTART               now dead ProffieOShumDelay instead               // 200ms delay from on.wav beginning all the time.             **Requires modified hybrid_font.h file.
#define ENABLE_AUTO_SPINS_BLAST                   // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define LOW_BATT_ONCE                          // No repeated warnings
// #define LOW_BATT_WARNINGS_TIERED                // meh...just annoying if not accurate..likely.                                                            **Requires modified hybrid_font.h file.
// #define ENABLE_GESTURE_MENU                    // PSISTORM prop - cool stuff! the TrySound else beep void.

#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8

//#define POV_INCLUDE_FILE "Pretend_data.h"

// ---------Edit Mode Stuff -------------
// #define BC_EDIT_MODE_MENU
// #define ENABLE_ALL_EDIT_OPTIONS                   // Fett263 OS 6
//     // #define DYNAMIC_BLADE_LENGTH
//     // #define DYNAMIC_BLADE_DIMMING
//     // #define DYNAMIC_CLASH_THRESHOLD
//     // #define SAVE_VOLUME
//     // #define SAVE_BLADE_DIMMING
//     // #define SAVE_CLASH_THRESHOLD
//     // #define SAVE_COLOR_CHANGE
// #define BC_SAY_COLOR_LIST
// #define BC_SAY_COLOR_LIST_CC


#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
//#include "../scripts/motion_startup_recorder.h"
#endif


#ifdef CONFIG_PRESETS

// #include "aliases/TrueWhites/BC_effects_1.h"
// #include "aliases/TrueWhites/BC_effects_2.h"
// #include "aliases/TrueWhites/BC_effects_Red.h"
// #include "aliases/TrueWhites/BC_effects_White.h"

//   TransitionEffectL<TrConcat<TrInstant,Red,TrWipe<2000>>,EFFECT_USER1>,
//   TransitionEffectL<TrConcat<TrInstant,Orange,TrWipe<2000>>,EFFECT_USER2>,
//   TransitionEffectL<TrConcat<TrInstant,Yellow,TrWipe<2000>>,EFFECT_USER3>,
//   TransitionEffectL<TrConcat<TrInstant,Green,TrWipe<2000>>,EFFECT_USER4>,
//   // User Effects when OFF
//   TransitionEffectL<TrConcat<TrInstant,Blue,TrWipe<2000>>,EFFECT_USER5>,
//   TransitionEffectL<TrConcat<TrInstant,ElectricViolet,TrWipe<2000>>,EFFECT_USER6>,
//   TransitionEffectL<TrConcat<TrInstant,White,TrWipe<2000>>,EFFECT_USER7>,
//   TransitionEffectL<TrConcat<TrInstant,Rainbow,TrWipe<2000>>,EFFECT_USER8>,


// Preset AllBlades [] = {
// // { "testfont2b", "testfont2b/tracks/track2.wav",

// { "sine", "testfont2b/tracks/track2.wav",
// //    StylePtr<ColorSequence<1500,Red,Green,Blue,Black,White,Rainbow>>(),
//   StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RotateColorsX<Variation,SteelBlue>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelay<800>>,EFFECT_PREON>>>(),
//   StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RotateColorsX<Variation,SteelBlue>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelay<800>>,EFFECT_PREON>>>(),
//   StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RotateColorsX<Variation,SteelBlue>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelay<800>>,EFFECT_PREON>>>(),
 
//   //StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
// // ,
// // StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
// // StylePtr<Layers<
// //   TransitionLoop<Black,TrConcat<TrWipe<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipe<1000>,Black,TrConcat<TrWipeIn<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipeIn<1000>>>>,
// //   TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
// //   LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
// //   LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// //   TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
// //   InOutTrL<TrInstant,TrInstant,TransitionLoop<Black,TrConcat<TrWipe<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipe<1000>,Black,TrConcat<TrWipeIn<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipeIn<1000>>>>>>>(),
// //   "testfont"
// "testfont2b-preonMatchTest"},
// { "crisp", "tracks/JFO5.wav",
// //    StylePtr<ColorSequence<1500,Red,Green,Blue,Black,White,Rainbow>>(),
//   StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RotateColorsX<Variation,SteelBlue>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelay<800>>,EFFECT_PREON>>>(),
//   StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RotateColorsX<Variation,SteelBlue>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelay<800>>,EFFECT_PREON>>>(),
//   StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RotateColorsX<Variation,SteelBlue>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelay<800>>,EFFECT_PREON>>>(),
 
//   //StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
// // ,
// // StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
// // StylePtr<Layers<
// //   TransitionLoop<Black,TrConcat<TrWipe<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipe<1000>,Black,TrConcat<TrWipeIn<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipeIn<1000>>>>,
// //   TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
// //   LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
// //   LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// //   TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
// //   InOutTrL<TrInstant,TrInstant,TransitionLoop<Black,TrConcat<TrWipe<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipe<1000>,Black,TrConcat<TrWipeIn<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipeIn<1000>>>>>>>(),
// //   "testfont"
// "testfont2b-preonMatchTest"},
// // { "RootCore;common", "RootCore/tracks/root.wav",
// //   StylePtr<RotateColorsX<Sin<Int<3>>,Red>>(),
// //   StylePtr<RotateColorsX<Sin<Int<3>>,Red>>(),
// //   StylePtr<RotateColorsX<Sin<Int<3>>,Red>>(),
// // "testfont\nblade in"},

// // { "a_BANE/RuleOfTwo;common", "a_BANE/tracks/track3.wav", // AudioFlicker Red base Color Wheel Changeable
   
// //   StylePtr<Layers<
// //     AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
// //     TransitionEffectL<TrConcat<TrFade<7000>,Rgb<0,0,75>,TrDelay<1000>>,EFFECT_USER2>,
// //     TransitionEffectL<TrConcat<TrWipe<8000>,TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,
// //       Sparkle<Rgb<25,105,255>,Rgb<250,250,250>,30,200>,
// //       TrFade<11500>,TrDelay<20000>,EFFECT_USER2>,TrDelay<7000>,
// //       Sparkle<Rgb<25,105,255>,Rgb<250,250,250>,30,200>,
// //       TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>,
// //     TransitionEffectL<TrConcat<TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,Int<400>,Int<50>,Int<1000>,Int<0>>,TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,Int<15000>,Int<400>,Int<8000>,Int<0>>,TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,AlphaL<Rgb<100,200,255>,Int<0>>,TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,Int<300>,Int<50>,Int<1000>,Int<0>>,TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>,TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>,
// //     BC_effects_Red, 
// //     InOutTrL<
// //       TrConcat<TrInstant,Layers<
// //       TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<1950>>,EFFECT_IGNITION>,
// //       AlphaL<AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
// //         SmoothStep<Scale<Trigger<EFFECT_IGNITION,Scale<Trigger<EFFECT_IGNITION,Int<2000>,Int<1>,Int<1>>,Int<300>,Int<2000>>,Int<1>,Int<1>>,Int<-1200>,Int<35000>>,Int<-3000>>>>,TrDelay<5000>>,
// //       TrConcat<TrInstant,Layers<
// //       TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<2000>>,EFFECT_RETRACTION>,
// //       AlphaL<AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
// //         SmoothStep<Scale<Trigger<EFFECT_RETRACTION,Scale<Trigger<EFFECT_RETRACTION,Int<1000>,Int<1000>,Int<1>>,Int<3000>,Int<10>>,Int<1000>,Int<500>>,Int<35000>,Int<-1200>>,Int<-3000>>>>,TrDelay<1000>>>,
// //      TransitionEffectL<TrConcat<TrWipe<100>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<60,0,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,
// //      TrDelayX< Percentage<WavLen<EFFECT_PREON>,49> >,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<60,0,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,
// //      TrFadeX<  Percentage<WavLen<EFFECT_PREON>,49> >,AlphaL<HumpFlickerL<RotateColorsX<Variation,BrownNoiseFlicker<Yellow,OrangeRed,50>>,90>,SmoothStep<Int<2700>,Int<-500>>>,TrInstant>,EFFECT_PREON>,
// //     // On-Demand Battery Level
// //     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// //   >>(),
// // // HiltPCB
// //   StylePtr<Black>(),
// // // Switches
// //   StylePtr<Layers<
// //     // Sith Crystal Red
// //     Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
// //     // Sith Force Red
// //     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
// //     BC_effects_2,
// //     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
// //   >>(),

// // "rule of\ntwo"},
// // { "a_DARKSABER/DarkV3;common", "a_DARKSABER/DarkV3/tracks/Mandalorian.wav",
// //   StylePtr<Layers<
// //     Mix<SwingSpeed<400>,RotateColorsX<Variation,Rgb<80,100,150>>,RotateColorsX<Variation,Rgb<130,150,225>>>,
// //     BrownNoiseFlickerL<Stripes<5000,-300,RotateColorsX<Variation,Rgb<15,25,55>>,RotateColorsX<Variation,Rgb<60,75,120>>,RotateColorsX<Variation,Rgb<0,10,20>>,RotateColorsX<Variation,Rgb<40,50,75>>>,Int<38400>>,
// //     AudioFlickerL<RotateColorsX<Variation,Rgb<25,35,75>>>,
// //     AlphaL<RotateColorsX<Variation,Rgb<155,175,225>>,SwingSpeed<600>>,
// //     BC_effects_1,
// //     InOutTrL<TrWipe<300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// //   // On-Demand Battery Level
// //     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// //   >>(),
// // // HiltPCB
// //   StylePtr<Black>(),
// // // Switches
// //   StylePtr<Layers<
// //     Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,200>,
// //     //InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,2500>>>>(),
// //     InOutTrL<TrInstant,TrInstant,ColorSequence<500,Red,Green,Blue,Black>>>>(),

// // "   dark\n    v3"},

// };

//----------------------------------------------------------------------------------------------------------------------------------------
Preset noblade[] = {

{ "testfont2b;common,commonBU", "testfont2/tracks/track1.wav",
// { "sine", "testfont2/tracks/track1.wav",

//    StylePtr<ColorSequence<1500,Red,Green,Blue,Black,White,Rainbow>>(),
  StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
  StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipe<1000>,Black,TrConcat<TrWipeIn<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipeIn<1000>>>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    InOutTrL<TrInstant,TrInstant,TransitionLoop<Black,TrConcat<TrWipe<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipe<1000>,Black,TrConcat<TrWipeIn<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipeIn<1000>>>>>>>(),
"testpreset\n1"},

// { "crisp", "tracks/JFO5.wav",

// //    StylePtr<ColorSequence<1500,Red,Green,Blue,Black,White,Rainbow>>(),
//   StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
//   StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
//   StylePtr<Layers<
//     TransitionLoop<Black,TrConcat<TrWipe<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipe<1000>,Black,TrConcat<TrWipeIn<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipeIn<1000>>>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
//     LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_NORMAL>,
//     LockupTrL<AudioFlickerL<White>,TrInstant,TrFade<500>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
//     InOutTrL<TrInstant,TrInstant,TransitionLoop<Black,TrConcat<TrWipe<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipe<1000>,Black,TrConcat<TrWipeIn<1000>,RotateColorsX<Sin<Int<10>>,Red>,TrWipeIn<1000>>>>>>>(),
// "testfont\nmessage"},

{ "RootCore;common;commonBU", "RootCore/tracks/root.wav",
  StylePtr<RotateColorsX<Sin<Int<3>>,Red>>(),
  StylePtr<RotateColorsX<Sin<Int<3>>,Red>>(),
  StylePtr<RotateColorsX<Sin<Int<3>>,Red>>(),
"font but\nno idle"},

{ "RootCoretest;common;", "RootCore/tracks/root.wav",
  StylePtr<Green>(),
  StylePtr<Green>(),
  StylePtr<Green>(),
"no font\nno idle1"},

{ "Calibr8", "",
  StylePtr<Rainbow>(),
  StylePtr<Rainbow>(),
  StylePtr<Rainbow>(),
"no font\nno idle2"},

{ "common;commonBU", "",
  
  StylePtr<Black>(),
  StylePtr<LengthFinder<>>(),
  StylePtr<Black>(),
"length\nfinder"},

};

BladeConfig blades[] = {

{ NO_BLADE, 
  WS281XBladePtr<144, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),  // D1 dead?
  WS281XBladePtr<144, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),  // D2 test leads
	WS281XBladePtr<4, blade5Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), // Onboard 4 LEDs
CONFIGARRAY(noblade),
"00_NO_BLADEsave", },


// { 0,  
//   WS281XBladePtr<144, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),  // D1 dead?
//   WS281XBladePtr<144, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),  // D2 test leads
// 	WS281XBladePtr<4, blade5Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), // Onboard 4 LEDs
// CONFIGARRAY(AllBlades),
// "01_AllBladessave", }, 


};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");

#endif

// // Button connect to 3.3v instead of GND. Up to 5v is OK
// PullDownButton PowerButton(BUTTON_POWER, powerButtonPin, "pow"); // isn't this backwards?

// // Analog Potentiometer 
// ChangeVolumeAnalogReceiver volume_function;
// PotClass pot(0, &volume_function);

// // Or, you can use it to change the variation (color):

// ChangeVariationAnalogReceiver variation_function;
// PotClass pot(0, &variation_function);

// // Rotary Encoder (see rotary.h)

// ChangePresetRotaryReceiver rotary_receiver;
// Rotary<8, 9> rotary(&rotary_receiver);
/*
The receiver decides what the rotary events do.
There are currently receivers for changing presets, 
changing variation and one that just prints things out. 
More receivers can be added as needed. 
(I should probably create one for changing the volume.)


Displays:

When you go with a standard display setup, images which are 64 pixels wide won’t work.
Also, the configuration in CONFIG_BOTTOM has changed a bit since last time.
You need a display controller now. At minimum, it should look like this:

#ifdef CONFIG_BOTTOM
StandardDisplayController<64, uint32_t> display_controller;
SSD1306Template<64, uint32_t> display(&display_controller);
#endif

For bullet counts, you’ll want something like:

#ifdef CONFIG_BOTTOM
DisplayHelper<64, uint32_t,
  BaseLayerOp<StandardDisplayController>,
  ClearRectangleOp<10, 50, 8, 24>, // was ClearRectangleOp<10, 80, 8, 24>,
  WriteBulletCountOp<10, 20, 3>
> display_controller;
SSD1306Template<64, uint32_t> display(&display_controller);
#endif

 here is an example for an 128x32 display:

#ifdef CONFIG_BOTTOM
DisplayHelper<128, uint32_t,
  BaseLayerOp<StandardDisplayController>,
  ClearRectangleOp<10, 80, 8, 24>,
  WriteBulletCountOp<10, 20, 5>
> display_controller;
SSD1306Template<128, uint32_t> display(&display_controller);
#endif

- what's the diff between that and then this?:

Support for 128x64 OLED
#ifdef CONFIG_BOTTOM
SSD1306Template<128, uint64_t> display(0x3C);
#endif

Also,
#define INCLUDE_SSD1306

Without it, the section at the bottom will throw errors.

Note that you should not have #define ENABLE_SSD1306 in your CONFIG_TOP section.
That will try to enable a 128x32 display, which will not work.


Color DIsplays
PQF files....????

DisplayStyle<>
This style requires a little more work than regular styles.
First you would need to declare an in-memory display.
To do this, we would put this in the CONFIG_STYLES section:

    InMemoryDisplay<8, 8, 3> my_small_display;

Then you need a controller for it:

    StandarColorDisplayController<8, 8> my_small_display_controller(&my_small_display);

Now we need give this display a name we can use in a style:

    NAME_INSTANCE(my_small_display, MYDISPLAY);

Now we we can use this inside a style template:

    DisplayStyle<MYDISPLAY>

Briefly, the display controller reads SCR files and tells
the in-memory display which PQF files to read. The PQF
files are rendered into an in-memory frame buffer.
DisplayStyle is used to read from that frame buffer.
Note that it's totally ok to use this with regular
blades, just make the height or the width of the
display equal to 1.
*/

*/
