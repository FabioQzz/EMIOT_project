/*
 * Code generation for system model 'Eq7_8_k1k2k3Linearization'
 * For more details, see corresponding source file Eq7_8_k1k2k3Linearization.c
 *
 */

#ifndef RTW_HEADER_Eq7_8_k1k2k3Linearization_h_
#define RTW_HEADER_Eq7_8_k1k2k3Linearization_h_
#ifndef Eq7_8_k1k2k3Linearization_COMMON_INCLUDES_
#define Eq7_8_k1k2k3Linearization_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                          /* Eq7_8_k1k2k3Linearization_COMMON_INCLUDES_ */

#include "Eq7_8_k1k2k3Linearization_types.h"
#include <string.h>

/* Block signals for model 'Eq7_8_k1k2k3Linearization' */
typedef struct {
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Gain2;                        /* '<Root>/Gain2' */
} B_Eq7_8_k1k2k3Linearization_c_T;

/* Parameters (default storage) */
struct P_Eq7_8_k1k2k3Linearization_T_ {
  real_T Gain_Gain;                    /* Expression: 6.0600e-08
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: -1.4300e-06
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1.6000e-06
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant1_Value;              /* Expression: 2.1000e-04
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 8.0000e-06
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Constant2_Value;              /* Expression: 0.0013
                                        * Referenced by: '<Root>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Eq7_8_k1k2k3Lineariza_T {
  const char_T **errorStatus;
};

typedef struct {
  B_Eq7_8_k1k2k3Linearization_c_T rtb;
  RT_MODEL_Eq7_8_k1k2k3Lineariz_T rtm;
} MdlrefDW_Eq7_8_k1k2k3Lineariz_T;

/* Model reference registration function */
extern void Eq7_8_k1k2k3Lineariz_initialize(const char_T **rt_errorStatus,
  RT_MODEL_Eq7_8_k1k2k3Lineariz_T *const Eq7_8_k1k2k3Linearization_M,
  B_Eq7_8_k1k2k3Linearization_c_T *localB);
extern void Eq7_8_k1k2k3Linearization(const real_T *rtu_Temperature, real_T
  *rty_k1, real_T *rty_k2, real_T *rty_k3, B_Eq7_8_k1k2k3Linearization_c_T
  *localB);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Eq7_8_k1k2k3Linearization'
 */
#endif                             /* RTW_HEADER_Eq7_8_k1k2k3Linearization_h_ */
