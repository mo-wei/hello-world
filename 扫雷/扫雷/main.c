#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
char mine[ROWS][COLS];
char show[ROWS][COLS];
int  blank = ROW * COL - SET;
void game(void)
{
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	// ����
	set(mine);
	//��ӡ����
	print(mine, ROWS, COLS);
	print(show, ROWS, COLS);
	//���벢�ж�

	while (blank > 0)
	{
		//�ж�����еĲ���
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
					printf("��Ӯ��\n");
				}
			}
			else
			{
				system("cls");
				printf("�㱻ը����\n");
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
	printf("������Ϸ������1������Ϊ���ף�����2������Ϊ����\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		manu();
		printf("������>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		}
	} while (input);
	printf("�˳���Ϸ");
	return 0;
}
