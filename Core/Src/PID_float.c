#include "PID_float.h"
 
float PIDfloat(float xk, t_PI_Struct * params)
{
	float tmp;
	params->IntegralMemory+=params->Ki*(xk+params->ek_old)*params->Ts*0.5f;
	if (params->IntegralMemory>params->IntSatH) params->IntegralMemory=params->IntSatH;
	if (params->IntegralMemory<params->IntSatL) params->IntegralMemory=params->IntSatL;
	tmp=params->Kp*xk+params->IntegralMemory;

	if (tmp>params->OutSatH) tmp=params->OutSatH;
	if (tmp<params->OutSatL) tmp=params->OutSatL;

	params->ek_old=xk;
	return tmp;
}


void InitPI_BC(t_PI_Struct * params)
{
    params->ek_old = 0;            // Previous sample
    params->duk = 0;
    params->Kp = 0;
    params->Ki = 0;
    params->IntegralMemory = 0;    // The integral memory
    params->OutSatH = 0;
    params->OutSatL = 0;           // Output saturations
    params->Ts = 0;                // Sampling time
}


float PI_BC(float ek, t_PI_Struct * params)
{
    float uk = 0, proportional = 0, error = 0;

    proportional = params->Kp*ek;

    error = ek*params->Ki + params->duk*params->Kdesat;
    params->IntegralMemory += (params->ek_old + error)*params->Ts*0.5f;

    uk = proportional + params->IntegralMemory;

    if(uk > params->OutSatH)
    	uk = params->OutSatH;

    if(uk < params->OutSatL)
    	uk = params->OutSatL;

    params->duk = uk - (proportional + params->IntegralMemory);
    params->ek_old = error;

    return uk;
}

