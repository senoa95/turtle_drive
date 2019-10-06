//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: EstimateLaneCenter.cpp
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
#include "EstimateLaneCenter.h"

// Include model header file for global data
#include "mono_camera_lane_tracking.h"
#include "mono_camera_lane_tracking_private.h"

// Output and update for atomic system: '<Root>/Estimate Lane Center'
void PathFollowingControllerRefMdlModelClass::EstimateLaneCenter(real_T
  rtu_left_strength, real_T rtu_right_strength, real_T rtu_LongitudinalVelocity,
  real_T rtu_left_curvature_rate, real_T rtu_left_curvature, real_T
  rtu_left_relative_yaw_heading, real_T rtu_left_lateral_offset, real_T
  rtu_right_curvature_rate, real_T rtu_right_curvature, real_T
  rtu_right_relative_yaw_heading, real_T rtu_right_lateral_offset, real_T
  *rty_CurvatureDerivative, real_T *rty_PreviewedCurvature, real_T
  *rty_LateralDeviation, real_T *rty_RelativeYawAngle, const
  ConstB_EstimateLaneCenter *localC, DW_EstimateLaneCenter *localDW)
{
  real_T rtb_Product_d;
  real_T Curvature_o;
  real_T CurvatureDerivative_g;
  real_T HeadingAngle_j;
  real_T LateralOffset_b;

  // MATLAB Function: '<S1>/MATLAB Function'
  if ((rtu_left_strength > 0.0) && (rtu_right_strength > 0.0)) {
    // Outputs for Function Call SubSystem: '<S1>/Center from Left and Right'
    // Gain: '<S4>/Gain'
    Curvature_o = 0.5 * localC->Add;

    // Gain: '<S4>/Gain1'
    CurvatureDerivative_g = 0.5 * localC->Add1;

    // Gain: '<S4>/Gain2'
    HeadingAngle_j = 0.5 * localC->Add2;

    // Gain: '<S4>/Gain3'
    LateralOffset_b = 0.5 * localC->Add3;

    // End of Outputs for SubSystem: '<S1>/Center from Left and Right'
  } else if (rtu_left_strength > 0.0) {
    // Outputs for Function Call SubSystem: '<S1>/Center from Left'
    // Product: '<S3>/Divide'
    Curvature_o = rtu_left_curvature / localC->Subtract_l;

    // Product: '<S3>/Divide1'
    CurvatureDerivative_g = rtu_left_curvature_rate / localC->Product1_g;

    // Sum: '<S3>/Subtract1' incorporates:
    //   Constant: '<S3>/Half Lane Width Estimate1'

    LateralOffset_b = rtu_left_lateral_offset - 1.8;

    // SignalConversion generated from: '<S3>/Center'
    HeadingAngle_j = rtu_left_relative_yaw_heading;

    // End of Outputs for SubSystem: '<S1>/Center from Left'
  } else if (rtu_right_strength > 0.0) {
    // Outputs for Function Call SubSystem: '<S1>/Center from Right'
    // Product: '<S6>/Divide'
    Curvature_o = rtu_right_curvature / localC->Subtract;

    // Product: '<S6>/Divide1'
    CurvatureDerivative_g = rtu_right_curvature_rate / localC->Product1;

    // Sum: '<S6>/Subtract1' incorporates:
    //   Constant: '<S6>/Half Lane Width Estimate1'

    LateralOffset_b = rtu_right_lateral_offset + 1.8;

    // SignalConversion generated from: '<S6>/Center'
    HeadingAngle_j = rtu_right_relative_yaw_heading;

    // End of Outputs for SubSystem: '<S1>/Center from Right'
  } else {
    // Outputs for Function Call SubSystem: '<S1>/Center from None'
    // SignalConversion generated from: '<S5>/Out1' incorporates:
    //   Delay generated from: '<S1>/Delay'

    Curvature_o = localDW->Delay_1_DSTATE;

    // SignalConversion generated from: '<S5>/Out1' incorporates:
    //   Delay generated from: '<S1>/Delay'

    CurvatureDerivative_g = localDW->Delay_2_DSTATE;

    // SignalConversion generated from: '<S5>/Out1' incorporates:
    //   Delay generated from: '<S1>/Delay'

    HeadingAngle_j = localDW->Delay_3_DSTATE;

    // SignalConversion generated from: '<S5>/Out1' incorporates:
    //   Delay generated from: '<S1>/Delay'

    LateralOffset_b = localDW->Delay_4_DSTATE;

    // End of Outputs for SubSystem: '<S1>/Center from None'
  }

  // End of MATLAB Function: '<S1>/MATLAB Function'

  // UnaryMinus: '<S7>/Unary Minus'
  *rty_LateralDeviation = -Curvature_o;

  // Saturate: '<S1>/Saturation2'
  if (*rty_LateralDeviation > 0.15) {
    *rty_LateralDeviation = 0.15;
  } else {
    if (*rty_LateralDeviation < -0.15) {
      *rty_LateralDeviation = -0.15;
    }
  }

  // End of Saturate: '<S1>/Saturation2'

  // UnaryMinus: '<S7>/Unary Minus1'
  *rty_RelativeYawAngle = -CurvatureDerivative_g;

  // Saturate: '<S1>/Saturation3'
  if (*rty_RelativeYawAngle > 0.06) {
    *rty_CurvatureDerivative = 0.06;
  } else if (*rty_RelativeYawAngle < -0.06) {
    *rty_CurvatureDerivative = -0.06;
  } else {
    *rty_CurvatureDerivative = *rty_RelativeYawAngle;
  }

  // End of Saturate: '<S1>/Saturation3'

  // Product: '<S9>/Product'
  rtb_Product_d = *rty_CurvatureDerivative * rtu_LongitudinalVelocity;

  // Sum: '<S9>/Sum' incorporates:
  //   Gain: '<S9>/Gain'

  *rty_PreviewedCurvature = 0.0 * rtb_Product_d + *rty_LateralDeviation;

  // UnaryMinus: '<S1>/Unary Minus' incorporates:
  //   UnaryMinus: '<S7>/Unary Minus2'

  *rty_RelativeYawAngle = HeadingAngle_j;

  // Saturate: '<S1>/Saturation1'
  if (*rty_RelativeYawAngle > 0.6) {
    *rty_RelativeYawAngle = 0.6;
  } else {
    if (*rty_RelativeYawAngle < -0.6) {
      *rty_RelativeYawAngle = -0.6;
    }
  }

  // End of Saturate: '<S1>/Saturation1'

  // UnaryMinus: '<S1>/Unary Minus1' incorporates:
  //   UnaryMinus: '<S7>/Unary Minus3'

  *rty_LateralDeviation = LateralOffset_b;

  // Saturate: '<S1>/Saturation'
  if (*rty_LateralDeviation > 0.5) {
    *rty_LateralDeviation = 0.5;
  } else {
    if (*rty_LateralDeviation < -0.5) {
      *rty_LateralDeviation = -0.5;
    }
  }

  // End of Saturate: '<S1>/Saturation'

  // Update for Delay generated from: '<S1>/Delay'
  localDW->Delay_4_DSTATE = LateralOffset_b;

  // Update for Delay generated from: '<S1>/Delay'
  localDW->Delay_3_DSTATE = HeadingAngle_j;

  // Update for Delay generated from: '<S1>/Delay'
  localDW->Delay_2_DSTATE = CurvatureDerivative_g;

  // Update for Delay generated from: '<S1>/Delay'
  localDW->Delay_1_DSTATE = Curvature_o;
}

//
// File trailer for generated code.
//
// [EOF]
//
