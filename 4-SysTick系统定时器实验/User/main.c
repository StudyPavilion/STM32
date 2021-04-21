#include "stm32f10x.h"
#include "led.h"
#include "SysTick.h"

void delay(u32 i)//��ʱ����
{
	while(i--);
}

int main()
{
	SysTick_Init(72);
	LED_Init();//��ʼ��LED
	while(1)
	{
		LED0=0;
		LED1=1;
		delay_ms(1000);  //��ȷ��ʱ1000ms
		LED0=1;
		LED1=0;
		delay_ms(1000);  //��ȷ��ʱ1000ms
	}
	
}

