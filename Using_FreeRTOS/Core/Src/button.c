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
		  if(uxSemaphoreGetCount(*sem)){
			  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
			  xSemaphoreTake(*sem, 1);
		  }
		  else{
			  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
			  xSemaphoreGive(*sem);
		  }
	  }
	  osDelay(1);
	}
  /* USER CODE END LisBtn */
}
