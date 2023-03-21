#define USE_FULL_LL_DRIVER = 1
void my_timer_delay(int ticks);
//static void TIM_Init_hal(void);
void TIM_Init_ll(void);
void TIM_Init_cmsis(void);
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

