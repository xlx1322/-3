#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "timer.h"
int main(void)
 {		
 
	delay_init();	    	 //��ʱ������ʼ�� 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	uart_init(115200);	 //���ڳ�ʼ��115200
 	LED_Init();			     
	TIM3_Int_Init(19999,7199);//10Khz�ļ���Ƶ�ʣ�������20000��Ϊ2s
   	while(1)
	{
			   
	}	 

 
}	 