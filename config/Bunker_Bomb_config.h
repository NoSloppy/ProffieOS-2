#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 2
#define VOLUME 30
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 2.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_ALL_EDIT_OPTIONS
#define COLOR_CHANGE_DIRECT
#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define NO_REPEAT_RANDOM
// #define ROTATE_PRESETS  // not a thing
#define MOTION_TIMEOUT 60 * 15 * 1000
#define IDLE_OFF_TIME 60 * 15 * 1000
#define DIAGNOSTIC_STARTUP_DELAY_FOR_SERIAL_MONITOR // BC 3000ms delay to catch all messages.

#endif

#ifdef CONFIG_PROP
#include "../props/bunker_bomb.h"
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {


{ "Bunker_Bomb/5;Bunker_Bomb", "Bunker_Bomb/tracks/SEAGULLS.wav",
  //inside
  StylePtr<Layers<
    Stripes<3000,-2400,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,Mix<Int<4000>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>>,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>>>,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,White>>,TrFade<1200>>,EFFECT_IGNITION>,
    InOutTrL<TrColorCycleX<IgnitionTime<1500>,0,800>,TrColorCycleX<RetractionTime<800>,800,0>,ColorCycle<RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,25,40,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,25,300,6000>>>>(),

  //top blinkie
  StylePtr<Layers<
    Blinking<RgbArg<BASE_COLOR_ARG,Red>,Black,2000,500>,
    InOutTrL<TrInstant,TrInstant,RgbArg<OFF_COLOR_ARG,Red>>>>(),
    
  //bottom blinkie
  StylePtr<Layers<
    Blinking<Black,RgbArg<BASE_COLOR_ARG,Red>,2000,500>,
    InOutTrL<TrInstant,TrInstant,RgbArg<OFF_COLOR_ARG,Red>>>>(),

"5"},

{ "Bunker_Bomb/120;Bunker_Bomb", "",
  //inside
  StylePtr<Layers<
    Stripes<3000,-2400,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,Mix<Int<4000>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>>,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>>>,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,White>>,TrFade<1200>>,EFFECT_IGNITION>,
    InOutTrL<TrColorCycleX<IgnitionTime<1500>,0,800>,TrColorCycleX<RetractionTime<800>,800,0>,ColorCycle<RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,25,40,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,25,300,6000>>>>(),

  //top blinkie
  StylePtr<Layers<
    Blinking<RgbArg<BASE_COLOR_ARG,Red>,Black,2000,500>,
    InOutTrL<TrInstant,TrInstant,RgbArg<OFF_COLOR_ARG,Red>>>>(),
    
  //bottom blinkie
  StylePtr<Layers<
    Blinking<Black,RgbArg<BASE_COLOR_ARG,Red>,2000,500>,
    InOutTrL<TrInstant,TrInstant,RgbArg<OFF_COLOR_ARG,Red>>>>(),

"120"},

{ "Bunker_Bomb/90;Bunker_Bomb", "",
  //inside
  StylePtr<Layers<
    Stripes<3000,-2400,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,Mix<Int<4000>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>>,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>>>,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,White>>,TrFade<1200>>,EFFECT_IGNITION>,
    InOutTrL<TrColorCycleX<IgnitionTime<1500>,0,800>,TrColorCycleX<RetractionTime<800>,800,0>,ColorCycle<RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,25,40,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,25,300,6000>>>>(),

  //top blinkie
  StylePtr<Layers<
    Blinking<RgbArg<BASE_COLOR_ARG,Red>,Black,2000,500>,
    InOutTrL<TrInstant,TrInstant,RgbArg<OFF_COLOR_ARG,Red>>>>(),
    
  //bottom blinkie
  StylePtr<Layers<
    Blinking<Black,RgbArg<BASE_COLOR_ARG,Red>,2000,500>,
    InOutTrL<TrInstant,TrInstant,RgbArg<OFF_COLOR_ARG,Red>>>>(),

"90"},

{ "Bunker_Bomb/60;Bunker_Bomb", "",
  //inside
  StylePtr<Layers<
    Stripes<3000,-2400,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,Mix<Int<4000>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>>,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>>>,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,White>>,TrFade<1200>>,EFFECT_IGNITION>,
    InOutTrL<TrColorCycleX<IgnitionTime<1500>,0,800>,TrColorCycleX<RetractionTime<800>,800,0>,ColorCycle<RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,25,40,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,25,300,6000>>>>(),

  //top blinkie
  StylePtr<Layers<
    Blinking<RgbArg<BASE_COLOR_ARG,Red>,Black,2000,500>,
    InOutTrL<TrInstant,TrInstant,RgbArg<OFF_COLOR_ARG,Red>>>>(),
    
  //bottom blinkie
  StylePtr<Layers<
    Blinking<Black,RgbArg<BASE_COLOR_ARG,Red>,2000,500>,
    InOutTrL<TrInstant,TrInstant,RgbArg<OFF_COLOR_ARG,Red>>>>(),

"60"},

{ "Bunker_Bomb/30;Bunker_Bomb", "",
  //inside
  StylePtr<Layers<
    Stripes<3000,-2400,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,Mix<Int<4000>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>>,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>>>,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,White>>,TrFade<1200>>,EFFECT_IGNITION>,
    InOutTrL<TrColorCycleX<IgnitionTime<1500>,0,800>,TrColorCycleX<RetractionTime<800>,800,0>,ColorCycle<RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,25,40,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,25,300,6000>>>>(),

  //top blinkie
  StylePtr<Layers<
    Blinking<RgbArg<BASE_COLOR_ARG,Red>,Black,2000,500>,
    InOutTrL<TrInstant,TrInstant,RgbArg<OFF_COLOR_ARG,Red>>>>(),
    
  //bottom blinkie
  StylePtr<Layers<
    Blinking<Black,RgbArg<BASE_COLOR_ARG,Red>,2000,500>,
    InOutTrL<TrInstant,TrInstant,RgbArg<OFF_COLOR_ARG,Red>>>>(),

"30"},

{ "Bunker_Bomb/15;Bunker_Bomb", "",
  //inside
  StylePtr<Layers<
    Stripes<3000,-2400,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,Mix<Int<4000>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>>,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>>>,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,White>>,TrFade<1200>>,EFFECT_IGNITION>,
    InOutTrL<TrColorCycleX<IgnitionTime<1500>,0,800>,TrColorCycleX<RetractionTime<800>,800,0>,ColorCycle<RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,25,40,RgbArg<BASE_COLOR_ARG,Rgb16<40982,47835,55787>>,25,300,6000>>>>(),

  //top blinkie
  StylePtr<Layers<
    Blinking<RgbArg<BASE_COLOR_ARG,Red>,Black,2000,500>,
    InOutTrL<TrInstant,TrInstant,RgbArg<OFF_COLOR_ARG,Red>>>>(),
    
  //bottom blinkie
  StylePtr<Layers<
    Blinking<Black,RgbArg<BASE_COLOR_ARG,Red>,2000,500>,
    InOutTrL<TrInstant,TrInstant,RgbArg<OFF_COLOR_ARG,Red>>>>(),

"15"},


};
BladeConfig blades[] = {
 //inside
 { 0, WS281XBladePtr<29, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
 //blinkie 1
    WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
  //blinkie 2
    WS281XBladePtr<1, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),
    CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button AuxButton(BUTTON_AUX, powerButtonPin, "aux");
#endif