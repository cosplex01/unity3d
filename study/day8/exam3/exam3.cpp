// exam3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
void incNumber(int *_a) //1씩 증가하는 함수[포인터 변수를 받아서]
{
	*_a = *_a + 1;
	printf_s("인크리먼트 함수에서만: %d\n",*_a);
}

void swapNumber(int* a, int* b)
{
	int* temp;
	temp = a;
	a = b;
	b = temp;

	printf_s("바꾸어보았는데...%d | %d\n", *a,*b);
}
int main()
{
  int a, b;
  a = 0;
  b = 4;

  printf_s("%d \n",a);
  swapNumber(&a, &b);
  incNumber(&a);
  printf_s("%d \n",a);
  return 0;
}