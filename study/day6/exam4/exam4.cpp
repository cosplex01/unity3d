﻿// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <iostream>

int main()
{
	int _Map[] = {
		1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1
	};

	for (int iy = 0; iy < 8; iy++) {
		for (int ix = 0; ix < 8; ix++) {
			int _cell = _Map[(iy * 8) + ix];
			if (_cell == 0) { printf_s(" "); }
			else if (_cell == 1) { printf_s("^"); }
			//printf_s("%d", _Map[(iy*8) + ix]);
		}
		printf_s("\n");
	}
	return 0;
}