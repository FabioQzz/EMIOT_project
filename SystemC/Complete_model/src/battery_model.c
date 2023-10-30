#include <stdio.h>
#include <stdlib.h>
#include "Eq_4_CapacityCorrectionFactor.h"
#include "Eq_2_SOC_VOC.h"
#include "Eq_8_12_RC_Components.h"
#include "c_rate.h"
#include "integration_SoC.h"
#include "integration_N.h"
#include "Eq_Zeq_circuit.h"

void battery_model( float clock_period,
                    float current,
                    float cap_init,
                    float storage_time,
                    float temperature,
                    float cycle_n_init,
                    float soc_init,
                    float *out_v_batt,
                    float *out_ccf,
                    float *out_soc){

    // Internal variables
    static float cycle_n_var = 0;           // Variation in cycle number
    static float soc_var = 0;               // Variation in SoC

    float ccf;                              // Capacity Correction Factor
    float c_rate;                           // C-rate : current/capacity
    float cycle_n_tot;                      // Total charge-discharge cycles
    float delta_E;                          // Temperature correction of the potential
    float R_cycle, R_series;                // Components of Zeq
    float R_transient_S, C_transient_S;     // ^
    float R_transient_L, C_transient_L;     // ^
    float soc_tot;                          // Total State of Charge
    float v_oc;                             // Open Circuit Voltage
    float v_zeq;                            // Voltage of equivalent impedance


    cycle_n_tot = cycle_n_var + cycle_n_init;

    CapacityCorrectionFactor(cycle_n_tot, storage_time, temperature, &R_cycle, &delta_E, &ccf);
    
    c_rate = CRate(current, cap_init, ccf);

    integration_SoC(c_rate, soc_init, ccf, clock_period, &soc_var);

    soc_tot = soc_init - soc_var;

    v_oc = SocToVoc(soc_tot);

    cycle_n_var = integration_N(c_rate, clock_period);

    RC_Components(soc_tot, &R_series, &R_transient_S, &C_transient_S, &R_transient_L, &C_transient_L);

    v_zeq = Zeq_circuit(current, clock_period, R_series, R_cycle, R_transient_S, C_transient_S, R_transient_L, C_transient_L);

    *out_v_batt = v_oc - v_zeq + delta_E;
    *out_ccf = ccf;
    *out_soc = soc_tot;

    //DEBUG
    /* printf("--- FUNCTION battery_model ---\n");
    printf("C_rate: \t%.6f\n", c_rate);
    printf("V oc: \t\t%.6f V\n", v_oc);
    printf("V Zeq: \t\t%.6f V\n", v_zeq);
    printf("Delta E: \t%.6f V\n", delta_E); */
}