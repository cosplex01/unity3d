// tge_exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <stdio.h>
#include "..\..\..\cstudy\engine\tge.h"
int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);

	//char szTokens[8][TGE::MAX_TOKEN_SIZE];
	char szBuf[256];
	int bLoop = true;
	while(bLoop)
	{
		if (TGE::input::g_KeyTable[VK_RETURN])
		{
			TGE::input::pauseInputThread();//쓰레드를 동기입력 모드
			TGE::input::setEditMode();

			TGE::showCursor(hStdout); //커서 표시
			TGE::setCursor(hStdout, 0, 1); //커서의 위치 지정

			gets_s(szBuf,sizeof(szBuf)); //입력을 받고
			if (!strcmp(szBuf,"exit"))
			{
				bLoop = false;
				puts("종료합니다");
			}
			//puts(szBuf);

			TGE::input::resumeInputThread();//쓰레드 비동기모드로 변경
			TGE::input::setNormalMode();
			TGE::input::g_KeyTable[VK_RETURN]; //재입력 방지
		}

		TGE::setCursor(hStdout, 0, 0);
		printf_s("U%-4dD%-4dL%-4dR%-4d",
			TGE::input::g_KeyTable[VK_UP],
			TGE::input::g_KeyTable[VK_DOWN],
			TGE::input::g_KeyTable[VK_LEFT],
			TGE::input::g_KeyTable[VK_RIGHT]
		);

		puts("cls"); //화면 클리어
	}

	TGE::endTGE();
    return 0;
}
