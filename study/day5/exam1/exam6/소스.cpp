#include <iostream>
#include <stdio.h>
#include <Windows.h>

int main()
{
	char _cmd;
	int _bLoop = 1;
	int _nMoney = 100;
	int _nMoneyPower = 1;

	// ��ũ�� ���۸� �ҷ��ͼ� ��ũ���� �����κ��� �÷��� �����մϴ�
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	if (GetConsoleScreenBufferInfo(hConsole, &csbInfo) == 0)
	{
		printf_s("��ũ�� ���۸� ���� ���ߴµ�\n");
	}
	
	WORD wOldColor = csbInfo.wAttributes;// ��ũ�����ۿ� �̿��� ������ �ʱ�ȭ �ؾ� �մϴ�

	while (_bLoop)
	{
		printf_s("Ŀ��� �Է� (���� h)\n");
		scanf_s("\n%c", &_cmd,sizeof(_cmd));
		int ___jakupsu = 0;
			
		/* else
		{
			
			SetConsoleTextAttribute(hConsole, 0x0c);//1001 1100 red
			printf_s("���̿�\n");
			SetConsoleTextAttribute(hConsole, 0x0a);//0000 1010 green
			printf_s("���̿�\n");
			SetConsoleTextAttribute(hConsole, 0x09);//0000 1001 blue
			printf_s("���̿�\n");
			SetConsoleTextAttribute(hConsole, 0xfc);//1111 1001 ��������� �����۾�
			printf_s("���̿�\n");
			SetConsoleTextAttribute(hConsole, 0xf4);//1111 0100 ��������� �����۾�
			printf_s("���̿�\n");

			SetConsoleTextAttribute(hConsole, wOldColor); //����ó���� �ǵ�����
		}
		*/
		switch (_cmd)
		{
			
		case 'q':
			SetConsoleTextAttribute(hConsole, 0xf4);//1111 0100 ��������� �����۾�
			_bLoop = 0; printf_s("\n�����մϴ�\n");
			SetConsoleTextAttribute(hConsole, wOldColor); //����ó���� �ǵ�����
			break;
		case 'l':
			SetConsoleTextAttribute(hConsole, 0xfc);//1111 1001 ��������� �����۾�
			_bLoop = 0; printf_s("\nġ������ �������� �ʾҾ�, �����մϴ�\n");
			SetConsoleTextAttribute(hConsole, wOldColor); //����ó���� �ǵ�����
			break;
		case 'u':
			SetConsoleTextAttribute(hConsole, 0x09);//0000 1001 blue
			_bLoop = 0; printf_s("\n����Ͱ� ���� ��� �����մϴ�\n");
			SetConsoleTextAttribute(hConsole, wOldColor); //����ó���� �ǵ�����
			break;
		case 'g':
			SetConsoleTextAttribute(hConsole, 0x0a);//0000 1010 green
			_bLoop = 1; printf_s("\n�������� �ֿ����ϴ�. �׷���...\n");
			SetConsoleTextAttribute(hConsole, wOldColor); //����ó���� �ǵ�����
			_nMoney = _nMoney+20;
			break;
		case 'h':
			_bLoop = 1; 
			SetConsoleTextAttribute(hConsole, 0x0c);//1001 1100 red
			printf_s("m. ������\n");
			printf_s("l. ġ���ϱ�\n");
			printf_s("u. ����ϱ�\n");
			printf_s("g. ������ �ݱ�\n");
			printf_s("q. �����ϱ�\n");
			SetConsoleTextAttribute(hConsole, wOldColor); //����ó���� �ǵ�����
			break;
		case 'm':
			_bLoop = 1; printf_s("m. ������ �۾� �õ���\n");
			_nMoney = _nMoney + _nMoneyPower;
			printf_s("%d���� �����׿�\n",_nMoney);
			SetConsoleTextAttribute(hConsole, wOldColor); //����ó���� �ǵ�����
			break;
		default:
			_bLoop = 1;
			SetConsoleTextAttribute(hConsole, wOldColor); //����ó���� �ǵ�����
			break;
		}
		
	}
	return 0;
}