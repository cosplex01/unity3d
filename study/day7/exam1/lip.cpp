#include <stdio.h>
int getStringLength(char strTemp[], int nBufSize) //������ ���� �ϳ��� �ܾ �Է¹޴°�
{
	int check = 0;
	for (int i = 0; i < nBufSize; i++)
	{
		if (strTemp[i] != 0x00)
		{
			check++;
			printf_s("strTemp[%c]�� �ι��ڰ� �ƴѰ�?\n", strTemp[i]);
			printf_s("%08x,%d", strTemp[i], check);
		}
		else
		{
			break;
		}
	}
	return check;
}