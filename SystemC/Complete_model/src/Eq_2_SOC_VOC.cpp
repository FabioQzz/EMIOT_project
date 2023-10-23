#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float SocToVoc(float soc){
    float voc;
    voc = (-1.031 * exp(-35 * soc) ) + 3.685 + (0.2156 * soc) - 0.1178 * pow(soc, 2) + (0.321 * pow(soc, 3)) ;

    return voc;
}