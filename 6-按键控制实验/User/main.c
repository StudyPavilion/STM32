#include "stm32f10x.h"
#include "led.h"
#include "SysTick.h"
#include "beep.h"
#include "key.h"

int main()
{
	u8 key,i=0;
	
	SysTick_Init(72);
	LED_Init();						//初始化LED
	BEEP_Init();					//初始化蜂鸣器
	KEY_Init();						//按键初始化
	
	while(1)
	{
		key=KEY_Scan(0);
		switch(key)
		{
			case KEY_UP_PRESS: 	LED1=0;break;		//点亮DS1灯
			case KEY0_PRESS: 		LED1=1;break;		//熄灭DS1灯
			case KEY1_PRESS: 		BEEP=1;break;		//蜂鸣器开
			case KEY2_PRESS: 		BEEP=0;break;		//蜂鸣器关
		}
		i++;
		if(i%20==0)
		{
			LED0=!LED0;
		}
		delay_ms(10);

	}
	
}

