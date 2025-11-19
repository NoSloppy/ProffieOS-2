#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 2
#define VOLUME 1700
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 3.0
#define ENABLE_AUDIO
#define ENABLE_WS2811
#define ENABLE_SD
#define SAVE_STATE
#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define NO_REPEAT_RANDOM
#define DELAYED_OFF
#define ENABLE_BLASTER_AUTO
#endif

#ifdef CONFIG_PROP
#include "../props/blaster.h"
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {


{ "NN14", "tracks/nn14.wav",


// barrel

StylePtr<Layers<TransitionLoop<Black,TrConcat<TrWipe<200>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,TrWipe<200>>>,InOutTrL<TrInstant,TrInstant,Blinking<Black,RgbArg<OFF_COLOR_ARG,Rgb<255,0,0>>,500,500>>>>(),



},


};
BladeConfig blades[] = {
{ 0, SimpleBladePtr<CH1LED, NoLED, NoLED, NoLED, bladePowerPin2, -1, -1, -1>(),
CONFIGARRAY(presets) },
};

#endif

#ifdef CONFIG_BUTTONS
Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");

#endif