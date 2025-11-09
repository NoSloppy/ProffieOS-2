// DualProp saber and blaster based on blade detect

#ifdef CONFIG_TOP
#include "proffieboard_v1_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 1
#define VOLUME 100
const unsigned int maxLedsPerStrip = 144; 
#define EXTRA_COLOR_BUFFER_SPACE 30               // New define that can speed up processing a bit. Basically, it can calculate the colors for the next blade (or the next frame for the same blade) even though it's not done feeding out the data for the data in the color buffer yet.
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL //Bluetooth or UART TTL
#define SHARED_POWER_PINS
#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    // #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING     // upload overwrites presets.ini/tmp unless this is defined
// #define DISABLE_COLOR_CHANGE
//#define COLOR_CHANGE_DIRECT
#define BLADE_DETECT_PIN blade3Pin
// #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> // This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors 
//                         Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value, so I would recommend using something like 200000 instead of NO_BLADE.
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #deefine ENABLE_SPDIF_OUT
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
#define VOLUME_MENU_CYCLE                         // BC now canon
#define NO_REPEAT_RANDOM                          // BC now canon
// #define DISABLE_TALKIE

// ------- OLED stuff ----------

#define ENABLE_SSD1306                            // OLED
// #define OLED_FLIP_180                             // BC now canon
// #define OLED_MIRRORED
// #define USE_AUREBESH_FONT                      // BC now canon
#define OLED_SYNCED_EFFECTS
#define PLI_OFF_TIME 60 * 5 * 1000

// ------- Gesture stuff -------

#define BC_SWING_ON
#define BC_SWING_ON_SPEED 250
#define BC_STAB_ON
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
#define BC_FORCE_PUSH
#define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS 
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200

// ------- Custom / Experimental stuff ---------

#define DISABLE_BASIC_PARSER_STYLES               // Standard, Advanced, etc...
// #define NO_VOLUME_MENU                            // self evident
#define NO_BLADE_NO_GEST_ONOFF                    // If using blade detect, No Blade = No Gesture ignitions or retractions
#define AUTO_HUMSTART                             // 200ms delay from out.wav beginning all the time.             **Requires modified hybrid_font.h file.
#define ENABLE_AUTO_SPINS_BLAST                   // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define LOW_BATT_ONCE                          // No repeated warnings
// #define LOW_BATT_WARNINGS_TIERED                // meh...just annoying if not accurate..likely.                                                            **Requires modified hybrid_font.h file.
// #define ENABLE_GESTURE_MENU                    // PSISTORM prop - cool stuff! the TrySound else beep void.
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
// #define POV_INCLUDE_FILE "erik_BIG216x532_copy_123_SC_POV_data.h"

// ---------Edit Mode Stuff -------------
#define ENABLE_ALL_EDIT_OPTIONS
    // #define DYNAMIC_BLADE_LENGTH
    // #define DYNAMIC_BLADE_DIMMING
    // #define DYNAMIC_CLASH_THRESHOLD
    // #define SAVE_VOLUME
    // #define SAVE_BLADE_DIMMING
    // #define SAVE_CLASH_THRESHOLD
    // #define SAVE_COLOR_CHANGE

// --------- blaster --------------

#define ENABLE_BLASTER_AUTO
#define BLASTER_SHOTS_UNTIL_EMPTY 5  // (whatever number)
#define BLASTER_JAM_PERCENTAGE 10     // if not defined, random.
#define DEFAULT_BLASTER_MODE MODE_KILL

#endif

// #ifdef CONFIG_PROP // Change buttons to FIRE and MODE down in CONFIG_BUTTONS if blaster only
// #include "../props/blaster_BC.h"
// #endif

#ifdef CONFIG_PROP
#include "../props/dual_prop.h"
#include "../props/saber_BC_buttons_personal.h"
#undef PROP_TYPE
#include "../props/blaster_BC_buttons.h"
// #include "../props/blaster.h"
#undef PROP_TYPE
#define PROP_TYPE SaberBlasterProp<SaberBCButtons, BlasterBC>
// #define PROP_TYPE SaberBlasterProp<SaberBCButtons, Blaster>
#endif

#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"     // For Red, Green, light Blue, ...light colored blades
#include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"
#include "aliases/TrueWhites/BC_effects_2.h"     // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"   // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_White.h" // For White blades


Preset saber [] = {
  
{ "TeensySF;common", "",
// main blade
  StylePtr<Red>(),
// muzzle
  StylePtr<Black>(),
// barrel
  StylePtr<Black>(),
  "1. message only"},

{ "testfont2a;common;commonBU", "testfont2a/tracks/track2.wav",
// main blade  
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
  // Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
    AlphaL<Black,Int<16384>>,
    AlphaL<Black,Int<0>>>,
  // Clash
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
  // Stab 
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,DarkOrange,Rgb<80,60,0>,Orange,Rgb<60,30,0>,Black,DarkOrange,Orange>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
  // Blast - white to red for blue and green blades
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
    BlastL<Red,850,250,351>,
    AlphaL<TransitionEffectL<TrConcat<TrDelay<300>,Red,TrFade<500>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
    BlastL<White,500,300,100000>,
  // Lockup
    LockupTrL<Layers<       
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
      AlphaL<BrownNoiseFlicker<Yellow,Black,50>,                                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
      TrConcat<TrInstant,
      AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
  // Non-Responsive Drag
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
  // Lightning Block Non-Responsive    
    LockupTrL<AlphaL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
    Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
    Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
    Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
    //Begin Lightning Transition
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
    //End Lightning Transition    
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,       
  // Melt    
    LockupTrL<
    AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
    // Melt Shape
    SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
    //Melt Begin and End transitions
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,  // Great melt colors as you twist, gets dripping red hot/fire and bright yellow.
  // Ignition / Retraction
    InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_FORCE>,Ifon<Int<0>,Int<32768>>>
  >>(),
// muzzle
  StylePtr<Black>(),
// barrel
  StylePtr<Black>(),
  "2. has font, has idle"},

{ "1-NIGHTFALL;common", "",
// main blade
  StylePtr<Red>(),
// muzzle
  StylePtr<Black>(),
// barrel
  StylePtr<Black>(),
  "3. has font, no idle"},


{ "17-ANCIENT_PROPHECIES;common", "",
// main blade
  StylePtr<Red>(),
// muzzle
  StylePtr<Black>(),
// barrel
  StylePtr<Black>(),
  "testing\naurebesh"},


{ "BOBA_S1E5_MANDO_SABER;common", "",
// main blade
  StylePtr<Red>(),
// muzzle
  StylePtr<Black>(),
// barrel
  StylePtr<Black>(),
  "1. message only"},

};  

//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------

Preset blaster[] = {

{ "testblaster;common;commonBU", "testblaster/tracks/track1.wav",
// Main BLade
  StylePtr<Black>(),
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,
    // TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  >>(),
// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipe<100>,White,TrInstant,Red,TrWipe<150>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<100>,AlphaL<Black,Int<0>>,TrDelay<100>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
      TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  >>()
  "testblaster\nbladeout"},

{ "blaster1;common;commonBU", "blaster1/tracks/ImperialMarchROTJ3_long.wav",
// Main BLade
  StylePtr<Black>(),
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,
    // TransitionEffectL<TrConcat<TrInstant,Mix<Sin<Int<12>>,Pulsing<Red,Black,800>,Pulsing<Red,Black,100>>,TrDelayX<Int<10000>>>,EFFECT_DESTRUCT>
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  >>(),
// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipe<100>,White,TrWipe<100>,Red,TrWipe<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  >>(),
  "blaster1\nbladeout"},

{ "F11-D;blaster1;common;commonBU", "blaster1/tracks/ImperialMarchROTJ3_long.wav",
// Main BLade
  StylePtr<Black>(),
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  >>(),
// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipe<100>,White,TrWipe<100>,Red,TrWipe<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>,
    TransitionEffectL<TrConcat<TrInstant,Mix<Trigger<EFFECT_DESTRUCT,WavLen<EFFECT_DESTRUCT>,Int<1>,Int<1>>,Pulsing<Red,Black,1000>,Pulsing<Red,Black,500>,Strobe<Black,Red,15,30>>,TrDelayX<WavLen<EFFECT_DESTRUCT>>>,EFFECT_DESTRUCT>
  >>(),
  "f11-d\nbladeout"}

};

BladeConfig blades[] = {
{ 0,  
  WS281XBladePtr<144, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2,bladePowerPin3> >(),  // D2 Test leads
  SubBlade (3, 3, WS281XBladePtr<4, blade5Pin, Color8::GRB, PowerPINS<bladePowerPin4> >() ), // Onboard 4 LEDs (last one it muzzle)
  SubBlade (0, 2, NULL),                                                                      // barrel
CONFIGARRAY(saber),
"00_SaberSave"}, 
{ NO_BLADE, 
  WS281XBladePtr<144, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2,bladePowerPin3> >(),  // D2 Test leads
  SubBlade (3, 3, WS281XBladePtr<4, blade5Pin, Color8::GRB, PowerPINS<bladePowerPin4> >() ), // Onboard 4 LEDs (last one it muzzle)
  SubBlade (0, 2, NULL),                                                                      // barrel
CONFIGARRAY(blaster),
"01_blasterSave"}

};
#endif

#ifdef CONFIG_BUTTONS

// For saber or dual_prop:
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
Button Clip(BUTTON_CLIP_DETECT, aux2Pin, "clip");

// // For blaster only:
// Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
// Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");
// //Button ReloadButton(BUTTON_RELOAD, 24, "reload");

#endif

/*
// // Button connect to 3.3v instead of GND. Up to 5v is OK
// PullDownButton PowerButton(BUTTON_POWER, powerButtonPin, "pow"); // isn't this backwards?

// // Analog Potentiometer 
// ChangeVolumeAnalogReceiver volume_function;
// PotClass pot(0, &volume_function);

// // Or, you can use it to change the variation (color):

// ChangeVariationAnalogReceiver variation_function;
// PotClass pot(0, &variation_function);

// // Rotary Encoder (see rotary.h)

// ChangePresetRotaryReceiver rotary_receiver;
// Rotary<8, 9> rotary(&rotary_receiver);

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
  WriteBulletCountOp<10, 20, 3> // <x?, y?, #of digits>
> display_controller;
SSD1306Template<64, uint32_t> display(&display_controller);
#endif


- what's the diff between that and then this?:

Support for 128x64 OLED
#ifdef CONFIG_BOTTOM
SSD1306Template<128, uint64_t> display(0x3C);
#endif

Also,
#define INCLUDE_SSD1306

Without it, the section at the bottom will throw errors.

Note that you should not have #define ENABLE_SSD1306 in your CONFIG_TOP section.
That will try to enable a 128x32 display, which will not work.*/


