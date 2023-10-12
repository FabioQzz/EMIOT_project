#include <stdio.h>
#include <stdlib.h>
#include "Eq_4_CapacityCorrectionFactor.h"
#include "Eq_2_SOC_VOC.h"
#include "Eq_8_12_RC_Components.h"
#include "c_rate.h"
#include "integration_SoC.h"
#include "integration_N.h"
#include "Eq_Zeq_circuit.h"

//This model will be time-integrated and simulated in a SystemC env
//to the main will be passed input parameters such as charge/discharge current, T, t, N

void main(){
   //inputs
    float C, T=25.0, I, SoC_init, period;
    int t=40, N=10, N_sum;
    static int N_update = 0;

   //outputs
    float Vout, CCF, Vzeq, Voc;
    static float SoC;

   //internal vars
    float R_cycle, delta_E, c_r,SoC_tot;
    float R_series, R_transient_S, C_transient_S, R_transient_L, C_transient_L;

     printf("This is a battery model written in C \n");

   //Computing CCF, R_cycle and delta_E (these last two are passed and returned by reference)
    N_sum = N_update + N ;
   
    CapacityCorrectionFactor(N_sum,t,T,&R_cycle,&delta_E,&CCF);
   
    c_rate(I,C,CCF,&c_r);
   
    integration_SoC(c_r,SoC_init,CCF,period,&SoC);
    SoC_tot = SoC_init - SoC;


    Voc= SOC_2_VOC(SoC_tot);
   
    N_update = integration_N(c_r, period);
   
    RC_Components(SoC_tot,&R_series,&R_transient_S,&C_transient_S,&R_transient_L,&C_transient_L);

    Vzeq = Zeq_circuit(I,period,R_series,R_cycle,R_transient_S,C_transient_S,R_transient_L,C_transient_L);
    Vout = Voc - Vzeq + delta_E ;

    printf("CCF = %f\n R Cycle = %f\n Potential Correction Factor = %f\n", CCF, R_cycle, delta_E);
   

}