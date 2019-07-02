// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <iostream>
#include <Windows.h>
const int g_cScreenBufsize = 64; //25*80으로 스크린버퍼를 지정한다

void _put(CHAR_INFO chiBuffer[],int x, int y)
{
	//unicode 의 속성을 적용한다
	//첫번째 바이트는 케릭터 좌우선택
	//두번째 바이트는 컬러속성 컬러체계는 8421->irgb
	system("cls");
	chiBuffer[(y * 4 + x) * 2].Char.UnicodeChar = 0x25A0;
	chiBuffer[(y * 4 + x) * 2].Attributes = COMMON_LVB_LEADING_BYTE | 0x006f;

	chiBuffer[(y * 4 + x) * 2 + 1].Char.UnicodeChar = 0x25A0;
	chiBuffer[(y * 4 + x) * 2 + 1].Attributes = COMMON_LVB_TRAILING_BYTE | 0x006f;
}
int main()
{
	system("cls");
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); //스크린 핸들러
	CHAR_INFO chiBuffer[g_cScreenBufsize];

	//초기화	
	for (int i = 0; i < g_cScreenBufsize / 2; i++)
	{
		//unicode 의 속성을 적용한다
		//첫번째 바이트는 케릭터 좌우선택
		//두번째 바이트는 컬러속성 컬러체계는 8421->irgb
		chiBuffer[i * 2].Char.UnicodeChar = 0x00;//0x25ce;//text('◎');좌측반절
		chiBuffer[i * 2].Attributes = COMMON_LVB_LEADING_BYTE | 0x009f; //첫번째 왼쪽 표시
		chiBuffer[i * 2 + 1].Char.UnicodeChar = 0x00;// 0x25ce; //text('◎');오른쪽반절
		chiBuffer[i * 2 + 1].Attributes = COMMON_LVB_TRAILING_BYTE | 0x009f; //첫번째 오른쪽 나머지 절반표시
	}
	
	_put(chiBuffer,1,2);
	_put(chiBuffer,1,3);
	_put(chiBuffer,1,4);

	SMALL_RECT destRect; //위치지정
	destRect.Top = 0;
	destRect.Left = 0;
	destRect.Bottom= 7;
	destRect.Right = 7;

	WriteConsoleOutput(
		hStdout,
		chiBuffer,
		{8,8},
		{ 0,0 },
		&destRect); //콘솔에 지정위치로 뿌려라
	
	return 0;
}