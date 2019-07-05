#include "..\..\..\cstudy\engine\tge.h"
#include <iostream>
void test()
{
	puts("이건 함수가 아니야");
}
void sample1_1()
{
	int a = 1;
}
void sample1_2()
{
	int a = 1;
}
void sample1()
{
	int a = 1;
	{
		int a = 2;
		{
			int a = 3;
			{
				int a = 4;
				{
					int a = 5;
					printf_s("%d\n",a);
				}
				printf_s("%d\n", a);
			}
			printf_s("%d\n", a);
		}
		printf_s("%d\n", a);
	}
	printf_s("%d\n", a);
}