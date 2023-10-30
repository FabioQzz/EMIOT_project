#include <stdio.h>
#include <stdlib.h>
#include "battery.h"
#include "src/battery_model.h"

int main(){

    // SIMULATION PARAMETERS
    const float BASE_PERIOD_MS = 1;             // Minimum period, calls main lool. ALL PERIODS MUST BE DIVISIBLE BY THIS AMOUNT
    //const float SIM_PERIOD_MS = 1;            // Simulation clock period in milliseconds
    const float CHECK_PERIOD_MS = 60000;         // Output checking period in milliseconds
    const float MAX_SIM_TIME_MS = 30 * 60 * 1000;    // Maximum simulation time

    // Input variables
    float clock_period      = BASE_PERIOD_MS / 1000;
    float current           = 0;
    float init_cap          = 2;
    float storage_time      = 1;
    float temperature       = 25;
    float init_cycle_n      = 1;
    float init_soc          = 0.75;

    // Output variables
    float v_batt            = 0;
    float ccf               = 0;
    float soc               = 0;

    //Simulation variables
    float clock_time        = 0;            // time variable updated each iteration


    for(clock_time = 0; clock_time <= MAX_SIM_TIME_MS; clock_time += BASE_PERIOD_MS){

        // Update input data
        input_generation(   clock_time,
                            &current,
                            &init_cap,
                            &storage_time,
                            &temperature,
                            &init_cycle_n,
                            &init_soc);
        // Launch simulation
        battery_model(      clock_period,
                            current,
                            init_cap,
                            storage_time,
                            temperature,
                            init_cycle_n,
                            init_soc,
                            &v_batt,
                            &ccf,
                            &soc);

        // Check results
        if((int)clock_time % (int)CHECK_PERIOD_MS == 0){
        output_check(       clock_time, 
                            current, 
                            v_batt, 
                            ccf, 
                            soc);
        }

    }
    return 0;
}

void input_generation(  float clock_time,
                        float *current,
                        float *init_cap,
                        float *storage_time,
                        float *temperature,
                        float *init_cycle_n,
                        float *init_soc){
    if(clock_time == 0) {                      
        *current     = 0;
        *init_cap    = 1;
    } else {
        *current     = 1;
        *init_cap    = 1;
    }
    return;
}

void output_check(  float clock_time, 
                    float current, 
                    float v_batt, 
                    float ccf, 
                    float soc)
{
    printf("**********\n");
    printf("TIME: \t\t%f ms\n", clock_time);
    printf("Current: \t%.6f A\n", current);
    printf("V Batt: \t%.6f V\n", v_batt);
    printf("CCF: \t\t%.6f \n", ccf);
    printf("SoC: \t\t%.6f V\n", soc);
    printf("\n");
    return;
}