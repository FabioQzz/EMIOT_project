/*
 * Code generation for system model 'Eq7_CyclesLoss'
 * For more details, see corresponding source file Eq7_CyclesLoss.c
 *
 */

#ifndef RTW_HEADER_Eq7_CyclesLoss_h_
#define RTW_HEADER_Eq7_CyclesLoss_h_
#ifndef Eq7_CyclesLoss_COMMON_INCLUDES_
#define Eq7_CyclesLoss_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Eq7_CyclesLoss_COMMON_INCLUDES_ */

#include "Eq7_CyclesLoss_types.h"
#include <string.h>

/* Block signals for model 'Eq7_CyclesLoss' */
typedef struct {
  real_T Square;                       /* '<Root>/Square' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Product;                      /* '<Root>/Product' */
  real_T Product1;                     /* '<Root>/Product1' */
} B_Eq7_CyclesLoss_c_T;

/* Parameters (default storage) */
struct P_Eq7_CyclesLoss_T_ {
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Eq7_CyclesLoss_T {
  const char_T **errorStatus;
};

typedef struct {
  B_Eq7_CyclesLoss_c_T rtb;
  RT_MODEL_Eq7_CyclesLoss_T rtm;
} MdlrefDW_Eq7_CyclesLoss_T;

/* Model reference registration function */
extern void Eq7_CyclesLoss_initialize(const char_T **rt_errorStatus,
  RT_MODEL_Eq7_CyclesLoss_T *const Eq7_CyclesLoss_M, B_Eq7_CyclesLoss_c_T
  *localB);
extern void Eq7_CyclesLoss(const real_T *rtu_N, const real_T *rtu_k1, const
  real_T *rtu_k2, real_T *rty_CycleLosses, B_Eq7_CyclesLoss_c_T *localB);

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
 * '<Root>' : 'Eq7_CyclesLoss'
 */
#endif                                 /* RTW_HEADER_Eq7_CyclesLoss_h_ */
