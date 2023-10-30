#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float SocToVoc(float soc){
    double voc, soc_d;
    soc_d = (double)soc;
    voc = (-1.031 * exp(-35 * soc_d) ) + 3.685 + (0.2156 * soc_d) - 0.1178 * pow(soc_d, 2) + (0.321 * pow(soc_d, 3)) ;
    
    //DEBUG
    /* printf("--- FUNCTION SocToVoc ---\n");
    printf("SoC: \t\t%.6f\n", soc);
    printf("V oc: \t\t%.6f\n", voc);
    printf("debug1: \t%.6f\n", (-1.031 * exp(-35 * soc_d) ));
    printf("debug1: \t%.6f\n", 3.685 + (0.2156 * soc_d));
    printf("debug1: \t%.6f\n", 0.1178 * pow(soc_d, 2));
    printf("debug1: \t%.6f\n", (0.321 * pow(soc_d, 3))); */

    return voc;
}