#include "led.h"

void LED_Init()
{
	
	GPIO_InitTypeDef GPIO_Initstructure;
	RCC_APB2PeriphClockCmd(LED0_PORT_RCC|LED1_PORT_RCC, ENABLE);
	//开启两灯时钟
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//设置为推挽输出
	GPIO_Initstructure.GPIO_Pin = LED0_PIN;
	//选择控制LED0的引脚
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	//选择速度
	GPIO_Init(LED0_PORT, &GPIO_Initstructure);
	//初始化LED1配置
	GPIO_SetBits(LED0_PORT, LED0_PIN);
	//先将LED0引脚置1，即灯灭
	
	GPIO_Initstructure.GPIO_Pin = LED1_PIN;
	//选择控制LED1的引脚
	GPIO_Init(LED1_PORT, &GPIO_Initstructure);
	//初始化LED2配置
	GPIO_SetBits(LED1_PORT, LED1_PIN);
	//先将LED1引脚置1，即灯灭
}
