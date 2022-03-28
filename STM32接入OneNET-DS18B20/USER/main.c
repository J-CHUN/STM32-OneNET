//C库
#include <string.h>

//单片机头文件
#include "sys.h"

//网络协议层
#include "onenet.h"

//网络设备
#include "esp8266.h"

//硬件驱动
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "ds18b20.h"
float temper;


//硬件初始化
void Hardware_Init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	
	delay_init();			//延时函数初始化
	
	Usart1_Init(115200);	//串口1初始化为115200
	Usart2_Init(115200); 	//串口2，驱动ESP8266用
	LED_Init();				//LED初始化
	
	while(DS18B20_Init())
	{
		printf("DS18B20检测失败，请插好!\r\n");
		delay_ms(1000);
	}
	printf("DS18B20检测成功!\r\n");
	
}

void Net_Init()
{
	ESP8266_Init();					//初始化ESP8266
	
	while(OneNet_DevLink())			//接入OneNET
		delay_ms(500);
	 LED = LED_ON1;					 //入网成功
}

int main(void)
{
	unsigned char *dataPtr = NULL;
	unsigned short timeCount = 300;	//发送间隔变量
	
	Hardware_Init();				//初始化外围硬件
	Net_Init();						//网络初始化

	while(1)
	{	
		delay_ms(10);
		timeCount ++;
		
		if(timeCount >= 300)	//发送间隔3s
		{	
			temper=DS18B20_GetTemperture();
			if(temper<0)
			{
				printf("检测的温度为：-");
			}
			else
			{
				printf("检测的温度为： ");
			}
			printf("%.2f°C\r\n",temper);  //串口1打印温度数据
			
			OneNet_SendData();	         //上传数据到平台
			
			timeCount = 0;
			ESP8266_Clear();
		}
		
		dataPtr = ESP8266_GetIPD(0);
		if(dataPtr != NULL)
		{
			OneNet_RevPro(dataPtr);     //接收命令
		}	
	}
}



















