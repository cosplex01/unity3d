﻿// jungryul.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<stdio.h>

int main()
{
	int guka = 90;
	int yonga = 75;
	int suhak = 80;
	int total = 0;
	double everage = 0.00;
	char nameS[20]= "리마니";
	char title[20] = "이름";
	char gamok1[20] = "국어";
	char gamok2[20] = "영어";
	char gamok3[20] = "수학";
	char total1[20] = "총점";
	char ever1[20] = "평균";

	total = guka + yonga + suhak;
	everage = total / 3;
	printf_s("평균 : %.2lf \n", everage);
	printf_s("총점 : %2d \n", total);
	printf_s("\u250C\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2530\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2530\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2530\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2530\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2530\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2513\n");
	printf_s("\u2502%7s   \u2502%6s  \u2502%6s  \u2502%6s  \u2502%6s  \u2502%7s   \u2502\n",title,gamok1,gamok2,gamok3,total1,ever1); // 구분 타이틀도 위치지정함
	printf_s("\u2523\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253c\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253c\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253c\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253c\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253c\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u252b\n");
	printf_s("\u2502%-10s\u2502%8d\u2502%8d\u2502%8d\u2502%8d\u2502%10.2lf\u2502\n",nameS,guka,yonga,suhak,total,everage);
	printf_s("\u2514\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253b\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253b\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253b\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253b\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u253b\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u2501\u251B\n");

	return 0;

}