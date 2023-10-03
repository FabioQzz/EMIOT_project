
float CapacityCorrectionFactor(int N, int t, float T, float *R_cycle, float *delta_E);
float StorageLoss(int t, float T);
void K_coefficients(float T, float *k1, float *k2, float *k3);
float Cycle_Losses(int N, float k1, float k2);