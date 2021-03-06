/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "rtc.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
	char word1[] = "Hello Sako !";
	char word2[] = "1139 Days";
	char word3[] = "Since we've meet.";
	char word4[] = "762 Days";
	char word5[] = "Since we've chat.";
	char word6[] = "72 Days";
	char word7[] = "Fallen in love.";
	char word8[] = "24 Hours";
	char word9[] = "Together a Day.";
	char word10[] = "We had quarrel";
	char word11[] = "Never breakup";
	char word12[] = "We had suspect";
	char word13[] = "Never unhappy";
	char word14[] = "I was choosen";
	char word15[] = "only For You.";
	char word16[] = "The shortest poe";
	char word17[] = "m Is your name.";
	char word18[] = "To be your hero";
	char word19[] = "Away the Pain.";
	char word20[] = "I know I love";
	char word21[] = "Only You";
	char word22[] = "   I love You";
	char word23[] = "3 thousand times";
	char blank[] = " ";
	char colon[] = ":";
	char line[] = "/";
	RTC_DateTypeDef sdatestructure;
	RTC_TimeTypeDef stimestructure;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
	void Lcd_Init(void);
	void Lcd_WriteData(char);
	void printf_lcd_words(char *,char *);
	void ReadTime(char *,char *,char *,char *,char *,char *);
	void printf_lcd_time(char *,char *,char *,char *,char *,char *,char *,char *,char *,char *,char *,char *);
	char* Int2String(int,char *);
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */

	char Y[5],M[2],D[2],H[2],Min[2],Sec[2];

//	char time[] = {(2000+sdatestructure.Year), sdatestructure.Month, sdatestructure.Date,
//								stimestructure.Hours, stimestructure.Minutes, stimestructure.Seconds};
	printf_lcd_words(word1,blank);
	HAL_Delay(2500);
	printf_lcd_words(word2,word3);
	HAL_Delay(2500);
	printf_lcd_words(word4,word5);
	HAL_Delay(2500);
	printf_lcd_words(word6,word7);
	HAL_Delay(2500);
	printf_lcd_words(word8,word9);
	HAL_Delay(2500);
	printf_lcd_words(word10,word11);
	HAL_Delay(2500);
	printf_lcd_words(word12,word13);
	HAL_Delay(2500);
	printf_lcd_words(word14,word15);
	HAL_Delay(2500);
	printf_lcd_words(word16,word17);
	HAL_Delay(2500);
	printf_lcd_words(word18,word19);
	HAL_Delay(2500);
	printf_lcd_words(word20,word21);
	HAL_Delay(2500);
	printf_lcd_words(word22,word23);
	HAL_Delay(1500);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		HAL_Delay(1000);
		
		ReadTime(Y,M,D,H,Min,Sec);
		printf_lcd_time(word22,Y,line,M,line,D,blank,H,colon,Min,colon,Sec);


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
