#ifndef __BEEP_H
#define __BEEP_H	 
#include "sys.h"

#define BEEP_PORT		GPIOA
#define BEEP_RCC		RCC_APB2Periph_GPIOA
#define BEEP_PIN		GPIO_Pin_11
#define BEEP_PIN_MODE	GPIO_Mode_Out_PP

//蜂鸣器端口定义
#define BEEP PAout(11)	// BEEP,蜂鸣器接口		   

#define BEEP_OFF	1
#define BEEP_ON		0
void BEEP_Init(void);	//初始化
		 				    
#endif

