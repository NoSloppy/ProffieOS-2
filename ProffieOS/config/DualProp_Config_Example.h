// DualProp saber and blaster based on blade detect

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 1

// ------ Audio Stuff --------

#define VOLUME 1500
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

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
// New define that can speed up processing a bit. Basically, it can calculate the colors for the next
// blade (or the next frame for the same blade) even though it's not done feeding out the data for the
// data in the color buffer yet. Equivalent to just increasing maxLedsPerStrip.
// #define EXTRA_COLOR_BUFFER_SPACE 30
#define SHARED_POWER_PINS
#define BLADE_DETECT_PIN blade4Pin
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

#define ENABLE_SD
 #define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    // #define SAVE_COLOR_CHANGE
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
//    Turns power to the OLED display off once SCREEN_OFF state. (Either IDLE_OFF_TIME or PLI_OFF_TIME)
// #define DISPLAY_POWER_PINS PowerPINS<bladePowerPin6> 

// ------ System Stuff --------

// #define ENABLE_DEBUG
// #define NO_BATTERY_MONITOR
#define ENABLE_SERIAL // Bluetooth
// #define DISABLE_COLOR_CHANGE
#define ENABLE_DEVELOPER_COMMANDS
//#define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 1 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SDA_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE
// The following changes the angle required to register twists on curved hilts.
// Example is for assaj ventress curved hit install
// #define ORIENTATION_ROTATION 0,-20,0
// #define CONFIG_STARTUP_DELAY 15000                 // BC now canon
#define DISABLE_BASIC_PARSER_STYLES               // Standard, Advanced, etc...

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

// -------- BC Prop Other Stuff --------

// #define NO_VOLUME_MENU                           // self evident. But why?

// -------- Blaster Stuff ----------

#define ENABLE_BLASTER_AUTO
#define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
#define BLASTER_JAM_PERCENTAGE 10     // if not defined, random.

#endif


#ifdef CONFIG_PROP // Leave buttons as POW and AUX down in CONFIG_BUTTONS
#include "../props/dual_prop.h"
#include "../props/saber_BC_buttons.h"
#undef PROP_TYPE
#include "../props/blaster_BC_buttons.h"
#undef PROP_TYPE
#define PROP_TYPE SaberBlasterProp<SaberBCButtons, BlasterBC>
#endif

#ifdef CONFIG_PRESETS

// Blade in
Preset saber [] = {

{ "testfont2b;common", "tracks/track1.wav",
// Main Blade
  StylePtr<Layers<
    Red,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),
// Blaster style
  StylePtr<Black>(),
"blade_in_style"};

};  

//-----------------------------------------------------------------------------------------------------------------------

// Blade out
Preset blaster[] = {
{ "testblaster;common", "testblaster/tracks/track1.wav",
// Main Blade
  StylePtr<Black>(),
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
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipe<100>,White,TrWipe<100>,Red,TrWipe<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>
  >>(),
"blade_out_style"},

};

BladeConfig blades[] = {

{ 0,
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // Blaster LED
  CONFIGARRAY(saber),
"00_SaberSave"}, 

{ NO_BLADE,                                      // D1_data_line = proffie_D1---> NPXL ctrpin---> bladePCB 330ohm--->Main blade strips
  WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // Blaster LED
  CONFIGARRAY(blaster),
"01_BlasterSave"}

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");

#endif
