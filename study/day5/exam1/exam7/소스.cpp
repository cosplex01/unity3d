#include <iostream>
#include<Windows.h>
int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;

	if (GetConsoleScreenBufferInfo(hConsole, &csbInfo) == 0)
	{
		printf_s("��ũ�� ���۸� ���� ���ߴµ�\n");
	}
	else
	{
		WORD wOldColor = csbInfo.wAttributes;
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
	return 0;
}