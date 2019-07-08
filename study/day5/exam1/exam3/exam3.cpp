// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h> 
int main()
{
	int num = 45;
	int _input = 32;
	printf_s("숫자 맞추기 시도합니다,숫자를 입력해 주세요:\n");
	scanf_s("%d",&_input);

	if (num == _input) {
		printf_s("숫자 맞추기 했습니다\n");
	}
	if (num != _input) {
		printf_s("숫자 맞추기 실패했습니다\n");
	}
	if (num <= _input) {
		printf_s("숫자가 큽니다\n");
	}
	else {
		printf_s("숫자가 작습니다\n");
	}
	printf_s("종료합니다\n");

	return 0;
}