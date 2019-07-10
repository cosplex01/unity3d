//#include "\makeP\cstudy\engine\tge.h"
#include "\cs2019\cstudy\engine\tge.h"
#include "playerObject.h"
#include <iostream>

int map[2000];

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);
	TGE::hideCursor(hStdout);

	S_PlayerObject playerObj;
	initPlayerObject(&playerObj, "����");

	int bLoop = true;

	UINT64 ddwTick = TGE::util::GetTimeMs64();
	UINT64 accTick = 0;

	CHAR_INFO* pBackBuf = TGE::CreateScreenBuffer();
	TGE::loadBufferBinary(pBackBuf, "level1.map");
	//TGE::clearScreenBuffer(pBackBuf, 0x0020, 0x0000);

	int regenPosX, regenPosY;

	for (int iy = 0; iy < 25; iy++)
	{
		for (int ix = 0; ix < 80; ix++)
		{
			int nlndex = iy * 80 + ix;

			if (pBackBuf[nlndex].Attributes == 0xF0) {
				map[nlndex] = 1;
			}
			else if (pBackBuf[nlndex].Attributes == 0x40) {
				regenPosX = ix;
				regenPosY = iy;
			}
			else {
				map[nlndex] = 0;
			}
		}
	}
	//free(pBackBuf);

	playerObj.m_fXpos = regenPosX;
	playerObj.m_fYpos = regenPosY;

	while (bLoop) {

		if (TGE::input::g_KeyTable[VK_RETURN]) {
			//����� �Է� ó�� 
			TGE::input::pauseInputThread();
			TGE::input::setEditMode();

			TGE::showCursor(hStdout);
			TGE::setCursor(hStdout, 0, 27);
			char szBuf[256];
			gets_s(szBuf, sizeof(szBuf));

			int tokenNum = TGE::Tokenize(szBuf); //TGE::g_szTokens �� ��ū ���� 
			if (tokenNum > 0) {
				if (!strcmp(TGE::g_szTokens[0], "exit")) {
					bLoop = false;
					TGE::setCursor(hStdout, 0, 26);
					puts("�����մϴ�.");
				}
				else {
					TGE::setCursor(hStdout, 0, 27);
					puts("                        ");

				}
			}
			//Ŀ�� �ٽ� ����� 
			TGE::hideCursor(hStdout);
			TGE::input::g_KeyTable[VK_RETURN] = false;

			TGE::input::setNormalMode();
			TGE::input::resumeInputThread();
		}

		UINT64 _deltaTick = TGE::util::GetTimeMs64() - ddwTick;
		ddwTick = TGE::util::GetTimeMs64();
		accTick += _deltaTick;

		applyPlayerObject(&playerObj, _deltaTick / 1000.0, map); //�Է� ó�� , �ൿ�� ����ó�� 

		TGE::clearScreenBuffer(TGE::g_chiBuffer, 0x0020, 0x0000);

		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf);//��� �׸���
		DrawPlayerObject(&playerObj, TGE::g_chiBuffer); //������� ĳ���� �׸��� 
		//TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf);//��� �׸���

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer); //�츮���� ���̰� �Ǵ� ����

		TGE::setCursor(hStdout, 0, 26);

		printf_s("%4.2f,%4.2f   %llu      \n", playerObj.m_fXpos, playerObj.m_fYpos, accTick);

		int _chrposIndex = (int)playerObj.m_fYpos * 80 + (int)playerObj.m_fXpos;

		printf_s("  %x    \n", pBackBuf[_chrposIndex].Attributes);
	}

	TGE::endTGE();

	free(pBackBuf);
	releasePlayerObject(&playerObj);

	return 0;
}