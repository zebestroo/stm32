#include "const.h"
#include "delay.h"
#include "led.h"

#if MODE_EXECUTE == 0
#include "stm32f0xx_hal.h"

#elif MODE_EXECUTE == 1
#include "stm32f0xx_ll_gpio.h"

#elif MODE_EXECUTE == 2
#include "stm32f0xx.h"

#elif MODE_EXECUTE == 3
#include "stm32f0xx.h"

#else
// TODO: Fail compilation
#endif


void blink(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, int ticks);
