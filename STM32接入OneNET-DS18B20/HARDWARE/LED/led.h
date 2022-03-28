#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define LED PCout(13)	// LED接口	

#define LED_OFF1	1
#define LED_ON1		0

void LED_Init(void);//初始化
			    
#endif
