// BC style shortcuts

using OnDemandVolumeLevel = TransitionEffectL<TrConcat<TrSmoothFade<200>,AlphaL<Gradient<Blue,Green>,SmoothStep<VolumeLevel,Int<-1>>>,TrDelay<1000>,TrSmoothFade<500>>,EFFECT_VOLUME_LEVEL>;
using OnDemandBatteryLevel = AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>;

using BC_Bend1_NoSpark_SetOUT_NoSpark_WavIN =
InOutTrL<
// OUT
TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,
// IN
TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>;
// find - InOutTrL<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>

using BC_Bend2_Spark_SetOUT_NoSpark_WavIN =
InOutTrL<
// OUT
TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,
// IN
TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>;
// find - InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>

using BC_Bend3_NoSpark_SetOUT_Spark_WavIN =
InOutTrL<
// OUT
TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,
// IN
TrWipeInSparkTipX<AlphaL<White,Trigger<EFFECT_RETRACTION,Int<100>,WavLen<EFFECT_RETRACTION>,Int<1>,Percentage<WavLen<EFFECT_RETRACTION>,35>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>;
// find - InOutTrL<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrWipeInSparkTipX<AlphaL<White,Trigger<EFFECT_RETRACTION,Int<100>,WavLen<EFFECT_RETRACTION>,Int<1>,Percentage<WavLen<EFFECT_RETRACTION>,35>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>

using BC_Bend4_Spark_SetOUT_Spark_WavIN =
InOutTrL<
// OUT
TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,
// IN
TrWipeInSparkTipX<AlphaL<White,Trigger<EFFECT_RETRACTION,Int<100>,WavLen<EFFECT_RETRACTION>,Int<1>,Percentage<WavLen<EFFECT_RETRACTION>,35>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>;
// find - InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<Int<1500>,Int<135000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<Int<1500>,Int<110000>>,Int<1600>>>,TrWipeInSparkTipX<AlphaL<White,Trigger<EFFECT_RETRACTION,Int<100>,WavLen<EFFECT_RETRACTION>,Int<1>,Percentage<WavLen<EFFECT_RETRACTION>,35>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>

// WavLen for ignition
using BC_Bend5_NoSpark_WavOUT_NoSpark_WavIN =
InOutTrL<
// OUT
TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<175000>>>,
// IN
TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>;
// find - InOutTrL<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<175000>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>;

using BC_Bend6_NoSpark_WavOUT_Spark_WavIN =
InOutTrL<
// OUT
TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<175000>>>,
// IN
TrWipeInSparkTipX<AlphaL<White,Trigger<EFFECT_RETRACTION,Int<100>,WavLen<EFFECT_RETRACTION>,Int<1>,Percentage<WavLen<EFFECT_RETRACTION>,35>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>;
// find - InOutTrL<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<175000>>>,TrWipeInSparkTipX<AlphaL<White,Trigger<EFFECT_RETRACTION,Int<100>,WavLen<EFFECT_RETRACTION>,Int<1>,Percentage<WavLen<EFFECT_RETRACTION>,35>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>;


using BC_Bend7_Spark_WavOUT_NoSpark_WavIN =
InOutTrL<
// OUT
TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,
// IN
TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>;
// find - InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInX<BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>>>;

using BC_Bend8_Spark_WavOUT_Spark_WavIN =
InOutTrL<
// OUT
TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,
// IN
TrWipeInSparkTipX<AlphaL<White,Trigger<EFFECT_RETRACTION,Int<100>,WavLen<EFFECT_RETRACTION>,Int<1>,Percentage<WavLen<EFFECT_RETRACTION>,35>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>;
// find - InOutTrL<TrJoin<TrWipeX<BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<110000>>>,TrSparkX<White,Int<400>,BendTimePowInvX<WavLen<EFFECT_IGNITION>,Int<85000>>,Int<1500>>>,TrWipeInSparkTipX<AlphaL<White,Trigger<EFFECT_RETRACTION,Int<100>,WavLen<EFFECT_RETRACTION>,Int<1>,Percentage<WavLen<EFFECT_RETRACTION>,35>>>,BendTimePowX<WavLen<EFFECT_RETRACTION>,Int<180000>>,Int<401>>>;



