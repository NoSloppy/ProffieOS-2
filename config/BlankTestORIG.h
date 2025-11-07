#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 4
#define NUM_BUTTONS 1
#define VOLUME 1000
const unsigned int maxLedsPerStrip = 144; 
#define EXTRA_COLOR_BUFFER_SPACE 30
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL
#define SHARED_POWER_PINS
#define SAVE_STATE
#define ENABLE_DEVELOPER_COMMANDS
#define IDLE_OFF_TIME 60 * 1 * 1000
#define MOTION_TIMEOUT 60 * 1 * 1000
// #define FEMALE_TALKIE_VOICE
#define DISABLE_TALKIE
// #define VOLUME_MENU_CYCLE // dead . quick MAX MIN now
#define NO_REPEAT_RANDOM
#define ENABLE_SSD1306
#define OLED_SYNCED_EFFECTS
#define BC_STAB_ON
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
#define BC_FORCE_PUSH
#define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST
#define ENABLE_SPINS
#define BC_LOCKUP_DELAY 200
#define DISABLE_BASIC_PARSER_STYLES
#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
// #include "../props/saber_fett263_buttons.h"

#endif

#ifdef CONFIG_PRESETS

Preset saber [] = {

{ "TeensySF;common", "",
StylePtr<Stripes<16000,100,Red,Black,Green,Black,Blue,Black,White,Black,Rainbow,Black,Yellow,Black,Rgb<60,0,255>,Black>>(),
StylePtr<Pulsing<Black,Red,800>>(),
StylePtr<Pulsing<Black,Blue,800>>(),
StylePtr<Pulsing<Black,Green,800>>(),
  "1-TeensySF"},

{ "RgueCmdr;common", "testfont2a/tracks/track2.wav",
StylePtr<Red>(),
StylePtr<Pulsing<Black,Red,800>>(),
StylePtr<Pulsing<Black,Blue,800>>(),
StylePtr<Pulsing<Black,Green,800>>(),
  "2-RgueCmdr"},

{ "SmthFuzz;common", "testfont2a/tracks/track2.wav",
StylePtr<Green>(),
StylePtr<Pulsing<Black,Red,800>>(),
StylePtr<Pulsing<Black,Blue,800>>(),
StylePtr<Pulsing<Black,Green,800>>(),
  "3-SmthFuzz"},

{ "SmthJedi;common", "",
StylePtr<Blue>(),
StylePtr<Pulsing<Black,Red,800>>(),
StylePtr<Pulsing<Black,Blue,800>>(),
StylePtr<Pulsing<Black,Green,800>>(),
  "4-SmthJedi"},

};

BladeConfig blades[] = {
{ 0,  
  WS281XBladePtr<13, bladePin, Color8::GRB, PowerPINS<bladePowerPin1, bladePowerPin2> >(),
  WS281XBladePtr<14, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin3, bladePowerPin4> >(),
  WS281XBladePtr<14, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),
  WS281XBladePtr<14, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(),
CONFIGARRAY(saber),
"00_SaberSave"}, 

};
#endif

#ifdef CONFIG_BUTTONS

Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
Button Aux2Button(BUTTON_AUX2, aux2Pin, "aux2");
// // If btn 1 broken, shift to btn 2 & 3
// Button PowerButton(BUTTON_POWER, auxPin, "pow");
// Button AuxButton(BUTTON_AUX, aux2Pin, "aux");



#endif

// #ifdef CONFIG_BUTTONS

// // For saber or dual_prop:
// Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
// Button AuxButton(BUTTON_AUX, auxPin, "aux");
// Button Aux2Button(BUTTON_AUX2, aux2Pin, "aux2");
// //Button Clip(BUTTON_CLIP_DETECT, aux2Pin, "clip");
// // for swapped buttons
// // Button PowerButton(BUTTON_POWER, auxPin, "pow");
// // Button AuxButton(BUTTON_AUX, aux2Pin, "aux");
// // // For blaster only:
// // Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
// // Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");
// // //Button ReloadButton(BUTTON_RELOAD, 24, "reload");

// #endif