// BC_Scoundrel_6.x_CONSTANT_BLADEID_TEST

#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 1
// #define DUAL_POWER_BUTTONS   ****not working fully, only power     // BC Make both buttons identical for 1-btn use... useful?

// ------ Audio Stuff --------

#define VOLUME 2000
#define BOOT_VOLUME 30
// -------------------- defaulted #define ENABLE_AUDIO
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                    // SPDIF out
 #define FILTER_CUTOFF_FREQUENCY 100
 #define FILTER_ORDER 8
// #define FEMALE_TALKIE_VOICE                        // BC now canon OS6
// -------------------- defaulted #define NO_REPEAT_RANDOM                          // BC now canon
// -------------------- defaulted #define KILL_OLD_PLAYERS                          // BC now canon
// #define DISABLE_TALKIE                            // I feel I'm not gonna like this

// ------ Blade Stuff ------

// -------------------- defaulted #define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet.Equivalent to just indrasing maxLedsPerStrip.
// #define EXTRA_COLOR_BUFFER_SPACE 30

// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000> // resistor value used

// BridgedPullupBladeID is the default Proffieboard V3 BLADE_ID_CLASS, so it doesn't need to be defined explicitly with a V3.
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9> // TX pad for example

/*  SnapshotBladeID is the default Proffieboard V1.5 and V2.2 BLADE_ID_CLASS, so it doesn't need to defined explicitly.
    It will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value,
    so using something like 200000 instead of NO_BLADE is best. */
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin>

/*
-- Real Time Blade ID
 
Main blade must be wired to data1
Have a Presets array for each blade,
and match those names to the CONFIGARRAY for the given blade.
Arrays should be named differently like blade_1, blade_2, no_blade etc...
Blades can use the same set of presets, or different ones for different blades.

Open Serial Monitor in Arduino and type `scanid` to get read value.
Use that value in the blade definition in the BladeConfig.
* Note * It is recommended to use a Blade ID resistor in each blade 
to ensure different resistance vales between blades. 
However, in testing, values reported for a chassis alone,
chassis inserted into the hilt (connected to emitter PCB)
and then main blade inserted all gave different enough values on their own
without added resistors that it worked fine. YMMV.
*/
//    Blanket define to cover the following 4
#define REAL_TIME_BLADE_ID_POWER_PINS 2, 3
                //    Use with Blade ID. Specify the LED pad(s) that the main blade uses.
                // #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>

                //    Required when blades on different data pads use common LED power pads.
                //    and/or when BLADE_ID_SCAN_MILLIS is used with Blade ID.
                // #define SHARED_POWER_PINS

                //    Choose how often to check for new blade (milliseconds).
                //    Larger values will be a longer delay before a blade is recognized.
                // #define BLADE_ID_SCAN_MILLIS 1000
                //    How many Blade ID scans to average (default is 10, 15 works well)
                // #define BLADE_ID_TIMES 15

                // Not blanketed. This will make the blade ID class for that Measured value range to return as NO_BLADE (use NO_BLADE as the blade definition value.)
                #define NO_BLADE_ID_RANGE 685000,1000000000

//    Requires wiring a pad to a switched GND
//    (floating pogo pin until grounded via blade-side PCB ring)
// #define BLADE_DETECT_PIN 10 

// ------ SD Card Stuff -------

// -------------------- defaulted #define ENABLE_SD
//#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
     #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//    Upload overwrites presets.ini/tmp unless this is defined
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING

// ------- OLED stuff ----------

// #define ENABLE_SSD1306                         // OLED display. also defines ENABLE_DISPLAY_CODE
// #define OLED_FLIP_180                          // BC now canon
// #define USE_AUREBESH_FONT                      // BC now canon
// #define OLED_SYNCED_EFFECTS
// #define PLI_OFF_TIME 60 * 5 * 1000
// #define OLED_USE_BLASTER_IMAGES
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144_SC_POV_data.h"
// #define POV_INCLUDE_FILE "Raiden_123_FC_POV_data.h"
// #define POV_INCLUDE_FILE "JohnCena_144_8b_POV_data.h"

// ------ System Stuff --------

// #define ENABLE_DEBUG
// #define PROFFIEOS_LOG_LEVEL 400
// PVLOG_ERROR 100 = errors
// PVLOG_STATUS 200 = things you should probably know, like blade ID
// PVLOG_NORMAL 300 = normal information about what is happening (default level)
// PVLOG_DEBUG 400 = information helpful for debugging
// PVLOG_VERBOSE 500 = repeated, spammy information you don't normally want

// #define NO_BATTERY_MONITOR
#define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
// #define COLOR_CHANGE_DIRECT
// #define ENABLE_DEVELOPER_COMMANDS
// #define DISABLE_DIAGNOSTIC_COMMANDS
//    Standard, Advanced, Old School original templated styles etc...
#define DISABLE_BASIC_PARSER_STYLES
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_CCW_FROM_BLADE
// #define ORIENTATION ORIENTATION_USB_CW_FROM_BLADE
//    The following changes the angle required to register twists on curved hilts.
//    Example is for Assaj Ventress curved hilt install.
// #define ORIENTATION_ROTATION 0,-20,0

// #define CONFIG_STARTUP_DELAY 15000               // BC now canon

// ------- Motion and Gesture stuff -------

// -------------------- defaulted #define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_SPINS
#define BC_SWING_ON
#define BC_SWING_ON_SPEED 250
// #define BC_STAB_ON
#define BC_THRUST_ON
//#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                     // BC Multiblast continues as long as swinging within 1 second. 
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
// #define NO_BLADE_NO_GEST_ONOFF                   // If using blade detect, No Blade = No Gesture ignitions or retractions

// ------- Custom / Experimental / Alpha-Beta stuff ---------

// #define OPTIMIZE_TRCONCAT                       // this TRCONCAT can save some RAM, but it's not compatible with IntArg/RgbArg
#define DIAGNOSTIC_STARTUP_DELAY_FOR_SERIAL_MONITOR // BC 3000ms delay to catch all messages.

// -------- BC Prop Other Stuff --------
// #define BC_DUAL_BLADES
// #define NO_VOLUME_MENU                           // self evident. But why?

// -------- Blaster Stuff ----------

// #define ENABLE_BLASTER_AUTO
// #define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
// #define BLASTER_JAM_PERCENTAGE 10     // if not defined, random.

// -------- Fett263 Stuff ----------
// #define ENABLE_ALL_MENU_OPTIONS
    //#define DYNAMIC_BLADE_DIMMING
    //#define DYNAMIC_CLASH_THRESHOLD
    //#define SAVE_VOLUME
    //#define SAVE_BLADE_DIMMING
    //#define SAVE_CLASH_THRESHOLD
    //#define SAVE_COLOR_CHANGE

#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons.h"
#endif

#ifdef CONFIG_PRESETS
// #include "aliases/TrueWhites/BC_effects_1.h"              // For Red, Green, light Blue, ...light colored blades
// #include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"  // EffectSequence driven different blast animations
// #include "aliases/TrueWhites/BC_effects_2.h"              // for crystals chambers or accents
// #include "aliases/TrueWhites/BC_effects_Red.h"            // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_Red_Main.h"             // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_Red_Alt.h"              // For Red or dark blades
// #include "aliases/TrueWhites/BC_effects_White.h"          // For White blades
// #include "aliases/TrueWhites/BC_12color_8effect_SS.h"     // All in one blade style from CC Fork. SS = SwingSpeed included 

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;


Preset blade_array_1 [] = {

{ "blade1;testfont2b;common;commonBU", "",
  // Blade 2
/* Dual Blade */ 
StylePtr<Layers<
/* Used to toggle Dual Blade on-off. Int<100> could be anything up to 16383 */
    Mix<IsGreaterThan<EffectIncrementF<EFFECT_USER4,Int<32768>,Int<16384>>,Int<100>>,

/* off layers */
  Layers<
    Black,
    // pseudo EFFECT_RETRACTION
    TransitionEffectL<TrConcat<TrInstant,
/* This color should be the same as the main blade base color layer. Shown instantly and wipes to black */
// -------------------
    Mix<SwingSpeed<300>,StaticFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,10,1000,2>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>>,
// -------------------
    TrWipeInX<BendTimePowX<WavLen<>,Int<180000>>>>,EFFECT_USER4>,
/* EFFECT_RETRACTION effects from the style can be added as well, just use EFFECT_USER4 instead */
    // Retraction Emitter flare.
    TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,50>>,TrFadeX<Percentage<WavLen<>,30>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrInstant>,EFFECT_USER4>
  >,  // off layers

/* on layers */
/* main blade base color and effects down to, but not including, the InOutTrL, and minus any  EFFECT_RETRACTION layers.
   EFFECT_IGNITION effects can be added as well, just use EFFECT_USER4 instead
   The effects layers in here might want to be limited by BladeAngle<> to only show on the blade that is is above the horizon line. */
  Layers<
// ------------------
    Mix<SwingSpeed<300>,StaticFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,10,1000,2>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>>,
    BC_effects_Red_Alt,

/* pseudo EFFECT_IGNITION */
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_USER4>,
// ------------------
/* In-Out extension wipe mimicking */
    TransitionEffectL<TrConcat<TrInstant,Black,TrWipeX<BendTimePowInvX<WavLen<>,Int<196608>>>>,EFFECT_USER4>
  >  // on layers
>,  // Mix
    InOutTrL<
/* In-Out: Nothing to do here. Showing Black base in Off Layers */
    TrInstant,
/* Give time to let Pseudo Retraction Finish if dual blade left on and POW button used for Off() */
    TrDelayX<WavLen<EFFECT_RETRACTION>>
    >
  >>(),

  StylePtr<ColorCycle<Blue,20,50,Blue,20,100,1000>>(), // PCB

 // Blade 1
//   StylePtr<Layers< // Switches
//     Mix<SwingSpeed<300>,StaticFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,10,1000,2>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>>,
//     BC_effects_Red_Main,
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,50>>,TrFadeX<Percentage<WavLen<>,30>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,30>>>,EFFECT_IGNITION>,
// // Non spark tip version, Wavlen for both in and out
//     InOutTrL<
//       TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
//       TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
StylePtr<Layers<
    Mix<SwingSpeed<300>,StaticFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,10,1000,2>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>>,
    // ResponsiveLockupL<White,TrInstant,TrFade<100>,Int<26000>>,
    // ResponsiveLightningBlockL<White>,
    // ResponsiveMeltL<Mix<TwistAngle<>,Red,Yellow>>,
    // ResponsiveDragL<White>,
    // ResponsiveClashL<White,TrInstant,TrFade<200>,Int<26000>>,
    // ResponsiveBlastL<White>,
    // ResponsiveBlastWaveL<White>,
    // ResponsiveBlastFadeL<White>,
    // ResponsiveStabL<White>,
    TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,50>>,TrFadeX<Percentage<WavLen<>,30>>,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,30>>>,EFFECT_IGNITION>,
    InOutTrL<
      TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<196608>>>,
      TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>
  >>(),


  StylePtr<Blue>(), // Pommel static blue 3mm LED
  StylePtr<Blue>(), // Bluetooth
"*********** blade_array_1 INSERTED"}

};
//----------------------------------------------------------------------------------------------------------------------------------------

Preset blade_array_2 [] = {

{ "blade2;Dooku_CW;common;commonBU", "", // 40000
  StylePtr<Green>(),
  StylePtr<ColorCycle<Green,20,50,Green,20,100,1000>>(),
  StylePtr<Green>(),
  StylePtr<Blue>(), // Pommel static blue 3mm LED
  StylePtr<Blue>(), // Bluetooth
"*********** blade_array_2 INSERTED"}

};
//----------------------------------------------------------------------------------------------------------------------------------------

Preset blade_array_0 [] = {

// { "blade0;testfont2b;common;commonBU", "",
//   StylePtr<Layers<
//     Blue,
//     InOutTrL<TrWipeX<WavLen<>>,TrWipeIn<500>>>>(),
//   StylePtr<ColorCycle<Blue,20,50,Blue,20,100,1000>>(),
//   StylePtr<Blue>(),
//   StylePtr<Blue>(), // Pommel static blue 3mm LED
//   StylePtr<Blue>(), // Bluetooth
// "*********** NO BLADE INSERTED"},


{ "blade0;Savant01;common;commonBU", "aa_JayDalorian/nobunaga/tracks/sharingan.wav",
  StylePtr<Red>(),
  StylePtr<ColorCycle<Red,20,50,Red,20,100,1000>>(),
  StylePtr<Red>(),
  StylePtr<Blue>(), // Pommel static blue 3mm LED
  StylePtr<Blue>(), // Bluetooth
"*********** NO BLADE INSERTED"},


{ "blade0;a_Dooku/Duke;common;commonBU", "",
  StylePtr<Blue>(),
  StylePtr<ColorCycle<Blue,20,50,Blue,20,100,1000>>(),
  StylePtr<Blue>(),
  StylePtr<Blue>(), // Pommel static blue 3mm LED
  StylePtr<Blue>(), // Bluetooth
"*********** NO BLADE INSERTED"}

};
//----------------------------------------------------------------------------------------------------------------------------------------

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


{ NO_BLADE, // use for Blade Detect..testing for blade ID as well.
 // { 750000, // use for Blade ID
// { 1000000, // use for Blade ID (alternate?)
  WS281XBladePtr<0, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(blade_array_0)}, 

{ 300000,
  WS281XBladePtr<100, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(blade_array_1)}, 


{ 575000,
  WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                    // HiltPCB
  WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                                                   // Switches
  SimpleBladePtr<AccentsLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),                                              // Pommel
  SimpleBladePtr<CH3LED, NoLED, NoLED, NoLED, bladePowerPin6, -1, -1, -1>(),                                                  // Bluetooth
CONFIGARRAY(blade_array_2)}, 




};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
