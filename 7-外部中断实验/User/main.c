#include "stm32f10x.h"
#include "led.h"
#include "SysTick.h"
#include "beep.h"
#include "key.h"
#include "exti.h"


int main()
{
	u8 i=0;
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	LED_Init();						//��ʼ��LED
	BEEP_Init();					//��ʼ��������
	KEY_Init();						//������ʼ��
	My_EXTI_init();
	
	while(1)
	{
		
		i++;
		if(i%20==0)
		{
			LED0=!LED0;
		}
		delay_ms(10);

	}
	
}

