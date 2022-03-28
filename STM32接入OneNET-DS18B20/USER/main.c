//C��
#include <string.h>

//��Ƭ��ͷ�ļ�
#include "sys.h"

//����Э���
#include "onenet.h"

//�����豸
#include "esp8266.h"

//Ӳ������
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "ds18b20.h"
float temper;


//Ӳ����ʼ��
void Hardware_Init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	
	delay_init();			//��ʱ������ʼ��
	
	Usart1_Init(115200);	//����1��ʼ��Ϊ115200
	Usart2_Init(115200); 	//����2������ESP8266��
	LED_Init();				//LED��ʼ��
	
	while(DS18B20_Init())
	{
		printf("DS18B20���ʧ�ܣ�����!\r\n");
		delay_ms(1000);
	}
	printf("DS18B20���ɹ�!\r\n");
	
}

void Net_Init()
{
	ESP8266_Init();					//��ʼ��ESP8266
	
	while(OneNet_DevLink())			//����OneNET
		delay_ms(500);
	 LED = LED_ON1;					 //�����ɹ�
}

int main(void)
{
	unsigned char *dataPtr = NULL;
	unsigned short timeCount = 300;	//���ͼ������
	
	Hardware_Init();				//��ʼ����ΧӲ��
	Net_Init();						//�����ʼ��

	while(1)
	{	
		delay_ms(10);
		timeCount ++;
		
		if(timeCount >= 300)	//���ͼ��3s
		{	
			temper=DS18B20_GetTemperture();
			if(temper<0)
			{
				printf("�����¶�Ϊ��-");
			}
			else
			{
				printf("�����¶�Ϊ�� ");
			}
			printf("%.2f��C\r\n",temper);  //����1��ӡ�¶�����
			
			OneNet_SendData();	         //�ϴ����ݵ�ƽ̨
			
			timeCount = 0;
			ESP8266_Clear();
		}
		
		dataPtr = ESP8266_GetIPD(0);
		if(dataPtr != NULL)
		{
			OneNet_RevPro(dataPtr);     //��������
		}	
	}
}



















