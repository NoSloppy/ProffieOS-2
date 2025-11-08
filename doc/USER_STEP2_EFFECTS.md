# USERn_STEP2 Effects Documentation

## Overview

The USERn_STEP2 feature provides a two-step effect system for USER1 through USER8 effects. STEP2 effects trigger when their associated sound actually starts playing from SOUNDQ, enabling perfect synchronization between visual effects and audio, with accurate WavLen<> timing.

## How It Works

### Sound-Synchronized Triggering

When you queue a sound to SOUNDQ with an associated STEP2 effect:
1. **Sound queues** to SOUNDQ (may wait behind other sounds)
2. **When sound actually plays**, STEP2 effect triggers automatically
3. **Visual effect syncs** perfectly with the audio
4. **WavLen<>** returns accurate sound duration

### Sound Files

Place sound files in your font directory with these naming conventions:

- `user1.wav` through `user8.wav` - Primary sounds for STEP2 effects
- `user1s2.wav` through `user8s2.wav` - Step 2 effects (optional)

If `userNs2.wav` files are not found, they will fall back to playing the corresponding `userN.wav` file.

## Usage in Prop Files

### Basic Example with SOUNDQ

```cpp
// In SB_Effect handler
case EFFECT_USER1:
  // Queue sound with STEP2 effect to trigger when sound plays
  SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2));
  return;
```

When SOUNDQ processes the queue:
1. Other sounds might play first (normal queue behavior)
2. When `SFX_health` actually starts playing, EFFECT_USER1_STEP2 triggers
3. Blade animation appears exactly when the voice line plays
4. WavLen<EFFECT_USER1_STEP2> returns the correct sound duration

### Alternative: Immediate Effect + STEP2

You can also trigger an immediate effect, then queue the STEP2 for later:

```cpp
// Immediate visual feedback
SaberBase::DoEffect(EFFECT_USER1, 0);

// Queue sound that will trigger STEP2 when it plays
SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2));
```

This gives you both:
- Instant visual response (EFFECT_USER1)
- Sound-synchronized animation (EFFECT_USER1_STEP2)

## Usage in Blade Styles

Blade styles can react to either the immediate effect or the sound-synchronized STEP2 effect:

### Immediate Effect (EFFECT_USERn)
Use these for instant visual responses:

```cpp
TransitionEffectL<TrInstant, EFFECT_USER1, AlphaL<Red, Int<16384>>>
```

### Sound-Synchronized Effect (EFFECT_USERn_STEP2)
Use these for animations that sync with sounds:

```cpp
// Animation displays exactly when sound plays, for the sound's duration
TransitionEffectL<
  TrConcat<TrInstant, Red, TrFadeX<WavLen<EFFECT_USER1_STEP2>>>,
  EFFECT_USER1_STEP2
>
```

### Combined Example

```cpp
// Blade reacts to both immediate trigger and sound playback
Layers<
  // Base blade color
  Blue,
  // Flash white immediately when event happens
  TransitionEffectL<TrInstant, EFFECT_USER1, AlphaL<White, Int<32768>>>,
  // Pulsing red when sound actually plays, lasting the sound's duration
  TransitionEffectL<
    TrConcat<TrInstant, Pulsing<Red, Black, 200>, TrFadeX<WavLen<EFFECT_USER1_STEP2>>>,
    EFFECT_USER1_STEP2
  >
>
```

## No Loop Required

Unlike traditional effect queueing systems, STEP2 effects trigger automatically when SOUNDQ plays the associated sound. No special Loop() processing is needed - SOUNDQ handles everything.

## Technical Details

### How Sound-Triggered Effects Work

1. **Queue Sound with Effect:** `SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2))`
2. **SOUNDQ Processes Queue:** Other sounds may play first
3. **Sound Starts Playing:** When `SFX_health` reaches the front of the queue
4. **Effect Triggers:** SOUNDQ calls `SaberBase::DoEffect(EFFECT_USER1_STEP2, 0)`
5. **WavLen Works:** Effect has correct sound_length because sound is playing

### Supported Effects

Any effect can be triggered when a sound plays:

- EFFECT_USER1_STEP2 through EFFECT_USER8_STEP2
- Can also use for other effects if needed

### SoundToPlay Constructors

```cpp
// Basic sound, no effect
SOUNDQ->Play(&SFX_health);

// Sound with STEP2 effect trigger
SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2));

// Filename with effect trigger
SOUNDQ->Play(SoundToPlay("health.wav", EFFECT_USER1_STEP2));
```

## Examples

### Example 1: Two-Stage Force Power

```cpp
// In prop file
void ActivateForcePower() {
  // Stage 1: Charging sound and visual
  SaberBase::DoEffect(EFFECT_USER1, 0);
  // Stage 2 (auto-queued): Release sound and visual
}
```

Blade style:
```cpp
Layers<
  RgbArg<BASE_COLOR_ARG>,
  // Charging effect (pulsing white)
  TransitionEffectL<TrConcat<TrInstant, AlphaL<White, Pulsing<Int<0>, Int<32768>, 500>>, TrFadeX<WavLen<>>>,
    EFFECT_USER1>,
  // Release effect (bright flash)
  TransitionEffectL<TrConcat<TrInstant, White, TrFade<300>>, 
    EFFECT_USER1_STEP2>
>
```

### Example 2: Sequential Activation

```cpp
// Trigger a sequence of effects
SaberBase::DoEffect(EFFECT_USER1, 0);  // Triggers immediately, queues STEP2
SaberBase::DoEffect(EFFECT_USER2, 0);  // Triggers immediately, queues STEP2
SaberBase::DoEffect(EFFECT_USER3, 0);  // Triggers immediately, queues STEP2

// Timeline:
// - All USER1, USER2, USER3 trigger immediately
// - USER1_STEP2 triggers after user1.wav completes
// - USER2_STEP2 triggers after user2.wav completes  
// - USER3_STEP2 triggers after user3.wav completes
```

## Troubleshooting

### STEP2 Effects Don't Trigger

1. Ensure `ProcessEffectQueue()` is being called from Loop()
2. Verify sound files exist and are playing correctly
3. Check that SaberBase::sound_length is being set properly

### Effects Trigger Too Fast

- The queue adds a 10ms buffer after each sound
- If sounds are very short, effects may appear nearly simultaneous
- Use longer sound files for more noticeable separation

### Queue Overflow

- Maximum 8 effects can be queued
- If queue is full, effects trigger immediately instead of queuing
- This is a safety fallback to ensure effects aren't lost

## Best Practices

1. **Always process the queue:** Call `ProcessEffectQueue()` in your main loop
2. **Use appropriate sound lengths:** Longer sounds create more obvious staging
3. **Test both immediate and STEP2:** Ensure your blade styles work for both effect types
4. **Don't overflow the queue:** Be mindful of triggering too many effects rapidly
5. **Provide fallback sounds:** Always have `userN.wav` even if you have `userNs2.wav`
