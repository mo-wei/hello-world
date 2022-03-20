#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define SET 15
extern int blank;
void InitBoard(char ch[][COLS], int row, int col, char init);
void print(char ch[][COLS], int row, int col);
void set(char ch[][COLS]);
int check(char mine[][COLS], char show[][COLS]);
