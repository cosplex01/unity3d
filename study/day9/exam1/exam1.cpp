// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "..\..\..\cstudy\engine\tge.h"
#include <iostream>
void test();
void sample1();
void sample1_1();
void sample1_2();
void sample2();
void sample3();

extern int globalNumber; //어느파일에 있는 변수를 사용함[프로젝트 소스중에 하나에 있어야 하는 변수]

int main()
{
	int bLoop = true;

	while (bLoop)
	{
		char szBuf[256];
		gets_s(szBuf);
		int tokenNum = TGE::Tokenize(szBuf);
		if (!strcmp("exit",TGE::g_szTokens[0]))
		{
			bLoop = false;
			puts("exit");
		}
		else if (!strcmp("showValue", TGE::g_szTokens[0]))
		{
			printf_s("globalNum : %d\n",globalNumber);
		}
		else if(!strcmp("call", TGE::g_szTokens[0]))
		{
			if (!strcmp("test", TGE::g_szTokens[1]))
			{
				test();
			}
			else if (!strcmp("sample1", TGE::g_szTokens[1]))
			{
				sample1();
			}
			else if (!strcmp("sample2", TGE::g_szTokens[1]))
			{
				sample2();
			}
			else if (!strcmp("sample3", TGE::g_szTokens[1]))
			{
				sample3();
			}
		}
	}
    return 0;
}