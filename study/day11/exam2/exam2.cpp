// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <iostream>

struct S_gameObject {
	char* m_szName;
	int m_nDamage;
	int m_nHitPoint;
	double m_fSpeed;
	double m_fXpos, m_fYpos;
}; //구조체 지정

void initGmaeObject(S_gameObject *_obj,const char *szName, int nNameSize)//구조체 초기화하는 함수
{
	(*_obj).m_fSpeed = 5.0;
	_obj->m_fXpos = 2.0;
	_obj->m_fYpos = 2.5;
	_obj->m_nDamage = 6;
	_obj->m_nHitPoint = 4;
	
	_obj->m_szName = (char*)malloc(nNameSize+1);
	strcpy_s(_obj->m_szName, nNameSize+1, szName);
}
void releseGameObject(S_gameObject* _obj)
{
	free(_obj->m_szName);
}
int main()
{
	S_gameObject myObj;
	const char* pTestName = "렙처☆아스카";
	initGmaeObject(&myObj,pTestName,strlen(pTestName));
	
	printf_s("%s --- %d --- %f \n",myObj.m_szName, myObj.m_nDamage, myObj.m_fXpos);
	releseGameObject(&myObj);
    return 0;
}