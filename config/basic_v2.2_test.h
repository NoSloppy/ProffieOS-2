// PB v2.2 basic_test w/ Kim 4x1515s

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 4
#define NUM_BUTTONS 1
#define VOLUME 100
const unsigned int maxLedsPerStrip = 144;
#define EXTRA_COLOR_BUFFER_SPACE 30               // New define that can speed up processing a bit. Basically, it can calculate the colors for the next blade (or the next frame for the same blade) even though it's not done feeding out the data for the data in the color buffer yet.
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL //Bluetooth or UART TTL (make_default_console if TTL) baud 115200
#define SHARED_POWER_PINS
#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    // #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING     // upload overwrites presets.ini/tmp unless this is defined
//#define BLADE_DETECT_PIN blade3Pin
// #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000> // if pullup resistor on v2.2 board btw data1 and 3.3v pads
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> // This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors 
//                         Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value, so I would recommend using something like 200000 instead of NO_BLADE.
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                    // SPDIF out
#define ENABLE_DEVELOPER_COMMANDS
// #define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SDA_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE
// #define ORIENTATION_ROTATION 0,-20,0
//changes the angle required to register twists on curved hilts
//example is for assaj ventress curved hit install

// #define CONFIG_STARTUP_DELAY 15000              // BC now canon
#define FEMALE_TALKIE_VOICE                       // BC now canon
#define VOLUME_MENU_CYCLE                         // BC prop
#define NO_REPEAT_RANDOM                          // BC now canon

// ------- OLED stuff ----------

//#define ENABLE_SSD1306                            // OLED
//#define OLED_FLIP_180                             // BC now canon
//#define OLED_MIRRORED
// #define USE_AUREBESH_FONT                      // BC now canon
#define OLED_SYNCED_EFFECTS
// #define PLI_OFF_TIME 60 * 5 * 1000

// ------- Gesture stuff -------

#define BC_SWING_ON
#define BC_SWING_ON_SPEED 250
// #define BC_STAB_ON
#define BC_THRUST_ON
// #define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS 
// # define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200

// ------- Custom / Experimental / Alpha-Beta stuff ---------

#define DISABLE_BASIC_PARSER_STYLES               // Standard, Advanced, etc...
// #define NO_VOLUME_MENU 
//#define NO_BLADE_NO_GEST_ONOFF                    // If using blade detect, No Blade = No Gesture ignitions or retractions
#define AUTO_HUMSTART                             // 200ms delay from on.wav beginning all the time.             **Requires modified hybrid_font.h file.
#define ENABLE_AUTO_SPINS_BLAST                   // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define LOW_BATT_ONCE                          // No repeated warnings
// #define LOW_BATT_WARNINGS_TIERED                // meh...just annoying if not accurate..likely.                                                            **Requires modified hybrid_font.h file.
// #define ENABLE_GESTURE_MENU                    // PSISTORM prop - cool stuff! the TrySound else beep void.

#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8

//#define POV_INCLUDE_FILE "Pretend_data.h"


#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS

Preset test[] = {


{ "Dmaul", "",
  StylePtr<Red>(),
  StylePtr<Green>(),
  StylePtr<Blue>(),
  StylePtr<White>(),
"test"},


};

BladeConfig blades[] = {

{ NO_BLADE, 
    WS281XBladePtr<4, bladePin, Color8::GRB, PowerPINS<bladePowerPin1> >(),
    WS281XBladePtr<4, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2> >(),
    WS281XBladePtr<4, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin3> >(),
    WS281XBladePtr<4, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin4, bladePowerPin5, bladePowerPin6> >(),

CONFIGARRAY(test),
"00_test_save", },


};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");

#endif

// // Button connect to 3.3v instead of GND. Up to 5v is OK
// PullDownButton PowerButton(BUTTON_POWER, powerButtonPin, "pow"); // isn't this backwards?

// // Analog Potentiometer 
// ChangeVolumeAnalogReceiver volume_function;
// PotClass pot(0, &volume_function);

// // Or, you can use it to change the variation (color):

// ChangeVariationAnalogReceiver variation_function;
// PotClass pot(0, &variation_function);

// ChangeVariationAnalogReceiver receiver;
// PotClass pot(data4pin, &receiver);

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
