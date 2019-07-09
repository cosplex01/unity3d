// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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

int main()
{
	S_gameObject t47TankObj;//instans 지정

	char szTemp[256] = { 1 };
	gets_s(szTemp);
	// 문자열의 길이 구하고 길이만큼 메모리 할당하여 문자열 대입
	int nLength = strnlen_s(szTemp, sizeof(szTemp));
	t47TankObj.m_szName = (char *)malloc(sizeof(nLength+1));
	strcpy_s(t47TankObj.m_szName, nLength+1,szTemp);

	t47TankObj.m_nDamage = 15;
	t47TankObj.m_fSpeed = 5.7;
	t47TankObj.m_nHitPoint = 3;
	t47TankObj.m_fXpos = 1;
	t47TankObj.m_fYpos = 0;

	printf_s("name : %s\n", t47TankObj.m_szName);
	printf_s("speed : %f\n", t47TankObj.m_fSpeed);
	printf_s("충격량 : %d\n", t47TankObj.m_nHitPoint);
	printf_s("위치 : 맵의 X축%f,Y축%f 에 있습니다\n", t47TankObj.m_fXpos, t47TankObj.m_fYpos);
	free(t47TankObj.m_szName);

 return 0;
}