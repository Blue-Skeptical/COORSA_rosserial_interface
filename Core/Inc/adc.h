#ifndef INC_ADC_H_
#define INC_ADC_H_


  ///////////////
 ///   ADC   ///
///////////////

#define RIS_ADC 1024.0f 		//Risoluzione ADC
#define V_REF 3.3f				//Fondo Scala misurato sul pin 3.3V
#define CURRENT_FS 5.0f
#define OFFSET 0.2f

typedef struct
{
float Adc_1; //Misura da Potenziometro
float Adc_2; //Misura Corrente
}t_AdcStruct;

void AdcStruct_init(t_AdcStruct *params);
void read_ADC(t_AdcStruct *params);


#endif /* INC_ADC_H_ */
