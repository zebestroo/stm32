#include "cmsis_os.h"
#include "stm32f0xx_hal.h"
//#include "semaHandle.h"
#include "semphr.h"



/* USER CODE END Header_BlinkTask */
void BlinkTask(SemaphoreHandle_t sema)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
	  if(uxSemaphoreGetCount(sema)){
		  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
		  osDelay(500);
		  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
		  osDelay(500);
	  }
  }
  /* USER CODE END 5 */
}
