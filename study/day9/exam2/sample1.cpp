#include "..\..\..\cstudy\engine\tge.h"

void sample1()
{
	puts("���� 1����");

	int score[3][4] = {
		{1,2,3,4},
		{11,12,13,14},
		{20,21,22,23}
	};
	//[��(y)][��(x)]
	printf_s("%d\n",score[1][0]);
	puts("��켱");
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			printf_s("%d\n", score[row][col]);
		}
	}
	puts("���켱");
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 3; row++)
		{
			printf_s("%d\n", score[row][col]);
		}
	}
}