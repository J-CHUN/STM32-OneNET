#include "beep.h"

//��ʼ��PB8Ϊ�����.��ʹ������ڵ�ʱ��		    
//��������ʼ��
void BEEP_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(BEEP_RCC, ENABLE);	 //ʹ��GPIOA�˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin = BEEP_PIN;				 //BEEP-->PA.11 �˿�����
	GPIO_InitStructure.GPIO_Mode = BEEP_PIN_MODE; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //�ٶ�Ϊ50MHz
	GPIO_Init(BEEP_PORT, &GPIO_InitStructure);	 //���ݲ�����ʼ��GPIOA.11

	BEEP = BEEP_OFF;//���1���رշ��������
}
