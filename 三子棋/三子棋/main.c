#define _CRT_SECURE_NO_WARNINGS 1
//三子棋游戏
#include "game.h"
int main()
{
	//创建 数组--二维数组
	char board[ROW][COL] ;
	int input;
	srand((unsigned int)time(NULL));
	//菜单
	manu();

	do{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game(board);
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:printf("错误输入，请重新输入0/1\n");
			break;
		}
	} while (input);
}