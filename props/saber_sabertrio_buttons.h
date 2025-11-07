/*
ProffieOS: Control software for lightsabers and other props.
http://fredrik.hubbe.net/lightsaber/teensy_saber.html
Copyright (c) 2016-2019 Fredrik Hubinette
 
Copyright (c) 2020-2021 Fernando da Rosa
 
Voice Prompts and sounds required for certain features and should be included in /common folder or /font folder on SD card.
 
Track Player requires track files to be located in /font/tracks for font specific tracks or /common/tracks for universal (all presets) or a combination of the two.
*/
 
// Sabertrio Proffie Preconfiguration
// DEFAULT 2 SWITCH CONTROLS (ACTIVATION and AUXILIARY)
//
// Ignite Blade                 - Press & release ACTIVATION SWITCH while blade is OFF.
//                              - Twist while blade is OFF.
//                                NOTE: If no blade or blade plug is detected, the 'no blade' sound effect will play.
// Mute Mode                    - Press & hold AUXILIARY SWITCH + press & release ACTIVATION SWITCH while blade is OFF.
// Retract Blade                - Press & hold the ACTIVATION SWITCH for while blade is ON.
//                              - Twist while blade is ON.
// Blaster Block Effect         - Press & release AUXILIARY SWITCH while blade is ON.
// Flash on Clash               - Strike blade while blade is ON.
// Blade Lockup Effect          - Press & hold AUXILIARY SWITCH and strike blade while blade is ON.
// Blade Tip Drag Effect        - Press & hold AUXILIARY SWITCH and strike blade downwards while blade is ON.
// Wall Melt Effect             - Press & hold AUXILIARY SWITCH and strike blade forward while blade is ON.
// Force Effect                 - Press & hold AUXILIARY SWITCH while blade is ON.
// Force Lightning Parry Effect - Double press & hold ACTIVATION SWITCH when blade is on.
// Kyber Dial                   - Press & hold AUXILIARY SWITCH + press & release ACTIVATION SWITCH while blade is ON.
//                              - Press & hold ACTIVATION SWITCH or AUXILIARY SWITCH while in Blade Length Adjust Mode.
//                                THEN: Twist rotate saber to change blade color.
//                                NOTE: Press & release AUXILIARY SWITCH to select color and exit Kyber Dial.
//                                NOTE: Press & release ACTIVATION SWITCH to revert to default color and exit Kyber Dial.
// Blade Length Adjustment      - Press & Hold ACTIVATION SWITCH or AUXILIARY SWITCH while in Kyber Dial.
//                                THEN: Twist rotate to change blade length.
//                                NOTE: Press & release AUXILIARY SWITCH to save blade length and exit Blade Length Adjustment.
//                                NOTE: Press & release ACTIVATION SWITCH to revert to last saved blade length and exit Blade Length Adjustment.
// Sound Bank Selection         - Press & hold AUXILIARY SWITCH while blade is OFF.
//                                NOTE: Press & release AUXILIARY SWITCH while in Sound Bank Selection to cycle to next sound font.
//                                NOTE: Press & release ACTIVATION SWITCH while in Sound Bank Selection to cycle to previous sound font.
//                                NOTE: Press & Hold ACTIVATION or AUXIALRY SWITCH while in Sound Bank Selection to select sound font.
// Volume Menu                  - Press & Hold AUXILIARY SWITCH & ACTIVATION SWITCH while blade is OFF.
//                                NOTE: Press & release AUXILIARY SWITCH while in Volume Menu to increase volume.
//                                NOTE: Press & release ACTIVATION SWITCH while in Volume Menu to decrease volume.
//                                NOTE: Press & hold ACTIVATION SWITCH or AUXILIARY SWITCH while in Volume Menu to exit.
// Battery Level Meter          - Press & release AUXILIARY SWITCH while blade is OFF.
// Gesture Toggle               - Press & hold ACTIVATION SWITCH + Twist Rotate the saber while blade is OFF.
// Track Player                 - Press & hold ACTIVATION SWITCH + press & release AUXILIARY SWITCH.
 
#ifndef PROPS_SABER_SABERTRIO_BUTTONS_H
#define PROPS_SABER_SABERTRIO_BUTTONS_H
 
#ifndef MOTION_TIMEOUT
#define MOTION_TIMEOUT 60 * 15 * 1000
#endif
 
#ifndef FETT263_SWING_ON_SPEED
#define FETT263_SWING_ON_SPEED 250
#endif
 
#ifndef FETT263_LOCKUP_DELAY
#define FETT263_LOCKUP_DELAY 200
#endif
 
#ifndef FETT263_BM_CLASH_DETECT
#define FETT263_BM_CLASH_DETECT 0
#endif
 
#ifndef FETT263_FORCE_PUSH_LENGTH
#define FETT263_FORCE_PUSH_LENGTH 5
#endif
 
#if NUM_BUTTONS < 1
#error /props/s3button_config.h requires 1 or 2 Buttons for operation
#endif
 
#if defined(FETT263_CLASH_STRENGTH_SOUND) && !defined(FETT263_MAX_CLASH)
#define FETT263_MAX_CLASH 16
#endif
 
#ifdef FETT263_TWIST_ON
#define TWIST_GESTURE
#endif
 
#if defined(FETT263_THRUST_ON_NO_BM) && !defined(THRUST_GESTURE)
#error FETT263_THRUST_ON_NO_BM requires either FETT263_THRUST_ON or FETT263_THRUST_ON_PREON
#endif
 
#ifdef FETT263_FORCE_PUSH_ALWAYS_ON
#define FORCE_PUSH_CONDITION true
#define FETT263_FORCE_PUSH
#else
#define FORCE_PUSH_CONDITION battle_mode_
#endif
 
#include "prop_base.h"
#include "../sound/hybrid_font.h"
#include "../sound/effect.h"
#include "../common/current_preset.h"
 
#ifdef FETT263_EDIT_MODE_MENU
#include "../common/file_reader.h"
#include "../common/malloc_helper.h"
#include "../common/color.h"
#include "../styles/edit_mode.h"
#endif
 
#undef PROP_TYPE
#define PROP_TYPE SaberSabertrioButtons
 
EFFECT(dim);        // for EFFECT_POWERSAVE
EFFECT(battery);    // for EFFECT_BATTERY_LEVEL
EFFECT(bmbegin);    // for Begin Battle Mode
EFFECT(bmend);      // for End Battle Mode
EFFECT(vmbegin);    // for Begin Volume Menu
EFFECT(vmend);      // for End Volume Menu
EFFECT(volup);      // for increse volume
EFFECT(voldown);    // for decrease volume
EFFECT(volmin);     // for minimum volume reached
EFFECT(volmax);     // for maximum volume reached
EFFECT(mute);       // for Mute Mode
EFFECT(faston);     // for EFFECT_FAST_ON
EFFECT(blstbgn);    // for Begin Multi-Blast
EFFECT(blstend);    // for End Multi-Blast
EFFECT(push);       // for Force Push gesture in Battle Mode
EFFECT(quote);      // quote on force effect
EFFECT(no_blade);   // for NO BLADE img
EFFECT(kyber);      // for KyberDial img
EFFECT(volumemenu); // for Volume Menu img
EFFECT(length);     // for Blade Length Menu img
EFFECT(cancel);     // for Cancel
 
EFFECT(fontmenu);
EFFECT(plus);
EFFECT(minus);
EFFECT(default);
#ifdef FETT263_EDIT_MODE_MENU
EFFECT(medit);      // Edit Mode
#endif
 
#include "../sound/sound_library.h"
 
class GestureControlFile : public ConfigFile {
public:
  void iterateVariables(VariableOP *op) override {
    CONFIG_VARIABLE2(gestureon, 1);
 
    CONFIG_VARIABLE2(swingonspeed, FETT263_SWING_ON_SPEED);
    #ifdef TWIST_GESTURE
    CONFIG_VARIABLE2(twiston, 1);
    #else
    CONFIG_VARIABLE2(twiston, 0);
    #endif
 
    #ifdef FETT263_TWIST_OFF
    CONFIG_VARIABLE2(twistoff, 1);
    #else
    CONFIG_VARIABLE2(twistoff, 0);
    #endif
 
    #ifdef FORCE_PUSH_CONDITION
    CONFIG_VARIABLE2(forcepush, 1);
    #else
    CONFIG_VARIABLE2(forcepush, 0);
    #endif
 
    CONFIG_VARIABLE2(forcepushlen, FETT263_FORCE_PUSH_LENGTH);
    CONFIG_VARIABLE2(lockupdelay, FETT263_LOCKUP_DELAY);
    CONFIG_VARIABLE2(clashdetect, FETT263_BM_CLASH_DETECT);
    #ifdef FETT263_MAX_CLASH
    CONFIG_VARIABLE2(maxclash, FETT263_MAX_CLASH);
    #else
    CONFIG_VARIABLE2(maxclash, 16);
    #endif
  }
  bool gestureon;           // gesture controls on/off for use with "Gesture Sleep"
  bool swingon;             // Swing On ignition
  int swingonspeed;         // Swing On speed (200 ~ 500 range)
  bool twiston;             // Twist On ignition
  bool thruston;            // Thrust On ignition
  bool stabon;              // Stab On ignition
  bool forcepush;           // Force Push
  uint32_t forcepushlen;    // Force Push Length
  uint32_t lockupdelay;     // Lockup Delay (for Battle Mode)
  bool twistoff;            // Twist Off retraction
  // disable PWR button for retraction, for use with "Power Lock" mode
  // to prevent button turning saber off
  bool powerlock;
  int clashdetect;          // maximum Clash Strength to detect Clash during Battle Mode (0 ~ 10 range)
  int maxclash;             // maximum Clash Strength for Clash Sound and Detection works with CLASH_THRESHOLD_G to create range of Clash Strength (8 ~ 16 range)
};
 
#ifdef FETT263_EDIT_MODE_MENU
// Edit Length
int length_edit_length = 0;
 
// Edit Length Preview for Edit Mode
// LengthEdit uses blade color and creates single white pixel at last pixel, black above last pixel
template<class BASE, class LIGHTUP, class BLACK = BLACK>
class LengthEdit {
public:
  void run(BladeBase* blade) {
    base_.run(blade);
    lightup_.run(blade);
    black_.run(blade);
  }
 
  OverDriveColor getColor(int led) {
    if (led == length_edit_length) return lightup_.getColor(led);
    if (led > length_edit_length) return black_.getColor(led);
    return base_.getColor(led);
  }
 
private:
  BASE base_;
  LIGHTUP lightup_;
  BLACK black_;
};
 
// Edit Style Settings
 
class IntEdit {
public:
  void run(BladeBase* blade) {  }
  int getInteger(int led) { return int_edit_; }
  static void SetIntValue(int value) { int_edit_ = value; }
private:
  static int int_edit_;
};
 
int IntEdit::int_edit_ = 0;
#endif
 
// Color List
struct ColorListEntry { Color16 color; ColorNumber color_number; };
 
static constexpr ColorListEntry color_list_[] = {
  { Red::color(), COLOR_RED },
  { OrangeRed::color(), COLOR_ORANGERED },
  { DarkOrange::color(), COLOR_DARKORANGE },
  { Orange::color(), COLOR_ORANGE },
  { { 46260, 33410, 0 }, COLOR_GOLD },
  { Yellow::color(), COLOR_YELLOW },
  { GreenYellow::color(), COLOR_GREENYELLOW },
  { Green::color(), COLOR_GREEN },
  { Aquamarine::color(), COLOR_AQUAMARINE },
  { Cyan::color(), COLOR_CYAN },
  { DeepSkyBlue::color(), COLOR_DEEPSKYBLUE },
  { DodgerBlue::color(), COLOR_DODGERBLUE },
  { Blue::color(), COLOR_BLUE },
  { { 7710, 15420, 51400 }, COLOR_ICEBLUE },
  { { 11102, 92, 53864 }, COLOR_INDIGO },
  { { 24000, 0, 50536 }, COLOR_PURPLE },
  { { 30324, 0, 49768 }, COLOR_DEEPPURPLE },
  { Magenta::color(), COLOR_MAGENTA },
  { DeepPink::color(), COLOR_DEEPPINK },
  { { 25700, 25700, 38550 }, COLOR_SILVER },
  { { 21845, 21845, 51400 }, COLOR_GLACIER },
  { { 46260, 46260, 65535 }, COLOR_ICEWHITE },
  { LightCyan::color(), COLOR_LIGHTCYAN },
  { Moccasin::color(), COLOR_MOCCASIN },
  { LemonChiffon::color(), COLOR_LEMONCHIFFON },
  { NavajoWhite::color(), COLOR_NAVAJOWHITE },
  { White::color(), COLOR_WHITE }
};
 
// Edit Color Submenu
const int rgb_arg_menu_[] {
  BASE_COLOR_ARG,
  ALT_COLOR_ARG,
  BLAST_COLOR_ARG,
  CLASH_COLOR_ARG,
  LOCKUP_COLOR_ARG,
  DRAG_COLOR_ARG,
  LB_COLOR_ARG,
  STAB_COLOR_ARG,
  PREON_COLOR_ARG,
  IGNITION_COLOR_ARG,
  RETRACTION_COLOR_ARG,
  POSTOFF_COLOR_ARG,
  SWING_COLOR_ARG,
  EMITTER_COLOR_ARG,
  OFF_COLOR_ARG
};
 
// Edit Style Setting Submenu
const int int_arg_menu_[] {
  STYLE_OPTION_ARG,
  IGNITION_OPTION_ARG,
  IGNITION_TIME_ARG,
  IGNITION_DELAY_ARG,
  IGNITION_POWER_UP_ARG,
  RETRACTION_OPTION_ARG,
  RETRACTION_TIME_ARG,
  RETRACTION_DELAY_ARG,
  RETRACTION_COOL_DOWN_ARG,
  LOCKUP_POSITION_ARG,
  DRAG_SIZE_ARG,
  MELT_SIZE_ARG,
  SWING_OPTION_ARG,
  EMITTER_SIZE_ARG,
  OFF_OPTION_ARG,
  // preon always needs to be last options to allow check for SFX_preon in menu
  PREON_OPTION_ARG,
  PREON_SIZE_ARG
};
 
// The Saber class implements the basic states and actions
// for the saber.
class SaberSabertrioButtons : public PROP_INHERIT_PREFIX PropBase {
public:
  SaberSabertrioButtons() : PropBase() {}
  const char* name() override { return "SaberSabertrioButtons"; }
 
  GestureControlFile saved_gesture_control;
 
  void RestoreGestureState() {
    saved_gesture_control.ReadINIFromDir(NULL, "gesture");
  }
 
  void SaveGestureState() {
    STDOUT.println("Saving Gesture State");
    saved_gesture_control.Write("gesture.tmp");
    saved_gesture_control.Write("gesture.ini");
  }
 
  //This generates ini files to save the saber state
  void GenerateIniFiles() {
    SaveState(current_preset_.preset_num);
    SaveGestureState();
  }
 
  Color16 GetColorArg(int blade, int arg) {
    char argspace[32];
    if (style_parser.GetArgument(current_preset_.GetStyle(blade), arg + 2, argspace))
    {
      char* tmp;
      int r = strtol(argspace, &tmp, 0);
      int g = strtol(tmp+1, &tmp, 0);
      int b = strtol(tmp+1, NULL, 0);
      return Color16(r,g,b);
    }
    return Color16();
  }
 
  // Color / Style Editing
  HSL hsl_;
  ShowColorAllBladesTemplate<ShowColorStyle> show_color_all_;
  #ifdef FETT263_EDIT_MODE_MENU
  ShowColorSingleBladeTemplate<ShowColorStyle> show_color_;
  ShowColorSingleBladeTemplate<Mix<Bump<Int<16384>,Int<14000>>,RgbArg<1,Rgb<255,0,0>>,ShowColorStyle>> bump_color_;
  ShowColorSingleBladeTemplate<Mix<SmoothStep<Int<26000>,Int<8000>>,RgbArg<1,Rgb<255,0,0>>,ShowColorStyle>> tip_color_;
  ShowColorSingleBladeTemplate<Mix<SmoothStep<Int<7000>,Int<-6000>>,RgbArg<1,Rgb<255,0,0>>,ShowColorStyle>> hilt_color_;
  ShowColorSingleBladeTemplate<Mix<SmoothStep<Int<7000>,Int<-6000>>,Black,ShowColorStyle>> pre_color_;
  ShowColorSingleBladeTemplate<LengthEdit<ShowColorStyle,Pulsing<White,Rgb<100,100,100>,800>>,LengthEdit<ShowColorStyle,Pulsing<White,Rgb<100,100,100>,800>>> show_length_;
  ShowColorSingleBladeTemplate<Mix<Bump<IntEdit,Int<10000>>,Black,ShowColorStyle>> show_lockup_position_;
  ShowColorSingleBladeTemplate<Mix<SmoothStep<IntEdit,Int<6000>>,Black,ShowColorStyle>> show_drag_size_;
  ShowColorSingleBladeTemplate<Mix<SmoothStep<IntEdit,Int<-6000>>,Black,ShowColorStyle>> show_emitter_size_;
  #if NUM_BLADES > 1
  ShowColorSingleBladeTemplate<Pulsing<ShowColorStyle,Black,800>,Pulsing<ShowColorStyle,Black,800>> show_preview_;
  #endif
 
  // Show Full Blade Preview for Color Editing
  void ShowFull() {
    show_color_.Start(blade_num_);
    ShowColorStyle::SetColor(GetColorArg(blade_num_, effect_num_));
    saved_color_ = GetColorArg(blade_num_, effect_num_);
    hsl_ = saved_color_.toHSL();
    hsl_angle_ = fusor.angle2();
  }
 
  // Show Partial Blade Preview (Clash, Lockup, Drag, Melt, Preon, Emitter) for Color Editing
  void ShowPart() {
    ShowColorStyle::SetColor(GetColorArg(blade_num_, effect_num_));
    saved_color_ = GetColorArg(blade_num_, effect_num_);
    hsl_ = saved_color_.toHSL();
    hsl_angle_ = fusor.angle2();
  }
 
  #if NUM_BLADES > 1
  void BladePreview(int blade) {
    if (blade_preview_ > 0)
    {
      show_preview_.Stop(blade_preview_);
    }
    blade_preview_ = blade;
    show_preview_.Start(blade);
    ShowColorStyle::SetColor(GetColorArg(blade_num_, 1));
  }
  #endif
 
  void LengthPreview(int blade) {
    show_length_.Start(blade);
    length_edit_length = blade_length_ - 1;
    ShowColorStyle::SetColor(GetColorArg(blade_num_, 1));
  }
 
  // Copy Color Arguments from one blade to another
  void CopyColors() {
    effect_num_ = 16;
    while (true) {
      effect_num_ -= 1;
      if (style_parser.UsesArgument(current_preset_.GetStyle(blade_num_), effect_num_ + 2)) break;
    }
    saved_color_ = GetColorArg(blade_num_, effect_num_);
    hsl_ = saved_color_.toHSL();
    NewColor(blade_num_, effect_num_);
    current_preset_.Save();
    effect_num_ = 0;
  }
 
  // Set In/Out (Ignition/Retraction) Arguments
  void SetInOut() {
    char style_arg[10];
    itoa(calc_, style_arg, 10);
    current_preset_.SetStyle(blade_num_,style_parser.SetArgument(current_preset_.GetStyle(blade_num_), set_num_ + 2, style_arg));
    current_preset_.Save();
    switch (menu_type_) {
      case MENU_STYLE_OPTION:
      case MENU_IGNITION_TIME:
      case MENU_IGNITION_OPTION:
      case MENU_IGNITION_POWER_UP_OPTION:
      case MENU_IGNITION_DELAY:
      SetPresetFast(current_preset_.preset_num);
      break;
      case MENU_PREON_OPTION:
      case MENU_PREON_SIZE:
      UpdatePreon();
      break;
      case MENU_RETRACTION_TIME:
      case MENU_RETRACTION_OPTION:
      case MENU_RETRACTION_COOL_DOWN_OPTION:
      case MENU_RETRACTION_DELAY:
      UpdateStyle();
      off_event_ = true;
      restart_millis_ = millis();
      break;
      default:
      break;
    }
  }
 
  void RevertInOut() {
    char style_arg[10];
    itoa(arg_revert_, style_arg, 10);
    current_preset_.SetStyle(blade_num_,style_parser.SetArgument(current_preset_.GetStyle(blade_num_), set_num_ + 2, style_arg));
    switch (menu_type_) {
      case MENU_RETRACTION_OPTION:
      case MENU_RETRACTION_TIME:
      case MENU_RETRACTION_COOL_DOWN_OPTION:
      case MENU_RETRACTION_DELAY:
      char ig[10];
      itoa(ignite_time_, ig, 10);
      current_preset_.SetStyle(blade_num_,style_parser.SetArgument(current_preset_.GetStyle(blade_num_), RETRACTION_TIME_ARG, ig));
      break;
      default:
      break;
    }
    current_preset_.Save();
    SetPresetFast(current_preset_.preset_num);
  }
 
  void SayStyleNumber(int style_num) {
    sound_library_.SayStyle();
    sound_library_.SayNumber(style_num, SAY_WHOLE);
    if (style_parser.UsesArgument(current_preset_.GetStyle(blade_num_), STYLE_OPTION_ARG + 2)) {
      char argspace[32];
      style_parser.GetArgument(current_preset_.GetStyle(blade_num_), STYLE_OPTION_ARG + 2, argspace);
      int opt = strtol(argspace, NULL, 0);
      sound_library_.SayOption();
      sound_library_.SayNumber(opt, SAY_WHOLE);
    }
  }
 
  // Stop location/size previews in Style Settings Mode
  void StopSettingPreview() {
    switch (set_num_) {
      case LOCKUP_POSITION_ARG:
      show_lockup_position_.Stop(blade_num_);
      break;
 
      case DRAG_SIZE_ARG:
      case MELT_SIZE_ARG:
      show_drag_size_.Stop(blade_num_);
      break;
 
      case EMITTER_SIZE_ARG:
      case PREON_SIZE_ARG:
      show_emitter_size_.Stop(blade_num_);
      break;
 
      default:
      break;
    }
    UpdateStyle();
    menu_type_ = MENU_STYLE_SETTING_SUB;
  }
 
  // Save IntArg values 16 ~ 25 from Edit Mode Menu selection
  void SaveStyleSetting() {
    char style_arg[10];
    itoa(calc_, style_arg, 10);
    current_preset_.SetStyle(blade_num_,style_parser.SetArgument(current_preset_.GetStyle(blade_num_), set_num_ + 2, style_arg));
    current_preset_.Save();
    StopSettingPreview();
    MenuSave();
  }
 
  void CancelStyleSetting() {
    StopSettingPreview();
    MenuCancel();
  }
  #endif
 
  // Edit Color
  #define H_CHANGE (M_PI / 98304)
  #define L_ANGLE (M_PI / 30)
  #define H_ANGLE (M_PI / 16384)
  #define EDIT_MODE_ZOOM (M_PI * 2 / 2000)
 
  void EditColor() {
    if (edit_color_ && color_mode_ != COLOR_LIST)
    {
      float a = fusor.angle2() - hsl_angle_;
      if (a > M_PI) a-=M_PI*2;
      if (a < -M_PI) a+=M_PI*2;
      float angle = 100;
      switch (color_mode_) {
        case EDIT_COLOR: angle = H_ANGLE; break;
        case ZOOM_COLOR:
        case CC_ZOOM_COLOR:
        angle = EDIT_MODE_ZOOM;
        break;
        case EDIT_WHITE:
        case EDIT_BLACK: angle = L_ANGLE; break;
        default: break;
      }
      int steps = 0;
      if (a > angle * 2/3)
      {
        hsl_angle_ += angle;
        if (hsl_angle_ > M_PI) hsl_angle_ -= M_PI*2;
        steps++;
      }
      if (a < -angle * 2/3)
      {
        hsl_angle_ -= angle;
        if (hsl_angle_ < M_PI) hsl_angle_ += M_PI*2;
        steps--;
      }
      switch (color_mode_) {
        default: break;
        case EDIT_COLOR:
        case ZOOM_COLOR:
        case CC_ZOOM_COLOR:
        hsl_.H = fract(hsl_.H - H_CHANGE * steps);
        break;
 
        case EDIT_WHITE:
        if (steps > 0)
        {
          if (hsl_.L < 1.0)
          {
            hsl_.L = clamp(hsl_.L + 0.01, 0.5, 1.0);
            if (hsl_.L == 1.0)
            {
              sound_library_.SayMaximum();
              hsl_angle_ = fusor.angle2();
            }
          }
        }
        if (steps < 0)
        {
          if (hsl_.L > 0.5)
          {
            hsl_.L = clamp(hsl_.L - 0.01, 0.5, 1.0);
            if (hsl_.L == 0.5)
            {
              sound_library_.SayMinimum();
              hsl_angle_ = fusor.angle2();
            }
          }
        }
        break;
 
        case EDIT_BLACK:
        if (steps > 0)
        {
          if (hsl_.L < 0.5)
          {
            hsl_.L = clamp(hsl_.L + 0.01, 0.01, 0.5);
            if (hsl_.L == 0.5)
            {
              sound_library_.SayMaximum();
              hsl_angle_ = fusor.angle2();
            }
          }
        }
        if (steps < 0)
        {
          if (hsl_.L > 0.01)
          {
            hsl_.L = clamp(hsl_.L - 0.01, 0.01, 0.5);
            if (hsl_.L == 0.01)
            {
              sound_library_.SayMinimum();
              hsl_angle_ = fusor.angle2();
            }
          }
        }
        break;
      }
      ShowColorStyle::SetColor(Color16(hsl_));
    }
  }
 
  // Saves New Color from Edit Mode Preview Styles to Preset
  void NewColor(int blade, int effect) {
    STDOUT << "NewColor(" << blade << "," << effect << ")\n";
    char new_color[32];
    Color16 color_source;
    switch (color_mode_) {
      case COLOR_LIST:
      case CC_COLOR_LIST:
      color_source = Color16(color_list_[dial_].color);
      break;
 
      default:
      color_source = Color16(hsl_);
      break;
    }
    itoa(Color16(color_source).r, new_color, 10);
    strcat(new_color, ",");
    itoa(Color16(color_source).g, new_color + strlen(new_color), 10);
    strcat(new_color, ",");
    itoa(Color16(color_source).b, new_color + strlen(new_color), 10);
    #if NUM_BLADES > 1
    if (color_mode_ == CC_COLOR_LIST  || color_mode_ == CC_ZOOM_COLOR)
    {
      for (int i = 1; i <= NUM_BLADES; i++) {
        current_preset_.SetStyle(i,style_parser.SetArgument(current_preset_.GetStyle(i), effect + 2, new_color));
      }
    }
    else
    {
      current_preset_.SetStyle(blade,style_parser.SetArgument(current_preset_.GetStyle(blade), effect + 2, new_color));
    }
    #else
    current_preset_.SetStyle(blade,style_parser.SetArgument(current_preset_.GetStyle(blade), effect + 2, new_color));
    #endif
    color_mode_ = NONE;
  }
 
  // Toggles ColorChange Mode if current style uses RgbArg to CC_COLOR_LIST
  void ToggleCCMode() {
    bool uses_rgb_arg = false;
    for (int i = 1; i <= NUM_BLADES; i++)
    uses_rgb_arg |= style_parser.UsesArgument(current_preset_.GetStyle(i), 3);
    if (!uses_rgb_arg)
    {
      #ifndef DISABLE_COLOR_CHANGE
      ToggleColorChangeMode();
      #endif
    }
    else
    {
      bool handles_color_change;
      #define USES_COLOR_CHANGE(N) \
      handles_color_change |= current_config->blade##N->current_style() && current_config->blade##N->current_style()->IsHandled(HANDLED_FEATURE_CHANGE_TICKED);
      ONCEPERBLADE(USES_COLOR_CHANGE)
      if (!handles_color_change)
      {
        color_mode_ = CC_COLOR_LIST;
        show_color_all_.Start();
        for (int i = 1; i <= NUM_BLADES; i++) {
          if (style_parser.UsesArgument(current_preset_.GetStyle(i), BASE_COLOR_ARG + 2))
          {
            ShowColorStyle::SetColor(GetColorArg(i, BASE_COLOR_ARG));
            break;
          }
        }
        current_menu_angle_ = fusor.angle2();
        dial_ = -1;
        hybrid_font.PlayCommon(&SFX_ccbegin);
      }
      else
      {
        #ifndef DISABLE_COLOR_CHANGE
        ToggleColorChangeMode();
        #endif
      }
    }
  }
 
  void Setup() override {
    RestoreGestureState();
  }
 
  #ifdef FETT263_SAVE_CHOREOGRAPHY
  bool chdir(const char* dir) override {
    bool ret = PropBase::chdir(dir);
    RestoreChoreo();
    clash_count_ = 0;
    return ret;
  }
  #endif
 
  // Check Event "Delays" for Edit Mode for Ignition/Retraction/Preon Settings Previews and Choreography Save
  void CheckEvent() {
    if (next_event_ && !wav_player->isPlaying())
    {
        #ifdef FETT263_EDIT_MODE_MENU
        switch (menu_type_) {
          case MENU_IGNITION_TIME:
          case MENU_RETRACTION_TIME:
          next_event_ = false;
          SetInOut();
          break;
 
          default:
          next_event_ = false;
          break;
        }
        #endif
    }
 
    #ifdef FETT263_EDIT_MODE_MENU
    if (off_event_ && millis() - restart_millis_ > 200)
    {
      Off();
      off_event_ = false;
      restart_ = true;
      restart_millis_ = millis();
    }
    if (restart_ && (int)(millis() - restart_millis_) > ignite_time_ + 1000)
    {
      restart_ = false;
      FastOn();
    }
    #endif
  }
 
  enum ClashType {
    CLASH_NONE,
    CLASH_CHECK,
    CLASH_BATTLE_MODE,
    CLASH_LOCKUP,
    CLASH_LOCKUP_END,
    #ifdef FETT263_CLASH_STRENGTH_SOUND
    CLASH_NORMAL,
    CLASH_STAB,
    #endif
  };
 
  #ifdef FETT263_CLASH_STRENGTH_SOUND
  void HandleClash() {
    if (clash_type_ == CLASH_BATTLE_MODE)
    {
      if (SaberBase::GetClashStrength() < saved_gesture_control.clashdetect)
      {
        clash_type_ = CLASH_NORMAL;
      }
      else
      {
        clash_type_ = CLASH_LOCKUP;
        auto_lockup_on_ = true;
      }
    }
 
    if (saved_gesture_control.maxclash < 8) saved_gesture_control.maxclash = 8;
    float clash_value = (SaberBase::GetClashStrength() - GetCurrentClashThreshold()) / saved_gesture_control.maxclash;
    switch (clash_type_) {
      default:
      break;
      case CLASH_NORMAL:
      if (SFX_clash)
      {
        SFX_clash.SelectFloat(clash_value);
      }
      else
      {
        SFX_clsh.SelectFloat(clash_value);
      }
      SaberBase::DoClash();
      break;
      case CLASH_STAB:
      if (SFX_stab)
      {
        SFX_stab.SelectFloat(clash_value);
      }
      else
      {
        if (SFX_clash)
        {
          SFX_clash.SelectFloat(clash_value);
        }
        else
        {
          SFX_clsh.SelectFloat(clash_value);
        }
      }
      SaberBase::DoStab();
      break;
 
      case CLASH_LOCKUP:
      if (battle_mode_) clash_value = (SaberBase::GetClashStrength() - saved_gesture_control.clashdetect) / saved_gesture_control.maxclash;
      if (SFX_bgnlock)
      {
        SFX_bgnlock.SelectFloat(clash_value);
      }
      SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
      SaberBase::DoBeginLockup();
      break;
      case CLASH_LOCKUP_END:
      if (SFX_endlock)
      {
        float swing_value = fusor.swing_speed() / 600;
        SFX_endlock.SelectFloat(swing_value);
      }
      SaberBase::DoEndLockup();
      SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
      break;
    }
    clash_type_ = CLASH_NONE;
  }
  #endif
 
  void Loop() override {
    PropBase::Loop();
    DetectTwist();
    Vec3 mss = fusor.mss();
    if (clash_type_ != CLASH_NONE && millis() - clash_impact_millis_ > 1)
    {
      // CHECK PUSH
      if (clash_type_ == CLASH_CHECK)
      {
        Event(BUTTON_NONE, EVENT_PUSH);
        clash_type_ = CLASH_NONE;
      }
      if (clash_type_ != CLASH_LOCKUP_END)
      {
        #ifdef FETT263_CLASH_STRENGTH_SOUND
        HandleClash();
        #else
        if (clash_type_ == CLASH_BATTLE_MODE && SaberBase::GetClashStrength() > saved_gesture_control.clashdetect) {
          SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
          SaberBase::DoBeginLockup();
          auto_lockup_on_ = true;
        }
        else
        {
          SaberBase::DoClash();
        }
        clash_type_ = CLASH_NONE;
        #endif
      }
    }
    sound_library_.Poll(wav_player);
    #if defined(FETT263_EDIT_MODE_MENU) || defined(FETT263_SAVE_CHOREOGRAPHY)
    CheckEvent();
    #endif
    EditColor();
    if (SaberBase::IsOn())
    {
      DetectSwing();
 
      if (auto_lockup_on_ &&
        !swinging_ &&
        fusor.swing_speed() > 120 &&
        millis() - clash_impact_millis_ > saved_gesture_control.lockupdelay &&
        SaberBase::Lockup())
        {
          #ifdef FETT263_CLASH_STRENGTH_SOUND
          clash_type_ = CLASH_LOCKUP_END;
          HandleClash();
          #else
          SaberBase::DoEndLockup();
          SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
          #endif
          auto_lockup_on_ = false;
        }
 
        if (auto_melt_on_ &&
          !swinging_ &&
          fusor.swing_speed() > 60 &&
          millis() - clash_impact_millis_ > saved_gesture_control.lockupdelay &&
          SaberBase::Lockup())
          {
            SaberBase::DoEndLockup();
            SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
            auto_melt_on_ = false;
          }
 
          // EVENT_PUSH
          if (fabs(mss.x) < 3.0 &&
          mss.y * mss.y + mss.z * mss.z > 100 &&
          fusor.swing_speed() < 20 &&
          fabs(fusor.gyro().x) < 5)
          {
            if (millis() - push_begin_millis_ > saved_gesture_control.forcepushlen) {
              // Checking for Clash at end of movement
              clash_type_ = CLASH_CHECK;
              push_begin_millis_ = millis();
              clash_impact_millis_ = millis();
            }
          }
          else
          {
            push_begin_millis_ = millis();
          }
        }
        else
        {
          // EVENT_SWING - Swing On gesture control to allow fine tuning of speed needed to ignite
          if (menu_ || millis() - saber_off_time_millis_ < MOTION_TIMEOUT)
          {
            SaberBase::RequestMotion();
            if (swinging_ && fusor.swing_speed() < 90)
            {
              swinging_ = false;
            }
            if (!swinging_ && fusor.swing_speed() > saved_gesture_control.swingonspeed)
            {
              swinging_ = true;
              Event(BUTTON_NONE, EVENT_SWING);
            }
          }
          // EVENT_THRUST
          if (mss.y * mss.y + mss.z * mss.z < 16.0 &&
            mss.x > 14  &&
            fusor.swing_speed() < 150)
            {
              if (millis() - thrust_begin_millis_ > 15)
              {
                Event(BUTTON_NONE, EVENT_THRUST);
                thrust_begin_millis_ = millis();
              }
            }
            else
            {
              thrust_begin_millis_ = millis();
            }
          }
          DetectMenuTurn();
          #ifdef ENABLE_AUDIO
          TrackPlayer();
          #else
          STDOUT.println("Audio disabled.");
          #endif
        }
        //End of Loop()
 
        // Fett263 Track Player
        enum TrackMode {
          PLAYBACK_OFF,
          PLAYBACK_LOOP,
          PLAYBACK_ROTATE,
          PLAYBACK_RANDOM,
        };
 
        void StartTrackPlayer() {
          num_tracks_ = RunCommandAndGetSingleLine("list_current_tracks", nullptr, 0, 0, 0);
          if (num_tracks_ > 0)
          {
            sound_library_.SaySelect();
            StartMenu(MENU_TRACK_PLAYER);
            track_num_ = 1;
            PlayTrack();
          }
          else
          {
            // Loop default track if tracks not found
            sound_library_.SayLoop();
            track_num_ = 0;
            track_mode_ = PLAYBACK_LOOP;
            StartOrStopTrack();
          }
        }
 
        void TrackPlayer() {
          if (track_mode_ != PLAYBACK_OFF)
          {
            if (!track_player_)
            {
              if (track_num_ <= 0 && track_mode_ == PLAYBACK_LOOP)
              {
                StartOrStopTrack();
              }
              else
              {
                switch (track_mode_) {
                  case PLAYBACK_ROTATE:
                  track_num_ += 1;
                  if (track_num_ > num_tracks_) track_num_ = 1;
                  break;
                  case PLAYBACK_RANDOM:
                  track_num_ = rand() % num_tracks_;
                  if (track_num_ <= 0) track_num_ = num_tracks_;
                  break;
                  default:
                  break;
                }
                PlayTrack();
              }
            }
          }
          else
          {
            if (track_player_ && !track_player_->isPlaying())
            {
              track_player_.Free();
            }
          }
        }
 
        void PlayTrack() {
          char playtrack[128];
          RunCommandAndGetSingleLine("list_current_tracks", nullptr, track_num_, playtrack, sizeof(playtrack));
          MountSDCard();
          EnableAmplifier();
          track_player_ = GetFreeWavPlayer();
          if (track_player_)
          {
            track_player_->Play(playtrack);
          }
          else
          {
            STDOUT.println("No available WAV players.");
          }
        }
 
        void StopTrackPlayer() {
          track_mode_ = PLAYBACK_OFF;
          if (track_player_)
          {
            track_player_->Stop();
            track_player_.Free();
          }
          else
          {
            StartOrStopTrack();
          }
        }
 
        void SelectPreset(int preset) {
          #ifdef SAVE_PRESET
          SaveState(preset);
          #endif
          SetPreset(preset, true);
        }
 
        void DetectMenuTurn() {
          if (menu_ || color_mode_ == CC_COLOR_LIST)
          {
            float a = fusor.angle2() - current_menu_angle_;
            if (a > M_PI) a-=M_PI*2;
            if (a < -M_PI) a+=M_PI*2;
            if (a > twist_menu_ * 2/3)
            {
              Event(BUTTON_NONE, EVENT_TWIST_RIGHT);
              STDOUT.println("EVENT MENU TURN RIGHT");
              current_menu_angle_ = fusor.angle2();
            }
            if (a < -twist_menu_ * 2/3)
            {
              Event(BUTTON_NONE, EVENT_TWIST_LEFT);
              STDOUT.println("EVENT MENU TURN LEFT");
              current_menu_angle_ = fusor.angle2();
            }
          }
        }
 
        #ifdef FETT263_EDIT_MODE_MENU
        #define SUBMENUS 3
        #define COLOR_OPTIONS 3
        #define GESTURE_OPTIONS 12
        #define SET_SUBMENUS 5
        #endif
 
        enum MenuType {
          MENU_TOP,
          MENU_PRESET,
          MENU_VOLUME,
          MENU_TRACK_PLAYER,
          #ifdef FETT263_SAVE_CHOREOGRAPHY
          MENU_REHEARSE,
          #endif
          #ifdef FETT263_EDIT_MODE_MENU
          MENU_STYLE,
          MENU_COLOR,
          MENU_COLOR_CHANGE,
          MENU_FONT,
          MENU_TRACK,
          MENU_LENGTH,
          MENU_COPY,
          MENU_DELETE,
          MENU_RESET,
          MENU_EXIT,
          MENU_STYLE_SUB,
          MENU_COLOR_SUB,
          MENU_COLOR_MODE,
          MENU_EFFECT,
          MENU_RESET_COLOR,
          #if NUM_BLADES > 1
          MENU_COPY_COLOR,
          MENU_BLADE_STYLE,
          MENU_BLADE_COLOR,
          MENU_BLADE_COPY,
          MENU_BLADE_LENGTH,
          #endif
          MENU_GESTURE_SUB,
          MENU_SWINGON,
          MENU_TWISTON,
          MENU_THRUSTON,
          MENU_STABON,
          MENU_FORCEPUSH,
          MENU_TWISTOFF,
          MENU_POWERLOCK,
          MENU_SETTING_SUB,
          MENU_STYLE_SETTING_SUB,
          MENU_STYLE_OPTION,
          MENU_IGNITION_OPTION,
          MENU_IGNITION_TIME,
          MENU_IGNITION_POWER_UP_OPTION,
          MENU_IGNITION_DELAY,
          MENU_RETRACTION_OPTION,
          MENU_RETRACTION_TIME,
          MENU_RETRACTION_COOL_DOWN_OPTION,
          MENU_RETRACTION_DELAY,
          MENU_LOCKUP_POSITION,
          MENU_DRAG_SIZE,
          MENU_MELT_SIZE,
          MENU_SWING_OPTION,
          MENU_EMITTER_SIZE,
          MENU_PREON_OPTION,
          MENU_PREON_SIZE,
          MENU_DIM_BLADE,
          MENU_CLASH_THRESHOLD,
          MENU_SWINGON_SPEED,
          MENU_FORCEPUSH_LENGTH,
          MENU_LOCKUP_DELAY,
          MENU_CLASH_DETECT,
          MENU_MAX_CLASH,
          MENU_COLOR_BASE,
          MENU_COLOR_ALT,
          MENU_COLOR_BLAST,
          MENU_COLOR_CLASH,
          MENU_COLOR_LOCKUP,
          MENU_COLOR_DRAG,
          MENU_COLOR_LB,
          MENU_COLOR_STAB,
          MENU_COLOR_PREON,
          MENU_COLOR_IGNITE,
          MENU_COLOR_RETRACT,
          MENU_COLOR_PSTOFF,
          MENU_COLOR_SWING,
          MENU_COLOR_EMITTER,
          MENU_COLOR_OFF,
          #endif
        };
 
        enum MainMenu {
          EDIT_COLORS = 1,
          EDIT_BLADE_LENGTH = 2,
          EXIT_MENU = 3,
        };
 
        enum StyleSubMenu {
          EDIT_STYLE_SETTINGS = 2,
        };
 
        enum ColorSubMenu {
          EDIT_EFFECT_COLOR = 1,
          #if NUM_BLADES == 1
          RESET_COLORS = 2,
          #else
          COPY_COLORS = 2,
          RESET_COLORS = 3,
          #endif
        };
        enum ColorOptions {
          COLOR_LIST_MODE = 0,
          COLOR_HUE_MODE = 1,
          WHITE_MODE = 2,
          BLACK_MODE = 3,
        };
 
        enum SettingsMenu {
          EDIT_VOLUME = 1,
          EDIT_CONTROL_SETTINGS = 2,
          EDIT_CLASH_THRESHOLD = 3,
          EDIT_BRIGHTNESS = 5,
        };
 
        // Gesture Control Boolean Menu
        void EnterBooleanMenu(MenuType t, bool current_value) {
          menu_type_ = t;
          choice_ = current_value;
          sound_library_.SayBool(current_value);
        }
 
        int GetStyleNumber(int blade_num) {
          const char* tmp;
          tmp = current_preset_.GetStyle(blade_num);
          int style_num = FirstWord(tmp, "builtin") ? atoi(SkipWord(tmp)) : 0;
          return style_num;
        }
 
        void ChangeStyleNumber(int blade_num, int direction) {
          int num_presets = current_config->num_presets;
          int style_num = GetStyleNumber(blade_num);
          style_num += direction;
          if (style_num < 0) style_num = num_presets - 1;
          if (style_num >= num_presets) style_num = 0;
          char style_arg[10];
          itoa(style_num, style_arg, 10);
          current_preset_.SetStyle(blade_num, style_parser.SetArgument(current_preset_.GetStyle(blade_num), 1, style_arg));
        }
 
        void ChangeStyleNumberAllBlades(int direction) {
          for (int i = 1; i <= NUM_BLADES - 1; i++) {
            ChangeStyleNumber(i, direction);
          }
          current_preset_.Save();
          UpdateStyle();
        }
 
        // Uses font_num_ value for starting font, not current font
        void ChangeFont(int direction) {
          int num_fonts = RunCommandAndGetSingleLine("list_fonts", nullptr, 0, 0, 0);
          font_num_ += direction;
          if (font_num_ > num_fonts) font_num_ = 1;
          if (font_num_ <= 0) font_num_ = num_fonts;
          char font[128];
          RunCommandAndGetSingleLine("list_fonts", nullptr, font_num_, font, sizeof(font));
          strcat(font, ";common");
          current_preset_.font = mkstr(font);
          current_preset_.Save();
          SetPresetFast(current_preset_.preset_num);
          hybrid_font.SB_Effect(EFFECT_NEWFONT, 0);
        }
 
        int GetNumberOfPresets() {
          CurrentPreset tmp;
          tmp.SetPreset(-1);
          return tmp.preset_num + 1;
        }
 
        #ifdef FETT263_EDIT_MODE_MENU
        // Color Edit Helper Functions
        void SaveColorEdit() {
          menu_type_ = MENU_COLOR_MODE;
          edit_color_ = false;
          twist_menu_ = M_PI / 4;
          NewColor(blade_num_, effect_num_);
          current_preset_.Save();
          color_mode_ = NONE;
        }
 
        void RevertColorEdit() {
          menu_type_ = MENU_COLOR_MODE;
          edit_color_ = false;
          twist_menu_ = M_PI / 4;
          color_mode_ = NONE;
        }
 
        void StartEditMode() {
          if (track_player_)
          {
            StopTrackPlayer();
          }
 
          if (!SFX_medit)
          {
            talkie.Say(talkie_error_in_15, 15);
            talkie.Say(talkie_font_directory_15, 15);
            STDOUT.println("Edit Mode prompts missing");
          }
          else
          {
            STDOUT.println("Enter Edit Mode");
            GenerateIniFiles();
            sound_library_.SayEditMode();
            StartMenu(MENU_TOP);
            menu_top_pos_ = 0;
            FastOn();
          }
        }
        #endif
 
        void CopyPreset(bool announce) {
          int32_t pos = current_preset_.preset_num;
          current_preset_.preset_num = -1;
          current_preset_.SaveAt(pos);
          if (announce)
          {
            sound_library_.SayCopyPreset();
            wav_player.Free();
          }
        }
 
        // Check if ShowColor for ColorChange / Color Editing is active to prevent other events
        bool CheckShowColorCC() {
          if (color_mode_ == CC_COLOR_LIST || color_mode_ == CC_ZOOM_COLOR) return true;
          if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) return true;
          return false;
        }
 
        // Check to see if ShowColor style is being used and use MenuUndo to properly close if button presses or holds not in menu are used
        bool CancelShowColor() {
          if (color_mode_ != NONE)
          {
            if (CheckShowColorCC())
            {
              EndColorZoom();
              return true;
            }
            else
            {
              MenuUndo();
              return true;
            }
          }
          else
          {
            switch (menu_type_) {
              #ifdef FETT263_EDIT_MODE_MENU
              case MENU_LENGTH:
              #if NUM_BLADES > 1
              case MENU_BLADE_STYLE:
              case MENU_BLADE_COLOR:
              case MENU_BLADE_COPY:
              case MENU_BLADE_LENGTH:
              case MENU_COPY_COLOR:
              #endif
              MenuUndo();
              return true;
              break;
              #endif
              default:
              return false;
              break;
            }
          }
        }
 
        bool DoColorZoom() {
          if (SaberBase::GetColorChangeMode() == SaberBase::COLOR_CHANGE_MODE_SMOOTH)
          {
            SaberBase::SetColorChangeMode(SaberBase::COLOR_CHANGE_MODE_ZOOMED);
            return true;
          }
 
          if (color_mode_ == COLOR_LIST || color_mode_ == CC_COLOR_LIST)
          {
            hsl_ = Color16(color_list_[dial_].color).toHSL();
          }
 
          switch (color_mode_) {
            case COLOR_LIST:
            case EDIT_COLOR:
            color_mode_ = ZOOM_COLOR;
            hsl_angle_ = fusor.angle2();
            return true;
            break;
            case CC_COLOR_LIST:
            color_mode_ = CC_ZOOM_COLOR;
            edit_color_ = true;
            hsl_angle_ = fusor.angle2();
            return true;
            break;
            default:
            return false;
            break;
          }
        }
 
        // If Color Zoom mode is active save NewColor and end ShowColor style
        bool EndColorZoom() {
          #ifndef DISABLE_COLOR_CHANGE
          if (SaberBase::GetColorChangeMode() == SaberBase::COLOR_CHANGE_MODE_ZOOMED)
          {
            ToggleColorChangeMode();
            return true;
          }
          #endif
          switch(color_mode_) {
            case ZOOM_COLOR:
            case EDIT_COLOR:
            case COLOR_LIST:
            MenuChoice();
            return true;
            break;
            case CC_COLOR_LIST:
            case CC_ZOOM_COLOR:
            edit_color_ = false;
            NewColor(1, BASE_COLOR_ARG);
            current_preset_.Save();
            show_color_all_.Stop();
            UpdateStyle();
            wav_player.Free();
            return true;
            break;
            default:
            return false;
            break;
          }
        }
 
        // Start Menu Mode
        void StartMenu(MenuType menu) {
          current_menu_angle_ = fusor.angle2();
          menu_type_ = menu;
          menu_ = true;
        }
 
        // Edit Mode Menu Select (Aux Button)
        void MenuChoice() {
          switch (menu_type_) {
            case MENU_PRESET:
            sound_library_.SaySelect();
            menu_type_ = MENU_TOP;
            menu_ = false;
            break;
            #ifdef FETT263_SAVE_CHOREOGRAPHY
            case MENU_REHEARSE:
            if (choice_)
            {
              menu_ = false;
              BeginRehearsal();
            }
            else
            {
              MenuExit();
            }
            break;
            #endif
            case MENU_VOLUME:
            if (SaberBase::IsOn())
            {
              #ifdef FETT263_EDIT_MODE_MENU
              menu_type_ = MENU_SETTING_SUB;
              #endif
              MenuSave();
            }
            else
            {
              MenuExit();
            }
            break;
            #ifdef FETT263_EDIT_MODE_MENU
            case MENU_TOP:
            switch (menu_top_pos_) {
 
              case EDIT_COLORS:
              ToggleColorChangeMode();
              menu_type_ = MENU_COLOR;
              break;
 
              case EDIT_BLADE_LENGTH:
              sound_library_.SayEditBladeLength();
              #if (NUM_BLADES >= 2)
              menu_type_ = MENU_LENGTH;
              SaveState(current_preset_.preset_num);
              blade_num_ = 1;
              max_length_ = GetMaxBladeLength(blade_num_);
              blade_length_ = GetBladeLength(blade_num_);
              if (blade_length_ < 1) blade_length_ = max_length_;
              length_revert_ = blade_length_;
              LengthPreview(blade_num_);
              #endif
              break;
 
              case EXIT_MENU:
              sound_library_.SaySelect();
              MenuExit();
              break;
            }
            break;
            #if NUM_BLADES > 1
            case MENU_BLADE_STYLE:
            if (blade_num_ == 0) {
              sound_library_.SaySelectBlade();
              break;
            }
            show_preview_.Stop(blade_preview_);
            blade_preview_ = 0;
            menu_sub_pos_ = 0;
            menu_type_ = MENU_STYLE_SUB;
            sound_library_.SaySelectOption();
            break;
            case MENU_BLADE_COLOR:
            #if NUM_BLADES > 2
            copy_blade_ = blade_num_;
            sound_library_.SayColorMenu();
            #else
            if (blade_num_ == 1)
            {
              copy_blade_ = 2;
            }
            else
            {
              copy_blade_ = 1;
            }
            sound_library_.SaySelectOption();
            #endif
            menu_type_ = MENU_COLOR_SUB;
            menu_sub_pos_ = 0;
            show_preview_.Stop(blade_preview_);
            blade_preview_ = 0;
            break;
            case MENU_BLADE_COPY:
            menu_type_ = MENU_COPY_COLOR;
            CopyColors();
            MenuConfirm();
            break;
 
            case MENU_COPY_COLOR:
            if (choice_)
            {
              current_preset_.SetStyle(copy_blade_, style_parser.CopyArguments(current_preset_.GetStyle(blade_num_), current_preset_.GetStyle(copy_blade_), int_arg_menu_, NELEM(int_arg_menu_)));
              DOVALIDATE(current_preset_);
              current_preset_.Save();
              DOVALIDATE(current_preset_);
              show_preview_.Stop(blade_preview_);
              UpdateStyle();
              menu_type_ = MENU_COLOR_SUB;
              MenuSelect();
              choice_ = false;
              blade_preview_ = 0;
              break;
            }
            sound_library_.SayConfirm();
            break;
            #endif
 
            case MENU_STYLE_SUB:
            switch (menu_sub_pos_) {
              case EDIT_STYLE_SETTINGS:
              effect_num_ = 0;
              menu_type_ = MENU_STYLE_SETTING_SUB;
              sound_library_.SaySelectOption();
              arg_dial_ = -1;
              break;
 
              default:
              sound_library_.SaySelectOption();
            }
            break;
 
            case MENU_COLOR:
            if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE)
            {
              ToggleColorChangeMode();
            }
            menu_type_ = MENU_TOP;
            MenuExit();
            break;
 
            case MENU_LENGTH:
            menu_type_ = MENU_TOP;
            current_preset_.Save();
            show_length_.Stop(blade_num_);
            UpdateStyle();
            MenuExit();
            break;
 
            case MENU_EXIT:
            sound_library_.SaySelect();
            MenuExit();
            break;
 
            #endif
            default:
            break;
          }
        }
        // end menu choice
 
        void MenuDialIncrement(int direction) {
          switch (menu_type_) {
            case MENU_PRESET:
            #ifdef FETT263_EDIT_MODE_MENU
            case MENU_FONT:
            case MENU_TRACK:
            case MENU_LENGTH:
            #endif
            direction *= 5;
            break;
 
            default:
            break;
          }
          MenuDial(direction);
        }
 
        // Edit Mode Dial
        void MenuDial(int direction) {
          switch (menu_type_) {
            default:
            break;
 
            case MENU_PRESET:
            if (SaberBase::IsOn())
            {
              if (direction > 0)
              {
                next_preset_fast();
              }
              else
              {
                previous_preset_fast();
              }
            }
            else
            {
              int num_presets = GetNumberOfPresets();
              int preset = (current_preset_.preset_num + num_presets * 10 + direction) % num_presets;
              SelectPreset(preset);
            }
            break;
 
            case MENU_VOLUME:
            if (direction > 0)
            {
              VolumeUp();
            }
            else
            {
              VolumeDown();
            }
            break;
 
            #ifdef FETT263_EDIT_MODE_MENU
            case MENU_TOP:
            menu_top_pos_ += direction;
            if (menu_top_pos_ <= 0) menu_top_pos_ = SUBMENUS;
            if (menu_top_pos_ > SUBMENUS) menu_top_pos_ = 1;
            switch (menu_top_pos_) {
              case EDIT_COLORS:
              sound_library_.SayEditColor();
              break;
 
              case EDIT_BLADE_LENGTH:
              sound_library_.SayEditBladeLength();
              break;
 
              case EXIT_MENU:
              sound_library_.SayExit();
              break;
            }
            break;
 
            #if NUM_BLADES > 1
            case MENU_BLADE_LENGTH:
            blade_num_ += direction;
            if (blade_num_ > NUM_BLADES) blade_num_ = 1;
            if (blade_num_ <= 0) blade_num_ = NUM_BLADES;
            BladePreview(blade_num_);
            sound_library_.SayNumber(blade_num_, SAY_WHOLE);
            break;
 
            break;
 
            #else
            if (menu_sub_pos_ <= 0) menu_sub_pos_ = 3;
            if (menu_sub_pos_ > 3) menu_sub_pos_ = 1;
            switch (menu_sub_pos_) {
              case RESET_COLORS:
              sound_library_.SayResetColors();
              break;
            }
            #endif
            break;
 
            case MENU_FONT:
            if (!restore_point.get()) restore_point = std::move(current_preset_.font);
            ChangeFont(direction);
            break;
 
            case MENU_LENGTH:
            if (direction>0)
            {
              hybrid_font.PlayCommon(&SFX_plus);
            }
            else
            {
              hybrid_font.PlayCommon(&SFX_minus);
            }
 
            blade_length_ += direction;
            if (blade_length_ >= max_length_)
            {
              sound_library_.SayMaximum();
              blade_length_ = max_length_;
            }
            if (blade_length_ <= 1)
            {
              sound_library_.SayMinimum();
              blade_length_ = 1;
            }
            length_edit_length = blade_length_ - 1;
            SetBladeLength(blade_num_, blade_length_);
            SaveState(current_preset_.preset_num);
            break;
 
            case MENU_TWISTON:
            case MENU_TWISTOFF:
            case MENU_STYLE_SETTING_SUB:
            for (int i = 0; i < (int)NELEM(int_arg_menu_); i++) {
              arg_dial_ += direction;
              if (direction > 0)
              {
                // Detect preon.wav for setting preview (cannot be shown without so skip over)
                if (!SFX_preon && (int_arg_menu_[arg_dial_] == PREON_OPTION_ARG || int_arg_menu_[arg_dial_] == PREON_SIZE_ARG)) arg_dial_ = 0;
                if (arg_dial_ > (int)NELEM(int_arg_menu_) - 1) arg_dial_ = 0;
              }
              else
              {
                // Detect preon.wav for setting preview (cannot be shown without so skip over)
                if (!SFX_preon && (int_arg_menu_[arg_dial_] == PREON_OPTION_ARG || int_arg_menu_[arg_dial_] == PREON_SIZE_ARG)) arg_dial_ = NELEM(int_arg_menu_) - 3;
                if (arg_dial_ < 0) arg_dial_ = NELEM(int_arg_menu_) - 1;
              }
              set_num_ = int_arg_menu_[arg_dial_];
              if (style_parser.UsesArgument(current_preset_.GetStyle(blade_num_), set_num_ + 2)) break;
            }
 
            #endif
          }
        }
 
        //end of EditMode Dial
 
        // Edit Mode Undo (POWER Button)
        void MenuUndo() {
          switch (menu_type_) {
            case MENU_TOP:
            sound_library_.SayExit();
            MenuExit();
            break;
 
            #ifdef FETT263_EDIT_MODE_MENU
            case MENU_VOLUME:
            menu_type_ = MENU_SETTING_SUB;
            dynamic_mixer.set_volume(VOLUME);
            MenuRevert();
            break;
 
            #if NUM_BLADES > 1
 
            case MENU_BLADE_LENGTH:
            menu_type_ = MENU_SETTING_SUB;
            show_preview_.Stop(blade_preview_);
            blade_preview_ = 0;
            MenuCancel();
            break;
 
            #endif
 
            case MENU_COLOR:
            ToggleColorChangeMode();
            SaberBase::SetVariation(0);
            current_preset_.SetStyle(blade_num_, style_parser.CopyArguments("~", current_preset_.GetStyle(blade_num_),  int_arg_menu_, NELEM(int_arg_menu_)));
            current_preset_.Save();
            UpdateStyle();
            menu_type_ = MENU_TOP;
            MenuRevert();
            MenuExit();
            break;
 
            case MENU_COLOR_SUB:
            #if NUM_BLADES == 1
            menu_type_ = MENU_TOP;
            MenuCancel();
            break;
 
            #else
            menu_type_ = MENU_BLADE_COLOR;
            show_preview_.Stop(blade_preview_);
            blade_preview_ = 0;
            blade_num_ = 0;
            MenuCancel();
            break;
 
            #endif
            case MENU_COLOR_MODE:
            edit_color_ = false;
            menu_type_ = MENU_EFFECT;
            MenuCancel();
            break;
 
            case MENU_LENGTH:
            menu_type_ = MENU_TOP;
            SetBladeLength(blade_num_, length_revert_);
            SaveState(current_preset_.preset_num);
            MenuRevert();
            show_length_.Stop(blade_num_);
            UpdateStyle();
            MenuExit();
            break;
 
            case MENU_EXIT:
            default:
            choice_ = false;
            menu_type_ = MENU_TOP;
            MenuCancel();
            break;
            #endif
          }
        }
        // End of Edit MenuUndo
 
        // Exit Edit Mode
        void MenuExit() {
          switch (menu_type_) {
 
            case MENU_PRESET:
            first_preset();
            sound_library_.SaySelect();
            break;
 
            case MENU_VOLUME:
            if (SFX_vmend)
            {
              sound_library_.SayVolumeMenuEnd();
            }
            else
            {
              sound_library_.SayExit();
            }
            break;
 
            default:
            break;
          }
          menu_type_ = MENU_TOP;
          menu_ = false;
          wav_player.Free();
        }
 
        void MenuSave() {
          sound_library_.SaySave();
          //MenuPrompt();
        }
 
        void MenuSelect() {
          sound_library_.SaySelect();
          MenuPrompt();
        }
 
        void MenuConfirm() {
          sound_library_.SayConfirm();
          MenuPrompt();
        }
 
        void MenuCancel() {
          sound_library_.SayCancel();
          MenuPrompt();
        }
 
        void MenuRevert() {
          sound_library_.SayRevert();
          //MenuPrompt();
        }
 
        void MenuPrompt() {
          switch (menu_type_) {
            case MENU_TOP:
            sound_library_.SayMainMenu();
            break;
 
            default:
            break;
          }
        }
 
        enum EditColorMode {
          NONE,
          CC_COLOR_LIST,
          CC_ZOOM_COLOR,
          COLOR_LIST,
          EDIT_COLOR,
          EDIT_BLACK,
          EDIT_WHITE,
          ZOOM_COLOR,
        };
 
        bool Parse(const char *cmd, const char* arg) override {
          if (PropBase::Parse(cmd, arg)) return true;
          if (!strcmp(cmd, "list_current_tracks"))
          {
            // Tracks must be in: font/tracks/*.wav
            LOCK_SD(true);
            for (const char* dir = current_directory; dir; dir = next_current_directory(dir)) {
              PathHelper path(dir, "tracks");
              ListTracks(path);
            }
            LOCK_SD(false);
            return true;
          }
          if (!strcmp(cmd, "get_gesture") && arg)
          {
            saved_gesture_control.Print(arg);
            return true;
          }
          if (!strcmp(cmd, "set_gesture") && arg)
          {
            saved_gesture_control.Set(arg);
            SaveGestureState();
            return true;
          }
          #ifndef DISABLE_DIAGNOSTIC_COMMANDS
          if (!strcmp(cmd, "left") || !strcmp(cmd, "l"))
          {
            MenuDial(-1);
            return true;
          }
          if (!strcmp(cmd, "right") || !strcmp(cmd, "r"))
          {
            MenuDial(1);
            return true;
          }
          #endif
          return false;
        }
 
        void ToggleBattleMode() {
          if (!battle_mode_)
          {
            battle_mode_ = true;
            if (SFX_bmbegin)
            {
              hybrid_font.PlayCommon(&SFX_bmbegin);
            }
            else
            {
              hybrid_font.DoEffect(EFFECT_FORCE, 0);
            }
          }
          else
          {
            battle_mode_ = false;
            if (SFX_bmend)
            {
              hybrid_font.PlayCommon(&SFX_bmend);
            }
            else
            {
              beeper.Beep(0.5, 3000);
            }
          }
        }
 
        void ToggleMultiBlast() {
          swing_blast_ = !swing_blast_;
          if (swing_blast_)
          {
            if (SFX_blstbgn)
            {
              hybrid_font.PlayCommon(&SFX_blstbgn);
            }
            else
            {
              hybrid_font.SB_Effect(EFFECT_BLAST, 0);
            }
          }
          else
          {
            if (SFX_blstend)
            {
              hybrid_font.PlayCommon(&SFX_blstend);
            }
            else
            {
              hybrid_font.SB_Effect(EFFECT_BLAST, 0);
            }
          }
        }
 
        void ToggleBattleModeMultiBlast() {
          if (battle_mode_ && !swing_blast_) {
            check_blast_ = true;
            last_blast_millis_ = millis();
          }
          swing_blast_ = false;
        }
 
        void DoAutoMultiBlast() {
          if (check_blast_)
          {
            if (millis() - last_blast_millis_ < 2000)
            {
              swing_blast_ = true;
              SaberBase::DoBlast();
            }
            check_blast_ = false;
          }
        }
        void DoIgnition() {
          #ifdef FETT263_DUAL_MODE_SOUND
          SelectIgnitionSound();
          #endif
          if (SFX_preon)
          {
            #ifdef FETT263_DUAL_MODE_SOUND
            SelectPreonSound();
            #endif
            On();
          }
          else
          {
            FastOn();
          }
          #ifdef FETT263_BATTLE_MODE_ALWAYS_ON
          battle_mode_ = true;
          #endif
          #ifdef FETT263_BATTLE_MODE_START_ON
          battle_mode_ = true;
          #endif
        }
 
        #ifdef FETT263_DUAL_MODE_SOUND
        // Select preon wav based on blade orientation if more than 1 file, up = odd, down = even
        void SelectPreonSound() {
          SelectSFXEvenOdd(&SFX_preon);
        }
 
        // Select ignition wav based on blade orientation, up = odd, down = even
        void SelectIgnitionSound() {
          Effect* effect;
          if (SFX_poweron)
          {
            effect = &SFX_poweron;
          }
          else
          {
            effect = &SFX_out;
          }
          SelectSFXEvenOdd(effect);
        }
 
        // Select retraction wav based on blade orientation, up = odd, down = even
        // Do not mix poweroff.wav and pwroff.wav files in font or selection will not work
        void SelectRetractionSound() {
          Effect* effect;
          if (SFX_poweroff)
          {
            effect = &SFX_poweroff;
          }
          else if (SFX_pwroff)
          {
            effect = &SFX_pwroff;
          }
          else
          {
            effect = &SFX_in;
          }
          SelectSFXEvenOdd(effect);
          if (SFX_pstoff) SelectSFXEvenOdd(&SFX_pstoff);
        }
 
        // Select wav file based on blade orientation, up = odd, down = even
        void SelectSFXEvenOdd(Effect* effect) {
          int f = effect->files_found();
          if (f > 1)
          {
            if (fusor.angle1() > 0)
            {
              f = (rand() % ((f + 1)/ 2)) * 2;
            }
            else
            {
              f = 1 + (rand() % (f / 2)) * 2;
            }
            effect->Select(f);
          }
        }
        #endif
 
        void ForceQuote() {
          if (force_quote_) {
            SFX_quote.SelectNext();
            hybrid_font.PlayCommon(&SFX_quote);
          } else {
            SaberBase::DoForce();
          }
        }
 
        // Battery Level
        void DoBattery() {
          SaberBase::DoEffect(EFFECT_BATTERY_LEVEL, 0);
        }
 
        // Go to first Preset.
        void first_preset() {
          #ifdef SAVE_PRESET
          SaveState(0);
          #endif
          SetPreset(0, true);
        }
 
        // SA22C Volume Menu
        void VolumeUp() {
          STDOUT.println("Volume up");
          if (dynamic_mixer.get_volume() < VOLUME)
          {
            dynamic_mixer.set_volume(std::min<int>(VOLUME + VOLUME * 0.1,
              dynamic_mixer.get_volume() + VOLUME * 0.10));
              hybrid_font.PlayCommon(&SFX_volup);
              STDOUT.print("Current Volume: ");
              STDOUT.println(dynamic_mixer.get_volume());
            }
            else
            {
              hybrid_font.PlayCommon(&SFX_volmax);
            }
          }
 
          void VolumeDown() {
            STDOUT.println("Volume Down");
            if (dynamic_mixer.get_volume() > (0.10 * VOLUME))
            {
              dynamic_mixer.set_volume(std::max<int>(VOLUME * 0.1,
                dynamic_mixer.get_volume() - VOLUME * 0.10));
                hybrid_font.PlayCommon(&SFX_voldown);
                STDOUT.print("Current Volume: ");
                STDOUT.println(dynamic_mixer.get_volume());
              }
              else
              {
                hybrid_font.PlayCommon(&SFX_volmin);
              }
            }
 
            // S3 - Soundbank Selection / Preset Menu
            void PresetMenu(bool preset_forward_)
            {
              if(preset_forward_)
              {
                next_preset();
              }
              else
              {
                previous_preset();
              }
            }
 
            RefPtr<BufferedWavPlayer> wav_player;
            float current_menu_angle_ = 0.0;
            float current_twist_angle_ = 0.0;
            float clash_t_ = 2.00;
            #ifdef FETT263_EDIT_MODE_MENU
            LSPtr<char> restore_point;
            int blade_length_;
            int max_length_;
            float dim;
            float dim_revert_;
            #endif
 
            bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
              {
                switch (EVENTID(button, event, modifiers))
                {
                  case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_ON):
                  case EVENTID(BUTTON_AUX, EVENT_PRESSED, MODE_ON):
                  if (accel_.x < -0.15)
                  {
                    pointing_down_ = true;
                  }
 
                  else
                  {
                    pointing_down_ = false;
                  }
                  return true;
 
                  // S3 - Saber ON , Volume Down & Preset Menu foward
                  case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_OFF):
                  case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_OFF):
 
                  //Volume Down if in mode volume
                  if (mode_volume_)
                  {
                    VolumeDown();
                  }
                  else
                  {
                    //Checks if in preset menu and moves preset forward
                    if(preset_menu_)
                    {
                      preset_forward_= false;
                      PresetMenu(preset_forward_);
                      return true;
                    }
 
                    //Checks if blade is not detected and plays no blade sound
                    if(!blade_detected_)
                    {
                      Off();
                      hybrid_font.PlayCommon(&SFX_no_blade);
                      return true;
                    }
                    //Saber only turns on out of preset menu
                    else
                    {
                      aux_on_ = false;
                      On();
                    }
                  }
 
                  return true;
 
                  // S3 - Battery Indicator & Volume Up
                  case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_OFF):
                  case EVENTID(BUTTON_AUX, EVENT_CLICK_LONG, MODE_OFF):
 
                  // Volume Up if in Volume Mode
                  if(mode_volume_)
                  {
                    VolumeUp();
                  }
                  else
                  {
                    //checks if saber is in preset menu and moves preset forward
                    if (preset_menu_)
                    {
                      preset_forward_ = true;
                      PresetMenu(preset_forward_);
                    }
 
                    //if saber not in preset menu and off, display battery level
                    else
                    {
                       SaberBase::DoEffect(EFFECT_BATTERY_LEVEL, 0);
                    }
                  }
                  return true;
 
                  //S3 - Enter Volume Menu
                  case EVENTID(BUTTON_AUX, EVENT_HELD_LONG, MODE_OFF | BUTTON_POWER):
                  if (!mode_volume_ && !preset_menu_)
                  {
                    mode_volume_ = true;
                    if (SFX_vmbegin)
                    {
                      hybrid_font.PlayCommon(&SFX_vmbegin);
                    }
                    else
                    {
                      beeper.Beep(0.5, 3000);
                    }
                  }
                  else {
                    mode_volume_ = false;
                    if (SFX_vmend && !preset_menu_)
                    {
                      hybrid_font.PlayCommon(&SFX_vmend);
                    }
                    else
                    {
                      if(!preset_menu_)
                      {
                        beeper.Beep(0.5, 3000);
                      }
 
                    }
                  }
                  return true;
 
                  //S3 - Mute Mode
                  case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_OFF | BUTTON_AUX):
                  if(!mode_volume_ && blade_detected_)
                  {
                    hybrid_font.PlayCommon(&SFX_mute);
                    delay(500);
                    if(SetMute(true))
                    {
                      unmute_on_deactivation_ = true;
                      On();
                    }
                    return true;
 
                  }
                  return false;
 
                  //S3 - Detects Twist for Saber On
                  case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_OFF):
                  if (!saved_gesture_control.gestureon) return true;
                  if (!saved_gesture_control.twiston) return true;
                  if(!mode_volume_ && !preset_menu_)
                  {
                    //Checks if blade is no detected and plays no blade sound
                    if(!blade_detected_)
                    {
                      Off();
                      hybrid_font.PlayCommon(&SFX_no_blade);
                      return true;
                    }
                    // Delays twist events to prevent false trigger from over twisting
                    else if (millis() - last_twist_ > 1000 && millis() - saber_off_time_ > 1000)
                    {
                      On();
                      last_twist_ = millis();
                    }
                    return true;
                  }
                  return false;
 
                  //S3 - Detects Twist for Saber Off
                  case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_ON):
                  if(menu_) return true;
                  if (!saved_gesture_control.twistoff) return true;
                  // Checks if blade is not detected and plays no blade sound
                  if(!blade_detected_)
                  {
                    Off();
                    hybrid_font.PlayCommon(&SFX_no_blade);
                    return true;
                  }
                  else if(!SaberBase::Lockup())
                  {
                    if (SaberBase::GetColorChangeMode() == SaberBase::COLOR_CHANGE_MODE_NONE && !preset_menu_)
                    {
                      // Delay twist events to prevent false trigger from over twisting
                      if (millis() - last_twist_ > 1000)
                      {
                        Off();
                        last_twist_= millis();
                      }
                    }
                  }
                  return true;
 
                  // Gesture Sleep Toggle
                  case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_OFF | BUTTON_POWER):
                  if (!menu_)
                  {
                    if (!saved_gesture_control.gestureon)
                    {
                      saved_gesture_control.twistoff = true;
                      saved_gesture_control.gestureon = true;
                      sound_library_.SayGesturesOn();
                    }
                    else
                    {
                      saved_gesture_control.gestureon = false;
                      saved_gesture_control.twistoff = false;
                      sound_library_.SayGesturesOff();
                    }
                    SaveGestureState();
                  }
                  return true;
 
                  // Gesture Controls (not button specific)
                  case EVENTID(BUTTON_NONE, EVENT_TWIST_RIGHT, MODE_ON):
                  if (wav_player && wav_player->isPlaying())
                  {
                    current_menu_angle_ = fusor.angle2();
                    return true;
                  }
                  if (menu_) MenuDial(1);
                  return true;
 
                  case EVENTID(BUTTON_NONE, EVENT_TWIST_LEFT, MODE_ON):
                  if (wav_player && wav_player->isPlaying())
                  {
                    current_menu_angle_ = fusor.angle2();
                    return true;
                  }
                  if (menu_) MenuDial(-1);
                  return true;
 
                  case EVENTID(BUTTON_NONE, EVENT_TWIST_RIGHT, MODE_OFF):
                  if (wav_player && wav_player->isPlaying())
                  {
                    current_menu_angle_ = fusor.angle2();
                    return true;
                  }
                  if (menu_) MenuDial(1);
                  return true;
 
                  case EVENTID(BUTTON_NONE, EVENT_TWIST_LEFT, MODE_OFF):
                  if (wav_player && wav_player->isPlaying())
                  {
                    current_menu_angle_ = fusor.angle2();
                    return true;
                  }
                  if (menu_) MenuDial(-1);
                  return true;
 
                  // S3 - Blade OFF
                  case EVENTID(BUTTON_POWER, EVENT_HELD_MEDIUM, MODE_ON):
                  if(menu_) return false;
 
                  //Checks if no blade detected and plays no blade sound
                  if(!blade_detected_)
                  {
                    Off();
                    hybrid_font.PlayCommon(&SFX_no_blade);
                    return true;
                  }
                  else if (SaberBase::GetColorChangeMode() == SaberBase::COLOR_CHANGE_MODE_NONE)
                  {
                    Off();
                    return true;
                  }
                  return false;
 
                  // S3 - Exits Volume Menu & Enters Soundbank Selection
                  case EVENTID(BUTTON_AUX, EVENT_HELD_LONG, MODE_OFF):
                  if(mode_volume_)
                  {
                    mode_volume_ = false;
                    if(SFX_vmend)
                    {
                      hybrid_font.PlayCommon(&SFX_vmend);
                    }
                    else
                    {
                      beeper.Beep(0.5,3000);
                    }
                    STDOUT.println("Exit Volume Menu");
                    return true;
                  }
 
                  // Enters Soundbank Selection / Preset Menu
                  if(!preset_menu_)
                  {
                    preset_menu_ = true;
                    preset_forward_ = true;
                    hybrid_font.PlayCommon(&SFX_fontmenu);
                    delay(2100);
                    hybrid_font.PlayCommon(&SFX_font);
                    SaberBase::DoNewFont();
                  }
                  else
                  // Exits Soundbank Selection / Preset Menu
                  {
                    preset_menu_ = false;
                    hybrid_font.PlayCommon(&SFX_boot);
                  }
                  return true;
 
                  // S3 - Exit Volume Menu, Saber On ,Previous Soundfont & Exit Soundfont
                  case EVENTID(BUTTON_POWER, EVENT_HELD_LONG, MODE_OFF):
 
                  // Exits volume menu
                  if(mode_volume_)
                  {
                    mode_volume_ = false;
                    if (SFX_vmend)
                    {
                      hybrid_font.PlayCommon(&SFX_vmend);
                    }
                    else
                    {
                      beeper.Beep(0.5, 3000);
                    }
                    STDOUT.println("Exit Volume Menu");
                  }
                  else
                  {
                    // Checks if in preset menu and exits
                    if(preset_menu_)
                    {
                      preset_menu_ = false;
                      hybrid_font.PlayCommon(&SFX_boot);
                      return true;
 
                    }
                    else
                    {
                      //Checks if blade is not detected and plays no blade sound
                      if(!blade_detected_)
                      {
                        Off();
                        hybrid_font.PlayCommon(&SFX_no_blade);
                        return true;
                      }
                      //Saber only turns on out of preset menu
                      else
                      {
                        aux_on_ = false;
                        On();
                      }
                    }
                  }
                  return true;
 
                  // S3 - Start or Stop Track
                  case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_OFF | BUTTON_POWER):
                  if(!mode_volume_)
                  {
                    StartOrStopTrack();
                  }
                  return true;
 
                  case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_ON | BUTTON_POWER):
                  if (!mode_volume_ && !menu_)
                  {
                    StartOrStopTrack();
                  }
                  return true;
 
                  case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_OFF):
                  case EVENTID(BUTTON_AUX, EVENT_PRESSED, MODE_OFF):
                  SaberBase::RequestMotion();
                  return true;
 
                  // S3 - Saves Menu / Blaster Block
                  case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_ON):
 
                  // Handles exit/toggle while in KyberDial
                  if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE
                  && menu_type_ == MENU_COLOR)
                  {
                    MenuChoice();
                    MenuSave();
                    menu_time_ = millis();
                  }
 
                  // Saves Settings in Settings Menu
                  if(menu_)
                  {
                    MenuChoice();
                    MenuSave();
                    menu_time_ = millis();
                  }
 
                  if (!SaberBase::Lockup()&& !menu_)
                  {
                    if (SaberBase::GetColorChangeMode() == SaberBase::COLOR_CHANGE_MODE_NONE)
                    {
                      if(millis() - menu_time_ > 1000 )
                      {
                        DoBlast();
                      }
                    }
                  }
                  return true;
 
                  // S3 - Reverts options on Menu
                  case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_ON):
 
                  // Handles exit/toggle while in KyberDial
                  if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE
                  && menu_type_ == MENU_COLOR)
                  {
                    MenuUndo();
                    menu_time_ = millis();
                  }
 
                  if(menu_)
                  {
                    MenuUndo();
                    menu_time_ = millis();
                  }
                  return true;
 
                  // S3 - Cycles to next settings while in Menu
                  case EVENTID(BUTTON_AUX, EVENT_HELD_LONG, MODE_ON):
 
                  // Handles KyberDial exit/toggle to BladeLength transition
                  if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE
                  && menu_type_ == MENU_COLOR)
                  {
                    ToggleColorChangeMode();
                    menu_ = true;
                  }
 
                  // Switching from KyberDial to BladeLength
                  if(menu_)
                  {
                    if(menu_type_ == MENU_COLOR)
                    {
                      if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE)
                      {
                        ToggleColorChangeMode();
                      }
                      menu_type_ = MENU_TOP;
                      menu_top_pos_ = 2;
                      MenuChoice();
                    }
                    else if(menu_type_ == MENU_LENGTH)
                    {
                      MenuChoice();
                      menu_type_ = MENU_TOP;
                      menu_top_pos_ = 1;
                      MenuChoice();
                    }
                  }
                  return true;
 
                  // S3- Cycles to next settings while in Menu
                  case EVENTID(BUTTON_POWER, EVENT_HELD_LONG, MODE_ON):
 
                  // Handles KyberDial toggle/exit to BladeLength transition
                  if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE
                  && menu_type_ == MENU_COLOR)
                  {
                    ToggleColorChangeMode();
                    menu_ = true;
                  }
 
                  // Switching from KyberDial to BladeLength
                  if(menu_)
                  {
                    if(menu_type_ == MENU_COLOR)
                    {
                      if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE)
                      {
                        ToggleColorChangeMode();
                      }
                      menu_type_ = MENU_TOP;
                      menu_top_pos_ = 2;
                      MenuChoice();
                    }
                    else if(menu_type_ == MENU_LENGTH)
                    {
                      MenuChoice();
                      menu_type_ = MENU_TOP;
                      menu_top_pos_ = 1;
                      MenuChoice();
                    }
                  }
                  return true;
 
                  // S3 - Lightning Block
                  case EVENTID(BUTTON_POWER, EVENT_SECOND_HELD, MODE_ON):
                  if(menu_) return true;
                  if (SaberBase::GetColorChangeMode() == SaberBase::COLOR_CHANGE_MODE_NONE)
                  {
                    SaberBase::SetLockup(SaberBase::LOCKUP_LIGHTNING_BLOCK);
                    SaberBase::DoBeginLockup();
                    return true;
                  }
                  return false;
 
                  // S3 - Lockup & Drag
                  case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_AUX):
 
                  if (!SaberBase::Lockup())
                  {
                    if (pointing_down_)
                    {
                      SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
                    }
                    else
                    {
                      SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
                    }
                    SaberBase::DoBeginLockup();
                    return true;
                  }
                  return false;
 
                  // S3 - Melt Lockup
                  case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_ON | BUTTON_AUX):
                  if (!SaberBase::Lockup())
                  {
                    SaberBase::SetLockup(SaberBase::LOCKUP_MELT);
                    SaberBase::DoBeginLockup();
                    return true;
                  }
                  return false;
 
                  // S3 - Toggle color change mode
                  case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_ON | BUTTON_AUX):
                  #ifdef FETT263_EDIT_MODE_MENU
                  // Enters KyberDial
                  if(!menu_)
                  {
                    StartMenu(MENU_TOP);
                    menu_top_pos_ = 1;
                    MenuChoice();
                  }
                  #else
                  // If Edit Mode Menu Disabled Save .ini files for SD card editing
                  if (menu_) return true;
                  GenerateIniFiles();
                  sound_library_.SaySave();
                  #endif
                  return true;
 
                  // S3 - Force
                  case EVENTID(BUTTON_AUX, EVENT_HELD_MEDIUM, MODE_ON):
                  if(menu_) return false;
                  if (SaberBase::GetColorChangeMode() == SaberBase::COLOR_CHANGE_MODE_NONE)
                  {
                    SaberBase::DoForce();
                    return true;
                  }
                  return false;
 
                  // S3 - Detects if blade is present
                  #ifdef BLADE_DETECT_PIN
                  case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_ON, MODE_ANY_BUTTON | MODE_ON):
                  case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_ON, MODE_ANY_BUTTON | MODE_OFF):
                  // Might need to do something cleaner, but let's try this for now.
                  blade_detected_ = true;
                  FindBladeAgain();
                  SaberBase::DoBladeDetect(true);
                  if(preset_menu_)
                  {
 
                  }
                  return true;
 
                  // S3 - Detects if blade is absent
                  case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_OFF, MODE_ANY_BUTTON | MODE_ON):
                  case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_OFF, MODE_ANY_BUTTON | MODE_OFF):
                  // Might need to do something cleaner, but let's try this for now.
                  Off();
                  blade_detected_ = false;
                  FindBladeAgain();
                  SaberBase::DoBladeDetect(false);
                  if(preset_menu_)
                  {
 
                  }
 
                  if(menu_)
                  {
                    if(menu_type_ == MENU_LENGTH)
                    {
                      MenuUndo();
                    }
                    menu_ = false;
                  }
 
                  return true;
 
                  #endif
 
                  // Events that needs to be handled regardless of what other buttons are pressed.
                  case EVENTID(BUTTON_POWER, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
                  case EVENTID(BUTTON_AUX, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
                  if (SaberBase::Lockup())
                  {
                    SaberBase::DoEndLockup();
                    SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
                    mode_volume_ = false;
                    preset_menu_ = false;
                    return true;
                  }
                }
                return false;
              }
            }
 
            void SB_Effect(EffectType effect, float location) override
            {
              switch (effect)
              {
                case EFFECT_BATTERY_LEVEL:
                if (SFX_battery)
                {
                  hybrid_font.PlayCommon(&SFX_battery);
                }
                else
                {
                  beeper.Beep(0.5, 3000);
                }
                return;
              }
            }
 
          private:
            bool swing_blast_ = false; // Multi-Blast Mode (Swing = Blast Deflect)
            bool check_blast_ = false; // Check if Multi-Blast mode should be enabled (Battle Mode)
            bool auto_lockup_on_ = false; // Battle Mode Lockup active
            bool auto_melt_on_ = false; // Battle Mode Melt/Drag active
            bool battle_mode_ = false; // Battle Mode active
            bool menu_ = false; // Edit Mode / Menu System active
 
            //S3 Preconfiguration variables
            bool aux_on_ = true;
            bool pointing_down_ = false;
            bool mode_volume_ = false;
            bool max_volume_reached = false;
            bool min_vol_reached_ = false;
            bool preset_menu_ = false;
            bool preset_forward_;
            uint32_t last_twist_ = millis();
            uint32_t saber_off_time_ = millis();
            uint32_t menu_time_ = millis();
 
            #ifdef FETT263_QUOTE_PLAYER_START_ON
            bool force_quote_ = true; // Quote Player active (in place of force effect)
            #else
            bool force_quote_ = false; // Quote Player active (in place of force effect)
            #endif
            #ifdef FETT263_SAVE_CHOREOGRAPHY
            bool rehearse_ = false; // Rehearsal Mode active
            bool choreo_ = false; // Choreography Mode active
            #endif
            uint32_t thrust_begin_millis_; // Thrust timer
            uint32_t push_begin_millis_; // Push timer
            uint32_t clash_impact_millis_; // Clash timer
            uint32_t last_push_millis_; // Last Push (to prevent gesture spamming)
            uint32_t last_blast_millis_; // Last Blast (for Battle Mode Multi-Blast detection)
            uint32_t saber_off_time_millis_; // Off timer
            uint32_t restart_millis_; // Used to time restarts to show preon timing.
            ClashType clash_type_ = CLASH_NONE;
            MenuType menu_type_ = MENU_TOP;
            int menu_top_pos_ = 0; // Top menu dial position
            int menu_sub_pos_ = 0; // Sub menu dial position
            TrackMode track_mode_ = PLAYBACK_OFF;
            int track_num_; // Track Number for Track Player
            int num_tracks_; // Number of Tracks Found
            int ignite_time_; // Ignition timer for Edit Mode retraction preview
            int dial_ = -1; // Menu dial "tick"
            int sub_dial_; // Sub menu dial "tick"
            int arg_dial_; // Argument Sub menu dial "tick"
            int gesture_num_;
            float twist_menu_ = M_PI / 3; // Twist Menu sensitivity
            bool choice_ = false;
            // Edit Mode selection confirmation
            // for True/False control when deleting, disabling/enabling or copying
            bool off_event_ = false; // Do off event in Edit Mode
            bool restart_ = false; // Ignite blade after off event in Edit Mode
            bool next_event_ = false;
            // Do next event in Edit Mode, allows an action/wav to complete before
            // "next event" begins, for use with choreography and ignition/retraction previews where menu sound
            // would otherwise be truncated by change in state
            EditColorMode color_mode_;
            bool edit_color_ = false; // Color Editing Mode active
            float hsl_angle_ = 0.0; // HSL angle for Color Editing
            int font_num_; // Font number from list_fonts array for use in Edit Mode dial
            #ifdef FETT263_EDIT_MODE_MENU
            uint32_t variation_revert_; // Variation revert value
            Color16 saved_color_;
            int blade_preview_ = 0; // Blade number for "preview" style
            int blade_num_; // Active Blade Number for editing
            int effect_num_; // Effect Arg Number
            int copy_blade_; // Blade to Copy from
            int set_num_; // Settings Arg Number
            int style_revert_; // Original Style Number for Revert
            int length_revert_; // Original Blade Length for Revert
            int arg_revert_; // Original Arg vale for Revert
            // Calculated value for IntArg (Settings Arguments)
            // used to add or subtract from original saved value by dial
            int calc_;
            #endif
            #ifdef FETT263_SAVE_CHOREOGRAPHY
            int clash_count_ = -1; // Choreography Mode Clash counter
            #endif
          };
 
          #endif
 