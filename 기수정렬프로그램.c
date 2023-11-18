#include <stdio.h> // print �Լ��� ����� �� �ֵ��� �ϴ� ���̺귯��
#include <stdlib.h>// ǥ�� ��ƿ��Ƽ �Լ����� ��Ƴ��� ���̺귯��
#include <time.h> //�������� �޾ƿ��� ���� ���̺귯��
#define _CRT_SECURE_NO_WARNINGS // scanf�� ����ϱ� ���� ���̺귯��

#define MAX_QUEUE_SIZE 100 //�ִ� ť ����� 100���� ����
typedef int element; // int �ڷ����� element�� ġȯ ����
typedef struct { //����ü ����
	element data[MAX_QUEUE_SIZE]; // element�ڷ����� �迭(ũ�� 100)�� data����
	int front, rear; // int �ڷ����� front�� rear����
}QueueType; //����ü �̸��� QueueType


void error(const char* message)//�����Լ�
{
	fprintf(stderr, "%s\n", message);//�����Լ� ����
	exit(1);//����Ż��
}


void init_queue(QueueType* q)//�ʱ�ȭ�Լ�
{
	q->front = q->rear = 0;//ť�� front�� rear�� 0�� �����ν� �ʱ� ���� �ҷ���
}


int is_empty(QueueType* q)//������°����Լ�
{
	return (q->front == q->rear); //ť�� front�� rear�� ���� ���¸� ��ȯ�Ͽ� ������� ����
}

int is_full(QueueType* q) // ��ȭ���°����Լ�
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); //ť�� rear������ ��ĭ ������ �̵��ϸ� ť�� front���� ���� == ��ȭ���� 
}

void enqueue(QueueType* q, element item) //ť ���� �Լ�
{
	if (is_full(q))error("ť�� ��ȭ�����Դϴ�.");//���� ť�� ��ȭ���¸� �����Լ�
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //ť�� rear��ĭ �̵�
	q->data[q->rear] = item; // ť��rear�� item����
}

element dequeue(QueueType* q) //ť �� ������ ���� �Լ�
{
	if (is_empty(q))error("ť�� ��������Դϴ�."); // ť�� ��������� �����Լ�
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // ť�� front ��ĭ �̵�
	return q->data[q->front];//front �� ��ȯ
}

#define BUCKETS 10 //BUCKETS�� 10
#define DIGITS 4 // DIGITS�� 4
void radix_sort(int list[], int n) // ��������Լ�
{
	int i, b, d, factor = 1; // int �ڷ����� i, b, d, factor �� 1 ����
	QueueType queues[BUCKETS]; // QueueType�ڷ����� �迭 queue����(������� 10)

	for (b = 0; b < BUCKETS; b++)init_queue(&queues[b]); //10ȸ �ݺ��ϸ� ť �ʱ�ȭ
	for (d = 0; d < DIGITS; d++) { // 4ȸ �ݺ�
		for (i = 0; i < n; i++) // nȸ�ݺ�
			enqueue(&queues[(list[i] / factor) % 10], list[i]);//ť�� ����Ʈ ����
		for (b = i = 0; b < BUCKETS; b++) // 10ȸ �ݺ��ϸ�
			while (!is_empty(&queues[b])) // queues��[i]�� ������� �ʴµ���
				list[i++] = dequeue(&queues[b]); //ť���� �� ���� ����Ʈ�� ����
		factor *= 10; // factor�� 10 ����(�� �ڸ��� �����Ϸ���)
	}
}

#define SIZE 10 //SIZE�� 10
int main(void) //�����Լ�
{ 
	int list[SIZE]; // �迭 list ����
	srand(time(NULL)); // ���� ����

	for (int i = 0; i < SIZE; i++) // SIZE �� 10ȸ �ݺ�
		list[i] = rand() % 100; // list[i]�� 0~99������ ���� ����

	radix_sort(list, SIZE); // �������
	for (int i = 0; i < SIZE; i++) // 10ȸ �ݺ�
		printf("%d ", list[i]); // list[i]���
	printf("\n"); //�� �ٲ�
	return 0; // 0��ȯ
}