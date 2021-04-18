#ifndef _led_h
#define _led_h

#include "stm32f10x.h"
#include "system.h"

void LED_Init(void);

#define LED0_PORT_RCC 		RCC_APB2Periph_GPIOB
#define LED0_PIN  				GPIO_Pin_5
#define LED0_PORT					GPIOB

#define LED1_PORT_RCC 		RCC_APB2Periph_GPIOE
#define LED1_PIN  				GPIO_Pin_5
#define LED1_PORT					GPIOE

#define LED0 							PBout(5)  	
#define LED1 							PEout(5)  	

#endif
