#include "button.h"
#include "io_information.h"
#include "stm32f051x8.h"
#include "stm32f0xx_hal.h"
#define ROW_DELAY 50
#define ITERATIONS_NUMBER 5

extern UART_HandleTypeDef huart1;

uint8_t count_timer;
uint8_t button_state = 0;
uint8_t button_prestate = 1;
uint8_t iter_counter = ITERATIONS_NUMBER;

int button_action_status(void){
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);
}


void change_button_action_status(void){
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	button_state = (button_state + 1) % 2;
	button_prestate = (button_prestate + 1) % 2;
	iter_counter = ITERATIONS_NUMBER;
	print_button_state(huart1, button_state);
}

void button_handler(void){
	if(button_state != button_pressed()){
		iter_counter--;
		if(!iter_counter){
			change_button_action_status();
		}
	}
	else{
		iter_counter = ITERATIONS_NUMBER;
	}
}


int is_time_out(void){
	if(count_timer == 0){
		return 1;
	}
	else{
		return 0;
	}
}

void reload_timer(void){
	count_timer = ROW_DELAY;
}

void count_timer_dec(void){
	count_timer--;
}


int button_pressed(void){
	return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
}

void button_processing(void){
	if(is_time_out()){
		button_handler();
		/*
		if(button_action_status()){
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
		}
		*/

		reload_timer();
	}
}

uint32_t get_ticks_of_timer(void){
	return count_timer;
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);


}
