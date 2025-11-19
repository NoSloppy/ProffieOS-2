// proffieboard_v1_test_bench_configBC.h
// Proffieboard V1.5 board testing configuration.
// Read ../scripts/proffieboard_test_script.h for instructions.

#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 0
#define VOLUME 300
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL             //Bluetooth or UART TTL
#define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin1>
#define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 68000>
#define ENABLE_DEVELOPER_COMMANDS
#define ENABLE_SSD1306            // OLED
#define PLI_OFF_TIME 60 * 5 * 1000
#endif

#ifdef CONFIG_PRESETS

Preset saber [] = {
#if NUM_BLADES == 1
  { "TestRig", "",
    StylePtr<Red>(),
  "testrig"},
#endif
#if NUM_BLADES == 2
  { "TestRig", "",
    StylePtr<Red>(),StylePtr<Green>(),
  "testrig"},
#endif
  #if NUM_BLADES == 3
  { "TestRig", "",
    StylePtr<Red>(),StylePtr<Green>(),StylePtr<Blue>(),
  "testrig"},
#endif
  #if NUM_BLADES == 4
  { "TestRig", "",
    StylePtr<Red>(),StylePtr<Green>(),StylePtr<Blue>(),StylePtr<Yellow>(),
  "testrig"},
#endif
    #if NUM_BLADES == 5
  { "TestRig", "",
    StylePtr<Red>(),StylePtr<Green>(),StylePtr<Blue>(),StylePtr<Yellow>(),StylePtr<White>(),
  "testrig"},
#endif

};  

BladeConfig blades[] = {

#if NUM_BLADES == 1
{ 0,  
  WS281XBladePtr<10, blade2Pin,  Color8::GRB, PowerPINS<bladePowerPin1> >(),
CONFIGARRAY(saber)}, 
#endif
#if NUM_BLADES == 2
{ 0,  
  WS281XBladePtr<10, bladePin,  Color8::GRB, PowerPINS<bladePowerPin1> >(),
  WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2> >(),
CONFIGARRAY(saber)}, 
#endif
#if NUM_BLADES == 3
{ 0,  
  WS281XBladePtr<10, bladePin,  Color8::GRB, PowerPINS<bladePowerPin1> >(),
  WS281XBladePtr<13, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2> >(),
  WS281XBladePtr<13, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),
CONFIGARRAY(saber)}, 
#endif
#if NUM_BLADES == 4
{ 0,  
  WS281XBladePtr<13, bladePin,  Color8::GRB, PowerPINS<bladePowerPin1> >(),
  WS281XBladePtr<14, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2> >(),
  WS281XBladePtr<14, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),
  WS281XBladePtr<14, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
CONFIGARRAY(saber)}, 
#endif
#if NUM_BLADES == 5
{ 0,  
  WS281XBladePtr<13, bladePin,  Color8::GRB, PowerPINS<bladePowerPin1> >(),
  WS281XBladePtr<14, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2> >(),
  WS281XBladePtr<14, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),
  WS281XBladePtr<14, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
  WS281XBladePtr<14, blade5Pin, Color8::GRB, PowerPINS<bladePowerPin5,bladePowerPin6> >(),
CONFIGARRAY(saber)}, 
#endif
};

#endif // CONFIG_PRESETS

#if 0
#ifdef CONFIG_BUTTONS

#include "../scripts/proffieboard_test_script.h"
#warning !!! PROFFIEBOARD TEST SCRIPT ACTIVE !!!
V4TestScript script;
Blinker1 blinker1;
Blinker2 blinker2;
CapTest captest;
#endif  // CONFIG_BUTTONS
#endif // commented condition


#if 1
#ifdef CONFIG_BUTTONS

// For saber or dual_prop:
#if 1
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
Button Aux2Button(BUTTON_AUX2, aux2Pin, "aux2");
//Button Clip(BUTTON_CLIP_DETECT, aux2Pin, "clip");
#endif

// for swapped buttons
#if 0
Button PowerButton(BUTTON_POWER, auxPin, "pow");
Button AuxButton(BUTTON_AUX, aux2Pin, "aux");
#endif

// For blaster only:
#if 0
Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");
//Button ReloadButton(BUTTON_RELOAD, 24, "reload");
#endif

#endif // CONFIG_BUTTONS
#endif // all buttons

