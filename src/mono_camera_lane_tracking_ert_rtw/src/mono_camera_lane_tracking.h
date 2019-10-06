//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: mono_camera_lane_tracking.h
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
#ifndef RTW_HEADER_mono_camera_lane_tracking_h_
#define RTW_HEADER_mono_camera_lane_tracking_h_
#include <cmath>
#include <cstring>
#include <math.h>
#ifndef mono_camera_lane_tracking_COMMON_INCLUDES_
# define mono_camera_lane_tracking_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                            // mono_camera_lane_tracking_COMMON_INCLUDES_

#include "mono_camera_lane_tracking_types.h"

// Child system includes
#include "EstimateLaneCenter.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_assert.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals and states (default storage) for system '<Root>'
typedef struct {
  DW_EstimateLaneCenter EstimateLaneCenter_a;// '<Root>/Estimate Lane Center'
  real_T LastPcov_PreviousInput[25];   // '<S15>/LastPcov'
  real_T last_x_PreviousInput[5];      // '<S15>/last_x'
  real_T last_mv_DSTATE;               // '<S15>/last_mv'
  void* Assertion_slioAccessor;        // '<S12>/Assertion'
  boolean_T Memory_PreviousInput[4];   // '<S15>/Memory'
} DW;

// Invariant block signals (default storage)
typedef const struct tag_ConstB {
  real_T Am[4];                        // '<S46>/Matrix Concatenate'
  real_T b1;                           // '<S46>/Gain'
  real_T b2;                           // '<S46>/Gain1'
  ConstB_EstimateLaneCenter EstimateLaneCenter_a;// '<Root>/Estimate Lane Center' 
} ConstB;

// Constant parameters (default storage)
typedef struct {
  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<S11>/Reference constant'
  //    '<S13>/U Constant'
  //    '<S13>/Y Constant'
  //    '<S14>/F_zero'
  //    '<S14>/y.wt_zero'
  //    '<S14>/ymax_zero'
  //    '<S14>/ymin_zero'

  real_T pooled10[2];

  // Pooled Parameter (Expression: zeros(NumEgoStates+2*(1+hasLag),1))
  //  Referenced by:
  //    '<S13>/DX Constant'
  //    '<S13>/X Constant'

  real_T pooled11[4];

  // Expression: lastPcov
  //  Referenced by: '<S15>/LastPcov'

  real_T LastPcov_InitialCondition[25];
} ConstP;

// Real-time Model Data Structure
struct tag_RTM {
  const char_T * volatile errorStatus;
};

extern const ConstB rtConstB;          // constant block i/o

// Constant parameters (default storage)
extern const ConstP rtConstP;

// Class declaration for model mono_camera_lane_tracking
class PathFollowingControllerRefMdlModelClass {
  // public data and function members
 public:
  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  PathFollowingControllerRefMdlModelClass();

  // Destructor
  ~PathFollowingControllerRefMdlModelClass();

  // Real-Time Model get method
  RT_MODEL * getRTM();

  // private data and function members
 private:
  // Block signals and states
  DW rtDW;

  // Real-Time Model
  RT_MODEL rtM;

  // private member function(s) for subsystem '<Root>/Estimate Lane Center'
  void EstimateLaneCenter(real_T rtu_left_strength, real_T rtu_right_strength,
    real_T rtu_LongitudinalVelocity, real_T rtu_left_curvature_rate, real_T
    rtu_left_curvature, real_T rtu_left_relative_yaw_heading, real_T
    rtu_left_lateral_offset, real_T rtu_right_curvature_rate, real_T
    rtu_right_curvature, real_T rtu_right_relative_yaw_heading, real_T
    rtu_right_lateral_offset, real_T *rty_CurvatureDerivative, real_T
    *rty_PreviewedCurvature, real_T *rty_LateralDeviation, real_T
    *rty_RelativeYawAngle, const ConstB_EstimateLaneCenter *localC,
    DW_EstimateLaneCenter *localDW);

  // private member function(s) for subsystem '<Root>'
  void mldivide(const real_T A[16], real_T B_0[16]);
  void PadeApproximantOfDegree(const real_T A[16], uint8_T m_2, real_T F[16]);
  void expm(real_T A[16], real_T F[16]);
  void mpc_plantupdate(const real_T a[16], real_T b[8], const real_T c[8],
                       real_T d[4], real_T b_A[25], real_T b_B[30], real_T b_C
                       [10], real_T b_D[12], const real_T b_myindex[2], const
                       real_T b_Uscale[2], const real_T b_Yscale[2], real_T Bu[5],
                       real_T Bv[10], real_T Cm[10], real_T Dv[4], real_T Dvm[4],
                       real_T QQ[25], real_T RR[4], real_T NN[10]);
  real_T mod(real_T x_0);
  void mpc_updateFromNominal(real_T b_Mlim[4], const real_T b_Mrows[4], const
    real_T U0[2], const real_T b_Uscale[2], real_T b_utarget[10], const real_T
    Y0[2], const real_T b_Yscale[2], const real_T old_yoff[2], const real_T
    b_myindex[2], const real_T X0[4], real_T b_xoff[5], const real_T DX0[4],
    real_T Bv[110], real_T *new_mvoff, real_T *new_mdoff, real_T new_yoff[2],
    real_T new_myoff[2]);
  void mpcblock_refmd(const real_T ref[2], real_T md, const real_T b_yoff[2],
                      real_T b_voff, const real_T b_RYscale[2], real_T
                      b_RMDscale, real_T rseq[20], real_T vseq[22], real_T v[2]);
  void eye(real_T b_I[4]);
  void mpc_constraintcoef(const real_T b_A[25], const real_T Bu[55], const
    real_T Bv[110], const real_T b_C[10], const real_T Dv[44], const real_T
    b_Jm[20], real_T b_SuJm[40], real_T b_Sx[100], real_T b_Su1[20], real_T
    b_Hv[440]);
  void kron(const real_T b_A[100], real_T b_B, real_T K[100]);
  void WtMult(real_T W, const real_T M[20], real_T WM[20]);
  void mpc_calculatehessian(const real_T b_Wy[2], real_T b_Wu, real_T b_Wdu,
    const real_T b_SuJm[40], const real_T I2Jm[20], const real_T b_Jm[20], const
    real_T b_I1[10], const real_T b_Su1[20], const real_T b_Sx[100], const
    real_T b_Hv[440], real_T b_ny, real_T b_H[4], real_T b_Ku1[2], real_T b_Kut
    [20], real_T b_Kx[10], real_T b_Kv[44], real_T b_Kr[40]);
  int32_T xpotrf(real_T b_A[9]);
  void mpc_checkhessian(real_T b_H[9], real_T L[9], real_T *BadH);
  void eye_g(real_T b_I[9]);
  void trisolve(const real_T b_A[9], real_T b_B[9]);
  void linsolve(const real_T b_A[9], const real_T b_B[9], real_T b_C[9]);
  void Unconstrained(const real_T b_Hinv[9], const real_T f[3], real_T x_8[3],
                     int16_T n_4);
  real_T norm(const real_T x_3[3]);
  void abs_g(const real_T x_4[3], real_T y_2[3]);
  void abs_gt(const real_T x_5[4], real_T y_3[4]);
  real_T xnrm2(int32_T n_0, const real_T x_2[9], int32_T ix0);
  void xgemv(int32_T m_0, int32_T n_2, const real_T b_A[9], int32_T ia0, const
             real_T x_7[9], int32_T ix0, real_T y_4[3]);
  void xgerc(int32_T m_1, int32_T n_3, real_T alpha1, int32_T ix0, const real_T
             y_5[3], real_T b_A[9], int32_T ia0);
  void qr(const real_T b_A[9], real_T Q[9], real_T R[9]);
  real_T KWIKfactor(const real_T b_Ac[12], const int16_T iC[4], int16_T nA,
                    const real_T b_Linv[9], real_T RLinv[9], real_T b_D[9],
                    real_T b_H[9], int16_T n_1);
  void DropConstraint(int16_T kDrop, int16_T iA[4], int16_T *nA, int16_T iC[4]);
  void qpkwik(const real_T b_Linv[9], const real_T b_Hinv[9], const real_T f[3],
              const real_T b_Ac[12], const real_T b[4], int16_T iA[4], int16_T
              b_maxiter, real_T FeasTol, real_T x_6[3], real_T lambda[4], real_T
              *status);
  void mpc_solveQP(const real_T xQP[5], const real_T b_Kx[10], const real_T
                   b_Kr[40], const real_T rseq[20], const real_T b_Ku1[2],
                   real_T old_u, const real_T b_Kv[44], const real_T vseq[22],
                   const real_T b_Kut[20], const real_T b_utarget[10], const
                   real_T b_Linv[9], const real_T b_Hinv[9], const real_T b_Ac
                   [12], const real_T Bc[4], boolean_T iA[4], real_T zopt[3],
                   real_T f[3], real_T *status);
  void mpcblock_optimizer(const real_T rseq[20], const real_T vseq[22], real_T
    umin, real_T umax, real_T switch_in, const real_T x_1[5], real_T old_u,
    const boolean_T iA[4], const real_T b_Mlim[4], real_T b_Mx[20], real_T
    b_Mu1[4], real_T b_Mv[88], const real_T b_utarget[10], real_T b_uoff, real_T
    b_enable_value, real_T b_H[9], real_T b_Ac[12], const real_T b_Wy[2], const
    real_T b_Jm[20], const real_T b_I1[10], const real_T b_A[25], const real_T
    Bu[55], const real_T Bv[110], const real_T b_C[10], const real_T Dv[44],
    const real_T b_Mrows[4], real_T *u, real_T useq[11], real_T *status,
    boolean_T iAout[4]);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S15>/Data Type Conversion22' : Unused code path elimination
//  Block '<S15>/Data Type Conversion23' : Unused code path elimination
//  Block '<S16>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S17>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S18>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S19>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S20>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S21>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S22>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S23>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S24>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S25>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S26>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S27>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S28>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S29>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S30>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S31>/Matrix Dimension Check' : Unused code path elimination
//  Block '<S32>/Vector Dimension Check' : Unused code path elimination
//  Block '<S33>/Vector Dimension Check' : Unused code path elimination
//  Block '<S34>/Vector Dimension Check' : Unused code path elimination
//  Block '<S35>/Vector Dimension Check' : Unused code path elimination
//  Block '<S36>/Vector Dimension Check' : Unused code path elimination
//  Block '<S37>/Vector Dimension Check' : Unused code path elimination
//  Block '<S38>/Vector Dimension Check' : Unused code path elimination
//  Block '<S39>/Vector Dimension Check' : Unused code path elimination
//  Block '<S40>/Vector Dimension Check' : Unused code path elimination
//  Block '<S41>/Vector Dimension Check' : Unused code path elimination
//  Block '<S42>/Vector Dimension Check' : Unused code path elimination
//  Block '<S15>/u_scale' : Unused code path elimination
//  Block '<S15>/useq_scale' : Unused code path elimination
//  Block '<S15>/useq_scale1' : Unused code path elimination
//  Block '<S15>/ym_zero' : Unused code path elimination
//  Block '<S14>/m_zero' : Unused code path elimination
//  Block '<S14>/p_zero' : Unused code path elimination
//  Block '<S11>/DataTypeConversion_utrack' : Unused code path elimination
//  Block '<S10>/External control signal constant' : Unused code path elimination
//  Block '<S13>/DataTypeConversion_A' : Unused code path elimination
//  Block '<S13>/DataTypeConversion_B' : Unused code path elimination
//  Block '<S13>/DataTypeConversion_C' : Unused code path elimination
//  Block '<S10>/Vehicle dynamics matrix A constant' : Unused code path elimination
//  Block '<S10>/Vehicle dynamics matrix B constant' : Unused code path elimination
//  Block '<S10>/Vehicle dynamics matrix C constant' : Unused code path elimination
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<S15>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion10' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion11' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion12' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion13' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion14' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion15' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion16' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion17' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion18' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion19' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion20' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion21' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion6' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion7' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion8' : Eliminate redundant data type conversion
//  Block '<S15>/Data Type Conversion9' : Eliminate redundant data type conversion
//  Block '<S15>/E Conversion' : Eliminate redundant data type conversion
//  Block '<S15>/F Conversion' : Eliminate redundant data type conversion
//  Block '<S15>/G Conversion' : Eliminate redundant data type conversion
//  Block '<S15>/Reshape' : Reshape block reduction
//  Block '<S15>/Reshape1' : Reshape block reduction
//  Block '<S15>/Reshape2' : Reshape block reduction
//  Block '<S15>/Reshape3' : Reshape block reduction
//  Block '<S15>/Reshape4' : Reshape block reduction
//  Block '<S15>/Reshape5' : Reshape block reduction
//  Block '<S15>/S Conversion' : Eliminate redundant data type conversion
//  Block '<S15>/mo or x Conversion' : Eliminate redundant data type conversion
//  Block '<S11>/DataTypeConversion_optsgn' : Eliminate redundant data type conversion
//  Block '<S11>/DataTypeConversion_umax' : Eliminate redundant data type conversion
//  Block '<S11>/DataTypeConversion_umin' : Eliminate redundant data type conversion
//  Block '<S13>/DataTypeConversion_Vx' : Eliminate redundant data type conversion
//  Block '<S13>/DataTypeConversion_curvature' : Eliminate redundant data type conversion
//  Block '<S13>/DataTypeConversion_e1' : Eliminate redundant data type conversion
//  Block '<S13>/DataTypeConversion_e2' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'mono_camera_lane_tracking'
//  '<S1>'   : 'mono_camera_lane_tracking/Estimate Lane Center'
//  '<S2>'   : 'mono_camera_lane_tracking/MPC Controller '
//  '<S3>'   : 'mono_camera_lane_tracking/Estimate Lane Center/Center from Left'
//  '<S4>'   : 'mono_camera_lane_tracking/Estimate Lane Center/Center from Left and Right'
//  '<S5>'   : 'mono_camera_lane_tracking/Estimate Lane Center/Center from None'
//  '<S6>'   : 'mono_camera_lane_tracking/Estimate Lane Center/Center from Right'
//  '<S7>'   : 'mono_camera_lane_tracking/Estimate Lane Center/ISO 8855 to SAE J670E'
//  '<S8>'   : 'mono_camera_lane_tracking/Estimate Lane Center/MATLAB Function'
//  '<S9>'   : 'mono_camera_lane_tracking/Estimate Lane Center/Preview curvature'
//  '<S10>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System'
//  '<S11>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA'
//  '<S12>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Longitudinal velocity must be positive'
//  '<S13>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Model for Adaptive MPC'
//  '<S14>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller'
//  '<S15>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC'
//  '<S16>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Matrix Signal Check'
//  '<S17>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Matrix Signal Check A'
//  '<S18>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Matrix Signal Check B'
//  '<S19>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Matrix Signal Check C'
//  '<S20>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Matrix Signal Check D'
//  '<S21>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Matrix Signal Check DX'
//  '<S22>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Matrix Signal Check U'
//  '<S23>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Matrix Signal Check X'
//  '<S24>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Matrix Signal Check Y'
//  '<S25>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Matrix Signal Check1'
//  '<S26>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Matrix Signal Check2'
//  '<S27>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Preview Signal Check'
//  '<S28>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Preview Signal Check1'
//  '<S29>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Preview Signal Check2'
//  '<S30>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Preview Signal Check3'
//  '<S31>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Preview Signal Check4'
//  '<S32>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Scalar Signal Check'
//  '<S33>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Scalar Signal Check1'
//  '<S34>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Scalar Signal Check2'
//  '<S35>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Vector Signal Check'
//  '<S36>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Vector Signal Check1'
//  '<S37>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Vector Signal Check11'
//  '<S38>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Vector Signal Check2'
//  '<S39>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Vector Signal Check3'
//  '<S40>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Vector Signal Check4'
//  '<S41>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Vector Signal Check5'
//  '<S42>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/MPC Vector Signal Check6'
//  '<S43>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/optimizer'
//  '<S44>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Adaptive MPC for LKA/Adaptive MPC Controller/MPC/optimizer/FixedHorizonOptimizer'
//  '<S45>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Model for Adaptive MPC/Adaptive Model'
//  '<S46>'  : 'mono_camera_lane_tracking/MPC Controller /Lane Keeping Assist System/Model for Adaptive MPC/Vehicle Dynamics from Parameters'

#endif                               // RTW_HEADER_mono_camera_lane_tracking_h_

//
// File trailer for generated code.
//
// [EOF]
//
