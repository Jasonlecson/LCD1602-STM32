char* Int2String(int num,char *str);

char* Int2String(int num,char *str)
{
	int i = 0;
	if(num<0)
	{
		num = -num;
		str[i++] = '-';
	} 

	do
	{
		str[i++] = num%10+48;
		num /= 10;
	}while(num);
	
	str[i] = '\0';
	
 
	int j = 0;
	if(str[0]=='-')
	{
		j = 1;
		++i;
	}
	for(;j<i/2;j++)
	{
		str[j] = str[j] + str[i-1-j];
		str[i-1-j] = str[j] - str[i-1-j];
		str[j] = str[j] - str[i-1-j];
	} 
	
	return str;
}
