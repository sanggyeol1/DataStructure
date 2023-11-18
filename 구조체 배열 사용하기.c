#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SATCK_SIZE 100
#define MAX_STRING 100

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char adress[MAX_STRING];
}element;
element stack[MAX_SATCK_SIZE];
int top = -1;

int is_empty()
{
	return(top == -1);
}
int is_full()
{
	return (top == (MAX_SATCK_SIZE - 1));
}
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}

element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}

element peek()
{
	if (is_empty()) {
		printf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}

int main(void)
{
	element ie = { 20190001,
			"HONG",
			"Gachon Univ." };
	element oe;
	push(ie);
	oe = pop();

	printf("�й�: %d\n", oe.student_no);
	printf("�̸�: %s\n", oe.name);
	printf("�б�: %s\n", oe.adress);
	return 0;
}
