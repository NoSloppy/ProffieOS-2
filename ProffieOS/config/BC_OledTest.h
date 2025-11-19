// DualProp saber and blaster based on blade detect

#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 4
#define NUM_BUTTONS 1
#define VOLUME 1000
#define BOOT_VOLUME 200
const unsigned int maxLedsPerStrip = 144;
// #define EXTRA_COLOR_BUFFER_SPACE 30               // New define that can speed up processing a bit. Basically, it can calculate the colors for the next blade (or the next frame for the same blade) even though it's not done feeding out the data for the data in the color buffer yet.
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL // Bluetooth
#define SHARED_POWER_PINS
// #define SAVE_STATE
    // #define SAVE_VOLUME
    #define SAVE_PRESET
    #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING        // upload overwrites presets.ini/tmp unless this is defined
// #define DISABLE_COLOR_CHANGE
#define BLADE_DETECT_PIN aux2Pin
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
#define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> // This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors 
//                         Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value, so I would recommend using something like 200000 instead of NO_BLADE.
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                   // SPDIF out
// #define ENABLE_DEBUG
// #define NO_BATTERY_MONITOR
#define ENABLE_DEVELOPER_COMMANDS
//#define DISABLE_DIAGNOSTIC_COMMANDS
//#define IDLE_OFF_TIME 40000
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

// #define CONFIG_STARTUP_DELAY 15000              // BC now canon
// #define FEMALE_TALKIE_VOICE                       // BC now canon OS6
// #define DISABLE_TALKIE
// #define NO_REPEAT_RANDOM                          // BC now canon OS6

// ------- OLED stuff ----------

#define ENABLE_SSD1306                         // OLED display. also defines ENABLE_DISPLAY_CODE
// #define OLED_FLIP_180
// #define OLED_MIRRORED
// #define USE_AUREBESH_FONT
// #define OLED_SYNCED_EFFECTS
#define OLED_USE_BLASTER_IMAGES
#define PLI_OFF_TIME 60 * 5 * 1000// if inactive, if font_config.ProffieOSFontImageDuration == 0 then 3500, otherwise use font_config.ProffieOSFontImageDuration)

//    
//#define DISPLAY_POWER_PINS PowerPINS<bladePowerPin6> 

// ------- Gesture stuff -------

//#define BC_SWING_ON
// #define BC_STAB_ON
// #define BC_THRUST_ON
// #define BC_TWIST_ON
// #define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
// #define BC_ENABLE_AUTO_SWING_BLAST                  // BC Multiblast continues as long as swinging within 1 second. 
// #define ENABLE_SPINS
// #define ENABLE_AUTO_SPINS_BLAST                  // BC Same as auto-multi-blast but for spins. 1.5 second window
// #define GESTURE_AUTO_BATTLE_MODE
// #define BC_LOCKUP_DELAY 200
// #define BC_NO_BM                                 // bypass battle mode

// ------- Custom / Experimental stuff ---------

// #define NO_VOLUME_MENU                            // self evident
// #define NO_BLADE_NO_GEST_ONOFF                    // If using blade detect, No Blade = No Gesture ignitions or retractions
// #define AUTO_HUMSTART                             // 200ms delay from on.wav beginning all the time.             **Requires modified hybrid_font.h file.
// #define ENABLE_AUTO_SPINS_BLAST                   // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define LOW_BATT_ONCE                           //                                                             **Requires modified hybrid_font.h file.
// #define LOW_BATT_WARNINGS_TIERED                // meh...just annoying if not accurate..likely.                *Requires modified hybrid_font.h file.
// #define ENABLE_GESTURE_MENU                    // PSISTORM prop - cool stuff! the TrySound else beep void.
// #define KILL_OLD_PLAYERS                          // If requested EFFECT trigger exceed 7 wavplayers
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144__POV_data.h"

// ---------Edit Mode Stuff -------------

// #define ENABLE_ALL_EDIT_OPTIONS
    //#define DYNAMIC_BLADE_LENGTH
    //#define DYNAMIC_BLADE_DIMMING
    //#define DYNAMIC_CLASH_THRESHOLD
    //#define SAVE_VOLUME
    //#define SAVE_BLADE_DIMMING
    //#define SAVE_CLASH_THRESHOLD
    //#define SAVE_COLOR_CHANGE

// --------- blaster --------------

// #define ENABLE_BLASTER_AUTO
// #define BLASTER_SHOTS_UNTIL_EMPTY 5  // (whatever number, default is unlimited shots)
// #define BLASTER_JAM_PERCENTAGE 10     // if not defined, random.
// #define DEFAULT_BLASTER_MODE MODE_KILL
// #define PROP_HAS_BULLET_COUNT // enables drwing bullet counts overlay. CONFIG_BOTTOM needs Display COntroller.
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

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS

Preset saber [] = {

{ "testfont2b", "",
    StylePtr<Layers<Black,
TransitionEffectL<TrConcat<TrInstant,Rainbow,TrFade<2000>>,EFFECT_QUOTE>,
// // Volume Level - gradient Green -> Red
// TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,
// AlphaL<Gradient<Blue,Green>,
// SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>,
// Volume Level - stepped blue "stripes"
  TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,
AlphaL<Layers<
  AlphaL<Blue,LinearSectionF<Int<1638>,Int<3276>>>,
  AlphaL<SteelBlue,LinearSectionF<Int<4914>,Int<3276>>>,
  AlphaL<Blue,LinearSectionF<Int<8190>,Int<3276>>>,
  AlphaL<SteelBlue,LinearSectionF<Int<11466>,Int<3276>>>,
  AlphaL<Blue,LinearSectionF<Int<14742>,Int<3276>>>,
  AlphaL<SteelBlue,LinearSectionF<Int<18018>,Int<3276>>>,
  AlphaL<Blue,LinearSectionF<Int<21294>,Int<3276>>>,
  AlphaL<SteelBlue,LinearSectionF<Int<24570>,Int<3276>>>,
  AlphaL<Blue,LinearSectionF<Int<27846>,Int<3276>>>,
  AlphaL<SteelBlue,LinearSectionF<Int<31122>,Int<3276>>>>,
SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>,
// On-Demand Battery Level
  AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<   Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  StylePtr<Black>(),
  StylePtr<Black>(), 
  StylePtr<Black>(), 
"testfont2b"},


    { "Duke;common;commonBU", "", // 2nd blade on AUX test. No OLED Images for font, idle, preon, out, in, pstoff. On only??
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

  "duke"},

};  

Preset noblade [] = {



{ "testfont2b", "",
   StylePtr<Layers<Black,
TransitionEffectL<TrConcat<TrInstant,Rainbow,TrFade<2000>>,EFFECT_QUOTE>,
// Volume Level
  TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,
    AlphaL<Mix<LayerFunctions<
      LinearSectionF<Int<4914>,Int<3276>>,
      LinearSectionF<Int<11466>,Int<3276>>,
      LinearSectionF<Int<18018>,Int<3276>>,
      LinearSectionF<Int<24570>,Int<3276>>,
      LinearSectionF<Int<31122>,Int<3276>>>,Blue,SteelBlue>,
    SmoothStep<VolumeLevel,Int<-1>>>,
    // AlphaL<Gradient<Red,Green>,SmoothStep<VolumeLevel,Int<-1>>>, // Alternate color of basic Red to Green
    TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>,
// On-Demand Battery Level
  AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<   Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
  StylePtr<Black>(),
  StylePtr<Black>(), 
  StylePtr<Black>(), 
"testfont2b"},


    { "Duke;common;commonBU", "", // 2nd blade on AUX test. No Oled Images for font, idle, preon, pstoff, out, pstoff 
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

  ""},

};  


BladeConfig blades[] = {
    
    { 0,
  WS281XBladePtr<10, bladePin,  Color8::GRB, PowerPINS<bladePowerPin1> >(),
  WS281XBladePtr<10, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2> >(),
  WS281XBladePtr<10, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),
  WS281XBladePtr<10, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),
CONFIGARRAY(saber),
"00_OledTest_Save"}, 

    { NO_BLADE,
  WS281XBladePtr<10, bladePin,  Color8::GRB, PowerPINS<bladePowerPin1> >(),
  WS281XBladePtr<10, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2> >(),
  WS281XBladePtr<10, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),
  WS281XBladePtr<10, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),
CONFIGARRAY(noblade),
"00_OledTest_NB_Save"}, 

};
#endif

#ifdef CONFIG_BUTTONS
// For saber or dual_prop:
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");

// For blaster only:
//Button Clip(BUTTON_CLIP_DETECT, aux2Pin, "clip");
// Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
// Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");
//Button ReloadButton(BUTTON_RELOAD, 7, "reload");
#endif

/*


Displays:

When you go with a standard display setup, images which are 64 pixels wide won’t work.

See POD  page here: https://pod.hubbe.net/display/bullet-counts.html

You need a display controller now. At minimum, it should look like this (64x32 shown):

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




Also,
#define INCLUDE_SSD1306

Without it, the section at the bottom will throw errors.

Note that you should not have #define ENABLE_SSD1306 in your CONFIG_TOP section.
That will try to enable a 128x32 display, which will not work.*/
