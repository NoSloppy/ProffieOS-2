//BC_LukeHero_6.x // ProffieOS 6.x
// Latest upload: 8/1/21 New Kingston SD
// Blade detect is really chassis detect for Crystal reveal
// Swing On delay in prop set to 18000 from 3000 to compensate for delay? works!
#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 6
#define NUM_BUTTONS 1
#define VOLUME 1800
const unsigned int maxLedsPerStrip = 264;
#define EXTRA_COLOR_BUFFER_SPACE 66               // New define that can speed up processing a bit. Basically, it can calculate the colors for the next blade (or the next frame for the same blade) even though it's not done feeding out the data for the data in the color buffer yet.
#define CLASH_THRESHOLD_G 3.3
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
//#define ENABLE_SERIAL //Bluetooth
//#define ENABLE_SSD1306 //OLED
#define SHARED_POWER_PINS
#define SAVE_STATE
    //#define SAVE_VOLUME
    //#define SAVE_PRESET
    //#define SAVE_COLOR_CHANGE
    //#define SAVE_DYNAMIC_DIMMING
//#define KEEP_SAVEFILES_WHEN_PROGRAMMING         // upload overwrites presets.ini/tmp unless this is defined
#define BLADE_DETECT_PIN blade4Pin
// #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
//#define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> // This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors 
//#define SPEAK_BLADE_ID
//#define ENABLE_I2S_OUT
//#define ENABLE_SPDIF_OUT
//#define LINE_OUT_VOLUME 2000                    // SPDIF out
//#define ENABLE_DEVELOPER_COMMANDS
#define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
//#define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
//#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
//#define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
//#define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
//#define ORIENTATION ORIENTATION_SDA_TOWARDS_BLADE
//#define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE
//#define ORIENTATION_ROTATION 0,-20,0
//changes the angle required to register twists on curved hilts
//example is for assaj ventress curved hit install
#define CONFIG_STARTUP_DELAY 15000
//#define OLED_FLIP_180                           // BC  Figured this out and it got added!
//#define USE_AUREBESH_FONT
#define FEMALE_TALKIE_VOICE                       // BC now canon
#define VOLUME_MENU_CYCLE                         // BC now canon
#define NO_REPEAT_RANDOM                          // BC now canon

// ------- Gesture stuff -------

#define BC_SWING_ON                             // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
//#define BC_STAB_ON
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
#define BC_FORCE_PUSH
#define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS
//#define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200

// ------- Custom / Experimental / Alpha-Beta stuff ---------
#define PREONS_MATCH_OUTS
#define PSTOFFS_MATCH_INS
#define NO_BLADE_NO_GEST_ONOFF                    // If using blade detect, No Blade = No Gesture ignitions or retractions
#define ANGLE_PREON                               // Bypass preon if pointing up.                                **Required modified prop_base.h
#define AUTO_HUMSTART                             // 200ms delay from on.wav beginning all the time.             **Requires modified hybrid_font.h file.
#define ENABLE_AUTO_SPINS_BLAST                   // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
//#define LOW_BATT_ONCE                           //                                                             **Requires modified hybrid_font.h file.
//#define ENABLE_GESTURE_MENU                      // PSISTORM prop - cool stuff! the TrySound else beep void.

//#define OPTIMIZE_TRCONCAT                       // this TRCONCAT can save some RAM, but it's not compatible with IntArg/RgbArg
//#define FILTER_CUTOFF_FREQUENCY 100
//#define FILTER_ORDER 8

#define ENABLE_ALL_MENU_OPTIONS                    // OS 6
    //#define DYNAMIC_BLADE_LENGTH
    //#define DYNAMIC_BLADE_DIMMING
    //#define DYNAMIC_CLASH_THRESHOLD
    //#define SAVE_VOLUME
    //#define SAVE_BLADE_DIMMING
    //#define SAVE_CLASH_THRESHOLD
    //#define SAVE_COLOR_CHANGE

#endif


#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"
#include "aliases/TrueWhites/BC_effects_2.h"
#include "aliases/TrueWhites/BC_effects_Red.h"

/*
Luke V1 Hero presets summary:

1. LS6 (Sail Barge)
2. Vader
3. Daddy Issues (Final Fight)
4. Rescue (Grogu)
5. ANH Training (w/ remote on Falcon)
6. Royalty (Leia)
7. Kylo Ren
8. Son Of Darkness (Very dark Kylo)
9. Scavenger’s Destiny (Rey Yellow)
10. ESB Graflex (Carbonite Chamber)
11. Ahsoka Ultimate
12. The Jedi (Ahsoka Mandalorian episode)
13. The White (Neutral Jedi, sort of Ahsoka)
14. Nextor
15. Comet
16. Falcon
17. Tie Fighter
18. X-Wing
19. Slave 1
20. Proto 2
*/

//-----------------------------------------------------------------------------------------------------------------------------------------

// ******Style storage area*******
//
// *******Alternate Blinking/ Pulsing behavior for the Control Box LEDs.
//  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
//  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
//----------------------------------------------------------------------------------------------------------------------------------------


Preset KR_Pixel_Stick [] = {


{ "a_LUKE/LS6;common", "a_LUKE/LS6/tracks/jabba_scene.wav", // 1 AudioFlicker Green Color Wheel Changeable   
    StylePtr<Layers<
    // Main Blade Color/Styles Base
        // AudioFlicker Default = Green
        AudioFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,
        BC_effects_1, 
        InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(), 
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),

"luke\nskywalker"},




{ "a_VADER/RogueVader;common", "a_VADER/RogueVader/tracks/Imperial_March_ROTJ.wav", // 2 AudioFlicker Red base Color Wheel Changeable
    StylePtr<Layers<
        AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
        BC_effects_Red,
        InOutTrL<TrWipeSparkTip<White,500>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
        // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
        // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"darth\nvader"},


{ "a_LUKE/DaddyIssues;common", "a_LUKE/DaddyIssues/tracks/Final_Duel.wav", // 1 AudioFlicker Green Color Wheel Changeable
    StylePtr<Layers<
    // Main Blade Color/Styles Base
        AudioFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,
        BC_effects_Red,
        InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(), 
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"daddy\nissues"},



{ "a_LUKE/Rescue;common", "a_LUKE/Rescue/tracks/Intro_fight.wav", // 1 AudioFlicker Green Color Wheel Changeable
    StylePtr<Layers<
    // Main Blade Color/Styles Base
        AudioFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,
        BC_effects_1,
    InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(), 
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"the\nrescue"},


{ "a_LUKE/ANH_Training;a_LUKE/ANH_Graflex;common", "a_LUKE/ANH_Training/tracks/training_ambience.wav", // 3 AudioFlicker DeepSkyBlue Base Color Wheel Changeable
    StylePtr<Layers<
        AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
        BC_effects_1,
        InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"anh\ntraining"},




{ "a_LEIA/Royalty;common", "a_LEIA/Royalty/tracks/Leia1.wav", //  3 AudioFlicker DeepSkyBlue base Color Wheel Changeable
    StylePtr<Layers<
        AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
        BC_effects_1,
        InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"royalty"},   



{ "a_KYLO/KyloUltimate;common", "a_KYLO/KyloUltimate/tracks/Kylo1.wav", // 4 BrownNoiseFlicker Red base Color Wheel Changeable
    StylePtr<Layers<
        StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
        BC_effects_Red,
        InOutTrL<TrWipeSparkTip<White,500>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"kylo ren"},   


 
{ "a_KYLO/SonOfDarkness;common", "a_BANE/tracks/track4.wav", // 4 BrownNoiseFlicker Red base Color Wheel Changeable 
    StylePtr<Layers<
        Layers<Stripes<2000,-2500,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<30,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<30,0,0>>>>,
          TransitionLoopL<TrConcat<TrWaveX<RotateColorsX<Variation,Red>,Int<400>,Int<600>,Int<500>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1500>>,Int<200>,Int<1200>>>>>,
          AlphaL<Mix<SwingSpeed<500>,Red,Orange>,Scale<SwingSpeed<400>,Int<0>,Int<32768>>>,
          AlphaL<RotateColorsX<Variation,ColorCycle<Black,0,1,Red,75,900,1000>>,Bump<Int<0>,Int<8000>>> >,
        BC_effects_Red,
        InOutTrL<TrWipeSparkTip<White,500>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"son of\ndarkness"},   



{ "a_REY/ScavngrsDstny;common", "a_REY/ScavngrsDstny/tracks/ReyEp9End", // 5 AudioFlicker Default = Golden Yellow Color Wheel Changeable 
    StylePtr<Layers<
        AudioFlicker<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<90,65,0>>>,
        BC_effects_1,
        InOutTrL<TrWipeSparkTip<White,400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
        TransitionEffectL<TrConcat<TrInstant,AlphaL<Green,Bump<Int<0>,Int<1000>>>,TrDelay<90>,AlphaL<DodgerBlue,Bump<Int<0>,Int<1000>>>,TrFade<100>,AlphaL<DeepSkyBlue,Bump<Int<0>,Int<1000>>>,TrDelay<200>>,EFFECT_PREON>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"scavenger's\ndestiny"},   



{"a_LUKE/ESB_Graflex;common", "a_LUKE/ESB_Graflex/tracks/LvsV.wav", // 6 RandomFlicker Blue base Color Wheel Changeable
    StylePtr<Layers<
        Mix<SwingSpeed<400>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,Mix<SwingSpeed<800>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<150,150,255>>>>,
        BC_effects_1,
        InOutTrL<TrWipeSparkTip<White,200>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"esb\ngraflex"},




{ "a_AHSOKA/AhsokaUltimate;common", "a_AHSOKA/CdeFlcrm/tracks/ItsOverNow.wav", // 8 AudioFlicker Bright Swing Color Wheel Changeable - Default = Silver White
    StylePtr<Layers<
        Mix<SwingSpeed<500>,AudioFlicker<RotateColorsX<Variation,Rgb<110,150,255>>,RotateColorsX<Variation,Rgb<80,90,130>>>,Mix<SwingSpeed<800>,AudioFlicker<RotateColorsX<Variation,Rgb<110,150,255>>,RotateColorsX<Variation,White>>,RotateColorsX<Variation,White>>>,
// Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
    AlphaL<Black,Int<16384>>,
    AlphaL<Black,Int<0>>>,
// Clash
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// Stab 
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,DarkOrange,Rgb<80,60,0>,Orange,Rgb<60,30,0>,Black,DarkOrange,Orange>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// Blast - for white blades
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
    BlastL<EffectSequence<EFFECT_BLAST,Red,Green,Blue,White,Black>,850,250,351>,
    BlastL<Red,700,250,100000>,
    BlastL<White,500,300,100000>,
// Lockup - BC custom range mid-blade
    LockupTrL<Layers<
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
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
    // Begin Lightning Transition
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
    // End Lightning Transition    
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
       
// Melt    
    LockupTrL<
    AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
	  // Melt Shape
    SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
    // Melt Begin and End transitions
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,  // Great melt colors as you twist, gets dripping red hot/fire and bright yellow.

    InOutTrL<TrWipeSparkTip<White,400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// Auto-dim blade on Low batt
    AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"ahsoka\nultimate"},   




{ "a_AHSOKA/TheJediMandoEp;common", "a_AHSOKA/TheJediMandoEp/tracks/Mando.wav", // 8 AudioFlicker Bright Swing Color Wheel Changeable - Default = Silver White 
   StylePtr<Layers<
            Mix<SwingSpeed<500>,AudioFlicker<RotateColorsX<Variation,Rgb<110,150,255>>,RotateColorsX<Variation,Rgb<80,90,130>>>,Mix<SwingSpeed<800>,AudioFlicker<RotateColorsX<Variation,Rgb<110,150,255>>,RotateColorsX<Variation,White>>,RotateColorsX<Variation,White>>>,
// Dim Blade 50% "Power Save" button combo
  EffectSequence<EFFECT_POWERSAVE,
  AlphaL<Black,Int<16384>>,
  AlphaL<Black,Int<0>>>,
// Clash
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// Stab 
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,DarkOrange,Rgb<80,60,0>,Orange,Rgb<60,30,0>,Black,DarkOrange,Orange>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// Blast - for white blades
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
    BlastL<EffectSequence<EFFECT_BLAST,Red,Green,Blue,White,Black>,850,250,351>,
    BlastL<Red,700,250,100000>,
    BlastL<White,500,300,100000>,
// Lockup - BC custom range mid-blade
    LockupTrL<Layers<
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
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
    // Begin Lightning Transition
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
    // End Lightning Transition    
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
       
// Melt    
    LockupTrL<
    AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
	  // Melt Shape
    SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
    // Melt Begin and End transitions
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,  // Great melt colors as you twist, gets dripping red hot/fire and bright yellow.

    InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// Auto-dim blade on Low batt
    AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(), 
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"ahsoka\nmando"},   



{ "TheWhite;common", "", // 8 AudioFlicker Bright Swing Color Wheel Changeable - Default = Silver White
  StylePtr<Layers<
    Mix<SwingSpeed<500>,AudioFlicker<RotateColorsX<Variation,Rgb<110,150,255>>,RotateColorsX<Variation,Rgb<80,90,130>>>,Mix<SwingSpeed<800>,AudioFlicker<RotateColorsX<Variation,Rgb<110,150,255>>,RotateColorsX<Variation,White>>,RotateColorsX<Variation,White>>>,
// Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
    AlphaL<Black,Int<16384>>,
    AlphaL<Black,Int<0>>>,
// Clash
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<White,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,White,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// Stab 
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,DarkOrange,Rgb<80,60,0>,Orange,Rgb<60,30,0>,Black,DarkOrange,Orange>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// Blast - for white blades
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
    BlastL<EffectSequence<EFFECT_BLAST,Red,Green,Blue,White,Black>,850,250,351>,
    BlastL<Red,700,250,100000>,
    BlastL<White,500,300,100000>,
// Lockup - BC custom range mid-blade
    LockupTrL<Layers<
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
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
    // Begin Lightning Transition
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
    // End Lightning Transition    
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
       
// Melt    
    LockupTrL<
    AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
	  // Melt Shape
    SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
    // Melt Begin and End transitions
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,  // Great melt colors as you twist, gets dripping red hot/fire and bright yellow.

    InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// Auto-dim blade on Low batt
    AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
 // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"the\nwhite"},   



{ "Nextor;common", "", // 9 HumpFlicker Blade Default = PurpleBlue  
    StylePtr<Layers<
        HumpFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Blue,50>,
        BC_effects_Red,
        InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"Nextor"},   

{ "aa_NoSloppy/Comet;common", "", // 10 HumpFlicker tight speckle humps Blade Default = Red Custom preon, in and out...Comet animation
    StylePtr<Layers<
        HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,10>,
        BC_effects_Red,
        InOutTrL<TrJoin<TrConcat<TrWipe<1000>,RandomBlink<100,Red,Rgb<255,50,50>>,TrFade<175>,BrownNoiseFlicker<Rgb<200,20,20>,Rgb<80,0,0>,200>,TrFade<900>>,TrJoin<TrWipe<1700>,
        TrWaveX<BrownNoiseFlicker<Yellow,RandomFlicker<White,Red>,50>,Int<3000>,Int<200>,Int<1000>,Int<2000>>,TrWaveX<BrownNoiseFlicker<Yellow,OrangeRed,100>,Int<3000>,Int<150>,Int<1000>,Int<0>>,
        TrWaveX<BrownNoiseFlicker<Red,Rgb<80,0,0>,100>,Int<3000>,Int<100>,Int<1000>,Int<-2000>>>>,
        TrJoin<TrConcat<TrFade<90>,RandomBlink<100,Red,Rgb<255,50,50>>,TrSmoothFade<250>,RandomBlink<10000,Rgb<80,0,0>>,TrSmoothFade<700>>,
        TrJoin<TrFade<3000>,TrWaveX<BrownNoiseFlicker<Yellow,RandomFlicker<White,Red>,50>,Int<3000>,Int<200>,Int<1400>,Int<30000>>,
        TrWaveX<BrownNoiseFlicker<Yellow,OrangeRed,100>,Int<3000>,Int<150>,Int<1400>,Int<32768>>,TrWaveX<BrownNoiseFlicker<Red,Rgb<80,0,0>,100>,Int<3000>,Int<100>,Int<1400>,Int<34000>>>>>,
        TransitionEffectL<TrConcat<TrInstant,Rgb<100,100,0>,TrFade<50>>,EFFECT_IGNITION>,
        TransitionEffectL<TrConcat<TrWipe<100>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<60,0,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,
        TrDelayX< Percentage<WavLen<EFFECT_PREON>,49> >,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<60,0,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,
        TrFadeX<  Percentage<WavLen<EFFECT_PREON>,49> >,AlphaL<HumpFlickerL<RotateColorsX<Variation,BrownNoiseFlicker<Yellow,OrangeRed,50>>,90>,SmoothStep<Int<2700>,Int<-500>>>,TrInstant>,EFFECT_PREON>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"comet"},   



{"a_SHIPS/Falcon;common", "a_SHIPS/Falcon/tracks/Falcon.wav", // 11 Stripes based Pulse - Default = Blue Color Wheel Changeable   
    StylePtr<Layers<    
        Stripes<10000,-2000,RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
        BC_effects_1, 
    // Engines Starting Ignition, cyle down retraction
        InOutTrL<TrJoin<TrWipe<500>,TrWipeIn<500>>,TrColorCycle<6000,-600,-100>>,
        TransitionEffectL<TrConcat<TrInstant,StrobeL<AlphaL<White,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,Int<25>,Int<30>>,TrFade<1500>>,EFFECT_IGNITION>,
        TransitionEffectL<TrConcat<TrInstant,White,TrFade<50>>,EFFECT_IGNITION>,
        TransitionEffectL<TrConcat<TrFadeX< Percentage<WavLen<EFFECT_PREON>,30> >,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,DeepSkyBlue>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelayX< Percentage<WavLen<EFFECT_PREON>,70> >>,EFFECT_PREON>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"millenium\nfalcon"},   


{"a_SHIPS/Tie;common", "a_SHIPS/Tie/tracks/Tie.wav", // 11 Stripes based Pulse - Default = Green Color Wheel Changeable   
    StylePtr<Layers< 
        Stripes<10000,-2000,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,60,0>>,RotateColorsX<Variation,Rgb<50,255,50>>,RotateColorsX<Variation,Rgb<0,128,0>>>,
        BC_effects_1, 
    // Engines Starting Ignition, cyle down retraction
        InOutTrL<TrJoin<TrWipe<500>,TrWipeIn<500>>,TrColorCycle<6000,-600,-100>>,
        TransitionEffectL<TrConcat<TrInstant,StrobeL<AlphaL<White,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,Int<25>,Int<30>>,TrFade<1500>>,EFFECT_IGNITION>,
        TransitionEffectL<TrConcat<TrInstant,White,TrFade<50>>,EFFECT_IGNITION>,
        TransitionEffectL<TrConcat<TrFadeX< Percentage<WavLen<EFFECT_PREON>,30> >,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Green>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelayX< Percentage<WavLen<EFFECT_PREON>,70> >>,EFFECT_PREON>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"tie\nfighter"},   



{"a_SHIPS/Xwing;common", "a_SHIPS/Xwing/tracks/Xwing.wav", // 11 Stripes Pulse - Default = Red base Color Wheel Changeable   
    StylePtr<Layers<    
        Stripes<10000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,RotateColorsX<Variation,Rgb<255,50,50>>,RotateColorsX<Variation,Rgb<128,0,0>>>,
        BC_effects_Red, 
    // Engines Starting Ignition, cyle down retraction
        InOutTrL<TrJoin<TrWipe<500>,TrWipeIn<500>>,TrColorCycle<6000,-600,-100>>,
        TransitionEffectL<TrConcat<TrInstant,StrobeL<AlphaL<White,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,Int<25>,Int<30>>,TrFade<1500>>,EFFECT_IGNITION>,
        TransitionEffectL<TrConcat<TrInstant,White,TrFade<50>>,EFFECT_IGNITION>,
        TransitionEffectL<TrConcat<TrFadeX< Percentage<WavLen<EFFECT_PREON>,30> >,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelayX< Percentage<WavLen<EFFECT_PREON>,70> >>,EFFECT_PREON>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"x-wing\nfighter"},




{"a_SHIPS/Slave1;common", "a_SHIPS/Slave1/tracks/Pursuit.wav", // Center out stripes - custom preon and ignition
   
// Slave 1 with seismic charge preon
   
 StylePtr<Layers<
  Mix<SmoothStep<Int<16384>,Int<4000>>,Stripes<10000,500,Rgb<0,30,80>,Rgb<0,60,180>>,Stripes<10000,-500,Rgb<0,30,80>,Rgb<0,60,180>>>,
// Dim Blade 50% "Power Save" button combo
  EffectSequence<EFFECT_POWERSAVE,
  AlphaL<Black,Int<16384>>,
  AlphaL<Black,Int<0>>>,
// Clash - 3 stage fading impact spot
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// Stab 
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,DarkOrange,Rgb<80,60,0>,Orange,Rgb<60,30,0>,Black,DarkOrange,Orange>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// Blast - custom for slave 1 sound fx
    MultiTransitionEffectL<TrConcat<TrDelay<700>,AlphaL<Black,Int<0>>,TrFade<800>,LocalizedClashL<HumpFlicker<DarkOrange,Red,50>,2000,50,EFFECT_BLAST>,TrFade<600>>,EFFECT_BLAST>,
    LocalizedClashL<Blinking<White,Black,130,800>,1560,50,EFFECT_BLAST>,
    LocalizedClashL<Blinking<Red,Black,130,500>,1560,15,EFFECT_BLAST>,
// Lockup - BC custom range mid-blade
    LockupTrL<Layers<
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
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
    // Begin Lightning Transition
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
    // End Lightning Transition    
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  
// Melt
    LockupTrL<
    //Melt Colors
    AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
    // Melt Shape
    SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
    // Melt Begin and End transitions
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
// Ignition Powerup
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<DeepSkyBlue,White,100>,TrFade<800>>,EFFECT_IGNITION>,
// In/out using Trigger for instantaneous Center-out wipes
   InOutTrL<TrConcat<TrInstant,Layers<
    AlphaL<Black,SmoothStep<Scale<Trigger<EFFECT_IGNITION,Int<300>,Int<1000>,Int<500>>,Int<16385>,Int<0>>,Int<-1>>>,
    AlphaL<Black,SmoothStep<Scale<Trigger<EFFECT_IGNITION,Int<300>,Int<1000>,Int<500>>,Int<16384>,Int<32768>>,Int<0>>>>,TrDelay<1000>>,TrJoin<TrWipe<700>,TrWipeIn<700>>>,
   TransitionEffectL<TrConcat<TrInstant,Cyan,TrDelay<50>>,EFFECT_IGNITION>,
// Asteroid impacts after detonation - timed sequence
   TransitionEffectL<TrConcat<
    TrDelay<1500>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Red,White,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<3000>,Int<6000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<100>,AlphaL<Red,Int<0>>,
    TrDelay<400>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Orange,White,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<6000>,Int<10000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<100>,AlphaL<Red,Int<0>>,
    TrDelay<200>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Black,White,100>,Bump<ChangeSlowly<SlowNoise<Int<30000>>,Int<60000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<300>,AlphaL<Red,Int<0>>,
    TrDelay<200>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Yellow,Red,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<10000>,Int<28000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<200>,AlphaL<Red,Int<0>>,
    TrDelay<500>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Orange,White,100>,Bump<ChangeSlowly<SlowNoise<Int<30000>>,Int<60000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<200>,AlphaL<Red,Int<0>>,
    TrDelay<100>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Red,White,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<5000>,Int<13000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<100>,AlphaL<Red,Int<0>>,
    TrDelay<500>,GreenYellow,TrDelay<25>>,EFFECT_IGNITION>,
// Seismic Charge preon effect. use with linked preon sound
  TransitionEffectL<TrConcat<TrDelay<2125>,Cyan,TrFade<100>,Black,TrDelay<10>,Cyan,TrFade<150>  >,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrDelay<2125>,AlphaL<White,Bump<Int<16384>,Int<32768>>>,TrFade<100>, Black,TrDelay<10>,AlphaL<White,Bump<Int<16384>,Int<32768>>>,TrFade<150>  >,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrDelay<2100>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<3000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<4000>>>,
    TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<5000>>>,
    TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<10000>>>,
    TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<20000>>>,
    TrSmoothFade<175>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<30000>>>,
    TrSmoothFade<125>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<35000>>>,
    TrSmoothFade<150>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<30000>>>,
    TrSmoothFade<75>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<20000>>>,
    TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<8000>>>,
    TrSmoothFade<25>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<3000>>>,TrFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<20000>>>,TrDelay<25>>,EFFECT_PREON>,

  TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Scale<Trigger<EFFECT_PREON,Int<2000>,Int<1000>,Int<500>>,Int<-1000>,Int<16500>>,Int<1500>>>,TrDelay<2000>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrDelay<1100>,AlphaL<Red,Int<0>>,TrSmoothFade<700>,Black,TrDelay<100>,AlphaL<White,Bump<Int<16384>,Int<3000>>>,TrDelay<100>>,EFFECT_PREON>,
// Auto-dim blade on Low batt
    AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),

StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"slave 1"},





{"Proto2;common", "Proto2/tracks/proto2.wav", // 12 Color Cycle to Glitchy Pulsing Blade Default = Green
    StylePtr<Layers<   
        ColorCycle<RotateColorsX<Variation,Rgb<0,128,0>>,100,-3250,RotateColorsX<Variation,BlinkingX<RandomFlicker<RandomBlink<13000,RotateColorsX<Variation,Rgb<128,200,128>>,RotateColorsX<Variation,Black>>,RotateColorsX<Variation,Green>>,RandomFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<30,30,30>>>,Scale<SlowNoise<Int<16000>>,Int<300>,Int<1000>>,Scale<SlowNoise<Int<16000>>,Int<200>,Int<650>>>>,50,3000,3000>,
        BC_effects_1,
        InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // Auto-dim blade on Low batt
        AlphaL<Black,Scale<IsLessThan<BatteryLevel,Int<11000>>,Int<0>,Int<16384>>>,
    // On-Demand Battery Level
        AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
StylePtr<Black>(),
StylePtr<Black>(),
StylePtr<Black>(),  
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"proto 2"},





 //  {"BattLevl;common","",
  
 //  StylePtr<Layers<Black,AlphaL<PulsingX<Mix<BatteryLevel,Red,Green>,Black,Scale<BatteryLevel,Int<500>,Int<4000>>>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<40000>>,Int<-1>>>>>(),
 //  StylePtr<Black>(),
 //  StylePtr<Black>(),
 //  StylePtr<Black>(), 
 //  StylePtr<Black>(),
 //  StylePtr<Black>(),
 // "Battery\nlevel bc"}

    // { "BattLevl;common", "tracks/Ambience.wav",
    // &style_charging,
    //Side 2
    // &style_charging,
    // StylePtr<Black>(),
    // StylePtr<Black>(),
// StylePtr<Black>(),
// StylePtr<Black>(),
// StylePtr<Black>(),     
    // "battery\nlevel"},

    // { "LngthFnd;common", "",
    // StylePtr<LengthFinder<>>(),
    // StylePtr<LengthFinder<>>(),
    // StylePtr<Black>(),
    // StylePtr<Black>(), 
    // StylePtr<Black>(),
    // StylePtr<Black>(),
    // StylePtr<Black>(),
    // "length\nfinder"},

//  { "testfont2", "tracks/theforce1.wav",
//     StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
//     StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
//     StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
//     StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
//     StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
// // Red Arrow Blinks when blade is ON
//     StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// // Green Arrow
//     StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
//  "testfont2"},


};




//----------------------------------------------------------------------------------------------------------------------------------------
Preset noblade[] = {


{ "a_LUKE/LS6;common", "a_LUKE/LS6/tracks/jabba_scene.wav", // AudioFlicker Green Color Wheel Changeable
// Emitter PCB and Main Blade
    
    StylePtr<Black>(),
// Chassis PCB
   StylePtr<Layers<
  Cylon<Stripes<1000,-275,Green,Rgb<0,128,0>,Black,Rgb<0,128,0>>,100,1,Stripes<1000,-2000,Green,Rgb<0,128,0>,Black>,100,1,500>,
  BlastFadeoutL<Blue,400>,
  LockupL<Blinking<Green,Black,85,500>,AudioFlicker<Yellow,Blue>,Int<32768>,Int<32768>,Int<32768>>,
  LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  SimpleClashL<Yellow,150,EFFECT_CLASH,SmoothStep<Int<0>,Int<24000>>>,
  InOutTrL<TrWipeSparkTip<Yellow,500,75>,TrInstant,AlphaL<Red,Int<0>>>>>(),
// Chamber Top  
   StylePtr<Layers<
  RandomFlicker<Green,Rgb<0,128,0>>,
  BlastFadeoutL<Blue>,  
  LockupL<AudioFlicker<Yellow,Blue>,Blinking<Green,Black,85,500>,Int<32768>,Int<32768>,Int<32768>>,
  SimpleClashL<Yellow,100,EFFECT_CLASH,SmoothStep<Int<0>,Int<24000>>>,
  LockupTrL<Pulsing<Red,Yellow,1000>,TrInstant,TrInstant,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeSparkTip<Yellow,500,75>,TrInstant,Pulsing<ColorCycle<Green,25,50,Green,75,400,3000>,Black,2000>>>>(),
// Chamber Bot  
   StylePtr<Layers<
  Pulsing<RandomFlicker<Rgb<0,128,0>,Green>,Black,800>,
  BlastFadeoutL<Blue,400>,  
  LockupL<Blinking<Green,Black,85,500>,AudioFlicker<Yellow,Blue>,Int<32768>,Int<32768>,Int<32768>>,
  SimpleClashL<Yellow,100,EFFECT_CLASH,SmoothStep<Int<0>,Int<24000>>>,
  LockupTrL<Pulsing<Red,Yellow,1000>,TrInstant,TrInstant,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeSparkTip<Yellow,500,75>,TrInstant,Pulsing<Black,ColorCycle<Green,25,20,Green,100,3000,3000>,2000>>>>(),
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"luke\nskywalker"},


 { "Calibr8;common", "tracks/TalesOfAJediKnight.wav",                            
// Emitter PCB and Main Blade
    StylePtr<Black>(),
// Chassis PCB
    StylePtr<Layers<
  Cylon<Stripes<1000,-275,Green,Rgb<0,128,0>,Black,Rgb<0,128,0>>,100,1,Stripes<1000,-2000,Green,Rgb<0,128,0>,Black>,100,1,500>,
  BlastFadeoutL<Blue,400>,
  LockupL<Blinking<Green,Black,85,500>,AudioFlicker<Yellow,Blue>,Int<32768>,Int<32768>,Int<32768>>,
  LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
  SimpleClashL<Yellow,150,EFFECT_CLASH,SmoothStep<Int<0>,Int<24000>>>,
  InOutTrL<TrWipeSparkTip<Yellow,500,75>,TrInstant,AlphaL<Red,Int<0>>>>>(),
// Chamber Top  
  StylePtr<Layers<
  RandomFlicker<Green,Rgb<0,128,0>>,
  BlastFadeoutL<Blue>,  
  LockupL<AudioFlicker<Yellow,Blue>,Blinking<Green,Black,85,500>,Int<32768>,Int<32768>,Int<32768>>,
  SimpleClashL<Yellow,100,EFFECT_CLASH,SmoothStep<Int<0>,Int<24000>>>,
  LockupTrL<Pulsing<Red,Yellow,1000>,TrInstant,TrInstant,SaberBase::LOCKUP_MELT>,  
  InOutTrL<TrWipeSparkTip<Yellow,500,75>,TrInstant,Pulsing<ColorCycle<Green,25,50,Green,75,400,3000>,Black,2000>>>>(),
// Chamber Bot  
   StylePtr<Layers<
  Pulsing<RandomFlicker<Rgb<0,128,0>,Green>,Black,800>,
  BlastFadeoutL<Blue,400>,  
  LockupL<Blinking<Green,Black,85,500>,AudioFlicker<Yellow,Blue>,Int<32768>,Int<32768>,Int<32768>>,
  SimpleClashL<Yellow,100,EFFECT_CLASH,SmoothStep<Int<0>,Int<24000>>>,
  LockupTrL<Pulsing<Red,Yellow,1000>,TrInstant,TrInstant,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeSparkTip<Yellow,500,75>,TrInstant,Pulsing<Black,ColorCycle<Green,25,20,Green,100,3000,3000>,2000>>>>(),
// Red Arrow Blinks when blade is ON
    StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// Green Arrow
    StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
"calibrate"},   

           

//  { "testfont2;common", "tracks/theforce1.wav",
//     StylePtr<Black>(),
//     StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
//     StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
//     StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
// // Red Arrow Blinks when blade is ON
//     StylePtr<InOutHelper<Blinking<Black,Rgb<130,130,130>,1500,500>, 1, 1, Sequence<Rgb<130,130,130>, Black, 200, 30, 0b0000000000000000,0b0010101010101000>>>(),
// // Green Arrow
//     StylePtr<InOutHelper<Rgb<85,85,85>, 1, 1, Sequence<Rgb<85,85,85>, Black, 200, 30, 0b1010101010101010,0b1000000000000000>>>(),
//  "testfont2"},


};

struct AccentsLED {
static constexpr float MaxAmps = 0.02;
static constexpr float MaxVolts = 3.2;
static constexpr float P2Amps = 0.10;
static constexpr float P2Volts = 3.0;
static constexpr float R = 0; // Resistor value
static const int Red = 255;
static const int Green = 255;
static const int Blue = 255;
};


BladeConfig blades[] = {
{ 0,          // 264 pixel KR_Pixel_Stick - No SUBBLADE
  WS281XBladePtr<264, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3>,DefaultPinClass, 900000  >() ,  // HiltPCB and KR_Pixel_Stick Main Blade in parallel
  WS281XBladePtr<5, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // ChassisPCB 
  SubBlade (4, 7, WS281XBladePtr<8, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ),                  // Chamber Top
  SubBlade (0, 3, NULL),                                                                                                      // Chamber Bottom
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>(),                                              // Red Arrow
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                              // Green Arrow
CONFIGARRAY(KR_Pixel_Stick), 
"01_KR_Pixel_Stick", }, 

{ NO_BLADE, 
  WS281XBladePtr<264, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ,  // HiltPCB and KR_Pixel_Stick Main Blade removed with Grenade section
  
  WS281XBladePtr<5, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // ChassisPCB 
  SubBlade (4, 7, WS281XBladePtr<8, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ),                  // Chamber Top
  SubBlade (0, 3, NULL),                                                                                                      // Chamber Bottom
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>(),                                              // Red Arrow
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                              // Green Arrow
CONFIGARRAY(noblade),
"00_NO_BLADEsave", }, 
// { 0,          // 264 pixel KR_Pixel_Stick - SubBladeWithStride
//   //WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3>,DefaultPinClass, 900000 >(),         // HiltPCB and Main Blade in parallel
  // SubBladeWithStride (0, 262, 2, WS281XBladePtr<264, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ),  // HiltPCB and KR_Pixel_Stick Main Blade in parallel
  // SubBladeWithStride (1, 263, 2, NULL),
//   WS281XBladePtr<5, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // ChassisPCB 
//   SubBlade (4, 7, WS281XBladePtr<8, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ),                  // Chamber Top
//   SubBlade (0, 3, NULL),																						                                              	          // Chamber Bottom
//   SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>(),					                                    // Red Arrow
//   SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),					                                    // Green Arrow
// CONFIGARRAY(KR_Pixel_Stick), 
// "01_KR_Pixel_Stick", }, 

// { NO_BLADE, 
//   //WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                 // HiltPCB and Main Blade removed with Grenade section
//   SubBladeWithStride (0, 262, 2, WS281XBladePtr<264, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ),  // HiltPCB and KR_Pixel_Stick Main Blade removed with Grenade section
//   SubBladeWithStride (1, 263, 2, NULL),
//   WS281XBladePtr<5, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // ChassisPCB 
//   SubBlade (4, 7, WS281XBladePtr<8, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ),                  // Chamber Top
//   SubBlade (0, 3, NULL),																							                                                        // Chamber Bottom
//   SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>(),					                                    // Red Arrow
//   SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),					                                    // Green Arrow
// CONFIGARRAY(noblade),
// "00_NO_BLADEsave", }, 


};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
