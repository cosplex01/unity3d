#include <stdio.h>
int getStringLength(char* szBuf, int szBufsize)
{
	int check = 0;
	for (int i = 0; i < szBufsize; i++)
	{
		if (szBuf[i] != 0x00)
		{
			check++;
			printf_s("strTemp[%c]�� �ι��ڰ� �ƴѰ�?\n", szBuf[i]);
			printf_s("%08x,%d", szBuf[i], check);
		}
		else
		{
			break;
		}
	}
	return check;
}
void displayBuf(char strTemp[], int nBufsize)
{
	if (getStringLength(strTemp, nBufsize) <= 0)
	{
		puts("���ڿ��Դϴ�");
	}
	else puts(strTemp);
}
void insertChar(char szBuf[], int nBufSize, int nindex, char ch)
{
	szBuf[nindex] = ch;

}