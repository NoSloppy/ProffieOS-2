// BC_DL44_8.x.h

#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
// ------ Audio Stuff --------

#define VOLUME 2500
#define BOOT_VOLUME 400
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
#define FEMALE_TALKIE_VOICE                       // BC now canon

// ------ Blade Stuff ------

const unsigned int maxLedsPerStrip = 144;

// ------ SD Card Stuff -------

#define MOUNT_SD_SETTING
// #define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    // #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING

// ------ System Stuff --------

// #define ENABLE_DEBUG
   // PVLOG_ERROR 100 = errors
   // PVLOG_STATUS 200 = things you should probably know, like blade ID
   // PVLOG_NORMAL 300 = normal information about what is happening (default level)
   // PVLOG_DEBUG 400 = information helpful for debugging
   // PVLOG_VERBOSE 500 = repeated, spammy information you don't normally want
 #define PROFFIEOS_LOG_LEVEL 300

// #define ENABLE_DEVELOPER_COMMANDS
// #define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES                 // Standard, Advanced, Old School original templated styles etc...
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000

#define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE // This means the Serial pad (same side as speakers)

#define CONFIG_STARTUP_DELAY 1000               // BC now canon

// ------- Motion and Gesture stuff -------

#define CLASH_THRESHOLD_G 3.5
// Use this define to turn on an optional "iPod® Clickwheel" sound when rotating the hilt in smooth colorchange mode (Color Wheel).
// mclick.wav will play, so the sound should probably be a very subtle "tick" sound.
// The value is the number of ticks per 360 hilt rotation. Higher number = more ticks per angle change.
// Suggested Range 50 - 120. Using zero or not defining will turn ticks off.
#define SMOOTH_COLORCHANGE_TICKS_PER_REVOLUTION 120
// Rotation sensitivity
#define STEPS_PER_REVOLUTION 24

// -------- BC Prop Other Stuff --------

// OS Menu 
//  #define MENU_SPEC_TEMPLATE DefaultMenuSpec

// --------- blaster --------------

#define BLASTER_ENABLE_AUTO
//#define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
#define BLASTER_JAM_PERCENTAGE 5     // if not defined, no jams.
#define BLASTER_DEFAULT_MODE MODE_KILL
#endif

#ifdef CONFIG_PROP
#include "../props/blaster_BC_buttons.h"
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {



// { "testblaster;commonB", "tracks/DL44.wav",
//   StylePtr<Layers<
//     Black,
//     TransitionEffectL<TrConcat<TrDelay<100>,Red,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
//     TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
//     LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
  //   TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
  //   TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  // >>(),
// "testblaster"},

{ "DL44;ProffieOS_V2_Voicepack_Rebel_Leia/common;commonB", "tracks/DL44.wav",
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,Red,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
  >>(),
"han dl-44"},

{ "Bowcaster;ProffieOS_V2_Voicepack_C-3PO/common;commonB", "tracks/Bowcaster.wav",
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Blinking<Black,Green,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Green,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<0,50,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
  >>(),
"bowcaster"},

{ "EE-3;ProffieOS_V2_Voicepack_Vader_V2/common;commonB", "tracks/EE-3.wav",
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
  >>(),
"ee-3"},

{ "NN14;ProffieOS_V2_Voicepack_Rey/common;commonB", "tracks/NN14.wav",
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Rgb<180,0,0>,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
  >>(),
"rey nn14"},

{ "A180;ProffieOS_V2_Voicepack_Rey/common;commonB", "tracks/A180.wav",
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
  >>(),
"jyn a180"},

{ "E-11;ProffieOS_V2_Voicepack_Vader_V2/common;commonB", "tracks/ImperialMarchROTJ3_long.wav",
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
  >>(),
"stormtrooper E-11"},

{ "F11-D;ProffieOS_V2_Voicepack_Vader_V2/common;commonB", "tracks/ImperialMarchROTJ3_long.wav",
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
  >>(),
"stormtrooper f11-d"},

{ "DLT-19;ProffieOS_V2_Voicepack_Emperor/common;commonB", "tracks/DLT-19.wav",
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,DarkOrange,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,DarkOrange,TrFade<25>,Black,TrFade<25>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
  >>(),
"stormtrooper heavy dlt-19"},

{ "WESTAR-35;ProffieOS_V2_Voicepack_Din_Djarin/common;commonB", "tracks/Westar.wav",
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,DarkOrange,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,Green,TrFade<200>,Blinking<Black,DeepSkyBlue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,DeepSkyBlue,TrFade<50>,DarkOrange,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
  >>(),
"jango westar"},

{ "BadBatch;ProffieOS_V2_Voicepack_Vader_V2/common;commonB", "tracks/BadBatch.wav",
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Blue,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,Magenta,TrFade<200>,Blinking<Black,Magenta,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<25>,Blue,TrFade<100>>>>,TrInstant,TrConcat<TrInstant,Rgb<0,0,50>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
  >>(),
"bad batch cf-99"},

{ "MouthBlaster;ProffieOS_V2_Voicepack_C-3PO/common;commonB", "tracks/Cantina.wav",
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,Blue,TrFade<200>,Blinking<Black,DeepSkyBlue,100,500>,TrFade<500>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,White,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<225,225,225>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
  >>(),
"mouthblaster"},

};
BladeConfig blades[] = {
{ 0, WS281XBladePtr<9, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
CONFIGARRAY(presets) },
};

#endif

#ifdef CONFIG_BUTTONS
Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
Button ModeButton(BUTTON_MODE_SELECT, auxPin, "mode");
Button ReloadButton(BUTTON_RELOAD, aux2Pin, "reload");

#endif
