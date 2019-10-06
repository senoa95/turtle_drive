//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: mono_camera_lane_tracking_data.cpp
//
// Code generated for Simulink model 'mono_camera_lane_tracking'.
//
// Model version                  : 1.762
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sun Oct  6 17:36:27 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "mono_camera_lane_tracking.h"
#include "mono_camera_lane_tracking_private.h"

// Invariant block signals (default storage)
const ConstB rtConstB = {
  {
    -66.031746031746039,
    20.869565217391305,
    37.095238095238095,
    -77.8017391304348
  }
  ,                                    // '<S46>/Matrix Concatenate'
  24.126984126984127
  ,                                    // '<S46>/Gain'
  15.860869565217392
  ,                                    // '<S46>/Gain1'

  // Start of '<Root>/Estimate Lane Center'
  {
    1.00104324663727
    ,                                  // '<S6>/Subtract'
    1.0020875816380863
    ,                                  // '<S6>/Product1'
    0.96570793674747324
    ,                                  // '<S3>/Subtract'
    0.93259181909706179
    ,                                  // '<S3>/Product1'
    0.019630727716553817
    ,                                  // '<S4>/Add'
    -0.0010245709951852739
    ,                                  // '<S4>/Add1'
    0.3146839612370167
    ,                                  // '<S4>/Add2'
    -0.817025068611844
    // '<S4>/Add3'
  }
  // End of '<Root>/Estimate Lane Center'
};

// Constant parameters (default storage)
const ConstP rtConstP = {
  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S11>/Reference constant'
  //    '<S13>/U Constant'
  //    '<S13>/Y Constant'
  //    '<S14>/F_zero'
  //    '<S14>/y.wt_zero'
  //    '<S14>/ymax_zero'
  //    '<S14>/ymin_zero'

  { 0.0, 0.0 },

  // Pooled Parameter (Expression: zeros(NumEgoStates+2*(1+hasLag),1))
  //  Referenced by:
  //    '<S13>/DX Constant'
  //    '<S13>/X Constant'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: lastPcov
  //  Referenced by: '<S15>/LastPcov'

  { 0.50122212108824427, 0.34797925370382254, -0.01945933218759523,
    -0.010976571613469939, 0.014490759144003244, 0.34797925370382254,
    0.6585216746484015, 0.098399393256076828, 0.0630047458032801,
    -0.0030899664277228931, -0.01945933218759523, 0.098399393256076828,
    0.128838565122736, 0.030815536408990419, -0.053417773147518458,
    -0.010976571613469939, 0.0630047458032801, 0.030815536408990419,
    0.014469543208574851, -0.0095964902719191236, 0.014490759144003244,
    -0.0030899664277228931, -0.053417773147518458, -0.0095964902719191236,
    0.13402669899530378 }
};

//
// File trailer for generated code.
//
// [EOF]
//
