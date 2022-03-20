#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>;
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//游戏总函数
void game(char board[ROW][COL]);
//打印菜单的函数
void manu(void);
//初始化数组的函数  
void ini(char board[ROW][COL], int row, int col);
//打印棋盘的函数
void PrintBoard(char board[ROW][COL], int row, int col);
//玩家下棋的函数
void player(char board[ROW][COL], int row, int col);
//电脑下棋的函数
void computer(char board[ROW][COL], int row, int col);
//判断输赢函数
char is_win(char board[ROW][COL], int row, int col);