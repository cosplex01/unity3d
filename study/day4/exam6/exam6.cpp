// exam6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int num = -1;
	printf_s("%d, %u\n", num, num); //정수의 부호있고 없기를 출력하기 옵션

	double _pi = 3.1445926;
	printf_s("%d, %lf\n", (int)_pi, _pi); //실수의 표현을 생각한다

	printf_s("\\	A\tB	\\ \n");
}
