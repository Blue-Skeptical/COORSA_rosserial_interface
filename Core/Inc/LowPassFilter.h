/*
 * LowPassFilter.h
 *
 *  Created on: 17/set/2015
 *      Author: Raffaele Fornari
 */

#ifndef LOWPASSFILTER_H_
#define LOWPASSFILTER_H_

#define _filt_PI 3.14159265358	//pigreco

typedef struct lpfilterStruct
{
	float T_s;				//periodo di sampling [s]
	float f_t;				//frequenza di taglio [Hz]
	float I_p;				//ingresso precedente
	float U_p;				//uscita precedente
	float I_a;				//ingresso attuale
	float U_a;				//uscita attuale
	float A0;				//coefficiente A0
	float A1;				//coefficiente A1
	float B0;				//coefficiente B1
}t_lpfilterStruct;


void init_filter(float T_s, float f_t, t_lpfilterStruct *f);	//funzione di inizializzazione della struttura del filtro passa basso
float filter_run(float I_a, t_lpfilterStruct *f);	//funzione di calcolo uscita del filtro

#endif /* LOWPASSFILTER_H_ */
