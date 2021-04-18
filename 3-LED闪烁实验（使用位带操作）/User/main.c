#include "stm32f10x.h"
#include "led.h"


void delay(u32 i)//延时函数
{
	while(i--);
}

int main()
{
	LED_Init();//初始化LED
	
	while(1)
	{
		LED0=0;
		//点亮DS0
		delay(6000000);
		LED0=1;
		//熄灭DS0
		delay(6000000);
		LED1=0;
		//点亮DS1
		delay(6000000);
		LED1=1;
		//熄灭DS1
		delay(6000000);
		
	}
	
}

