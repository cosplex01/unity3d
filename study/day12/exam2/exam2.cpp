// exam2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

struct S_GameObject {
	int m_nSkima;
	double m_xPos, m_yPos;
	int m_nld;
	double m_nSpeed;
};
int main()
{
	S_GameObject* pObj;
	pObj = (S_GameObject*)malloc(sizeof(S_GameObject));

	pObj->m_nSkima = 1;
	pObj->m_xPos = 35.6;
	pObj->m_yPos = 7.85;
	pObj->m_nld = 1000;
	pObj->m_nSpeed = 2.5;

	FILE* fp;
	fopen_s(&fp, "puransinu.dat", "w");
	if (fp) {
		puts("파일오픈 성공");
		int nSize = fwrite(pObj, sizeof(S_GameObject), 1, fp);
		printf_s("기록크기: %d \n",nSize);
		fclose(fp);
	}
	else {
		puts("파일오픈 실패");
	}

	free(pObj);
   return 0;
}
