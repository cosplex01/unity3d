// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

int main()
{
	int num = 10;
	int num2 = 50;
	int pyungyun = 0;
	//...
	num = 20;
	num = num2;

	//scanf_s("%d", &num);
	//printf_s("%d \n", num);
	printf_s("정수2개를 입력하시오 (구분은 공백으로)\n");
	scanf_s("%d%d", &num, &num2);
	printf_s("%d %d\n", num, num2);

	printf_s("정수2개를 입력하시오 (구분은 /으로)\n");
	scanf_s("%d/%d", &num, &num2);
	printf_s("%d %d\n", num, num2);

	printf_s("정수2개를 입력하시오 - 평균을 구하기 위함\n");
	scanf_s("%d/%d", &num, &num2);
	pyungyun = (num + num2) / 2;

	printf_s("첫째수%d 둘째수%d 평균%d\n", num, num2, pyungyun);


	return num;
}