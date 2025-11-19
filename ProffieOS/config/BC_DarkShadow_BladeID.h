//BC_DarkShadow_BladeID.h

#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 1
#define VOLUME 1500
const unsigned int maxLedsPerStrip = 144;
#define EXTRA_COLOR_BUFFER_SPACE 30               // New define that can speed up processing a bit. Basically, it can calculate the colors for the next blade (or the next frame for the same blade) even though it's not done feeding out the data for the data in the color buffer yet.
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL //Bluetooth
#define BLE_PASSWORD "000000"
//#define ENABLE_SSD1306 //OLED
#define SHARED_POWER_PINS
#define SAVE_STATE
    //#define SAVE_VOLUME
    //#define SAVE_PRESET
    //#define SAVE_COLOR_CHANGE
    //#define SAVE_BLADE_DIMMING
//#define KEEP_SAVEFILES_WHEN_PROGRAMMING           // upload overwrites presets.ini/tmp unless this is defined
// #define BLADE_DETECT_PIN blade4Pin
 #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
/*  This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value,
    so I would recommend using something like 200000 instead of NO_BLADE. */
#define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin>

/*  Millis is Blade ID scan interval. If the blade ID comes out the same as before, it will do nothing.
    If it comes out different, it will do FindBladeAgain(), which will basically initialize the saber from 
    scratch and load the right settings for the new id().
    It will only work with neopixel blades, and requires SHARED_POWER_PINS to work. */
#define BLADE_ID_SCAN_MILLIS 1000
//    How many Blade ID scans to average
#define BLADE_ID_TIMES 10
//#define SPEAK_BLADE_ID
//#define ENABLE_I2S_OUT
//#define ENABLE_SPDIF_OUT
//#define LINE_OUT_VOLUME 2000                    // SPDIF out
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
#define KILL_OLD_PLAYERS

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

// #define NO_BLADE_NO_GEST_ONOFF                    // If using blade detect, No Blade = No Gesture ignitions or retractions
//#define ANGLE_PREON                               // Preon that only works if the blade is angled down           **Required modified prop_base.h
// #define AUTO_HUMSTART          DEAD                   // 200ms delay from on.wav beginning all the time.             **Requires modified hybrid_font.h file.
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
0. DarkV3
1. Blue
2. Green -  Used style 0 with variation 21844 in presets.ini on blue so I could fit Protoblade ;)
3. Orange
4. Purple
5. Yellow
6. Cyan
7. Magenta
8. Indigo
9. Second Sister Red
10. Inquisitorious   Blueforce Legion
11. Crispity _Greyscale Cyan +Purple
12. Protoblade      blueforce BC custom

COLORS USED. Base, Force, Swing repectively
// Jedi base Blue
  StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,
  TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
  AlphaL<RotateColorsX<Variation,Rgb<70,70,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// Jedi base Green
  StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Green>,Pulsing<RotateColorsX<Variation,Rgb<0,90,0>>,RotateColorsX<Variation,Green>,800>,RotateColorsX<Variation,Green>>,
  TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<3000>,RotateColorsX<Variation,Green>,TrFade<800>>,EFFECT_FORCE>,
  AlphaL<RotateColorsX<Variation,Rgb<100,255,100>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// Jedi base Purple
  StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<95,0,225>>,Pulsing<RotateColorsX<Variation,Rgb<39,5,71>>,RotateColorsX<Variation,Rgb<95,0,225>>,800>,RotateColorsX<Variation,Rgb<95,0,225>>>,
  TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<95,0,225>>,TrFade<800>>,EFFECT_FORCE>,
  AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// Jedi base Orange
  StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,DarkOrange>,Pulsing<RotateColorsX<Variation,Rgb<90,24,0>>,RotateColorsX<Variation,DarkOrange>,800>,RotateColorsX<Variation,DarkOrange>>,
  TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<160,43,0>>>,TrDelay<3000>,RotateColorsX<Variation,DarkOrange>,TrFade<800>>,EFFECT_FORCE>,
  AlphaL<RotateColorsX<Variation,Rgb<255,178,110>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// Jedi base Yellow
  StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<180,180,0>>,Pulsing<RotateColorsX<Variation,Rgb<64,64,0>>,RotateColorsX<Variation,Rgb<180,180,0>>,800>,RotateColorsX<Variation,Rgb<180,180,0>>>,
  TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<113,113,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<180,180,0>>,TrFade<800>>,EFFECT_FORCE>,
  AlphaL<RotateColorsX<Variation,Rgb<230,180,80>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// Jedi base Cyan
  StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<30,120,150>>,Pulsing<RotateColorsX<Variation,Rgb<11,42,53>>,RotateColorsX<Variation,Rgb<30,120,150>>,800>,RotateColorsX<Variation,Rgb<30,120,150>>>,
  TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<30,120,150>>,RotateColorsX<Variation,Rgb<19,75,94>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<30,120,150>>,TrFade<800>>,EFFECT_FORCE>,
  AlphaL<RotateColorsX<Variation,Rgb<90,180,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// Jedi base Magenta
  StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<180,30,140>>,Pulsing<RotateColorsX<Variation,Rgb<64,11,49>>,RotateColorsX<Variation,Rgb<180,30,140>>,800>,RotateColorsX<Variation,Rgb<180,30,140>>>,
  TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,30,140>>,RotateColorsX<Variation,Rgb<113,19,88>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<180,30,140>>,TrFade<800>>,EFFECT_FORCE>,
  AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// Jedi base Indigo
  StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<80,50,200>>,Pulsing<RotateColorsX<Variation,Rgb<28,18,71>>,RotateColorsX<Variation,Rgb<80,50,200>>,800>,RotateColorsX<Variation,Rgb<80,50,200>>>,
  TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<80,50,200>>,RotateColorsX<Variation,Rgb<50,31,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<80,50,200>>,TrFade<800>>,EFFECT_FORCE>,
  AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// Sith base Red
  StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Red>,Pulsing<RotateColorsX<Variation,Rgb<90,0,0>>,RotateColorsX<Variation,Red>,800>,RotateColorsX<Variation,Red>>,
  TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
  AlphaL<RotateColorsX<Variation,Rgb<255,100,100>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,

// Second Sister base
  StripesX<Int<10000>,Int<-1700>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<50,0,0>>,RotateColorsX<Variation,Red>>,
// Second Sister Swing color
  AlphaL<RotateColorsX<Variation,Rgb<255,75,75>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
*/

Preset blade1 [] = {


// preset 0
 { "aa_NoSloppy/Cantina;common",  "",
  StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),

// HiltPCB
  StylePtr<Black>(),
// Switches
  StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),

// Pommel
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
//Bluetooth
  StylePtr<Blue>(),
"  blade1test"}



};


Preset bladein [] = {


// preset 0
{ "a_DARKSABER/DarkV2;common", "",
  StylePtr<Layers<
    Mix<SwingSpeed<400>,RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<150,150,225>>>,
    BrownNoiseFlickerL<Stripes<5000,-300,RotateColorsX<Variation,Rgb<25,25,55>>,RotateColorsX<Variation,Rgb<75,75,120>>,RotateColorsX<Variation,Rgb<10,10,20>>,RotateColorsX<Variation,Rgb<50,50,75>>>,Int<38400>>,
    AudioFlickerL<RotateColorsX<Variation,Rgb<35,35,75>>>,
    AlphaL<RotateColorsX<Variation,Rgb<175,175,225>>,SwingSpeed<600>>,
    BC_effects_1,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
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
//Bluetooth
  StylePtr<Blue>(),
"   dark\n    v2"}


};

//----------------------------------------------------------------------------------------------------------------------------------------
Preset no_blade[] = {

// preset 0
{ "a_DARKSABER/DarkV3;common", "",
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
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Switches
  StylePtr<Layers<
    Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<RotateColorsX<Variation,Rgb<100,100,150>>,Black,2500>>>>(),
// Pommel
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
//Bluetooth
  StylePtr<Blue>(),
"   dark\n    v3"},

// preset 1
{ "testfont2", "testfont2/tracks/track1.wav",
// Main Blade
  StylePtr<Black>(),
// Hilt PCB
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
// Switches
  StylePtr<LengthFinder<>>(),
// Pommel
  StylePtr<Layers<
    Pulsing<Blue,Black,200>,
    InOutTrL<TrInstant,TrInstant,Pulsing<Blue,Black,2500>>>>(),
//Bluetooth
  StylePtr<Blue>(),
"testfont2"},

//  { "Calibr8;common", "tracks/TalesOfAJediKnight.wav", 

//  { "RootCore;common", "RootCore/tracks/root.wav", 

 // { "testfont2", "tracks/track2.wav",
 //    StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
 //    StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
 //    StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
 // "testfont2"},


// { "BattLevl;common", "tracks/theforce1.wav",
//     StylePtr<Layers<Black,AlphaL<PulsingX<Mix<BatteryLevel,Red,Green>,Black,Scale<BatteryLevel,Int<500>,Int<4000>>>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>>>(),
//     StylePtr<Layers<Black,AlphaL<PulsingX<Mix<BatteryLevel,Red,Green>,Black,Scale<BatteryLevel,Int<500>,Int<4000>>>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>>>(),
//     StylePtr<Layers<Black,AlphaL<PulsingX<Mix<BatteryLevel,Red,Green>,Black,Scale<BatteryLevel,Int<500>,Int<4000>>>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>>>(),

// "battery\nlevel"}

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
{ 735,    //  1" BC_A_123           D1_data_line = proffie_D1---> HiltPCB ctrpin---> bladePCB 330ohm??--->Main blade strips
  WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(blade1), 
"01_blade1_save"}, 


{ 124,    //  1" Ciel_Tan_A 132           D1_data_line = proffie_D1---> HiltPCB ctrpin---> bladePCB 330ohm??--->Main blade strips
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(bladein), 
"01_bladein_save"}, 

{ 200000, // NEED VALUE  1" Ciel_Tan_A 132           D1_data_line = proffie_D1---> HiltPCB ctrpin
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches 
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(no_blade),
"00_NO_BLADE_save"}, 


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
