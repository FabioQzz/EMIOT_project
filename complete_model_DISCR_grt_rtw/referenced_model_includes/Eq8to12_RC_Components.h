/*
 * Code generation for system model 'Eq8to12_RC_Components'
 * For more details, see corresponding source file Eq8to12_RC_Components.c
 *
 */

#ifndef RTW_HEADER_Eq8to12_RC_Components_h_
#define RTW_HEADER_Eq8to12_RC_Components_h_
#ifndef Eq8to12_RC_Components_COMMON_INCLUDES_
#define Eq8to12_RC_Components_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                              /* Eq8to12_RC_Components_COMMON_INCLUDES_ */

#include "Eq8to12_RC_Components_types.h"
#include <string.h>

/* Block signals for model 'Eq8to12_RC_Components' */
typedef struct {
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T MathFunction1;                /* '<Root>/Math Function1' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Gain9;                        /* '<Root>/Gain9' */
  real_T MathFunction5;                /* '<Root>/Math Function5' */
  real_T Gain10;                       /* '<Root>/Gain10' */
  real_T Gain3;                        /* '<Root>/Gain3' */
  real_T MathFunction2;                /* '<Root>/Math Function2' */
  real_T Gain4;                        /* '<Root>/Gain4' */
  real_T Gain5;                        /* '<Root>/Gain5' */
  real_T MathFunction3;                /* '<Root>/Math Function3' */
  real_T Gain6;                        /* '<Root>/Gain6' */
  real_T Gain7;                        /* '<Root>/Gain7' */
  real_T MathFunction4;                /* '<Root>/Math Function4' */
  real_T Gain8;                        /* '<Root>/Gain8' */
} B_Eq8to12_RC_Components_c_T;

/* Parameters (default storage) */
struct P_Eq8to12_RC_Components_T_ {
  real_T Constant1_Value;              /* Expression: 0.07446
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -24.37
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.1562
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Constant5_Value;              /* Expression: 4475
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Gain9_Gain;                   /* Expression: -27.12
                                        * Referenced by: '<Root>/Gain9'
                                        */
  real_T Gain10_Gain;                  /* Expression: -6056
                                        * Referenced by: '<Root>/Gain10'
                                        */
  real_T Constant2_Value;              /* Expression: 0.04669
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain3_Gain;                   /* Expression: -29.14
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 0.3208
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Constant3_Value;              /* Expression: 703.6
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Gain5_Gain;                   /* Expression: -13.51
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Gain6_Gain;                   /* Expression: 752.9
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T Constant4_Value;              /* Expression: 0.04984
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Gain7_Gain;                   /* Expression: -155.2
                                        * Referenced by: '<Root>/Gain7'
                                        */
  real_T Gain8_Gain;                   /* Expression: 6.603
                                        * Referenced by: '<Root>/Gain8'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Eq8to12_RC_Components_T {
  const char_T **errorStatus;
};

typedef struct {
  B_Eq8to12_RC_Components_c_T rtb;
  RT_MODEL_Eq8to12_RC_Component_T rtm;
} MdlrefDW_Eq8to12_RC_Component_T;

/* Model reference registration function */
extern void Eq8to12_RC_Component_initialize(const char_T **rt_errorStatus,
  RT_MODEL_Eq8to12_RC_Component_T *const Eq8to12_RC_Components_M,
  B_Eq8to12_RC_Components_c_T *localB);
extern void Eq8to12_RC_Components(const real_T *rtu_SOC, real_T *rty_RSeries,
  real_T *rty_RTransientS, real_T *rty_CTransientS, real_T *rty_RTransientL,
  real_T *rty_CTransientL, B_Eq8to12_RC_Components_c_T *localB);

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
 * '<Root>' : 'Eq8to12_RC_Components'
 */
#endif                                 /* RTW_HEADER_Eq8to12_RC_Components_h_ */
