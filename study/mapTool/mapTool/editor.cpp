#include "..\..\..\cstudy\engine\tge.h"

int cursor_x = 0;
int cursor_y = 0;
int cursorAttr = 0xf0;

CHAR_INFO* pBackBuf;
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

void applyEditor(HANDLE hStdout)
{
	TGE::clearScreenBuffer(0x0020, 0x00f0); //화면버퍼 클리어
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
		TGE::setCharacter(TGE::g_chiBuffer, cursor_x, cursor_y, 0x00c0, cursorAttr); //커서선택하여 그리기
		TGE::input::g_KeyTable[VK_SPACE] = false;
	}
	TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf); //가상 버퍼에 스크린버퍼 복사해둠[더블 버퍼링 트릭]
	TGE::setCharacter(TGE::g_chiBuffer, cursor_x, cursor_y, 0x00c0, cursorAttr); //커서선택하여 그리기
}