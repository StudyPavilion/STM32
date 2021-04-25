#include "key.h"
#include "SysTick.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_Initstructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE, ENABLE);//����ʱ��
	
	GPIO_Initstructure.GPIO_Pin=KEY_UP_PIN;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_Init(KEY_UP_PORT, &GPIO_Initstructure);	//��������
	
	GPIO_Initstructure.GPIO_Pin=KEY0_PIN|KEY1_PIN|KEY2_PIN;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_IPU;		//��������
	GPIO_Init(KEY_PORT, &GPIO_Initstructure);

}

u8 KEY_Scan(u8 mode)
{
	static u8 key=1;
	
	if(mode==1)	//������������
		key=1;
	if(key==1&&(KEY_UP==1||KEY0==0||KEY1==0||KEY2==0))	//����һ����������
	{
		delay_ms(10);		//����
		if(KEY_UP==1)
			return KEY_UP_PRESS;
		else if(KEY0==0)
			return KEY0_PRESS;
		else if(KEY1==0)
			return KEY1_PRESS;
		else if(KEY2==0)
			return KEY2_PRESS;
	}
	else if(KEY_UP==1||KEY0==0||KEY1==0||KEY2==0)			//�ް�������
		key=1;
	return 0;
}
