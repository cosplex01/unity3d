// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <iostream>
void displayMap(int *_Map) //8x8맵 작성
{
	for (int iy = 0; iy < 8; iy++) {
		for (int ix = 0; ix < 8; ix++) {
			int _cell = _Map[(iy * 8) + ix];
			if (_cell == 0) { printf_s(" "); }
			else if (_cell == 1) { printf_s("^"); }
			else if (_cell == 2) { printf_s("X"); }
			else if (_cell == 3) { printf_s("Y"); }
			//printf_s("%d", _Map[(iy*8) + ix]);
		}
		printf_s("\n");
	}
}
void putChar(int _Map[],int x, int y, int c)
{
	_Map[(y * 8) + x] = c;
}
int main()
{
	int _Map[] = {
		1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,2,0,0,1,
		1,0,0,2,2,0,0,1,
		1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1
	};
	//주인공 오브젝트 위치
	int player_x, player_y;
	player_x = 2;
	player_y = 2;

	int _bLoop = 1;
	system("cls");
	while (_bLoop)
	{
		puts("0.ext\n1.display map\n2.putChar\n3.->\n4.<-\n5.↑\n6.↓");
		printf_s("cmd>");
		int _cmd; scanf_s("%d", &_cmd);
		switch (_cmd)
		{
		case 0: _bLoop = 0; puts("종료합니다"); break;
		case 1: //display
		{
			system("cls"); putChar(_Map, player_x, player_y, 3);//플레이어 위치갱신
			displayMap(_Map);
		}break;
		case 2: 
		{
			int _x, _y;
			printf_s("input x y=>"); scanf_s("%d %d",&_x,&_y);
			system("cls"); 
			putChar(_Map, _x, _y, 3);
		}
		break;//putObject
		case 3:
		{
			system("cls");
			putChar(_Map,player_x,player_y,0);// 흔적을 지운다
			player_x += 1;
			if (player_x >= 7) { player_x = 1; }				
		}
		break;//move left
		case 4:
		{
			system("cls");
			putChar(_Map, player_x, player_y,0);// 흔적을 지운다
			player_x -= 1;
			if (player_x <= 1) { player_x = 6; }
		}
		break; //move right
		case 5:
		{
			system("cls");
			putChar(_Map, player_x, player_y, 0);
			player_y -= 1;
			if (player_y <= 1) { player_y = 6; }
		}
		break; //move up
		case 6:
		{
			system("cls");
			putChar(_Map, player_x, player_y, 0);
			player_y += 1;
			if (player_y >= 7) { player_y = 1; }
		}
		break; //move down
		default:
			break;
		}
	}
	return 0;
}
