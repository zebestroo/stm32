#include "cmsis_os.h"
#include "stm32f0xx_hal.h"
#include "semaHandle.h"



/* USER CODE END Header_BlinkTask */
void BlinkTask(void * parameter)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
	SemaphoreHandle_t * sem = parameter;
	for(;;)
	{
	  if(uxSemaphoreGetCount(*sem)){
		  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
		  osDelay(500);
		  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
		  osDelay(500);
	  }
	}
  /* USER CODE END 5 */
}
