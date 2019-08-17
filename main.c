#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "timer.h"
int main(void)
 {		
 
	delay_init();	    	 //延时函数初始化 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	uart_init(115200);	 //串口初始化115200
 	LED_Init();			     
	TIM3_Int_Init(19999,7199);//10Khz的计数频率，计数到20000，为2s
   	while(1)
	{
			   
	}	 

 
}	 