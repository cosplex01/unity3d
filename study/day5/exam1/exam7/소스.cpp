#include <iostream>
#include<Windows.h>
int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;

	if (GetConsoleScreenBufferInfo(hConsole, &csbInfo) == 0)
	{
		printf_s("스크린 버퍼를 얻지 못했는데\n");
	}
	else
	{
		WORD wOldColor = csbInfo.wAttributes;
		SetConsoleTextAttribute(hConsole, 0x0c);//1001 1100 red
		printf_s("하이요\n");
		SetConsoleTextAttribute(hConsole, 0x0a);//0000 1010 green
		printf_s("하이요\n");
		SetConsoleTextAttribute(hConsole, 0x09);//0000 1001 blue
		printf_s("하이요\n");
		SetConsoleTextAttribute(hConsole, 0xfc);//1111 1001 흰색바탕의 빨간글씨
		printf_s("하이요\n");
		SetConsoleTextAttribute(hConsole, 0xf4);//1111 0100 흰색바탕의 빨간글씨
		printf_s("하이요\n");

		SetConsoleTextAttribute(hConsole, wOldColor); //변경처리후 되돌리기
	}
	return 0;
}