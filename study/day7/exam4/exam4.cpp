// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "heder.h"
#include <iostream>
char szBuf[256];

int main()
{
	int _bLoop = true; //1, false 0

	while (_bLoop)
	{
		int _cmd; scanf_s("%d", &_cmd);
		switch (_cmd)
		{
		case 0:_bLoop = false; puts("종료합니다");break;
		case 1:
		{
			displayBuf(szBuf,sizeof(szBuf));
		} break;
		case 2: 
		{
			puts("문자열을 입력하세요"); getchar(); gets_s(szBuf, sizeof(szBuf));
		}break;
		case 3:
		{
			int nindex;
			char ch; 
			scanf_s("%d %c",&nindex,&ch,1);
			insertChar(szBuf, sizeof(szBuf), nindex, ch);
		}break;
		default:break;
		}
	}
	return 0;
}
