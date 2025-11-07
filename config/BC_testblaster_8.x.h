// BC_testblaster_8.x.h

#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2

// ------ Audio Stuff --------

#define VOLUME 2000
#define BOOT_VOLUME 200
// #define ENABLE_AUDIO
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                   // SPDIF out
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
#define FEMALE_TALKIE_VOICE                       // BC now canon
// #define DISABLE_TALKIE                           // I feel I'm not gonna like this
#define ENABLE_IDLE_SOUND

// ------ Blade Stuff ------

const unsigned int maxLedsPerStrip = 144;
//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet. Equivalent to just increasing maxLedsPerStrip.
// #define EXTRA_COLOR_BUFFER_SPACE 30
// #define SHARED_POWER_PINS
// #define BLADE_DETECT_PIN blade3Pin
// #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9>         // TX pad
//    This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
//    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value, so I would recommend using something like 200000 instead of NO_BLADE.
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> 
//    Millis is Blade ID scan interval. If the blade ID comes out the same as before, it will do nothing.
//    If it comes out different, it will do FindBladeAgain(), which will basically initialize the saber from scratch and load the right settings for the new id().
//    It will only work with neopixel blades, and it probably requires SHARED_POWER_PINS to work.
// #define BLADE_ID_SCAN_MILLIS 1000
//    How many Blade ID scans to average
// #define BLADE_ID_TIMES 10

// ------ SD Card Stuff -------

#define MOUNT_SD_SETTING
// #define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    // #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//    Upload overwrites presets.ini/tmp unless this is defined
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING      

// ------- OLED stuff ----------

// #define ENABLE_SSD1306                         // OLED display. also defines ENABLE_DISPLAY_CODE
// #define OLED_FLIP_180                          // BC now canon
// #define OLED_MIRRORED
// #define USE_AUREBESH_FONT                      // BC now canon
// #define PLI_OFF_TIME 60 * 5 * 1000
// #define OLED_USE_BLASTER_IMAGES
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144_SC_POV_data.h"
//    Turns power to the OLED display off once SCREEN_OFF state. (Either IDLE_OFF_TIME or PLI_OFF_TIME)
// #define DISPLAY_POWER_PINS PowerPINS<bladePowerPin6> 

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

//#define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE // This means the Serial pad (same side as speakers)

//#define CONFIG_STARTUP_DELAY 1000               // BC now canon

// ------- Motion and Gesture stuff -------

#define CLASH_THRESHOLD_G 3.5
// #define BC_SWING_ON
// #define BC_STAB_ON
// #define BC_THRUST_ON
// #define BC_TWIST_ON
// #define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
// #define ENABLE_SPINS
// #define GESTURE_AUTO_BATTLE_MODE
// #define BC_LOCKUP_DELAY 200
// Use this define to turn on an optional "iPod® Clickwheel" sound when rotating the hilt in smooth colorchange mode (Color Wheel).
// mclick.wav will play, so the sound should probably be a very subtle "tick" sound.
// The value is the number of ticks per 360 hilt rotation. Higher number = more ticks per angle change.
// Suggested Range 50 - 120. Using zero or not defining will turn ticks off.
#define SMOOTH_COLORCHANGE_TICKS_PER_REVOLUTION 120
// Rotation sensitivity
#define STEPS_PER_REVOLUTION 24

// -------- BC Prop Other Stuff --------

// #define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second.
// #define NO_BLADE_NO_GEST_ONOFF                   // If using blade detect, No Blade = No Gesture ignitions or retractions
// #define NO_VOLUME_MENU                           // self evident. But why?

// --------- OS Menu -------------
//  #define MENU_SPEC_TEMPLATE DefaultMenuSpec

// --------- blaster --------------

// #define BLASTER_ENABLE_AUTO
#define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
#define BLASTER_JAM_PERCENTAGE 5     // if not defined, no jams.
 // #define BLASTER_DEFAULT_MODE MODE_KILL
// #define RELOAD_BUTTON_IS_POWER
#endif

#ifdef CONFIG_PROP
#include "../props/blaster_BC_buttons.h"
// #include "../props/blaster.h"
#endif

#ifdef CONFIG_PRESETS

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

Preset presets[] = {

{ "testblaster;ProffieOS_V2_Voicepack_Thrawn/common", "tracks/DL44.wav",
// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipe<200>,Red,TrWipe<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,Red,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  >>(),
"testblaster"},

{ "DL44;ProffieOS_V2_Voicepack_Thrawn/common", "tracks/DL44.wav",
// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipe<100>,Red,TrWipe<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),
// muzzle
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

// { "NN14;commonB", "tracks/NN14.wav",
//   StylePtr<Layers<
//     Black,
//     TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Rgb<180,0,0>,TrFade<300>>,EFFECT_FIRE>,
//     TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
//     LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
//     TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
//     TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
//   >>(),
// "rey nn14"},

// { "A180;commonB", "tracks/A180.wav",
//   StylePtr<Layers<
//     Black,
//     TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
//     TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
//     LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
//     TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
//     TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
//   >>(),
// "jyn a180"},

// { "F11-D;commonB", "F11-D/tracks/ImperialMarchROTJ3_long.wav",
//   StylePtr<Layers<
//     Black,
//     TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
//     TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
//     LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
//     TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
//     TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
//   >>(),
// "stormtrooper f11-d"},

// { "DLT-19;commonB", "tracks/DLT-19.wav",
//   StylePtr<Layers<
//     Black,
//     TransitionEffectL<TrConcat<TrDelay<100>,DarkOrange,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
//     TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
//     LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,DarkOrange,TrFade<25>,Black,TrFade<25>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
//     TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
//     TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
//   >>(),
// "stormtrooper heavy dlt-19"},

// { "WESTAR-35;commonB", "tracks/Westar.wav",
//   StylePtr<Layers<
//     Black,
//     TransitionEffectL<TrConcat<TrDelay<100>,DarkOrange,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
//     TransitionEffectL<TrConcat<TrDelay<100>,Green,TrFade<200>,Blinking<Black,DeepSkyBlue,100,500>,TrFade<300>>,EFFECT_STUN>,
//     LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,DeepSkyBlue,TrFade<50>,DarkOrange,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
//     TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
//     TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
//   >>(),
// "jango westar"},

// { "BadBatch;commonB", "tracks/BadBatch.wav",
//   StylePtr<Layers<
//     Black,
//     TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Blue,TrFade<300>>,EFFECT_FIRE>,
//     TransitionEffectL<TrConcat<TrDelay<100>,Magenta,TrFade<200>,Blinking<Black,Magenta,100,500>,TrFade<300>>,EFFECT_STUN>,
//     LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<25>,Blue,TrFade<100>>>>,TrInstant,TrConcat<TrInstant,Rgb<0,0,50>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
//     TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
//     TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
//   >>(),
// "bad batch cf-99"},

// { "MouthBlaster;commonB", "tracks/medley1.wav",
//   StylePtr<Layers<
//     Black,
//     TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
//     TransitionEffectL<TrConcat<TrDelay<100>,Blue,TrFade<200>,Blinking<Black,DeepSkyBlue,100,500>,TrFade<500>>,EFFECT_STUN>,
//     LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,White,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<225,225,225>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
//     TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
//     TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>
//   >>(),
// "mouthblaster"},

};
BladeConfig blades[] = {
{ 0,
  WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin6> >(),
  WS281XBladePtr<8, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),
CONFIGARRAY(presets) },
};

#endif

#ifdef CONFIG_BUTTONS
Button FireButton(BUTTON_FIRE, auxPin, "fire");
Button ModeButton(BUTTON_MODE_SELECT, powerButtonPin, "mode");
// Button ReloadButton(BUTTON_RELOAD, aux2Pin, "reload");

#endif
