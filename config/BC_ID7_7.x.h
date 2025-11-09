// BC_ID7_7.x

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 1
// #define DUAL_POWER_BUTTONS   ****not working fully, only power     // BC Make both buttons identical for 1-btn use... useful?

// ------ Audio Stuff --------

#define VOLUME 1200
#define BOOT_VOLUME 200
#define ENABLE_AUDIO
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                    // SPDIF out
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8
// #define FEMALE_TALKIE_VOICE                       // BC now canon OS6
#define NO_REPEAT_RANDOM                          // BC now canon
#define KILL_OLD_PLAYERS                          // BC now canon
#define DISABLE_TALKIE                            // I feel I'm not gonna like this

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
// New define that can speed up processing a bit. Basically, it can calculate the colors for the next
// blade (or the next frame for the same blade) even though it's not done feeding out the data for the
// data in the color buffer yet. Equivalent to just increasing maxLedsPerStrip.
#define EXTRA_COLOR_BUFFER_SPACE 30
// #define SHARED_POWER_PINS
// #define BLADE_DETECT_PIN blade3Pin
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
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING          // upload overwrites presets.ini/tmp unless this is defined

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
// #define BC_SWING_ON                                 // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
// #define BC_STAB_ON
#define BC_THRUST_ON
// #define BC_TWIST_ON
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

// #define ENABLE_GESTURE_MENU                      // PSISTORM prop - cool stuff! the TrySound else beep void.  

// -------- BC Prop Other Stuff --------

// #define NO_VOLUME_MENU                           // self evident. But why?

// -------- Blaster Stuff ----------

// #define ENABLE_BLASTER_AUTO
// #define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
// #define BLASTER_JAM_PERCENTAGE 10     // if not defined, random.

#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
//#include "../scripts/motion_startup_recorder.h"
#endif

#ifdef CONFIG_PRESETS

#include "aliases/TrueWhites/BC_effects_1.h"              // For Green, light Blue, ...light colored blades
// #include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"  // EffectSequence driven different blast animations
// #include "aliases/TrueWhites/BC_effects_2.h"              // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"            // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_White.h"          // For White blades
// #include "aliases/TrueWhites/BC_12color_8effect_SS.h"     // Uses BC_SWAP for base blade color. All in one blade style from CC Fork. 96 possible blade combos in one style. .

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

/* __Presets List___
1. aa_Syndicate/MachineCity
2. aa_HarrySolo/KAIJU
3. aa_HarrySolo/DESTABILIZE
4. aa_HarrySolo/STASIS
5. aa_JayDalorian/OdaNobunaga
6. aa_JayDalorian/Blastermode
7. aa_JayDalorian/Decimate (collab)
8. aa_Kyberphonic/Metamorphose
9. aa_NoSloppy/TheMaw
10. aa_Juansith/Red_Five
*/

Preset ID7 [] = {

{ "aa_Syndicate/MachineCity;common;commonBU", "aa_Syndicate/MachineCity/tracks/bluepill.wav",
   
  // Syndicate Custom Relics - Machine City Proffie Bade Style - BC 2022
 
  StylePtr<Layers<
    StyleFire<Strobe<Black,Strobe<Black,RandomPerLEDFlicker<SpringGreen,Black>,50,1>,100,1>,Green,0,5,FireConfig<0,2000,5>,FireConfig<0,2000,0>,FireConfig<200,1000,10>,FireConfig<0,2000,5>>,
    BC_effects_Red,
      InOutTrL<TrWipeSparkTipX<White,Int<300>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
      TransitionEffectL<TrConcat<TrWipeX<Int<100>>,AlphaL<StaticFire<Rgb<100,255,100>,Rgb<60,100,60>,0,8>,Bump<Int<6000>,Int<40000>>>,TrFade<134>,AlphaL<StaticFire<Strobe<Black,Strobe<Black,RandomPerLEDFlicker<Green,Black>,50,1>,100,1>,Green,0,5>,Bump<Int<6000>,Int<40000>>>,TrWipeInX<Int<200>>,Black,TrDelay<100>,Black,TrBoing<650,6>,Strobe<Black,RandomPerLEDFlicker<Green,Black>,50,1>,TrInstant>,EFFECT_PREON>,
    // Volume Level - gradient Blue -> Green
      OnDemandVolumeLevel,
    // On-Demand Battery Level
      OnDemandBatteryLevel
    >>(),
"machine\n  city"},

// --------------------------------

{ "aa_HarrySolo/KAIJU;common;commonBU", "",
// Harry Solo - Kaiju Blade StyleV2 - BC 2022
  StylePtr<Layers<
    Black,
    AlphaL<Stripes<40000,-100,Pulsing<Black,TransitionLoop<Black,TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<300>,Int<1000>>>,Black,TrWipeInSparkTipX<White,Int<300>>>>,1500>,Pulsing<Black,TransitionLoop<AlphaL<AlphaL<Green,Int<16000>>,Int<10000>>,TrConcat<TrBoing<500,2>,Black,TrJoin<TrWipeInSparkTipX<White,Int<300>>,TrWipeSparkTipX<White,Int<300>>>>>,1500>,Pulsing<Black,TransitionLoop<Black,TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<300>,Int<1000>>>,Black,TrJoin<TrWipeInSparkTipX<White,Int<300>>,TrWipeSparkTipX<White,Int<300>>>>>,1500>>,Int<16000>>,
    AlphaL<Stripes<250,1,Green,Black>,LayerFunctions<Bump<Int<0>,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<70000>>,Int<500>,Int<18000>>>,Bump<Int<16384>,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<70000>>,Int<500>,Int<18000>>>,Bump<Int<32768>,Scale<ChangeSlowly<SlowNoise<Int<3000>>,Int<70000>>,Int<500>,Int<18000>>>>>,
    AlphaL<PulsingL<Stripes<250,1,Black,Rgb<25,10,255>>,Int<600>>,LayerFunctions<Bump<Int<0>,Int<12000>>,Bump<Int<16384>,Int<12000>>,Bump<Int<32768>,Int<12000>>>>,
  // Swing color
    AlphaL<Stripes<2800,1,Blue,Cyan,Rgb<128,128,128>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    BC_effects_Red,
  // Ignition and Retraction
    TransitionEffectL<TrConcat<TrJoin<TrWipeX<Int<200>>,TrWaveX<White,Int<200>,Int<400>,Int<200>,Int<0>>>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>,StyleFire<Rgb<100,200,255>,Rgb<60,60,60>,0,8>,TrFadeX<Int<1700>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,Cyan,TrDelay<100>,AlphaL<Black,Int<0>>,TrDelay<70>,Green,TrDelay<100>,AlphaL<Black,Int<0>>,TrDelay<70>,Yellow,TrDelay<100>,AlphaL<Black,Int<0>>,TrDelay<70>,Magenta,TrDelay<100>,AlphaL<Black,Int<0>>,TrDelay<70>,White,TrDelay<100>>,EFFECT_RETRACTION>,
    InOutTrL<TrWipe<200>,TrColorCycle<1374>>,
  // Preon
    TransitionEffectL<TrConcat<TrDelay<3526>,AlphaL<Black,Int<0>>,TrFade<400>,AlphaL<HumpFlicker<White,Red,100>,Bump<Int<16384>,Int<40000>>>,TrFade<300>,SparkleL<Red,600,300>,TrFade<400>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<3038>,AlphaL<Black,Int<0>>,TrFade<200>,Stripes<1000,7000,Blue,Cyan,Blue,Black,Black,Black,Black>,TrDelay<300>,Stripes<1000,7000,Blue,Cyan,Blue,Black,Black,Black,Black>,TrFade<219>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrFade<217>,AlphaL<BrownNoiseFlicker<Red,Black,500>,Bump<Int<0>>>,TrFade<217>,AlphaL<Black,Int<0>>,TrFade<217>,AlphaL<BrownNoiseFlicker<Red,Black,500>,Bump<Int<0>,Int<50000>>>,TrFade<217>,AlphaL<Black,Int<0>>,TrFade<217>,AlphaL<BrownNoiseFlicker<Red,Black,500>,Bump<Int<0>>>,TrFade<217>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<1283>,AlphaL<HumpFlicker<White,Red,20>,Bump<Int<8000>>>,TrFade<478>,AlphaL<Black,Int<0>>,TrInstant,AlphaL<HumpFlicker<White,Red,20>,Bump<Int<25000>>>,TrFade<400>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrFade<1300>,SparkleL<Stripes<1000,-1000,Cyan,Magenta,Black,Blue>,200,600>,TrDelay<1000>,SparkleL<Stripes<2000,2000,Green,Rgb<0,50,200>>,2000,1200>,TrDelay<735>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<4244>,AlphaL<Black,Int<0>>,TrWaveX<RandomPerLEDFlicker<Rgb<130,50,255>,Black>,Int<500>,Int<50>,Int<400>,Int<0>>,AlphaL<Black,Int<0>>,TrWaveX<RandomPerLEDFlicker<Rgb<130,50,255>,Black>,Int<700>,Int<50>,Int<320>,Int<32000>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<5012>,SparkleL<DodgerBlue,6000,200>,TrDelay<885>,SparkleL<DodgerBlue,6000,200>,TrSmoothFade<900>,SparkleL<DodgerBlue,1000,5000>,TrDelay<20>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<5716>,AlphaL<Black,Int<0>>,TrFade<200>,AlphaL<Stripes<1000,-4000,Rgb<20,10,100>,Rgb<10,0,200>,Yellow,Black,Black>,SmoothStep<Int<8192>,Int<-1>>>,TrDelay<200>,AlphaL<Stripes<1000,-4000,Rgb<20,10,100>,Rgb<10,0,200>,Yellow,Black,Black>,SmoothStep<Int<16384>,Int<-1>>>,TrDelay<200>,Stripes<1000,-4000,Rgb<20,10,100>,Rgb<10,0,200>,Yellow,Black,Black>,TrDelay<100>,AlphaL<Stripes<1000,-4000,Rgb<20,10,100>,Rgb<10,0,200>,Yellow,Black,Black>,SmoothStep<Int<32768>,Int<-1>>>,TrDelay<75>,AlphaL<Black,Int<0>>,TrSmoothFade<375>,HumpFlicker<Red,White,15>,TrSmoothFade<172>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<2088>,Layers<
      AlphaL<HumpFlicker<White,Red,20>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<1>,Int<2088>,Int<950>>,Int<-100>,Int<16385>>,Int<-1>>>,
      AlphaL<HumpFlicker<White,Red,20>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<1>,Int<2088>,Int<950>>,Int<33000>,Int<16384>>,Int<0>>>>,TrDelay<3038>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<7224>,Black,TrSmoothFade<200>,HumpFlicker<Black,Green,10>,TrSmoothFade<739>>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"kaiju\nkiller"},

{ "aa_HarrySolo/DESTABILIZE;common;commonBU", "",
   
  StylePtr<Layers<
    Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,StyleFire<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>,0,6,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,Stripes<5000,-1500,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,105>>>>,
    BC_effects_1,
    InOutTrL<TrConcat<TrWipe<200>,Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,StyleFire<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>,0,6,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,Stripes<5000,-1500,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,105>>>>,TrWipe<100>,Black,TrBoing<300,3>>,TrBoing<500,3>>,
    TransitionEffectL<TrConcat<TrFade<2000>,AlphaL<HumpFlickerL<Rgb<120,120,165>,10>,Bump<Int<0>,Int<4000>>>,TrFade<2950>,AlphaL<HumpFlickerL<Rgb<120,120,165>,15>,Bump<Int<0>,Int<5000>>>,TrFade<3000>,AlphaL<HumpFlickerL<Rgb<120,120,165>,20>,Bump<Int<0>,Int<6000>>>,TrBoing<1000,3>>,EFFECT_PREON>,
  // New preon
    TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<60000>>>,TrFade<270>,Black,TrWipe<540>,AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>>,TrInstant,Blinking<DeepSkyBlue,Black,100,500>,TrDelay<250>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<520>,AlphaL<Black,Int<0>>,TrWipeIn<540>,Black,TrWipe<380>,AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>>,TrInstant,Black,TrInstant,AlphaL<BrownNoiseFlicker<DeepSkyBlue,Black,80>,SmoothStep<Scale<NoisySoundLevel,Int<2000>,Int<20000>>,Int<-10000>>>,TrDelay<400>,Black,TrFade<1500>,StyleFire<HumpFlicker<DeepSkyBlue,Black,100>,Rgb<95,0,210>,0,3,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,5000,10>,FireConfig<100,1500,35>>,TrSmoothFade<883>,HumpFlickerL<White,100>,TrInstant>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"destabilize"},

{ "aa_HarrySolo/STASIS;common;commonBU", "",
 // STASIS blade style - Harry Solo - NoSloppy tweaks

  StylePtr<Layers<
    Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,AudioFlicker<RotateColorsX<Variation,Rgb<24,7,51>>,RotateColorsX<Variation,Rgb<56,0,255>>>,StyleFire<RotateColorsX<Variation,Rgb16<26511,4702,65535>>,HumpFlicker<RotateColorsX<Variation,Rgb16<25487,5257,63295>>,Rgb16<3131,1305,5845>,15>,0,3,FireConfig<1,2000,6>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<35>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<35>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<35>>,EFFECT_BLAST>,
    BlastL<White,850,250,351>,
    AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
    BlastL<White,500,350,100000>,
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,50>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
      AlphaL<StrobeX<Black,White,Scale<SlowNoise<Int<1000>>,Int<0>,Int<2>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>,Int<20000>>,
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
      AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,AlphaL<Mix<SmoothStep<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>>,Int<1000>>,Stripes<2500,2000,TransitionEffect<White,Azure,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Rgb<95,0,210>>,Stripes<2500,-2500,TransitionEffect<White,Azure,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Rgb<95,0,210>>>,Int<18000>>,TrFade<600>>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<Layers<
      Stripes<3000,-2000,RandomBlink<30000,Strobe<Rgb<125,125,225>,White,50,1>,Rgb<75,75,150>>,RandomPerLEDFlicker<Rgb<20,20,100>,Rgb<100,100,150>>>,
      AlphaL<StrobeX<AlphaL<Black,Int<0>>,White,Scale<SlowNoise<Int<1000>>,Int<0>,Int<7>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>,Int<22000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,TrJoin<TrWipe<300>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>>>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<35>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
    AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Bump<Int<0>,Scale<TwistAngle<>,Int<2000>,Int<10000>>>>,
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,60,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<200,100,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,80>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFade<1200>>,EFFECT_IGNITION>,
    AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<2400>>,Int<22000>,Int<40000>>,Int<22000>>>,
    InOutTrL<TrColorCycle<600>,TrWipeIn<200>>,
    TransitionEffectL<TrConcat<TrFade<650>,BlinkingL<Rgb<128,100,128>,Int<100>,Int<500>>,TrFade<1000>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFade<800>,AlphaL<Blinking<Rgb<56,0,255>,Black,100,500>,Bump<Int<0>,Int<20000>>>,TrConcat<TrInstant,AlphaL<Blinking<Rgb<56,0,255>,Black,100,500>,Bump<Int<0>,Int<20000>>>,TrFade<250>,AlphaL<Blinking<Rgb<56,0,255>,Black,100,200>,SmoothStep<Int<16000>,Int<-8000>>>,TrInstant,White,TrDelay<50>>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrDelay<200>,Layers<
      AlphaL<Stripes<300,4500,Black,Black,Rgb<95,0,210>>,SmoothStep<Int<16384>,Int<0>>>,
      AlphaL<Stripes<300,-4500,Black,Black,Rgb<95,0,210>>,SmoothStep<Int<16385>,Int<-1>>>>,TrJoin<TrWipeInSparkTip<Rgb<95,0,210>,800,200>,TrWipeSparkTip<Rgb<95,0,210>,800,200>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,Strobe<Black,Rgb<95,0,210>,15,40>,TrFade<250>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<650>,AlphaL<Black,Int<0>>,TrFade<88>,Rgb<95,0,210>,TrInstant,White,TrDelay<50>>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"stasis"},

// --------------------------------

{ "aa_JayDalorian/OdaNobunaga;common;commonBU", "aa_JayDalorian/nobunaga/tracks/sharingan.wav",

  StylePtr<Layers<
      StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,20>,RotateColorsX<Variation,Rgb<7,5,0>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Blue>,70>,RotateColorsX<Variation,DodgerBlue>>,RotateColorsX<Variation,Red>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
      TransitionEffectL<TrConcat<TrFade<400>,
        StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,AudioFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,RotateColorsX<Variation,Rgb<10,0,0>>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,70>,RotateColorsX<Variation,Red>>,Blue,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrDelay<3000>,
        StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,AudioFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,RotateColorsX<Variation,Rgb<10,0,0>>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,25>>,70>,RotateColorsX<Variation,Rgb<128,0,0>>>,Rgb<80,0,0>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrFade<800>>,EFFECT_FORCE>,
      AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,Black>,Black,RotateColorsX<Variation,Blue>,Black>,SwingSpeed<600>>,
      BC_effects_1,
      InOutTrL<TrJoinR<TrWipe<1000>,TrWipeIn<750>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Rgb<180,130,0>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,TrDelay<2000>>,EFFECT_RETRACTION>,
      TransitionEffectL<TrConcat<TrInstant,Layers<AlphaL<TransitionLoopL<TrConcat<TrWaveX<RotateColorsX<Variation,DodgerBlue>,Int<300>,Int<200>,Int<300>,Int<0>>,Black,TrDelay<0>>>,SmoothStep<Int<16384>,Int<-100>>>>,TrDelay<1435>>,EFFECT_PREON>,
      TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RotateColorsX<Variation,Blue>,Bump<Int<16384>,Int<4000>>>,TrFade<2000>,AlphaL<AudioFlickerL<RotateColorsX<Variation,Blue>>,Bump<Int<16384>,Int<16000>>>,TrDelay<700>>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"nobunga"}, 


{ "aa_JayDalorian/Blastermode;common;commonBU", "",
// no effects because... blaster. But....... use Force to toggle to use stun sounds instead using alt sounds!
StylePtr<Layers<Black,
// base
  // Test AltF using it in Colorselect<>
  // ColorSelect<AltF,TrInstant,
  //   MultiTransitionEffectL<TrConcat<TrWipe<150>,Red,TrWipe<100>>,EFFECT_BLAST>,
  //   MultiTransitionEffectL<TrConcat<TrWipe<200>,Stripes<1000,-2000,Cyan,Blue>,TrWipe<100>>,EFFECT_BLAST>>,
  // TransitionEffectL<TrDoEffectX<TrInstant, EFFECT_ALT_SOUND, EffectIncrementF<EFFECT_FORCE, Int<2>, Int<1>>>, EFFECT_FORCE>,
  // Test AltF using in a TrSelect, since that's all that's swapping here:
  MultiTransitionEffectL<TrSelect<AltF,
                          TrConcat<TrWipe<150>,Red,TrWipe<100>>,
                          TrConcat<TrWipe<200>,Stripes<1000,-2000,Cyan,Blue>,TrWipe<100>>>,EFFECT_BLAST>>,

  TransitionEffectL<TrDoEffectX<TrInstant, EFFECT_ALT_SOUND, EffectIncrementF<EFFECT_FORCE, Int<2>, Int<1>>>, EFFECT_FORCE>,
  AlphaL<Pulsing<Black,ColorSelect<AltF,TrInstant,Red,Cyan>,3000>,Bump<Int<0>,Int<1000>>>,
// Muzzle flash
  MultiTransitionEffectL<TrConcat<TrDelay<250>,AlphaL<AudioFlickerL<White>,SmoothStep<Int<6000>,Int<-4000>>>,TrFade<100>,AlphaL<AudioFlicker<Red,Rgb<100,0,0>>,SmoothStep<Int<3000>,Int<-4000>>>,TrFade<350>>,EFFECT_BLAST>,
// Clash
  TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<NavajoWhite,Black>,Bump<Int<0>,Int<12000>>>,TrFadeX<WavLen<>>>,EFFECT_CLASH>,
// Lockup scanner
  LockupTrL<Cylon<DodgerBlue,5,1,DodgerBlue,20,175,1>,TrConcat<TrFade<330>,LightCyan,TrFade<330>,AlphaL<RandomBlink<14000>,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>>>,TrDelay<900>,AlphaL<Black,Int<0>>,TrWipe<170>,White,TrWipe<170>,DodgerBlue,TrBoing<500,3>>,TrWipeSparkTip<White,250,40>,SaberBase::LOCKUP_NORMAL>,
// Melt
  LockupTrL<StyleFire<Black,Cyan,0,4,FireConfig<3000,3000,1>,FireConfig<2200,0,0>,FireConfig<10,2000,0>,FireConfig<0,0,5>>,TrWipeSparkTipX<Red,Int<250>,Int<2000>>,TrFade<300>,SaberBase::LOCKUP_MELT>,
// Stab
  TransitionEffectL<TrConcat<TrWipeIn<50>,LightCyan,TrWipeIn<50>,AlphaL<AudioFlicker<NavajoWhite,Black>,Bump<Int<0>,Int<12000>>>,TrFadeX<WavLen<>>>,EFFECT_STAB>,
// Preon muzzle warmup
  TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<>,33>>,AlphaL<HumpFlickerL<Blue,10>,Bump<Int<0>,Int<4000>>>,TrFadeX<Percentage<WavLen<>,33>>,AlphaL<HumpFlickerL<Red,15>,Bump<Int<0>,Int<5000>>>,TrFadeX<Percentage<WavLen<>,20>>,AlphaL<HumpFlickerL<White,20>,Bump<Int<0>,Int<6000>>>,TrBoingX<Percentage<WavLen<>,14>,3>>,EFFECT_PREON>,
  InOutTrL<TrFade<1000>,TrWipeInSparkTip<White,300>>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"blastermode"},

{ "aa_JayDalorian/Decimate;common;commonBU", "",
  StylePtr<Layers<
    StaticFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,20>,RotateColorsX<Variation,Rgb<4,0,8>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,RotateColorsX<Variation,Rgb<42,0,105>>>,RotateColorsX<Variation,Rgb<30,0,66>>,0,5,2,3000,0>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>>,TrFade<1200>>,EFFECT_RETRACTION>,
    InOutTrL<TrWipeSparkTip<White,800>,TrWipeInSparkTip<White,880>>,
    TransitionEffectL<TrConcat<TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<21,0,52>>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<21,0,52>>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<42,0,105>>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrDelay<1000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<42,0,105>>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrWipe<300>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<64,0,145>>,30>,SmoothStep<Int<6000>,Int<-500>>>,TrDelay<5100>>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"decimate"},

// --------------------------------

{ "aa_Kyberphonic/Metamorphose;common;commonBU", "",
  StylePtr<Layers<
    Stripes<15000,-5000,Sparkle<Rgb<0,0,150>,White,250>,Magenta,Blue,Blue>,
    TransitionLoopL<TrConcat<TrBoing<800,1>,AlphaL<Strobe<Black,Strobe<Black,RandomPerLEDFlicker<Green,Black>,50,1>,100,1>,Bump<Sin<Int<5>>,Int<25000>>>,TrBoing<1500,2>>>,
    TransitionLoopL<TrConcat<TrSmoothFade<3000>,AlphaL<PulsingL<Orange,Int<3000>>,Bump<Scale<Sin<Int<5>>,Int<32768>,Int<0>>,Int<30000>>>,TrSmoothFade<3000>>>,
    BC_effects_Red,
    InOutTrL<TrWipe<300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"metamorphose"},

// --------------------------------

{ "aa_NoSloppy/TheMaw;common;commonBU", "",
   StylePtr<Layers<
// Main Blade Color    
    Mix<SmoothStep<Int<16000>,Int<10000>>,
      StripesX<Scale<TwistAngle<1>,Int<1500>,Int<3000>>,Int<-2000>,Rgb<60,0,255>,Black>,
      StripesX<Scale<TwistAngle<1>,Int<1500>,Int<3000>>,Int<2000>,Rgb<60,0,255>,Black>>,
    // Ice Force
    TransitionEffectL< 
      TrConcat<TrFade<7000>,Rgb<10,0,75>,// blade turns solid cold 1000ms before ice full coverage
      TrDelay<1000>>,EFFECT_USER2>,  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to base color
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
// Clash
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,
      AlphaL<
        TransitionEffect<
          TransitionEffect<Strobe<Rgb<255,150,50>,Black,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,
        Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,
      Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,
    EFFECT_CLASH>,
// Stab
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// Blast
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
    BlastL<EffectSequence<EFFECT_BLAST,Red,Green,Cyan,GreenYellow>,850,250,351>,
    AlphaL<TransitionEffectL<TrConcat<TrDelay<300>,Red,TrFade<500>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
    BlastL<Rgb<100,200,255>,500,350,100000>,
// Lockup - BC custom range mid-blade w/random strobe flash
    LockupTrL<Layers<StrobeX<AlphaL<Black,Int<0>>,White,Scale<SlowNoise<Int<1000>>,Int<0>,Int<2>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>,
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
      AlphaL<Blinking<BrownNoiseFlicker<Rgb<100,200,255>,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,
      TrConcat<TrInstant,
      AlphaL<Blinking<Rgb<100,200,255>,Strobe<BrownNoiseFlicker<Yellow,Black,500>,White,15,30>,60,500>,         Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<Rgb<100,200,255>,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// Non-Responsive Drag
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,Rgb<100,200,255>>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
    LockupTrL<Layers<AlphaL<StrobeX<Black,White,Scale<SlowNoise<Int<1000>>,Int<0>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>,Int<22000>>,AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
      Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
      Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
      Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
    // Begin Lightning Transition
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
    // End Lightning Transition    
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// Melt    
    LockupTrL<
      AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
      // Melt Shape
      SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
      // Melt Begin and End transitions
      TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>, 
// Ignition and Retraction
    TransitionEffectL<TrConcat<TrDelay<200>,Strobe<Black,Rgb<100,100,150>,15,40>,TrJoin<TrWipeInSparkTip<Rgb<100,200,255>,800,200>,TrWipeSparkTip<Rgb<100,200,255>,800,200>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFade<700>,Strobe<Black,Rgb<100,100,150>,15,40>,TrDelay<300>>,EFFECT_RETRACTION>,
    InOutTrL<
      TrJoin<
        TrJoin<TrWipeIn<800>,TrWaveX<White,Int<800>,Int<500>,Int<800>,Int<32768>>>,
        TrJoin<TrWipe<800>,TrWaveX<White,Int<400>,Int<500>,Int<800>,Int<0>>>>,
      TrJoin<
        TrJoin<TrWipeInX<Percentage<WavLen<EFFECT_RETRACTION>,200>>,TrWaveX<White,WavLen<EFFECT_RETRACTION>,Int<500>,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<32768>>>,
        TrJoin<TrWipeX<Percentage<WavLen<EFFECT_RETRACTION>,200>>,TrWaveX<White,WavLen<EFFECT_RETRACTION>,Int<500>,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<0>>>>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<50>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrDelayX<WavLen<EFFECT_RETRACTION>>,White,TrFade<50>>,EFFECT_RETRACTION>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"the\nmaw"},

// --------------------------------

{ "aa_Juansith/Red_Five;common;commonBU", "aa_Juansith/Red_Five/tracks/Xwing.wav",
// Juansith Red Five Blade Style - BC 2022
  StylePtr<Layers<Black,
    AlphaL<Layers<
      AlphaL<Stripes<5000,-3000,Red,Rgb<100,0,0>,Black,Red,Rgb<100,0,0>,Rgb<150,150,150>,Black>,SmoothStep<Int<16385>,Int<-1>>>,
      AlphaL<Stripes<5000,3000,Red,Rgb<100,0,0>,Black,Red,Rgb<100,0,0>,Rgb<150,150,150>,Black>,SmoothStep<Int<16384>,Int<0>>>>,Int<16000>>,
    AlphaL<AudioFlicker<Red,Rgb<100,0,0>>,Bump<Int<16384>,Scale<Sin<Int<40>>,Int<14000>,Int<50000>>>>,
    BC_effects_Red,
  // Engines Starting Ignition, cyle down retraction WavLen version for auto-sync OS6 and above
    InOutTrL<TrConcat<TrDelay<1000>,Black,TrJoin<TrWipe<700>,TrWipeIn<700>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<300>,AudioFlicker<Red,Rgb<100,0,0>>,TrJoin<TrJoin<TrWipeX<Percentage<WavLen<EFFECT_RETRACTION>,200>>,TrWipeInX<Percentage<WavLen<EFFECT_RETRACTION>,200>>>,TrColorCycleX<WavLen<EFFECT_RETRACTION>,-400,-100>>>>,
    TransitionEffectL<TrConcat<TrInstant,StrobeL<AlphaL<White,LayerFunctions<Bump<Int<0>,Scale<Trigger<EFFECT_IGNITION,Int<1000>,Int<2000>,Int<500>>,Int<0>,Int<16384>>>,Bump<Int<32768>,Scale<Trigger<EFFECT_IGNITION,Int<1000>,Int<2000>,Int<500>>,Int<0>,Int<16384>>>>>,Int<25>,Int<30>>,TrFade<2000>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<50>>,EFFECT_IGNITION>,
  // preon - WavLen version for OS6 and above. 
    TransitionEffectL<TrConcat<TrFadeX< Percentage<WavLen<EFFECT_PREON>,30> >,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Rgb<100,100,150>,300>,LayerFunctions<Bump<Int<0>,Int<10000>>,Bump<Int<32768>,Int<10000>>>>,TrDelayX< Percentage<WavLen<EFFECT_PREON>,70> >>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"    red\n   five"},

{ "aa_Juansith/Sereph;common;commonBU", "",
  StylePtr<Layers<
    StripesX<Int<6000>,Int<-1000>,RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<24,24,35>>>,
    //AlphaL<White,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    AlphaL<Stripes<4000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Black>,White,RotateColorsX<Variation,Rgb<100,100,150>>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    BC_effects_White,  
    InOutTrL<TrWipe<400>,TrConcat<TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,50>>,Stripes<3000,2000,White,Rgb<100,100,100>>,TrFadeX< Percentage<WavLen<EFFECT_RETRACTION>,50> >>>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"sereph"}


};

BladeConfig blades[] = {
{ 0,    // CTB? NEED Main Blade for this hilt D1_data_line = proffie_D1---> KimCanamaCC_PCB ctrpin parallel to onboards---> bladePCB 330ohm--->Main blade strips
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),                                   // Main Blade
CONFIGARRAY(ID7), 
"01_ID7_save"}, 

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, auxPin, "pow"); 
Button AuxButton(BUTTON_AUX, powerButtonPin, "aux");
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

