// exam6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int num = -1;
	printf_s("%d, %u\n", num, num); //정수의 부호있고 없기를 출력하기 옵션

	double _pi = 3.1445926;
	printf_s("%d, %lf\n", (int)_pi, _pi); //실수의 표현을 생각한다

	printf_s("\\	A\tB	\\ \n");
	printf_s("\x41	\\ \n");

	printf_s("\x42 \u2664 \u2665 %lf\n", _pi); //유니코드 문자도 출력하자
	//10칸확보후 우측정렬 시도하기
	printf_s("%10d \n", 128);
	printf_s("%10d \n", 1280);
	printf_s("%10d \n", 12800);
	printf_s("%10d \n", 128000);
	//10칸확보후 좌측정렬 시도하기
	printf_s("%-10d *\n", 128);
	printf_s("%-10d *\n", 1280);
	printf_s("%-10d *\n", 12800);
	printf_s("%-10d *\n", 128000);
	//그냥 좌측정렬 시도하기
	printf_s("%d *\n", 128);
	printf_s("%d *\n", 1280);
	printf_s("%d *\n", 12800);
	printf_s("%d *\n", 128000);
	//실수표시를 그냥 좌측정렬 시도하기
	printf_s("%lf *\n", 12.8);
	printf_s("%lf *\n", 1.280);
	printf_s("%lf *\n", .128);
	printf_s("%lf *\n", .0128);
	//10칸 확보후 실수표시를 그냥 좌측정렬 시도하기
	printf_s("%10lf *\n", 12.8);
	printf_s("%10lf *\n", 1.280);
	printf_s("%10lf *\n", .128);
	printf_s("%10lf *\n", .0128);
	//10칸 확보후 실수표시를 좌측정렬 및 소수점 2자리로 시도하기
	printf_s("%10.1lf *\n", 12.8);
	printf_s("%10.1lf *\n", 1.280);
	printf_s("%10.1lf *\n", .128);
	printf_s("%10.1lf *\n", .0128);
	//10칸 확보후 실수표시를 좌측정렬 및 소수점 2자리로 시도하기
	printf_s("%-10.1lf *\n", 12.8);
	printf_s("%-10.1lf *\n", 1.280);
	printf_s("%-10.1lf *\n", .128);
	printf_s("%-10.1lf *\n", .0128);
}
