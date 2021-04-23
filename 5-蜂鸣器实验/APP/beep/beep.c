#include "beep.h"

void BEEP_Init(void)
{
	GPIO_InitTypeDef GPIO_Initstructure;
	RCC_APB2PeriphClockCmd(BEEP_PORT_RCC, ENABLE);
	
	GPIO_Initstructure.GPIO_Pin=BEEP_PIN;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(BEEP_PORT, &GPIO_Initstructure);
	
	GPIO_ResetBits(BEEP_PORT, BEEP_PIN);
}
