/*
 * Eq4_CapacityCorrectionFactor_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Eq4_CapacityCorrectionFactor".
 *
 * Model version              : 2.11
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Sep 26 17:08:42 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Eq4_CapacityCorrectionFactor_private_h_
#define RTW_HEADER_Eq4_CapacityCorrectionFactor_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Eq4_CapacityCorrectionFactor.h"
#include "Eq4_CapacityCorrectionFactor_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern P_Eq4_CapacityCorrectionFacto_T Eq4_CapacityCorrectionFactor_P;

#endif                  /* RTW_HEADER_Eq4_CapacityCorrectionFactor_private_h_ */
