#include "stm32f10x.h"
#include "led.h"


void delay(u32 i)//��ʱ����
{
	while(i--);
}

int main()
{
	LED_Init();//��ʼ��LED
	
	while(1)
	{
		LED0=0;
		//����DS0
		delay(6000000);
		LED0=1;
		//Ϩ��DS0
		delay(6000000);
		LED1=0;
		//����DS1
		delay(6000000);
		LED1=1;
		//Ϩ��DS1
		delay(6000000);
		
	}
	
}

