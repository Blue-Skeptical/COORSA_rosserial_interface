#include "adc.h"
#include "stm32g4xx_hal.h"
#include "stm32g4xx.h"
#include "stm32g4xx_it.h"

int Reg_1;		//Variabile temporanea in cui memorizzo il valore del registro DR per ADC1
float Adc_1;		//ADC1
int Reg_2;		//Variabile temporanea in cui memorizzo il valore del registro DR per ADC2
float Adc_2;		//ADC2

void read_ADC(t_AdcStruct *params){


	if(ADC1->ISR &= ADC_ISR_EOC){    	//Andiamo a vedere se EOC è settato, se lo è leggo il registro DR.

		Reg_1 = ADC1->DR;		//Viene allocata sulla variabile Reg_1 il valore del registri DR
		Reg_2 = ADC2->DR;		//Avendo letto DR vado a resettare EOC e la conversione può ripartire.

		Adc_1 = (Reg_1*V_REF)/(RIS_ADC-1);	//Viene calcolato il Valore letto in ADC1
		Adc_2 = (Reg_2*V_REF)/(RIS_ADC-1);	//Viene calcolato il Valore letto in ADC2

		if(Adc_2 < V_REF/2)
			Adc_2 = -CURRENT_FS*(((V_REF/2)-Adc_2)/(V_REF/2)) + OFFSET;
		else
			Adc_2 = CURRENT_FS*(((Adc_2)-(V_REF/2))/(V_REF/2)) + OFFSET;


		ADC1->CR |= ADC_CR_ADEN;
		ADC2->CR |= ADC_CR_ADEN;
		ADC1->CR |= ADC_CR_ADSTART;	 //Settando ADSTART è possibile iniziare una nuova conversione, poichè setta nuovamente EOC.
		ADC2->CR |= ADC_CR_ADSTART;	 //Settando ADSTART è possibile iniziare una nuova conversione, poichè setta nuovamente EOC.


		params->Adc_1 = Adc_1;
		params->Adc_2 = Adc_2;
	}
}

void AdcStruct_init(t_AdcStruct *params){
		params->Adc_1 = 0;
		params->Adc_2 = 0;
}
