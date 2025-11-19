
#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BUTTONS 1
#define NUM_BLADES 1
#define BOOT_VOLUME 100
#define VOLUME 500
const unsigned int maxLedsPerStrip = 144;
#define ENABLE_SSD1306
#define CLASH_THRESHOLD_G 3.5
#define MOUNT_SD_SETTING
#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS

Preset bladein [] = {

{ "testfont2b;ProffieOS_V2_Voicepack_Vader_V2/common;commonBU", "a_STARKILLER/tracks/Starkillers_Theme.wav",
StylePtr<Red>(),
"testfont2b"}

};


BladeConfig blades[] = {
{0,
  WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  CONFIGARRAY(bladein),
"01_Ronin_save"},

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

