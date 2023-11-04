#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float StorageLoss(float t, float T);
void K_coefficients(float T, float *k1, float *k2, float *k3);
float Cycle_Losses(float N, float k1, float k2);

void CapacityCorrectionFactor(float N, float t, float T, float *R_cycle, float *delta_E, float *CCF){
    //float CCF=5.5; 
    float storage_loss;
    float k1, k2, k3;
    float CycleLosses;

    //DEBUG
    printf("---FUNCTION CCF---\n");
    printf("storage loss: %.6f\n", storage_loss);
    printf("cycle loss: %.6f\n", CycleLosses);
    printf("temperature T: %.6f\n", T);
    printf("time months t: %.6f\n", t);

    //Eq6_StorageLoss
    storage_loss = StorageLoss(t,T);

    //Eq7_8_k1k2k3Linearization
    K_coefficients(T,&k1,&k2,&k3);

    //Eq7_CyclesLoss
    CycleLosses = Cycle_Losses(N,k1,k2);

    //First output, passed by value
    *CCF = 1 - (storage_loss + CycleLosses);

    //Second output, passed by reference
    *R_cycle = k3 * (float)sqrt(N); 

    //Third output, passed by reference
    *delta_E = (T * 0.0102) - 0.2118 ;


}


//Eq6_StorageLoss
float StorageLoss(float t, float T){
    float St_Loss;
    float T_kelvin;

    T_kelvin = T + 273.15 ; 
    St_Loss =  1.544e7 * exp(-40498 / (8.3143 * T_kelvin)) * t;

    //DEBUG
    //printf("T_kelvin: %.6f\n", T_kelvin);
    //printf("debug1: %.6f\n", (8.3143 * T_kelvin));
    //printf("debug2: %.6f\n", (-40498 / (8.3143 * T_kelvin)));
    //printf("debug3: %.6f\n", exp(-40498 / (8.3143 * T_kelvin)) * t);
    //printf("debug4: %.6f\n", 1.544e7 * exp(-40498 / (8.3143 * T_kelvin)) * t);

    return St_Loss * 0.01; //returning a %
}


//Eq7_8_k1k2k3Linearization
void K_coefficients(float T, float *k1, float *k2, float *k3){
    *k1 = (T * (6.0600e-08)) + (-1.4300e-06);
    *k2 = (T * (1.6000e-06)) + (2.1000e-04);
    *k3 = (T * (8.0000e-06)) + (0.0013);        
}


//Eq7_CyclesLoss
float Cycle_Losses(float N, float k1, float k2){
    float Cycle_loss;
    Cycle_loss = ( N*N*0.5*k1) + (N * k2);
    return Cycle_loss;
}