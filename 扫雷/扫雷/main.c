#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
char mine[ROWS][COLS];
char show[ROWS][COLS];
int  blank = ROW * COL - SET;
void game(void)
{
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	// 埋雷
	set(mine);
	//打印棋盘
	print(mine, ROWS, COLS);
	print(show, ROWS, COLS);
	//输入并判断

	while (blank > 0)
	{
		//判断需进行的操作
		int operate = 0;
		scanf("%d", &operate);
		if (operate == 1)
		{
			if (check(mine, show))
			{
				system("cls");
				print(mine, ROWS, COLS);
				print(show, ROWS, COLS);
				if (blank == 0)
				{
					printf("你赢了\n");
				}
			}
			else
			{
				system("cls");
				printf("你被炸死了\n");
				print(mine, ROWS, COLS);
				break;
			}
		}
		else
		{
			int x, y = 0;
			system("cls");
			scanf("%d%d", &x, &y);
			show[x][y] = '@';
			print(mine, ROWS, COLS);
			print(show, ROWS, COLS);
		}
	}

}
void manu(void)
{
	printf("***********************************\n");
	printf("**********     play.1     *********\n");
	printf("**********     exit.0     *********\n");
	printf("***********************************\n");
	printf("进入游戏后，输入1加坐标为排雷，输入2加坐标为插旗\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		manu();
		printf("请输入>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		}
	} while (input);
	printf("退出游戏");
	return 0;
}
