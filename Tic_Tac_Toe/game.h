#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3


//��ʼ������
void Init_board(char chessboard[ROW][COL], int row, int col);

//��ӡ����
void print_board(char chessboard[ROW][COL], int row, int col);


//�������
void Player_chess(char chessboard[ROW][COL], int row, int col);


//��������
void Computer_chess(char chessboard[ROW][COL], int row, int col);

//�ж���Ӯ
char Is_win(char chessboard[ROW][COL], int row, int col);

//�����Ƿ�����
int Is_full(char chessboard[ROW][COL], int row, int col);