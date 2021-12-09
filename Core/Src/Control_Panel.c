#include "Control_Panel.h"
#include "PID_float.h"
#include "stm32g4xx_hal.h"
#include "stm32g4xx.h"
#include "stm32g4xx_it.h"
#include <mainpp.h>

float Pos_ref = 0;
float Pos_error = 0;
float I_ref;
float I_star = 0;
int up_f = 0;
int down_f = 0;
float DOWN_LIM;
float MID_LIM_UP;
float MID_LIM_DOWN;
float UP_LIM;
t_PI_Struct Pos_PI;



void Control_Panel(int down_lim, int mid_lim, int up_lim, float Adc_Pot, t_Control_Panel_Struct *params){

	  ///////////////////////////////////////
	 ///   CONTROLLO ATTUATORE LINEARE   ///
	///////////////////////////////////////

	params->down_lim = down_lim;
	params->mid_lim = mid_lim;
	params->up_lim = up_lim;
	DOWN_LIM = params->DOWN_LIM;
	MID_LIM_UP = params->MID_LIM_UP;
	MID_LIM_DOWN = params->MID_LIM_DOWN;
	UP_LIM = params->UP_LIM;

	if(down_lim == 1 && WaitingForResult){		//POSIZIONE 0
		Pos_ref = DOWN_LIM;
		down_f = 1;
	}
	else if(mid_lim == 2 && WaitingForResult && down_f == 1){	//POSIZIONE 1
		Pos_ref = MID_LIM_DOWN;
	}
	else if(mid_lim == 2 && WaitingForResult && up_f == 1){	//POSIZIONE 1
		Pos_ref = MID_LIM_UP;
	}
	else if(up_lim == 4 && WaitingForResult){	//POSIZIONE 2
		Pos_ref = UP_LIM;
		up_f = 1;
	}
	else{					//MANTIENI POSIZIONE
		Pos_ref = Adc_Pot;
	}

	Pos_error = Pos_ref - Adc_Pot;
	I_star = PIDfloat(Pos_error, &Pos_PI);


	if(I_star >= CURRENT_MAX_UP){  //SATURAZIONE [-I_MAX,+I_MAX]
		I_star = CURRENT_MAX_UP;
	}
	else if(I_star <= -CURRENT_MAX_DOWN){
		I_star = -CURRENT_MAX_DOWN;
	}


	if(Adc_Pot >= Pos_ref - 0.005f && Adc_Pot <= Pos_ref + 0.005f){ //RAGGIUNGIMENTO SET-POINT ISTERESI ADC POTENZIOMETRO

		if(Pos_ref == DOWN_LIM && WaitingForResult){
			WaitingForResult = 0;
			down_lim = 0;
			sendMess(8);
		}
		else if(Pos_ref == MID_LIM_DOWN && WaitingForResult){
			WaitingForResult = 0;
			mid_lim = 0;
			down_f = 0;
			sendMess(16);
			//INVIO MESSAGGIO POSIZIONE 1 RAGGIUNTA
		}
		else if(Pos_ref == MID_LIM_UP && WaitingForResult){
			WaitingForResult = 0;
			mid_lim = 0;
			up_f = 0;
			sendMess(16);
			//INVIO MESSAGGIO POSIZIONE 1 RAGGIUNTA
		}
		else if(Pos_ref == UP_LIM && WaitingForResult){
			WaitingForResult = 0;
			up_lim = 0;
			sendMess(32);
			//INVIO MESSAGGIO POSIZIONE 2 RAGGIUNTA
		}
	}

	Current_Ramp(&I_star, &I_ref);

	params->I_ref=I_ref;
	params->down_lim = down_lim;
	params->mid_lim = mid_lim;
	params->up_lim = up_lim;
}

void Control_Panel_Struct_init(t_Control_Panel_Struct *params){
	params->down_lim = 0;
	params->mid_lim = 0;
	params->up_lim = 0;
	params->I_ref=0;
	params->DOWN_LIM=0.05f;
	params->MID_LIM_UP=0.40f;
	params->MID_LIM_DOWN=0.55f;
	params->UP_LIM=1.5f;

}


void Current_Ramp(float *I_star, float *I_ref){

	 if(*I_star >= *I_ref){
			*I_ref += 0.00005f;
		}
	 if(*I_star < *I_ref){
			*I_ref -= 0.00005f;
		}
}
