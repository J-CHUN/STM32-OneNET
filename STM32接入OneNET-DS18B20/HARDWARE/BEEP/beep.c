#include "beep.h"

//初始化PB8为输出口.并使能这个口的时钟		    
//蜂鸣器初始化
void BEEP_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(BEEP_RCC, ENABLE);	 //使能GPIOA端口时钟
	
	GPIO_InitStructure.GPIO_Pin = BEEP_PIN;				 //BEEP-->PA.11 端口配置
	GPIO_InitStructure.GPIO_Mode = BEEP_PIN_MODE; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //速度为50MHz
	GPIO_Init(BEEP_PORT, &GPIO_InitStructure);	 //根据参数初始化GPIOA.11

	BEEP = BEEP_OFF;//输出1，关闭蜂鸣器输出
}
