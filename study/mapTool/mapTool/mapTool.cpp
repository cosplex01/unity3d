// mapTool.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "..\..\..\cstudy\engine\tge.h"
#include <iostream>

extern CHAR_INFO* pBackBuf; 
void applyEditor(HANDLE hStdout);
void changeCursorColor(int Color);

int main()
{
	int bLoop = true;

	HANDLE hStdout;
	TGE::startTGE(&hStdout);

	pBackBuf = TGE::CreateScreenBuffer(); // 맵상에서 계속 존재시킬것을 위한 임시버퍼생성
	TGE::clearScreenBuffer(pBackBuf, 0x0020, 0x0090); //가상버퍼를 클리어시킨다. 처음에
	//전체 맵사이즈는 80*25 이다
	while (bLoop)
	{
		if (TGE::input::g_KeyTable[VK_RETURN]) {
			//동기식 입력처리
			TGE::input::pauseInputThread();
			TGE::input::setEditMode();

			TGE::showCursor(hStdout);
			TGE::setCursor(hStdout, 0, 20);

			char szBuf[256];
			gets_s(szBuf);
			int tokenNum = TGE::Tokenize(szBuf);
			if (!strcmp("exit", TGE::g_szTokens[0])) {
				bLoop = false;
				puts("프로그램 종료");
			}
			else if(!strcmp("chgcolor", TGE::g_szTokens[0])) {
				changeCursorColor(
					atoi(TGE::g_szTokens[0])
				);
				puts("color");
			}
			else {
				puts("알수없는 명령어입니다");
			}
			//커서 다시 숨기기
			TGE::hideCursor(hStdout);
			TGE::input::g_KeyTable[VK_RETURN] = false;

			TGE::input::setEditMode();
			TGE::input::resumeInputThread();
		}
		applyEditor(hStdout);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}
	TGE::endTGE();
    return 0;
}