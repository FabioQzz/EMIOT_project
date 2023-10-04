/*
 * complete_model_DISCR.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "complete_model_DISCR".
 *
 * Model version              : 2.36
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Sep 26 17:16:03 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_complete_model_DISCR_h_
#define RTW_HEADER_complete_model_DISCR_h_
#ifndef complete_model_DISCR_COMMON_INCLUDES_
#define complete_model_DISCR_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                               /* complete_model_DISCR_COMMON_INCLUDES_ */

#include "complete_model_DISCR_types.h"
#include "Eq2_SOC_VOC.h"
#include "Eq8to12_RC_Components.h"
#include "Eq4_CapacityCorrectionFactor.h"
#include "Eq_Zeq_circuit.h"
#include "model_reference_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T DiscreteTimeIntegrator;       /* '<Root>/Discrete-Time Integrator' */
  real_T Voc;                          /* '<Root>/V oc' */
  real_T Model1_o1;                    /* '<Root>/Model1' */
  real_T Model1_o2;                    /* '<Root>/Model1' */
  real_T Model1_o3;                    /* '<Root>/Model1' */
  real_T Model1_o4;                    /* '<Root>/Model1' */
  real_T Model1_o5;                    /* '<Root>/Model1' */
  real_T DiscreteTimeIntegrator1;      /* '<Root>/Discrete-Time Integrator1' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Model_o2;                     /* '<Root>/Model' */
  real_T Model_o3;                     /* '<Root>/Model' */
  real_T Model2;                       /* '<Root>/Model2' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Product1;                     /* '<Root>/Product1' */
  real_T Divide;                       /* '<Root>/Divide' */
  real_T Abs;                          /* '<Root>/Abs' */
  real_T Gain1;                        /* '<Root>/Gain1' */
} B_complete_model_DISCR_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<Root>/Discrete-Time Integrator1' */
  MdlrefDW_Eq2_SOC_VOC_T Voc_InstanceData;/* '<Root>/V oc' */
  MdlrefDW_Eq8to12_RC_Component_T Model1_InstanceData;/* '<Root>/Model1' */
  MdlrefDW_Eq4_CapacityCorrecti_T Model_InstanceData;/* '<Root>/Model' */
  MdlrefDW_Eq_Zeq_circuit_T Model2_InstanceData;/* '<Root>/Model2' */
} DW_complete_model_DISCR_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T CurrentA;                     /* '<Root>/Current [A]' */
  real_T BattCapAh;                    /* '<Root>/Batt Cap [Ah]' */
  real_T StorageTime;                  /* '<Root>/Storage Time' */
  real_T Temperature;                  /* '<Root>/Temperature' */
  real_T CycleNumber;                  /* '<Root>/Cycle Number' */
  real_T InitialSoC;                   /* '<Root>/Initial SoC [%]' */
} ExtU_complete_model_DISCR_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Vbattery;                     /* '<Root>/V battery' */
  real_T CCF;                          /* '<Root>/CCF' */
  real_T SoC;                          /* '<Root>/SoC' */
} ExtY_complete_model_DISCR_T;

/* Parameters (default storage) */
struct P_complete_model_DISCR_T_ {
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator1'
                                        */
  real_T Gain_Gain;                    /* Expression: 3600
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_complete_model_DISCR_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_complete_model_DISCR_T complete_model_DISCR_P;

/* Block signals (default storage) */
extern B_complete_model_DISCR_T complete_model_DISCR_B;

/* Block states (default storage) */
extern DW_complete_model_DISCR_T complete_model_DISCR_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_complete_model_DISCR_T complete_model_DISCR_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_complete_model_DISCR_T complete_model_DISCR_Y;

/* Model entry point functions */
extern void complete_model_DISCR_initialize(void);
extern void complete_model_DISCR_step(void);
extern void complete_model_DISCR_terminate(void);

/* Real-time Model object */
extern RT_MODEL_complete_model_DISCR_T *const complete_model_DISCR_M;

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
 * '<Root>' : 'complete_model_DISCR'
 */
#endif                                 /* RTW_HEADER_complete_model_DISCR_h_ */
