// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

int sumint(int num1, int num2);
int subInt(int num1, int num2);
int multiInt(int num1, int num2);
int divideInt(int num1, int num2);

int main()
{
	int result;
	result = sumint(4, 6);
	int number1,number2 = 0;
	char check;

	printf_s("%d\n", result);

	printf_s("%d\n",sumint(2,3));
	printf_s("%d\n",sumint(4,3));
	printf_s("%d\n",sumint(5,3));

	printf_s("%d\n", subInt(2, 3));
	printf_s("%d\n", subInt(4, 3));
	printf_s("%d\n", subInt(5, 3));

	printf_s("수를 계산하기 위해서 계산식을 넣으세요 : ex> a+b \n");
	scanf_s("%d%c%d", &number1, &check,sizeof(check), &number2);

	switch(check)
	{
		case '+':
			result = sumint(number1,number2);
			printf_s("%d + %d = %d\n", number1, number2, result);
			break;
		case '-':
			result = subInt(number1, number2);
			printf_s("%d - %d = %d\n", number1, number2, result);
			break;
		case '/':
			result = divideInt(number1,number2);
			printf_s("%d / %d = %d\n", number1, number2, result);
			break;
		case '*':
			result =  multiInt(number1,number2);
			printf_s("%d * %d = %d\n", number1, number2, result);
			break;
		default:
			printf_s("입력식이 문제라니깐~");
			break;
	}
}
int sumint(int num1, int num2) //+
{
	int num3 = num1 + num2;
	return num3;
}
int subInt(int num1, int num2) //-
{
	int num3 = num1 - num2;
	return num3;
}
int multiInt(int num1, int num2)//*
{
	int num3 = num1 * num2;
	return num3;
}
int divideInt(int num1, int num2)// /
{
	int num3 = num1 / num2;
	return num3;
}