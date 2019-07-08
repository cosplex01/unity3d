//#include "..\..\..\..\cstudy\engine\tge.h"
#include "\makeP\cstudy\engine\tge.h"
#include <Windows.h>

int cursor_x = 0;
int cursor_y = 0;
int cursorAttr = 0xf0;
int nlength = 0;
CHAR_INFO* pBackBuf;

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void changeCursorColor(int nColor)
{
	int _Table[] = {
		0x00,
		0xc0,0x40,//밝은 빨간, 어두운 빨간
		0xa0,0x20,//밝은 녹색, 어두운 녹색
		0x90,0x10, //밝은 파란, 어두운 파란
		0xf0,0x80 //밝은 빨강, 어두운 빨강
	};
	cursorAttr = _Table[nColor];
}
void changeLine(int line)
{
	nlength = line;
}
void makeCoverline()
{
	for (int x = 0; x < 79; x++) {
		gotoxy(x, 0); printf_s("M");
		gotoxy(x, 27); printf_s("M");
	}
}
void applyEditor(HANDLE hStdout)
{
	//TGE::clearScreenBuffer(0x0020, 0x00f0); //화면버퍼 클리어
	//TGE::setCharacter(TGE::g_chiBuffer, cursor_x, cursor_y, 0x0020, 0x00f0); //커서선택하여 그리기

	if (TGE::input::g_KeyTable[VK_UP]) {
		cursor_y--;
		TGE::input::g_KeyTable[VK_UP] = false;
	}
	if (TGE::input::g_KeyTable[VK_DOWN]) {
		cursor_y++;
		TGE::input::g_KeyTable[VK_DOWN] = false;
	}
	if (TGE::input::g_KeyTable[VK_LEFT]) {
		cursor_x--;
		TGE::input::g_KeyTable[VK_LEFT] = false;
	}
	if (TGE::input::g_KeyTable[VK_RIGHT]) {
		cursor_x++;
		TGE::input::g_KeyTable[VK_RIGHT] = false;
	}
	if (TGE::input::g_KeyTable[VK_SPACE]) {
		TGE::setCharacter(pBackBuf, cursor_x, cursor_y, 0x00c0, cursorAttr); //커서선택하여 그리기[가상버퍼에 그리기]
		TGE::input::g_KeyTable[VK_SPACE] = false;
	}
		
	TGE::drawLineH(cursor_x, cursor_y, nlength, 0x00c0, 0x0090);
	TGE::drawLineV(cursor_x, cursor_y, nlength, 0x00c0, 0x0090);

	TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf); //가상 버퍼에 스크린버퍼 복사해둠[더블 버퍼링 트릭]
	TGE::setCharacter(TGE::g_chiBuffer, cursor_x, cursor_y, 0x00c0, 0x00f0); //커서선택하여 그리기
	
	TGE::setCursor(hStdout, 0, 26);
	printf_s("커서상태:%-4d,%-4d,%-4d\n",cursor_x,cursor_y,cursorAttr);
	makeCoverline(); // 글자를 보여줌
}