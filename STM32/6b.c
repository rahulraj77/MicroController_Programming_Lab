#include "main.h"

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);

uint16_t analogValue, i;

int main(void)
{
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_ADC1_Init();

  while (1)
  {
    HAL_ADC_Start(&hadc1);
		//Poll ADC1 Peripherals & TimeOut = 1mSec
		if(HAL_ADC_PollForConversion(&hadc1, 1) == HAL_OK)
			analogValue = HAL_ADC_GetValue(&hadc1);
		else
			analogValue = 0;
		
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
		for(i = 0; i < analogValue; i++);
		for(i = 0; i < analogValue; i++);
		analogValue = (~analogValue) & 0x0FFF; // Masking upper four bits.
		for(i = 0; i < analogValue; i++);
		for(i = 0; i < analogValue; i++);
  }
}