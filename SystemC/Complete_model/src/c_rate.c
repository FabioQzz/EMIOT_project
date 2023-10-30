#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float CRate(float current,float capacity, float ccf){
    float c_rate;
    c_rate = current / ( ccf *(capacity*3600) );
    
    //DEBUG
    /* printf("--- Function CRate ---\n");
    printf("current: \t%.6f\n", current);
    printf("CCF: \t\t%.6f\n", ccf);
    printf("capacity: \t%.6f\n", capacity); */
    return c_rate;
}