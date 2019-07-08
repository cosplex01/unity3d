#include <stdio.h>
#include <iostream>
int main()
{
	int gold[5] = {120,130,100,110,90}; //컴파일중 배열초기화
	//실행중 배열초기환
	gold[0] = 120;
	gold[1] = 100;
	gold[2] = 130;
	gold[3] = 150;
	gold[4] = 180;

 	printf_s("gold[0] : %d\n",gold[0]);
	printf_s("sizeof(gold): %d, sizeof(int) : %d\n", sizeof(gold),sizeof(int));

	for (int i = 0; i < sizeof(gold)/sizeof(int); i++)
	{
		printf_s("gold[0] : %d\n", gold[i]);
	}
	return 0;
}