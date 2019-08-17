#include "timer.h"
#include "led.h"

void TIM3_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //ʱ��ʹ��
	
	//TIM3��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //�Զ���װ�Ĵ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //Ԥ��Ƶ�ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM3���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //??????????TIMx???????
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM3�жϣ����������ж�

	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ��ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���


	TIM_Cmd(TIM3, ENABLE);  //�ж�TIM3					 
}
//TIM3�жϷ���
void TIM3_IRQHandler(void)   //TIM3??
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //�Ƿ��������ж�
		{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //��������жϱ�־ 
		LED1=!LED1;
		}
}