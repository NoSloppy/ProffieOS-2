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

Integrate effect triggering directly into SOUNDQ where:

1. **Sound queued with effect tag** - `SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2))`
2. **SOUNDQ processes queue** - Other sounds may play first (normal queue behavior)
3. **When sound plays** - SOUNDQ triggers the associated effect automatically
4. **Effect and sound sync** - They happen at exactly the same time
5. **WavLen<> works correctly** - Returns accurate sound duration

```cpp
// Queue sound with STEP2 effect
SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2));
// → Sound queued to SOUNDQ
// → When sound actually plays, STEP2 triggers automatically

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

### 2. Sound Queue Integration (sound_queue.h)

Modified `SoundToPlay` struct to support effect triggering:
- Added `effect_to_trigger_` field (defaults to `EFFECT_NONE`)
- Added constructors: `SoundToPlay(Effect*, EffectType)` and `SoundToPlay(const char*, EffectType)`
- Modified `PollSoundQueue()` to trigger associated effect when sound starts playing

```cpp
struct SoundToPlay {
  const char* filename_;
  Effect::FileID file_id_;
  EffectType effect_to_trigger_;  // New field

  // New constructors
  SoundToPlay(Effect* effect, EffectType trigger_effect);
  SoundToPlay(const char* file, EffectType trigger_effect);
};
```

When SOUNDQ plays a sound (in `PollSoundQueue()`):
```cpp
queue_[0].Play(player.get());

// Trigger associated effect when sound starts playing
if (queue_[0].effect_to_trigger_ != EFFECT_NONE) {
  SaberBase::DoEffect(queue_[0].effect_to_trigger_, 0);
}
```

### 3. Backward Compatibility

All existing `SoundToPlay` constructors default `effect_to_trigger_` to `EFFECT_NONE`, ensuring existing code continues to work:
```cpp
SoundToPlay(Effect* effect) : ... effect_to_trigger_(EFFECT_NONE) {}
```

Existing calls remain unchanged:
- `SOUNDQ->Play(&SFX_health)` ✅ Works (no effect triggered)
- `SOUNDQ->Play("file.wav")` ✅ Works (no effect triggered)

### 4. Sound Playback (hybrid_font.h)

STEP2 effects are handled through the normal hybrid_font effect system. When triggered by SOUNDQ, they play their associated sound and set sound_length for WavLen<>.

No special handlers needed - STEP2 effects work like any other effect type.

## Usage Example (HEV Health Warning)

### Prop Integration

Update the `SB_Effect` handler to queue sound with STEP2 effect:

```cpp
case EFFECT_USER1:
  SFX_health.SelectFloat(health_ / 100.0);
  // Queue sound with STEP2 - effect triggers when sound plays!
  SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2));
  return;
```

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
- `user1.wav` - The sound that will be played (e.g., health voice line)
- No separate s2 files needed - props control what sound plays

### Timeline
1. Health drops → Prop calls `SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2))`
2. Sound queued to SOUNDQ (may wait behind other sounds)
3. When health sound actually plays → EFFECT_USER1_STEP2 triggers automatically
4. Cylon displays for `WavLen<EFFECT_USER1_STEP2>` duration
5. Perfect sync - visual appears exactly when voice plays!

## Files Modified

1. **common/saber_base.h**
   - EFFECT_USERn_STEP2 definitions (8 new effect types)

2. **sound/sound_queue.h**
   - Added `effect_to_trigger_` field to `SoundToPlay`
   - Added new constructors with effect parameter
   - Modified `PollSoundQueue()` to trigger effects when sounds play

3. **sound/effect.h**
   - No changes needed - sound files can be played without pre-declaration

4. **sound/hybrid_font.h**
   - No changes needed - STEP2 effects handled like any other effect

5. **doc/USER_STEP2_EFFECTS.md**
   - Comprehensive usage documentation
   - Technical specifications
   - Examples and best practices

6. **doc/HEV_STEP2_EXAMPLE.md**
   - Real-world HEV prop example
   - Actual Cylon/WavLen use case
   - Sound file strategies
   - Troubleshooting guide

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
Update `SB_Effect` handlers to queue sounds with STEP2 effects:
```cpp
case EFFECT_USER1:
  SFX_health.SelectFloat(health_ / 100.0);
  SOUNDQ->Play(SoundToPlay(&SFX_health, EFFECT_USER1_STEP2));
  return;
```

No Loop() processing needed - SOUNDQ handles effect triggering automatically.

**For Sound Files:**
- Place `user1.wav` through `user8.wav` in font directory (or any sound file name)
- Props control which sounds play for which effects

**For Blade Styles:**
- Use `EFFECT_USERn_STEP2` for effects synchronized with SOUNDQ sounds
- WavLen<EFFECT_USERn_STEP2> returns accurate sound duration

## Benefits

1. **Perfect synchronization** - Effects trigger exactly when sounds play
2. **Accurate timing** - WavLen<> returns real sound duration
3. **No hardcoded delays** - Visual effects automatically match audio
4. **Works with queue delays** - Handles other sounds playing first
5. **Backward compatible** - Existing code continues to work unchanged
6. **Simple integration** - Just use new SoundToPlay constructor

## Design Decisions

### Why Integrate with SOUNDQ?
Triggering effects from SOUNDQ when sounds actually play ensures:
- Perfect synchronization even when other sounds are queued first
- Accurate WavLen<> because sound is playing when effect triggers
- No separate queue processing needed

### Why Separate STEP2 Effects?
Having distinct EFFECT_USERn_STEP2 types allows:
- Blade styles to create sound-synchronized effects
- Props to control when effects trigger (immediate vs when sound plays)
- Clear intent in blade style code

### Why New Constructor Instead of Auto-Queueing?
Using `SoundToPlay(Effect*, EffectType)` gives props control over:
- Which effects trigger with which sounds
- Whether to use STEP2 at all
- Maximum flexibility for different use cases

## Credits

Implementation based on Fredrik Hubinette's suggestion to trigger effects when sounds play (not separately) so effects and sounds happen together, enabling accurate sound_length (wavlen) access.

Primary use case from HEV prop by James Nash, which needed accurate timing for health announcement visual effects synchronized with voice lines.

## Summary

This feature solves a fundamental timing problem in ProffieOS where effects and queued sounds couldn't be synchronized. By integrating effect triggering directly into SOUNDQ, visual effects can now trigger exactly when sounds play and accurately match sound durations using WavLen<>, eliminating the need for hardcoded delays and enabling rich, synchronized audio-visual effects.
