#include "stm32f10x.h"
#include "led.h"
#include "SysTick.h"
#include "beep.h"


void delay(u32 i)//��ʱ����
{
	while(i--);
}

int main()
{
	SysTick_Init(72);
	LED_Init();						//��ʼ��LED
	BEEP_Init();					//��ʼ��������

	
	while(1)
	{
		LED0=!LED0;					//DS0��ʼΪ�͵�ƽ
		BEEP=1;							//�������ߵ�ƽ��Ч
		delay_ms(400);			//��ȷ��ʱ400ms
		BEEP=0;							//��������0
		delay_ms(1600);			//��ȷ��ʱ1600ms

	}
	
}

