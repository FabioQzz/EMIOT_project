void input_generation(  FILE *file_ptr,
                        float clock_time,
                        float *current,
                        float *init_cap,
                        float *storage_time,
                        float *temperature,
                        float *init_cycle_n,
                        float *init_soc);

void output_check(  FILE *file_ptr,
                    float clock_time, 
                    float current, 
                    float v_batt, 
                    float ccf, 
                    float soc);