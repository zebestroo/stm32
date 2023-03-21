#include "delay.h"
#include "stm32f0xx.h"
#include "stm32f0xx_hal.h"
#include "stm32f0xx_ll_utils.h"
#include "stm32f0xx_hal_tim.h"
#include "stm32f0xx_it.h"
#include "stm32f0xx_ll_tim.h"
#include "stm32f0xx_ll_bus.h"
#include "assert.h"

#include "const.h"

//TIM_HandleTypeDef htim3;
int action_counter = 1;
int action_ticks = 0;


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

#elif TIMER_MODE == 3
	action_ticks = ticks;
	TIM_Init_hal();
	HAL_TIM_Base_Start_IT(&htim3);

#elif TIMER_MODE == 4
	action_ticks = ticks;
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
	TIM_Init_ll();
	LL_TIM_EnableCounter(TIM3);

#elif TIMER_MODE == 5
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
	TIM_Init_cmsis();
	TIM3->CR1 = 1;
#endif

}
/*
static void TIM_Init_hal(void)
{


  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};


  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 47999;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = action_ticks;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }

}
*/


void TIM_Init_ll(void){
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);
	LL_TIM_SetPrescaler(TIM3, 47999);
	LL_TIM_SetCounterMode(TIM3, LL_TIM_COUNTERMODE_UP);
	LL_TIM_SetAutoReload(TIM3, 500);
	LL_TIM_SetClockDivision(TIM3, LL_TIM_CLOCKDIVISION_DIV1);
	LL_TIM_EnableIT_UPDATE(TIM3);
	NVIC_EnableIRQ(TIM3_IRQn);
}


void TIM_Init_cmsis(void){
	RCC->APB1ENR = 2;
	TIM3->PSC = 47999;
	TIM3->ARR = 500;
	TIM3->DIER = 1;
	NVIC_EnableIRQ(TIM3_IRQn);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);

	//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
	//HAL_TIM_Base_Stop_IT(&htim3);
}

