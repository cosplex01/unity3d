// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include<stdio.h>
#include <iostream>

int main()
{
	int _nlndex = 0;
	while (1)
	{
		if (_nlndex > 10)
		{
			printf_s("계산가능해?");
			break;
		}
		if (_nlndex % 2) //2로 나누어 떨어지지 않으면
		{
			_nlndex++;
			continue;
		}
		/*
		else
		{
			printf_s("%d \n",_nlndex);
			_nlndex++;
		}
		*/
		printf_s("%d \n", _nlndex);
		_nlndex++;
	}
	return 0;
}