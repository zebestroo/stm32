#include "stdint.h"
#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_uart.h"


void print_button_state(UART_HandleTypeDef huart, uint8_t set_button_status);
