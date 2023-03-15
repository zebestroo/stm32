#include "stm32f0xx_it.h"
#include "stm32f0xx_hal.h"
#include "stm32f0xx_ll_rcc.h"
#include "stm32f0xx_ll_utils.h"


void my_handler(void);
void configure_ll_timer(int ticks);
void configure_hal_timer(int ticks);
void action_timer_1ms_step(int ticks);
