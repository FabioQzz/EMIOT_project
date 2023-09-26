/*
 * Code generation for system model 'Eq_Zeq_circuit'
 * For more details, see corresponding source file Eq_Zeq_circuit.c
 *
 */

#ifndef RTW_HEADER_Eq_Zeq_circuit_h_
#define RTW_HEADER_Eq_Zeq_circuit_h_
#ifndef Eq_Zeq_circuit_COMMON_INCLUDES_
#define Eq_Zeq_circuit_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "nesl_rtw.h"
#include "Eq_Zeq_circuit_a13582f8_1_gateway.h"
#endif                                 /* Eq_Zeq_circuit_COMMON_INCLUDES_ */

#include "Eq_Zeq_circuit_types.h"
#include "model_reference_types.h"
#include <string.h>

/* Block signals for model 'Eq_Zeq_circuit' */
typedef struct {
  real_T INPUT_1_1_1[4];               /* '<S16>/INPUT_1_1_1' */
  real_T INPUT_2_1_1[4];               /* '<S16>/INPUT_2_1_1' */
  real_T INPUT_3_1_1[4];               /* '<S16>/INPUT_3_1_1' */
  real_T INPUT_4_1_1[4];               /* '<S16>/INPUT_4_1_1' */
  real_T INPUT_5_1_1[4];               /* '<S16>/INPUT_5_1_1' */
  real_T INPUT_6_1_1[4];               /* '<S16>/INPUT_6_1_1' */
  real_T INPUT_7_1_1[4];               /* '<S16>/INPUT_7_1_1' */
  real_T STATE_1[12];                  /* '<S16>/STATE_1' */
  real_T OUTPUT_1_0[4];                /* '<S16>/OUTPUT_1_0' */
} B_Eq_Zeq_circuit_c_T;

/* Block states (default storage) for model 'Eq_Zeq_circuit' */
typedef struct {
  real_T INPUT_1_1_1_Discrete[2];      /* '<S16>/INPUT_1_1_1' */
  real_T INPUT_2_1_1_Discrete[2];      /* '<S16>/INPUT_2_1_1' */
  real_T INPUT_3_1_1_Discrete[2];      /* '<S16>/INPUT_3_1_1' */
  real_T INPUT_4_1_1_Discrete[2];      /* '<S16>/INPUT_4_1_1' */
  real_T INPUT_5_1_1_Discrete[2];      /* '<S16>/INPUT_5_1_1' */
  real_T INPUT_6_1_1_Discrete[2];      /* '<S16>/INPUT_6_1_1' */
  real_T INPUT_7_1_1_Discrete[2];      /* '<S16>/INPUT_7_1_1' */
  real_T STATE_1_Discrete[6];          /* '<S16>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S16>/OUTPUT_1_0' */
  void* STATE_1_Simulator;             /* '<S16>/STATE_1' */
  void* STATE_1_SimData;               /* '<S16>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S16>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S16>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S16>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S16>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S16>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S16>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S16>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S16>/OUTPUT_1_0' */
  int_T STATE_1_Modes[6];              /* '<S16>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S16>/OUTPUT_1_0' */
  boolean_T STATE_1_FirstOutput;       /* '<S16>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S16>/OUTPUT_1_0' */
} DW_Eq_Zeq_circuit_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_Eq_Zeq_circuit_T {
  const char_T **errorStatus;
  const rtTimingBridge *timingBridge;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    int_T mdlref_GlobalTID[1];
  } Timing;
};

typedef struct {
  B_Eq_Zeq_circuit_c_T rtb;
  DW_Eq_Zeq_circuit_f_T rtdw;
  RT_MODEL_Eq_Zeq_circuit_T rtm;
} MdlrefDW_Eq_Zeq_circuit_T;

/* Model reference registration function */
extern void Eq_Zeq_circuit_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, RT_MODEL_Eq_Zeq_circuit_T *
  const Eq_Zeq_circuit_M, B_Eq_Zeq_circuit_c_T *localB, DW_Eq_Zeq_circuit_f_T
  *localDW);
extern void Eq_Zeq_circuit_Init(RT_MODEL_Eq_Zeq_circuit_T * const
  Eq_Zeq_circuit_M, DW_Eq_Zeq_circuit_f_T *localDW);
extern void Eq_Zeq_circuit(RT_MODEL_Eq_Zeq_circuit_T * const Eq_Zeq_circuit_M,
  const real_T *rtu_Current, const real_T *rtu_RSeries, const real_T
  *rtu_RTransientS, const real_T *rtu_CTransientS, const real_T *rtu_RTransientL,
  const real_T *rtu_CTransientL, const real_T *rtu_RCycle, real_T *rty_VOut,
  B_Eq_Zeq_circuit_c_T *localB, DW_Eq_Zeq_circuit_f_T *localDW);
extern void Eq_Zeq_circuit_Term(DW_Eq_Zeq_circuit_f_T *localDW);

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
 * '<Root>' : 'Eq_Zeq_circuit'
 * '<S1>'   : 'Eq_Zeq_circuit/Simulink-PS Converter1'
 * '<S2>'   : 'Eq_Zeq_circuit/Simulink-PS Converter2'
 * '<S3>'   : 'Eq_Zeq_circuit/Simulink-PS Converter3'
 * '<S4>'   : 'Eq_Zeq_circuit/Simulink-PS Converter4'
 * '<S5>'   : 'Eq_Zeq_circuit/Simulink-PS Converter5'
 * '<S6>'   : 'Eq_Zeq_circuit/Simulink-PS Converter6'
 * '<S7>'   : 'Eq_Zeq_circuit/Simulink-PS Converter7'
 * '<S8>'   : 'Eq_Zeq_circuit/Solver Configuration'
 * '<S9>'   : 'Eq_Zeq_circuit/Simulink-PS Converter1/EVAL_KEY'
 * '<S10>'  : 'Eq_Zeq_circuit/Simulink-PS Converter2/EVAL_KEY'
 * '<S11>'  : 'Eq_Zeq_circuit/Simulink-PS Converter3/EVAL_KEY'
 * '<S12>'  : 'Eq_Zeq_circuit/Simulink-PS Converter4/EVAL_KEY'
 * '<S13>'  : 'Eq_Zeq_circuit/Simulink-PS Converter5/EVAL_KEY'
 * '<S14>'  : 'Eq_Zeq_circuit/Simulink-PS Converter6/EVAL_KEY'
 * '<S15>'  : 'Eq_Zeq_circuit/Simulink-PS Converter7/EVAL_KEY'
 * '<S16>'  : 'Eq_Zeq_circuit/Solver Configuration/EVAL_KEY'
 */
#endif                                 /* RTW_HEADER_Eq_Zeq_circuit_h_ */
