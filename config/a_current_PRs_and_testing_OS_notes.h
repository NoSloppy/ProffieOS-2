// pr - add lowbatt image support for OLED

// ssd1306
IMAGE_FILESET(lowbatt);

      case EFFECT_LOW_BATTERY:
        // Maybe we should make this blink or something?
        SetMessage("low\nbattery");
        ShowFile(&IMG_lowbatt, 5000);
        break;

//pr - figure out recticle / bulletcounts/aniation for blaster , kill, stun, auto. (Lady tano other odes)
// has to do with alternate DisplayController and all that. Lots to wrap head around there.

        

-----

pr idea    - BC_Buttons -- add DUAL_POWER_BUTTONS - nope...nnot
instructions:
Optional #defines:
#define DUAL_POWER_BUTTONS      - If using NUM_BUTTONS = 1 on a saber that has 2 buttons,
                                  this will turn both buttons into POW, so that
                                  either button can be used for all 1-btn controls.


  bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
#if NUM_BUTTONS == 1 && defined(DUAL_POWER_BUTTONS)                                 // BC Make both buttons identical for 1-btn use... useful?
      if (button == BUTTON_AUX) button = BUTTON_POWER;
#endif
    switch (EVENTID(button, event, modifiers)) {

----
documentation
------

Using videotoblc
MacOS:
pre-req: Developer tools installed.
  `xcode-select --install`
install Homebrew
`/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
`brew install ffmpeg`

cd to videotoblc directory.
make
PATH=/usr/local/bin:
./videotoblc spectrum_song.mp4 >humm.blc
unless PATH is already established
