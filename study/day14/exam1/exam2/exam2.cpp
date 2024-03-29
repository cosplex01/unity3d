﻿// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include "\cs2019\cstudy\engine\irrlicht\include\irrlicht.h"
#include "\cs2019\cstudy\engine\tge.h"

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);
	bool bLoop = true;
	UINT64 _tick = TGE::util::GetTimeMs64();
	irr::core::vector2df canon(40,12);
	irr::core::vector2df vDir(1.0);
	irr::f32 m_fAngle = 0;

	while (bLoop)
	{
		UINT64 _delta = TGE::util::GetTimeMs64() - _tick;
		_tick = TGE::util::GetTimeMs64();
		double _fDelta = _delta / 1000.0;

		TGE::clearScreenBuffer(TGE::g_chiBuffer, 0x0020, 0x0000);

		TGE::setCharacter(TGE::g_chiBuffer, (int)canon.X, (int)canon.Y, 0x0020, 0x00f0);

		irr::core::vector2df _vdir = vDir;
		_vdir.rotateBy(m_fAngle);
		_vdir *= 4;

		irr::core::vector2df _canonBall = canon;
		_canonBall += _vdir;


		TGE::setCharacter(TGE::g_chiBuffer, (int)_canonBall.X, (int)_canonBall.Y, 0x00c0, 0x00f0);

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
		TGE::setCursor(hStdout, 0, 25);
		printf_s("%4.3f : %4.3f : %4.3f\n",_vdir.X, _vdir.Y,m_fAngle);

		if (TGE::input::g_KeyTable[VK_LEFT])
		{
			m_fAngle += (irr::f32)(_fDelta*5.0);
		}
		else if(TGE::input::g_KeyTable[VK_RIGHT])
		{
			m_fAngle -= (irr::f32)(_fDelta * 5.0);
		}
		
	}
	TGE::endTGE();

   return 0;
}
