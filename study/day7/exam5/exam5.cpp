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
	//문자열 복사 copy
	for (size_t i = 0; i < strlen(szBuf2)+1; i++)
	{
		szBuf2[i] = szBuf[i];
	}
	puts(szBuf2);
	return 0;
}
