#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

#define DEFAULT_NUM 3
#define INCREMENT_NUM 2


//ÿ���˰�������Ϣ
typedef struct Person
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}Person;



typedef struct Contact {
	int count;          //��ǰͨѶ¼��ʵ����ϵ�˵�����
	int capacity;       //��ǰͨѶ¼�ɴ洢��ϵ�˵�����
	Person* person;    //��ϵ�˵���Ϣ
}Contact;



//��ʼ��ͨѶ¼
void init_Contact(Contact* pc);
//�����ϵ��
void add_Contact(Contact* pc);
//��ʾͨѶ¼
void print_Contact(const Contact* pc);
//ɾ��ͨѶ¼��ָ����ϵ��
void del_Contact(Contact* pc);
//����ͨѶ¼��ָ����ϵ��
void Search_Contact(const Contact* pc);
//�޸�ͨѶ¼��ָ����ϵ����Ϣ
void Modify_Contact(Contact* pc);
//��ͨѶ¼��������
void Sort_Contact(Contact* pc);
//����ͨѶ¼
void Destroy_Contact(Contact* pc);
//����ͨѶ¼����Ϣ���ļ�
void Save_Contact(Contact* pc);
//�����ļ�����Ϣ��ͨѶ¼
void Load_Contact(Contact* pc);
