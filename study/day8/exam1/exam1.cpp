// exam1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <iostream>

int main()
{
	int a, b, c;

	a = 1;
	b = 2;
	c = 3;

	printf_s("%p:%-10d,%-10d\n",&a,*&a, a);

	int d[3];
	d[0] = 1000;
	d[1] = 1500;
	d[2] = 1800;

	printf_s("값은%d %d %d\n", a, b, c);
	printf_s("주소는%p %p %p\n", &a, &b, &c);
	printf_s("d의 값%d %d %d\n", d[0],d[1],d[2]);
	printf_s("d의 값%d %d %d\n", *&(d[0]), *&(d[1]), *&(d[2]));
	printf_s("d의 주소는%p %p %p\n", &(d[0]), &(d[1]), &(d[2]));

	int* ptr;
	ptr = &a;
	printf_s("%p | %p\n", ptr, &a);
	printf_s("%d | %d\n", *ptr, a);

	ptr = &d[0];
	printf_s("%d | %d\n", *ptr, d[0]);
	printf_s("%p | %p\n", ptr, &d[0]);
    return 0;
}
