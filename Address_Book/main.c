#include "contact.h"

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

void menu() {
	printf("*********************************************\n");
	printf("******  1. add             2. del     *******\n");
	printf("******  3. search          4. modify  *******\n");
	printf("******  5. show            6. sort    *******\n");
	printf("******  0. exit                       *******\n");
	printf("*********************************************\n");
}

int main() {
	int input = 0;

	Contact ct;
	init_Contact(&ct);

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			add_Contact(&ct);
			break;
		case DEL:
			del_Contact(&ct);
			break;
		case SEARCH:
			Search_Contact(&ct);
			break;
		case MODIFY:
			Modify_Contact(&ct);
			break;
		case SHOW:
			print_Contact(&ct);
			break;
		case SORT:
			Sort_Contact(&ct);
			break;
		case EXIT:
			Save_Contact(&ct);
			Destroy_Contact(&ct);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);

	return 0;
}