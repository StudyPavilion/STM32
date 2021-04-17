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
		GPIO_ResetBits(LED0_PORT, LED0_PIN);//点亮DS0
		delay(6000000);
		GPIO_SetBits(LED0_PORT, LED0_PIN);//熄灭DS0
		delay(6000000);
		GPIO_ResetBits(LED1_PORT, LED1_PIN);//点亮DS1
		delay(6000000);
		GPIO_SetBits(LED1_PORT, LED1_PIN);//熄灭DS1
		delay(6000000);
		
	}
	
}

