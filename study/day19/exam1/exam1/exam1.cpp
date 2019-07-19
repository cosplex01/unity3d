// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 서버를 제작한다

#include <iostream>
#include <stdlib.h>
#include <WS2tcpip.h>
#include <WinSock2.h>
#include "packet.h"
#pragma comment(lib,"ws2_32.lib")

S_GameObject g_GameObjs[32];
char g_szIpTable[32][64];

int main()
{
	for (int i = 0; i < 32; i++) {
		g_GameObjs[i].m_nStatus = 0;
		strcpy_s(g_szIpTable[i],"");
	}
	
	SOCKET hServerSocket;

	WSADATA wsa;
	if (WSAStartup(MAKEWORD(4, 4), &wsa) != 0) {
		printf("WSAStartup %d\n",WSAGetLastError());
		return EXIT_FAILURE;
	}
	//소켓 열기
	hServerSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (hServerSocket == INVALID_SOCKET) {
		printf("invalid socket%d\n",WSAGetLastError());
		return EXIT_FAILURE;
	}

	sockaddr_in si_severaddr; //답신자의 정보구조체
	memset(&si_severaddr, 0, sizeof(sockaddr_in));
	
	//서버역활을 위한 주소정보 셋업
	si_severaddr.sin_family = AF_INET;
	si_severaddr.sin_port = htons(3333); //SHORT형태로 포트지정 htons=>리틀엔디언 -> 빅엔디언
	si_severaddr.sin_addr.S_un.S_addr = INADDR_ANY; //전체목록중 접속한이들만 


	if (bind(hServerSocket, (sockaddr*)& si_severaddr, sizeof(sockaddr_in)) == SOCKET_ERROR)
	{
		printf_s("bind error:%d\n",WSAGetLastError());
		return EXIT_FAILURE;
	}

	while (1) {
		sockaddr_in si_other; //접속한 손님

		memset(&si_other, 0, sizeof(sockaddr_in));
		int slen = sizeof(sockaddr_in);

		puts("wait request");
		fflush(stdout);
		char szBuf[1024];
		memset(szBuf, 0, sizeof(szBuf));

		int recv_len = recvfrom(hServerSocket, szBuf,
			sizeof(szBuf), 0, (sockaddr*)& si_other, &slen); //발송할 데이터 길이

		char _szIp[256];
		inet_ntop(AF_INET, &si_other.sin_addr, _szIp, sizeof(_szIp)); //빅엔디언으로 상대방에게서 데이터 얻기
		printf_s("from:%s : %d\n", _szIp, ntohs(si_other.sin_port)); //ntohs : 빅엔디언->리틀엔디언

		//겹치는 것이 있는지 확인
		int i;
		for (i = 0; i < 32; i++) {
			if (strcmp(g_szIpTable[i], _szIp) == 0 || strcmp("", g_szIpTable[i]))
			{
				break;
			}
		}
		//주소 저장
		if (i < 32) {
			S_GameObject* pObj = (S_GameObject*)szBuf;

			strcpy_s(g_szIpTable[i], _szIp);
			g_GameObjs[i].m_Xpos = pObj->m_Xpos;
			g_GameObjs[i].m_Ypos = pObj->m_Ypos;
			g_GameObjs[i].m_nStatus = 1;
			printf_s("x:%f y:%f\n",pObj->m_Xpos,pObj->m_Ypos);
		}
		sendto(hServerSocket, (char*)g_GameObjs, sizeof(S_GameObject) * 32, 0,
			(sockaddr*)& si_other, sizeof(si_other));
		//새로추가

	//전체 오브젝트 전송
	}
	closesocket(hServerSocket);
	WSACleanup(); //WSADATA 쪽 데이터 정리
   return 0;
}
