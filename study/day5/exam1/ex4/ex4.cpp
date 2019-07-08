// ex4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int nai = 60;
	int ipjangryo = 3000;

	printf_s("나이는 몇세이세요? : \n");
	scanf_s("%d", &nai);

	if (nai <= 6 || nai >= 70 )
	{
		ipjangryo = 0;
		printf_s("입장료는 %d원 무료 입니다\n", ipjangryo);
	}
	else
	{
		printf_s("입장료는 %d원 입니다\n",ipjangryo);
	}

	return 0;
}