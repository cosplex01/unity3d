// exam7.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <iostream>

int main()
{
	char _szBuf[256];
	char* pTempNext = NULL; //문자열 기억공간용 포인터변수
	int _bLoop = true;

	// 명령어 인자1 인자2 인자3
	while (_bLoop)
	{
		char _cmd[256];
		gets_s(_szBuf,sizeof(_szBuf));
		strcpy_s(_cmd,strtok_s(_szBuf," ",&pTempNext));

		if (strcmp(_cmd, "exit")) {
			_bLoop = false;
			puts("종료합니다");
		}
		else {
			printf_s("%s 는 알수없는 명령어입니다\n",_cmd);
		}
	}
    return 0;
}
