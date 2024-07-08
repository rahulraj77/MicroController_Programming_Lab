#include "main.h"

ADC_HandleTypeDef hadc1;
TIM_HandleTypeDef htim2;

uint8_t analogValue;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM2_Init(void);

//ADC interrupt service routine
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	analogValue = HAL_ADC_GetValue(&hadc1);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
}
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();

	HAL_TIM_Base_Start(&htim2);
	HAL_ADC_Start_IT(&hadc1); //Start ADC in interrupt mode
	
  while (1)
  {
		// Nothing
  }

}