// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <stdlib.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32.lib")
#define MAX_LOADSTRING 100
#define SERVER "192.168.0.15" //192.168.0.15
#define BUFLEN 512
#define PORT 3333
struct S_TESTPACKET {
	int m_nCheckSum;
	int m_nCode;
};
SOCKET g_hSocket;
int main()
{
	sockaddr_in si_other;
	int slen;

	//S_TESTPACKET message;
	char message[BUFLEN];
	slen = sizeof(message);

	//char buf[BUFLEN];
	WSADATA wsa;
	
	if (WSAStartup(MAKEWORD(3, 5), &wsa) != 0) {
		MessageBox(NULL, L"WSAstartup", L"error", MB_OK);
		return EXIT_FAILURE;
	}

	g_hSocket = socket(AF_INET,SOCK_DGRAM, 0);
	if (g_hSocket == SOCKET_ERROR) {
		MessageBox(NULL, L"socket", L"error", MB_OK);
		printf_s("error code : %d\n", WSAGetLastError());
		return EXIT_FAILURE;
	}
	memset((char*)& si_other, 0, slen);
	InetPton(AF_INET, TEXT(SERVER), &si_other.sin_addr.s_addr);
	//si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);

	for(int i=0; i<20; i++)
	{
		puts("wait data from...somewhere");
		S_TESTPACKET pkt;
		
		pkt.m_nCheckSum = 21;
		pkt.m_nCode = 60;
		
		memset(&pkt, 0, sizeof(S_TESTPACKET));
		sendto(g_hSocket, (const char*)&pkt, sizeof(S_TESTPACKET),0,(sockaddr*) &si_other,sizeof(si_other));

		printf_s("count:%d",i);
		if (i == 18) {
			free(&si_other);
			closesocket(g_hSocket);
			break;
		}
		else {
			puts("정상동작중");
		}
	}
	free(&si_other);
	closesocket(g_hSocket);
	return 0;
}
