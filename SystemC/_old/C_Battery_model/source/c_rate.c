#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void c_rate(float I,float C, float CCF, float *c_r){
    *c_r = I / ( CCF *(C*3600) ) ;

}