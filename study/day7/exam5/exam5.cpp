// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <iostream>

int main()
{
	char szBuf[256] = "헤이 와이어";
	char szBuf2[256] = "월드월드 월드콘";
	printf_s("문자열크기 :%d\n",strlen(szBuf));

	puts(szBuf);
	puts(szBuf2);
	//문자열 복사 copy
	for (size_t i = 0; i < strlen(szBuf2)+1; i++)
	{
		szBuf2[i] = szBuf[i];
	}
	puts(szBuf2);
	
	strcpy_s(szBuf, sizeof(szBuf), szBuf2);
	puts(szBuf2);

	// 비교
	if (strcmp(szBuf, szBuf2) == 0)
	{
		puts("일치합니다");
	}
	else
	{
		puts("서로다릅니다");
	}

	int Equel = true;
	for (size_t i = 0; i < strlen(szBuf); i++)
	{
		if (szBuf[i] != szBuf2[i])
		{
			Equel = false;
			break;
		}
	}
	if(Equel)
	{
		puts("일치합니다");
	}
	else
	{
		puts("서로다릅니다");
	}
	return 0;
}
