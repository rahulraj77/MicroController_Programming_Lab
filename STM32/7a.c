#include "main.h"
#include <string.h>
#include <stdio.h>

ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;

/* Private function prototypes */
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART2_UART_Init(void);
uint32_t analogValue;

int main(void)
{
  const char Array[] = "\nTemperature ";
  char tempValue[20], i = 0;

  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN WHILE*/
  while(1)
  {
    HAL_ADC_Start(&hadc1);
    // Poll ADC1 Peripherals & TimeOut = 1mSec
    if(HAL_ADC_PollForConversion(&hadc1, 1) == HAL_OK)
      analogValue = HAL_ADC_GetValue(&hadc1);
    else
      analogValue = 0;

    HAL_UART_Transmit(&huart2, (uint8_t*)Array, strlen(Array), 10);
    i = 0;
    while(analogValue != 0){
      tempValue[i] = analogValue % 10 + '0';
      analogValue = analogValue / 10;
      i++;
    }
    tempValue[i] = '\0';
    HAL_UART_Transmit(&huart2, (uint8_t*)tempValue, strlen(tempValue), 10);
    HAL_Delay(1000);
    
  }
}
