#include <stdio.h>
#include <stdlib.h>
#include "Eq_4_CapacityCorrectionFactor.h"
#include "Eq_2_SOC_VOC.h"
#include "Eq_8_12_RC_Components.h"

//This model will be time-integrated and simulated in a SystemC env
//to the main will be passed input parameters such as charge/discharge current, T, t, N

void main(){
   //inputs
    float C, T=25.0;
    int t=40, N=10;

   //outputs
    float V, CCF;
    int SoC;

   //internal vars
    float R_cycle, delta_E; 
    float R_series, R_transient_S, C_transient_S, R_transient_L, C_transient_L;

     printf("This is a battery model written in C \n");

   //Computing CCF, R_cycle and delta_E (these last two are passed and returned by reference)
    CCF = CapacityCorrectionFactor(N,t,T,&R_cycle,&delta_E);

    printf("CCF = %f\n R Cycle = %f\n Potential Correction Factor = %f\n", CCF, R_cycle, delta_E);
   

}