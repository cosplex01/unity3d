// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	char* ptr = NULL;
	ptr = (char*)malloc(256); //실행중에 동적인 메모리관리함

	if (ptr != NULL) {
		gets_s(ptr, 256);
		printf_s("%s\n", ptr);
		free(ptr); //메모리 복귀시킴
	}
	else {
		printf_s("메모리확보 실패\n");
	}
	
  return 0;
}
