/*
 * Eq7_8_k1k2k3Linearization_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Eq7_8_k1k2k3Linearization".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Sep 26 16:59:48 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Eq7_8_k1k2k3Linearization_private_h_
#define RTW_HEADER_Eq7_8_k1k2k3Linearization_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Eq7_8_k1k2k3Linearization.h"
#include "Eq7_8_k1k2k3Linearization_types.h"

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

extern P_Eq7_8_k1k2k3Linearization_T Eq7_8_k1k2k3Linearization_P;

#endif                     /* RTW_HEADER_Eq7_8_k1k2k3Linearization_private_h_ */
