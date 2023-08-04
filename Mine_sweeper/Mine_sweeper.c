#include "Mine_sweeper.h"


void Init_board(char board[ROW][COL], int row, int col, char value) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = value;
		}
	}
}


void print_board(char board[ROW][COL], int row, int col) {
	printf("-------ɨ����Ϸ-----\n");
	printf("  ");
	for (int i = 1; i < col - 1; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 1; i < row - 1; i++)
	{
		printf("%d ", i);
		for (int j = 1; j < col - 1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------ɨ����Ϸ-----\n");
}


void Set_Mine(char board[ROW][COL], int row, int col, int num) {
	while (num)
	{
		int x = rand() % (row - 2) + 1;
		int y = rand() % (col - 2) + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			num--;
		}
	}
}


int get_mine_count(char board[ROW][COL], int x, int y) {
	//printf("%c\n", board[x - 1][y - 1]);
	//return board[x - 1][y - 1] - '0';
	return (board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] +
		board[x][y - 1] + board[x][y + 1] +
		board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] - 8 * '0');
}

void Fine_Mine(char mine[ROW][COL], char sweep[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	int step = 0;

	while (step < row * col - Easy_Count)
	{
		printf("����������:>");
		scanf("%d %d", &x, &y);

		//�ж������Ƿ�Ϸ�
		if ((x > 0 && x < row - 1) && (y > 0 && y < col - 1))
		{
			if (sweep[x][y] != '*')
			{
				printf("�����걻�Ų����\n");
			}
			else
			{
				//�ж�������ǲ�����
				if (mine[x][y] == '1') {
					printf("ɨ��ʧ��\n");
					print_board(mine, row, col);
					break;
				}
				else
				{
					//�����������Χ�м�����
					int num = get_mine_count(mine, x, y);
					//printf("num=%d\n", num);
					sweep[x][y] = num + '0';
					print_board(sweep, row, col);
					step++;
				}
			}
		}
		else
		{
			printf("���벻�Ϸ�������������");
		}

		if (step == row * col - Easy_Count)
		{
			printf("��ϲ�㣬���׳ɹ�\n");
			print_board(mine, row, col);
		}
	}
}