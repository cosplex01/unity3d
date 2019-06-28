// exam5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int _bLoop = 1;
	char _cmd;
	
	while (_bLoop)
	{
		printf_s("h - 도움말, q - 종료: \n");
		printf_s("커멘드 입력하시오: \n");
		scanf_s("\n%c", &_cmd, sizeof(_cmd));
		switch (_cmd)
		{
			case 'q':
				printf_s("프로그램 종료\n");
				_bLoop = 0;
				break;
			case 'h':
				printf_s("================\n");
				printf_s("q : 나가기\n");
				printf_s("c : 캐릭터 생성\n");
				printf_s("s : 시작\n");
				printf_s("i : 설정\n");
				printf_s("================\n");
				_bLoop = 1;
				break;
			case 's':
				printf_s("아직 개발중이라서..\n");
				_bLoop = 0;
				break;
			case 'i':
				printf_s("아직 개발중이라서..\n");
				_bLoop = 0;
				break;
			case 'c':
				int __cmd;
				printf_s("================\n");
				printf_s("캐릭터를 생성합니다\n");
				printf_s("직업을 선택하세요\n");
				printf_s("1 : 파이터\n");
				printf_s("2 : 마법사\n");
				printf_s("3 : 치료사\n");
				printf_s("================\n");

				scanf_s("\n%d", &__cmd);
				printf_s("%d 를 선택했네요\n", __cmd);
				_bLoop = 1;
				break;
			default:
				_bLoop = 1;
		}
	}
/*		else if (_cmd == 'h')
		{
			printf_s("================\n");
			printf_s("q : 나가기\n");
			printf_s("c : 캐릭터 생성\n");
			printf_s("s : 시작\n");
			printf_s("i : 설정\n");
			printf_s("================\n");
		}
		else if (_cmd == 'c')
		{
			int __cmd;
			printf_s("================\n");
			printf_s("캐릭터를 생성합니다\n");
			printf_s("직업을 선택하세요\n");
			printf_s("1 : 파이터\n");
			printf_s("2 : 마법사\n");
			printf_s("3 : 치료사\n");
			printf_s("================\n");

			scanf_s("\n%d",&__cmd);
			printf_s("%d 를 선택했네요\n",__cmd);
		}
	    else if (_cmd == ' ')
		{
			printf_s("스페이스 공백으로 종료\n");
			break;
		}
		else {
			printf_s("\n커멘드를 확인하세요\n");
		}
		
	}
	*/
	return 0;
}