#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void integration_SoC(float c_r, float Soc_init, float CCF, float period,float *SoC){
    static float c_r_1=0;
    
    // Right trapezoid formula, linear approximation
    *SoC =  *SoC + ((c_r + c_r_1) * period / 2);

    //c_r is the current value of C rate, just computed
    //c_r_1 contains the value of c_rate computed in the previous cycle
    c_r_1 = c_r; 

}