#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>;
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//��Ϸ�ܺ���
void game(char board[ROW][COL]);
//��ӡ�˵��ĺ���
void manu(void);
//��ʼ������ĺ���  
void ini(char board[ROW][COL], int row, int col);
//��ӡ���̵ĺ���
void PrintBoard(char board[ROW][COL], int row, int col);
//�������ĺ���
void player(char board[ROW][COL], int row, int col);
//��������ĺ���
void computer(char board[ROW][COL], int row, int col);
//�ж���Ӯ����
char is_win(char board[ROW][COL], int row, int col);