// may4thflagship_config_8.x//
// Last upload 11-09-2024

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BUTTONS 1
#define NUM_BLADES 2

// ------ Audio Stuff --------

#define VOLUME 2000
#define BOOT_VOLUME 100
//#define FILTER_CUTOFF_FREQUENCY 100
//#define FILTER_ORDER 8
#define ENABLE_FASTON

// ------ Blade Stuff ------

const unsigned int maxLedsPerStrip = 144;
#define EXTRA_COLOR_BUFFER_SPACE 30
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9> // PBv2.2 TX pad for example
// #define REAL_TIME_BLADE_ID_POWER_PINS 2, 3
// #define NO_BLADE_ID_RANGE 100068000,99999999
#define DYNAMIC_BLADE_LENGTH

// ------ SD Card Stuff -------

#define MOUNT_SD_SETTING
#define SAVE_COLOR_CHANGE

// ------ System Stuff --------

//#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define CONFIG_STARTUP_DELAY 3000
 // #define PROFFIEOS_LOG_LEVEL 500

// ------- Motion and Gesture stuff -------

#define CLASH_THRESHOLD_G 3.5
#define ENABLE_SPINS

// --- BC prop stuff -----

#define BC_SWING_ON
#define BC_SWING_ON_SPEED 400 // Default 250
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
#define BC_FORCE_PUSH
#define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second. 
//#define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200


#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"
#include "aliases/TrueWhites/BC_effects_2.h"
#include "aliases/TrueWhites/BC_effects_Red.h"

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrSmoothFade<200>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrDelay<1000>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

Preset may4thflagship [] = {

{ "aa_KSith/Induction;common;commonBU", "tracks/darkrey.wav",
  StylePtr<Layers<
    StripesX<Int<5000>,Int<-1500>,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb<0,30,60>>,RotateColorsX<Variation,Rgb<50,50,255>>,RotateColorsX<Variation,Rgb<0,80,128>>>,
    AlphaL<White,Bump<Int<0>,Int<8000>>>,
    BC_effects_1,
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,
    TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Stripes<1000,-300,RareBlue,Mix<Int<16384>,RareBlue,Black>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Mix<Int<16384>,RareBlue,Black>,RareBlue,400>,TrDelayX<Percentage<WavLen<>,80>>,Mix<Int<6000>,RareBlue,White>,TrFade<800>>,EFFECT_FORCE>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<RareBlue,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<RareBlue,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,RareBlue,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,RareBlue,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,RareBlue,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"induction"},

{ "aa_Blueforce/Dangerous;common;commonBU", "tracks/order66.wav",
  StylePtr<Layers<
    StripesX<Int<5000>,Int<-1500>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,50,0>>,RotateColorsX<Variation,Tomato>>,
    AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,50>,Bump<Int<0>,Int<8000>>>,
    BC_effects_Red,
    InOutTrL<TrJoinR<TrWipeSparkTip<White,1000>,TrColorCycle<2000,0,3000>>,TrWipeInX<BendTimePowX<Int<1538>,Int<180000>>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlickerL<Rgb<255,100,100>>,Bump<Int<0>,Int<8000>>>,TrDelay<600>>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Stripes<1000,-300,Red,Rgb<128,0,0>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<90,0,0>,Red,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<Red,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<Red,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,Red,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"dangerous"},

{ "aa_KSith/Ascension;common;commonBU", "tracks/battleofheros.wav",
  StylePtr<Layers<
    StripesX<Int<3000>,Int<-3000>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,60>>,RotateColorsX<Variation,Rgb<50,50,255>>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    AlphaL<Rgb<100,100,255>,SwingSpeed<600>>,
    BC_effects_1,
    InOutTrL<TrJoinR<TrWipeSparkTip<White,1000>,TrColorCycle<2000,0,3000>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Stripes<1000,-300,RareBlue,Mix<Int<16384>,RareBlue,Black>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Mix<Int<16384>,RareBlue,Black>,RareBlue,400>,TrDelayX<Percentage<WavLen<>,80>>,Mix<Int<6000>,RareBlue,White>,TrFade<800>>,EFFECT_FORCE>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<RareBlue,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<RareBlue,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,RareBlue,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,RareBlue,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,RareBlue,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"ascension"},

{ "aa_KSith/Proto;common;commonBU", "tracks/order66.wav",
  StylePtr<Layers<
    RandomBlink<30000>,
    Mix<SwingSpeed<400>,AlphaL<Black,Int<0>>,RotateColorsX<Variation,Rgb<150,150,225>>>,
    AlphaL<RotateColorsX<Variation,Rgb<35,35,75>>,Int<10000>>,
    BC_effects_1,
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Percentage<WavLen<EFFECT_IGNITION>,50>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    TransitionEffectL<TrConcat<TrFade<500>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,Int<1000>,Int<6000>>,Int<-3000>>,Black,RandomBlink<30000>>,TrDelay<100>>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Stripes<1000,-300,White,Mix<Int<16384>,White,Black>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Mix<Int<16384>,White,Black>,White,400>,TrDelayX<Percentage<WavLen<>,80>>,Mix<Int<6000>,White,White>,TrFade<800>>,EFFECT_FORCE>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<White,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,White,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,White,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,White,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"proto"},

{ "aa_Blueforce/IgnitionUltimate;common;commonBU", "tracks/duelofthefates.wav",
  StylePtr<Layers<
    Stripes<2000,-2500,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<30,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<30,0,0>>>>,
    TransitionLoopL<TrConcat<TrWaveX<RandomFlicker<RotateColorsX<Variation,Red>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,Black,300>>,Int<400>,Int<100>,Int<200>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1500>>,Int<200>,Int<1200>>>>>,
    AlphaL<BrownNoiseFlicker<Red,Black,300>,SwingSpeed<400>>,
    BC_effects_1,
    //TransitionEffectL<TrConcat<TrDelay<150>,AlphaL<Black,Int<0>>,TrFade<500>,AlphaL<Strobe<White,Black,40,40>,Bump<Int<0>,Int<80000>>>,TrDelay<350>>,EFFECT_RETRACTION>,
    // Cooling tip - meh
    // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>,
  InOutTrL<
    TrConcat<TrInstant,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrWipe<300>,Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,Black,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<255,20,0>>,White>,RotateColorsX<Variation,Rgb<128,34,0>>>,TrFade<300>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,TrBoing<300,3>>,
    TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// Comment out this following line for non-stutter on actual ignition
  //TransitionEffectL<TrConcat<TrWaveX<White,Int<800>,Int<200>,Int<300>,Int<0>>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrDelay<650>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrDelay<100>,BrownNoiseFlicker<White,Red,70>,TrFade<500>,Black,TrInstant>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrDelayX<WavLen<EFFECT_RETRACTION>>,AlphaL<White,Bump<Int<0>,Int<66000>>>,TrDelay<25>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<
      TrInstant,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrFade<100>,Black,
      TrDelay<50>,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<50000>>>,TrDelay<150>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<70000>>>,TrFade<150>,Black,
      TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<400>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<450>,Black,
      
      TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<70000>>>,TrDelay<250>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<50000>>>,TrFade<200>,Black,
      TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<500>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<600>,Black,

      TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<10000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<5000>>>,TrFade<150>,Black,
      TrDelay<350>,Black,
      TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<10000>>>,TrDelay<70>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<5000>>>,TrFade<40>,Black,
      TrDelay<20>,Black,

      TrInstant,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrDelay<50>,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrFade<50>,Black,
      TrDelay<50>,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<50000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<70000>>>,TrFade<150>,Black,
      TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<300>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<400>,

      AlphaL<BrownNoiseFlicker<White,Red,100>,Bump<Int<0>,Int<10000>>>,
      TrFade<175>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<20000>>>,TrFade<175>,AlphaL<BrownNoiseFlicker<White,Red,100>,Bump<Int<0>,Int<10000>>>,
      TrFade<115>,AlphaL<BrownNoiseFlicker<White,DarkOrange,100>,Bump<Int<0>,Int<40000>>>,TrFade<115>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<20000>>>,
      TrFade<100>,AlphaL<BrownNoiseFlicker<White,DarkOrange,100>,Bump<Int<0>,Int<60000>>>,TrFade<100>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<40000>>>,
      TrFade<75>,BrownNoiseFlicker<White,DarkOrange,300>,TrFade<50>,Black,TrFade<50>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Rgb<200,150,150>,20>,
      TrSmoothFade<100>>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Stripes<1000,-300,Red,Rgb<128,0,0>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Rgb<90,0,0>,Red,400>,TrDelayX<Percentage<WavLen<>,80>>,Rgb<255,80,80>,TrFade<800>>,EFFECT_FORCE>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<Red,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<Red,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,Red,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Red,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"ignition\nultimate"},


{ "aa_Kyberphonic/DeathStar;common;commonBU", "aa_Kyberphonic/DeathStar/tracks/track3.wav",
  StylePtr<Layers<
    StripesX<Int<3500>,Int<-3000>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,60,0>>,RotateColorsX<Variation,Rgb<50,255,50>>,RotateColorsX<Variation,Rgb<0,128,0>>>,
    BC_effects_1,
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<150,255,150>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,60,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<150,255,150>>,RotateColorsX<Variation,Rgb<0,60,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,60,0>>>>,TrFade<1200>>,EFFECT_IGNITION>,
    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<Mix<Int<16384>,White,Black>,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
    TransitionEffectL<TrConcat<
      TrWipe<50>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,60,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,TrDelay<100>,
      AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,128,0>>,60>,SmoothStep<Int<4000>,Int<-500>>>,TrWipe<50>,
      AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,190,0>>,30>,SmoothStep<Int<6000>,Int<-500>>>,TrDelay<100>>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  StylePtr<Layers<
    Stripes<1000,-300,Green,Mix<Int<16384>,Green,Black>,Black>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Pulsing<Mix<Int<16384>,Green,Black>,Green,400>,TrDelayX<Percentage<WavLen<>,80>>,Mix<Int<6000>,Green,White>,TrFade<800>>,EFFECT_FORCE>,
    InOutTrL<TrConcat<TrInstant,HumpFlicker<Green,Black,50>,TrSmoothFade<1000>>,TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<Green,Black,50>,TrSmoothFade<1000>>,TransitionLoop<TransitionLoop<Black,TrConcat<TrCenterWipe<1000>,Green,TrCenterWipeIn<1000>>>,TrConcat<TrJoin<TrDelay<2000>,TrCenterWipe<2000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Green,TrCenterWipe<1000>>>,TrJoin<TrDelay<2000>,TrCenterWipeIn<1000>>,TransitionLoop<Black,TrConcat<TrCenterWipeIn<1000>,Green,TrCenterWipe<2000>>>,TrJoin<TrDelay<4000>,TrCenterWipeIn<2000>>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
  "death\nstar"}

};


BladeConfig blades[] = {
{ 0,
  WS281XBladePtr<131, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  // WS281XBladePtr<16, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
  WS281XBladePtr<5, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
  CONFIGARRAY(may4thflagship), 
"01_may4thflagship"}

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, auxPin, "pow"); 
Button AuxButton(BUTTON_AUX, powerButtonPin, "aux");
#endif

