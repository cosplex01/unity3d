// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include<stdio.h>
#include <iostream>

int main()
{
	int val = 10;
	int* ip;
	
	ip = &val;
	printf_s("%d\n",*ip);
	printf_s("%p\n",ip);

	val = 3;
	printf_s("%d\n", *ip);

	int** ipp;
	ipp = &ip;
	val = 6;
	printf_s("%p\n", *ipp);
	return 0;
}