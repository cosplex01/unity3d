// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include<stdio.h>
#include <iostream>
// 선언
int getStringLength(char strTemp[], int nBufSize); //공백없이 하나의 단어를 넣으면 그것의 배열공간을 확인

int main()
{
	char strTemp[256]; //문자열입력 버퍼용 변수
	char strTemp2[] = "hello";
	char strTemp3[] = "トランプ";

	printf_s("배열의 크기 : %d \n",sizeof(strTemp));
	printf_s("배열의 크기 : %d \n", sizeof(strTemp2));
	printf_s("배열의 크기 : %d \n", sizeof(strTemp3));

	printf_s("하나의 문장을 작성하세요\n");
	scanf_s("%s",strTemp,sizeof(strTemp));

	int nCount = getStringLength(strTemp, sizeof(strTemp));
	printf_s("입력한 문자열의 갯수는%d 개", nCount);
	return 0;
}
