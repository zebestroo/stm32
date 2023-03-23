#include "blink.h"
#include "delay.h"
#include "led.h"


void blink(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, int ticks){

#if MODE_EXECUTE == 0
	  HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);	// Used HAL lib
	  my_timer_delay(ticks);

#elif MODE_EXECUTE == 1
	  LL_GPIO_TogglePin(GPIOx, GPIO_Pin);	// Used Low-layer lib
	  my_timer_delay(ticks);

#elif MODE_EXECUTE == 2
	  GPIOx->BSRR = GPIO_Pin;
	  my_timer_delay(ticks);
	  GPIOx->BRR = GPIO_Pin;
	  my_timer_delay(ticks);

#elif MODE_EXECUTE == 3
	  my_timer_delay(ticks);

#endif
}
