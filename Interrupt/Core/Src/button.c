#include "button.h"
#include "stm32f051x8.h"
#include "stm32f0xx_hal.h"


void blink_button(void){
	if(GPIOA->IDR & GPIO_PIN_0){
		GPIOC->BSRR |= 1 << 8;
	}
	else{
		GPIOC->BRR |= 1 << 8;
	}
}

void blink_button_period(int period){
	if(GPIOA->IDR & GPIO_PIN_0){
		GPIOC->BSRR |= 1 << 8;
		HAL_Delay(period);
		GPIOC->BRR |= 1 << 8;
		HAL_Delay(period);
	}
}
