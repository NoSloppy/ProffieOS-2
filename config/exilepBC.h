#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 1
#define VOLUME 50
const unsigned int maxLedsPerStrip = 148;
#define CLASH_THRESHOLD_G 2.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define SHARED_POWER_PINS
#define MOTION_TIMEOUT 60 * 10 * 1000
#define IDLE_OFF_TIME 60 * 10 * 1000
#define DISABLE_BASIC_PARSER_STYLES
#define DISABLE_DIAGNOSTIC_COMMANDS
#define ENABLE_ALL_EDIT_OPTIONS
#define SAVE_PRESET
//#define KEEP_SAVEFILES_WHEN_PROGRAMMING
#define NO_REPEAT_RANDOM
#define COLOR_CHANGE_DIRECT
#define FETT263_EDIT_MODE_MENU
//#define FETT263_SAY_COLOR_LIST
//#define FETT263_SAY_COLOR_LIST_CC
#define FETT263_SAY_BATTERY_PERCENT
#define FETT263_MOTION_WAKE_POWER_BUTTON
#define FETT263_TRACK_PLAYER_NO_PROMPTS
#define FETT263_DISABLE_COPY_PRESET
#define FETT263_RANDOMIZE_QUOTE_PLAYER
#define FETT263_BATTLE_MODE
#define FETT263_LOCKUP_DELAY 200
#define FETT263_BM_CLASH_DETECT 6
#define FETT263_THRUST_ON
//#define FETT263_TWIST_ON
//#define FETT263_TWIST_ON_NO_BM
#define FETT263_TWIST_OFF
//#define FETT263_MULTI_PHASE
#define FETT263_SPECIAL_ABILITIES
//#define DISABLE_TALKIE
#define FILTER_CUTOFF_FREQUENCY 90
#define FILTER_ORDER 8
//#define FETT263_FORCE_PUSH
#define FETT263_HOLD_BUTTON_LOCKUP
#define DISABLE_COLOR_CHANGE
#define FETT263_DISABLE_CHANGE_STYLE

#define ENABLE_ALL_EDIT_OPTIONS
#define MOUNT_SD_SETTING

#endif

#ifdef CONFIG_PROP
//#include "../props/saber_fett263_buttons_next_E.h"
#include "../props/saber_BC_buttons_personal.h"
// #include "../props/saber_fett263_buttons.h"
#endif


#ifdef CONFIG_STYLES


InMemoryDisplay<9, 9, 3> matrix_display;
StandardColorDisplayController<9, 9> matrix_display_controller(&matrix_display);
NAME_INSTANCE(matrix_display, MYMATRIX);

#endif

#ifdef CONFIG_PRESETS



Preset p1[] = {

// { "testfont", "",
//   StylePtr<Red>(),
//   StylePtr<Green>(),
//   StylePtr<Blue>(),
// "test"},

{ "aa_JayDalorian/OdaNobunaga;ProffieOS_V2_Voicepack_The_Ronin/common;commonBU", "aa_JayDalorian/OdaNobunaga/tracks/sharingan.wav",
StylePtr<DisplayStyle<MYMATRIX>>(),
"imgtest"},

};



BladeConfig blades[] = {
  { 0,
    SubBladeWithList<0, 1, 2, 3,4,5,6,7>(WS281XBladePtr<8, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3>>() ),
    // SubBladeWithStride (4, 6, 2, NULL),
    // SubBladeWithStride (5, 7, 2, NULL),
    CONFIGARRAY(p1),
  "1savep"}
};
// { 0,
//   SubBladeWithList<0, 1, 2, 3>(WS281XBladePtr<5, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ), /* Test List */
//   SubBlade(4, 4, NULL),
//   CONFIGARRAY(p1), "1savep"
//  },
//  { 1,
//      SubBlade(16, 93,WS281XBladePtr<148, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ), /* 20in main blade 78px */
//      SubBladeWithStride (0, 14, 2, NULL), /* emitter inner ring 8px */
//      SubBladeWithStride (1, 15, 2, NULL), /* emitter outer ring 8px */

//      WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), /* crystal chamber 11px */

//      WS281XBladePtr<15, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(), /* chassis strip right 15px */

//      WS281XBladePtr<15, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(), /* chassis strip left 15px */

//      CONFIGARRAY(p1), "1savep" },
      
//  { 2,
//          SubBlade(16, 105,WS281XBladePtr<148, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ), /* 24in main blade 90px */
//          SubBladeWithStride (0, 14, 2, NULL), /* emitter inner ring 8px */
//          SubBladeWithStride (1, 15, 2, NULL), /* emitter outer ring 8px */

//          WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), /* crystal chamber 11px */

//          WS281XBladePtr<15, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(), /* chassis strip right 15px */

//          WS281XBladePtr<15, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(), /* chassis strip left 15px */

//          CONFIGARRAY(p1), "1savep" },

//  { 3,
//          SubBlade(16, 132,WS281XBladePtr<148, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ), /* 32in main blade 117px */
//          SubBladeWithStride (0, 14, 2, NULL), /* emitter inner ring 8px */
//          SubBladeWithStride (1, 15, 2, NULL), /* emitter outer ring 8px */

//          WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), /* crystal chamber 11px */

//          WS281XBladePtr<15, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(), /* chassis strip right 15px */

//          WS281XBladePtr<15, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(), /* chassis strip left 15px */

//          CONFIGARRAY(p1), "1savep" },
 
//  { 4,
//          SubBlade(16, 147,WS281XBladePtr<148, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >() ), /* 36in main blade 132px */
//          SubBladeWithStride (0, 14, 2, NULL), /* emitter inner ring 8px */
//          SubBladeWithStride (1, 15, 2, NULL), /* emitter outer ring 8px */

//          WS281XBladePtr<11, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(), /* crystal chamber 11px */

//          WS281XBladePtr<15, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin6> >(), /* chassis strip right 15px */

//          WS281XBladePtr<15, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(), /* chassis strip left 15px */

//          CONFIGARRAY(p1), "1savep" }, 
               

#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, auxPin, "pow");
Button AuxButton(BUTTON_AUX, powerButtonPin, "aux");
#endif