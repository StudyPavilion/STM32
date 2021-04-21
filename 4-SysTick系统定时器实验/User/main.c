#include "stm32f10x.h"
#include "led.h"
#include "SysTick.h"

void delay(u32 i)//延时函数
{
	while(i--);
}

int main()
{
	SysTick_Init(72);
	LED_Init();//初始化LED
	while(1)
	{
		LED0=0;
		LED1=1;
		delay_ms(1000);  //精确延时1000ms
		LED0=1;
		LED1=0;
		delay_ms(1000);  //精确延时1000ms
	}
	
}

