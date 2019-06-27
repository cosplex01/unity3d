// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    printf_s("몫 : %d 나머지:%d\n", (5 / 2), (5 % 2));
	//1바이트 정수형으로 사용하기
	char num = 255;
	printf_s("255=> %d \n", num);
	//문자형으로 사용하기
	char num2 = 65;
	printf_s("%c \n", num2);

	unsigned char num3 = 255;
	printf_s("255=> %d \n", num3);

	short num4 = 65535; //2byte정수형
	printf_s("65535=> %d \n", num4);

	unsigned short num5 = 65535; //2byte정수형
	printf_s("65535=> %d \n", num5);
}