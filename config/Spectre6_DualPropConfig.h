// ---------- Spectre 6 Dual Prop Saber/Blaster ----------
// 
// 10 pole connections
// -------------------
// NPXL DATA (bladePin)
// NPXL NEG (bladePowerPin2, bladePowerPin3)
// BATT+
// GND (BATT- or GND pad)
// SW2 (under rubber strip) (auxPin)
// SW3 (Latching red toggle) (to aux2Pin)
// BLST NEG (bladePowerPin5)
// BLST DATA (blade2pin)


#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 2
#define VOLUME 1400
const unsigned int maxLedsPerStrip = 146; 
#define CLASH_THRESHOLD_G 3.5
#define SHARED_POWER_PINS
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define BLADE_DETECT_PIN aux2Pin
#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
#define NO_REPEAT_RANDOM
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF

// --------- blaster --------------

#define BLASTER_ENABLE_AUTO // was #define ENABLE_BLASTER_AUTO
#define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
#define BLASTER_JAM_PERCENTAGE 5     // if not defined, random.
#define BLASTER_DEFAULT_MODE MODE_KILL
#endif

#ifdef CONFIG_PROP
#include "../props/dual_prop.h"
#include "../props/saber_BC_buttons.h"
#include "../props/blaster.h"
#undef PROP_TYPE
#define PROP_TYPE SaberBlasterProp<SaberBCButtons, Blaster>
#endif


#ifdef CONFIG_PRESETS

// Blades as follows
// 1: Crystal Chamber
// 2: Blade
// 3: Blaster LED
// 4. Accent Strip1
// 5. Accent Strip2

Preset saber [] = {

{ "StapleSword;common", "StapleSword/track/EzraTheme.wav",
// 1: Crystal Chamber
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    BlastL<White>,
    InOutTrL<TrInstant,TrFade<300>,Pulsing<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,10>>,3000>>>>(),
// 2: Blade
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
// 3: Blaster LED
  StylePtr<Black>(),
// 4. Accent Strip1
  StylePtr<Layers<Mix<LinearSectionF<Sin<Int<20>>,Int<4000>>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>,InOutTrL<TrInstant,TrInstant,Mix<LinearSectionF<Sin<Int<20>>,Int<4000>>,Black,RgbArg<OFF_COLOR_ARG,Rgb<2,72,255>>>>>>(),
// 5. Accent Strip2
  StylePtr<Layers<TransitionLoop<Black,TrConcat<TrCenterWipe<500>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,TrCenterWipe<500>>>,InOutTrL<TrInstant,TrInstant,TransitionLoop<Black,TrConcat<TrCenterWipe<500>,RgbArg<OFF_COLOR_ARG,Rgb<2,72,255>>,TrCenterWipe<500>>>>>>(),
"StapleSword"
},

};


Preset blaster[] = {

{ "Blaster", "StapleSword/track/EzraTheme.wav",
// 1: Crystal Chamber
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
    BlastL<White>,
    InOutTrL<TrInstant,TrFade<300>,Pulsing<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,10>>,3000>>>>(),
// 2: Blade
  StylePtr<Black>(),
// 3: Blaster LED
  StylePtr<Lockup<BlastFadeout<BlastFadeout<Black,AudioFlicker<Black,Red>,250,EFFECT_FIRE>,AudioFlicker<Black,Blue>,1500,EFFECT_STUN>,AudioFlicker<Black,Red>>>(),
// 4. Accent Strip1
  StylePtr<Layers<Mix<LinearSectionF<Sin<Int<20>>,Int<4000>>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>>,InOutTrL<TrInstant,TrInstant,Mix<LinearSectionF<Sin<Int<20>>,Int<4000>>,Black,RgbArg<OFF_COLOR_ARG,Rgb<2,72,255>>>>>>(),
// 5. Accent Strip2
  StylePtr<Layers<TransitionLoop<Black,TrConcat<TrCenterWipe<500>,RgbArg<BASE_COLOR_ARG,Rgb<0,135,255>>,TrCenterWipe<500>>>,InOutTrL<TrInstant,TrInstant,TransitionLoop<Black,TrConcat<TrCenterWipe<500>,RgbArg<OFF_COLOR_ARG,Rgb<2,72,255>>,TrCenterWipe<500>>>>>>(),
"Blaster"
},

};


BladeConfig blades[] = {
  { 0,  
// 1: Crystal Chamber
    SubBlade(0, 1, WS281XBladePtr<146, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin5> >()),
// 2: Blade
    SubBlade(2, 145, NULL),
// 3: Blaster LED
    WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
// 4. Accent Strip1
    WS281XBladePtr<14, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
// 5. Accent Strip2
    WS281XBladePtr<14, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(),
  CONFIGARRAY(saber),
  "SaberSave"},

  { NO_BLADE, 
// 1: Crystal Chamber
    SubBlade(0, 1, WS281XBladePtr<146, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3, bladePowerPin5> >()),
// 2: Blade
    SubBlade(2, 145, NULL),
// 3: Blaster LED
    WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
// 4. Accent Strip1
    WS281XBladePtr<14, blade3Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
// 5. Accent Strip2
    WS281XBladePtr<14, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(),
  CONFIGARRAY(blaster),
  "blasterSave"}
};

#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
