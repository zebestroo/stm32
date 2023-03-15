#define MODE_EXECUTE 1


#if MODE_EXECUTE == 0
#include "stm32f0xx_hal_gpio.h"

#elif MODE_EXECUTE == 1
#include "stm32f0xx_ll_gpio.h"

#elif MODE_EXECUTE == 2
#include "stm32f0xx.h"

#else
// TODO: Fail compilation
#endif


void blink(void);
