#include <stdio.h>
#include <stdlib.h>
#include "Eq_4_CapacityCorrectionFactor.h"
#include "Eq_2_SOC_VOC.h"
#include "Eq_8_12_RC_Components.h"
#include "c_rate.h"
#include "integration_SoC.h"
#include "integration_N.h"
#include "Eq_Zeq_circuit.h"

void battery_model( float current, float init_cap, float storage_time, float temperature, float init_cycle_n, float init_soc, float *out_v_batt, float *out_ccf, float *out_soc){

    // Internal variables
    static float cycle_n_var = 0;           // Variation in cycle number
    static float soc_var = 0;               // Variation in SoC

    float ccf;
    float cycle_n_tot;                      
    float delta_E;                          // Temperature correction of the potential
    float R_cycle, R_series;                // Components of Zeq
    float R_transient_S, C_transient_S;     // //
    float R_transient_L, C_transient_L;     // //


    cycle_n_tot = cycle_n_var + init_cycle_n;

    CapacityCorrectionFactor(cycle_n_tot, storage_time, temperature, &R_cycle, &delta_E, &ccf);
    
}