//#include "\makeP\cstudy\engine\tge.h"
#include "\cs2019\cstudy\engine\tge.h"
#include "playerObject.h"

namespace PlayerObject{

		void init(void* pObj,void* pMap)
		{
			PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;
			ptrThis->m_nFSM = 0;//���� �ʱ�ȭ
		}
		void release(void* pObj)
		{
			PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;
		}
		void apply(void* pObj,double _fDelta)
		{
			PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;	
			switch (ptrThis->m_nFSM)
			{
			case 0: //������
			{
				if (TGE::input::g_dwButtonState == 1) {
					ptrThis->m_vDestPoint = irr::core::vector2df(
						TGE::input::g_cdMousePos.X,
						TGE::input::g_cdMousePos.Y
						//���콺 ��ġ
					);
					ptrThis->m_nFSM = 10;
				}
			}
			break;
			case 10: //�ȱ�
			{
				irr::core::vector2df vDir = ptrThis->m_vDestPoint - ptrThis->m_vpos;
				vDir.normalize();//������� [����]

				ptrThis->m_vpos += vDir * (_fDelta * ptrThis->m_fSpeed); //1�ʿ� m_fSpeed��ŭ �̵�
				irr::f32 fDist = (irr::f32)(ptrThis->m_vDestPoint - ptrThis->m_vpos).getLength();
				if (fDist <0.3) //������ �Ÿ�
				{
					ptrThis->m_nFSM = 0;
				}
			}
			break;
			default:	break;
			}
		}
		void draw(void* pObj)
		{
			PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;

			TGE::setCharacter(TGE::g_chiBuffer, (int)ptrThis->m_vpos.X, (int)ptrThis->m_vpos.Y, 0x0020, 0x00f0);
		}
}