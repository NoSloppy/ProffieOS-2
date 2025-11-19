// BC_Testbed_blaster.h

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
#define VOLUME 100
const unsigned int maxLedsPerStrip = 144; 
#define EXTRA_COLOR_BUFFER_SPACE 30               // New define that can speed up processing a bit. Basically, it can calculate the colors for the next blade (or the next frame for the same blade) even though it's not done feeding out the data for the data in the color buffer yet.
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL //Bluetooth or UART TTL
#define SHARED_POWER_PINS
#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    // #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING     // upload overwrites presets.ini/tmp unless this is defined
// #define DISABLE_COLOR_CHANGE
#define BLADE_DETECT_PIN blade3Pin
// #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> // This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors 
//                         Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value, so I would recommend using something like 200000 instead of NO_BLADE.
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #deefine ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                    // SPDIF out
#define ENABLE_DEVELOPER_COMMANDS
// #define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 1 * 1000
#define MOTION_TIMEOUT 60 * 1 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SDA_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE
// #define ORIENTATION_ROTATION 0,-20,0
//changes the angle required to register twists on curved hilts
//example is for assaj ventress curved hit install

 #define CONFIG_STARTUP_DELAY 3000              // BC now canon
// #define FEMALE_TALKIE_VOICE                       // BC now canon
// #define VOLUME_MENU_CYCLE                         // BC now canon - deprecated in BC prop. 
// #define NO_REPEAT_RANDOM                          // BC now canon - and defaulted on

// ------- OLED stuff ----------
#define ENABLE_SSD1306                            // OLED
//#define OLED_FLIP_180                             // BC now canon
//#define OLED_MIRRORED
// #define USE_AUREBESH_FONT                      // BC now canon
#define PLI_OFF_TIME 60 * 5 * 1000// if inactive, if font_config.ProffieOSFontImageDuration == 0 then 3500, otherwise use font_config.ProffieOSFontImageDuration)


// ------- Gesture stuff -------

// #define BC_SWING_ON
#define BC_STAB_ON
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
#define BC_FORCE_PUSH
#define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS 
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200

// ------- Custom / Experimental stuff ---------

#define DISABLE_BASIC_PARSER_STYLES               // Standard, Advanced, etc...
// #define NO_VOLUME_MENU                            // self evident
//#define NO_BLADE_NO_GEST_ONOFF                    // If using blade detect, No Blade = No Gesture ignitions or retractions
//#define AUTO_HUMSTART                             // 200ms delay from on.wav beginning all the time.             **Requires modified hybrid_font.h file.
#define ENABLE_AUTO_SPINS_BLAST                   // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define LOW_BATT_ONCE                           //                                                             **Requires modified hybrid_font.h file.
// #define LOW_BATT_WARNINGS_TIERED                // meh...just annoying if not accurate..likely.                                                            **Requires modified hybrid_font.h file.
// #define ENABLE_GESTURE_MENU                    // PSISTORM prop - cool stuff! the TrySound else beep void.

// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8


#define ENABLE_ALL_EDIT_OPTIONS
    // #define DYNAMIC_BLADE_LENGTH
    // #define DYNAMIC_BLADE_DIMMING
    // #define DYNAMIC_CLASH_THRESHOLD
    // #define SAVE_VOLUME
    // #define SAVE_BLADE_DIMMING
    // #define SAVE_CLASH_THRESHOLD
    // #define SAVE_COLOR_CHANGE

// --------- blaster --------------

#define ENABLE_BLASTER_AUTO
#define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
#define BLASTER_JAM_PERCENTAGE 10     // if not defined, random.
#define BLASTER_DEFAULT_MODE MODE_KILL
// #define PROP_HAS_BULLET_COUNT // enables drwing bullet counts overlay. CONFIG_BOTTOM needs Display Controller.
#define OLED_USE_BLASTER_IMAGES
#endif

#ifdef CONFIG_PROP // Change buttons to FIRE and MODE down in CONFIG_BUTTONS
// #include "../props/saber_BC_buttons_personal.h"
#include "../props/blaster_BC_buttons.h"
#endif

#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"     // For Red, Green, light Blue, ...light colored blades
#include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"
#include "aliases/TrueWhites/BC_effects_2.h"     // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"   // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_White.h" // For White blades


Preset blaster[] = {

// { "testblaster0;commonBlaster", "testblaster/tracks/track1.wav",
{ "testblaster0", "testblaster/tracks/track1.wav",
// Main BLade
  StylePtr<ColorSelect<BlasterModeF, TrInstant, Blue, Red, Green>>(),
// muzzle
  // StylePtr<Layers<
  //   Black,
  //   TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
  //   TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
  //   LockupTrL<Layers<
  //     TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
  //   TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,
  //   // TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  //   TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  // >>(),
// barrel
  // StylePtr<Layers<
  //   Black,
  //   TransitionEffectL<TrConcat<TrWipe<100>,White,TrWipe<100>,Red,TrWipe<200>>,EFFECT_FIRE>,
  //   TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
  //   LockupTrL<Layers<
  //     TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
  //     TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>,
  //     TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
  //   TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  // >>(),
  "0no boot or font images, only on.bmp. no durations set. should show both 3500"},
// result: 


// { "testblaster1;commonBlaster", "testblaster/tracks/track1.wav",
{ "testblaster1", "testblaster/tracks/track1.wav",
// Main BLade
  StylePtr<ColorSelect<BlasterModeF, TrInstant, Blue, Red, Green>>(),
  "1boot only, no durations. should show both 3500"},


// { "testblaster2;commonBlaster", "testblaster/tracks/track1.wav",
{ "testblaster2", "testblaster/tracks/track1.wav",
// Main BLade
  StylePtr<ColorSelect<BlasterModeF, TrInstant, Blue, Red, Green>>(),
  "2Boot BMP (destruct) and font img. bootDur 5000 no fontDur (should show 3500)"},


// { "testblaster3;commonBlaster", "testblaster/tracks/track1.wav",
{ "testblaster3", "testblaster/tracks/track1.wav",
// Main BLade
  StylePtr<ColorSelect<BlasterModeF, TrInstant, Blue, Red, Green>>(),
  "3no boot, yes font img, boot dur 5000, font 7000. should show 5000 and 7000"},


// { "testblaster4;commonBlaster", "testblaster/tracks/track1.wav",
{ "testblaster4", "testblaster/tracks/track1.wav",
// Main BLade
  StylePtr<ColorSelect<BlasterModeF, TrInstant, Blue, Red, Green>>(),
  "4no boot or font images. Only text dur 5000 should show 5000 both"},


// { "testblaster5;commonBlaster", "testblaster/tracks/track1.wav",
{ "testblaster5", "testblaster/tracks/track1.wav",
// Main BLade
  StylePtr<ColorSelect<BlasterModeF, TrInstant, Blue, Red, Green>>(),
  "5no img. text dur set to 0. "},


// { "testblaster6;commonBlaster", "testblaster/tracks/track1.wav",
{ "testblaster6", "testblaster/tracks/track1.wav",
// Main BLade
  StylePtr<ColorSelect<BlasterModeF, TrInstant, Blue, Red, Green>>(),
  "6both boot and font img. all dur set to 0"},



{ "blaster1;commonBlaster", "blaster1/tracks/ImperialMarchROTJ3_long.wav",
// Main BLade
  // StylePtr<Black>(),
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,
    // TransitionEffectL<TrConcat<TrInstant,Mix<Sin<Int<12>>,Pulsing<Red,Black,800>,Pulsing<Red,Black,100>>,TrDelayX<Int<10000>>>,EFFECT_DESTRUCT>
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  >>(),
// // barrel
//   StylePtr<Layers<
//     Black,
//     TransitionEffectL<TrConcat<TrWipe<100>,White,TrWipe<100>,Red,TrWipe<200>>,EFFECT_FIRE>,
//     TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
//     LockupTrL<Layers<
//       TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
//       TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>,
//       TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
//     TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
//   >>(),
  "blaster1\nbladeout"},

// { "F11-D;blaster1;commonBlaster", "blaster1/tracks/ImperialMarchROTJ3_long.wav",
{ "F11-D;commonBlaster", "blaster1/tracks/ImperialMarchROTJ3_long.wav",

// Main BLade
  // StylePtr<Black>(),
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  >>(),
// barrel
  // StylePtr<Layers<
  //   Black,
  //   TransitionEffectL<TrConcat<TrWipe<100>,White,TrWipe<100>,Red,TrWipe<200>>,EFFECT_FIRE>,
  //   TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
  //   LockupTrL<Layers<
  //     TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
  //     TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>,
  //     TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
  //   TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  // >>(),
  "f11-d\nbladeout"}

};

BladeConfig blades[] = {

// proffieholder tester
// { 0, 
//   WS281XBladePtr<144, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2,bladePowerPin3> >(),  // D2 Test leads
//   SubBlade (3, 3, WS281XBladePtr<4, blade5Pin, Color8::GRB, PowerPINS<bladePowerPin4> >() ), // Onboard 4 LEDs (last one it muzzle)
//   SubBlade (0, 2, NULL),                                                                      // barrel
// CONFIGARRAY(blaster),
// "01_blasterSave"}

// 3d printed testbed
      { 0,
  WS281XBladePtr<13, bladePin,  Color8::GRB, PowerPINS<bladePowerPin1> >(),
  // WS281XBladePtr<10, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2> >(),
  // WS281XBladePtr<10, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),
  // WS281XBladePtr<10, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),
CONFIGARRAY(blaster),
"00_OledTest_Save"},

};
#endif

#ifdef CONFIG_BUTTONS

// // For blaster only:
Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");
//Button ReloadButton(BUTTON_RELOAD, 24, "reload");
// Button Clip(BUTTON_CLIP_DETECT, aux2Pin, "clip");

#endif

/*
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
  WriteBulletCountOp<10, 20, 3> // <x?, y?, #of digits>
> display_controller;
SSD1306Template<64, uint32_t> display(&display_controller);
#endif


- what's the diff between that and then this?:

Support for 128x64 OLED
#ifdef CONFIG_BOTTOM
SSD1306Template<128, uint64_t> display(0x3C);
#endif
*/

