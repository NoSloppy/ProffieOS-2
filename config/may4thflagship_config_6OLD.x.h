// may4thflagship_config_6.x// ProffieOS version 6.xPA - Native WavLen!

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 1
#define VOLUME 1800
const unsigned int maxLedsPerStrip = 144;
#define EXTRA_COLOR_BUFFER_SPACE 30               // New define that can speed up processing a bit. Basically, it can calculate the colors for the next blade (or the next frame for the same blade) even though it's not done feeding out the data for the data in the color buffer yet.
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
//#define ENABLE_SERIAL //Bluetooth
//#define ENABLE_SSD1306 //OLED
#define SHARED_POWER_PINS
#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    // #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//#define KEEP_SAVEFILES_WHEN_PROGRAMMING           // upload overwrites presets.ini/tmp unless this is defined
#define BLADE_DETECT_PIN blade4Pin
//#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
//#define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
//#define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #deefine ENABLE_SPDIF_OUT
//#define ENABLE_DEVELOPER_COMMANDS
//#define DISABLE_DIAGNOSTIC_COMMANDS
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
//#define CONFIG_STARTUP_DELAY 15000              // BC now canon
//#define OLED_FLIP_180                           // BC now canon
//#define USE_AUREBESH_FONT
#define FEMALE_TALKIE_VOICE                       // BC now canon
#define VOLUME_MENU_CYCLE                         // BC now canon
#define NO_REPEAT_RANDOM                          // BC now canon


// ------- Gesture stuff -------

//#define BC_SWING_ON                             // Motion time out causing false ignitions on preset switch. this is annoying but possibly resolved with I2C updates.
//#define BC_STAB_ON
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
#define BC_FORCE_PUSH
#define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200

// ------- Custom / Experimental / Alpha-Beta stuff ---------
#define PREONS_MATCH_OUTS
#define PSTOFFS_MATCH_INS
//#define NO_BLADE_NO_GEST_ONOFF                    // BC test this. If using blade detect, No Blade = No Gesture ignitions or retractions
//#define ANGLE_PREON                               // Preon that only works if the blade is angled down
#define AUTO_HUMSTART                              // 200ms delay from on.wav beginning all the time.
#define ENABLE_AUTO_SPINS_BLAST                   // BC Same as auto-multi-blast but for spins. 2 second window.
//#define LOW_BATT_ONCE
//#define ENABLE_GESTURE_MENU                      // PSISTORM prop - cool stuff! the TrySound else beep void.
//#define LINE_OUT_VOLUME 2000                    // SPDIF out
//#define OPTIMIZE_TRCONCAT                       // this TRCONCAT can save some RAM, but it's not compatible with IntArg/RgbArg
//#define FILTER_CUTOFF_FREQUENCY 100
//#define FILTER_ORDER 8

#define ENABLE_ALL_MENU_OPTIONS                    // OS 6
    // #define DYNAMIC_BLADE_LENGTH
    // #define DYNAMIC_BLADE_DIMMING
    // #define DYNAMIC_CLASH_THRESHOLD
    // #define SAVE_VOLUME
    // #define SAVE_BLADE_DIMMING
    // #define SAVE_CLASH_THRESHOLD
    // #define SAVE_COLOR_CHANGE


#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif



#ifdef CONFIG_PRESETS

#include "aliases/TrueWhites/BC_effects_1.h"
#include "aliases/TrueWhites/BC_effects_Red.h"

Preset presets [] = {

   { "TheLight", "",
StylePtr<Yellow>(),

StylePtr<Layers<RotateColorsX<Variation,Red>,InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Red>,3000>>>>()},



};




//----------------------------------------------------------------------------------------------------------------------------------------
Preset noblade[] = {
   { "Proto", "",
StylePtr<Layers<
  Black,
      TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<1000>>,EFFECT_LOCKUP_END>,

  LockupTrL<Layers<
    AlphaL<AudioFlickerL<Rgb<255,240,80>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<LemonChiffon,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<10000>>>>,
      TrConcat<TrInstant,AlphaL<TransitionEffect<Rgb<255,180,50>,LemonChiffon,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<20000>>>,TrFade<400>>,
      TrConcat<TrInstant,AlphaL<Mix<SmoothStep<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<1000>>,Stripes<1500,2000,White,Blue>,Stripes<1500,-2500,White,Blue>>,Int<18000>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  AlphaL<White,Bump<Int<0>,Int<6000>>>,
  InOutTrL<TrJoin<TrWipeX<Int<600>>,TrWaveX<White,Int<800>,Int<400>,Int<600>,Int<0>>>,TrJoin<TrWipeInX<Int<600>>,TrWaveX<White,Int<800>,Int<400>,Int<600>,Int<32768>>>>>>(),

StylePtr<Layers<RotateColorsX<Variation,Red>,InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Red>,3000>>>>()},

   { "Ascension", "",
StylePtr<Layers<
  Black,
  TransitionEffectL<TrConcat<TrInstant,Rgb<0,0,150>,TrDelay<1000>>,EFFECT_LOCKUP_END>,
  LockupTrL<AlphaL<White,Bump<Int<16384>>>,TrInstant,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
  AlphaL<Red,Bump<Int<0>,Int<6000>>>,
  InOutTrL<TrJoin<TrWipeX<Int<600>>,TrWaveX<White,Int<800>,Int<400>,Int<600>,Int<0>>>,TrJoin<TrWipeInX<Int<600>>,TrWaveX<White,Int<800>,Int<400>,Int<600>,Int<32768>>>>>>(),
  
StylePtr<Layers<RotateColorsX<Variation,Red>,InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Red>,3000>>>>()},


   { "Dangerous", "",
StylePtr<Layers<
  Black,
  BC_effects_1,
  AlphaL<Blue,Bump<Int<0>,Int<6000>>>,
  InOutTrL<TrJoin<TrWipeX<Int<600>>,TrWaveX<White,Int<800>,Int<400>,Int<600>,Int<0>>>,TrJoin<TrWipeInX<Int<600>>,TrWaveX<White,Int<800>,Int<400>,Int<600>,Int<32768>>>>>>(),

StylePtr<Layers<RotateColorsX<Variation,Red>,InOutTrL<TrInstant,TrInstant,Pulsing<Black,RotateColorsX<Variation,Red>,3000>>>>()}



};



BladeConfig blades[] = {
{ 0,
  WS281XBladePtr<131, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
  CONFIGARRAY(presets), 
"01_may4thflagship"}, 

{ NO_BLADE, 
  WS281XBladePtr<131, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
  CONFIGARRAY(noblade),
"00_NO_BLADEsave"}, 


};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

// // Button connect to 3.3v instead of GND
// PullDownButton PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 

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
