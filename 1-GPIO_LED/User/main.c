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
		GPIO_ResetBits(LED0_PORT, LED0_PIN);//����DS0
		delay(6000000);
		GPIO_SetBits(LED0_PORT, LED0_PIN);//Ϩ��DS0
		delay(6000000);
		GPIO_ResetBits(LED1_PORT, LED1_PIN);//����DS1
		delay(6000000);
		GPIO_SetBits(LED1_PORT, LED1_PIN);//Ϩ��DS1
		delay(6000000);
		
	}
	
}

