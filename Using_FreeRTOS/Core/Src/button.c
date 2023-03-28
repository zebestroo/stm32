#include "cmsis_os.h"
#include "stm32f0xx_hal.h"
#include "semphr.h"



/* USER CODE END Header_LisBtn */
void LisBtn(SemaphoreHandle_t sema)
{
  /* USER CODE BEGIN LisBtn */
  /* Infinite loop */
  for(;;)
  {
	  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)){
		  if(uxSemaphoreGetCount(sema)){
			  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
			  xSemaphoreTake(sema, 1);
		  }
		  else{
			  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
			  xSemaphoreGive(sema);
		  }
	  }
	  osDelay(1);
  }
  /* USER CODE END LisBtn */
}
