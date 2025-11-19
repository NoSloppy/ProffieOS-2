// BC_Ronin_fett263_7.x.h

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2

// ------ Audio Stuff --------

#define VOLUME 2000
#define BOOT_VOLUME 300
#define ENABLE_AUDIO
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                   // SPDIF out
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8
// #define FEMALE_TALKIE_VOICE
#define NO_REPEAT_RANDOM
#define KILL_OLD_PLAYERS
#define DISABLE_TALKIE

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet. Equivalent to just increasing maxLedsPerStrip.
#define EXTRA_COLOR_BUFFER_SPACE 60

// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000> // resistor value used

// BridgedPullupBladeID is the default Proffieboard V3 BLADE_ID_CLASS, so it doesn't need to defined explicitly with a V3.
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9> // PBv2.2 TX pad for example

/*  SnapshotBladeID is the default Proffieboard V1.5 and V2.2 BLADE_ID_CLASS, so it doesn't need to defined explicitly.
    It will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value,
    so using something like 200000 instead of NO_BLADE is best. */
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin>

/*
-- Real Time BladeID --
 
Main blade must be wired to data1
Blades can use the same set of presets, or have a Presets array for each blade.
Arrays should be named differently like no_blade, blade_1, blade_2,  etc...
Match Preset array names names to the CONFIGARRAY for the given blade.

Open Serial Monitor in Arduino and type `id` to read the resistance value.
It will display "BLADE ID: (some number)"
Use that value in the blade definition in the BladeConfig.
* Note * It is recommended to use a Blade ID resistor in each blade 
to ensure different and distant enough resistance values between blades. 
However, in testing, values reported for a chassis alone,
chassis inserted into the hilt (connected to emitter PCB)
and then main blade inserted all gave different enough values on their own
without added resistors and it worked fine. YMMV.
*/

//    Blanket define to cover the following 4
// #define REAL_TIME_BLADE_ID_PINS 2, 3

  //    Use with Blade ID. Specify the LED pad(s) that the main blade uses.
  // #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>

  //    Required when blades on different data pads use common LED power pads.
  //    and/or when BLADE_ID_SCAN_MILLIS is used with Blade ID.
  // #define SHARED_POWER_PINS

  //    Choose how often to check for new blade (milliseconds).
  //    Larger values will be a longer delay before a blade is recognized.
  // #define BLADE_ID_SCAN_MILLIS 1000

  //    How many Blade ID scans to average (default is 10, works well)
  // #define BLADE_ID_TIMES 15

//    Add this when using dual_prop, and make sure the blaster preset (no blade) is first in the config file.
//    Can be used with Blade Detect or Blade ID (including Real Time Blade ID)
 // #define DUAL_PROP_CONDITION (current_config != blades)
// #define DUAL_PROP_CONDITION (!current_config || current_config->ohm >= NO_BLADE) // FH suggestion with NoBladeBladeId<>, but inverse dual prop behavior
//#define DUAL_PROP_CONDITION (current_config && current_config->ohm < NO_BLADE) - WIP with NoBladeBladeId<>

//    Requires wiring a pad to a switched GND
//    (floating pogo pin until grounded via blade-side PCB ring)
// #define BLADE_DETECT_PIN 10 

// ------ SD Card Stuff -------

#define ENABLE_SD
//#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    // #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//    presets.ini/tmp is ignored after reprogramming unless this is defined.
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING

// ------- OLED stuff ----------

// #define ENABLE_SSD1306                         // OLED display. also defines ENABLE_DISPLAY_CODE
// #define OLED_FLIP_180                          // BC now canon
// #define OLED_MIRRORED                          // BC now canon
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
// #define PROFFIEOS_LOG_LEVEL 300
//    PVLOG_ERROR 100 = errors
//    PVLOG_STATUS 200 = things you should probably know, like blade ID
//    PVLOG_NORMAL 300 = normal information about what is happening (default level)
//    PVLOG_DEBUG 400 = information helpful for debugging
//    PVLOG_VERBOSE 500 = repeated, spammy information you don't normally want
// #define PROFFIEOS_LOG_LEVEL 300

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
//    The following changes the angle required to register twists on curved hilts.
//    Example is for Assaj Ventress curved hilt install.
// #define ORIENTATION_ROTATION 0,-20,0

// #define CONFIG_STARTUP_DELAY 15000               // BC now canon

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3
#define AUDIO_CLASH_SUPPRESSION_LEVEL 10
// #define BC_SWING_ON
// #define BC_SWING_ON_SPEED 400 // Default 250
// #define BC_STAB_ON
// #define BC_THRUST_ON
//#define BC_TWIST_ON
// #define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
//    BC Multiblast continues as long as swinging within 1 second. 
// #define BC_ENABLE_AUTO_SWING_BLAST
// #define ENABLE_SPINS
// #define GESTURE_AUTO_BATTLE_MODE
// #define BC_LOCKUP_DELAY 200
/*    If using blade detect, Gesture ignitions or retractions are 
      disabled when no blade is used. BC prop.
      **NOTE** Only works when a BLADE_DETECT_PIN is defined.*/
//#define NO_BLADE_NO_GEST_ONOFF

// ------- Custom / Experimental / Alpha-Beta stuff ---------

//    BC - THIS NEEDS TO BE CheckLowBattry(), see PR     **Requires modified hybrid_font.h file.
// #define LOW_BATT_ONCE
//    This can save some RAM, but it's not compatible with IntArg/RgbArg (Edit Mode compatible stuff)
// #define OPTIMIZE_TRCONCAT

// -------- BC Prop Other Stuff --------

// #define NO_VOLUME_MENU                         // BC prop. Self evident, but why?

// -------- Blaster Stuff ----------

// #define BLASTER_ENABLE_AUTO
// #define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
// #define BLASTER_JAM_PERCENTAGE 4     // if not defined, random.
// #define BLASTER_DEFAULT_MODE MODE_KILL

// -------- Fett263 Stuff ----------
#define ENABLE_ALL_EDIT_OPTIONS
#define COLOR_CHANGE_DIRECT
// #define ENABLE_ALL_MENU_OPTIONS
    //#define DYNAMIC_BLADE_DIMMING
    //#define DYNAMIC_CLASH_THRESHOLD
    //#define SAVE_VOLUME
    //#define SAVE_BLADE_DIMMING
    //#define SAVE_CLASH_THRESHOLD
    //#define SAVE_COLOR_CHANGE
#define FETT263_EDIT_MODE_MENU
/* --- Either OR, not both --- */
//#define FETT263_EDIT_SETTINGS_MENU
#define FETT263_SPECIAL_ABILITIES
#define FETT263_CLASH_STRENGTH_SOUND
#define FETT263_MAX_CLASH 16
#define FETT263_POWER_LOCK
//#define FETT263_QUICK_SELECT_ON_BOOT
#define FETT263_SAY_COLOR_LIST
#define FETT263_SAY_COLOR_LIST_CC
#define FETT263_BC_SAY_BATTERY_VOLTS_PERCENT
#define FETT263_MOTION_WAKE_POWER_BUTTON
#define FETT263_QUOTE_PLAYER_START_ON
#define FETT263_HOLD_BUTTON_OFF
#define FETT263_USE_BC_MELT_STAB
#define FETT263_LOCKUP_DELAY 200
#define FETT263_BM_CLASH_DETECT 6
#define FETT263_SWING_ON_SPEED 250
#define FETT263_SWING_ON
#define FETT263_SWING_ON_NO_BM
#define FETT263_THRUST_ON
#define FETT263_THRUST_ON_NO_BM
#define FETT263_TWIST_OFF
#define FETT263_FORCE_PUSH
#define FETT263_FORCE_PUSH_LENGTH 5

#endif

#ifdef CONFIG_PROP
// #include "../props/saber_BC_buttons_personal.h"
#include "../props/saber_fett263_buttons.h"

#endif

#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"
#include "aliases/TrueWhites/BC_effects_2.h"
#include "aliases/TrueWhites/BC_effects_Red.h"
#include "aliases/TrueWhites/BC_effects_White.h"

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

/* ---- Presets list ---- /*

aa_Kyberphonic/The_Duel
aa_JayDalorian/OdaNobunaga
aa_HarrySolo/Ronins_Path
aa_Kyberphonic/Skoll
aa_Kyberphonic/Great_Mother_V2 - BC blade Style
aa_Syndicate/Synergy - BC blade style - Preons matched to sounds



a_INQUISITOR/2ndSistr
a_INQUISITOR/9thSistr
a_BANE/TheBane w/ice monosfx
// a_BANE/RuleOfTwo
a_SIDIOUS/TheReturn
a_ASAJJ/NiteSist
a_DOOKU/Duke // Matched Preons/outs
a_DOOKU/Dooku_CW
a_SAVAGE/Savage_Opress
a_DARTH_MAUL/CrimsonMenace
a_INQUISITOR/RevaUltimate
aa_Syndicate/SithChant // ------------- check it
a_STARKILLER/Secret_Apprentice w/ice monosfx - broken out fx because force choke anim
aa_KSith/Aggression w/ colorchange 2 colors
a_KYLO/KyloUltimate
a_REY/Empress
a_VADER/Father_V2/ANH
aa_Greyscale/Seethe_Greyscale
aa_Juansith/HATE
aa_Blueforce/IgnitionUltimate
aa_HarrySolo/AGONY
aa_KSith/Proto
aa_KSith/Desolation
aa_KSith/Ascension
Arcane
aa_KSith/Traveler
GhostsOfTheGrey
aa_LordBlako/PitchBlk
a_PONG_KRELL/PongKrll
Proto2
PsyBorg
a_DARKSABER/DarkV3
aa_Blueforce/LiquidStatic
*/


Preset Ronin [] = {
{ "aa_Kyberphonic/The_Duel/Ronin;ProffieOS_Voicepack_Kylo_V2/common;commonBU", "The_Duel/tracks/track2.wav",
/* copyright Fett263 Visions (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Visions
OS7.8 v1.015
This Style Contains 648 Unique Combinations
Style Options:
Default (0): The Duel: Ronin
1: The Duel: Bandit Leader
2: The Twins: Karre

Base Color: BaseColorArg (0)

NOTE:This style includes Control Layer. Only one Control Layer should be used per preset.

*This style REQUIRES Alt Fonts alt000/ to alt00-1/ to be set up. Uses altchng.wav on change.
See https://pod.hubbe.net/sound/alt_sounds.html for more information.
--Effects Included--
Ignition Effect Options: Default (0): SparkTip Ignition, 1: Cycle Up, 2: Lightning Strike [Color: IgnitionColorArg]
PowerUp Effect Options: Default (0): Power Flash, 1: Rey TROS Spark, 2: Power Burst Emitter [Color: AltColor2Arg]
Retraction Effect Options: Default (0): Standard Retraction, 1: Center In, 2: Center Out + Fade (Blade Angle Position) [Color: RetractionColorArg]
CoolDown Effect Options: Default (0): Power Burst Reverse, 1: Unstable Cool Down Center Out [Color: Rgb<0,255,17>]
PostOff Effect Options: Default (0): Emitter Cool Off (Emitter Size), 1: Emitter Glow (Preon Size) [Color: EmitterColorArg]
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Localized Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect (Randomly Selected): Blast Wave (Random), Blast Ripple, Blast Fade (Large) [Color: BlastColorArg]
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Swing Effect Options: Default (0): Flame Thrower Swing, 1: Force Boost AudioFlicker Swing (Scaled Responsive Edge) [Color: AltColor3Arg]
Emitter Effect: Flickering Flare [Color: EmitterColorArg]
Emitter Off Effect: Base Color Pulse (One-Time Preset Indicator) [Color: EmitterColorArg]
Rain Effect: Rain Dent [Color: EmitterColorArg]
Battery Level: Blade Location (Green to Red)
Display Volume: % Blade [Color: LBColorArg]
Special Ability 1: Toggle Swing Change (Random / Party Mode) Uses tr.wav #0 on toggle
Special Ability 5: Ignite - Play Sound Uses tr.wav #0

*/
StylePtr<Layers<ColorSelect<IntArg<STYLE_OPTION_ARG,0>,TrInstant,HumpFlicker<Stripes<20000,-800,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,50>,HumpFlicker<Stripes<20000,-1200,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,50>,Mix<SmoothStep<Int<15000>,Int<18000>>,Stripes<22000,-2000,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>>,HumpFlicker<Mix<Int<6000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>,20>>,Stripes<20000,-1800,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<18000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,HumpFlicker<Mix<Int<6000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,20>>>>,AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-6000>>>,ColorSelect<IntArg<SWING_OPTION_ARG,0>,TrInstant,AlphaL<StaticFire<Stripes<12000,-2000,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>,RotateColorsX<Int<200>,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>>,Mix<Int<16384>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>,0,3,2,2000,8>,SmoothStep<Scale<HoldPeakF<Ifon<Scale<IsGreaterThan<SwingSpeed<500>,Int<16000>>,Int<2000>,SwingSpeed<300>>,Int<0>>,Scale<SwingAcceleration<>,Int<100>,Int<600>>,Scale<SwingAcceleration<>,Int<10000>,Int<4000>>>,Int<1000>,Int<40000>>,Int<-4000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<5000>,TrFade<300>>,AlphaL<AlphaL<AudioFlickerL<RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Scale<Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>,Int<28000>,Int<14000>>,Int<16000>>>,TrFade<300>>,EFFECT_FORCE>>,TransitionEffectL<TrSelect<IntArg<IGNITION_POWER_UP_ARG,0>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>,TrFade<1000>>,TrConcat<TrJoin<TrDelay<200>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<300>,AlphaL<Blue,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,AlphaL<Stripes<5000,-2500,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>,Mix<Int<7710>,Black,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>>,Mix<Int<3855>,Black,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>>,EFFECT_IGNITION>,TransitionEffectL<TrSelect<IntArg<RETRACTION_COOL_DOWN_ARG,0>,TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<5000,2500,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,Mix<Int<7710>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>>,TrFade<800>>,TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Remap<CenterDistF<>,Stripes<3000,-3500,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Black>,BrownNoiseFlicker<Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>>>>,TrFade<800>>>,EFFECT_RETRACTION>,TransitionPulseL<TrSelect<IncrementModuloF<EffectPulseF<EFFECT_USER1>,Int<2>>,TrInstant,TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<-1>>>,Int<0>>,Int<-1>>>,ThresholdPulseF<SwingSpeed<320>,Int<31000>>>,TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>,Int<-1>>,EFFECT_USER1>,SparkleL<Black>,TransitionEffectL<TrRandom<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Remap<CenterDistF<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>>,TrConcat<TrInstant,AlphaMixL<Bump<EffectPosition<EFFECT_BLAST>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>>,EFFECT_BLAST>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Int<13000>>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
InOutTrL<TrSelect<IncrementWithReset<ThresholdPulseF<EffectPulseF<EFFECT_USER5>,Int<30000>>,EffectPulseF<EFFECT_RETRACTION>,Int<1>>,TrSelect<IntArg<IGNITION_OPTION_ARG,0>,TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,White>,BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,18992>,Int<98304>>>>,TrColorCycleX<BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,18992>,Int<98304>>>>,TrConcat<TrWipeInX<Mult<IgnitionTime<0>,Int<6553>>>,RandomBlink<30000,RgbArg<IGNITION_COLOR_ARG,White>>,TrJoin<TrDelayX<Mult<IgnitionTime<0>,Int<19660>>>,TrWipeInX<Mult<IgnitionTime<230>,Int<6553>>>>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,IntArg<EMITTER_SIZE_ARG,1000>,Sum<Int<5000>,IntArg<EMITTER_SIZE_ARG,1000>>>,Int<-3000>>,Black,RgbArg<IGNITION_COLOR_ARG,White>>,TrWipeX<Mult<IgnitionTime<0>,Int<19660>>>>>,TrInstant>,TrSelect<IntArg<RETRACTION_OPTION_ARG,0>,TrWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrCenterWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrJoin<TrCenterWipeX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>,Scale<BladeAngle<>,Int<6000>,Int<27000>>>,TrSmoothFadeX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>>>,
TransitionEffectL<TrSelect<IntArg<OFF_OPTION_ARG,0>,TrConcat<TrInstant,AlphaL<White,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Orange,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Red,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>>,EFFECT_POSTOFF>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<300>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

"preset0"
},

{ "aa_JayDalorian/OdaNobunaga;ProffieOS_Voicepack_Narrator/common;commonBU", "aa_JayDalorian/OdaNobunaga/tracks/sharingan.wav",
/* copyright Fett263 Visions (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Visions
OS7.8 v1.015
This Style Contains 648 Unique Combinations
Style Options:
Default (0): The Duel: Ronin
1: The Duel: Bandit Leader
2: The Twins: Karre

Base Color: BaseColorArg (0)

NOTE:This style includes Control Layer. Only one Control Layer should be used per preset.

*This style REQUIRES Alt Fonts alt000/ to alt00-1/ to be set up. Uses altchng.wav on change.
See https://pod.hubbe.net/sound/alt_sounds.html for more information.
--Effects Included--
Ignition Effect Options: Default (0): SparkTip Ignition, 1: Cycle Up, 2: Lightning Strike [Color: IgnitionColorArg]
PowerUp Effect Options: Default (0): Power Flash, 1: Rey TROS Spark, 2: Power Burst Emitter [Color: AltColor2Arg]
Retraction Effect Options: Default (0): Standard Retraction, 1: Center In, 2: Center Out + Fade (Blade Angle Position) [Color: RetractionColorArg]
CoolDown Effect Options: Default (0): Power Burst Reverse, 1: Unstable Cool Down Center Out [Color: Rgb<0,255,17>]
PostOff Effect Options: Default (0): Emitter Cool Off (Emitter Size), 1: Emitter Glow (Preon Size) [Color: EmitterColorArg]
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Localized Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect (Randomly Selected): Blast Wave (Random), Blast Ripple, Blast Fade (Large) [Color: BlastColorArg]
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Swing Effect Options: Default (0): Flame Thrower Swing, 1: Force Boost AudioFlicker Swing (Scaled Responsive Edge) [Color: AltColor3Arg]
Emitter Effect: Flickering Flare [Color: EmitterColorArg]
Emitter Off Effect: Base Color Pulse (One-Time Preset Indicator) [Color: EmitterColorArg]
Rain Effect: Rain Dent [Color: EmitterColorArg]
Battery Level: Blade Location (Green to Red)
Display Volume: % Blade [Color: LBColorArg]
Special Ability 1: Toggle Swing Change (Random / Party Mode) Uses tr.wav #0 on toggle
Special Ability 5: Ignite - Play Sound Uses tr.wav #0

*/
StylePtr<Layers<ColorSelect<IntArg<STYLE_OPTION_ARG,0>,TrInstant,HumpFlicker<Stripes<20000,-800,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,50>,HumpFlicker<Stripes<20000,-1200,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,50>,Mix<SmoothStep<Int<15000>,Int<18000>>,Stripes<22000,-2000,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>>,HumpFlicker<Mix<Int<6000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>,20>>,Stripes<20000,-1800,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<18000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,HumpFlicker<Mix<Int<6000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,20>>>>,AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-6000>>>,ColorSelect<IntArg<SWING_OPTION_ARG,0>,TrInstant,AlphaL<StaticFire<Stripes<12000,-2000,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>,RotateColorsX<Int<200>,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>>,Mix<Int<16384>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>,0,3,2,2000,8>,SmoothStep<Scale<HoldPeakF<Ifon<Scale<IsGreaterThan<SwingSpeed<500>,Int<16000>>,Int<2000>,SwingSpeed<300>>,Int<0>>,Scale<SwingAcceleration<>,Int<100>,Int<600>>,Scale<SwingAcceleration<>,Int<10000>,Int<4000>>>,Int<1000>,Int<40000>>,Int<-4000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<5000>,TrFade<300>>,AlphaL<AlphaL<AudioFlickerL<RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Scale<Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>,Int<28000>,Int<14000>>,Int<16000>>>,TrFade<300>>,EFFECT_FORCE>>,TransitionEffectL<TrSelect<IntArg<IGNITION_POWER_UP_ARG,0>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>,TrFade<1000>>,TrConcat<TrJoin<TrDelay<200>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<300>,AlphaL<Blue,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,AlphaL<Stripes<5000,-2500,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>,Mix<Int<7710>,Black,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>>,Mix<Int<3855>,Black,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>>,EFFECT_IGNITION>,TransitionEffectL<TrSelect<IntArg<RETRACTION_COOL_DOWN_ARG,0>,TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<5000,2500,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,Mix<Int<7710>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>>,TrFade<800>>,TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Remap<CenterDistF<>,Stripes<3000,-3500,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Black>,BrownNoiseFlicker<Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>>>>,TrFade<800>>>,EFFECT_RETRACTION>,TransitionPulseL<TrSelect<IncrementModuloF<EffectPulseF<EFFECT_USER1>,Int<2>>,TrInstant,TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<-1>>>,Int<0>>,Int<-1>>>,ThresholdPulseF<SwingSpeed<320>,Int<31000>>>,TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>,Int<-1>>,EFFECT_USER1>,SparkleL<Black>,TransitionEffectL<TrRandom<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Remap<CenterDistF<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>>,TrConcat<TrInstant,AlphaMixL<Bump<EffectPosition<EFFECT_BLAST>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>>,EFFECT_BLAST>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Int<13000>>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrSelect<IncrementWithReset<ThresholdPulseF<EffectPulseF<EFFECT_USER5>,Int<30000>>,EffectPulseF<EFFECT_RETRACTION>,Int<1>>,TrSelect<IntArg<IGNITION_OPTION_ARG,0>,TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,White>,BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,18992>,Int<98304>>>>,TrColorCycleX<BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,18992>,Int<98304>>>>,TrConcat<TrWipeInX<Mult<IgnitionTime<0>,Int<6553>>>,RandomBlink<30000,RgbArg<IGNITION_COLOR_ARG,White>>,TrJoin<TrDelayX<Mult<IgnitionTime<0>,Int<19660>>>,TrWipeInX<Mult<IgnitionTime<230>,Int<6553>>>>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,IntArg<EMITTER_SIZE_ARG,1000>,Sum<Int<5000>,IntArg<EMITTER_SIZE_ARG,1000>>>,Int<-3000>>,Black,RgbArg<IGNITION_COLOR_ARG,White>>,TrWipeX<Mult<IgnitionTime<0>,Int<19660>>>>>,TrInstant>,TrSelect<IntArg<RETRACTION_OPTION_ARG,0>,TrWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrCenterWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrJoin<TrCenterWipeX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>,Scale<BladeAngle<>,Int<6000>,Int<27000>>>,TrSmoothFadeX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>>>,TransitionEffectL<TrSelect<IntArg<OFF_OPTION_ARG,0>,TrConcat<TrInstant,AlphaL<White,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Orange,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Red,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>>,EFFECT_POSTOFF>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<300>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

"preset1"
},

{ "aa_HarrySolo/Ronins_Path;ProffieOS_Voicepack_Obi-Wan_CW/common;commonBU", "tracks/FallenOrderTracks/JFO9.wav",
/* copyright Fett263 Visions (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Visions
OS7.8 v1.015
This Style Contains 648 Unique Combinations
Style Options:
Default (0): The Duel: Ronin
1: The Duel: Bandit Leader
2: The Twins: Karre

Base Color: BaseColorArg (0)

NOTE:This style includes Control Layer. Only one Control Layer should be used per preset.

*This style REQUIRES Alt Fonts alt000/ to alt00-1/ to be set up. Uses altchng.wav on change.
See https://pod.hubbe.net/sound/alt_sounds.html for more information.
--Effects Included--
Ignition Effect Options: Default (0): SparkTip Ignition, 1: Cycle Up, 2: Lightning Strike [Color: IgnitionColorArg]
PowerUp Effect Options: Default (0): Power Flash, 1: Rey TROS Spark, 2: Power Burst Emitter [Color: AltColor2Arg]
Retraction Effect Options: Default (0): Standard Retraction, 1: Center In, 2: Center Out + Fade (Blade Angle Position) [Color: RetractionColorArg]
CoolDown Effect Options: Default (0): Power Burst Reverse, 1: Unstable Cool Down Center Out [Color: Rgb<0,255,17>]
PostOff Effect Options: Default (0): Emitter Cool Off (Emitter Size), 1: Emitter Glow (Preon Size) [Color: EmitterColorArg]
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Localized Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect (Randomly Selected): Blast Wave (Random), Blast Ripple, Blast Fade (Large) [Color: BlastColorArg]
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Swing Effect Options: Default (0): Flame Thrower Swing, 1: Force Boost AudioFlicker Swing (Scaled Responsive Edge) [Color: AltColor3Arg]
Emitter Effect: Flickering Flare [Color: EmitterColorArg]
Emitter Off Effect: Base Color Pulse (One-Time Preset Indicator) [Color: EmitterColorArg]
Rain Effect: Rain Dent [Color: EmitterColorArg]
Battery Level: Blade Location (Green to Red)
Display Volume: % Blade [Color: LBColorArg]
Special Ability 1: Toggle Swing Change (Random / Party Mode) Uses tr.wav #0 on toggle
Special Ability 5: Ignite - Play Sound Uses tr.wav #0

*/
StylePtr<Layers<ColorSelect<IntArg<STYLE_OPTION_ARG,0>,TrInstant,HumpFlicker<Stripes<20000,-800,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,50>,HumpFlicker<Stripes<20000,-1200,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,50>,Mix<SmoothStep<Int<15000>,Int<18000>>,Stripes<22000,-2000,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>>,HumpFlicker<Mix<Int<6000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>,20>>,Stripes<20000,-1800,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<18000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,HumpFlicker<Mix<Int<6000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,20>>>>,AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-6000>>>,ColorSelect<IntArg<SWING_OPTION_ARG,0>,TrInstant,AlphaL<StaticFire<Stripes<12000,-2000,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>,RotateColorsX<Int<200>,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>>,Mix<Int<16384>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>,0,3,2,2000,8>,SmoothStep<Scale<HoldPeakF<Ifon<Scale<IsGreaterThan<SwingSpeed<500>,Int<16000>>,Int<2000>,SwingSpeed<300>>,Int<0>>,Scale<SwingAcceleration<>,Int<100>,Int<600>>,Scale<SwingAcceleration<>,Int<10000>,Int<4000>>>,Int<1000>,Int<40000>>,Int<-4000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<5000>,TrFade<300>>,AlphaL<AlphaL<AudioFlickerL<RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Scale<Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>,Int<28000>,Int<14000>>,Int<16000>>>,TrFade<300>>,EFFECT_FORCE>>,TransitionEffectL<TrSelect<IntArg<IGNITION_POWER_UP_ARG,0>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>,TrFade<1000>>,TrConcat<TrJoin<TrDelay<200>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<300>,AlphaL<Blue,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,AlphaL<Stripes<5000,-2500,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>,Mix<Int<7710>,Black,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>>,Mix<Int<3855>,Black,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>>,EFFECT_IGNITION>,TransitionEffectL<TrSelect<IntArg<RETRACTION_COOL_DOWN_ARG,0>,TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<5000,2500,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,Mix<Int<7710>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>>,TrFade<800>>,TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Remap<CenterDistF<>,Stripes<3000,-3500,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Black>,BrownNoiseFlicker<Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>>>>,TrFade<800>>>,EFFECT_RETRACTION>,TransitionPulseL<TrSelect<IncrementModuloF<EffectPulseF<EFFECT_USER1>,Int<2>>,TrInstant,TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<-1>>>,Int<0>>,Int<-1>>>,ThresholdPulseF<SwingSpeed<320>,Int<31000>>>,TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>,Int<-1>>,EFFECT_USER1>,SparkleL<Black>,TransitionEffectL<TrRandom<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Remap<CenterDistF<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>>,TrConcat<TrInstant,AlphaMixL<Bump<EffectPosition<EFFECT_BLAST>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>>,EFFECT_BLAST>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Int<13000>>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrSelect<IncrementWithReset<ThresholdPulseF<EffectPulseF<EFFECT_USER5>,Int<30000>>,EffectPulseF<EFFECT_RETRACTION>,Int<1>>,TrSelect<IntArg<IGNITION_OPTION_ARG,0>,TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,White>,BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,18992>,Int<98304>>>>,TrColorCycleX<BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,18992>,Int<98304>>>>,TrConcat<TrWipeInX<Mult<IgnitionTime<0>,Int<6553>>>,RandomBlink<30000,RgbArg<IGNITION_COLOR_ARG,White>>,TrJoin<TrDelayX<Mult<IgnitionTime<0>,Int<19660>>>,TrWipeInX<Mult<IgnitionTime<230>,Int<6553>>>>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,IntArg<EMITTER_SIZE_ARG,1000>,Sum<Int<5000>,IntArg<EMITTER_SIZE_ARG,1000>>>,Int<-3000>>,Black,RgbArg<IGNITION_COLOR_ARG,White>>,TrWipeX<Mult<IgnitionTime<0>,Int<19660>>>>>,TrInstant>,TrSelect<IntArg<RETRACTION_OPTION_ARG,0>,TrWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrCenterWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrJoin<TrCenterWipeX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>,Scale<BladeAngle<>,Int<6000>,Int<27000>>>,TrSmoothFadeX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>>>,TransitionEffectL<TrSelect<IntArg<OFF_OPTION_ARG,0>,TrConcat<TrInstant,AlphaL<White,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Orange,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Red,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>>,EFFECT_POSTOFF>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<300>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

"preset2"
},

{ "aa_Kyberphonic/Skoll;ProffieOS_Voicepack_Skoll/common;commonBU", "aa_Kyberphonic/Skoll/tracks/track1.wav",
/* copyright Fett263 Visions (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Visions
OS7.8 v1.015
This Style Contains 648 Unique Combinations
Style Options:
Default (0): The Duel: Ronin
1: The Duel: Bandit Leader
2: The Twins: Karre

Base Color: BaseColorArg (0)

NOTE:This style includes Control Layer. Only one Control Layer should be used per preset.

*This style REQUIRES Alt Fonts alt000/ to alt00-1/ to be set up. Uses altchng.wav on change.
See https://pod.hubbe.net/sound/alt_sounds.html for more information.
--Effects Included--
Ignition Effect Options: Default (0): SparkTip Ignition, 1: Cycle Up, 2: Lightning Strike [Color: IgnitionColorArg]
PowerUp Effect Options: Default (0): Power Flash, 1: Rey TROS Spark, 2: Power Burst Emitter [Color: AltColor2Arg]
Retraction Effect Options: Default (0): Standard Retraction, 1: Center In, 2: Center Out + Fade (Blade Angle Position) [Color: RetractionColorArg]
CoolDown Effect Options: Default (0): Power Burst Reverse, 1: Unstable Cool Down Center Out [Color: Rgb<0,255,17>]
PostOff Effect Options: Default (0): Emitter Cool Off (Emitter Size), 1: Emitter Glow (Preon Size) [Color: EmitterColorArg]
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Localized Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect (Randomly Selected): Blast Wave (Random), Blast Ripple, Blast Fade (Large) [Color: BlastColorArg]
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Swing Effect Options: Default (0): Flame Thrower Swing, 1: Force Boost AudioFlicker Swing (Scaled Responsive Edge) [Color: AltColor3Arg]
Emitter Effect: Flickering Flare [Color: EmitterColorArg]
Emitter Off Effect: Base Color Pulse (One-Time Preset Indicator) [Color: EmitterColorArg]
Rain Effect: Rain Dent [Color: EmitterColorArg]
Battery Level: Blade Location (Green to Red)
Display Volume: % Blade [Color: LBColorArg]
Special Ability 1: Toggle Swing Change (Random / Party Mode) Uses tr.wav #0 on toggle
Special Ability 5: Ignite - Play Sound Uses tr.wav #0

*/
StylePtr<Layers<ColorSelect<IntArg<STYLE_OPTION_ARG,0>,TrInstant,HumpFlicker<Stripes<20000,-800,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,50>,HumpFlicker<Stripes<20000,-1200,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,50>,Mix<SmoothStep<Int<15000>,Int<18000>>,Stripes<22000,-2000,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>>,HumpFlicker<Mix<Int<6000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>,20>>,Stripes<20000,-1800,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<18000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,HumpFlicker<Mix<Int<6000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,20>>>>,AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-6000>>>,ColorSelect<IntArg<SWING_OPTION_ARG,0>,TrInstant,AlphaL<StaticFire<Stripes<12000,-2000,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>,RotateColorsX<Int<200>,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>>,Mix<Int<16384>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>,0,3,2,2000,8>,SmoothStep<Scale<HoldPeakF<Ifon<Scale<IsGreaterThan<SwingSpeed<500>,Int<16000>>,Int<2000>,SwingSpeed<300>>,Int<0>>,Scale<SwingAcceleration<>,Int<100>,Int<600>>,Scale<SwingAcceleration<>,Int<10000>,Int<4000>>>,Int<1000>,Int<40000>>,Int<-4000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<5000>,TrFade<300>>,AlphaL<AlphaL<AudioFlickerL<RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Scale<Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>,Int<28000>,Int<14000>>,Int<16000>>>,TrFade<300>>,EFFECT_FORCE>>,TransitionEffectL<TrSelect<IntArg<IGNITION_POWER_UP_ARG,0>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>,TrFade<1000>>,TrConcat<TrJoin<TrDelay<200>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<300>,AlphaL<Blue,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,AlphaL<Stripes<5000,-2500,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>,Mix<Int<7710>,Black,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>>,Mix<Int<3855>,Black,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>>,EFFECT_IGNITION>,TransitionEffectL<TrSelect<IntArg<RETRACTION_COOL_DOWN_ARG,0>,TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<5000,2500,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,Mix<Int<7710>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>>,TrFade<800>>,TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Remap<CenterDistF<>,Stripes<3000,-3500,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Black>,BrownNoiseFlicker<Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>>>>,TrFade<800>>>,EFFECT_RETRACTION>,TransitionPulseL<TrSelect<IncrementModuloF<EffectPulseF<EFFECT_USER1>,Int<2>>,TrInstant,TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<-1>>>,Int<0>>,Int<-1>>>,ThresholdPulseF<SwingSpeed<320>,Int<31000>>>,TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>,Int<-1>>,EFFECT_USER1>,SparkleL<Black>,TransitionEffectL<TrRandom<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Remap<CenterDistF<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>>,TrConcat<TrInstant,AlphaMixL<Bump<EffectPosition<EFFECT_BLAST>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>>,EFFECT_BLAST>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Int<13000>>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrSelect<IncrementWithReset<ThresholdPulseF<EffectPulseF<EFFECT_USER5>,Int<30000>>,EffectPulseF<EFFECT_RETRACTION>,Int<1>>,TrSelect<IntArg<IGNITION_OPTION_ARG,0>,TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,White>,BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,18992>,Int<98304>>>>,TrColorCycleX<BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,18992>,Int<98304>>>>,TrConcat<TrWipeInX<Mult<IgnitionTime<0>,Int<6553>>>,RandomBlink<30000,RgbArg<IGNITION_COLOR_ARG,White>>,TrJoin<TrDelayX<Mult<IgnitionTime<0>,Int<19660>>>,TrWipeInX<Mult<IgnitionTime<230>,Int<6553>>>>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,IntArg<EMITTER_SIZE_ARG,1000>,Sum<Int<5000>,IntArg<EMITTER_SIZE_ARG,1000>>>,Int<-3000>>,Black,RgbArg<IGNITION_COLOR_ARG,White>>,TrWipeX<Mult<IgnitionTime<0>,Int<19660>>>>>,TrInstant>,TrSelect<IntArg<RETRACTION_OPTION_ARG,0>,TrWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrCenterWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrJoin<TrCenterWipeX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>,Scale<BladeAngle<>,Int<6000>,Int<27000>>>,TrSmoothFadeX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>>>,TransitionEffectL<TrSelect<IntArg<OFF_OPTION_ARG,0>,TrConcat<TrInstant,AlphaL<White,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Orange,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Red,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>>,EFFECT_POSTOFF>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<300>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

"preset3"
},

{ "a_STARKILLER/Secret_Apprentice;ProffieOS_Voicepack_Starkiller/common;commonBU", "a_STARKILLER/tracks/SKT4.wav", // AudioFlicker Red Base Color Wheel Changeable
/* copyright Fett263 Visions (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Visions
OS7.8 v1.015
This Style Contains 648 Unique Combinations
Style Options:
Default (0): The Duel: Ronin
1: The Duel: Bandit Leader
2: The Twins: Karre

Base Color: BaseColorArg (0)

NOTE:This style includes Control Layer. Only one Control Layer should be used per preset.

*This style REQUIRES Alt Fonts alt000/ to alt00-1/ to be set up. Uses altchng.wav on change.
See https://pod.hubbe.net/sound/alt_sounds.html for more information.
--Effects Included--
Ignition Effect Options: Default (0): SparkTip Ignition, 1: Cycle Up, 2: Lightning Strike [Color: IgnitionColorArg]
PowerUp Effect Options: Default (0): Power Flash, 1: Rey TROS Spark, 2: Power Burst Emitter [Color: AltColor2Arg]
Retraction Effect Options: Default (0): Standard Retraction, 1: Center In, 2: Center Out + Fade (Blade Angle Position) [Color: RetractionColorArg]
CoolDown Effect Options: Default (0): Power Burst Reverse, 1: Unstable Cool Down Center Out [Color: Rgb<0,255,17>]
PostOff Effect Options: Default (0): Emitter Cool Off (Emitter Size), 1: Emitter Glow (Preon Size) [Color: EmitterColorArg]
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Localized Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect (Randomly Selected): Blast Wave (Random), Blast Ripple, Blast Fade (Large) [Color: BlastColorArg]
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Swing Effect Options: Default (0): Flame Thrower Swing, 1: Force Boost AudioFlicker Swing (Scaled Responsive Edge) [Color: AltColor3Arg]
Emitter Effect: Flickering Flare [Color: EmitterColorArg]
Emitter Off Effect: Base Color Pulse (One-Time Preset Indicator) [Color: EmitterColorArg]
Rain Effect: Rain Dent [Color: EmitterColorArg]
Battery Level: Blade Location (Green to Red)
Display Volume: % Blade [Color: LBColorArg]
Special Ability 1: Toggle Swing Change (Random / Party Mode) Uses tr.wav #0 on toggle
Special Ability 5: Ignite - Play Sound Uses tr.wav #0

*/
StylePtr<Layers<ColorSelect<IntArg<STYLE_OPTION_ARG,0>,TrInstant,HumpFlicker<Stripes<20000,-800,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,50>,HumpFlicker<Stripes<20000,-1200,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,50>,Mix<SmoothStep<Int<15000>,Int<18000>>,Stripes<22000,-2000,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>>,HumpFlicker<Mix<Int<6000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>,20>>,Stripes<20000,-1800,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<18000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,HumpFlicker<Mix<Int<6000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,20>>>>,AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-6000>>>,ColorSelect<IntArg<SWING_OPTION_ARG,0>,TrInstant,AlphaL<StaticFire<Stripes<12000,-2000,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>,RotateColorsX<Int<200>,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>>,Mix<Int<16384>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>,0,3,2,2000,8>,SmoothStep<Scale<HoldPeakF<Ifon<Scale<IsGreaterThan<SwingSpeed<500>,Int<16000>>,Int<2000>,SwingSpeed<300>>,Int<0>>,Scale<SwingAcceleration<>,Int<100>,Int<600>>,Scale<SwingAcceleration<>,Int<10000>,Int<4000>>>,Int<1000>,Int<40000>>,Int<-4000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<5000>,TrFade<300>>,AlphaL<AlphaL<AudioFlickerL<RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Scale<Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>,Int<28000>,Int<14000>>,Int<16000>>>,TrFade<300>>,EFFECT_FORCE>>,TransitionEffectL<TrSelect<IntArg<IGNITION_POWER_UP_ARG,0>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>,TrFade<1000>>,TrConcat<TrJoin<TrDelay<200>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<300>,AlphaL<Blue,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,AlphaL<Stripes<5000,-2500,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>,Mix<Int<7710>,Black,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>>,Mix<Int<3855>,Black,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>>,EFFECT_IGNITION>,TransitionEffectL<TrSelect<IntArg<RETRACTION_COOL_DOWN_ARG,0>,TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<5000,2500,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,Mix<Int<7710>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>>,TrFade<800>>,TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Remap<CenterDistF<>,Stripes<3000,-3500,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Black>,BrownNoiseFlicker<Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>>>>,TrFade<800>>>,EFFECT_RETRACTION>,
TransitionPulseL<TrSelect<IncrementModuloF<EffectPulseF<EFFECT_USER1>,Int<2>>,TrInstant,TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<-1>>>,Int<0>>,Int<-1>>>,ThresholdPulseF<SwingSpeed<320>,Int<31000>>>,TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>,Int<-1>>,EFFECT_USER1>,SparkleL<Black>,TransitionEffectL<TrRandom<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Remap<CenterDistF<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>>,TrConcat<TrInstant,AlphaMixL<Bump<EffectPosition<EFFECT_BLAST>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>>,EFFECT_BLAST>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Int<13000>>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
InOutTrL<TrSelect<IncrementWithReset<ThresholdPulseF<EffectPulseF<EFFECT_USER5>,Int<30000>>,EffectPulseF<EFFECT_RETRACTION>,Int<1>>,TrSelect<IntArg<IGNITION_OPTION_ARG,0>,TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,White>,BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,18992>,Int<98304>>>>,TrColorCycleX<BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,18992>,Int<98304>>>>,TrConcat<TrWipeInX<Mult<IgnitionTime<0>,Int<6553>>>,RandomBlink<30000,RgbArg<IGNITION_COLOR_ARG,White>>,TrJoin<TrDelayX<Mult<IgnitionTime<0>,Int<19660>>>,TrWipeInX<Mult<IgnitionTime<230>,Int<6553>>>>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,IntArg<EMITTER_SIZE_ARG,1000>,Sum<Int<5000>,IntArg<EMITTER_SIZE_ARG,1000>>>,Int<-3000>>,Black,RgbArg<IGNITION_COLOR_ARG,White>>,TrWipeX<Mult<IgnitionTime<0>,Int<19660>>>>>,TrInstant>,TrSelect<IntArg<RETRACTION_OPTION_ARG,0>,TrWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrCenterWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrJoin<TrCenterWipeX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>,Scale<BladeAngle<>,Int<6000>,Int<27000>>>,TrSmoothFadeX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>>>,TransitionEffectL<TrSelect<IntArg<OFF_OPTION_ARG,0>,TrConcat<TrInstant,AlphaL<White,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Orange,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Red,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>>,EFFECT_POSTOFF>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<300>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

"preset4"
},

 { "a_VADER/Father_V2/ANH;ProffieOS_Voicepack_Vader_V2/common;commonBU", "a_VADER/Father_V2/tracks/track1.wav",
/* copyright Fett263 Visions (Primary Blade) OS7 Style
https://fett263library.com/early-access/#Visions
OS7.8 v1.015
This Style Contains 648 Unique Combinations
Style Options:
Default (0): The Duel: Ronin
1: The Duel: Bandit Leader
2: The Twins: Karre

Base Color: BaseColorArg (0)

NOTE:This style includes Control Layer. Only one Control Layer should be used per preset.

*This style REQUIRES Alt Fonts alt000/ to alt00-1/ to be set up. Uses altchng.wav on change.
See https://pod.hubbe.net/sound/alt_sounds.html for more information.
--Effects Included--
Ignition Effect Options: Default (0): SparkTip Ignition, 1: Cycle Up, 2: Lightning Strike [Color: IgnitionColorArg]
PowerUp Effect Options: Default (0): Power Flash, 1: Rey TROS Spark, 2: Power Burst Emitter [Color: AltColor2Arg]
Retraction Effect Options: Default (0): Standard Retraction, 1: Center In, 2: Center Out + Fade (Blade Angle Position) [Color: RetractionColorArg]
CoolDown Effect Options: Default (0): Power Burst Reverse, 1: Unstable Cool Down Center Out [Color: Rgb<0,255,17>]
PostOff Effect Options: Default (0): Emitter Cool Off (Emitter Size), 1: Emitter Glow (Preon Size) [Color: EmitterColorArg]
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Localized Absorb [Color: LockupColorArg]
LightningBlock Effect: Responsive Lightning Block [Color: LBColorArg]
Drag Effect: Intensity Sparking Drag [Color: DragColorArg]
Melt Effect: Intensity Melt [Color: StabColorArg]
Blast Effect (Randomly Selected): Blast Wave (Random), Blast Ripple, Blast Fade (Large) [Color: BlastColorArg]
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Swing Effect Options: Default (0): Flame Thrower Swing, 1: Force Boost AudioFlicker Swing (Scaled Responsive Edge) [Color: AltColor3Arg]
Emitter Effect: Flickering Flare [Color: EmitterColorArg]
Emitter Off Effect: Base Color Pulse (One-Time Preset Indicator) [Color: EmitterColorArg]
Rain Effect: Rain Dent [Color: EmitterColorArg]
Battery Level: Blade Location (Green to Red)
Display Volume: % Blade [Color: LBColorArg]
Special Ability 1: Toggle Swing Change (Random / Party Mode) Uses tr.wav #0 on toggle
Special Ability 5: Ignite - Play Sound Uses tr.wav #0

*/
StylePtr<Layers<ColorSelect<IntArg<STYLE_OPTION_ARG,0>,TrInstant,HumpFlicker<Stripes<20000,-800,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,50>,HumpFlicker<Stripes<20000,-1200,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,50>,Mix<SmoothStep<Int<15000>,Int<18000>>,Stripes<22000,-2000,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>>,HumpFlicker<Mix<Int<6000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,36,118>>,20>>,Stripes<20000,-1800,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,Mix<Int<18000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,HumpFlicker<Mix<Int<6000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>>,RgbArg<ALT_COLOR_ARG,Rgb<0,135,255>>,20>>>>,AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-6000>>>,ColorSelect<IntArg<SWING_OPTION_ARG,0>,TrInstant,AlphaL<StaticFire<Stripes<12000,-2000,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>,RotateColorsX<Int<200>,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>>,Mix<Int<16384>,Black,RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>,0,3,2,2000,8>,SmoothStep<Scale<HoldPeakF<Ifon<Scale<IsGreaterThan<SwingSpeed<500>,Int<16000>>,Int<2000>,SwingSpeed<300>>,Int<0>>,Scale<SwingAcceleration<>,Int<100>,Int<600>>,Scale<SwingAcceleration<>,Int<10000>,Int<4000>>>,Int<1000>,Int<40000>>,Int<-4000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<5000>,TrFade<300>>,AlphaL<AlphaL<AudioFlickerL<RgbArg<ALT_COLOR3_ARG,Rgb<180,130,0>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Scale<Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>,Int<28000>,Int<14000>>,Int<16000>>>,TrFade<300>>,EFFECT_FORCE>>,TransitionEffectL<TrSelect<IntArg<IGNITION_POWER_UP_ARG,0>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>,TrFade<1000>>,TrConcat<TrJoin<TrDelay<200>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<300>,AlphaL<Blue,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>,TrConcat<TrJoin<TrDelayX<IgnitionTime<0>>,TrInstant>,AlphaL<Stripes<5000,-2500,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>,Mix<Int<7710>,Black,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>>,Mix<Int<3855>,Black,Mix<NoisySoundLevel,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,Mix<Int<4096>,RgbArg<ALT_COLOR2_ARG,Rgb<255,0,0>>,White>>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>>,EFFECT_IGNITION>,TransitionEffectL<TrSelect<IntArg<RETRACTION_COOL_DOWN_ARG,0>,TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<5000,2500,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,Mix<Int<7710>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>>,TrFade<800>>,TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Remap<CenterDistF<>,Stripes<3000,-3500,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Black>,BrownNoiseFlicker<Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>,Mix<Int<3855>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<4096>>,Rgb<0,255,17>>,RotateColorsX<Scale<Sin<Int<20>>,Int<4096>,Int<0>>,Rgb<0,255,17>>>>>>>,TrFade<800>>>,EFFECT_RETRACTION>,TransitionPulseL<TrSelect<IncrementModuloF<EffectPulseF<EFFECT_USER1>,Int<2>>,TrInstant,TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Scale<RandomF,Int<1>,Int<-1>>>,Int<0>>,Int<-1>>>,ThresholdPulseF<SwingSpeed<320>,Int<31000>>>,TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>,Int<-1>>,EFFECT_USER1>,SparkleL<Black>,TransitionEffectL<TrRandom<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Remap<CenterDistF<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>>,TrConcat<TrInstant,AlphaMixL<Bump<EffectPosition<EFFECT_BLAST>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>>,EFFECT_BLAST>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,13431>,Int<-10000>>>,Int<13000>>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrSelect<IncrementWithReset<ThresholdPulseF<EffectPulseF<EFFECT_USER5>,Int<30000>>,EffectPulseF<EFFECT_RETRACTION>,Int<1>>,TrSelect<IntArg<IGNITION_OPTION_ARG,0>,TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,White>,BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,18992>,Int<98304>>>>,TrColorCycleX<BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,18992>,Int<98304>>>>,TrConcat<TrWipeInX<Mult<IgnitionTime<0>,Int<6553>>>,RandomBlink<30000,RgbArg<IGNITION_COLOR_ARG,White>>,TrJoin<TrDelayX<Mult<IgnitionTime<0>,Int<19660>>>,TrWipeInX<Mult<IgnitionTime<230>,Int<6553>>>>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,IntArg<EMITTER_SIZE_ARG,1000>,Sum<Int<5000>,IntArg<EMITTER_SIZE_ARG,1000>>>,Int<-3000>>,Black,RgbArg<IGNITION_COLOR_ARG,White>>,TrWipeX<Mult<IgnitionTime<0>,Int<19660>>>>>,TrInstant>,TrSelect<IntArg<RETRACTION_OPTION_ARG,0>,TrWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrCenterWipeInX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrJoin<TrCenterWipeX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>,Scale<BladeAngle<>,Int<6000>,Int<27000>>>,TrSmoothFadeX<BendTimePowInvX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>>>,TransitionEffectL<TrSelect<IntArg<OFF_OPTION_ARG,0>,TrConcat<TrInstant,AlphaL<White,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Orange,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Red,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>>,EFFECT_POSTOFF>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<300>>,EFFECT_BATTERY_LEVEL>,TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<100>>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<VolumeLevel,Int<-1>>>,TrFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

"preset5"
},




// { "aa_Kyberphonic/The_Duel/Ronin;common;commonBU", "The_Duel/tracks/track2.wav",
//   StylePtr<Layers<
//     HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // Postoff Emitter Cooldown
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb<255,50,50>,Bump<Int<0>,Int<3500>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Rgb<100,0,0>,Bump<Int<0>,Int<1000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "the\nduel"},


// { "aa_JayDalorian/OdaNobunaga;common;commonBU", "aa_JayDalorian/OdaNobunaga/tracks/sharingan.wav",
//   StylePtr<Layers<
//     AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<200>>,EFFECT_IGNITION>,
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // Postoff Emitter Cooldown
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb<255,50,50>,Bump<Int<0>,Int<3500>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Rgb<100,0,0>,Bump<Int<0>,Int<1000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "oda\nnobunaga"},

// { "aa_HarrySolo/Ronins_Path;common;commonBU", "tracks/FallenOrderTracks/JFO9.wav",
//   StylePtr<Layers<
//     StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<200>>,EFFECT_IGNITION>,
//     InOutTrL<TrWipeSparkTip<Rgb<200,100,100>,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "ronins\npath"},


// { "aa_Kyberphonic/Skoll;common;commonBU", "aa_Kyberphonic/Skoll/tracks/track1.wav",
// //Second Sister Base Red
//   StylePtr<Layers<
//     Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Mix<Int<16384>,OrangeRed,Black>>>,BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,OrangeRed>>,1>>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<100>>,EFFECT_IGNITION>,
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     // AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "skoll"},

//    { "aa_Kyberphonic/Great_Mother_V2;common;commonBU", "aa_Kyberphonic/Great_Mother_V2/tracks/track1.wav",
//     StylePtr<Layers<Black,
//       AlphaL<Mix<HoldPeakF<SwingSpeed<100>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<30000>,Int<10000>>>,
//         StaticFire<Mix<Int<16000>,Black,Green>,Mix<Int<16000>,Black,Rgb16<0,18927,65535>>,0,1,10,3000,2>,
//         StaticFire<Mix<Int<16000>,Black,Green>,Mix<Int<16000>,Black,Rgb16<0,18927,65535>>,0,3,10,3000,2>>,IsGreaterThan<BladeAngle<>,Int<16384>>>,
//       AlphaL<Mix<HoldPeakF<SwingSpeed<100>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<30000>,Int<10000>>>,
//         Remap<InvertF<RampF>,StaticFire<Mix<Int<16000>,Black,Green>,Mix<Int<16000>,Black,Rgb16<0,18927,65535>>,0,1,10,3000,2>>,
//         Remap<InvertF<RampF>,StaticFire<Mix<Int<16000>,Black,Green>,Mix<Int<16000>,Black,Rgb16<0,18927,65535>>,0,3,10,3000,2>>>,IsLessThan<BladeAngle<>,Int<16384>>>,
//       AlphaL<Black,LayerFunctions<Bump<Sin<Int<10>,Int<-10000>,Int<33000>>,Sin<Int<10>,Int<58000>,Int<48000>>>,Bump<Sin<Int<7>,Int<-1000>,Int<37000>>,Sin<Int<50>,Int<47000>,Int<38000>>>,Bump<Sin<Int<8>,Int<35000>,Int<-8000>>,Sin<Int<15>,Int<43000>,Int<35000>>>>>,
//       SparkleL<SpringGreen,150,50>,
//     // Force effect powerup. WavLen duration sync.
//     EffectSequence<EFFECT_FORCE,
//       TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<0,0,80>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Blue,Strobe<Black,Cyan,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>,
//       TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<0,80,0>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Green,Strobe<Black,GreenYellow,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>>,
//   // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//         AlphaL<Black,Int<16384>>,
//         AlphaL<Black,Int<0>>>,
//   // Clash 1 - BladeAngle responsive. Flash at impact, WavLen duration sync.
//     // Linear TrConcat version, now clash impact sized
//         TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<155,250,0>,Black,50>,White,TrInstant,TrFadeX<Percentage<WavLen<>,35>>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Scale<ClashImpactF<>,Int<4000>,Int<32768>>>>,TrFadeX<Percentage<WavLen<>,65>>>,EFFECT_CLASH>,
//    // Stab - OrangeRed stripes. WavLen duration sync.
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,30>>,AlphaL<Stripes<5000,1000,GreenYellow,DodgerBlue,Green,Chartreuse,Black,Green>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFadeX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeX<Percentage<WavLen<EFFECT_STAB>,70>>>>,EFFECT_STAB>,
//   // Blast
//     TransitionEffectL<TrConcat<
//         // Impact Flash - BC always
//         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//         // Waves
//         BlastL<DeepSkyBlue,850,250,351>,
//         // Impact point afterimage
//         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Cyan,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         // Impact point
//         BlastL<SpringGreen,300,350,100000>,
//   // Lockup 1 - BC custom range mid-blade to hilt w/random strobe flash
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//         //Random Strobe Flash no dimming
//         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//         // Bottom Layer Bump - random width
//         AlphaL<Blinking<Green,Strobe<Yellow,Black,15,30>,60,500>,                                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//         // Top Layer Bump - fixed width
//         AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Green,50>,100,500>,          Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,
//         // Begin Lockup Transition
//         TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//         // End Lockup Transition
//         TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//   // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
//     LockupTrL<Layers<
//         //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
//         AlphaL<Black,Int<16000>>,
//         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<
//         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//         // Begin Lightning Transition
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
//         // End Lightning Transition    
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//         // OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
//         AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
//         // Melt Shape
//         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
//         // Melt Begin and End transitions
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
// InOutTrL<TrWipe<1800>,TrWipe<1000>>,
// TransitionEffectL<TrConcat<TrJoin<TrCenterWipeInX<Int<200>>,TrJoin<TrWaveX<SpringGreen,Int<200>,Int<200>,Sum<Int<200>,Int<200>>,Int<0>>,TrWaveX<SpringGreen,Int<200>,Int<300>,Sum<Int<200>,Int<200>>,Int<32768>>>>,SparkleL<SpringGreen,650,80>,TrFade<3000>>,EFFECT_IGNITION>,
//     // Volume Level - gradient Blue -> Green
//       OnDemandVolumeLevel,
//     // On-Demand Battery Level
//       OnDemandBatteryLevel
//   >>(),
// "great_mother_v2"},


// { "aa_Syndicate/Synergy;common;commonBU", "aa_Syndicate/SithChant/tracks/music_from_the_dark_side_edit.wav",

// /* Synergy by Syndicate Customs. Bladestyle by NoSloppy 2023
// Preons matched to sounds via font's config.ini
// Swing Responsive effect.*/

// StylePtr<Layers<
//   /* Base blade */
//   StripesX<Int<300>,Int<-4500>,Black,RotateColorsX<Variation,Rgb16<13896,65,22546>>>,
//   AlphaL<StaticFire<Black,RotateColorsX<Variation,DarkOrange>,0,3,0,3000,70>,Int<16000>>,
//   /* Swing color */
//   AlphaL<Layers<
//     HumpFlicker<Black,RotateColorsX<Variation,Rgb16<13896,65,22546>>,3>,
//     AlphaL<RotateColorsX<Variation,DarkOrange>,SmoothStep<Int<4001>,Int<-10000>>>>,HoldPeakF<SwingSpeed<300>,Scale<SwingAcceleration<100>,Int<50>,Int<100>>,Scale<SwingAcceleration<>,Int<60000>,Int<10000>>>>,
//   /* Random surge */
//   TransitionLoop<AlphaL<Black,Int<0>>,TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<1500>,Int<5000>>>,AlphaL<Black,Int<0>>,TrSparkX<Mix<Int<25000>,Rgb<200,128,128>,Black>,Int<600>,Int<200>,Int<0>>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<13896,65,22546>>,Black,500>,TrFade<1000>>>,
//   /* Force effect powerup. WavLen duration sync. */
//   EffectSequence<EFFECT_FORCE,TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<0,0,80>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Blue,Strobe<Black,Cyan,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<0,80,0>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Green,Strobe<Black,GreenYellow,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>>,
//   /* Dim Blade 50% "Power Save" button combo */
//   EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<0>>>,
//   /* Clash 1 - BladeAngle responsive. Flash at impact, WavLen duration sync. Size based on impact strength */
//   TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFadeX<Percentage<WavLen<>,35>>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Scale<ClashImpactF<>,Int<4000>,Int<32768>>>>,TrFadeX<Percentage<WavLen<>,65>>>,EFFECT_CLASH>,
//   /* Stab - OrangeRed stripes. WavLen duration sync. */
//   TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,30>>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFadeX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeX<Percentage<WavLen<EFFECT_STAB>,70>>>>,EFFECT_STAB>,
//   /* Blast */
//   /* Impact Flash - BC always */ 
//   TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//   /* Waves */
//   BlastL<White,850,250,351>,
//   /* Impact point afterimage */
//   AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<255,70,70>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//   /* Impact point */
//   BlastL<White,300,350,100000>,
//   /* Lockup 1 - BC custom range mid-blade to hilt w/random strobe flash */
//   TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//   LockupTrL<Layers<
//     /*Random Strobe Flash no dimming */
//     AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//     /* Bottom Layer Bump - random width */
//     AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//     /* Top Layer Bump - fixed width */
//     AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     /* Begin Lockup Transition */
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     /* End Lockup Transition */
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//   /* Non-Responsive Drag - BC custom drag fadeout */
//   LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_DRAG>,
//   /* Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning) */
//   LockupTrL<Layers<
//     /*Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop */
//     AlphaL<Black,Int<16000>>,
//     AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//     AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//     /* Begin Lightning Transition */
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
//     /* End Lightning Transition */
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   /* Melt - BC custom melt effects, uses twistangle<>. For OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions) */
//   LockupTrL<
//     AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
//     /* Melt Begin and End transitions */
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
//   /* Ignition surge */
//   TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<600>>,EFFECT_IGNITION>,
//   /* Extension and retraction */
//   InOutTrL<TrWipeSparkTipX<Rgb<128,128,128>,BendTimePowInvX<Int<600>,Int<180000>>>,TrWipeInSparkTipX<AlphaL<DarkOrange,Scale<Trigger<EFFECT_RETRACTION,Percentage<WavLen<EFFECT_RETRACTION>,40>,Percentage<WavLen<EFFECT_RETRACTION>,60>,Int<1>>,Int<0>,Int<16000>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<150000>>>>,
//   /* PostOff effects - auto matched to which wav file is chosen */
//   ColorSelect<WavNum<EFFECT_POSTOFF>,TrInstant,
//     /* Emitter pop effect */
//     TransitionEffectL<TrConcat<TrInstant,TrWaveX<Orange,Int<125>,Int<400>,Int<500>,Int<0>>>,EFFECT_POSTOFF>,
//     /* Cool down emitter effect */
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<DarkOrange,Bump<Int<0>,Int<10000>>>,TrFadeX<Percentage<WavLen<>,50>>,AlphaL<DarkOrange,Bump<Int<0>,Int<8000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,25>>>,EFFECT_POSTOFF>>,
//   /* Preons matched to sounds via font's config.ini */
//   ColorSelect<WavNum<EFFECT_PREON>,TrInstant,
//    /* Preon 1 */
//     Layers<
//       TransitionEffectL<TrConcat<TrInstant,White,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipe<75>,AlphaL<BrownNoiseFlicker<DarkOrange,Black,200>,SmoothStep<Int<16384>,Int<-1>>>,TrCenterWipe<200>,Black,TrInstant,AlphaL<Rgb16<13896,65,22546>,SmoothStep<Scale<SlowNoise<Int<8000>>,Int<0>,Int<8000>>,Int<-1>>>,TrDelay<1410>,AlphaL<Stripes<300,-1000,Black,Rgb16<13896,65,22546>>,SmoothStep<Scale<SlowNoise<Int<6000>>,Int<4000>,Int<20000>>,Int<-1>>>,TrDelay<1100>,AlphaL<Black,Int<0>>,TrCenterWipeIn<1295>,RandomBlink<30000,Rgb16<13896,65,22546>>,TrSparkX<DarkOrange,Int<300>,Int<300>,Int<0>>,AlphaL<Black,Int<0>>,TrWipe<300>,AlphaL<RandomFlicker<Orange,Black>,Bump<Int<0>,Int<35000>>>,TrFade<370>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<1125>,AlphaL<Black,Int<0>>,TrFade<300>,StaticFire<Black,Strobe<Red,DarkOrange,75,35>,0,5,0,2500,25>,TrDelay<285>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<3020>,White,TrDelay<25>,RandomFlicker<Orange,Black>,TrFade<200>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<4565>,SparkleL<DarkOrange,200,2000>,TrFade<1550>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<6115>,AlphaL<Black,Int<0>>,TrFade<1164>,StaticFire<Black,Strobe<Red,DarkOrange,75,35>,0,5,0,2500,15>,TrInstant>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<6115>,AlphaL<Black,Int<0>>,TrWipeIn<635>,Stripes<300,-1000,Black,Rgb16<13896,65,22546>>,TrWipeIn<529>,Black,TrInstant,White,TrDelay<10>>,EFFECT_PREON>>,
//     /* Preon 2 */
//     Layers<
//       TransitionEffectL<TrConcat<TrColorCycle<4800,1>,Rgb16<13896,65,22546>,TrFade<100>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<1575>,AlphaL<Black,Int<0>>,TrCenterWipe<900>,RandomBlink<30000,Black,Rgb<128,0,0>>,TrCenterWipe<775>,Stripes<300,-4500,Black,Rgb16<13896,65,22546>>,TrInstant,BlinkingX<AlphaL<Stripes<3000,-4500,Black,DarkOrange>,Int<16000>>,Black,Int<100>,Int<500>>,TrDelay<800>,AlphaL<Stripes<3000,-4500,Black,DarkOrange>,Int<16000>>,TrFade<350>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<3888>,AlphaL<Black,Int<0>>,TrWipe<800>,StaticFire<Black,Strobe<Red,DarkOrange,75,35>,100,5,100,2500>,TrSparkX<DarkOrange,Int<100>,Int<100>,Int<32768>>>,EFFECT_PREON>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "synergy"},


// { "aa_Greyscale/Skotos_Greyscale;common;commonBU", "",
// StylePtr<Layers<
// // Base Fett263 Violet Audioflicker
//   AudioFlicker<RotateColorsX<Variation,Rgb<135,0,255>>,RotateColorsX<Variation,Rgb<67,0,115>>>,
// // Deep Violet HumpFlicker Swing Effect
//   AlphaL<HumpFlicker<RotateColorsX<Variation,Rgb<175,0,255>>,RotateColorsX<Variation,Rgb<97,0,135>>,20>,SwingSpeed<375>>,
// // BC less severe Unstable Charge-Up Ignition
// TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-1550,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFadeX<Percentage<WavLen<EFFECT_IGNITION>,35>>,TrInstant>,EFFECT_IGNITION>,
// // HumpFlicker Bright Retraction
//   TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<RotateColorsX<Variation,Rgb16<65535,42753,65535>>,RotateColorsX<Variation,White>,50>,TrInstant>,EFFECT_RETRACTION>,
//  BC_effects_1,
//   //BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// // False Start Preon
//  TransitionEffectL<TrConcat<TrInstant,Black,TrWaveX<RotateColorsX<Variation,Rgb<135,0,255>>,Int<1750>,Int<175>,Int<1575>,Int<-3000>>,Black,TrInstant>,EFFECT_PREON>,
// //Ripple Out Preon
//   TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_PREON>,43>>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb16<37981,16439,65535>>,Int<525>,Int<350>,Int<715>,Int<0>>>,TrFadeX<Percentage<WavLen<EFFECT_PREON>,55>>>,EFFECT_PREON>,
// // Noise Responsive Charge Up Preon
//   TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_PREON>,14>>,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb16<65535,42753,65535>>,150>,SmoothStep<Scale<NoisySoundLevel,Int<-1500>,Trigger<EFFECT_PREON,WavLen<EFFECT_PREON>,Int<0>,Int<0>>>,Int<-9500>>>,TrDelayX<Percentage<WavLen<EFFECT_PREON>,86>>>,EFFECT_PREON>,
// TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
// // BC Emitter White with audio pulses (hopefully) then blackout silence before end full blade noise
// TransitionEffectL<TrConcat<TrDelay<5500>,TrFade<440>,Black,TrDelay<560>,TrFade<230>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb16<65535,42753,65535>>,150>,TrDelay<290>>,EFFECT_PREON>
// >>(),
// "skotos"},


// { "a_INQUISITOR/2ndSistr;common;commonBU", "tracks/FallenOrderTracks/JFO5.wav",
// //Second Sister Base Red
//   StylePtr<Layers<
//     Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<100>>,EFFECT_IGNITION>,
//     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "second\nsister"},


// { "a_INQUISITOR/9thSistr;common;commonBU", "tracks/FallenOrderTracks/JFO7.wav",
// //Second Sister Base Red
//   StylePtr<Layers<
// Mix<SwingSpeed<500>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<150,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<180,0,0>>,0,2,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<100>>,EFFECT_IGNITION>,
//     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "ninth\nsister"},



// { "a_BANE/TheBane;common;commonBU", "a_BANE/tracks/track2.wav", // AudioFlicker Red Base Color Wheel Changeable
   
//   StylePtr<Layers<
//     AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//         // Ice Force
//     TransitionEffectL< 
//       TrConcat<TrFade<7000>,Rgb<10,0,75>,// blade turns solid cold 1000ms before ice full coverage
//       TrDelay<1000>>,EFFECT_USER2>,  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to Base color
//     TransitionEffectL< TrConcat<TrWipe<8000>, //wipe in stripes ice freezing effect
//     TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>,TrFade<11500>,TrDelay<20000>,EFFECT_USER2>, // Stripes fade to solid over remaining 4 seconds from freezing edge's finish until 12000 then hold for next joined delay to end at 15000, so 3000 more.
//       TrDelay<7000>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>, //after 15000 (TrConcat makes it 8000 + 7000) from effect start, full blade to this shade of white for wiping away (seamless color from end of stripes fade to solid)
//       TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>, // wipe ice away and melt to thinner opacity , but not 100%, leave like 30% by using longer fade duration than the wipe takes. 
//     TransitionEffectL<TrConcat<
//       TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,     Int<400>,  Int<50>, Int<1000>,Int<0>>,    // burst
//         TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,      Int<15000>,Int<400>,Int<8000>,Int<0>>,         // leading freeze edge
//         TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,    // crystalizing in edge's wake
//     AlphaL<Rgb<100,200,255>,Int<0>>,
//       TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,    Int<300>,  Int<50>, Int<1000>,Int<0>>,  // burst
//         TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>, // crystalizing in thaw's path
//         TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,     Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>, // leading thawing edge
//     // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//         AlphaL<Black,Int<16384>>,
//         AlphaL<Black,Int<0>>>,
//     // Clash 2 - for red blades
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//     // Stab - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//     // Blast v1
//     TransitionEffectL<TrConcat<
//         // Impact Flash - BC always
//         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//         // Waves
//         BlastL<Rgb<100,200,255>,850,250,351>,
//         // Impact point afterimage
//         //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         // Impact point
//         //BlastL<Rgb<100,200,255>,500,350,100000>,
//         BlastL<Rgb<100,200,255>,300,350,100000>,
//     // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//         //Random Strobe Flash no dimming
//         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//         //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<2>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         // Bottom Layer Bump - random width
//         AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
//         // Top Layer Bump - fixed width
//         AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                              Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//         // Begin Lockup Transition
//         TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,   Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//         // End Lockup Transition
//         TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                  Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//     // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
//     LockupTrL<Layers<
//        //Random Strobe Flash and 16000 = 50% Base blade dimming to make lb pop
//         AlphaL<Black,Int<16000>>,
//         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//         // Begin Lightning Transition
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//         // End Lightning Transition    
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//         AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//         // Melt Shape
//         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//         // Melt Begin and End transitions
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>, 
// // standard
//     // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "the\nbane"},



// { "a_BANE/RuleOfTwo;common;commonBU", "a_BANE/tracks/track3.wav", // AudioFlicker Red Base Color Wheel Changeable
   
//   StylePtr<Layers<
//     AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//     BC_effects_Red, 
// // standard
//     // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "rule of\ntwo"},



// { "a_SIDIOUS/TheReturn;common;commonBU", "tracks/Palpatheme_SHORT.wav",
//   StylePtr<Layers<
//     Mix<SwingSpeed<500>,AudioFlicker<Gradient<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red>,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,
//     BC_effects_Red,       
//       InOutTrL<TrConcat<TrWipe<200>,Strobe<Black,Rgb<100,100,155>,45,60>,TrJoinR<TrSmoothFade<190>,TrWipe<200>>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
//   >>(),    
// "the return\nof the sith"},




// { "a_DOOKU/Duke;common;commonBU", "a_DOOKU/tracks/Duke1_Short.wav",
//   StylePtr<Layers<
//     AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<100>>,EFFECT_IGNITION>,
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "dooku"},



// { "a_DOOKU/Dooku_CW;common;commonBU", "a_DOOKU/tracks/Duke2_Short.wav",
//   StylePtr<Layers<
//     RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,BrownNoiseFlickerL<Rgb<100,50,50>,Int<100>>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Rgb<100,50,50>>,TrFade<500>>,EFFECT_RETRACTION>,
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     // AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "clone wars\ndooku"}, 



// { "a_SAVAGE/Savage_Opress;common;commonBU", "tracks/Sister2_short.wav",
// //Second Sister Base Red
//   StylePtr<Layers<
//     Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<100>>,EFFECT_IGNITION>,
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     // AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "savage\nopress"},



// { "a_DARTH_MAUL/CrimsonMenace;common;commonBU", "a_DARTH_MAUL/tracks/Maul_Solo_Theme.wav", // AudioFlicker Red Base Color Wheel Changeable
   
//   StylePtr<Layers<
//     AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//     BC_effects_Red, 
// // standard
//     // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "darth\nmaul"},



// { "a_INQUISITOR/RevaUltimate;common;commonBU", "tracks/FallenOrderTracks/JFO9.wav",
//   StylePtr<Layers<
//     StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<100>>,EFFECT_IGNITION>,
//     InOutTrL<TrWipeSparkTip<Rgb<200,100,100>,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "reva\nltimate"},



// { "aa_Syndicate/SithChant;common;commonBU", "aa_Syndicate/SithChant/tracks/music_from_the_dark_side_edit.wav",
//   StylePtr<Layers<
//     Stripes<6000,-3000,RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<150,0,0>>>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<Rgb<128,128,128>>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Red,Black,500>,TrJoin<TrFade<1000>,TrWipe<800>>>,EFFECT_IGNITION>,
//     AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<228,128,128>,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
//     // AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "sith\nchant"},



// { "a_STARKILLER/Secret_Apprentice;common;commonBU", "a_STARKILLER/tracks/SKT4.wav", // AudioFlicker Red Base Color Wheel Changeable
   
//   StylePtr<Layers<
//     AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//         // Ice Force
//     TransitionEffectL< 
//       TrConcat<TrFade<7000>,Rgb<10,0,75>,// blade turns solid cold 1000ms before ice full coverage
//       TrDelay<1000>>,EFFECT_USER2>,  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to Base color
//     TransitionEffectL< TrConcat<TrWipe<8000>, //wipe in stripes ice freezing effect
//     TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>,TrFade<11500>,TrDelay<20000>,EFFECT_USER2>, // Stripes fade to solid over remaining 4 seconds from freezing edge's finish until 12000 then hold for next joined delay to end at 15000, so 3000 more.
//       TrDelay<7000>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>, //after 15000 (TrConcat makes it 8000 + 7000) from effect start, full blade to this shade of white for wiping away (seamless color from end of stripes fade to solid)
//       TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>, // wipe ice away and melt to thinner opacity , but not 100%, leave like 30% by using longer fade duration than the wipe takes. 
//     TransitionEffectL<TrConcat<
//       TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,     Int<400>,  Int<50>, Int<1000>,Int<0>>,    // burst
//         TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,      Int<15000>,Int<400>,Int<8000>,Int<0>>,         // leading freeze edge
//         TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,    // crystalizing in edge's wake
//     AlphaL<Rgb<100,200,255>,Int<0>>,
//       TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,    Int<300>,  Int<50>, Int<1000>,Int<0>>,  // burst
//         TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>, // crystalizing in thaw's path
//         TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,     Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>, // leading thawing edge
//     // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//         AlphaL<Black,Int<16384>>,
//         AlphaL<Black,Int<0>>>,
//     // Clash 2 - for red blades
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//     // Stab - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//     // Blast v1
//     TransitionEffectL<TrConcat<
//         // Impact Flash - BC always
//         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//         // Waves
//         BlastL<Rgb<100,200,255>,850,250,351>,
//         // Impact point afterimage
//         //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         // Impact point
//         //BlastL<Rgb<100,200,255>,500,350,100000>,
//         BlastL<Rgb<100,200,255>,300,350,100000>,
//     // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//         //Random Strobe Flash no dimming
//         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//         //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<2>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         // Bottom Layer Bump - random width
//         AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
//         // Top Layer Bump - fixed width
//         AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                              Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//         // Begin Lockup Transition
//         TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,   Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//         // End Lockup Transition
//         TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                  Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//     // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
//     LockupTrL<Layers<
//        //Random Strobe Flash and 16000 = 50% Base blade dimming to make lb pop
//         AlphaL<Black,Int<16000>>,
//         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//         // Begin Lightning Transition
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//         // End Lightning Transition    
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//         AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//         // Melt Shape
//         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//         // Melt Begin and End transitions
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>, 
// // standard
//     // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "starkiller"},



// { "aa_KSith/Aggression;common;commonBU", "tracks/FallenOrderTracks/JFO11a.wav", // colorchange 2 colors
//   StylePtr<Layers<
//     ColorChange<TrWipe<500>,StyleFire<BrownNoiseFlicker<Rgb<95,0,210>,RandomPerLEDFlicker<Rgb<42,0,105>,Rgb<21,0,52>>,300>,Rgb<10,0,26>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,StyleFire<Red,Rgb<60,0,0>,0,6,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>>,TrFade<1200>>,EFFECT_IGNITION>,
// // standard
//     // InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<100,200,255>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "starkiller"},



// { "a_KYLO/KyloUltimate;common;commonBU", "a_KYLO/KyloUltimate/tracks/Kylo1.wav",
//   StylePtr<Layers<
//     StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,150,150>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
//     InOutTrL<TrWipe<400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "kylo\nultimate"},    



// { "a_REY/Empress;common;commonBU", "a_REY/tracks/DarkReyBC.wav",
//   StylePtr<Layers<
//     HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "empress"}, 



// { "a_VADER/Father_V2/ANH;common;commonBU", "a_VADER/Father_V2/tracks/track1.wav",
//   StylePtr<Layers<
//     AudioFlicker<Red,Rgb<128,0,0>>,
//     BC_effects_Red,
//     InOutTrL<TrWipe<1000>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "father_v2\nanh"},



// { "aa_Greyscale/Seethe_Greyscale;common;commonBU", "",
//   StylePtr<Layers<
//   // Red audioflicker
//     AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,0,0>>>,
//   // Force effect, temporarily allows a swing effect where solid dark orange takes over the blade when swinging
//     TransitionEffectL<TrConcat<TrFade<200>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,SwingSpeed<500>>,TrDelay<30000>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,SwingSpeed<500>>,TrFade<800>>,EFFECT_FORCE>,
//   // Unstable swing
//     AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>,SwingSpeed<315>>,
//   // Timed "breathing" emitter flare
//     Mix<Sin<Int<8>>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,Bump<Int<0>,Int<6000>>>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,Bump<Int<0>,Int<22000>>>>,
//     BC_effects_Red,
// // standard
//   // Wipe out ignition, wipe in retraction
//     // InOutTrL<TrWipe<2650>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // BC_Bend with surge
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "seethe"},


// { "aa_Juansith/HATE;common;commonBU", "",
// //Second Sister Base Red
//   StylePtr<Layers<
//     Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
//     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "hate"},



// { "aa_Blueforce/IgnitionUltimate;common;commonBU", "",
// StylePtr<Layers<
//   Stripes<2000,-2500,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<30,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<30,0,0>>>>,
//   TransitionLoopL<TrConcat<TrWaveX<RandomFlicker<RotateColorsX<Variation,Red>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,Black,300>>,Int<400>,Int<100>,Int<200>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1500>>,Int<200>,Int<1200>>>>>,
//   AlphaL<BrownNoiseFlicker<Red,Black,300>,SwingSpeed<400>>,
//   BC_effects_Red,
//   InOutTrL<
//     TrConcat<TrInstant,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrWipe<300>,Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,Black,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<255,20,0>>,White>,RotateColorsX<Variation,Rgb<128,34,0>>>,TrFade<300>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,TrBoing<300,3>>,
//     TrConcat<TrInstant,BrownNoiseFlicker<White,DarkOrange,300>,TrFade<250>,AlphaL<Black,Int<0>>,TrJoin<TrWipeInX<Int<850>>,TrWaveX<White,Int<800>,Int<400>,Int<850>,Int<32768>>>>>,
// // Comment out this following line for non-stutter on actual ignition
//   //TransitionEffectL<TrConcat<TrWaveX<White,Int<800>,Int<200>,Int<300>,Int<0>>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrDelay<650>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrDelay<100>,BrownNoiseFlicker<White,Red,70>,TrFade<500>,Black,TrInstant>,EFFECT_IGNITION>,
//   TransitionEffectL<TrConcat<TrDelay<1100>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<50>>,EFFECT_RETRACTION>,
//   TransitionEffectL<TrConcat<
//     TrInstant,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrFade<100>,Black,
//     TrDelay<50>,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<50000>>>,TrDelay<150>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<70000>>>,TrFade<150>,Black,
//     TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<400>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<450>,Black,
    
//     TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<70000>>>,TrDelay<250>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<50000>>>,TrFade<200>,Black,
//     TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<500>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<600>,Black,

//     TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<10000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<5000>>>,TrFade<150>,Black,
//     TrDelay<350>,Black,
//     TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<10000>>>,TrDelay<70>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<5000>>>,TrFade<40>,Black,
//     TrDelay<20>,Black,

//     TrInstant,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrDelay<50>,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrFade<50>,Black,
//     TrDelay<50>,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<50000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<70000>>>,TrFade<150>,Black,
//     TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<300>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<400>,

//     AlphaL<BrownNoiseFlicker<White,Red,100>,Bump<Int<0>,Int<10000>>>,
//     TrFade<175>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<20000>>>,TrFade<175>,AlphaL<BrownNoiseFlicker<White,Red,100>,Bump<Int<0>,Int<10000>>>,
//     TrFade<115>,AlphaL<BrownNoiseFlicker<White,DarkOrange,100>,Bump<Int<0>,Int<40000>>>,TrFade<115>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<20000>>>,
//     TrFade<100>,AlphaL<BrownNoiseFlicker<White,DarkOrange,100>,Bump<Int<0>,Int<60000>>>,TrFade<100>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<40000>>>,
//     TrFade<75>,BrownNoiseFlicker<White,DarkOrange,300>,TrFade<50>,Black,TrFade<50>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Rgb<200,150,150>,20>,
//     TrSmoothFade<100>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "ignition\nultimate"},


// { "aa_HarrySolo/AGONY;common;commonBU", "",
//   StylePtr<Layers<
//     HumpFlicker<Blue,Stripes<22000,-100,RotateColorsX<Variation,Rgb<48,0,105>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<22,0,49>>>,10>,
//     BC_effects_Red,
//     InOutTrL<TrJoin<TrWipeX<Int<600>>,TrWaveX<White,Int<1200>,Int<400>,Int<600>,Int<0>>>,
//              TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,150>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
     
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<200>>,EFFECT_IGNITION>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,10>,Bump<Int<0>,Int<4000>>>,TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,15>,Bump<Int<0>,Int<5000>>>,TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,20>,Bump<Int<0>,Int<6000>>>,TrFade<1000>>,EFFECT_PREON>,Ifon<Int<0>,Int<32768>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "agony"},


// { "aa_KSith/Proto;common;commonBU", "",
//   StylePtr<Layers<
// // Main Blade
//     // Jedi Base Orange
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,DarkOrange>,Pulsing<RotateColorsX<Variation,Rgb<90,24,0>>,RotateColorsX<Variation,DarkOrange>,800>,RotateColorsX<Variation,DarkOrange>>,
//     // Jedi Force Orange
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<160,43,0>>>,TrDelay<3000>,RotateColorsX<Variation,DarkOrange>,TrFade<800>>,EFFECT_FORCE>,
//     // Jedi Swing Orange
//     AlphaL<RotateColorsX<Variation,Rgb<255,178,110>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     BC_effects_1,
// // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "proto"},




// { "aa_KSith/Desolation;common", "tracks/FallenOrderTracks/JFO12.wav",
//   StylePtr<Layers<
// // Main Blade
//     // Jedi base Yellow
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<180,180,0>>,Pulsing<RotateColorsX<Variation,Rgb<64,64,0>>,RotateColorsX<Variation,Rgb<180,180,0>>,800>,RotateColorsX<Variation,Rgb<180,180,0>>>,
//     // Jedi Force Yellow
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<113,113,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<180,180,0>>,TrFade<800>>,EFFECT_FORCE>,
//     // Jedi Swing Yellow
//     AlphaL<RotateColorsX<Variation,Rgb<230,180,80>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// BC_effects_Red,
// // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Yellow,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "desolation"},




// { "aa_KSith/Ascension;common;commonBU", "tracks/battleofheros.wav",
//   StylePtr<Layers<
//     StripesX<Int<3000>,Int<-3000>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,60>>,RotateColorsX<Variation,Rgb<50,50,255>>,RotateColorsX<Variation,Rgb<0,0,128>>>,
//     AlphaL<Rgb<100,100,255>,SwingSpeed<600>>,
//     BC_effects_1,
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<100,200,255>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "ascension"},



// { "Arcane;common;commonBU", "",
//   StylePtr<Layers<
//     HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "arcane"}, 



// { "aa_KSith/Traveler;common;commonBU", "tracks/FallenOrderTracks/JFO3.wav",
//   StylePtr<Layers<
//     Mix<SwingSpeed<500>,AudioFlicker<Gradient<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red>,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,
//     BC_effects_Red,       
//     InOutTrL<TrConcat<TrWipe<200>,Strobe<Black,Rgb<100,100,155>,45,60>,TrJoinR<TrSmoothFade<190>,TrWipe<200>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "traveler"},




// { "GhostsOfTheGrey;common;commonBU", "", 
//   StylePtr<Layers<
//     StripesX<Int<6000>,Int<-1000>,RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<24,24,35>>>,AlphaL<White,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     AlphaL<Stripes<4000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Black>,White,RotateColorsX<Variation,Rgb<100,100,150>>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     BC_effects_White,  
//     InOutTrL<TrWipe<400>,TrConcat<TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,50>>,Stripes<3000,2000,White,Rgb<100,100,100>>,TrFadeX< Percentage<WavLen<EFFECT_RETRACTION>,50> >>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "ghosts of\nthe grey"},   


// { "aa_LordBlako/PitchBlk;common;commonBU", "tracks/MSV.wav",

// //Second Sister Base Red
//   StylePtr<Layers<
//     Mix<SwingSpeed<300>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,Black>,300>,RotateColorsX<Variation,Rgb<40,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,AudioFlicker<RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Rgb<20,0,0>>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Rgb<100,200,255>>,TrFade<1000>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Rgb<100,200,255>,50>,TrFade<1000>>,EFFECT_IGNITION>,
//     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<100,200,255>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// // Emitter cooldown
//     TransitionEffectL<TrConcat<TrInstant,
//       AlphaL<Rgb<100,200,255>,Bump<Int<0>,Int<6000>>>,TrFadeX<  Int<1875> >,
//       AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFadeX<  Int<1875> >,
//       AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX< Int<3750> >>,EFFECT_RETRACTION>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "pitch\nblack"},



// { "a_PONG_KRELL/PongKrll;common;commonBU", "a_PONG_KRELL/tracks/Krell.wav",
//   StylePtr<Layers<
//     Pulsing<Yellow,Chartreuse,20>,
//     BC_effects_1,
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
//   "pong\nkrell"},


// { "Proto2;common;commonBU", "Proto2/tracks/proto2.wav", // Color Cycle to Glitchy Pulsing Blade Default = Green
//   StylePtr<Layers<   
//       ColorCycle<RotateColorsX<Variation,Rgb<0,128,0>>,100,-3250,RotateColorsX<Variation,BlinkingX<RandomFlicker<RandomBlink<13000,RotateColorsX<Variation,Rgb<128,200,128>>,RotateColorsX<Variation,Black>>,RotateColorsX<Variation,Green>>,RandomFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<30,30,30>>>,Scale<SlowNoise<Int<16000>>,Int<300>,Int<1000>>,Scale<SlowNoise<Int<16000>>,Int<200>,Int<650>>>>,50,3000,3000>,
//       BC_effects_1,
//       TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//       TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//       InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "proto 2"},




// { "PsyBorg;common;commonBU", "tracks/FallenOrderTracks/JFO7.wav",
//   StylePtr<Layers<
// // Main Blade - variation applied 21844 (green)
//     // Jedi base Blue
// StripesX<Int<16000>,Int<-1000>,RotateColorsX<Int<21844>,Blue>,Pulsing<RotateColorsX<Int<21844>,Rgb<0,0,90>>,RotateColorsX<Int<21844>,Blue>,800>,RotateColorsX<Int<21844>,Blue>>,
//     // Jedi Force Blue
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
//     // Jedi Swing Blue
//     AlphaL<RotateColorsX<Variation,Rgb<70,70,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// BC_effects_1,
// // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "psyborg"},



// { "a_DARKSABER/DarkV3;common;commonBU", "a_DARKSABER/DarkV3/tracks/Mandalorian.wav",
//   StylePtr<Layers<
//     Mix<SwingSpeed<400>,RotateColorsX<Variation,Rgb<80,100,150>>,RotateColorsX<Variation,Rgb<130,150,225>>>,
//     BrownNoiseFlickerL<Stripes<5000,-300,RotateColorsX<Variation,Rgb<15,25,55>>,RotateColorsX<Variation,Rgb<60,75,120>>,RotateColorsX<Variation,Rgb<0,10,20>>,RotateColorsX<Variation,Rgb<40,50,75>>>,Int<38400>>,
//     AudioFlickerL<RotateColorsX<Variation,Rgb<25,35,75>>>,
//     AlphaL<RotateColorsX<Variation,Rgb<155,175,225>>,SwingSpeed<600>>,
//     BC_effects_White,
//    // InOutTrL<TrWipeSparkTipX<White,BendTimePowInvX<Int<1000>,Int<180000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//      // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "   dark\n    v3"},



// { "aa_Blueforce/LiquidStatic;common;commonBU", "",
//   StylePtr<Layers<
//     StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Blue,Mix<Int<2570>,Black,Blue>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Blue>,Black>>,Mix<Int<7710>,Black,Blue>,Pulsing<Mix<Int<6425>,Black,Blue>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Blue,Mix<Int<12000>,Black,Blue>>,2000>,Pulsing<Mix<Int<16448>,Black,Blue>,Mix<Int<642>,Black,Blue>,3000>>,
//     AlphaL<StaticFire<Blue,Mix<Int<256>,Black,Blue>,0,1,10,2000,2>,Int<10000>>,
//     AlphaL<LightCyan,SmoothStep<Int<2000>,Int<-6000>>>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1200>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Blue,RandomPerLEDFlicker<Mix<Int<7710>,Black,Blue>,Black>,BrownNoiseFlicker<Blue,Mix<Int<3855>,Black,Blue>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Blue>,Mix<Int<3855>,Black,Blue>>>,TrInstant>,EFFECT_RETRACTION>,
//     BC_effects_1,
//     InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTipX<LightCyan,WavLen<EFFECT_RETRACTION>,Int<401>>>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "liquid\nstatic"},

     

};


BladeConfig blades[] = {
{ 144,
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
CONFIGARRAY(Ronin), 
"01_Ronin_save"}, 

};

#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

// // Button connect to 3.3v instead of GND. Up to 5v is OK
// PullDownButton PowerButton(BUTTON_POWER, powerButtonPin, "pow"); // isn't this backwards?

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

