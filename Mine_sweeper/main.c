#include "Mine_sweeper.h"

void menu()
{
	printf("*****************************\n");
	printf("*****  1. play  0. exit *****\n");
	printf("*****************************\n");
}

void game() {
	char mine[ROW][COL] = { '0' };
	char sweep[ROW][COL] = { '0' };

	//��ʼ����������
	Init_board(mine, ROW, COL, '0');

	//��ʼ��ɨ������
	Init_board(sweep, ROW, COL, '*');

	//������
	Set_Mine(mine, ROW, COL, Easy_Count);

	//print_board(mine, ROW, COL);

	//��ӡ����
	print_board(sweep, ROW, COL);

	//����
	Fine_Mine(mine, sweep, ROW, COL);

	//��ӡ����
	//print_board(mine, ROW, COL);

}

int main() {
	int n = 0;
	//��ʼ�������������
	srand((unsigned int)time(NULL));

	do
	{
		// ��ӡ�˵�
		menu();
		printf("��ѡ��:>");
		scanf("%d", &n);

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