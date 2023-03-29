#include "cmsis_os.h"
#include "stm32f0xx_hal.h"
#include "semaHandle.h"



/* USER CODE END Header_LisBtn */
void LisBtn(void * parameter)
{
  /* USER CODE BEGIN LisBtn */
  /* Infinite loop */
	SemaphoreHandle_t * sem = parameter;
	uint8_t button_click_accepted = 0;

	uint8_t counter = 20;	// Define time (ms) of a button check
	for(;;)
	{

		if(is_button_pressed()){
			button_click_accepted = 1;
			uint8_t point_time = HAL_GetTick();
			while(HAL_GetTick() - point_time <= counter){
				if(!is_button_pressed()){
					point_time = HAL_GetTick();
					button_click_accepted = 0;
					break;
				}
			}

			if(button_click_accepted){
				if(uxSemaphoreGetCount(*sem)){
					HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
					xSemaphoreTake(*sem, 1);
				}
				else{
					HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
					xSemaphoreGive(*sem);
				}
			}
		}

	  //osDelay(50);
	}
  /* USER CODE END LisBtn */
}


int is_button_pressed(){
	return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
}
