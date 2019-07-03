#include "헤더.h"
#include <stdio.h>

int getStringLength(char *szBuf, int szBufsize)
{
	int check = 0;
	for (int i = 0; i < szBufsize; i++)
	{
		if (szBuf[i] != 0x00)
		{
			check++;
			printf_s("strTemp[%c]는 널문자가 아닌가?\n", szBuf[i]);
			printf_s("%08x,%d", szBuf[i], check);
		}
		else
		{
			break;
		}
	}
	return check;
}
