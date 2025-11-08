# USERn_STEP2 Feature - Implementation Summary

## Overview

This implementation adds full support for two-step user effects (USER1_STEP2 through USER8_STEP2) that enable accurate sound-length timing with WavLen<> when using queued sounds.

## Problem Statement

When props use `SOUNDQ->Play()` to queue sounds, effects triggered via `DoEffect()` happen separately from the sound playback. This caused:

1. **WavLen<> returns 0** - No sound is playing when the effect triggers
2. **Timing mismatches** - Visual effects can't sync with sound durations
3. **Hardcoded workarounds** - Had to use fixed delays like `TrDelayX<Int<4000>>`

Example from HEV prop:
```cpp
// Health alert triggers effect
SaberBase::DoEffect(EFFECT_USER1, 0.0);

// But sound is queued separately
SOUNDQ->Play(&SFX_health);

// In blade style, WavLen returns 0
TransitionEffectL<..., TrDelayX<WavLen<>>, EFFECT_USER1>  // ❌ WavLen is 0
```

## Solution

Implement effect queueing (similar to SOUNDQ) where:

1. **EFFECT_USERn triggers immediately** - Fires right away for instant response
2. **EFFECT_USERn_STEP2 auto-queues** - Added to effect queue automatically  
3. **Queue waits for sound** - Uses actual sound_length to wait
4. **STEP2 triggers with sound** - Effect and sound happen together
5. **WavLen<> works correctly** - Returns accurate sound duration

```cpp
// Trigger USER1
SaberBase::DoEffect(EFFECT_USER1, 0.0);
// → EFFECT_USER1 fires immediately
// → EFFECT_USER1_STEP2 auto-queued

// In blade style
TransitionEffectL<..., TrDelayX<WavLen<EFFECT_USER1_STEP2>>, EFFECT_USER1_STEP2>
// ✅ WavLen returns actual sound duration!
```

## Implementation Details

### 1. Effect Type Definitions (saber_base.h)

Added 8 new effect types after USER8:
```cpp
DEFINE_EFFECT(USER1_STEP2)
DEFINE_EFFECT(USER2_STEP2)
DEFINE_EFFECT(USER3_STEP2)
DEFINE_EFFECT(USER4_STEP2)
DEFINE_EFFECT(USER5_STEP2)
DEFINE_EFFECT(USER6_STEP2)
DEFINE_EFFECT(USER7_STEP2)
DEFINE_EFFECT(USER8_STEP2)
```

### 2. Effect Queue System (saber_base.h)

Created `EffectQueue<QueueLength>` template class:
- Similar structure to `SoundQueue`
- Queues `EffectToTrigger` structs
- Processes sequentially with timing based on sound_length
- 10ms buffer after each sound for safety

Key methods:
- `Queue(EffectType, EffectLocation)` - Add effect to queue
- `PollEffectQueue()` - Process queue (call from Loop)
- `clear()` - Clear all queued effects

### 3. Automatic Queueing (saber_base.h - PushEffect)

When USER effects are pushed, automatically queue STEP2:
```cpp
case EFFECT_USER1:
  effect_queue_.Queue(EFFECT_USER1_STEP2, location);
  break;
// ... same for USER2-USER8
```

### 4. Sound File Support (effect.h)

Added effect declarations with fallback:
```cpp
EFFECT(user1);
EFFECT(user2);
// ... through user8

EFFECT2(user1s2, user1);  // Falls back to user1 if user1s2 not found
EFFECT2(user2s2, user2);
// ... through user8s2
```

### 5. Sound Playback (hybrid_font.h)

Added handlers for all USER and STEP2 effects:
```cpp
case EFFECT_USER1: PlayCommon(&SFX_user1); return;
case EFFECT_USER1_STEP2: PlayCommon(&SFX_user1s2); return;
// ... same for USER2-USER8
```

### 6. Queue Processing

Props must call this in their Loop():
```cpp
void Loop() override {
  SaberBase::ProcessEffectQueue();
  // ... rest of loop
}
```

## Usage Example (HEV Health Warning)

### Blade Style
```cpp
TransitionEffectL<
  TrConcat<
    TrDelay<1400>,
    Black,
    TrFade<300>,
    Cylon<Red,5,20,Gradient<Red,Red,Green>,33,50,1>,
    TrDelayX<WavLen<EFFECT_USER1_STEP2>>,  // Duration matches sound!
    TrFade<300>,
    Black,
    TrFade<300>
  >,
  EFFECT_USER1_STEP2
>
```

### Sound Files
- `health.wav` - "Warning: Health at 40"
- `user1s2.wav` - Alert beep or tone (Cylon displays for this duration)

### Timeline
1. Health drops → `DoEffect(EFFECT_USER1, 0)`
2. Health voice plays via SOUNDQ
3. EFFECT_USER1_STEP2 auto-queues
4. After voice completes, STEP2 triggers
5. Cylon displays for `WavLen<EFFECT_USER1_STEP2>` duration
6. Perfect sync between visual and audio!

## Files Modified

1. **common/saber_base.h** (130 lines added)
   - EFFECT_USERn_STEP2 definitions
   - EffectToTrigger struct
   - EffectQueue<> template class
   - Automatic STEP2 queueing in PushEffect
   - ProcessEffectQueue() method
   - Template implementation after SaberBase definition

2. **sound/effect.h** (20 lines added)
   - EFFECT(user1) through EFFECT(user8)
   - EFFECT2(user1s2, user1) through EFFECT2(user8s2, user8)

3. **sound/hybrid_font.h** (16 lines added)
   - case EFFECT_USER1 through EFFECT_USER8
   - case EFFECT_USER1_STEP2 through EFFECT_USER8_STEP2
   - All use PlayCommon() for mono/poly compatibility

4. **.gitignore** (25 lines added)
   - Exclude test artifacts from commits

5. **doc/USER_STEP2_EFFECTS.md** (210 lines added)
   - Comprehensive usage documentation
   - Technical specifications
   - Examples and best practices

6. **doc/HEV_STEP2_EXAMPLE.md** (306 lines added)
   - Real-world HEV prop example
   - Actual Cylon/WavLen use case
   - Sound file strategies
   - Troubleshooting guide

**Total: 707 lines added**

## Testing

### Unit Tests
- ✅ common/tests pass
- ✅ common/test2 pass
- ✅ blades/tests pass

### Real-World Testing
Requires:
1. Blade style with `WavLen<EFFECT_USERn_STEP2>`
2. Prop that calls `ProcessEffectQueue()` in Loop()
3. Sound files (userN.wav and optionally userNs2.wav)
4. Hardware to verify visual/audio sync

HEV prop health warning system is the primary test case.

## Integration Requirements

**For Prop Files:**
```cpp
void Loop() override {
  SaberBase::ProcessEffectQueue();  // Required!
  // ... rest of loop
}
```

**For Sound Files:**
- Place `user1.wav` through `user8.wav` in font directory
- Optionally add `user1s2.wav` through `user8s2.wav`
- If s2 files don't exist, falls back to userN.wav

**For Blade Styles:**
- Use `EFFECT_USERn` for immediate effects
- Use `EFFECT_USERn_STEP2` for timed effects with WavLen<>

## Benefits

1. **Accurate timing** - WavLen<> returns real sound duration
2. **No hardcoded delays** - Visual effects automatically match audio
3. **Sequential effects** - Multiple alerts queue properly without overlap
4. **Backward compatible** - Existing code continues to work unchanged
5. **Flexible** - Can use immediate or queued effects as needed
6. **Simple integration** - Just call ProcessEffectQueue() in Loop()

## Design Decisions

### Why Auto-Queue?
Automatically queueing STEP2 when USERn triggers ensures:
- Users don't forget to queue manually
- Consistent behavior across all props
- Simpler API (just trigger USERn as normal)

### Why Separate STEP2 Effects?
Having distinct EFFECT_USERn_STEP2 types allows:
- Blade styles to react differently to immediate vs queued
- Different visual effects for step 1 vs step 2
- Clear intent in blade style code

### Why Template Implementation After Class?
The EffectQueue template needs to call SaberBase methods, so the implementation must come after SaberBase is fully defined. This is a common C++ pattern for templates that reference the containing class.

### Why 10ms Buffer?
After each sound completes, we add 10ms before triggering the next queued effect. This prevents edge cases where:
- Sound player hasn't fully released
- Timing is too tight and effects overlap
- Small inaccuracies in sound_length measurement

## Future Enhancements

Possible improvements (not implemented):

1. **Manual queuing** - `SaberBase::QueueEffect(type, location, delay_ms)`
2. **Queue inspection** - Methods to check queue state
3. **Priority system** - High-priority effects bypass queue
4. **Conditional queueing** - Only queue STEP2 if sound exists
5. **Queue events** - Callbacks when effects are queued/triggered

## Credits

Implementation based on Fredrik Hubinette's suggestion to queue effects (not just sounds) so effects and sounds trigger together, enabling accurate sound_length (wavlen) access.

Primary use case from HEV prop by James Nash, which needed accurate timing for health announcement visual effects.

## Summary

This feature solves a fundamental timing problem in ProffieOS where effects and queued sounds couldn't be synchronized. By implementing an effect queue that works alongside the sound queue, visual effects can now accurately match sound durations using WavLen<>, eliminating the need for hardcoded delays and enabling rich, synchronized audio-visual effects.
