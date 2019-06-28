// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
int main()
	{
		char a, b;
		printf_s("문자2개 입력하세요: \n");
		scanf_s("%c", &a,sizeof(a));
		scanf_s("%c", &b, sizeof(b));
		printf_s("=> %c %c \n", a, b);

		return 0;
	}
