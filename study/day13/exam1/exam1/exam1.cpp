// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include "c:\\cs2019\\cstudy\\engine\\tge.h"

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);

	bool bLoop = true;

	while (bLoop) {
		TGE::setCursor(hStdout, 0, 0);
		printf_s("%8d,%8d,Mouse:%8x\n",TGE::input::g_cdMousePos.X, TGE::input::g_cdMousePos.Y,
			TGE::input::g_dwButtonState); //마우스의 위치값 받아오기
		if (TGE::input::g_dwButtonState == 4) // 휠버튼을 누른다면
		{
			bLoop = false;
		}
	}
	TGE::showCursor(hStdout);
	TGE::endTGE();
  return 0;
}
