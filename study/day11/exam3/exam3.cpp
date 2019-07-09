// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include "gameobject.h"

int main()
{
	S_gameObject* pObject;
	pObject = (S_gameObject*)malloc(sizeof(S_gameObject));
	const char* szName = "war★nurse쿠루미";

	initGmaeObject(pObject,szName,strlen(szName));
	printf_s("%s -- %f -- %d\n", pObject->m_szName, pObject->m_fXpos, pObject->m_nDamage);
	releseGameObject(pObject);
    return 0;
}