// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include<stdio.h>
#include <iostream>

int main()
{
	int nums[5];

	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d",&nums[i]); //배열변수 안에 입력을 받아서 누적한다
	}
	printf_s("입력완료됨\n");

	for (int i = 0; i < 5; i++)
	{
		printf_s("%d\n", nums[i]); //배열을 이용해서 출력한다
	}
	printf_s("출력완료됨\n");

	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum = sum + nums[i]; //배열을 이용해서 재귀덧셈 한다
	}
	printf_s("입력한 전체의 합은 : %d\n",sum);
	return 0;
}