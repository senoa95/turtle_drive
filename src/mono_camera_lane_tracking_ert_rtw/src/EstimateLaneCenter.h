//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: EstimateLaneCenter.h
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
#ifndef RTW_HEADER_EstimateLaneCenter_h_
#define RTW_HEADER_EstimateLaneCenter_h_
#ifndef mono_camera_lane_tracking_COMMON_INCLUDES_
# define mono_camera_lane_tracking_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                            // mono_camera_lane_tracking_COMMON_INCLUDES_

#include "mono_camera_lane_tracking_types.h"

// Block signals and states (default storage) for system '<Root>/Estimate Lane Center' 
typedef struct {
  real_T Delay_4_DSTATE;               // '<S1>/Delay'
  real_T Delay_3_DSTATE;               // '<S1>/Delay'
  real_T Delay_2_DSTATE;               // '<S1>/Delay'
  real_T Delay_1_DSTATE;               // '<S1>/Delay'
} DW_EstimateLaneCenter;

// Invariant block signals for system '<Root>/Estimate Lane Center'
typedef const struct tag_ConstB_EstimateLaneCenter {
  real_T Subtract;                     // '<S6>/Subtract'
  real_T Product1;                     // '<S6>/Product1'
  real_T Subtract_l;                   // '<S3>/Subtract'
  real_T Product1_g;                   // '<S3>/Product1'
  real_T Add;                          // '<S4>/Add'
  real_T Add1;                         // '<S4>/Add1'
  real_T Add2;                         // '<S4>/Add2'
  real_T Add3;                         // '<S4>/Add3'
} ConstB_EstimateLaneCenter;

#endif                                 // RTW_HEADER_EstimateLaneCenter_h_

//
// File trailer for generated code.
//
// [EOF]
//
