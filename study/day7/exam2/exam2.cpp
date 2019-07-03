// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "헤더.h"

int main()
{
	char szBuf[256];
	int check = 0;
	gets_s(szBuf, sizeof(szBuf));

	check = getStringLength(szBuf, sizeof(szBuf));
	printf_s("문자열의 버퍼공간%d\n",check);
	printf_s("%s\n",szBuf);
	
	return 0;
}