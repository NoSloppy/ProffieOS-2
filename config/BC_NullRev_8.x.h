// BC_NullRev_8.x

#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BUTTONS 1
#define NUM_BLADES 2
// ------ Audio Stuff --------

#define VOLUME 2000
#define BOOT_VOLUME 100
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                   // SPDIF out
#define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8  // default is 8
// #define FEMALE_TALKIE_VOICE
// #define DISABLE_TALKIE
#define ENABLE_FASTON
#define ENABLE_IDLE_SOUND

// ------ Blade Stuff ------

// #define ENABLE_WS2811     defaulted OS8
const unsigned int maxLedsPerStrip = 144;
//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet. Equivalent to just increasing maxLedsPerStrip.
#define EXTRA_COLOR_BUFFER_SPACE 30


// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000> // resistor value used

// BridgedPullupBladeID is the default Proffieboard V3 BLADE_ID_CLASS, so it doesn't need to defined explicitly with a V3.
// #define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9> // PBv2.2 TX pad for example

/*  SnapshotBladeID is the default Proffieboard V1.5 and V2.2 BLADE_ID_CLASS, so it doesn't need to defined explicitly.
    It will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors.
    Blade ID can detect if a blade is connected or not, but it won't actually reach the NO_BLADE value,
    so using something like 200000 instead of NO_BLADE is best. */
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin>

/*
-- Real Time BladeID --
 
Main blade must be wired to data1
Blades can use the same set of presets, or have a Presets array for each blade.
Arrays should be named differently like no_blade, blade_1, blade_2,  etc...
Match Preset array names names to the CONFIGARRAY for the given blade.

Open Serial Monitor in Arduino and type `id` to read the resistance value.
It will display "BLADE ID: (some number)"
Use that value in the blade definition in the BladeConfig.
* Note * It is recommended to use a Blade ID resistor in each blade 
to ensure different and distant enough resistance values between blades. 
However, in testing, values reported for a chassis alone,
chassis inserted into the hilt (connected to emitter PCB)
and then main blade inserted all gave different enough values on their own
without added resistors and it worked fine. YMMV.
*/

//    Blanket define to cover the following 4 // BC Personal only
#define REAL_TIME_BLADE_ID_POWER_PINS 2, 3

                //    Use with Blade ID. Specify the LED pad(s) that the main blade uses.
                 // #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>

                //    Required when blades on different data pads use common LED power pads.
                //    and/or when BLADE_ID_SCAN_MILLIS is used with Blade ID.
                 // #define SHARED_POWER_PINS

                //    Choose how often to check for new blade (milliseconds).
                //    Larger values will be a longer delay before a blade is recognized.
                // #define BLADE_ID_SCAN_MILLIS 1000

                //    How many Blade ID scans to average (default is 10, works well)
                // #define BLADE_ID_TIMES 15

                // Not blanketed. This will make the blade ID class for that range return NO_BLADE (use NO_BLADE as the blade definition value.)
                #define NO_BLADE_ID_RANGE 40000,99999999


// Show blade ID value every BLADE_ID_SCAN_MILLIS
// #define PROFFIEOS_LOG_LEVEL 500


//    Requires wiring a pad to a switched GND
//    (floating pogo pin until grounded via blade-side PCB ring)
// #define BLADE_DETECT_PIN 10 

// To be able to edit blade length on the saber via a menu, use the following define:
#define DYNAMIC_BLADE_LENGTH

// The BC_buttons menu for blade length adjust automatically knows if there is more than one blade, and if so, all are editable.
// The OS System Menu version for Dynamic Blade Length adjustment, the OS menu system will default to 1 removable blade. If there are more, use this define
// with the blades numbers based on the BladeConfig array entry order, separated by a commas 
// #define REMOVABLE_BLADES 1,2

// #define BC_DUAL_BLADES
// BLADE # corresponds to the blades list in the BladeConfig section of the config file.
// Defaults are BLADE 1 and BLADE 2 as MAIN and SECOND blades respectively.
// Optionally, you can also manually define custom dual blades if different than 1 and 2, for example:
// #define BC_MAIN_BLADE 2
// #define BC_SECOND_BLADE 4

// ------ SD Card Stuff -------

#define MOUNT_SD_SETTING  
// This define will allow manual control of when to allow the SD to mount to the computer when Mass Storage is enabled by issuing 'sd 1' in Serial Monitor.  
// First let's review how Mass Storage works.  
// Having the Arduino setting Tools>USB Type> Serial + Mass Storage selected allows the SD card to be accessed over USB (using the Proffieboard as a card reader).  
// The way it used to work before OS8 and this define was after the boot sound played, the SD card would immediately mount to the computer as an external USB drive.  
// File transfers could take place then, and when finished, you would eject the SD from the computer. From then, the Proffieboard would use it as normal.
// This meant that you always had to wait for the SD card to mount, and then eject it before uploading or using Serial Monitor.  
// It also meant that to re-access the SD, you'd need to either reboot, or unplug and then re-plug the USB cable.  
// Now here's how it can work in OS8 using #define MOUNT_SD_SETTING.  
// Even though Mass Storage was selected and uploaded, this define prevents the SD card from mounting until manually "allowed" by the user.  
// To allow the SD to mount, send the command "sd 1" in Serial Monitor.  
// When you finish accessing the SD card and "eject" it from the computer, the Proffieboard will use it as normal and set the permission back to FALSE.  
// If you want to access the SD again, you can just issue the 'sd 1' command again, and repeat as above.

//#define SAVE_STATE
    // #define SAVE_VOLUME
       #define SAVE_PRESET
       #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//    Upload overwrites presets.ini/tmp unless this is defined
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING

// ------- OLED stuff ----------

// #define ENABLE_SSD1306                         // OLED display. also defines ENABLE_DISPLAY_CODE
// #define OLED_FLIP_180                          // BC now canon
// #define OLED_MIRRORED                          // BC now canon
// #define USE_AUREBESH_FONT                      // BC now canon
// #define OLED_SYNCED_EFFECTS
// #define PLI_OFF_TIME 60 * 5 * 1000
// #define OLED_USE_BLASTER_IMAGES
// #define POV_INCLUDE_FILE "1024px-Star_Wars_Logo.svg_144_SC_POV_data.h"

// ------ System Stuff --------

 //#define ENABLE_DEBUG
   // PVLOG_ERROR 100 = errors
   // PVLOG_STATUS 200 = things you should probably know, like blade ID
   // PVLOG_NORMAL 300 = normal information about what is happening (default level)
   // PVLOG_DEBUG 400 = information helpful for debugging
   // PVLOG_VERBOSE 500 = repeated, spammy information you don't normally want
// #define PROFFIEOS_LOG_LEVEL 400

// #define ENABLE_SERIAL //Bluetooth
// #define DISABLE_COLOR_CHANGE
// #define COLOR_CHANGE_DIRECT
// #define ENABLE_DEVELOPER_COMMANDS
#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_CCW_FROM_BLADE
// #define ORIENTATION ORIENTATION_USB_CW_FROM_BLADE
//    The following changes the angle required to register twists on curved hilts.
//    Example is for Assaj Ventress curved hilt install.
// #define ORIENTATION_ROTATION 0,-20,0
#define ORIENTATION_ROTATION 0,20,0

// Give serial monitor a chance to catchup at boot,
// and/or for waiting until speaker pod is connected on certain chassis etc...
 #define CONFIG_STARTUP_DELAY 5000


// ------- Motion and Gesture stuff -------

#define CLASH_THRESHOLD_G 3.5
#define ENABLE_SPINS

// Use this define to turn on an optional "iPod® Clickwheel" sound when rotating the hilt in smooth colorchange mode (Color Wheel).
// mclick.wav will play, so the sound should probably be a very subtle "tick" sound.
// The value is the number of ticks per 360 hilt rotation. Higher number = more ticks per angle change.
// Suggested Range 50 - 120. Using zero or not defining will turn ticks off.
#define SMOOTH_COLORCHANGE_TICKS_PER_REVOLUTION 120
// Rotation sensitivity
#define STEPS_PER_REVOLUTION 24
//#define COLLECT_THRUST_TELEMETRY

// --- BC prop stuff -----

#define BC_SWING_ON
#define BC_SWING_ON_SPEED 400 // Default 250
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
 #define BC_ENABLE_AUTO_SWING_BLAST                     // BC Multiblast continues as long as swinging within 1 second. 
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
/*    If using blade detect, Gesture ignitions or retractions are
      disabled when no blade is used. BC prop.
      **NOTE** Only works when a BLADE_DETECT_PIN is defined.*/
// #define NO_BLADE_NO_GEST_ONOFF

// ------- Custom / Experimental / Alpha-Beta stuff ---------

// #define LOW_BATT_ONCE                            // BC - THIS NEEDS TO BE CheckLowBattry(), see PR     **Requires modified hybrid_font.h file.

// -------- BC Prop Other Stuff --------

// As of OS8, the default for the BC_buttons prop file are volume level and blade length edit menus.
// A System Menu is available to edit presets, colors settings, and more. To use this menu system instead, use the following define:
// #define MENU_SPEC_TEMPLATE DefaultMenuSpec



#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"                 // For Red, Green, light Blue, ...light colored blades
// #include "aliases/TrueWhites/BC_effects_1_BlastRotate.h"     // EffectSequence driven different blast animations
// #include "aliases/TrueWhites/BC_effects_2.h"                 // for crystals chambers or accents
#include "aliases/TrueWhites/BC_effects_Red.h"               // For Red or dark blades
#include "aliases/TrueWhites/BC_effects_White.h"             // For White blades
// #include "aliases/TrueWhites/BC_12color_8effect_SS.h"        // All in one blade style from CC Fork. SS = SwingSpeed included 

#include "aliases/BC_shortcuts.h"

/* ---- Presets list ---- /*

a_CORRAN_HORN/JUMPBIKE
aa_HarrySolo/ORBITAL
a_CORRAN_HORN/CA_74Z
a_CORRAN_HORN/Son_Of_Corellia - EffectSequence<EFFECT_FORCE, CC
a_CORRAN_HORN/CorranHorn
a_CORRAN_HORN/SpeederBike
aa_NoSloppy/DiscWars
aa_JayDalorian/Subspace
aa_JayDalorian/Vortex
aa_BVM/Absorbed
aa_BVM/Alias
aa_BVM/Astral_Projection
aa_BVM/Celsius
aa_BVM/High_Voltage
aa_BVM/Poison
aa_BVM/Son_of_a_Glitch
aa_BVM/Terra
aa_BVM/The_Baron
aa_BVM/The_Cursed_Saber
aa_BVM/Zero
Whispers_Of_Power
aa_MountainSabers/QuantumKnight
aa_KSith/ScrapTecHP-BC
aa_KSith/SoverignHP-BC

*/




// Preset noblade [] = {
// { "JUMPBIKE;ProffieOS_V2_Voicepack_Huyang/common;commonBU", "tracks/JF17.wav",
// // Main blade Whire flutter ColorChange to Purple noisy.
//   StylePtr<Yellow>(),

//   StylePtr<Layers<
//     ColorCycle<Red,25,100,Red,25,300,4000>,
//     InOutTrL<TrInstant,TrInstant,TransitionLoop<Red,TrConcat<TrBoing<1200,2>,Mix<Int<1285>,Black,Red>,TrFade<1200>>>>
//   >>(),

// "jumpbike"},

// };


Preset bladein[] = {

{ "a_CORRAN_HORN/JUMPBIKE;ProffieOS_V2_Voicepack_Huyang/common;commonBU", "tracks/JF17.wav",
// Main blade Whire flutter ColorChange to Purple noisy.
  StylePtr<Layers<
    ColorChange<TrFade<1000>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,Rgb<100,100,150>,Rgb<100,100,150>,Rgb<24,24,35>,Rgb<100,100,150>,Rgb<59,59,88>>,Rgb<100,100,150>>,Stripes<3000,-3500,Rgb<115,15,240>,RandomPerLEDFlicker<Rgb<27,4,57>,Black>,BrownNoiseFlicker<Rgb<115,15,240>,Rgb<13,2,28>,200>,RandomPerLEDFlicker<Rgb<36,5,75>,Rgb<14,2,28>>>>,
    BC_effects_White,
    BC_Bend7_Spark_WavOUT_NoSpark_WavIN,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    ColorCycle<Red,25,100,Red,25,300,4000>,
    InOutTrL<TrInstant,TrInstant,TransitionLoop<Red,TrConcat<TrBoing<1200,2>,Mix<Int<1285>,Black,Red>,TrFade<1200>>>>
  >>(),
"jumpbike"},

{ "aa_HarrySolo/ORBITAL;ProffieOS_V2_Voicepack_Huyang/common;commonBU", "tracks/JF17.wav", 
  StylePtr<Layers<
    StaticFire<Stripes<2500,-5000,BrownNoiseFlicker<DarkOrange,Black,20>,Rgb<10,3,0>,BrownNoiseFlicker<Black,Mix<Int<3212>,DarkOrange,White>,70>,Rgb<128,34,0>>,Rgb<80,21,0>,0,5,2,3000,0>,
    AlphaL<TransitionEffect<OrangeRed,AlphaL<OrangeRed,Int<0>>,TrInstant,TrConcat<TrFade<1000>,Red,TrFade<1000>,Orange,TrFade<1000>>,EFFECT_IGNITION>,SmoothStep<Int<5446>,Int<-6000>>>,
    TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrConcat<TrJoin<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<200>,Int<700>>>,TrWipe<200>>,RandomPerLEDFlickerL<Red>,TrWipe<200>>>,TrFade<300>>,EFFECT_FORCE>,
    TransitionEffectL<TrRandom<TrWaveX<Moccasin,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,TrWaveX<Moccasin,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>>,EFFECT_BLAST>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<LightCyan,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
    LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<Int<16000>,Int<-12000>>,Sum<Int<16000>,Int<10000>>>,Sum<Int<16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<Cyan,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Rgb<0,50,50>,Cyan,Rgb<0,100,100>>>,AlphaL<AudioFlicker<Cyan,Rgb<0,80,80>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Sum<Int<16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,Cyan,AlphaL<Cyan,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,Cyan,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Cyan,AudioFlicker<Cyan,Blue>,50,1>,TrConcat<TrInstant,AlphaL<Cyan,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<Cyan,Int<16000>>,30>,TrSmoothFade<600>>>,
    LockupTrL<AlphaL<RandomPerLEDFlickerL<Rgb<180,130,0>>,SmoothStep<Int<28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<Rgb<180,130,0>,Int<300>>,SmoothStep<Int<28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,MoltenCore,RotateColorsX<Int<3000>,MoltenCore>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,MoltenCore>,RotateColorsX<Int<3000>,Rgb<93,9,0>>>,0,3,5,3000,10>>,SmoothStep<Int<28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<MoltenCore,SmoothStep<Int<28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,MoltenCore,RotateColorsX<Int<3000>,MoltenCore>>,SmoothStep<Int<28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTipX<Blue,IgnitionTime<450>,Int<100>>,TrWipeInSparkTipX<Blue,RetractionTime<0>,Int<100>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<Red,SmoothStep<Int<5446>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"orbital"},

{ "a_CORRAN_HORN/CA_74Z;ProffieOS_V2_Voicepack_Huyang/common;commonBU", "tracks/JFO5.wav", 
// CA-74Z - Brian Conner 7-21
  StylePtr<Layers<
    AudioFlicker<Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,Blue>,
// Swing Color
    AlphaL<Pulsing<Blue,LightCyan,1000>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    BC_effects_1,
        TransitionEffectL<TrConcat<TrInstant,White,TrSmoothFade<500>,Strobe<StyleFire<HumpFlicker<DeepPink,Stripes<10000,-3000,Cyan,DarkOrange>,50>,Cyan,0,5,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,100,0>,FireConfig<0,2000,5>>,Red,15,20>,TrSmoothFade<600>>,EFFECT_IGNITION>,
  InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWaveX<White,Int<800>,Int<400>,Int<400>,Int<0>>>,TrFade<200>>,
  TransitionEffectL<TrJoinR<TrConcat<TrInstant,SparkleL<AudioFlicker<Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,Blue>>,TrFade<400>,AlphaL<AudioFlicker<Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,Blue>,Bump<Scale<Trigger<EFFECT_RETRACTION,Int<1>,Int<800>,Int<800>>,Int<-5000>,Int<1000>>,Int<10000>>>,TrDelay<3000>>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrDelay<133>,AlphaL<Black,Int<0>>,TrJoin<TrWipeIn<4133>,TrWaveX<White,Int<6000>,Int<350>,Int<4133>,Int<32768>>>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrDelay<50>,Black,TrWaveX<GreenYellow,Int<200>,Int<100>,Int<200>,Int<32768>>,White,TrDelay<50>,AlphaL<Red,SmoothStep<Int<3000>,Int<-6000>>>,TrFade<450>,AlphaL<OrangeRed,SmoothStep<Int<10000>,Int<-8000>>>,TrFade<450>,AlphaL<HumpFlicker<Rgb<208,128,128>,Red,20>,SmoothStep<Int<16000>,Int<-8000>>>,TrFade<50>,White,TrJoin<TrWipeIn<150>,TrWaveX<Green,Int<150>,Int<75>,Int<150>,Int<32768>>>>,EFFECT_PREON>,
  AlphaL<HumpFlicker<DeepPink,Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,50>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<2500>,Int<1000>,Int<1>>,Int<-32768>,Int<32768>>,Int<-8000>>>,
  TransitionEffectL<TrConcat<TrDelay<2500>,Layers<
    HumpFlicker<Cyan,DeepPink,40>,
    AlphaL<Black,Int<25000>>>,TrSmoothFade<963>,Strobe<StyleFire<HumpFlicker<DeepPink,Stripes<10000,-3000,Cyan,DarkOrange>,50>,Cyan,0,5,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,100,0>,FireConfig<0,2000,5>>,Red,15,20>,TrInstant>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrDelay<2120>,White,TrDelay<80>,AlphaL<Black,Int<0>>,TrDelay<200>,Cyan,TrDelay<80>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrDelay<3275>,AlphaL<Black,Int<0>>,TrWipeIn<188>,Black,TrInstant>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"ca_74z"},


{ "a_CORRAN_HORN/Son_Of_Corellia;ProffieOS_V2_Voicepack_Huyang/common;commonBU", "tracks/JF17.wav", 
/*
Kyber Weapon saber sound font by JayDalorian. https://jaydalorian.com 
Blade style NoSloppy 2023.
This style is customizable. 

Each time you do force, it cycles through 9 different base blade effects,
and each can be changed to 12 different colors for a total of 108 different base blade choices in real time while blade is running. 
*/
  StylePtr<Layers<
    EffectSequence<EFFECT_FORCE,
    // Fett263 Unstable
    Layers<
    StaticFire<BrownNoiseFlicker< ColorChange<TrFade<300>,    Red,        DarkOrange,  Rgb<180,130,0>,GreenYellow, Green,      Aquamarine,  Cyan,        DeepSkyBlue,Blue,       Rgb<125,30,255>,Magenta,     White>, RandomPerLEDFlicker<    ColorChange<TrFade<300>,Rgb<25,0,0>,OrangeRed,   Rgb<15,15,0>,  Rgb<10,15,0>,Rgb<0,25,0>,Rgb<0,15,10>,Rgb<0,0,25>, Rgb<0,0,25>,Rgb<0,0,25>,Rgb<15,0,10>,   Rgb<10,0,15>,Rgb<15,15,30>>,   ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,  Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>,   Rgb<30,0,30>,Rgb<60,60,100>>>,200>,ColorChange<TrFade<300>,        Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,  Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>,   Rgb<40,0,40>,Rgb<80,80,150>>,0,6,10,1000,2>,AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>>,
    // HumpFlicker
    Layers<
    HumpFlicker<ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,        Rgb<95,0,225>,Magenta,     White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,  Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>,20>,AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>>,
    // Pulsing
    Layers<
    Pulsing<ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,AudioFlickerL<ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,1000>,AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>>,
    // Simple BrownNoiseFlicker
    Layers<
    BrownNoiseFlicker<ColorChange<TrFade<300>,Red,        DarkOrange,  Rgb<180,130,0>,GreenYellow, Green,      Aquamarine,  Cyan,        DeepSkyBlue,Blue,       Rgb<95,0,225>,Magenta,       White>,ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,  Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>, Rgb<30,0,30>,  Rgb<60,60,100>>,200>,AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>>,
    // BrownNoiseFlicker Unstable
    Layers<
    BrownNoiseFlicker<RandomPerLEDFlicker<  ColorChange<TrFade<300>,Red,        DarkOrange,  Rgb<180,130,0>,GreenYellow, Green,      Aquamarine,  Cyan,        DeepSkyBlue,Blue,       Rgb<95,0,225>,Magenta,     White>, ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,  Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>, Rgb<30,0,30>,Rgb<60,60,100>>>,ColorChange<TrFade<300>,    Rgb<80,0,0>,Rgb<60,15,0>,Rgb<40,40,0>,  Rgb<15,60,0>,Rgb<0,80,0>,Rgb<0,60,15>,Rgb<0,15,60>,Rgb<0,0,80>,Rgb<0,0,80>,Rgb<25,8,80>, Rgb<40,0,40>,Rgb<80,80,150>>, 200>,AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>>,
    // Normal Fireblade
    Layers<
    StaticFire<ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>>,
    // Fast Fireblade
    Layers<
    StaticFire<ColorChange<TrFade<300>,Red,        DarkOrange,  Rgb<180,130,0>,GreenYellow, Green,      Aquamarine,  Cyan,        DeepSkyBlue,Blue,       Rgb<95,0,225>,Magenta,     White>,ColorChange<TrFade<300>,Rgb<60,0,0>,Rgb<50,10,0>,Rgb<30,30,0>,  Rgb<10,50,0>,Rgb<0,60,0>,Rgb<0,50,10>,Rgb<0,10,50>,Rgb<0,0,60>,Rgb<0,0,60>,Rgb<15,2,60>, Rgb<30,0,30>,Rgb<60,60,100>>,0,4>,AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>>,

    // Rain Blade
    Layers<
    Sparkle<AudioFlicker< ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>, ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,White>,AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>>,
    // AudioFlicker
    Layers<
    AudioFlicker<ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,ColorChange<TrFade<300>,Rgb<128,0,0>,OrangeRed, Rgb<90,65,0>,  Rgb<0,100,0>,Rgb<0,128,0>,Rgb<0,80,40>,SteelBlue,SteelBlue,  DodgerBlue,Rgb<39,5,71>, Rgb<60,0,60>,Rgb<80,80,150>>>,AlphaL<Mix<Int<8000>,ColorChange<TrFade<300>,Red,         DarkOrange,Rgb<180,130,0>,GreenYellow, Green,       Aquamarine,  Cyan,     DeepSkyBlue,Blue,      Rgb<95,0,225>,Magenta,     White>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>
    >>,
// Dim Blade 50% "Power Save" button combo
    EffectSequence<EFFECT_POWERSAVE,
    AlphaL<Black,Int<16384>>,
    AlphaL<Black,Int<0>>>,
// Clash - Flash at impact. WavLen duration sync. Now Clash impact sensitive.
TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFadeX<Percentage<WavLen<>,35>>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,
  Scale<ClashImpactF<>,Int<1>,Int<32768>>>>,TrFadeX<Percentage<WavLen<>,65>>>,EFFECT_CLASH>,
// Stab - OrangeRed stripes. WavLen duration sync.
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,30>>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFadeX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeX<Percentage<WavLen<EFFECT_STAB>,70>>>>,EFFECT_STAB>,
// Blast - for white blades
    TransitionEffectL<TrConcat<
    // Impact Flash - BC always
    TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
    // Waves
    BlastL<EffectSequence<EFFECT_BLAST,Red,Green,Blue,Black>,850,250,351>,
    // Impact point afterimage
    AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Red,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
    // Impact point
    BlastL<Black,300,350,100000>,
// Lockup - BC custom range mid-blade
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
      //Random Strobe Flash no dimming
      AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
      // Bottom Layer Bump - random width
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
      // Top Layer Bump - fixed width
      AlphaL<BrownNoiseFlicker<Yellow,Black,50>,                                                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
      // Begin Lockup Transition
      TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>, Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
      // End Lockup Transition
      TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                             Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
// Non-Responsive Drag
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// Lightning Block Non-Responsive    
    LockupTrL<Layers<
        //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
        AlphaL<Black,Int<16000>>,
        AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
        AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<
        Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
        // Begin Lightning Transition
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
        // End Lightning Transition    
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// Melt - BC custom melt effects, uses twistangle<>
    LockupTrL<
        // OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
        AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
        // Melt Shape
        SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
        // Melt Begin and End transitions
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
    // Ignition overlayed effect
    TransitionEffectL<TrConcat<TrFade<300>,HumpFlicker<Black,White,50>,TrFade<1000>>,EFFECT_IGNITION>,
    BC_Bend7_Spark_WavOUT_NoSpark_WavIN,
// Postoff Emitter Cooldown
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb<255,50,50>,Bump<Int<0>,Int<3500>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Rgb<100,0,0>,Bump<Int<0>,Int<1000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    ColorCycle<Red,25,100,Red,25,300,4000>,
    InOutTrL<TrInstant,TrInstant,TransitionLoop<Red,TrConcat<TrBoing<1200,2>,Mix<Int<1285>,Black,Red>,TrFade<1200>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"son of corellia"},


{ "a_CORRAN_HORN/CorranHorn;ProffieOS_V2_Voicepack_Huyang/common;commonBU", "tracks/JFO5.wav", 
// CA-74Z - Brian Conner 7-21
  StylePtr<Layers<
    AudioFlicker<Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,Blue>,
// Swing Color
    AlphaL<Pulsing<Blue,LightCyan,1000>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    BC_effects_1,
        TransitionEffectL<TrConcat<TrInstant,White,TrSmoothFade<500>,Strobe<StyleFire<HumpFlicker<DeepPink,Stripes<10000,-3000,Cyan,DarkOrange>,50>,Cyan,0,5,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,100,0>,FireConfig<0,2000,5>>,Red,15,20>,TrSmoothFade<600>>,EFFECT_IGNITION>,
  InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWaveX<White,Int<800>,Int<400>,Int<400>,Int<0>>>,TrFade<200>>,
  TransitionEffectL<TrJoinR<TrConcat<TrInstant,SparkleL<AudioFlicker<Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,Blue>>,TrFade<400>,AlphaL<AudioFlicker<Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,Blue>,Bump<Scale<Trigger<EFFECT_RETRACTION,Int<1>,Int<800>,Int<800>>,Int<-5000>,Int<1000>>,Int<10000>>>,TrDelay<3000>>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrDelay<133>,AlphaL<Black,Int<0>>,TrJoin<TrWipeInX<WavLen<>>,TrWaveX<White,Percentage<WavLen<>,120>,Int<350>,WavLen<>,Int<32768>>>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrDelay<50>,Black,TrWaveX<GreenYellow,Int<200>,Int<100>,Int<200>,Int<32768>>,White,TrDelay<50>,AlphaL<Red,SmoothStep<Int<3000>,Int<-6000>>>,TrFade<450>,AlphaL<OrangeRed,SmoothStep<Int<10000>,Int<-8000>>>,TrFade<450>,AlphaL<HumpFlicker<Rgb<208,128,128>,Red,20>,SmoothStep<Int<16000>,Int<-8000>>>,TrFade<50>,White,TrJoin<TrWipeIn<150>,TrWaveX<Green,Int<150>,Int<75>,Int<150>,Int<32768>>>>,EFFECT_PREON>,
  AlphaL<HumpFlicker<DeepPink,Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,50>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<2500>,Int<1000>,Int<1>>,Int<-32768>,Int<32768>>,Int<-8000>>>,
  TransitionEffectL<TrConcat<TrDelay<2500>,Layers<
    HumpFlicker<Cyan,DeepPink,40>,
    AlphaL<Black,Int<25000>>>,TrSmoothFade<963>,Strobe<StyleFire<HumpFlicker<DeepPink,Stripes<10000,-3000,Cyan,DarkOrange>,50>,Cyan,0,5,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,100,0>,FireConfig<0,2000,5>>,Red,15,20>,TrInstant>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrDelay<2120>,White,TrDelay<80>,AlphaL<Black,Int<0>>,TrDelay<200>,Cyan,TrDelay<80>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrDelay<3275>,AlphaL<Black,Int<0>>,TrWipeIn<188>,Black,TrInstant>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"CorranHorn"},


{ "a_CORRAN_HORN/SpeederBike;ProffieOS_V2_Voicepack_Huyang/common;commonBU", "tracks/JFO5.wav", 
// CA-74Z - Brian Conner 7-21
  StylePtr<Layers<
    AudioFlicker<Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,Blue>,
// Swing Color
    AlphaL<Pulsing<Blue,LightCyan,1000>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    BC_effects_1,
        TransitionEffectL<TrConcat<TrInstant,White,TrSmoothFade<500>,Strobe<StyleFire<HumpFlicker<DeepPink,Stripes<10000,-3000,Cyan,DarkOrange>,50>,Cyan,0,5,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,100,0>,FireConfig<0,2000,5>>,Red,15,20>,TrSmoothFade<600>>,EFFECT_IGNITION>,
  InOutTrL<TrJoin<TrWipeX<Int<400>>,TrWaveX<White,Int<800>,Int<400>,Int<400>,Int<0>>>,TrFade<200>>,
  TransitionEffectL<TrJoinR<TrConcat<TrInstant,SparkleL<AudioFlicker<Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,Blue>>,TrFade<400>,AlphaL<AudioFlicker<Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,Blue>,Bump<Scale<Trigger<EFFECT_RETRACTION,Int<1>,Int<800>,Int<800>>,Int<-5000>,Int<1000>>,Int<10000>>>,TrDelay<3000>>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrDelay<133>,AlphaL<Black,Int<0>>,TrJoin<TrWipeInX<WavLen<>>,TrWaveX<White,Percentage<WavLen<>,120>,Int<350>,WavLen<>,Int<32768>>>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrDelay<50>,Black,TrWaveX<GreenYellow,Int<200>,Int<100>,Int<200>,Int<32768>>,White,TrDelay<50>,AlphaL<Red,SmoothStep<Int<3000>,Int<-6000>>>,TrFade<450>,AlphaL<OrangeRed,SmoothStep<Int<10000>,Int<-8000>>>,TrFade<450>,AlphaL<HumpFlicker<Rgb<208,128,128>,Red,20>,SmoothStep<Int<16000>,Int<-8000>>>,TrFade<50>,White,TrJoin<TrWipeIn<150>,TrWaveX<Green,Int<150>,Int<75>,Int<150>,Int<32768>>>>,EFFECT_PREON>,
  AlphaL<HumpFlicker<DeepPink,Stripes<10000,-3000,Cyan,Rgb<100,100,150>>,50>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<2500>,Int<1000>,Int<1>>,Int<-32768>,Int<32768>>,Int<-8000>>>,
  TransitionEffectL<TrConcat<TrDelay<2500>,Layers<
    HumpFlicker<Cyan,DeepPink,40>,
    AlphaL<Black,Int<25000>>>,TrSmoothFade<963>,Strobe<StyleFire<HumpFlicker<DeepPink,Stripes<10000,-3000,Cyan,DarkOrange>,50>,Cyan,0,5,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,100,0>,FireConfig<0,2000,5>>,Red,15,20>,TrInstant>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrDelay<2120>,White,TrDelay<80>,AlphaL<Black,Int<0>>,TrDelay<200>,Cyan,TrDelay<80>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrDelay<3275>,AlphaL<Black,Int<0>>,TrWipeIn<188>,Black,TrInstant>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"SpeederBike"},


{ "aa_NoSloppy/DiscWars;ProffieOS_V2_Voicepack_Huyang/common;commonBU", "aa_NoSloppy/DiscWars/tracks/discwars.wav", 
// DiscWars ProfieOS blade style - NoSloppy 2023

// Main blade or Tron Disc Outer Ring
  StylePtr<Layers<
    Mix<SwingSpeed<400>,ColorCycle<Pulsing<Rgb<0,100,140>,Rgb<20,200,240>,100>,70,900,Pulsing<Rgb<0,100,140>,Rgb<20,200,240>,100>,70,900,100>,HumpFlicker<Rgb<100,220,250>,Rgb<20,100,140>,10>>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlicker<White,Rgb<100,220,250>,50>,TrFadeX<WavLen<>>>,EFFECT_CLASH>,
// Blast - for white blades
    TransitionEffectL<TrConcat<
    // Impact Flash - BC always
    TrInstant,SteelBlue,TrDelay<25>>,EFFECT_BLAST>,
    // Waves
    BlastL<EffectSequence<EFFECT_BLAST,Red,Green,Blue,Black>,850,250,351>,
    // Impact point afterimage
    AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Red,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
    // Impact point
    BlastL<Black,300,350,100000>,
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
      AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
      AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
      AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,20>,50,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_DRAG_END>,
    LockupTrL<Layers<
      AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
      AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
      AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,20>,50,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_DRAG>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_DRAG_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_DRAG_BEGIN>,
// Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
    LockupTrL<Layers<
        //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
        AlphaL<Black,Int<16000>>,
        AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
        AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
        Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
        // Begin Lightning Transition
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
        // End Lightning Transition    
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  
    LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
    LockupTrL<AlphaL<Remap<Scale<RampF,Int<0>,Int<65536>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,SmoothStep<Scale<TwistAngle<>,Int<9000>,Int<3000>>,Int<-4000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipe<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<9000>,Int<3000>>,Int<-2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<9000>,Int<3000>>,Int<-2000>>>,TrFade<3000>>,TrColorCycle<1500,2000>,SaberBase::LOCKUP_MELT>,
// Non-Responsive Drag
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    TransitionEffectL<TrConcat<TrFade<75>,White,TrDelay<75>,White,TrFade<50>,Stripes<2000,1,Rgb<0,40,80>,Rgb<20,200,240>>,TrDelay<125>,Stripes<2000,-500,Rgb<0,40,80>,Rgb<20,200,240>>,TrFade<100>>,EFFECT_IGNITION>,
    InOutTrL<TrInstant,TrFadeX<WavLen<EFFECT_RETRACTION>>>,
    TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<>,75>>,Stripes<2000,-500,Rgb<0,40,80>,Rgb<20,200,240>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,White,TrInstant>,EFFECT_RETRACTION>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"disc wars"},


{ "aa_JayDalorian/Subspace;ProffieOS_V2_Voicepack_Huyang/common;commonBU", "", 
  StylePtr<Layers<
    AudioFlicker<BrownNoiseFlicker<Mix<SwingSpeed<400>,RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<170,150,225>>>,Stripes<5000,-300,RotateColorsX<Variation,Rgb<35,25,55>>,RotateColorsX<Variation,Rgb<90,75,120>>,RotateColorsX<Variation,Rgb<15,10,20>>,RotateColorsX<Variation,Rgb<60,50,75>>>,300>,RotateColorsX<Variation,Rgb<45,35,75>>>,
    AlphaL<Mix<SwingSpeed<600>,Red,Orange,White>,Scale<SwingSpeed<600>,Int<0>,Int<32768>>>,
    OriginalBlastL<Yellow>,
    BC_effects_1,
    InOutTrL<TrConcat<TrWipe<800>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<170,150,225>>,Black,300>,TrWipe<100>,Black,TrBoing<1600,3>>,TrConcat<TrWipe<200>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<100,100,150>>>,TrWaveX<RotateColorsX<Variation,Yellow>,Int<100>,Int<150>,Int<100>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Yellow>>,TrWaveX<RotateColorsX<Variation,Yellow>,Int<125>,Int<300>,Int<150>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Yellow>>,TrWaveX<RotateColorsX<Variation,Yellow>,Int<150>,Int<300>,Int<150>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Yellow>>,TrWaveX<RotateColorsX<Variation,Yellow>,Int<175>,Int<300>,Int<175>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Yellow>>,TrWaveX<RotateColorsX<Variation,Yellow>,Int<200>,Int<300>,Int<200>,Int<0>>,Black,TrWaveX<RotateColorsX<Variation,DodgerBlue>,Int<200>,Int<300>,Int<200>,Int<0>>,Black,TrInstant>>,
    TransitionEffectL<TrConcat<TrDelay<1180>,TrSparkX<White,Int<350>,Int<216>,Int<32768>>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Blue,Bump<Int<0>,Int<10000>>>,TrFadeX<Percentage<WavLen<>,33>>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFadeX<Percentage<WavLen<>,33>>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,33>>>,EFFECT_POSTOFF>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BlinkingL<Blue,Int<300>,Int<500>>,Bump<Int<0>,Int<4000>>>,TrBoing<500,3>,AlphaL<BlinkingL<DodgerBlue,Int<200>,Int<500>>,Bump<Int<4000>,Int<4000>>>,TrBoing<750,2>,AlphaL<BlinkingL<DeepSkyBlue,Int<100>,Int<500>>,Bump<Int<0>,Int<4000>>>,TrDelay<435>>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"subspace"},

{ "aa_JayDalorian/Vortex;ProffieOS_V2_Voicepack_Huyang/common;commonBU", "",
  StylePtr<Layers<
    StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,20>,RotateColorsX<Variation,Rgb<4,0,8>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<115,15,220>>,70>,RotateColorsX<Variation,Rgb<42,0,105>>>,RotateColorsX<Variation,Rgb<30,0,66>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
    AlphaL<Stripes<2500,-3000,Red,Rgb<60,0,0>,Pulsing<Rgb<30,0,0>,Black,800>>,SwingSpeed<600>>,
    SparkleL<White,100,300>,
    BC_effects_Red,
// InOutTrL</* Out->in */ TrSelect<Divide<Trigger<EFFECT_FAST_ON,Int<0>,Int<3000>,Int<0>>,Int<32768>>,TrWipe<3000>,TrBoing<3000,3>>,TrWipeIn<500>>,
//InOutTrL</* Out->in */ TrSelect<Divide<Trigger<EFFECT_FAST_ON,Int<0>,WavLen<>,Int<0>>,Int<32768>>,TrWipeX<WavLen<>>,TrBoingX<WavLen<>,3>>,TrWipeIn<500>>,
    // InOutTrL<TrSelect<Divide<Trigger<EFFECT_FAST_ON,Int<0>,WavLen<>,Int<0>>,Int<32768>>,TrConcat<TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<400>,Int<32768>>,Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<350>,Int<32768>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<300>,Int<32768>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<250>,Int<32768>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<200>,Int<32768>>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrWipeIn<200>,Mix<SmoothStep<Int<33000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrDelay<100>,AudioFlickerL<White>,TrFade<550>>,

    //TrConcat<TrWipeSparkTip<White,300,350>,AudioFlickerL<White>,TrFade<550>>>,TrConcat<TrInstant,RotateColorsX<Variation,Rgb<95,0,210>>,TrWipe<244>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<200>,Int<258>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<200>,Int<282>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<278>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<350>,Int<285>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<400>,Int<0>>,Black,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<400>,Int<400>,Int<0>>,Black,TrInstant>>,
  InOutTrL<TrSelect<Divide<Trigger<EFFECT_FAST_ON,Int<0>,Int<3000>,Int<0>>,Int<32768>>,TrConcat<TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<400>,Int<32768>>,Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<350>,Int<32768>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<300>,Int<32768>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<250>,Int<32768>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<200>,Int<32768>>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrWipeIn<200>,Mix<SmoothStep<Int<33000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrDelay<100>,AudioFlickerL<White>,TrFade<550>>,TrConcat<TrWipeSparkTip<White,300,350>,AudioFlickerL<White>,TrFade<550>>>,TrConcat<TrInstant,RotateColorsX<Variation,Rgb<95,0,210>>,TrWipe<244>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<200>,Int<258>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<200>,Int<282>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<278>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<350>,Int<285>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Rgb<95,0,210>>>,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<400>,Int<0>>,Black,TrSparkX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<400>,Int<400>,Int<0>>,Black,TrInstant>>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<300>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrFadeX<WavLen<>>,AlphaL<HumpFlickerL<White,40>,Bump<Int<0>,Int<5000>>>,TrFade<300>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFadeX<Percentage<WavLen<>,35>>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFadeX<Percentage<WavLen<>,35>>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,30>>>,EFFECT_POSTOFF>,
  TransitionEffectL<TrConcat<TrBoingX<Percentage<WavLen<EFFECT_PREON>,16>,3>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,15>,Bump<Int<0>,Int<5000>>>,TrFadeX<Percentage<WavLen<EFFECT_PREON>,33>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,10>,Bump<Int<0>,Int<8000>>>,TrFadeX<Percentage<WavLen<EFFECT_PREON>,33>>,AlphaL<HumpFlickerL<White,20>,Bump<Int<0>,Int<12000>>>,TrInstant>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"vortex"},

// BVM collection
{ "aa_BVM/Absorbed;ProffieOS_V2_Voicepack_HAL_9000/common;commonBU", "",
/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.23p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Base Overlay Effect: Style Option
0: Power Bolt[Color: AltColor3Arg, Type: Full Blade, Loop: Timed Loop, Time: 200, Delay: 1000, Mod: 0]
Preon Effect: Sparking Absorb [Color: PreonColorArg]
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V2) [Color: IgnitionColorArg]
Retraction Effect: SparkTip Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Stab Effect: Normal Stab [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Swing Effect: Force Rage Unstable [Color: ]
Emitter Effect: Flickering Flare [Color: EmitterColorArg]
 */
StylePtr<Layers<
  HumpFlicker<RgbArg<BASE_COLOR_ARG,Red>,Mix<Int<8192>,Black,RgbArg<BASE_COLOR_ARG,Red>>,120>,
  TransitionLoopL<TrConcat<TrConcat<TrWipeX<Int<100>>,RgbArg<ALT_COLOR3_ARG,Rgb<118,0,194>>,TrWipeX<Int<100>>>,TrDelayX<Int<1000>>>>,
  AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<118,0,194>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-6000>>>,
  TransitionEffectL<TrConcat<TrJoin<TrDelay<3500>,TrFade<300>>,StripesX<Int<3500>,Scale<SlowNoise<Int<3000>>,Int<-2500>,Int<-3500>>,RgbArg<SWING_COLOR_ARG,Rgb<118,0,194>>,Mix<Int<10280>,Black,RgbArg<SWING_COLOR_ARG,Rgb<118,0,194>>>,RandomPerLEDFlicker<Mix<Int<2570>,Black,RgbArg<SWING_COLOR_ARG,Rgb<118,0,194>>>,RgbArg<SWING_COLOR_ARG,Rgb<118,0,194>>>>,TrFade<300>>,EFFECT_FORCE>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<118,0,194>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<100>>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<118,0,194>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<100>>,EFFECT_STAB>,
  TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<118,0,194>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
  Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<118,0,194>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<118,0,194>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
  LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<118,0,194>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<118,0,194>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<118,0,194>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<118,0,194>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<118,0,194>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<118,0,194>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<118,0,194>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<118,0,194>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<118,0,194>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<118,0,194>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<118,0,194>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<118,0,194>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<118,0,194>>,TrFade<400>>>,
  LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<118,0,194>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<118,0,194>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<118,0,194>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<118,0,194>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<118,0,194>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<118,0,194>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<118,0,194>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<118,0,194>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<118,0,194>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<118,0,194>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<118,0,194>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<118,0,194>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<118,0,194>>,BendTimePowInvX<IgnitionTime<409>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInSparkTipX<RotateColorsX<Int<4096>,RgbArg<RETRACTION_COLOR_ARG,Rgb<118,0,194>>>,BendTimePowX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<118,0,194>>>,SmoothStep<Scale<NoisySoundLevel,IntArg<PREON_SIZE_ARG,2000>,Int<16000>>,Int<-4000>>>,TrLoopN<8,TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<118,0,194>>,Int<200>,Divide<WavLen<EFFECT_PREON>,Int<8>>,Int<32768>>>>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"absorbed"},


{ "aa_BVM/Alias;ProffieOS_V2_Voicepack_HAL_9000/common;commonBU", "",
/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Overload [Color: PreonColorArg]
Ignition Effect: Glitch On [Color: IgnitionColorArg]
Retraction Effect: Glitch Off [Color: RetractionColorArg]
PostOff Effect: Emitter Spark (Preon Size) [Color: PostOffColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
*/
  StylePtr<Layers<
    HumpFlicker<RgbArg<BASE_COLOR_ARG,Green>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Green>>,60>,
    TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,White>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
    Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,White>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
    LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,White>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,White>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,White>,TrFade<400>>>,
    LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,White>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrJoin<TrDelayX<Mult<IgnitionTime<>,Int<16384>>>,TrWipeX<Mult<IgnitionTime<>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<IGNITION_COLOR_ARG,White>>,TrWipeX<Mult<IgnitionTime<>,Int<16384>>>>,TrConcat<TrJoin<TrDelayX<Mult<RetractionTime<>,Int<16384>>>,TrWipeInX<Mult<RetractionTime<>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<BASE_COLOR_ARG,Green>>,TrWipeInX<Mult<RetractionTime<>,Int<16384>>>>>,
    TransitionEffectL<TrConcat<TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Green>,10>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Green>,15>,SmoothStep<Sum<Int<2000>,IntArg<PREON_SIZE_ARG,2000>>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Green>,20>,SmoothStep<Sum<Int<4000>,IntArg<PREON_SIZE_ARG,2000>>,Int<-4000>>>,TrBoingX<Mult<Int<8192>,WavLen<EFFECT_PREON>>,3>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<POSTOFF_COLOR_ARG,Green>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,IntArg<PREON_SIZE_ARG,2000>,Sum<IntArg<PREON_SIZE_ARG,2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"alias"},


{ "aa_BVM/Astral_Projection;ProffieOS_V2_Voicepack_HAL_9000/common;commonBU", "",
/* copyright Fett263 LavaLamp (Primary Blade) OS7 Style
https://fett263library.com/early-access/#LavaLamp
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Center Absorb [Color: PreonColorArg]
Ignition Effect: SparkTip Center Out [Color: IgnitionColorArg]
PowerUp Effect: Power Flash [Color: IgnitionColorArg]
Retraction Effect: SparkTip Center In [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
*/
  StylePtr<Layers<
    StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<25>,Int<80>>,Pulsing<Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Yellow>,White>,Mix<Int<2570>,Black,RgbArg<BASE_COLOR_ARG,Yellow>>,3000>,Mix<Sin<Int<2>>,Mix<Int<25700>,Black,RgbArg<BASE_COLOR_ARG,Yellow>>,Mix<Int<1285>,Black,RgbArg<BASE_COLOR_ARG,Yellow>>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Yellow>>,Pulsing<Mix<Int<6425>,Black,RgbArg<BASE_COLOR_ARG,Yellow>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,RgbArg<BASE_COLOR_ARG,Yellow>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Yellow>,White>>,Mix<Int<12336>,Black,RgbArg<BASE_COLOR_ARG,Yellow>>>,2000>,Pulsing<Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Yellow>>,Mix<Int<6425>,Black,RgbArg<BASE_COLOR_ARG,Yellow>>,3000>>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<275>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Yellow>,TrFade<1000>>,EFFECT_IGNITION>,
    TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,White>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
    Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,White>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
    LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,White>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,White>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,White>,TrFade<400>>>,
    LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,White>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrCenterWipeSparkX<RgbArg<IGNITION_COLOR_ARG,Yellow>,IgnitionTime<275>>,TrCenterWipeInSparkX<RotateColorsX<Int<4096>,RgbArg<RETRACTION_COLOR_ARG,White>>,RetractionTime<>>>,
    TransitionEffectL<TrConcat<TrExtendX<WavLen<EFFECT_PREON>,TrInstant>,Remap<CenterDistF<>,Layers<
      TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Yellow>,Int<200>,Int<100>,Int<32768>>>,
      AlphaL<RgbArg<PREON_COLOR_ARG,Yellow>,SmoothStep<Int<0>,Scale<Trigger<EFFECT_PREON,WavLen<EFFECT_PREON>,Int<500>,Int<200>,Int<100>>,Int<-1>,Int<-20000>>>>>>,TrInstant>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"astral_projection"},


{ "aa_BVM/Celsius;ProffieOS_V2_Voicepack_HAL_9000/common;commonBU", "",
/* copyright Fett263 FireBlade (Primary Blade) OS7 Style
https://fett263library.com/
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Faulty Fire Ignition [Color: PreonColorArg]
Ignition Effect: Glitch On [Color: IgnitionColorArg]
Retraction Effect: Glitch Off [Color: RetractionColorArg]
PostOff Effect: Emitter Spark (Emitter Size) [Color: PostOffColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
*/
  StylePtr<Layers<
    StaticFire<Stripes<12000,-2000,RgbArg<BASE_COLOR_ARG,Red>,RotateColorsX<Int<200>,RgbArg<BASE_COLOR_ARG,Red>>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Red>>,0,3,2,2000,8>,
    TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Yellow>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
    Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Yellow>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Yellow>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
    LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Yellow>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Yellow>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Yellow>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Yellow>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Yellow>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Yellow>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Yellow>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Yellow>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Yellow>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Yellow>,AudioFlicker<RgbArg<LB_COLOR_ARG,Yellow>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Yellow>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Yellow>,TrFade<400>>>,
    LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Yellow>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Yellow>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Yellow>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Yellow>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Yellow>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Yellow>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Yellow>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Yellow>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Yellow>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Yellow>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Yellow>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Yellow>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrJoin<TrDelayX<Mult<IgnitionTime<>,Int<16384>>>,TrWipeX<Mult<IgnitionTime<>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<IGNITION_COLOR_ARG,Yellow>>,TrWipeX<Mult<IgnitionTime<>,Int<16384>>>>,TrConcat<TrJoin<TrDelayX<Mult<RetractionTime<>,Int<16384>>>,TrWipeInX<Mult<RetractionTime<>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<BASE_COLOR_ARG,Red>>,TrWipeInX<Mult<RetractionTime<>,Int<16384>>>>>,
    TransitionEffectL<TrConcat<TrExtendX<WavLen<EFFECT_PREON>,TrWipe<100>>,AlphaL<StripesX<Int<3000>,Sin<Int<60>,Int<-1600>,Int<-4000>>,RgbArg<PREON_COLOR_ARG,Red>,Mix<Int<10772>,Black,RgbArg<PREON_COLOR_ARG,Red>>,Mix<Int<24000>,Black,RgbArg<PREON_COLOR_ARG,Red>>>,SmoothStep<NoisySoundLevel,Int<-3000>>>,TrFade<100>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<POSTOFF_COLOR_ARG,Red>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"celsius"},


{ "aa_BVM/High_Voltage;ProffieOS_V2_Voicepack_JARVIS/common;commonBU", "",
/* copyright Fett263 EnergyBlade (Primary Blade) OS7 Style
https://fett263library.com/early-access/#EnergyBlade
OS7.14 v4.0
Single Style
Base Style: Death Star Blast

Base Color: BaseColorArg (0) Style Mod: Mirror Out


--Effects Included--

Effect Reaction: Fast Wave, BaseColorArg, Type: Full Blade, Direction: Normal, Duration: 3000, Consecutive Effects to Max: 3
Effect Reactions: Clash, BlastPreon Effect: Center Absorb [Color: PreonColorArg]
Ignition Effect: Center Out [Color: IgnitionColorArg]
PowerUp Effect: Power Burst Center Out [Color: IgnitionColorArg]
Retraction Effect: Center In [Color: RetractionColorArg]
CoolDown Effect: Power Burst Center Out [Color: RetractionColorArg]
PostOff Effect: Exit Hyperspace [Color: Rgb<0,255,0>]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Vortex - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Stab Effect: Normal Stab [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Random Clash with Wave [Color: ClashColorArg]
*/

  StylePtr<Layers<
    Remap<CenterDistF<>,Stripes<3500,-3000,RgbArg<BASE_COLOR_ARG,Green>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Green>>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Green>,White>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Green>>>>,
    TransitionEffectL<TrConcat<TrFade<400>,StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<Green,Black,20>,Green,BrownNoiseFlicker<Black,Green,70>,GreenYellow>,Green,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrDelay<1500>,StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<Green,Black,20>,GreenYellow,BrownNoiseFlicker<Black,Green,70>,Green>,Green,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrFade<800>>,EFFECT_FORCE>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<>>,TrInstant>,Remap<CenterDistF<>,Stripes<5000,-2500,RgbArg<IGNITION_COLOR_ARG,Green>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Green>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Green>>>>,TrFade<800>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<>>,TrInstant>,Remap<CenterDistF<>,Stripes<5000,-2500,RgbArg<RETRACTION_COLOR_ARG,Green>,Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Green>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Green>>>>,TrFade<800>>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RgbArg<STAB_COLOR_ARG,Red>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
    TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Yellow>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
    TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Yellow>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<ClashImpactF<>,Int<28000>,Int<8000>>>,EFFECT_CLASH>,
    LockupTrL<AlphaL<Remap<CenterDistF<IntArg<LOCKUP_POSITION_ARG,16000>>,Stripes<2000,3200,RgbArg<LOCKUP_COLOR_ARG,Yellow>,Mix<Int<18000>,Black,RgbArg<LOCKUP_COLOR_ARG,Yellow>>,Mix<Int<8000>,Black,RgbArg<LOCKUP_COLOR_ARG,Yellow>>>>,Bump<IntArg<LOCKUP_POSITION_ARG,16000>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Yellow>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Yellow>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Yellow>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    LockupTrL<AlphaL<Strobe<RgbArg<LB_COLOR_ARG,Yellow>,AudioFlicker<RgbArg<LB_COLOR_ARG,Yellow>,Blue>,50,1>,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Yellow>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Yellow>,TrFade<400>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
    LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,White>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<IntArg<DRAG_SIZE_ARG,30385>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Red>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Red>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Red>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Red>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Red>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Red>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Red>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Red>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Red>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Red>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrCenterWipeX<BendTimePowInvX<IgnitionTime<>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrCenterWipeInX<BendTimePowX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,
    TransitionEffectL<TrConcat<TrExtendX<WavLen<EFFECT_PREON>,TrInstant>,Remap<CenterDistF<>,Layers<
      TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Green>,Int<200>,Int<100>,Int<32768>>>,
      AlphaL<RgbArg<PREON_COLOR_ARG,Green>,SmoothStep<Int<0>,Scale<Trigger<EFFECT_PREON,WavLen<EFFECT_PREON>,Int<500>,Int<200>,Int<100>>,Int<-1>,Int<-20000>>>>>>,TrInstant>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8192>>>,TrCenterWipeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8192>>>>,Remap<CenterDistF<>,Stripes<2000,-1500,Black,Green>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8192>>>,Remap<CenterDistF<>,Stripes<1000,-500,Black,Green,Black>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8192>>>>,EFFECT_POSTOFF>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"high voltage"},


{ "aa_BVM/Poison;ProffieOS_V2_Voicepack_JARVIS/common;commonBU", "",
/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://fett263library.com
OS7.14 v3.0p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Overload [Color: PreonColorArg]
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Flash [Color: IgnitionColorArg]
Retraction Effect: Disassemble [Color: RetractionColorArg]
PostOff Effect: Emitter Glow (Emitter Size) [Color: PostOffColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Localized Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Localized Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Random Clash [Color: ClashColorArg]
Rain Effect: Rain Spark [Color: EmitterColorArg]
*/
  StylePtr<Layers<
    HumpFlicker<Rgb<118,0,194>,Mix<Int<24576>,Black,Rgb<118,0,194>>,60>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<>>,TrInstant>,Rgb<80,50,210>,TrFade<1000>>,EFFECT_IGNITION>,
    SparkleL<Magenta>,
    TransitionEffectL<TrWaveX<Yellow,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
    TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<EffectPosition<EFFECT_CLASH>,Scale<ClashImpactF<>,Int<9000>,Int<12000>>>,Yellow,Rgb<128,128,0>>,TrFade<300>>,EFFECT_CLASH>,
    LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<Int<16000>,Int<-12000>>,Sum<Int<16000>,Int<10000>>>,Sum<Int<16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<Yellow,Mix<Int<12000>,Black,Yellow>>,BrownNoiseFlicker<Yellow,Mix<Int<12000>,Black,Yellow>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<Int<16000>,Int<-12000>>,Sum<Int<16000>,Int<10000>>>,Sum<Int<16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<Yellow,Mix<Int<20000>,Black,Yellow>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<Int<16000>,Int<-12000>>,Sum<Int<16000>,Int<10000>>>,Sum<Int<16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,Yellow,AlphaL<Yellow,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<Int<16000>,Int<-12000>>,Sum<Int<16000>,Int<10000>>>,Sum<Int<16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<Yellow,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<Int<16000>,Int<-12000>>,Sum<Int<16000>,Int<10000>>>,Sum<Int<16000>,Int<-10000>>>,Int<13000>>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Yellow,AudioFlicker<Yellow,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<Yellow,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,AlphaL<Yellow,Bump<Int<18000>,Int<13000>>>,TrFade<400>>>,
    LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<Yellow>,BrownNoiseFlickerL<Yellow,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,Int<28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,DarkOrange,RotateColorsX<Int<3000>,DarkOrange>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,DarkOrange,RotateColorsX<Int<3000>,DarkOrange>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,DarkOrange,RotateColorsX<Int<3000>,DarkOrange>>>>,SmoothStep<Scale<TwistAngle<>,Int<28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,DarkOrange,RotateColorsX<Int<3000>,DarkOrange>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,DarkOrange,RotateColorsX<Int<3000>,DarkOrange>>>,100>,SmoothStep<Scale<TwistAngle<>,Int<28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTipX<Rgb<80,50,210>,BendTimePowInvX<IgnitionTime<>,Mult<Int<10992>,Int<98304>>>>,TrConcat<TrSparkX<Rgb<118,0,194>,Int<100>,Mult<RetractionTime<>,Int<6554>>,Int<0>>,AlphaL<Black,SmoothStep<Int<26216>,Int<0>>>,TrSparkX<Rgb<118,0,194>,Int<100>,Mult<RetractionTime<>,Int<6554>>,Int<0>>,AlphaL<Black,SmoothStep<Int<19662>,Int<0>>>,TrSparkX<Rgb<118,0,194>,Int<100>,Mult<RetractionTime<>,Int<6554>>,Int<0>>,AlphaL<Black,SmoothStep<Int<13108>,Int<0>>>,TrSparkX<Rgb<118,0,194>,Int<100>,Mult<RetractionTime<>,Int<6554>>,Int<0>>,AlphaL<Black,SmoothStep<Int<6554>,Int<0>>>,TrSparkX<Rgb<118,0,194>,Int<100>,Mult<RetractionTime<>,Int<6554>>,Int<0>>>>,
    TransitionEffectL<TrConcat<TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<Rgb<80,50,210>,10>,SmoothStep<Int<2000>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<Rgb<80,50,210>,15>,SmoothStep<Sum<Int<2000>,Int<2000>>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<Rgb<80,50,210>,20>,SmoothStep<Sum<Int<4000>,Int<2000>>,Int<-4000>>>,TrBoingX<Mult<Int<8192>,WavLen<EFFECT_PREON>>,3>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb<118,0,194>,SmoothStep<Int<2000>,Int<-2000>>>,TrSmoothFadeX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"poison"},


{ "aa_BVM/Son_of_a_Glitch;ProffieOS_V2_Voicepack_HAL_9000/common;commonBU", "",
/* copyright Fett263 EnergyWeapon (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#EnergyWeapon
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Sparking Absorb [Color: PreonColorArg]
Ignition Effect: Glitch On [Color: IgnitionColorArg]
Retraction Effect: Glitch Off [Color: RetractionColorArg]
PostOff Effect: Emitter Spark (Emitter Size) [Color: PostOffColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Stab Effect: Normal Stab [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Emitter Effect: Random Pulse [Color: EmitterColorArg]
*/
  StylePtr<Layers<
    StaticFire<Strobe<RgbArg<BASE_COLOR_ARG,White>,Strobe<Rgb<100,100,150>,RandomPerLEDFlicker<RgbArg<BASE_COLOR_ARG,White>,Black>,50,1>,100,1>,Mix<Int<6425>,Black,RgbArg<BASE_COLOR_ARG,White>>,0,5,2,1000>,
    TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<1000>>,Int<300>,Int<3000>>>,AlphaL<RgbArg<EMITTER_COLOR_ARG,Cyan>,Int<0>>,TrSparkX<RgbArg<EMITTER_COLOR_ARG,Cyan>,Scale<NoisySoundLevel,Int<200>,Int<600>>,Int<250>,Int<0>>>>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RgbArg<STAB_COLOR_ARG,Cyan>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
    TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Cyan>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
    Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Cyan>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Cyan>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
    LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Cyan>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Cyan>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Cyan>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Cyan>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Cyan>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Cyan>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Cyan>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Cyan>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Cyan>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Cyan>,AudioFlicker<RgbArg<LB_COLOR_ARG,Cyan>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Cyan>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Cyan>,TrFade<400>>>,
    LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Cyan>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Cyan>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Cyan>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Cyan>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Cyan>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Cyan>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Cyan>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Cyan>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Cyan>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Cyan>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Cyan>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Cyan>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrConcat<TrJoin<TrDelayX<Mult<IgnitionTime<2000>,Int<16384>>>,TrWipeX<Mult<IgnitionTime<2000>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<IGNITION_COLOR_ARG,White>>,TrWipeX<Mult<IgnitionTime<2000>,Int<16384>>>>,TrConcat<TrJoin<TrDelayX<Mult<RetractionTime<>,Int<16384>>>,TrWipeInX<Mult<RetractionTime<>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<BASE_COLOR_ARG,White>>,TrWipeInX<Mult<RetractionTime<>,Int<16384>>>>>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlickerL<RgbArg<PREON_COLOR_ARG,White>>,SmoothStep<Scale<NoisySoundLevel,IntArg<PREON_SIZE_ARG,2000>,Int<16000>>,Int<-4000>>>,TrLoopN<8,TrSparkX<RgbArg<PREON_COLOR_ARG,White>,Int<200>,Divide<WavLen<EFFECT_PREON>,Int<8>>,Int<32768>>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<POSTOFF_COLOR_ARG,White>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"son_of_a_glitch"},


{ "aa_BVM/Terra;ProffieOS_V2_Voicepack_HAL_9000/common;commonBU", "",
/* copyright Fett263 EnergyBlade (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#EnergyBlade
OS7.14 v2.52p
Single Style
Base Style: Surging Pulse

Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Faulty Ignition [Color: PreonColorArg]
Ignition Effect: Glitch On [Color: IgnitionColorArg]
Retraction Effect: Glitch Off [Color: RetractionColorArg]
PostOff Effect: Emitter Spark (Emitter Size) [Color: PostOffColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
*/
StylePtr<Layers<
  Stripes<6000,-3000,Rgb<0,0,128>,Blue,Rgb<0,0,60>>,
  TransitionEffectL<TrWaveX<Red,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
  Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<Red,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<Red,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<26000>,Int<6000>>,Int<6000>>>,EFFECT_CLASH>>,
  LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<Red,Rgb<93,0,0>>,BrownNoiseFlicker<Red,Rgb<93,0,0>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<Red,Rgb<155,0,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,Red,AlphaL<Red,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,Red,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<Red,AudioFlicker<Red,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<Red,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,Red,TrFade<400>>>,
  LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<Red>,BrownNoiseFlickerL<Red,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,Int<28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,DarkOrange,RotateColorsX<Int<3000>,DarkOrange>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,DarkOrange,RotateColorsX<Int<3000>,DarkOrange>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,DarkOrange,RotateColorsX<Int<3000>,DarkOrange>>>>,SmoothStep<Scale<TwistAngle<>,Int<28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,DarkOrange,RotateColorsX<Int<3000>,DarkOrange>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,DarkOrange,RotateColorsX<Int<3000>,DarkOrange>>>,100>,SmoothStep<Scale<TwistAngle<>,Int<28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrConcat<TrJoin<TrDelayX<Mult<IgnitionTime<>,Int<16384>>>,TrWipeX<Mult<IgnitionTime<>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,Blue>,TrWipeX<Mult<IgnitionTime<>,Int<16384>>>>,TrConcat<TrJoin<TrDelayX<Mult<RetractionTime<>,Int<16384>>>,TrWipeInX<Mult<RetractionTime<>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,Blue>,TrWipeInX<Mult<RetractionTime<>,Int<16384>>>>>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Percentage<WavLen<EFFECT_PREON>,50>,Percentage<WavLen<EFFECT_PREON>,33>,Percentage<WavLen<EFFECT_PREON>,17>>,BrownNoiseFlicker<Black,Blue,100>,RandomPerLEDFlicker<Blue,Rgb<50,50,50>>,BrownNoiseFlicker<Mix<NoisySoundLevel,Blue,RotateColorsX<Int<4000>,Blue>>,White,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<Blue,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Int<5000>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"terra"},


{ "aa_BVM/The_Baron;ProffieOS_V2_Voicepack_HAL_9000/common;commonBU", "",
/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Overload [Color: PreonColorArg]
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: SparkTip Retraction [Color: RetractionColorArg]
PostOff Effect: Emitter Spark (Emitter Size) [Color: PostOffColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Stab Effect: Normal Stab [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
Emitter Effect: Unstable Flare with Random Pulse [Color: EmitterColorArg]
*/
StylePtr<Layers<
  HumpFlicker<RgbArg<BASE_COLOR_ARG,Yellow>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Yellow>>,120>,
  TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<1000>>,Int<300>,Int<3000>>>,AlphaL<RgbArg<EMITTER_COLOR_ARG,Green>,Int<0>>,TrSparkX<RgbArg<EMITTER_COLOR_ARG,Green>,Scale<NoisySoundLevel,Int<200>,Int<600>>,Int<250>,Int<0>>>>,
  AlphaL<RandomPerLEDFlickerL<RgbArg<EMITTER_COLOR_ARG,Green>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<6000>>>,Int<-6000>>>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RgbArg<STAB_COLOR_ARG,Green>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
  TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Green>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
  Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Green>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Green>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
  LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Green>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Green>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Green>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Green>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Green>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Green>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Green>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Green>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Green>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Green>,AudioFlicker<RgbArg<LB_COLOR_ARG,Green>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Green>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Green>,TrFade<400>>>,
  LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Green>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Green>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Green>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Green>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Green>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Green>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Green>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Green>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Green>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Green>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Green>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Green>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Green>,BendTimePowInvX<IgnitionTime<>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInSparkTipX<RotateColorsX<Int<4096>,RgbArg<RETRACTION_COLOR_ARG,Yellow>>,BendTimePowX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,
  TransitionEffectL<TrConcat<TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Green>,10>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Green>,15>,SmoothStep<Sum<Int<2000>,IntArg<PREON_SIZE_ARG,2000>>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Green>,20>,SmoothStep<Sum<Int<4000>,IntArg<PREON_SIZE_ARG,2000>>,Int<-4000>>>,TrBoingX<Mult<Int<8192>,WavLen<EFFECT_PREON>>,3>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<POSTOFF_COLOR_ARG,Green>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"the_baron"},


{ "aa_BVM/The_Cursed_Saber;ProffieOS_V2_Voicepack_HAL_9000/common;commonBU", "",
/* copyright Fett263 PowerWave (Primary Blade) OS7 Style
https://fett263library.com
OS7.14 v3.0p
Single Style
Base Style: Power Ripple High

Base Color: BaseColorArg (0) Style Mod: Invert


--Effects Included--
Base Overlay Effect: Style Option
0: None[Color: AltColor3Arg, Type: Full Blade, Loop: Timed Loop, Time: 200, Delay: 1000, Mod: 0]
Ignition Effect: Lightning Strike [Color: IgnitionColorArg]
PowerUp Effect: Power Burst Reverse [Color: IgnitionColorArg]
Retraction Effect: Fade Out [Color: RetractionColorArg]
CoolDown Effect: Power Burst Reverse [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Stab Effect: Normal Stab [Color: StabColorArg]
Blast Effect: Blast Wave (Random) [Color: BlastColorArg]
Clash Effect: Real Clash V1 [Color: ClashColorArg]
*/
StylePtr<Layers<
  Remap<InvertF<RampF>,Stripes<3000,-2400,RgbArg<BASE_COLOR_ARG,Red>,Mix<Int<4000>,Black,RgbArg<BASE_COLOR_ARG,Red>>,RgbArg<BASE_COLOR_ARG,Red>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Red>>>>,
  TransitionEffectL<TrConcat<TrFade<400>,StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<Cyan,Black,20>,Rgb<0,0,10>,BrownNoiseFlicker<Black,Cyan,70>,Cyan>,DeepSkyBlue,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrDelay<1500>,StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<Blue,Black,20>,Cyan,BrownNoiseFlicker<Black,Red,70>,Cyan>,Cyan,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrFade<800>>,EFFECT_FORCE>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<75>>,TrInstant>,Stripes<5000,2500,RgbArg<IGNITION_COLOR_ARG,White>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,White>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,White>>>,TrFade<800>>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<>>,TrInstant>,Stripes<5000,2500,RgbArg<RETRACTION_COLOR_ARG,Red>,Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Red>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Red>>>,TrFade<800>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<30>>,AlphaL<RgbArg<STAB_COLOR_ARG,Cyan>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<30>>,EFFECT_STAB>,
  TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Cyan>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
  Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Cyan>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Cyan>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
  LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Cyan>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Cyan>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Cyan>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Cyan>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Cyan>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Cyan>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Cyan>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Cyan>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Cyan>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Cyan>,AudioFlicker<RgbArg<LB_COLOR_ARG,Cyan>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Cyan>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Cyan>,TrFade<400>>>,
  LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Cyan>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Cyan>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Cyan>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Cyan>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Cyan>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Cyan>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Cyan>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Cyan>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Cyan>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Cyan>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Cyan>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Cyan>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrConcat<TrWipeInX<Mult<IgnitionTime<75>,Int<6553>>>,RandomBlink<10,RgbArg<IGNITION_COLOR_ARG,Red>,Red>,TrJoin<TrDelayX<Mult<IgnitionTime<75>,Int<19660>>>,TrWipeInX<Mult<IgnitionTime<230>,Int<6553>>>>,Mix<SmoothStep<Scale<SlowNoise<Int<10>>,IntArg<EMITTER_SIZE_ARG,1000>,Sum<Int<5000>,IntArg<EMITTER_SIZE_ARG,1000>>>,Int<-3000>>,Black,RgbArg<IGNITION_COLOR_ARG,Red>>,TrWipeX<Mult<IgnitionTime<75>,Int<19660>>>>,TrFadeX<BendTimePowX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"the_cursed_saber"},


{ "aa_BVM/Zero;ProffieOS_V2_Voicepack_HAL_9000/common;commonBU", "",
StylePtr<Layers<
  Mix<HoldPeakF<IncrementWithReset<Sum<EffectPulseF<EFFECT_BLAST>,EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_LOCKUP_BEGIN>>,ThresholdPulseF<IncrementWithReset<ThresholdPulseF<BlinkingF<Int<1000>,Int<500>>,Int<32000>>,Sum<EffectPulseF<EFFECT_BLAST>,EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_LOCKUP_BEGIN>>,Int<32768>,Int<8000>>,Int<32000>>,Int<32768>,Scale<ClashImpactF<>,Int<2000>,Int<8000>>>,Int<2000>,Int<10000>>,StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RgbArg<BASE_COLOR_ARG,DarkOrange>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,DarkOrange>>,RgbArg<BASE_COLOR_ARG,DarkOrange>,Mix<Int<2570>,Black,RgbArg<BASE_COLOR_ARG,DarkOrange>>,RgbArg<BASE_COLOR_ARG,DarkOrange>>,StaticFire<Stripes<12000,-1000,RgbArg<ALT_COLOR_ARG,OrangeRed>,RotateColorsX<Int<200>,RgbArg<ALT_COLOR_ARG,OrangeRed>>>,Mix<Int<16384>,Black,RgbArg<ALT_COLOR_ARG,OrangeRed>>,0,2,2,2000,4>>,
  TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<1000>>,Int<300>,Int<3000>>>,AlphaL<Orange,Int<0>>,TrSparkX<Orange,Scale<NoisySoundLevel,Int<200>,Int<600>>,Int<250>,Int<0>>>>,
  AlphaL<RandomPerLEDFlickerL<Red>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<6000>>>,Int<-6000>>>,
  TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrConcat<TrJoin<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<200>,Int<700>>>,TrWipe<200>>,RandomPerLEDFlickerL<RgbArg<LB_COLOR_ARG,Rgb<85,85,200>>>,TrWipe<200>>>,TrFade<300>>,EFFECT_FORCE>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<>>,TrInstant>,Stripes<3000,-3500,RgbArg<ALT_COLOR_ARG,OrangeRed>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<ALT_COLOR_ARG,OrangeRed>>,Black>,BrownNoiseFlicker<RgbArg<ALT_COLOR_ARG,OrangeRed>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,OrangeRed>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<ALT_COLOR_ARG,OrangeRed>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,OrangeRed>>>>,TrFade<800>>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<>>,TrInstant>,Stripes<3000,3500,RgbArg<ALT_COLOR_ARG,DarkOrange>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<ALT_COLOR_ARG,DarkOrange>>,Black>,BrownNoiseFlicker<RgbArg<ALT_COLOR_ARG,DarkOrange>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,DarkOrange>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<ALT_COLOR_ARG,DarkOrange>>,Mix<Int<3855>,Black,RgbArg<ALT_COLOR_ARG,DarkOrange>>>>,TrFade<800>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Red>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
  TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,White>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
  Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,White>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
  LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
  ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<85,85,200>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<85,85,200>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<85,85,200>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<85,85,200>>,TrFade<400>>>,
  LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<100,100,150>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<100,100,150>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Red>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Red>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Red>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Red>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Red>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Red>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,DarkOrange>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,DarkOrange>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrConcat<TrWipeInX<Mult<IgnitionTime<>,Int<6553>>>,RandomBlink<30000,RgbArg<IGNITION_COLOR_ARG,DarkOrange>>,TrJoin<TrDelayX<Mult<IgnitionTime<4500>,Int<19660>>>,TrWipeInX<Mult<IgnitionTime<230>,Int<6553>>>>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,IntArg<EMITTER_SIZE_ARG,1000>,Sum<Int<5000>,IntArg<EMITTER_SIZE_ARG,1000>>>,Int<-3000>>,Black,RgbArg<IGNITION_COLOR_ARG,DarkOrange>>,TrWipeX<Mult<IgnitionTime<>,Int<19660>>>>,TrColorCycleX<BendTimePowX<RetractionTime<>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Mult<Int<16384>,WavLen<EFFECT_PREON>>,Mult<Int<10922>,WavLen<EFFECT_PREON>>,Mult<Int<5462>,WavLen<EFFECT_PREON>>>,BrownNoiseFlicker<Black,RgbArg<ALT_COLOR_ARG,DarkOrange>,100>,RandomPerLEDFlicker<RgbArg<ALT_COLOR_ARG,DarkOrange>,Rgb<50,50,50>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RgbArg<ALT_COLOR_ARG,DarkOrange>,RotateColorsX<Int<4000>,RgbArg<ALT_COLOR_ARG,DarkOrange>>>,DarkOrange,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"zero"},


{ "Whispers_Of_Power;ProffieOS_V2_Voicepack_JARVIS/common;commonBU", "",
  StylePtr<Layers<
    Stripes<6000,-3000,RotateColorsX<Variation,Rgb<0,0,128>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,60>>>,
    BC_effects_1,
    BC_Bend7_Spark_WavOUT_NoSpark_WavIN,
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"whispers\nof power"},


{ "aa_MountainSabers/QuantumKnight;ProffieOS_V2_Voicepack_Optimus_Prime/common;commonBU", "aa_MountainSabers/QuantumKnight/tracks/Transformers.wav",
  StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,
   TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
      //Random Strobe Flash no dimming
      AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,OrangeRed,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
      // Bottom Layer Bump - random width
      AlphaL<Blinking<Tomato,Strobe<Red,Black,15,30>,60,500>,                                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
      // Top Layer Bump - fixed width
      AlphaL<BrownNoiseFlicker<White,Black,50>,                                                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
      // Begin Lockup Transition
      TrConcat<TrInstant,AlphaL<Blinking<Orange,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>, Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
      // End Lockup Transition
      TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<Red,AudioFlicker<Red,White>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<Red,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveBlastWaveL<Red,Int<300>,Int<100>,Int<300>,Scale<BladeAngle<0,16000>,Int<10000>,Int<30000>>,Int<10000>,EFFECT_CLASH>,
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<800>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<150,150,255>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
// Melt - BC custom melt effects, uses twistangle<>
    LockupTrL<
        // OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
        AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
        // Melt Shape
        SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
        // Melt Begin and End transitions
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
  InOutTrL<TrWipe<200>,TrDelayX<WavLen<>>>,
  TransitionEffectL<TrConcat<TrWipeX<Percentage<WavLen<>,5>>,Mix<SmoothStep<Int<27500>,Int<-2000>>,Black,RotateColorsX<Variation,Blue>>,TrWaveX<RotateColorsX<Variation,Blue>,Percentage<WavLen<>,10>,Int<300>,Percentage<WavLen<>,10>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<-2000>>,Black,RotateColorsX<Variation,Blue>>,TrWaveX<RotateColorsX<Variation,Blue>,Percentage<WavLen<>,12>,Int<300>,Percentage<WavLen<>,12>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<-2000>>,Black,RotateColorsX<Variation,Blue>>,TrWaveX<RotateColorsX<Variation,Blue>,Percentage<WavLen<>,15>,Int<300>,Percentage<WavLen<>,15>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<-2000>>,Black,RotateColorsX<Variation,Blue>>,TrWaveX<RotateColorsX<Variation,Blue>,Percentage<WavLen<>,17>,Int<300>,Percentage<WavLen<>,17>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<-2000>>,Black,RotateColorsX<Variation,Blue>>,TrWaveX<RotateColorsX<Variation,Blue>,Percentage<WavLen<>,20>,Int<300>,Percentage<WavLen<>,20>,Int<0>>,Black,TrWaveX<RotateColorsX<Variation,Blue>,Percentage<WavLen<>,20>,Int<300>,Percentage<WavLen<>,20>,Int<0>>,Black,TrInstant>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,TrDelayX<WavLen<>>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,90>>,TrJoin<TrWipeInX<Percentage<WavLen<>,10>>,TrSparkX<White,Int<400>,Percentage<WavLen<>,10>,Int<32768>>>,Black,TrInstant>,EFFECT_RETRACTION>,
    ColorSelect<WavNum<EFFECT_PREON>,TrInstant,
      /* Preon 1 */
      TransitionEffectL<TrConcat<TrInstant,Black,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
      /* Preon2 */
      Layers<
        TransitionEffectL<TrConcat<TrDelay<700>,TransitionLoopL<TrConcat<TrInstant,Red,TrDelay<55>,Black,TrDelay<55>,Blue,TrDelay<55>,Black,TrDelay<55>>>,TrDelay<1430>>,EFFECT_PREON>,
        TransitionEffectL<TrConcat<TrInstant,AlphaL<HumpFlickerL<Red,10>,Bump<Int<0>,Int<15000>>>,TrFade<400>,Black,TrFade<150>,AlphaL<HumpFlickerL<White,100>,Bump<Int<0>,Int<45000>>>,TrFade<150>,Black,TrWipe<1430>>,EFFECT_PREON>>,
      /* Preon 3 */
      Layers<
        TransitionEffectL</* Preon3 */ TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<20000>>>,TrFade<150>,TrConcat<TrInstant,AlphaL<TransitionLoopL<TrConcat<TrInstant,Red,TrDelay<55>,Black,TrDelay<55>,Blue,TrDelay<55>,Black,TrDelay<55>>>,SmoothStep<Scale<Trigger<EFFECT_PREON,WavLen<>,Int<1>,Int<1>,Int<200>>,Int<-1>,Int<16384>>,Int<-1>>>,TrDelayX<WavLen<>>>>,EFFECT_PREON>,
        TransitionEffectL<TrConcat<TrFade<500>,AlphaL<AlphaL<HumpFlicker<White,Black,100>,Int<16000>>,SmoothStep<Scale<Trigger<EFFECT_PREON,Int<250>,Int<1>,Int<1>,Int<200>>,Int<-1>,Int<16384>>,Int<-1>>>,TrDelay<250>>,EFFECT_PREON>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"optimus\nprime"},


{ "aa_KSith/ScrapTecHP-BC;ProffieOS_V2_Voicepack_Savage/common;commonBU", "aa_KSith/ScrapTecHP-BC/tracks/ScrapTec_track.wav",
  // KSith_Scraptec - Solo Sabers - Final v2: Commented explanations - BC version with random glitch
  StylePtr<Layers<Black,
    // Sputtering Emitter
    Mix<Trigger<EFFECT_USER8,Int<1>,Int<1500>,Int<1000>>,
      StyleFire<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,0,8,FireConfig<350,500,0>,FireConfig<350,500,0>,FireConfig<350,500,0>,FireConfig<350,500,0>>,
      AlphaL<Black,Int<0>>>,
    // Base color is BrownNoise Red. When USER8 happens, it "dies down" to the glitchy 1/4 blade dimmer version, then grows back. Shrinking and growing are timed to the tr01.wav.
    Mix<Trigger<EFFECT_USER8,Int<1>,Int<1500>,Int<1000>>,
      AlphaL<BrownNoiseFlickerL<Rgb<140,0,0>,Int<20>>,SmoothStep<Int<3000>,Int<1000>>>,
      AlphaL<BrownNoiseFlicker<Rgb<180,0,0>,Rgb<35,0,0>,10>,SmoothStep<Scale<Scale<Trigger<EFFECT_USER8,Int<350>,Int<300>,Int<2000>>,Int<-300>,SlowNoise<Int<20000>>>,Scale<Trigger<EFFECT_USER8,Int<350>,Int<300>,Int<700>>,Int<32768>,Int<6000>>,Int<10000>>,Scale<SlowNoise<Int<5000>>,Int<-3000>,Int<-7000>>>>>,
    // More Sputtering Emitter
    AlphaL<Yellow,Bump<Scale<RandomF,Int<-8000>,Int<1000>>,Int<2000>>>,
    // Randomly Do EFFECT_USER8 on a loop. Occurances range from 8 sec to 20 sec.
    TransitionLoopL<TrConcat<TrDelayX<Scale<RandomF,Int<8000>,Int<20000>>>,TrDoEffect<TrInstant,EFFECT_USER8>>>,
    // USER8 additional blade glitch.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Black,SmoothStep<Int<18000>,Int<10000>>>,TrDelay<75>,Rgb<255,15,15>,TrDelay<50>>,EFFECT_USER8>,
    // USER8 additional glitch at emitter.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Orange,Bump<Scale<Trigger<EFFECT_USER8,Int<50>,Int<1>,Int<25>>,Int<0>,Int<7000>>,Int<4000>>>,TrDelay<75>,AlphaL<White,Bump<Int<0>,Int<9000>>>,TrFade<100>>,EFFECT_USER8>,
// alt sound stuff -------------
    // // USER8 causes tr01.wav to play.
    TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>>,EFFECT_USER8>,
    // // USER8 causes hum to switch to alt001 (silent) version. Then when the tr01.wav is finished (1742ms), it resumes playing alt000 version.
    // // In essence, this causes a monophonic playback effect of the glitch sound so it doesn't overlap the hum sound.
    TransitionEffectL<TrConcat<TrDoEffect<TrInstant,EFFECT_ALT_SOUND,1>,TrDelay<1742>,TrDoEffect<TrInstant,EFFECT_ALT_SOUND,0>>,EFFECT_USER8>,

    // This could also be done with a single switch by using a polyphonic version using altchg? But certainly works with monophonic chhum.wav.
    // By duplicating the real hum in both alt000 and alt001, then using chhum for the glitch sound, it will seamlessly play gapless between the hums.
    // Then no need to switch back to first hum (1 back to 0)again as above does, and a single line of code can be used:
    //TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_ALT_SOUND,EffectIncrementF<EFFECT_USER8,Int<2>>>,EFFECT_USER8>, 
// end alt sound stuff -------------
BC_effects_Red,
    // Ignition surge
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrSmoothFade<500>>,EFFECT_IGNITION>,
    // Reset hum to alt000 just in case so ignition is correct.
    TransitionEffectL<TrDoEffect<TrInstant,EFFECT_ALT_SOUND,0>,EFFECT_IGNITION>,
    // Reset hum to alt000 so next ignition is correct.
    TransitionEffectL<TrDoEffect<TrInstant,EFFECT_ALT_SOUND,0>,EFFECT_RETRACTION>,
    // Extension and retraction - Acceleration curved
    BC_Bend7_Spark_WavOUT_NoSpark_WavIN,
    // PostOff effects - auto matched to which wav file is chosen
    ColorSelect<WavNum<EFFECT_POSTOFF>,TrInstant,
      TransitionEffectL<TrConcat<TrFade<950>,AlphaL<BrownNoiseFlicker<Rgb<180,0,0>,Black,100>,Bump<Int<0>,Int<2000>>>,TrDelay<25>,AlphaL<OrangeRed,Bump<Int<0>,Int<8000>>>,TrDelay<50>,AlphaL<AudioFlicker<Red,Black>,Bump<Int<0>,Int<5000>>>,TrBoing<300,1>>,EFFECT_POSTOFF>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Red,Black>,Bump<Int<0>,Int<2000>>>,TrDelayX<Percentage<WavLen<>,25>>,AlphaL<AudioFlicker<OrangeRed,Black>,Bump<Int<0>,Int<9000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<BrownNoiseFlicker<Rgb<220,0,0>,Black,100>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,25>>>,EFFECT_POSTOFF>>,
    // Preon effect
    TransitionEffectL<TrConcat<TrWipe<100>,AlphaL<BrownNoiseFlicker<Rgb<255,20,20>,Black,80>,Bump<Int<0>,Int<40000>>>,TrFade<200>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<250>>,EFFECT_PREON>,
    // Volume Level
    TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>,
    // Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"scraptec" },


{ "aa_KSith/SoverignHP-BC;ProffieOS_V2_Voicepack_Malgus2/common;commonBU", "aa_KSith/SoverignHP-BC/tracks/track1.wav",

  StylePtr<Layers<
    /* Base blade */
    StripesX<Int<300>,Int<-4500>,Black,RotateColorsX<Variation,Rgb16<13896,65,22546>>>,
    AlphaL<StaticFire<Black,RotateColorsX<Variation,DarkOrange>,0,3,0,3000,70>,Int<16000>>,
    /* Swing color */
    AlphaL<Layers<
      HumpFlicker<Black,RotateColorsX<Variation,Cyan>,3>,
      AlphaL<RotateColorsX<Variation,DarkOrange>,SmoothStep<Int<4001>,Int<-10000>>>>,HoldPeakF<SwingSpeed<450>,Scale<SwingAcceleration<100>,Int<50>,Int<100>>,Scale<SwingAcceleration<>,Int<60000>,Int<10000>>>>,
    /* Random surge */
    TransitionLoop<AlphaL<Black,Int<0>>,TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<1500>,Int<5000>>>,AlphaL<Black,Int<0>>,TrSparkX<Mix<Int<25000>,Rgb<200,128,128>,Black>,Int<600>,Int<200>,Int<0>>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<13896,65,22546>>,Black,500>,TrFade<1000>>>,
    BC_effects_1,
    /* Ignition surge */
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<600>>,EFFECT_IGNITION>,
    /* Extension and retraction */
    InOutTrL<TrWipeSparkTipX<Rgb<128,128,128>,BendTimePowInvX<Int<600>,Int<180000>>>,TrWipeInSparkTipX<AlphaL<DarkOrange,Scale<Trigger<EFFECT_RETRACTION,Percentage<WavLen<EFFECT_RETRACTION>,40>,Percentage<WavLen<EFFECT_RETRACTION>,60>,Int<1>>,Int<0>,Int<16000>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<150000>>>>,
    /* PostOff effects - auto matched to which wav file is chosen */
    ColorSelect<WavNum<EFFECT_POSTOFF>,TrInstant,
      /* Emitter pop effect */
      TransitionEffectL<TrConcat<TrInstant,TrWaveX<Orange,Int<125>,Int<400>,Int<500>,Int<0>>>,EFFECT_POSTOFF>,
      /* Cool down emitter effect */
      TransitionEffectL<TrConcat<TrInstant,AlphaL<DarkOrange,Bump<Int<0>,Int<10000>>>,TrFadeX<Percentage<WavLen<>,50>>,AlphaL<DarkOrange,Bump<Int<0>,Int<8000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,25>>>,EFFECT_POSTOFF>>,
// On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),

  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrWipe<200>,Red,TrWipe<200>>>,
    InOutTrL<TrInstant,TrInstant,Blinking<Black,Red,2000,500>>
  >>(),
"soverign"},


};


BladeConfig blades[] = {

 { NO_BLADE,
  WS281XBladePtr<30, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SimpleBladePtr<CH1LED, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>(),
  CONFIGARRAY(bladein),
"00_noblade_save"},

 { 37000,
  WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SimpleBladePtr<CH1LED, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>(),
  CONFIGARRAY(bladein),
"00_bladein_save"}

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, auxPin, "aux");
Button AuxButton(BUTTON_AUX, powerButtonPin, "pow");
#endif
