#include "exti.h"
#include "key.h"
#include "beep.h"


void My_EXTI_init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	
	//开启复用时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

	//选择GPIO管脚用作外部中断线路
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);
	
	//EXTI0  配置
	EXTI_InitStructure.EXTI_Line=EXTI_Line0;								//中断线路
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;				//中断模式
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;		//上升沿触发
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;									//线路使能
	EXTI_Init(&EXTI_InitStructure);													//完成初始化
	
	EXTI_InitStructure.EXTI_Line=EXTI_Line2|EXTI_Line3|EXTI_Line4;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;	
	EXTI_Init(&EXTI_InitStructure);

	//EXTI0 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel=EXTI0_IRQn;					//EXTI0中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;	//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=3;				//响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;						//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);													//完成初始化
	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);	

	NVIC_InitStructure.NVIC_IRQChannel=EXTI3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);	

	NVIC_InitStructure.NVIC_IRQChannel=EXTI2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);	
	
}

void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0)==1)
	{
		//delay_ms(10);
		if(KEY_UP==1)
		{
			BEEP=1;
		}	
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
}

void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4)==1)
	{
		//delay_ms(10);
		if(KEY0==0)
		{
			BEEP=0;
		}	
	}
	EXTI_ClearITPendingBit(EXTI_Line4);
}

void EXTI3_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line3)==1)
	{
		//delay_ms(10);
		if(KEY1==0)
		{
			BEEP=0;
		}	
	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}

void EXTI2_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line2)==1)
	{
		//delay_ms(10);
		if(KEY2==0)
		{
			BEEP=0;
		}	
	}
	EXTI_ClearITPendingBit(EXTI_Line2);
}
