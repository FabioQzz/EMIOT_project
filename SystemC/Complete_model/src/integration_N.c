

float integration_N(float c_r, float period){
    static float N_update=0;
    static float c_r_1=0;
        
    N_update =  N_update + ((c_r + c_r_1) * period / 2);

    c_r_1 = c_r;

    return N_update;
}