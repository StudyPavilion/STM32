#include "stm32f10x.h"
#include "led.h"
#include "SysTick.h"
#include "beep.h"
#include "key.h"

int main()
{
	u8 key,i=0;
	
	SysTick_Init(72);
	LED_Init();						//��ʼ��LED
	BEEP_Init();					//��ʼ��������
	KEY_Init();						//������ʼ��
	
	while(1)
	{
		key=KEY_Scan(0);
		switch(key)
		{
			case KEY_UP_PRESS: 	LED1=0;break;		//����DS1��
			case KEY0_PRESS: 		LED1=1;break;		//Ϩ��DS1��
			case KEY1_PRESS: 		BEEP=1;break;		//��������
			case KEY2_PRESS: 		BEEP=0;break;		//��������
		}
		i++;
		if(i%20==0)
		{
			LED0=!LED0;
		}
		delay_ms(10);

	}
	
}

