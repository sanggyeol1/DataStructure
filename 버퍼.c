#define _CRT_SECURE_NO_WARNINGS //scanf�� �������� ����� �� �ְ� �ϴ� �ڵ�
#include <stdio.h> // printf�� ����� �� �ְ� �ϴ� �ڵ�
#include <stdlib.h> // ��ƿ��Ƽ �Լ� ���̺귯�� �ҷ�����

#define MAX_QUEUE_SIZE 5 //�ִ� ť ������ ���� = 5
typedef int element; // int �ڷ����� element�ڷ������� ġȯ ����
typedef struct { // ����ü ����
	element data[MAX_QUEUE_SIZE]; // element �ڷ����� data �迭����
	int front, rear; // int �ڷ����� front , rear���� ����
} QueueType; // ����ü �̸��� QueueType

void error(const char* message) // ���� ǥ�� �Լ�
{
	fprintf(stderr, "%s\n", message); // ���� �޼��� ���
	exit(1); // Ż��
}

void init_queue(QueueType* q) //ť �ʱ�ȭ �Լ�
{
	q->front = q->rear = 0; // ť�� front �� rear�� 0���� ���� : �������
}

int is_empty(QueueType* q) // ������� ���� �Լ�
{
	return (q->front == q->rear); // ť�� front�� rear�� ���� ���¸� ��ȯ��
}

int is_full(QueueType* q) // ��ȭ���� ���� �Լ�
{
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front); // ť�� rear+1�� ť�� �ִ� ������� �������� �� ������ == ť�� front ��ȯ (��ȭ����)
}

void queue_print(QueueType* q) // ť ����Ʈ�Լ�
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear); // ť�� front�� rear ���
	if (!is_empty(q)) { // ���� ť�� ������� �ʴٸ�
		int i = q->front; // ť�� front�� ���� i�� ����
		do { // do while ��
			i = (i + 1) % (MAX_QUEUE_SIZE);//i�� (i+1)%MAX_QUEUE_SIZE ����,�� i�� front�� ����ĭ
			printf("%d | ", q->data[i]); // ť�� ���� ù��° ������ ���
			if (i == q->rear) // ���� i�� ť�� ������ ��Ҷ�� (rear�� ��ġ)
				break; // while�� Ż��
		} while (i != q->front);// i�� 
	}
	printf("\n"); // �� ����
}

void enqueue(QueueType* q, element item) // ť �����Լ�
{
	if (is_full(q)) // ť�� ��ȭ���¶��
		error("ť�� ��ȭ�����Դϴ�."); // error�޽��� ���
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // ť�� rear�� (q->rear+1)�� ť���ִ������� ���� �� ���� (rear��ĭ �̵�)
		q->data[q->rear] = item; // ť�� rear�� item ����
}

element dequeue(QueueType* q) // ť ���� �Լ�
{
	if (is_empty(q)) // ť�� ������¶�� 
		error("ť�� ��������Դϴ�."); // error �޽��� ���
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // ť�� front�� (q->front)�� ť�� �ִ������� ���� �� ���� (front ��ĭ �̵�)
	return q->data[q->front]; // data�� front��° �� ��ȯ(������)
}

element peek(QueueType* q) // ť�� ��� �� ù��° �� ��ȯ�Լ�
{
	if (is_empty(q)) // ���� ť�� ������¶��
		error("ť�� ��������Դϴ�."); // error�޽��� ���
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE]; // ť�� front+1�� ť�� �ִ������� ���� ���� ��ȯ��(front+1�ϸ� ť �ڷ��� ù��°�� �ش�)
}

int main(void)// �����Լ�
{
	QueueType queue; // ť ����
	int element;	// int �ڷ����� element ���� ����

	init_queue(&queue); // ť �ʱ�ȭ
	srand(time(NULL)); // ���� ����

	for (int i = 0; i < 100; i++) { // 100�� �ݺ��ϴ� for ��
		if (rand() % 5 == 0) { // ������ 5�� ������
			enqueue(&queue, rand() % 100); // ������ ť�� ����
		}
		queue_print(&queue); // ť�� �����
		if (rand() % 10 == 0) { // ������ 10�� ������
			int data = dequeue(&queue); // data������ ������ ��� ����
		}
		queue_print(&queue); //ť ����Ʈ
	}
	return 0; //0��ȯ
}