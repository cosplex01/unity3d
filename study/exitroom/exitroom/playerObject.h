//#include "\makeP\cstudy\engine\tge.h"
#include "\cs2019\cstudy\engine\tge.h"

struct S_PlayerObject{
	double m_fXpos,m_fYpos;
	double m_fSpeed;
	char m_szName[64];
};
void initPlayerObject(S_PlayerObject* pObj, const char* pszName);
void releasePlayerObject(S_PlayerObject* pObj);
void DrawPlayerObject(S_PlayerObject* pObj, CHAR_INFO* pDrawBuff);
void applyPlayerObject(S_PlayerObject* pObj, double _fDelta, int* pMap);