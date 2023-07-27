//#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void Init_board(char chessboard[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			chessboard[i][j] = ' ';
		}
	}
}

void print_board(char chessboard[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		// ��ӡÿ�н��
		for (int j = 0; j < col; j++)
		{
			// ����ʽ��ӡÿ����Ԫ��
			printf(" %c ", chessboard[i][j]);


			// ��ӡ�зָ���
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");

		// ��ӡ�зָ���
		if (i < row - 1)
		{
			for (int k = 0; k < col; k++)
			{
				printf("---");

				// ��ӡ�зָ���
				if (k < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
	printf("\n");
}


void Player_chess(char chessboard[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;

	printf("��ҿ�ʼ����:>\n");
	while (1)
	{
		printf("����������:>");
		scanf("%d %d", &x, &y);

		//�ж������Ƿ����
		if ((x > 0 && x <= row) && (y > 0 && y <= col))
		{
			//�ж������Ƿ��Ѿ���ռ��
			if (chessboard[x - 1][y - 1] == ' ')
			{
				chessboard[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����ѱ�ռ�ã���ѡ������λ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}


void Computer_chess(char chessboard[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;

	printf("���Կ�ʼ����:>\n");
	while (1)
	{
		//�����������
		x = rand() % row;
		y = rand() % col;

		//�ж������Ƿ�ռ��
		if (chessboard[x][y] == ' ')
		{
			chessboard[x][y] = '#';
			break;
		}
	}

}

int Is_full(char chessboard[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (chessboard[i][j] == ' ')
			{
				return 0;
			}
		}
	}

	return 1;
}

char Is_win(char chessboard[ROW][COL], int row, int col) {
	//�����
	for (int i = 0; i < row; i++)
	{
		if (chessboard[i][0] == chessboard[i][1] && chessboard[i][1] == chessboard[i][2] && chessboard[i][0] != ' ')
		{
			return chessboard[i][0];
		}
	}

	//�����
	for (int j = 0; j < col; j++)
	{
		if (chessboard[0][j] == chessboard[1][j] && chessboard[1][j] == chessboard[2][j] && chessboard[0][j] != ' ')
		{
			return chessboard[0][j];
		}
	}

	//���Խ���
	if (chessboard[0][0] == chessboard[1][1] && chessboard[1][1] == chessboard[2][2] && chessboard[0][0] != ' ')
	{
		return chessboard[0][0];
	}

	if (chessboard[2][0] == chessboard[1][1] && chessboard[1][1] == chessboard[0][2] && chessboard[2][0] != ' ')
	{
		return chessboard[2][0];
	}

	if (Is_full(chessboard, row, col))
	{
		return 'Q';
	}

	return 'C';

}