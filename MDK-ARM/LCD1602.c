#include "gpio.h"


void Lcd_Init(void);
void Lcd_WriteCom(char com);
void Lcd_WriteData(char data);

void Lcd_Init()
{
	Lcd_WriteCom(0x38);
	Lcd_WriteCom(0x0c);
	Lcd_WriteCom(0x06);
	Lcd_WriteCom(0x01);
	Lcd_WriteCom(0x80);
}

void Lcd_WriteCom(char com)
{
	HAL_GPIO_WritePin((GPIO_TypeDef *)GPIOG, (uint16_t) GPIO_PIN_6, (GPIO_PinState) 1); //E
	HAL_GPIO_WritePin((GPIO_TypeDef *)GPIOG, (uint16_t) GPIO_PIN_4, (GPIO_PinState) 0); //RS
	HAL_GPIO_WritePin((GPIO_TypeDef *)GPIOG, (uint16_t) GPIO_PIN_5, (GPIO_PinState) 0); //RW
	GPIOD->ODR = com;
	HAL_Delay(1);
	HAL_GPIO_WritePin((GPIO_TypeDef *)GPIOG, (uint16_t) GPIO_PIN_6, (GPIO_PinState) 0); //E
}

void Lcd_WriteData(char data)
{
	HAL_GPIO_WritePin((GPIO_TypeDef *)GPIOG, (uint16_t) GPIO_PIN_6, (GPIO_PinState) 1); //E
	HAL_GPIO_WritePin((GPIO_TypeDef *)GPIOG, (uint16_t) GPIO_PIN_4, (GPIO_PinState) 1); //RS
	HAL_GPIO_WritePin((GPIO_TypeDef *)GPIOG, (uint16_t) GPIO_PIN_5, (GPIO_PinState) 0); //RW
	GPIOD->ODR = data;
	HAL_Delay(1);
	HAL_GPIO_WritePin((GPIO_TypeDef *)GPIOG, (uint16_t) GPIO_PIN_6, (GPIO_PinState) 0); //E
}
