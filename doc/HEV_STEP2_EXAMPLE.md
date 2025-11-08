# HEV Suit Example: Using USERn_STEP2 with Health Announcements

## Overview

This example demonstrates how to use the USERn_STEP2 effect system with the HEV prop's health announcement system. The HEV prop triggers EFFECT_USER1 when health drops, which plays a voice line. We can use EFFECT_USER1_STEP2 to create a visual effect that times perfectly with the voice line duration.

## HEV Prop Health System

In `props/hev.h`, line 491:
```cpp
// When health drops below 50 and crosses a 10-point threshold
SaberBase::DoEffect(EFFECT_USER1, 0.0);
```

This triggers in `SB_Effect` (line 801):
```cpp
case EFFECT_USER1:
  SFX_health.SelectFloat(health_ / 100.0);
  SOUNDQ->Play(&SFX_health);
  return;
```

## The Problem (Before STEP2)

Previously, if you wanted a visual effect that lasted the duration of the health voice line, you couldn't use `WavLen<>` because the effect and sound were triggered separately through SOUNDQ.

## The Solution (With STEP2)

Now, when EFFECT_USER1 is triggered:
1. EFFECT_USER1 fires immediately
2. EFFECT_USER1_STEP2 is automatically queued
3. After the health voice line completes, EFFECT_USER1_STEP2 triggers
4. EFFECT_USER1_STEP2 has access to accurate sound_length via WavLen<>

## Real HEV Prop Example (From Actual Use)

Here's the actual blade style layer currently used in the HEV prop:

### Before STEP2 (Current - Fixed Timing)
```cpp
TransitionEffectL<
  TrConcat<
    TrDelay<1400>,
    Black,
    TrFade<300>,
    Cylon<Red,5,20,Gradient<Red,Red,Green>,33,50,1>,
    TrDelayX<Int<4000>>,  // ❌ Fixed 4 second delay
    TrFade<300>,
    Black,
    TrFade<300>
  >,
  EFFECT_USER1
>
```

### After STEP2 (Dynamic Timing with WavLen)
```cpp
TransitionEffectL<
  TrConcat<
    TrDelay<1400>,
    Black,
    TrFade<300>,
    Cylon<Red,5,20,Gradient<Red,Red,Green>,33,50,1>,
    TrDelayX<WavLen<EFFECT_USER1_STEP2>>,  // ✅ Delay matches actual sound duration!
    TrFade<300>,
    Black,
    TrFade<300>
  >,
  EFFECT_USER1_STEP2  // Changed from EFFECT_USER1
>
```

**Key Difference:** The Cylon warning now displays for exactly the duration of the health alert sound, instead of a fixed 4 seconds. If the voice line is 2.5 seconds, the Cylon displays for 2.5 seconds. If it's 3.8 seconds, the Cylon displays for 3.8 seconds.

## Example Blade Style

Here's a practical blade style for the HEV suit that uses both effects:

```cpp
using HEVHealthWarning = Layers<
  // Base color - changes based on health (using variation)
  Gradient<
    Red,           // 0% health
    OrangeRed,     // 25% health  
    Yellow,        // 50% health
    Green,         // 75% health
    Cyan           // 100% health
  >,
  
  // IMMEDIATE: Quick flash when health alert triggers
  // This happens instantly when EFFECT_USER1 fires
  TransitionEffectL<
    TrConcat<
      TrInstant,
      AlphaL<White, Int<32768>>,
      TrFade<100>
    >,
    EFFECT_USER1
  >,
  
  // STEP2: Pulsing warning that lasts the duration of the voice line
  // This triggers after EFFECT_USER1's sound completes
  // WavLen<> now works correctly because effect and sound are synchronized
  TransitionEffectL<
    TrConcat<
      TrInstant,
      AlphaL<
        Red,
        Pulsing<Int<16384>, Int<32768>, 200>
      >,
      TrFadeX<WavLen<>>  // Fades over the duration of the STEP2 sound
    >,
    EFFECT_USER1_STEP2
  >,
  
  // Armor compromised warning (EFFECT_USER2)
  TransitionEffectL<
    TrConcat<
      TrInstant,
      AlphaL<Red, Int<32768>>,
      TrFade<300>
    >,
    EFFECT_USER2
  >,
  
  // STEP2 for armor compromised - sustained warning
  TransitionEffectL<
    TrConcat<
      TrInstant,
      Strobe<Red, Black, 50, 450>,
      TrFadeX<WavLen<>>
    >,
    EFFECT_USER2_STEP2
  >
>;
```

## How It Works in Practice

### Scenario: Health drops from 45 to 38

1. **Prop triggers:** `SaberBase::DoEffect(EFFECT_USER1, 0.0)`
2. **Immediately:**
   - EFFECT_USER1 fires
   - Blade flashes white briefly (100ms)
   - SOUNDQ queues the health voice line
   - EFFECT_USER1_STEP2 is automatically added to the effect queue
3. **Voice line plays:** "Warning: Health at 40"
4. **Effect queue waits** for the voice line to complete (using sound_length)
5. **After voice line:**
   - EFFECT_USER1_STEP2 triggers
   - Red pulsing warning appears on blade
   - WavLen<> correctly uses the STEP2 sound duration
   - Pulsing fades out over the duration

## Integration with Props

To use this in the HEV prop, you need to process the effect queue. Add this to your main Loop():

```cpp
void Loop() override {
  // Process the effect queue for STEP2 effects
  SaberBase::ProcessEffectQueue();
  
  // ... rest of your loop code
}
```

Or if the prop doesn't have a Loop(), create a helper:

```cpp
class HEVEffectProcessor : public Looper {
public:
  const char* name() override { return "HEVEffectProcessor"; }
  void Loop() override {
    SaberBase::ProcessEffectQueue();
  }
};

HEVEffectProcessor hev_effect_processor;
```

## Sound Files Needed

Place these in your font directory:

### For Health Alerts (EFFECT_USER1)
- `health.wav` or `health1.wav` through `health50.wav` - Health alert voice lines
- `user1s2.wav` - Follow-up sound for STEP2 timing control

**Sound Strategy Options:**

**Option 1: Actual Follow-up Sounds**
- `user1s2.wav` - Alert beep, warning tone, or acknowledgment sound
- The Cylon effect will display for the duration of this sound
- Most immersive option

**Option 2: Silent/Minimal Sound for Timing**
- `user1s2.wav` - Very quiet ambient or short beep of desired duration
- Use this to control exactly how long the Cylon displays
- Clean visual timing control

**Option 3: Simple Fallback**
- Don't create `user1s2.wav` at all
- STEP2 will fallback to playing `user1.wav` (health voice line)
- Cylon will display for voice line duration
- Simplest option but might sound repetitive

### For Armor Alerts (EFFECT_USER2)
- `armor_compromised.wav` - Armor alert voice
- `user2s2.wav` - Optional follow-up (fallback to armor_compromised.wav)

## Testing

1. **Setup:** Install the blade style on your HEV prop config
2. **Damage yourself:** Use clashes or hazards to reduce health below 50
3. **Observe:** 
   - Health voice line plays ("Warning: Health at 40")
   - After 1.4s delay, Cylon effect fades in
   - Cylon displays for the duration of the STEP2 sound
   - Cylon fades out
4. **Verify timing:** The Cylon duration should match the `user1s2.wav` duration exactly

### Debugging WavLen

If the Cylon doesn't display at all or displays for 0 seconds:

1. **Check ProcessEffectQueue() is running:**
   - Add `PVLOG_DEBUG << "Effect queue size: " << SaberBase::effect_queue_.size() << "\n";` in your Loop()
   - Should see the queue increase when USER1 triggers

2. **Check STEP2 effect triggers:**
   - Add debug in hybrid_font.h case EFFECT_USER1_STEP2
   - Should see it trigger after USER1 sound completes

3. **Check sound file exists:**
   - `user1s2.wav` must exist OR `user1.wav` must exist as fallback
   - If neither exists, no sound plays and WavLen returns 0

4. **Check sound plays:**
   - Listen for the STEP2 sound playing
   - If you hear it, WavLen should work

5. **Verify WavLen usage:**
   - Make sure you're using `WavLen<EFFECT_USER1_STEP2>` not `WavLen<EFFECT_USER1>`
   - EFFECT_USER1 has no sound associated directly (it uses SOUNDQ)
   - EFFECT_USER1_STEP2 has the sound when it triggers

## Advanced: Multiple Sequential Warnings

If you trigger multiple health alerts quickly, they will queue:

```
Health 45 → 38:
  - EFFECT_USER1 (immediate flash + voice "40")
  - EFFECT_USER1_STEP2 queued

Health 38 → 28:  
  - EFFECT_USER1 (immediate flash + voice "30")
  - EFFECT_USER1_STEP2 queued (will wait for previous STEP2 to complete)

Timeline:
  0.0s: Flash + "40" voice starts
  1.5s: "40" voice ends, STEP2 pulses starts
  3.0s: First STEP2 ends, Flash + "30" voice already happened
  4.5s: Second STEP2 pulses starts
  6.0s: All effects complete
```

Note: The immediate effects (EFFECT_USER1) always fire right away, but the STEP2 effects wait their turn in the queue.

## Comparison: Before vs After

### Before STEP2 (Doesn't Work):
```cpp
// This DOESN'T work because SOUNDQ and DoEffect are separate
TransitionEffectL<
  TrConcat<
    TrInstant,
    AlphaL<Red, Int<32768>>,
    TrFadeX<WavLen<>>  // ❌ WavLen is 0 - no sound playing during effect
  >,
  EFFECT_USER1
>
```

### After STEP2 (Works!):
```cpp
// This WORKS because STEP2 effect triggers WITH its sound
TransitionEffectL<
  TrConcat<
    TrInstant,
    AlphaL<Red, Int<32768>>,
    TrFadeX<WavLen<>>  // ✅ WavLen is correct - sound is playing
  >,
  EFFECT_USER1_STEP2
>
```

## Benefits

1. **Accurate timing:** WavLen<> now works correctly with queued sounds
2. **Sequential effects:** Multiple health alerts queue properly without overlap
3. **Visual feedback:** Users get both immediate and sustained feedback
4. **Synchronized:** Visual effects perfectly match voice line durations
5. **Flexible:** Can use different visual effects for immediate vs sustained warnings
