#include <iostream>
#include <stdio.h>
#include <Windows.h>

int main()
{
	char _cmd;
	int _bLoop = 1;
	int _nMoney = 100;
	int _nMoneyPower = 1;

	// 스크린 버퍼를 불러와서 스크린에 일정부분의 컬러를 변경합니다
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	if (GetConsoleScreenBufferInfo(hConsole, &csbInfo) == 0)
	{
		printf_s("스크린 버퍼를 얻지 못했는데\n");
	}
	
	WORD wOldColor = csbInfo.wAttributes;// 스크린버퍼에 이용할 변수를 초기화 해야 합니다

	while (_bLoop)
	{
		printf_s("커멘드 입력 (도움말 h)\n");
		scanf_s("\n%c", &_cmd,sizeof(_cmd));
		int ___jakupsu = 0;
			
		/* else
		{
			
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
		*/
		switch (_cmd)
		{
			
		case 'q':
			SetConsoleTextAttribute(hConsole, 0xf4);//1111 0100 흰색바탕의 빨간글씨
			_bLoop = 0; printf_s("\n종료합니다\n");
			SetConsoleTextAttribute(hConsole, wOldColor); //변경처리후 되돌리기
			break;
		case 'l':
			SetConsoleTextAttribute(hConsole, 0xfc);//1111 1001 흰색바탕의 빨간글씨
			_bLoop = 0; printf_s("\n치료방법이 구현되지 않았어, 종료합니다\n");
			SetConsoleTextAttribute(hConsole, wOldColor); //변경처리후 되돌리기
			break;
		case 'u':
			SetConsoleTextAttribute(hConsole, 0x09);//0000 1001 blue
			_bLoop = 0; printf_s("\n사냥터가 아직 없어서 종료합니다\n");
			SetConsoleTextAttribute(hConsole, wOldColor); //변경처리후 되돌리기
			break;
		case 'g':
			SetConsoleTextAttribute(hConsole, 0x0a);//0000 1010 green
			_bLoop = 1; printf_s("\n아이템을 주웠습니다. 그런데...\n");
			SetConsoleTextAttribute(hConsole, wOldColor); //변경처리후 되돌리기
			_nMoney = _nMoney+20;
			break;
		case 'h':
			_bLoop = 1; 
			SetConsoleTextAttribute(hConsole, 0x0c);//1001 1100 red
			printf_s("m. 돈벌기\n");
			printf_s("l. 치료하기\n");
			printf_s("u. 사냥하기\n");
			printf_s("g. 아이템 줍기\n");
			printf_s("q. 종료하기\n");
			SetConsoleTextAttribute(hConsole, wOldColor); //변경처리후 되돌리기
			break;
		case 'm':
			_bLoop = 1; printf_s("m. 돈벌기 작업 시도함\n");
			_nMoney = _nMoney + _nMoneyPower;
			printf_s("%d원을 벌었네요\n",_nMoney);
			SetConsoleTextAttribute(hConsole, wOldColor); //변경처리후 되돌리기
			break;
		default:
			_bLoop = 1;
			SetConsoleTextAttribute(hConsole, wOldColor); //변경처리후 되돌리기
			break;
		}
		
	}
	return 0;
}