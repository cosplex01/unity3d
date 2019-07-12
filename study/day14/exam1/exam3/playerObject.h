//#include "\makeP\cstudy\engine\tge.h"
#include "\cs2019\cstudy\engine\tge.h"

namespace PlayerObject {
	struct S_OBJ {
		irr::core::vector2df m_vpos;
		irr::core::vector2df m_vDestPoint;
		double m_fSpeed;
		char m_szName[64];
		void* m_pMap;
		int m_nStatus_HaveKey, m_nFSM;

	};
	void init(void* pObj, void* pMap);
	void release(void* pObj);
	void apply(void* pObj, double fDelta);
	void draw(void* pObj);
}