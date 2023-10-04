/*
 * Code generation for system model 'Eq4_CapacityCorrectionFactor'
 * For more details, see corresponding source file Eq4_CapacityCorrectionFactor.c
 *
 */

#ifndef RTW_HEADER_Eq4_CapacityCorrectionFactor_h_
#define RTW_HEADER_Eq4_CapacityCorrectionFactor_h_
#ifndef Eq4_CapacityCorrectionFactor_COMMON_INCLUDES_
#define Eq4_CapacityCorrectionFactor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                       /* Eq4_CapacityCorrectionFactor_COMMON_INCLUDES_ */

#include "Eq4_CapacityCorrectionFactor_types.h"
#include "Eq6_StorageLoss.h"
#include "Eq7_8_k1k2k3Linearization.h"
#include "Eq7_CyclesLoss.h"
#include <string.h>

/* Block signals for model 'Eq4_CapacityCorrectionFactor' */
typedef struct {
  real_T Model;                        /* '<Root>/Model' */
  real_T Model2_o1;                    /* '<Root>/Model2' */
  real_T Model2_o2;                    /* '<Root>/Model2' */
  real_T Model2_o3;                    /* '<Root>/Model2' */
  real_T Model1;                       /* '<Root>/Model1' */
  real_T Add;                          /* '<Root>/Add' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T Sqrt;                         /* '<Root>/Sqrt' */
} B_Eq4_CapacityCorrectionFac_c_T;

/* Block states (default storage) for model 'Eq4_CapacityCorrectionFactor' */
typedef struct {
  MdlrefDW_Eq6_StorageLoss_T Model_InstanceData;/* '<Root>/Model' */
  MdlrefDW_Eq7_8_k1k2k3Lineariz_T Model2_InstanceData;/* '<Root>/Model2' */
  MdlrefDW_Eq7_CyclesLoss_T Model1_InstanceData;/* '<Root>/Model1' */
} DW_Eq4_CapacityCorrectionFa_f_T;

/* Parameters (default storage) */
struct P_Eq4_CapacityCorrectionFacto_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant4_Value;              /* Expression: -0.2118
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.0102
                                        * Referenced by: '<Root>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Eq4_CapacityCorrectio_T {
  const char_T **errorStatus;
};

typedef struct {
  B_Eq4_CapacityCorrectionFac_c_T rtb;
  DW_Eq4_CapacityCorrectionFa_f_T rtdw;
  RT_MODEL_Eq4_CapacityCorrecti_T rtm;
} MdlrefDW_Eq4_CapacityCorrecti_T;

/* Model reference registration function */
extern void Eq4_CapacityCorrecti_initialize(const char_T **rt_errorStatus,
  RT_MODEL_Eq4_CapacityCorrecti_T *const Eq4_CapacityCorrectionFactor_M,
  B_Eq4_CapacityCorrectionFac_c_T *localB, DW_Eq4_CapacityCorrectionFa_f_T
  *localDW);
extern void Eq4_CapacityCorrectionFactor(const real_T *rtu_StorageTime, const
  real_T *rtu_Temperature, const real_T *rtu_CycleNumber, real_T *rty_CCF,
  real_T *rty_RCycle, real_T *rty_Potentialvariationduetotemp,
  B_Eq4_CapacityCorrectionFac_c_T *localB, DW_Eq4_CapacityCorrectionFa_f_T
  *localDW);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 */

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
 * '<Root>' : 'Eq4_CapacityCorrectionFactor'
 */
#endif                          /* RTW_HEADER_Eq4_CapacityCorrectionFactor_h_ */
