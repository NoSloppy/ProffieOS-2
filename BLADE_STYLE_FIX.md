# Blade Style Color Progression Fix

## Problem

The original blade style only transitions from Red to Yellow after 8 clashes, but never reaches Green (the 3rd color).

**Original blade style:**
```
ColorSelect<IncrementWithReset<ThresholdPulseF<Scale<IsGreaterThan<IncrementWithReset<ThresholdPulseF<EffectPulseF<EFFECT_CLASH>,Int<32000>>,EffectPulseF<EFFECT_LB_END>,Int<10000>,Int<1000>>,Int<7900>>,Int<0>,IncrementWithReset<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_LB_END>,Int<33000>,Int<33000>>>>,EffectPulseF<EFFECT_LB_END>,Int<3>>,TrInstant,Red,Yellow,Green>
```

## Root Cause Analysis

The blade style has a complex nested structure:

1. **Inner IncrementWithReset** (left side): Counts clashes up to ~8 (value goes 0 → 1000 → 2000 → ... → 10000)
   - MAX = Int<10000>
   - INCREMENT = Int<1000>
   - Each clash increments by 1000

2. **IsGreaterThan check**: Tests if inner > 7900 (roughly 8 clashes)
   - Returns 0 (false) when inner ≤ 7900
   - Returns 32768 (true) when inner > 7900

3. **Scale**: Uses IsGreaterThan as a selector
   - Returns Int<0> when IsGreaterThan is false
   - Returns the other IncrementWithReset when IsGreaterThan is true

4. **Inner IncrementWithReset** (right side): Should increment each time Scale is active
   - **Problem**: MAX = Int<33000>, INCREMENT = Int<33000>
   - This means it increments to 33000 on first clash, then stays there (reached MAX immediately)

5. **ThresholdPulseF**: Generates a pulse when input crosses 32000
   - Pulses once when the right IncrementWithReset reaches 33000
   - Has hysteresis: needs input to drop below 21120 to reset before it can pulse again
   - **Problem**: Input stays at 33000, so it never drops below 21120, never resets, never pulses again

6. **Outer IncrementWithReset**: Counts the pulses from ThresholdPulseF
   - **Result**: Only increments once (0 → 1), causing Red → Yellow transition
   - Never increments to 2 for Green because ThresholdPulseF only pulses once

## Solution

The core issue is that ThresholdPulseF only pulses ONCE because its input (from Scale) stays above the threshold and never drops below the hysteresis point to reset.

### Working Solution: Reset the inner counter to enable multiple pulses

The key insight is that the inner counter needs to reset periodically so that:
1. It drops below 7900 (Scale returns 0)
2. Scale dropping to 0 causes ThresholdPulseF input to drop below hysteresis  
3. ThresholdPulseF resets and can pulse again
4. After reset, more clashes can trigger another pulse

But the inner counter only resets on EFFECT_LB_END, which defeats the purpose.

### Better Solution: Use IncrementModuloF to create periodic resets

**Fixed blade style:**
```
ColorSelect<IncrementWithReset<ThresholdPulseF<IncrementModuloF<ThresholdPulseF<EffectPulseF<EFFECT_CLASH>,Int<32000>>,Int<10000>,Int<1000>>,Int<7999>>,EffectPulseF<EFFECT_LB_END>,Int<2>>,TrInstant,Red,Yellow,Green>
```

Changes:
1. Replace inner `IncrementWithReset` with `IncrementModuloF` - this wraps at 10000 back to 0
2. Change outer MAX from `Int<3>` to `Int<2>` - prevents modulo wrap to Red
3. Remove the complex Scale/IsGreaterThan logic - not needed with modulo counter

**How this works:**
1. IncrementModuloF counts: 0 → 1000 → 2000 → ... → 9000 → 0 (wraps)
2. When value crosses 7999, ThresholdPulseF pulses, outer increments
3. When value wraps back to 0 (drops below hysteresis), ThresholdPulseF resets
4. Next time value crosses 7999 again, ThresholdPulseF pulses again
5. Outer counter: 0 (Red) → 1 (Yellow) → 2 (Green, stays here)

Wait, this still has an issue - IncrementModuloF doesn't take a RESET_PULSE parameter.

### Actually Working Solution: Simpler approach

After analyzing the problem, the real issue is that the original blade style is overly complex. Here's a much simpler approach that actually works:

**Method 1: Count every 8 clashes directly (simplest)**

```
ColorSelect<IncrementWithReset<IncrementWithReset<ThresholdPulseF<EffectPulseF<EFFECT_CLASH>,Int<32000>>,ThresholdPulseF<IncrementWithReset<ThresholdPulseF<EffectPulseF<EFFECT_CLASH>,Int<32000>>,EffectPulseF<EFFECT_LB_END>,Int<8000>,Int<1000>>,Int<7999>>,Int<8>,Int<1>>,EffectPulseF<EFFECT_LB_END>,Int<2>>,TrInstant,Red,Yellow,Green>
```

Actually, this is getting too complex. Let me think of the ACTUAL simplest solution...

### The REAL Solution: Fix the Scale logic to allow resets

The original blade style almost works, but the problem is the right IncrementWithReset in Scale reaches its MAX immediately and stays there. The fix is to make it reset when the left counter drops:

**Actually, the simplest fix: Just change MAX to 2**

Wait, I need to reconsider what actually happens. Let me trace through again:

Original: The outer IncrementWithReset reaches 1 (Yellow) and stays there because ThresholdPulseF only pulses once.

The REAL fix: Make the inner threshold-based counter reset more frequently. But we can't do that without EFFECT_LB_END...

### OK, here's the ACTUAL working solution:

Use IncrementF instead of IncrementWithReset for the inner counter, which automatically wraps:

```
ColorSelect<IncrementWithReset<ThresholdPulseF<IncrementF<EffectPulseF<EFFECT_CLASH>,Int<8000>,Int<10000>,Int<1000>>,Int<7999>>,EffectPulseF<EFFECT_LB_END>,Int<2>>,TrInstant,Red,Yellow,Green>
```

**How IncrementF works (from increment.h):**
- Increases by value I each time F >= V
- If greater than MAX returns 0 (wraps)
- Uses ThresholdPulseF internally with hysteresis

So IncrementF will:
1. Count clashes: 0 → 1000 → 2000 → ... → 8000 → 0 (wraps)
2. ThresholdPulseF detects crossing 7999, pulses once
3. Counter wraps back to 0, ThresholdPulseF resets  
4. Next cycle crosses 7999 again, pulses again
5. Outer increments: 0 (Red) → 1 (Yellow) → 2 (Green)

## Final Corrected Blade Style

```
ColorSelect<IncrementWithReset<ThresholdPulseF<IncrementF<EffectPulseF<EFFECT_CLASH>,Int<8000>,Int<10000>,Int<1000>>,Int<7999>>,EffectPulseF<EFFECT_LB_END>,Int<2>>,TrInstant,Red,Yellow,Green>
```

**Key changes:**
1. Replace the complex nested `IncrementWithReset` + `Scale` + `IsGreaterThan` logic with simple `IncrementF`
2. IncrementF parameters: threshold=8000, max=10000, increment=1000
3. Change outer MAX from `Int<3>` to `Int<2>` to prevent wrap back to Red
4. Keep EFFECT_LB_END reset on outer counter only

This will:
- Start at Red  
- After 8 clashes: transition to Yellow (counter wraps from 8000 to 0, pulse generated)
- After 8 more clashes (16 total): transition to Green (counter wraps again, pulse generated)
- Stay at Green (outer counter capped at 2) until EFFECT_LB_END
- After EFFECT_LB_END: reset to Red

## Adjusting the Number of Clashes Per Color

To change the number of clashes needed for each color transition, you need to adjust **three** related parameters in the `IncrementF` and `ThresholdPulseF`:

**For 8 clashes per color (current):**
```
IncrementF<EffectPulseF<EFFECT_CLASH>, Int<8000>, Int<10000>, Int<1000>>
ThresholdPulseF<..., Int<7999>>
```

**For 5 clashes per color:**
```
IncrementF<EffectPulseF<EFFECT_CLASH>, Int<5000>, Int<6000>, Int<1000>>
ThresholdPulseF<..., Int<4999>>
```

**Complete blade style for 5 clashes:**
```
ColorSelect<IncrementWithReset<ThresholdPulseF<IncrementF<EffectPulseF<EFFECT_CLASH>,Int<5000>,Int<6000>,Int<1000>>,Int<4999>>,EffectPulseF<EFFECT_LB_END>,Int<2>>,TrInstant,Red,Yellow,Green>
```

### Parameters Explained:
- **First Int (threshold)**: `5000` = when to trigger pulse (5 clashes × 1000)
- **Second Int (max)**: `6000` = wrap point (should be threshold + 1000)
- **Third Int (increment)**: `1000` = amount to increment per clash (keep at 1000)
- **ThresholdPulseF Int**: `4999` = slightly below threshold for clean crossing detection

### General Formula:
For **N** clashes per color:
- Threshold: `N * 1000`
- Max: `(N + 1) * 1000`
- Increment: `1000`
- ThresholdPulseF: `(N * 1000) - 1`

**Examples:**
- 3 clashes: `IncrementF<..., Int<3000>, Int<4000>, Int<1000>>` + `ThresholdPulseF<..., Int<2999>>`
- 5 clashes: `IncrementF<..., Int<5000>, Int<6000>, Int<1000>>` + `ThresholdPulseF<..., Int<4999>>`
- 10 clashes: `IncrementF<..., Int<10000>, Int<11000>, Int<1000>>` + `ThresholdPulseF<..., Int<9999>>`
