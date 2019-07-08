// firstmenu.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include<Windows.h>
#include <iostream>
#include<stdio.h>

char _cmd;
int _bLoop = true;
int _nMoney = 100;
int _nMoneyPower = 1;

void MainGame()
{
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (GetConsoleScreenBufferInfo(hConsole, &csbInfo) == 0)
	{
		printf_s("스크린 버퍼를 얻지 못했는데\n");
	}
	WORD wOldColor = csbInfo.wAttributes;// 스크린버퍼에 이용할 변수를 초기화 해야 합니다

	while (_bLoop)
	{
		printf_s("커멘드 입력 (도움말 h)\n");
		scanf_s("\n%c", &_cmd, sizeof(_cmd));
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
			_nMoney = _nMoney + 20;
			break;
		case 'h':
			_bLoop = 1;
			SetConsoleTextAttribute(hConsole, 0x0c);//1001 1100 red
			printf_s("m. 체력단련\n");
			printf_s("l. 치료하기\n");
			printf_s("u. 사냥하기\n");
			printf_s("g. 아이템 줍기\n");
			printf_s("q. 종료하기\n");
			SetConsoleTextAttribute(hConsole, wOldColor); //변경처리후 되돌리기
			break;
		case 'm':
			_bLoop = 1; printf_s("m. 돈벌기 작업 시도함\n");
			_nMoney = _nMoney + _nMoneyPower;
			printf_s("%d원을 벌었네요\n", _nMoney);
			SetConsoleTextAttribute(hConsole, wOldColor); //변경처리후 되돌리기
			break;
		default:
			_bLoop = 1;
			SetConsoleTextAttribute(hConsole, wOldColor); //변경처리후 되돌리기
			break;
		}
	}
}
void gotoxy(int x, int y) //커서위치를 지정한다
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void makeCoverline() //맨처음 화면을 작성한다
{
	gotoxy(9, 5); puts("Magical Girl Spec-Ops Asuka");
	gotoxy(9, 8); puts("거대한 운석이 지구앞에서 폭발을 일으키고"); 
	gotoxy(9, 9); puts("세상에 나타는 명수라는 존재는 인류에게 있어서 두려움의 대상이었다");
	gotoxy(9, 11); puts("어느날 세상에 나타난 하나의 불꽃이 어둠을 몰아내기 시작하였다");
	gotoxy(9, 12); puts("그 불꽃은 후일 페아토라고 불리우고 있었다");
	gotoxy(9, 14); puts("명수들은 페아토에게 패하여 점점 세상에서 사라져갔다");
	gotoxy(9, 15); puts("페아토는 명수에게 맞설 무기를 인류에게 주기로 약속을 한다");
	gotoxy(9, 18); puts("이것은 그 이후의 이야기이다");

	for (int x = 0; x < 79; x++) {
		gotoxy(x, 2); printf_s("M");
		gotoxy(x, 20); printf_s("M");
	} //첫 메뉴의 경계선을 그린다	

	gotoxy(2, 22); //게임 시작을 위해서 커서를 옮김
}

int main()
{
	makeCoverline();
	MainGame();

	return 0;
}