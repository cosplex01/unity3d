// samgakhyung.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
int main()
{
    //삼각형 피라미드를 생성해 봅시다
	int stone_x, tall_y = 0;
	//우측정렬 삼각형
	for(tall_y = 0; tall_y < 20; tall_y++)
	{
		for (stone_x = 0; stone_x < (20-tall_y); stone_x++)
		{
			printf("o");
		}
		printf_s("\n");
	}
	// 좌측정렬 삼각형
	for (tall_y = 0; tall_y < 20; tall_y++)
	{
		
		for (stone_x = 0; stone_x < (20 - tall_y); stone_x++)
		{
			printf("x");
		}
		for (stone_x = 0; stone_x < (tall_y+1); stone_x++)
		{
			printf("o");
		}
		for (stone_x = 0; stone_x < (tall_y+ 1); stone_x++)
		{
			printf("1");
		}
		printf_s("\n");
	}
	return 0;
}