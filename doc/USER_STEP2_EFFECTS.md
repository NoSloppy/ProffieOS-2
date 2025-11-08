# USERn_STEP2 Effects Documentation

## Overview

The USERn_STEP2 feature provides a two-step effect system for USER1 through USER8 effects. This allows for sequential effect triggering where STEP2 effects automatically queue and wait for the first effect's sound to complete before triggering.

## How It Works

### Automatic Queueing

When you trigger any USERn effect (USER1-USER8), the system automatically:
1. **Immediately triggers** the USERn effect (sound + visual)
2. **Queues** the corresponding USERn_STEP2 effect
3. **Waits** for the USERn sound to complete
4. **Triggers** the USERn_STEP2 effect

### Sound Files

Place sound files in your font directory with these naming conventions:

- `user1.wav` through `user8.wav` - Primary effects
- `user1s2.wav` through `user8s2.wav` - Step 2 effects (optional)

If `userNs2.wav` files are not found, they will fall back to playing the corresponding `userN.wav` file.

## Usage in Prop Files

### Basic Example

```cpp
// Trigger USER1 effect (will automatically queue USER1_STEP2)
SaberBase::DoEffect(EFFECT_USER1, 0);
```

When this line executes:
1. EFFECT_USER1 triggers immediately
2. `user1.wav` plays
3. EFFECT_USER1_STEP2 is automatically queued
4. After `user1.wav` completes, EFFECT_USER1_STEP2 triggers
5. `user1s2.wav` plays (or `user1.wav` if not found)

### With SOUNDQ

If your prop uses SOUNDQ for queuing sounds, the effect queue works independently:

```cpp
// Queue multiple sounds with their effects
SOUNDQ->Play(&SFX_user1);
SaberBase::DoEffect(EFFECT_USER1, 0);  // Queues USER1_STEP2

SOUNDQ->Play(&SFX_user2);
SaberBase::DoEffect(EFFECT_USER2, 0);  // Queues USER2_STEP2
```

## Usage in Blade Styles

Blade styles can react to either the immediate effect or the queued STEP2 effect:

### Immediate Effect (EFFECT_USERn)
Use these for instant visual responses:

```cpp
TransitionEffectL<TrInstant, EFFECT_USER1, AlphaL<Red, Int<16384>>>
```

### Queued Effect (EFFECT_USERn_STEP2)
Use these for sequential effects:

```cpp
TransitionEffectL<TrFade<300>, EFFECT_USER1_STEP2, AlphaL<Blue, Int<16384>>>
```

### Combined Example

```cpp
// Blade reacts to both step 1 and step 2
Layers<
  // Base blade color
  Blue,
  // Flash red immediately on USER1
  TransitionEffectL<TrInstant, EFFECT_USER1, AlphaL<Red, Int<32768>>>,
  // Flash green after USER1 sound completes
  TransitionEffectL<TrFade<300>, EFFECT_USER1_STEP2, AlphaL<Green, Int<32768>>>
>
```

## Processing the Effect Queue

The effect queue must be processed in a Loop(). The recommended approach is to call it from the main loop:

```cpp
void Loop() override {
  SaberBase::ProcessEffectQueue();
  // ... other loop code
}
```

Alternatively, create a dedicated Looper:

```cpp
class EffectQueueProcessor : public Looper {
public:
  const char* name() override { return "EffectQueueProcessor"; }
  void Loop() override {
    SaberBase::ProcessEffectQueue();
  }
};

EffectQueueProcessor effect_queue_processor;
```

## Technical Details

### Effect Queue Specifications

- **Queue Size:** 8 effects
- **Processing:** Sequential (one at a time)
- **Timing:** Based on actual sound lengths (wavlen)
- **Buffer:** 10ms added after each sound for safety

### Supported Effects

All USER effects automatically queue their STEP2 variants:

- EFFECT_USER1 → EFFECT_USER1_STEP2
- EFFECT_USER2 → EFFECT_USER2_STEP2
- EFFECT_USER3 → EFFECT_USER3_STEP2
- EFFECT_USER4 → EFFECT_USER4_STEP2
- EFFECT_USER5 → EFFECT_USER5_STEP2
- EFFECT_USER6 → EFFECT_USER6_STEP2
- EFFECT_USER7 → EFFECT_USER7_STEP2
- EFFECT_USER8 → EFFECT_USER8_STEP2

### Effect Lifecycle

1. **Trigger:** EFFECT_USERn is triggered via DoEffect()
2. **Sound:** Sound system plays `userN.wav` and sets SaberBase::sound_length
3. **Queue:** EFFECT_USERn_STEP2 is automatically added to the effect queue
4. **Wait:** Effect queue monitors time, waiting for sound to complete
5. **Trigger Step2:** After sound_length expires, EFFECT_USERn_STEP2 is triggered
6. **Repeat:** If more effects are queued, process the next one

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
