// laser_musket_config.h

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2

// ------ Audio Stuff --------

#define VOLUME 1500

// ------ Blade Stuff ------

const unsigned int maxLedsPerStrip = 144;

// ------ SD Card Stuff -------

#define MOUNT_SD_SETTING
#define SAVE_STATE

// ------- Motion and Gesture stuff -------

#define CLASH_THRESHOLD_G 3.5
#define STEPS_PER_REVOLUTION 24

// --------- OS Menu -------------
#define MENU_SPEC_TEMPLATE DefaultMenuSpec

#endif

#ifdef CONFIG_PROP
#include "../props/laser_musket_buttons.h"
#endif

#ifdef CONFIG_PRESETS

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;


Preset presets[] = {

{ "Fallout;common", "Fallout/tracks/wasteland.wav",
  // Chamber (Blade 1): Effects based on crank count, flash with FIRE
    StylePtr<Layers<Black,
    ColorSelect<AltF,TrFadeX<Int<1000>>,
      //Default
      Black,
      //Phase1
      StripesX<Int<6000>,Scale<SlowNoise<Int<3000>>,Int<-1250>,Int<-2500>>,Red,RandomPerLEDFlicker<Rgb<79,0,0>,Rgb<9,0,0>>,BrownNoiseFlicker<Rgb<9,0,0>,Rgb<128,0,0>,300>,Red>,
      //Phase2
      StripesX<Int<6000>,Scale<SlowNoise<Int<2000>>,Int<-1600>,Int<-3200>>,Red,RandomPerLEDFlicker<Rgb<79,0,0>,Rgb<9,0,0>>,BrownNoiseFlicker<Rgb<9,0,0>,Rgb<128,0,0>,300>,Red,RandomPerLEDFlicker<Black,Rgb<128,0,0>>,Red>,
      //Phase3
      Stripes<3000,-3500,Red,RandomPerLEDFlicker<Rgb<59,0,0>,Black>,BrownNoiseFlicker<Red,Rgb<29,0,0>,200>,RandomPerLEDFlicker<Rgb<79,0,0>,Rgb<29,0,0>>>,
      //Phase4
      Layers<
        Stripes<2000,-2500,Red,RandomPerLEDFlicker<Rgb<59,0,0>,Black>,BrownNoiseFlicker<Red,Rgb<29,0,0>,200>,RandomPerLEDFlicker<Rgb<79,0,0>,Rgb<29,0,0>>>,
        TransitionLoopL<TrJoin<TrDelayX<Scale<SlowNoise<Int<1500>>,Int<200>,Int<1200>>>,TrWaveX<Rgb<255,50,50>,Int<400>,Int<100>,Int<200>,Int<0>>>>>,
      //Phase5
      StaticFire<Stripes<2500,-5000,BrownNoiseFlicker<Red,Black,20>,Rgb<9,0,0>,BrownNoiseFlicker<Black,Rgb<255,24,24>,70>,Rgb<128,0,0>>,Rgb<79,0,0>,0,5,2,3000,0>,
      //Phase6
      StaticFire<StripesX<Int<3000>,Scale<SlowNoise<Int<2000>>,Int<-1000>,Int<-5000>>,BrownNoiseFlicker<Red,Black,100>,RandomPerLEDFlicker<Rgb<60,0,0>,Rgb<10,0,0>>,Rgb<255,24,24>,Rgb<128,0,0>>,Rgb<79,0,0>,0,6,7,3000,0>>,
  // USER1 = next phase
  TransitionEffectL<TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,ModF<Sum<AltF,Int<1>>,Int<7>>,Int<-1>>,EFFECT_USER1>,
  // FIRE and reset to default phase
  TransitionEffectL<TrConcat<TrInstant,TrDoEffectAlwaysX<TrInstant,EFFECT_ALT_SOUND,Int<0>,Int<-1>>,HumpFlicker<White,Black,100>,TrDelay<200>,TrFade<700>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,
    OnDemandVolumeLevel
  >>(),
    // Edison filament LED (Blade 2): Brightness increase with charge level, flash with FIRE
  StylePtr<Layers<Black,
    ColorSelect<AltF,TrFadeX<Int<1000>>,
      //Default
      Black,
      // 1 crank: 6%
      Mix<Sin<Int<30>,Int<2000>>,Rgb<30,0,0>,Red>,
      // 2 cranks: 18%
      Mix<Sin<Int<50>,Int<6000>,Int<2500>>,Rgb<30,0,0>,Red>,
      // 3 cranks: 31%
      Mix<Sin<Int<85>,Int<10000>,Int<6800>>,Rgb<30,0,0>,Red>,
      // 4 cranks: 44%
      Mix<Sin<Int<150>,Int<14400>,Int<9200>>,Rgb<30,0,0>,Red>,
      // 5 cranks: 52%
      Mix<Sin<Int<240>,Int<17000>,Int<12000>>,Rgb<30,0,0>,Red>,
      // 6 cranks: 64%
      Mix<Sin<Int<400>,Int<21000>,Int<15000>>,Rgb<30,0,0>,Red>>,
    // Flash on FIRE
    TransitionEffectL<TrConcat<TrInstant,HumpFlicker<Red,Black,100>,TrDelay<200>,TrFade<500>>,EFFECT_FIRE>
  >>(),
"fallout"}

};

BladeConfig blades[] = {
  { 0,
    WS281XBladePtr<40, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3>>(),
    SimpleBladePtr<CH1LED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),
    CONFIGARRAY(presets)
  }
};
#endif

#ifdef CONFIG_BUTTONS
Button FireButton(BUTTON_POWER, powerButtonPin, "fire");
Button CrankButton(BUTTON_AUX, auxPin, "crank");
#endif

