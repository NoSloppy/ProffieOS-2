// BC_Vektra_7.x 

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 1
// #define DUAL_POWER_BUTTONS                        // BC Make both buttons identical for 1-btn use... useful? **not working 100%

// ------ Audio Stuff --------

#define VOLUME 1500
#define BOOT_VOLUME 200
#define ENABLE_AUDIO
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                     // SPDIF out
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
// #define FEMALE_TALKIE_VOICE                      // BC now canon OS6
#define NO_REPEAT_RANDOM                          // BC now canon
#define KILL_OLD_PLAYERS                          // BC now canon
#define DISABLE_TALKIE                            // I feel I'm not gonna like this

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;
//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet. Equivalent to just increasing maxLedsPerStrip.
// #define EXTRA_COLOR_BUFFER_SPACE 30
// #define SHARED_POWER_PINS
// #define BLADE_DETECT_PIN blade3Pin
// #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9>         // TX pad
//    This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
//    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value, so I would recommend using something like 200000 instead of NO_BLADE.
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> 
//    Millis is BladeID scan interval. If the blade ID comes out the same as before, it will do nothing.
//    If it comes out different, it will do FindBladeAgain(), which will basically initialize the saber from scratch and load the right settings for the new id().
//    It will only work with neopixel blades, and it probably requires SHARED_POWER_PINS to work.
// #define BLADE_ID_SCAN_MILLIS 1000

// ------ SD Card Stuff -------

#define ENABLE_SD
// #define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//    Upload overwrites presets.ini/tmp unless this is defined
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING 

// ------- OLED stuff ----------

// #define VERBOSE_READIMAGE_TIMING
// #define ENABLE_SSD1306                         // OLED display. also defines ENABLE_DISPLAY_CODE
// #define OLED_FLIP_180                              // BC now canon
// #define USE_AUREBESH_FONT                          // BC now canon
// #define OLED_SYNCED_EFFECTS
// #define PLI_OFF_TIME 60 * 5 * 1000
// #define OLED_USE_BLASTER_IMAGES
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144_SC_POV_data.h"
// #define POV_INCLUDE_FILE "Raiden_123_FC_POV_data.h"
// #define POV_INCLUDE_FILE "JohnCena_144_8b_POV_data.h"
//    Turns power to the OLED display off once SCREEN_OFF state. (Either IDLE_OFF_TIME or PLI_OFF_TIME) **Not really needed
// #define DISPLAY_POWER_PINS PowerPINS<bladePowerPin6>

// ------ System Stuff --------

// #define VERBOSE_SD_ERRORS                    // investigate
// #define PROFFIEOS_DONT_USE_GYRO_FOR_CLASH    // investigate
// #define ENABLE_DEBUG
// #define NO_BATTERY_MONITOR
// #define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
// #define ENABLE_DEVELOPER_COMMANDS
#define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SDA_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE
//    The following changes the angle required to register twists on curved hilts.
//    Example is for Assaj Ventress curved hilt install.
// #define ORIENTATION_ROTATION 0,-20,0

// #define CONFIG_STARTUP_DELAY 15000                 // BC now canon
#define DISABLE_BASIC_PARSER_STYLES                 // Standard, Advanced, Old School original templated styles etc...

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3.5
// #define BC_SWING_ON                                 // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
// #define BC_STAB_ON
#define BC_THRUST_ON
// #define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
#define BC_ENABLE_AUTO_SWING_BLAST                     // BC Multiblast continues as long as swinging within 1 second. 
#define ENABLE_SPINS
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
// #define NO_BLADE_NO_GEST_ONOFF                   // If using blade detect, No Blade = No Gesture ignitions or retractions

// ------- Custom / Experimental / Alpha-Beta stuff ---------

// #define ENABLE_GESTURE_MENU                      // PSISTORM prop - cool stuff! the TrySound else beep void.  

// -------- BC Prop Other Stuff --------

// #define NO_VOLUME_MENU                             // self evident. But why?

// -------- Blaster Stuff ----------

// #define ENABLE_BLASTER_AUTO
// #define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
// #define BLASTER_JAM_PERCENTAGE 10     // if not defined, random.

#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS 

#include "aliases/TrueWhites/BC_effects_1.h"              // For Green, light Blue, ...light colored blades
// #include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"  // EffectSequence driven different blast animations
// #include "aliases/TrueWhites/BC_effects_2.h"              // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"            // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_White.h"          // For White blades
#include "aliases/TrueWhites/BC_12color_8effect_SS.h"     // Uses BC_SWAP for base blade color. All in one blade style from CC Fork. 96 possible blade combos in one style. .

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

/*__Presets List___
// aa_Kyberphonic/Praetorian_Elite
1. aa_JayDalorian/Vortex
2. aa_JayDalorian/Subspace
3. aa_JayDalorian/Eve
4. aa_JayDalorian/Nexus
5. aa_JayDalorian/Kyber_Weapon
6. aa_JayDalorian/Blood_Bath
7. aa_JayDalorian/Reboot_Redux
8. aa_Greyscale/SteelAndFire_Greyscale
9. aa_Greyscale/Protostar_Greyscale
10. aa_Greyscale/Mercenary_Greyscale
11. aa_Blueforce/LiquidStatic
12. aa_Blueforce/JediKiller
13. aa_Blueforce/Fracture
14. aa_Blueforce/CrystalRadiance
15. aa_Juansith/Sereph100
16. aa_Juansith/HATE
17. aa_Syndicate/Retribution
*/


Preset Vektra[] = {

  // underwhelmed by overload. Too much cookoo crazy all together on this one.
  // used new fonts from FONTS_TO_DO here. JayDalorian pack.
  // used 12color_8effect
  
//  { "aa_Kyberphonic/Praetorian_Elite/Bilari_electro-chain_whip;aa_Kyberphonic/Praetorian_Elite;common;commonBU", "aa_Kyberphonic/Praetorian_Elite/tracks/A_New_Alliance_1.wav",

// StylePtr<Layers<
//   Stripes<1000,-100,Stripes<100,2000,Red,Black,RandomPerLEDFlicker<Mix<Int<10280>,Black,Red>,Mix<Int<3855>,Black,Red>>>,Stripes<200,-3000,Red,RandomPerLEDFlicker<Mix<Int<7710>,Black,Red>,Black>,RandomPerLEDFlicker<Mix<Int<10280>,Black,Red>,Mix<Int<3855>,Black,Red>>>>,
//   Mix<LayerFunctions<LinearSectionF<Int<4000>,Int<1000>>,LinearSectionF<Int<9000>,Int<1000>>,LinearSectionF<Int<14000>,Int<1000>>,LinearSectionF<Int<19000>,Int<1000>>,LinearSectionF<Int<24000>,Int<1000>>,LinearSectionF<Int<29000>,Int<1000>>,LinearSectionF<Int<34000>,Int<1000>>>,Black,
//   Layers<
//   BC_effects_Red,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrInstant,TrConcat<TrFadeX<RetractionTime<>>,HumpFlickerL<White,50>,TrInstant>>>>,
//   // Volume Level - gradient Blue -> Green
//     OnDemandVolumeLevel,
//   // On-Demand Battery Level
//     OnDemandBatteryLevel
//   >>(),
// "bilari"},

// --------------------------------

{ "aa_JayDalorian/Vortex;common;commonBU", "",
  StylePtr<Layers<
    StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,20>,RotateColorsX<Variation,Rgb<4,0,8>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,RotateColorsX<Variation,Rgb<42,0,105>>>,RotateColorsX<Variation,Rgb<30,0,66>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
    AlphaL<Stripes<2500,-3000,Red,Rgb<60,0,0>,Pulsing<Rgb<30,0,0>,Black,800>>,SwingSpeed<600>>,
    SparkleL<White,100,300>,
  BC_effects_Red,
    InOutTrL<TrConcat<TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<400>,Int<32768>>,Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<350>,Int<32768>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<300>,Int<32768>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<250>,Int<32768>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<200>,Int<32768>>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrWipeIn<200>,Mix<SmoothStep<Int<33000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrDelay<100>,AudioFlickerL<White>,TrFade<550>>,TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<300>,RotateColorsX<Variation,Rgb<95,0,210>>,TrWipe<300>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<200>,Int<200>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<200>,Int<250>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<300>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<350>,Int<350>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<400>,Int<0>>,Black,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<400>,Int<400>,Int<0>>,Black,TrInstant>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFadeX<Percentage<WavLen<>,35>>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFadeX<Percentage<WavLen<>,35>>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,30>>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrBoingX<Percentage<WavLen<EFFECT_PREON>,16>,3>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,15>,Bump<Int<0>,Int<5000>>>,TrFadeX<Percentage<WavLen<EFFECT_PREON>,33>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,10>,Bump<Int<0>,Int<8000>>>,TrFadeX<Percentage<WavLen<EFFECT_PREON>,33>>,AlphaL<HumpFlickerL<White,20>,Bump<Int<0>,Int<12000>>>,TrInstant>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"vortex"},

{ "aa_JayDalorian/Subspace;common;commonBU", "",
  StylePtr<Layers<
    AudioFlicker<BrownNoiseFlicker<Mix<SwingSpeed<400>,RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<170,150,225>>>,Stripes<5000,-300,RotateColorsX<Variation,Rgb<35,25,55>>,RotateColorsX<Variation,Rgb<90,75,120>>,RotateColorsX<Variation,Rgb<15,10,20>>,RotateColorsX<Variation,Rgb<60,50,75>>>,300>,RotateColorsX<Variation,Rgb<45,35,75>>>,
    AlphaL<Mix<SwingSpeed<600>,Red,Orange,White>,Scale<SwingSpeed<600>,Int<0>,Int<32768>>>,
    BC_effects_1,
    InOutTrL<TrConcat<TrWipe<800>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<170,150,225>>,Black,300>,TrWipe<100>,Black,TrBoing<1600,3>>,TrConcat<TrWipe<200>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<100,100,150>>>,TrWaveX<RotateColorsX<Variation,Yellow>,Int<100>,Int<150>,Int<100>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Yellow>>,TrWaveX<RotateColorsX<Variation,Yellow>,Int<125>,Int<300>,Int<150>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Yellow>>,TrWaveX<RotateColorsX<Variation,Yellow>,Int<150>,Int<300>,Int<150>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Yellow>>,TrWaveX<RotateColorsX<Variation,Yellow>,Int<175>,Int<300>,Int<175>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Yellow>>,TrWaveX<RotateColorsX<Variation,Yellow>,Int<200>,Int<300>,Int<200>,Int<0>>,Black,TrWaveX<RotateColorsX<Variation,DodgerBlue>,Int<200>,Int<300>,Int<200>,Int<0>>,Black,TrInstant>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Blue,Bump<Int<0>,Int<10000>>>,TrFade<3000>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BlinkingL<Blue,Int<300>,Int<500>>,Bump<Int<0>,Int<4000>>>,TrBoing<500,3>,AlphaL<BlinkingL<DodgerBlue,Int<200>,Int<500>>,Bump<Int<4000>,Int<4000>>>,TrBoing<750,2>,AlphaL<BlinkingL<DeepSkyBlue,Int<100>,Int<500>>,Bump<Int<0>,Int<4000>>>,TrDelay<435>>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"subspace"},

{ "aa_JayDalorian/Eve;common;commonBU", "", // WavNum Paired Force Effects, even/odd.
  StylePtr<Layers<
    StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,20>,RotateColorsX<Variation,Rgb<4,0,8>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,RotateColorsX<Variation,Rgb<42,0,105>>>,RotateColorsX<Variation,Rgb<30,0,66>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
    BC_effects_1,
    ColorSelect<WavNum<EFFECT_FORCE>,TrInstant,
      Layers< TransitionEffectL<TrConcat<TrFade<100>,AudioFlicker<Rgb<0,50,50>,Black>,TrDelay<620>,Cylon<Black,10,800,Yellow,10,120,1>,TrDelay<2815>>,EFFECT_FORCE>,
              TransitionEffectL<TrConcat<TrJoin<TrSparkX<White,Int<1100>,Int<720>,Int<0>>,TrSparkX<White,Int<1100>,Int<720>,Int<32768>>>,AlphaL<Black,Int<0>>,TrSparkX<Yellow,Int<80>,Int<750>>,AlphaL<AudioFlicker<Rgb<0,100,100>,Black>,Int<10000>>,TrDelay<1100>,AlphaL<Black,Int<0>>,TrSparkX<Yellow,Int<80>,Int<750>>,AlphaL<AudioFlicker<Rgb<0,100,100>,Black>,Int<10000>>,TrFade<659>,HumpFlicker<White,Black,50>,TrInstant>,EFFECT_FORCE>>,
      TransitionEffectL<TrConcat<TrFade<400>,Sparkle<ColorCycle<Blue,0,1,Cyan,2,200,1>,RotateColorsX<SlowNoise<Int<2000>>,Red>,1000,100>,TrDelayX<WavLen<EFFECT_FORCE>>>,EFFECT_FORCE>>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
    InOutTrL<TrWipeSparkTip<Yellow,450>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
    TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RandomPerLEDFlickerL<Yellow>,SmoothStep<Int<3000>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrWipe<200>,BrownNoiseFlickerL<Magenta,Int<200>>,TrWipeIn<200>>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"eve"},

{ "aa_JayDalorian/Nexus;common;commonBU", "", // Ice Stab and scanning Force
  StylePtr<Layers<
    StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<30,0,66>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<7,0,16>>,RotateColorsX<Variation,Rgb<95,0,210>>>,
    BC_effects_White,
    TransitionEffectL<TrConcat<TrFade<400>,RotateColorsX<Variation,Rgb<160,60,255>>,TrDelay<7000>,RotateColorsX<Variation,Rgb<160,60,255>>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Stripes<10,-1600,Mix<Sin<Int<30>>,White,Black>,Mix<Sin<Int<30>>,White,Black>,Mix<Sin<Int<24>>,Green,White>>,Bump<Scale<Sin<Int<40>>,Int<1000>,Int<34000>>,Int<20000>>>,TrDelay<7000>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrFade<3000>,RotateColorsX<Variation,Rgb<95,0,210>>,TrDelay<5000>,RotateColorsX<Variation,Rgb<95,0,210>>,TrFade<3000>>,EFFECT_STAB>,
    TransitionEffectL<TrConcat<TrWipe<3000>,TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Rgb<100,150,230>,TrFade<3000>,TrDelay<3000>,EFFECT_STAB>,TrDelay<3000>,Rgb<100,150,230>,TrWipe<3000>>,EFFECT_STAB>,
    TransitionEffectL<TrConcat<TrWaveX<BrownNoiseFlicker<White,SteelBlue,60>,Int<3000>,Int<400>,Int<3000>,Int<0>>,AlphaL<White,Int<0>>,TrDelay<3000>,AlphaL<White,Int<0>>,TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,Int<10000>,Int<400>,Int<3000>,Int<0>>>,EFFECT_STAB>,
    InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTipX<White,WavLen<EFFECT_RETRACTION>>>,
    TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RandomPerLEDFlickerL<White>,SmoothStep<Int<6000>,Int<-4000>>>,TrDelayX<WavNum<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrColorCycle<1000,0>,GhostWhite,TrFade<100>>,EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"nexus"},

{ "aa_JayDalorian/Kyber_Weapon;common;commonBU", "",
  StylePtr<Layers<
    BC_12color_8effect_SS,
      BC_effects_White,
    InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTipX<White,WavLen<EFFECT_RETRACTION>>>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"kyber\nweapon"},

{ "aa_JayDalorian/Blood_Bath;common;commonBU", "",
  StylePtr<Layers<
    StyleFire<StripesX<Int<3000>,Scale<SlowNoise<Int<2000>>,Int<-1000>,Int<-5000>>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,RotateColorsX<Variation,Rgb<10,0,0>>>,RotateColorsX<Variation,Rgb<255,25,25>>,RotateColorsX<Variation,Rgb<128,0,0>>>,RotateColorsX<Variation,Rgb<80,0,0>>,0,5,FireConfig<3,3000,0>,FireConfig<3,3000,0>,FireConfig<3,3000,0>,FireConfig<3,3000,0>>,
    SparkleL<White,100,400>,
    BC_effects_Red,
    InOutTrL<TrWipeSparkTip<White,900>,TrWipeInSparkTipX<White,WavLen<EFFECT_RETRACTION>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrDelay<200>,AlphaL<HumpFlickerL<Rgb<100,100,150>,30>,Bump<Int<0>,Int<3000>>>,TrFade<500>,AlphaL<HumpFlickerL<Rgb<100,100,150>,30>,Bump<Int<0>,Int<4000>>>,TrFade<1000>,AlphaL<HumpFlickerL<Rgb<100,100,150>,30>,Bump<Int<0>,Int<5000>>>,TrBoing<1950,7>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrSparkX<Rgb<100,100,150>,Int<200>,Int<500>,Int<32768>>>,TrDelay<1500>,TransitionLoopL<TrSparkX<Rgb<100,100,150>,Int<300>,Int<300>,Int<32768>>>,TrDelay<1500>,TransitionLoopL<TrSparkX<Rgb<100,100,150>,Int<400>,Int<100>,Int<32768>>>,TrDelay<1200>>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"blood\nbath"},

{ "aa_JayDalorian/Kyber_White;common;commonBU", "",
  StylePtr<Layers<
    StaticFire<Stripes<2500,-2000,BrownNoiseFlicker<LightCyan,Black,20>,AliceBlue,BrownNoiseFlicker<Black,MistyRose,70>,FloralWhite>,Cornsilk,0,3,1,3000,0>,
    AlphaL<Stripes<2500,-3000,Blue,DeepSkyBlue,Pulsing<DodgerBlue,Black,800>>,SwingSpeed<600>>,
    BC_effects_White,
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<800>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>,

    InOutTrL<TrWipeSparkTip<Blue,500>,TrWipeInSparkTipX<Blue,WavLen<EFFECT_RETRACTION>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFadeX<Percentage<WavLen<EFFECT_POSTOFF>,15>>,AlphaL<DodgerBlue,Bump<Int<0>,Int<8000>>>,TrFadeX<Percentage<WavLen<EFFECT_POSTOFF>,15>>,AlphaL<Blue,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<EFFECT_POSTOFF>,70>>>,EFFECT_POSTOFF>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<HumpFlickerL<LavenderBlush,15>,Bump<Int<0>,Int<40000>>>,TrWipeInX<Percentage<WavLen<EFFECT_PREON>,20>>,AlphaL<HumpFlickerL<White,20>,Bump<Int<0>,Int<6000>>>,TrBoingX<Percentage<WavLen<EFFECT_PREON>,80>,3>>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"kyber\nwhite"},

{ "aa_JayDalorian/Reboot_Redux;common;commonBU", "",
  StylePtr<Layers<
    Mix<SmoothStep<Int<16000>,Int<10000>>,RotateColorsX<Variation,Blue>,StyleFire<RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,0,3,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,
  // Emitter Flare
      AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,
    BC_effects_1,   
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
    InOutTrL<TrWipeSparkTip<White,1000>,TrWipeInSparkTip<White,1300>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrDelay<1500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<3000>>>,TrFade<2000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<4000>>>,TrFade<2500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<5000>>>,TrBoing<1950,7>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<500>,Int<200>,Int<500>,Int<32768>>>,TrDelay<1500>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<300>,Int<300>,Int<32768>>>,TrDelay<2000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<100>,Int<400>,Int<100>,Int<32768>>>,TrDelay<3000>,AlphaL<RotateColorsX<Variation,Rgb<95,0,210>>,Bump<Int<0>,Int<6000>>>,TrBoing<1450,5>>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"reboot\nredux"},

// --------------------------------

{ "aa_Greyscale/SteelAndFire_Greyscale;common;commonBU", "",
  StylePtr<Layers<
  // Base Fett263 Magenta Audioflicker
    AudioFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<95,0,95>>>,
  // Deep Pink HumpFlicker Swing Effect
    AlphaL<HumpFlicker<RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,Rgb<105,0,210>>,50>,SwingSpeed<375>>,
    BC_effects_White,
  // Unstable HumpFlicker Ignition Effect
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Magenta>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<95,0,95>>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<1250>,HumpFlicker<RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,Magenta>,50>,TrFade<1250>,AudioFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<95,0,95>>>,TrFade<700>,AudioFlicker<RotateColorsX<Variation,Rgb<105,0,210>>,RotateColorsX<Variation,Rgb<58,0,105>>>,TrFade<300>,HumpFlicker<RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,Rgb<105,0,210>>,50>,TrFade<750>>,EFFECT_IGNITION>,
  // Fett263 Bright HumpFlicker retraction Effect
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<195,60,225>>,40>,TrFadeX<WavLen<EFFECT_RETRACTION>>>,EFFECT_RETRACTION>,
  // White spark tip ignition and retraction
    InOutTrL<TrJoin<TrWipeX<Percentage<WavLen<EFFECT_IGNITION>,4>>,TrWaveX<White,Percentage<WavLen<EFFECT_IGNITION>,15>,Int<400>,Percentage<WavLen<EFFECT_IGNITION>,4>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
  // Clicky retraction "post off" effect
    TransitionEffectL<TrConcat<TrDelayX<WavLen<EFFECT_RETRACTION>>,AlphaL<Pulsing<Rgb<120,120,165>,Rgb<50,50,80>,40>,Bump<Int<0>,Int<9000>>>,TrDelayX<Percentage<WavLen<EFFECT_POSTOFF>,50>>>,EFFECT_RETRACTION>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"steel and\nfire"},

{ "aa_Greyscale/Protostar_Greyscale;common;commonBU", "",
  StylePtr<Layers<
  // Base Fett263 Dark Orange Audioflicker
    AudioFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<128,34,0>>>,
  // Unstable Orange-Red Audioflicker Swing Effect
    AlphaL<AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,Black,300>,RotateColorsX<Variation,Orange>>,SwingSpeed<285>>,
  // Fett263 Bright Ripple Hard Swing
    AlphaL<Stripes<2000,-3250,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<60,36,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,17,0>>,Black,800>>,Scale<IsLessThan<SwingSpeed<675>,Int<13600>>,Scale<SwingSpeed<675>,Int<-19300>,Int<32768>>,Int<0>>>,
  // Fett263 Bright Sparking Emitter Flare
    AlphaL<RotateColorsX<Variation,Rgb16<65535,52226,0>>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1500>,Int<4500>>,Int<-6000>>>,
    BC_effects_1,
  // Fett263 White Unstable Ignition Effect
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-2500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<2400>>,EFFECT_IGNITION>,
  // Bright Retraction Effect
    TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,AudioFlickerL<RotateColorsX<Variation,Rgb16<65535,52226,0>>>,TrInstant>,EFFECT_RETRACTION>,
  // Fett263 Power Save, if using his prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
  // Fett263 Dual Mode White Spark Tip Ignition and Retraction - Hold above horizontal for fast ignition or below horizontal for slow ignition.
    InOutTrL<TrJoin<TrWipeX<Scale<IsLessThan<BladeAngle<>,Int<16000>>,Percentage<WavLen<EFFECT_IGNITION>,5>,Percentage<WavLen<EFFECT_IGNITION>,50>>>,TrWaveX<White,Scale<IsLessThan<BladeAngle<>,Int<16000>>,Percentage<WavLen<EFFECT_IGNITION>,15>,Percentage<WavLen<EFFECT_IGNITION>,75>>,Int<400>,Scale<IsLessThan<BladeAngle<>,Int<16000>>,Percentage<WavLen<EFFECT_IGNITION>,5>,Percentage<WavLen<EFFECT_IGNITION>,50>>,Int<0>>>,TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
  // Audio responsive charge-up preon effect
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Percentage<WavLen<EFFECT_PREON>,33>,Percentage<WavLen<EFFECT_PREON>,34>,Percentage<WavLen<EFFECT_PREON>,33>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb16<65535,52226,0>>>,RotateColorsX<Variation,Rgb<60,30,0>>,0,1,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,RandomPerLEDFlicker<RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb16<14386,7000,0>>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Orange>,100>>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<25000>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
  // Ripple-Out Preon Effect
    TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_PREON>,65>>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb16<65535,52226,0>>,Int<115>,Int<375>,Int<250>,Int<0>>>,TrDelayX<Percentage<WavLen<EFFECT_PREON>,35>>>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"protostar"},

{ "aa_Greyscale/Mercenary_Greyscale;common;commonBU", "",
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb<15,14,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<90,87,0>>,Black>>,RotateColorsX<Variation,Rgb<40,40,0>>,Pulsing<RotateColorsX<Variation,Rgb<36,33,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb<60,58,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<90,88,0>>,RotateColorsX<Variation,Rgb<5,5,0>>,3000>>,
    AlphaL<StyleFire<RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb<2,2,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
    AlphaL<RotateColorsX<Variation,LemonChiffon>,SmoothStep<Scale<SlowNoise<Int<2750>>,Int<1750>,Int<3750>>,Int<-4000>>>,
    AlphaL<Stripes<2500,-3000,RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb<44,42,0>>,Pulsing<RotateColorsX<Variation,Rgb<22,20,0>>,Black,800>>,SwingSpeed<375>>,
  BC_effects_White,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFadeX<Percentage<WavLen<>,125>>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<500>>,EFFECT_IGNITION>,
    InOutTrL<TrWipeSparkTip<White,200>,TrColorCycleX<WavLen<EFFECT_RETRACTION>,950,7500>>,
    TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,33>>,TransitionLoopL<TrJoin<TrWipeIn<142>,TrSparkX<RotateColorsX<Variation,LemonChiffon>,Int<425>,Int<142>,Int<32768>>>>,TrDelayX<Percentage<WavLen<>,67>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Percentage<WavLen<>,33>,Percentage<WavLen<>,67>,Int<0>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,HotPink>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,LightPink>,RotateColorsX<Variation,LemonChiffon>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,DeepPink>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Yellow>>>,RotateColorsX<Variation,LemonChiffon>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-350>,Int<17500>>,Int<-4000>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Black,SmoothStep<Sin<Int<10>,Int<16500>,Int<14500>>,Sin<Int<7>,Int<10500>,Int<9500>>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,White,TrDelay<25>>,EFFECT_POSTOFF>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"mercenary"},

// --------------------------------

{ "aa_Blueforce/LiquidStatic;common;commonBU", "",
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Blue,Mix<Int<2570>,Black,Blue>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Blue>,Black>>,Mix<Int<7710>,Black,Blue>,Pulsing<Mix<Int<6425>,Black,Blue>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Blue,Mix<Int<12000>,Black,Blue>>,2000>,Pulsing<Mix<Int<16448>,Black,Blue>,Mix<Int<642>,Black,Blue>,3000>>,
    AlphaL<StaticFire<Blue,Mix<Int<256>,Black,Blue>,0,1,10,2000,2>,Int<10000>>,
    AlphaL<LightCyan,SmoothStep<Int<2000>,Int<-6000>>>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1200>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Blue,RandomPerLEDFlicker<Mix<Int<7710>,Black,Blue>,Black>,BrownNoiseFlicker<Blue,Mix<Int<3855>,Black,Blue>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Blue>,Mix<Int<3855>,Black,Blue>>>,TrInstant>,EFFECT_RETRACTION>,
    BC_effects_1,
    InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTipX<LightCyan,WavLen<EFFECT_RETRACTION>,Int<401>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"liquid\nstatic"},

{ "aa_Blueforce/JediKiller;common;commonBU", "",
  StylePtr<Layers<
    StripesX<Int<18000>,Int<-1600>,Red,RandomFlicker<Red,Mix<Int<16384>,Black,Red>>,RandomFlicker<Red,Stripes<9000,-900,Red,Mix<Int<7710>,Black,Red>>>>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<>>,TrInstant>,White,TrFade<1000>>,EFFECT_IGNITION>,
    BC_effects_Red,
    InOutTrL<TrWipeSparkTipX<White,IgnitionTime<>>,TrColorCycleX<RetractionTime<>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BlinkingL<Mix<Int<16384>,White,Red>,Int<300>,Int<500>>,SmoothStep<Int<1821>,Int<-2000>>>,TrBoingX<Mult<WavLen<EFFECT_PREON>,Int<2458>>,3>,AlphaL<BlinkingL<Mix<Int<8192>,White,Red>,Int<200>,Int<500>>,SmoothStep<Int<1821>,Int<-4000>>>,TrJoin<TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<29082>>>,TrBoingX<Mult<WavLen<EFFECT_PREON>,Int<1638>>,3>>>,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"jedi\nkiller"},

{ "aa_Blueforce/Fracture;common;commonBU", "",
  StylePtr<Layers<
    StyleFire<Gradient<Yellow,OrangeRed,Red>,Cyan,0,3,FireConfig<100,2500,21>,FireConfig<50,1000,0>,FireConfig<50,10,10>,FireConfig<0,0,13>>,
    BC_effects_Red,
    InOutTrL<TrWipeSparkTipX<DodgerBlue,IgnitionTime<2100>,Int<200>>,TrWipeInSparkTipX<DodgerBlue,RetractionTime<>,Int<200>>>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"fracture"},

{ "aa_Blueforce/CrystalRadiance;common;commonBU", "",
  StylePtr<Layers<
    Mix<HoldPeakF<SwingSpeed<200>,Int<300>,Scale<SwingSpeed<200>,Int<8000>,Int<24000>>>,Mix<Int<16384>,Black,Rgb<100,100,150>>,RandomFlicker<Mix<Int<16384>,Black,Rgb<100,100,150>>,StripesX<Int<16000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingSpeed<200>,Int<1000>,Int<4000>>,Scale<SwingSpeed<200>,Int<4000>,Int<8000>>>,Int<-100>,Int<-3000>>,Mix<Int<24576>,Black,Rgb<100,100,150>>,Rgb<100,100,150>,Mix<Int<8192>,Black,Rgb<100,100,150>>>>>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<>>,TrInstant>,Rgb<30,60,200>,TrFade<1000>>,EFFECT_IGNITION>,
    BC_effects_White,
    InOutTrL<TrColorCycleX<IgnitionTime<>>,TrFadeX<RetractionTime<>>>,
    TransitionEffectL<TrInstant,EFFECT_PREON>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"crystal\nradiance"},

// --------------------------------

  { "aa_Juansith/Sereph100;common;commonBU", "",
  StylePtr<Layers<
    StripesX<Int<6000>,Int<-1000>,RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<24,24,35>>>,AlphaL<White,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    AlphaL<Stripes<4000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Black>,White,RotateColorsX<Variation,Rgb<100,100,150>>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    BC_effects_White,  
    InOutTrL<TrWipe<400>,TrConcat<TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,50>>,Stripes<3000,2000,White,Rgb<100,100,100>>,TrFadeX< Percentage<WavLen<EFFECT_RETRACTION>,50> >>>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"sereph100"},

{ "aa_Juansith/HATE;common;commonBU", "",
  StylePtr<Layers<
    Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrFadeX<WavLen<>>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<600>>,EFFECT_IGNITION>,
    InOutTrL<TrWipeSparkTip<Rgb<200,100,100>,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"hate"},

// --------------------------------

{ "aa_Syndicate/Retribution;common;commonBU", "",
  StylePtr<Layers<
    Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,StaticFire<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>,0,6>,Stripes<5000,-1500,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,105>>>>,
    BC_effects_1,
    InOutTrL<TrConcat<TrWipe<200>,Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,StaticFire<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,26,60>>,0,6>,Stripes<5000,-1500,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<21,0,52>>,RotateColorsX<Variation,Rgb<130,40,230>>,RotateColorsX<Variation,Rgb<42,0,105>>>>,TrWipe<100>,Black,TrBoing<300,3>>,TrBoing<500,3>>,
  // Volume Level - gradient Blue -> Green
    OnDemandVolumeLevel,
  // On-Demand Battery Level
    OnDemandBatteryLevel
  >>(),
"retribution"},

};


BladeConfig blades[] = {
 { 0, // CT_A 132 BC_A 123
  WS281XBladePtr<123, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  CONFIGARRAY(Vektra),
  "00_Vektra_save" }

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, auxPin, "aux");
Button AuxButton(BUTTON_AUX, powerButtonPin, "pow");
#endif


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
