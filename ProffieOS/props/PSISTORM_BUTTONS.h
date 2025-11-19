/*
Prop file by Psistorm
Credits go to sa22c / fett263
 
 
Features:
* one button config, easy to use
* on-demand battery level, uses style
* blast delay option, separate blaster shot and deflect sounds
* volume change menu with spoken option
* optional gesture based font selection menu
* gesture ignition options
 
 
Defines:
#define STAB_ON - enables stab ignition
#define TWIST_ON - enables twist ignition
#define GESTURE_MENU - enables font selection menu. hold power and twist while off to enter. twist right for next, twist left for previous. press power to select
#define BLAST_DELAY <milis> - enables separate shot/deflect sounds, value in miliseconds, recommended is 500. looks for blshot to trigger delay, will play blhit instead of blst if present
#define BLAST_RANDOM - used with BLAST_DELAY, introduces a chance for multiple blasts to queue up for a single button press
 
Define this in your CONFIG_TOP section for easy on-demand battery level integration:
#define BladePtr(...) StylePtr<Layers<__VA_ARGS__, AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Pulsing<Mix<BatteryLevel,Red,Green>,Black,2000>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<32768>>,Int<-1>>>,TrSmoothFade<4000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>>>()
 
Simply paste your blade style into BladePtr() but omit the StylePtr<Layers< part and the >>() at the end.
 
 
Controls:
 
While off:
* Saber pointing down, hold power and clash: Volume menu. Short click for quieter, medium hold for louder. Hold power and clash while pointing down to exit
* Saber pointing up, hold power and clash: Display battery charge level
* If GESTURE_MENU is defined:
    * Hold power and twist to enter menu
    * Twist left for previous preset, twist right for next
    * Click power button to select preset
* Click power to ignite
 
 
While on:
* Hold power to retract blade
* Clash blade for clash effect
* Clash while holding power to trigger lockup
* Clash and hold power while pointing down to trigger drag
* Press power button for blast effects
* Double click and hold power for lightning block
* Stab forward for stab effect
* Stab and hold power for melt
* Hold power and twist blade for force effect
 
 
TODO:
* Implement swing blast
* Port into a separate, two button config?
*/
 
#ifndef PROPS_SABER_PSISTORM_BUTTONS_H
#define PROPS_SABER_PSISTORM_BUTTONS_H
 
#include "prop_base.h"
#include "../sound/hybrid_font.h"
 
#undef PROP_TYPE
#define PROP_TYPE SaberPsistormButtons
 
#if defined(BLAST_RANDOM) && !defined(BLAST_DELAY)
#error Defining BLAST_RANDOM requires defining BLAST_DELAY
#endif
 
#ifndef BUTTON_DOUBLE_CLICK_TIMEOUT
#define BUTTON_DOUBLE_CLICK_TIMEOUT 300
#endif
 
#ifndef BUTTON_SHORT_CLICK_TIMEOUT
#define BUTTON_SHORT_CLICK_TIMEOUT 300
#endif
 
#ifndef BUTTON_HELD_TIMEOUT
#define BUTTON_HELD_TIMEOUT 300
#endif
 
#ifndef BUTTON_HELD_MEDIUM_TIMEOUT
#define BUTTON_HELD_MEDIUM_TIMEOUT 1000
#endif
 
#ifndef BUTTON_HELD_LONG_TIMEOUT
#define BUTTON_HELD_LONG_TIMEOUT 2000
#endif
 
EFFECT(battery);
EFFECT(vmbegin);
EFFECT(vmend);
EFFECT(vmup);
EFFECT(vmdown);
EFFECT(vmmax);
EFFECT(vmmin);
EFFECT(fmenter);
EFFECT(blhit);
EFFECT(blshot);
 
//workaround to twist left/right not being present, we redefine twist and co-opt an unused event trigger
#define EVENT_TWIST_RIGHT EVENT_TWIST
#define EVENT_TWIST_LEFT EVENT_SHAKE
#define EFFECT_BLAST_SHOT EFFECT_USER1
#define EFFECT_BLAST_HIT EFFECT_USER2
 
 
class SaberPsistormButtons : public PropBase {
public:
    SaberPsistormButtons() : PropBase() {}
    const char* name() override { return "SaberPsistormButtons"; }
    
    void Loop() override {
        PropBase::Loop();
        //DetectTwist();
        DetectSwing();
        
        Vec3 gyro = fusor.gyro();
        bool process = false;
        if (fabsf(gyro.x) > 200.0 &&
            fabsf(gyro.x) > 3.0f * abs(gyro.y) &&
            fabsf(gyro.x) > 3.0f * abs(gyro.z)) {
            process = DoGesture(gyro.x > 0 ? TWIST_LEFT : TWIST_RIGHT);
        }
        else {
            process = DoGesture(TWIST_CLOSE);
        }
        
        if (process) {
            if ((strokes[NELEM(strokes)-1].type == TWIST_LEFT &&
                 strokes[NELEM(strokes)-2].type == TWIST_RIGHT) ||
                (strokes[NELEM(strokes)-1].type == TWIST_RIGHT &&
                 strokes[NELEM(strokes)-2].type == TWIST_LEFT)) {
                if (strokes[NELEM(strokes) -1].length() > 90UL &&
                    strokes[NELEM(strokes) -1].length() < 300UL &&
                    strokes[NELEM(strokes) -2].length() > 90UL &&
                    strokes[NELEM(strokes) -2].length() < 300UL) {
                    uint32_t separation =
                        strokes[NELEM(strokes)-1].start_millis -
                        strokes[NELEM(strokes)-2].end_millis;
                    if (separation < 200UL) {
                        
                        // We have a twisting gesture.
                        if (gyro.x > 0) {
                            STDOUT.println("TWIST LEFT");
                            Event(BUTTON_NONE, EVENT_TWIST_LEFT);
                        }
                        else {
                            STDOUT.println("TWIST RIGHT");
                            Event(BUTTON_NONE, EVENT_TWIST_RIGHT);
                        }
                    }
                }
            }
        }
        
        #ifdef BLAST_DELAY
        //blast delay response
        for (int i = 0; i < 5; i++) {
            if (millis() - blast_delay_[i] > BLAST_DELAY && blast_delay_[i] > 0) {
                STDOUT.println("blast hit playing");
                blast_delay_[i] = 0;
                SaberBase::DoBlast();
            }
        }
        
        if (millis() - shot_delay_ > 200 && shot_delay_ > 0) {
            shot_delay_ = 0;
            SaberBase::DoEffect(EFFECT_BLAST_SHOT, 0);
        }
        
        #endif
    }
    
    //play sound if present, else play beeper
    void trySound(Effect sound, float duration, int beepfreq, int beepfreq2)
    {
        if (sound){
            hybrid_font.PlayCommon(&sound);
        }
        else {
            beeper.Beep(duration, beepfreq);
            if (beepfreq2 > 0) beeper.Beep(duration, beepfreq2);
        }
    }
    
    //volume change function
    void ChangeVolume(bool up) {
        if (up) {
            STDOUT.println("Volume up");
            if (dynamic_mixer.get_volume() < VOLUME) {
                dynamic_mixer.set_volume(std::min<int>(VOLUME + VOLUME * 0.1, dynamic_mixer.get_volume() + VOLUME * 0.10));
                trySound(SFX_vmup, 0.5, 2000, 0);
                STDOUT.print("Current Volume: ");
                STDOUT.println(dynamic_mixer.get_volume());
            }
            else {
                trySound(SFX_vmmax, 0.5, 3000, 0);
            }
        }
        
        else {
            STDOUT.println("Volume Down");
            if (dynamic_mixer.get_volume() > (0.10 * VOLUME)) {
                dynamic_mixer.set_volume(std::max<int>(VOLUME * 0.1, dynamic_mixer.get_volume() - VOLUME * 0.10));
                trySound(SFX_vmdown, 0.5, 2000, 0);
                STDOUT.print("Current Volume: ");
                STDOUT.println(dynamic_mixer.get_volume());
            }
            else{
                trySound(SFX_vmmin, 0.5, 1000, 0);
            }
        }
    }
    
    //fast ignition, skip pre-on
    void QuickOn() {
        if (IsOn()) return;
        if (current_style() && current_style()->NoOnOff()) return;
        activated_ = millis();
        STDOUT.println("Ignition.");
        MountSDCard();
        EnableAmplifier();
        SaberBase::RequestMotion();
 
        //ignore clashes on activation
        IgnoreClash(300);
        SaberBase::TurnOn();
    }
    
    bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
        
        switch (EVENTID(button, event, modifiers)) {
            
            //determine whether blade is pointing up or down
            case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_ON):
                if (accel_.x < -0.15) {
                    pointing_down_ = true;
                }
                else {
                    pointing_down_ = false;
                }
                return true;
            
            case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_OFF):
                if (accel_.x < -0.15) {
                    pointing_down_ = true;
                }
                else {
                    pointing_down_ = false;
                }
                SaberBase::RequestMotion();
                return true;
            
            //turn blade off
            case EVENTID(BUTTON_POWER, EVENT_FIRST_HELD_LONG, MODE_ON):
                if (!SaberBase::Lockup()) {
                    Off();
                }
                return true;
            
            //start or stop music
            case EVENTID(BUTTON_POWER, EVENT_SECOND_SAVED_CLICK_SHORT, MODE_OFF):
                StartOrStopTrack();
                return true;
            
            //saber On or volume down - for gesture menu, either exit menu and play boot, or if not in menu, turn saber on
            case EVENTID(BUTTON_POWER, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_OFF):
                if (mode_volume_) {
                    ChangeVolume(false);
                }
                else {
                    #ifdef ENABLE_GESTURE_MENU
                    if (mode_menu_) {
                        mode_menu_ = false;
                        SaberBase::DoBoot();
                    }
                    else if (!mode_volume_ && !mode_menu_) {
                        On();
                    }
                    #else
                    On();
                    #endif
                }
                return true;
            
            #ifdef ENABLE_STAB_ON
            case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_OFF):
            #ifdef ENABLE_TWIST_ON
            case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_OFF):
            #endif
                if (!mode_volume_ && !mode_menu_) {
                  QuickOn();
                }
                return true;
            #endif
            
            #ifdef ENABLE_GESTURE_MENU
            //enter font selection menu
            case EVENTID(BUTTON_NONE, EVENT_TWIST_LEFT, MODE_OFF | BUTTON_POWER):
            case EVENTID(BUTTON_NONE, EVENT_TWIST_RIGHT, MODE_OFF | BUTTON_POWER):
                if (!mode_volume_ && !mode_menu_) {
                    mode_menu_ = true;
                    trySound(SFX_fmenter, 0.5, 2500, 3000);
                }
                return true;
                break;
            
            //previous preset
            case EVENTID(BUTTON_NONE, EVENT_TWIST_LEFT, MODE_OFF):
                if (!mode_volume_ && mode_menu_) {
                    previous_preset();
                }
                return true;
            
            //next preset
            case EVENTID(BUTTON_NONE, EVENT_TWIST_RIGHT, MODE_OFF):
                if (!mode_volume_ && mode_menu_) {
                    next_preset();
                }
                return true;
            
            //fix, roll into other first_held_medium event with ifdefs
            #else
            case EVENTID(BUTTON_POWER, EVENT_FIRST_HELD_MEDIUM, MODE_OFF):
                if (pointing_down_) {
                    previous_preset();
                }
                else {
                    next_preset();
                }
                return true;
            #endif
            
            //volume up
            case EVENTID(BUTTON_POWER, EVENT_FIRST_HELD_MEDIUM, MODE_OFF):
                if (mode_volume_) {
                    ChangeVolume(true);
                }
                return true;
            
            //volume change mode if pointing down, battery level if pointing up
            case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_OFF | BUTTON_POWER):
                if (pointing_down_)
                {
                    if (!mode_volume_) {
                        mode_volume_ = true;
                        trySound(SFX_vmbegin, 0.1, 2000, 2500);
                        STDOUT.println("Enter Volume Menu");
                    }
                    
                    else {
                        mode_volume_ = false;
                        trySound(SFX_vmend, 0.1, 2500, 2000);
                        STDOUT.println("Exit Volume Menu");
                    }
                }
                
                else {
                    SaberBase::DoEffect(EFFECT_BATTERY_LEVEL, 0);
                }
                return true;
            
            //melt
            case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_ON | BUTTON_POWER):
                if (!SaberBase::Lockup()) {
                    SaberBase::SetLockup(SaberBase::LOCKUP_MELT);
                    SaberBase::DoBeginLockup();
                    return true;
                }
                break;
            
            //force effect
            case EVENTID(BUTTON_NONE, EVENT_TWIST_LEFT, MODE_ON | BUTTON_POWER):
            case EVENTID(BUTTON_NONE, EVENT_TWIST_RIGHT, MODE_ON | BUTTON_POWER):
                SaberBase::DoForce();
                return true;
            
            //blaster hit
            case EVENTID(BUTTON_POWER, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_ON):
            case EVENTID(BUTTON_POWER, EVENT_SECOND_CLICK_SHORT, MODE_ON):
            case EVENTID(BUTTON_POWER, EVENT_THIRD_CLICK_SHORT, MODE_ON):
            #ifndef BLAST_DELAY
                SaberBase::DoBlast();
            #else
                if (SFX_blhit) {
                    for (int i = 0; i < 5; i++) {
                        if (!blast_delay_[i]) {
                            blast_delay_[i] = millis();
                            STDOUT.println("delay set");
                            
                            SaberBase::DoEffect(EFFECT_BLAST_SHOT, 0);
                            #ifdef BLAST_RANDOM
                            if (rand() % 10 > 7 && i < 5) {
                                STDOUT.println("multi delay set");
                                blast_delay_[i + 1] = millis() + 200;
                                shot_delay_ = millis() + 200;
                            }
                            #endif
                            break;
                        }
                    }
                }
                else {
                    SaberBase::DoBlast();
                }
            #endif
                return true;
            
            //lockup
            case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_POWER):
                if (!SaberBase::Lockup()) {
                    if (pointing_down_) {
                        SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
                    } else {
                        SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
                    }
                    
                    SaberBase::DoBeginLockup();
                    return true;
                }
                break;
            
            //lightning block
            case EVENTID(BUTTON_POWER, EVENT_SECOND_HELD, MODE_ON):
                SaberBase::SetLockup(SaberBase::LOCKUP_LIGHTNING_BLOCK);
                SaberBase::DoBeginLockup();
                return true;
            
            //on button release while on, end lockups if active
            case EVENTID(BUTTON_POWER, EVENT_RELEASED, MODE_ON | BUTTON_POWER):
                if (SaberBase::Lockup()) {
                    SaberBase::DoEndLockup();
                    SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
                    return true;
                }
            
        }
        return false;
    }
    
    //extend sound effect function
    void SB_Effect(EffectType effect, float location) override {
        switch (effect) {
            case EFFECT_BATTERY_LEVEL: trySound(SFX_battery, 0.5, 3000, 0); return;
            
            case EFFECT_BLAST_SHOT: 
                if (SFX_blshot) {
                    STDOUT.println("blaster shot");
                    hybrid_font.PlayCommon(&SFX_blshot); return;
                }
                return;
            
            #ifdef BLAST_DELAY
            case EFFECT_BLAST:
                if (!SFX_blhit) {
                    hybrid_font.Play(&SFX_blaster, &SFX_blst); return;
                }
                else {
                    hybrid_font.PlayCommon(&SFX_blhit); return;
                }
                return;
            #endif
        }
    }
    
    private:
        bool  mode_menu_     = false;
        bool  mode_volume_   = false;
        bool  pointing_down_ = false;
        unsigned long blast_delay_[5] = {0, 0, 0, 0, 0};
        unsigned long shot_delay_ = 0;
};
 
#endif