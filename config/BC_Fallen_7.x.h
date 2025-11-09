//BC_Fallen_7.x// ProffieOS version 6.x - BC manual update - Native WavLen!
//Last upload : 8-17-23
// Uses 1 button config, because no space! @nd option is kill another preset, presets.ini it instead, and renumber ALL THE dam presets.ini.
// repeats fonts because no space.
// That's ridiculous.
// Use "party mode" fett263 , alt-sounds etc...?  blech
#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 1
#define VOLUME 2000
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
    //#define SAVE_VOLUME
    //#define SAVE_PRESET
    //#define SAVE_COLOR_CHANGE
    //#define SAVE_BLADE_DIMMING
#define KEEP_SAVEFILES_WHEN_PROGRAMMING           // upload overwrites presets.ini/tmp unless this is defined
#define BLADE_DETECT_PIN blade4Pin
//#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
//#define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
//#define SPEAK_BLADE_ID
//#define ENABLE_I2S_OUT
//#define ENABLE_SPDIF_OUT
//#define LINE_OUT_VOLUME 2000                    // SPDIF out
//#define ENABLE_DEVELOPER_COMMANDS
#define DISABLE_DIAGNOSTIC_COMMANDS
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

//#define BC_SWING_ON                             // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
//#define BC_STAB_ON
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
#define BC_FORCE_PUSH
#define BC_FORCE_PUSH_LENGTH 4
#define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS
//#define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200

// ------- Custom / Experimental / Alpha-Beta stuff ---------

#define NO_BLADE_NO_GEST_ONOFF                    // If using blade detect, No Blade = No Gesture ignitions or retractions
#define ANGLE_PREON                               // Bypass preon if pointing up.                                **Required modified prop_base.h
#define AUTO_HUMSTART                             // 200ms delay from on.wav beginning all the time.             **Requires modified hybrid_font.h file.
#define ENABLE_AUTO_SPINS_BLAST                   // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
//#define LOW_BATT_ONCE                           //                                                             **Requires modified hybrid_font.h file.
//#define ENABLE_GESTURE_MENU                      // PSISTORM prop - cool stuff! the TrySound else beep void.

//#define OPTIMIZE_TRCONCAT                       // this TRCONCAT can save some RAM, but it's not compatible with IntArg/RgbArg
//#define FILTER_CUTOFF_FREQUENCY 100
//#define FILTER_ORDER 8

#define ENABLE_ALL_EDIT_OPTIONS                    // OS 6
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
This File uses the following from prests.ini
*needed to eek out 160 bytes more, so Mass Storage turned off (just for Upload, will neeed to reupload with less config content to access SD card THANKS ROBERT SOTOMAYOR!!! Grrr.)
* also set all Cal's colors to blue in here to make compile fit. Again, driven by presets.ini instead
0. Blue
1. Green -  Used style 0 with variation 21844 in presets.ini on blue so I could fit Protoblade ;)
2. Orange
3. Purple
4. Yellow
5. Cyan
6. Magenta
7. Indigo
8. Second Sister Red
Agression           Uses 7
AscensionSS_BC      Uses 8
Desolation          Uses 4
InquisitoriousRED   Uses 8
9. Inquisitorious   Blueforce Legion
ProtoBC             Uses 2
PsyBorg             Uses 0 w/ variation 21844
RA_Greyscale        Uses 4
RuinerSM            Uses 3
SonOfDarkness       Uses 8
2ndSistr            Uses 8
9thSistr            Uses 8
CybrAssn            Uses 0 w/ variation 21844
Vengence            Uses 6
Legion              Uses 9
JFOScrapper         Uses 0
10. Crispity _Greyscale Cyan +Purple
Assassin_Greyscale  Uses 0 w/ variation 21844
Volatile_Greyscale  Uses 3
Exaulted_Greyscale  Uses 5
Grey_Greyscale      Uses 2 but custom pale GreenBleu 10918
Seethe_Greyscale    Uses 9
Menace              Uses 8
11. Protoblade      blueforce BC custom

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




/* this is some crazy changes-on-force-effect thing from SHane Overton.

StylePtr<Layers<
  AudioFlicker<ColorSelect<IncrementModuloF<EffectPulseF<EFFECT_FORCE>,Int<32000>>,TrInstant,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<8000>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Blue>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,Pulsing<RgbArg<BASE_COLOR_ARG,Blue>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,1400>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<10000>,Int<5000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2000>,Int<-3000>>,RgbArg<ALT_COLOR_ARG,Cyan>,Mix<Int<12000>,Black,RgbArg<ALT_COLOR_ARG,Cyan>>,Pulsing<RgbArg<ALT_COLOR_ARG,Cyan>,Mix<Int<8000>,Black,RgbArg<ALT_COLOR_ARG,Cyan>>,1400>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<4000>,Int<1800>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2800>,Int<-4000>>,Mix<Int<16000>,Black,RgbArg<ALT_COLOR2_ARG,Green>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,RgbArg<ALT_COLOR2_ARG,Green>>,Mix<Int<8000>,Black,RgbArg<ALT_COLOR2_ARG,Green>>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<9000>,Int<4000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2400>,Int<-3000>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Mix<Int<15000>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>>,Pulsing<RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Mix<Int<10000>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>>,600>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<9000>,Int<4000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2000>,Int<-3000>>,Magenta,Mix<Int<12000>,Black,Magenta>,Pulsing<Magenta,Mix<Int<8000>,Black,Magenta>,800>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<4000>,Int<1800>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2800>,Int<-4000>>,Mix<Int<16000>,Black,DarkOrange>,Mix<Sin<Int<20>,Int<20000>,Int<32768>>,Black,DarkOrange>,Mix<Int<10000>,Black,DarkOrange>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Sin<Int<20>,Int<10000>,Int<7000>>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2300>,Int<-4000>>,Rgb<115,15,240>,Mix<Int<12000>,Black,Rgb<115,15,240>>,Pulsing<Rgb<115,15,240>,Mix<Int<20000>,Black,Rgb<115,15,240>>,2000>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<4000>,Int<1800>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-3000>,Int<-4500>>,Mix<Int<16000>,Black,Rgb<100,100,150>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,Rgb<100,100,150>>,Mix<Int<8000>,Black,Rgb<100,100,150>>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<3600>,Int<1600>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2700>,Int<-4100>>,Mix<Int<16000>,Black,Rgb<180,130,0>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,Rgb<180,130,0>>,Mix<Int<8000>,Black,Rgb<180,130,0>>>>,Mix<Int<16384>,ColorSelect<IncrementModuloF<EffectPulseF<EFFECT_FORCE>,Int<32000>>,TrInstant,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<8000>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Blue>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,Pulsing<RgbArg<BASE_COLOR_ARG,Blue>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Blue>>,1400>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<10000>,Int<5000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2000>,Int<-3000>>,RgbArg<ALT_COLOR_ARG,Cyan>,Mix<Int<12000>,Black,RgbArg<ALT_COLOR_ARG,Cyan>>,Pulsing<RgbArg<ALT_COLOR_ARG,Cyan>,Mix<Int<8000>,Black,RgbArg<ALT_COLOR_ARG,Cyan>>,1400>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<4000>,Int<1800>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2800>,Int<-4000>>,Mix<Int<16000>,Black,RgbArg<ALT_COLOR2_ARG,Green>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,RgbArg<ALT_COLOR2_ARG,Green>>,Mix<Int<8000>,Black,RgbArg<ALT_COLOR2_ARG,Green>>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<9000>,Int<4000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2400>,Int<-3000>>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Mix<Int<15000>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>>,Pulsing<RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Mix<Int<10000>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>>,600>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<9000>,Int<4000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2000>,Int<-3000>>,Magenta,Mix<Int<12000>,Black,Magenta>,Pulsing<Magenta,Mix<Int<8000>,Black,Magenta>,800>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<4000>,Int<1800>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2800>,Int<-4000>>,Mix<Int<16000>,Black,DarkOrange>,Mix<Sin<Int<20>,Int<20000>,Int<32768>>,Black,DarkOrange>,Mix<Int<10000>,Black,DarkOrange>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Sin<Int<20>,Int<10000>,Int<7000>>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2300>,Int<-4000>>,Rgb<115,15,240>,Mix<Int<12000>,Black,Rgb<115,15,240>>,Pulsing<Rgb<115,15,240>,Mix<Int<20000>,Black,Rgb<115,15,240>>,2000>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<4000>,Int<1800>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-3000>,Int<-4500>>,Mix<Int<16000>,Black,Rgb<100,100,150>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,Rgb<100,100,150>>,Mix<Int<8000>,Black,Rgb<100,100,150>>>,StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<3600>,Int<1600>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2700>,Int<-4100>>,Mix<Int<16000>,Black,Rgb<180,130,0>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,Rgb<180,130,0>>,Mix<Int<8000>,Black,Rgb<180,130,0>>>>,Black>>,
  TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<9>>,Int<-1>>,EFFECT_USER1>,
  TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<-1>>,Int<9>>,Int<-1>>,EFFECT_USER2>,
  TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<8>>>,Int<9>>,Int<-1>>,EFFECT_USER3>,
  TransitionPulseL<TrSelect<IncrementModuloF<EffectPulseF<EFFECT_USER4>,Int<2>>,TrInstant,TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<8>>>,Int<9>>>>,ThresholdPulseF<SwingSpeed<320>,Int<31000>>>,
  TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>>,EFFECT_USER4>,
  TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,White>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
  LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,White>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,White>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,White>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,White>,Int<16000>>,30>,TrSmoothFade<600>>>,
  LockupTrL<AlphaL<Stripes<2000,4000,RgbArg<DRAG_COLOR_ARG,White>,Mix<Sin<Int<50>>,Black,RgbArg<DRAG_COLOR_ARG,White>>,Mix<Int<4096>,Black,RgbArg<DRAG_COLOR_ARG,White>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<Stripes<2000,3000,RgbArg<DRAG_COLOR_ARG,White>,Mix<Sin<Int<30>>,Black,RgbArg<DRAG_COLOR_ARG,White>>,Mix<Int<8192>,Black,RgbArg<DRAG_COLOR_ARG,White>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,DarkOrange>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<300>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrConcat<TrJoin<TrDelayX<Mult<IgnitionTime<>,Int<16384>>>,TrWipeX<Mult<IgnitionTime<>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<IGNITION_COLOR_ARG,White>>,TrWipeX<Mult<IgnitionTime<>,Int<16384>>>>,TrConcat<TrJoin<TrDelayX<Mult<RetractionTime<>,Int<16384>>>,TrWipeInX<Mult<RetractionTime<>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<RETRACTION_COLOR_ARG,White>>,TrWipeInX<Mult<RetractionTime<>,Int<16384>>>>>
  >>()
"*/



Preset Cal_Kestis [] = {

/* copyright Fett263 JediSurvivor (Primary Blade) OS7 Style
https://fett263library.com/early-access/#JediSurvivor
OS7.8 v1.015
Single Style
Base Style: Cal Kestis Survivor Blue

Base Color: Kyber Select - BaseColorArg - AltColorArg - AltColor2Arg - AltColor3Arg - Rgb<255,0,255> - Rgb<255,68,0> - Rgb<115,15,240> - Rgb<100,100,150> - Rgb<180,130,0> (0)
Kyber Select Interactive Control: While Blade is On, use selected Special Ability to change color (Phase). Requires Alt Font.

NOTE:This style includes Control Layer. Only one Control Layer should be used per preset.

*This style REQUIRES Alt Fonts alt000/ to alt008/ to be set up. Uses altchng.wav on change.
See https://pod.hubbe.net/sound/alt_sounds.html for more information.
--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Special Ability 1: Next Phase
Special Ability 2: Previous Phase
Special Ability 3: Select Random Phase
Special Ability 4: Toggle Swing Change (Random / Party Mode) Uses tr.wav #0 on toggle

*/
StylePtr<Layers<
  StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<8000>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2600>,Int<-3600>>,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Blue>,RgbArg<ALT_COLOR_ARG,Cyan>,RgbArg<ALT_COLOR2_ARG,Green>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Magenta,DarkOrange,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>,Mix<Int<12000>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Blue>,RgbArg<ALT_COLOR_ARG,Cyan>,RgbArg<ALT_COLOR2_ARG,Green>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Magenta,DarkOrange,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>>,Pulsing<ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Blue>,RgbArg<ALT_COLOR_ARG,Cyan>,RgbArg<ALT_COLOR2_ARG,Green>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Magenta,DarkOrange,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>,Mix<Int<8000>,Black,ColorSelect<AltF,TrInstant,RgbArg<BASE_COLOR_ARG,Blue>,RgbArg<ALT_COLOR_ARG,Cyan>,RgbArg<ALT_COLOR2_ARG,Green>,RgbArg<ALT_COLOR3_ARG,Rgb<80,50,210>>,Magenta,DarkOrange,Rgb<115,15,240>,Rgb<100,100,150>,Rgb<180,130,0>>>,1400>>,
  TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<9>>,Int<-1>>,EFFECT_USER4>,
  TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<-1>>,Int<9>>,Int<-1>>,EFFECT_USER2>,
  TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<8>>>,Int<9>>,Int<-1>>,EFFECT_USER3>,
  TransitionPulseL<TrSelect<IncrementModuloF<EffectPulseF<EFFECT_USER4>,Int<2>>,TrInstant,TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<8>>>,Int<9>>>>,ThresholdPulseF<SwingSpeed<320>,Int<31000>>>,
  TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>>,EFFECT_USER4>,
  TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,White>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
  Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,White>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
  LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>,RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,White>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,White>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,White>,Int<16000>>,30>,TrSmoothFade<600>>>,
  LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,White>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,DarkOrange>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,DarkOrange>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<>,Mult<IntArg<IGNITION_OPTION2_ARG,22992>,Int<98304>>>>,TrWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,5992>,Int<98304>>>>>>>(),

/*------------------ Responsive RealFlame Red ---------------------
copyright Fett263 ResponsiveFlame (Primary Blade) OS6 Style
https://fett263.com/fett263-proffieOS6-style-library.html#ResponsiveFlame
OS6.6 v4.014
Single Style
Base Style: Responsive Flame (Real Flame Gradient)


--Effects Included--
Ignition Effect: Standard Wipe Ignition
Retraction Effect: Standard WipeIn Retraction - WavLen
Clash Effect: Real Clash V1
BC_effects_1 sans clash
*/
  StylePtr<Mix<SmoothStep<Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<36000>,Scale<BladeAngle<>,Int<10924>,Int<54000>>>,Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<-1>,Scale<BladeAngle<>,Int<-10000>,Int<-1>>>>,Black,Remap<Scale<RampF,Int<0>,Scale<IsLessThan<BladeAngle<>,Int<15000>>,Int<32768>,Scale<BladeAngle<0,15000>,Int<60000>,Int<32768>>>>,
    Layers<
      Mix<BladeAngle<>,StaticFire<Gradient<RotateColorsX<Int<1600>,RgbArg<BASE_COLOR_ARG,Red>>,RotateColorsX<Int<1000>,RgbArg<BASE_COLOR_ARG,Red>>,RotateColorsX<Int<400>,RgbArg<BASE_COLOR_ARG,Red>>,RgbArg<BASE_COLOR_ARG,Red>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Red>>,0,2,0,1800,10>,StaticFire<Gradient<RotateColorsX<Int<1600>,RgbArg<BASE_COLOR_ARG,Red>>,RotateColorsX<Int<1200>,RgbArg<BASE_COLOR_ARG,Red>>,RotateColorsX<Int<600>,RgbArg<BASE_COLOR_ARG,Red>>,RgbArg<BASE_COLOR_ARG,Red>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Red>>,0,4,0,2200,2>>,
      // fett263 dynamic clash
      Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,White>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
      // Force Choke / lightning
      TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<>,20>>,Strobe<Black,Rgb<80,0,0>,30,30>,TrFadeX<Percentage<WavLen<>,60>>,StaticFire<Red,Strobe<Black,Cyan,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<>,20>>>,EFFECT_FORCE>,
      EffectSequence<EFFECT_POWERSAVE,
        AlphaL<Black,Int<16384>>,
        AlphaL<Black,Int<0>>>,
    // Stab - OrangeRed stripes
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
    // Blast v1
    TransitionEffectL<TrConcat<
      // Impact Flash - BC always
      TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
      // Waves
      BlastL<Rgb<100,200,255>,850,250,351>,
      // Impact point afterimage
      //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
      AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
      // Impact point
      //BlastL<Rgb<100,200,255>,500,350,100000>,
      BlastL<Rgb<100,200,255>,300,350,100000>,
    // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
      //Random Strobe Flash no dimming
      AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
      //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
      // Bottom Layer Bump - random width
      AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
      // Top Layer Bump - fixed width
      AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                              Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
      // Begin Lockup Transition
      TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,   Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
      // End Lockup Transition
      TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                  Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
    // Non-Responsive Drag - BC custom drag fadeout
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
    LockupTrL<Layers<
      //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
      AlphaL<Black,Int<16000>>,
      AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
      AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
      Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
      Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
      Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
      // Begin Lightning Transition
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
      // End Lightning Transition    
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    // Melt - BC custom melt effects, uses twistangle<>
    LockupTrL<
      AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
      // Melt Shape
      SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
      // Melt Begin and End transitions
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeInX<RetractionTime<>>>>>
  >>(),
  StylePtr<InOutHelper<White,300,800,Pulsing<Black,White,3000>>>(),
  StylePtr<InOutHelper<Blinking<Black,White,1500,500>,300,800,Blinking<Black,Blinking<Black,White,500,500>,2000,500>>>(),
  "grand\ninquisitor"
},


// preset 0
// Blue
{ "a_CAL_KESTIS/The_Survivor/Blue;common", "",

  StylePtr<Layers<
// Main Blade
    // Jedi base Blue
  	StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,
  	// Jedi Force Blue
  	TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
  	// Jedi Swing Blue
  	AlphaL<RotateColorsX<Variation,Rgb<70,70,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_1,
// Ignition and Retraction
    InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWaveX<White,Int<5000>,Int<400>,Int<400>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(), 
// Crystal Chamber 
  StylePtr<Layers<
    // Jedi Crystal Blue
    Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
    // Jedi Force Blue
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Blue>,35,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
// Pommel
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,Blue,Pulsing<Rgb<0,0,90>,Blue,800>,Blue>,RotateColorsX<Variation,Black>>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<6000,-200,RandomFlicker<Blue,Black>,Black,RandomFlicker<Blue,Rgb<0,0,128>>>,Black>>
  >>(),
"survivor\nblue"},



// preset 1
// Green
{ "a_CAL_KESTIS/The_Survivor/Blue;common", "", //placeholder style, not used because I used style 0 with variation 21846 in presets.ini on Blue so I could fit Protoblade ;)
StylePtr<Black>()}, // Using NULL for remaining blades.....cheating for mem savings!


// preset 2
// Orange
{ "a_CAL_KESTIS/The_Survivor/Blue;common", "",

  StylePtr<Layers<
// Main Blade
    // Jedi base Orange
    StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,DarkOrange>,Pulsing<RotateColorsX<Variation,Rgb<90,24,0>>,RotateColorsX<Variation,DarkOrange>,800>,RotateColorsX<Variation,DarkOrange>>,
    // Jedi Force Orange
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<160,43,0>>>,TrDelay<3000>,RotateColorsX<Variation,DarkOrange>,TrFade<800>>,EFFECT_FORCE>,
    // Jedi Swing Orange
    AlphaL<RotateColorsX<Variation,Rgb<255,178,110>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_1,
// Ignition and Retraction
    InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWaveX<White,Int<5000>,Int<400>,Int<400>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(), 
// Crystal Chamber 
  StylePtr<Layers<
    // Jedi Crystal Orange
    Stripes<1000,-2000,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<90,24,0>>,Black>,
    // Jedi Force Orange
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<160,43,0>>>,TrDelay<3000>,RotateColorsX<Variation,DarkOrange>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,DarkOrange>,25,20,Black,100,300,1000>,Black,2000>,Black>>>
  >(),
/// Pommel
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,Blue,Pulsing<Rgb<0,0,90>,Blue,800>,Blue>,RotateColorsX<Variation,Black>>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<6000,-200,RandomFlicker<Blue,Black>,Black,RandomFlicker<Blue,Rgb<0,0,128>>>,Black>>
  >>(),
"survivor\norange"},



// preset 3
// Purple
{ "a_CAL_KESTIS/The_Survivor/Blue;common", "",
  StylePtr<Layers<
// Main Blade
    // Jedi base Purple
    StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<95,0,225>>,Pulsing<RotateColorsX<Variation,Rgb<39,5,71>>,RotateColorsX<Variation,Rgb<95,0,225>>,800>,RotateColorsX<Variation,Rgb<95,0,225>>>,
    // Jedi Force Purple
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<95,0,225>>,TrFade<800>>,EFFECT_FORCE>,
    // Jedi Swing Purple
    AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_1,
// Ignition and Retraction
    InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWaveX<White,Int<5000>,Int<400>,Int<400>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(), 
// Crystal Chamber 
  StylePtr<Layers<
    // Jedi Crystal Purple
    Stripes<1000,-2000,RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<39,5,71>>,Black>,
    // Jedi Force Purple
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<95,0,225>>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Rgb<95,0,225>>,25,20,Black,100,300,1000>,Black,2000>,Black>>>
  >(),
/// Pommel
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,Blue,Pulsing<Rgb<0,0,90>,Blue,800>,Blue>,RotateColorsX<Variation,Black>>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<6000,-200,RandomFlicker<Blue,Black>,Black,RandomFlicker<Blue,Rgb<0,0,128>>>,Black>>
  >>(),
"survivor\npurple"},




// preset 4
// Yellow
{ "a_CAL_KESTIS/The_Survivor/Blue;common", "",
   
  StylePtr<Layers<
// Main Blade
    // Jedi base Yellow
    StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<180,180,0>>,Pulsing<RotateColorsX<Variation,Rgb<64,64,0>>,RotateColorsX<Variation,Rgb<180,180,0>>,800>,RotateColorsX<Variation,Rgb<180,180,0>>>,
    // Jedi Force Yellow
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<113,113,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<180,180,0>>,TrFade<800>>,EFFECT_FORCE>,
    // Jedi Swing Yellow
    AlphaL<RotateColorsX<Variation,Rgb<230,180,80>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_Red,
// Ignition and Retraction
    InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWaveX<White,Int<5000>,Int<400>,Int<400>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),   
// Crystal Chamber
  StylePtr<Layers<
    // Jedi Crystal Yellow
    Stripes<1000,-2000,RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<64,64,0>>,Black>,
    // Jedi Force Yellow
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>, RotateColorsX<Variation,Rgb<113,113,0>>>,TrDelay<3000>, RotateColorsX<Variation,Rgb<180,180,0>>,  TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Rgb<180,180,0>>,25,20,Black,100,300,1000>,Black,2000>,Black>>>
  >(),
/// Pommel
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,Blue,Pulsing<Rgb<0,0,90>,Blue,800>,Blue>,RotateColorsX<Variation,Black>>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<6000,-200,RandomFlicker<Blue,Black>,Black,RandomFlicker<Blue,Rgb<0,0,128>>>,Black>>
  >>(),
"survivor\nyellow"},



// preset 5
// Cyan
{ "a_CAL_KESTIS/The_Survivor/Blue;common", "",

  StylePtr<Layers<
// Main Blade
    // Jedi base Cyan
  	StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<0,200,200>>,Pulsing<RotateColorsX<Variation,Rgb<11,42,53>>,RotateColorsX<Variation,Rgb<0,200,200>>,800>,RotateColorsX<Variation,Rgb<0,200,200>>>,
  	// Jedi Force Cyan
  	TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<0,200,200>>,RotateColorsX<Variation,Rgb<19,75,94>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<0,200,200>>,TrFade<800>>,EFFECT_FORCE>,
  	// Jedi Swing Cyan
  	AlphaL<RotateColorsX<Variation,Rgb<90,180,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_1,
// Ignition and Retraction
    InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWaveX<White,Int<5000>,Int<400>,Int<400>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(), 
// Crystal Chamber 
  StylePtr<Layers<
    // Jedi Crystal Cyan
    Stripes<1000,-2000,RotateColorsX<Variation,Rgb<0,200,200>>,RotateColorsX<Variation,Rgb<11,42,53>>,Black>,
    // Jedi Force Cyan
  	TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<0,200,200>>,RotateColorsX<Variation,Rgb<19,75,94>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<0,200,200>>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Rgb<0,200,200>>,25,20,Black,100,300,1000>,Black,2000>,Black>>>
  >(),
/// Pommel
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,Blue,Pulsing<Rgb<0,0,90>,Blue,800>,Blue>,RotateColorsX<Variation,Black>>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<6000,-200,RandomFlicker<Blue,Black>,Black,RandomFlicker<Blue,Rgb<0,0,128>>>,Black>>
  >>(),
"survivor\ncyan"},



// preset 6
// Magenta
{ "a_CAL_KESTIS/The_Survivor/Blue;common", "",
   
  StylePtr<Layers<
// Main Blade
    // Jedi base Magenta
    StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<100,20,150>>,Pulsing<RotateColorsX<Variation,Rgb<50,0,50>>,RotateColorsX<Variation,Rgb<100,20,150>>,800>,RotateColorsX<Variation,Rgb<100,20,150>>>,
    // Jedi Force Magenta
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<100,20,150>>,RotateColorsX<Variation,Rgb<50,19,100>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<100,20,150>>,TrFade<800>>,EFFECT_FORCE>,
    // Jedi Swing Magenta
    AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_1,
// Ignition and Retraction
    InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWaveX<White,Int<5000>,Int<400>,Int<400>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(), 
// Crystal Chamber
  StylePtr<Layers<
    // Jedi Crystal Magenta
    Stripes<1000,-2000,RotateColorsX<Variation,Rgb<100,20,150>>,RotateColorsX<Variation,Rgb<50,0,50>>, Black>,
    // Jedi Force Magenta
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<100,20,150>>,RotateColorsX<Variation,Rgb<50,19,100>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<100,20,150>>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Rgb<100,20,150>>,25,20,Black,100,300,1000>,Black,2000>,Black>>>
  >(),
/// Pommel
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,Blue,Pulsing<Rgb<0,0,90>,Blue,800>,Blue>,RotateColorsX<Variation,Black>>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<6000,-200,RandomFlicker<Blue,Black>,Black,RandomFlicker<Blue,Rgb<0,0,128>>>,Black>>
  >>(),
"survivor\nmagenta"},



// preset 7
// Indigo
{ "a_CAL_KESTIS/The_Survivor/Blue;common", "",

  StylePtr<Layers<
// Main Blade
    // Jedi base Indigo
    StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<80,50,200>>, Pulsing<RotateColorsX<Variation,Rgb<28,18,71>>, RotateColorsX<Variation,Rgb<80,50,200>>,800>,   RotateColorsX<Variation,Rgb<80,50,200>>>,
    // Jedi Force Indigo
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<80,50,200>>, RotateColorsX<Variation,Rgb<50,31,125>>>,TrDelay<3000>, RotateColorsX<Variation,Rgb<80,50,200>>,  TrFade<800>>,EFFECT_FORCE>,
    // Jedi Swing Indigo
    AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,  Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_1,
// Ignition and Retraction
    InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWaveX<White,Int<5000>,Int<400>,Int<400>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(), 
// Crystal Chamber
  StylePtr<Layers<
    // Jedi Crystal Indigo
    Stripes<1000,-2000,RotateColorsX<Variation,Rgb<80,50,200>>,RotateColorsX<Variation,Rgb<28,18,71>>,Black>,
    // Jedi Force Indigo
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<80,50,200>>, RotateColorsX<Variation,Rgb<50,31,125>>>,TrDelay<3000>, RotateColorsX<Variation,Rgb<80,50,200>>,  TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Rgb<160,60,255>>,25,20,Black,100,300,1000>,Black,2000>,Black>>>
  >(),
/// Pommel
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,Blue,Pulsing<Rgb<0,0,90>,Blue,800>,Blue>,RotateColorsX<Variation,Black>>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<6000,-200,RandomFlicker<Blue,Black>,Black,RandomFlicker<Blue,Rgb<0,0,128>>>,Black>>
  >>(),
"survivor\nindigo"},



// preset 8
// Red
{ "a_CAL_KESTIS/The_Survivor/Blue;common", "",
   
//Second Sister base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
// Second Sister Force Red
    TransitionEffectL<TrConcat<TrFade<200>,Rgb<255,50,50>,TrFade<400>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<255,50,50>>,TrFade<800>>,EFFECT_FORCE>,
BC_effects_Red,
// Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
    InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Red>,AudioFlicker<Yellow,Red>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
/// Pommel
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,Blue,Pulsing<Rgb<0,0,90>,Blue,800>,Blue>,RotateColorsX<Variation,Black>>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<6000,-200,RandomFlicker<Blue,Black>,Black,RandomFlicker<Blue,Rgb<0,0,128>>>,Black>>
  >>(),
"2nd sister\nred"},



// USE preset 7 Indigo
// { "a_KSith/Aggression;common", "tracks/FallenOrderTracks/JFO3.wav",


// USE preset 8 Second Sister Red
// { "a_KSith/Ascension;common", "tracks/FallenOrderTracks/JFO11.wav",


// Use preset 8 Second Sister Red
// { "a_KSith/AscensionSS_BC;common", "tracks/FallenOrderTracks/JFO11.wav",


// Use preset 4 Yellow
// { "a_KSith/Desolation;common", "tracks/FallenOrderTracks/JFO12.wav",


// USE preset 8 Second Sister Red
// { "a_CAL_KESTIS/InquisitoriousRed;common", "tracks/FallenOrderTracks/JFO9.wav",



// preset 9
{ "a_CAL_KESTIS/The_Survivor/Blue;common", "", // blueforce Legion based style w/ my effects

StylePtr<Layers<
  Mix<SwingSpeed<500>,StyleFire<BrownNoiseFlicker<Red,Black,50>,Rgb<83,0,255>,0,2,FireConfig<0,3000,5>,FireConfig<4000,0,0>>,BrownNoiseFlicker<Red,Black,50>>,
BC_effects_Red,
// Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
   InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
   AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Crystal Chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Red>,AudioFlicker<Yellow,Red>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
/// Pommel
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,Blue,Pulsing<Rgb<0,0,90>,Blue,800>,Blue>,RotateColorsX<Variation,Black>>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<6000,-200,RandomFlicker<Blue,Black>,Black,RandomFlicker<Blue,Rgb<0,0,128>>>,Black>>
  >>(),
"Inquisitorious"},


// USE preset 2 Orange
// { "a_KSith/ProtoBC;common", "tracks/FallenOrderTracks/JFO2.wav",


// USE preset 1 Green
// { "PsyBorg;common", "tracks/FallenOrderTracks/JFO7.wav",


// USE preset 4 Yellow
// { "a_greyscale/RA;common", "tracks/FallenOrderTracks/JFO8.wav",


// USE preset 3 Purple
// { "RuinerSM;common", "tracks/FallenOrderTracks/JFO13.wav",


// USE preset 8 Second Sister Red
// { "a_KYLO/SonOfDarkness;common", "tracks/FallenOrderTracks/JFO11.wav",


// USE preset 8 Second Sister Red
// { "2ndSistr;common", "tracks/FallenOrderTracks/JFO12.wav",


// USE preset 8 Second Sister Red
// { "9thSistr;common", "tracks/FallenOrderTracks/JFO4.wav",


// USE preset 1 Green
// { "CybrAssn;common", "tracks/FallenOrderTracks/JFO15.wav",


// USE preset 6 Magenta
// { "Vengence;common", "tracks/FallenOrderTracks/JFO15.wav",


// USE preset 9 Legion Red
// { "a_blueforce/Legion;common", "",


// USE preset 0 Blue
// {"a_CAL_KESTIS/JFOScrapper;common", "tracks/FallenOrderTracks/JFO1.wav",



// CYAN + PURPLE
// preset 10
{ "a_CAL_KESTIS/The_Survivor/Blue;common", "",
   
  StylePtr<Layers<
// Main Blade
     // Custom base Cyan + Purple
    StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<39,5,71>>,Pulsing<RotateColorsX<Variation,Rgb<0,200,200>>,  RotateColorsX<Variation,Rgb<95,0,225>>,800>,  RotateColorsX<Variation,Rgb<0,200,200>>>,
    // Custom Force Cyan
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<0,200,200>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,  RotateColorsX<Variation,Rgb<95,0,225>>, TrFade<800>>,EFFECT_FORCE>,
    // Jedi Swing Purple
    AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,  Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,

BC_effects_Red,
// Ignition and Retraction
TransitionEffectL<TrConcat<TrInstant,HumpFlicker<White,Black,75>,TrSmoothFade<500>>,EFFECT_IGNITION>,
    InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWipeInX<Int<400>>>,TrWipeInSparkTip<White,200>>,
    TransitionEffectL<TrConcat<
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<70>>, TrWaveX<Cyan,           Int<70>, Int<80>,Int<70>, Int<32768>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<32768>,Int<4000>>>,TrFade<100>>,TrWaveX<Rgb<160,60,255>,Int<100>,Int<80>,Int<100>,Int<32768>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<130>>,TrWaveX<Cyan,           Int<130>,Int<100>,Int<130>,Int<32768>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<32768>,Int<4000>>>,TrFade<150>>,TrWaveX<Rgb<160,60,255>,Int<150>,Int<110>,Int<150>,Int<32768>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<160>>,TrWaveX<Cyan,           Int<160>,Int<110>,Int<160>,Int<32768>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<32768>,Int<4000>>>,TrFade<170>>,TrWaveX<Rgb<160,60,255>,Int<170>,Int<100>,Int<170>,Int<32768>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<190>>,TrWaveX<Cyan,           Int<190>,Int<140>,Int<190>,Int<32768>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<32768>,Int<4000>>>,TrFade<210>>,TrWaveX<Rgb<160,60,255>,Int<210>,Int<160>,Int<210>,Int<32768>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<240>>,TrWaveX<Cyan,           Int<240>,Int<180>,Int<240>,Int<32768>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<32768>,Int<4000>>>,TrFade<300>>,TrWaveX<Rgb<160,60,255>,Int<300>,Int<200>,Int<300>,Int<32768>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<340>>,TrWaveX<Cyan,           Int<340>,Int<230>,Int<340>,Int<32768>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<32768>,Int<4000>>>,TrFade<400>>,TrWaveX<Rgb<160,60,255>,Int<420>,Int<250>,Int<420>,Int<32768>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,           Bump<Int<32768>,Int<4000>>>,TrFade<450>>,TrWaveX<Cyan,           Int<520>,Int<300>,Int<520>,Int<32768>>>,Black,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Sin<Scale<Trigger<EFFECT_RETRACTION,Int<3000>,Int<1000>,Int<500>>,Int<550>,Int<70>>>,Cyan,Rgb<160,60,255>>,Bump<Scale<Trigger<EFFECT_RETRACTION,Int<3000>,Int<1000>,Int<500>>,Int<-8000>,Int<2000>>>>,TrDelay<3000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrDelay<3000>,White,TrDelay<50>>,EFFECT_RETRACTION>,

    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Sin<Scale<Trigger<EFFECT_PREON,Int<3000>,Int<1000>,Int<500>>,Int<70>,Int<550>>>,Cyan,Rgb<160,60,255>>,Bump<Scale<Trigger<EFFECT_PREON,Int<3000>,Int<1000>,Int<500>>,Int<41000>,Int<32768>>>>,TrDelay<3000>>,EFFECT_PREON>,
      TransitionEffectL<TrConcat<
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<520>>,TrWaveX<Cyan,Int<520>,Int<550>,Int<520>,Int<0>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<0>,Int<4000>>>,TrFade<420>>,TrWaveX<Rgb<160,60,255>,Int<420>,Int<450>,Int<420>,Int<0>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<340>>,TrWaveX<Cyan,Int<340>,Int<430>,Int<340>,Int<0>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<0>,Int<4000>>>,TrFade<300>>,TrWaveX<Rgb<160,60,255>,Int<300>,Int<400>,Int<300>,Int<0>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<240>>,TrWaveX<Cyan,Int<240>,Int<380>,Int<240>,Int<0>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<0>,Int<4000>>>,TrFade<210>>,TrWaveX<Rgb<160,60,255>,Int<210>,Int<360>,Int<210>,Int<0>>>,AlphaL<Black,Int<0>>,       // If Pulsing emitter doesn't really like the Trigger, then need to do this need this
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<190>>,TrWaveX<Cyan,Int<190>,Int<340>,Int<190>,Int<0>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<0>,Int<4000>>>,TrFade<170>>,TrWaveX<Rgb<160,60,255>,Int<170>,Int<320>,Int<170>,Int<0>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<160>>,TrWaveX<Cyan,Int<160>,Int<300>,Int<160>,Int<0>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<0>,Int<4000>>>,TrFade<150>>,TrWaveX<Rgb<160,60,255>,Int<150>,Int<250>,Int<150>,Int<0>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<130>>,TrWaveX<Cyan,Int<130>,Int<150>,Int<130>,Int<0>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Rgb<160,60,255>,Bump<Int<0>,Int<4000>>>,TrFade<100>>,TrWaveX<Rgb<160,60,255>,Int<100>,Int<100>,Int<100>,Int<0>>>,AlphaL<Black,Int<0>>,
      TrJoin<TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<0>,Int<4000>>>,TrFade<70>>,TrWaveX<Cyan,Int<70>,Int<500>,Int<70>,Int<0>>>,Black,TrInstant>,EFFECT_PREON>,
// On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(), 
// Crystal Chamber
  StylePtr<Layers<
    Stripes<1000,-2000,Pulsing<RotateColorsX<Variation,Rgb<0,200,200>>,RotateColorsX<Variation,Rgb<95,0,225>>,800>,RotateColorsX<Variation,Rgb<95,0,225>>,Black>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<95,0,225>>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<Pulsing<RotateColorsX<Variation,Rgb<0,200,200>>,RotateColorsX<Variation,Rgb<95,0,225>>,800>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
 /// Pommel
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,Blue,Pulsing<Rgb<0,0,90>,Blue,800>,Blue>,RotateColorsX<Variation,Black>>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<6000,-200,RandomFlicker<Blue,Black>,Black,RandomFlicker<Blue,Rgb<0,0,128>>>,Black>>
  >>(),
"crispity\nhybrid"},



// // USE preset 1 Green
// // {"a_greyscale/Assassin_Greyscale;common", "",


// // USE preset 3 Purple
// // {"a_greyscale/Volatile_Greyscale;common", "",


// USE preset 5 Cyan
// {"a_greyscale/Exaulted_Greyscale;common", "",


// USE preset 2 - variation to pale GreenBleu
// {"a_greyscale/Grey_Greyscale;common", "",


// USE preset 9 Legion Red
// {"a_greyscale/Seeth_Greyscale;common", "",


// USE preset 8 Second Sister Red
// {"a_KSith/Menace;common", "",






// preset 11
{ "a_CAL_KESTIS/The_Survivor/Blue;common", "",

//{"a_blueforce/Protoblade;common","", // 15888 bytes when compiling, but reported style size is 3224...?
    StylePtr<Layers<
      StripesX<Int<3000>,Int<-3500>,RotateColorsX<Variation,Blue>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,0,60>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,30>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,0,80>>,RotateColorsX<Variation,Rgb<0,0,30>>>>,
      TransitionLoopL<TrConcat<TrWaveX<AudioFlicker<RotateColorsX<Variation,Blue>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<0,0,80>>,Black,200>>,Int<400>,Int<100>,Int<200>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<50>,Int<1000>>>>>,
      TransitionLoopL<TrConcat<TrWaveX<AudioFlicker<RotateColorsX<Variation,Blue>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<0,0,60>>,300>>,Int<400>,Int<100>,Int<200>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<200>,Int<1500>>>>>,
      AlphaL<StrobeL<White,Int<20>,Int<1>>,SwingSpeed<600>>,
// Dim Blade 50% "Power Save" button combo
      EffectSequence<EFFECT_POWERSAVE,
      AlphaL<Black,Int<16384>>,
      AlphaL<Black,Int<0>>>,
// Clash 1 - BladeAngle responsive.
      TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// Stab 1 - OrangeRed stripes
      TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// Blast 1
    // Impact Flash
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
    // Waves
    BlastL<White,850,250,351>,
    // Impact point afterimage
    AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
    // Impact point
    BlastL<White,500,350,100000>,
// Lockup - Custom for Protoblade lock01.wav - TransitionLoop Pulse increases speed then slows in time w/ sound
      LockupTrL<Layers<
        AlphaL<Blinking<Rgb<100,100,200>,Strobe<Yellow,Black,15,30>,60,500>,                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
       AlphaL<Blinking<BrownNoiseFlicker<White,Black,70>,BrownNoiseFlicker<Yellow,NavajoWhite,80>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,
        TrConcat<TrInstant,
        AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,             Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
      LockupTrL<TransitionLoopL<TrWaveX<BrownNoiseFlicker<White,Black,100>,Scale<Trigger<EFFECT_LOCKUP_BEGIN,Int<12000>,Int<3000>,Int<2500>>,Int<1000>,Int<200>>,Int<250>>>,TrInstant,TrInstant,SaberBase::LOCKUP_NORMAL>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                         Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
      TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// Drag
      LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// Lightning Block  
      LockupTrL<AlphaL<Black,RandomBlinkF<Sin<Int<70>,Int<30000>,Int<10000>>>>,TrInstant,TrInstant,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
      LockupTrL<AlphaL<Strobe<White,AudioFlicker<White,Blue>,50,1>,LayerFunctions<Bump<Scale<Sin<Int<40>>,Int<3000>,Int<8000>>,Scale<Sin<RandomBlinkF<Int<5000>>>,Scale<Sin<Int<10>,Int<3000>,Int<2000>>,Scale<Sin<Int<10>,Int<3068>,Int<1000>>,Int<9000>,Int<5000>>,Int<0>>,Int<0>>>,Bump<Scale<Sin<Int<25>>,Scale<NoisySoundLevel,Int<26000>,Int<18000>>,Int<8000>>,Scale<NoisySoundLevel,Scale<Sin<Int<20>>,Int<6000>,Int<10000>>,Scale<SlowNoise<Int<1500>>,Int<10000>,Int<14000>>>>,Bump<Scale<Sin<Int<60>,Int<10008>>,Scale<Sin<Int<10>>,Int<20000>,Int<16000>>,Scale<Sin<Int<10>>,Sin<Int<20>>,Int<24000>>>,Scale<Sin<Int<10>>,Scale<Sin<Int<10>,Int<3000>,Int<2000>>,Scale<Sin<Int<10>,Int<3068>,Int<1000>>,Int<9000>,Int<5000>>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
      LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
      Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
      Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
      Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>, 
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// Melt
      LockupTrL<AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
        SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>, 
// Ignition Effects
      TransitionEffectL<TrConcat<TrInstant,Layers<
        AlphaL<Stripes<3000,3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,SmoothStep<Int<16385>,Int<-1>>>,
        AlphaL<Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,SmoothStep<Int<16384>,Int<0>>>>,TrFade<800>>,EFFECT_IGNITION>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<16384>,Int<20000>>>,TrSmoothFade<1400>>,EFFECT_IGNITION>,
// Extension / Retraction
      InOutTrL<TrJoinR<TrWipe<100>,TrWipeIn<100>>,TrConcat<TrInstant,White,TrFade<200>,Black,TrDelay<100>,HumpFlicker<Rgb<100,100,100>,Rgb<0,0,155>,20>,TrSmoothFade<800>,StrobeL<White,Int<20>,Int<2>>,TrInstant,Black,TrDelay<50>,Black,TrInstant,White,TrDelay<50>,Blue,TrFade<100>>>,
 // Cooldown tips fizzle out
      TransitionEffectL<TrConcat<
        TrFade<450>,       AlphaL<RandomFlicker<Strobe<White,RotateColorsX<Variation,Rgb<0,0,255>>,50,10>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<0,0,255>>,Black,500>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,
        TrDelay<1000>,     AlphaL<RandomFlicker<Strobe<White,RotateColorsX<Variation,Rgb<0,0,255>>,50,10>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<0,0,255>>,Black,500>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,
        TrSmoothFade<1600>,Black,
        TrDelay<100>,      AlphaL<RandomFlicker<Strobe<White,RotateColorsX<Variation,Rgb<0,0,255>>,50,10>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<0,0,255>>,Black,500>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelay<50>>,EFFECT_RETRACTION>,
// Preon
      TransitionEffectL<TrJoin<TrWaveX<White,Int<400>,Int<200>,Int<200>,Int<0>>,TrWaveX<White,Int<400>,Int<200>,Int<200>,Int<32768>>>,EFFECT_PREON>,
      TransitionEffectL<TrConcat<
        TrInstant,Blinking<AlphaL<RandomFlicker<Strobe<White,RotateColorsX<Variation,Blue>,        50,10>,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,        Black,500>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,Black,50,500>,
        TrDelay<200>,      AlphaL<RandomFlicker<Strobe<White,RotateColorsX<Variation,Blue>,        50,10>,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,        Black,500>>,LayerFunctions<Bump<Int<0>,Int<15000>>,Bump<Int<32768>,Int<15000>>>>,
        TrBoing<500,3>,    AlphaL<RandomFlicker<Strobe<White,RotateColorsX<Variation,Blue>,        50,10>,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,        Black,500>>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrSmoothFade<300>,HumpFlicker<White,Blue,20>,TrFade<325>,White,TrJoin<TrWipeIn<200>,TrWipe<200>>>,EFFECT_PREON>,
// On-Demand Battery Level
      AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
    >>(),
    
// Crystal Chamber 
  StylePtr<Layers<
    // Jedi Crystal Blue
    Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
    // Jedi Force Blue
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Blue>,25,20,Black,100,300,1000>,Black,2000>,Black>>>
  >(),
/// Pommel
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,Blue,Pulsing<Rgb<0,0,90>,Blue,800>,Blue>,RotateColorsX<Variation,Black>>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<6000,-200,RandomFlicker<Blue,Black>,Black,RandomFlicker<Blue,Rgb<0,0,128>>>,Black>>
  >>(),
"protoblade"},




// Use preset 0 Blue
// { "testfont2", "tracks/track1.wav",







// { "Metropls;common", "",
   
// StylePtr<Layers<
//   // Smoke base Gold
//   StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<15,8,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<90,50,0>>,Black>>,RotateColorsX<Variation,Rgb<40,30,0>>,Pulsing<RotateColorsX<Variation,Rgb<36,26,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<60,40,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<90,65,0>>,RotateColorsX<Variation,Rgb<5,2,0>>,3000>>,
//   AlphaL<StyleFire<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<2,1,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
//   // Bright Swing Gold
//   AlphaL<RotateColorsX<Variation,Rgb<230,180,80>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   // Dim Blade 50% "Power Save" button combo
//   EffectSequence<EFFECT_POWERSAVE,
//   AlphaL<Black,Int<16384>>,
//   AlphaL<Black,Int<0>>>,
// // Clash 1 - BladeAngle responsive.
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// // Stab 1 - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// // Blast 1
//     // Impact Flash
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//     // Waves
//     BlastL<White,850,250,351>,
//     // Impact point afterimage
//     AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//     // Impact point
//     BlastL<White,500,350,100000>,
// // Lockup - BC custom range mid-blade - Red or Yellow blade alt colors
//     LockupTrL<Layers<
//       AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
//       AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                      Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//       TrConcat<TrInstant,
//       AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Red,Black,500>,Black,15,30>,60,500>, Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,          Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<Red,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// // Non-Responsive Drag
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// // Lightning Block Non-Responsive
//     LockupTrL<AlphaL<BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,LayerFunctions<
//     Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//     Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//     Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
//     // Begin Lightning Transition
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//     // End Lightning Transition    
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,    
// // Melt    
//     LockupTrL<
//     AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//     // Melt Shape
//     SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//     // Melt Begin and End transitions
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,  // Great melt colors as you twist, gets dripping red hot/fire and bright yellow.

//   TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<230,180,80>>>,TrFade<1200>>,EFFECT_IGNITION>,
  
//   InOutTrL<TrWipeSparkTip<White,400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<2000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<180,130,0>>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<180,130,0>>,Rgb<50,50,50>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Rgb<180,130,0>>>>,White,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelay<6000>>,EFFECT_PREON>,
// // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // Crystal Chamber
//   StylePtr<Layers<
//     // Jedi Crystal Yellow
//     Cylon<Stripes<1000,-275,RotateColorsX<Variation,Rgb<180,180,0>>,  RotateColorsX<Variation,Rgb<64,64,0>>,  Black,RotateColorsX<Variation,Rgb<64,64,0>>>,100,1, Stripes<1000,-2000,RotateColorsX<Variation,Rgb<180,180,0>>, RotateColorsX<Variation,Rgb<64,64,0>>,  Black>,100,1,500>,
//     // Jedi Force Yellow
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>, RotateColorsX<Variation,Rgb<113,113,0>>>,TrDelay<3000>, RotateColorsX<Variation,Rgb<180,180,0>>,  TrFade<800>>,EFFECT_FORCE>,
//     BlastFadeoutL<White>,
//     LockupL<Blinking<White,Rgb<60,160,255>,20,500>,AudioFlicker<Yellow,Blue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Rgb<180,180,0>>,25,20,Black,100,300,1000>,Black,2000>,Black>>>
//   >(),
// /// Pommel
//   StylePtr<Layers<
//     Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,Black>,
//     TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
//     LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
//     InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<1500>>,Int<3000>>,Pulsing<Stripes<1000,275,Blue,Rgb<0,0,128>,Black,Rgb<0,0,128>>,Black,2000>,AlphaL<Black,Int<16384>>>>
//   >>(),
// "metropolis"},






// Version 1 of all-in-one style using EffectSequence to cycle through all 9 colors (but the whole identical style is repeated..meh.)
// {"a_CAL_KESTIS/TwoGeek;common", "tracks/FallenOrderTracks/JFO3.wav",
//   StylePtr<Layers<
// // Main Blade Base Color/Styles
//       EffectSequence<EFFECT_SWAP,
//   // Jedi base Blue
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Blue>,           Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,   RotateColorsX<Variation,Blue>,800>,             RotateColorsX<Variation,Blue>>,
//   // Jedi base Green
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Green>,          Pulsing<RotateColorsX<Variation,Rgb<0,90,0>>,   RotateColorsX<Variation,Green>,800>,            RotateColorsX<Variation,Green>>,
//   // Jedi base Purple
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<95,0,225>>,Pulsing<RotateColorsX<Variation,Rgb<39,5,71>>,  RotateColorsX<Variation,Rgb<95,0,225>>,800>,  RotateColorsX<Variation,Rgb<95,0,225>>>,
//   // Jedi base Orange
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,DarkOrange>,     Pulsing<RotateColorsX<Variation,Rgb<90,24,0>>,  RotateColorsX<Variation,DarkOrange>,800>,       RotateColorsX<Variation,DarkOrange>>,
//   // Jedi base Yellow
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<180,180,0>>, Pulsing<RotateColorsX<Variation,Rgb<64,64,0>>,  RotateColorsX<Variation,Rgb<180,180,0>>,800>,   RotateColorsX<Variation,Rgb<180,180,0>>>,
//   // Jedi base Cyan
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<30,120,150>>,Pulsing<RotateColorsX<Variation,Rgb<11,42,53>>, RotateColorsX<Variation,Rgb<30,120,150>>,800>,  RotateColorsX<Variation,Rgb<30,120,150>>>,
//   // Jedi base Magenta
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<180,30,140>>,Pulsing<RotateColorsX<Variation,Rgb<64,11,49>>, RotateColorsX<Variation,Rgb<180,30,140>>,800>,  RotateColorsX<Variation,Rgb<180,30,140>>>,
//   // Jedi base Indigo
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<80,50,200>>, Pulsing<RotateColorsX<Variation,Rgb<28,18,71>>, RotateColorsX<Variation,Rgb<80,50,200>>,800>,   RotateColorsX<Variation,Rgb<80,50,200>>>,
//   // Sith base Red
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Red>,            Pulsing<RotateColorsX<Variation,Rgb<90,0,0>>,   RotateColorsX<Variation,Red>,800>,              RotateColorsX<Variation,Red>>>,

// // Main Blade Force Effect Color/Styles
//     EffectSequence<EFFECT_SWAP,
//   // Jedi Force Blue
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,           RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,   RotateColorsX<Variation,Blue>,            TrFade<800>>,EFFECT_FORCE>,
//   // Jedi Force Green
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Green>,          RotateColorsX<Variation,Rgb<0,160,0>>>,TrDelay<3000>,   RotateColorsX<Variation,Green>,           TrFade<800>>,EFFECT_FORCE>,
//   // Jedi Force Purple
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,  RotateColorsX<Variation,Rgb<95,0,225>>, TrFade<800>>,EFFECT_FORCE>,
//   // Jedi Force Orange
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,     RotateColorsX<Variation,Rgb<160,43,0>>>,TrDelay<3000>,  RotateColorsX<Variation,DarkOrange>,      TrFade<800>>,EFFECT_FORCE>,
//   // Jedi Force Yellow
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>, RotateColorsX<Variation,Rgb<113,113,0>>>,TrDelay<3000>, RotateColorsX<Variation,Rgb<180,180,0>>,  TrFade<800>>,EFFECT_FORCE>,
//   // Jedi Force Cyan
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<30,120,150>>,RotateColorsX<Variation,Rgb<19,75,94>>>,TrDelay<3000>,  RotateColorsX<Variation,Rgb<30,120,150>>, TrFade<800>>,EFFECT_FORCE>,
//   // Jedi Force Magenta
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,30,140>>,RotateColorsX<Variation,Rgb<113,19,88>>>,TrDelay<3000>, RotateColorsX<Variation,Rgb<180,30,140>>, TrFade<800>>,EFFECT_FORCE>,
//   // Jedi Force Indigo
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<80,50,200>>, RotateColorsX<Variation,Rgb<50,31,125>>>,TrDelay<3000>, RotateColorsX<Variation,Rgb<80,50,200>>,  TrFade<800>>,EFFECT_FORCE>,
//   // Sith Force Red
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,            RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,   RotateColorsX<Variation,Red>,             TrFade<800>>,EFFECT_FORCE>>,

// // Main Blade Swing Color/Styles
//     EffectSequence<EFFECT_SWAP,
//   // Jedi Swing Blue
//     AlphaL<RotateColorsX<Variation,Rgb<70,70,255>>,   Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   // Jedi Swing Green
//     AlphaL<RotateColorsX<Variation,Rgb<100,255,100>>, Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   // Jedi Swing Purple
//     AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,  Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   // Jedi Swing Orange
//     AlphaL<RotateColorsX<Variation,Rgb<255,178,110>>, Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   // Jedi Swing Yellow
//     AlphaL<RotateColorsX<Variation,Rgb<230,180,80>>,  Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   // Jedi Swing Cyan
//     AlphaL<RotateColorsX<Variation,Rgb<90,180,255>>,  Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   // Jedi Swing Magenta
//     AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,  Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   // Jedi Swing Indigo
//     AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,  Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   // Sith Swing Red
//     AlphaL<RotateColorsX<Variation,Rgb<255,100,100>>, Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>>,

// // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//     AlphaL<Black,Int<16384>>,
//     AlphaL<Black,Int<0>>>,
// // Clash 1 - BladeAngle responsive.
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// // Stab 1 - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// // Blast 1
//     // Impact Flash
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//     // Waves
//     BlastL<White,850,250,351>,
//     // Impact point afterimage
//     AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//     // Impact point
//     BlastL<White,500,350,100000>,
// // Lockup - BC custom range mid-blade
//     LockupTrL<Layers<
//       AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//       AlphaL<BrownNoiseFlicker<Yellow,Black,50>,                                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//       TrConcat<TrInstant,
//       AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// // Non-Responsive Drag
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// // Lightning Block Non-Responsive    
//     LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//     Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//     Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//     Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
//     // Begin Lightning Transition
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//     // End Lightning Transition    
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// // Melt    
//     LockupTrL<
//     AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//     // Melt Shape
//     SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//     // Melt Begin and End transitions
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,  // Great melt colors as you twist, gets dripping red hot/fire and bright yellow.

//     InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<400>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>> >(), 

// // Crystal Chamber 
//   StylePtr<Layers<
//   // Crystal Chamber Color/Styles
//     EffectSequence<EFFECT_SWAP,
//   // Jedi Crystal Blue
//     Cylon<Stripes<1000,-275,RotateColorsX<Variation,Blue>,            RotateColorsX<Variation,Rgb<0,0,128>>,  Black,RotateColorsX<Variation,Rgb<0,0,128>>>,100,1, Stripes<1000,-2000,RotateColorsX<Variation,Blue>,           RotateColorsX<Variation,Rgb<0,0,128>>,  Black>,100,1,500>,
//   // Jedi Crystal Green
//     Cylon<Stripes<1000,-275,RotateColorsX<Variation,Green>,           RotateColorsX<Variation,Rgb<0,128,0>>,  Black,RotateColorsX<Variation,Rgb<0,128,0>>>,100,1, Stripes<1000,-2000,RotateColorsX<Variation,Green>,          RotateColorsX<Variation,Rgb<0,128,0>>,  Black>,100,1,500>,
//   // Jedi Crystal Purple
//     Cylon<Stripes<1000,-275,RotateColorsX<Variation,Rgb<95,0,225>>, RotateColorsX<Variation,Rgb<39,5,71>>,  Black,RotateColorsX<Variation,Rgb<39,5,71>>>,100,1, Stripes<1000,-2000,RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<39,5,71>>,  Black>,100,1,500>,
//   // Jedi Crystal Orange
//     Cylon<Stripes<1000,-275,RotateColorsX<Variation,DarkOrange>,      RotateColorsX<Variation,Rgb<90,24,0>>,  Black,RotateColorsX<Variation,Rgb<90,24,0>>>,100,1, Stripes<1000,-2000,RotateColorsX<Variation,DarkOrange>,     RotateColorsX<Variation,Rgb<90,24,0>>,  Black>,100,1,500>,
//   // Jedi Crystal Yellow
//     Cylon<Stripes<1000,-275,RotateColorsX<Variation,Rgb<180,180,0>>,  RotateColorsX<Variation,Rgb<64,64,0>>,  Black,RotateColorsX<Variation,Rgb<64,64,0>>>,100,1, Stripes<1000,-2000,RotateColorsX<Variation,Rgb<180,180,0>>, RotateColorsX<Variation,Rgb<64,64,0>>,  Black>,100,1,500>,
//   // Jedi Crystal Cyan
//     Cylon<Stripes<1000,-275,RotateColorsX<Variation,Rgb<30,120,150>>, RotateColorsX<Variation,Rgb<11,42,53>>, Black,RotateColorsX<Variation,Rgb<11,42,53>>>,100,1,Stripes<1000,-2000,RotateColorsX<Variation,Rgb<30,120,150>>,RotateColorsX<Variation,Rgb<11,42,53>>, Black>,100,1,500>,
//   // Jedi Crystal Magenta
//     Cylon<Stripes<1000,-275,RotateColorsX<Variation,Rgb<180,30,140>>, RotateColorsX<Variation,Rgb<64,11,49>>, Black,RotateColorsX<Variation,Rgb<64,11,49>>>,100,1,Stripes<1000,-2000,RotateColorsX<Variation,Rgb<180,30,140>>,RotateColorsX<Variation,Rgb<64,11,49>>, Black>,100,1,500>,
//   // Jedi Crystal Indigo
//     Cylon<Stripes<1000,-275,RotateColorsX<Variation,Rgb<80,50,200>>,  RotateColorsX<Variation,Rgb<28,18,71>>, Black,RotateColorsX<Variation,Rgb<28,18,71>>>,100,1,Stripes<1000,-2000,RotateColorsX<Variation,Rgb<80,50,200>>, RotateColorsX<Variation,Rgb<28,18,71>>, Black>,100,1,500>,
//   // Sith Crystal Red
//     Cylon<Stripes<1000,-275,RotateColorsX<Variation,Red>,             RotateColorsX<Variation,Rgb<90,0,0>>,   Black,RotateColorsX<Variation,Rgb<90,0,0>>>,100,1,  Stripes<1000,-2000,RotateColorsX<Variation,Red>,            RotateColorsX<Variation,Rgb<90,0,0>>,   Black>,100,1,500>>,

//     TransitionEffectL<TrConcat<TrFade<600>,Pulsing<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<30,30,160>>,1000>,TrDelay<3000>,RotateColorsX<Variation,Rgb<75,75,255>>,TrFade<800>>,EFFECT_FORCE>,
//     BlastFadeoutL<Rgb<75,75,255>,400>,
//     LockupL<Blinking<White,Rgb<75,75,255>,20,500>,AudioFlicker<Yellow,Blue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<500>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Rgb<75,75,255>,20,500>,TrFade<400>>,EFFECT_CLASH>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<Rgb<75,75,255>,25,20,AlphaL<Red,Int<0>>,100,300,3000>,ColorCycle<Rgb<0,0,80>,25,20,AlphaL<Red,Int<0>>,100,300,3000>,2000>,Black>>>>(),

// // Pommel
//   StylePtr<Layers<
//     Cylon<Stripes<1000,-275,Blue,Rgb<0,0,128>,Black,Rgb<0,0,128>>,100,1,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,Black>,100,1,500>,
//     TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
//     LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrFade<300>,Layers<
//       Mix<IsLessThan<SlowNoise<Int<1500>>,Int<10000>>,Cylon<Stripes<1000,-275,Blue,Rgb<0,0,128>,Black,Rgb<0,0,128>>,100,1,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,Black>,100,1,500>,Black>,
//       PulsingL<Black,Int<1000>>>>>>(),
// "cal\nkestis"},




// // Version 2 of all-in-one preset, using simplified styles for CC, and sequencing colors, not whole style  (since they're identical style)
// {"Fallen;common", "tracks/FallenOrderTracks/JFO3.wav",
//   StylePtr<Layers<
// // Main Blade Base Color/Styles
//       StripesX<Int<16000>,Int<-1000>,
//         RotateColorsX<Variation,EffectSequence<EFFECT_SWAP,Green,Rgb<95,0,225>,DarkOrange,Rgb<180,180,0>,Rgb<30,120,150>,Rgb<180,30,140>,Rgb<80,50,200>,Red,Blue>>,
//         Pulsing<
//           RotateColorsX<Variation,EffectSequence<EFFECT_SWAP,Rgb<0,90,0>,Rgb<39,5,71>,Rgb<90,24,0>,Rgb<64,64,0>,Rgb<11,42,53>,Rgb<64,11,49>,Rgb<28,18,71>,Rgb<90,0,0>,Rgb<0,0,90>>>,
//           RotateColorsX<Variation,EffectSequence<EFFECT_SWAP,Green,Rgb<95,0,225>,DarkOrange,Rgb<180,180,0>,Rgb<30,120,150>,Rgb<180,30,140>,Rgb<80,50,200>,Red,Blue>>,800>,
//         RotateColorsX<Variation,EffectSequence<EFFECT_SWAP,Green,Rgb<95,0,225>,DarkOrange,Rgb<180,180,0>,Rgb<30,120,150>,Rgb<180,30,140>,Rgb<80,50,200>,Red,Blue>>>,
      
// // Main Blade Force Color
//     TransitionEffectL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrFade<500>,
//       RandomFlicker<
//         RotateColorsX<Variation,EffectSequence<EFFECT_SWAP,Green,Rgb<95,0,225>,DarkOrange,Rgb<180,180,0>,Rgb<30,120,150>,Rgb<180,30,140>,Rgb<80,50,200>,Red,Blue>>,
//         RotateColorsX<Variation,EffectSequence<EFFECT_SWAP,Rgb<0,160,0>,Rgb<69,9,125>,Rgb<160,43,0>,Rgb<113,113,0>,Rgb<19,75,94>,Rgb<113,19,88>,Rgb<50,31,125>,Rgb<160,0,0>,Rgb<0,0,160>>>>,TrDelay<3000>,   
//         HumpFlicker<White,Black,50>,TrFade<800>>,EFFECT_FORCE>,
// // Main Blade Swing Color/Styles
//     AlphaL<RotateColorsX<Variation,EffectSequence<EFFECT_SWAP,Rgb<100,255,100>,Rgb<160,60,255>,Rgb<255,178,110>,Rgb<230,180,80>,Rgb<90,180,255>,Rgb<160,60,255>,Rgb<255,100,100>,Rgb<70,70,255>>>, Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//     AlphaL<Black,Int<16384>>,
//     AlphaL<Black,Int<0>>>,
// // Clash 1 - BladeAngle responsive.
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// // Stab 1 - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// // Blast 1
//     // Impact Flash
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//     // Waves
//     BlastL<White,850,250,351>,
//     // Impact point afterimage
//     AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//     // Impact point
//     BlastL<White,500,350,100000>,
// // Lockup - BC custom range mid-blade
//     LockupTrL<Layers<
//       AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//       AlphaL<BrownNoiseFlicker<Yellow,Black,50>,                                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//       TrConcat<TrInstant,
//       AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// // Non-Responsive Drag
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// // Lightning Block Non-Responsive    
//     LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//     Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//     Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//     Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
//     // Begin Lightning Transition
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//     // End Lightning Transition    
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// // Melt    
//     LockupTrL<
//     AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//     // Melt Shape
//     SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//     // Melt Begin and End transitions
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,  // Great melt colors as you twist, gets dripping red hot/fire and bright yellow.
// // Extension and Retraction
//     InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<400>,Int<300>,Int<0>>>,TrWipeInX<Int<700> >>>
//   >(), 

// // // Condensed Crystal Chamber, simpler (Pulsing)....same effect in the end? Even with 4x1515 PCB?
// // Crystal Chamber
//    StylePtr<Layers<
//     RandomFlicker<
//       RotateColorsX<Variation,EffectSequence<EFFECT_SWAP,Green,Rgb<95,0,225>,DarkOrange,Rgb<180,180,0>,Rgb<30,120,150>,Rgb<180,30,140>,Rgb<80,50,200>,Red,Blue>>,
//       RotateColorsX<Variation,EffectSequence<EFFECT_SWAP,Rgb<0,128,0>,Rgb<39,5,71>,Rgb<90,24,0>,Rgb<64,64,0>,Rgb<11,42,53>,Rgb<64,11,49>,Rgb<28,18,71>,Rgb<90,0,0>,Rgb<0,0,128>>>>,
//     TransitionEffectL<TrConcat<TrInstant,
//       HumpFlicker<White,Black,50>,TrFade<500>,
//       Pulsing<
//         RotateColorsX<Variation,EffectSequence<EFFECT_SWAP,Green,Rgb<95,0,225>,DarkOrange,Rgb<180,180,0>,Rgb<30,120,150>,Rgb<180,30,140>,Rgb<80,50,200>,Red,Blue>>,
//         RotateColorsX<Variation,EffectSequence<EFFECT_SWAP,Rgb<0,128,0>,Rgb<39,5,71>,Rgb<90,24,0>,Rgb<64,64,0>,Rgb<11,42,53>,Rgb<64,11,49>,Rgb<28,18,71>,Rgb<90,0,0>,Rgb<0,0,128>>>,1000>,TrDelay<3000>,
//       HumpFlicker<White,Black,50>,TrFade<500>>,EFFECT_FORCE>,
//     BlastFadeoutL<White>,
//     LockupL<Blinking<White,Rgb<60,160,255>,20,500>,AudioFlicker<Yellow,Blue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
//     InOutTrL<
//       TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,
//       TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,
//         Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,
//         Pulsing<
//           RotateColorsX<Variation,EffectSequence<EFFECT_SWAP,Green,Rgb<95,0,225>,DarkOrange,Rgb<180,180,0>,Rgb<30,120,150>,Rgb<180,30,140>,Rgb<80,50,200>,Red,Blue>>,
//           Black,3000>,
//         AlphaL<Black,Int<16384>>>>
//   >>(),

// // Pommel
//   StylePtr<Layers<
//     Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,Black>,
//     TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
//     LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
//     InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<1500>>,Int<3000>>,Pulsing<Stripes<1000,275,Blue,Rgb<0,0,128>,Black,Rgb<0,0,128>>,Black,2000>,AlphaL<Black,Int<16384>>>>
//   >>(),
// "cal\nkestis"},







// { "Comet;common", "", // 10 HumpFlicker tight speckle humps Blade Default = Red Custom preon, in and out...Comet animation
   
//    StylePtr<Layers<// Main Blade
//     // Sith base Red
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Red>,Pulsing<RotateColorsX<Variation,Rgb<90,0,0>>,RotateColorsX<Variation,Red>,800>,RotateColorsX<Variation,Red>>,
//     // Sith Swing Red
//     AlphaL<RotateColorsX<Variation,Rgb<255,100,100>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     // Sith Force Red
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,            RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,   RotateColorsX<Variation,Red>,             TrFade<800>>,EFFECT_FORCE>,

//    //          HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,50,0>>,10>,
// // Dim Blade 50% "Power Save" button combo
//   EffectSequence<EFFECT_POWERSAVE,
//   AlphaL<Black,Int<16384>>,
//   AlphaL<Black,Int<0>>>,
// // Clash 1 - BladeAngle responsive.
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// // Stab 1 - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// // Blast 1
//     // Impact Flash
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//     // Waves
//     BlastL<White,850,250,351>,
//     // Impact point afterimage
//     AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//     // Impact point
//     BlastL<White,500,350,100000>,
// // Lockup - BC custom range mid-blade - Red or Yellow blade alt colors
//     LockupTrL<Layers<
//       AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
//       AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                      Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//       TrConcat<TrInstant,
//       AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Red,Black,500>,Black,15,30>,60,500>, Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,          Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<Red,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// // Non-Responsive Drag
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// // Lightning Block Non-Responsive    
//     LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//     Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//     Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//     Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
//     // Begin Lightning Transition
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//     // End Lightning Transition    
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// // Melt    
//     LockupTrL<
//     AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//   // Melt Shape
//     SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//   // Melt Begin and End transitions
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>, 
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
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),
// // Crystal Chamber
//   StylePtr<Layers<
//     // Sith Crystal Red
//     Cylon<Stripes<1000,-275,RotateColorsX<Variation,Red>,             RotateColorsX<Variation,Rgb<90,90,0>>,   Black,RotateColorsX<Variation,Rgb<90,0,0>>>,100,1,  Stripes<1000,-2000,RotateColorsX<Variation,Red>,            RotateColorsX<Variation,Rgb<90,0,0>>,   Black>,100,1,500>,
//     // Sith Force Red
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,            RotateColorsX<Variation,Rgb<160,160,0>>>,TrDelay<3000>,   RotateColorsX<Variation,Red>,             TrFade<800>>,EFFECT_FORCE>,
//     BlastFadeoutL<Rgb<255,75,75>,400>,
//     LockupL<Blinking<White,Red,20,500>,AudioFlicker<Yellow,Blue>,Int<32768>,Int<32768>,Int<32768>>,
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<500>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Pulsing<BrownNoiseFlicker<Orange,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<Red,25,20,AlphaL<Red,Int<0>>,100,300,3000>,ColorCycle<Rgb<100,0,0>,25,20,AlphaL<Red,Int<0>>,100,300,3000>,2000>,Black>>>>(),
// // Pommel
//   StylePtr<Layers<
//   Cylon<Stripes<1000,-275,Blue,Rgb<0,0,128>,Black,Rgb<0,0,128>>,100,1,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,Black>,100,1,500>,
//   TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
//   BlastFadeoutL<Strobe<GreenYellow,Rgb<100,50,0>,15,30>,400>,
//   LockupTrL<BrownNoiseFlicker<OrangeRed,Yellow,200>,TrConcat<TrInstant,GreenYellow,TrDelay<50>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,Int<32768>>,TrInstant,TrConcat<TrInstant,Strobe<White,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,50,10>,TrFade<1000>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   LockupTrL<AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,Int<32768>>,TrConcat<TrInstant,AlphaL<Blinking<White,BrownNoiseFlicker<Yellow,Black,500>,60,500>,Int<32768>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//   LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,1300>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//   TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
//   InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrFade<300>,Layers<
//     Mix<IsLessThan<SlowNoise<Int<1500>>,Int<10000>>,Cylon<Stripes<1000,-275,Blue,Rgb<0,0,128>,Black,Rgb<0,0,128>>,100,1,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,Black>,100,1,500>,Black>,
//     PulsingL<Black,Int<1000>>>>>>(),
// "comet"},



// { "testfont2", "tracks/track1.wav",
//     StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
//     StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
//     StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
// "testfont2"},



// { "BattLevl;common", "tracks/theforce1.wav",
//  StylePtr<Layers<Black,AlphaL<PulsingX<Mix<BatteryLevel,Red,Green>,Black,Scale<BatteryLevel,Int<500>,Int<4000>>>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>>>(),
// 	StylePtr<Layers<Black,AlphaL<PulsingX<Mix<BatteryLevel,Red,Green>,Black,Scale<BatteryLevel,Int<500>,Int<4000>>>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>>>(),
// 	StylePtr<Layers<Black,AlphaL<PulsingX<Mix<BatteryLevel,Red,Green>,Black,Scale<BatteryLevel,Int<500>,Int<4000>>>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>>>(),
// "battery\nlevel"}



};




//----------------------------------------------------------------------------------------------------------------------------------------
Preset noblade[] = {


{ "a_CAL_KESTIS/The_Survivor/Blue;common", "",
// Hilt PCB
  StylePtr<Layers<
    Cylon<Stripes<1000,-275,Blue,Rgb<0,0,128>,Black,Rgb<0,0,128>>,100,1,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,Black>,100,1,500>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrFade<300>,Layers<
    Mix<IsLessThan<SlowNoise<Int<1500>>,Int<10000>>,Cylon<Stripes<1000,-275,Blue,Rgb<0,0,128>,Black,Rgb<0,0,128>>,100,1,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,Black>,100,1,500>,Black>,
    PulsingL<Black,Int<1000>>>>
  >>(),
// Crystal Chamber 
  StylePtr<Layers<
    // Jedi Crystal Blue
    Stripes<1000,-2000,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>,Black>,
    // Jedi Force Blue
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupL<AudioFlicker<White,Blue>,AudioFlicker<Yellow,SteelBlue>,Int<32768>,Int<32768>,Int<32768>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_LOCKUP_END>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<500>>,EFFECT_DRAG_END>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Blue>,35,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
  // Pommel
  StylePtr<Layers<
    Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,Blue,Pulsing<Rgb<0,0,90>,Blue,800>,Blue>,RotateColorsX<Variation,Black>>,
    TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFade<500>,HumpFlicker<White,Black,50>,TrDelay<300>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<6000,-200,RandomFlicker<Blue,Black>,Black,RandomFlicker<Blue,Rgb<0,0,128>>>,Black>>
  >>(),
// Pommel
//original option glitchy
// StylePtr<Layers<
//   Cylon<Stripes<1000,-275,Blue,Rgb<0,0,128>,Black,Rgb<0,0,128>>,100,1,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,Black>,100,1,500>,
//   TransitionEffectL<TrConcat<TrFade<600>,Stripes<1000,-300,Blue,Rgb<0,0,128>,Black>,TrDelay<3000>,Rgb<80,80,255>,TrFade<800>>,EFFECT_FORCE>,
//   BlastFadeoutL<Strobe<GreenYellow,Rgb<100,50,0>,15,30>,400>,
//   LockupTrL<BrownNoiseFlicker<OrangeRed,Yellow,200>,TrConcat<TrInstant,GreenYellow,TrDelay<50>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,Int<32768>>,TrInstant,TrConcat<TrInstant,Strobe<White,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,50,10>,TrFade<1000>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   LockupTrL<AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,Int<32768>>,TrConcat<TrInstant,AlphaL<Blinking<White,BrownNoiseFlicker<Yellow,Black,500>,60,500>,Int<32768>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//   LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,1300>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//   TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
//   InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrFade<300>,Layers<
//     Mix<IsLessThan<SlowNoise<Int<1500>>,Int<10000>>,Cylon<Stripes<1000,-275,Blue,Rgb<0,0,128>,Black,Rgb<0,0,128>>,100,1,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<10000>>,Stripes<16000,-1000,RotateColorsX<Variation,Blue>,Pulsing<RotateColorsX<Variation,Rgb<0,0,90>>,RotateColorsX<Variation,Blue>,800>,RotateColorsX<Variation,Blue>>,Black>,100,1,500>,Black>,
//     PulsingL<Black,Int<1000>>>>>>(),
"cal\nkestis"},


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



BladeConfig blades[] = {
{ 0,          // 131 pixels. BC B
  WS281XBladePtr<131, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ,                                  // Main Blade and HiltPCB
  WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >() ,                                                   // Crystal Chamber 
  WS281XBladePtr<8, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                    // Pommel
CONFIGARRAY(Cal_Kestis), 
"01_Cal_Kestis"}, 

{ NO_BLADE, 
  WS281XBladePtr<131, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ,                                  // Main Blade and HiltPCB
  WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >() ,                                                   // Crystal Chamber 
  WS281XBladePtr<8, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                    // Pommel
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
