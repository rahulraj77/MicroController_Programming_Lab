#include "stm32f4xx.h"
void delayMs(int n);
void EXTI0_IRQHandler(void);

int main(void)
{
	RCC -> AHB1ENR |= 9;
	RCC -> APB2ENR |= (1 << 14);
	
	GPIOD -> MODER |= 0x11000000;
	GPIOD -> MODER &= ~(0x00000003);
	
	SYSCFG -> EXTICR[0] &= ~(0xF << 0);
	EXTI -> IMR |= (1 << 0);
	EXTI -> RTSR |= (1 << 0);
	EXTI -> FTSR &= ~(1 << 0);
	
	NVIC -> ISER[0] |= (1 << 6);
	
	while(1)
		{
			GPIOD -> BSRR = 1 << 12;
			delayMs(300);
			GPIOD -> BSRR = 1 << 28;
			delayMs(300);
		}
}

void EXTI0_IRQHandler(void)
{
	int i;
	for(i = 0; i < 3; i++)
	{
		GPIOD -> BSRR = 1 << 14;
		delayMs(300);
		GPIOD -> BSRR = 1 << 30;
		delayMs(300);
	}
	EXTI -> PR |= (1 << 0);
}

void delayMs(int n)
{
	int i;
	for(; n >0; n--)
		for(i = 0; i < 3195; i++);
}
