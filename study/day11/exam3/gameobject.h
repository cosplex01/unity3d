#pragma once
struct S_gameObject {
	char* m_szName;
	int m_nDamage;
	int m_nHitPoint;
	double m_fSpeed;
	double m_fXpos, m_fYpos;
}; //����ü ����
void initGmaeObject(S_gameObject* _obj, const char* szName, int nNameSize);
void releseGameObject(S_gameObject* _obj);