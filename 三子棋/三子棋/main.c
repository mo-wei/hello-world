#define _CRT_SECURE_NO_WARNINGS 1
//��������Ϸ
#include "game.h"
int main()
{
	//���� ����--��ά����
	char board[ROW][COL] ;
	int input;
	srand((unsigned int)time(NULL));
	//�˵�
	manu();

	do{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game(board);
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:printf("�������룬����������0/1\n");
			break;
		}
	} while (input);
}