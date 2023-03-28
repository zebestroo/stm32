/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "blink.h"
#include "button.h"
#include "semaHandle.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* Definitions for StatusQueue */
osMessageQueueId_t StatusQueueHandle;
const osMessageQueueAttr_t StatusQueue_attributes = {
  .name = "StatusQueue"
};


//int status = 0;
/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */


void start_tasks(void){
	semaHandle = xSemaphoreCreateBinary();
	BlinkHandle = osThreadNew(BlinkTask, &semaHandle, &Blink_attributes);
	ListenButtonHandle = osThreadNew(LisBtn, &semaHandle, &ListenButton_attributes);
	StatusQueueHandle = osMessageQueueNew (16, sizeof(uint16_t), &StatusQueue_attributes);

}

/* USER CODE END FunctionPrototypes */

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

void start_kernel(void){
	osKernelInitialize();
	start_tasks();
	osKernelStart();
}

/* USER CODE END Application */

