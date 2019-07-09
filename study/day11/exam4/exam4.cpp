// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include "gameobject.h"
int main()
{
	S_gameObject* pObj[8];
	pObj[0] = (S_gameObject*)malloc(sizeof(S_gameObject));
	initGmaeObject(pObj[0], "player1", sizeof("player1"));

	pObj[1] = (S_gameObject*)malloc(sizeof(S_gameObject));
	initGmaeObject(pObj[1], "오키나와", sizeof("오키나와"));

	for (int i = 0; i < 2; i++)
	{
		printf_s("%s \n",pObj[i]->m_szName);
		releseGameObject(pObj[i]);
	}
   return 0;
}