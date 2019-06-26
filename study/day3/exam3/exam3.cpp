// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <stdio.h>

int main()
{
	int gibonyogum = 660;
	double sayongyogum = 88.5;
	double zoncheyogum = 0.0;
	int sayongyang = 1;
	double segum = 0.0;
	double gojiseryogum = 0.0;

	//printf_s("두개의 수를 입력하시오");
	printf_s("전기사용량을 입력하세요(kw)");
	scanf_s("%d", &sayongyang); // 사용량 확인

	zoncheyogum = gibonyogum + (sayongyang * sayongyogum); //전체요금 계산
	segum = zoncheyogum * 0.09; // 세금계산

	gojiseryogum = zoncheyogum + segum;
	printf_s("전기사용요금은 %lf 원 입니다\n", gojiseryogum);

	//result = (num1 + num2) / 2.0;

	//printf_s("결과는 :%lf\n",result);

//	printf_s("결과는 :%d\n", result);

	//printf_s("결과는 :%ld\n", ((int)(&num1) - (int)(&num2)));

	return 0;
}
