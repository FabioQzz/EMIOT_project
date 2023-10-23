#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float CRate(float current,float capacity, float ccf){
    float c_rate;
    c_rate = current / ( ccf *(capacity*3600) );
    
    return c_rate;
}