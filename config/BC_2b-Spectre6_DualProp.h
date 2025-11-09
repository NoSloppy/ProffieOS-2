// ---------- Spectre 6 Dual Prop Saber/Blaster ----------

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 2
#define VOLUME 1400
const unsigned int maxLedsPerStrip = 144; 
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define BLADE_DETECT_PIN aux2Pin   
#define SAVE_STATE
#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_PARSER_STYLES
#define BC_LOCKUP_DELAY 200
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 1 * 1000
//#define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> 
//    Millis is Blade ID scan interval. If the blade ID comes out the same as before, it will do nothing.
//    If it comes out different, it will do FindBladeAgain(), which will basically initialize the saber from scratch and load the right settings for the new id().
//    It will only work with neopixel blades, and it probably requires SHARED_POWER_PINS to work.
// #define BLADE_ID_SCAN_MILLIS 1000
//    How many Blade ID scans to average
// #define BLADE_ID_TIMES 10
// --------- blaster --------------

#define ENABLE_BLASTER_AUTO
#define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
#define BLASTER_JAM_PERCENTAGE 1     // if not defined, random.
#define DEFAULT_BLASTER_MODE MODE_KILL

#endif

#ifdef CONFIG_PROP
#include "../props/dual_prop.h"
#include "../props/saber_BC_buttons_personal.h"
#include "../props/blaster.h"
#undef PROP_TYPE
#define PROP_TYPE SaberBlasterProp<SaberBCButtons, Blaster>
#endif


#ifdef CONFIG_PRESETS

Preset saber [] = {
  
{ "StapleSword", "StapleSword/tracks/EzraTheme.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    BlastL<White>,
    InOutTrL<TrInstant,TrFade<300>,Pulsing<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,10>>,3000>>>>(),
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    LockupTrL<Layers<
      AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
      AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    AlphaL<RotateColorsX<Variation,Rgb<150,150,255>>,Bump<Int<0>,Int<8000>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipe<300>,TrWipeIn<500>>>>(),
  StylePtr<Black>(),
  "Saber"}
};

Preset blaster[] = {

{ "Blaster", "StapleSword/tracks/EzraTheme.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    BlastL<White>,
    InOutTrL<TrInstant,TrFade<300>,Pulsing<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,10>>,3000>>>>(),
  StylePtr<Black>(),
  StylePtr<Lockup<BlastFadeout<BlastFadeout<Black,AudioFlicker<Black,Red>,250,EFFECT_FIRE>,AudioFlicker<Black,Blue>,1500,EFFECT_STUN>,AudioFlicker<Black,Red>>>(),
  "Blaster"}
};

BladeConfig blades[] = {
{ 0, 
  SubBlade(0, 1, WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >()),
  SubBlade(2, 143, NULL),
  WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),
CONFIGARRAY(saber),
"SaberSave"}, 
{ NO_BLADE, 
  SubBlade(0, 1, WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >()),
  SubBlade(2, 143, NULL),
	WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),
CONFIGARRAY(blaster),
"blasterSave"}

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
