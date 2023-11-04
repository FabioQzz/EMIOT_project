#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float SOC_2_VOC(float SOC){
    float VOC;
    printf("Computing Voc \n");
    VOC = (-1.031 * exp(-35 * SOC) ) + 3.685 + (0.2156 * SOC) - 0.1178 * pow(SOC, 2) + (0.321 * pow(SOC, 3)) ;

    return VOC;
}