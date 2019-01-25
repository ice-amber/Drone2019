#include "LED.h"
#include "stm32f10x.h"

void Led_On(GPIO_TypeDef*GPIOx,uint16_t GPIO_Pin)//推挽输出，引脚下拉点亮，需要结合电路图
{
	
	GPIOx->BRR = GPIO_Pin;
}

void Led_Off(GPIO_TypeDef*GPIOx,uint16_t GPIO_Pin)//推挽输出，引脚上拉熄灭，需要结合电路图
{
	
	GPIOx->BSRR = GPIO_Pin;
}

void Led_Reserve(GPIO_TypeDef*GPIOx,uint16_t GPIO_Pin)//led灯状态取反函数
{
	GPIOx->ODR ^= GPIO_Pin;
}







