#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_uart.h"
#include "strings.h"
#include "stdint.h"



extern UART_HandleTypeDef huart1;



void print_button_state(UART_HandleTypeDef huart, uint8_t set_button_status){
	if(set_button_status){
		char message[] = "BUTTON1\n";
		HAL_UART_Transmit(&huart, message, sizeof(message), 100);
	}
	else{
		char message[] = "BUTTON0\n";
		HAL_UART_Transmit(&huart, message, sizeof(message), 100);
	}
}




