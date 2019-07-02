// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <iostream>

void showData(int nBuf[], int nBufLength) //show
{
	for (int i = 0; i < nBufLength; i++)
	{
		if (nBuf[i] == -1)break;
		printf_s("%d", nBuf[i]);
	}
}
void pushData(int nBuf[], int nBufLength, int _ndata) //push
{
	for (int i = 0; i < nBufLength; i++)
	{
		if (nBuf[i] == -1) {
			nBuf[i] = 3;
			nBuf[i + 1] = -1;
			break;
		}
	}
}
void popData(int nBuf[], int nBufLength, int _ndata) //pop
{
	for (int i = nBufLength; i > 0; i--)
	{
		if (nBuf[i] == -1) {
			nBuf[i] = 0; // 초기화시켰을때의 nBuf[1~255]의 값을 넣음
			nBuf[i - 1] = -1;
			break;
		}
	}
}
int main()
{
	int nBuf[256] = {-1}; // nBuf[0] = -1 , nBuf[1~255] = 0;
	int nBufLength = sizeof(nBuf) / sizeof(int);

	nBuf[0] = 3;
	nBuf[1] = -1;
	
	int _cmd;
	int _bLoop = 1;
	
	while (_bLoop)
	{
		printf_s("\nCmd>"); scanf_s("%d", &_cmd);
		switch (_cmd)
		{
		case 0:
			_bLoop = 0;
			printf_s("프로그램을 종료합니다\n");
			break;
		case 1:
			showData(nBuf, nBufLength);
			break;
		case 2:
			pushData(nBuf, nBufLength, 3);
			break;
		case 3:
			popData(nBuf, nBufLength, 3);
			break;
		default:
			break;
		}
	}

	

	return 0;
}
