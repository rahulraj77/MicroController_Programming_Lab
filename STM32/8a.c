#include "main.h"
#include "accelo.h"

SPI_HandleTypeDef hspi1;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);

LIS3DSH_DataScaled myData;

int main(void)
{
	LIS3DSH_InitTypeDef myaccelo_config;
  HAL_Init();
  SystemClock_Config();

	myaccelo_config.dataRate = LIS3DSH_DATARATE_12_5;
	myaccelo_config.fullScale = LIS3DSH_FULLSCALE_4;
	myaccelo_config.antiAliasingBW = LIS3DSH_FILTER_BW_50;
	myaccelo_config.enableAxes = LIS3DSH_XYZ_ENABLE;
	myaccelo_config.interruptEnable = false;

  MX_GPIO_Init();
  MX_SPI1_Init();
	LIS3DSH_Init(&hspi1, &myaccelo_config);

  while (1)
  {
	  if(LIS3DSH_PollDRDY(1000) == true)
	  {
			myData = LIS3DSH_GetDataScaled();
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
	  }
  }
}
