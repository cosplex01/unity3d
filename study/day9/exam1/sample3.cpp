#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"

int globalNumber = 9;
int* counter()
{
	static int _cnt = 0;
	_cnt++;
	printf_s("counter : %d\n",_cnt);
	printf_s("GlobalNumber : %d\n", globalNumber);
	return &_cnt;
}
void sample3()
{
	counter();
	counter();
	counter();
	counter();
	counter();
	globalNumber++;
	int* ptrCnt = counter();
	(*ptrCnt)++;
	counter();
	printf_s("globalnumber : %d\n", globalNumber);
	globalNumber = 20;

	printf_s("globalnumber: %d\n",globalNumber);
}