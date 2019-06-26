// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <stdio.h>
#include <Windows.h>
#include <iostream>

int main()
{
	int gibonyogum = 660;
	double sayongyogum = 88.5;
	double zoncheyogum = 0.0;
	int sayongyang = 1;
	double segum = 0.0;
	double gojiseryogum = 0.0;
	CHAR texts[800] = ""; //lpcwstr 형식변환을 위해서 char행렬변수 생성
	TCHAR text[600] = {0, }; //lpcwstr 형식변환을 위해서 tchar행렬변수 생성

	//printf_s("두개의 수를 입력하시오");
	printf_s("전기사용량을 입력하세요(kw)");
	scanf_s("%d", &sayongyang); // 사용량 확인

	zoncheyogum = gibonyogum + (sayongyang * sayongyogum); //전체요금 계산
	segum = zoncheyogum * 0.09; // 세금계산

	gojiseryogum = zoncheyogum + segum;
	printf_s("전기사용요금은 %lf 원 입니다\n", gojiseryogum);

	sprintf_s(texts,"전기요금은 이것입니다: %d\n", (int)gojiseryogum);
	
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, texts, strlen(texts), text, 256); //lpcwstr형변환시도
	MessageBox(NULL, text, TEXT("정보창"), MB_OK);
	
	return 0;
}
