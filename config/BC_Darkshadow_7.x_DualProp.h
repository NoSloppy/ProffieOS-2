// DualProp saber and blaster based on blade detect

#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 2
// #define DUAL_POWER_BUTTONS   ****not working fully, only power     // BC Make both buttons identical for 1-btn use... useful?

// ------ Audio Stuff --------

#define VOLUME 1500
#define BOOT_VOLUME 100
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

// *Note* - using dual_prop needs Blade Detect, not Blade ID ... for now... BC gettin to work-> 

//#define BLADE_DETECT_PIN 10 //10 is Free3 which is how the hilt is wired
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
#define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> //PBv2.2 uses this by default this for Blade ID. PBv3.x uses built in BridgedPullUp. Use reported ID: values in BladeConfig
/*  Millis is Blade ID scan interval. If the blade ID comes out the same as before, it will do nothing.
    If it comes out different, it will do FindBladeAgain(), which will basically initialize the saber
    from scratch and load the right settings for the new id().
   It will only work with neopixel blades, and it probably requires SHARED_POWER_PINS to work.*/
#define BLADE_ID_SCAN_MILLIS 1000
   // How many Blade ID scans to average
#define BLADE_ID_TIMES 10
#define DUAL_PROP_CONDITION (current_config != blades)

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
#define ENABLE_SERIAL //Bluetooth
#define BLE_PASSWORD "000000"
// #define DISABLE_COLOR_CHANGE
#define ENABLE_DEVELOPER_COMMANDS
//#define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 1 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE // default
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SDA_TOWARDS_BLADE // This means the SDA pad
// #define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE // This means the Serial pad (same side as speakers)
// The following changes the angle required to register twists on curved hilts.
// Example is for assaj ventress curved hit install
// #define ORIENTATION_ROTATION 0,-20,0
// #define CONFIG_STARTUP_DELAY 15000                 // BC now canon
#define DISABLE_BASIC_PARSER_STYLES               // Standard, Advanced, etc...

// #define  VERBOSE_SD_ERRORS


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

#define BLASTER_ENABLE_AUTO // was #define ENABLE_BLASTER_AUTO
#define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
#define BLASTER_JAM_PERCENTAGE 5     // if not defined, random.
#define BLASTER_DEFAULT_MODE MODE_KILL

#endif

// #ifdef CONFIG_POV //  226832 before this using the normal way
// #include "../styles/star_wars_logo_pov_data.h"
// #endif

// #ifdef CONFIG_PROP // Change buttons to FIRE and MODE down in CONFIG_BUTTONS to use blaster mode only 
// #include "../props/blaster_BC.h"
// #endif
// #ifdef CONFIG_PROP // Change buttons to FIRE and MODE down in CONFIG_BUTTONS to use blaster mode only 
// #include "../props/saber_BC_buttons_personal.h"
// #endif

#ifdef CONFIG_PROP // Leave buttons as POW and AUX down in CONFIG_BUTTONS
#include "../props/dual_prop.h"
#include "../props/saber_BC_buttons_personal.h"
#undef PROP_TYPE
#include "../props/blaster_BC_buttons.h"
#undef PROP_TYPE
#define PROP_TYPE SaberBlasterProp<SaberBCButtons, Blaster>
#endif

#ifdef CONFIG_PRESETS
// save mem by disabling unused aliases.
#include "aliases/TrueWhites/BC_effects_1.h"              // For Green, light Blue, ...light colored blades
#include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"  // EffectSequence driven different blast animations
#include "aliases/TrueWhites/BC_effects_2.h"              // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"            // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_White.h"          // For White blades
#include "aliases/TrueWhites/BC_12color_8effect_SS.h"     // Uses BC_SWAP for base blade color. All in one blade style from CC Fork. 96 possible blade combos in one style. .

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

//-----------------------------------------------------------------------------------------------------------------------

// Blade out
Preset blaster[] = {
{ "testblaster;common;commonB", "testblaster/tracks/track1.wav",

// { "blaster1;common;commonBU", "testfont2a/tracks/track1.wav",
// Main BLade
  StylePtr<Black>(),
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
  >>(),
// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipe<100>,White,TrWipe<100>,Red,TrWipe<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),

// Pommel
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// Bluetooth
  StylePtr<Blue>(),
"testblaster\nbladeout"},

{ "DL44;commonB", "tracks/DL44.wav",
// Main BLade
  StylePtr<Black>(),
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
  >>(),
// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipe<100>,White,TrWipe<100>,Red,TrWipe<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),

// Pommel
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// Bluetooth
  StylePtr<Blue>(),
"dl-44"},

{ "blaster1;commonB;", "blaster1/tracks/ImperialMarchROTJ3_long.wav",

// Main BLade
  StylePtr<Black>(),
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFadeX<Percentage<WavLen<>,25>>,Red,TrFadeX<Percentage<WavLen<>,75>>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
  >>(),
// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipe<100>,White,TrWipe<100>,Red,TrWipe<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),

// Pommel
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// Bluetooth
  StylePtr<Blue>(),
  "blaster1\nbladeout"},

{ "F11-D;commonB;", "blaster1/tracks/ImperialMarchROTJ3_long.wav",

// Main BLade
  StylePtr<Black>(),
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
  >>(),
// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipe<100>,White,TrWipe<100>,Red,TrWipe<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),

// Pommel
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// Bluetooth
  StylePtr<Blue>(),
  "f11-d\nbladeout"},
// 

};
// --------------------------------------------------------------------------------------------------------------------------------



// Blade in (saber or dual_prop) / Clip in (blaster only)
Preset saber [] = {

//    { "Gender_Reveal", "tracks/cantina.wav",
// StylePtr<Layers<StripesX<Int<2000>,Int<-800>,DeepPink,Blue,Blue>,
// TransitionEffectL<TrConcat<TrInstant,BlinkingX<DeepPink,Blue,Scale<Trigger<EFFECT_BLAST,Int<16000>,Int<2000>,Int<1>>,Int<1000>,Int<200>>,Int<500>>,TrDelay<18000>,Green,TrFade<1000>,Black,TrDelay<1000>,White,TrFade<3000>,Sparkle<AudioFlicker<DeepPink,HotPink>,White,50>,TrDelay<200000>>,EFFECT_BLAST>,
//   TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,EffectIncrementF<EFFECT_BLAST,Int<2>>>,EFFECT_BLAST>,
//   InOutTrL<TrWipe<1600>,TrWipeIn<500>>>>(),
// StylePtr<Layers<StripesX<Int<2000>,Int<-800>,DeepPink,Blue,Blue>,
// TransitionEffectL<TrConcat<TrInstant,BlinkingX<DeepPink,Blue,Scale<Trigger<EFFECT_BLAST,Int<16000>,Int<2000>,Int<1>>,Int<1000>,Int<200>>,Int<500>>,TrDelay<18000>,Green,TrFade<1000>,Black,TrDelay<1000>,White,TrFade<3000>,Sparkle<AudioFlicker<DeepPink,HotPink>,White,50>,TrDelay<200000>>,EFFECT_BLAST>,
//   TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,EffectIncrementF<EFFECT_BLAST,Int<2>>>,EFFECT_BLAST>,
//   InOutTrL<TrWipe<1600>,TrWipeIn<500>>>>(),
//          StylePtr<Black>(),
//        StylePtr<Black>(), 
//        StylePtr<Black>(), 
//        "gender\nreveal_PINK"},


// { "aa_Juansith/Red_Five;common", "aa_Juansith/Red_Five/tracks/Xwing.wav",
// { "aa_Juansith/Baby_Trainer90;common;commonBU", "",
{ "testfont2b;common;commonBU", "",
  StylePtr<Layers<
  StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RgbArg<BASE_COLOR_ARG,Blue>,Mix<Int<2570>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,Black>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,Pulsing<Mix<Int<6425>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RgbArg<BASE_COLOR_ARG,Blue>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Blue>>>,2000>,Pulsing<Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,Mix<Int<642>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,3000>>,
  AlphaL<StaticFire<RgbArg<BASE_COLOR_ARG,Blue>,Mix<Int<256>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,0,1,10,2000,2>,Int<10000>>,
  AlphaL<RgbArg<EMITTER_COLOR_ARG,LightCyan>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-6000>>>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RgbArg<IGNITION_COLOR_ARG,White>,40>,TrFade<1200>>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<2100>>,TrInstant>,Stripes<3000,3500,RgbArg<RETRACTION_COLOR_ARG,Blue>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Blue>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Blue>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Blue>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Blue>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Blue>>>>,TrFade<800>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RgbArg<STAB_COLOR_ARG,Red>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
  MultiTransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Aquamarine>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
  TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,DeepSkyBlue>,TrFade<300>>,EFFECT_CLASH>,
  LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Cyan>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Cyan>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Cyan>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Cyan>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Cyan>,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Cyan>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Cyan>,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,LightCyan>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,LightCyan>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,White>,IgnitionTime<>>,TrWipeInSparkTipX<RgbArg<RETRACTION_COLOR_ARG,Blue>,Scale<IsLessThan<IntArg<RETRACTION_TIME_ARG,2100>,Int<1>>,IntArg<RETRACTION_TIME_ARG,2100>,WavLen<EFFECT_RETRACTION>>>>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<PREON_COLOR_ARG,White>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,IntArg<PREON_SIZE_ARG,2000>,Sum<IntArg<PREON_SIZE_ARG,2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<POSTOFF_COLOR_ARG,White>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,IntArg<PREON_SIZE_ARG,2000>,Sum<IntArg<PREON_SIZE_ARG,2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>>>(),
         StylePtr<Black>(),
       StylePtr<Black>(), 
       StylePtr<Black>(), 
       StylePtr<Black>(), 
  "    red\n   five"},

  // { "TeensySF", "",
  //  &style_pov,
  //      StylePtr<Black>(),
  //      StylePtr<Black>(), 
  //      StylePtr<Black>(), 
  //      StylePtr<Black>(), 
  // "my_pov"},
  // { "Kaiju", "",
  //  &style_charging,
  //      StylePtr<Black>(),
  //      StylePtr<Black>(), 
  //      StylePtr<Black>(), 
  //      StylePtr<Black>(), 
  // "charging"},

      // { "aa_Juansith/Sereph100;common;commonBU", "",
{ "testfont2Q;common;commonBU", "",
  StylePtr<Layers<Black,AlphaL<
    // The following Red can be replaced by a Layers<> with your exising style stuff in it, 
    // from the base blade color down to, but not including, the InOutTrL.
    Red,
    IsGreaterThan<EffectIncrementF<EFFECT_USER4,Int<32768>,Int<16384>>,Int<100>>>,
    EffectSequence<EFFECT_USER4,TransitionEffectL<TrConcat<TrInstant,Black,TrWipe<500>>,EFFECT_USER4>,TransitionEffectL<TrConcat<TrInstant,
    // This Red should be the same as the base blade color layer
    Red,
    TrWipeInX<Int<600>>>,EFFECT_USER4>>,
    InOutTrL<TrInstant,TrWipeInX<WavLen<EFFECT_RETRACTION>>>
  >>(),
  StylePtr<Layers<
    Red,
    InOutTrL<TrWipeIn<300>,TrWipeX<WavLen<EFFECT_RETRACTION>>>
  >>(),
  StylePtr<Layers<
    Red,
    InOutTrL<TrWipeIn<300>,TrWipeX<WavLen<EFFECT_RETRACTION>>>
  >>(), 
       StylePtr<Black>(), 
       StylePtr<Black>(), 
  "Sereph100"},

    { "Dooku_CW;common;commonBU", "",
  StylePtr<Layers<Black,AlphaL<
    // The following Red can be replaced by a Layers<> with your exising style stuff in it, 
    // from the base blade color down to, but not including, the InOutTrL.
    Red,
    IsGreaterThan<EffectIncrementF<EFFECT_USER4,Int<32768>,Int<16384>>,Int<100>>>,
    EffectSequence<EFFECT_USER4,TransitionEffectL<TrConcat<TrInstant,Black,TrWipe<500>>,EFFECT_USER4>,TransitionEffectL<TrConcat<TrInstant,
    // This Red should be the same as the base blade color layer
    Red,
    TrWipeInX<Int<600>>>,EFFECT_USER4>>,
    InOutTrL<TrInstant,TrWipeInX<WavLen<EFFECT_RETRACTION>>>
  >>(),
  StylePtr<Layers<
    Red,
    InOutTrL<TrWipeIn<300>,TrWipeX<WavLen<EFFECT_RETRACTION>>>
  >>(),
  StylePtr<Layers<
    Red,
    InOutTrL<TrWipeIn<300>,TrWipeX<WavLen<EFFECT_RETRACTION>>>
  >>(), 
       StylePtr<Black>(), 
       StylePtr<Black>(), 
  "2nd blade test"},
// { "Kaiju;common;commonBU", "",

// // Harry Solo - Kaiju Blade Style - BC 2022

//   // first way
//           //AlphaL<Stripes<40000,-40,Pulsing<Black,TransitionLoop<Black,TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<300>,Int<1000>>>,Black,TrJoin<TrWipeInSparkTipX<White,Int<300>>,TrWipeSparkTipX<White,Int<300>>>>>,1500>,Pulsing<Black,TransitionLoop<AlphaL<AlphaL<Cyan,Int<16000>>,Int<10000>>,TrConcat<TrBoing<500,2>,Black,TrJoin<TrWipeInSparkTipX<White,Int<300>>,TrWipeSparkTipX<White,Int<300>>>>>,1500>,Pulsing<Black,TransitionLoop<Black,TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<300>,Int<1000>>>,Black,TrJoin<TrWipeInSparkTipX<White,Int<300>>,TrWipeSparkTipX<White,Int<300>>>>>,1500>,Pulsing<Black,TransitionLoop<AlphaL<Rgb<25,10,255>,Int<10000>>,TrConcat<TrBoing<500,2>,Black,TrFade<400>>>,1500>,Black>,Int<16000>>
//   // second way works, but dont like
//           // AlphaL<
//           //     PulsingL<
//           //         TransitionLoop<
//           //             AlphaL<ColorSequence<3500,Cyan,Black,Rgb<25,10,255>,Black>,Int<8000>>,
//           //             TrConcat<
//           //                 TrBoingX<Scale<Sin<Int<100>>,Int<300>,Int<2000>>,2>,
//           //                 Black,
//           //                 TrJoinR<
//           //                   TrWipeInSparkTipX<White,Int<300>>,
//           //                   TrWipeSparkTipX<White,Int<300>>>>>,
//           //     Int<1500>>,
//           // Int<10000>>,
//   //  added still stripes on swingspeed) meshed stripes for purple visibility
//     // AlphaL<Stripes<250,1,Green,Black>,                                               Bump<Int<0>,    Scale<RandomF,Int<200>,Int<18000>>>>,
//     // AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,                   Bump<Int<0>,Int<8000>>>,
//     // AlphaL<Stripes<250,1,Green,Black>,                                               Bump<Int<16384>,Scale<RandomF,Int<200>,Int<18000>>>>,
//     // AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,                   Bump<Int<16384>,Int<8000>>>,
//     // AlphaL<Stripes<250,1,Green,Black>,                                               Bump<Int<32768>,Scale<RandomF,Int<200>,Int<18000>>>>,
//     // AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,                   Bump<Int<32768>,Int<8000>>>,

// //    SmoothSoundLevel - got nothing - try noisy - nope. Kinda mellow without actually.
//     // AlphaL<Stripes<250,1,Green,Black>,                                               Bump<Int<0>,    Scale<NoisySoundLevel,Int<200>,Int<18000>>>>,
//     // AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,                   Bump<Int<0>,Int<8000>>>,
//     // AlphaL<Stripes<250,1,Green,Black>,                                               Bump<Int<16384>,Scale<NoisySoundLevel,Int<200>,Int<18000>>>>,
//     // AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,                   Bump<Int<16384>,Int<8000>>>,
//     // AlphaL<Stripes<250,1,Green,Black>,                                               Bump<Int<32768>,Scale<NoisySoundLevel,Int<200>,Int<18000>>>>,
//     // AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,                   Bump<Int<32768>,Int<8000>>>,

// //simply alternating-boring
// //     AlphaL<Pulsing<Stripes<250,1,Green,Black>,Black,600>,         Bump<Int<0>,    Scale<SmoothSoundLevel,Int<200>,Int<18000>>>,
// //     AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<0>,    Int<8000>>>,
// //     AlphaL<Pulsing<Stripes<250,1,Green,Black>,Black,600>,         Bump<Int<16384>,Scale<SmoothSoundLevel,Int<200>,Int<18000>>>,
// //     AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<16384>,Int<8000>>>,
// //     AlphaL<Pulsing<Stripes<250,1,Green,Black>,Black,600>,         Bump<Int<32768>,Scale<SmoothSoundLevel,Int<200>,Int<18000>>>,
// //     AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<32768>,Int<8000>>>,

// // //random green pulsing, steady purple-meh
//   // AlphaL<PulsingX<Stripes<250,1,Green,Black>,Black,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<1000>>,Int<5000>,Int<10000>>>,Bump<Int<0>,Scale<Sin<Int<10>>,Int<1200>,Int<18000>>>>,
//   // AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<0>,Int<12000>>>,
//   // AlphaL<PulsingX<Stripes<250,1,Green,Black>,Black,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<1000>>,Int<5000>,Int<10000>>>,Bump<Int<16384>,Scale<Sin<Int<10>>,Int<1200>,Int<18000>>>>,
//   // AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<16384>,Int<12000>>>,
//   // AlphaL<PulsingX<Stripes<250,1,Green,Black>,Black,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<1000>>,Int<5000>,Int<10000>>>,Bump<Int<32768>,Int<18000>>>,
//   // AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<32768>,Int<12000>>>,

// //steady sin appeance of flickery- ok - has motion
// //   AlphaL<PulsingX<Stripes<250,1,Green,Black>,Black,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<2000>>,Int<5000>,Int<10000>>>,Bump<Int<0>,Scale<Sin<Int<70>>,Int<1200>,Int<18000>>>>,
// //   AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<0>,Int<12000>>>,
// //   AlphaL<PulsingX<Stripes<250,1,Green,Black>,Black,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<3000>>,Int<5000>,Int<10000>>>,Bump<Int<16384>,Scale<Sin<Int<70>>,Int<1200>,Int<18000>>>>,
// //   AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<16384>,Int<12000>>>,
// //   AlphaL<PulsingX<Stripes<250,1,Green,Black>,Black,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<3000>>,Int<5000>,Int<10000>>>,Bump<Int<32768>,Scale<Sin<Int<70>>,Int<1200>,Int<18000>>>>,
// //   AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<32768>,Int<12000>>>,

// // // back to random green strpes-- too random
// // AlphaL<Stripes<250,1,Green,Black>,                              Bump<Int<0>,Scale<RandomF,Int<500>,Int<18000>>>>,
// //   AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<0>,Int<12000>>>,
// // AlphaL<Stripes<250,1,Green,Black>,                              Bump<Int<16384>,Scale<RandomF,Int<500>,Int<18000>>>>,
// //   AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<16384>,Int<12000>>>,
// // AlphaL<Stripes<250,1,Green,Black>,                              Bump<Int<32768>,Scale<RandomF,Int<500>,Int<18000>>>>,
// //   AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<32768>,Int<12000>>>,

// //reeling it in
//   // AlphaL<Stripes<250,1,Green,Black>,                            Bump<Int<0>,    Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<70000>>,Int<500>,Int<18000>>>>,
//   // AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<0>,    Int<12000>>>,
//   // AlphaL<Stripes<250,1,Green,Black>,                            Bump<Int<16384>,Scale<RandomF,Int<200>,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<70000>>,Int<500>,Int<18000>>>>>,
//   // AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<16384>,Int<12000>>>,
//   // AlphaL<Stripes<250,1,Green,Black>,                            Bump<Int<32768>,Scale<RandomF,Int<500>,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<70000>>,Int<500>,Int<18000>>>>>,
//   // AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,Bump<Int<32768>,Int<12000>>>,

// // how bout doing them all the right way, not  just emitter
// // // back to basic pulse

// StylePtr<Layers<
//   Black,
//   AlphaL<
//     Stripes<40000,-100,
//       Pulsing<
//         Black,
//         TransitionLoop<Black,
//           TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<300>,Int<1000>>>,Black,TrWipeInSparkTipX<White,Int<300>>>>,1500>,
//       Pulsing<
//         Black,
//         TransitionLoop<AlphaL<Green,Int<8000>>,
//           TrConcat<TrBoing<500,2>,Black,TrJoin<TrWipeInSparkTipX<White,Int<300>>,TrWipeSparkTipX<White,Int<300>>>>>,1500>,
//       Pulsing<Black,
//         TransitionLoop<Black,
//           TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<300>,Int<1000>>>,Black,TrJoin<TrWipeInSparkTipX<White,Int<300>>,TrWipeSparkTipX<White,Int<300>>>>>,1500>>,
//   Int<16000>>,
//   AlphaL<Stripes<250,1,Green,Black>,LayerFunctions<Bump<Int<0>,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<70000>>,Int<500>,Int<18000>>>,Bump<Int<16384>,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<70000>>,Int<500>,Int<18000>>>,Bump<Int<32768>,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<70000>>,Int<500>,Int<18000>>>>>,
//   AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,LayerFunctions<Bump<Int<0>,Int<12000>>,Bump<Int<16384>,Int<12000>>,Bump<Int<32768>,Int<12000>>>>,
// // Swing color
//     AlphaL<Stripes<2800,1,Blue,Cyan,Rgb<128,128,128>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// // Force Choke / lightning
//     TransitionEffectL<TrConcat<TrSmoothFade<1000>,Strobe<Black,Rgb<80,0,0>,30,30>,TrFade<1500>,StyleFire<Red,Strobe<Black,White,30,30>,0,3,FireConfig<300,2000,5>>,TrFade<400>>,EFFECT_FORCE>,
// // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//         AlphaL<Black,Int<16384>>,
//         AlphaL<Black,Int<0>>>,
// // Clash
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// // Stab - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// // Blast v1
//     TransitionEffectL<TrConcat<
//         // Impact Flash - BC always
//         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//         // Waves
//         BlastL<Rgb<100,200,255>,850,250,351>,
//         // Impact point afterimage
//         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         // Impact point
//         BlastL<Rgb<100,200,255>,300,350,100000>,
// // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//         //Random Strobe Flash no dimming
//         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
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
// // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
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
// // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//         AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//         // Melt Shape
//         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//         // Melt Begin and End transitions
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
// // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrJoin<TrWipeX<Int<200>>,TrWaveX<White,Int<200>,Int<400>,Int<200>,Int<0>>>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<400>,StyleFire<Rgb<100,200,255>,Rgb<60,60,60>,0,8>,TrFadeX<Int<1700>>>,EFFECT_IGNITION>,
//   TransitionEffectL<TrConcat<TrInstant,Cyan,TrDelay<100>,AlphaL<Black,Int<0>>,TrDelay<70>,Green,TrDelay<100>,AlphaL<Black,Int<0>>,TrDelay<70>,Yellow,TrDelay<100>,AlphaL<Black,Int<0>>,TrDelay<70>,Magenta,TrDelay<100>,AlphaL<Black,Int<0>>,TrDelay<70>,White,TrDelay<100>>,EFFECT_RETRACTION>,
//   InOutTrL<TrWipe<200>,TrColorCycle<1374>>,
// // Preon
//   TransitionEffectL<TrConcat<TrDelay<3526>,AlphaL<Black,Int<0>>,TrFade<400>,AlphaL<HumpFlicker<White,Red,100>,Bump<Int<16384>,Int<40000>>>,TrFade<300>,SparkleL<Red,600,300>,TrFade<400>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrDelay<3038>,AlphaL<Black,Int<0>>,TrFade<200>,Stripes<1000,7000,Blue,Cyan,Blue,Black,Black,Black,Black>,TrDelay<300>,Stripes<1000,7000,Blue,Cyan,Blue,Black,Black,Black,Black>,TrFade<219>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrFade<217>,AlphaL<BrownNoiseFlicker<Red,Black,500>,Bump<Int<0>>>,TrFade<217>,AlphaL<Black,Int<0>>,TrFade<217>,AlphaL<BrownNoiseFlicker<Red,Black,500>,Bump<Int<0>,Int<50000>>>,TrFade<217>,AlphaL<Black,Int<0>>,TrFade<217>,AlphaL<BrownNoiseFlicker<Red,Black,500>,Bump<Int<0>>>,TrFade<217>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrDelay<1283>,AlphaL<HumpFlicker<White,Red,20>,Bump<Int<8000>>>,TrFade<478>,AlphaL<Black,Int<0>>,TrInstant,AlphaL<HumpFlicker<White,Red,20>,Bump<Int<25000>>>,TrFade<400>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrFade<1300>,SparkleL<Stripes<1000,-1000,Cyan,Magenta,Black,Blue>,200,600>,TrDelay<1000>,SparkleL<Stripes<2000,2000,Green,Rgb<0,50,200>>,2000,1200>,TrDelay<735>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrDelay<4244>,AlphaL<Black,Int<0>>,TrWaveX<RandomPerLEDFlicker<Rgb<130,50,255>,Black>,Int<500>,Int<50>,Int<400>,Int<0>>,AlphaL<Black,Int<0>>,TrWaveX<RandomPerLEDFlicker<Rgb<130,50,255>,Black>,Int<700>,Int<50>,Int<320>,Int<32000>>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrDelay<5012>,SparkleL<DodgerBlue,6000,200>,TrDelay<885>,SparkleL<DodgerBlue,6000,200>,TrSmoothFade<900>,SparkleL<DodgerBlue,1000,5000>,TrDelay<20>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrDelay<5716>,AlphaL<Black,Int<0>>,TrFade<200>,AlphaL<Stripes<1000,-4000,Rgb<20,10,100>,Rgb<10,0,200>,Yellow,Black,Black>,SmoothStep<Int<8192>,Int<-1>>>,TrDelay<200>,AlphaL<Stripes<1000,-4000,Rgb<20,10,100>,Rgb<10,0,200>,Yellow,Black,Black>,SmoothStep<Int<16384>,Int<-1>>>,TrDelay<200>,Stripes<1000,-4000,Rgb<20,10,100>,Rgb<10,0,200>,Yellow,Black,Black>,TrDelay<100>,AlphaL<Stripes<1000,-4000,Rgb<20,10,100>,Rgb<10,0,200>,Yellow,Black,Black>,SmoothStep<Int<32768>,Int<-1>>>,TrDelay<75>,AlphaL<Black,Int<0>>,TrSmoothFade<375>,HumpFlicker<Red,White,15>,TrSmoothFade<172>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrDelay<2088>,Layers<
//     AlphaL<HumpFlicker<White,Red,20>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<1>,Int<2088>,Int<950>>,Int<-100>,Int<16385>>,Int<-1>>>,
//     AlphaL<HumpFlicker<White,Red,20>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<1>,Int<2088>,Int<950>>,Int<33000>,Int<16384>>,Int<0>>>>,TrDelay<3038>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrDelay<7224>,Black,TrSmoothFade<200>,HumpFlicker<Black,Green,10>,TrSmoothFade<739>>,EFFECT_PREON>,
// // On-Demand Battery Level
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
//   "kaiju"},












// { "testfont2a;common;commonBU", "testfont2a/tracks/track2.wav",
// // main blade  // So PRIDEful lol.
//   StylePtr<Layers<
//     //AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
// Black,
// Layers<
// AlphaL<Red,LinearSectionF<Int<1638>,Int<3277>>>,
// AlphaL<Orange,LinearSectionF<Int<4915>,Int<3277>>>,
// AlphaL<Yellow,LinearSectionF<Int<7292>,Int<3277>>>,
// AlphaL<Green,LinearSectionF<Int<10568>,Int<3277>>>,
// AlphaL<Blue,LinearSectionF<Int<13846>,Int<3277>>>,
// AlphaL<White,LinearSectionF<Int<17123>,Int<3277>>>,
// AlphaL<Magenta,LinearSectionF<Int<20400>,Int<3277>>>,
// AlphaL<DeepSkyBlue,LinearSectionF<Int<23677>,Int<3277>>>,
// AlphaL<GreenYellow,LinearSectionF<Int<26954>,Int<3277>>>,
// AlphaL<OrangeRed,LinearSectionF<Int<30231>,Int<3277>>>>,
//   // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//     AlphaL<Black,Int<16384>>,
//     AlphaL<Black,Int<0>>>,
//   // Clash
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//   // Stab 
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,DarkOrange,Rgb<80,60,0>,Orange,Rgb<60,30,0>,Black,DarkOrange,Orange>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//   // Blast - white to red for blue and green blades
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//     BlastL<Red,850,250,351>,
//     AlphaL<TransitionEffectL<TrConcat<TrDelay<300>,Red,TrFade<500>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//     BlastL<White,500,300,100000>,
//   // Lockup
//     LockupTrL<Layers<       
//       AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//       AlphaL<BrownNoiseFlicker<Yellow,Black,50>,                                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//       TrConcat<TrInstant,
//       AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//   // Non-Responsive Drag
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block Non-Responsive    
//     LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//     Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//     Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//     Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
//     //Begin Lightning Transition
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//     //End Lightning Transition    
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,       
//   // Melt    
//     LockupTrL<
//     AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//     // Melt Shape
//     SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//     //Melt Begin and End transitions
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,  // Great melt colors as you twist, gets dripping red hot/fire and bright yellow.
//   // Ignition / Retraction
//     InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_FORCE>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
  // StylePtr<Layers<
  //   Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,200>,
  //   InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
//   "testdualprop\nblade in"},


// { "aa_JayDalorian/nobunaga;common;commonBU", "aa_JayDalorian/nobunaga/tracks/sharingan.wav",

// // Main Blade
  
// StylePtr<Layers<
//   StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,20>,RotateColorsX<Variation,Rgb<7,5,0>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Blue>,70>,RotateColorsX<Variation,
// DodgerBlue>>,RotateColorsX<Variation,Red>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
//   TransitionEffectL<TrConcat<TrFade<400>,StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,AudioFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,
// RotateColorsX<Variation,Rgb<10,0,0>>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,70>,RotateColorsX<Variation,Red>>,Blue,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,
// FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrDelay<30000>,StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,AudioFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,
// RotateColorsX<Variation,Rgb<10,0,0>>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,25>>,70>,RotateColorsX<Variation,Rgb<128,0,0>>>,Rgb<80,0,0>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,
// FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrFade<800>>,EFFECT_FORCE>,
//   AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,Black>,Black,RotateColorsX<Variation,Blue>,Black>,SwingSpeed<600>>,
//   LockupTrL<Layers<
//     AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
//     AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,
// Int<30000>>,Int<10000>>,Int<20000>>>,TrFade<400>>,TrConcat<TrInstant,AlphaL<Mix<SmoothStep<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<1000>>,Stripes<1500,2000,
// TransitionEffect<Moccasin,Rgb<255,150,0>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Rgb<180,130,0>>,Stripes<1500,-2500,TransitionEffect<Moccasin,Rgb<255,150,0>,TrInstant,TrFade<200>,
// EFFECT_LOCKUP_BEGIN>,Rgb<180,130,0>>>,Int<18000>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
//   ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,
// TrSmoothFade<600>>>,
//   ResponsiveStabL<Red>,
//   ResponsiveBlastWaveL<Blue,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
//   ResponsiveClashL<White,TrInstant,TrFade<400>,Int<28000>,Int<8000>,Int<20000>>,
//   LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
//   LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//   InOutTrL<TrJoinR<TrWipe<1000>,TrWipeIn<750>>,TrWipeIn<1000>>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<180,130,0>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,TrDelay<2000>>,
// EFFECT_RETRACTION>,
//   TransitionEffectL<TrConcat<TrInstant,Layers<
//     AlphaL<TransitionLoopL<TrConcat<TrWaveX<RotateColorsX<Variation,DodgerBlue>,Int<300>,Int<200>,Int<300>,Int<0>>,Black,TrDelay<0>>>,SmoothStep<Int<16384>,Int<-100>>>>,TrDelay<1435>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RotateColorsX<Variation,Blue>,Bump<Int<16384>,Int<4000>>>,TrFade<2000>,AlphaL<AudioFlickerL<RotateColorsX<Variation,Blue>>,Bump<Int<16384>,Int<16000>>>,
// TrDelay<700>>,EFFECT_PREON>>>(),
// // HiltPCB
//   StylePtr<Black>(),
// // Switches
//   StylePtr<Layers<
//     Pulsing<RotateColorsX<Variation,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,20>>,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,20>>,Black,2500>>>>(),
// // Pommel
//   StylePtr<Layers<
//     Pulsing<Blue,Black,200>,
//     InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// // Bluetooth
//   StylePtr<Blue>(),
//   "nobunaga"},



// { "Plane;common;commonBU", "",
// // Main Blade
//   StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
// // HiltPCB
//   StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
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
//   "plane"},

// { "TeensySF;common", "",
// // Main Blade
//   StylePtr<Blue>(),
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
//   "TeensySF\nbladein"},



};  

//-----------------------------------------------------------------------------------------------------------------------


struct AccentsLED {
static constexpr float MaxAmps = 0.02;
static constexpr float MaxVolts = 3.2;
static constexpr float P2Amps = 0.015;
static constexpr float P2Volts = 3.0;
static constexpr float R = 0; // Resistor value
static const int Red = 0;
static const int Green = 0;
static const int Blue = 255;
};

BladeConfig blades[] = {


{ 750000,                                      // D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
  WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<10, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches 
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth                                                                     // barrel
CONFIGARRAY(blaster),
"01_BlasterSave"},

{ 630000,    // BCA 123,  1" Ciel_Tan_A 132           D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
  WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<10, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth                                                                     // barrel
CONFIGARRAY(saber),
"00_SaberSave"}

};
#endif

#ifdef CONFIG_BUTTONS
// For saber or dual_prop:
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");

// For blaster only:
Button Clip(BUTTON_CLIP_DETECT, aux2Pin, "clip");
// Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
// Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");
//Button ReloadButton(BUTTON_RELOAD, 7, "reload"); // pin7?? SDA? why? use aux2Pin.
#endif
