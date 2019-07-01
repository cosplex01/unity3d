// cursorControl.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>
#include <stdio.h>

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	printf_s("하로~미라이 아카리다요");

	COORD _pos;
	_pos.X = 10;
	_pos.Y = 7;

	SetConsoleCursorPosition(hStdout, _pos);
	SetConsoleTextAttribute(hStdout, 0x9e); //0x9e컬러를 적용합니다
	printf_s("그런작업은 그만둬");

	_pos.X = 18;
	_pos.Y = 20;

	int num;
	SetConsoleCursorPosition(hStdout, _pos);
	scanf_s("%d", &num);
	SetConsoleTextAttribute(hStdout, 0x0f); //0x0f컬러를 적용합니다

	int _ix, _iy = 0;
	for(_iy=0; _iy < 16; _iy++)
	{
		for (_ix = 20; _ix < 28; _ix++)
		{
			//특정위치를 지정함
			_pos.X = _ix;
			_pos.Y = _iy;
			//커서를 표시하면서 색깔도 지정
			SetConsoleCursorPosition(hStdout, _pos);
			SetConsoleTextAttribute(hStdout, 0xae);
			printf_s(" ");
		}
	}

	SetConsoleTextAttribute(hStdout, 0x07); // 초기 색깔로 돌립니다
	return 0;
}
