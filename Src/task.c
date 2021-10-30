/**
 ******************************************************************************
 * @file    task.h
 * @created 11/02/1398 9:01:22 AM
 * @author  Mehdi Adham
 * @brief   This file contains all the functions Event
 ******************************************************************************
 */

#include "main.h"
#include "task.h"
#include "touchsensing.h"

//extern UART_HandleTypeDef huart1;
//extern uint8_t serial_data;
extern tsl_user_status_t touch_status;



void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	if(huart -> Instance == USART1){
		//HAL_UART_Transmit_IT(&huart1, (uint8_t *)0x00, 1);
	}
	UNUSED(huart);
}



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart ->Instance ==USART1){
		//HAL_UART_Receive_IT(&huart1,&serial_data,1);
	}
	UNUSED(huart);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

	touch_status = tsl_user_Exec();

	UNUSED(htim);
}






