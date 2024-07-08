#include "main.h"

ADC_HandleTypeDef hadc1;

DAC_HandleTypeDef hdac;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_DAC_Init(void);

uint16_t analogValue;

int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_DAC_Init();

  while (1)
  {
		HAL_ADC_Start(&hadc1);
		if(HAL_ADC_PollForConversion(&hadc1, 1) == HAL_OK)
			analogValue = HAL_ADC_GetValue(&hadc1);
		else
			analogValue = 0;
		
		HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, analogValue);
		HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
  }
}