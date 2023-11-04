#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float CRate(float current,float capacity, float ccf){
    float c_rate;
    c_rate = current / ( ccf *(capacity*3600) );
    
    //DEBUG
    printf("--- Function CRate ---\n");
    printf("current: %.6f\n", current);
    printf("CCF: %.6f\n", ccf);
    printf("capacity: %.6f\n", capacity);
    printf("\n\n");
    return c_rate;
}