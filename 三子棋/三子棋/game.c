#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void game(char board[ROW][COL])
{
	//��ʼ������
	ini(board, ROW, COL);
	//��ӡ����
	PrintBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//�������
		player(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
		//��������
		computer(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
			break;
	}
		if (ret == '1')
			printf("��Ӯ��\n");
		if (ret == '0')
			printf("����Ӯ��\n");
		if (ret == 'Q')
			printf("����ƽ��\n");
		printf("����1���¿�ʼ");

}
void manu(void)
{
	printf("**************************************\n");
	printf("*******        play.1        *********\n");
	printf("*******        exit.0        *********\n");
	printf("**************************************\n");
	printf(" ������>: ");
}

void ini(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void PrintBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j < col - 1)
				printf("|");
		}
		printf("\n");
		for (int j = 0; j < col; j++)
		{
			if (i < row - 1)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void player(char board[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�˴��������ӣ����±�\n");
			}
		}
		else
		{
			printf("δ���ں���Χ�ڣ�����������\n");
		}
	}
}

void computer(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char is_win(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{

			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] !=' ')
			{
				if (board[i][1] == '*')
					return '1';
				else
					return '0';
			}
			else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			{
				if (board[0][i] == '*')
					return '1';
				else
					return '0';
			}
			else if ((board[0][0] == board[1][1] && board[2][2] == board[1][1] || board[0][2] == board[1][1] && board[2][0] == board[1][1]) && board[1][1] != ' ')
			{
				if (board[1][1] == '*')
					return '1';
				else
					return '0';
			}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if(board[i][j]==' ')
				return 'C';
		}
	}
	return 'Q';
}