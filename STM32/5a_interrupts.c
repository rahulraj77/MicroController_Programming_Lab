// Alternate program to control motors using Interrupts
#include "main.h"

void Step_Sequence1(void);
void Step_Sequence2(void);
void Step_Sequence3(void);
void Step_Sequence4(void);

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

uint8_t flag = 0;

void HAL_GPIO_EXT1_Callback(uint16_t GPIO_Pin)
{
    UNUSED(GPIO_Pin);
    flag = ~flag;
}

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  while(1)
  {
    if(flag)
    {
        Step_Sequence1();
        HAL_Delay(50);
        Step_Sequence2();
        HAL_Delay(50);
        Step_Sequence3();
        HAL_Delay(50);
        Step_Sequence4();
        HAL_Delay(50);
    }
    else
    {
        Step_Sequence4();
        HAL_Delay(50);
        Step_Sequence3();
        HAL_Delay(50);
        Step_Sequence2();
        HAL_Delay(50);
        Step_Sequence1();
        HAL_Delay(50);
    }
    
  }
}

void Step_Sequence1()
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

void Step_Sequence2()
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
}

void Step_Sequence3()
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

void Step_Sequence4()
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}
