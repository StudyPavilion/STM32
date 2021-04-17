#include "led.h"

void LED_Init()
{
	
	GPIO_InitTypeDef GPIO_Initstructure;
	RCC_APB2PeriphClockCmd(LED0_PORT_RCC|LED1_PORT_RCC, ENABLE);
	//��������ʱ��
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_Out_PP;
	//����Ϊ�������
	GPIO_Initstructure.GPIO_Pin = LED0_PIN;
	//ѡ�����LED0������
	GPIO_Initstructure.GPIO_Speed = GPIO_Speed_50MHz;
	//ѡ���ٶ�
	GPIO_Init(LED0_PORT, &GPIO_Initstructure);
	//��ʼ��LED1����
	GPIO_SetBits(LED0_PORT, LED0_PIN);
	//�Ƚ�LED0������1��������
	
	GPIO_Initstructure.GPIO_Pin = LED1_PIN;
	//ѡ�����LED1������
	GPIO_Init(LED1_PORT, &GPIO_Initstructure);
	//��ʼ��LED2����
	GPIO_SetBits(LED1_PORT, LED1_PIN);
	//�Ƚ�LED1������1��������
}
