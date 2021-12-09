/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32g4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32g4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "adc.h"
#include "LowPassFilter.h"
#include "PID_float.h"
#include "Control_Panel.h"
#include <mainpp.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */
/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
float DutyCycle = 0;  //Duty Cycle Attuatore Lineare
float Adc_Pot = 0;	 //ADC controllo Potenziometro Attuatore Lineare
float I_sense = 0;	 //ADC Sensore ad effetto HALL Attuatore Lineare (controllo in corrente)
float Out_Filter = 0;	//Uscita filtro digitale per segnale di corrente
float I_ref = 0;	//Corrente di riferimento
float V_star = 0;	//Segnale modulante del controllo in corrente
float I_error = 0;
float DAC_Value_1 = 0;
float DAC_Value_2 = 0;
float count = 0;

t_AdcStruct Adc;
t_lpfilterStruct Low_Pass;
t_PI_Struct Pos_PI;
t_PI_Struct I_PI;


int down_lim = 0;  //POSIZIONE 0: Attuatore Lineare minima estensione
int mid_lim = 0;   //POSIZIONE 1: Attuatore Lineare a metà corsa
int up_lim = 0;	   //POSIZIONE 2: Attuatore Lineare massima estensione

float k = 0;
float j = 0;
int Servo_Angle_1 = 0;     //POSIZIONE A (90°): Servo_Angle = 0  POSIZIONE B (180°): Servo_Angle = 1
int Servo_Angle_2 = 0;
int up_flag = 0;
int down_flag = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim1;
extern DMA_HandleTypeDef hdma_usart2_rx;
extern DMA_HandleTypeDef hdma_usart2_tx;
extern UART_HandleTypeDef huart2;
/* USER CODE BEGIN EV */
extern DAC_HandleTypeDef hdac1;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32G4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32g4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 channel1 global interrupt.
  */
void DMA1_Channel1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel1_IRQn 0 */

  /* USER CODE END DMA1_Channel1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart2_rx);
  /* USER CODE BEGIN DMA1_Channel1_IRQn 1 */

  /* USER CODE END DMA1_Channel1_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel2 global interrupt.
  */
void DMA1_Channel2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel2_IRQn 0 */

  /* USER CODE END DMA1_Channel2_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart2_tx);
  /* USER CODE BEGIN DMA1_Channel2_IRQn 1 */

  /* USER CODE END DMA1_Channel2_IRQn 1 */
}

/**
  * @brief This function handles TIM1 update interrupt and TIM16 global interrupt.
  */
void TIM1_UP_TIM16_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_TIM16_IRQn 0 */


	down_lim = Mess & (1);

	mid_lim = Mess & (2);

	up_lim = Mess & (4);

	read_ADC(&Adc);  //Lettura periferica ADC
	Adc_Pot = Adc.Adc_1;	//Lettura Potenziometro Attuatore Lineare
	I_sense = Adc.Adc_2;	//Lettura sensote di Corrente Attuatore Lineare
	Out_Filter = filter_run(I_sense, &Low_Pass);


	Control_Panel(down_lim, mid_lim, up_lim, Adc_Pot, &ControlPanel);

	I_ref = ControlPanel.I_ref;
	down_lim = ControlPanel.down_lim;
	mid_lim = ControlPanel.mid_lim;
	up_lim = ControlPanel.up_lim;

	I_error = I_ref-Out_Filter;  //Calcolo errore in ingresso al regolatore PI

	if(I_error <= 0.005f && I_error >= -0.005f){  //Dead-Zone
		I_error = 0.0f;
	}

	V_star = PIDfloat(I_error, &I_PI);	//Calcolo tensione di uscita regolatore PI
	DutyCycle = V_star/2 + 0.5f;	//Calcolo Duty Cycle scalato e traslato (V_star: [-1,1] -> [0,1])

	if(DutyCycle >= 0.90f){
		DutyCycle = 0.90f;
	}

	if(DutyCycle <= 0.1f){
		DutyCycle = 0.1f;
	}

	TIM1->CCR1 = DutyCycle*8499; //Impostazione Duty Cycle PWM Attuatore Lineare (DutyCycle*CounterPeriod)

	  ////////////////////////////////////////
	 ///   CONTROLLO SERVOMOTORI GRIFFE   ///
	////////////////////////////////////////

	// 0° = k = 25
	// 90° = k = 75
	// 180° = k = 125
	Servo_Angle_1 = Mess & (64);
	Servo_Angle_2 = Mess & (128);

	if(Servo_Angle_1 == 64 && k>=75){	//POSIZIONE A: 90°
		k -= 0.005f;
		j += 0.005f;
		if(k <= 75 && WaitingForResult){
		down_flag = 1;
		}
	}

	if(Servo_Angle_2 == 128 && k<=120){	//POSIZIONE B: 180°
		k += 0.005f;
		j -= 0.005f;
		if(k >= 95 && WaitingForResult){
		up_flag = 1;
		}
	}

	TIM2->CCR2 = j;		//Impostazione Duty Cycle PWM Servomotori
	TIM2->CCR3 = k;

	if(down_flag == 1 && WaitingForResult){
		WaitingForResult = 0;
		down_flag = 0;
		sendMess(256);
	}

	if(up_flag == 1 && WaitingForResult){
		WaitingForResult = 0;
		up_flag = 0;
		sendMess(512);
	}

	  ///////////////
	 ///   DAC   ///
	///////////////

	DAC_Value_1 = ((4095/2)+(1.0f * I_ref * (4095/2))); //Viene normalizzato il valore che voglio passare al DAC. Risoluzione -> 4096 Posizionamento a metà per vedere valori positivi e negatvi-> 2048
	HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, DAC_Value_1);

	DAC_Value_2 =((4095/2)+(1.0f * Out_Filter * (4095/2)));
	HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_2, DAC_ALIGN_12B_R, DAC_Value_2);



  /* USER CODE END TIM1_UP_TIM16_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_UP_TIM16_IRQn 1 */

  /* USER CODE END TIM1_UP_TIM16_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt / USART2 wake-up interrupt through EXTI line 26.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */
  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */

  /* USER CODE END USART2_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void EXTI15_10_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
}


void InitSystem(void){

	HAL_GPIO_WritePin(GPIOB, EN_A_Pin|EN_B_Pin, GPIO_PIN_SET);
	DutyCycle = 0.5f;
	k = 75;
	j = 75;
	TIM2->CCR2 = k;
	TIM2->CCR3 = j;
	AdcStruct_init(&Adc);  //Init struct ADC
	init_filter(0.0001f, 0.5f, &Low_Pass);	//Init struct Low_Pass_Filter
	Control_Panel_Struct_init(&ControlPanel);
	InitPI_BC(&I_PI);

	I_PI.Kp = 25;	//Impostazione parametri PI anello di corrente
	I_PI.Ki = 70;
	I_PI.Ts = 0.0001f;
	I_PI.IntegralMemory = 0;
	I_PI.OutSatH = 1;
	I_PI.OutSatL = -I_PI.OutSatH;
	I_PI.IntSatH = 1;
	I_PI.IntSatL = -I_PI.IntSatH;

	Pos_PI.Kp = 30;	//Impostazione parametri PI anello di posizione
	Pos_PI.Ki = 0;
	Pos_PI.Ts = 0.0001f;
	Pos_PI.IntegralMemory = 0;
	Pos_PI.OutSatH = 1;
	Pos_PI.OutSatL = -I_PI.OutSatH;
	Pos_PI.IntSatH = 1;
	Pos_PI.IntSatL = -I_PI.IntSatH;

}


/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
