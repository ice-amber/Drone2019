#include "LED.h"
#include "stm32f10x.h"


void led_GPIO_configFunc(uint32_t RCC_APB2Periph_GPIOx, GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_Initstructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOx,ENABLE);
	
	/*#define RCC_APB2Periph_GPIOA             ((uint32_t)0x00000004)
    #define RCC_APB2Periph_GPIOB             ((uint32_t)0x00000008)
    #define RCC_APB2Periph_GPIOC             ((uint32_t)0x00000010)
    #define RCC_APB2Periph_GPIOD             ((uint32_t)0x00000020)
    #define RCC_APB2Periph_GPIOE             ((uint32_t)0x00000040)
    #define RCC_APB2Periph_GPIOF             ((uint32_t)0x00000080)
    #define RCC_APB2Periph_GPIOG             ((uint32_t)0x00000100)
	*/
	
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin=GPIO_Pin;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_Initstructure);
	
	GPIO_SetBits(GPIOx,GPIO_Pin);
}



void Led_On(GPIO_TypeDef*GPIOx,uint16_t GPIO_Pin)//推挽输出，引脚下拉点亮，需要结合电路图
{
	GPIO_ResetBits(GPIOx,GPIO_Pin);
}

void Led_Off(GPIO_TypeDef*GPIOx,uint16_t GPIO_Pin)//推挽输出，引脚上拉熄灭，需要结合电路图
{
	GPIO_SetBits(GPIOx,GPIO_Pin);
}

void Led_Reserve(GPIO_TypeDef*GPIOx,uint16_t GPIO_Pin)//led灯状态取反函数
{
	GPIO_WriteBit(GPIOx, GPIO_Pin, (BitAction) (1 -
	 GPIO_ReadOutputDataBit(GPIOx, GPIO_Pin)));
}







