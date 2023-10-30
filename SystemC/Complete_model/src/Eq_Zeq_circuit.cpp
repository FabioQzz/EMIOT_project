#include <math.h>

float ZeqCircuit(float current, float period, float R_series, float R_cycle, float R_transient_S, float C_transient_S, float R_transient_L, float C_transient_L){
    float V_R_series, V_R_cycle;
    float V_tot;
    static float V_tr_S = 0; 
    static float V_tr_L = 0;

    V_R_series = current * R_series;
    V_R_cycle = current * R_cycle;
    V_tr_S = (R_transient_S * period) / (period * R_transient_S * C_transient_S) * (current + C_transient_S * V_tr_S / period);
    V_tr_L = (R_transient_L * period) / (period * R_transient_L * C_transient_L) * (current + C_transient_L * V_tr_L / period);

    V_tot = V_R_series + V_R_cycle + V_tr_S + V_tr_L;

    return V_tot;

}