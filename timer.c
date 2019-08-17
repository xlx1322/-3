#include "timer.h"
#include "led.h"

void TIM3_Int_Init(u16 arr,u16 psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //Ê±ÖÓÊ¹ÄÜ
	
	//TIM3³õÊ¼»¯
	TIM_TimeBaseStructure.TIM_Period = arr; //×Ô¶¯ÖØ×°¼Ä´æÆ÷ÖÜÆÚµÄÖµ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //Ô¤·ÖÆµÖÖµ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //ÉèÖÃÊ±ÖÓ·Ö¸î:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM3ÏòÉÏ¼ÆÊıÄ£Ê½
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //??????????TIMx???????
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //Ê¹ÄÜÖ¸¶¨µÄTIM3ÖĞ¶Ï£¬ÔÊĞí¸üĞÂÖĞ¶Ï

	//ÖĞ¶ÏÓÅÏÈ¼¶NVICÉèÖÃ
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3ÖĞ¶Ï
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //ÏÈÕ¼ÓÅÏÈ¼¶0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //´ÓÓÅÏÈ¼¶3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ±»Ê¹ÄÜ
	NVIC_Init(&NVIC_InitStructure);  //³õÊ¼»¯NVIC¼Ä´æÆ÷


	TIM_Cmd(TIM3, ENABLE);  //ÖĞ¶ÏTIM3					 
}
//TIM3ÖĞ¶Ï·şÎñ
void TIM3_IRQHandler(void)   //TIM3??
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //ÊÇ·ñ·¢Éú¸üĞÂÖĞ¶Ï
		{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //Çå³ı¸üĞÂÖĞ¶Ï±êÖ¾ 
		LED1=!LED1;
		}
}
