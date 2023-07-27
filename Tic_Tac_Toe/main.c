#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("*****  1. play  0. exit *****\n");
	printf("*****************************\n");
}

void game() {
	char chessboard[ROW][COL] = { 0 };
	Init_board(chessboard, ROW, COL);
	print_board(chessboard, ROW, COL);

	int ret = 0;
	while (1)
	{
		Player_chess(chessboard, ROW, COL);
		print_board(chessboard, ROW, COL);

		ret = Is_win(chessboard, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		Computer_chess(chessboard, ROW, COL);
		print_board(chessboard, ROW, COL);

		ret = Is_win(chessboard, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}

	//�ж���˭Ӯ��
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}

}

int main(int argc, char const* argv[])
{
	int n = 0;

	//��ʼ���������
	srand((unsigned int)time(NULL));

	do
	{
		// ��ӡ�˵�
		menu();
		printf("������:>");

		//��ȡ�û����� 
		scanf("%d", &n);

		// �ж��Ƿ�����Ϸ
		switch (n)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (n);
	return 0;
}
