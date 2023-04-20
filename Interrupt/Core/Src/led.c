#include "main.h"

uint8_t led_state = 0;

void led_on(void){
	HAL_GPIO_WritePin(GPIOC, LD4_Pin, GPIO_PIN_SET);
}

void led_off(void){
	HAL_GPIO_WritePin(GPIOC, LD4_Pin, GPIO_PIN_RESET);
}

void change_led_state(void){
	if(led_state){
		led_off();
	}
	else{
		led_on();
	}
	led_state = (led_state + 1) % 2;
}
