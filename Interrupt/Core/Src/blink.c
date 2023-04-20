#include "blink.h"
#include "button.h"
#include "delay.h"
#include "led.h"

#define BLINK_TIMER 100


extern UART_HandleTypeDef huart1;


uint8_t blink_timer = BLINK_TIMER;

void blink(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, int ticks){

#if MODE_EXECUTE == 0
	  HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);	// Used HAL lib
	  my_timer_delay(ticks);

#elif MODE_EXECUTE == 1
	  //LL_GPIO_TogglePin(GPIOx, GPIO_Pin);	// Used Low-layer lib
	  my_timer_delay(ticks);

#elif MODE_EXECUTE == 2
	  GPIOx->BSRR = GPIO_Pin;
	  my_timer_delay(ticks);
	  GPIOx->BRR = GPIO_Pin;
	  my_timer_delay(ticks);

#elif MODE_EXECUTE == 3
	  my_timer_delay(ticks);

#elif MODE_EXECUTE == 4
	  led_on(GPIOx, GPIO_Pin);
	  HAL_Delay(ticks);
	  led_off(GPIOx, GPIO_Pin);
	  HAL_Delay(ticks);

#endif
}

void blink_on_timer(void){
	if(button_action_status()){
		if(!blink_timer){
			change_led_state();
			print_blink_ticks(huart1, blink_timer);

			blink_timer = BLINK_TIMER;
		}
	}
}

void blink_timer_dec(void){
	blink_timer--;
}

void blink_timer_reload(void){
	blink_timer = BLINK_TIMER;
}

uint32_t get_blink_ticks(void){
	return blink_timer;
}

