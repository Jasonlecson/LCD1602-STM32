#include "gpio.h"
#include "string.h"

void Lcd_Init(void);
void Lcd_WriteCom(char com);
void Lcd_WriteData(char data);
void printf_lcd(char *word1st,char *word2nd);
void Write_First(void);
void Write_Second(void);

void Lcd_Init()
{
	Lcd_WriteCom(0x38);
	Lcd_WriteCom(0x0c);
	Lcd_WriteCom(0x06);
	Lcd_WriteCom(0x01);
}

void Write_First()
{
	Lcd_WriteCom(0x80);
}

void Write_Second()
{
	Lcd_WriteCom(0x80+0x40);
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

void printf_lcd(char *word1st,char *word2nd)
{
	Lcd_Init();
	Write_First();
	while(*word1st){
	Lcd_WriteData(*(word1st++));
	}
	Write_Second();
	while(*word2nd){
	Lcd_WriteData(*(word2nd++));
	}
}
