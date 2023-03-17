#include "delay.h"
#include "stm32f0xx.h"
#include "stm32f0xx_hal.h"
#include "stm32f0xx_ll_utils.h"

#include "const.h"

void my_timer_delay(int ticks){
#if TIMER_MODE == 0
	SysTick_Config(SYSTICK_PRESCALER);
	HAL_Delay(ticks);

#elif TIMER_MODE == 1
	LL_InitTick(HAL_RCC_GetHCLKFreq(), ticks);
	//SysTick->CTRL = SysTick->CTRL | SysTick_CTRL_TICKINT_Msk;
	LL_mDelay(ticks);

#elif TIMER_MODE == 2
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/ticks);
	HAL_Delay(ticks);

#endif

}
