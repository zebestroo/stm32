#include "cmsis_os.h"
#include "stm32f0xx_hal.h"
#include "semaHandle.h"


/* USER CODE END Header_LisBtn */
void LisBtn(void * parameter)
{
  /* USER CODE BEGIN LisBtn */
  /* Infinite loop */
	SemaphoreHandle_t * sem = parameter;

	uint8_t button_state = 0;

	for(;;)
	{

		if(is_button_pressed() != button_state){
			uint8_t counter = 5;
			uint8_t toggle = 1;
			while(counter){
				if(is_button_pressed() == button_state){
					toggle = 0;
					break;
				}

				osDelay(10);
				counter--;
			}
			button_state = (button_state + 1) % 2;


			if(button_state && toggle){
				if(uxSemaphoreGetCount(*sem)){
					//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
					xSemaphoreTake(*sem, 1);
				}
				else{
					//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
					xSemaphoreGive(*sem);
				}
			}

		}

	}
  /* USER CODE END LisBtn */
}

int is_button_pressed(){
	return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
}
