// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <iostream>
int nBuf[256];
int nLastIndex = -1;
void printData() //show
{
	for (int i = 0; i <= nLastIndex; i++)
	{
		printf_s("%d",nBuf[i]);
	}
}
void pushData(int _data) //push
{
	nLastIndex++;
	nBuf[nLastIndex] = _data;
}
int popData() //pop
{
	int _r = -9999;
	if (nLastIndex < 0) { printf_s("데이터 없음");}
	else
	{
		int _r = nBuf[nLastIndex];
		nLastIndex--;
	}
	return _r;
}
int deleteData() //delete
{
	int _r = -9999;
	if (nLastIndex >= 0) {
		_r = nBuf[0];
		for (int i = 0; i < nLastIndex; i++)
		{
			nBuf[i] = nBuf[i + 1];
		}
		nLastIndex--;
	}
	
	return _r;
}
void insertData(int _data) //que insert
{
	if (nLastIndex >= 0) {
		for (int i = nLastIndex; i >= 0; i--)
		{
			nBuf[i + 1] = nBuf[i];
		}
	}	
	nBuf[0] = _data;
	nLastIndex++;
}
void insertToData(int _data,int nlndex) //중간에 큐삽입
{
	int i = nlndex;
		if (i <= nLastIndex)
		{
			for (i=nLastIndex; i >= nlndex; i--)
			{
				nBuf[i + 1] = nBuf[i];
			}
			nBuf[nlndex] = _data;
			nLastIndex++;
		}
		else
		{
			nBuf[nlndex] = _data;
			nLastIndex = nlndex;
		}
}
int delToData(int nlndex)//중간 삭제구간
{
	int _r = nBuf[nlndex];
	
	for (int i = nlndex; i < nLastIndex; i++)
		{
			nBuf[i] = nBuf[i + 1];
		}
		nLastIndex--;
	return _r;
}
int main()
{
	int _bLoop = 1;
	while (_bLoop)
	{
		int _cmd; printf_s("Cmd>"); scanf_s("%d", &_cmd);
		switch (_cmd)
		{
		case 0: _bLoop = 0; printf_s("종료합니다\n"); break;
		case 1:
		{
			int _num; printf_s("input num =>"); scanf_s("%d", &_num); pushData(_num);
		}break; //push
		case 2: {printf_s("pop =>%d\n", popData()); } break; //pop
		case 3: printData(); break; //pop
		case 4: {printf_s("del : %d\n", deleteData()); }break; //delete
		case 5: {int _num; printf_s("input num=>"); scanf_s("%d", &_num); insertData(_num); }break;
		case 6: {int _num,index; printf_s("input middle num=>"); scanf_s("%d %d", &_num,&index); insertToData(_num,index); }break;
		case 7: {int index; printf_s("delete middle num=>"); scanf_s("%d", &index); printf_s("%d\n", delToData(index)); }break;
		default: break;
		}
	}
	return 0;
}