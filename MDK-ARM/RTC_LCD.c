#include "rtc.h"

extern	RTC_DateTypeDef sdatestructure;
extern	RTC_TimeTypeDef stimestructure;

void ReadTime(void);

void ReadTime()
{
		HAL_RTC_GetTime(&hrtc, &stimestructure, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &sdatestructure, RTC_FORMAT_BIN);
}

