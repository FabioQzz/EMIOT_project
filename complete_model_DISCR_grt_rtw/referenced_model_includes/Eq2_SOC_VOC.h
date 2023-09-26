/*
 * Code generation for system model 'Eq2_SOC_VOC'
 * For more details, see corresponding source file Eq2_SOC_VOC.c
 *
 */

#ifndef RTW_HEADER_Eq2_SOC_VOC_h_
#define RTW_HEADER_Eq2_SOC_VOC_h_
#ifndef Eq2_SOC_VOC_COMMON_INCLUDES_
#define Eq2_SOC_VOC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Eq2_SOC_VOC_COMMON_INCLUDES_ */

#include "Eq2_SOC_VOC_types.h"
#include <string.h>

/* Block signals for model 'Eq2_SOC_VOC' */
typedef struct {
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Exp;                          /* '<Root>/Exp' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Add;                          /* '<Root>/Add' */
  real_T Square;                       /* '<Root>/Square' */
  real_T Gain3;                        /* '<Root>/Gain3' */
  real_T Square1;                      /* '<Root>/Square1' */
  real_T Product;                      /* '<Root>/Product' */
  real_T Gain4;                        /* '<Root>/Gain4' */
} B_Eq2_SOC_VOC_c_T;

/* Parameters (default storage) */
struct P_Eq2_SOC_VOC_T_ {
  real_T Gain2_Gain;                   /* Expression: 0.2156
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain_Gain;                    /* Expression: -35
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1.031
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant_Value;               /* Expression: 3.685
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain3_Gain;                   /* Expression: -0.1178
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 0.321
                                        * Referenced by: '<Root>/Gain4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Eq2_SOC_VOC_T {
  const char_T **errorStatus;
};

typedef struct {
  B_Eq2_SOC_VOC_c_T rtb;
  RT_MODEL_Eq2_SOC_VOC_T rtm;
} MdlrefDW_Eq2_SOC_VOC_T;

/* Model reference registration function */
extern void Eq2_SOC_VOC_initialize(const char_T **rt_errorStatus,
  RT_MODEL_Eq2_SOC_VOC_T *const Eq2_SOC_VOC_M, B_Eq2_SOC_VOC_c_T *localB);
extern void Eq2_SOC_VOC(const real_T *rtu_SOC, real_T *rty_Voc,
  B_Eq2_SOC_VOC_c_T *localB);

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
 * '<Root>' : 'Eq2_SOC_VOC'
 */
#endif                                 /* RTW_HEADER_Eq2_SOC_VOC_h_ */
