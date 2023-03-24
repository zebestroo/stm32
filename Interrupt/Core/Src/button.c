#include "button.h"
#include "stm32f051x8.h"
#include "stm32f0xx_hal.h"
#include "stm32f0xx_hal_exti.h"


int button_action_status(void){
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);
}

void change_button_action_status(void){
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
}

int button_pressed(void){
	return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	change_button_action_status();
}

