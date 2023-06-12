#include "exti_key.h"
#include "misc.h"


void EXTI_Key_Init(void)
{
    
		EXTI_InitTypeDef EXTI_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE);//开启PA3和PA4的时钟，并开启复用时钟
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_4;
	  
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB,&GPIO_InitStructure);//GPIO初始化配置:PA3和PA4
	
	
   
    
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);//NVIC初始化配置
    
		
   
    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure); //NVIC初始化配置
    
		
	
    
	
 
    EXTI_ClearITPendingBit(EXTI_Line1); //清楚中断线路3和44的挂起
		EXTI_ClearITPendingBit(EXTI_Line4); //清楚中断线路3和44的挂起
		
		
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);//外部中断配置函数，，连接GPIO和中断
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource4);//外部中断配置函数，，连接GPIO和中断
     
		 
    EXTI_InitStructure.EXTI_Line = EXTI_Line1;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
		EXTI_InitStructure.EXTI_LineCmd = ENABLE ;
		
    EXTI_Init(&EXTI_InitStructure);//使能外部中断线路3
		
		
		
		
		 EXTI_InitStructure.EXTI_Line = EXTI_Line4;//使能外部中断线路4
		 EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
		 EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
		 EXTI_InitStructure.EXTI_LineCmd = ENABLE ; 
		EXTI_Init(&EXTI_InitStructure);
                

}
    


  
