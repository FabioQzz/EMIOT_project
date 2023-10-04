/*
 * Code generation for system model 'Eq6_StorageLoss'
 * For more details, see corresponding source file Eq6_StorageLoss.c
 *
 */

#ifndef RTW_HEADER_Eq6_StorageLoss_h_
#define RTW_HEADER_Eq6_StorageLoss_h_
#ifndef Eq6_StorageLoss_COMMON_INCLUDES_
#define Eq6_StorageLoss_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Eq6_StorageLoss_COMMON_INCLUDES_ */

#include "Eq6_StorageLoss_types.h"
#include <string.h>

/* Block signals for model 'Eq6_StorageLoss' */
typedef struct {
  real_T CtoK;                         /* '<Root>/°C to K' */
  real_T Product;                      /* '<Root>/Product' */
  real_T Divide;                       /* '<Root>/Divide' */
  real_T MathFunction;                 /* '<Root>/Math Function' */
  real_T Product1;                     /* '<Root>/Product1' */
  real_T Product2;                     /* '<Root>/Product2' */
} B_Eq6_StorageLoss_c_T;

/* Parameters (default storage) */
struct P_Eq6_StorageLoss_T_ {
  real_T Constant_Value;               /* Expression: 8.3143
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: -40498
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 1.544e7
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 273.15
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.01
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Eq6_StorageLoss_T {
  const char_T **errorStatus;
};

typedef struct {
  B_Eq6_StorageLoss_c_T rtb;
  RT_MODEL_Eq6_StorageLoss_T rtm;
} MdlrefDW_Eq6_StorageLoss_T;

/* Model reference registration function */
extern void Eq6_StorageLoss_initialize(const char_T **rt_errorStatus,
  RT_MODEL_Eq6_StorageLoss_T *const Eq6_StorageLoss_M, B_Eq6_StorageLoss_c_T
  *localB);
extern void Eq6_StorageLoss(const real_T *rtu_StorageTime, const real_T
  *rtu_Temperature, real_T *rty_StorageLoss, B_Eq6_StorageLoss_c_T *localB);

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
 * '<Root>' : 'Eq6_StorageLoss'
 */
#endif                                 /* RTW_HEADER_Eq6_StorageLoss_h_ */
