#include "led.h"


void led_on(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	GPIOx->BSRR = GPIO_Pin;
}

void led_off(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
	GPIOx->BRR = GPIO_Pin;
}
