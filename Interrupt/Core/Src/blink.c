#include "blink.h"


void blink(void){

#if MODE_EXECUTE == 3
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);	// Used HAL lib
	  HAL_Delay(500);

#elif MODE_EXECUTE == 1
	  LL_GPIO_TogglePin(GPIOC, LL_GPIO_PIN_8);	// Used Low-layer lib
	  HAL_Delay(2000);

#elif MODE_EXECUTE == 2
	  GPIOC->BSRR = GPIO_PIN_8 + GPIO_PIN_9;
	  HAL_Delay(100);
	  GPIOC->BRR = GPIO_PIN_8 + GPIO_PIN_9;
	  HAL_Delay(100);

#endif
}
