// jinsuhenkan.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


int main()
{
	printf_s("%.2lf\n",1.0e3);

	char _c = 'A';

	printf_s("%c %d\n",  _c,_c);
	printf_s("%c %d\n", _c+1,_c+1);

	printf_s("인트형의 크기 : %d\n", sizeof(int));
	printf_s("더블형의 크기 : %d\n", sizeof(double));

	int num = 0;
	printf_s("변수 num크기 : %d 바이트 \n", sizeof(num));
	printf_s("변수 _c크기 : %d 바이트 \n", sizeof(_c));

	char _szBuf[64];
	printf_s("변수 _c크기 : %d 바이트 \n", sizeof(_szBuf));
	return 0;
}

