#include "rtc.h"

extern char* Int2String(int num,char *str);
extern	RTC_DateTypeDef sdatestructure;
extern	RTC_TimeTypeDef stimestructure;

extern 	char Y[5],M[2],D[2],H[2],Min[2],Sec[2];

void ReadTime(char *Y,char *M,char *D,char *H,char *Min,char *Sec);

void ReadTime(char *Y,char *M,char *D,char *H,char *Min,char *Sec)
{
		HAL_RTC_GetTime(&hrtc, &stimestructure, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &sdatestructure, RTC_FORMAT_BIN);
		Int2String(sdatestructure.Year,Y);
		Int2String(sdatestructure.Month,M);
		Int2String(sdatestructure.Date,D);
		Int2String(stimestructure.Hours,H);
		Int2String(stimestructure.Minutes,Min);
		Int2String(stimestructure.Seconds,Sec);
}
