#ifndef __PID_FLOAT_H
#define __PID_FLOAT_H


typedef struct
{
    float ek_old, duk;                  // Previous sample
    float Kp, Ki, Kdesat;               // Regulator parameters
    float IntegralMemory;               // The integral memory
    float OutSatH, OutSatL;             // Output saturations
    float IntSatH,IntSatL; 
    float Ts;                           // Sampling time
}t_PI_Struct;


float PIDfloat(float xk, t_PI_Struct * params);
float PI_BC(float ek, t_PI_Struct *params);
void InitPI_BC(t_PI_Struct *params);



#endif
