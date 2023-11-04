
void CapacityCorrectionFactor(float N, float t, float T, float *R_cycle, float *delta_E, float *CCF);
float StorageLoss(float t, float T);
void K_coefficients(float T, float *k1, float *k2, float *k3);
float Cycle_Losses(float N, float k1, float k2);