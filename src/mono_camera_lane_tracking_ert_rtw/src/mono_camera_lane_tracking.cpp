//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: mono_camera_lane_tracking.cpp
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

// Named constants for MATLAB Function: '<S43>/FixedHorizonOptimizer'
const real_T RMDscale = 100.0;
const real_T Wdu = 0.010000000000000002;
const real_T Wu = 0.0;
const real_T enable_value = 0.0;
const real_T nu = 1.0;
const real_T nv = 2.0;
const real_T ny = 2.0;
const real_T uoff = 0.0;
real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y_7;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y_7 = (rtNaN);
  } else {
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y_7 = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y_7 = (rtInf);
        } else {
          y_7 = 0.0;
        }
      } else if (u1 > 0.0) {
        y_7 = 0.0;
      } else {
        y_7 = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y_7 = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y_7 = u0;
      } else {
        y_7 = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y_7 = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y_7 = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y_7 = (rtNaN);
    } else {
      y_7 = pow(u0, u1);
    }
  }

  return y_7;
}

// Function for MATLAB Function: '<S13>/Adaptive Model'
void PathFollowingControllerRefMdlModelClass::mldivide(const real_T A[16],
  real_T B_0[16])
{
  int32_T ip;
  real_T b_A[16];
  int8_T ipiv[4];
  int32_T j_4;
  int32_T ix;
  real_T smax;
  int32_T c_k;
  int32_T iy;
  real_T y_6;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  std::memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  for (j_4 = 0; j_4 < 3; j_4++) {
    ip = j_4 * 5;
    iy = 0;
    ix = ip;
    smax = std::abs(b_A[ip]);
    for (c_k = 2; c_k <= 4 - j_4; c_k++) {
      ix++;
      y_6 = std::abs(b_A[ix]);
      if (y_6 > smax) {
        iy = c_k - 1;
        smax = y_6;
      }
    }

    if (b_A[ip + iy] != 0.0) {
      if (iy != 0) {
        c_k = j_4 + iy;
        ipiv[j_4] = static_cast<int8_T>((c_k + 1));
        smax = b_A[j_4];
        b_A[j_4] = b_A[c_k];
        b_A[c_k] = smax;
        ix = j_4 + 4;
        iy = c_k + 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
      }

      iy = (ip - j_4) + 4;
      for (ix = ip + 1; ix < iy; ix++) {
        b_A[ix] /= b_A[ip];
      }
    }

    iy = ip;
    ix = ip + 4;
    for (c_k = 0; c_k <= 2 - j_4; c_k++) {
      if (b_A[ix] != 0.0) {
        smax = -b_A[ix];
        c_ix = ip + 1;
        d = (iy - j_4) + 8;
        for (ijA = iy + 5; ijA < d; ijA++) {
          b_A[ijA] += b_A[c_ix] * smax;
          c_ix++;
        }
      }

      ix += 4;
      iy += 4;
    }
  }

  for (j_4 = 0; j_4 < 3; j_4++) {
    if (j_4 + 1 != ipiv[j_4]) {
      ip = ipiv[j_4] - 1;
      smax = B_0[j_4];
      B_0[j_4] = B_0[ip];
      B_0[ip] = smax;
      smax = B_0[j_4 + 4];
      B_0[j_4 + 4] = B_0[ip + 4];
      B_0[ip + 4] = smax;
      smax = B_0[j_4 + 8];
      B_0[j_4 + 8] = B_0[ip + 8];
      B_0[ip + 8] = smax;
      smax = B_0[j_4 + 12];
      B_0[j_4 + 12] = B_0[ip + 12];
      B_0[ip + 12] = smax;
    }
  }

  for (j_4 = 0; j_4 < 4; j_4++) {
    ip = j_4 << 2;
    if (B_0[ip] != 0.0) {
      for (c_k = 2; c_k < 5; c_k++) {
        ix = (c_k + ip) - 1;
        B_0[ix] -= b_A[c_k - 1] * B_0[ip];
      }
    }

    if (B_0[ip + 1] != 0.0) {
      for (c_k = 3; c_k < 5; c_k++) {
        ix = (c_k + ip) - 1;
        B_0[ix] -= B_0[ip + 1] * b_A[c_k + 3];
      }
    }

    if (B_0[ip + 2] != 0.0) {
      B_0[ip + 3] -= B_0[ip + 2] * b_A[11];
    }
  }

  for (j_4 = 0; j_4 < 4; j_4++) {
    ip = j_4 << 2;
    if (B_0[ip + 3] != 0.0) {
      B_0[ip + 3] /= b_A[15];
      for (c_k = 0; c_k < 3; c_k++) {
        ix = c_k + ip;
        B_0[ix] -= B_0[ip + 3] * b_A[c_k + 12];
      }
    }

    if (B_0[ip + 2] != 0.0) {
      B_0[ip + 2] /= b_A[10];
      for (c_k = 0; c_k < 2; c_k++) {
        ix = c_k + ip;
        B_0[ix] -= B_0[ip + 2] * b_A[c_k + 8];
      }
    }

    if (B_0[ip + 1] != 0.0) {
      B_0[ip + 1] /= b_A[5];
      B_0[ip] -= B_0[ip + 1] * b_A[4];
    }

    if (B_0[ip] != 0.0) {
      B_0[ip] /= b_A[0];
    }
  }
}

// Function for MATLAB Function: '<S13>/Adaptive Model'
void PathFollowingControllerRefMdlModelClass::PadeApproximantOfDegree(const
  real_T A[16], uint8_T m_2, real_T F[16])
{
  real_T A2[16];
  real_T V[16];
  real_T d;
  real_T A3[16];
  real_T A4[16];
  int32_T e_k;
  real_T A4_0[16];
  int32_T i_n;
  int32_T A2_tmp;
  int32_T A2_tmp_tmp;
  for (e_k = 0; e_k < 4; e_k++) {
    for (i_n = 0; i_n < 4; i_n++) {
      A2_tmp_tmp = e_k << 2;
      A2_tmp = i_n + A2_tmp_tmp;
      A2[A2_tmp] = 0.0;
      A2[A2_tmp] += A[A2_tmp_tmp] * A[i_n];
      A2[A2_tmp] += A[A2_tmp_tmp + 1] * A[i_n + 4];
      A2[A2_tmp] += A[A2_tmp_tmp + 2] * A[i_n + 8];
      A2[A2_tmp] += A[A2_tmp_tmp + 3] * A[i_n + 12];
    }
  }

  if (m_2 == 3) {
    std::memcpy(&F[0], &A2[0], sizeof(real_T) << 4U);
    F[0] += 60.0;
    F[5] += 60.0;
    F[10] += 60.0;
    F[15] += 60.0;
    for (e_k = 0; e_k < 4; e_k++) {
      for (i_n = 0; i_n < 4; i_n++) {
        A2_tmp_tmp = e_k << 2;
        A2_tmp = i_n + A2_tmp_tmp;
        A4_0[A2_tmp] = 0.0;
        A4_0[A2_tmp] += F[A2_tmp_tmp] * A[i_n];
        A4_0[A2_tmp] += F[A2_tmp_tmp + 1] * A[i_n + 4];
        A4_0[A2_tmp] += F[A2_tmp_tmp + 2] * A[i_n + 8];
        A4_0[A2_tmp] += F[A2_tmp_tmp + 3] * A[i_n + 12];
      }
    }

    for (e_k = 0; e_k < 16; e_k++) {
      F[e_k] = A4_0[e_k];
      V[e_k] = 12.0 * A2[e_k];
    }

    d = 120.0;
  } else {
    for (e_k = 0; e_k < 4; e_k++) {
      for (i_n = 0; i_n < 4; i_n++) {
        A2_tmp_tmp = e_k << 2;
        A2_tmp = i_n + A2_tmp_tmp;
        A3[A2_tmp] = 0.0;
        A3[A2_tmp] += A2[A2_tmp_tmp] * A2[i_n];
        A3[A2_tmp] += A2[A2_tmp_tmp + 1] * A2[i_n + 4];
        A3[A2_tmp] += A2[A2_tmp_tmp + 2] * A2[i_n + 8];
        A3[A2_tmp] += A2[A2_tmp_tmp + 3] * A2[i_n + 12];
      }
    }

    if (m_2 == 5) {
      for (e_k = 0; e_k < 16; e_k++) {
        F[e_k] = 420.0 * A2[e_k] + A3[e_k];
      }

      F[0] += 15120.0;
      F[5] += 15120.0;
      F[10] += 15120.0;
      F[15] += 15120.0;
      for (e_k = 0; e_k < 4; e_k++) {
        for (i_n = 0; i_n < 4; i_n++) {
          A2_tmp_tmp = e_k << 2;
          A2_tmp = i_n + A2_tmp_tmp;
          A4_0[A2_tmp] = 0.0;
          A4_0[A2_tmp] += F[A2_tmp_tmp] * A[i_n];
          A4_0[A2_tmp] += F[A2_tmp_tmp + 1] * A[i_n + 4];
          A4_0[A2_tmp] += F[A2_tmp_tmp + 2] * A[i_n + 8];
          A4_0[A2_tmp] += F[A2_tmp_tmp + 3] * A[i_n + 12];
        }
      }

      for (e_k = 0; e_k < 16; e_k++) {
        F[e_k] = A4_0[e_k];
        V[e_k] = 30.0 * A3[e_k] + 3360.0 * A2[e_k];
      }

      d = 30240.0;
    } else {
      for (e_k = 0; e_k < 4; e_k++) {
        for (i_n = 0; i_n < 4; i_n++) {
          A2_tmp = e_k << 2;
          A2_tmp_tmp = i_n + A2_tmp;
          A4[A2_tmp_tmp] = 0.0;
          A4[A2_tmp_tmp] += A2[A2_tmp] * A3[i_n];
          A4[A2_tmp_tmp] += A2[A2_tmp + 1] * A3[i_n + 4];
          A4[A2_tmp_tmp] += A2[A2_tmp + 2] * A3[i_n + 8];
          A4[A2_tmp_tmp] += A2[A2_tmp + 3] * A3[i_n + 12];
        }
      }

      switch (m_2) {
       case 7:
        for (e_k = 0; e_k < 16; e_k++) {
          F[e_k] = (1512.0 * A3[e_k] + A4[e_k]) + 277200.0 * A2[e_k];
        }

        F[0] += 8.64864E+6;
        F[5] += 8.64864E+6;
        F[10] += 8.64864E+6;
        F[15] += 8.64864E+6;
        for (e_k = 0; e_k < 4; e_k++) {
          for (i_n = 0; i_n < 4; i_n++) {
            A2_tmp_tmp = e_k << 2;
            A2_tmp = i_n + A2_tmp_tmp;
            A4_0[A2_tmp] = 0.0;
            A4_0[A2_tmp] += F[A2_tmp_tmp] * A[i_n];
            A4_0[A2_tmp] += F[A2_tmp_tmp + 1] * A[i_n + 4];
            A4_0[A2_tmp] += F[A2_tmp_tmp + 2] * A[i_n + 8];
            A4_0[A2_tmp] += F[A2_tmp_tmp + 3] * A[i_n + 12];
          }
        }

        for (e_k = 0; e_k < 16; e_k++) {
          F[e_k] = A4_0[e_k];
          V[e_k] = (56.0 * A4[e_k] + 25200.0 * A3[e_k]) + 1.99584E+6 * A2[e_k];
        }

        d = 1.729728E+7;
        break;

       case 9:
        for (e_k = 0; e_k < 4; e_k++) {
          for (i_n = 0; i_n < 4; i_n++) {
            A2_tmp = e_k << 2;
            A2_tmp_tmp = i_n + A2_tmp;
            V[A2_tmp_tmp] = 0.0;
            V[A2_tmp_tmp] += A2[A2_tmp] * A4[i_n];
            V[A2_tmp_tmp] += A2[A2_tmp + 1] * A4[i_n + 4];
            V[A2_tmp_tmp] += A2[A2_tmp + 2] * A4[i_n + 8];
            V[A2_tmp_tmp] += A2[A2_tmp + 3] * A4[i_n + 12];
          }
        }

        for (e_k = 0; e_k < 16; e_k++) {
          F[e_k] = ((3960.0 * A4[e_k] + V[e_k]) + 2.16216E+6 * A3[e_k]) +
            3.027024E+8 * A2[e_k];
        }

        F[0] += 8.8216128E+9;
        F[5] += 8.8216128E+9;
        F[10] += 8.8216128E+9;
        F[15] += 8.8216128E+9;
        for (e_k = 0; e_k < 4; e_k++) {
          for (i_n = 0; i_n < 4; i_n++) {
            A2_tmp_tmp = e_k << 2;
            A2_tmp = i_n + A2_tmp_tmp;
            A4_0[A2_tmp] = 0.0;
            A4_0[A2_tmp] += F[A2_tmp_tmp] * A[i_n];
            A4_0[A2_tmp] += F[A2_tmp_tmp + 1] * A[i_n + 4];
            A4_0[A2_tmp] += F[A2_tmp_tmp + 2] * A[i_n + 8];
            A4_0[A2_tmp] += F[A2_tmp_tmp + 3] * A[i_n + 12];
          }
        }

        for (e_k = 0; e_k < 16; e_k++) {
          F[e_k] = A4_0[e_k];
          V[e_k] = ((90.0 * V[e_k] + 110880.0 * A4[e_k]) + 3.027024E+7 * A3[e_k])
            + 2.0756736E+9 * A2[e_k];
        }

        d = 1.76432256E+10;
        break;

       default:
        for (e_k = 0; e_k < 16; e_k++) {
          F[e_k] = (3.352212864E+10 * A4[e_k] + 1.05594705216E+13 * A3[e_k]) +
            1.1873537964288E+15 * A2[e_k];
          V[e_k] = (16380.0 * A3[e_k] + A4[e_k]) + 4.08408E+7 * A2[e_k];
        }

        F[0] += 3.238237626624E+16;
        F[5] += 3.238237626624E+16;
        F[10] += 3.238237626624E+16;
        F[15] += 3.238237626624E+16;
        for (e_k = 0; e_k < 4; e_k++) {
          for (i_n = 0; i_n < 4; i_n++) {
            A2_tmp_tmp = e_k << 2;
            A2_tmp = A2_tmp_tmp + i_n;
            A4_0[A2_tmp] = (((V[A2_tmp_tmp + 1] * A4[i_n + 4] + V[A2_tmp_tmp] *
                              A4[i_n]) + V[A2_tmp_tmp + 2] * A4[i_n + 8]) +
                            V[A2_tmp_tmp + 3] * A4[i_n + 12]) + F[A2_tmp];
          }
        }

        for (e_k = 0; e_k < 4; e_k++) {
          for (i_n = 0; i_n < 4; i_n++) {
            A2_tmp_tmp = e_k << 2;
            A2_tmp = i_n + A2_tmp_tmp;
            F[A2_tmp] = 0.0;
            F[A2_tmp] += A4_0[A2_tmp_tmp] * A[i_n];
            F[A2_tmp] += A4_0[A2_tmp_tmp + 1] * A[i_n + 4];
            F[A2_tmp] += A4_0[A2_tmp_tmp + 2] * A[i_n + 8];
            F[A2_tmp] += A4_0[A2_tmp_tmp + 3] * A[i_n + 12];
          }
        }

        for (e_k = 0; e_k < 16; e_k++) {
          A4_0[e_k] = (182.0 * A4[e_k] + 960960.0 * A3[e_k]) + 1.32324192E+9 *
            A2[e_k];
        }

        for (e_k = 0; e_k < 4; e_k++) {
          for (i_n = 0; i_n < 4; i_n++) {
            A2_tmp_tmp = e_k << 2;
            A2_tmp = A2_tmp_tmp + i_n;
            V[A2_tmp] = (((((A4_0[A2_tmp_tmp + 1] * A4[i_n + 4] +
                             A4_0[A2_tmp_tmp] * A4[i_n]) + A4_0[A2_tmp_tmp + 2] *
                            A4[i_n + 8]) + A4_0[A2_tmp_tmp + 3] * A4[i_n + 12])
                          + A4[A2_tmp] * 6.704425728E+11) + A3[A2_tmp] *
                         1.29060195264E+14) + A2[A2_tmp] * 7.7717703038976E+15;
          }
        }

        d = 6.476475253248E+16;
        break;
      }
    }
  }

  V[0] += d;
  V[5] += d;
  V[10] += d;
  V[15] += d;
  for (e_k = 0; e_k < 16; e_k++) {
    V[e_k] -= F[e_k];
    F[e_k] *= 2.0;
  }

  mldivide(V, F);
  F[0]++;
  F[5]++;
  F[10]++;
  F[15]++;
}

// Function for MATLAB Function: '<S13>/Adaptive Model'
void PathFollowingControllerRefMdlModelClass::expm(real_T A[16], real_T F[16])
{
  real_T normA;
  real_T b_s;
  int32_T b_j;
  int32_T e;
  real_T F_0[16];
  int32_T b_s_tmp;
  int32_T F_tmp;
  int32_T F_tmp_tmp;
  static const real_T theta[5] = { 0.01495585217958292, 0.253939833006323,
    0.95041789961629319, 2.097847961257068, 5.3719203511481517 };

  static const uint8_T b[5] = { 3U, 5U, 7U, 9U, 13U };

  boolean_T exitg1;
  normA = 0.0;
  b_j = 0;
  exitg1 = false;
  while ((!exitg1) && (b_j < 4)) {
    b_s_tmp = b_j << 2;
    b_s = ((std::abs(A[b_s_tmp + 1]) + std::abs(A[b_s_tmp])) + std::abs
           (A[b_s_tmp + 2])) + std::abs(A[b_s_tmp + 3]);
    if (rtIsNaN(b_s)) {
      normA = (rtNaN);
      exitg1 = true;
    } else {
      if (b_s > normA) {
        normA = b_s;
      }

      b_j++;
    }
  }

  if (normA <= 5.3719203511481517) {
    b_j = 0;
    exitg1 = false;
    while ((!exitg1) && (b_j < 5)) {
      if (normA <= theta[b_j]) {
        PadeApproximantOfDegree(A, b[b_j], F);
        exitg1 = true;
      } else {
        b_j++;
      }
    }
  } else {
    b_s = normA / 5.3719203511481517;
    if ((!rtIsInf(b_s)) && (!rtIsNaN(b_s))) {
      b_s = frexp(b_s, &e);
    } else {
      e = 0;
    }

    normA = e;
    if (b_s == 0.5) {
      normA = static_cast<real_T>(e) - 1.0;
    }

    b_s = rt_powd_snf(2.0, normA);
    for (b_s_tmp = 0; b_s_tmp < 16; b_s_tmp++) {
      A[b_s_tmp] /= b_s;
    }

    PadeApproximantOfDegree(A, 13, F);
    for (b_j = 0; b_j < static_cast<int32_T>(normA); b_j++) {
      for (b_s_tmp = 0; b_s_tmp < 4; b_s_tmp++) {
        for (e = 0; e < 4; e++) {
          F_tmp_tmp = e << 2;
          F_tmp = b_s_tmp + F_tmp_tmp;
          F_0[F_tmp] = 0.0;
          F_0[F_tmp] += F[F_tmp_tmp] * F[b_s_tmp];
          F_0[F_tmp] += F[F_tmp_tmp + 1] * F[b_s_tmp + 4];
          F_0[F_tmp] += F[F_tmp_tmp + 2] * F[b_s_tmp + 8];
          F_0[F_tmp] += F[F_tmp_tmp + 3] * F[b_s_tmp + 12];
        }
      }

      std::memcpy(&F[0], &F_0[0], sizeof(real_T) << 4U);
    }
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::mpc_plantupdate(const real_T a[16],
  real_T b[8], const real_T c[8], real_T d[4], real_T b_A[25], real_T b_B[30],
  real_T b_C[10], real_T b_D[12], const real_T b_myindex[2], const real_T
  b_Uscale[2], const real_T b_Yscale[2], real_T Bu[5], real_T Bv[10], real_T Cm
  [10], real_T Dv[4], real_T Dvm[4], real_T QQ[25], real_T RR[4], real_T NN[10])
{
  int8_T UnknownIn[5];
  real_T CovMat[49];
  real_T b_B_0[35];
  real_T b_B_1[35];
  int32_T i_c;
  real_T d_0;
  int32_T b_tmp;
  int32_T b_tmp_0;
  int32_T Dvm_tmp;
  for (i_c = 0; i_c < 2; i_c++) {
    b_tmp = i_c << 2;
    b[b_tmp] *= b_Uscale[i_c];
    b_tmp_0 = b_tmp + 1;
    b[b_tmp_0] *= b_Uscale[i_c];
    b_tmp_0 = b_tmp + 2;
    b[b_tmp_0] *= b_Uscale[i_c];
    b_tmp += 3;
    b[b_tmp] *= b_Uscale[i_c];
  }

  d[2] = d[2] / b_Yscale[0] * b_Uscale[1];
  d_0 = d[3] / b_Yscale[1] * b_Uscale[1];
  for (i_c = 0; i_c < 4; i_c++) {
    b_tmp = i_c << 1;
    b_C[b_tmp] = c[b_tmp] / b_Yscale[0];
    b_tmp++;
    b_C[b_tmp] = c[b_tmp] / b_Yscale[1];
    b_tmp = i_c << 2;
    b_A[5 * i_c] = a[b_tmp];
    b_A[5 * i_c + 1] = a[b_tmp + 1];
    b_A[5 * i_c + 2] = a[b_tmp + 2];
    b_A[5 * i_c + 3] = a[b_tmp + 3];
    b_B[i_c] = b[i_c];
    b_B[i_c + 5] = b[i_c + 4];
  }

  b_D[2] = d[2];
  b_D[3] = d_0;
  for (i_c = 0; i_c < 5; i_c++) {
    Bu[i_c] = b_B[i_c];
  }

  for (i_c = 0; i_c < 2; i_c++) {
    for (b_tmp = 0; b_tmp < 5; b_tmp++) {
      Bv[b_tmp + 5 * i_c] = b_B[(i_c + 1) * 5 + b_tmp];
    }
  }

  Dv[0] = d[2];
  b_tmp_0 = static_cast<int32_T>(b_myindex[0]);
  Dvm[0] = b_D[b_tmp_0 + 1];
  Dv[1] = d_0;
  Dvm_tmp = static_cast<int32_T>(b_myindex[1]);
  Dvm[1] = b_D[Dvm_tmp + 1];
  Dv[2] = b_D[4];
  Dvm[2] = b_D[b_tmp_0 + 3];
  Dv[3] = b_D[5];
  Dvm[3] = b_D[Dvm_tmp + 3];
  UnknownIn[0] = 1;
  UnknownIn[1] = 2;
  UnknownIn[2] = 4;
  UnknownIn[3] = 5;
  UnknownIn[4] = 6;
  for (i_c = 0; i_c < 5; i_c++) {
    b_tmp = i_c << 1;
    Cm[b_tmp] = b_C[(b_tmp + b_tmp_0) - 1];
    Cm[b_tmp + 1] = b_C[(b_tmp + Dvm_tmp) - 1];
    for (b_tmp = 0; b_tmp < 5; b_tmp++) {
      b_B_0[b_tmp + 7 * i_c] = b_B[(UnknownIn[i_c] - 1) * 5 + b_tmp];
      b_B_1[b_tmp + 5 * i_c] = b_B[(UnknownIn[b_tmp] - 1) * 5 + i_c];
    }

    b_tmp = (UnknownIn[i_c] - 1) << 1;
    b_B_0[7 * i_c + 5] = b_D[(b_tmp + b_tmp_0) - 1];
    b_B_0[7 * i_c + 6] = b_D[(b_tmp + Dvm_tmp) - 1];
  }

  for (i_c = 0; i_c < 2; i_c++) {
    for (b_tmp = 0; b_tmp < 5; b_tmp++) {
      b_B_1[b_tmp + 5 * (i_c + 5)] = b_D[(((UnknownIn[b_tmp] - 1) << 1) +
        static_cast<int32_T>(b_myindex[i_c])) - 1];
    }
  }

  for (i_c = 0; i_c < 7; i_c++) {
    for (b_tmp = 0; b_tmp < 7; b_tmp++) {
      b_tmp_0 = b_tmp + 7 * i_c;
      CovMat[b_tmp_0] = 0.0;
      for (Dvm_tmp = 0; Dvm_tmp < 5; Dvm_tmp++) {
        CovMat[b_tmp_0] += b_B_0[7 * Dvm_tmp + b_tmp] * b_B_1[5 * i_c + Dvm_tmp];
      }
    }
  }

  for (i_c = 0; i_c < 5; i_c++) {
    for (b_tmp = 0; b_tmp < 5; b_tmp++) {
      QQ[b_tmp + 5 * i_c] = CovMat[7 * i_c + b_tmp];
    }
  }

  for (i_c = 0; i_c < 2; i_c++) {
    b_tmp_0 = (i_c + 5) * 7;
    b_tmp = i_c << 1;
    RR[b_tmp] = CovMat[b_tmp_0 + 5];
    RR[b_tmp + 1] = CovMat[b_tmp_0 + 6];
    for (b_tmp = 0; b_tmp < 5; b_tmp++) {
      NN[b_tmp + 5 * i_c] = CovMat[b_tmp_0 + b_tmp];
    }
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
real_T PathFollowingControllerRefMdlModelClass::mod(real_T x_0)
{
  real_T r_0;
  if (rtIsNaN(x_0)) {
    r_0 = (rtNaN);
  } else if (rtIsInf(x_0)) {
    r_0 = (rtNaN);
  } else if (x_0 == 0.0) {
    r_0 = 0.0;
  } else {
    r_0 = std::fmod(x_0, ny);
    if (r_0 == 0.0) {
      r_0 = 0.0;
    } else {
      if (x_0 < 0.0) {
        r_0 += ny;
      }
    }
  }

  return r_0;
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::mpc_updateFromNominal(real_T
  b_Mlim[4], const real_T b_Mrows[4], const real_T U0[2], const real_T b_Uscale
  [2], real_T b_utarget[10], const real_T Y0[2], const real_T b_Yscale[2], const
  real_T old_yoff[2], const real_T b_myindex[2], const real_T X0[4], real_T
  b_xoff[5], const real_T DX0[4], real_T Bv[110], real_T *new_mvoff, real_T
  *new_mdoff, real_T new_yoff[2], real_T new_myoff[2])
{
  int32_T i_d;
  *new_mvoff = U0[0] / b_Uscale[0];
  new_yoff[0] = Y0[0] / b_Yscale[0];
  new_yoff[1] = Y0[1] / b_Yscale[1];
  *new_mdoff = U0[1] / b_Uscale[1];
  new_myoff[0] = new_yoff[static_cast<int32_T>(b_myindex[0]) - 1];
  new_myoff[1] = new_yoff[static_cast<int32_T>(b_myindex[1]) - 1];
  if (b_Mrows[0] <= 20.0) {
    i_d = static_cast<int32_T>((mod(b_Mrows[0] - 1.0) + 1.0)) - 1;
    b_Mlim[0] += old_yoff[i_d] - new_yoff[i_d];
  } else if (b_Mrows[0] <= 40.0) {
    i_d = static_cast<int32_T>((mod((b_Mrows[0] - 20.0) - 1.0) + 1.0)) - 1;
    b_Mlim[0] -= old_yoff[i_d] - new_yoff[i_d];
  } else if (b_Mrows[0] <= 50.0) {
    b_Mlim[0] += uoff - *new_mvoff;
  } else {
    if (b_Mrows[0] <= 60.0) {
      b_Mlim[0] -= uoff - *new_mvoff;
    }
  }

  if (b_Mrows[1] <= 20.0) {
    i_d = static_cast<int32_T>((mod(b_Mrows[1] - 1.0) + 1.0)) - 1;
    b_Mlim[1] += old_yoff[i_d] - new_yoff[i_d];
  } else if (b_Mrows[1] <= 40.0) {
    i_d = static_cast<int32_T>((mod((b_Mrows[1] - 20.0) - 1.0) + 1.0)) - 1;
    b_Mlim[1] -= old_yoff[i_d] - new_yoff[i_d];
  } else if (b_Mrows[1] <= 50.0) {
    b_Mlim[1] += uoff - *new_mvoff;
  } else {
    if (b_Mrows[1] <= 60.0) {
      b_Mlim[1] -= uoff - *new_mvoff;
    }
  }

  if (b_Mrows[2] <= 20.0) {
    i_d = static_cast<int32_T>((mod(b_Mrows[2] - 1.0) + 1.0)) - 1;
    b_Mlim[2] += old_yoff[i_d] - new_yoff[i_d];
  } else if (b_Mrows[2] <= 40.0) {
    i_d = static_cast<int32_T>((mod((b_Mrows[2] - 20.0) - 1.0) + 1.0)) - 1;
    b_Mlim[2] -= old_yoff[i_d] - new_yoff[i_d];
  } else if (b_Mrows[2] <= 50.0) {
    b_Mlim[2] += uoff - *new_mvoff;
  } else {
    if (b_Mrows[2] <= 60.0) {
      b_Mlim[2] -= uoff - *new_mvoff;
    }
  }

  if (b_Mrows[3] <= 20.0) {
    i_d = static_cast<int32_T>((mod(b_Mrows[3] - 1.0) + 1.0)) - 1;
    b_Mlim[3] += old_yoff[i_d] - new_yoff[i_d];
  } else if (b_Mrows[3] <= 40.0) {
    i_d = static_cast<int32_T>((mod((b_Mrows[3] - 20.0) - 1.0) + 1.0)) - 1;
    b_Mlim[3] -= old_yoff[i_d] - new_yoff[i_d];
  } else if (b_Mrows[3] <= 50.0) {
    b_Mlim[3] += uoff - *new_mvoff;
  } else {
    if (b_Mrows[3] <= 60.0) {
      b_Mlim[3] -= uoff - *new_mvoff;
    }
  }

  for (i_d = 0; i_d < 10; i_d++) {
    b_utarget[i_d] -= *new_mvoff;
  }

  b_xoff[0] = X0[0];
  Bv[5] = DX0[0];
  b_xoff[1] = X0[1];
  Bv[6] = DX0[1];
  b_xoff[2] = X0[2];
  Bv[7] = DX0[2];
  b_xoff[3] = X0[3];
  Bv[8] = DX0[3];
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::mpcblock_refmd(const real_T ref[2],
  real_T md, const real_T b_yoff[2], real_T b_voff, const real_T b_RYscale[2],
  real_T b_RMDscale, real_T rseq[20], real_T vseq[22], real_T v[2])
{
  int32_T i_0;
  int32_T vseq_tmp;
  std::memset(&vseq[0], 0, 22U * sizeof(real_T));
  for (i_0 = 0; i_0 < 11; i_0++) {
    vseq_tmp = static_cast<int32_T>(nv);
    vseq[(i_0 * vseq_tmp + vseq_tmp) - 1] = 1.0;
  }

  std::memset(&rseq[0], 0, 20U * sizeof(real_T));
  for (i_0 = 0; i_0 < 10; i_0++) {
    vseq_tmp = i_0 * static_cast<int32_T>(ny);
    rseq[vseq_tmp] = ref[0] * b_RYscale[0] - b_yoff[0];
    rseq[vseq_tmp + 1] = ref[1] * b_RYscale[1] - b_yoff[1];
  }

  for (i_0 = 0; i_0 < 11; i_0++) {
    vseq[i_0 * static_cast<int32_T>(nv)] = b_RMDscale * md - b_voff;
  }

  v[0] = vseq[0];
  v[1] = vseq[1];
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::eye(real_T b_I[4])
{
  b_I[1] = 0.0;
  b_I[2] = 0.0;
  b_I[0] = 1.0;
  b_I[3] = 1.0;
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::mpc_constraintcoef(const real_T
  b_A[25], const real_T Bu[55], const real_T Bv[110], const real_T b_C[10],
  const real_T Dv[44], const real_T b_Jm[20], real_T b_SuJm[40], real_T b_Sx[100],
  real_T b_Su1[20], real_T b_Hv[440])
{
  real_T CA[10];
  real_T Sum[2];
  real_T Su[200];
  int8_T rows[2];
  real_T b_C_0[4];
  int8_T i_4;
  real_T Sum_0[20];
  real_T CA_0[44];
  real_T CA_1[10];
  int32_T i_5;
  int32_T i_6;
  real_T tmp;
  int32_T CA_tmp;
  int32_T b_C_tmp;
  int32_T b_Hv_tmp;
  for (i_5 = 0; i_5 < 2; i_5++) {
    Sum[i_5] = 0.0;
    for (b_Hv_tmp = 0; b_Hv_tmp < 5; b_Hv_tmp++) {
      CA_tmp = i_5 + (b_Hv_tmp << 1);
      CA[CA_tmp] = 0.0;
      for (i_6 = 0; i_6 < 5; i_6++) {
        CA[CA_tmp] += b_C[(i_6 << 1) + i_5] * b_A[5 * b_Hv_tmp + i_6];
      }

      Sum[i_5] += b_C[CA_tmp] * Bu[b_Hv_tmp];
    }

    for (b_Hv_tmp = 0; b_Hv_tmp < 2; b_Hv_tmp++) {
      b_C_tmp = i_5 + (b_Hv_tmp << 1);
      b_C_0[b_C_tmp] = 0.0;
      for (i_6 = 0; i_6 < 5; i_6++) {
        b_C_0[b_C_tmp] += b_C[(i_6 << 1) + i_5] * Bv[5 * b_Hv_tmp + i_6];
      }
    }
  }

  b_Hv[0] = b_C_0[0];
  b_Hv[40] = Dv[0];
  b_Hv[1] = b_C_0[1];
  b_Hv[41] = Dv[1];
  b_Hv[20] = b_C_0[2];
  b_Hv[60] = Dv[2];
  b_Hv[21] = b_C_0[3];
  b_Hv[61] = Dv[3];
  for (i_5 = 0; i_5 < 18; i_5++) {
    b_Hv_tmp = 20 * (i_5 + 4);
    b_Hv[b_Hv_tmp] = 0.0;
    b_Hv[b_Hv_tmp + 1] = 0.0;
  }

  for (i_5 = 0; i_5 < 22; i_5++) {
    std::memset(&b_Hv[i_5 * 20 + 2], 0, 18U * sizeof(real_T));
  }

  for (i_5 = 0; i_5 < 5; i_5++) {
    b_Hv_tmp = i_5 << 1;
    b_Sx[20 * i_5] = CA[b_Hv_tmp];
    b_Sx[20 * i_5 + 1] = CA[b_Hv_tmp + 1];
    std::memset(&b_Sx[i_5 * 20 + 2], 0, 18U * sizeof(real_T));
  }

  b_Su1[0] = Sum[0];
  b_Su1[1] = Sum[1];
  std::memset(&b_Su1[2], 0, 18U * sizeof(real_T));
  Su[0] = Sum[0];
  Su[1] = Sum[1];
  for (i_5 = 0; i_5 < 9; i_5++) {
    b_Hv_tmp = 20 * (i_5 + 1);
    Su[b_Hv_tmp] = 0.0;
    Su[b_Hv_tmp + 1] = 0.0;
  }

  for (i_5 = 0; i_5 < 10; i_5++) {
    std::memset(&Su[i_5 * 20 + 2], 0, 18U * sizeof(real_T));
  }

  for (b_C_tmp = 0; b_C_tmp < 9; b_C_tmp++) {
    i_4 = static_cast<int8_T>((((b_C_tmp + 1) << 1) + 1));
    for (i_5 = 0; i_5 < 2; i_5++) {
      rows[i_5] = static_cast<int8_T>((i_5 + i_4));
      tmp = 0.0;
      for (b_Hv_tmp = 0; b_Hv_tmp < 5; b_Hv_tmp++) {
        tmp += CA[(b_Hv_tmp << 1) + i_5] * Bu[b_Hv_tmp];
      }

      Sum[i_5] += tmp;
    }

    b_Su1[rows[0] - 1] = Sum[0];
    Sum_0[0] = Sum[0];
    b_Su1[rows[1] - 1] = Sum[1];
    Sum_0[1] = Sum[1];
    for (i_5 = 0; i_5 < 9; i_5++) {
      b_Hv_tmp = (i_5 + 1) << 1;
      Sum_0[b_Hv_tmp] = Su[(20 * i_5 + rows[0]) - 3];
      Sum_0[b_Hv_tmp + 1] = Su[(20 * i_5 + rows[1]) - 3];
    }

    for (i_5 = 0; i_5 < 10; i_5++) {
      b_Hv_tmp = i_5 << 1;
      Su[(rows[0] + 20 * i_5) - 1] = Sum_0[b_Hv_tmp];
      Su[(rows[1] + 20 * i_5) - 1] = Sum_0[b_Hv_tmp + 1];
    }

    for (i_5 = 0; i_5 < 2; i_5++) {
      for (b_Hv_tmp = 0; b_Hv_tmp < 2; b_Hv_tmp++) {
        CA_tmp = i_5 + (b_Hv_tmp << 1);
        b_C_0[CA_tmp] = 0.0;
        for (i_6 = 0; i_6 < 5; i_6++) {
          b_C_0[CA_tmp] += CA[(i_6 << 1) + i_5] * Bv[5 * b_Hv_tmp + i_6];
        }
      }
    }

    CA_0[0] = b_C_0[0];
    CA_0[1] = b_C_0[1];
    CA_0[2] = b_C_0[2];
    CA_0[3] = b_C_0[3];
    for (i_5 = 0; i_5 < 20; i_5++) {
      CA_tmp = (i_5 + 2) << 1;
      CA_0[CA_tmp] = b_Hv[(20 * i_5 + rows[0]) - 3];
      CA_0[CA_tmp + 1] = b_Hv[(20 * i_5 + rows[1]) - 3];
    }

    for (i_5 = 0; i_5 < 22; i_5++) {
      b_Hv_tmp = i_5 << 1;
      b_Hv[(rows[0] + 20 * i_5) - 1] = CA_0[b_Hv_tmp];
      b_Hv[(rows[1] + 20 * i_5) - 1] = CA_0[b_Hv_tmp + 1];
    }

    for (i_5 = 0; i_5 < 2; i_5++) {
      for (b_Hv_tmp = 0; b_Hv_tmp < 5; b_Hv_tmp++) {
        CA_tmp = i_5 + (b_Hv_tmp << 1);
        CA_1[CA_tmp] = 0.0;
        for (i_6 = 0; i_6 < 5; i_6++) {
          CA_1[CA_tmp] += CA[(i_6 << 1) + i_5] * b_A[5 * b_Hv_tmp + i_6];
        }
      }
    }

    std::memcpy(&CA[0], &CA_1[0], 10U * sizeof(real_T));
    for (i_5 = 0; i_5 < 5; i_5++) {
      b_Hv_tmp = i_5 << 1;
      b_Sx[(rows[0] + 20 * i_5) - 1] = CA[b_Hv_tmp];
      b_Sx[(rows[1] + 20 * i_5) - 1] = CA[b_Hv_tmp + 1];
    }
  }

  for (i_5 = 0; i_5 < 2; i_5++) {
    for (b_Hv_tmp = 0; b_Hv_tmp < 20; b_Hv_tmp++) {
      b_C_tmp = b_Hv_tmp + 20 * i_5;
      b_SuJm[b_C_tmp] = 0.0;
      for (i_6 = 0; i_6 < 10; i_6++) {
        b_SuJm[b_C_tmp] += Su[20 * i_6 + b_Hv_tmp] * b_Jm[10 * i_5 + i_6];
      }
    }
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::kron(const real_T b_A[100], real_T
  b_B, real_T K[100])
{
  int32_T kidx;
  int32_T b_j1;
  int32_T i1;
  kidx = -1;
  for (b_j1 = 0; b_j1 < 10; b_j1++) {
    for (i1 = 0; i1 < 10; i1++) {
      kidx++;
      K[kidx] = b_A[10 * b_j1 + i1] * b_B;
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y_a;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y_a = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y_a = u * 0.0;
    } else {
      y_a = std::ceil(u - 0.5);
    }
  } else {
    y_a = u;
  }

  return y_a;
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::WtMult(real_T W, const real_T M[20],
  real_T WM[20])
{
  int32_T i_a;
  int32_T i_b;
  int32_T WM_tmp;
  for (i_b = 0; i_b < 2; i_b++) {
    for (i_a = 0; i_a < 10; i_a++) {
      WM_tmp = 10 * i_b + i_a;
      WM[WM_tmp] = M[WM_tmp] * W;
    }
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::mpc_calculatehessian(const real_T
  b_Wy[2], real_T b_Wu, real_T b_Wdu, const real_T b_SuJm[40], const real_T
  I2Jm[20], const real_T b_Jm[20], const real_T b_I1[10], const real_T b_Su1[20],
  const real_T b_Sx[100], const real_T b_Hv[440], real_T b_ny, real_T b_H[4],
  real_T b_Ku1[2], real_T b_Kut[20], real_T b_Kx[10], real_T b_Kv[44], real_T
  b_Kr[40])
{
  int16_T ixw;
  int32_T i_7;
  real_T tmp[20];
  real_T b_Wy_0;
  real_T b_SuJm_0[4];
  real_T b_Jm_0[4];
  real_T b_Su1_0[2];
  real_T b_I1_0[2];
  int32_T i_8;
  int32_T i_9;
  int32_T b_SuJm_tmp;
  int32_T tmp_0;
  int32_T tmp_1;
  ixw = 1;
  for (i_7 = 0; i_7 < 20; i_7++) {
    b_Wy_0 = b_Wy[ixw - 1];
    b_Kr[i_7] = b_Wy_0 * b_SuJm[i_7];
    b_Kr[i_7 + 20] = b_SuJm[i_7 + 20] * b_Wy_0;
    i_9 = ixw + 1;
    if (i_9 > 32767) {
      i_9 = 32767;
    }

    ixw = static_cast<int16_T>(i_9);
    if (static_cast<int16_T>(i_9) > 2) {
      b_Wy_0 = rt_roundd_snf(2.0 - b_ny);
      if (b_Wy_0 < 32768.0) {
        if (b_Wy_0 >= -32768.0) {
          ixw = static_cast<int16_T>(b_Wy_0);
        } else {
          ixw = MIN_int16_T;
        }
      } else {
        ixw = MAX_int16_T;
      }

      i_9 = ixw + 1;
      if (i_9 > 32767) {
        i_9 = 32767;
      }

      ixw = static_cast<int16_T>(i_9);
    }
  }

  WtMult(b_Wu, I2Jm, b_Kut);
  WtMult(b_Wdu, b_Jm, tmp);
  for (i_9 = 0; i_9 < 2; i_9++) {
    for (i_7 = 0; i_7 < 2; i_7++) {
      b_SuJm_tmp = i_9 + (i_7 << 1);
      b_SuJm_0[b_SuJm_tmp] = 0.0;
      for (i_8 = 0; i_8 < 20; i_8++) {
        b_SuJm_0[b_SuJm_tmp] += b_SuJm[20 * i_9 + i_8] * b_Kr[20 * i_7 + i_8];
      }

      b_Jm_0[b_SuJm_tmp] = 0.0;
      b_Wy_0 = 0.0;
      for (i_8 = 0; i_8 < 10; i_8++) {
        tmp_0 = 10 * i_9 + i_8;
        tmp_1 = 10 * i_7 + i_8;
        b_Wy_0 += I2Jm[tmp_0] * b_Kut[tmp_1];
        b_Jm_0[b_SuJm_tmp] += b_Jm[tmp_0] * tmp[tmp_1];
      }

      b_H[b_SuJm_tmp] = (b_SuJm_0[b_SuJm_tmp] + b_Jm_0[b_SuJm_tmp]) + b_Wy_0;
    }

    b_Su1_0[i_9] = 0.0;
    for (i_7 = 0; i_7 < 20; i_7++) {
      b_Su1_0[i_9] += b_Kr[20 * i_9 + i_7] * b_Su1[i_7];
    }

    b_I1_0[i_9] = 0.0;
    for (i_7 = 0; i_7 < 10; i_7++) {
      b_I1_0[i_9] += b_Kut[10 * i_9 + i_7] * b_I1[i_7];
    }

    b_Ku1[i_9] = b_Su1_0[i_9] + b_I1_0[i_9];
  }

  for (i_9 = 0; i_9 < 20; i_9++) {
    b_Kut[i_9] = -b_Kut[i_9];
  }

  for (i_9 = 0; i_9 < 5; i_9++) {
    for (i_7 = 0; i_7 < 2; i_7++) {
      b_SuJm_tmp = i_9 + 5 * i_7;
      b_Kx[b_SuJm_tmp] = 0.0;
      for (i_8 = 0; i_8 < 20; i_8++) {
        b_Kx[b_SuJm_tmp] += b_Sx[20 * i_9 + i_8] * b_Kr[20 * i_7 + i_8];
      }
    }
  }

  for (i_9 = 0; i_9 < 22; i_9++) {
    for (i_7 = 0; i_7 < 2; i_7++) {
      b_SuJm_tmp = i_9 + 22 * i_7;
      b_Kv[b_SuJm_tmp] = 0.0;
      for (i_8 = 0; i_8 < 20; i_8++) {
        b_Kv[b_SuJm_tmp] += b_Hv[20 * i_9 + i_8] * b_Kr[20 * i_7 + i_8];
      }
    }
  }

  for (i_9 = 0; i_9 < 40; i_9++) {
    b_Kr[i_9] = -b_Kr[i_9];
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
int32_T PathFollowingControllerRefMdlModelClass::xpotrf(real_T b_A[9])
{
  int32_T info;
  int32_T idxAjj;
  real_T ssq;
  int32_T j_1;
  real_T c;
  int32_T iy;
  int32_T d;
  int32_T ia;
  int32_T b_ix;
  int32_T b_iy;
  int32_T b_k;
  boolean_T exitg1;
  info = 0;
  j_1 = 0;
  exitg1 = false;
  while ((!exitg1) && (j_1 < 3)) {
    idxAjj = j_1 * 3 + j_1;
    ssq = 0.0;
    if (j_1 >= 1) {
      b_ix = j_1;
      b_iy = j_1;
      for (b_k = 0; b_k < j_1; b_k++) {
        ssq += b_A[b_ix] * b_A[b_iy];
        b_ix += 3;
        b_iy += 3;
      }
    }

    ssq = b_A[idxAjj] - ssq;
    if (ssq > 0.0) {
      ssq = std::sqrt(ssq);
      b_A[idxAjj] = ssq;
      if (j_1 + 1 < 3) {
        if (j_1 != 0) {
          b_ix = j_1;
          b_iy = ((j_1 - 1) * 3 + j_1) + 2;
          for (b_k = j_1 + 2; b_k <= b_iy; b_k += 3) {
            c = -b_A[b_ix];
            iy = idxAjj + 1;
            d = (b_k - j_1) + 1;
            for (ia = b_k; ia <= d; ia++) {
              b_A[iy] += b_A[ia - 1] * c;
              iy++;
            }

            b_ix += 3;
          }
        }

        ssq = 1.0 / ssq;
        b_ix = (idxAjj - j_1) + 3;
        for (idxAjj++; idxAjj < b_ix; idxAjj++) {
          b_A[idxAjj] *= ssq;
        }
      }

      j_1++;
    } else {
      b_A[idxAjj] = ssq;
      info = j_1 + 1;
      exitg1 = true;
    }
  }

  return info;
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::mpc_checkhessian(real_T b_H[9],
  real_T L[9], real_T *BadH)
{
  real_T normH;
  real_T d[3];
  int8_T b_I[9];
  real_T s;
  int32_T idx;
  int32_T b_idx;
  int32_T f_k;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *BadH = 0.0;
  std::memcpy(&L[0], &b_H[0], 9U * sizeof(real_T));
  idx = xpotrf(L);
  guard1 = false;
  if (idx == 0) {
    d[0] = L[0];
    d[1] = L[4];
    d[2] = L[8];
    if (!rtIsNaN(L[0])) {
      idx = 1;
    } else {
      idx = 0;
      b_idx = 2;
      exitg2 = false;
      while ((!exitg2) && (b_idx < 4)) {
        if (!rtIsNaN(d[b_idx - 1])) {
          idx = b_idx;
          exitg2 = true;
        } else {
          b_idx++;
        }
      }
    }

    if (idx == 0) {
      normH = L[0];
    } else {
      normH = d[idx - 1];
      while (idx + 1 <= 3) {
        if (normH > d[idx]) {
          normH = d[idx];
        }

        idx++;
      }
    }

    if (normH > 1.4901161193847656E-7) {
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    normH = 0.0;
    idx = 0;
    exitg2 = false;
    while ((!exitg2) && (idx < 3)) {
      s = (std::abs(b_H[idx + 3]) + std::abs(b_H[idx])) + std::abs(b_H[idx + 6]);
      if (rtIsNaN(s)) {
        normH = (rtNaN);
        exitg2 = true;
      } else {
        if (s > normH) {
          normH = s;
        }

        idx++;
      }
    }

    if (normH >= 1.0E+10) {
      *BadH = 2.0;
    } else {
      idx = 0;
      exitg1 = false;
      while ((!exitg1) && (idx <= 4)) {
        for (b_idx = 0; b_idx < 9; b_idx++) {
          b_I[b_idx] = 0;
        }

        b_I[0] = 1;
        b_I[4] = 1;
        b_I[8] = 1;
        normH = rt_powd_snf(10.0, static_cast<real_T>(idx)) *
          1.4901161193847656E-7;
        for (b_idx = 0; b_idx < 9; b_idx++) {
          s = normH * static_cast<real_T>(b_I[b_idx]) + b_H[b_idx];
          L[b_idx] = s;
          b_H[b_idx] = s;
        }

        b_idx = xpotrf(L);
        guard2 = false;
        if (b_idx == 0) {
          d[0] = L[0];
          d[1] = L[4];
          d[2] = L[8];
          if (!rtIsNaN(L[0])) {
            b_idx = 1;
          } else {
            b_idx = 0;
            f_k = 2;
            exitg2 = false;
            while ((!exitg2) && (f_k < 4)) {
              if (!rtIsNaN(d[f_k - 1])) {
                b_idx = f_k;
                exitg2 = true;
              } else {
                f_k++;
              }
            }
          }

          if (b_idx == 0) {
            normH = L[0];
          } else {
            normH = d[b_idx - 1];
            while (b_idx + 1 <= 3) {
              if (normH > d[b_idx]) {
                normH = d[b_idx];
              }

              b_idx++;
            }
          }

          if (normH > 1.4901161193847656E-7) {
            *BadH = 1.0;
            exitg1 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          *BadH = 3.0;
          idx++;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::eye_g(real_T b_I[9])
{
  std::memset(&b_I[0], 0, 9U * sizeof(real_T));
  b_I[0] = 1.0;
  b_I[4] = 1.0;
  b_I[8] = 1.0;
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::trisolve(const real_T b_A[9],
  real_T b_B[9])
{
  int32_T jBcol;
  int32_T j_2;
  int32_T i_e;
  real_T tmp;
  int32_T tmp_0;
  for (j_2 = 0; j_2 < 3; j_2++) {
    jBcol = 3 * j_2;
    if (b_B[jBcol] != 0.0) {
      b_B[jBcol] /= b_A[0];
      for (i_e = 2; i_e < 4; i_e++) {
        tmp_0 = (i_e + jBcol) - 1;
        b_B[tmp_0] -= b_A[i_e - 1] * b_B[jBcol];
      }
    }

    tmp = b_B[jBcol + 1];
    if (tmp != 0.0) {
      b_B[jBcol + 1] = tmp / b_A[4];
      b_B[jBcol + 2] -= b_B[jBcol + 1] * b_A[5];
    }

    if (b_B[jBcol + 2] != 0.0) {
      b_B[jBcol + 2] /= b_A[8];
    }
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::linsolve(const real_T b_A[9],
  const real_T b_B[9], real_T b_C[9])
{
  int32_T j_0;
  int32_T b_C_tmp;
  for (j_0 = 0; j_0 < 3; j_0++) {
    b_C[3 * j_0] = b_B[3 * j_0];
    b_C_tmp = 3 * j_0 + 1;
    b_C[b_C_tmp] = b_B[b_C_tmp];
    b_C_tmp = 3 * j_0 + 2;
    b_C[b_C_tmp] = b_B[b_C_tmp];
  }

  trisolve(b_A, b_C);
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::Unconstrained(const real_T b_Hinv
  [9], const real_T f[3], real_T x_8[3], int16_T n_4)
{
  int32_T i_l;
  int32_T i_m;
  for (i_l = 1; i_l - 1 < n_4; i_l++) {
    i_m = static_cast<int16_T>(i_l);
    x_8[static_cast<int16_T>(i_l) - 1] = (-b_Hinv[i_m - 1] * f[0] + -b_Hinv[i_m
      + 2] * f[1]) + -b_Hinv[i_m + 5] * f[2];
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
real_T PathFollowingControllerRefMdlModelClass::norm(const real_T x_3[3])
{
  real_T y_1;
  real_T scale;
  real_T absxk;
  real_T t_1;
  scale = 3.3121686421112381E-170;
  absxk = std::abs(x_3[0]);
  if (absxk > 3.3121686421112381E-170) {
    y_1 = 1.0;
    scale = absxk;
  } else {
    t_1 = absxk / 3.3121686421112381E-170;
    y_1 = t_1 * t_1;
  }

  absxk = std::abs(x_3[1]);
  if (absxk > scale) {
    t_1 = scale / absxk;
    y_1 = y_1 * t_1 * t_1 + 1.0;
    scale = absxk;
  } else {
    t_1 = absxk / scale;
    y_1 += t_1 * t_1;
  }

  absxk = std::abs(x_3[2]);
  if (absxk > scale) {
    t_1 = scale / absxk;
    y_1 = y_1 * t_1 * t_1 + 1.0;
    scale = absxk;
  } else {
    t_1 = absxk / scale;
    y_1 += t_1 * t_1;
  }

  return scale * std::sqrt(y_1);
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::abs_g(const real_T x_4[3], real_T
  y_2[3])
{
  y_2[0] = std::abs(x_4[0]);
  y_2[1] = std::abs(x_4[1]);
  y_2[2] = std::abs(x_4[2]);
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::abs_gt(const real_T x_5[4], real_T
  y_3[4])
{
  y_3[0] = std::abs(x_5[0]);
  y_3[1] = std::abs(x_5[1]);
  y_3[2] = std::abs(x_5[2]);
  y_3[3] = std::abs(x_5[3]);
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
real_T PathFollowingControllerRefMdlModelClass::xnrm2(int32_T n_0, const real_T
  x_2[9], int32_T ix0)
{
  real_T y_0;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t_0;
  int32_T k;
  y_0 = 0.0;
  if (n_0 >= 1) {
    if (n_0 == 1) {
      y_0 = std::abs(x_2[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n_0) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = std::abs(x_2[k - 1]);
        if (absxk > scale) {
          t_0 = scale / absxk;
          y_0 = y_0 * t_0 * t_0 + 1.0;
          scale = absxk;
        } else {
          t_0 = absxk / scale;
          y_0 += t_0 * t_0;
        }
      }

      y_0 = scale * std::sqrt(y_0);
    }
  }

  return y_0;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y_8;
  real_T a;
  a = std::abs(u0);
  y_8 = std::abs(u1);
  if (a < y_8) {
    a /= y_8;
    y_8 *= std::sqrt(a * a + 1.0);
  } else if (a > y_8) {
    y_8 /= a;
    y_8 = std::sqrt(y_8 * y_8 + 1.0) * a;
  } else {
    if (!rtIsNaN(y_8)) {
      y_8 = a * 1.4142135623730951;
    }
  }

  return y_8;
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::xgemv(int32_T m_0, int32_T n_2,
  const real_T b_A[9], int32_T ia0, const real_T x_7[9], int32_T ix0, real_T
  y_4[3])
{
  int32_T ix;
  real_T c;
  int32_T b_iy;
  int32_T b;
  int32_T iac;
  int32_T d;
  int32_T ia;
  if ((m_0 != 0) && (n_2 != 0)) {
    for (b_iy = 0; b_iy < n_2; b_iy++) {
      y_4[b_iy] = 0.0;
    }

    b_iy = 0;
    b = (n_2 - 1) * 3 + ia0;
    for (iac = ia0; iac <= b; iac += 3) {
      ix = ix0;
      c = 0.0;
      d = (iac + m_0) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += b_A[ia - 1] * x_7[ix - 1];
        ix++;
      }

      y_4[b_iy] += c;
      b_iy++;
    }
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::xgerc(int32_T m_1, int32_T n_3,
  real_T alpha1, int32_T ix0, const real_T y_5[3], real_T b_A[9], int32_T ia0)
{
  int32_T jA;
  int32_T jy;
  real_T temp;
  int32_T ix;
  int32_T j_3;
  int32_T b;
  int32_T ijA;
  if (!(alpha1 == 0.0)) {
    jA = ia0 - 1;
    jy = 0;
    for (j_3 = 0; j_3 < n_3; j_3++) {
      if (y_5[jy] != 0.0) {
        temp = y_5[jy] * alpha1;
        ix = ix0;
        b = m_1 + jA;
        for (ijA = jA; ijA < b; ijA++) {
          b_A[ijA] += b_A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 3;
    }
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::qr(const real_T b_A[9], real_T Q[9],
  real_T R[9])
{
  real_T c_A[9];
  real_T work[3];
  real_T b_atmp;
  real_T beta1;
  int32_T knt;
  int32_T lastc;
  int32_T coltop;
  int32_T b_coltop;
  real_T tau_idx_0;
  real_T tau_idx_1;
  int32_T exitg1;
  boolean_T exitg2;
  tau_idx_0 = 0.0;
  tau_idx_1 = 0.0;
  std::memcpy(&c_A[0], &b_A[0], 9U * sizeof(real_T));
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  b_atmp = c_A[0];
  beta1 = xnrm2(2, c_A, 2);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(c_A[0], beta1);
    if (c_A[0] >= 0.0) {
      beta1 = -beta1;
    }

    if (std::abs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      lastc = 0;
      do {
        knt++;
        for (coltop = 1; coltop < 3; coltop++) {
          c_A[coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while (!(std::abs(beta1) >= 1.0020841800044864E-292));

      beta1 = rt_hypotd_snf(b_atmp, xnrm2(2, c_A, 2));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (coltop = 1; coltop < 3; coltop++) {
        c_A[coltop] *= b_atmp;
      }

      while (lastc <= knt) {
        beta1 *= 1.0020841800044864E-292;
        lastc++;
      }

      b_atmp = beta1;
    } else {
      tau_idx_0 = (beta1 - c_A[0]) / beta1;
      b_atmp = 1.0 / (c_A[0] - beta1);
      for (lastc = 1; lastc < 3; lastc++) {
        c_A[lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  c_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    knt = 3;
    lastc = 0;
    while ((knt > 0) && (c_A[lastc + 2] == 0.0)) {
      knt--;
      lastc--;
    }

    lastc = 2;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      coltop = (lastc - 1) * 3 + 3;
      b_coltop = coltop;
      do {
        exitg1 = 0;
        if (b_coltop + 1 <= coltop + knt) {
          if (c_A[b_coltop] != 0.0) {
            exitg1 = 1;
          } else {
            b_coltop++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    knt = 0;
    lastc = 0;
  }

  if (knt > 0) {
    xgemv(knt, lastc, c_A, 4, c_A, 1, work);
    xgerc(knt, lastc, -tau_idx_0, 1, work, c_A, 4);
  }

  c_A[0] = b_atmp;
  b_atmp = c_A[4];
  beta1 = xnrm2(1, c_A, 6);
  if (beta1 != 0.0) {
    beta1 = rt_hypotd_snf(c_A[4], beta1);
    if (c_A[4] >= 0.0) {
      beta1 = -beta1;
    }

    if (std::abs(beta1) < 1.0020841800044864E-292) {
      knt = -1;
      do {
        knt++;
        for (coltop = 5; coltop < 6; coltop++) {
          c_A[coltop] *= 9.9792015476736E+291;
        }

        beta1 *= 9.9792015476736E+291;
        b_atmp *= 9.9792015476736E+291;
      } while (!(std::abs(beta1) >= 1.0020841800044864E-292));

      beta1 = rt_hypotd_snf(b_atmp, xnrm2(1, c_A, 6));
      if (b_atmp >= 0.0) {
        beta1 = -beta1;
      }

      tau_idx_1 = (beta1 - b_atmp) / beta1;
      b_atmp = 1.0 / (b_atmp - beta1);
      for (coltop = 5; coltop < 6; coltop++) {
        c_A[coltop] *= b_atmp;
      }

      for (lastc = 0; lastc <= knt; lastc++) {
        beta1 *= 1.0020841800044864E-292;
      }

      b_atmp = beta1;
    } else {
      tau_idx_1 = (beta1 - c_A[4]) / beta1;
      b_atmp = 1.0 / (c_A[4] - beta1);
      for (lastc = 5; lastc < 6; lastc++) {
        c_A[lastc] *= b_atmp;
      }

      b_atmp = beta1;
    }
  }

  c_A[4] = 1.0;
  if (tau_idx_1 != 0.0) {
    knt = 2;
    lastc = 3;
    while ((knt > 0) && (c_A[lastc + 2] == 0.0)) {
      knt--;
      lastc--;
    }

    lastc = 1;
    b_coltop = 7;
    do {
      exitg1 = 0;
      if (b_coltop + 1 <= 7 + knt) {
        if (c_A[b_coltop] != 0.0) {
          exitg1 = 1;
        } else {
          b_coltop++;
        }
      } else {
        lastc = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    knt = 0;
    lastc = 0;
  }

  if (knt > 0) {
    xgemv(knt, lastc, c_A, 8, c_A, 5, work);
    xgerc(knt, lastc, -tau_idx_1, 5, work, c_A, 8);
  }

  c_A[4] = b_atmp;
  R[0] = c_A[0];
  for (lastc = 1; lastc + 1 < 4; lastc++) {
    R[lastc] = 0.0;
  }

  work[0] = 0.0;
  for (lastc = 0; lastc < 2; lastc++) {
    R[lastc + 3] = c_A[lastc + 3];
  }

  while (lastc + 1 < 4) {
    R[lastc + 3] = 0.0;
    lastc++;
  }

  work[1] = 0.0;
  for (lastc = 0; lastc < 3; lastc++) {
    R[lastc + 6] = c_A[lastc + 6];
  }

  work[2] = 0.0;
  c_A[8] = 1.0;
  for (lastc = 0; lastc < 2; lastc++) {
    c_A[7 - lastc] = 0.0;
  }

  c_A[4] = 1.0;
  if (tau_idx_1 != 0.0) {
    coltop = 7;
    while ((lastc > 0) && (c_A[coltop - 2] == 0.0)) {
      lastc--;
      coltop--;
    }

    coltop = 1;
    knt = 8;
    do {
      exitg1 = 0;
      if (knt <= lastc + 7) {
        if (c_A[knt - 1] != 0.0) {
          exitg1 = 1;
        } else {
          knt++;
        }
      } else {
        coltop = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    lastc = 0;
    coltop = 0;
  }

  if (lastc > 0) {
    xgemv(lastc, coltop, c_A, 8, c_A, 5, work);
    xgerc(lastc, coltop, -tau_idx_1, 5, work, c_A, 8);
  }

  for (coltop = 5; coltop < 6; coltop++) {
    c_A[coltop] *= -tau_idx_1;
  }

  c_A[4] = 1.0 - tau_idx_1;
  c_A[3] = 0.0;
  c_A[0] = 1.0;
  if (tau_idx_0 != 0.0) {
    lastc = 3;
    coltop = 4;
    while ((lastc > 0) && (c_A[coltop - 2] == 0.0)) {
      lastc--;
      coltop--;
    }

    coltop = 2;
    exitg2 = false;
    while ((!exitg2) && (coltop > 0)) {
      b_coltop = (coltop - 1) * 3 + 4;
      knt = b_coltop;
      do {
        exitg1 = 0;
        if (knt <= (b_coltop + lastc) - 1) {
          if (c_A[knt - 1] != 0.0) {
            exitg1 = 1;
          } else {
            knt++;
          }
        } else {
          coltop--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastc = 0;
    coltop = 0;
  }

  if (lastc > 0) {
    xgemv(lastc, coltop, c_A, 4, c_A, 1, work);
    xgerc(lastc, coltop, -tau_idx_0, 1, work, c_A, 4);
  }

  for (coltop = 1; coltop < 3; coltop++) {
    c_A[coltop] *= -tau_idx_0;
  }

  c_A[0] = 1.0 - tau_idx_0;
  for (lastc = 0; lastc < 3; lastc++) {
    Q[3 * lastc] = c_A[3 * lastc];
    coltop = 3 * lastc + 1;
    Q[coltop] = c_A[coltop];
    coltop = 3 * lastc + 2;
    Q[coltop] = c_A[coltop];
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
real_T PathFollowingControllerRefMdlModelClass::KWIKfactor(const real_T b_Ac[12],
  const int16_T iC[4], int16_T nA, const real_T b_Linv[9], real_T RLinv[9],
  real_T b_D[9], real_T b_H[9], int16_T n_1)
{
  real_T Status;
  real_T TL[9];
  real_T QQ[9];
  real_T RR[9];
  int32_T i_i;
  int16_T b_j;
  int16_T c_k;
  int32_T f_i;
  int32_T i_j;
  int32_T tmp;
  int32_T TL_tmp;
  int32_T TL_tmp_0;
  int32_T tmp_0;
  int32_T exitg1;
  int32_T exitg2;
  Status = 1.0;
  std::memset(&RLinv[0], 0, 9U * sizeof(real_T));
  i_i = 1;
  do {
    exitg1 = 0;
    i_j = nA - 1;
    if (i_i - 1 <= i_j) {
      f_i = static_cast<int16_T>(i_i) - 1;
      TL_tmp = iC[f_i];
      for (i_j = 0; i_j < 3; i_j++) {
        tmp = i_j + 3 * f_i;
        RLinv[tmp] = 0.0;
        RLinv[tmp] += b_Ac[TL_tmp - 1] * b_Linv[i_j];
        RLinv[tmp] += b_Linv[i_j + 3] * b_Ac[TL_tmp + 3];
        RLinv[tmp] += b_Linv[i_j + 6] * b_Ac[TL_tmp + 7];
      }

      i_i++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  qr(RLinv, QQ, RR);
  i_i = 1;
  do {
    exitg1 = 0;
    if (i_i - 1 <= i_j) {
      if (std::abs(RR[((static_cast<int16_T>(i_i) - 1) * 3 + static_cast<int16_T>
                       (i_i)) - 1]) < 1.0E-12) {
        Status = -2.0;
        exitg1 = 1;
      } else {
        i_i++;
      }
    } else {
      i_i = 1;
      do {
        exitg2 = 0;
        tmp = n_1 - 1;
        if (i_i - 1 <= tmp) {
          for (f_i = 1; f_i - 1 <= tmp; f_i++) {
            TL_tmp = (static_cast<int16_T>(i_i) - 1) * 3;
            TL_tmp_0 = (static_cast<int16_T>(f_i) - 1) * 3;
            TL[(static_cast<int16_T>(i_i) + 3 * (static_cast<int16_T>(f_i) - 1))
              - 1] = (b_Linv[TL_tmp + 1] * QQ[TL_tmp_0 + 1] + b_Linv[TL_tmp] *
                      QQ[TL_tmp_0]) + b_Linv[TL_tmp + 2] * QQ[TL_tmp_0 + 2];
          }

          i_i++;
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      std::memset(&RLinv[0], 0, 9U * sizeof(real_T));
      b_j = nA;
      while (b_j > 0) {
        TL_tmp = b_j - 1;
        TL_tmp_0 = 3 * TL_tmp;
        f_i = (b_j + TL_tmp_0) - 1;
        RLinv[f_i] = 1.0;
        for (c_k = b_j; c_k <= nA; c_k = static_cast<int16_T>((c_k + 1))) {
          tmp_0 = ((c_k - 1) * 3 + b_j) - 1;
          RLinv[tmp_0] /= RR[f_i];
        }

        if (b_j > 1) {
          for (i_i = 1; i_i - 1 <= b_j - 2; i_i++) {
            for (c_k = b_j; c_k <= nA; c_k = static_cast<int16_T>((c_k + 1))) {
              f_i = (c_k - 1) * 3;
              tmp_0 = (f_i + static_cast<int16_T>(i_i)) - 1;
              RLinv[tmp_0] -= RR[(TL_tmp_0 + static_cast<int16_T>(i_i)) - 1] *
                RLinv[(f_i + b_j) - 1];
            }
          }
        }

        b_j = static_cast<int16_T>(TL_tmp);
      }

      for (i_i = 1; i_i - 1 <= tmp; i_i++) {
        for (b_j = static_cast<int16_T>(i_i); b_j <= n_1; b_j =
             static_cast<int16_T>((b_j + 1))) {
          TL_tmp = (static_cast<int16_T>(i_i) + 3 * (b_j - 1)) - 1;
          b_H[TL_tmp] = 0.0;
          TL_tmp_0 = nA + 1;
          if (TL_tmp_0 > 32767) {
            TL_tmp_0 = 32767;
          }

          for (c_k = static_cast<int16_T>(TL_tmp_0); c_k <= n_1; c_k =
               static_cast<int16_T>((c_k + 1))) {
            TL_tmp_0 = (c_k - 1) * 3;
            b_H[TL_tmp] -= TL[(TL_tmp_0 + static_cast<int16_T>(i_i)) - 1] * TL
              [(TL_tmp_0 + b_j) - 1];
          }

          b_H[(b_j + 3 * (static_cast<int16_T>(i_i) - 1)) - 1] = b_H[TL_tmp];
        }
      }

      for (i_i = 1; i_i - 1 <= i_j; i_i++) {
        for (f_i = 1; f_i - 1 <= tmp; f_i++) {
          TL_tmp = (static_cast<int16_T>(f_i) + 3 * (static_cast<int16_T>(i_i) -
                     1)) - 1;
          b_D[TL_tmp] = 0.0;
          for (b_j = static_cast<int16_T>(i_i); b_j <= nA; b_j =
               static_cast<int16_T>((b_j + 1))) {
            TL_tmp_0 = (b_j - 1) * 3;
            b_D[TL_tmp] += TL[(TL_tmp_0 + static_cast<int16_T>(f_i)) - 1] *
              RLinv[(TL_tmp_0 + static_cast<int16_T>(i_i)) - 1];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Status;
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::DropConstraint(int16_T kDrop,
  int16_T iA[4], int16_T *nA, int16_T iC[4])
{
  int16_T i_k;
  int32_T tmp;
  iA[iC[kDrop - 1] - 1] = 0;
  if (kDrop < *nA) {
    tmp = *nA - 1;
    if (tmp < -32768) {
      tmp = -32768;
    }

    for (i_k = kDrop; i_k <= static_cast<int16_T>(tmp); i_k =
         static_cast<int16_T>((i_k + 1))) {
      iC[i_k - 1] = iC[i_k];
    }
  }

  tmp = *nA - 1;
  iC[tmp] = 0;
  if (tmp < -32768) {
    tmp = -32768;
  }

  *nA = static_cast<int16_T>(tmp);
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::qpkwik(const real_T b_Linv[9],
  const real_T b_Hinv[9], const real_T f[3], const real_T b_Ac[12], const real_T
  b[4], int16_T iA[4], int16_T b_maxiter, real_T FeasTol, real_T x_6[3], real_T
  lambda[4], real_T *status)
{
  real_T r_1[3];
  real_T rMin;
  real_T RLinv[9];
  real_T b_D[9];
  real_T b_H[9];
  real_T U[9];
  real_T cTol[4];
  boolean_T cTolComputed;
  int16_T iC[4];
  int16_T nA;
  real_T Opt[6];
  real_T Rhs[6];
  boolean_T DualFeasible;
  boolean_T ColdReset;
  int16_T kDrop;
  real_T Xnorm0;
  real_T cMin;
  int16_T kNext;
  real_T cVal;
  real_T AcRow[3];
  real_T t_2;
  real_T varargin_1[4];
  int32_T idx;
  int32_T e_k;
  int32_T i_h;
  real_T b_Ac_0[3];
  int32_T tmp;
  int32_T Rhs_tmp;
  int32_T U_tmp;
  int32_T lambda_tmp;
  int32_T exitg1;
  int32_T exitg2;
  int32_T exitg3;
  boolean_T exitg4;
  int32_T exitg5;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *status = 1.0;
  lambda[0] = 0.0;
  lambda[1] = 0.0;
  lambda[2] = 0.0;
  lambda[3] = 0.0;
  x_6[0] = 0.0;
  r_1[0] = 0.0;
  x_6[1] = 0.0;
  r_1[1] = 0.0;
  x_6[2] = 0.0;
  r_1[2] = 0.0;
  rMin = 0.0;
  cTolComputed = false;
  cTol[0] = 1.0;
  iC[0] = 0;
  cTol[1] = 1.0;
  iC[1] = 0;
  cTol[2] = 1.0;
  iC[2] = 0;
  cTol[3] = 1.0;
  iC[3] = 0;
  nA = 0;
  if (iA[0] == 1) {
    nA = 1;
    iC[0] = 1;
  }

  if (iA[1] == 1) {
    e_k = nA + 1;
    nA = static_cast<int16_T>(e_k);
    iC[static_cast<int16_T>(e_k) - 1] = 2;
  }

  if (iA[2] == 1) {
    e_k = nA + 1;
    nA = static_cast<int16_T>(e_k);
    iC[static_cast<int16_T>(e_k) - 1] = 3;
  }

  if (iA[3] == 1) {
    e_k = nA + 1;
    nA = static_cast<int16_T>(e_k);
    iC[static_cast<int16_T>(e_k) - 1] = 4;
  }

  guard1 = false;
  if (nA > 0) {
    for (i_h = 0; i_h < 6; i_h++) {
      Opt[i_h] = 0.0;
    }

    Rhs[0] = f[0];
    Rhs[3] = 0.0;
    Rhs[1] = f[1];
    Rhs[4] = 0.0;
    Rhs[2] = f[2];
    Rhs[5] = 0.0;
    DualFeasible = false;
    ColdReset = false;
    do {
      exitg3 = 0;
      if ((!DualFeasible) && (nA > 0) && (static_cast<int32_T>(*status) <=
           b_maxiter)) {
        Xnorm0 = KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, b_D, b_H, 3);
        if (Xnorm0 < 0.0) {
          if (ColdReset) {
            *status = -2.0;
            exitg3 = 2;
          } else {
            nA = 0;
            iA[0] = 0;
            iC[0] = 0;
            iA[1] = 0;
            iC[1] = 0;
            iA[2] = 0;
            iC[2] = 0;
            iA[3] = 0;
            iC[3] = 0;
            ColdReset = true;
          }
        } else {
          i_h = 1;
          do {
            exitg5 = 0;
            e_k = nA - 1;
            if (i_h - 1 <= e_k) {
              lambda_tmp = static_cast<int16_T>(i_h) + 3;
              if (lambda_tmp > 32767) {
                lambda_tmp = 32767;
              }

              Rhs_tmp = static_cast<int16_T>(i_h) - 1;
              Rhs[lambda_tmp - 1] = b[iC[Rhs_tmp] - 1];
              for (kNext = static_cast<int16_T>(i_h); kNext <= nA; kNext =
                   static_cast<int16_T>((kNext + 1))) {
                lambda_tmp = (kNext + 3 * Rhs_tmp) - 1;
                U[lambda_tmp] = 0.0;
                for (idx = 1; idx - 1 <= e_k; idx++) {
                  U_tmp = (static_cast<int16_T>(idx) - 1) * 3;
                  U[lambda_tmp] += RLinv[(U_tmp + kNext) - 1] * RLinv[(U_tmp +
                    static_cast<int16_T>(i_h)) - 1];
                }

                U[(static_cast<int16_T>(i_h) + 3 * (kNext - 1)) - 1] =
                  U[lambda_tmp];
              }

              i_h++;
            } else {
              exitg5 = 1;
            }
          } while (exitg5 == 0);

          for (i_h = 0; i_h < 3; i_h++) {
            idx = i_h + 1;
            Opt[i_h] = (b_H[idx - 1] * Rhs[0] + b_H[idx + 2] * Rhs[1]) + b_H[idx
              + 5] * Rhs[2];
            for (idx = 1; idx - 1 <= e_k; idx++) {
              lambda_tmp = static_cast<int16_T>(idx) + 3;
              if (lambda_tmp > 32767) {
                lambda_tmp = 32767;
              }

              Opt[i_h] += b_D[(static_cast<int16_T>(idx) - 1) * 3 + i_h] *
                Rhs[lambda_tmp - 1];
            }
          }

          for (i_h = 1; i_h - 1 <= e_k; i_h++) {
            lambda_tmp = static_cast<int16_T>(i_h) + 3;
            Rhs_tmp = lambda_tmp;
            if (lambda_tmp > 32767) {
              Rhs_tmp = 32767;
            }

            idx = (static_cast<int16_T>(i_h) - 1) * 3;
            Opt[Rhs_tmp - 1] = (b_D[idx + 1] * Rhs[1] + b_D[idx] * Rhs[0]) +
              b_D[idx + 2] * Rhs[2];
            for (idx = 1; idx - 1 <= e_k; idx++) {
              Rhs_tmp = lambda_tmp;
              if (lambda_tmp > 32767) {
                Rhs_tmp = 32767;
              }

              U_tmp = lambda_tmp;
              if (lambda_tmp > 32767) {
                U_tmp = 32767;
              }

              tmp = static_cast<int16_T>(idx) + 3;
              if (tmp > 32767) {
                tmp = 32767;
              }

              Opt[Rhs_tmp - 1] = U[((static_cast<int16_T>(idx) - 1) * 3 +
                                    static_cast<int16_T>(i_h)) - 1] * Rhs[tmp -
                1] + Opt[U_tmp - 1];
            }
          }

          Xnorm0 = -1.0E-12;
          kDrop = 0;
          for (i_h = 1; i_h - 1 <= e_k; i_h++) {
            lambda_tmp = static_cast<int16_T>(i_h) + 3;
            Rhs_tmp = lambda_tmp;
            if (lambda_tmp > 32767) {
              Rhs_tmp = 32767;
            }

            lambda[iC[static_cast<int16_T>(i_h) - 1] - 1] = Opt[Rhs_tmp - 1];
            Rhs_tmp = lambda_tmp;
            if (lambda_tmp > 32767) {
              Rhs_tmp = 32767;
            }

            if ((Opt[Rhs_tmp - 1] < Xnorm0) && (static_cast<int16_T>(i_h) <= nA))
            {
              kDrop = static_cast<int16_T>(i_h);
              if (lambda_tmp > 32767) {
                lambda_tmp = 32767;
              }

              Xnorm0 = Opt[lambda_tmp - 1];
            }
          }

          if (kDrop <= 0) {
            DualFeasible = true;
            x_6[0] = Opt[0];
            x_6[1] = Opt[1];
            x_6[2] = Opt[2];
          } else {
            (*status)++;
            if (static_cast<int32_T>(*status) > 5) {
              nA = 0;
              iA[0] = 0;
              iC[0] = 0;
              iA[1] = 0;
              iC[1] = 0;
              iA[2] = 0;
              iC[2] = 0;
              iA[3] = 0;
              iC[3] = 0;
              ColdReset = true;
            } else {
              lambda[iC[kDrop - 1] - 1] = 0.0;
              DropConstraint(kDrop, iA, &nA, iC);
            }
          }
        }
      } else {
        if (nA <= 0) {
          lambda[0] = 0.0;
          lambda[1] = 0.0;
          lambda[2] = 0.0;
          lambda[3] = 0.0;
          Unconstrained(b_Hinv, f, x_6, 3);
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    Unconstrained(b_Hinv, f, x_6, 3);
    guard1 = true;
  }

  if (guard1) {
    Xnorm0 = norm(x_6);
    do {
      exitg2 = 0;
      if (static_cast<int32_T>(*status) <= b_maxiter) {
        cMin = -FeasTol;
        kNext = 0;
        for (i_h = 0; i_h < 4; i_h++) {
          if (!cTolComputed) {
            idx = i_h + 1;
            b_Ac_0[0] = b_Ac[idx - 1] * x_6[0];
            b_Ac_0[1] = b_Ac[idx + 3] * x_6[1];
            b_Ac_0[2] = b_Ac[idx + 7] * x_6[2];
            abs_g(b_Ac_0, AcRow);
            if (!rtIsNaN(AcRow[0])) {
              idx = 1;
            } else {
              idx = 0;
              e_k = 2;
              exitg4 = false;
              while ((!exitg4) && (e_k < 4)) {
                if (!rtIsNaN(AcRow[e_k - 1])) {
                  idx = e_k;
                  exitg4 = true;
                } else {
                  e_k++;
                }
              }
            }

            if (idx == 0) {
              cVal = AcRow[0];
            } else {
              cVal = AcRow[idx - 1];
              while (idx + 1 <= 3) {
                if (cVal < AcRow[idx]) {
                  cVal = AcRow[idx];
                }

                idx++;
              }
            }

            if ((!(cTol[i_h] > cVal)) && (!rtIsNaN(cVal))) {
              cTol[i_h] = cVal;
            }
          }

          if (iA[i_h] == 0) {
            idx = i_h + 1;
            cVal = (((b_Ac[idx - 1] * x_6[0] + b_Ac[idx + 3] * x_6[1]) +
                     b_Ac[idx + 7] * x_6[2]) - b[i_h]) / cTol[i_h];
            if (cVal < cMin) {
              cMin = cVal;
              kNext = static_cast<int16_T>((i_h + 1));
            }
          }
        }

        cTolComputed = true;
        if (kNext <= 0) {
          exitg2 = 1;
        } else {
          do {
            exitg1 = 0;
            if ((kNext > 0) && (static_cast<int32_T>(*status) <= b_maxiter)) {
              guard2 = false;
              if (nA == 0) {
                for (e_k = 0; e_k < 3; e_k++) {
                  AcRow[e_k] = b_Hinv[e_k + 6] * b_Ac[kNext + 7] + (b_Hinv[e_k +
                    3] * b_Ac[kNext + 3] + b_Ac[kNext - 1] * b_Hinv[e_k]);
                }

                guard2 = true;
              } else {
                cMin = KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, b_D, b_H, 3);
                if (cMin <= 0.0) {
                  *status = -2.0;
                  exitg1 = 1;
                } else {
                  for (e_k = 0; e_k < 9; e_k++) {
                    U[e_k] = -b_H[e_k];
                  }

                  for (e_k = 0; e_k < 3; e_k++) {
                    AcRow[e_k] = U[e_k + 6] * b_Ac[kNext + 7] + (U[e_k + 3] *
                      b_Ac[kNext + 3] + b_Ac[kNext - 1] * U[e_k]);
                  }

                  for (i_h = 1; i_h - 1 < nA; i_h++) {
                    e_k = (static_cast<int16_T>(i_h) - 1) * 3;
                    r_1[static_cast<int16_T>(i_h) - 1] = (b_D[e_k + 1] *
                      b_Ac[kNext + 3] + b_D[e_k] * b_Ac[kNext - 1]) + b_D[e_k +
                      2] * b_Ac[kNext + 7];
                  }

                  guard2 = true;
                }
              }

              if (guard2) {
                kDrop = 0;
                cMin = 0.0;
                DualFeasible = true;
                ColdReset = true;
                if (nA > 0) {
                  i_h = 0;
                  exitg4 = false;
                  while ((!exitg4) && (i_h <= nA - 1)) {
                    if (r_1[i_h] >= 1.0E-12) {
                      ColdReset = false;
                      exitg4 = true;
                    } else {
                      i_h++;
                    }
                  }
                }

                if ((nA != 0) && (!ColdReset)) {
                  for (i_h = 1; i_h - 1 < nA; i_h++) {
                    e_k = static_cast<int16_T>(i_h) - 1;
                    if (r_1[e_k] > 1.0E-12) {
                      cVal = lambda[iC[e_k] - 1] / r_1[e_k];
                      if ((kDrop == 0) || (cVal < rMin)) {
                        rMin = cVal;
                        kDrop = static_cast<int16_T>(i_h);
                      }
                    }
                  }

                  if (kDrop > 0) {
                    cMin = rMin;
                    DualFeasible = false;
                  }
                }

                idx = kNext - 1;
                i_h = kNext + 3;
                e_k = kNext + 7;
                cVal = (b_Ac[idx] * AcRow[0] + b_Ac[i_h] * AcRow[1]) + b_Ac[e_k]
                  * AcRow[2];
                if (cVal <= 0.0) {
                  cVal = 0.0;
                  ColdReset = true;
                } else {
                  cVal = (b[idx] - ((b_Ac[idx] * x_6[0] + b_Ac[i_h] * x_6[1]) +
                                    b_Ac[e_k] * x_6[2])) / cVal;
                  ColdReset = false;
                }

                if (DualFeasible && ColdReset) {
                  *status = -1.0;
                  exitg1 = 1;
                } else {
                  if (ColdReset) {
                    t_2 = cMin;
                  } else if (DualFeasible) {
                    t_2 = cVal;
                  } else if ((cMin < cVal) || rtIsNaN(cVal)) {
                    t_2 = cMin;
                  } else {
                    t_2 = cVal;
                  }

                  for (i_h = 1; i_h - 1 < nA; i_h++) {
                    e_k = static_cast<int16_T>(i_h) - 1;
                    lambda_tmp = iC[e_k] - 1;
                    lambda[lambda_tmp] -= r_1[e_k] * t_2;
                    if ((iC[e_k] <= 4) && (lambda[lambda_tmp] < 0.0)) {
                      lambda[lambda_tmp] = 0.0;
                    }
                  }

                  lambda[idx] += t_2;
                  if (t_2 == cMin) {
                    DropConstraint(kDrop, iA, &nA, iC);
                  }

                  if (!ColdReset) {
                    x_6[0] += t_2 * AcRow[0];
                    x_6[1] += t_2 * AcRow[1];
                    x_6[2] += t_2 * AcRow[2];
                    if (t_2 == cVal) {
                      if (nA == 3) {
                        *status = -1.0;
                        exitg1 = 1;
                      } else {
                        e_k = nA + 1;
                        if (e_k > 32767) {
                          e_k = 32767;
                        }

                        nA = static_cast<int16_T>(e_k);
                        iC[static_cast<int16_T>(e_k) - 1] = kNext;
                        kDrop = static_cast<int16_T>(e_k);
                        exitg4 = false;
                        while ((!exitg4) && (kDrop > 1)) {
                          e_k = kDrop - 1;
                          lambda_tmp = kDrop - 2;
                          if (iC[e_k] > iC[lambda_tmp]) {
                            exitg4 = true;
                          } else {
                            kNext = iC[e_k];
                            iC[e_k] = iC[lambda_tmp];
                            iC[lambda_tmp] = kNext;
                            kDrop = static_cast<int16_T>(e_k);
                          }
                        }

                        iA[idx] = 1;
                        kNext = 0;
                        (*status)++;
                      }
                    } else {
                      (*status)++;
                    }
                  } else {
                    (*status)++;
                  }
                }
              }
            } else {
              cMin = norm(x_6);
              if (std::abs(cMin - Xnorm0) > 0.001) {
                Xnorm0 = cMin;
                abs_gt(b, varargin_1);
                if (varargin_1[0] > 1.0) {
                  cTol[0] = varargin_1[0];
                } else {
                  cTol[0] = 1.0;
                }

                if (varargin_1[1] > 1.0) {
                  cTol[1] = varargin_1[1];
                } else {
                  cTol[1] = 1.0;
                }

                if (varargin_1[2] > 1.0) {
                  cTol[2] = varargin_1[2];
                } else {
                  cTol[2] = 1.0;
                }

                if (varargin_1[3] > 1.0) {
                  cTol[3] = varargin_1[3];
                } else {
                  cTol[3] = 1.0;
                }

                cTolComputed = false;
              }

              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = 1;
          }
        }
      } else {
        *status = 0.0;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::mpc_solveQP(const real_T xQP[5],
  const real_T b_Kx[10], const real_T b_Kr[40], const real_T rseq[20], const
  real_T b_Ku1[2], real_T old_u, const real_T b_Kv[44], const real_T vseq[22],
  const real_T b_Kut[20], const real_T b_utarget[10], const real_T b_Linv[9],
  const real_T b_Hinv[9], const real_T b_Ac[12], const real_T Bc[4], boolean_T
  iA[4], real_T zopt[3], real_T f[3], real_T *status)
{
  real_T unusedU0[4];
  int16_T iAnew[4];
  int32_T i_f;
  real_T b_Kx_0;
  real_T b_Kr_0;
  real_T b_Kv_0;
  real_T b_Kut_0;
  int32_T i_g;
  f[0] = 0.0;
  f[1] = 0.0;
  f[2] = 0.0;
  for (i_f = 0; i_f < 2; i_f++) {
    b_Kx_0 = 0.0;
    for (i_g = 0; i_g < 5; i_g++) {
      b_Kx_0 += b_Kx[5 * i_f + i_g] * xQP[i_g];
    }

    b_Kr_0 = 0.0;
    for (i_g = 0; i_g < 20; i_g++) {
      b_Kr_0 += b_Kr[20 * i_f + i_g] * rseq[i_g];
    }

    b_Kv_0 = 0.0;
    for (i_g = 0; i_g < 22; i_g++) {
      b_Kv_0 += b_Kv[22 * i_f + i_g] * vseq[i_g];
    }

    b_Kut_0 = 0.0;
    for (i_g = 0; i_g < 10; i_g++) {
      b_Kut_0 += b_Kut[10 * i_f + i_g] * b_utarget[i_g];
    }

    f[i_f] = (((b_Kx_0 + b_Kr_0) + b_Ku1[i_f] * old_u) + b_Kv_0) + b_Kut_0;
  }

  iAnew[0] = iA[0];
  iAnew[1] = iA[1];
  iAnew[2] = iA[2];
  iAnew[3] = iA[3];
  qpkwik(b_Linv, b_Hinv, f, b_Ac, Bc, iAnew, 120, 1.0E-6, zopt, unusedU0, status);
  iA[0] = (iAnew[0] != 0);
  iA[1] = (iAnew[1] != 0);
  iA[2] = (iAnew[2] != 0);
  iA[3] = (iAnew[3] != 0);
  if ((*status < 0.0) || (*status == 0.0)) {
    zopt[0] = 0.0;
    zopt[1] = 0.0;
    zopt[2] = 0.0;
  }
}

// Function for MATLAB Function: '<S43>/FixedHorizonOptimizer'
void PathFollowingControllerRefMdlModelClass::mpcblock_optimizer(const real_T
  rseq[20], const real_T vseq[22], real_T umin, real_T umax, real_T switch_in,
  const real_T x_1[5], real_T old_u, const boolean_T iA[4], const real_T b_Mlim
  [4], real_T b_Mx[20], real_T b_Mu1[4], real_T b_Mv[88], const real_T
  b_utarget[10], real_T b_uoff, real_T b_enable_value, real_T b_H[9], real_T
  b_Ac[12], const real_T b_Wy[2], const real_T b_Jm[20], const real_T b_I1[10],
  const real_T b_A[25], const real_T Bu[55], const real_T Bv[110], const real_T
  b_C[10], const real_T Dv[44], const real_T b_Mrows[4], real_T *u, real_T useq
  [11], real_T *status, boolean_T iAout[4])
{
  real_T c_Linv[9];
  real_T Bc[4];
  real_T umax_incr;
  real_T umin_incr;
  real_T DelBound;
  real_T c_SuJm[40];
  real_T c_Sx[100];
  real_T c_Su1[20];
  real_T c_Hv[440];
  real_T c_Ku1[2];
  real_T c_Kut[20];
  real_T c_Kx[10];
  real_T c_Kv[44];
  real_T c_Kr[40];
  real_T d_Linv[9];
  real_T zopt[3];
  real_T f[3];
  int32_T i_1;
  real_T tmp[9];
  real_T tmp_0[100];
  real_T tmp_1[20];
  real_T b_Mv_0[4];
  int32_T i_2;
  int32_T i_3;
  int32_T c_Linv_tmp;
  static const real_T b[100] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0 };

  boolean_T exitg1;
  boolean_T guard1 = false;
  std::memset(&useq[0], 0, 11U * sizeof(real_T));
  *status = 1.0;
  iAout[0] = false;
  iAout[1] = false;
  iAout[2] = false;
  iAout[3] = false;
  if (switch_in != b_enable_value) {
    *u = old_u + b_uoff;
    for (i_1 = 0; i_1 < 11; i_1++) {
      useq[i_1] = *u;
    }
  } else {
    mpc_constraintcoef(b_A, Bu, Bv, b_C, Dv, b_Jm, c_SuJm, c_Sx, c_Su1, c_Hv);
    if (b_Mrows[0] > 0.0) {
      i_1 = 0;
      exitg1 = false;
      while ((!exitg1) && (i_1 < 4)) {
        if (b_Mrows[i_1] <= 20.0) {
          c_Linv_tmp = static_cast<int32_T>(b_Mrows[i_1]);
          b_Ac[i_1] = -c_SuJm[c_Linv_tmp - 1];
          b_Ac[i_1 + 4] = -c_SuJm[c_Linv_tmp + 19];
          for (i_2 = 0; i_2 < 5; i_2++) {
            b_Mx[i_1 + (i_2 << 2)] = -c_Sx[(20 * i_2 + c_Linv_tmp) - 1];
          }

          b_Mu1[i_1] = -c_Su1[static_cast<int32_T>(b_Mrows[i_1]) - 1];
          for (i_2 = 0; i_2 < 22; i_2++) {
            b_Mv[i_1 + (i_2 << 2)] = -c_Hv[(20 * i_2 + c_Linv_tmp) - 1];
          }

          i_1++;
        } else if (b_Mrows[i_1] <= 40.0) {
          c_Linv_tmp = static_cast<int32_T>((b_Mrows[i_1] - 20.0));
          b_Ac[i_1] = c_SuJm[c_Linv_tmp - 1];
          b_Ac[i_1 + 4] = c_SuJm[c_Linv_tmp + 19];
          for (i_2 = 0; i_2 < 5; i_2++) {
            b_Mx[i_1 + (i_2 << 2)] = c_Sx[(20 * i_2 + c_Linv_tmp) - 1];
          }

          b_Mu1[i_1] = c_Su1[static_cast<int32_T>((b_Mrows[i_1] - 20.0)) - 1];
          for (i_2 = 0; i_2 < 22; i_2++) {
            b_Mv[i_1 + (i_2 << 2)] = c_Hv[(20 * i_2 + c_Linv_tmp) - 1];
          }

          i_1++;
        } else {
          exitg1 = true;
        }
      }
    }

    kron(b, 1.0, tmp_0);
    for (i_2 = 0; i_2 < 2; i_2++) {
      for (i_1 = 0; i_1 < 10; i_1++) {
        c_Linv_tmp = i_1 + 10 * i_2;
        tmp_1[c_Linv_tmp] = 0.0;
        for (i_3 = 0; i_3 < 10; i_3++) {
          tmp_1[c_Linv_tmp] += tmp_0[10 * i_3 + i_1] * b_Jm[10 * i_2 + i_3];
        }
      }
    }

    mpc_calculatehessian(b_Wy, Wu, Wdu, c_SuJm, tmp_1, b_Jm, b_I1, c_Su1, c_Sx,
                         c_Hv, ny, Bc, c_Ku1, c_Kut, c_Kx, c_Kv, c_Kr);
    b_H[0] = Bc[0];
    b_H[1] = Bc[1];
    b_H[3] = Bc[2];
    b_H[4] = Bc[3];
    std::memcpy(&c_Linv[0], &b_H[0], 9U * sizeof(real_T));
    mpc_checkhessian(c_Linv, d_Linv, &umax_incr);
    if (umax_incr > 1.0) {
      *u = old_u + b_uoff;
      for (i_1 = 0; i_1 < 11; i_1++) {
        useq[i_1] = *u;
      }

      *status = -2.0;
    } else {
      eye_g(tmp);
      linsolve(d_Linv, tmp, c_Linv);
      for (i_2 = 0; i_2 < 4; i_2++) {
        umax_incr = 0.0;
        for (i_1 = 0; i_1 < 5; i_1++) {
          umax_incr += b_Mx[(i_1 << 2) + i_2] * x_1[i_1];
        }

        b_Mv_0[i_2] = 0.0;
        for (i_1 = 0; i_1 < 22; i_1++) {
          b_Mv_0[i_2] += b_Mv[(i_1 << 2) + i_2] * vseq[i_1];
        }

        Bc[i_2] = -(((b_Mlim[i_2] + umax_incr) + b_Mu1[i_2] * old_u) +
                    b_Mv_0[i_2]);
      }

      umax_incr = (rtNaN);
      umin_incr = (rtNaN);
      if (b_Mrows[0] > 0.0) {
        i_1 = 0;
        exitg1 = false;
        while ((!exitg1) && (i_1 < 4)) {
          DelBound = 0.0;
          guard1 = false;
          if ((b_Mrows[i_1] <= 20.0) || (b_Mrows[i_1] <= 40.0)) {
            guard1 = true;
          } else if (b_Mrows[i_1] <= 50.0) {
            if (rtIsNaN(umax_incr)) {
              DelBound = -(umax - b_uoff) - (-b_Mlim[i_1]);
            } else {
              DelBound = umax_incr;
            }

            umax_incr = DelBound;
            guard1 = true;
          } else if (b_Mrows[i_1] <= 60.0) {
            if (rtIsNaN(umin_incr)) {
              DelBound = (umin - b_uoff) - (-b_Mlim[i_1]);
            } else {
              DelBound = umin_incr;
            }

            umin_incr = DelBound;
            guard1 = true;
          } else {
            exitg1 = true;
          }

          if (guard1) {
            Bc[i_1] += DelBound;
            i_1++;
          }
        }
      }

      iAout[0] = iA[0];
      iAout[1] = iA[1];
      iAout[2] = iA[2];
      iAout[3] = iA[3];
      for (i_2 = 0; i_2 < 3; i_2++) {
        for (i_1 = 0; i_1 < 3; i_1++) {
          c_Linv_tmp = i_2 + 3 * i_1;
          d_Linv[c_Linv_tmp] = 0.0;
          d_Linv[c_Linv_tmp] += c_Linv[3 * i_2] * c_Linv[3 * i_1];
          d_Linv[c_Linv_tmp] += c_Linv[3 * i_2 + 1] * c_Linv[3 * i_1 + 1];
          d_Linv[c_Linv_tmp] += c_Linv[3 * i_2 + 2] * c_Linv[3 * i_1 + 2];
        }
      }

      mpc_solveQP(x_1, c_Kx, c_Kr, rseq, c_Ku1, old_u, c_Kv, vseq, c_Kut,
                  b_utarget, c_Linv, d_Linv, b_Ac, Bc, iAout, zopt, f, status);
      *u = (old_u + zopt[0]) + b_uoff;
    }
  }
}

// Model step function
void PathFollowingControllerRefMdlModelClass::step()
{
  real_T Af[16];
  real_T h_0;
  real_T Ai[16];
  int32_T Coef;
  real_T b[16];
  real_T xk[5];
  real_T Bu[55];
  real_T Bv[110];
  real_T Dv[44];
  real_T Dvm[44];
  real_T Cm[110];
  real_T Kinv[4];
  real_T L[10];
  real_T y_innov[2];
  real_T b_A[25];
  real_T b_C[10];
  real_T Qk[25];
  real_T Nk[10];
  real_T b_utarget[10];
  real_T b_myoff[2];
  real_T b_xoff[5];
  real_T rseq[20];
  real_T vseq[22];
  real_T v[2];
  real_T c_A[4];
  real_T b_B[4];
  int32_T r1;
  real_T a22;
  static const real_T c[25] = { 0.59029522013726732, 0.083693736924718917,
    0.081595384470467269, 0.0050186685703353332, 0.0, -0.74954881953164743,
    0.54309372380774523, 0.017801733348590924, 0.076034046986390588, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.5, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const real_T d[30] = { 0.61873334759502352, 0.6900642918472496,
    0.059282882687925628, 0.036786097444293293, 0.0, 0.0, 0.0, -0.00075, -0.001,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T q_0[9] = { 585.85190096706924, 444.68969773152065, 0.0,
    444.68969773152065, 338.89323888417346, 0.0, 0.0, 0.0, 100000.0 };

  real_T rtb_Sum;
  real_T rtb_useq[11];
  real_T rtb_A[16];
  real_T rtb_Saturation;
  real_T rtb_Saturation1;
  real_T L_tmp[25];
  real_T L_tmp_0[10];
  int32_T i_o;
  real_T xk_0[5];
  boolean_T tmp[4];
  real_T tmp_0[20];
  real_T tmp_1[88];
  real_T q_1[9];
  real_T h_1[8];
  real_T d_0[30];
  real_T f[12];
  real_T Af_0[16];
  int8_T tmp_2[6];
  real_T b_a[4];
  int32_T r1_0;
  real_T tmp_3[8];
  real_T Cm_0[10];
  real_T rtb_Saturation_0[2];
  real_T L_tmp_1[25];
  real_T L_tmp_2[25];
  real_T a22_tmp;
  static const int8_T b_a_0[6] = { 1, 0, 0, 1, 0, -1 };

  static const int8_T e[10] = { 0, 0, 0, 0, 2, 0, 0, 10, 0, 1 };

  static const int8_T f_0[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 };

  static const real_T tmp_4[8] = { 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0 };

  static const real_T g_0[2] = { 0.52, 0.01 };

  static const real_T h_2[2] = { 0.5, 0.1 };

  static const real_T i_p[4] = { 41.0, 42.0, 51.0, 52.0 };

  static const real_T t_3[2] = { 1.0, 0.010000000000000002 };

  static const real_T w_0[20] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T s[12] = { -1, -1, 1, 1, 0, -1, 0, 1, 0, 0, 0, 0 };

  // Outputs for Atomic SubSystem: '<Root>/Estimate Lane Center'
  // Constant: '<Root>/Constant1' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant10'
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant5'
  //   Constant: '<Root>/Constant6'
  //   Constant: '<Root>/Constant7'
  //   Constant: '<Root>/Constant8'
  //   Constant: '<Root>/Constant9'

  EstimateLaneCenter(24.605325443786988, 25.150251256281418, 1.0,
                     -0.00095949909848026945, 0.019051146251403757,
                     -0.0032961285439003641, -1.1756433879005408,
                     -6.5071896705004291E-5, 0.00057958146515005879,
                     0.31798008978091707, 0.35861831928869681, &rtb_Sum,
                     &rtb_Sum, &rtb_Saturation, &rtb_Saturation1,
                     &rtConstB.EstimateLaneCenter_a, &rtDW.EstimateLaneCenter_a);

  // End of Outputs for SubSystem: '<Root>/Estimate Lane Center'

  // MATLAB Function: '<S13>/Adaptive Model' incorporates:
  //   Constant: '<Root>/Constant11'
  //   Constant: '<S13>/Sample time constant'
  //   Constant: '<S46>/Cm Constant'

  tmp_2[0] = 1;
  tmp_2[1] = 0;
  tmp_2[2] = 0;
  tmp_2[3] = 0;
  tmp_2[4] = 1;
  tmp_2[5] = 0;
  for (i_o = 0; i_o < 2; i_o++) {
    for (r1 = 0; r1 < 2; r1++) {
      Coef = i_o + (r1 << 1);
      b_a[Coef] = 0.0;
      b_a[Coef] += static_cast<real_T>((tmp_2[3 * r1] * b_a_0[i_o]));
      b_a[Coef] += static_cast<real_T>((tmp_2[3 * r1 + 1] * b_a_0[i_o + 2]));
      b_a[Coef] += static_cast<real_T>((tmp_2[3 * r1 + 2] * b_a_0[i_o + 4]));
      Af[r1 + (i_o << 2)] = rtConstB.Am[(i_o << 1) + r1];
      Af[r1 + ((i_o + 2) << 2)] = 0.0;
    }
  }

  Af[10] = 0.0;
  Af[14] = 1.0;
  Af[2] = b_a[0];
  Af[3] = b_a[1];
  Af[11] = 0.0;
  Af[6] = b_a[2];
  Af[7] = b_a[3];
  Af[15] = 0.0;
  for (i_o = 0; i_o < 16; i_o++) {
    Af_0[i_o] = Af[i_o] * 0.1;
  }

  expm(Af_0, rtb_A);
  std::memset(&Ai[0], 0, sizeof(real_T) << 4U);
  Ai[0] = 1.0;
  Ai[5] = 1.0;
  Ai[10] = 1.0;
  Ai[15] = 1.0;
  for (i_o = 0; i_o < 16; i_o++) {
    Ai[i_o] += rtb_A[i_o];
  }

  Coef = 2;
  for (r1 = 0; r1 < 3; r1++) {
    if (Coef == 2) {
      Coef = 4;
    } else {
      Coef = 2;
    }

    r1_0 = r1 + 1;
    for (i_o = 0; i_o < 16; i_o++) {
      Af_0[i_o] = Af[i_o] * static_cast<real_T>(r1_0) * 0.025;
    }

    expm(Af_0, b);
    for (i_o = 0; i_o < 16; i_o++) {
      Ai[i_o] += static_cast<real_T>(Coef) * b[i_o];
    }
  }

  // MATLAB Function: '<S43>/FixedHorizonOptimizer'
  std::memset(&Bu[0], 0, 55U * sizeof(real_T));
  std::memset(&Bv[0], 0, 110U * sizeof(real_T));
  std::memset(&Dv[0], 0, 44U * sizeof(real_T));
  std::memset(&Dvm[0], 0, 44U * sizeof(real_T));
  std::memset(&Cm[0], 0, 110U * sizeof(real_T));
  std::memcpy(&b_A[0], &c[0], 25U * sizeof(real_T));
  for (i_o = 0; i_o < 10; i_o++) {
    b_C[i_o] = e[i_o];
  }

  // MATLAB Function: '<S13>/Adaptive Model' incorporates:
  //   SignalConversion generated from: '<S45>/ SFunction '

  tmp_3[0] = rtConstB.b1;
  tmp_3[1] = rtConstB.b2;
  tmp_3[4] = 0.0;
  tmp_3[5] = 0.0;
  tmp_3[2] = 0.0;
  tmp_3[3] = 0.0;
  tmp_3[6] = 0.0;
  tmp_3[7] = -1.0;
  for (i_o = 0; i_o < 2; i_o++) {
    for (r1 = 0; r1 < 4; r1++) {
      Coef = i_o << 2;
      r1_0 = r1 + Coef;
      h_1[r1_0] = 0.0;
      h_1[r1_0] += 0.0083333333333333332 * Ai[r1] * tmp_3[Coef];
      h_1[r1_0] += Ai[r1 + 4] * 0.0083333333333333332 * tmp_3[Coef + 1];
      h_1[r1_0] += Ai[r1 + 8] * 0.0083333333333333332 * 0.0;
      h_1[r1_0] += Ai[r1 + 12] * 0.0083333333333333332 * tmp_3[Coef + 3];
    }
  }

  c_A[0] = 0.0;
  c_A[1] = 0.0;
  c_A[2] = 0.0;
  c_A[3] = 0.0;

  // MATLAB Function: '<S43>/FixedHorizonOptimizer' incorporates:
  //   Constant: '<S11>/Reference constant'
  //   Constant: '<S13>/DX Constant'
  //   Constant: '<S13>/U Constant'
  //   Constant: '<S13>/X Constant'
  //   Constant: '<S13>/Y Constant'
  //   MATLAB Function: '<S13>/Adaptive Model'
  //   Memory: '<S15>/LastPcov'
  //   Memory: '<S15>/last_x'
  //   Product: '<S13>/Product'

  std::memcpy(&d_0[0], &d[0], 30U * sizeof(real_T));
  for (i_o = 0; i_o < 12; i_o++) {
    f[i_o] = f_0[i_o];
  }

  rtb_Saturation_0[0] = 1.0;
  rtb_Saturation_0[1] = 2.0;
  mpc_plantupdate(rtb_A, h_1, tmp_4, c_A, b_A, d_0, b_C, f, rtb_Saturation_0,
                  g_0, h_2, &Bu[0], b_utarget, L, &Dv[0], b_a, Qk, Kinv, Nk);
  for (i_o = 0; i_o < 2; i_o++) {
    for (r1 = 0; r1 < 5; r1++) {
      Bv[r1 + 5 * i_o] = b_utarget[5 * i_o + r1];
    }
  }

  for (i_o = 0; i_o < 5; i_o++) {
    r1 = i_o << 1;
    Cm[r1] = L[r1];
    r1++;
    Cm[r1] = L[r1];
  }

  Dvm[0] = b_a[0];
  Dvm[1] = b_a[1];
  Dvm[2] = b_a[2];
  Dvm[3] = b_a[3];
  b_a[0] = 0.5;
  b_a[1] = 0.5;
  b_a[2] = 0.5;
  b_a[3] = 0.5;
  std::memset(&b_utarget[0], 0, 10U * sizeof(real_T));
  for (i_o = 0; i_o < 5; i_o++) {
    b_xoff[i_o] = 0.0;
  }

  rtb_Saturation_0[0] = 0.0;
  v[0] = 1.0;
  rtb_Saturation_0[1] = 0.0;
  v[1] = 2.0;
  mpc_updateFromNominal(b_a, i_p, rtConstP.pooled10, g_0, b_utarget,
                        rtConstP.pooled10, h_2, rtb_Saturation_0, v,
                        rtConstP.pooled11, b_xoff, rtConstP.pooled11, Bv, &h_0,
                        &a22, y_innov, b_myoff);
  rtb_Saturation_0[0] = 2.0;
  rtb_Saturation_0[1] = 10.0;
  mpcblock_refmd(rtConstP.pooled10, rtb_Sum, y_innov, a22, rtb_Saturation_0,
                 RMDscale, rseq, vseq, v);
  eye(c_A);
  for (i_o = 0; i_o < 2; i_o++) {
    for (r1 = 0; r1 < 5; r1++) {
      r1_0 = (r1 << 1) + i_o;
      L[r1 + 5 * i_o] = Cm[r1_0];
      Cm_0[r1_0] = 0.0;
      for (Coef = 0; Coef < 5; Coef++) {
        Cm_0[r1_0] += Cm[(Coef << 1) + i_o] * rtDW.LastPcov_PreviousInput[5 * r1
          + Coef];
      }
    }
  }

  for (i_o = 0; i_o < 2; i_o++) {
    for (r1 = 0; r1 < 2; r1++) {
      rtb_Sum = 0.0;
      for (Coef = 0; Coef < 5; Coef++) {
        rtb_Sum += Cm_0[(Coef << 1) + r1] * L[5 * i_o + Coef];
      }

      Coef = (i_o << 1) + r1;
      b_B[Coef] = Kinv[Coef] + rtb_Sum;
    }
  }

  if (std::abs(b_B[1]) > std::abs(b_B[0])) {
    r1 = 1;
    Coef = 0;
  } else {
    r1 = 0;
    Coef = 1;
  }

  rtb_Sum = b_B[Coef] / b_B[r1];
  a22_tmp = b_B[r1 + 2];
  a22 = b_B[Coef + 2] - a22_tmp * rtb_Sum;
  i_o = r1 << 1;
  Kinv[i_o] = c_A[0] / b_B[r1];
  Coef <<= 1;
  Kinv[Coef] = (c_A[2] - Kinv[i_o] * a22_tmp) / a22;
  Kinv[i_o] -= Kinv[Coef] * rtb_Sum;
  i_o++;
  Kinv[i_o] = c_A[1] / b_B[r1];
  Coef++;
  Kinv[Coef] = (c_A[3] - Kinv[i_o] * a22_tmp) / a22;
  Kinv[i_o] -= Kinv[Coef] * rtb_Sum;
  for (i_o = 0; i_o < 5; i_o++) {
    for (r1 = 0; r1 < 5; r1++) {
      r1_0 = i_o + 5 * r1;
      L_tmp[r1_0] = 0.0;
      for (Coef = 0; Coef < 5; Coef++) {
        L_tmp[r1_0] += b_A[5 * Coef + i_o] * rtDW.LastPcov_PreviousInput[5 * r1
          + Coef];
      }
    }

    for (r1 = 0; r1 < 2; r1++) {
      rtb_Sum = 0.0;
      for (Coef = 0; Coef < 5; Coef++) {
        rtb_Sum += L_tmp[5 * Coef + i_o] * L[5 * r1 + Coef];
      }

      r1_0 = 5 * r1 + i_o;
      L_tmp_0[r1_0] = Nk[r1_0] + rtb_Sum;
    }
  }

  for (i_o = 0; i_o < 5; i_o++) {
    L[i_o] = 0.0;
    L[i_o] += L_tmp_0[i_o] * Kinv[0];
    rtb_Sum = L_tmp_0[i_o + 5];
    L[i_o] += rtb_Sum * Kinv[1];
    L[i_o + 5] = 0.0;
    L[i_o + 5] += L_tmp_0[i_o] * Kinv[2];
    L[i_o + 5] += rtb_Sum * Kinv[3];
    xk[i_o] = (rtDW.last_x_PreviousInput[i_o] - b_xoff[i_o]) + Bu[i_o] * 0.0;
  }

  // SignalConversion generated from: '<S44>/ SFunction ' incorporates:
  //   MATLAB Function: '<S43>/FixedHorizonOptimizer'

  rtb_Saturation_0[0] = rtb_Saturation * 2.0 - b_myoff[0];
  rtb_Saturation_0[1] = rtb_Saturation1 * 10.0 - b_myoff[1];

  // MATLAB Function: '<S43>/FixedHorizonOptimizer' incorporates:
  //   Memory: '<S15>/LastPcov'

  for (i_o = 0; i_o < 2; i_o++) {
    b_myoff[i_o] = 0.0;
    for (r1 = 0; r1 < 5; r1++) {
      b_myoff[i_o] += Cm[(r1 << 1) + i_o] * xk[r1];
    }

    y_innov[i_o] = rtb_Saturation_0[i_o] - (b_myoff[i_o] + (Dvm[i_o + 2] * v[1]
      + Dvm[i_o] * v[0]));
  }

  for (i_o = 0; i_o < 5; i_o++) {
    for (r1 = 0; r1 < 2; r1++) {
      Coef = i_o + 5 * r1;
      Nk[Coef] = 0.0;
      for (r1_0 = 0; r1_0 < 5; r1_0++) {
        Nk[Coef] += rtDW.LastPcov_PreviousInput[5 * r1_0 + i_o] * Cm[(r1_0 << 1)
          + r1];
      }
    }

    Cm_0[i_o] = 0.0;
    Cm_0[i_o] += Nk[i_o] * Kinv[0];
    rtb_Sum = Nk[i_o + 5];
    Cm_0[i_o] += rtb_Sum * Kinv[1];
    rtb_Saturation = Cm_0[i_o] * y_innov[0];
    Cm_0[i_o + 5] = 0.0;
    Cm_0[i_o + 5] += Nk[i_o] * Kinv[2];
    Cm_0[i_o + 5] += rtb_Sum * Kinv[3];
    rtb_Saturation += Cm_0[i_o + 5] * y_innov[1];
    xk_0[i_o] = xk[i_o] + rtb_Saturation;
  }

  // Memory: '<S15>/Memory'
  tmp[0] = rtDW.Memory_PreviousInput[0];
  tmp[1] = rtDW.Memory_PreviousInput[1];
  tmp[2] = rtDW.Memory_PreviousInput[2];
  tmp[3] = rtDW.Memory_PreviousInput[3];

  // MATLAB Function: '<S43>/FixedHorizonOptimizer'
  std::memset(&tmp_0[0], 0, 20U * sizeof(real_T));
  for (i_o = 0; i_o < 10; i_o++) {
    Nk[i_o] = 1.0;
  }

  std::memset(&tmp_0[0], 0, 20U * sizeof(real_T));
  Kinv[0] = -1.0;
  Kinv[1] = -1.0;
  Kinv[2] = 1.0;
  Kinv[3] = 1.0;
  std::memset(&tmp_1[0], 0, 88U * sizeof(real_T));
  std::memcpy(&q_1[0], &q_0[0], 9U * sizeof(real_T));
  for (i_o = 0; i_o < 12; i_o++) {
    f[i_o] = s[i_o];
  }

  // Update for Memory: '<S15>/Memory' incorporates:
  //   Constant: '<S10>/Maximum steering angle constant'
  //   Constant: '<S10>/Minimum steering angle constant'
  //   Gain: '<S15>/umax_scale'
  //   Gain: '<S15>/umin_scale'
  //   MATLAB Function: '<S43>/FixedHorizonOptimizer'
  //   UnitDelay: '<S15>/last_mv'

  mpcblock_optimizer(rseq, vseq, -0.5, 0.5, 0.0, xk_0, rtDW.last_mv_DSTATE - h_0,
                     tmp, b_a, tmp_0, Kinv, tmp_1, b_utarget, h_0, enable_value,
                     q_1, f, t_3, w_0, Nk, b_A, Bu, Bv, b_C, Dv, i_p,
                     &rtb_Saturation, rtb_useq, &rtb_Saturation1,
                     rtDW.Memory_PreviousInput);

  // MATLAB Function: '<S43>/FixedHorizonOptimizer'
  rtb_Saturation1 = rtb_Saturation - h_0;
  for (i_o = 0; i_o < 5; i_o++) {
    for (r1 = 0; r1 < 5; r1++) {
      r1_0 = i_o + 5 * r1;
      L_tmp_1[r1_0] = 0.0;
      for (Coef = 0; Coef < 5; Coef++) {
        L_tmp_1[r1_0] += L_tmp[5 * Coef + i_o] * b_A[5 * Coef + r1];
      }

      L_tmp_2[r1_0] = 0.0;
      L_tmp_2[r1_0] += L_tmp_0[i_o] * L[r1];
      L_tmp_2[r1_0] += L_tmp_0[i_o + 5] * L[r1 + 5];
    }
  }

  for (i_o = 0; i_o < 25; i_o++) {
    L_tmp[i_o] = (L_tmp_1[i_o] - L_tmp_2[i_o]) + Qk[i_o];
  }

  // Assertion: '<S12>/Assertion'
  utAssert(true);

  // Update for UnitDelay: '<S15>/last_mv' incorporates:
  //   MATLAB Function: '<S43>/FixedHorizonOptimizer'

  rtDW.last_mv_DSTATE = rtb_Saturation;
  for (i_o = 0; i_o < 5; i_o++) {
    // MATLAB Function: '<S43>/FixedHorizonOptimizer'
    rtb_Sum = 0.0;
    for (r1 = 0; r1 < 5; r1++) {
      // MATLAB Function: '<S43>/FixedHorizonOptimizer'
      Coef = 5 * i_o + r1;
      r1_0 = 5 * r1 + i_o;

      // Update for Memory: '<S15>/LastPcov' incorporates:
      //   MATLAB Function: '<S43>/FixedHorizonOptimizer'

      rtDW.LastPcov_PreviousInput[Coef] = (L_tmp[Coef] + L_tmp[r1_0]) * 0.5;

      // MATLAB Function: '<S43>/FixedHorizonOptimizer'
      rtb_Sum += b_A[r1_0] * xk[r1];
    }

    // Update for Memory: '<S15>/last_x' incorporates:
    //   MATLAB Function: '<S43>/FixedHorizonOptimizer'

    rtDW.last_x_PreviousInput[i_o] = (((Bu[i_o] * rtb_Saturation1 + rtb_Sum) +
      (Bv[i_o + 5] * v[1] + Bv[i_o] * v[0])) + (L[i_o + 5] * y_innov[1] + L[i_o]
      * y_innov[0])) + b_xoff[i_o];
  }
}

// Model initialize function
void PathFollowingControllerRefMdlModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // InitializeConditions for Memory: '<S15>/LastPcov'
  std::memcpy(&rtDW.LastPcov_PreviousInput[0],
              &rtConstP.LastPcov_InitialCondition[0], 25U * sizeof(real_T));
}

// Constructor
PathFollowingControllerRefMdlModelClass::PathFollowingControllerRefMdlModelClass
  () : rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
PathFollowingControllerRefMdlModelClass::
  ~PathFollowingControllerRefMdlModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL * PathFollowingControllerRefMdlModelClass::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
