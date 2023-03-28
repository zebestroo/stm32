/* Definitions for ListenButton */
osThreadId_t ListenButtonHandle;
const osThreadAttr_t ListenButton_attributes = {
  .name = "ListenButton",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

void LisBtn(void * parameter);
