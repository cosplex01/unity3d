// mainMap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "C:\cs2019\unity3d\cstudy\engine\tge.h" // 사용할 엔진용 헤더파일 [엔진파일도 외부파일임]

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout); //내부에 초기화를 시킴

	int bLoop = true; 
	while (bLoop) //엔진 작동을 지속화
	{
		if (TGE::input::g_KeyTable[VK_RETURN]) //동기 커멘드모드 진입
		{
			TGE::input::pauseInputThread();//스레드멈춤
			TGE::input::setEditMode();

			//...동기식 코드
			char szBuf[256];
			gets_s(szBuf);
			int tokenNum = TGE::Tokenize(szBuf); //space 하나로 문장을 단어로 토큰화 자르기 함

			if (tokenNum > 0)
			{
				if (strcmp(TGE::g_szTokens[0], "exit") == 0)
				{
					bLoop = false; //엔진작동 지속화 종료
					puts("엔진종료 합니다");
				}
			}
			TGE::input::g_KeyTable[VK_RETURN] = false;//키버퍼 클리어
			TGE::input::setNormalMode();//비동기모드
			TGE::input::resumeInputThread();
		}
		printf_s("%d", TGE::input::g_KeyTable[VK_RETURN]);
	}

	TGE::endTGE(); //엔진종료
    return 0;
}