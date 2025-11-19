// BC_Reva_7.x 

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 1
// #define DUAL_POWER_BUTTONS                        // BC Make both buttons identical for 1-btn use... useful? **not working 100%

// ------ Audio Stuff --------

#define VOLUME 1500
#define BOOT_VOLUME 200
#define ENABLE_AUDIO
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                     // SPDIF out
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8
// #define FEMALE_TALKIE_VOICE                      // BC now canon OS6
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
// #define SHARED_POWER_PINS
#define BLADE_DETECT_PIN blade3Pin
// #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9>         // TX pad
//    This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
//    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value, so I would recommend using something like 200000 instead of NO_BLADE.
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> 
//    Millis is BladeID scan interval. If the blade ID comes out the same as before, it will do nothing.
//    If it comes out different, it will do FindBladeAgain(), which will basically initialize the saber from scratch and load the right settings for the new id().
//    It will only work with neopixel blades, and it probably requires SHARED_POWER_PINS to work.
// #define BLADE_ID_SCAN_MILLIS 1000

// ------ SD Card Stuff -------

#define ENABLE_SD
// #define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING            // upload overwrites presets.ini/tmp unless this is defined

// ------- OLED stuff ----------

// #define ENABLE_SSD1306                         // OLED display. also defines ENABLE_DISPLAY_CODE
// #define OLED_FLIP_180                              // BC now canon
// #define OLED_MIRRORED
// #define USE_AUREBESH_FONT                          // BC now canon
// #define OLED_SYNCED_EFFECTS
// #define PLI_OFF_TIME 60 * 5 * 1000
// #define OLED_USE_BLASTER_IMAGES
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144_SC_POV_data.h"
// #define POV_INCLUDE_FILE "Raiden_123_FC_POV_data.h"
// #define POV_INCLUDE_FILE "JohnCena_144_8b_POV_data.h"
// #define DISPLAY_POWER_PINS PowerPINS<bladePowerPin6> // turns power to the OLED display off once SCREEN_OFF state. (Either IDLE_OFF_TIME or PLI_OFF_TIME)

// ------ System Stuff --------

// #define ENABLE_DEBUG
// #define NO_BATTERY_MONITOR
// #define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
// #define ENABLE_DEVELOPER_COMMANDS
#define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 5 * 1000
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

// #define CONFIG_STARTUP_DELAY 15000                 // BC now canon
#define DISABLE_BASIC_PARSER_STYLES                 // Standard, Advanced, Old School original templated styles etc...

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3.5
#define BC_SWING_ON                                 // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
// #define BC_STAB_ON
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                     // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS
#define ENABLE_AUTO_SPINS_BLAST                     // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
// #define NO_BLADE_NO_GEST_ONOFF                   // If using blade detect, No Blade = No Gesture ignitions or retractions

// ------- Custom / Experimental / Alpha-Beta stuff ---------

// #define ENABLE_GESTURE_MENU                        // PSISTORM prop - cool stuff! the TrySound else beep void.  

// -------- BC Prop Other Stuff --------

// #define NO_VOLUME_MENU                             // self evident. But why?

// -------- Blaster Stuff ----------

// #define ENABLE_BLASTER_AUTO
// #define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
// #define BLASTER_JAM_PERCENTAGE 10     // if not defined, random.

#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS 
#include "aliases/TrueWhites/BC_effects_Red_Main.h"       // For main staff blade
#include "aliases/TrueWhites/BC_effects_Red_Alt.h"        // For 2nd staff blade

// save mem by disabling unused aliases? nope..
#include "aliases/TrueWhites/BC_effects_1.h"              // For Green, light Blue, ...light colored blades
#include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"  // EffectSequence driven different blast animations
// #include "aliases/TrueWhites/BC_effects_2.h"              // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"            // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_White.h"          // For White blades
#include "aliases/TrueWhites/BC_12color_8effect_SS.h"     // Uses BC_SWAP for base blade color. All in one blade style from CC Fork. 96 possible blade combos in one style. .

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;


/*__Presets List___




*/


Preset Reva[] = {

{ "a_INQUISITOR/RevaUltimate;common;commonBU", "a_INQUISITOR/tracks/Inquisitor_Theme.wav",

  // StylePtr<Layers<
    // StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
  // BC_effects_Red,
  //   InOutTrL<TrWipeSparkTipX<White,Int<300>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  //   // Volume Level - gradient Blue -> Green
  //     OnDemandVolumeLevel,
  //   // On-Demand Battery Level
  //     OnDemandBatteryLevel
  // >>(),

// Blade 1
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
    BC_effects_Red_Main,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<600>>,EFFECT_IGNITION>,
    InOutTrL<TrWipeSparkTip<Rgb<200,100,100>,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>,
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),

// Blade 2
  StylePtr<Layers<
// Used to toggle base color on-off.
  EffectSequence<EFFECT_USER4,
// The following Layers<> contains primary blade style stuff, 
// from the base blade color down to, but not including, the InOutTrL.
  Layers< // on press, this color becomes active.
  StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
  BC_effects_Red_Alt,
  // pseudo EFFECT_IGNITION
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_USER4>
  >,
// -------------------
// EffectSequence starts here at power on of main blade.
  Black>,
  EffectSequence<EFFECT_USER4,
    // pseudo extension wipe
    TransitionEffectL<TrConcat<TrInstant,Black,TrWipe<500>>,EFFECT_USER4>,     
    TransitionEffectL<TrConcat<TrInstant,
    // The following color should be the same as the base blade color layer
// -------------------
  StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
// -------------------
  TrJoin<
    // pseudo EFFECT_RETRACTION
    TrConcat<TrFadeX<WavLen<>>,AudioFlickerL<White>,TrInstant>,
    // pseudo retraction wipe (for 2nd blade discrete retraction before actual power off.)
    TrWipeInX<WavLen<>>>>,EFFECT_USER4>>,
  InOutTrL<TrInstant,TrWipeInX<WavLen<EFFECT_RETRACTION>>>
>>(),
// Hilt LEDs
  StylePtr<Layers<
    Stripes<1000,-300,Red,Rgb<128,0,0>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<90,0,0>,Red,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Red,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<White,Black,50>,TrInstant>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,Red,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>
  >>()
  "reva\nultimate"},


 { "a_INQUISITOR/Third;common;commonBU", "a_INQUISITOR/Third/tracks/track2.wav",
// Blade 1
  StylePtr<Layers<
        StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
    BC_effects_Red_Main,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<600>>,EFFECT_IGNITION>,
    InOutTrL<TrWipeSparkTip<Rgb<200,100,100>,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),

// Blade 2
  StylePtr<Layers<
    EffectSequence<EFFECT_USER4, // Used to toggle base color on-off.
      // The following COLOR can be replaced by a Layers<> containing your primary blade style stuff, 
      // from the base blade color down to, but not including, the InOutTrL.
// -------------------
Layers< // on press
      StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
  BC_effects_Red_Alt,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_USER4> // pseudo EFFECT_IGNITION
>,
// -------------------
      Black // starts here at power on of main blade
    >,
    EffectSequence<EFFECT_USER4,
      TransitionEffectL<TrConcat<TrInstant,Black,TrWipe<500>>,EFFECT_USER4>, // pseudo extension wipe     
      TransitionEffectL<TrConcat<TrInstant,
      // This color should be the same as the base blade color layer
// -------------------
        StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
// -------------------
          TrJoin<
            TrConcat<TrFadeX<WavLen<>>,AudioFlickerL<White>,TrInstant>, // pseudo EFFECT_RETRACTION
            TrWipeInX<WavLen<>>>>,EFFECT_USER4>                         // pseudo retraction wipe (for 2nd blade discrete retraction before actual power off.)
    >,
    InOutTrL<TrInstant,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
// Hilt LEDs
  StylePtr<Layers<
    Stripes<1000,-300,Red,Rgb<128,0,0>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<90,0,0>,Red,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Red,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<White,Black,50>,TrInstant>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,Red,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>
  >>()
  "third"},

{ "aa_Blueforce/CyberAssassin2;common;commonBU", "",
// Blade 1
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Green,Mix<Int<2570>,Black,Green>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Green>,Black>>,Mix<Int<7710>,Black,Green>,Pulsing<Mix<Int<6425>,Black,Green>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Green,Mix<Int<12000>,Black,Green>>,2000>,Pulsing<Mix<Int<16448>,Black,Green>,Mix<Int<642>,Black,Green>,3000>>,
    AlphaL<StaticFire<Green,Mix<Int<256>,Black,Green>,0,1,10,2000,2>,Int<10000>>,
    AlphaL<Chartreuse,SmoothStep<Int<2000>,Int<-6000>>>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Green,RandomPerLEDFlicker<Mix<Int<7710>,Black,Green>,Black>,BrownNoiseFlicker<Green,Mix<Int<3855>,Black,Green>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Green>,Mix<Int<3855>,Black,Green>>>,TrInstant>,EFFECT_RETRACTION>,
    BC_effects_1_Main,
    InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTipX<Chartreuse,WavLen<EFFECT_RETRACTION>,Int<401>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
// Blade 2
  StylePtr<Layers<
    EffectSequence<EFFECT_USER4, // Used to toggle base color on-off.
      // The following Layers<> contains your primary blade style stuff, 
      // from the base blade color down to, but not including, the InOutTrL, and minus any EFFECT_RETRACTION layers.
Layers< // ------------------- on press
  StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Green,Mix<Int<2570>,Black,Green>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Green>,Black>>,Mix<Int<7710>,Black,Green>,Pulsing<Mix<Int<6425>,Black,Green>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Green,Mix<Int<12000>,Black,Green>>,2000>,Pulsing<Mix<Int<16448>,Black,Green>,Mix<Int<642>,Black,Green>,3000>>,
  AlphaL<StaticFire<Green,Mix<Int<256>,Black,Green>,0,1,10,2000,2>,Int<10000>>,
  AlphaL<Chartreuse,SmoothStep<Int<2000>,Int<-6000>>>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1200>>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Green,RandomPerLEDFlicker<Mix<Int<7710>,Black,Green>,Black>,BrownNoiseFlicker<Green,Mix<Int<3855>,Black,Green>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Green>,Mix<Int<3855>,Black,Green>>>,TrInstant>,EFFECT_USER4>,
  BC_effects_1_Alt
>, // -------------------
    Black>, // Starts Here
    EffectSequence<EFFECT_USER4,TransitionEffectL<TrConcat<TrInstant,Black,TrWipe<500>>,EFFECT_USER4>,TransitionEffectL<TrConcat<TrInstant, // toggled pseudo extension wipe 
// ------------------- This color should be the same as the base blade color layer
Layers<
  StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Green,Mix<Int<2570>,Black,Green>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Green>,Black>>,Mix<Int<7710>,Black,Green>,Pulsing<Mix<Int<6425>,Black,Green>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Green,Mix<Int<12000>,Black,Green>>,2000>,Pulsing<Mix<Int<16448>,Black,Green>,Mix<Int<642>,Black,Green>,3000>>,
  AlphaL<StaticFire<Green,Mix<Int<256>,Black,Green>,0,1,10,2000,2>,Int<10000>>,
  AlphaL<Chartreuse,SmoothStep<Int<2000>,Int<-6000>>>
>,// -------------------
    TrJoin<TrConcat<TrFadeX<WavLen<>>,AudioFlickerL<White>,TrInstant>,TrWipeInX<WavLen<>>>>,EFFECT_USER4>>,// toggled pseudo retraction wipe (for 2nd blade discrete retraction before actual power off.)
    InOutTrL<TrInstant,TrWipeInX<WavLen<EFFECT_RETRACTION>>>
  >>(),

// Sides
  StylePtr<Layers<
    Stripes<1000,-300,Green,Rgb<0,128,0>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<0,90,0>,Green,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<80,255,80>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
    LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Red,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>,TrConcat<TrWipeIn<100>,BrownNoiseFlicker<Red,Black,300>,TrExtend<1000,TrFade<3000>>,Mix<TwistAngle<>,Red,Orange>,TrFade<3000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<White,Black,50>,TrInstant>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,Green,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Green,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Green,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>
  >>(),
"cyber\nassassin2"},






};


BladeConfig blades[] = {
 { 0, // CT_A 132 BC_A 123
  WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  WS281XBladePtr<8, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(),
  CONFIGARRAY(Vektra),
  "00_Vektra_save" }

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "aux");
Button AuxButton(BUTTON_AUX, auxPin, "pow");
#endif


// // Button connect to 3.3v instead of GND. Up to 5v is OK
// PullDownButton PowerButton(BUTTON_POWER, powerButtonPin, "pow"); // isn't this backwards?

// // Analog Potentiometer 
// ChangeVolumeAnalogReceiver volume_function;
// PotClass pot(0, &volume_function);

// // Or, you can use it to change the variation (color):

// ChangeVariationAnalogReceiver variation_function;
// PotClass pot(0, &variation_function);

// // Rotary Encoder (see rotary.h)

// ChangePresetRotaryReceiver rotary_receiver;
// Rotary<8, 9> rotary(&rotary_receiver);
/*
The receiver decides what the rotary events do.
There are currently receivers for changing presets, 
changing variation and one that just prints things out. 
More receivers can be added as needed. 
(I should probably create one for changing the volume.)

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
  WriteBulletCountOp<10, 20, 3>
> display_controller;
SSD1306Template<64, uint32_t> display(&display_controller);
#endif


- what's the diff between that and then this?:

Support for 128x64 OLED
#ifdef CONFIG_BOTTOM
SSD1306Template<128, uint64_t> display(0x3C);
#endif
*/
