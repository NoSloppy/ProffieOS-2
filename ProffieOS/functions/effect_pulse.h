#ifndef FUNCTIONS_EFFECT_PULSE_H
#define FUNCTIONS_EFFECT_PULSE_H

#include "svf.h"

// Usage: EffectPulse<EFFECT>
// EFFECT: BladeEffectType
// Returns 32768 once for each time the given effect occurs.

template<BladeEffectType EFFECT>
class EffectPulseSVF {
public:
  void run(BladeBase* blade) {}
  int calculate(BladeBase* blade) {
    return effect_.Detect(blade) ? 32768 : 0;
  }
private:
  OneshotEffectDetector<EFFECT> effect_;
};

template<BladeEffectType EFFECT>
using EffectPulseF = SingleValueAdapter<EffectPulseSVF<EFFECT>>;

// Usage: LockupPulseF<LOCKUP_TYPE>
// LOCKUP_TYPE: a SaberBase::LockupType
// Returns 32768 once for each time the given lockup occurs.

template<SaberBase::LockupType LOCKUP_TYPE>
class LockupPulseSVF {
public:
  LockupPulseSVF() {
    BladeBase::HandleFeature(FeatureForLockupType(LOCKUP_TYPE));
  }
  void run(BladeBase* blade) {}
  int calculate(BladeBase* blade) {
    if (SaberBase::LockupForBlade(blade->GetBladeNumber()) == LOCKUP_TYPE) {
      return 32768;
    } else {
      return 0;
    }
  }
};

template<SaberBase::LockupType LOCKUP_TYPE>
using LockupPulseF = SingleValueAdapter<LockupPulseSVF<LOCKUP_TYPE>>;

// Usage: ThresholdPulseF<F, THRESHOLD, HYST_PERCENT>
// F: FUNCTION
// THRESHOLD: FUNCTION (defaults to Int<32768>)
// HYST_PERCENT: FUNCTION (defaults to Int<66>
// Returns 32768 once when F > THRESHOLD, then waits until
// F < THRESHOLD * HYST_PERCENT / 100 before going back
// to the initial state (waiting for F > THRESHOLD).

template<class F, class THRESHOLD = Int<32768>, class HYST_PERCENT = Int<66> >
class ThresholdPulseFSVF {
public:
  void run(BladeBase* blade) {
    f_.run(blade);
    threshold_.run(blade);
    hyst_percent_.run(blade);
  }
  int calculate(BladeBase* blade) {
    int f = f_.calculate(blade);
    int threshold = threshold_.calculate(blade);
    if (triggered_) {
      if (f < threshold * hyst_percent_.calculate(blade) / 100) {
  triggered_ = false;
      }
    } else {
      if (f >= threshold) {
  triggered_ = true;
  return 32768;
      }
    }
    return 0;
  }
  
private:
  PONUA SVFWrapper<F> f_;
  PONUA SVFWrapper<THRESHOLD> threshold_;
  PONUA SVFWrapper<HYST_PERCENT> hyst_percent_;
  bool triggered_ = false;
};

template<class F, class THRESHOLD = Int<32768>, class HYST_PERCENT = Int<66> >
using ThresholdPulseF = SingleValueAdapter<ThresholdPulseFSVF<F, THRESHOLD, HYST_PERCENT>>;

#endif  // FUNCTIONS_EFFECT_PULSE_H