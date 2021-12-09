/*
 * LowPassFilter.c
 *
 *  Created on: 17/set/2015
 *      Author: Raffaele Fornari - Raw Power srl
 */

#include "LowPassFilter.h"

//funzione di inizializzazione della struttura del filtro passa basso
void init_filter(float T_s, float f_t, t_lpfilterStruct *f)
{
	f->I_a = 0;
	f->I_p = 0;
	f->U_a = 0;
	f->U_p = 0;

	f->T_s = T_s;
	f->f_t = f_t;

	f->A0 = (2*_filt_PI*f_t)*T_s/(2+(2*_filt_PI*f_t)*T_s);
	f->A1 = f->A0;
	f->B0 = (2-(2*_filt_PI*f_t)*T_s)/(2+(2*_filt_PI*f_t)*T_s);
}

//funzione di calcolo uscita del filtro
float filter_run(float I_a, t_lpfilterStruct *f)
{
	f->I_a = I_a;

	f->U_a = f->A1*f->I_a + f->A0*f->I_p + f->B0*f->U_p;

	//update
	f->I_p = f->I_a;
	f->U_p = f->U_a;

	return f->U_a;
}

