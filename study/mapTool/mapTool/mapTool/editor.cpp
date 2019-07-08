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
		0xc0,0x40,//���� ����, ��ο� ����
		0xa0,0x20,//���� ���, ��ο� ���
		0x90,0x10, //���� �Ķ�, ��ο� �Ķ�
		0xf0,0x80 //���� ����, ��ο� ����
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
	//TGE::clearScreenBuffer(0x0020, 0x00f0); //ȭ����� Ŭ����
	//TGE::setCharacter(TGE::g_chiBuffer, cursor_x, cursor_y, 0x0020, 0x00f0); //Ŀ�������Ͽ� �׸���

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
		TGE::setCharacter(pBackBuf, cursor_x, cursor_y, 0x00c0, cursorAttr); //Ŀ�������Ͽ� �׸���[������ۿ� �׸���]
		TGE::input::g_KeyTable[VK_SPACE] = false;
	}
		
	TGE::drawLineH(cursor_x, cursor_y, nlength, 0x00c0, 0x0090);
	TGE::drawLineV(cursor_x, cursor_y, nlength, 0x00c0, 0x0090);

	TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf); //���� ���ۿ� ��ũ������ �����ص�[���� ���۸� Ʈ��]
	TGE::setCharacter(TGE::g_chiBuffer, cursor_x, cursor_y, 0x00c0, 0x00f0); //Ŀ�������Ͽ� �׸���
	
	TGE::setCursor(hStdout, 0, 26);
	printf_s("Ŀ������:%-4d,%-4d,%-4d\n",cursor_x,cursor_y,cursorAttr);
	makeCoverline(); // ���ڸ� ������
}