#include "headers.h"

#define REPEAT_TIMER 1
#define TIMER_TICKS 1000

int counter = TIMER_TICKS;

void action_timer_1ms_step(void){
	SysTick_Config(48000);
}

void timer_1ms_handler(void){
	// Example code
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
}

void HAL_SYSTICK_Callback(void){
	counter--;
	if(counter == 0){
		timer_1ms_handler();
		counter = TIMER_TICKS;
	}
}


void configure_ll_timer(int ticks){
	LL_InitTick(HAL_RCC_GetHCLKFreq(), ticks);
	SysTick->CTRL = SysTick->CTRL | SysTick_CTRL_TICKINT_Msk;
}



