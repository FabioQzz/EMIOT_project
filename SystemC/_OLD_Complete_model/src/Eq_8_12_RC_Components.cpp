#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void RC_Components(float SOC, float *R_series, float *R_transient_S,float *C_transient_S, float *R_transient_L, float *C_transient_L){

*R_series = 0.1562 * exp(-24.37*SOC) + 0.07446 ;
*R_transient_S = 0.3208 * exp(-29.14*SOC) + 0.04669;
*C_transient_S = 752.9 * exp(-13.51*SOC) + 703.6;
*R_transient_L = 6.603 * exp(-155.2*SOC) + 0.04984;
*C_transient_L = -6056 * exp(-27.12*SOC) + 4475;

}
