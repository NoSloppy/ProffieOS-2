/*
// BC_Bane_MK2_Black_fun_7.x
// Happy 50th SeanZAAAAAAYYYY!!!!


   // BC Personal Version for OS7.x

saber_BC_buttons.h
  http://fredrik.hubbe.net/lightsaber/proffieos.html
  Copyright (c) 2016-2019 Fredrik Hubinette
  Copyright (c) 2023 Brian Conner with contributions by:
  Fredrik Hubinette, Fernando da Rosa, Matthew McGeary, and Scott Weber.
  Distributed under the terms of the GNU General Public License v3.
  http://www.gnu.org/licenses/

Includes 1 and 2 button controls.
Incorporates an intuitive control scheme so button actions are consistant
whether blade is on or off.
Best if used with OS6 ProffieOS_Voicepack spoken menu prompts.
Download your choice of language and variation here:
http://fredrik.hubbe.net/lightsaber/sound/

Features:
- Live preset changing while blade is running (skips font.wav and preon).
- Battle Mode, gesture ignitions, and multi-blast based on fett263's work.
- Auto enter/exit multi-blaster block mode 
- Spoken Battery level in volts OR percentage. Both always available.
- Dedicated Quote sounds - Always available. force.wavs can remain as force.
                           Add quote.wav files to font to use.
                           Live toggle between seqential or random quote play.
- Play / Stop track control while blade is on.
- Force Push is always available, not just in Battle Mode.
- Melt is always available as no button, with pull-away or button to end.
- Drag is always clash with button pressed while pointing down.
- No blade inserted = no gestures option if Blade Detect is used.
- Optional On-the-fly volume controls with Quick MIN and MAX levels.
- Bypass preon and/or postoff based on blade angle.
- Spam Blast - Enter this mode to make the button super sensitive for
                          multiple blaster blocks. Presses are prioritized over
                          other features. No limits, no lag when "rapid firing".
- Swap feature with sound - Just an additional EFFECT that can be used to trigger
                            blade animations. See below.
// BC PERSONAL Version only --------------------------------------------------------
// - Alt blade independent ignition and retraction (such as for a staff saber.)               // BC personal only

---------------------------------------------------------------------------
Optional Blade style elements:
On-Demand battery level - A layer built into the blade styles that reacts
                          as the battery gets weaker, changing blade color
                          from Green to Red, and the blade length shortens.
EFFECT_USER1            - Swap feature: Use as a standalone trigger for EffectSequence<>,
                          for example as a way to have multiple blade styles in one preset.
                          Usage:EffectSequence<EFFECT_USER1, item1, item2...>
                          Custom swap.wav files can be used as the sound effect,
                          otherwise ccchange.wav is used.
EFFECT_USER2            - For blade effects with sounds that might work better without hum,
                          this plays sounds monophonically.
                          (think seismic charge silence, iceblade etc...)
                          monosfx.wav files are used. It can be just the sound, or a
                          blade effect too by using EFFECT_USER2 in a TransitionEffectL.
// BC PERSONAL Version only --------------------------------------------------------
// EFFECT_USER3            - for Rave glowstick, instead of preon.
// ---------------------------------------------------------------------------------
Optional #defines:

#define BC_ENABLE_AUTO_SWING_BLAST - Multi-blast initiated by simply swinging
                                  within 1 second of last blast.
                                  Exit by not swinging for 1 second.
#define FEMALE_TALKIE_VOICE     - To use a female voice version of onboard Talkie.

Gesture Controls:
- There are four gesture types: swing, stab, thrust and twist.
  For simplicity, using gesture ignition will automatically skip the preon effect.
  Below are the options to add to the config to enable the various gestures.
#define BC_SWING_ON
#define BC_STAB_ON
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF


#define BC_FORCE_PUSH
- This mode plays a force sound (or force push sound if the font contains push.wav) with
  a controlled pushing gesture, and is always available, not just in Battle Mode.

#define BC_FORCE_PUSH_LENGTH
- Used for adjustment to the Push gesture length in millis needed to trigger
  Force Push. Recommended range 1 ~ 10,
  1 = shortest, easiest to trigger, 10 = longest. Default value is 5.

#define BC_NO_BM
- Disable battle mode features.

#define BC_GESTURE_AUTO_BATTLE_MODE
- Makes gesture ignition ALSO enter battle mode automatically on ignition.
- *Note* - Cannot be used if #define BC_NO_BM is active.

"Battle Mode 1.0" by fett263, BC modified version:
- Once you enter battle mode, buttons are not used for lockup.
  Clashing the blade against something will automatically do lockup and then end
  when you pull away.
- Automatic lockup and grazing clash (swinging through) detection works
  by measuring delay of the saber blade pulling back from the clash.
  If you clash the blade and it does not pull back during the delay period,
  it is assumed to be a lockup and the lockup effect will show on the blade.
  If you clash the blade and pull away, only the bgn/end lockup effects will show.
  You can adjust the threshold of this detection by using:
#define BC_LOCKUP_DELAY (insert number here)
  Default value is 200.
  If you don't rebound off the object (opponent's blade) but instead clash while
  swinging through, clash will automatically trigger.
- To manually override the auto-lockup temporarily and get a regular clash,
  hold any button while clashing.
- Automatic clash/lockup uses the bgnlock and endlock effects
  so your blade style and font MUST have those capabilities to support
  battle mode.

- Melt will automatically trigger with no buttons when you physically
  stab something, and end when you pull away or push any button.

- Stab will trigger with no buttons and thrusting forward.

====================== 1 BUTTON CONTROLS ========================
| Sorted by ON or OFF state: (what it's like while using saber) |
=================================================================

*************   WHILE SABER BLADE IS OFF   ***************
Turn blade ON         - Short click POW. (BC Personal: or shake.) (or gestures if defined, uses FastOn)
                        * NOTE * Gesture ignitions using FastOn bypass preon.
Turn ON without preon - Short click POW while pointing up.
Turn blade ON Muted   - 4x click and hold POW.
Next Preset           - Long click and release POW.
Prev Preset           - Double click and hold POW, release after a second (click then long click).
Play/Stop Track       - 4x click POW.
Volume Menu:
                      * NOTE * Tilting blade too high or low in Volume Menu will give a warning tone to
                        tilt up or down to avoid erratic rotational volume changes at extreme blade angles.        
        Enter/Exit    - Hold POW + Clash.
        Volume UP     - Rotate Right
                      - or -
                      - Long click and release POW while in Volume Menu. (just like next preset)
        Volume DOWN   - Rotate Left
                      - or -
                      - Double click and hold POW, release after a second while in Volume Menu.
                        (click then long click, just like next preset)
        Quick MAX Vol - Short click POW while in Volume Menu.
        Quick MIN Vol - Double click POW while in Volume Menu.
Spoken Battery Level
        in volts      - Triple click POW.
        in percentage - Triple click and hold POW.
On-Demand Batt Level  - Double click POW.
                        (requires EFFECT_BATTERY_LEVEL to be in blade style,
                        and uses battery.wav sound effect.)
Rave glowstick        - Clash while OFF to crack the glowstick, shake to start the party!   // BC personal only

*************   WHILE SABER BLADE IS ON   ****************
Play/Stop Track       - 4x click POW.
Next Preset Fast      - Long click and release POW while pointing up.
Prev Preset Fast      - Double click and hold POW, release after a second while pointing up. (click then long click)
                        * NOTE * Fast switching bypasses preon and font.wav.
Clash                 - No buttons, just hit the blade against something.
                        In Battle Mode, Hold POW and Clash to temporarily
                        override the auto-lockup and do regular Clash.
Stab                  - Just Thrust forward with a stabbing motion.
                        Works in Battle Mode.
Blaster Blocks        - Click or Double click POW.
Spam Blaster Blocks   - 3x click and hold while pointing up. This toggles SPAM BLAST mode ON/OFF,
                        and makes the button super sensitive for multiple blaster blocks.
                        * Note * This gets in the way of normal features,
                        so turn off when you're done spamming.  Plays mzoom.wav.
Auto Swing Blast      - if #define BC_ENABLE_AUTO_SWING_BLAST is active,
                        swinging within 1 second of doing a button activated
                        Blaster Block will start this timed mode.
                        To trigger auto blaster blocks, swing saber
                        within 1 second of last Swing Blast block.
                        To exit, stop swinging for 1 second.
Lockup                - Hold POW + Clash.
                        In Battle Mode, just Clash and stay there,
                        pull away or press POW to end lockup.
Drag                  - Hold POW + Clash while pointing down.
Melt                  - No button, just stab something. pull away or
                        press POW to end.
Lightning Block       - Double click and hold POW.
Battle Mode           - Triple click and hold POW to enter and exit.
                        Power OFF is disabled while in Battle Mode,
                        YOU MUST EXIT THE MODE WITH THIS COMBO FIRST.
Force Effect          - Hold POW + Twist while NOT pointing up or down.
Monophonic Force      - Hold POW + Twist while pointing up.
Color Change Mode     - Hold POW + Twist while pointing down.
                          Rotate hilt to cycle through available colors.
                          Click + hold POW to save color selection and exit.
                          Triple click POW to exit while restoring original color.
    ColorChange explained:
    If RotateColorsX<Variation,COLOR> is used in the blade style:
        Rotate hilt to cycle through all available colors, 
        Hold POW to save color selection and exit.
    If ColorChange<> is used in the blade style:
        There are up to 12 colors per rotation with a ccchange.wav sound at each step.
        If also using #define COLOR_CHANGE_DIRECT in the config,
        simply entering Color Change Mode will select the next color in the list and exit Color Change Mode.
Quote Player          - Triple click POW.
Toggle sequential or
  random quote play   - 4x click and hold POW. (while pointing down)
Force Push            - Push hilt perpendicularly from a stop.
Swap (EffectSequence) - 4x click and hold POW. (while NOT pointing up)
                        * Requires EFFECT_USER1 in blade style.
PowerSave Dim Blade   - 4x click and hold POW. (while pointing up)
                        To use Power Save requires AlphaL based EffectSequence<> in style.
Turn OFF blades   - Hold POW and wait until blade is off,
                        or do Twist if using #define BC_TWIST_OFF.
Turn OFF without postoff - Turn OFF while pointing up.

*/
#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 1

// ------ Audio Stuff --------

#define VOLUME 1800
#define BOOT_VOLUME 300
#define ENABLE_AUDIO
// #define FILTER_CUTOFF_FREQUENCY 100
// #define FILTER_ORDER 8
// #define FEMALE_TALKIE_VOICE
#define NO_REPEAT_RANDOM
#define KILL_OLD_PLAYERS
// #define DISABLE_TALKIE

// ------ Blade Stuff ------

#define ENABLE_WS2811
const unsigned int maxLedsPerStrip = 144;

//    New define that can speed up processing a bit. Basically, it can calculate the colors for the next
//    blade (or the next frame for the same blade) even though it's not done feeding out the data for the
//    data in the color buffer yet. Equivalent to just increasing maxLedsPerStrip.
#define EXTRA_COLOR_BUFFER_SPACE 30

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
// #define REAL_TIME_BLADE_ID_PINS 2,3

  //    Use with Blade ID. Specify the LED pad(s) that the main blade uses.
  // #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>

  //    Required when blades on different data pads use common LED power pads.
  //    and/or when BLADE_ID_SCAN_MILLIS is used with Blade ID.
  // #define SHARED_POWER_PINS

  //    Choose how often to check for new blade (milliseconds).
  //    Larger values will be a longer delay before a blade is recognized.
  // #define BLADE_ID_SCAN_MILLIS 

  //    How many Blade ID scans to average (default is 10, works well)
  // #define BLADE_ID_TIMES 15

// ------ SD Card Stuff -------

#define ENABLE_SD
//    Blanket define to cover the following 4
//#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    #define SAVE_COLOR_CHANGE
    // #define SAVE_BLADE_DIMMING
//    presets.ini/tmp is ignored after reprogramming unless this is defined.
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING 

// ------ System Stuff --------

// #define DIAGNOSTIC_STARTUP_DELAY_FOR_SERIAL_MONITOR
// #define ENABLE_DEBUG
// #define PROFFIEOS_LOG_LEVEL 300
//    PVLOG_ERROR 100 = errors
//    PVLOG_STATUS 200 = things you should probably know, like blade ID
//    PVLOG_NORMAL 300 = normal information about what is happening (default level)
//    PVLOG_DEBUG 400 = information helpful for debugging
//    PVLOG_VERBOSE 500 = repeated, spammy information you don't normally want
// #define PROFFIEOS_LOG_LEVEL 300

// #define ENABLE_DEVELOPER_COMMANDS
 #define DISABLE_DIAGNOSTIC_COMMANDS
//    Disable Old School original templated styles, like StyleNormalPtr<CYAN, WHITE, 300, 800>()
#define DISABLE_BASIC_PARSER_STYLES
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000

// ------- Motion and Gesture stuff -------

#define ENABLE_MOTION
#define CLASH_THRESHOLD_G 3.5
#define BC_SWING_ON
#define BC_SWING_ON_SPEED 600 // Default 250
// #define BC_STAB_ON
#define BC_THRUST_ON
//#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
//    BC Multiblast continues as long as swinging within 1 second. 
#define BC_ENABLE_AUTO_SWING_BLAST
#define ENABLE_SPINS
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200

#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_personal.h"
#endif

#ifdef CONFIG_PRESETS
#include "aliases/TrueWhites/BC_effects_1.h"
#include "aliases/TrueWhites/BC_effects_Red.h"
#include "aliases/TrueWhites/BC_effects_White.h"
#include "aliases/TrueWhites/BC_12color_8effect_SS.h"

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrExtendX<Int<1000>,TrSmoothFade<200>>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

/* ---- Presets list ----/*

BC_Bane_MK2_Black_fun_7.x.h config file
* NO CW = single color, no colorwheel

--- blade in ---
aa_NoSloppy/Crushed
aa_NoSloppy/Rave
aa_NoSloppyTheMaw - Ice monosfx
aa_JayDalorian/Kyber_Weapon - BC_12color_8effect_SS
// aa_HarrySolo/WORKBENCH
a_SHIPS/Slave1_2.1_Proffie
aa_BK/Party_Foul
Fire
--- no blade ---
Calibr8
RootCore
*/


Preset bladein [] = {


{ "aa_NoSloppy/Crushed;common;commonBU", "",
// NoSloppy 06/2022
StylePtr<Layers<
  BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
  Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>,
  AlphaL<StaticFire<Black,BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,600>,0,4,2,4000,0>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<500>,Int<-19300>,Int<32768>>,Int<0>>>,
  BC_effects_Red,
  // Ignition and Retraction effect
  // InOutTrL<TrJoin<TrWipeX<BendTimePowX<Int<1300>,Int<16384>>>,TrSparkX<White,Int<400>,BendTimePowX<Int<1300>,Int<16384>>,Int<0>>>,
  //                 TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<150000>>>>,
  InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,
                    TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // Postoff Emitter Cooldown
  TransitionEffectL<TrConcat<TrInstant,AlphaL<Rgb16<22863,5695,53231>,Bump<Int<0>,Int<3500>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Red,Bump<Int<0>,Int<2000>>>,TrFadeX<Percentage<WavLen<>,25>>,AlphaL<Rgb<100,0,0>,Bump<Int<0>,Int<1000>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
  // Preon effects - auto matched to which wav file is chosen
 AlphaL<ColorSelect<WavNum<EFFECT_PREON>,TrInstant,
  Layers<
    TransitionEffectL<TrConcat<TrDelay<200>,AlphaL<Black,Int<0>>,TrFade<1300>,Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Rgb<180,0,0>>,RotateColorsX<Variation,Rgb<15,0,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>>,RotateColorsX<Variation,Rgb<40,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<36,0,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Rgb<180,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<90,0,0>>,RotateColorsX<Variation,Rgb<5,2,0>>,3000>>,
    AlphaL<StyleFire<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<2,1,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>>,TrDelay<1000>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrFade<1500>,SparkleL<ColorSelect<Sin<Int<1>,Int<68>>,TrFade<300>,Red,Rgb16<22863,5695,53231>,White>,200,500>,TrDelay<1000>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<Black,Int<0>>,TrFade<800>,AlphaL<StaticFire<Black,Rgb16<22863,5695,53231>,0,3,0,6000>,Bump<Int<0>,Int<5000>>>,TrInstant,AlphaL<AlphaL<White,NoisySoundLevelCompat>,Bump<Int<0>,Int<25000>>>,TrDelay<700>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<1000>,AlphaL<Black,Int<0>>,TrFade<700>,AlphaL<StaticFire<Black,Rgb16<22863,5695,53231>,0,3,0,3000>,Int<16000>>,TrDelay<700>>,EFFECT_PREON>>,
  Layers<
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<5000>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<9830>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<14745>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<19660>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<24576>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<29491>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>,AlphaL<Layers<
    BrownNoiseFlicker<Black,Rgb16<22863,5695,53231>,50>,
    Pulsing<PulsingL<Rgb16<22863,5695,53231>,Int<800>>,Red,1900>>,SmoothStep<Int<32768>,Int<-1>>>,TrDelay<55>,Black,TrDelay<56>>,EFFECT_PREON>>>,Ifon<Int<0>,Int<32768>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Switch
  StylePtr<Layers<
    Rgb<100,100,100>,
    InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
  >>(),
"crushed"},



{ "aa_NoSloppy/Rave;common;commonBU", "",
    // Rave blade style v1 - Clash while OFF to crack the glowstick, shake to start the party!
  StylePtr<Layers<Black,
    AlphaL<Layers<
    AudioFlicker<GreenYellow,AlphaL<Black,Int<10000>>>,
    TransitionLoopL<TrConcat<TrInstant,Rgb<100,200,255>,TrDelay<50>,AlphaL<Black,Int<0>>,TrDelay<360>>>,
    TransitionLoopL<TrConcat<TrInstant,AlphaL<Green,SmoothStep<Int<30000>,Int<0>>>,TrDelay<180>,AlphaL<Green,SmoothStep<Int<2000>,Int<-1>>>,TrDelay<180>>>>,Ifon<Int<32768>,Int<0>>>,
// Clash
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// Stab From EVO
    TransitionEffectL<TrConcat<TrWipeIn<350>,Mix<Bump<Int<32768>,Int<16000>>,Gradient<Blue,Blue,DodgerBlue,DeepSkyBlue,Rgb<100,200,255>>,BrownNoiseFlicker<Yellow,Strobe<Strobe<Blue,Rgb<100,200,255>,15,20>,GreenYellow,10,10>,500>>,TrFade<800>>,EFFECT_STAB>,
// Blast - for Rgb<100,200,255> blades
    TransitionEffectL<TrConcat<TrInstant,Red,TrDelay<25>>,EFFECT_BLAST>,
    BlastL<ColorSequence<400,Red,Green,Blue,Rgb<100,200,255>,Black>,850,250,351>,
    AlphaL<TransitionEffectL<TrConcat<TrDelay<300>,Red,TrFade<500>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
    BlastL<Rgb<100,200,255>,500,300,100000>,
// Lockup - BC custom range mid-blade - Red blade alt colors
    LockupTrL<Layers<
      AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<Rgb<100,200,255>,Blue,300>,30,20>,            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
      AlphaL<Strobe<Rgb<100,200,255>,BrownNoiseFlicker<Rgb<100,200,255>,Black,200>,50,30>,                      Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
      TrConcat<TrInstant,
      AlphaL<Blinking<Rgb<100,200,255>,Strobe<BrownNoiseFlicker<Red,Black,500>,Black,15,30>,60,500>, Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,          Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<Red,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
// Non-Responsive Drag
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,Rgb<100,200,255>>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// Lightning Block - Non-responsive 
    LockupTrL<AlphaL<RandomFlicker<Strobe<Rgb<100,200,255>,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<
    Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
    Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
    Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,
    //Begin Lightning Transition
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
    //End Lightning Transition    
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<Rgb<100,200,255>,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// Melt    
    LockupTrL<
    AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
    // Melt Shape
    SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
    //Melt Begin and End transitions
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,

    InOutTrL<TrSmoothFade<1200>,TrConcat<TrInstant,AlphaL<Mix<BlinkingF<Int<360>,Int<100>>,Rgb<100,200,255>,Sparkle<GreenYellow,Rgb<10,255,0>,3000,500>>,Bump<Int<16384>,Scale<Trigger<EFFECT_RETRACTION,Int<3000>,Int<1>,Int<3000>>,Int<65536>,Int<0>>>>,TrDelay<3000>>>,
    AlphaL<Layers<
    AlphaL<Sparkle<Rgb<50,128,0>,Rgb<0,150,0>,3000,500>,Bump<Int<16384>,Scale<Trigger<EFFECT_PREON,Int<10000>,Int<1>,Int<3000>>,Int<0>,Int<50000>>>>,
    TransitionEffectL<TrWaveX<Sparkle<AlphaL<Black,Int<0>>,Rgb<50,130,0>,3000,500>,Int<20000>,Int<200>,Int<20000>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<15>>,EFFECT_PREON>>,Ifon<ChangeSlowly<Ifon<Int<0>,Int<32768>>,Int<30000>>,Int<32768>>>,
  // Glow Stick EFFECT_USER_3 - 13 seconds before lose glow - BC prop.
    AlphaL<Layers<
    AlphaL<Sparkle<Rgb<50,128,0>,Rgb<0,150,0>,3000,500>,Bump<Int<16384>,Scale<Trigger<EFFECT_USER3,Int<10000>,Int<1>,Int<3000>>,Int<0>,Int<50000>>>>,
    TransitionEffectL<TrWaveX<Sparkle<AlphaL<Black,Int<0>>,Rgb<50,130,0>,3000,500>,Int<20000>,Int<200>,Int<20000>>,EFFECT_USER3>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<15>>,EFFECT_USER3>>,Ifon<ChangeSlowly<Ifon<Int<0>,Int<32768>>,Int<30000>>,Int<32768>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Switch
  StylePtr<Layers<
    Rgb<100,100,100>,
    InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
  >>(),
"rave"},



{ "aa_NoSloppy/TheMaw;common;commonBU", "",
  StylePtr<Layers<
// Main Blade Color    
    Mix<SmoothStep<Int<16000>,Int<10000>>,
      StripesX<Scale<TwistAngle<1>,Int<1500>,Int<3000>>,Int<-2000>,Rgb<60,0,255>,Black>,
      StripesX<Scale<TwistAngle<1>,Int<1500>,Int<3000>>,Int<2000>,Rgb<60,0,255>,Black>>,
    // Ice Force
    TransitionEffectL< 
      TrConcat<TrFade<7000>,Rgb<10,0,75>,// blade turns solid cold 1000ms before ice full coverage
      TrDelay<1000>>,EFFECT_USER2>,  // hidden by ice overlay at this point, so no reason to have anything more than 1000 before back to base color
    TransitionEffectL< TrConcat<TrWipe<8000>, //wipe in stripes ice freezing effect
    TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>,TrFade<11500>,TrDelay<20000>,EFFECT_USER2>, // Stripes fade to solid over remaining 4 seconds from freezing edge's finish until 12000 then hold for next joined delay to end at 15000, so 3000 more.
      TrDelay<7000>,Sparkle<Rgb<100,150,230>,Rgb<100,200,255>,50,300>, //after 15000 (TrConcat makes it 8000 + 7000) from effect start, full blade to this shade of white for wiping away (seamless color from end of stripes fade to solid)
      TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>, // wipe ice away and melt to thinner opacity , but not 100%, leave like 30% by using longer fade duration than the wipe takes. 
    TransitionEffectL<TrConcat<
      TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,     Int<400>,  Int<50>, Int<1000>,Int<0>>,    // burst
        TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,      Int<15000>,Int<400>,Int<8000>,Int<0>>,         // leading freeze edge
        TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,    // crystalizing in edge's wake
    AlphaL<Rgb<100,200,255>,Int<0>>,
      TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,    Int<300>,  Int<50>, Int<1000>,Int<0>>,  // burst
        TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>, // crystalizing in thaw's path
        TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,     Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>, // leading thawing edge
BC_effects_Red, 
// Ignition and Retraction
    TransitionEffectL<TrConcat<TrDelay<200>,Strobe<Black,Rgb<100,100,150>,15,40>,TrJoin<TrWipeInSparkTip<Rgb<100,200,255>,800,200>,TrWipeSparkTip<Rgb<100,200,255>,800,200>>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrFade<700>,Strobe<Black,Rgb<100,100,150>,15,40>,TrDelay<300>>,EFFECT_RETRACTION>,
    InOutTrL<
      TrJoin<
        TrJoin<TrWipeIn<800>,TrWaveX<White,Int<800>,Int<500>,Int<800>,Int<32768>>>,
        TrJoin<TrWipe<800>,TrWaveX<White,Int<400>,Int<500>,Int<800>,Int<0>>>>,
      TrJoin<
        TrJoin<TrWipeInX<Percentage<WavLen<EFFECT_RETRACTION>,200>>,TrWaveX<White,WavLen<EFFECT_RETRACTION>,Int<500>,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<32768>>>,
        TrJoin<TrWipeX<Percentage<WavLen<EFFECT_RETRACTION>,200>>,TrWaveX<White,WavLen<EFFECT_RETRACTION>,Int<500>,Percentage<WavLen<EFFECT_RETRACTION>,200>,Int<0>>>>>,
    TransitionEffectL<TrConcat<TrInstant,White,TrFade<50>>,EFFECT_IGNITION>,
    TransitionEffectL<TrConcat<TrDelayX<WavLen<EFFECT_RETRACTION>>,White,TrFade<50>>,EFFECT_RETRACTION>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Switch
  StylePtr<Layers<
    Rgb<100,100,100>,
    InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
  >>(),
"the\nmaw"},



{ "aa_JayDalorian/Kyber_Weapon;common;commonBU", "",
  StylePtr<Layers<
    BC_12color_8effect_SS,
      BC_effects_White,
// standard
    // InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTipX<White,WavLen<EFFECT_RETRACTION>>>,
// bend
   InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<Rgb<255,100,100>,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Switch
  StylePtr<Layers<
    Rgb<100,100,100>,
    InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
  >>(),
"kyber\nweapon"},



// { "aa_HarrySolo/WORKBENCH;common;commonBU", "",
// StylePtr<
// Layers<Black,
//     AlphaL<Layers< //Swing color
//       AlphaL<HumpFlicker<Blue,Rgb<0,0,100>,50>,SmoothStep<Int<8000>,Int<-3000>>>,
//       AlphaL<HumpFlicker<Cyan,Rgb<0,120,200>,50>,SmoothStep<Int<2500>,Int<-6000>>>>,
//     SmoothStep<Scale<SwingSpeed<250>,Int<-2000>,Int<16000>>,Int<-2000>>>,
//   TransitionLoopL<TrConcat<TrFade<1000>,AlphaL<RotateColorsX<Variation,Rgb<100,90,150>>,Bump<Int<0>,ChangeSlowly<NoisySoundLevel,Int<50000>>>>,TrDelay<3000>,AlphaL<RotateColorsX<Variation,Rgb<100,90,150>>,Bump<Int<0>,ChangeSlowly<NoisySoundLevel,Int<50000>>>>,TrFade<1000>,AlphaL<Black,Int<0>>,TrDelay<2000>>>,
// ColorSelect<WavNum<EFFECT_CLASH>,TrInstant,
//   //clsh01.wav handle with care
//   Layers<
//   TransitionEffectL<TrConcat<TrInstant,HumpFlicker<White,Black,50>,TrWipeIn<560>>,EFFECT_CLASH>,
//   TransitionEffectL<TrConcat<TrDelay<70>,AlphaL<Red,SmoothStep<Int<5000>,Int<-1>>>,TrFade<250>,Black,TrInstant,AlphaL<Red,SmoothStep<Int<5000>,Int<-1>>>,TrFade<250>,Black,TrInstant,AlphaL<Red,SmoothStep<Int<5000>,Int<-1>>>,TrFade<250>>,EFFECT_CLASH>>,
//   // clsh02.wav excessive impact
//   TransitionEffectL<TrConcat<TrInstant,White,TrDelay<20>,Blinking<AlphaL<BrownNoiseFlicker<Red,DarkOrange,500>,Bump<Int<0>,Int<60000>>>,Black,100,500>,TrJoin<TrFade<1200>,TrWipeIn<1200>>>,EFFECT_CLASH>,
//   // clash03.wav please stop
//   Layers<
//   TransitionEffectL<TrJoin<TrSparkX<BrownNoiseFlicker<Red,DarkOrange,500>,Int<100>,Int<800>,Int<0>>,TrConcat<TrDelay<300>,AlphaL<Black,Int<0>>,TrFade<300>,AlphaL<White,Bump<Int<0>,Int<30000>>>,TrFade<500>>>,EFFECT_CLASH>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<3000>>>,TrDelay<500>,AlphaL<Black,Int<0>>,TrDelay<350>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<3000>>>,TrDelay<500>,AlphaL<Black,Int<0>>,TrDelay<350>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<3000>>>,TrDelay<500>,AlphaL<Black,Int<0>>,TrInstant>,EFFECT_CLASH>>,
//   // clsh04.wav dueling prohibited
//   Layers<
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<3000>>>,TrDelay<500>,AlphaL<Black,Int<0>>,TrDelay<716>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<3000>>>,TrDelay<500>,AlphaL<Black,Int<0>>,TrDelay<716>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<3000>>>,TrDelay<500>,AlphaL<Black,Int<0>>,TrInstant>,EFFECT_CLASH>,
//   TransitionEffectL<TrJoin<TrSparkX<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,DarkOrange>,500>,Int<100>,Int<800>,Int<0>>,TrConcat<TrDelay<266>,AlphaL<Black,Int<0>>,TrBoing<250,1>,AlphaL<Red,Bump<Int<0>>>,TrWipeIn<250>>>,EFFECT_CLASH>>,
//   // clash05.wav not best idea
//   Layers<
//   TransitionEffectL<TrConcat<TrDelay<100>,AlphaL<Black,Int<0>>,TrFade<100>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,DarkOrange>,500>,SmoothStep<Int<6000>,Int<-5000>>>,TrFade<100>,AlphaL<OrangeRed,SmoothStep<Int<1000>,Int<-5000>>>,TrFade<200>>,EFFECT_CLASH>,
//   TransitionEffectL<TrJoin<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<8000>>>,TrFade<200>>,TrSparkX<White,Int<500>,Int<300>,Int<0>>>,EFFECT_CLASH>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Black,SmoothStep<Int<8000>,Int<6000>>>,TrDelay<300>>,EFFECT_CLASH>>>,
//   ColorSelect<WavNum<EFFECT_BLAST>,TrInstant,
//     // blst01.wav repair completed
//     TransitionEffectL<TrConcat<TrBoing<1300,8>,AlphaL<PulsingL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,40,255>>,50>,Int<800>>,LinearSectionF<Bump<Int<16384>>,Sin<Int<100>>>>,TrWipe<460>,HumpFlickerL<RotateColorsX<Variation,Rgb<0,40,255>>,50>,TrDelay<300>>,EFFECT_BLAST>,
//     // blst02.wav repair failed
//     TransitionEffectL<TrConcat<TrBoing<250,3>,AlphaL<BlinkingL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,40,255>>,50>,Int<160>,Int<500>>,LinearSectionF<Sin<Int<500>,Int<8000>,Int<-10000>>,Int<25000>>>,TrWipeInSparkTip<Red,300>,BlinkingL<AlphaL<HumpFlickerL<Red,50>,SmoothStep<Int<1000>,Int<-1>>>,Int<500>,Int<500>>,TrDelay<1530>>,EFFECT_BLAST>,
//     // blst03.wav repair interrupted
//     TransitionEffectL<TrConcat<TrInstant,AlphaL<Blinking<RotateColorsX<Variation,Rgb<128,128,200>>,Blue,400,500>,LinearSectionF<Sin<Int<400>,Int<32768>,Int<-500>>,Scale<RandomF,Int<100>,Int<1000>>>>,TrDelay<2000>,AlphaL<Black,Int<0>>,TrBoing<300,1>,AlphaL<White,Bump<Int<0>>>,TrInstant>,EFFECT_BLAST>,
//     // blst04.wav no deflecting please
//     TransitionEffectL<TrConcat<TrBoing<300,1>,AlphaL<Red,Bump<Int<0>>>,TrWipeIn<100>,PulsingL<AlphaL<HumpFlickerL<Red,50>,SmoothStep<Int<1000>,Int<-1>>>,Int<800>>,TrDelay<4380>,AlphaL<White,LinearSectionF<Sin<Int<300>>,Sin<Int<200>,Int<1000>>>>,TrDelay<450>>,EFFECT_BLAST>>,
//   // force
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Blinking<RotateColorsX<Variation,Rgb<128,128,200>>,Blue,400,500>,LinearSectionF<Sin<Int<300>,Int<32768>,Int<-500>>,Scale<RandomF,Int<300>,Int<1000>>>>,TrFade<1075>,AlphaL<Black,Int<0>>,TrJoin<TrCenterWipeX<Int<1000>>,TrWaveX<White,Int<1000>,Int<200>,Int<2000>>>,Layers<
//     AlphaL<White,LayerFunctions<SmoothStep<Scale<RandomF,Int<-5000>,Int<2000>>,Int<-1>>,SmoothStep<Scale<RandomF,Int<37768>,Int<30768>>,Int<1>>>>,
//     AlphaL<ColorSequence<500,DarkOrange,Green,Blue>,LinearSectionF<Sin<Int<100>,Int<32768>,Int<-500>>,Scale<RandomF,Int<300>,Int<2000>>>>>,TrDelay<2750>,AlphaL<Black,Int<0>>,TrConcat<TrBoing<650,5>,AlphaL<HumpFlickerL<Green,50>,LayerFunctions<SmoothStep<Int<30768>,Int<1>>,SmoothStep<Int<2000>,Int<-1>>>>,TrInstant>>,EFFECT_FORCE>,
//   LockupTrL<Layers<
//     AudioFlicker<RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,Rgb16<0,43202,44565>>>,
//     TransitionLoopL<TrConcat<TrDelayX<Scale<RandomF,Int<700>,Int<4000>>>,AlphaL<White,LinearSectionF<RandomF,Int<500>>>,TrDelay<400>>>,
//     Layers<
//       TransitionEffectL<TrConcat<TrDelayX<Int<8738>>,AlphaL<RotateColorsX<Variation,Cyan>,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,TrBoing<735,3>,AlphaL<Black,Int<0>>,TrDelay<7118>,AlphaL<RotateColorsX<Variation,Cyan>,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,TrBoing<951,3>,AlphaL<Black,Int<0>>,TrDelay<6273>,AlphaL<RotateColorsX<Variation,Cyan>,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,TrBoing<735,3>,AlphaL<Black,Int<0>>,TrDelay<7118>,AlphaL<RotateColorsX<Variation,Cyan>,LayerFunctions<Bump<Int<0>>,Bump<Int<32768>>>>,TrBoing<951,3>,AlphaL<Black,Int<0>>,TrDelay<4546>>,EFFECT_LOCKUP_BEGIN>,
//       TransitionEffectL<TrConcat<TrDelay<10300>,AlphaL<Black,Int<0>>,TrFade<400>,BrownNoiseFlicker<RotateColorsX<Variation,Cyan>,Black,500>,TrFade<300>,AlphaL<Black,Int<0>>,TrDelay<7767>,AlphaL<Black,Int<0>>,TrFade<400>,BrownNoiseFlicker<RotateColorsX<Variation,Cyan>,Black,500>,TrFade<300>,AlphaL<Black,Int<0>>,TrDelay<5990>,AlphaL<Black,Int<0>>,TrFade<400>,BrownNoiseFlicker<RotateColorsX<Variation,Cyan>,Black,500>,TrFade<300>,AlphaL<Black,Int<0>>,TrDelay<7784>,AlphaL<Black,Int<0>>,TrFade<400>,BrownNoiseFlicker<RotateColorsX<Variation,Cyan>,Black,500>,TrFade<300>>,EFFECT_LOCKUP_BEGIN>>>,TrConcat<TrBoing<300,2>,AlphaL<AudioFlicker<RotateColorsX<Variation,DodgerBlue>,RotateColorsX<Variation,Rgb16<0,43202,44565>>>,Bump<Int<0>>>,TrWipe<275>>,TrWipeIn<500>,SaberBase::LOCKUP_NORMAL>,
//     ColorSelect<WavNum<EFFECT_LOCKUP_END>,TrInstant,
//       // endlock1.wav success
//       TransitionEffectL<TrConcat<TrWipeIn<500>,Black,TrInstant,White,TrDelay<25>,Black,TrFade<500>,HumpFlickerL<RotateColorsX<Variation,Rgb<0,40,255>>,100>,TrDelay<100>>,EFFECT_LOCKUP_END>,
//       // endlock2.wav fail
//       TransitionEffectL<TrConcat<TrWipeInSparkTip<White,460>,Black,TrBoing<250,2>,AlphaL<RotateColorsX<Variation,DodgerBlue>,SmoothStep<Int<12000>,Int<-1>>>,TrInstant,AlphaL<ColorSequence<75,Cyan,Black,Red,Black,Blue,DodgerBlue,Rgb<50,50,0>,Black>,SmoothStep<Scale<RandomF,Int<0>,Int<1500>>,Int<-1>>>,TrDelay<2673>>,EFFECT_LOCKUP_END>>,
//   InOutTrL<TrJoin<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>>>,TrFade<200>>,TrSparkX<White,Int<300>,Int<200>,Int<0>>>,TrConcat<TrBoing<2737,31>,AlphaL<AlphaL<DodgerBlue,Bump<Int<0>,Scale<Trigger<EFFECT_RETRACTION,Int<2737>,Int<1000>,Int<500>>,Int<65000>,Int<0>>>>,Scale<Trigger<EFFECT_RETRACTION,Int<2737>,Int<1000>,Int<500>>,Int<32768>,Int<0>>>,TrInstant>>,
//   TransitionEffectL<TrConcat<TrDelay<150>,AlphaL<Black,Int<0>>,TrBoing<300,2>,AlphaL<HumpFlickerL<White,50>,Bump<Int<0>,Int<16000>>>,TrDelay<400>,AlphaL<HumpFlickerL<White,50>,Bump<Int<0>,Int<16000>>>,TrConcat<TrFade<407>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<0,40,255>>,50>,Bump<Int<0>,Int<25000>>>,TrInstant>>,EFFECT_PREON>,
//   TransitionEffectL<TrJoin<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<8000>>>,TrFade<200>>,TrSparkX<White,Int<500>,Int<300>,Int<0>>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<Black,SmoothStep<Int<8000>,Int<6000>>>,TrDelay<300>>,EFFECT_PREON>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,DodgerBlue>,Bump<Int<0>,ChangeSlowly<NoisySoundLevel,Int<50000>>>>,TrFadeX<Percentage<WavLen<>,50>>>,EFFECT_POSTOFF>,
//   TransitionEffectL<TrConcat<TrInstant,AlphaL<ColorSequence<75,Cyan,Black,Green,Black,Blue,Black,Rgb<50,50,0>,Black>,SmoothStep<Sin<Int<300>,Int<0>,Int<12000>>,Int<-1>>>,TrDelay<700>,AlphaL<RandomFlicker<Rgb<70,100,200>,ColorSequence<350,Cyan,Green,Blue,Rgb<50,50,0>,Black>>,SmoothStep<Scale<Trigger<EFFECT_BOOT,Int<4000>,Int<1000>,Int<500>>,Int<20000>,Int<0>>,Int<-1>>>,TrDelay<4300>>,EFFECT_BOOT>,
//   TransitionEffectL<TrConcat<TrDelay<1000>,BlinkingL<AlphaL<HumpFlickerL<Red,50>,SmoothStep<Int<1000>,Int<-1>>>,Int<500>,Int<500>>,TrFade<4026>>,EFFECT_BOOT>,
//     TransitionEffectL<TrConcat<TrFade<1000>,AlphaL<AudioFlicker<Rgb<100,90,150>,Black>,Bump<Int<0>,ChangeSlowly<NoisySoundLevel,Int<50000>>>>,TrFade<250>,AlphaL<DodgerBlue,Bump<Int<0>,Int<60000>>>,TrWipeIn<100>>,EFFECT_NEWFONT>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// // Switch
//   StylePtr<Layers<
//     Rgb<100,100,100>,
//     InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
//   >>(),
//   "workbench"},



{"a_SHIPS/Slave1_2.1_Proffie;common", "a_SHIPS/Slave1/tracks/Pursuit.wav", // Center out stripes - custom preon and ignition
   
// Slave 1 with seismic charge preon
   
 StylePtr<Layers<
  Mix<SmoothStep<Int<16384>,Int<4000>>,Stripes<10000,500,Rgb<0,30,80>,Rgb<0,60,180>>,Stripes<10000,-500,Rgb<0,30,80>,Rgb<0,60,180>>>,
// Dim Blade 50% "Power Save" button combo
  EffectSequence<EFFECT_POWERSAVE,
  AlphaL<Black,Int<16384>>,
  AlphaL<Black,Int<0>>>,
// Clash - 3 stage fading impact spot
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// Stab 
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,DarkOrange,Rgb<80,60,0>,Orange,Rgb<60,30,0>,Black,DarkOrange,Orange>,SmoothStep<Int<20000>,Int<2000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// Blast - custom for slave 1 sound fx
    MultiTransitionEffectL<TrConcat<TrDelay<700>,AlphaL<Black,Int<0>>,TrFade<800>,LocalizedClashL<HumpFlicker<DarkOrange,Red,50>,2000,50,EFFECT_BLAST>,TrFade<600>>,EFFECT_BLAST>,
    LocalizedClashL<Blinking<White,Black,130,800>,1560,50,EFFECT_BLAST>,
    LocalizedClashL<Blinking<Red,Black,130,500>,1560,15,EFFECT_BLAST>,
// Lockup - BC custom range mid-blade
    LockupTrL<Layers<
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                            Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<10000>,Int<18000>>>>,
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
    // Begin Lightning Transition
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<100>>,
    // End Lightning Transition    
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  
// Melt
    LockupTrL<
    //Melt Colors
    AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
    // Melt Shape
    SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
    // Melt Begin and End transitions
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
// Ignition Powerup
    TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<DeepSkyBlue,White,100>,TrFade<800>>,EFFECT_IGNITION>,
// In/out using Trigger for instantaneous Center-out wipes
   InOutTrL<TrConcat<TrInstant,Layers<
    AlphaL<Black,SmoothStep<Scale<Trigger<EFFECT_IGNITION,Int<300>,Int<1000>,Int<500>>,Int<16385>,Int<0>>,Int<-1>>>,
    AlphaL<Black,SmoothStep<Scale<Trigger<EFFECT_IGNITION,Int<300>,Int<1000>,Int<500>>,Int<16384>,Int<32768>>,Int<0>>>>,TrDelay<1000>>,TrJoin<TrWipe<700>,TrWipeIn<700>>>,
   TransitionEffectL<TrConcat<TrInstant,Cyan,TrDelay<50>>,EFFECT_IGNITION>,
// Asteroid impacts after detonation - timed sequence
   TransitionEffectL<TrConcat<
    TrDelay<1500>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Red,White,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<3000>,Int<6000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<100>,AlphaL<Red,Int<0>>,
    TrDelay<400>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Orange,White,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<6000>,Int<10000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<100>,AlphaL<Red,Int<0>>,
    TrDelay<200>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Black,White,100>,Bump<ChangeSlowly<SlowNoise<Int<30000>>,Int<60000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<300>,AlphaL<Red,Int<0>>,
    TrDelay<200>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Yellow,Red,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<10000>,Int<28000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<200>,AlphaL<Red,Int<0>>,
    TrDelay<500>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Orange,White,100>,Bump<ChangeSlowly<SlowNoise<Int<30000>>,Int<60000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<200>,AlphaL<Red,Int<0>>,
    TrDelay<100>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Red,White,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<5000>,Int<13000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<100>,AlphaL<Red,Int<0>>,
    TrDelay<500>,GreenYellow,TrDelay<25>>,EFFECT_IGNITION>,
// Seismic Charge preon effect. use with linked preon sound
  TransitionEffectL<TrConcat<TrDelay<2125>,Cyan,TrFade<100>,Black,TrDelay<10>,Cyan,TrFade<150>  >,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrDelay<2125>,AlphaL<White,Bump<Int<16384>,Int<32768>>>,TrFade<100>, Black,TrDelay<10>,AlphaL<White,Bump<Int<16384>,Int<32768>>>,TrFade<150>  >,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrDelay<2100>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<3000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<4000>>>,
    TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<5000>>>,
    TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<10000>>>,
    TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<20000>>>,
    TrSmoothFade<175>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<30000>>>,
    TrSmoothFade<125>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<35000>>>,
    TrSmoothFade<150>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<30000>>>,
    TrSmoothFade<75>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<20000>>>,
    TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<8000>>>,
    TrSmoothFade<25>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<3000>>>,TrFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<20000>>>,TrDelay<25>>,EFFECT_PREON>,

  TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Scale<Trigger<EFFECT_PREON,Int<2000>,Int<1000>,Int<500>>,Int<-1000>,Int<16500>>,Int<1500>>>,TrDelay<2000>>,EFFECT_PREON>,
  TransitionEffectL<TrConcat<TrDelay<1100>,AlphaL<Red,Int<0>>,TrSmoothFade<700>,Black,TrDelay<100>,AlphaL<White,Bump<Int<16384>,Int<3000>>>,TrDelay<100>>,EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Switch
  StylePtr<Layers<
    Rgb<100,100,100>,
    InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
  >>(),
"slave 1"},



{ "aa_BK/Party_Foul;common;commonBU", "",
  StylePtr<Layers<
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,20,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<0,120,0>>,Black>>,RotateColorsX<Variation,Rgb<0,60,0>>,Pulsing<RotateColorsX<Variation,Rgb<0,50,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,96,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<0,5,0>>,3000>>,
    AlphaL<StyleFire<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,2,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
    BC_effects_1,
    InOutTrL<TrWipe<1000>,TrJoin<TrFade<1600>,TrWipe<1580>>>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Switch
  StylePtr<Layers<
    Rgb<100,100,100>,
    InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
  >>(),
"party\nfoul"},


{ "aa_Kyberphonic/Fire;common;commonBU", "",
  /* copyright Fett263 ResponsiveFlame (Primary Blade) OS6 Style
https://fett263.com/fett263-proffieOS6-style-library.html#ResponsiveFlame
OS6.6 v3.04
Single Style
Base Style: Responsive Flame (Real Flame Gradient)


--Effects Included--
Ignition Effect: BC custom "explosive" Ignition
Retraction Effect: WavLen WipeIn
PostOff Effect: Emitter Cool Off (Emitter Size)
Lockup Effect: Intensity Lockup V1
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Intensity Melt
Blast Effect: Blast Wave (Random)
Clash Effect: Real Clash V1
Preon: BC Sparking lighter thing.
*/
// Main Blade
  StylePtr<Layers<Mix<SmoothStep<Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<36000>,Scale<BladeAngle<>,Int<10924>,Int<54000>>>,Scale<IsLessThan<BladeAngle<>,Int<16000>>,Int<-1>,Scale<BladeAngle<>,Int<-10000>,Int<-1>>>>,Black,Remap<Scale<RampF,Int<0>,Scale<IsLessThan<BladeAngle<>,Int<15000>>,Int<32768>,Scale<BladeAngle<0,15000>,Int<60000>,Int<32768>>>>,Layers<Mix<BladeAngle<>,
    StaticFire<Gradient<RotateColorsX<Variation,Rgb<255,75,0>>,RotateColorsX<Variation,Rgb<255,50,0>>,RotateColorsX<Int<400>,Red>,Red>,Mix<Int<16384>,Black,Red>,0,2,0,1800,10>,StaticFire<Gradient<RotateColorsX<Variation,Rgb<255,75,0>>,RotateColorsX<Int<1200>,Red>,RotateColorsX<Int<600>,Red>,Red>,Mix<Int<16384>,Black,Red>,0,4,0,2200,2>>>>>,
    BC_effects_Red, 
    InOutTrL<TrConcat<TrWipe<100>,White,TrWipe<30>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<255,75,0>>,RotateColorsX<Variation,Yellow>,500>,TrJoin<TrFade<300>,TrWipeIn<500>>>,TrWipeInX<RetractionTime<>>>,
    TransitionEffectL<TrConcat<
    TrFade<50>,AlphaL<BrownNoiseFlicker<Rgb<255,75,0>,Yellow,500>,Bump<Int<0>,Int<10000>>>,TrInstant,AlphaL<White,Bump<Int<0>,Int<40000>>>,TrFade<60>,AlphaL<Sparkle<Black,BrownNoiseFlicker<Rgb<255,75,0>,Yellow,500>,500,503>,Bump<Int<0>,Int<60000>>>,TrFade<300>,
    TrDelay<360>,
    TrFade<50>,AlphaL<BrownNoiseFlicker<Rgb<255,75,0>,Yellow,500>,Bump<Int<0>,Int<10000>>>,TrInstant,AlphaL<White,Bump<Int<0>,Int<40000>>>,TrFade<60>,AlphaL<Sparkle<Black,BrownNoiseFlicker<Rgb<255,75,0>,Yellow,500>,500,503>,Bump<Int<0>,Int<60000>>>,TrFade<279>,
    TrFade<50>,AlphaL<BrownNoiseFlicker<Rgb<255,75,0>,Yellow,500>,Bump<Int<0>,Int<10000>>>,TrInstant,AlphaL<White,Bump<Int<0>,Int<40000>>>,TrFade<60>,AlphaL<Sparkle<Black,BrownNoiseFlicker<Rgb<255,75,0>,Yellow,500>,500,503>,Bump<Int<0>,Int<60000>>>,TrFade<300>,
    TrDelay<154>,
    TrFade<50>,AlphaL<BrownNoiseFlicker<Rgb<255,75,0>,Yellow,500>,Bump<Int<0>,Int<10000>>>,TrInstant,AlphaL<White,Bump<Int<0>,Int<40000>>>,TrFade<60>,AlphaL<Sparkle<Black,BrownNoiseFlicker<Rgb<255,75,0>,Yellow,500>,500,503>,Bump<Int<0>,Int<60000>>>,TrFade<300>,
    TrDelay<174>,
    TrFade<50>,AlphaL<BrownNoiseFlicker<Rgb<255,75,0>,Yellow,500>,Bump<Int<0>,Int<10000>>>,TrInstant,AlphaL<White,Bump<Int<0>,Int<40000>>>,TrFade<60>,AlphaL<Sparkle<Black,BrownNoiseFlicker<Rgb<255,75,0>,Yellow,500>,500,503>,Bump<Int<0>,Int<60000>>>,TrFade<52>>,
    EFFECT_PREON>,
  // On-Demand
    OnDemandVolumeLevel,
    OnDemandBatteryLevel
  >>(),
// Switch
  StylePtr<Layers<
    Rgb<100,100,100>,
    InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
  >>(),
"fire"},

};

//---------------------------------------------------------------------------------------------------------

// Preset bladeout [] = {

// { "Calibr8;common;commonBU", "tracks/Battle.wav", // Color Cycle to Glitchy Pulsing Blade Default = Green
//   StylePtr<Layers<   
//       ColorCycle<RotateColorsX<Variation,Rgb<0,128,0>>,100,-3250,RotateColorsX<Variation,BlinkingX<RandomFlicker<RandomBlink<13000,RotateColorsX<Variation,Rgb<128,200,128>>,RotateColorsX<Variation,Black>>,RotateColorsX<Variation,Green>>,RandomFlicker<RotateColorsX<Variation,Rgb<0,128,0>>,RotateColorsX<Variation,Rgb<30,30,30>>>,Scale<SlowNoise<Int<16000>>,Int<300>,Int<1000>>,Scale<SlowNoise<Int<16000>>,Int<200>,Int<650>>>>,50,3000,3000>,
//       BC_effects_1,
//       InOutTrL<TrWipeSparkTip<White,250>,TrWipeInX<WavLen<EFFECT_RETRACTION>>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// // Switch
//   StylePtr<Layers<
//     Red,
//     InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
//   >>(),
// "calibr8"},


// { "RootCore;common;commonBU", "RootCore/tracks/root.wav", 
// // Main Blade
//   StylePtr<Layers<
//     Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,Black>,
//     BC_effects_Red,
//     InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,ColorCycle<Red,10,30,Black,100,3000,1>>,
//   // On-Demand
//     OnDemandVolumeLevel,
//     OnDemandBatteryLevel
//   >>(),
// // Switch
//   StylePtr<Layers<
//     Red,
//     InOutTrL<TrFade<600>,TrFade<600>,Pulsing<Black,Red,3000>>
//   >>(),
// "root\ncore"},


// };

BladeConfig blades[] = {
// { 600,
//   WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // Main Blade
//   SimpleBladePtr<CH1LED, NoLED, NoLED, NoLED, bladePowerPin4, -1, -1, -1>(),  // Switch
// CONFIGARRAY(bladeout), 
// "01_bladeout_save"},

{ 200,
  WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), // Main Blade
  SimpleBladePtr<CH1LED, NoLED, NoLED, NoLED, bladePowerPin4, -1, -1, -1>(),  // Switch
CONFIGARRAY(bladein), 
"01_bladein_save"}, 
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow"); 
#endif
