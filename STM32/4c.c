// Interfacing push button and LED's
#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  while(1)
  {
    if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET)
    {
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13 | GPIO_PIN_15, GPIO_PIN_SET);
      HAL_Delay(500);
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13 | GPIO_PIN_15, GPIO_PIN_RESET);
      HAL_Delay(500);
    }
    else
    {
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_14, GPIO_PIN_SET);
      HAL_Delay(500);
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_14, GPIO_PIN_RESET);
      HAL_Delay(500);
    }
  }
}
