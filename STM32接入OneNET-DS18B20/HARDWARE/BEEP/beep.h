#ifndef __BEEP_H
#define __BEEP_H	 
#include "sys.h"

#define BEEP_PORT		GPIOA
#define BEEP_RCC		RCC_APB2Periph_GPIOA
#define BEEP_PIN		GPIO_Pin_11
#define BEEP_PIN_MODE	GPIO_Mode_Out_PP

//�������˿ڶ���
#define BEEP PAout(11)	// BEEP,�������ӿ�		   

#define BEEP_OFF	1
#define BEEP_ON		0
void BEEP_Init(void);	//��ʼ��
		 				    
#endif

