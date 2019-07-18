// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdlib.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

#define BUFLEN 256
#define PORT 3333

struct S_TESTPACKET {
	int m_nCheckSum;
	int m_nCode;
};
//데이터 받기
sockaddr_in g_listener_addr;//리스너
SOCKET g_socket; //소켓

int main()
{
	int recv_len;
	char buf[BUFLEN];
	WSADATA wsa;

	WSAStartup(MAKEWORD(3,3),&wsa);
	g_socket = socket(AF_INET, SOCK_DGRAM, 0);

	if (g_socket == INVALID_SOCKET) {
		printf_s("소켓에러:%d\n",WSAGetLastError());
	}
	g_listener_addr.sin_family = AF_INET;
	g_listener_addr.sin_port = htons(PORT);
	g_listener_addr.sin_addr.S_un.S_addr = INADDR_ANY;

	if (bind(g_socket, (sockaddr*)& g_listener_addr, sizeof(g_listener_addr)) == SOCKET_ERROR)
	{
		printf_s("소켓bind에러:%d\n", WSAGetLastError());
	}
	puts("바인드 성공");

	while (1)
	{
		sockaddr_in si_other;
		int slen=0;

		puts("데이터 전송 기다림");
		fflush(stdout);
		memset(buf, 0, BUFLEN);
		recv_len = recvfrom(g_socket, buf,BUFLEN, 0, (sockaddr*)& si_other, &slen);
		char _szBuf[256];

		//주소출력
		inet_ntop(AF_INET, &si_other.sin_addr, _szBuf, sizeof(_szBuf));
		//printf_s("data:%s\n",buf);

		S_TESTPACKET* pPacket = (S_TESTPACKET*)buf;
		if (pPacket->m_nCheckSum == 100) {
			puts("success");
			printf_s("code:%d checksum:%d\n", pPacket->m_nCode, pPacket->m_nCheckSum);
		}
	}
	closesocket(g_socket);
	return 0;
}