#include "timer.h"
#include "led.h"

void TIM3_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能
	
	//TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //自动重装寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //预分频种�
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM3向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //??????????TIMx???????
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断，允许更新中断

	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器


	TIM_Cmd(TIM3, ENABLE);  //中断TIM3					 
}
//TIM3中断服务
void TIM3_IRQHandler(void)   //TIM3??
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //是否发生更新中断
		{
		LED1=!LED1;
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //清除更新中断标志 
		}
}
