// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 

	int num, num2;
	double num3;
	char _a;
	char _strTemp[256];
	char _szBuf[256] = "128 254 12.2 S 행운을빕니다";

	sscanf_s(_szBuf, "%d %d %lf %c %s", &num, &num2, &num3, &_a,sizeof(_a), _strTemp,sizeof(_strTemp)); //입력소스는 버퍼에서 받는다

	printf_s("%d %d %lf %c %s", num, num2, num3, _a, _strTemp);
}

