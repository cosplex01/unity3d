#include <iostream>
#include "gameobject.h"
void initGmaeObject(S_gameObject* _obj, const char* szName, int nNameSize)//구조체 초기화하는 함수
{
	(*_obj).m_fSpeed = 5.0;
	_obj->m_fXpos = 2.0;
	_obj->m_fYpos = 2.5;
	_obj->m_nDamage = 6;
	_obj->m_nHitPoint = 4;

	_obj->m_szName = (char*)malloc(nNameSize + 1);
	strcpy_s(_obj->m_szName, nNameSize + 1, szName);
}
void releseGameObject(S_gameObject* _obj)
{
	free(_obj->m_szName);
}