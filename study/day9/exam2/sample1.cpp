#include "..\..\..\cstudy\engine\tge.h"

void sample1()
{
	puts("샘플 1시작");

	int score[3][4] = {
		{1,2,3,4},
		{11,12,13,14},
		{20,21,22,23}
	};
	//[행(y)][열(x)]
	printf_s("%d\n",score[1][0]);
	puts("행우선");
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			printf_s("%d\n", score[row][col]);
		}
	}
	puts("열우선");
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			printf_s("%d\n", score[row][col]);
		}
	}
}