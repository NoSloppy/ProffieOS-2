//BC_DarkShadow_6.x// ProffieOS version 6.x - BC manual update - Native WavLen!

// Use 1 button config?

#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 1
// #define DUAL_POWER_BUTTONS   ****not working fully, only power     // BC Make both buttons identical for 1-btn use... useful?

// ------ Audio Stuff --------

#define VOLUME 1000
#define BOOT_VOLUME 200
#define ENABLE_AUDIO
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                   // SPDIF out
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8
#define FEMALE_TALKIE_VOICE                       // BC now canon OS6
#define NO_REPEAT_RANDOM                          // BC now canon
#define KILL_OLD_PLAYERS                          // BC now canon
// #define DISABLE_TALKIE                            // I feel I'm not gonna like this
// #define VOLUME_MENU_CYCLE     **** DEAD         // quick MAX MIN now

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
// New define that can speed up processing a bit. Basically, it can calculate the colors for the next
// blade (or the next frame for the same blade) even though it's not done feeding out the data for the
// data in the color buffer yet. Equivalent to just increasing maxLedsPerStrip.
// #define EXTRA_COLOR_BUFFER_SPACE 30
#define SHARED_POWER_PINS
#define BLADE_DETECT_PIN 10
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9>         // TX pad
//    This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
//    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value, so I would recommend using something like 200000 instead of NO_BLADE.
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> 
//    Millis is BladeID scan interval. If the blade ID comes out the same as before, it will do nothing.
//    If it comes out different, it will do FindBladeAgain(), which will basically initialize the saber from scratch and load the right settings for the new id().
//    It will only work with neopixel blades, and it probably requires SHARED_POWER_PINS to work.
// #define BLADE_ID_SCAN_MILLIS 1000

// ------ SD Card Stuff -------

#define ENABLE_SD
// #define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING        // upload overwrites presets.ini/tmp unless this is defined

// ------- OLED stuff ----------

// #define ENABLE_SSD1306                         // OLED display. also defines ENABLE_DISPLAY_CODE
// #define OLED_FLIP_180                          // BC now canon
// #define OLED_MIRRORED
// #define USE_AUREBESH_FONT                      // BC now canon
// #define PLI_OFF_TIME 60 * 5 * 1000
// #define OLED_USE_BLASTER_IMAGES
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144_SC_POV_data.h"
// #define POV_INCLUDE_FILE "Raiden_123_FC_POV_data.h"
// #define POV_INCLUDE_FILE "JohnCena_144_8b_POV_data.h"
// #define DISPLAY_POWER_PINS PowerPINS<bladePowerPin6> // turns power to the OLED display off once SCREEN_OFF state. (Either IDLE_OFF_TIME or PLI_OFF_TIME)

// ------ System Stuff --------

// #define ENABLE_DEBUG
// #define NO_BATTERY_MONITOR
#define ENABLE_SERIAL // Bluetooth
// #define DISABLE_COLOR_CHANGE
#define ENABLE_DEVELOPER_COMMANDS
//#define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SDA_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE
//    The following changes the angle required to register twists on curved hilts.
//    Example is for Assaj Ventress curved hilt install.
// #define ORIENTATION_ROTATION 0,-20,0

// #define CONFIG_STARTUP_DELAY 15000                 // BC now canon
#define DISABLE_BASIC_PARSER_STYLES                 // Standard, Advanced, Old School original templated styles etc...

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3.5
// #define BC_SWING_ON                               // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
// #define BC_STAB_ON
#define BC_THRUST_ON
//#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second.
#define ENABLE_SPINS
#define ENABLE_AUTO_SPINS_BLAST                   // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
// #define NO_BLADE_NO_GEST_ONOFF                   // If using blade detect, No Blade = No Gesture ignitions or retractions

// ------- Custom / Experimental / Alpha-Beta stuff ---------

// #define LOW_BATT_ONCE                            // BC - THIS NEEDS TO BE CheckLowBattery(), see PR     **Requires modified hybrid_font.h file.
// #define LOW_BATT_WARNINGS_TIERED                 // meh...just annoying if not accurate..likely.        **Requires modified hybrid_font.h file.
// #define ENABLE_GESTURE_MENU                      // PSISTORM prop - cool stuff! the TrySound else beep void.

// -------- BC Prop Other Stuff --------

// #define NO_VOLUME_MENU                           // self evident. But why?

// -------- Blaster Stuff ----------

// #define ENABLE_BLASTER_AUTO
// #define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
// #define BLASTER_JAM_PERCENTAGE 10     // if not defined, random.


#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h" // Lately, preferring #define NUM_BUTTONS 1
#endif
// #ifdef CONFIG_PROP
// #include "../props/saber_fett263_buttons.h"
// #endif

#ifdef CONFIG_PRESETS
// save mem by disabling unused aliases.
#include "aliases/TrueWhites/BC_effects_1.h"              // For Green, light Blue, ...light colored blades
#include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"  // EffectSequence driven different blast animations
#include "aliases/TrueWhites/BC_effects_2.h"              // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"            // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_White.h"          // For White blades
#include "aliases/TrueWhites/BC_12color_8effect_SS.h"     // Uses BC_SWAP for base blade color. All in one blade style from CC Fork. 96 possible blade combos in one style. .

/*
0. DarkV3 - Kyberphonic
1. Darkstar - LINK
2. Analog_Greyscale
3. Assassin_Greyscale
4. Crispity_Greyscale
5. Deadlink_Greyscale
6. Decay_Greyscale
7. EngineGrip_Greyscale
8. Exaulted_Greyscale
9. Grey_Greyscale
10. Magnetic_Greyscale
11. Noble_Greyscale
12. RA_Greyscale
13. Seethe_Greyscale
14. Splinter_Greyscale
15. Volatile_Greyscale
16. Awaken_Greyscale
17. HaloEnergySword - xtwistyboi
18. STASIS - Harry Solo
19. AGONY - Harry Solo
20. TheMaw - NoSloppy
21. Darkness - Kyberphonic
22. Battle2 - Kyberphonic
23. DeathStar - Kyberphonic
24. ProjectStardust - Kyberphonic
25. Father_V2 ANH - Kyberphonic
26. Father_V2 ESB - Kyberphonic
27. Father_V2 ROTJ - Kyberphonic
28. Father_V2 R1 - Kyberphonic
29. LothHero - Kyberphonic
30. CA_74Z - Cosmic Ape
31. AncientIntegration - Syndicate
32. DarkJedi - Syndicate
33. FirstApprentice - Syndicate
34. LoneOutcast - Syndicate
35. SithKiller - Syndicate
36. ANH_Graflex - Kyberphonic
37. ANH_Training - Kyberphonic
38. MysticMaster - BK
39. Relictron - BK
40. Party_Foul - BK
41. Arcane - TehMothman
42. CyberAssassin2 - BlueForceCompany
43. TheMatrix - Sam Tardiff - too bassy
44. Legion - BlueForceCompany
45. Protoblade - BlueForceCompany
46. Portal - NoSloppy
47. Comet - NoSloppy
48. Metropls - TheBaconWizard
49. IgnitionUltimate - BlueForceCompany
50. SithChant - Syndicate
51. Blind Master - JuanSith
*/


Preset CTAbladein [] = {

{ "a_DARKSABER/DarkV3;common;commonBU", "a_DARKSABER/DarkV3/tracks/Mandalorian.wav",
  StylePtr<Layers<
    Mix<SwingSpeed<400>,RotateColorsX<Variation,Rgb<80,100,150>>,RotateColorsX<Variation,Rgb<130,150,225>>>,
    BrownNoiseFlickerL<Stripes<5000,-300,RotateColorsX<Variation,Rgb<15,25,55>>,RotateColorsX<Variation,Rgb<60,75,120>>,RotateColorsX<Variation,Rgb<0,10,20>>,RotateColorsX<Variation,Rgb<40,50,75>>>,Int<38400>>,
    AudioFlickerL<RotateColorsX<Variation,Rgb<25,35,75>>>,
    AlphaL<RotateColorsX<Variation,Rgb<155,175,225>>,SwingSpeed<600>>,
    BC_effects_1,
    InOutTrL<TrWipe<300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// HiltPCB
  StylePtr<Black>(),
// Switches
  StylePtr<Layers<
    Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,200>,
    //InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,2500>>>>(),
    InOutTrL<TrInstant,TrInstant,ColorSequence<500,Red,Green,Blue,Black>>>>(),
// Pommel
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// Bluetooth
  StylePtr<Blue>(),
"   dark\n    v3"},


 { "testfont2a;common;commonBU", "testfont2a/tracks/track3.wav", // Accel out and in.

StylePtr<Layers<
  AudioFlicker<RotateColorsX<Variation,Rgb<0,149,255>>,RotateColorsX<Variation,Rgb<0,85,200>>>,
   BC_effects_1,
   // Accel ignition and retraction
   InOutTrL<
     TrConcat<TrInstant,Layers<
      TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<1950>>,EFFECT_IGNITION>,
      AlphaL<AudioFlicker<RotateColorsX<Variation,Rgb<0,149,255>>,RotateColorsX<Variation,Rgb<0,85,200>>>,
        SmoothStep<Scale<Trigger<EFFECT_IGNITION,Scale<Trigger<EFFECT_IGNITION,Int<2000>,Int<1>,Int<1>>,Int<300>,Int<2000>>,Int<1>,Int<1>>,Int<-1200>,Int<35000>>,Int<-3000>>>>,TrDelay<5000>>,
     TrConcat<TrInstant,Layers<
     TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<2000>>,EFFECT_RETRACTION>,
     AlphaL<AudioFlicker<RotateColorsX<Variation,Rgb<0,149,255>>,RotateColorsX<Variation,Rgb<0,85,200>>>,
       SmoothStep<Scale<Trigger<EFFECT_RETRACTION,Scale<Trigger<EFFECT_RETRACTION,Int<1000>,Int<1000>,Int<1>>,Int<3000>,Int<10>>,Int<1000>,Int<500>>,Int<35000>,Int<-1200>>,Int<-3000>>>>,TrDelay<1000>>>,
    ColorSelect<WavNum<EFFECT_PREON>,TrInstant,
      AlphaL<TransitionEffectL<TrConcat<TrInstant,Layers<
        AlphaL<RotateColorsX<Variation,Stripes<300,1,Red,Black>>,Bump<Int<0>,Scale<SmoothSoundLevel,Int<1>,Int<200>>>>,
        AlphaL<RotateColorsX<Variation,Stripes<300,1,Red,Black>>,Bump<Int<16384>,Scale<SmoothSoundLevel,Int<1>,Int<200>>>>,
        AlphaL<RotateColorsX<Variation,Stripes<300,1,Red,Black>>,Bump<Int<32768>,Scale<SmoothSoundLevel,Int<1>,Int<200>>>>,
        AlphaL<RotateColorsX<Variation,AudioFlicker<Red,Rgb<128,0,0>>>,Bump<Int<16384>,Scale<SmoothSoundLevel,Int<1>,Int<200>>>>>,TrDelay<5000>>,EFFECT_PREON>,Ifon<Int<0>,Int<32768>>>,
      // TransitionEffectL<TrConcat<TrInstant,Remap<CenterDistF<Scale<BladeAngle<>,Int<5000>,Int<28000>>>,Stripes<1000,1000,Cyan,Magenta,Yellow,Blue>>,TrDelayX<Int<6000>>>,EFFECT_PREON>,
      TransitionEffectL<TrConcat<TrInstant,Green,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
      TransitionEffectL<TrConcat<TrInstant,Blue,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
      TransitionEffectL<TrConcat<TrInstant,Yellow,TrDelayX<WavLen<>>>,EFFECT_PREON>>, 
      //TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>>,
    ColorSelect<WavNum<EFFECT_POSTOFF>,TrInstant,
      //TransitionEffectL<TrConcat<TrInstant,Rainbow,TrDelayX<Percentage<WavLen<>,80>>,Red,TrDelayX<Percentage<WavLen<>,20>>>,EFFECT_POSTOFF>, // works without. works with.
      TransitionEffectL<TrConcat<TrInstant,Red,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
      TransitionEffectL<TrConcat<TrInstant,Green,TrDelayX<WavLen<>>>,EFFECT_POSTOFF>,
      TransitionEffectL<TrConcat<TrInstant,Blue,TrDelayX<WavLen<>>>,EFFECT_POSTOFF>,
      TransitionEffectL<TrConcat<TrInstant,Yellow,TrDelayX<WavLen<>>>,EFFECT_POSTOFF>>,
      //TransitionEffectL<TrConcat<TrInstant,White,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>>,
AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,
AlphaL<Mix<HoldPeakF<BatteryLevel, Int<2000>, Int<1>>
,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,
AlphaL<Mix<HoldPeakF<BatteryLevel, Int<2000>, Int<1>>,
Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//HoldPeakF<BatteryLevel, Int<2000>, Int<1>>

>>(),

// HiltPCB
  StylePtr<Black>(),
// Switches
  StylePtr<Layers<
    Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,2500>>>>(),
// Pommel
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// Bluetooth
  StylePtr<Blue>(),
"accel-in-out\ntest1"},












//  { "Wavlen", "",

//   StylePtr<Layers<
//     Red,
//     TransitionEffectL<TrConcat< TrFadeX< Percentage<WavLen<EFFECT_FORCE>,33> >, StyleFire<Blue,Cyan>, TrInstant, Cyan, TrDelayX< Percentage<WavLen<EFFECT_FORCE>,33> >, Green, TrWipeX< Percentage<WavLen<EFFECT_FORCE>,33> >  >,EFFECT_FORCE>,
// TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Int<26000>,Int<6000>>,Int<10000>>>,TrFadeX<WavLen<>>>,EFFECT_CLASH>,
//     InOutTrL<TrWipeX<WavLen<EFFECT_IGNITION>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//     TransitionEffectL<TrConcat<TrInstant,Layers<White,AlphaL<Black,SmoothStep<Trigger<EFFECT_PREON,WavLen<>,Int<10>,Int<1>>,Int<1>>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>
//   >>(),

// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "wavlen\ntest11"},




















// { "a_BANE/RuleOfTwo;common;commonBU", "a_BANE/tracks/track3.wav", // Testing IceForce monosfx
   
//   StylePtr<Layers<
//     AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//     TransitionEffectL<TrConcat<TrFade<7000>,Rgb<0,0,75>,TrDelay<1000>>,EFFECT_USER2>,
//     TransitionEffectL<TrConcat<TrWipe<8000>,TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,
//       Sparkle<Rgb<25,105,255>,Rgb<250,250,250>,30,200>,
//       TrFade<11500>,TrDelay<20000>,EFFECT_USER2>,TrDelay<7000>,
//       Sparkle<Rgb<25,105,255>,Rgb<250,250,250>,30,200>,
//       TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>,
//     TransitionEffectL<TrConcat<TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,Int<400>,Int<50>,Int<1000>,Int<0>>,TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,Int<15000>,Int<400>,Int<8000>,Int<0>>,TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,AlphaL<Rgb<100,200,255>,Int<0>>,TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,Int<300>,Int<50>,Int<1000>,Int<0>>,TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>,TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>,
//     BC_effects_Red, 
//     InOutTrL<
//       TrConcat<TrInstant,Layers<
//       TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<1950>>,EFFECT_IGNITION>,
//       AlphaL<AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//         SmoothStep<Scale<Trigger<EFFECT_IGNITION,Scale<Trigger<EFFECT_IGNITION,Int<2000>,Int<1>,Int<1>>,Int<300>,Int<2000>>,Int<1>,Int<1>>,Int<-1200>,Int<35000>>,Int<-3000>>>>,TrDelay<5000>>,
//       TrConcat<TrInstant,Layers<
//       TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<2000>>,EFFECT_RETRACTION>,
//       AlphaL<AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//         SmoothStep<Scale<Trigger<EFFECT_RETRACTION,Scale<Trigger<EFFECT_RETRACTION,Int<1000>,Int<1000>,Int<1>>,Int<3000>,Int<10>>,Int<1000>,Int<500>>,Int<35000>,Int<-1200>>,Int<-3000>>>>,TrDelay<1000>>>,
//      TransitionEffectL<TrConcat<TrWipe<100>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<60,0,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,
//      TrDelayX< Percentage<WavLen<EFFECT_PREON>,49> >,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<60,0,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,
//      TrFadeX<  Percentage<WavLen<EFFECT_PREON>,49> >,AlphaL<HumpFlickerL<RotateColorsX<Variation,BrownNoiseFlicker<Yellow,OrangeRed,50>>,90>,SmoothStep<Int<2700>,Int<-500>>>,TrInstant>,EFFECT_PREON>,
//     // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     // Sith Crystal Red
//     Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
//     // Sith Force Red
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
//     BC_effects_2,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
//   >>(),
//   // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "rule of\ntwo"},


// { "a_DARKSABER/Darkstar;common;commonBU", "", // LINK
//   StylePtr<Layers<
//     Mix<SwingSpeed<400>,RotateColorsX<Variation,Rgb<80,100,150>>,RotateColorsX<Variation,Rgb<130,150,225>>>,
//     BrownNoiseFlickerL<Stripes<5000,-300,RotateColorsX<Variation,Rgb<15,25,55>>,RotateColorsX<Variation,Rgb<60,75,120>>,RotateColorsX<Variation,Rgb<0,10,20>>,RotateColorsX<Variation,Rgb<40,50,75>>>,Int<38400>>,
//     AudioFlickerL<RotateColorsX<Variation,Rgb<25,35,75>>>,
//     AlphaL<RotateColorsX<Variation,Rgb<155,175,225>>,SwingSpeed<600>>,
//     BC_effects_1,
//     InOutTrL<TrWipe<300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "   darkstar"},



// { "aa_Greyscale/Analog_Greyscale;common;commonBU", "",
 // StylePtr<Layers<
 //  // Ice blue audioflicker
 //    AudioFlicker<RotateColorsX<Variation,Rgb<0,149,255>>,RotateColorsX<Variation,Rgb<0,85,200>>>,
 //  // Bright cyan color swing 
 //    AlphaL<RotateColorsX<Variation,Rgb<4,255,121>>,SwingSpeed<500>>,
 //  // Hard swing ripple effect
 //    AlphaL<Stripes<2500,-4000,RotateColorsX<Variation,Rgb<0,149,255>>,RotateColorsX<Variation,Rgb<0,26,60>>,Pulsing<RotateColorsX<Variation,Rgb<0,13,30>>,Black,800>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
 //  // Sparking emitter flare
 //    AlphaL<RotateColorsX<Variation,Rgb<0,255,117>>,SmoothStep<Scale<SlowNoise<Int<2300>>,Int<1200>,Int<4500>>,Int<-4000>>>,
 //    BC_effects_1,
 //  // Bright HumpFlicker ignition effect 
 //    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<1000>>,EFFECT_IGNITION>,
 //  // Bright HumpFlicker retraction effect
 //    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<90,180,255>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
 //  // Glitch out ignition and cycle down retraction 
 //    InOutTrL<TrConcat<TrWipe<200>,AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,TrWipe<100>,Black,TrBoing<550,2>>,TrColorCycle<790>>,
 //  // Retraction cool down effect
 //    TransitionEffectL<TrConcat<TrInstant,
 //    AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<0,149,255>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2200>>,Int<1500>,Int<5000>>,Int<-4000>>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,30> >,
 //    AlphaL<RotateColorsX<Variation,Rgb<0,43,82>>,Bump<Int<0>,Int<10000>>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,30> >,
 //    AlphaL<Rgb<80,80,80>,Bump<Int<0>,Int<7000>>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,30> >>,EFFECT_RETRACTION>,
 //  // Clickity preon
 //    TransitionEffectL<TrConcat<TrFade<100>,AlphaL<Pulsing<Rgb<120,120,165>,Rgb<50,50,80>,500>,Bump<Int<0>,Int<6000>>>,TrBoing<600,9>>,EFFECT_PREON>,
 //  // On-Demand Battery Level
 //    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
 //  >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<AudioFlicker<Green,Rgb<0,128,0>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<AudioFlicker<Green,Rgb<0,128,0>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "analog"},



// { "aa_Greyscale/Assassin_Greyscale;common;commonBU", "",
  //   StylePtr<Layers<
  //   // Green humpflicker
  //     HumpFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>,50>,
  //   // Swing effect, rippling green
  //     AlphaL<Stripes<2500,-2750,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<25,60,0>>,Pulsing<RotateColorsX<Variation,Rgb<0,30,0>>,Black,800>>,SwingSpeed<375>>,
  //   // Sparking emitter flare
  //     AlphaL<RotateColorsX<Variation,Rgb<83,255,0>>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<3000>>,Int<-4000>>>,
  //     BC_effects_1,
  //   // Unstable ignition  
  //     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<149,255,15>>,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<149,255,15>>,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<500>>,EFFECT_IGNITION>,
  //   // Bright retraction
  //     TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<213,255,0>>>,TrFade<1000>>,EFFECT_RETRACTION>,
  //     InOutTrL<TrWipeSparkTip<White,250>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
  //   // On-Demand Battery Level
  //     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  //   >>(),
  // // HiltPCB
  //   StylePtr<Black>(),
  // // Switches
  //   StylePtr<Layers<
  //     Pulsing<AudioFlicker<Green,Rgb<0,128,0>>,Black,200>,
  //     InOutTrL<TrInstant,TrInstant,Pulsing<AudioFlicker<Green,Rgb<0,128,0>>,Black,2500>>>>(),
  // // Pommel
  //   StylePtr<Layers<
  //     Pulsing<Blue,Black,200>,
  //     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
  // // Bluetooth
  //   StylePtr<Blue>(),
  // "assassin"},



// { "aa_Greyscale/Crispity_Greyscale;common;commonBU", "",
//   StylePtr<Layers<
//   // Main Blade
//      // Custom base Cyan + Purple
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<39,5,71>>,Pulsing<RotateColorsX<Variation,Rgb<0,200,200>>,  RotateColorsX<Variation,Rgb<95,0,225>>,800>,  RotateColorsX<Variation,Rgb<0,200,200>>>,
//     // Custom Force Cyan
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<0,200,200>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,  RotateColorsX<Variation,Rgb<95,0,225>>, TrFade<800>>,EFFECT_FORCE>,
//     // Jedi Swing Purple
//     AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,  Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,

//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrInstant,HumpFlicker<White,Black,75>,TrSmoothFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWipeInX<Int<400>>>,TrWipeInSparkTip<White,200>>,
//     TransitionEffectL<TrConcat<
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<70>>, TrWaveX<Cyan,           Int<70>, Int<80>,Int<70>, Int<32768>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<32768>,Int<4000>>>,TrFade<100>>,TrWaveX<Rgb<160,60,255>,Int<100>,Int<80>,Int<100>,Int<32768>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<130>>,TrWaveX<Cyan,           Int<130>,Int<100>,Int<130>,Int<32768>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<32768>,Int<4000>>>,TrFade<150>>,TrWaveX<Rgb<160,60,255>,Int<150>,Int<110>,Int<150>,Int<32768>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<160>>,TrWaveX<Cyan,           Int<160>,Int<110>,Int<160>,Int<32768>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<32768>,Int<4000>>>,TrFade<170>>,TrWaveX<Rgb<160,60,255>,Int<170>,Int<100>,Int<170>,Int<32768>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<190>>,TrWaveX<Cyan,           Int<190>,Int<140>,Int<190>,Int<32768>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<32768>,Int<4000>>>,TrFade<210>>,TrWaveX<Rgb<160,60,255>,Int<210>,Int<160>,Int<210>,Int<32768>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<240>>,TrWaveX<Cyan,           Int<240>,Int<180>,Int<240>,Int<32768>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<32768>,Int<4000>>>,TrFade<300>>,TrWaveX<Rgb<160,60,255>,Int<300>,Int<200>,Int<300>,Int<32768>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<340>>,TrWaveX<Cyan,           Int<340>,Int<230>,Int<340>,Int<32768>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<32768>,Int<4000>>>,TrFade<400>>,TrWaveX<Rgb<160,60,255>,Int<420>,Int<250>,Int<420>,Int<32768>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<450>>,TrWaveX<Cyan,           Int<520>,Int<300>,Int<520>,Int<32768>>>,Black,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Sin<Scale<Trigger<EFFECT_RETRACTION,Int<3000>,Int<1000>,Int<500>>,Int<550>,Int<70>>>,Cyan,Rgb<160,60,255>>,Bump<Scale<Trigger<EFFECT_RETRACTION,Int<3000>,Int<1000>,Int<500>>,Int<-8000>,Int<2000>>>>,TrDelay<3000>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrDelay<3000>,White,TrDelay<50>>,EFFECT_RETRACTION>,

//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Sin<Scale<Trigger<EFFECT_PREON,Int<3000>,Int<1000>,Int<500>>,Int<70>,Int<550>>>,Cyan,Rgb<160,60,255>>,Bump<Scale<Trigger<EFFECT_PREON,Int<3000>,Int<1000>,Int<500>>,Int<41000>,Int<32768>>>>,TrDelay<3000>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<520>>,TrWaveX<Cyan,Int<520>,Int<550>,Int<520>,Int<0>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<0>,Int<4000>>>,TrFade<420>>,TrWaveX<Rgb<160,60,255>,Int<420>,Int<450>,Int<420>,Int<0>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<340>>,TrWaveX<Cyan,Int<340>,Int<430>,Int<340>,Int<0>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<0>,Int<4000>>>,TrFade<300>>,TrWaveX<Rgb<160,60,255>,Int<300>,Int<400>,Int<300>,Int<0>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<240>>,TrWaveX<Cyan,Int<240>,Int<380>,Int<240>,Int<0>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<0>,Int<4000>>>,TrFade<210>>,TrWaveX<Rgb<160,60,255>,Int<210>,Int<360>,Int<210>,Int<0>>>,AlphaL<Black,Int<0>>,       // If Pulsing emitter doesn't really like the Trigger, then need to do this need this
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<190>>,TrWaveX<Cyan,Int<190>,Int<340>,Int<190>,Int<0>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<0>,Int<4000>>>,TrFade<170>>,TrWaveX<Rgb<160,60,255>,Int<170>,Int<320>,Int<170>,Int<0>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<160>>,TrWaveX<Cyan,Int<160>,Int<300>,Int<160>,Int<0>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<0>,Int<4000>>>,TrFade<150>>,TrWaveX<Rgb<160,60,255>,Int<150>,Int<250>,Int<150>,Int<0>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<130>>,TrWaveX<Cyan,Int<130>,Int<150>,Int<130>,Int<0>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<0>,Int<4000>>>,TrFade<100>>,TrWaveX<Rgb<160,60,255>,Int<100>,Int<100>,Int<100>,Int<0>>>,AlphaL<Black,Int<0>>,
//       TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<70>>,TrWaveX<Cyan,Int<70>,Int<500>,Int<70>,Int<0>>>,Black,TrInstant>,EFFECT_PREON>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(), 
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<Pulsing<RotateColorsX<Variation,Rgb<0,200,200>>,  RotateColorsX<Variation,Rgb<95,0,225>>,800>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Pulsing<RotateColorsX<Variation,Rgb<0,200,200>>,  RotateColorsX<Variation,Rgb<95,0,225>>,800>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "crispity\ngreyscale"},



// { "aa_Greyscale/Deadlink_Greyscale;common;commonBU", "",
//   StylePtr<Layers<
//   // Magenta HumpFlicker
//     HumpFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<150,0,150>>,50>,
//   // Ripple swing effect
//     AlphaL<Stripes<2500,-3000,RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,Rgb<49,0,70>>,Pulsing<RotateColorsX<Variation,Rgb<10,0,26>>,Black,800>>,SwingSpeed<350>>,
//   // Sparking emitter flare
//     AlphaL<RotateColorsX<Variation,Rgb<129,0,255>>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<3500>>,Int<-4000>>>,
//     BC_effects_Red,
//   // Unstable ignition effect
//   TransitionEffectL<TrConcat<TrDelay<875>,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,0,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,0,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFade<250>,HumpFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<80,0,80>>,50>,TrFade<400>,Stripes<3000,-3500,RotateColorsX<Variation,DeepPink>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,0,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFade<1500>>,EFFECT_IGNITION>,
//   // Bright HumpFlicker retraction effect 
//   TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<180,60,255>>,40>,TrFade<2000>>,EFFECT_RETRACTION>,
//   // Lightning strike ignition, cycle down retraction
//   InOutTrL<TrConcat<TrWipeIn<200>,RandomBlink<30000,RotateColorsX<Variation,Rgb<255,53,255>>>,TrWipeIn<200>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,Int<1000>,Int<6000>>,Int<-3000>>,Black,RotateColorsX<Variation,Rgb<255,53,255>>>,TrDelay<400>,Mix<SmoothStep<Int<4000>,Int<-3000>>,Black,White>,TrWipe<175>>,TrColorCycle<2000>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<AudioFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<150,0,150>>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<AudioFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<150,0,150>>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "deadlink"},



// { "aa_Greyscale/Decay_Greyscale;common;commonBU", "", // Custom BC/Facebook style
//   StylePtr<Layers<
//   //Alternate darker purple absorb effect, color change friendly (for reds and such)
//     StripesX<Int<3500>,Int<-1200>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<75,0,165>>>,Mix<Sin<Int<23>>,RotateColorsX<Variation,Rgb<52,0,125>>,RotateColorsX<Variation,Rgb<84,0,210>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Rgb<115,0,220>>,RotateColorsX<Variation,Rgb<95,0,210>>>,Mix<Sin<Int<18>>,RotateColorsX<Variation,Rgb<26,0,42>>,RotateColorsX<Variation,Rgb<60,0,132>>>>,
//   //Unstable swing
//     AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,300>,SwingSpeed<400>>,
//   //Ripple down swing
//     AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black>,Black,RotateColorsX<Variation,Rgb<95,0,210>>,Black>,SwingSpeed<500>>,
//   //Bright hard swings
//     AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrInstant,StyleFire<Mix<Int<16384>,Rgb<30,0,30>,Black>,White,0,6,FireConfig<0,3000,5>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,3000,5>>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrInstant,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//     AlphaL<Layers<
//       TransitionEffectL<TrConcat<TrFade<600>,Layers<
//         ColorCycle<AudioFlicker<SpringGreen,Rgb<0,150,0>>,30,30,Black,0,0,1>,
//         AlphaL<BrownNoiseFlicker<Black,Rgb<30,0,30>,500>,Int<16384>>>,TrDelay<10400>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<3000>,AlphaL<Black,Int<0>>,TrColorCycle<8000,50,500>,AudioFlicker<SpringGreen,Rgb<0,150,0>>,TrInstant>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<8000>,AlphaL<Black,Int<0>>,TrFade<2000>,StyleFire<Mix<Int<16384>,Rgb<30,0,30>,Black>,White,0,6,FireConfig<0,0,0>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<0,3000,5>>,TrDelay<1000>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrInstant,
//       AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<16384>,Scale<SlowNoise<Int<3000>>,Int<20000>,Int<50000>>>>,TrFade<750>,
//       AlphaL<Black,Int<0>>,TrDelay<3650>,
//       AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<16384>,Scale<SlowNoise<Int<3000>>,Int<20000>,Int<50000>>>>,TrDelay<50>,
//       AlphaL<Black,Int<0>>,TrDelay<50>,
//       AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<16384>,Scale<SlowNoise<Int<3000>>,Int<20000>,Int<50000>>>>,TrFade<600>,
//       AlphaL<Black,Int<0>>,TrDelay<900>,
//       AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<16384>,Scale<SlowNoise<Int<3000>>,Int<20000>,Int<50000>>>>,TrFade<500>,
//       AlphaL<Black,Int<0>>,TrDelay<1350>,
//       AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<16384>,Scale<SlowNoise<Int<3000>>,Int<20000>,Int<50000>>>>,TrFade<500>>,EFFECT_PREON>>,Ifon<Int<0>,Int<32768>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<AudioFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<75,0,165>>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<AudioFlicker<SpringGreen,Rgb<0,150,0>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "decay"},



// { "aa_Greyscale/EngineGrip_Greyscale;common;commonBU", "",
// // EngineGrip_blade - BC 5-4-2021
//   StylePtr<Layers<Black,
//     AlphaL<Stripes<6000,1000,Red,Rgb<59,3,3>,Rgb<255,100,75>>,Int<16384>>,
//     AlphaL<Stripes<3000,-4000,Red,Rgb<59,3,3>,HotPink>,Int<16384>>,
//     AlphaL<StrobeX<Black,OrangeRed,Scale<SlowNoise<Int<3000>>,Int<20>,Int<100>>,Scale<SlowNoise<Int<4000>>,Int<30>,Int<100>>>,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrDelay<200>,Strobe<Black,HumpFlicker<LemonChiffon,Red,50>,15,40>,TrJoin<TrWipeInSparkTip<White,800,200>,TrWipeSparkTip<White,800,200>>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrInstant,Mix<SmoothStep<Int<8000>,Int<10000>>,Stripes<3000,3000,Black,Rgb<137,26,1>>,Stripes<2000,3000,Black,HotPink>>,TrDelay<500>>,EFFECT_RETRACTION>,
//     InOutTrL<TrJoin<TrJoin<TrWipeIn<800>,TrWaveX<BrownNoiseFlicker<OrangeRed,LemonChiffon,100>,Int<800>,Int<100>,Int<800>,Int<32768>>>,TrJoin<TrWipe<800>,TrWaveX<BrownNoiseFlicker<OrangeRed,LemonChiffon,100>,Int<400>,Int<100>,Int<800>,Int<0>>>>,TrJoin<TrJoin<TrWipeIn<1700>,TrWaveX<BrownNoiseFlicker<OrangeRed,LemonChiffon,100>,Int<2000>,Int<400>,Int<1700>,Int<32768>>>,TrWaveX<StrobeX<Black,BrownNoiseFlicker<OrangeRed,LemonChiffon,100>,Scale<SlowNoise<Int<3000>>,Int<20>,Int<100>>,Int<40>>,Int<2000>,Int<100>,Int<1700>,Int<32768>>>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<50>,Black,TrJoin<TrWipe<800>,TrWaveX<StrobeX<Black,HumpFlicker<Rgb<255,200,0>,Rgb<150,30,70>,50>,Scale<SlowNoise<Int<3000>>,Int<20>,Int<100>>,Int<40>>,Int<1220>,Int<90>,Int<800>,Int<0>>>,AlphaL<StrobeX<Black,OrangeRed,Scale<SlowNoise<Int<3000>>,Int<20>,Int<100>>,Scale<SlowNoise<Int<4000>>,Int<30>,Int<100>>>,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,TrDelay<420>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrDelay<1700>,White,TrFade<55>>,EFFECT_RETRACTION>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<Stripes<6000,1000,Red,Rgb<59,3,3>,Rgb<255,100,75>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Stripes<6000,1000,Red,Rgb<59,3,3>,Rgb<255,100,75>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "engine\ngrip"},



// { "aa_Greyscale/Exaulted_Greyscale;common;commonBU", "",
//   StylePtr<Layers<
//     Stripes<3000,-3000,Rgb<100,100,150>,Rgb<25,25,40>,ColorChange<TrDelay<400>,Rgb<130,130,180>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow,Mix<TwistAngle<1>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow>>,Rgb<50,50,75>>,
//     AlphaL<ColorChange<TrWipeIn<400>,Rgb<130,130,180>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow,Mix<TwistAngle<1>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow>>,SmoothStep<Int<4000>,Int<-6000>>>,
//     TransitionEffectL<TrWaveX<ColorChange<TrInstant,Rgb<130,130,180>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow,White>,Int<400>,Int<100>,Int<400>,Int<32768>>,EFFECT_CHANGE>,
//     BC_effects_White,
//     InOutTrL<TrWipe<150>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//     TransitionEffectL<TrConcat<TrWaveX<Rgb<95,0,210>,Int<400>,Int<200>,Int<300>,Int<32768>>,AlphaL<PulsingL<Rgb<95,0,210>,Int<1000>>,SmoothStep<Int<2000>,Int<-3000>>>,TrDelay<1000>,AlphaL<PulsingL<Rgb<95,0,210>,Int<1000>>,SmoothStep<Int<2000>,Int<-3000>>>,TrWaveX<Blue,Int<400>,Int<200>,Int<300>,Int<32768>>,AlphaL<PulsingL<ColorSequence<400,Rgb<95,0,210>,Blue>,Int<1000>>,SmoothStep<Int<2000>,Int<-3000>>>,TrDelay<800>,AlphaL<PulsingL<ColorSequence<400,Blue,Rgb<95,0,210>>,Int<1000>>,SmoothStep<Int<2000>,Int<-3000>>>,TrWaveX<Red,Int<350>,Int<200>,Int<350>,Int<32768>>,AlphaL<PulsingL<ColorSequence<350,Blue,Rgb<95,0,210>,Red>,Int<800>>,SmoothStep<Int<2000>,Int<-3000>>>,TrDelay<800>,AlphaL<PulsingL<ColorSequence<350,Red,Blue,Rgb<95,0,210>>,Int<800>>,SmoothStep<Int<2000>,Int<-3000>>>,TrWaveX<DarkOrange,Int<350>,Int<400>,Int<350>,Int<32768>>,AlphaL<PulsingL<ColorSequence<350,Red,Blue,Rgb<95,0,210>,DarkOrange>,Int<700>>,SmoothStep<Int<2000>,Int<-3000>>>,TrDelay<700>,AlphaL<PulsingL<ColorSequence<350,DarkOrange,Red,Blue,Rgb<95,0,210>>,Int<700>>,SmoothStep<Int<2000>,Int<-3000>>>,TrWaveX<Green,Int<300>,Int<400>,Int<300>,Int<32768>>,AlphaL<PulsingL<ColorSequence<300,Red,Blue,Rgb<95,0,210>,DarkOrange,Green>,Int<600>>,SmoothStep<Int<2000>,Int<-3000>>>,TrDelay<700>,AlphaL<PulsingL<ColorSequence<300,Green,Red,Blue,Rgb<95,0,210>,DarkOrange>,Int<600>>,SmoothStep<Int<2000>,Int<-3000>>>,TrWaveX<Yellow,Int<300>,Int<400>,Int<300>,Int<32768>>,AlphaL<PulsingL<ColorSequence<250,Red,Blue,Rgb<95,0,210>,DarkOrange,Green,Yellow>,Int<400>>,SmoothStep<Int<2000>,Int<-3000>>>,TrDelay<600>,AlphaL<PulsingL<ColorSequence<200,Yellow,Red,Blue,Rgb<95,0,210>,DarkOrange,Green>,Int<500>>,SmoothStep<Int<2000>,Int<-3000>>>,TrDelay<1250>>,EFFECT_PREON>,
//     // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//   AudioFlicker<BrownNoiseFlicker<Mix<SwingSpeed<400>,Rgb<100,100,150>,ColorChange<TrFade<400>,Rgb<130,130,180>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow,Mix<TwistAngle<1>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow>,Rgb<50,50,75>>>,Stripes<5000,-300,ColorChange<TrFade<400>,Rgb<130,130,180>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow,Mix<TwistAngle<1>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow>,Rgb<50,50,75>>,ColorChange<TrFade<400>,Rgb<130,130,180>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow,Mix<TwistAngle<1>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow>,Rgb<50,50,75>>,Rgb<10,10,20>,Rgb<50,50,75>>,300>,Rgb<35,35,75>>,
//   InOutTrL<TrWipe<300>,TrFade<400>,Pulsing<ColorChange<TrFade<400>,Rgb<130,130,180>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow,Mix<TwistAngle<1>,Rgb<95,0,210>,Blue,Red,DarkOrange,Green,Yellow>,Rgb<50,50,75>>,Black,3000>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "thanos\nexaulted"},



// { "aa_Greyscale/Grey_Greyscale;common;commonBU", "",
//   StylePtr<Layers<
//    // White audioflicker
//     AudioFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<50,50,75>>>,
//   // Swing effect, white ripple
//     AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Black>,White,RotateColorsX<Variation,Rgb<100,100,150>>,White>,SwingSpeed<450>>,
//     BC_effects_1,  
//   // Unstable ignition effect
//     TransitionEffectL<TrConcat<TrInstant,TransitionEffect<White,Azure,TrInstant,TrFade<500>,EFFECT_LOCKUP_BEGIN>,TrFade<1000>,Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<575>,TransitionEffect<Rgb<95,95,95>,Rgb<68,93,93>,TrInstant,TrFade<100>,EFFECT_LOCKUP_BEGIN>,TrFade<300>,Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<1100>>,EFFECT_IGNITION>,
//   // Bright humpflicker retraction effect
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>,
//   // Spark tip ignition and retraction 
//     InOutTrL<TrJoin<TrWipe<1500>,TrWaveX<DeepSkyBlue,Int<2000>,Int<400>,Int<1500>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<AudioFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<50,50,75>>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<AudioFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<50,50,75>>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "grey"},



// { "aa_Greyscale/Magnetic_Greyscale;common;commonBU", "",
//   StylePtr<Layers<
//   // Blue audioflicker lava lamp
//     AudioFlicker<StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<25>,Int<80>>,Pulsing<RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb<0,132,81>>,3000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb<0,63,200>>,RotateColorsX<Variation,Rgb<0,7,8>>>>,RotateColorsX<Variation,Rgb<0,39,40>>,Pulsing<RotateColorsX<Variation,Rgb<0,36,30>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb<50,130,255>>>,RotateColorsX<Variation,Rgb<0,70,56>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,38,30>>,3000>>,AlphaL<StripesX<Sin<Int<8>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<60>,Int<140>>,StripesX<Sin<Int<6>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<-25>,Int<-80>>,Pulsing<Mix<Sin<Int<4>>,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb<50,130,255>>>,RotateColorsX<Variation,Rgb<0,12,14>>,4000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb<50,130,255>>,Black>>,RotateColorsX<Variation,Rgb<0,39,40>>,Pulsing<RotateColorsX<Variation,Rgb<0,26,40>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<-25>,Int<-75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb<7,192,255>>>,RotateColorsX<Variation,Rgb<0,30,96>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,16,50>>,3000>>,Int<10000>>>,
//   // Unstable, audio responsive swing. Force effect triggers a brief "charge up" effect while swinging which works well with the overcharged smooth swing
//     AlphaL<AudioFlickerL<AlphaL<Mix<Trigger<EFFECT_FORCE,Int<4000>,Int<3800>,Int<200>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<128,0,255>>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<170,0,255>>,RotateColorsX<Variation,Rgb<37,0,56>>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Cyan>,RotateColorsX<Int<4000>,RotateColorsX<Variation,DeepSkyBlue>>>,RotateColorsX<Variation,Rgb<170,0,255>>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>>,SwingSpeed<450>>,
//   // Sparking emitter flare 
//     AlphaL<RotateColorsX<Variation,Rgb<44,0,255>>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<4000>>,Int<-4000>>>,
//     BC_effects_1,
//   // Charge up ignition effect
//     TransitionEffectL<TrConcat<TrFade<1040>,RotateColorsX<Variation,Rgb<9,3,70>>,TrInstant,RotateColorsX<Variation,Cyan>,TrFade<550>>,EFFECT_IGNITION>,
//   // Purple retraction
//     TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<158,13,255>>>,TrFade<1000>>,EFFECT_RETRACTION>,
//     InOutTrL<TrJoin<TrWipeX<Int<1040>>,TrWaveX<White,Int<1400>,Int<400>,Int<1040>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,150>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Cyan>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Cyan>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "magnetic"},



// { "aa_Greyscale/Noble_Greyscale;common;commonBU", "",
//   StylePtr<Layers<
//   // Slightly different shades of yellow travel very slowly up the blade
//     Stripes<5000,-75,RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<200,120,0>>,RotateColorsX<Variation,Rgb<220,160,40>>,RotateColorsX<Variation,Rgb<170,95,0>>>,
//   // Alternate swing effects, triggering the force effect toggles between unstable white ripple and color change swings
//     EffectSequence<EFFECT_FORCE,AlphaL<Mix<Sin<Int<1>>,ColorChange<TrInstant,Red>,Green,Blue,Red>,SwingSpeed<600>>,AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black>,White,RotateColorsX<Variation,Rgb<95,0,210>>,White>,SwingSpeed<600>>>,
//   // Bright emitter flare
//     AlphaL<RotateColorsX<Variation,LemonChiffon>,Bump<Int<0>,Int<10000>>>,
//     BC_effects_1,
//   // Bright HumpFlicker ignition effect
//   TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_IGNITION>,
//   // Spark tip out ignition and retraction
//   InOutTrL<TrWipeSparkTip<White,350>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,150>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Cyan>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Cyan>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "noble"},



// { "aa_Greyscale/RA_Greyscale;common;commonBU", "",
//   StylePtr<Layers<
//   // Magenta audioflicker
//     AudioFlicker<RotateColorsX<Variation,Rgb<255,0,128>>,RotateColorsX<Variation,Rgb<180,0,120>>>,
//   // Ripple audioflicker swing
//     AlphaL<AudioFlickerL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<230,0,35>>,Black>,Black,RotateColorsX<Variation,Rgb<230,0,35>>,Black>>,SwingSpeed<350>>,
//   // Sparking emitter flare
//     AlphaL<RotateColorsX<Variation,DeepPink>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<3000>>,Int<-4000>>>,
//     BC_effects_Red,
//   // Color cycle ignition and retraction
//     InOutTrL<TrColorCycle<3000,3000,0>,TrColorCycle<1250>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Rgb<255,0,128>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<255,0,128>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "ra"},



// { "aa_Greyscale/Seethe_Greyscale;common;commonBU", "",
//   StylePtr<Layers<
//   // Red audioflicker
//     AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,0,0>>>,
//   // Force effect, temporarily allows a swing effect where solid dark orange takes over the blade when swinging
//     TransitionEffectL<TrConcat<TrFade<200>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,SwingSpeed<500>>,TrDelay<30000>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,SwingSpeed<500>>,TrFade<800>>,EFFECT_FORCE>,
//   // Unstable swing
//     AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>,SwingSpeed<315>>,
//   // Timed "breathing" emitter flare
//     Mix<Sin<Int<8>>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,Bump<Int<0>,Int<6000>>>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,Bump<Int<0>,Int<22000>>>>,
//     BC_effects_Red,
//   // Wipe out ignition, wipe in retraction
//     InOutTrL<TrWipe<2650>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Red>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Red>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "seethe"},



// { "aa_Greyscale/Splinter_Greyscale;common;commonBU", "",
//   StylePtr<Layers<
//   // Split blade, orange audioflicker with a rolling pulse at the emitter, which takes over the blade more the harder you swing
//     Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,Stripes<5000,-1300,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<60,17,0>>,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<128,34,0>>>,AudioFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<168,54,0>>>>,
//   // Unstable swing
//     AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,DarkOrange>,Black,300>,SwingSpeed<600>>,
//     BC_effects_1,
//   // Unstable ignition with splinter effect
//     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<255,229,21>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,17,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<255,178,110>>,RotateColorsX<Variation,Rgb<60,17,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,34,0>>,RotateColorsX<Variation,Rgb<60,17,0>>>>,TrFade<2700>>,EFFECT_IGNITION>,
//   // Bright HumpFlicker retraction
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,229,21>>,40>,TrFade<1100>>,EFFECT_RETRACTION>,
//   //Spark tip ignition and retraction
//     InOutTrL<TrWipeSparkTip<White,300>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,150>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Red>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Red>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "splinter"},



// { "aa_Greyscale/Volatile_Greyscale;common;commonBU", "",

//   StylePtr<Layers<
//   // Rotates 1 time per minute between blue and green audioflicker
//     Mix<Sin<Int<1>>,AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,AudioFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>>,
//   // Alternate swing - Rotates 2 times per minute between unstable ripple blue and green, so the blue and green don't always match up with the base layer, allowing for multiple mixes of blue/green
//     AlphaL<Mix<Sin<Int<2>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,Black>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Green>,Black>,RotateColorsX<Variation,Rgb<0,45,0>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,45,0>>>>,SwingSpeed<400>>,
//     AlphaL<Mix<Sin<Int<2>>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,300>,SwingSpeed<400>>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Green>,Black,300>,SwingSpeed<400>>>,SwingSpeed<400>>,
//     BC_effects_1,
//   // Spark tip ignition, wipe in retraction
//     InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // Preon, reacts to sound level
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<3000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Blue>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,3,89>>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Blue>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Cyan>>>,RotateColorsX<Variation,Green>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-2500>,Int<17500>>,Int<-4000>>>,TrDelay<6500>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Green>,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Pulsing<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Green>,1250>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "volatile"},



// { "aa_Greyscale/Awaken_Greyscale;common;commonBU", "",
//   StylePtr<Layers<
//   // Base lava ^lamp style, has a very subtle dim 25 times a minute
//     Mix<Sin<Int<25>>,StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<25>,Int<80>>,Pulsing<RotateColorsX<Variation,Rgb<255,41,0>>,RotateColorsX<Variation,OrangeRed>,3000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb<77,4,0>>,RotateColorsX<Variation,Rgb<77,0,0>>>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<255,25,0>>>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<50,0,0>>,3000>>,StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<25>,Int<80>>,Pulsing<RotateColorsX<Variation,Rgb<130,18,0>>,RotateColorsX<Variation,Rgb<130,9,0>>,3000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb<77,4,0>>,RotateColorsX<Variation,Rgb<77,1,0>>>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<140,0,0>>>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<50,0,0>>,3000>>>,
//   // Underlying lava lamp layer
//     AlphaL<StripesX<Sin<Int<8>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<60>,Int<140>>,StripesX<Sin<Int<6>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<-25>,Int<-80>>,Pulsing<Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,OrangeRed>>,RotateColorsX<Variation,Rgb<20,0,0>>,4000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,DarkOrange>,Black>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,0>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<-25>,Int<-75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<255,25,0>>>,RotateColorsX<Variation,Rgb<96,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,Black,3000>>,Int<10000>>,
//   // Swing effect, fades from red at slow swings to dark orange at slightly harder swings
//     AlphaL<AudioFlickerL<Mix<SwingSpeed<600>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Rgb<255,41,0>>>>,Scale<SwingSpeed<405>,Int<0>,Int<32768>>>,
//   // Hard swing effect, hard swings cause dark orange to ripple up the blade
//     AlphaL<Stripes<2500,-2700,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<60,10,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,5,0>>,Black,800>>,Scale<IsLessThan<SwingSpeed<625>,Int<13600>>,Scale<SwingSpeed<625>,Int<-19300>,Int<32768>>,Int<0>>>,
//   // Sparking emitter flare
//     AlphaL<RotateColorsX<Variation,Rgb<255,41,0>>,SmoothStep<Scale<SlowNoise<Int<2750>>,Int<1750>,Int<3750>>,Int<-4000>>>,
//     BC_effects_1,
//   // Unstable orange ignition effect
//     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Orange>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<255,25,0>>,RotateColorsX<Variation,Rgb<60,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>>,TrFade<895>>,EFFECT_IGNITION>,
//   // Sparkle beep ignition effect
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<White,SparkleF<200>>,TrFade<1000>>,EFFECT_IGNITION>,
//   // Orange humpflicker retraction effect
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,DarkOrange>,40>,TrFade<1071>>,EFFECT_RETRACTION>,
//   // White spark tip ignition and retraction
//     InOutTrL<TrJoin<TrWipe<300>,TrWaveX<White,Int<900>,Int<400>,Int<300>,Int<0>>>,TrJoin<TrWipeInX<Int<1071>>,TrWaveX<White,Int<2000>,Int<400>,Int<1071>,Int<32768>>>>,
//   // Clicky retraction "post off" effect
//     TransitionEffectL<TrConcat<TrDelay<1071>,AlphaL<Pulsing<Rgb<120,120,165>,Rgb<50,50,80>,60>,Bump<Int<0>,Int<6000>>>,TrDelay<500>>,EFFECT_RETRACTION>,
//   //Sparkle beep charge-up preon
//     TransitionEffectL<TrConcat<TrFade<350>,Black,TrFade<2150>,AlphaL<PulsingX<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,Int<50>>,Bump<Int<0>,Int<7750>>>,TrBoing<1500,5>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<255,25,0>>,RotateColorsX<Variation,Rgb<255,25,0>>,500>,Bump<Int<0>,Int<9750>>>,TrBoing<1250,7>,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,OrangeRed>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<3750>>,Int<1500>,Int<4200>>,Int<-4000>>>,TrDelay<2850>,AlphaL<Pulsing<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<42,7,0>>,60>,Bump<Int<0>,Int<17500>>>,TrDelay<800>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrDelay<4250>,AlphaL<Mix<Trigger<EFFECT_PREON,Int<1000>,Int<1000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<255,41,0>>,Rgb<102,0,0>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Red>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Red>>>,Rgb<255,41,0>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-350>,Int<25250>>,Int<-4000>>>,TrDelay<4750>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrDelay<8500>,AlphaL<White,SparkleF<200>>,TrFade<500>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Rgb<255,41,0>>,RotateColorsX<Variation,OrangeRed>,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<255,41,0>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "awaken\ngreyscale"},

// // Halo presets

// { "HaloEnergySword;common;commonBU", "HaloEnergySword/tracks/Halo.wav",
//   StylePtr<Layers<
//     StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,LightPink>,3>,RotateColorsX<Variation,SteelBlue>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
//     BC_effects_1,
//     InOutTrL<TrConcat<TrDelay<300>,Black,TrWipe<300>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<400>,Int<300>,Int<32768>>>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrDelay<50>,AlphaL<White,Int<0>>,TrFade<250>,AlphaL<RandomFlicker<Cyan,Blue>,Bump<Int<0>,Int<35000>>>,TrJoin<TrFade<300>,TrWaveX<White,Int<800>,Int<200>,Int<300>,Int<0>>>>,EFFECT_IGNITION>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(), 
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<BrownNoiseFlicker<RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,LightPink>,3>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<BrownNoiseFlicker<RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,LightPink>,3>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "energy\nsword"},



// { "aa_HarrySolo/STASIS;common;commonBU", "aa_HarrySolo/STASIS/tracks/stasis.wav", // Halo theme
//   StylePtr<Layers<
//     Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,AudioFlicker<RotateColorsX<Variation,Rgb<24,7,51>>,RotateColorsX<Variation,Rgb<56,0,255>>>,StyleFire<RotateColorsX<Variation,Rgb16<26511,4702,65535>>,HumpFlicker<RotateColorsX<Variation,Rgb16<25487,5257,63295>>,Rgb16<3131,1305,5845>,15>,0,3,FireConfig<1,2000,6>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<35>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<35>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<35>>,EFFECT_BLAST>,
//     BlastL<White,850,250,351>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<255,70,70>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//     BlastL<White,300,350,100000>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,50>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//       AlphaL<StrobeX<Black,White,Scale<SlowNoise<Int<1000>>,Int<0>,Int<2>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>,Int<20000>>,
//       AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//       AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,AlphaL<Mix<SmoothStep<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<1000>>,Stripes<2500,2000,TransitionEffect<White,Azure,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Rgb<95,0,210>>,Stripes<2500,-2500,TransitionEffect<White,Azure,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Rgb<95,0,210>>>,Int<18000>>,TrFade<600>>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     LockupTrL<Layers<
//       Stripes<3000,-2000,RandomBlink<30000,Strobe<Rgb<125,125,225>,White,50,1>,Rgb<75,75,150>>,RandomPerLEDFlicker<Rgb<20,20,100>,Rgb<100,100,150>>>,
//       AlphaL<StrobeX<AlphaL<Black,Int<0>>,White,Scale<SlowNoise<Int<1000>>,Int<0>,Int<7>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>,Int<22000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,TrJoin<TrWipe<300>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>>>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     LockupTrL<AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<35>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
//     AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Bump<Int<0>,Scale<TwistAngle<>,Int<2000>,Int<10000>>>>,
//     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,60,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<200,100,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,80>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFade<1200>>,EFFECT_IGNITION>,
//     AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<2400>>,Int<22000>,Int<40000>>,Int<22000>>>,
//     InOutTrL<TrColorCycle<600>,TrWipeIn<200>>,
//     TransitionEffectL<TrConcat<TrFade<650>,BlinkingL<Rgb<128,100,128>,Int<100>,Int<500>>,TrFade<1000>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrFade<800>,AlphaL<Blinking<Rgb<56,0,255>,Black,100,500>,Bump<Int<0>,Int<20000>>>,TrConcat<TrInstant,AlphaL<Blinking<Rgb<56,0,255>,Black,100,500>,Bump<Int<0>,Int<20000>>>,TrFade<250>,AlphaL<Blinking<Rgb<56,0,255>,Black,100,200>,SmoothStep<Int<16000>,Int<-8000>>>,TrInstant,White,TrDelay<50>>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrDelay<200>,Layers<
//       AlphaL<Stripes<300,4500,Black,Black,Rgb<95,0,210>>,SmoothStep<Int<16384>,Int<0>>>,
//       AlphaL<Stripes<300,-4500,Black,Black,Rgb<95,0,210>>,SmoothStep<Int<16385>,Int<-1>>>>,TrJoin<TrJoin<TrWipeIn<800>,TrWaveX<Rgb<95,0,210>,Int<400>,Int<500>,Int<800>,Int<32768>>>,TrJoin<TrWipe<800>,TrWaveX<Rgb<95,0,210>,Int<400>,Int<500>,Int<800>,Int<0>>>>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<Black,Rgb<95,0,210>,15,40>,TrFade<250>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrDelay<650>,AlphaL<Black,Int<0>>,TrFade<88>,Rgb<95,0,210>,TrInstant,White,TrDelay<50>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     AudioFlicker<RotateColorsX<Variation,Rgb<24,7,51>>,RotateColorsX<Variation,Rgb<56,0,255>>>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<AudioFlicker<RotateColorsX<Variation,Rgb<24,7,51>>,RotateColorsX<Variation,Rgb<56,0,255>>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "stasis"},



// { "aa_HarrySolo/AGONY;common;commonBU", "",
//   StylePtr<Layers<
//     HumpFlicker<Blue,Stripes<22000,-100,RotateColorsX<Variation,Rgb<48,0,105>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<22,0,49>>>,10>,
//     BC_effects_Red,
//     InOutTrL<TrJoin<TrWipeX<Int<600>>,TrWaveX<White,Int<1200>,Int<400>,Int<600>,Int<0>>>,
//              TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,150>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
     
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<200>>,EFFECT_IGNITION>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,10>,Bump<Int<0>,Int<4000>>>,TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,15>,Bump<Int<0>,Int<5000>>>,TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,20>,Bump<Int<0>,Int<6000>>>,TrFade<1000>>,EFFECT_PREON>,Ifon<Int<0>,Int<32768>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     HumpFlicker<Blue,Black,30>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<HumpFlicker<Blue,Black,30>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "agony"},



// { "aa_NoSloppy/TheMaw;common;commonBU", "",
//   StylePtr<Layers<
// // Main Blade Color    
//     Mix<SmoothStep<Int<16000>,Int<10000>>,
//       StripesX<Scale<TwistAngle<1>,Int<1500>,Int<3000>>,Int<-2000>,Rgb<60,0,255>,Black>,
//       StripesX<Scale<TwistAngle<1>,Int<1500>,Int<3000>>,Int<2000>,Rgb<60,0,255>,Black>>,
//     // Ice Force
//     TransitionEffectL< 
//       TrConcat<TrFade<7000>,Rgb<10,0,75>,// blade turns solid cold 1000ms before ice full coverage
//       TrDelay<1000>>,EFFECT_USER2>,  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to base color
//     TransitionEffectL< TrConcat<TrWipe<8000>, //wipe in stripes ice freezing effect
//     TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>,TrFade<11500>,TrDelay<20000>,EFFECT_USER2>, // Stripes fade to solid over remaining 4 seconds from freezing edge's finish until 12000 then hold for next joined delay to end at 15000, so 3000 more.
//       TrDelay<7000>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>, //after 15000 (TrConcat makes it 8000 + 7000) from effect start, full blade to this shade of white for wiping away (seamless color from end of stripes fade to solid)
//       TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>, // wipe ice away and melt to thinner opacity , but not 100%, leave like 30% by using longer fade duration than the wipe takes. 
//     TransitionEffectL<TrConcat<
//       TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,     Int<400>,  Int<50>, Int<1000>,Int<0>>,    // burst
//         TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,      Int<15000>,Int<400>,Int<8000>,Int<0>>,         // leading freeze edge
//         TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,    // crystalizing in edge's wake
//     AlphaL<Rgb<100,200,255>,Int<0>>,
//       TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,    Int<300>,  Int<50>, Int<1000>,Int<0>>,  // burst
//         TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>, // crystalizing in thaw's path
//         TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,     Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>, // leading thawing edge
//   // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//     AlphaL<Black,Int<16384>>,
//     AlphaL<Black,Int<0>>>,
//   // Clash
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,
//       AlphaL<
//         TransitionEffect<
//           TransitionEffect<Strobe<Rgb<255,150,50>,Black,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,
//         Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,
//       Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,
//     EFFECT_CLASH>,
//   // Stab
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//   // Blast
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//     BlastL<EffectSequence<EFFECT_BLAST,Red,Green,Cyan,GreenYellow>,850,250,351>,
//     AlphaL<TransitionEffectL<TrConcat<TrDelay<300>,Red,TrFade<500>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//     BlastL<Rgb<100,200,255>,500,350,100000>,
//   // Lockup - BC custom range mid-blade w/random strobe flash
//     LockupTrL<Layers<StrobeX<AlphaL<Black,Int<0>>,White,Scale<SlowNoise<Int<1000>>,Int<0>,Int<2>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>,
//       AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//       AlphaL<Blinking<BrownNoiseFlicker<Rgb<100,200,255>,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,
//       TrConcat<TrInstant,
//       AlphaL<Blinking<Rgb<100,200,255>,Strobe<BrownNoiseFlicker<Yellow,Black,500>,White,15,30>,60,500>,         Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<Rgb<100,200,255>,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//   // Non-Responsive Drag
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,Rgb<100,200,255>>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
//     LockupTrL<Layers<AlphaL<StrobeX<Black,White,Scale<SlowNoise<Int<1000>>,Int<0>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>,Int<22000>>,AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//       Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//       Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//       Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//     // Begin Lightning Transition
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//     // End Lightning Transition    
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Melt    
//     LockupTrL<
//       AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//       // Melt Shape
//       SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//       // Melt Begin and End transitions
//       TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>, 
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrDelay<200>,Strobe<Black,Rgb<100,100,150>,15,40>,TrJoin<TrWipeInSparkTip<Rgb<100,200,255>,800,200>,TrWipeSparkTip<Rgb<100,200,255>,800,200>>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrFade<700>,Strobe<Black,Rgb<100,100,150>,15,40>,TrDelay<300>>,EFFECT_RETRACTION>,
//     InOutTrL<
//       TrJoin<
//         TrJoin<TrWipeIn<800>,TrWaveX<White,Int<800>,Int<500>,Int<800>,Int<32768>>>,
//         TrJoin<TrWipe<800>,TrWaveX<White,Int<400>,Int<500>,Int<800>,Int<0>>>>,
//       TrJoin<
//         TrJoin<TrWipeInX<Percentage<WavLen<EFFECT_RETRACTION>,200>>,TrWaveX<White,WavLen<EFFECT_RETRACTION>,Int<500>,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<32768>>>,
//         TrJoin<TrWipeX<Percentage<WavLen<EFFECT_RETRACTION>,200>>,TrWaveX<White,WavLen<EFFECT_RETRACTION>,Int<500>,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<0>>>>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<50>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrDelayX<WavLen<EFFECT_RETRACTION>>,White,TrFade<50>>,EFFECT_RETRACTION>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Rgb<60,0,255>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<60,0,255>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "the\nmaw"},



// { "a_REY/Darkness;common;commonBU", "a_REY/Darkness/tracks/DarkReyBC.wav",
//   StylePtr<Layers<
//     StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,150,150>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
//     InOutTrL<TrWipeX<Int<300>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Red>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Red>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "rey\ndarkness"},



// { "aa_Kyberphonic/Battle2;common;commonBU", "aa_Kyberphonic/Battle2/tracks/Battle.wav",
//   StylePtr<Layers<
//     HumpFlicker<RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,Blue>,20>,
//     BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Blue>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Blue>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "battle 2"},



// { "aa_Kyberphonic/DeathStar;common;commonBU", "aa_Kyberphonic/DeathStar/tracks/track3.wav",
//   StylePtr<Layers<
//     Stripes<-1500,500,Rgb<150,150,150>,Black,Rgb<150,150,150>,Rgb<150,150,150>,Black,Rgb<150,150,150>,Rgb<150,150,150>,Rgb<150,150,150>,Rgb<150,150,150>,Black,Rgb<150,150,150>,Rgb<150,150,150>,Black>,
//     BC_effects_1,
//     InOutTrL<TrJoin<TrWipe<350>,TrWaveX<White,Int<600>,Int<150>,Int<350>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,White>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,White>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "death\nstar"},



//  { "aa_Kyberphonic/DeathStar/ProjectStardust;aa_Kyberphonic/DeathStar;common;commonBU", "aa_Kyberphonic/DeathStar/tracks/track5.wav",
// // Main Blade
//   StylePtr<Layers<
//   //Main Color
//     Stripes<3500,-3000,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,60,0>>,RotateColorsX<Variation,Rgb<50,255,50>>,RotateColorsX<Variation,Rgb<0,128,0>>>,
//   //Swing Color
//     AlphaL<StrobeL<RandomPerLEDFlickerL<Rgb<175,175,175>>,Int<50>,Int<125>>,SwingSpeed<600>>,
//   // Pulse Loop
//     TransitionLoopL<TrConcat<TrFade<500>,StrobeL<Stripes<2500,-3000,RotateColorsX<Variation,Rgb<150,255,150>>,RotateColorsX<Variation,Rgb<0,60,0>>,Pulsing<RotateColorsX<Variation,Rgb<0,30,0>>,Black,800>>,Int<50>,Int<125>>,TrDelayX<Scale<SlowNoise<Int<3200>>,Int<1000>,Int<80>>>,Stripes<2500,-3000,RotateColorsX<Variation,Rgb<150,255,150>>,RotateColorsX<Variation,Rgb<0,60,0>>,Pulsing<RotateColorsX<Variation,Rgb<0,30,0>>,Black,800>>,TrFade<300>>>,
//   // Emitter Flare
//     AlphaL<Rgb<100,255,100>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,
//     BC_effects_1,
//   // Extension and Retraction Effects
//     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<150,255,150>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,60,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<150,255,150>>,RotateColorsX<Variation,Rgb<0,60,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,60,0>>>>,TrFade<1200>>,EFFECT_IGNITION>,
//     InOutTrL<TrColorCycle<500>,TrColorCycle<2000>>,
//     TransitionEffectL<TrConcat<
//   // Preon
//     TrWipe<100>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,60,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,
//     TrWipe<100>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,128,0>>,60>,SmoothStep<Int<4000>,Int<-500>>>,
//     TrWipe<100>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,190,0>>,30>,SmoothStep<Int<6000>,Int<-500>>>,
//     TrInstant>,EFFECT_PREON>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Green>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Green>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "project\nstardust"},



// // { "a_PONG_KRELL/GeneralKrell;common;commonBU", "a_PONG_KRELL/GeneralKrell/tracks/track1.wav",

// { "a_VADER/Father_V2/ANH;common;commonBU", "a_VADER/Father_V2/tracks/track1.wav",
//   StylePtr<Layers<
//     AudioFlicker<Red,Rgb<128,0,0>>,
//     BC_effects_Red,
//     InOutTrL<TrWipe<1000>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<Red,Black,1000>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Red,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "father_v2\nanh"},



// { "a_VADER/Father_V2/ESB;common;commonBU", "a_VADER/Father_V2/tracks/track3.wav",
//   StylePtr<Layers<
//     AudioFlicker<Red,Rgb<128,0,0>>,
//     BC_effects_Red,
//     InOutTrL<TrWipe<1000>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<Red,Black,1000>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Red,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "father_v2\nesb"},



// { "a_VADER/Father_V2/ROTJ;common;commonBU", "a_VADER/Father_V2/tracks/track4.wav",
//   StylePtr<Layers<
//     AudioFlicker<Red,Rgb<128,0,0>>,
//     BC_effects_Red,
//     InOutTrL<TrWipe<1000>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<Red,Black,1000>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Red,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "father_v2\nrotj"},



// { "a_VADER/Father_V2/R1;common;commonBU", "a_VADER/Father_V2/tracks/track7.wav",
//   StylePtr<Layers<
//     AudioFlicker<Red,Rgb<128,0,0>>,
//     BC_effects_Red,
//     InOutTrL<TrWipe<1000>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<Red,Black,1000>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Red,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "father_v2\nrogue 1"},



// { "a_EZRA/LothHero;common;commonBU", "a_EZRA/LothHero/tracks/track1.wav",
//   StylePtr<Layers<
//     AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
//     BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,DeepSkyBlue>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,DeepSkyBlue>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "loth\nhero"},



// { "CA_74Z;common;commonBU", "CA_74Z/tracks/track1.wav", // Cosmic Ape
//   StylePtr<Layers<
//     AudioFlicker<Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,Blue>,
//   // Swing Color
//     //AlphaL<Pulsing<Blue,LightCyan,1000>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   // Clash 1 - BladeAngle responsive. Yellowish impact
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//   // Stab - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//   // Blast
//     // Impact Flash - BC always
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//     // Waves
//     BlastL<White,850,250,351>,
//     // Impact point afterimage
//     AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//     // Impact point
//     BlastL<White,500,350,100000>,
//   // Lockup 1 - BC custom range mid-blade to hilt w/random strobe flash
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<AlphaL<StrobeX<Black,White,Scale<SlowNoise<Int<1000>>,Int<0>,Int<2>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>,Int<20000>>,
//       // Bottom Layer Bump - random width
//       AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//       // Top Layer Bump - fixed width
//       AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,          Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,
//       // Begin Lockup Transition
//       TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//       // End Lockup Transition
//       TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,  
//   // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
//     LockupTrL<Layers<AlphaL<StrobeX<Black,White,Scale<SlowNoise<Int<1000>>,Int<0>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>,Int<22000>>,
//      AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<
//      Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//      Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//      Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//      // Begin Lightning Transition
//      TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
//      // End Lightning Transition    
//      TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//      AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,1,1>,Rgb<137,32,2>,150>,StyleFire<Rgb<79,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//      // Melt Shape
//      SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//      // Melt Begin and End transitions
//      TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrSmoothFade<500>,Strobe<StyleFire<HumpFlicker<DeepPink,Stripes<10000,-3000,Cyan,DarkOrange>,50>,Cyan,0,5,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,100,0>,FireConfig<0,2000,5>>,Red,15,20>,TrSmoothFade<600>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWaveX<White,Int<800>,Int<400>,Int<400>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//     TransitionEffectL<TrConcat<TrDelay<50>,Black,TrWaveX<GreenYellow,Int<200>,Int<100>,Int<200>,Int<32768>>,White,TrDelay<50>,
//       AlphaL<Red,SmoothStep<Int<3000>,Int<-6000>>>,TrFade<450>,
//       AlphaL<OrangeRed,SmoothStep<Int<10000>,Int<-8000>>>,TrFade<450>,
//       AlphaL<HumpFlicker<Rgb<208,128,128>,Red,20>,SmoothStep<Int<16000>,Int<-8000>>>,TrFade<50>,
//       White,TrJoin<TrWipeIn<150>,TrWaveX<Green,Int<150>,Int<75>,Int<150>,Int<32768>>>>,EFFECT_PREON>,
//     AlphaL<HumpFlicker<DeepPink,Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,50>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<2500>,Int<1000>,Int<1>>,Int<-32768>,Int<32768>>,Int<-8000>>>,
//     TransitionEffectL<TrConcat<TrDelay<2500>,Layers<HumpFlicker<Cyan,DeepPink,40>,AlphaL<Black,Int<25000>>>,TrSmoothFade<963>,Strobe<StyleFire<HumpFlicker<DeepPink,Stripes<10000,-3000,Cyan,DarkOrange>,50>,Cyan,0,5,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,100,0>,FireConfig<0,2000,5>>,Red,15,20>,TrInstant>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrDelay<2120>,White,TrDelay<80>,AlphaL<Black,Int<0>>,TrDelay<200>,Cyan,TrDelay<80>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrDelay<3275>,AlphaL<Black,Int<0>>,TrWipeIn<188>,Black,TrInstant>,EFFECT_PREON>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//  StylePtr<Layers<
//     Pulsing<AudioFlicker<Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,Blue>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Cyan,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "ca_74z\nspeeder"},



// { "aa_Syndicate/AncientIntegration;common;commonBU", "",
//   StylePtr<Layers<
//     Layers<
//       RotateColorsX<Variation,Blue>,
//       BrownNoiseFlickerL<Black,Int<38400>>,
//       BrownNoiseFlickerL<Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,Int<25600>>>,
//     BC_effects_1,
//     InOutTrL<TrJoin<TrWipe<300>,TrWipeIn<300>>,TrJoin<TrWipe<400>,TrWipeIn<400>>>,
//     TransitionEffectL<TrConcat<TrFade<2000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<100,100,150>>,10>,Bump<Int<0>,Int<4000>>>,TrFade<2950>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<100,100,150>>,15>,Bump<Int<0>,Int<5000>>>,TrFade<3000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<100,100,150>>,20>,Bump<Int<0>,Int<6000>>>,TrBoing<1000,3>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<Layers<
//     RotateColorsX<Variation,Blue>,
//     BrownNoiseFlickerL<Black,Int<38400>>,
//     BrownNoiseFlickerL<Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,Int<25600>>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Layers<
//     RotateColorsX<Variation,Blue>,
//     BrownNoiseFlickerL<Black,Int<38400>>,
//     BrownNoiseFlickerL<Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,Int<25600>>>,Black,2500>>
//   >>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "ancient\nintegration"},



// { "aa_Syndicate/DarkJedi;common;commonBU", "a_Syndicate/DarkJedi/tracks/DarkSIdeTheme.wav",
//   StylePtr<Layers<
//     Layers<
//       RotateColorsX<Variation,Green>,
//       TransitionLoopL<TrConcat<TrBoing<500,3>,Layers<
//         Stripes<10000,100,RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,30,0>>,RotateColorsX<Variation,Rgb<0,200,0>>>,
//         AlphaL<Stripes<8000,-200,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,60,0>>>,Int<16384>>>,TrDelayX<Scale<SlowNoise<Int<3000>>,Int<100>,Int<2000>>>>>,
//       TransitionLoopL<TrConcat<TrWipe<200>,RandomBlinkL<Int<30000>,White>,TrWipe<200>,AlphaL<White,Int<0>>,TrDelayX<Scale<SlowNoise<Int<3000>>,Int<300>,Int<3000>>>>>>,
//     BC_effects_1,
//     InOutTrL<TrWipe<300>,TrWipeIn<500>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Green>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Green>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "dark\njedi"},



// { "aa_Syndicate/FirstApprentice;common;commonBU", "aa_Syndicate/FirstApprentice/tracks/MauloftheFatesEdit.wav",
//   StylePtr<Layers<
//     AudioFlicker<Red,Rgb<120,0,0>>,
//     BC_effects_Red,
//     OnSparkL<HumpFlicker<MistyRose,Red,60>,Int<1600>>,
//     InOutTrL<TrWipe<800>,TrWipeIn<500>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<AudioFlicker<Red,Rgb<120,0,0>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<AudioFlicker<Red,Rgb<120,0,0>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "first\napprentice"},



// { "aa_Syndicate/LoneOutcast;common;commonBU",  "",
//   StylePtr<Layers<
//   // Main Blade
//     // Jedi base Green
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Green>,Pulsing<RotateColorsX<Variation,Rgb<0,90,0>>,RotateColorsX<Variation,Green>,800>,RotateColorsX<Variation,Green>>,
//     // Jedi Force Green
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
//     // Jedi Swing Green
//     AlphaL<RotateColorsX<Variation,Rgb<100,255,100>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     BC_effects_1,
//   // Ignition and Retraction
//     InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<400>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(), 
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Green>,Pulsing<RotateColorsX<Variation,Rgb<0,90,0>>,RotateColorsX<Variation,Green>,800>,RotateColorsX<Variation,Green>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Green>,Pulsing<RotateColorsX<Variation,Rgb<0,90,0>>,RotateColorsX<Variation,Green>,800>,RotateColorsX<Variation,Green>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "lone\noutcast"},



// { "aa_Syndicate/SithKiller;common;commonBU",  "",
//   //Second Sister base Red
//   StylePtr<Layers<
//     Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
//   // Second Sister Force Red
//     TransitionEffectL<TrConcat<TrFade<200>,Rgb<255,50,50>,TrFade<400>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<255,50,50>>,TrFade<800>>,EFFECT_FORCE>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
//     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
//     InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Red>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Red>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "sith\nkiller"},



// { "a_LUKE/ANH_Graflex;common;commonBU", "a_LUKE/ANH_Graflex/tracks/track1.wav",
//   StylePtr<Layers<
//     AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
//     BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "anh\ngraflex"},



// { "a_LUKE/ANH_Training;a_LUKE/ANH_Graflex;common;commonBU", "a_LUKE/ANH_Graflex/tracks/training_ambience.wav",
//   StylePtr<Layers<
//     AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
//     BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "anh\ntraining"},



// { "aa_BK/MysticMaster;common;commonBU", "",
//   StylePtr<Layers<
//     StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<5,5,20>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<45,45,70>>,Black>>,RotateColorsX<Variation,Rgb<20,20,30>>,Pulsing<RotateColorsX<Variation,Rgb<25,25,40>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<40,40,60>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<2,2,5>>,3000>>,
//     AlphaL<StyleFire<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<1,1,2>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
//   // Swing Color
//     AlphaL<Stripes<9000,-1500,RotateColorsX<Variation,Rgb<175,175,225>>,RotateColorsX<Variation,Rgb<25,25,38>>,Pulsing<RotateColorsX<Variation,Rgb<12,12,19>>,Black,800>>,SwingSpeed<600>>,
//   // Emitter Flare
//     AlphaL<RotateColorsX<Variation,Rgb<175,175,225>>,Bump<Int<0>,Int<8000>>>,
//     BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,500>,TrJoin<TrWipeIn<1000>,TrWaveX<White,Int<2000>,Int<400>,Int<1000>,Int<32768>>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<AudioFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,White>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Rgb<100,100,150>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "mystic\nmaster"},



// { "aa_BK/Relictron;common;commonBU", "",
//    StylePtr<Layers<
// // Main Blade
//     HumpFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<39,5,71>>,10>,
//     BC_effects_1,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrSmoothFade<800>,White,TrWipe<50>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<400>,Int<300>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(), 
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Rgb<95,0,225>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<95,0,225>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "relictron"},



// { "aa_BK/Party_Foul;common;commonBU", "",
//   StylePtr<Layers<
//     StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,20,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<0,120,0>>,Black>>,RotateColorsX<Variation,Rgb<0,60,0>>,Pulsing<RotateColorsX<Variation,Rgb<0,50,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,96,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,5,0>>,3000>>,
//     AlphaL<StyleFire<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,2,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
//     BC_effects_1,
//     InOutTrL<TrWipe<1000>,TrJoin<TrFade<1600>,TrWipe<1580>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Green>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Green>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "party\nfoul"},



// { "Arcane;common;commonBU", "", // TehMothman
//   StylePtr<Layers<
//   // Main Blade
//     Pulsing<HumpFlicker<RotateColorsX<Variation,Rgb<90,24,0>>,RotateColorsX<Variation,DarkOrange>,50>,HumpFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<90,24,0>>,10>,1200>,
//   // Jedi Swing Orange
//     AlphaL<RotateColorsX<Variation,Rgb<255,178,110>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     BC_effects_1,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrSmoothFade<800>,White,TrWipe<50>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<400>,Int<300>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(), 
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<Pulsing<RotateColorsX<Variation,Rgb<90,24,0>>,RotateColorsX<Variation,DarkOrange>,800>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Pulsing<RotateColorsX<Variation,Rgb<90,24,0>>,RotateColorsX<Variation,DarkOrange>,800>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "Arcane"},



// { "aa_Blueforce/CyberAssassin2;common;commonBU", "", // BlueForceCompany
//    StylePtr<Layers<
// // Main Blade
//     HumpFlicker<RotateColorsX<Variation,Rgb<0,150,0>>,Black,30>,
//   // Swing Color
//     AlphaL<RotateColorsX<Variation,Rgb<0,150,0>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     BC_effects_1,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrSmoothFade<800>,White,TrWipe<50>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<400>,Int<300>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(), 
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Rgb<0,150,0>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<0,150,0>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "cyber\nassassin 2"},



// { "TheMatrix;common;commonBU", "TheMatrix/tracks/clubbed_to_death.wav", // Sam Tardiff
//   StylePtr<Layers<
//     Stripes<16000,-1000,RotateColorsX<Variation,Green>,Pulsing<RotateColorsX<Variation,Rgb<0,90,0>>,RotateColorsX<Variation,Green>,800>,RotateColorsX<Variation,Green>>,
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<30000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
//     AlphaL<BrownNoiseFlicker<Green,Black,300>,SwingSpeed<300>>,
//      SparkleL<Black,2400,600>,
//     BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,4500>,TrColorCycle<4500>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(), 
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Rgb<0,90,0>>,RotateColorsX<Variation,Green>,800>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Pulsing<RotateColorsX<Variation,Rgb<0,90,0>>,RotateColorsX<Variation,Green>,800>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "the\nmatrix"},



// { "aa_Blueforce/Legion;common;commonBU", "", // blueforce Legion based style w/ my effects
//   StylePtr<Layers<
//     Mix<SwingSpeed<500>,StyleFire<BrownNoiseFlicker<Red,Black,50>,Rgb<83,0,255>,0,2,FireConfig<0,3000,5>,FireConfig<4000,0,0>>,BrownNoiseFlicker<Red,Black,50>>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
//     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
//    InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
//    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<BrownNoiseFlicker<Red,Black,50>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<BrownNoiseFlicker<Red,Black,50>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "legion"},



// {"aa_Blueforce/Protoblade;common;commonBU","", // 15888 bytes when compiling, but reported style size is 3224...?
//   StylePtr<Layers<
//     StripesX<Int<3000>,Int<-3500>,RotateColorsX<Variation,Blue>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,0,60>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,30>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,0,80>>,RotateColorsX<Variation,Rgb<0,0,30>>>>,
//     TransitionLoopL<TrConcat<TrWaveX<AudioFlicker<RotateColorsX<Variation,Blue>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<0,0,80>>,Black,200>>,Int<400>,Int<100>,Int<200>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<50>,Int<1000>>>>>,
//     TransitionLoopL<TrConcat<TrWaveX<AudioFlicker<RotateColorsX<Variation,Blue>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<0,0,60>>,300>>,Int<400>,Int<100>,Int<200>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<200>,Int<1500>>>>>,
//     AlphaL<StrobeL<White,Int<20>,Int<1>>,SwingSpeed<600>>,
//   // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//     AlphaL<Black,Int<16384>>,
//     AlphaL<Black,Int<0>>>,
//   // Clash 1 - BladeAngle responsive.
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//   // Stab 1 - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//   // Blast 1
//     // Impact Flash
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//     // Waves
//     BlastL<White,850,250,351>,
//     // Impact point afterimage
//     AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//     // Impact point
//     BlastL<White,500,350,100000>,
//   // Lockup - Custom for Protoblade lock01.wav - TransitionLoop Pulse increases speed then slows in time w/ sound
//     LockupTrL<Layers<
//       AlphaL<Blinking<Rgb<100,100,200>,Strobe<Yellow,Black,15,30>,60,500>,                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//       AlphaL<Blinking<BrownNoiseFlicker<White,Black,70>,BrownNoiseFlicker<Yellow,NavajoWhite,80>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,
//         TrConcat<TrInstant,
//         AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,             Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//       LockupTrL<TransitionLoopL<TrWaveX<BrownNoiseFlicker<White,Black,100>,Scale<Trigger<EFFECT_LOCKUP_BEGIN,Int<12000>,Int<3000>,Int<2500>>,Int<1000>,Int<200>>,Int<250>>>,TrInstant,TrInstant,SaberBase::LOCKUP_NORMAL>,
//       TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                         Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//       TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
//       TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
//       TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//   // Drag
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block  
//     LockupTrL<AlphaL<Black,RandomBlinkF<Sin<Int<70>,Int<30000>,Int<10000>>>>,TrInstant,TrInstant,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     LockupTrL<AlphaL<Strobe<White,AudioFlicker<White,Blue>,50,1>,LayerFunctions<
//      Bump<Scale<Sin<Int<40>>,Int<3000>,Int<8000>>,Scale<Sin<RandomBlinkF<Int<5000>>>,Scale<Sin<Int<10>,Int<3000>,Int<2000>>,Scale<Sin<Int<10>,Int<3068>,Int<1000>>,Int<9000>,Int<5000>>,Int<0>>,Int<0>>>,
//      Bump<Scale<Sin<Int<25>>,Scale<NoisySoundLevel,Int<26000>,Int<18000>>,Int<8000>>,Scale<NoisySoundLevel,Scale<Sin<Int<20>>,Int<6000>,Int<10000>>,Scale<SlowNoise<Int<1500>>,Int<10000>,Int<14000>>>>,
//      Bump<Scale<Sin<Int<60>,Int<10008>>,Scale<Sin<Int<10>>,Int<20000>,Int<16000>>,Scale<Sin<Int<10>>,Sin<Int<20>>,Int<24000>>>,Scale<Sin<Int<10>>,Scale<Sin<Int<10>,Int<3000>,Int<2000>>,Scale<Sin<Int<10>,Int<3068>,Int<1000>>,Int<9000>,Int<5000>>,Int<0>>,Int<0>>>>>,
//       TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
//       TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//       Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//       Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//       Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
//       TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>, 
//       TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Melt
//     LockupTrL<AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//       SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//       TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>, 
//   // Ignition Effects
//     TransitionEffectL<TrConcat<TrInstant,Layers<
//       AlphaL<Stripes<3000,3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,SmoothStep<Int<16385>,Int<-1>>>,
//       AlphaL<Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,SmoothStep<Int<16384>,Int<0>>>>,TrFade<800>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<16384>,Int<20000>>>,TrSmoothFade<1400>>,EFFECT_IGNITION>,
//   // Extension / Retraction
//     InOutTrL<TrJoinR<TrWipe<100>,TrWipeIn<100>>,TrConcat<TrInstant,White,TrFade<200>,Black,TrDelay<100>,HumpFlicker<Rgb<100,100,100>,Rgb<0,0,155>,20>,TrSmoothFade<800>,StrobeL<White,Int<20>,Int<2>>,TrInstant,Black,TrDelay<50>,Black,TrInstant,White,TrDelay<50>,Blue,TrFade<100>>>,
//  // Cooldown tips fizzle out
//     TransitionEffectL<TrConcat<
//       TrFade<450>,       AlphaL<RandomFlicker<Strobe<White,RotateColorsX<Variation,Rgb<0,0,255>>,50,10>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<0,0,255>>,Black,500>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,
//       TrDelay<1000>,     AlphaL<RandomFlicker<Strobe<White,RotateColorsX<Variation,Rgb<0,0,255>>,50,10>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<0,0,255>>,Black,500>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,
//       TrSmoothFade<1600>,Black,
//       TrDelay<100>,      AlphaL<RandomFlicker<Strobe<White,RotateColorsX<Variation,Rgb<0,0,255>>,50,10>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<0,0,255>>,Black,500>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelay<50>>,EFFECT_RETRACTION>,
//   // Preon
//     TransitionEffectL<TrJoin<TrWaveX<White,Int<400>,Int<200>,Int<200>,Int<0>>,TrWaveX<White,Int<400>,Int<200>,Int<200>,Int<32768>>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<
//       TrInstant,Blinking<AlphaL<RandomFlicker<Strobe<White,RotateColorsX<Variation,Blue>,        50,10>,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,        Black,500>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,Black,50,500>,
//       TrDelay<200>,      AlphaL<RandomFlicker<Strobe<White,RotateColorsX<Variation,Blue>,        50,10>,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,        Black,500>>,LayerFunctions<Bump<Int<0>,Int<15000>>,Bump<Int<32768>,Int<15000>>>>,
//       TrBoing<500,3>,    AlphaL<RandomFlicker<Strobe<White,RotateColorsX<Variation,Blue>,        50,10>,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,        Black,500>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrSmoothFade<300>,HumpFlicker<White,Blue,20>,TrFade<325>,White,TrJoin<TrWipeIn<200>,TrWipe<200>>>,EFFECT_PREON>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<BrownNoiseFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,30>>,200>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<BrownNoiseFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,30>>,200>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "protoblade"},


// { "aa_NoSloppy/Portal;common;commonBU", "aa_NoSloppy/Portal/tracks/02.Finale.wav",
// // ********************************************************
// // *** V5 optimized non-MultiTransitionEffectL - WavLen version ****
// // ********************************************************

//   StylePtr<Layers<
//   // Main Blade - toggled colors when "shooting a portal" with blast. All effects follow switch.
//     EffectSequence<EFFECT_BLAST,
//     Stripes<10000,-1000,DarkOrange,Rgb<60,17,0>,Orange,Rgb<128,34,0>>,
//     Stripes<10000,-1000,Blue,Rgb<0,0,60>,Blue,Rgb<0,0,128>>>,
  
//   // Swing colors  
//     EffectSequence<EFFECT_BLAST,
//     AlphaL<Moccasin,      Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     AlphaL<Rgb<90,90,255>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>>,

//   // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//     AlphaL<Black,Int<16384>>,
//     AlphaL<Black,Int<0>>>,
  
//   // Clash - alternates to visible colors based on main blade color. 3 stage fading impact spot
//     EffectSequence<EFFECT_BLAST,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<White,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,White,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH> >,
  
//   // Stab
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Red,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,800,Red,Rgb<80,0,0>,Rgb<156,0,0>,Rgb<150,30,30>>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<600>>>,EFFECT_STAB>,

//   // Blasts - toggled inverted colors
//     EffectSequence<EFFECT_BLAST,
//   ////// blast for Blue base - Blue goes first here because on first blast switch, this shows immediatly. Sequence order needs to be reverse of all other effects so it stays chronologically "at the end" of the blue base blade showing
//     TransitionEffectL<TrConcat<TrInstant,Stripes<10000,-1000,Blue,Rgb<0,0,60>,Blue,Rgb<0,0,128>>,TrJoin<TrWipeIn<100>,TrWaveX<White,Int<100>,Int<200>,Int<100>,Int<32768>>>,Black,TrDelay<25>,Black,TrJoin<TrWipe<200>,TrWaveX<LemonChiffon,Int<300>,Int<130>,Int<250>,Int<0>>>,Stripes<1400,-3600,DarkOrange,Rgb<60,17,0>>,TrJoin<TrWipe<200>,TrSmoothFade<300>>,Stripes<10000,-1000,Blue,Rgb<0,0,60>,Blue,Rgb<0,0,128>>,TrSmoothFade<1000>>,EFFECT_BLAST>,
//   ////// blast for Orange base - broken out. Blue above is same, just all one line.
//     TransitionEffectL<TrConcat< 
//   // hide the newly switched-to Blue main base blade color with the same Orange that was just running. (only for 100ms, but blue is visible on the wipe in if this omitted)
//     TrInstant,Stripes<10000,-1000,DarkOrange,Rgb<60,17,0>,Orange,Rgb<128,34,0>>,
//   //suck in for blast
//     TrWipeIn<100>,Black,
//   // take a beat
//     TrDelay<25>,Black,
//   // shoot portal
//     TrJoin<TrWipe<200>,TrWaveX<LemonChiffon,Int<300>,Int<130>,Int<250>,Int<0>>>,Stripes<1400,-3600,Blue,Rgb<0,0,60>>,TrJoin<TrWipe<200>,
//   //fade to color that was agin for a beat, then fade to new color that was shot
//     TrSmoothFade<300>>,Stripes<10000,-1000,DarkOrange,Rgb<60,17,0>,Orange,Rgb<128,34,0>>,TrSmoothFade<1000>>,EFFECT_BLAST>>,
//   // Blast's muzzle flash
//     TransitionEffectL<TrConcat<TrDelay<125>,AlphaL<DarkOrange,Bump<Int<0>,Int<4000>>>,TrFade<50>,AlphaL<LemonChiffon,Bump<Int<0>,Int<10000>>>,TrFade<50>,AlphaL<White,SmoothStep<Int<14000>,Int<-16000>>>,TrDelay<25>,AlphaL<LemonChiffon,Bump<Int<0>,Int<10000>>>,TrFade<550>,AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFade<150>,AlphaL<Rgb<255,54,0>,Bump<Int<0>,Int<2800>>>,TrFade<150>,AlphaL<OrangeRed,Bump<Int<0>,Int<1700>>>,TrFade<200>>,EFFECT_BLAST>,

//   // Lockup
//     LockupTrL<Layers<
//         AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<2000,28000>,Scale<BladeAngle<0,16000>,Int<3000>,Int<32768>>,Int<6000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//         AlphaL<BrownNoiseFlicker<Yellow,Black,50>,                                            Bump<Scale<BladeAngle<2000,28000>,Scale<BladeAngle<0,16000>,Int<3000>,Int<32768>>,Int<6000>>,Int<10000>>>>,
//       TrConcat<TrInstant,
//         AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<2000,28000>,Scale<BladeAngle<0,16000>,Int<3000>,Int<32768>>,Int<6000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,              Bump<Scale<BladeAngle<2000,28000>,Scale<BladeAngle<0,16000>,Int<3000>,Int<32768>>,Int<6000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<100>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,

//   // Drag
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block    
//       ResponsiveLightningBlockL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,
//       //Begin Lightning Transition
//       TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
//       //End Lightning Transition
//       TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >>,
//   // Melt    
//       LockupTrL<
//       AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,1,1>,Rgb<137,32,2>,150>,StyleFire<Rgb<79,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//       // Melt Shape
//       SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//       //Melt Begin and End transitions
//       TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
//   // Extension sparks - less laggy in this layer style
//     EffectSequence<EFFECT_BLAST,
//     OnSparkL<SparkleL<Blue,300,3000>,Int<3000>>,
//     OnSparkL<SparkleL<Orange,300,3000>,Int<3000>> >,

//     EffectSequence<EFFECT_BLAST,
//     InOutTrL<
//   // Extension - just wipe out, effects below.
//     TrWipe<500>,
//   // Retraction - wipe in 3 stage accelerating stripes followed by spark in below.
//     TrConcat<
//     TrWipeInX< Percentage<WavLen<EFFECT_RETRACTION>,40> >,      Stripes<2000,1500,Blue,DarkOrange>,
//     TrFadeX<   Percentage<WavLen<EFFECT_RETRACTION>,20> >,      Stripes<3000,2000,Blue,DarkOrange>,
//     TrFadeX<   Percentage<WavLen<EFFECT_RETRACTION>,20> >,      Stripes<4000,2500,Blue,DarkOrange>,
//     TrWipeInX< Percentage<WavLen<EFFECT_RETRACTION>,20> >,      Black,
//     TrDelay<100>,       AlphaL<White,SmoothStep<Int<15000>,Int<-20000>>>,
//     TrFade<75>,         Black,
//     TrFade<700>,Sparkle<Black,DarkOrange>,TrSmoothFade<1000>>,
//   // Color When Off
//     Layers<Black,TransitionLoopL<TrConcat<TrFade<500>,AlphaL<DarkOrange,SmoothStep<Int<200>,Int<-1>>>,TrFade<500>,AlphaL<Red,Int<0>>,TrFade<500>,AlphaL<Blue,SmoothStep<Int<200>,Int<-1>>>,TrFade<500>>> >>,
  
//     InOutTrL<
//   // Extension - just wipe out, effects below.
//     TrWipe<500>,
//   // Retraction - wipe in 3 stage accelerating stripes followed by spark in below.
//     TrConcat<
//     TrWipeInX< Percentage<WavLen<EFFECT_RETRACTION>,40> >,      Stripes<2000,1500,Blue,DarkOrange>,
//     TrFadeX<   Percentage<WavLen<EFFECT_RETRACTION>,20> >,      Stripes<3000,2000,Blue,DarkOrange>,
//     TrFadeX<   Percentage<WavLen<EFFECT_RETRACTION>,20> >,      Stripes<4000,2500,Blue,DarkOrange>,
//     TrWipeInX< Percentage<WavLen<EFFECT_RETRACTION>,20> >,      Black,
//     TrDelay<100>,       AlphaL<White,SmoothStep<Int<15000>,Int<-20000>>>,
//     TrFade<75>,         Black,
//     TrFade<700>,Sparkle<Black,Blue>,TrSmoothFade<1000>>,
//   // Color When Off
//     Layers<Black,TransitionLoopL<TrConcat<TrFade<500>,AlphaL<DarkOrange,SmoothStep<Int<200>,Int<-1>>>,TrFade<500>,AlphaL<Red,Int<0>>,TrFade<500>,AlphaL<Blue,SmoothStep<Int<200>,Int<-1>>>,TrFade<500>>> >> >,
//   // Retraction spark wave in
//     TransitionEffectL<TrConcat<TrDelayX<Int<800>>,AlphaL<Red,Int<0>>,TrWaveX<LemonChiffon,Percentage<WavLen<EFFECT_RETRACTION>,100> ,Int<201>,Percentage<WavLen<EFFECT_RETRACTION>,20> ,Int<32768>>>,EFFECT_RETRACTION>,
//   // Extension - Spark tip followed by 3 trailing particles and small sparks over strobing base fading to running base blade color
//     EffectSequence<EFFECT_BLAST,
//     TransitionEffectL<TrConcat<TrWipe<500>,Strobe<DarkOrange,Black,20,60>,TrSmoothFade<1000>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrWipe<500>,Strobe<Blue,Black,20,60>,TrSmoothFade<1000>>,EFFECT_IGNITION> >,

//     EffectSequence<EFFECT_BLAST, 
//     TransitionEffectL<TrJoin<
//     TrWaveX<Blue,Int<5000>,Int<151>,Int<500>,Int<0>>,
//     TrWaveX<Blue,Int<5000>,Int<201>,Int<625>,Int<-15000>>,
//     TrWaveX<Blue,Int<5000>,Int<251>,Int<825>,Int<-15000>>,
//     TrWaveX<Blue,Int<5000>,Int<301>,Int<1000>,Int<-15000>>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrJoin<
//     TrWaveX<DarkOrange,Int<5000>,Int<151>,Int<500>,Int<0>>,
//     TrWaveX<DarkOrange,Int<5000>,Int<201>,Int<625>,Int<-15000>>,
//     TrWaveX<DarkOrange,Int<5000>,Int<251>,Int<825>,Int<-15000>>,
//     TrWaveX<DarkOrange,Int<5000>,Int<301>,Int<1000>,Int<-15000>>>,EFFECT_IGNITION> >,

//   // Ignition Emitter flare
//     TransitionEffectL<TrConcat<
//     TrInstant,  AlphaL<Orange,Bump<Int<0>,Int<6000>>>,
//     TrFade<50>, AlphaL<LemonChiffon,Bump<Int<0>,Int<10000>>>,
//     TrFade<50>, AlphaL<White,SmoothStep<Int<14000>,Int<-16000>>>,
//     TrDelay<25>,AlphaL<LemonChiffon,Bump<Int<0>,Int<10000>>>,
//     TrFade<550>,AlphaL<Orange,Bump<Int<0>,Int<4000>>>,
//     TrFade<150>,AlphaL<Rgb<255,54,0>,Bump<Int<0>,Int<2800>>>,
//     TrFade<150>,AlphaL<OrangeRed,Bump<Int<0>,Int<1700>>>,
//     TrFade<200>>,EFFECT_IGNITION>,

//   // Retraction Emitter flare
//     TransitionEffectL<TrConcat<
//     TrInstant,AlphaL<OrangeRed,Bump<Int<0>,Int<1000>>>,
//     TrFadeX< Percentage<WavLen<EFFECT_RETRACTION>,20> >,AlphaL<Rgb<255,54,0>,Bump<Int<0>,Int<3500>>>,
//     TrFadeX< Percentage<WavLen<EFFECT_RETRACTION>,20> >,AlphaL<Orange,Bump<Int<0>,Int<9000>>>,
//     //TrFadeX< Percentage<WavLen<EFFECT_RETRACTION>,20> >,AlphaL<BrownNoiseFlicker<LemonChiffon,Black,300>,Bump<Int<0>,Int<17000>>>, //Optional effect
//     TrFadeX< Percentage<WavLen<EFFECT_RETRACTION>,20> >,AlphaL<Strobe<LemonChiffon,Black,15,50>,Bump<Int<0>,Int<17000>>>,
//     TrFadeX< Percentage<WavLen<EFFECT_RETRACTION>,20> >>,EFFECT_RETRACTION>,

//   //New Audio Meter preon
//     AlphaL<Layers<
//       AlphaL<TransitionEffectL<
//             TrJoin<
//               TrWaveX<Moccasin,Int<5000>,Int<10000>,Int<7000>,Int<0>>,
//               TrWaveX<Blue,    Int<5000>,Int<10000>,Int<7000>,Int<11000>>,
//               TrWaveX<Moccasin,Int<5000>,Int<7000>, Int<4000>>,
//               TrWaveX<Orange,  Int<5000>,Int<10000>,Int<7000>,Int<22000>>,
//               TrWaveX<Moccasin,Int<5000>,Int<10000>,Int<7000>,Int<32768>>>,EFFECT_PREON>,
//           Trigger<EFFECT_PREON,Int<2000>,Int<5000>,Int<1>>
//         >,
//         TransitionEffectL<TrConcat<TrInstant,
//             Layers< 
//               AlphaL<Orange,SmoothStep<Scale<NoisySoundLevel,Int<0>,    Int<6000>>, Scale<SmoothSoundLevel,Int<-1>,Int<-30000>> > >,
//               AlphaL<Blue,  SmoothStep<Scale<NoisySoundLevel,Int<26768>,Int<32768>>,Scale<SmoothSoundLevel,Int<0>,  Int<30000>> > >>,
//             TrDelay<5000>>,EFFECT_PREON>>,
//     Ifon<Int<0>,Int<32768>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<DarkOrange,Blue,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "portal"},



// { "aa_NoSloppy/Comet;common;commonBU", "", // 10 HumpFlicker tight speckle humps Blade Default = Red Custom preon, in and out...Comet animation
   
//    StylePtr<Layers<// Main Blade
//     // Sith base Red
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Red>,Pulsing<RotateColorsX<Variation,Rgb<90,0,0>>,RotateColorsX<Variation,Red>,800>,RotateColorsX<Variation,Red>>,
//     // Sith Swing Red
//     AlphaL<RotateColorsX<Variation,Rgb<255,100,100>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     // Sith Force Red
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
//     BC_effects_Red, 
//     InOutTrL<TrJoin<TrConcat<TrWipe<1000>,RandomBlink<100,Red,Rgb<255,50,50>>,TrFade<175>,BrownNoiseFlicker<Rgb<200,20,20>,Rgb<80,0,0>,200>,TrFade<900>>,TrJoin<TrWipe<1700>,
//    TrWaveX<BrownNoiseFlicker<Yellow,RandomFlicker<White,Red>,50>,Int<3000>,Int<200>,Int<1000>,Int<2000>>,TrWaveX<BrownNoiseFlicker<Yellow,OrangeRed,100>,Int<3000>,Int<150>,Int<1000>,Int<0>>,
//    TrWaveX<BrownNoiseFlicker<Red,Rgb<80,0,0>,100>,Int<3000>,Int<100>,Int<1000>,Int<-2000>>>>,
//    TrJoin<TrConcat<TrFade<90>,RandomBlink<100,Red,Rgb<255,50,50>>,TrSmoothFade<250>,RandomBlink<10000,Rgb<80,0,0>>,TrSmoothFade<700>>,
//    TrJoin<TrFade<3000>,TrWaveX<BrownNoiseFlicker<Yellow,RandomFlicker<White,Red>,50>,Int<3000>,Int<200>,Int<1400>,Int<30000>>,
//     TrWaveX<BrownNoiseFlicker<Yellow,OrangeRed,100>,Int<3000>,Int<150>,Int<1400>,Int<32768>>,TrWaveX<BrownNoiseFlicker<Red,Rgb<80,0,0>,100>,Int<3000>,Int<100>,Int<1400>,Int<34000>>>>>,
//  TransitionEffectL<TrConcat<TrInstant,Rgb<100,100,0>,TrFade<50>>,EFFECT_IGNITION>,
//  TransitionEffectL<TrConcat<TrWipe<100>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<60,0,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,
//      TrDelayX< Percentage<WavLen<EFFECT_PREON>,49> >,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<60,0,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,
//      TrFadeX<  Percentage<WavLen<EFFECT_PREON>,49> >,AlphaL<HumpFlickerL<RotateColorsX<Variation,BrownNoiseFlicker<Yellow,OrangeRed,50>>,90>,SmoothStep<Int<2700>,Int<-500>>>,TrInstant>,EFFECT_PREON>,
// // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Rgb<90,0,0>>,RotateColorsX<Variation,Red>,800>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Pulsing<RotateColorsX<Variation,Rgb<90,0,0>>,RotateColorsX<Variation,Red>,800>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "comet"},



// { "Metropls;common;commonBU", "",
// StylePtr<Layers<
//   // Smoke base Gold
//   StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<15,8,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<90,50,0>>,Black>>,RotateColorsX<Variation,Rgb<40,30,0>>,Pulsing<RotateColorsX<Variation,Rgb<36,26,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<60,40,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<90,65,0>>,RotateColorsX<Variation,Rgb<5,2,0>>,3000>>,
//   AlphaL<StyleFire<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<2,1,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
//   // Bright Swing Gold
//   AlphaL<RotateColorsX<Variation,Rgb<230,180,80>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   BC_effects_1,
//   TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<230,180,80>>>,TrFade<1200>>,EFFECT_IGNITION>,
  
//   InOutTrL<TrWipeSparkTip<White,400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<2000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<180,130,0>>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<180,130,0>>,Rgb<50,50,50>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Rgb<180,130,0>>>>,White,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelay<6000>>,EFFECT_PREON>,
// // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<15,8,0>>,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<180,130,0>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "metropolis"},






// { "aa_Syndicate/SithChant", "aa_Syndicate/SithChant/tracks/music_from_the_dark_side_edit.wav",
//   StylePtr<Layers<
//   Stripes<6000,-3000,RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<150,0,0>> >,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Rgb<128,128,128>>,TrFade<1000>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Red,Black,500>,TrJoin<TrFade<1000>,TrWipe<800>>>,EFFECT_IGNITION>,
//     AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
//     InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<228,128,128>,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<30,0,0>>,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<30,0,0>>,200>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "sith\nchant"},



// { "a_KANAN/BlindMaster;common;commonBU", "a_KANAN/BlindMaster/tracks/CantProtectEzraForever.wav",
//   StylePtr<Layers<
//   RandomFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,20,128>>>,
//   BC_effects_1,
//    InOutTrL<TrWipe<500>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<BrownNoiseFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,20,128>>,200>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<BrownNoiseFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,20,128>>,200>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
// "blind\nmaster"},

};

//----------------------------------------------------------------------------------------------------------------------------------------
Preset noblade[] = {

// preset 0
{ "a_DARKSABER/DarkV3;common;commonBU", "",
// Main Blade
  StylePtr<Black>(),
// HiltPCB
  StylePtr<Layers<
    Mix<SwingSpeed<400>,RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<150,150,225>>>,
    BrownNoiseFlickerL<Stripes<5000,-300,RotateColorsX<Variation,Rgb<25,25,55>>,RotateColorsX<Variation,Rgb<75,75,120>>,RotateColorsX<Variation,Rgb<10,10,20>>,RotateColorsX<Variation,Rgb<50,50,75>>>,Int<38400>>,
    AudioFlickerL<RotateColorsX<Variation,Rgb<35,35,75>>>,
    AlphaL<RotateColorsX<Variation,Rgb<175,175,225>>,SwingSpeed<600>>,
    BC_effects_1,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>,
  // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Switches
  StylePtr<Layers<
    Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,2500>>>>(),
// Pommel
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// Bluetooth
  StylePtr<Blue>(),
"   dark\n    v3"},

// preset 1
// { "testfont2a;common;commonBU", "testfont2a/tracks/track1.wav",
{ "perVol", "testfont2a/tracks/track1.wav",
// Main Blade
  StylePtr<Blue>(),
    // StylePtr<LengthFinder<>>(),
// Hilt PCB
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// Switches
StylePtr<Black>(),
// Pommel
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// Bluetooth
  StylePtr<Blue>(),
"testfont2a"},


};

struct AccentsLED {
static constexpr float MaxAmps = 0.02;
static constexpr float MaxVolts = 3.2;
static constexpr float P2Amps = 0.10;
static constexpr float P2Volts = 3.0;
static constexpr float R = 0; // Resistor value
static const int Red = 0;
static const int Green = 0;
static const int Blue = 255;
};

BladeConfig blades[] = {
{ 123,    // BCA 123,  1" Ciel_Tan_A 132           D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<10, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(CTAbladein), 
"01_bladein_save"}, 

{ NO_BLADE,                                      // D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<10, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches 
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(noblade),
"00_NO_BLADE_save"}, 


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

// // Rotary Encoder

// ChangePresetRotaryReceiver rotary_receiver;
// Rotary<8, 9> rotary(&rotary_receiver);
/*
The receiver decides what the rotary events do.
There are currently receivers for changing presets, 
changing variation and one that just prints things out. 
More receivers can be added as needed. 
(I should probably create one for changing the volume.)
*/

// Support for 128x64 OLED
// #ifdef CONFIG_BOTTOM
// SSD1306Template<128, uint64_t> display(0x3C);
// #endif
