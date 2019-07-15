// exam6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	//enum season {spring,summer,fall,winter};
	enum season { spring=500, summer, fall, winter }; //열거형을 사용
	int a;
	season b;

	b = spring;
	a = spring;
	printf_s("%d, %d\n",a,b);
	a = 1;
	if (a == summer) {
		printf_s("여름\n");
	}
	else {
		printf_s("봄\n");
	}
    return 0;
}
