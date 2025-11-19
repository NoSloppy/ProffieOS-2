// BC_Pariahs_7.x.h

#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 1

// ------ Audio Stuff --------

#define VOLUME 2000
#define BOOT_VOLUME 200
#define ENABLE_AUDIO
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                    // SPDIF out
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
#define FEMALE_TALKIE_VOICE                        // BC now canon OS6
#define NO_REPEAT_RANDOM                          // BC now canon
#define KILL_OLD_PLAYERS                          // BC now canon
// #define DISABLE_TALKIE                            // I feel I'm not gonna like this

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet.Equivalent to just indrasing maxLedsPerStrip.
// #define EXTRA_COLOR_BUFFER_SPACE 30

// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000> // resistor value used

// BridgedPullupBladeID is the default Proffieboard V3 BLADE_ID_CLASS, so it doesn't need to defined explicitly with a V3.
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9> // TX pad for example

/*  SnapshotBladeID is the default Proffieboard V1.5 and V2.2 BLADE_ID_CLASS, so it doesn't need to defined explicitly.
    It will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value,
    so using something like 200000 instead of NO_BLADE is best. */
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin>

/*
-- BladeID with constant monitoring --
 
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
// #define REAL_TIME_BLADE_ID_PINS 2, 3 // BC custom ProffieOS.ino addition. Blanket define.
  //    Use with Blade ID. Specify the LED pad(s) that the main blade uses.
  // #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>

  //    Required when blades on different data pads use common LED power pads.
  //    and/or when BLADE_ID_SCAN_MILLIS is used with Blade ID.
#define SHARED_POWER_PINS

  //    Choose how often to check for new blade (milliseconds).
  //    Larger values will be a longer delay before a blade is recognized.
  // #define BLADE_ID_SCAN_MILLIS 1000
  //    How many Blade ID scans to average (default is 10, works well)
  // #define BLADE_ID_TIMES 15

//    Add this when using dual_prop, and make sure the blaster preset (no blade) is first in the config file.
//    Can be used with Blade Detect or Blade ID (including Real Time Blade ID)
// #define DUAL_PROP_CONDITION (current_config != blades)

// Requires wiring a pad to a switched GND
// (floating pogo pin until grounded via blade-side PCB ring)
    #define BLADE_DETECT_PIN blade3Pin

// ------ SD Card Stuff -------

#define ENABLE_SD
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

// #define DIAGNOSTIC_STARTUP_DELAY_FOR_SERIAL_MONITOR
// #define ENABLE_DEBUG
 // #define PROFFIEOS_LOG_LEVEL 400
// PVLOG_ERROR 100 = errors
// PVLOG_STATUS 200 = things you should probably know, like blade ID
// PVLOG_NORMAL 300 = normal information about what is happening (default level)
// PVLOG_DEBUG 400 = information helpful for debugging
// PVLOG_VERBOSE 500 = repeated, spammy information you don't normally want

// #define NO_BATTERY_MONITOR
// #define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
// #define ENABLE_DEVELOPER_COMMANDS
#define DISABLE_DIAGNOSTIC_COMMANDS
//    Disable Old School original templated styles, like StyleNormalPtr<CYAN, WHITE, 300, 800>()
#define DISABLE_BASIC_PARSER_STYLES
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_CCW_FROM_BLADE
// #define ORIENTATION ORIENTATION_USB_CW_FROM_BLADE

// #define ORIENTATION_ROTATION 0,20,0 // -20 is USB  leaning down
// For Curved hilts, or where the board is not parallel with the blade. For Twist on/off particularly.
//This will rotate the orientation of the board 20 degrees around the Y axis.
// Depending on the orientation of the board, you might need -20 degrees instead. (Or 15 degrees? or 30?)
//    Example is for Assaj Ventress curved hilt install.
// #define ORIENTATION_ROTATION 0,-30,0

// #define CONFIG_STARTUP_DELAY 15000               // BC now canon

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3.5
#define BC_SWING_ON
#define BC_SWING_ON_SPEED 250
// #define BC_STAB_ON
#define BC_THRUST_ON
//#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                     // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS
// #define ENABLE_AUTO_SPINS_BLAST       // *** DEAD **** Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
// #define NO_BLADE_NO_GEST_ONOFF                   // If using blade detect, No Blade = No Gesture ignitions or retractions

// ------- Custom / Experimental / Alpha-Beta stuff ---------

// #define LOW_BATT_ONCE                            // BC - THIS NEEDS TO BE CheckLowBattry(), see PR     **Requires modified hybrid_font.h file.
// #define LOW_BATT_WARNINGS_TIERED                 // meh...just annoying if not accurate..likely.       **Requires modified hybrid_font.h file.
// #define ENABLE_GESTURE_MENU                      // PSISTORM prop - cool stuff! the TrySound else beep void.
// #define OPTIMIZE_TRCONCAT                       // this TRCONCAT can save some RAM, but it's not compatible with IntArg/RgbArg

// -------- BC Prop Other Stuff --------

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
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"
#include "aliases/TrueWhites/BC_effects_Red.h"
#include "aliases/TrueWhites/BC_effects_White.h"
#include "aliases/TrueWhites/BC_12color_8effect_SS.h"

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

/* --- Presets List --- /*

a_ASAJJ/NiteSist
a_ASAJJ/Ventress
a_DOOKU/Duke
a_SAVAGE/Savage_Night
a_SAVAGE/SavageKsith
a_INQUISITOR/2ndSistr
aa_LordBlako/AchluSS
BlakStar
Knighthood
aa_SyntheticEpiphany/Balanced_Entropy
a_DARTH_MAUL/FirstApprentice
Nextor
aa_LordBlako/PitchBlk
Proto1
a_SIDIOUS/SenateMajority2
aa_CFX/SHATTERPOINT
a_STARKILLER/Strkllr1
a_VADER/RogueVader
VnlaDark
aa_JayDalorian/Nexus
aa_Greyscale/Anomaly_Greyscale
aa_NoSloppy/Crushed
*/

Preset AllBlades [] = {

{ "a_ASAJJ/NiteSist;common;commonBU", "tracks/Sister1.wav", 
  StylePtr<Layers<
    HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"night\nsister"},



{ "a_ASAJJ/Ventress;common;commonBU", "tracks/Sister1.wav", 
  StylePtr<Layers<
    HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"ventress"},



{ "a_DOOKU/Duke;common;commonBU", "a_DOOKU/tracks/Duke1_Short.wav",// Matched Preons/outs
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"dooku"},



{ "a_SAVAGE/Savage_Night;common;commonBU", "tracks/Sister2_short.wav", // Real Flame

  StylePtr<Layers<
    Layers<
    Mix<SmoothStep<Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<36000>,Scale<BladeAngle<>,Int<10924>,Int<54000>>>,Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<-1>,Scale<BladeAngle<>,Int<-10000>,Int<-1>>>>,Black,Remap<Scale<RampF,Int<0>,Scale<IsLessThan<BladeAngle<>,Int<15000>>,Int<32768>,Scale<BladeAngle<0,15000>,Int<60000>,Int<32768>>>>,Layers<
    Mix<BladeAngle<>,StaticFire<Gradient<RotateColorsX<Variation,Rgb<255,75,0>>,RotateColorsX<Variation,Rgb<255,50,0>>,RotateColorsX<Int<400>,Red>,Red>,Mix<Int<16384>,Black,Red>,0,2,0,1800,10>,StaticFire<Gradient<RotateColorsX<Variation,Rgb<255,75,0>>,RotateColorsX<Int<1200>,Red>,RotateColorsX<Int<600>,Red>,Red>,Mix<Int<16384>,Black,Red>,0,4,0,2200,2>>>>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
  // standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
  // bend
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"savage\nopress"},



{ "a_SAVAGE/SavageKsith;common;commonBU", "tracks/Sister2.wav",
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,Black>,300>,RotateColorsX<Variation,Rgb<40,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,AudioFlicker<RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Rgb<20,0,0>>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Red>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Red,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<100,200,255>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// Emitter cooldown
    TransitionEffectL<TrConcat<TrInstant,
      AlphaL<Rgb<100,200,255>,Bump<Int<0>,Int<6000>>>,TrFadeX<  Int<1875> >,
      AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFadeX<  Int<1875> >,
      AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX< Int<3750> >>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"savage\nksith"},



{ "a_INQUISITOR/2ndSistr;common;commonBU", "tracks/FallenOrderTracks/JFO5.wav",
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"second\nsister"}, 



{ "aa_LordBlako/AchluSS;common;commonBU", "tracks/Sister1.wav", 
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"achluophobia"},



{ "BlakStar;common;commonBU", "tracks/Sister1.wav", 
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"blakstar"},



{ "Knighthood;common;commonBU", "tracks/mars.wav",
  StylePtr<Layers<
    Mix<SwingSpeed<400>,HumpFlicker<RotateColorsX<Variation,Rgb<50,20,255>>,RotateColorsX<Variation,Rgb<20,0,120>>,5>,HumpFlicker<White,RotateColorsX<Variation,Rgb<50,20,255>>,10>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"knighthood"},



{ "aa_SyntheticEpiphany/Balanced_Entropy;common;commonBU", "", 
StylePtr<Layers<
  HumpFlicker<Rgb<125,30,255>, Rgb<60,0,255>,50>,
TransitionEffectL<TrConcat<TrInstant,StaticFire<RotateColorsX<Variation,Rgb<120,40,255>>,White,0,6,10,1000,0>,TrSmoothFade<1600>>,EFFECT_IGNITION>,
  BC_effects_Red,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Red>>,TrFade<1200>>,EFFECT_RETRACTION>,

// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
TransitionEffectL<TrConcat<TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Red>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,OrangeRed>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Tomato>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Yellow>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Red>,30>,SmoothStep<Int<6000>,Int<-500>>>,TrDelay<5100>>,EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"balanced\nentropy"},



{ "a_DARTH_MAUL/FirstApprentice;common;commonBU", "a_DARTH_MAUL/tracks/Maul_Solo_Theme.wav", // AudioFlicker Red Base Color Wheel Changeable
   
  StylePtr<Layers<
    AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
    BC_effects_Red, 
// standard
    // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"darth\nmaul"},



{ "Nextor;common;commonBU", "tracks/StarWarsTheme.wav", 
  StylePtr<Layers<
    Mix<SwingSpeed<400>,AudioFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<128,34,0>>>,Mix<SwingSpeed<600>,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Orange>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"nextor"}, 


{ "aa_LordBlako/PitchBlk;common;commonBU", "tracks/MSV.wav",
//Second Sister Base Red
  StylePtr<Layers<
    Mix<SwingSpeed<300>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,Black>,300>,RotateColorsX<Variation,Rgb<40,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,AudioFlicker<RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Rgb<20,0,0>>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Red>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Red,50>,TrFade<1000>>,EFFECT_IGNITION>,
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<100,200,255>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// Emitter cooldown
    TransitionEffectL<TrConcat<TrInstant,
      AlphaL<Rgb<100,200,255>,Bump<Int<0>,Int<6000>>>,TrFadeX<  Int<1875> >,
      AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFadeX<  Int<1875> >,
      AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX< Int<3750> >>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Black>(),
"pitch\nblack"},

{ "Proto1;common;commonBU", "tracks/venus.wav",
    // Fully Responsive Kylo Ren Unstable (Unstable Swing) Styles - Jedi Silver - OS4.x
StylePtr<InOutTr<Layers<
  Blast<Mix<SwingSpeed<310>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<7,7,15>>,RotateColorsX<Variation,Rgb<17,17,36>>>,300>,RotateColorsX<Variation,Rgb<22,22,47>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<7,7,15>>,300>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<10,0,0>>>,0,8,FireConfig<10,1200,1>,FireConfig<0,0,0>,FireConfig<2,1000,5>,FireConfig<100,0,5>>>,TransitionEffect<GreenYellow,White,TrWipe<1>,TrWipe<150>,EFFECT_BLAST>,400,250,800>,
  ResponsiveStabL<Orange>,
  TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,
  ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,White,TrFade<200>>,TrFade<400>>,
  ResponsiveDragL<BrownNoiseFlickerL<White,Int<300>>,TrWipeIn<400>,TrFade<400>>,
  ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
  ResponsiveMeltL<Mix<TwistAngle<>,OrangeRed,Orange>,TrWipeIn<600>,TrSmoothFade<600>>,
  AlphaL<TransitionEffect<White,Rgb<128,0,0>,TrInstant,TrConcat<TrFade<1500>,Red,TrFade<2000>,Orange,TrFade<2500>>,EFFECT_IGNITION>,Bump<Int<0>,Int<6000>>>,
  TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<800>>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>>,TrWipe<300>,TrWipeIn<500>,Layers<
  Black,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<800>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<800>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<800>>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>>(),
    StylePtr<Black>(),
"proto 1"},



  { "a_SIDIOUS/SenateMajority2;common;commonBU", "tracks/Palpatheme_SHORT.wav",      // Troy Huang Palpatine / Sidiuos
  StylePtr<Layers<
    Mix<SwingSpeed<500>,AudioFlicker<Gradient<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red>,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,
    BC_effects_Red,       
      InOutTrL<TrConcat<TrWipe<200>,Strobe<Black,Rgb<100,100,155>,45,60>,TrJoinR<TrSmoothFade<190>,TrWipe<200>>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"senate\nmajority2"},



{ "aa_CFX/SHATTERPOINT;common;commonBU", "tracks/mars.wav",
// HarrySolo/AGONY
  StylePtr<Layers<
    HumpFlicker<Blue,Stripes<22000,-100,RotateColorsX<Variation,Rgb<48,0,105>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<22,0,49>>>,10>,
    BC_effects_Red,
    InOutTrL<TrJoin<TrWipeX<Int<600>>,TrWaveX<White,Int<1200>,Int<400>,Int<600>,Int<0>>>,
             TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,150>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
     
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<200>>,EFFECT_IGNITION>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,10>,Bump<Int<0>,Int<4000>>>,TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,15>,Bump<Int<0>,Int<5000>>>,TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,20>,Bump<Int<0>,Int<6000>>>,TrFade<1000>>,EFFECT_PREON>,Ifon<Int<0>,Int<32768>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"shatter\npoint"},


{ "a_STARKILLER/Strkllr1;common;commonBU", "tracks/Starkillers_Theme.wav", // 666 in
  StylePtr<Layers<
    AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
        // Ice Force
    TransitionEffectL< 
      TrConcat<TrFade<7000>,Rgb<10,0,75>,// blade turns solid cold 1000ms before ice full coverage
      TrDelay<1000>>,EFFECT_USER2>,  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to Base color
    TransitionEffectL< TrConcat<TrWipe<8000>, //wipe in stripes ice freezing effect
    TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>,TrFade<11500>,TrDelay<20000>,EFFECT_USER2>, // Stripes fade to solid over remaining 4 seconds from freezing edge's finish until 12000 then hold for next joined delay to end at 15000, so 3000 more.
      TrDelay<7000>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>, //after 15000 (TrConcat makes it 8000 + 7000) from effect start, full blade to this shade of white for wiping away (seamless color from end of stripes fade to solid)
      TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>, // wipe ice away and melt to thinner opacity , but not 100%, leave like 30% by using longer fade duration than the wipe takes. 
    TransitionEffectL<TrConcat<
      TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,     Int<400>,  Int<50>, Int<1000>,Int<0>>,    // burst
        TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,      Int<15000>,Int<400>,Int<8000>,Int<0>>,         // leading freeze edge
        TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,    // crystalizing in edge's wake
    AlphaL<Rgb<100,200,255>,Int<0>>,
      TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,    Int<300>,  Int<50>, Int<1000>,Int<0>>,  // burst
        TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>, // crystalizing in thaw's path
        TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,     Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>, // leading thawing edge
    // Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
        AlphaL<Black,Int<16384>>,
        AlphaL<Black,Int<0>>>,
    // Clash 2 - for red blades
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
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
        //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<2>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
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
       //Random Strobe Flash and 16000 = 50% Base blade dimming to make lb pop
        AlphaL<Black,Int<16000>>,
        AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
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
// standard
    // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"starkiller"},



{ "a_VADER/RogueVader;common;commonBU", "tracks/Imperial March ROTJ 3_long.wav",

    StylePtr<Layers<
        AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
        BC_effects_Red,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
 StylePtr<Black>(),
"rogue\nvader"}, 



{ "VnlaDark;common;commonBU", "tracks/FallenOrderTracks/JFO8.wav",  
  StylePtr<Layers<
// Main Blade
    // Jedi base Purple
    StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<95,0,225>>,Pulsing<RotateColorsX<Variation,Rgb<39,5,71>>,RotateColorsX<Variation,Rgb<95,0,225>>,800>,RotateColorsX<Variation,Rgb<95,0,225>>>,
    // Jedi Force Purple
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<95,0,225>>,RotateColorsX<Variation,Rgb<69,9,125>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<95,0,225>>,TrFade<800>>,EFFECT_FORCE>,
    // Jedi Swing Purple
    AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
BC_effects_1,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
    StylePtr<Black>(),
"vanilla\ndark"},



{ "aa_JayDalorian/Nexus;common;commonBU", "", // Ice Stab and scanning Force
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<30,0,66>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<7,0,16>>,RotateColorsX<Variation,Rgb<95,0,210>>>,
    BC_effects_White,
    TransitionEffectL<TrConcat<TrFade<400>,RotateColorsX<Variation,Rgb<160,60,255>>,TrDelay<7000>,RotateColorsX<Variation,Rgb<160,60,255>>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Stripes<6,-1600,Mix<Sin<Int<30>>,White,White>,Mix<Sin<Int<30>>,White,White>,Mix<Sin<Int<26>>,White,White>,Mix<Sin<Int<24>>,White,White>>,Bump<Scale<SwingSpeed<400>,Int<1000>,Int<34000>>,Int<20000>>>,TrDelay<7000>>,EFFECT_FORCE>,
   
    TransitionEffectL<TrConcat<TrFade<3000>,RotateColorsX<Variation,Rgb<95,0,210>>,TrDelay<5000>,RotateColorsX<Variation,Rgb<95,0,210>>,TrFade<3000>>,EFFECT_STAB>,
    TransitionEffectL<TrConcat<TrWipe<3000>,TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Rgb<100,150,230>,TrFade<3000>,TrDelay<3000>,EFFECT_STAB>,TrDelay<3000>,Rgb<100,150,230>,TrWipe<3000>>,EFFECT_STAB>,
    TransitionEffectL<TrConcat<TrWaveX<BrownNoiseFlicker<White,SteelBlue,60>,Int<3000>,Int<400>,Int<3000>,Int<0>>,AlphaL<White,Int<0>>,TrDelay<3000>,AlphaL<White,Int<0>>,TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,Int<10000>,Int<400>,Int<3000>,Int<0>>>,EFFECT_STAB>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RandomPerLEDFlickerL<White>,SmoothStep<Int<6000>,Int<-4000>>>,TrDelayX<WavNum<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrColorCycle<1000,0>,GhostWhite,TrFade<100>>,EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
 StylePtr<Black>(),
"nexus"},



{ "aa_Greyscale/Anomaly_Greyscale;common;commonBU", "", // ***** retraction stuck
  StylePtr<Layers<
    //Base Fett263 Silver Humpflicker
    HumpFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<50,50,75>>,50>,
    //Unstable Bright Audioflicker Swing Effect
    AlphaL<AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Black,50>,RotateColorsX<Variation,Rgb<65,50,75>>>,SwingSpeed<285>>,
    //Fett263 Bright Sparking Emitter Flare
    AlphaL<RotateColorsX<Variation,Rgb16<16975,9110,65535>>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1500>,Int<4500>>,Int<-6000>>>,
    BC_effects_White,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RandomPerLEDFlickerL<White>,SmoothStep<Int<6000>,Int<-4000>>>,TrDelayX<WavNum<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrColorCycle<1000,0>,GhostWhite,TrFade<100>>,EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
 StylePtr<Black>(),
"anomaly\ngreyscale"},




{ "aa_NoSloppy/Crushed;common;commonBU", "",
// NoSloppy 06/2022
StylePtr<Layers<
  BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
  Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>,
  AlphaL<StaticFire<Black,BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,600>,0,4,2,4000,0>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<500>,Int<-19300>,Int<32768>>,Int<0>>>,
  BC_effects_Red,
  // Ignition and Retraction effect
  // InOutTrL<TrJoin<TrWipeX<BendTimePowX<Int<1300>,Int<16384>>>,TrSparkX<White,Int<400>,BendTimePowX<Int<1300>,Int<16384>>,Int<0>>>,
  //                 TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<150000>>>>,
  InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,
                    TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // Postoff Emitter Cooldown
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb16<22863,5695,53231>,Bump<Int<0>,Int<3500>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Rgb<100,0,0>,Bump<Int<0>,Int<1000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
  // Preon effects - auto matched to which wav file is chosen
 AlphaL<ColorSelect<WavNum<EFFECT_PREON>,TrInstant,
  Layers<
    TransitionEffectL<TrConcat<TrDelay<200>,AlphaL<Black,Int<0>>,TrFade<1300>,Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<180,0,0>>,RotateColorsX<Variation,Rgb<15,0,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>>,RotateColorsX<Variation,Rgb<40,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<36,0,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<180,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<90,0,0>>,RotateColorsX<Variation,Rgb<5,2,0>>,3000>>,
    AlphaL<StyleFire<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<2,1,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>>,TrDelay<1000>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrFade<1500>,SparkleL<ColorSelect<Sin<Int<1>,Int<68>>,TrFade<300>,Red,Rgb16<22863,5695,53231>,White>,200,500>,TrDelay<1000>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<Black,Int<0>>,TrFade<800>,AlphaL<StaticFire<Black,Rgb16<22863,5695,53231>,0,3,0,6000>,Bump<Int<0>,Int<5000>>>,TrInstant,AlphaL<AlphaL<White,NoisySoundLevelCompat>,Bump<Int<0>,Int<25000>>>,TrDelay<700>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<Black,Int<0>>,TrFade<700>,AlphaL<StaticFire<Black,Rgb16<22863,5695,53231>,0,3,0,3000>,Int<16000>>,TrDelay<700>>,EFFECT_PREON>>,
  Layers<
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<5000>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<9830>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<14745>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<19660>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<24576>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<29491>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<32768>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>>,EFFECT_PREON>>>,Ifon<Int<0>,Int<32768>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
 StylePtr<Black>(),
"crushed"},



};

//----------------------------------------------------------------------------------------------------------------------------------------
Preset noblade[] = {

// // Try Sparkle<Red> as accents style

{ "a_ASAJJ/Ventress;common;commonBU", "tracks/Sister1.wav", 
    StylePtr<Black>(),
    StylePtr<SimpleClash<Lockup<Blast<ColorCycle<Red,20,50,BrownNoiseFlicker<Red,Rgb16<14386,0,0>,500>,100,200,800>,White,200,600>,AudioFlicker<Rgb<255,100,100>,White>,AudioFlicker<Rgb<255,100,100>,White>,Int<32768>,Int<32768>>,White,50,EFFECT_CLASH,Int<32768>>>(),
"assaj\nventress"},   


{ "Calibr8;common;commonBU", "tracks/ObiWan1.wav",    
    StylePtr<Black>(),
    StylePtr<ColorCycle<Pulsing<Blue,Sparkle<Cyan,White,100>,1500>,75,30,Stripes<1000,1000,Cyan,DodgerBlue,White,Black>,60,250,2000>>(),
"calibrate"},  

  
// { "Mauler;common;commonBU", "tracks/DuelOfTheFates.wav",      // Troy Huang Palpatine / Sidiuos
//     //StylePtr<InOutSparkTip<OnSpark<Blast<LocalizedClash<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<TransitionEffect<Lockup<Mix<SwingSpeed<500>,AudioFlicker<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,Pulsing<Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,RandomFlicker<OrangeRed,Red>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<Red,OrangeRed>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,RandomFlicker<Red,OrangeRed>,Strobe<Yellow,BrownNoiseFlicker<Black,Strobe<Black,Yellow,15,20>,300>,50,1>,RandomFlicker<OrangeRed,Red>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>,2000>,RandomPerLEDFlicker<Red,Yellow>>,Mix<Bump<Int<32768>,Int<10000>>,AudioFlicker<Red,Rgb<128,0,0>>,Yellow>,TrInstant,TrFade<300>,EFFECT_DRAG_END>,Gradient<Orange,Orange,White>,TrSmoothFade<50>,TrWipeIn<50>,EFFECT_DRAG_BEGIN>,Gradient<White,DeepSkyBlue,LightPink,DeepSkyBlue,White>,TrJoinR<TrWipe<100>,TrWipeIn<100>>,TrSmoothFade<100>,EFFECT_LOCKUP_END>,White,TrBoing<50,2>,TrFade<30>,EFFECT_LOCKUP_BEGIN>,Mix<Bump<Int<32768>,Int<16000>>,Gradient<BrownNoiseFlicker<Black,OrangeRed,400>,Red,OrangeRed,Orange,White>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Red,White,15,20>,Green,10,10>,500>>,TrWipeIn<350>,TrFade<800>,EFFECT_STAB>,BrownNoiseFlicker<White,DarkOrange,400>,100,75>,TransitionEffect<Blue,White,TrWipe<1>,TrWipe<75>,EFFECT_BLAST>,400,250,800>,BrownNoiseFlicker<Black,Orange,400>,500>,300,800>>(),
//     //Layer ver
//     StylePtr<Black>(),
//     StylePtr<SimpleClash<Lockup<Blast<ColorCycle<Red,20,50,BrownNoiseFlicker<Red,Rgb16<14386,0,0>,500>,100,200,800>,White,200,600>,AudioFlicker<Rgb<255,100,100>,White>,AudioFlicker<Rgb<255,100,100>,White>,Int<32768>,Int<32768>>,White,50,EFFECT_CLASH,Int<32768>>>(),
// "darth\nmaul"},



// { "ObiWan;common;commonBU", "tracks/ObiWan1.wav",   
//     StylePtr<Black>(),
//    StylePtr<SimpleClash<Lockup<Blast<ColorCycle<Pulsing<DodgerBlue,Rgb16<3,1053,20996>,2500>,15,40,RandomPerLEDFlicker<DodgerBlue,DeepSkyBlue>,100,200,800>,White,200,600>,AudioFlicker<Rgb<255,100,100>,White>,AudioFlicker<Rgb<255,100,100>,White>,Int<32768>,Int<32768>>,White,50,EFFECT_CLASH,Int<32768>>>(),
// "obi-wan\nkenobi"},  

// { "testfont;common;commonBU", "tracks/uranus.wav",
//     StylePtr<InOutHelper<SimpleClash<Lockup<Blast<RotateColorsX<Sin<Int<10>>,Red>,White>,AudioFlicker<Blue,White>>,White>,300,800>>(),
//     StylePtr<ColorChange<TrSmoothFade<500>,Red,Green,Blue,White,Black,Red,Orange,Yellow,Green,Blue,Magenta,Rgb16<13415,17,65535>>>(),
// "testfont"},



// { "BattLevl;common;commonBU", "tracks/mars.wav",
//      StylePtr<Black>(),
//      &style_charging,     
// "battery\nlevel"},

};


BladeConfig blades[] = {

{ NO_BLADE, // blade=0 //                               D1_data_line = proffie_D1 ---> NPXL ctrpin ---> Open when no blade 
            //                                          D3_data_line = proffie_D3 ---> BP pin --->LED NEG when blade in        
  WS281XBladePtr<0, bladePin,  Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // NPXL  D2_data_line = D2--->330ohm--->accents--->chamberBOT--->chamberTOP--->NPXL_D2pin--->330ohm--->5LEDs
CONFIGARRAY(noblade),
"00_NO_BLADEsave", }, // Make NPXL do cool shit when no blade in.


{ 0,     //blade=1 // 7/8" Ventress_A                D1_data_line = proffie_D1 ---> Switch ---> NPXL ctrpin---> bladePCB 330ohm ---> Main blade strips
            //                                                                             \ Battery NEG for charging
            //                                          D3_data_line = proffie_D3 ---> BP pin --->LED NEG when blade in
  WS281XBladePtr<130, bladePin,  Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                 ////////////////////////////////////////////CHANGE WHEN BC MADE BLADE.....IS MADE.
  WS281XBladePtr<5,   blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // D2_data_line = proffie_D2 ---> NPXL_D2pin---> 470ohm---> 5LEDs
CONFIGARRAY(AllBlades),
"01_AllBladessave", }, 


};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
