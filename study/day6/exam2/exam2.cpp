// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <iostream>

void showData(int nBuf[], int nBufLength) //show
{
	for (int i = 0; i < nBufLength; i++)
	{
		if (nBuf[i] == -1)
		{
			if (i <= 0)
			{
				printf_s("데이터가 없습니다\n");
			}
			break;
		}
		printf_s("%d", nBuf[i]);
	}
}
void pushData(int nBuf[], int nBufLength, int _ndata) //push
{
	for (int i = 0; i < nBufLength; i++)
	{
		if (nBuf[i] == -1) {
			nBuf[i] = _ndata;
			nBuf[i + 1] = -1;
			break;
		}
	}
}
int popData(int nBuf[], int nBufLength) //pop
{
	for (int i = 0; i < nBufLength; i++)
	{
		if (nBuf[i] == -1) {
			if (i > 0)
			{
				int _r = nBuf[i - 1];
				nBuf[i - 1] = -1;
				return _r;
			}
			else
			{
				printf_s("지워질데이터가 없습니다\n");
				nBuf[i] = 0; // 초기화시켰을때의 nBuf[1~255]의 값을 넣음
			}
			break;
		}
	}
	return -1;
	
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
		printf_s("\n(1.show 2.push 3.pop)Cmd>"); scanf_s("%d", &_cmd);
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
			int _num;
			printf_s("\ninput number=>"); scanf_s("%d", &_num);
			pushData(nBuf, nBufLength, _num);
			break;
		case 3:
			printf_s("pop : %d", popData(nBuf, nBufLength)); 
			break;
		default:
			break;
		}
	}
	return 0;
}
