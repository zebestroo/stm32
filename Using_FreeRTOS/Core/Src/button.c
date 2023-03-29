#include "cmsis_os.h"
#include "stm32f0xx_hal.h"
#include "semaHandle.h"



/* USER CODE END Header_LisBtn */
void LisBtn(void * parameter)
{
  /* USER CODE BEGIN LisBtn */
  /* Infinite loop */
	SemaphoreHandle_t * sem = parameter;

	for(;;)
	{
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)){
			uint8_t button_click_accepted = 1;
			uint8_t counter = 5;
			while(counter){
				if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)){
					osDelay(20);
				}
				else{
					button_click_accepted = 0;
					break;
				}
				counter--;
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
	  //osDelay(150);
	}
  /* USER CODE END LisBtn */
}
