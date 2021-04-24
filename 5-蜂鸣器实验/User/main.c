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
	LED_Init();						//初始化LED
	BEEP_Init();					//初始化蜂鸣器

	
	while(1)
	{
		LED0=!LED0;					//DS0初始为低电平
		BEEP=1;							//蜂鸣器高电平有效
		delay_ms(400);			//精确延时400ms
		BEEP=0;							//蜂鸣器置0
		delay_ms(1600);			//精确延时1600ms

	}
	
}

