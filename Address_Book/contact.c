#include "contact.h"


static int FindByName(Contact* pc, char* name) {
	for (int i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->person[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}


static int CompareByName(const void* e1, const void* e2) {
	return strcmp(((Person*)e1)->name, ((Person*)e2)->name);
}



void init_Contact(Contact* pc) {
	assert(pc);
	pc->count = 0;
	pc->capacity = DEFAULT_NUM;
	Person* ptr = (Person*)malloc(DEFAULT_NUM * sizeof(Person));
	if (ptr == NULL)
	{
		perror("��ʼ��ʧ��");
		return;
	}
	pc->person = ptr;
	Load_Contact(pc);
}



void add_Contact(Contact* pc) {
	assert(pc);
	if (pc->count == pc->capacity)
	{
		Person* ptr = (Person*)realloc(pc->person, (pc->capacity + INCREMENT_NUM) * sizeof(Person));
		if (ptr == NULL)
		{
			perror("��ʼ��ʧ��");
			return;
		}
		pc->person = ptr;
		pc->capacity += INCREMENT_NUM;
		printf("�������ӳɹ�\n");
	}

	//��ȡ����ӵ���Ϣ
	printf("����������:>");
	scanf("%s", pc->person[pc->count].name);
	printf("����������:>");
	scanf("%d", &(pc->person[pc->count].age));
	printf("�������Ա�:>");
	scanf("%s", pc->person[pc->count].sex);
	printf("������绰:>");
	scanf("%s", pc->person[pc->count].tele);
	printf("�������ַ:>");
	scanf("%s", pc->person[pc->count].addr);

	pc->count++;
	printf("��ӳɹ�\n");
}


void print_Contact(const Contact* pc) {
	assert(pc);
	printf("%-3s\t%-25s\t%-5s\t%-5s\t%-11s\t%-30s\n", " ", "Name", "Age", "Sex", "Tele", "Address");
	for (int i = 0; i < pc->count; i++)
	{
		printf("%-3d\t%-25s\t%-5d\t%-5s\t%-11s\t%-30s\n", i + 1,
			pc->person[i].name,
			pc->person[i].age,
			pc->person[i].sex,
			pc->person[i].tele,
			pc->person[i].addr);
	}
}


void del_Contact(Contact* pc) {
	assert(pc);
	char name[MAX_NAME];

	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û����ϵ�˿���ɾ��\n");
		return;
	}

	printf("������Ҫɾ����ϵ�˵�����:>");
	scanf("%s", name);

	//����ָ��������ϵ������λ��
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
		return;
	}

	//ɾ������ϵ��
	for (int i = ret; i < pc->count - 1; i++)
	{
		pc->person[i] = pc->person[i + 1];
	}
	pc->count--;
	printf("����ϵ����ɾ��\n");
}


void Search_Contact(const Contact* pc) {
	assert(pc);
	char name[MAX_NAME];

	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û����ϵ�˿��Բ���\n");
		return;
	}

	printf("������Ҫ������ϵ�˵�����:>");
	scanf("%s", name);

	//����ָ��������ϵ������λ��
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫ���ҵ���ϵ�˲�����\n");
		return;
	}

	//��ӡ���ҵ�����ϵ����Ϣ
	printf("%-3s\t%-10s\t%-5s\t%-5s\t%-11s\t%-30s\n", " ", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-3d\t%-10s\t%-5d\t%-5s\t%-11s\t%-30s\n", ret + 1,
		pc->person[ret].name,
		pc->person[ret].age,
		pc->person[ret].sex,
		pc->person[ret].tele,
		pc->person[ret].addr);
}


void Modify_Contact(Contact* pc) {
	assert(pc);
	char name[MAX_NAME];

	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û����ϵ�˿����޸�\n");
		return;
	}

	printf("������Ҫ�޸���ϵ�˵�����:>");
	scanf("%s", name);

	//����ָ��������ϵ������λ��
	int ret = FindByName(pc, name);
	if (ret == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
		return;
	}
	printf("Ҫ�޸ĵ���ϵ���Ѳ��ҵ�����������ʼ�޸�\n");

	//�޸���ϵ����Ϣ
	printf("����������:>");
	scanf("%s", pc->person[ret].name);
	printf("����������:>");
	scanf("%d", &(pc->person[ret].age));
	printf("�������Ա�:>");
	scanf("%s", pc->person[ret].sex);
	printf("������绰:>");
	scanf("%s", pc->person[ret].tele);
	printf("�������ַ:>");
	scanf("%s", pc->person[ret].addr);

	printf("�޸ĳɹ�\n");
}


void Sort_Contact(Contact* pc) {
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����Ҫ����\n");
		return;
	}

	qsort(pc->person, pc->count, sizeof(Person), CompareByName);
	printf("�������\n");
}


void Destroy_Contact(Contact* pc) {
	assert(pc);
	free(pc->person);
	pc->person = NULL;
}


void Save_Contact(Contact* pc) {
	assert(pc);
	FILE* fp = fopen("contact.txt", "wb");
	if (fp == NULL)
	{
		perror("���ļ�ʧ��");
	}
	else
	{
		//fprintf(fp, "%-3s\t%-15s\t%-5s\t%-5s\t%-11s\t%-30s\n", " ", "����", "����", "�Ա�", "�绰", "��ַ");
		for (int i = 0; i < pc->count; i++)
		{
			fwrite(pc->person + i, sizeof(Person), 1, fp);
		}
		fclose(fp);
		fp = NULL;
	}
}




void Load_Contact(Contact* pc) {
	assert(pc);
	FILE* fp = fopen("contact.txt", "rb");
	if (fp == NULL)
	{
		perror("���ļ�ʧ��");
		return;
	}
	else
	{
		Person tmp;
		while (fread(&tmp, sizeof(Person), 1, fp))
		{
			int i = 0;
			if (pc->count == pc->capacity)
			{
				Person* ptr = (Person*)realloc(pc->person, (pc->capacity + INCREMENT_NUM) * sizeof(Person));
				if (ptr == NULL)
				{
					perror("��ʼ��ʧ��");
					return;
				}
				pc->person = ptr;
				pc->capacity += INCREMENT_NUM;
				printf("�������ӳɹ�\n");
			}
			pc->person[pc->count] = tmp;
			pc->count++;
		}
		fclose(fp);
		fp = NULL;
	}
}