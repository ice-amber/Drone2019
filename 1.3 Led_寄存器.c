#include "LED.h"
#include "stm32f10x.h"

void Led_On(GPIO_TypeDef*GPIOx,uint16_t GPIO_Pin)//�������������������������Ҫ��ϵ�·ͼ
{
	
	GPIOx->BRR = GPIO_Pin;
}

void Led_Off(GPIO_TypeDef*GPIOx,uint16_t GPIO_Pin)//�����������������Ϩ����Ҫ��ϵ�·ͼ
{
	
	GPIOx->BSRR = GPIO_Pin;
}

void Led_Reserve(GPIO_TypeDef*GPIOx,uint16_t GPIO_Pin)//led��״̬ȡ������
{
	GPIOx->ODR ^= GPIO_Pin;
}







