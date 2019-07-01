// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>
#include <stdio.h>

int main()
{
	int j = 0;
	int dan = 0;
	for (dan = 1; dan <= 9; dan++)
	{
		for (j = 1; j <= 9; j++)
		{
			printf_s("%d * %d = %d \t", dan, j, dan * j);
		}
		printf_s("표시줄 전환\n");
	}
	return 0;
}