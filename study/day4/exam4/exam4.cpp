// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>

int main()
{
//	double _pi = 3.14;
	//int _nPi;
	
	//_nPi = (int)_pi; // 서로다른 데이터형

	//printf_s("%d %lf", (int)(5 / 2), (double)((double)5 / (double)2));
	//int num1 = 5;
	//int num2 = 2;
	//double num3 = num1 / num2;
	//printf_s("%lf \n", num3);

	double DaysForYears = 365.2422;
	int days = 0;

	printf_s("1년은 몇일입니까? :  \n");
	scanf_s("%d", &days);

	double total_days = days - DaysForYears;
	days = total_days;
	double total_hours = (total_days - days) * 24;
	int hour = total_hours;
	double total_Mins = (total_hours - hour) * 60;
	int mins = total_Mins;
	double total_Chos = (total_Mins - mins) * 60;
	int Chos = total_Chos;

	printf_s("1년은 %d 일, %d 시, %d 분, %d 초 입니다\n", days, hour, mins, Chos);

	int num = 12;
	printf_s("10진수:%d 8진수:%o 16진수:%x", num,num,num);
	char _szBuf[256];
	sprintf_s(_szBuf, sizeof(_szBuf),"10진수: % d 8진수 : % o 16진수 : % x", num,num,num);
	MessageBoxA(NULL,_szBuf,"결과는 이렇습니다",MB_OK);

	return 0;

}