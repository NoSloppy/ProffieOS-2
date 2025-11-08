# HEV Suit Example: Using USERn_STEP2 with Health Announcements

## Overview

This example demonstrates how to use the USERn_STEP2 effect system with the HEV prop's health announcement system. STEP2 effects trigger when SOUNDQ actually plays the sound, ensuring perfect synchronization between voice lines and visual effects.

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

The issue is that SOUNDQ might have other sounds queued before the health announcement. If you trigger an effect immediately with USER1, it doesn't sync with when the voice line actually plays. You can't use `WavLen<>` because the sound hasn't started playing yet.

**Timeline:**
1. Health drops → DoEffect(USER1) triggers
2. User1 effect happens immediately  
3. Sound queued to SOUNDQ
4. ... other sounds might play first ...
5. Health voice finally plays (could be seconds later)
6. Visual effect has already finished!

## The Solution (With STEP2)

With STEP2, the effect triggers when SOUNDQ actually plays the sound:

**Updated `SB_Effect` handler:**
```cpp
case EFFECT_USER1:
  SFX_health.SelectFloat(health_ / 100.0);
  // Queue sound with STEP2 effect - effect triggers when sound plays!
  SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2));
  return;
```

**Timeline:**
1. Health drops → Sound queued with STEP2 effect
2. ... other sounds might play first ...
3. Health voice starts playing → **STEP2 triggers now!**
4. Visual effect syncs perfectly with voice line
5. WavLen<> returns correct duration

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

**Key Difference:** The Cylon warning now appears exactly when the health voice line plays (not when USER1 triggers), and displays for exactly the duration of the sound.

## Example Blade Style

Here's a practical blade style for the HEV suit:

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
  
  // Optional: Immediate flash when health event triggers
  // (Use if you want instant feedback)
  TransitionEffectL<
    TrConcat<
      TrInstant,
      AlphaL<White, Int<32768>>,
      TrFade<100>
    >,
    EFFECT_USER1
  >,
  
  // STEP2: Cylon warning appears when voice line actually plays
  // Triggers when SOUNDQ plays the health sound
  // WavLen<> works correctly because sound is playing
  TransitionEffectL<
    TrConcat<
      TrDelay<1400>,
      Black,
      TrFade<300>,
      Cylon<Red,5,20,Gradient<Red,Red,Green>,33,50,1>,
      TrDelayX<WavLen<EFFECT_USER1_STEP2>>,  // Duration matches voice line!
      TrFade<300>,
      Black,
      TrFade<300>
    >,
    EFFECT_USER1_STEP2
  >,
  
  // Armor compromised - similar pattern
  TransitionEffectL<
    TrConcat<
      TrInstant,
      Strobe<Red, Black, 50, 450>,
      TrFadeX<WavLen<EFFECT_USER2_STEP2>>
    >,
    EFFECT_USER2_STEP2
  >
>;
```

## How It Works in Practice

### Scenario: Health drops from 45 to 38

1. **Prop calls:** `SaberBase::DoEffect(EFFECT_USER1, 0.0)`
2. **SB_Effect handler:**
   - Selects appropriate health sound
   - Queues to SOUNDQ with STEP2 effect: `SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2))`
3. **SOUNDQ processes queue:**
   - Other sounds might play first (normal queue behavior)
   - When health sound reaches front of queue and starts playing:
     - SOUNDQ triggers EFFECT_USER1_STEP2
     - Cylon warning appears on blade
     - WavLen<> returns correct duration
4. **Visual syncs perfectly:**
   - Cylon displays exactly when voice says "Warning: Health at 40"
   - Lasts for the exact duration of the voice line
   - No hardcoded delays needed!

## Integration with Props

Update the `SB_Effect` handler to use the new SOUNDQ constructor:

**Before:**
```cpp
case EFFECT_USER1:
  SFX_health.SelectFloat(health_ / 100.0);
  SOUNDQ->Play(&SFX_health);  // Just plays sound
  return;
```

**After:**
```cpp
case EFFECT_USER1:
  SFX_health.SelectFloat(health_ / 100.0);
  // Play sound and trigger STEP2 when it plays
  SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2));
  return;
```

No Loop() processing needed - SOUNDQ handles everything automatically!

## Sound Files Needed

Place these in your font directory:

### For Health Alerts (EFFECT_USER1_STEP2)
- `user1.wav` or `health.wav` - Health alert voice line played by STEP2
- `user1s2.wav` - Optional separate sound (falls back to user1.wav if not present)

**Note:** When STEP2 triggers, it plays the `user1` sound effect through hybrid_font. The HEV prop queues the health sound to SOUNDQ, and when SOUNDQ plays it, STEP2 triggers with its own sound.

**Sound Strategy:**
- The SOUNDQ health sound and the STEP2 sound can be the same file or different
- For simplest setup: Just have `health.wav` in font - it will be used for both
- For dual sounds: Have both `health.wav` (queued to SOUNDQ) and `user1.wav` (played by STEP2)

### For Armor Alerts (EFFECT_USER2_STEP2)
- `armor_compromised.wav` - Armor alert voice
- `user2.wav` or `user2s2.wav` - Played by STEP2 effect

## Testing

1. **Setup:** Install the blade style and update SB_Effect handler
2. **Damage yourself:** Use clashes or hazards to reduce health below 50
3. **Observe:** 
   - Other sounds might play first (normal queue behavior)
   - When health voice line actually plays, Cylon appears
   - Cylon displays for exact duration of the voice line
   - Perfect synchronization!
4. **Verify timing:** Cylon should appear exactly when voice says "Warning: Health at 40"

### Debugging

If the Cylon doesn't appear when the voice plays:

1. **Check SoundToPlay constructor:**
   - Make sure you're using `SoundToPlay(&SFX_health, EFFECT_USER1_STEP2)`
   - Not just `SOUNDQ->Play(&SFX_health)`

2. **Check STEP2 effect triggers:**
   - Add debug in hybrid_font.h case EFFECT_USER1_STEP2
   - Should trigger when SOUNDQ plays the sound

3. **Check sound file exists:**
   - `user1.wav` must exist for STEP2 sound
   - Or `user1s2.wav` with fallback to user1.wav

4. **Verify WavLen usage:**
   - Make sure you're using `WavLen<EFFECT_USER1_STEP2>` not `WavLen<EFFECT_USER1>`
   - EFFECT_USER1_STEP2 has the sound when it triggers from SOUNDQ

## How SOUNDQ Queueing Works

Multiple sounds queue normally:

```
1. Clash sound playing
2. Health alert queued: SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2))
3. Swing sound queued
4. Another health alert queued

Timeline:
  0.0s: Clash sound playing
  0.5s: Clash ends, health "40" starts → STEP2 triggers, Cylon appears
  2.5s: Health ends, swing plays
  3.0s: Swing ends, health "30" starts → STEP2 triggers, Cylon appears
  5.0s: All complete
```

Each STEP2 effect triggers when its associated sound actually plays, not when queued.

## Comparison: Before vs After

### Before STEP2 (Doesn't Work):
```cpp
// EFFECT_USER1 triggers immediately, sound queued separately
// WavLen returns 0 because sound isn't playing yet
TransitionEffectL<
  TrConcat<
    TrInstant,
    AlphaL<Red, Int<32768>>,
    TrFadeX<WavLen<>>  // ❌ WavLen is 0
  >,
  EFFECT_USER1
>
```

### After STEP2 (Works!):
```cpp
// STEP2 triggers when SOUNDQ actually plays the sound
// WavLen returns correct duration because sound is playing
TransitionEffectL<
  TrConcat<
    TrInstant,
    AlphaL<Red, Int<32768>>,
    TrFadeX<WavLen<>>  // ✅ WavLen is correct!
  >,
  EFFECT_USER1_STEP2
>
```

## Benefits

1. **Perfect synchronization:** Visual effects trigger exactly when sounds play
2. **Sequential effects:** Multiple health alerts queue properly without overlap
3. **Visual feedback:** Users get both immediate and sustained feedback
4. **Synchronized:** Visual effects perfectly match voice line durations
5. **Flexible:** Can use different visual effects for immediate vs sustained warnings
