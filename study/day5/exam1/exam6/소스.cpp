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
		printf_s("Ŀ��� �Է� (���� h)\n");
		scanf_s("\n%c", &_cmd,sizeof(_cmd));
		int ___jakupsu = 0;
		switch (_cmd)
		{
			
		case 'q':
			_bLoop = 0; printf_s("\n�����մϴ�\n");
			break;
		case 'l':
			_bLoop = 0; printf_s("\nġ������ �������� �ʾҾ�, �����մϴ�\n");
			break;
		case 'u':
			_bLoop = 0; printf_s("\n����Ͱ� ���� ��� �����մϴ�\n");
			break;
		case 'g':
			_bLoop = 1; printf_s("\n�������� �ֿ����ϴ�. �׷���...\n");
			_nMoney = _nMoney+20;
			break;
		case 'h':
			_bLoop = 1; printf_s("m. ������\n");
			printf_s("l. ġ���ϱ�\n");
			printf_s("u. ����ϱ�\n");
			printf_s("g. ������ �ݱ�\n");
			printf_s("q. �����ϱ�\n");
			break;
		case 'm':
			_bLoop = 1; printf_s("m. ������ �۾� �õ���\n");
			_nMoney = _nMoney + _nMoneyPower;
			printf_s("%d���� �����׿�\n",_nMoney);
			break;
		default:
			_bLoop = 1;
			break;
		}
		
	}
	return 0;
}