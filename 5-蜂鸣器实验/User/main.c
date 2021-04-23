#include "stm32f10x.h"
#include "led.h"
#include "SysTick.h"
#include "beep.h"


void delay(u32 i)//延时函数
{
	while(i--);
}

int main()
{
	SysTick_Init(72);
	LED_Init();//初始化LED
	BEEP_Init();

	
	while(1)
	{
		LED0=!LED0;
		BEEP=1;
		delay_ms(400);
		BEEP=0;
		delay_ms(1600);
	}
	
}

