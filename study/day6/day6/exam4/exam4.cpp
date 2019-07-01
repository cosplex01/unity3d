// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
//반환값 함수들
int sumint(int num1, int num2);
int subInt(int num1, int num2);
int multiInt(int num1, int num2);
int divideInt(int num1, int num2);
//반환값 없는 함수들
void _Sum(int a, int b);
void _Minus(int num1, int num2);
void _Multi(int num1, int num2);
void _Devide(int num1, int num2);
void calculator(); //사칙연산을 통합 담당할 함수

int main()
{
	printf_s("수를 계산하기 위해서 계산식을 넣으세요 : ex> a+b \n");
	calculator();

	return 0;
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
void _Sum(int num1, int num2)
{
	printf_s("두수의 합은 : %d\n",sumint(num1,num2));
}
void _Minus(int num1, int num2)
{
	printf_s("두수의 뺄셈은 : %d\n", subInt(num1, num2));
}
void _Multi(int num1, int num2)
{
	printf_s("두수의 곱은 : %d\n", multiInt(num1, num2));
}
void _Devide(int num1, int num2)
{
	printf_s("두수의 나눈 몫은 : %d\n", divideInt(num1, num2));
}
void calculator() //사칙연산 계산
{
	int result;
	result = sumint(4, 6);
	int number1, number2 = 0;
	char check;
	
	printf_s("%d\n", result);
	scanf_s("%d%c%d", &number1, &check, sizeof(check), &number2);
	
	switch (check)
	{
	case '+':
		result = sumint(number1, number2);
		printf_s("%d + %d = %d\n", number1, number2, result);
		_Sum(number1, number2);
		break;
	case '-':
		result = subInt(number1, number2);
		printf_s("%d - %d = %d\n", number1, number2, result);
		_Minus(number1, number2);
		break;
	case '/':
		result = divideInt(number1, number2);
		printf_s("%d / %d = %d\n", number1, number2, result);
		_Devide(number1, number2);
		break;
	case '*':
		result = multiInt(number1, number2);
		printf_s("%d * %d = %d\n", number1, number2, result);
		_Multi(number1, number2);
		break;
	default:
		printf_s("입력식이 문제라니깐~");
		break;
	}
}