#include "main.h"

ADC_HandleTypeDef hadc1;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);

uint32_t analogValue;

int main(void)
{
  HAL_Init();

  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();

  while (1)
  {
		//Start ADC Conversion
		HAL_ADC_Start(&hadc1);
		//Poll ADC1 Peripherals & Timeout = 1mSec
		if(HAL_ADC_PollForConversion(&hadc1, 1) == HAL_OK)
			analogValue = HAL_ADC_GetValue(&hadc1);
		else
			analogValue = 0;
  }
}