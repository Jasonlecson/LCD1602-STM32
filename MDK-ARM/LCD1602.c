#include "gpio.h"
#include "string.h"

void Lcd_Init(void);
void Lcd_WriteCom(char com);
void Lcd_WriteData(char data);
void printf_lcd_words(char *word1st,char *word2nd);
void printf_lcd_time(char *love,char *Y,char *A,char *M,char *B,char *D,char *blank,char *H,char *C,char *Min,char *E,char *Sec);
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

void printf_lcd_words(char *word1st,char *word2nd)
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

void printf_lcd_time(char *love,char *Y,char *A,char *M,char *B,char *D,char *blank,char *H,char *C,char *Min,char *E,char *Sec)
{
	Lcd_Init();
	Write_First();
	while(*love){
	Lcd_WriteData(*(love++));
	}
	Write_Second();
	while(*Y){
	Lcd_WriteData(*(Y++));
	}
	while(*A){
	Lcd_WriteData(*(A++));
	}
	while(*M){
	Lcd_WriteData(*(M++));
	}
	while(*B){
	Lcd_WriteData(*(B++));
	}
	while(*D){
	Lcd_WriteData(*(D++));
	}
	while(*blank){
	Lcd_WriteData(*(blank++));
	}
	while(*H){
	Lcd_WriteData(*(H++));
	}
	while(*C){
	Lcd_WriteData(*(C++));
	}
	while(*Min){
	Lcd_WriteData(*(Min++));
	}
	while(*E){
	Lcd_WriteData(*(E++));
	}
	while(*Sec){
	Lcd_WriteData(*(Sec++));
	}

}
