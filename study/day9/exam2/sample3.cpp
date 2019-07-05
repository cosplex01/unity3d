#include "..\..\..\cstudy\engine\tge.h"

void sample3()
{
	HANDLE _hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int _matObj1[4][4] = {
		0,1,0,0,
		1,0,1,0,
		0,1,0,0,
		1,1,1,0
	};

	system("cls"); //화면지우기 시도함
	TGE::g_chiBuffer[0].Char.AsciiChar = 'O';
	TGE::g_chiBuffer[0].Attributes = 0x00f6;
	
	/*
	for (int i = 0; i < 2000; i++) {
		TGE::g_chiBuffer[i].Char.AsciiChar = ' ';
		TGE::g_chiBuffer[i].Attributes = 0x00a0;
	}*/
	//(x,y) -> y*80+x
	TGE::g_chiBuffer[81].Char.AsciiChar = 'C'; //80*1 +1 ->(1,1)
	TGE::g_chiBuffer[81].Attributes = 0x00a4;
	//0.0에서 출력
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (_matObj1[y][x] == 1) {
				TGE::g_chiBuffer[y*80+x].Char.AsciiChar = 'C'; //80*1 +1 ->(1,1)
				TGE::g_chiBuffer[y*80+x].Attributes = 0x00a4;
			}
 		}
	}
	//10.0에서 출력
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (_matObj1[y][x] == 1) {
				int _nindex = (y+0) * 80 + (x+10);
				TGE::g_chiBuffer[_nindex].Char.AsciiChar = 'C'; //80*1 +1 ->(1,1)
				TGE::g_chiBuffer[_nindex].Attributes = 0x00a4;
			}
		}
	}
	//6.4에서 출력
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (_matObj1[y][x] == 1) {
				int _nindex = (y + 4) * 80 + (x + 6);
				TGE::g_chiBuffer[_nindex].Char.AsciiChar = 'C'; //80*1 +1 ->(1,1)
				TGE::g_chiBuffer[_nindex].Attributes = 0x00a4;
			}
		}
	}
	TGE::updateBuffer(_hStdout, TGE::g_chiBuffer);
}