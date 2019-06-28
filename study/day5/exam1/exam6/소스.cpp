#include <iostream>
#include <stdio.h>

int main()
{
	char _cmd;
	int _bLoop = 1;
	int _nMoney = 100;
	int _nMoneyPower = 1;

	while (_bLoop)
	{
		printf_s("커멘드 입력 (도움말 h)\n");
		scanf_s("\n%c", &_cmd,sizeof(_cmd));
		int ___jakupsu = 0;
		switch (_cmd)
		{
			
		case 'q':
			_bLoop = 0; printf_s("\n종료합니다\n");
			break;
		case 'l':
			_bLoop = 0; printf_s("\n치료방법이 구현되지 않았어, 종료합니다\n");
			break;
		case 'u':
			_bLoop = 0; printf_s("\n사냥터가 아직 없어서 종료합니다\n");
			break;
		case 'g':
			_bLoop = 1; printf_s("\n아이템을 주웠습니다. 그런데...\n");
			_nMoney = _nMoney+20;
			break;
		case 'h':
			_bLoop = 1; printf_s("m. 돈벌기\n");
			printf_s("l. 치료하기\n");
			printf_s("u. 사냥하기\n");
			printf_s("g. 아이템 줍기\n");
			printf_s("q. 종료하기\n");
			break;
		case 'm':
			_bLoop = 1; printf_s("m. 돈벌기 작업 시도함\n");
			_nMoney = _nMoney + _nMoneyPower;
			printf_s("%d원을 벌었네요\n",_nMoney);
			break;
		default:
			_bLoop = 1;
			break;
		}
		
	}
	return 0;
}