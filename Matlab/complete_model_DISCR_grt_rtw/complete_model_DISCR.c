/*
 * complete_model_DISCR.c
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

#include "complete_model_DISCR.h"
#include <math.h>
#include <string.h>
#include "complete_model_DISCR_private.h"
#include "Eq4_CapacityCorrectionFactor.h"
#include "Eq8to12_RC_Components.h"
#include "Eq_Zeq_circuit.h"
#include "Eq2_SOC_VOC.h"
#include "rt_nonfinite.h"

rtTimingBridge complete_model_DISCR_TimingBrdg;

/* Block signals (default storage) */
B_complete_model_DISCR_T complete_model_DISCR_B;

/* Block states (default storage) */
DW_complete_model_DISCR_T complete_model_DISCR_DW;

/* External inputs (root inport signals with default storage) */
ExtU_complete_model_DISCR_T complete_model_DISCR_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_complete_model_DISCR_T complete_model_DISCR_Y;

/* Real-time model */
static RT_MODEL_complete_model_DISCR_T complete_model_DISCR_M_;
RT_MODEL_complete_model_DISCR_T *const complete_model_DISCR_M =
  &complete_model_DISCR_M_;

/* Model step function */
void complete_model_DISCR_step(void)
{
  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  complete_model_DISCR_B.DiscreteTimeIntegrator =
    complete_model_DISCR_DW.DiscreteTimeIntegrator_DSTATE;

  /* Outport: '<Root>/SoC' incorporates:
   *  Inport: '<Root>/Initial SoC [%]'
   *  Sum: '<Root>/Sum'
   */
  complete_model_DISCR_Y.SoC = complete_model_DISCR_U.InitialSoC -
    complete_model_DISCR_B.DiscreteTimeIntegrator;

  /* ModelReference: '<Root>/V oc' incorporates:
   *  Outport: '<Root>/SoC'
   */
  Eq2_SOC_VOC(&complete_model_DISCR_Y.SoC, &complete_model_DISCR_B.Voc,
              &(complete_model_DISCR_DW.Voc_InstanceData.rtb));

  /* ModelReference: '<Root>/Model1' incorporates:
   *  Outport: '<Root>/SoC'
   */
  Eq8to12_RC_Components(&complete_model_DISCR_Y.SoC,
                        &complete_model_DISCR_B.Model1_o1,
                        &complete_model_DISCR_B.Model1_o2,
                        &complete_model_DISCR_B.Model1_o3,
                        &complete_model_DISCR_B.Model1_o4,
                        &complete_model_DISCR_B.Model1_o5,
                        &(complete_model_DISCR_DW.Model1_InstanceData.rtb));

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  complete_model_DISCR_B.DiscreteTimeIntegrator1 =
    complete_model_DISCR_DW.DiscreteTimeIntegrator1_DSTATE;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Inport: '<Root>/Cycle Number'
   */
  complete_model_DISCR_B.Sum1 = complete_model_DISCR_U.CycleNumber +
    complete_model_DISCR_B.DiscreteTimeIntegrator1;

  /* ModelReference: '<Root>/Model' incorporates:
   *  Inport: '<Root>/Storage Time'
   *  Inport: '<Root>/Temperature'
   *  Outport: '<Root>/CCF'
   */
  Eq4_CapacityCorrectionFactor(&complete_model_DISCR_U.StorageTime,
    &complete_model_DISCR_U.Temperature, &complete_model_DISCR_B.Sum1,
    &complete_model_DISCR_Y.CCF, &complete_model_DISCR_B.Model_o2,
    &complete_model_DISCR_B.Model_o3,
    &(complete_model_DISCR_DW.Model_InstanceData.rtb),
    &(complete_model_DISCR_DW.Model_InstanceData.rtdw));

  /* ModelReference: '<Root>/Model2' incorporates:
   *  Inport: '<Root>/Current [A]'
   */
  Eq_Zeq_circuit(&(complete_model_DISCR_DW.Model2_InstanceData.rtm),
                 &complete_model_DISCR_U.CurrentA,
                 &complete_model_DISCR_B.Model1_o1,
                 &complete_model_DISCR_B.Model1_o2,
                 &complete_model_DISCR_B.Model1_o3,
                 &complete_model_DISCR_B.Model1_o4,
                 &complete_model_DISCR_B.Model1_o5,
                 &complete_model_DISCR_B.Model_o2,
                 &complete_model_DISCR_B.Model2,
                 &(complete_model_DISCR_DW.Model2_InstanceData.rtb),
                 &(complete_model_DISCR_DW.Model2_InstanceData.rtdw));

  /* Outport: '<Root>/V battery' incorporates:
   *  Sum: '<Root>/V batt'
   */
  complete_model_DISCR_Y.Vbattery = (complete_model_DISCR_B.Voc -
    complete_model_DISCR_B.Model2) + complete_model_DISCR_B.Model_o3;

  /* Gain: '<Root>/Gain' incorporates:
   *  Inport: '<Root>/Batt Cap [Ah]'
   */
  complete_model_DISCR_B.Gain = complete_model_DISCR_P.Gain_Gain *
    complete_model_DISCR_U.BattCapAh;

  /* Product: '<Root>/Product1' incorporates:
   *  Outport: '<Root>/CCF'
   */
  complete_model_DISCR_B.Product1 = complete_model_DISCR_B.Gain *
    complete_model_DISCR_Y.CCF;

  /* Product: '<Root>/Divide' incorporates:
   *  Inport: '<Root>/Current [A]'
   */
  complete_model_DISCR_B.Divide = complete_model_DISCR_U.CurrentA /
    complete_model_DISCR_B.Product1;

  /* Abs: '<Root>/Abs' */
  complete_model_DISCR_B.Abs = fabs(complete_model_DISCR_B.Divide);

  /* Gain: '<Root>/Gain1' */
  complete_model_DISCR_B.Gain1 = complete_model_DISCR_P.Gain1_Gain *
    complete_model_DISCR_B.Abs;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  complete_model_DISCR_DW.DiscreteTimeIntegrator_DSTATE +=
    complete_model_DISCR_P.DiscreteTimeIntegrator_gainval *
    complete_model_DISCR_B.Divide;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  complete_model_DISCR_DW.DiscreteTimeIntegrator1_DSTATE +=
    complete_model_DISCR_P.DiscreteTimeIntegrator1_gainval *
    complete_model_DISCR_B.Gain1;

  /* Matfile logging */
  rt_UpdateTXYLogVars(complete_model_DISCR_M->rtwLogInfo,
                      (&complete_model_DISCR_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(complete_model_DISCR_M)!=-1) &&
        !((rtmGetTFinal(complete_model_DISCR_M)-
           complete_model_DISCR_M->Timing.taskTime0) >
          complete_model_DISCR_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(complete_model_DISCR_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++complete_model_DISCR_M->Timing.clockTick0)) {
    ++complete_model_DISCR_M->Timing.clockTickH0;
  }

  complete_model_DISCR_M->Timing.taskTime0 =
    complete_model_DISCR_M->Timing.clockTick0 *
    complete_model_DISCR_M->Timing.stepSize0 +
    complete_model_DISCR_M->Timing.clockTickH0 *
    complete_model_DISCR_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void complete_model_DISCR_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)complete_model_DISCR_M, 0,
                sizeof(RT_MODEL_complete_model_DISCR_T));
  rtmSetTFinal(complete_model_DISCR_M, 300.0);
  complete_model_DISCR_M->Timing.stepSize0 = 1.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    complete_model_DISCR_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(complete_model_DISCR_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(complete_model_DISCR_M->rtwLogInfo, (NULL));
    rtliSetLogT(complete_model_DISCR_M->rtwLogInfo, "tout");
    rtliSetLogX(complete_model_DISCR_M->rtwLogInfo, "");
    rtliSetLogXFinal(complete_model_DISCR_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(complete_model_DISCR_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(complete_model_DISCR_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(complete_model_DISCR_M->rtwLogInfo, 0);
    rtliSetLogDecimation(complete_model_DISCR_M->rtwLogInfo, 1);
    rtliSetLogY(complete_model_DISCR_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(complete_model_DISCR_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(complete_model_DISCR_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &complete_model_DISCR_B), 0,
                sizeof(B_complete_model_DISCR_T));

  /* states (dwork) */
  (void) memset((void *)&complete_model_DISCR_DW, 0,
                sizeof(DW_complete_model_DISCR_T));

  /* external inputs */
  (void)memset(&complete_model_DISCR_U, 0, sizeof(ExtU_complete_model_DISCR_T));

  /* external outputs */
  (void)memset(&complete_model_DISCR_Y, 0, sizeof(ExtY_complete_model_DISCR_T));

  {
    static uint32_T *clockTickPtrs[1];
    static uint32_T *clockTickHPtrs[1];
    static real_T *taskTimePtrs[1];
    complete_model_DISCR_TimingBrdg.nTasks = 1;
    clockTickPtrs[0] = &(complete_model_DISCR_M->Timing.clockTick0);
    clockTickHPtrs[0] = &(complete_model_DISCR_M->Timing.clockTickH0);
    complete_model_DISCR_TimingBrdg.clockTick = clockTickPtrs;
    complete_model_DISCR_TimingBrdg.clockTickH = clockTickHPtrs;
    taskTimePtrs[0] = &(complete_model_DISCR_M->Timing.taskTime0);
    complete_model_DISCR_TimingBrdg.taskTime = taskTimePtrs;
  }

  /* Model Initialize function for ModelReference Block: '<Root>/Model' */
  Eq4_CapacityCorrecti_initialize(rtmGetErrorStatusPointer
    (complete_model_DISCR_M), &(complete_model_DISCR_DW.Model_InstanceData.rtm),
    &(complete_model_DISCR_DW.Model_InstanceData.rtb),
    &(complete_model_DISCR_DW.Model_InstanceData.rtdw));

  /* Model Initialize function for ModelReference Block: '<Root>/Model1' */
  Eq8to12_RC_Component_initialize(rtmGetErrorStatusPointer
    (complete_model_DISCR_M), &(complete_model_DISCR_DW.Model1_InstanceData.rtm),
    &(complete_model_DISCR_DW.Model1_InstanceData.rtb));

  /* Model Initialize function for ModelReference Block: '<Root>/Model2' */
  Eq_Zeq_circuit_initialize(rtmGetErrorStatusPointer(complete_model_DISCR_M),
    &complete_model_DISCR_TimingBrdg, 0,
    &(complete_model_DISCR_DW.Model2_InstanceData.rtm),
    &(complete_model_DISCR_DW.Model2_InstanceData.rtb),
    &(complete_model_DISCR_DW.Model2_InstanceData.rtdw));

  /* Model Initialize function for ModelReference Block: '<Root>/V oc' */
  Eq2_SOC_VOC_initialize(rtmGetErrorStatusPointer(complete_model_DISCR_M),
    &(complete_model_DISCR_DW.Voc_InstanceData.rtm),
    &(complete_model_DISCR_DW.Voc_InstanceData.rtb));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(complete_model_DISCR_M->rtwLogInfo, 0.0,
    rtmGetTFinal(complete_model_DISCR_M),
    complete_model_DISCR_M->Timing.stepSize0, (&rtmGetErrorStatus
    (complete_model_DISCR_M)));

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  complete_model_DISCR_DW.DiscreteTimeIntegrator_DSTATE =
    complete_model_DISCR_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  complete_model_DISCR_DW.DiscreteTimeIntegrator1_DSTATE =
    complete_model_DISCR_P.DiscreteTimeIntegrator1_IC;

  /* SystemInitialize for ModelReference: '<Root>/Model2' */
  Eq_Zeq_circuit_Init(&(complete_model_DISCR_DW.Model2_InstanceData.rtm),
                      &(complete_model_DISCR_DW.Model2_InstanceData.rtdw));
}

/* Model terminate function */
void complete_model_DISCR_terminate(void)
{
  /* Terminate for ModelReference: '<Root>/Model2' */
  Eq_Zeq_circuit_Term(&(complete_model_DISCR_DW.Model2_InstanceData.rtdw));
}
