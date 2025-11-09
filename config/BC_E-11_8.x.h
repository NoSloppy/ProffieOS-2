// BC_E-11_8.x.h

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
// ------ Audio Stuff --------

#define VOLUME 2500
#define BOOT_VOLUME 200
#define ENABLE_AUDIO
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
#define FEMALE_TALKIE_VOICE

// ------ Blade Stuff ------

const unsigned int maxLedsPerStrip = 144;

// ------ SD Card Stuff -------

#define MOUNT_SD_SETTING

// ------ System Stuff --------

// #define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES                 // Standard, Advanced, Old School original templated styles etc...
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
#define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE

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
// // OS Menu 
//  #define MENU_SPEC_TEMPLATE DefaultMenuSpec

// --------- blaster --------------

// #define BLASTER_ENABLE_AUTO  // not needed. just have auto.wav fies or not
#define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
#define BLASTER_JAM_PERCENTAGE 5     // if not defined, no jams.
 // #define BLASTER_DEFAULT_MODE MODE_STUN
#endif

#ifdef CONFIG_PROP
#include "../props/blaster_BC_buttons.h"
#endif

#ifdef CONFIG_PRESETS

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

Preset presets[] = {

// { "testblaster;ProffieOS_V2_Voicepack_Thrawn/common", "tracks/DL44.wav",
// // barrel
//   StylePtr<Layers<
//     Black,
//     TransitionEffectL<TrConcat<TrWipe<200>,Red,TrWipe<200>>,EFFECT_FIRE>,
//     TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
//     LockupTrL<Layers<
//       TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
//       TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
//     OnDemandBatteryLevel,
//     OnDemandVolumeLevel
//   >>(),
// // muzzle
//   StylePtr<Layers<
//     Black,
//     TransitionEffectL<TrConcat<TrDelay<100>,Red,TrFade<300>>,EFFECT_FIRE>,
//     TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
//     LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
//     TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
//     TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
//   >>(),
// "testblaster"},

{ "E-11;ProffieOS_V2_Voicepack_Vader_V2/common;commonB", "tracks/ImperialMarchROTJ3_long.wav",
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
    TransitionEffectL<TrConcat<TrDelay<100>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),
"stormtrooper e-11"},

{ "F11-D;ProffieOS_V2_Voicepack_Vader_V2/common;commonB", "tracks/ImperialMarchROTJ3_long.wav",
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
    TransitionEffectL<TrConcat<TrDelay<100>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),
"stormtrooper f11-d"},

{ "DL44;ProffieOS_V2_Voicepack_Rebel_Leia/common;commonB", "tracks/DL44.wav",
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
    TransitionEffectL<TrConcat<TrDelay<100>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),
"han dl-44"},

{ "NN14;ProffieOS_V2_Voicepack_Rey/common;commonB", "tracks/NN14.wav",
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
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Rgb<180,0,0>,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),
"rey nn14"},

{ "A180;ProffieOS_V2_Voicepack_Rey/common;commonB", "tracks/A180.wav",
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
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),
"jyn a180"},

{ "DLT-19;ProffieOS_V2_Voicepack_Emperor/common;commonB", "tracks/DLT-19.wav",
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
    TransitionEffectL<TrConcat<TrDelay<100>,DarkOrange,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,DarkOrange,TrFade<25>,Black,TrFade<25>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),
"stormtrooper heavy dlt-19"},

{ "WESTAR-35;ProffieOS_V2_Voicepack_Din_Djarin/common;commonB", "tracks/Westar.wav",
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
    TransitionEffectL<TrConcat<TrDelay<100>,DarkOrange,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,Green,TrFade<200>,Blinking<Black,DeepSkyBlue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,DeepSkyBlue,TrFade<50>,DarkOrange,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),
"jango westar"},

{ "BadBatch;ProffieOS_V2_Voicepack_Vader_V2/common;commonB", "tracks/BadBatch.wav",
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
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Blue,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,Magenta,TrFade<200>,Blinking<Black,Magenta,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<25>,Blue,TrFade<100>>>>,TrInstant,TrConcat<TrInstant,Rgb<0,0,50>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),
"bad batch cf-99"},

{ "MouthBlaster;ProffieOS_V2_Voicepack_C-3PO/common;commonB", "tracks/Cantina.wav",
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
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,Blue,TrFade<200>,Blinking<Black,DeepSkyBlue,100,500>,TrFade<500>>,EFFECT_STUN>,
    LockupTrL<Layers<TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,White,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<225,225,225>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrExtend<1000,TrFade<250>>,Mix<BatteryLevel,Red,Green>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Black,75,500>,TrFade<1000>>,EFFECT_BOOM>,
    OnDemandBatteryLevel,
    OnDemandVolumeLevel
  >>(),
"mouthblaster"},

};
BladeConfig blades[] = {
{ 0,
  WS281XBladePtr<50, bladePin, Color8::GRB, PowerPINS<bladePowerPin6> >(),
  WS281XBladePtr<8, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),
CONFIGARRAY(presets) },
};

#endif

#ifdef CONFIG_BUTTONS
Button FireButton(BUTTON_FIRE, auxPin, "fire");
Button ModeButton(BUTTON_MODE_SELECT, powerButtonPin, "mode");
// Button ReloadButton(BUTTON_RELOAD, aux2Pin, "reload");

#endif
