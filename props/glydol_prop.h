// Glydal prop file
// Incorporates multi-blast by Fett263 and volume controls by SA22C.
//
//
// 1 Button Controls
//
// Ignite - click while OFF
// Muted Ignition - double click and hold while OFF
// Retract - hold and wait till blade is off while ON
// Play/Stop Music - double click while OFF or hold and release while ON and pointing blade up
// Next Preset - hold and release while OFF
// Previous Preset - hold and wait while OFF
// Lockup - hold and clash while ON
// Drag - hold and clash while ON (pointing the blade down)
// Blaster Deflection - short click while ON
// Force Effects - hold and release while ON
// Color Change - twist the hilt and hold the button while ON to enter Color Change Wheel, turn hilt
// to rotate through colors, hold button until sound to select color and exit. (If
// using COLOR_CHANGE_DIRECT each twist and hold advances one Color at a time.)
// Melt - hold the button and stab while ON
// Lightning Block - fast double click and hold the button while ON
// Enter Multi-Block Mode - swing the saber and hold and release the button while ON (now swing the
// saber, blaster blocks will trigger automatically)
// Exit Multi-Block Mode - short click while ON
// Enter Volume Menu - hold until beep while OFF
// Volume Up (10% increment, 100% max) - click while in Volume Menu
// Volume Down (10% increment) - hold and release while in Volume Menu
// Exit Volume Menu - hold until beep
//
//
// 2 Button Controls (PWR and AUX):
//
// Ignite - click PWR while OFF
// Muted Ignition - double click and hold PWR while OFF
// Retract - click PWR while ON (disabled during swinging)
// Play/Stop Music Track - double click PWR while OFF or hold and release PWR while ON and pointing
// blade straight up
// Blaster Deflection - click AUX while ON
// Multi-Block Mode - hold and release AUX while ON to enter mode, Swing to initiate
// Blasts, click Aux to exit mode. (Lockup, clash, stab, melt, drag
// or any button presses also automatically exits Multi-Blast mode.)
// Clash - clash blade while ON
// Lockup - hold AUX and clash while ON
// Drag - hold AUX and stab down while ON
// Melt - hold PWR (or AUX) and thrust forward and clash while ON
// Lightning Block - hold PWR and click AUX while ON
// Force - hold and release PWR while ON (not pointing straight up)
// Stab - thrust forward and clash blade while ON
// Color Change - hold AUX and click PWR while ON to enter Color Change Wheel, turn hilt to rotate
// through colors, click PWR to select/exit. (If using COLOR_CHANGE_DIRECT each button
// press advances one Color at a time.)
// Next Preset - click AUX while OFF
// Previous Preset - hold Aux and click PWR while OFF
// Enter Volume Menu - hold AUX until beep while OFF
// Volume Up (10% increment, 100% max) - click PWR while in Volume Menu
// Volume Down (10% increment) - click AUX while in Volume Menu
// Exit Volume Menu - hold and release AUX while in Volume Menu
// Play Random Boot Sound – hold and release PWR while OFF and pointing blade straight up
// Play Random Font Sound – hold and release AUX while OFF
// Play Random Quote – hold PWR and click AUX while OFF
//
//
// Enter Volume Menu - vmbegin.wav
// Exit Volume Menu - vmend.wav
// Force Push - push.wav
// Multi-Blast Mode On - blstbgn.wav
// Multi-Blast Mode Off - blstend.wav

#ifndef PROPS_SABER_GLYDAL_BUTTONS_H
#define PROPS_SABER_GLYDAL_BUTTONS_H

#include "prop_base.h"
#include "../sound/hybrid_font.h"

#undef PROP_TYPE
#define PROP_TYPE SaberGlydalButtons

EFFECT(quote); // for playing Quotes
EFFECT(vmbegin); // for Begin Volume Menu
EFFECT(vmend); // for End Volume Menu
EFFECT(blstbgn); // for Begin Multi-Blast
EFFECT(blstend); // for End Multi-Blast


// The Saber class implements the basic states and actions
// for the saber.
class SaberGlydalButtons : public PropBase {
public:
SaberGlydalButtons() : PropBase() {}
const char* name() override { return "SaberGlydalButtons"; }


void Loop() override {
PropBase::Loop();
DetectTwist();
DetectSwing();
}


// SA22C Volume Menu
void VolumeUp() {
STDOUT.println("Volume up");
if (dynamic_mixer.get_volume() < VOLUME) {
dynamic_mixer.set_volume(std::min<int>(VOLUME + VOLUME * 0.1,
dynamic_mixer.get_volume() + VOLUME * 0.10));
beeper.Beep(0.5, 2000);
STDOUT.print("Current Volume: ");
STDOUT.println(dynamic_mixer.get_volume());
} else {
beeper.Beep(0.5, 3000);
}
}

void VolumeDown() {
STDOUT.println("Volume Down");
if (dynamic_mixer.get_volume() > (0.10 * VOLUME)) {
dynamic_mixer.set_volume(std::max<int>(VOLUME * 0.1,
dynamic_mixer.get_volume() - VOLUME * 0.10));
beeper.Beep(0.5, 2000);
STDOUT.print("Current Volume: ");
STDOUT.println(dynamic_mixer.get_volume());
} else {
beeper.Beep(0.5, 1000);
}
}

bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
switch (EVENTID(button, event, modifiers)) {
case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_ON):
case EVENTID(BUTTON_AUX, EVENT_PRESSED, MODE_ON):
if (accel_.x < -0.15) {
pointing_down_ = true;
} else {
pointing_down_ = false;
}
return true;


#ifdef BLADE_DETECT_PIN
case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_ON, MODE_ANY_BUTTON | MODE_ON):
case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_ON, MODE_ANY_BUTTON | MODE_OFF):
// Might need to do something cleaner, but let's try this for now.
blade_detected_ = true;
FindBladeAgain();
SaberBase::DoBladeDetect(true);
return true;

case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_OFF, MODE_ANY_BUTTON | MODE_ON):
case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_OFF, MODE_ANY_BUTTON | MODE_OFF):
// Might need to do something cleaner, but let's try this for now.
blade_detected_ = false;
FindBladeAgain();
SaberBase::DoBladeDetect(false);
return true;
#endif


// Volume Menu Controls

// Enter Volume MENU

#if NUM_BUTTONS == 1
// 1 button
case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_OFF | BUTTON_POWER):
#else
// 2 buttons
case EVENTID(BUTTON_AUX, EVENT_CLICK_LONG, MODE_OFF):
#endif
if (!mode_volume_) {
mode_volume_ = true;
beeper.Beep(0.1, 2000);
beeper.Beep(0.1, 2500);
STDOUT.println("Enter Volume Menu");
} else {
mode_volume_ = false;
beeper.Beep(0.1, 2500);
beeper.Beep(0.1, 2000);
STDOUT.println("Exit Volume Menu");
}
return true;




// 1-button code


#if NUM_BUTTONS == 1


// Off Functions

// Turn on Saber
case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_OFF):
SaberBase::RequestMotion();
On();
return true;


// Activate Muted
case EVENTID(BUTTON_POWER, EVENT_SECOND_HELD, MODE_OFF):
if (SetMute(true)) {
unmute_on_deactivation_ = true;
On();
}
return true;


// Start or Stop Tracks
case EVENTID(BUTTON_POWER, EVENT_DOUBLE_CLICK, MODE_OFF):
if (millis() - activated_ < 500) {
StartOrStopTrack();
}
return true;


// Volume Controls

// Volume Up
case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_OFF):
if (mode_volume_) {
VolumeUp();
} else {
On();
}
return true;


// Volume Down or Next Preset
case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_OFF):
if (mode_volume_) {
VolumeDown();
} else {
next_preset();
}
return true;


// Previous Preset
case EVENTID(BUTTON_POWER, EVENT_HELD_MEDIUM, MODE_OFF):
previous_preset();
return true;


// On Functions

// Turn Blade OFF
case EVENTID(BUTTON_POWER, EVENT_HELD_MEDIUM, MODE_ON):
if (!SaberBase::Lockup()) {
#ifndef DISABLE_COLOR_CHANGE
if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) {
// Just exit color change mode.
// Don't turn saber off.
ToggleColorChangeMode();
return true;
}
#endif
if (!swinging_)
Off();
}
swing_blast_ = false;
return true;


// Start or Stop Tracks While Saber is On
case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_ON):
if (fusor.angle1() > M_PI / 3) {
StartOrStopTrack();
} else {
SaberBase::DoForce();
}
return true;


// Color Change mode
case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_ON | BUTTON_POWER):
ToggleColorChangeMode();
return true;


// Blaster Deflection
case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_ON):
swing_blast_ = false;
SaberBase::DoBlast();
return true;


// Multi-Block Mode
case EVENTID(BUTTON_NONE, EVENT_SWING, MODE_ON | BUTTON_POWER):
swing_blast_ = true;
hybrid_font.SB_Effect(EFFECT_BLAST, 0);
return true;

case EVENTID(BUTTON_NONE, EVENT_SWING, MODE_ON):
if (swing_blast_) {
SaberBase::DoBlast();
}
return true;


// Lockup
case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_POWER):
if (!SaberBase::Lockup()) {
if (pointing_down_) {
SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
} else {
SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
}
swing_blast_ = false;
SaberBase::DoBeginLockup();
return true;
}
break;


// Lightning Block
case EVENTID(BUTTON_POWER, EVENT_SECOND_HELD, MODE_ON):
SaberBase::SetLockup(SaberBase::LOCKUP_LIGHTNING_BLOCK);
swing_blast_ = false;
SaberBase::DoBeginLockup();
return true;


// Melt
case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_ON | BUTTON_POWER):
if (!SaberBase::Lockup()) {
SaberBase::SetLockup(SaberBase::LOCKUP_MELT);
swing_blast_ = false;
SaberBase::DoBeginLockup();
return true;
}
break;




// 2-button code


#elif NUM_BUTTONS == 2


// Off functions

// Turn on Saber
case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_OFF):
SaberBase::RequestMotion();
return true;


// Activate Muted
case EVENTID(BUTTON_POWER, EVENT_SECOND_HELD, MODE_OFF):
if (millis() - activated_ < 500) {
if (SetMute(true)) {
unmute_on_deactivation_ = true;
}
}
return true;


// Start or Stop Tracks (or play Random Boot Sound)
case EVENTID(BUTTON_POWER, EVENT_DOUBLE_CLICK, MODE_OFF):
if (fusor.angle1() > M_PI / 3) {
hybrid_font.PlayCommon(&SFX_boot);
} else {
StartOrStopTrack();
}
return true;


// Volume Controls

// Volume Up
case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_OFF):
if (mode_volume_) {
VolumeUp();
} else {
On();
}
return true;


// Volume Down and Next Preset
case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_OFF):
if (mode_volume_) {
VolumeDown();
} else
next_preset();
return true;


// Previous Preset
case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_OFF | BUTTON_AUX):
previous_preset();
return true;


// Play Random Font Sound
case EVENTID(BUTTON_AUX, EVENT_FIRST_CLICK_LONG, MODE_OFF):
hybrid_font.PlayCommon(&SFX_font);
return true;


// Play Random Quote
case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_OFF | BUTTON_POWER):
hybrid_font.PlayCommon(&SFX_quote);
return true;



// On Functions

// Turn Blade OFF
case EVENTID(BUTTON_POWER, EVENT_FIRST_CLICK_SHORT, MODE_ON):
if (!SaberBase::Lockup()) {
#ifndef DISABLE_COLOR_CHANGE
if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) {
// Just exit color change mode.
// Don't turn saber off.
ToggleColorChangeMode();
return true;
}
#endif
if (!swinging_)
Off();
}
swing_blast_ = false;
return true;


// Start or Stop Tracks While Saber is On
case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_ON):
if (fusor.angle1() > M_PI / 3) {
StartOrStopTrack();
} else {
SaberBase::DoForce();
}
return true;


// Blast Effects
case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_ON):
case EVENTID(BUTTON_AUX, EVENT_DOUBLE_CLICK, MODE_ON):
// Avoid the base and the very tip.
// TODO: Make blast only appear on one blade!
if(swing_blast_) {
swing_blast_ = false;
if (SFX_blstend) {
hybrid_font.PlayCommon(&SFX_blstend);
} else {
SaberBase::DoBlast();
}
return true;
} else {
SaberBase::DoBlast();
}
return true;


// Multi-Blast Effects
case EVENTID(BUTTON_AUX, EVENT_CLICK_LONG, MODE_ON):
swing_blast_ = true;
if (SFX_blstbgn) {
hybrid_font.PlayCommon(&SFX_blstbgn);
} else {
hybrid_font.SB_Effect(EFFECT_BLAST, 0);
}
return true;

case EVENTID(BUTTON_NONE, EVENT_SWING, MODE_ON):
if (swing_blast_) {
SaberBase::DoBlast();
}
return true;


// Color Change Mode
case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_ON | BUTTON_AUX):
ToggleColorChangeMode();
return true;


// Lockup and Drag
case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_AUX):
if (!SaberBase::Lockup()) {
swing_blast_ = false;
if (pointing_down_) {
SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
} else {
SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
}
SaberBase::DoBeginLockup();
return true;
}
break;


// Lightning Block
case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_ON | BUTTON_POWER):
SaberBase::SetLockup(SaberBase::LOCKUP_LIGHTNING_BLOCK);
swing_blast_ = false;
SaberBase::DoBeginLockup();
return true;


// Melt
case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_ON | BUTTON_POWER):
case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_ON | BUTTON_AUX):
if (!SaberBase::Lockup()) {
SaberBase::SetLockup(SaberBase::LOCKUP_MELT);
swing_blast_ = false;
SaberBase::DoBeginLockup();
return true;
}
break;


#endif


// Events that needs to be handled regardless of what other buttons
// are pressed.
case EVENTID(BUTTON_POWER, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
case EVENTID(BUTTON_AUX, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
if (SaberBase::Lockup()) {
SaberBase::DoEndLockup();
SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
return true;
}
}
return false;
}

private:
bool pointing_down_ = false;
bool swing_blast_ = false;
bool mode_volume_ = false;
uint32_t clash_impact_millis_ = millis();
uint32_t saber_off_time_ = millis();
};

#endif