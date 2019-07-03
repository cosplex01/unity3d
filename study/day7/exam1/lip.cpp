#include <stdio.h>
int getStringLength(char strTemp[], int nBufSize) //공백이 없는 하나의 단어를 입력받는것
{
	int check = 0;
	for (int i = 0; i < nBufSize; i++)
	{
		if (strTemp[i] != 0x00)
		{
			check++;
			printf_s("strTemp[%c]는 널문자가 아닌가?\n", strTemp[i]);
			printf_s("%08x,%d", strTemp[i], check);
		}
		else
		{
			break;
		}
	}
	return check;
}