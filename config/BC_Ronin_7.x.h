// BC_Ronin_7.x

#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BUTTONS 1
#define NUM_BLADES 1

// ------ Audio Stuff --------

#define VOLUME 2000
#define BOOT_VOLUME 100
// #define ENABLE_AUDIO     defaulted OS8
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                   // SPDIF out
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8
// #define FEMALE_TALKIE_VOICE
// #define NO_REPEAT_RANDOM     defaulted OS8
// #define KILL_OLD_PLAYERS     defaulted OS8
// #define DISABLE_TALKIE
#define ENABLE_FASTON

// ------ Blade Stuff ------

// #define ENABLE_WS2811     defaulted OS8
const unsigned int maxLedsPerStrip = 144;
//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet. Equivalent to just increasing maxLedsPerStrip.
// #define EXTRA_COLOR_BUFFER_SPACE 30

// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000> // resistor value used

// BridgedPullupBladeID is the default Proffieboard V3 BLADE_ID_CLASS, so it doesn't need to defined explicitly with a V3.
#define BLADE_ID_CLASS BridgedPullupBladeID<bladeIdentifyPin, 9> // PBv2.2 TX pad for example

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

//    Blanket define to cover the following 4
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
                #define NO_BLADE_ID_RANGE 15000,99999999

//    Requires wiring a pad to a switched GND
//    (floating pogo pin until grounded via blade-side PCB ring)
// #define BLADE_DETECT_PIN 10 

#define DYNAMIC_BLADE_LENGTH

// #define BC_DUAL_BLADES
// BLADE # corresponds to the blades list in the BladeConfig section of the config file.
// Defaults are BLADE 1 and BLADE 2 as MAIN and SECOND blades respectively.
// Optionally, you can also manually define custom dual blades if different than 1 and 2, for example:
// #define BC_MAIN_BLADE 2
// #define BC_SECOND_BLADE 4

// ------ SD Card Stuff -------

//#define ENABLE_SD     defaulted OS8
#define MOUNT_SD_SETTING  // This define will allow manual control of when to allow the SD to mount to the computer when Mass Storage is enabled by issuing "sd 1" in Serial Monitor.
// First let's review how Mass Storage works. Having the Arduino setting Tools>USB Type> Serial + Mass Storage selected allows the SD card to be accessed over USB (using the Proffieboard as a card reader).  
// The way it used to work before OS8 and this define was after the boot sound played, the SD card would immediately mount to the computer as an external USB drive. File transfers could take place then, and when finished, you would eject the SD from the computer. From then, the Proffieboard would use it as normal.
// This meant that you always had to wait for the SD card to mount, and then eject it before uploading or using Serial Monitor. It also meant that to re-access the SD, you'd need to either reboot, or unplug and then re-plug the USB cable.
// Now here's how it can work in OS8 using #define MOUNT_SD_SETTING.  
// Even though Mass Storage was selected and uploaded, this define prevents the SD card from mounting until manually "allowed" by the user.
// To allow the SD to mount, send the command "sd 1" in Serial Monitor. When you finish accessing the SD card and "eject" it from the computer, the Proffieboard will use it as normal and set the permission back to FALSE.
// If you want to access the SD again, you can just issue the  "sd 1" command again, and repeat as above.

//#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
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
//    PVLOG_ERROR 100 = errors
//    PVLOG_STATUS 200 = things you should probably know, like blade ID
//    PVLOG_NORMAL 300 = normal information about what is happening (default level)
//    PVLOG_DEBUG 400 = information helpful for debugging
//    PVLOG_VERBOSE 500 = repeated, spammy information you don't normally want
 #define PROFFIEOS_LOG_LEVEL 300

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

 #define CONFIG_STARTUP_DELAY 3000               // BC now canon

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_SPINS
// --- BC prop stuff -----
#define BC_SWING_ON
#define BC_SWING_ON_SPEED 400 // Default 250
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
#define BC_FORCE_PUSH
#define BC_FORCE_PUSH_LENGTH 5
 #define BC_ENABLE_AUTO_SWING_BLAST                     // BC Multiblast continues as long as swinging within 1 second. 
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200
/*    If using blade detect, Gesture ignitions or retractions are 
      disabled when no blade is used. BC prop.
      **NOTE** Only works when a BLADE_DETECT_PIN is defined.*/
//#define NO_BLADE_NO_GEST_ONOFF

// ------- Custom / Experimental / Alpha-Beta stuff ---------

// #define LOW_BATT_ONCE                            // BC - THIS NEEDS TO BE CheckLowBattry(), see PR     **Requires modified hybrid_font.h file.
// #define LOW_BATT_WARNINGS_TIERED                 // meh...just annoying if not accurate..likely.       **Requires modified hybrid_font.h file.
// #define ENABLE_GESTURE_MENU                      // PSISTORM prop - cool stuff! the TrySound else beep void.
// #define OPTIMIZE_TRCONCAT                       // this TRCONCAT can save some RAM, but it's not compatible with IntArg/RgbArg

// -------- BC Prop Other Stuff --------

// As of OS8, a System Menu is available to edit presets, colors and more. Also, Edit Settings menu to edit volume or blade length
// #define BC_ENABLE_OS_MENU

// -------- Blaster Stuff ----------

// #define BLASTER_ENABLE_AUTO
// #define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
// #define BLASTER_JAM_PERCENTAGE 4     // if not defined, random.
// #define BLASTER_DEFAULT_MODE MODE_KILL

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

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrSmoothFade<200>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrDelay<1000>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

/* ---- Presets list ---- /*

aa_Kyberphonic/The_Duel/Ronin;ProffieOS_Voicepack_The_Ronin/common;commonBU
aa_JayDalorian/OdaNobunaga;ProffieOS_Voicepack_The_Ronin/common;commonBU;commonBU/V2_Voicepack
aa_HarrySolo/Ronins_Path;ProffieOS_Voicepack_The_Ronin/common;commonBU
a_BAYLAN_SKOLL/Skoll;ProffieOS_Voicepack_Skoll/common;commonBU
aa_KSith/ScrapTec-BC;ProffieOS_Voicepack_Starkiller/common
aa_Kyberphonic/Great_Mother_V2;ProffieOS_Voicepack_Nightsisters/common;commonBU - BC blade Style
aa_Syndicate/Synergy;ProffieOS_Voicepack_Kylo_V2/common;commonBU- BC blade style - Preons matched to sounds
aa_Greyscale/Skotos_Greyscale;ProffieOS_Voicepack_The_Ronin/common;commonBU
aa_Blueforce/LiquidStatic;ProffieOS_Voicepack_Thrawn/common;commonBU
aa_JayDalorian/Parsec1;ProffieOS_Voicepack_The_Ronin/common;commonBU;commonBU/V2_Voicepack
aa_JayDalorian/Nexus;ProffieOS_Voicepack_The_Ronin/common;commonBU;commonBU/V2_Voicepack
aa_BK/The_Wicked;ProffieOS_Voicepack_The_Ronin/common;commonBU;commonBU/V2_Voicepack
aa_Greyscale/Stitched_Greyscale;ProffieOS_Voicepack_The_Ronin/common;commonBU;commonBU/V2_Voicepack



- commented out -
a_INQUISITOR/2ndSistr
a_INQUISITOR/9thSistr
a_BANE/TheBane w/ice monosfx
// a_BANE/RuleOfTwo
a_SIDIOUS/TheReturn
a_ASAJJ/NiteSist
a_DOOKU/Duke // Matched Preons/outs
a_DOOKU/Dooku_CW
a_SAVAGE/Savage_Opress
a_DARTH_MAUL/CrimsonMenace
a_INQUISITOR/RevaUltimate
aa_Syndicate/SithChant // ------------- check it
a_STARKILLER/Secret_Apprentice w/ice monosfx - broken out fx because force choke anim
aa_KSith/Aggression w/ colorchange 2 colors
a_KYLO/KyloUltimate
a_REY/Empress
a_VADER/Father_V2/ANH
aa_Greyscale/Seethe_Greyscale
aa_Juansith/HATE
aa_Blueforce/IgnitionUltimate
// aa_HarrySolo/AGONY
aa_KSith/Proto
aa_KSith/Desolation
aa_KSith/Ascension
// Arcane
aa_KSith/Traveler
// GhostsOfTheGrey
aa_LordBlako/PitchBlk
// a_PONG_KRELL/PongKrll
// Proto2
PsyBorg
a_DARKSABER/DarkV3
aa_Blueforce/LiquidStatic
*/


Preset Ronin [] = {

{ "aa_Kyberphonic/The_Duel/Ronin;ProffieOS_Voicepack_The_Ronin/common;commonBU;commonBU/V2_Voicepack", "The_Duel/tracks/track2.wav",
  StylePtr<Layers<
    HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
    BC_effects_Red,
    TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
// standard
    // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// BC_Bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // Postoff Emitter Cooldown
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb<255,50,50>,Bump<Int<0>,Int<3500>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Rgb<100,0,0>,Bump<Int<0>,Int<1000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
"the\nduel"},

// { "aa_JayDalorian/OdaNobunaga;ProffieOS_Voicepack_The_Ronin/common;commonBU;commonBU/V2_Voicepack", "aa_JayDalorian/OdaNobunaga/tracks/sharingan.wav",
//   StylePtr<Layers<
//     AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<200>>,EFFECT_IGNITION>,
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // Postoff Emitter Cooldown
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb<255,50,50>,Bump<Int<0>,Int<3500>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Rgb<100,0,0>,Bump<Int<0>,Int<1000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "oda\nnobunaga"},


// { "aa_HarrySolo/Ronins_Path;ProffieOS_Voicepack_The_Ronin/common;commonBU", "tracks/FallenOrderTracks/JFO9.wav",
//   StylePtr<Layers<
//     StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<200>>,EFFECT_IGNITION>,
// // standard
//     // InOutTrL<TrWipeSparkTip<Rgb<200,100,100>,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "ronins\npath"},


// { "a_BAYLAN_SKOLL/Skoll;ProffieOS_Voicepack_Skoll/common;commonBU", "a_BAYLAN_SKOLL/Skoll/tracks/track1.wav",
// //Second Sister Base Red
//   StylePtr<Layers<
// Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Mix<Int<16384>,OrangeRed,Black>>>,AudioFlicker<RotateColorsX<Variation,Mix<Int<16384>,Orange,Red>>,RotateColorsX<Variation,OrangeRed>>>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<100>>,EFFECT_IGNITION>,
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// // Preon
//   TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_PREON>>,AlphaL<RandomFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,OrangeRed>>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,
//     // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "baylan\nskoll"},


// { "aa_KSith/ScrapTec-BC;ProffieOS_Voicepack_Starkiller/common", "aa_KSith/ScrapTec/tracks/ScrapTec_track.wav",
//   // KSith_Scraptec - Solo Sabers - Final v2: Commented explanations - BC version with random glitch
//   StylePtr<Layers<Black,
//     // Sputtering Emitter
//     Mix<Trigger<EFFECT_USER8,Int<1>,Int<1500>,Int<1000>>,
//       StyleFire<Red,Red,0,8,FireConfig<350,500,0>,FireConfig<350,500,0>,FireConfig<350,500,0>,FireConfig<350,500,0>>,
//       AlphaL<Black,Int<0>>>,
//     // Base color is BrownNoise Red. When USER8 happens, it "dies down" to the glitchy 1/4 blade dimmer version, then grows back. Shrinking and growing are timed to the tr01.wav.
//     Mix<Trigger<EFFECT_USER8,Int<1>,Int<1500>,Int<1000>>,
//       AlphaL<BrownNoiseFlickerL<Rgb<140,0,0>,Int<20>>,SmoothStep<Int<3000>,Int<1000>>>,
//       AlphaL<BrownNoiseFlicker<Rgb<180,0,0>,Rgb<35,0,0>,10>,SmoothStep<Scale<Scale<Trigger<EFFECT_USER8,Int<350>,Int<300>,Int<2000>>,Int<-300>,SlowNoise<Int<20000>>>,Scale<Trigger<EFFECT_USER8,Int<350>,Int<300>,Int<700>>,Int<32768>,Int<6000>>,Int<10000>>,Scale<SlowNoise<Int<5000>>,Int<-3000>,Int<-7000>>>>>,
//     // More Sputtering Emitter
//     AlphaL<Yellow,Bump<Scale<RandomF,Int<-8000>,Int<1000>>,Int<2000>>>,
//     // Randomly Do EFFECT_USER8 on a loop. Occurances range from 8 sec to 20 sec.
//     TransitionLoopL<TrConcat<TrDelayX<Scale<RandomF,Int<8000>,Int<20000>>>,TrDoEffect<TrInstant,EFFECT_USER8>>>,
//     // USER8 additional blade glitch.
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Black,SmoothStep<Int<18000>,Int<10000>>>,TrDelay<75>,Rgb<255,15,15>,TrDelay<50>>,EFFECT_USER8>,
//     // USER8 additional glitch at emitter.
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Orange,Bump<Scale<Trigger<EFFECT_USER8,Int<50>,Int<1>,Int<25>>,Int<0>,Int<7000>>,Int<4000>>>,TrDelay<75>,AlphaL<White,Bump<Int<0>,Int<9000>>>,TrFade<100>>,EFFECT_USER8>,
//     // USER8 causes tr01.wav to play.
//     TransitionEffectL<TrDoEffectX<TrInstant,EFFECT_TRANSITION_SOUND,Int<0>>,EFFECT_USER8>,
//     // USER8 causes hum to switch to alt001 version. Then when the tr01.wav is finished (1742ms), it resumes playing alt000 version.
//     // In essence, this causes a monophonic playback effect of the glitch sound so it doesn't overlap the hum sound.
//     TransitionEffectL<TrConcat<TrDoEffect<TrInstant,EFFECT_ALT_SOUND,1>,TrDelay<1742>,TrDoEffect<TrInstant,EFFECT_ALT_SOUND,0>>,EFFECT_USER8>,
//     // Force Choke / lightning - WavLen duration sync.
//     TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<80,0,0>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Red,Strobe<Black,Cyan,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>,
//     // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<0>>>,
//     // Clash 2 V2 - Clash Impact sensitive, Flash at impact. WavLen duration sync.
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFadeX<Percentage<WavLen<>,35>>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,
//     Scale<ClashImpactF<200,5000>,Int<1000>,Int<32768>>>>,TrFadeX<Percentage<WavLen<>,45>>>,EFFECT_CLASH>,
//     // Stab - OrangeRed stripes. WavLen duration sync.
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,30>>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrSmoothFadeX<Percentage<WavLen<EFFECT_STAB>,90>>>,EFFECT_STAB>,
//     // Blast v1 - with Impact Flash
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//     // Waves
//     BlastL<Rgb<100,200,255>,850,250,351>,
//     // Impact point afterimage
//     AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//     // Impact point
//     BlastL<Rgb<100,200,255>,300,350,100000>,
//     // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//       // Random Strobe Flash no dimming
//       AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//       // Bottom Layer Bump - random width
//       AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
//       // Top Layer Bump - fixed width
//       AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//     // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
//     LockupTrL<Layers<
//       // Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
//       AlphaL<Black,Int<16000>>,
//       AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<4>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//       AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<Bump<Scale<SlowNoise<Int<1000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<1500>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//       // Begin Lightning Transition
//       TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
//       // End Lightning Transition    
//       TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     // Melt - OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
//     LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
//     // Ignition surge
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrSmoothFade<500>>,EFFECT_IGNITION>,
//     // Reset hum to alt000 just in case so ignition is correct.
//     TransitionEffectL<TrDoEffect<TrInstant,EFFECT_ALT_SOUND,0>,EFFECT_IGNITION>,
//     // Reset hum to alt000 so next ignition is correct.
//     TransitionEffectL<TrDoEffect<TrInstant,EFFECT_ALT_SOUND,0>,EFFECT_RETRACTION>,
//     // Extension and retraction - Acceleration curved
//     InOutTrL<TrWipeX<BendTimePowInvX<Int<600>,Int<180000>>>,TrWipeInSparkTipX<AlphaL<Rgb<255,10,10>,Scale<Trigger<EFFECT_RETRACTION,Percentage<WavLen<EFFECT_RETRACTION>,40>,Percentage<WavLen<EFFECT_RETRACTION>,60>,Int<1>>,Int<0>,Int<16000>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<150000>>>>,
//     // PostOff effects - auto matched to which wav file is chosen
//     ColorSelect<WavNum<EFFECT_POSTOFF>,TrInstant,
//       TransitionEffectL<TrConcat<TrFade<950>,AlphaL<BrownNoiseFlicker<Rgb<180,0,0>,Black,100>,Bump<Int<0>,Int<2000>>>,TrDelay<25>,AlphaL<OrangeRed,Bump<Int<0>,Int<8000>>>,TrDelay<50>,AlphaL<AudioFlicker<Red,Black>,Bump<Int<0>,Int<5000>>>,TrBoing<300,1>>,EFFECT_POSTOFF>,
//       TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<Red,Black>,Bump<Int<0>,Int<2000>>>,TrDelayX<Percentage<WavLen<>,25>>,AlphaL<AudioFlicker<OrangeRed,Black>,Bump<Int<0>,Int<9000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<BrownNoiseFlicker<Rgb<220,0,0>,Black,100>,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,25>>>,EFFECT_POSTOFF>>,
//     // Preon effect
//     TransitionEffectL<TrConcat<TrWipe<100>,AlphaL<BrownNoiseFlicker<Rgb<255,20,20>,Black,80>,Bump<Int<0>,Int<40000>>>,TrFade<200>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<250>>,EFFECT_PREON>,
//     // Volume Level
//     TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>,
//     // Battery Level
//     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// // { "aa_KSith/ScrapTec;ProffieOS_Voicepack_Starkiller/common", "aa_KSith/ScrapTec/tracks/ScrapTec_track.wav",
// //   // KSith_Scraptec - Solo Sabers - Final v3: Dumbed down - Commented explanations
// //   StylePtr<Layers<Black,
// //     // Sputtering Emitter
// //     Mix<Trigger<EFFECT_USER8,Int<1>,Int<1500>,Int<1000>>,StyleFire<Red,Red,0,8,FireConfig<350,500,0>,FireConfig<300,900,0>,FireConfig<300,900,0>,FireConfig<300,900,0>>,AlphaL<Black,Int<0>>>,
// //     // Base color is BrownNoise Red. When glitch happens, it "dies down" to the 1/4 blade dimmer version, then grows back.
// //     Mix<Trigger<EFFECT_USER8,Int<1>,Int<1500>,Int<1000>>,AlphaL<BrownNoiseFlickerL<Rgb<100,0,0>,Int<20>>,SmoothStep<Int<3000>,Int<1000>>>,AlphaL<BrownNoiseFlicker<Rgb<180,0,0>,Rgb<35,0,0>,10>,SmoothStep<Scale<Scale<Trigger<EFFECT_USER8,Int<350>,Int<300>,Int<2000>>,Int<-300>,SlowNoise<Int<20000>>>,Scale<Trigger<EFFECT_USER8,Int<350>,Int<300>,Int<700>>,Int<32768>,Int<6000>>,Int<10000>>,Scale<SlowNoise<Int<5000>>,Int<-3000>,Int<-7000>>>>>,
//     // // More Sputtering Emitter
//     // AlphaL<Yellow,Bump<Scale<RandomF,Int<-8000>,Int<1000>>,Int<2000>>>,
// //     // Do glitch on a loop. Occurs at 26.850 seconds of hum, accounts for duration of glitch and remaining hum for 1742ms.
// //     TransitionEffectL<TrLoop<TrConcat<TrDelayX<Int<26850>>,TrDoEffect<TrInstant,EFFECT_USER8>,TrDelay<1742>>>,EFFECT_IGNITION>,
// //     // Additional blade glitch.
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<Black,SmoothStep<Int<18000>,Int<10000>>>,TrDelay<75>,Rgb<255,15,15>,TrDelay<50>>,EFFECT_USER8>,
// //     // Additional glitch at emitter.
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<Orange,Bump<Scale<Trigger<EFFECT_USER8,Int<50>,Int<1>,Int<25>>,Int<0>,Int<7000>>,Int<4000>>>,TrDelay<75>,AlphaL<White,Bump<Int<0>,Int<9000>>>,TrFade<100>>,EFFECT_USER8>,
// //     // Force Choke / lightning - WavLen duration sync.
// //     TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<80,0,0>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Red,Strobe<Black,Cyan,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>,
// //     // Dim Blade 50% "Power Save" button combo
// //     EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<0>>>,
// //     // Clash 2 V2 - Clash Impact sensitive, Flash at impact. WavLen duration sync.
// //     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFadeX<Percentage<WavLen<>,35>>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,
// //     Scale<ClashImpactF<200,5000>,Int<1000>,Int<32768>>>>,TrFadeX<Percentage<WavLen<>,45>>>,EFFECT_CLASH>,
// //     // Stab - OrangeRed stripes. WavLen duration sync.
// //     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,30>>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrSmoothFadeX<Percentage<WavLen<EFFECT_STAB>,90>>>,EFFECT_STAB>,
// //     // Blast v1 - with Impact Flash
// //     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
// //     // Waves
// //     BlastL<Rgb<100,200,255>,850,250,351>,
// //     // Impact point afterimage
// //     AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
// //     // Impact point
// //     BlastL<Rgb<100,200,255>,300,350,100000>,
// //     // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
// //     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// //     LockupTrL<Layers<
// //       // Random Strobe Flash no dimming
// //       AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
// //       // Bottom Layer Bump - random width
// //       AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
// //       // Top Layer Bump - fixed width
// //       AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
// //     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
// //     // Non-Responsive Drag - BC custom drag fadeout
// //     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// //     // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
// //     LockupTrL<Layers<
// //       // Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
// //       AlphaL<Black,Int<16000>>,
// //       AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<4>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
// //       AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<Bump<Scale<SlowNoise<Int<1000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<1500>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
// //       // Begin Lightning Transition
// //       TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
// //       // End Lightning Transition    
// //       TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// //     // Melt - OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
// //     LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
// //     // Ignition surge
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrSmoothFade<500>>,EFFECT_IGNITION>,
// //     // Extension and retraction - Acceleration curved
// //     InOutTrL<TrWipeX<BendTimePowInvX<Int<600>,Int<180000>>>,TrWipeInSparkTipX<AlphaL<Rgb<255,10,10>,Scale<Trigger<EFFECT_RETRACTION,Percentage<WavLen<EFFECT_RETRACTION>,40>,Percentage<WavLen<EFFECT_RETRACTION>,60>,Int<1>>,Int<0>,Int<16000>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<150000>>>>,
// //     // Preon effect
// //     TransitionEffectL<TrConcat<TrWipe<100>,AlphaL<BrownNoiseFlicker<Rgb<255,20,20>,Black,80>,Bump<Int<0>,Int<40000>>>,TrFade<200>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<250>>,EFFECT_PREON>,
// //     // Volume Level
// //     TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>,
// //     // Battery Level
// //     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// //   >>(),
// "scraptec" },


//    { "aa_Kyberphonic/Great_Mother_V2;ProffieOS_Voicepack_Nightsisters/common;commonBU", "aa_Kyberphonic/Great_Mother_V2/tracks/track1.wav",
//     StylePtr<Layers<Black,
//       AlphaL<Mix<HoldPeakF<SwingSpeed<100>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<30000>,Int<10000>>>,
//         StaticFire<Mix<Int<16000>,Black,Green>,Mix<Int<16000>,Black,Rgb16<0,18927,65535>>,0,1,10,3000,2>,
//         StaticFire<Mix<Int<16000>,Black,Green>,Mix<Int<16000>,Black,Rgb16<0,18927,65535>>,0,3,10,3000,2>>,IsGreaterThan<BladeAngle<>,Int<16384>>>,
//       AlphaL<Mix<HoldPeakF<SwingSpeed<100>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<30000>,Int<10000>>>,
//         Remap<InvertF<RampF>,StaticFire<Mix<Int<16000>,Black,Green>,Mix<Int<16000>,Black,Rgb16<0,18927,65535>>,0,1,10,3000,2>>,
//         Remap<InvertF<RampF>,StaticFire<Mix<Int<16000>,Black,Green>,Mix<Int<16000>,Black,Rgb16<0,18927,65535>>,0,3,10,3000,2>>>,IsLessThan<BladeAngle<>,Int<16384>>>,
//       AlphaL<Black,LayerFunctions<Bump<Sin<Int<10>,Int<-10000>,Int<33000>>,Sin<Int<10>,Int<58000>,Int<48000>>>,Bump<Sin<Int<7>,Int<-1000>,Int<37000>>,Sin<Int<50>,Int<47000>,Int<38000>>>,Bump<Sin<Int<8>,Int<35000>,Int<-8000>>,Sin<Int<15>,Int<43000>,Int<35000>>>>>,
//       SparkleL<SpringGreen,150,50>,
//     // Force effect powerup. WavLen duration sync.
//     EffectSequence<EFFECT_FORCE,
//       TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<0,0,80>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Blue,Strobe<Black,Cyan,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>,
//       TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<0,80,0>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Green,Strobe<Black,GreenYellow,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>>,
//   // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//         AlphaL<Black,Int<16384>>,
//         AlphaL<Black,Int<0>>>,
//   // Clash 1 - BladeAngle responsive. Flash at impact, WavLen duration sync.
//     // Linear TrConcat version, now clash impact sized
//         TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<155,250,0>,Black,50>,White,TrInstant,TrFadeX<Percentage<WavLen<>,35>>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Scale<ClashImpactF<>,Int<4000>,Int<32768>>>>,TrFadeX<Percentage<WavLen<>,65>>>,EFFECT_CLASH>,
//    // Stab - OrangeRed stripes. WavLen duration sync.
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,30>>,AlphaL<Stripes<5000,1000,GreenYellow,DodgerBlue,Green,Chartreuse,Black,Green>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFadeX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeX<Percentage<WavLen<EFFECT_STAB>,70>>>>,EFFECT_STAB>,
//   // Blast
//     TransitionEffectL<TrConcat<
//         // Impact Flash - BC always
//         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//         // Waves
//         BlastL<DeepSkyBlue,850,250,351>,
//         // Impact point afterimage
//         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Cyan,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         // Impact point
//         BlastL<SpringGreen,300,350,100000>,
//   // Lockup 1 - BC custom range mid-blade to hilt w/random strobe flash
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//         //Random Strobe Flash no dimming
//         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//         // Bottom Layer Bump - random width
//         AlphaL<Blinking<Green,Strobe<Yellow,Black,15,30>,60,500>,                                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//         // Top Layer Bump - fixed width
//         AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Green,50>,100,500>,          Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,
//         // Begin Lockup Transition
//         TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//         // End Lockup Transition
//         TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                               Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//   // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//   // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)
//     LockupTrL<Layers<
//         //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
//         AlphaL<Black,Int<16000>>,
//         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<
//         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//         // Begin Lightning Transition
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
//         // End Lightning Transition    
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//         // OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions)
//         AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,
//         // Melt Shape
//         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
//         // Melt Begin and End transitions
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
// InOutTrL<TrWipe<1800>,TrWipe<1000>>,
// TransitionEffectL<TrConcat<TrJoin<TrCenterWipeInX<Int<200>>,TrJoin<TrWaveX<SpringGreen,Int<200>,Int<200>,Sum<Int<200>,Int<200>>,Int<0>>,TrWaveX<SpringGreen,Int<200>,Int<300>,Sum<Int<200>,Int<200>>,Int<32768>>>>,SparkleL<SpringGreen,650,80>,TrFade<3000>>,EFFECT_IGNITION>,
//     // Volume Level - gradient Blue -> Green
//       OnDemandVolumeLevel,
//     // On-Demand Battery Level
//       OnDemandBatteryLevel
//   >>(),
// "great_mother_v2"},


// { "aa_Syndicate/Synergy;ProffieOS_Voicepack_Kylo_V2/common;commonBU", "aa_Syndicate/SithChant/tracks/music_from_the_dark_side_edit.wav",

// /* Synergy by Syndicate Customs. Bladestyle by NoSloppy 2023
// Preons matched to sounds via font's config.ini
// Swing Responsive effect.*/

// StylePtr<Layers<
//   /* Base blade */
//   StripesX<Int<300>,Int<-4500>,Black,RotateColorsX<Variation,Rgb16<13896,65,22546>>>,
//   AlphaL<StaticFire<Black,RotateColorsX<Variation,DarkOrange>,0,3,0,3000,70>,Int<16000>>,
//   /* Swing color */
//   AlphaL<Layers<
//     HumpFlicker<Black,RotateColorsX<Variation,Rgb16<13896,65,22546>>,3>,
//     AlphaL<RotateColorsX<Variation,DarkOrange>,SmoothStep<Int<4001>,Int<-10000>>>>,HoldPeakF<SwingSpeed<300>,Scale<SwingAcceleration<100>,Int<50>,Int<100>>,Scale<SwingAcceleration<>,Int<60000>,Int<10000>>>>,
//   /* Random surge */
//   TransitionLoop<AlphaL<Black,Int<0>>,TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<1500>,Int<5000>>>,AlphaL<Black,Int<0>>,TrSparkX<Mix<Int<25000>,Rgb<200,128,128>,Black>,Int<600>,Int<200>,Int<0>>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<13896,65,22546>>,Black,500>,TrFade<1000>>>,
//   /* Force effect powerup. WavLen duration sync. */
//   EffectSequence<EFFECT_FORCE,TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<0,0,80>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Blue,Strobe<Black,Cyan,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<0,80,0>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<Green,Strobe<Black,GreenYellow,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>>,
//   /* Dim Blade 50% "Power Save" button combo */
//   EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<0>>>,
//   /* Clash 1 - BladeAngle responsive. Flash at impact, WavLen duration sync. Size based on impact strength */
//   TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFadeX<Percentage<WavLen<>,35>>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Scale<ClashImpactF<>,Int<4000>,Int<32768>>>>,TrFadeX<Percentage<WavLen<>,65>>>,EFFECT_CLASH>,
//   /* Stab - OrangeRed stripes. WavLen duration sync. */
//   TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,30>>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFadeX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeX<Percentage<WavLen<EFFECT_STAB>,70>>>>,EFFECT_STAB>,
//   /* Blast */
//   /* Impact Flash - BC always */ 
//   TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//   /* Waves */
//   BlastL<White,850,250,351>,
//   /* Impact point afterimage */
//   AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<255,70,70>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//   /* Impact point */
//   BlastL<White,300,350,100000>,
//   /* Lockup 1 - BC custom range mid-blade to hilt w/random strobe flash */
//   TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//   LockupTrL<Layers<
//     /*Random Strobe Flash no dimming */
//     AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//     /* Bottom Layer Bump - random width */
//     AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//     /* Top Layer Bump - fixed width */
//     AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     /* Begin Lockup Transition */
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     /* End Lockup Transition */
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//   /* Non-Responsive Drag - BC custom drag fadeout */
//   LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_DRAG>,
//   /* Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning) */
//   LockupTrL<Layers<
//     /*Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop */
//     AlphaL<Black,Int<16000>>,
//     AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//     AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//     /* Begin Lightning Transition */
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
//     /* End Lightning Transition */
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//   /* Melt - BC custom melt effects, uses twistangle<>. For OS 6 (Based on "Intensity Melt" - Fett263. Remap Fire to travel tip->emitter, Custom Begin and End Transitions) */
//   LockupTrL<
//     AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,Rgb16<20393,93,93>,DarkOrange>,Mix<TwistAngle<>,Rgb16<20393,93,93>,Orange>,0,4,5,4000,10>>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<4000>>>,
//     /* Melt Begin and End transitions */
//     TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>,AlphaL<Red,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrExtend<3000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,TrFade<3000>>,TrColorCycle<1500,-2000>,SaberBase::LOCKUP_MELT>,
//   /* Ignition surge */
//   TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<600>>,EFFECT_IGNITION>,
//   /* Extension and retraction */
//   InOutTrL<TrWipeSparkTipX<Rgb<128,128,128>,BendTimePowInvX<Int<600>,Int<180000>>>,TrWipeInSparkTipX<AlphaL<DarkOrange,Scale<Trigger<EFFECT_RETRACTION,Percentage<WavLen<EFFECT_RETRACTION>,40>,Percentage<WavLen<EFFECT_RETRACTION>,60>,Int<1>>,Int<0>,Int<16000>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<150000>>>>,
//   /* PostOff effects - auto matched to which wav file is chosen */
//   ColorSelect<WavNum<EFFECT_POSTOFF>,TrInstant,
//     /* Emitter pop effect */
//     TransitionEffectL<TrConcat<TrInstant,TrWaveX<Orange,Int<125>,Int<400>,Int<500>,Int<0>>>,EFFECT_POSTOFF>,
//     /* Cool down emitter effect */
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<DarkOrange,Bump<Int<0>,Int<10000>>>,TrFadeX<Percentage<WavLen<>,50>>,AlphaL<DarkOrange,Bump<Int<0>,Int<8000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFadeX<Percentage<WavLen<>,25>>>,EFFECT_POSTOFF>>,
//   /* Preons matched to sounds via font's config.ini */
//   ColorSelect<WavNum<EFFECT_PREON>,TrInstant,
//    /* Preon 1 */
//     Layers<
//       TransitionEffectL<TrConcat<TrInstant,White,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipe<75>,AlphaL<BrownNoiseFlicker<DarkOrange,Black,200>,SmoothStep<Int<16384>,Int<-1>>>,TrCenterWipe<200>,Black,TrInstant,AlphaL<Rgb16<13896,65,22546>,SmoothStep<Scale<SlowNoise<Int<8000>>,Int<0>,Int<8000>>,Int<-1>>>,TrDelay<1410>,AlphaL<Stripes<300,-1000,Black,Rgb16<13896,65,22546>>,SmoothStep<Scale<SlowNoise<Int<6000>>,Int<4000>,Int<20000>>,Int<-1>>>,TrDelay<1100>,AlphaL<Black,Int<0>>,TrCenterWipeIn<1295>,RandomBlink<30000,Rgb16<13896,65,22546>>,TrSparkX<DarkOrange,Int<300>,Int<300>,Int<0>>,AlphaL<Black,Int<0>>,TrWipe<300>,AlphaL<RandomFlicker<Orange,Black>,Bump<Int<0>,Int<35000>>>,TrFade<370>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<1125>,AlphaL<Black,Int<0>>,TrFade<300>,StaticFire<Black,Strobe<Red,DarkOrange,75,35>,0,5,0,2500,25>,TrDelay<285>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<3020>,White,TrDelay<25>,RandomFlicker<Orange,Black>,TrFade<200>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<4565>,SparkleL<DarkOrange,200,2000>,TrFade<1550>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<6115>,AlphaL<Black,Int<0>>,TrFade<1164>,StaticFire<Black,Strobe<Red,DarkOrange,75,35>,0,5,0,2500,15>,TrInstant>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<6115>,AlphaL<Black,Int<0>>,TrWipeIn<635>,Stripes<300,-1000,Black,Rgb16<13896,65,22546>>,TrWipeIn<529>,Black,TrInstant,White,TrDelay<10>>,EFFECT_PREON>>,
//     /* Preon 2 */
//     Layers<
//       TransitionEffectL<TrConcat<TrColorCycle<4800,1>,Rgb16<13896,65,22546>,TrFade<100>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<1575>,AlphaL<Black,Int<0>>,TrCenterWipe<900>,RandomBlink<30000,Black,Rgb<128,0,0>>,TrCenterWipe<775>,Stripes<300,-4500,Black,Rgb16<13896,65,22546>>,TrInstant,BlinkingX<AlphaL<Stripes<3000,-4500,Black,DarkOrange>,Int<16000>>,Black,Int<100>,Int<500>>,TrDelay<800>,AlphaL<Stripes<3000,-4500,Black,DarkOrange>,Int<16000>>,TrFade<350>>,EFFECT_PREON>,
//       TransitionEffectL<TrConcat<TrDelay<3888>,AlphaL<Black,Int<0>>,TrWipe<800>,StaticFire<Black,Strobe<Red,DarkOrange,75,35>,100,5,100,2500>,TrSparkX<DarkOrange,Int<100>,Int<100>,Int<32768>>>,EFFECT_PREON>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "synergy"},


// { "aa_Greyscale/Skotos_Greyscale;ProffieOS_Voicepack_The_Ronin/common;commonBU", "",
//   StylePtr<Layers<
//     // Base Fett263 Violet Audioflicker
//       AudioFlicker<RotateColorsX<Variation,Rgb<135,0,255>>,RotateColorsX<Variation,Rgb<67,0,115>>>,
//     // Deep Violet HumpFlicker Swing Effect
//       AlphaL<HumpFlicker<RotateColorsX<Variation,Rgb<175,0,255>>,RotateColorsX<Variation,Rgb<97,0,135>>,20>,SwingSpeed<375>>,
//     // BC less severe Unstable Charge-Up Ignition
//     TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-1550,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFadeX<Percentage<WavLen<EFFECT_IGNITION>,35>>,TrInstant>,EFFECT_IGNITION>,
//     // HumpFlicker Bright Retraction
//       TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<RotateColorsX<Variation,Rgb16<65535,42753,65535>>,RotateColorsX<Variation,White>,50>,TrInstant>,EFFECT_RETRACTION>,
//      BC_effects_1,
//       //BC_Bend
//        InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     // False Start Preon
//      TransitionEffectL<TrConcat<TrInstant,Black,TrWaveX<RotateColorsX<Variation,Rgb<135,0,255>>,Int<1750>,Int<175>,Int<1575>,Int<-3000>>,Black,TrInstant>,EFFECT_PREON>,
//     //Ripple Out Preon
//       TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_PREON>,43>>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb16<37981,16439,65535>>,Int<525>,Int<350>,Int<715>,Int<0>>>,TrFadeX<Percentage<WavLen<EFFECT_PREON>,55>>>,EFFECT_PREON>,
//     // Noise Responsive Charge Up Preon
//       TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_PREON>,14>>,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb16<65535,42753,65535>>,150>,SmoothStep<Scale<NoisySoundLevel,Int<-1500>,Trigger<EFFECT_PREON,WavLen<EFFECT_PREON>,Int<0>,Int<0>>>,Int<-9500>>>,TrDelayX<Percentage<WavLen<EFFECT_PREON>,86>>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,Bump<Int<0>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
//     // BC Emitter White with audio pulses (hopefully) then blackout silence before end full blade noise
//     TransitionEffectL<TrConcat<TrDelay<5500>,TrFade<440>,Black,TrDelay<560>,TrFade<230>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb16<65535,42753,65535>>,150>,TrDelay<290>>,EFFECT_PREON>,
//     // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "skotos"},


// { "aa_Blueforce/LiquidStatic;ProffieOS_Voicepack_Thrawn/common;commonBU", "",
//   StylePtr<Layers<
//     StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<Blue,Mix<Int<2570>,Black,Blue>,1200>,Mix<SwingSpeed<200>,Mix<Int<16000>,Black,Blue>,Black>>,Mix<Int<7710>,Black,Blue>,Pulsing<Mix<Int<6425>,Black,Blue>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,Blue,Mix<Int<12000>,Black,Blue>>,2000>,Pulsing<Mix<Int<16448>,Black,Blue>,Mix<Int<642>,Black,Blue>,3000>>,
//     AlphaL<StaticFire<Blue,Mix<Int<256>,Black,Blue>,0,1,10,2000,2>,Int<10000>>,
//     AlphaL<LightCyan,SmoothStep<Int<2000>,Int<-6000>>>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1200>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,Stripes<3000,3500,Blue,RandomPerLEDFlicker<Mix<Int<7710>,Black,Blue>,Black>,BrownNoiseFlicker<Blue,Mix<Int<3855>,Black,Blue>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,Blue>,Mix<Int<3855>,Black,Blue>>>,TrInstant>,EFFECT_RETRACTION>,
//     BC_effects_1,
//     // InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTipX<LightCyan,WavLen<EFFECT_RETRACTION>,Int<401>>>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<2000>,Sum<Int<2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_POSTOFF>>>,EFFECT_POSTOFF>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "liquid\nstatic"},


// { "aa_JayDalorian/Parsec1;ProffieOS_Voicepack_The_Ronin/common;commonBU;commonBU/V2_Voicepack", "",
//   StylePtr<Layers<
//     StyleFire<Stripes<2500,-8000,BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,20>,RotateColorsX<Variation,DeepSkyBlue>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Blue>,70>,RotateColorsX<Variation,SteelBlue>>,RotateColorsX<Variation,DodgerBlue>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,
//     /* Emitter Flare */
//     AlphaL<White,Bump<Int<0>,Int<8000>>>,
//    /* Clash 1 - BladeAngle responsive. Yellowish impact */
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,White,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//     /* Blast */
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//     /* Waves */
//     BlastL<White,850,250,351>,
//     /* Impact point afterimage */
//     AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<255,70,70>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//     /* Impact point */
//     BlastL<White,300,350,100000>,
//     /* Stab - OrangeRed stripes */
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//    /* Force */
//      TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<EFFECT_FORCE>,5>>,Mix<SwingSpeed<400>,AudioFlickerL<Green>,Orange>,TrDelayX<Percentage<WavLen<EFFECT_FORCE>,80>>,Mix<SwingSpeed<400>,AudioFlickerL<Cyan>,SpringGreen>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,15>>>,EFFECT_FORCE>,
//       /* Lockup 1 - BC custom range mid-blade to hilt w/random strobe flash */
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//       /* Random Strobe Flash no dimming */
//       AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//       /* Bottom Layer Bump - random width */
//       AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
//       /* Top Layer Bump - fixed width */
//       AlphaL<Blinking<BrownNoiseFlicker<White,Black,50>,BrownNoiseFlicker<Yellow,Tomato,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<9000>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//     /* Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning) */
//     LockupTrL<Layers<
//       /*Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop */
//       AlphaL<Black,Int<16000>>,
//       AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//       AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,150,150>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,150,150>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
//    /* Drag */
//     LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
//    /* Melt */
//     LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<100,100,255>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrJoin<TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>,TrSparkX<Rgb<100,100,255>,Int<400>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<32768>>>>,
//     TransitionEffectL<TrConcat<TrColorCycle<1000>,DeepSkyBlue,TrWipeIn<200>>,EFFECT_PREON>,
//     TransitionEffectL<TrSparkX<White,Int<100>,Int<300>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "parsec\nblue"},

// { "aa_JayDalorian/Nexus;ProffieOS_Voicepack_The_Ronin/common;commonBU;commonBU/V2_Voicepack", "", // Ice Stab and scanning Force
//   StylePtr<Layers<
//     StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<30,0,66>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<7,0,16>>,RotateColorsX<Variation,Rgb<95,0,210>>>,
//     BC_effects_White,
//     TransitionEffectL<TrConcat<TrFade<400>,RotateColorsX<Variation,Rgb<160,60,255>>,TrDelay<7000>,RotateColorsX<Variation,Rgb<160,60,255>>,TrFade<800>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Stripes<10,-1600,Mix<Sin<Int<30>>,White,Black>,Mix<Sin<Int<30>>,White,Black>,Mix<Sin<Int<24>>,Green,White>>,Bump<Scale<Sin<Int<40>>,Int<1000>,Int<34000>>,Int<20000>>>,TrDelay<7000>>,EFFECT_FORCE>,
//     TransitionEffectL<TrConcat<TrFade<3000>,RotateColorsX<Variation,Rgb<95,0,210>>,TrDelay<5000>,RotateColorsX<Variation,Rgb<95,0,210>>,TrFade<3000>>,EFFECT_STAB>,
//     TransitionEffectL<TrConcat<TrWipe<3000>,TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Rgb<100,150,230>,TrFade<3000>,TrDelay<3000>,EFFECT_STAB>,TrDelay<3000>,Rgb<100,150,230>,TrWipe<3000>>,EFFECT_STAB>,
//     TransitionEffectL<TrConcat<TrWaveX<BrownNoiseFlicker<White,SteelBlue,60>,Int<3000>,Int<400>,Int<3000>,Int<0>>,AlphaL<White,Int<0>>,TrDelay<3000>,AlphaL<White,Int<0>>,TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,Int<10000>,Int<400>,Int<3000>,Int<0>>>,EFFECT_STAB>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<100,100,255>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrJoin<TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>,TrSparkX<Rgb<100,100,255>,Int<400>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<32768>>>>,
//     TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RandomPerLEDFlickerL<White>,SmoothStep<Int<6000>,Int<-4000>>>,TrDelayX<WavNum<EFFECT_PREON>>>,EFFECT_PREON>,
//     TransitionEffectL<TrConcat<TrColorCycle<1000,0>,GhostWhite,TrFade<100>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "nexus"},



// { "aa_BK/The_Wicked;ProffieOS_Voicepack_The_Ronin/common;commonBU;commonBU/V2_Voicepack", "aa_BK/The_Wicked/wick-trk.wav",
//   StylePtr<Layers<
//     StyleFire<Gradient<Yellow,OrangeRed,Red>,Cyan,0,3,FireConfig<100,2500,21>,FireConfig<50,1000,0>,FireConfig<50,10,10>,FireConfig<0,0,13>>,
//     BC_effects_Red,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<100,100,255>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrJoin<TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>,TrSparkX<Rgb<100,100,255>,Int<400>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<32768>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "the\nwicked"},


// { "aa_Greyscale/Stitched_Greyscale;ProffieOS_Voicepack_The_Ronin/common;commonBU;commonBU/V2_Voicepack", "",
//   StylePtr<Layers<
//   //Base Fett263 Ice Blue Audioflicker
//   AudioFlicker<RotateColorsX<Variation,Rgb16<13655,53737,65535>>,RotateColorsX<Variation,Rgb<45,95,135>>>,
//     //Ice Blue HumpFlicker Swing Effect
//   AlphaL<HumpFlicker<RotateColorsX<Variation,Rgb16<33124,58942,65535>>,RotateColorsX<Variation,Rgb<45,95,135>>,90>,SwingSpeed<375>>,
//   BC_effects_1,
//     //Fett263 Unstable Charge-Up Ignition
//   TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-1550,Rgb16<33124,58942,65535>,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<Rgb16<33124,58942,65535>,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFadeX<Percentage<WavLen<EFFECT_IGNITION>,35>>,Stripes<3000,-1950,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,300>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFadeX<Percentage<WavLen<EFFECT_IGNITION>,65>>>,EFFECT_IGNITION>,
//     //HumpFlicker Bright Retraction
//   TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,HumpFlicker<RotateColorsX<Variation,Rgb16<33124,58942,65535>>,RotateColorsX<Variation,White>,50>,TrInstant>,EFFECT_RETRACTION>,
// // BC_Bend
//   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<100,100,255>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrJoin<TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>,TrSparkX<Rgb<100,100,255>,Int<400>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<32768>>>>,
//   //Overload Preon Effect
//   TransitionEffectL<TrConcat<TrFadeX<Percentage<WavLen<>,15>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,10>,Bump<Int<0>,Int<3000>>>,TrFadeX<Percentage<WavLen<>,20>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,15>,Bump<Int<0>,Int<5000>>>,TrFadeX<Percentage<WavLen<>,30>>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,25>,Bump<Int<0>,Int<7000>>>,TrFadeX<Percentage<WavLen<>,35>>>,EFFECT_PREON>,
//   //Noise Responsive Charge Up Preon
//   TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_PREON>,66>>,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb16<33124,58942,65535>>,150>,SmoothStep<Scale<NoisySoundLevel,Int<-1500>,Trigger<EFFECT_PREON,WavLen<EFFECT_PREON>,Int<0>,Int<0>>>,Int<-13500>>>,TrDelayX<Percentage<WavLen<EFFECT_PREON>,34>>>,EFFECT_PREON>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "stitched"},











































// { "a_INQUISITOR/2ndSistr;ProffieOS_Voicepack_Vader_V2/common;commonBU", "tracks/FallenOrderTracks/JFO5.wav",
// //Second Sister Base Red
//   StylePtr<Layers<
//     Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<100>>,EFFECT_IGNITION>,
//     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// "second\nsister"},


// // { "a_INQUISITOR/9thSistr;common;commonBU", "tracks/FallenOrderTracks/JFO7.wav",
// // //Second Sister Base Red
// //   StylePtr<Layers<
// // Mix<SwingSpeed<500>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<150,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<180,0,0>>,0,2,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
// //     BC_effects_Red,
// //   // Ignition and Retraction
// //     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<100>>,EFFECT_IGNITION>,
// //     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// // // standard
// //     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // // BC_Bend
// //    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// //     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "ninth\nsister"},



// // { "a_BANE/TheBane;common;commonBU", "a_BANE/tracks/track2.wav", // AudioFlicker Red Base Color Wheel Changeable
   
// //   StylePtr<Layers<
// //     AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
// //         // Ice Force
// //     TransitionEffectL< 
// //       TrConcat<TrFade<7000>,Rgb<10,0,75>,// blade turns solid cold 1000ms before ice full coverage
// //       TrDelay<1000>>,EFFECT_USER2>,  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to Base color
// //     TransitionEffectL< TrConcat<TrWipe<8000>, //wipe in stripes ice freezing effect
// //     TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>,TrFade<11500>,TrDelay<20000>,EFFECT_USER2>, // Stripes fade to solid over remaining 4 seconds from freezing edge's finish until 12000 then hold for next joined delay to end at 15000, so 3000 more.
// //       TrDelay<7000>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>, //after 15000 (TrConcat makes it 8000 + 7000) from effect start, full blade to this shade of white for wiping away (seamless color from end of stripes fade to solid)
// //       TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>, // wipe ice away and melt to thinner opacity , but not 100%, leave like 30% by using longer fade duration than the wipe takes. 
// //     TransitionEffectL<TrConcat<
// //       TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,     Int<400>,  Int<50>, Int<1000>,Int<0>>,    // burst
// //         TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,      Int<15000>,Int<400>,Int<8000>,Int<0>>,         // leading freeze edge
// //         TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,    // crystalizing in edge's wake
// //     AlphaL<Rgb<100,200,255>,Int<0>>,
// //       TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,    Int<300>,  Int<50>, Int<1000>,Int<0>>,  // burst
// //         TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>, // crystalizing in thaw's path
// //         TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,     Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>, // leading thawing edge
// //     // Dim Blade 50% "Power Save" button combo
// //     EffectSequence<EFFECT_POWERSAVE,
// //         AlphaL<Black,Int<16384>>,
// //         AlphaL<Black,Int<0>>>,
// //     // Clash 2 - for red blades
// //     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// //     // Stab - OrangeRed stripes
// //     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// //     // Blast v1
// //     TransitionEffectL<TrConcat<
// //         // Impact Flash - BC always
// //         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
// //         // Waves
// //         BlastL<Rgb<100,200,255>,850,250,351>,
// //         // Impact point afterimage
// //         //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
// //         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
// //         // Impact point
// //         //BlastL<Rgb<100,200,255>,500,350,100000>,
// //         BlastL<Rgb<100,200,255>,300,350,100000>,
// //     // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
// //     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// //     LockupTrL<Layers<
// //         //Random Strobe Flash no dimming
// //         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
// //         //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<2>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
// //         // Bottom Layer Bump - random width
// //         AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
// //         // Top Layer Bump - fixed width
// //         AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                              Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
// //         // Begin Lockup Transition
// //         TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,   Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
// //         // End Lockup Transition
// //         TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
// //     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                  Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
// //     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
// //     // Non-Responsive Drag - BC custom drag fadeout
// //     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// //     // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
// //     LockupTrL<Layers<
// //        //Random Strobe Flash and 16000 = 50% Base blade dimming to make lb pop
// //         AlphaL<Black,Int<16000>>,
// //         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
// //         AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
// //         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
// //         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
// //         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
// //         // Begin Lightning Transition
// //         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
// //         // End Lightning Transition    
// //         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// //     // Melt - BC custom melt effects, uses twistangle<>
// //     LockupTrL<
// //         AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
// //         // Melt Shape
// //         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
// //         // Melt Begin and End transitions
// //         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>, 
// // // standard
// //     // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // // BC_Bend
// //    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "the\nbane"},



// // { "a_BANE/RuleOfTwo;common;commonBU", "a_BANE/tracks/track3.wav", // AudioFlicker Red Base Color Wheel Changeable
   
// //   StylePtr<Layers<
// //     AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
// //     BC_effects_Red, 
// // // standard
// //     // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // // BC_Bend
// //    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "rule of\ntwo"},



// // { "a_SIDIOUS/TheReturn;common;commonBU", "tracks/Palpatheme_SHORT.wav",
// //   StylePtr<Layers<
// //     Mix<SwingSpeed<500>,AudioFlicker<Gradient<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red>,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,
// //     BC_effects_Red,       
// //       InOutTrL<TrConcat<TrWipe<200>,Strobe<Black,Rgb<100,100,155>,45,60>,TrJoinR<TrSmoothFade<190>,TrWipe<200>>>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// //   // On-Demand Battery Level
// //     AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
// //   >>(),    
// // "the return\nof the sith"},




// { "a_DOOKU/Duke;ProffieOS_Voicepack_Dooku/common;commonBU", "a_DOOKU/tracks/Duke1_Short.wav",
//   StylePtr<Layers<
//     AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<100>>,EFFECT_IGNITION>,
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// "dooku"},



// // { "a_DOOKU/Dooku_CW;common;commonBU", "a_DOOKU/tracks/Duke2_Short.wav",
// //   StylePtr<Layers<
// //     RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,BrownNoiseFlickerL<Rgb<100,50,50>,Int<100>>>>,
// //     BC_effects_Red,
// //     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Rgb<100,50,50>>,TrFade<500>>,EFFECT_RETRACTION>,
// // // standard
// //     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // // BC_Bend
// //    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// //     // AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "clone wars\ndooku"}, 



// // { "a_SAVAGE/Savage_Opress;common;commonBU", "tracks/Sister2_short.wav",
// // //Second Sister Base Red
// //   StylePtr<Layers<
// //     Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
// //     BC_effects_Red,
// //   // Ignition and Retraction
// //     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<100>>,EFFECT_IGNITION>,
// // // standard
// //     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Red,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // // BC_Bend
// //    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// //     // AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "savage\nopress"},



// // { "a_DARTH_MAUL/CrimsonMenace;common;commonBU", "a_DARTH_MAUL/tracks/Maul_Solo_Theme.wav", // AudioFlicker Red Base Color Wheel Changeable
   
// //   StylePtr<Layers<
// //     AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
// //     BC_effects_Red, 
// // // standard
// //     // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // // BC_Bend
// //    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "darth\nmaul"},



// // { "a_INQUISITOR/RevaUltimate;common;commonBU", "tracks/FallenOrderTracks/JFO9.wav",
// //   StylePtr<Layers<
// //     StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<20,0,0>>,RotateColorsX<Variation,Red>>,
// //     BC_effects_Red,
// //     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<White>,TrInstant>,EFFECT_RETRACTION>,
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<100>>,EFFECT_IGNITION>,
// //     InOutTrL<TrWipeSparkTip<Rgb<200,100,100>,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "reva\nltimate"},



// { "aa_Syndicate/SithChant;ProffieOS_Voicepack_Emperor/common;commonBU", "aa_Syndicate/SithChant/tracks/music_from_the_dark_side_edit.wav",
//   StylePtr<Layers<
//     Stripes<6000,-3000,RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<150,0,0>>>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<EFFECT_RETRACTION>,75>>,TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,25>>,AudioFlickerL<Rgb<128,128,128>>,TrInstant>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<Red,Black,500>,TrJoin<TrFade<1000>,TrWipe<800>>>,EFFECT_IGNITION>,
//     AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<228,128,128>,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
//     // AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// "sith\nchant"},



// { "a_STARKILLER/Secret_Apprentice;ProffieOS_Voicepack_Starkiller/common;commonBU", "a_STARKILLER/tracks/SKT4.wav", // AudioFlicker Red Base Color Wheel Changeable
   
//   StylePtr<Layers<
//     AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
//         // Ice Force
//     TransitionEffectL< 
//       TrConcat<TrFade<7000>,Rgb<10,0,75>,// blade turns solid cold 1000ms before ice full coverage
//       TrDelay<1000>>,EFFECT_USER2>,  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to Base color
//     TransitionEffectL< TrConcat<TrWipe<8000>, //wipe in stripes ice freezing effect
//     TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>,TrFade<11500>,TrDelay<20000>,EFFECT_USER2>, // Stripes fade to solid over remaining 4 seconds from freezing edge's finish until 12000 then hold for next joined delay to end at 15000, so 3000 more.
//       TrDelay<7000>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>, //after 15000 (TrConcat makes it 8000 + 7000) from effect start, full blade to this shade of white for wiping away (seamless color from end of stripes fade to solid)
//       TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>, // wipe ice away and melt to thinner opacity , but not 100%, leave like 30% by using longer fade duration than the wipe takes. 
//     TransitionEffectL<TrConcat<
//       TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,     Int<400>,  Int<50>, Int<1000>,Int<0>>,    // burst
//         TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,      Int<15000>,Int<400>,Int<8000>,Int<0>>,         // leading freeze edge
//         TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,    // crystalizing in edge's wake
//     AlphaL<Rgb<100,200,255>,Int<0>>,
//       TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,    Int<300>,  Int<50>, Int<1000>,Int<0>>,  // burst
//         TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>, // crystalizing in thaw's path
//         TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,     Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>, // leading thawing edge
//     // Dim Blade 50% "Power Save" button combo
//     EffectSequence<EFFECT_POWERSAVE,
//         AlphaL<Black,Int<16384>>,
//         AlphaL<Black,Int<0>>>,
//     // Clash 2 - for red blades
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Black,Red,20,20>,BrownNoiseFlicker<Rgb<100,200,255>,Black,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,Rgb<100,200,255>,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
//     // Stab - OrangeRed stripes
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
//     // Blast v1
//     TransitionEffectL<TrConcat<
//         // Impact Flash - BC always
//         TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
//         // Waves
//         BlastL<Rgb<100,200,255>,850,250,351>,
//         // Impact point afterimage
//         //AlphaL<TransitionEffectL<TrConcat<TrFade<200>,Red,TrFade<600>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
//         // Impact point
//         //BlastL<Rgb<100,200,255>,500,350,100000>,
//         BlastL<Rgb<100,200,255>,300,350,100000>,
//     // Lockup 2 - BC custom range mid-blade - Red or Yellow blade alt colors
//     TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
//     LockupTrL<Layers<
//         //Random Strobe Flash no dimming
//         AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
//         //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<2>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         // Bottom Layer Bump - random width
//         AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,                                    Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
//         // Top Layer Bump - fixed width
//         AlphaL<Strobe<White,BrownNoiseFlicker<White,Black,200>,50,30>,                                              Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
//         // Begin Lockup Transition
//         TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Orange,Black,500>,Black,15,30>,60,500>,   Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
//         // End Lockup Transition
//         TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                                  Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
//     TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<225>>,EFFECT_LOCKUP_BEGIN>,
//     // Non-Responsive Drag - BC custom drag fadeout
//     LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
//     // Lightning Block - Non-responsive. BC custom color (purple hint w/ random strobe flashes because....lightning)  
//     LockupTrL<Layers<
//        //Random Strobe Flash and 16000 = 50% Base blade dimming to make lb pop
//         AlphaL<Black,Int<16000>>,
//         AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<0>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
//         AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,LayerFunctions<
//         Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
//         Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
//         // Begin Lightning Transition
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
//         // End Lightning Transition    
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
//     // Melt - BC custom melt effects, uses twistangle<>
//     LockupTrL<
//         AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb<78,0,0>,Rgb<137,32,1>,150>,StyleFire<Rgb<80,0,0>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
//         // Melt Shape
//         SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
//         // Melt Begin and End transitions
//         TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>, 
// // standard
//     // InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// "starkiller"},



// { "aa_KSith/Aggression;ProffieOS_Voicepack_Ventress/common;commonBU", "tracks/FallenOrderTracks/JFO11a.wav", // colorchange 2 colors
//   StylePtr<Layers<
//     ColorChange<TrWipe<500>,StyleFire<BrownNoiseFlicker<Rgb<95,0,210>,RandomPerLEDFlicker<Rgb<42,0,105>,Rgb<21,0,52>>,300>,Rgb<10,0,26>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,StyleFire<Red,Rgb<60,0,0>,0,6,FireConfig<0,2000,5>,FireConfig<0,0,0>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>>,TrFade<1200>>,EFFECT_IGNITION>,
// // standard
//     // InOutTrL<TrWipeSparkTip<White,300>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<100,200,255>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// "starkiller"},



// // { "a_KYLO/KyloUltimate;common;commonBU", "a_KYLO/KyloUltimate/tracks/Kylo1.wav",
// //   StylePtr<Layers<
// //     StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
// //     BC_effects_Red,
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,150,150>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
// //     InOutTrL<TrWipe<400>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "kylo\nultimate"},    



// // { "a_REY/Empress;common;commonBU", "a_REY/tracks/DarkReyBC.wav",
// //   StylePtr<Layers<
// //     HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
// //     BC_effects_Red,
// //     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
// //     InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<White,Int<5000>,Int<50>,Int<300>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// //     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "empress"}, 



// // { "a_VADER/Father_V2/ANH;common;commonBU", "a_VADER/Father_V2/tracks/track1.wav",
// //   StylePtr<Layers<
// //     AudioFlicker<Red,Rgb<128,0,0>>,
// //     BC_effects_Red,
// //     InOutTrL<TrWipe<1000>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "father_v2\nanh"},



// { "aa_Greyscale/Seethe_Greyscale;ProffieOS_Voicepack_Din_Djarin/common;commonBU", "",
//   StylePtr<Layers<
//   // Red audioflicker
//     AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,0,0>>>,
//   // Force effect, temporarily allows a swing effect where solid dark orange takes over the blade when swinging
//     TransitionEffectL<TrConcat<TrFade<200>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,SwingSpeed<500>>,TrDelay<30000>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,SwingSpeed<500>>,TrFade<800>>,EFFECT_FORCE>,
//   // Unstable swing
//     AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>,SwingSpeed<315>>,
//   // Timed "breathing" emitter flare
//     Mix<Sin<Int<8>>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,Bump<Int<0>,Int<6000>>>,AlphaL<RotateColorsX<Variation,Rgb<255,45,0>>,Bump<Int<0>,Int<22000>>>>,
//     BC_effects_Red,
// // standard
//   // Wipe out ignition, wipe in retraction
//     // InOutTrL<TrWipe<2650>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
// // BC_Bend with surge
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// "seethe"},


// { "aa_Juansith/HATE;ProffieOS_Voicepack_Maul/common;commonBU", "",
// //Second Sister Base Red
//   StylePtr<Layers<
//     Mix<SwingSpeed<300>,AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,
//     BC_effects_Red,
//   // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<1000>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<1000>>,EFFECT_IGNITION>,
//     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
// // standard
//     // InOutTrL<TrJoin<TrWipeX<Int<300>>,TrWaveX<Rgb<150,0,0>,Int<5000>,Int<100>,Int<600>,Int<0>>>,TrWipeInX<WavLen<EFFECT_RETRACTION> >>,
// // BC_Bend
//    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// "hate"},



// // { "aa_Blueforce/IgnitionUltimate;ProffieOS_Voicepack_The_Ronin/common;commonBU", "",
// // StylePtr<Layers<
// //   Stripes<2000,-2500,RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<30,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,RotateColorsX<Variation,Rgb<30,0,0>>>>,
// //   TransitionLoopL<TrConcat<TrWaveX<RandomFlicker<RotateColorsX<Variation,Red>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<80,0,0>>,Black,300>>,Int<400>,Int<100>,Int<200>,Int<0>>,AlphaL<Red,Int<0>>,TrDelayX<Scale<SlowNoise<Int<1500>>,Int<200>,Int<1200>>>>>,
// //   AlphaL<BrownNoiseFlicker<Red,Black,300>,SwingSpeed<400>>,
// //   BC_effects_Red,
// //   InOutTrL<
// //     TrConcat<TrInstant,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrWipe<300>,Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,Black,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<255,20,0>>,White>,RotateColorsX<Variation,Rgb<128,34,0>>>,TrFade<300>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,20>,TrBoing<300,3>>,
// //     TrConcat<TrInstant,BrownNoiseFlicker<White,DarkOrange,300>,TrFade<250>,AlphaL<Black,Int<0>>,TrJoin<TrWipeInX<Int<850>>,TrWaveX<White,Int<800>,Int<400>,Int<850>,Int<32768>>>>>,
// // // Comment out this following line for non-stutter on actual ignition
// //   //TransitionEffectL<TrConcat<TrWaveX<White,Int<800>,Int<200>,Int<300>,Int<0>>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrDelay<650>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<20>,Black,TrDelay<100>,BrownNoiseFlicker<White,Red,70>,TrFade<500>,Black,TrInstant>,EFFECT_IGNITION>,
// //   TransitionEffectL<TrConcat<TrDelay<1100>,BrownNoiseFlicker<White,DarkOrange,300>,TrDelay<50>>,EFFECT_RETRACTION>,
// //   TransitionEffectL<TrConcat<
// //     TrInstant,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrFade<100>,Black,
// //     TrDelay<50>,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<50000>>>,TrDelay<150>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<70000>>>,TrFade<150>,Black,
// //     TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<400>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<450>,Black,
    
// //     TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<70000>>>,TrDelay<250>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<50000>>>,TrFade<200>,Black,
// //     TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<500>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<600>,Black,

// //     TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<10000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<5000>>>,TrFade<150>,Black,
// //     TrDelay<350>,Black,
// //     TrInstant,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<10000>>>,TrDelay<70>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<5000>>>,TrFade<40>,Black,
// //     TrDelay<20>,Black,

// //     TrInstant,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrDelay<50>,AlphaL<BrownNoiseFlicker<Red,Black,100>,Bump<Int<0>,Int<30000>>>,TrFade<50>,Black,
// //     TrDelay<50>,AlphaL<BrownNoiseFlicker<White,Black,100>,Bump<Int<0>,Int<50000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<70000>>>,TrFade<150>,Black,
// //     TrFade<100>,AlphaL<BrownNoiseFlicker<Rgb<255,100,100>,Black,40>,Bump<Int<0>,Int<40000>>>,TrFade<300>,AlphaL<BrownNoiseFlicker<Red,Black,40>,Bump<Int<0>,Int<20000>>>,TrFade<400>,

// //     AlphaL<BrownNoiseFlicker<White,Red,100>,Bump<Int<0>,Int<10000>>>,
// //     TrFade<175>,AlphaL<BrownNoiseFlicker<White,DarkOrange,300>,Bump<Int<0>,Int<20000>>>,TrFade<175>,AlphaL<BrownNoiseFlicker<White,Red,100>,Bump<Int<0>,Int<10000>>>,
// //     TrFade<115>,AlphaL<BrownNoiseFlicker<White,DarkOrange,100>,Bump<Int<0>,Int<40000>>>,TrFade<115>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<20000>>>,
// //     TrFade<100>,AlphaL<BrownNoiseFlicker<White,DarkOrange,100>,Bump<Int<0>,Int<60000>>>,TrFade<100>,AlphaL<BrownNoiseFlicker<White,Red,300>,Bump<Int<0>,Int<40000>>>,
// //     TrFade<75>,BrownNoiseFlicker<White,DarkOrange,300>,TrFade<50>,Black,TrFade<50>,BrownNoiseFlicker<RotateColorsX<Variation,Red>,Rgb<200,150,150>,20>,
// //     TrSmoothFade<100>>,EFFECT_PREON>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "ignition\nultimate"},


// // { "aa_HarrySolo/AGONY;ProffieOS_Voicepack_Mace/common;commonBU", "",
// //   StylePtr<Layers<
// //     HumpFlicker<Blue,Stripes<22000,-100,RotateColorsX<Variation,Rgb<48,0,105>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<22,0,49>>>,10>,
// //     BC_effects_Red,
// //     InOutTrL<TrJoin<TrWipeX<Int<600>>,TrWaveX<White,Int<1200>,Int<400>,Int<600>,Int<0>>>,
// //              TrJoin<TrWipeInX<WavLen<EFFECT_RETRACTION>>,TrWaveX<White,Percentage<WavLen<EFFECT_RETRACTION>,150>,Int<400>,WavLen<EFFECT_RETRACTION>,Int<32768>>>>,
     
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<200>>,EFFECT_IGNITION>,
// //     AlphaL<TransitionEffectL<TrConcat<TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,10>,Bump<Int<0>,Int<4000>>>,TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,15>,Bump<Int<0>,Int<5000>>>,TrFade<1500>,AlphaL<HumpFlickerL<Rgb<120,120,165>,20>,Bump<Int<0>,Int<6000>>>,TrFade<1000>>,EFFECT_PREON>,Ifon<Int<0>,Int<32768>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "agony"},


// { "aa_KSith/Proto;ProffieOS_Voicepack_Malgus/common;commonBU", "",
//   StylePtr<Layers<
// // Main Blade
//     // Jedi Base Orange
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,DarkOrange>,Pulsing<RotateColorsX<Variation,Rgb<90,24,0>>,RotateColorsX<Variation,DarkOrange>,800>,RotateColorsX<Variation,DarkOrange>>,
//     // Jedi Force Orange
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<160,43,0>>>,TrDelay<3000>,RotateColorsX<Variation,DarkOrange>,TrFade<800>>,EFFECT_FORCE>,
//     // Jedi Swing Orange
//     AlphaL<RotateColorsX<Variation,Rgb<255,178,110>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//     BC_effects_1,
// // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// "proto"},




// { "aa_KSith/Desolation;ProffieOS_Voicepack_Savage/common;commonBU", "tracks/FallenOrderTracks/JFO12.wav",
//   StylePtr<Layers<
// // Main Blade
//     // Jedi base Yellow
//     StripesX<Int<16000>,Int<-1000>,RotateColorsX<Variation,Rgb<180,180,0>>,Pulsing<RotateColorsX<Variation,Rgb<64,64,0>>,RotateColorsX<Variation,Rgb<180,180,0>>,800>,RotateColorsX<Variation,Rgb<180,180,0>>>,
//     // Jedi Force Yellow
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<113,113,0>>>,TrDelay<3000>,RotateColorsX<Variation,Rgb<180,180,0>>,TrFade<800>>,EFFECT_FORCE>,
//     // Jedi Swing Yellow
//     AlphaL<RotateColorsX<Variation,Rgb<230,180,80>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// BC_effects_Red,
// // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Yellow,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// "desolation"},




// { "aa_KSith/Ascension;ProffieOS_Voicepack_Kanan/common;commonBU", "tracks/battleofheros.wav",
//   StylePtr<Layers<
//     StripesX<Int<3000>,Int<-3000>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,60>>,RotateColorsX<Variation,Rgb<50,50,255>>,RotateColorsX<Variation,Rgb<0,0,128>>>,
//     AlphaL<Rgb<100,100,255>,SwingSpeed<600>>,
//     BC_effects_1,
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<100,200,255>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// "ascension"},



// // { "Arcane;ProffieOS_Voicepack_C-3PO/common;commonBU", "",
// //   StylePtr<Layers<
// //     HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,15>,
// //     BC_effects_Red,
// //     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
// //   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// //     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "arcane"}, 



// { "aa_KSith/Traveler;ProffieOS_Voicepack_Kota/common;commonBU", "tracks/FallenOrderTracks/JFO3.wav",
//   StylePtr<Layers<
//     Mix<SwingSpeed<500>,AudioFlicker<Gradient<Gradient<BrownNoiseFlicker<Black,Orange,400>,Red>,Red,Red,Red,Red,Red,Red,Red>,Rgb<120,0,0>>,Gradient<BrownNoiseFlicker<Black,DarkOrange,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>,BrownNoiseFlicker<Black,Rgb<128,0,0>,400>>>,
//     BC_effects_Red,       
//     InOutTrL<TrConcat<TrWipe<200>,Strobe<Black,Rgb<100,100,155>,45,60>,TrJoinR<TrSmoothFade<190>,TrWipe<200>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// "traveler"},




// // { "GhostsOfTheGrey;ProffieOS_Voicepack_The_Ronin/common;commonBU", "", 
// //   StylePtr<Layers<
// //     StripesX<Int<6000>,Int<-1000>,RotateColorsX<Variation,Rgb<50,50,75>>,RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<24,24,35>>>,AlphaL<White,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// //     AlphaL<Stripes<4000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Black>,White,RotateColorsX<Variation,Rgb<100,100,150>>,White>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// //     BC_effects_White,  
// //     InOutTrL<TrWipe<400>,TrConcat<TrFadeX<Percentage<WavLen<EFFECT_RETRACTION>,50>>,Stripes<3000,2000,White,Rgb<100,100,100>>,TrFadeX< Percentage<WavLen<EFFECT_RETRACTION>,50> >>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "ghosts of\nthe grey"},   


// { "aa_LordBlako/PitchBlk;ProffieOS_Voicepack_Starkiller/common;commonBU", "tracks/MSV.wav",
// //Second Sister Base Red
//   StylePtr<Layers<
//     Mix<SwingSpeed<300>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<25,0,0>>,Black>,300>,RotateColorsX<Variation,Rgb<40,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,AudioFlicker<RotateColorsX<Variation,Rgb<200,0,0>>,RotateColorsX<Variation,Rgb<20,0,0>>>>,
//     BC_effects_Red,
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<Rgb<100,200,255>>,TrFade<1000>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Rgb<100,200,255>,50>,TrFade<1000>>,EFFECT_IGNITION>,
//     // AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<1800>>,Int<22000>,Int<40000>>,Int<24000>>>, // Black cooling tip.....meh
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<Rgb<100,200,255>,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//     AlphaL<TransitionEffectL<TrConcat<TrFade<3000>,AlphaL<Pulsing<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Red>,350>,Bump<Int<0>,Int<7000>>>,TrInstant>,EFFECT_PREON>,Scale<Trigger<EFFECT_IGNITION,Int<1>,Int<5000>,Int<1>>,Int<32768>,Int<0>>>,
// // Emitter cooldown
//     TransitionEffectL<TrConcat<TrInstant,
//       AlphaL<Rgb<100,200,255>,Bump<Int<0>,Int<6000>>>,TrFadeX<  Int<1875> >,
//       AlphaL<Orange,Bump<Int<0>,Int<4000>>>,TrFadeX<  Int<1875> >,
//       AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX< Int<3750> >>,EFFECT_RETRACTION>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// "pitch\nblack"},



// // { "a_PONG_KRELL/PongKrll;ProffieOS_Voicepack_The_Ronin/common;commonBU", "a_PONG_KRELL/tracks/Krell.wav",
// //   StylePtr<Layers<
// //     Pulsing<Yellow,Chartreuse,20>,
// //     BC_effects_1,
// //     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
// //     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
// //     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// //   "pong\nkrell"},


// // { "Proto2;ProffieOS_Voicepack_The_Ronin/common;commonBU", "Proto2/tracks/proto2.wav", // Color Cycle to Glitchy Pulsing Blade Default = Green
// //   StylePtr<Layers<   
// //       ColorCycle<RotateColorsX<Variation,Rgb<0,128,0>>,100,-3250,RotateColorsX<Variation,BlinkingX<RandomFlicker<RandomBlink<13000,RotateColorsX<Variation,Rgb<128,200,128>>,RotateColorsX<Variation,Black>>,RotateColorsX<Variation,Green>>,RandomFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<30,30,30>>>,Scale<SlowNoise<Int<16000>>,Int<300>,Int<1000>>,Scale<SlowNoise<Int<16000>>,Int<200>,Int<650>>>>,50,3000,3000>,
// //       BC_effects_1,
// //       TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
// //       TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
// //       InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// //   // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "proto 2"},




// { "PsyBorg;ProffieOS_Voicepack_The_Ronin/common;commonBU", "tracks/FallenOrderTracks/JFO7.wav",
//   StylePtr<Layers<
// // Main Blade - variation applied 21844 (green)
//     // Jedi base Blue
// StripesX<Int<16000>,Int<-1000>,RotateColorsX<Int<21844>,Blue>,Pulsing<RotateColorsX<Int<21844>,Rgb<0,0,90>>,RotateColorsX<Int<21844>,Blue>,800>,RotateColorsX<Int<21844>,Blue>>,
//     // Jedi Force Blue
//     TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,160>>>,TrDelay<3000>,RotateColorsX<Variation,Blue>,TrFade<800>>,EFFECT_FORCE>,
//     // Jedi Swing Blue
//     AlphaL<RotateColorsX<Variation,Rgb<70,70,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
// BC_effects_1,
// // Ignition and Retraction
//     TransitionEffectL<TrConcat<TrFade<300>,AudioFlickerL<White>,TrFade<500>>,EFFECT_RETRACTION>,
//     TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,50>,TrFade<500>>,EFFECT_IGNITION>,
//     InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),

// "psyborg"},



// // { "a_DARKSABER/DarkV3;ProffieOS_Voicepack_The_Ronin/common;commonBU", "a_DARKSABER/DarkV3/tracks/Mandalorian.wav",
// //   StylePtr<Layers<
// //     Mix<SwingSpeed<400>,RotateColorsX<Variation,Rgb<80,100,150>>,RotateColorsX<Variation,Rgb<130,150,225>>>,
// //     BrownNoiseFlickerL<Stripes<5000,-300,RotateColorsX<Variation,Rgb<15,25,55>>,RotateColorsX<Variation,Rgb<60,75,120>>,RotateColorsX<Variation,Rgb<0,10,20>>,RotateColorsX<Variation,Rgb<40,50,75>>>,Int<38400>>,
// //     AudioFlickerL<RotateColorsX<Variation,Rgb<25,35,75>>>,
// //     AlphaL<RotateColorsX<Variation,Rgb<155,175,225>>,SwingSpeed<600>>,
// //     BC_effects_White,
// //    // InOutTrL<TrWipeSparkTipX<White,BendTimePowInvX<Int<1000>,Int<180000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// //    InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1800>,Int<235000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1800>,Int<210000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
// //      // On-Demand
// //     OnDemandVolumeLevel,
// //     OnDemandBatteryLevel
// //   >>(),
// // "   dark\n    v3"},




     

};


BladeConfig blades[] = {

// { NO_BLADE,
//   // Carl Chen Emitter PCB only
//   SubBlade(4,7, WS281XBladePtr<8, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >()),
//   SubBlade(0,3,NULL),
//   CONFIGARRAY(Ronin),
// "00_noblade_save"},

{ NO_BLADE,
  // Carl Chen Emitter PCB only
  WS281XBladePtr<8, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  CONFIGARRAY(Ronin),
"00_noblade_save"},

// { 6500,
//   // Carl Chen Emitter PCB and Main Blade in parallel
//   WS281XBladePtr<128, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
//   CONFIGARRAY(Ronin),
// "01_Ronin_save"},


{ 6400,  // Darkwolf courtesy blade
  // Carl Chen Emitter PCB and Main Blade in parallel
  WS281XBladePtr<110, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  CONFIGARRAY(Ronin),
"01_Ronin_save"},

};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

// #ifdef CONFIG_BOTTOM
// struct Script : Looper, StateMachine {
//   const char* name() override { return "script"; }
//   void Loop() override {
//     STATE_MACHINE_BEGIN();
//     while (true) {
//       CommandParser::DoParse("on", nullptr);
//       SLEEP(3000);
//       CommandParser::DoParse("clash", nullptr);
//       SLEEP(1000);
//       CommandParser::DoParse("clash", nullptr);
//       SLEEP(4000);
//       CommandParser::DoParse("blast", nullptr);
//       SLEEP(400);
//       CommandParser::DoParse("blast", nullptr);
//       SLEEP(400);
//       CommandParser::DoParse("blast", nullptr);
//       SLEEP(400);
//       CommandParser::DoParse("blast", nullptr);
//       SLEEP(4000);
//       CommandParser::DoParse("lock", nullptr);
//       SLEEP(2500);
//       CommandParser::DoParse("lock", nullptr);
//       SLEEP(4000);
//       CommandParser::DoParse("off", nullptr);
//       SLEEP(4000);
//     }
//     STATE_MACHINE_END();
//   }
// };
// Script script;
// #endif


// // Button connect to 3.3v(+) instead of GND. Up to 5v is OK
// PullDownButton PowerButton(BUTTON_POWER, powerButtonPin, "pow"); // isn't this backwards?

// // Analog Potentiometer 
// ChangeVolumeAnalogReceiver volume_function;
// PotClass pot(0, &volume_function);

// // Or, you can use it to change the variation (color):

// ChangeVariationAnalogReceiver variation_function;
// PotClass pot(0, &variation_function);

// // Rotary Encoder

// ChangePresetRotaryReceiver rotary_receiver;
// Rotary<8, 9> rotary(&rotary_receiver);
/*
The receiver decides what the rotary events do.
There are currently receivers for changing presets, 
changing variation and one that just prints things out. 
More receivers can be added as needed. 
(I should probably create one for changing the volume.)
*/

// Support for 128x64 OLED
// #ifdef CONFIG_BOTTOM
// SSD1306Template<128, uint64_t> display(0x3C);
// #endif

