// exam6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	char _szBuf[256] = "mondiang tuhyung kimdeji";
	char* _szToken[32];//문자열 포인터용 배열
	char* pNextToken = NULL;
	
	_szToken[0] = strtok_s(_szBuf," ",&pNextToken);
	puts(_szToken[0]);
	puts(pNextToken);

	_szToken[1] = strtok_s(NULL, " ", &pNextToken);
	puts(_szToken[1]);
	puts(pNextToken);

	_szToken[2] = strtok_s(NULL, " ", &pNextToken);
	puts(_szToken[2]);
	puts(pNextToken);

	strcpy_s(_szBuf, "뭘봐요 이보세요");

	char _token[256];
	strcpy_s(_token, sizeof(_token),strtok_s(_szBuf," ",&pNextToken));
	puts(_token);

	int num;
	char szTemp[256];
	sscanf_s(pNextToken,"%d %s",&num,szTemp,sizeof(szTemp));
  return 0;
}