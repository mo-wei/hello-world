#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//mine表示埋雷数组，1为有雷，0为没雷，show为表示雷，原本为*找出周围数后改为周围雷数
void numble(char mine[][COLS], char show[][COLS], int x, int y)
{
	int sum = 0;
	if (mine[x][y] == '1')
	{
		return;
	}
	//找x，y附近的雷数
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			sum += mine[i][j] - '0';
		}
	}
	show[x][y] = sum + '0';
	// 如果为0，继续递归展开附近的八个
	if (sum ==0 && (x <= 9 && y <= 9) &&(x >= 1 && y >= 1))
	{
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if(show[i][j] == '*')
				numble(mine, show, i, j);
			}
		}
	}
	blank--;
	return;
}
void InitBoard(char ch[][COLS], int row, int col, char init)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ch[i][j] = init;
		}
	}
}

void print(char ch[][COLS], int row, int col)
{
	for (int n = 0; n < col - 1; n++)
	{
		printf("%-2d", n);
	}
	printf("\n");
	for (int i = 1; i < row - 1; i++)
	{
		printf("%d ", i);
		for (int j = 1; j < col - 1; j++)
		{
			printf("%c ", ch[i][j]);
		}
		printf("\n");
	}
	printf("---------------------\n");
}

void set(char ch[][COLS])
{
	for (int i = SET; i > 0;)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (ch[x][y] == '0')
		{
			ch[x][y] = '1';
			i--;
		}
	}
}

int check(char mine[][COLS], char show[][COLS])
{
	int x = 0, y = 0;
	printf("请输入想排的坐标>:");
	scanf("%d%d", &x, &y);
	if (mine[x][y] == '1')
	{
		return 0;
	}
	numble(mine, show, x, y);
	return 1;
}