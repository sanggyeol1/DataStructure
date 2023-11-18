#include <stdio.h> // print 함수를 사용할 수 있도록 하는 라이브러리
#include <stdlib.h>// 표준 유틸리티 함수들을 모아놓은 라이브러리
#include <time.h> //랜덤값을 받아오기 위한 라이브러리
#define _CRT_SECURE_NO_WARNINGS // scanf를 사용하기 위한 라이브러리

#define MAX_QUEUE_SIZE 100 //최대 큐 사이즈를 100으로 상정
typedef int element; // int 자료형을 element로 치환 가능
typedef struct { //구조체 정의
	element data[MAX_QUEUE_SIZE]; // element자료형의 배열(크기 100)인 data선언
	int front, rear; // int 자료형의 front와 rear선언
}QueueType; //구조체 이름은 QueueType


void error(const char* message)//오류함수
{
	fprintf(stderr, "%s\n", message);//오류함수 출혁
	exit(1);//오류탈출
}


void init_queue(QueueType* q)//초기화함수
{
	q->front = q->rear = 0;//큐의 front와 rear을 0에 둠으로써 초기 상태 불러옴
}


int is_empty(QueueType* q)//공백상태검출함수
{
	return (q->front == q->rear); //큐의 front와 rear가 같은 상태를 반환하여 공백상태 검출
}

int is_full(QueueType* q) // 포화상태검출함수
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); //큐의 rear값에서 한칸 앞으로 이동하면 큐의 front값과 동일 == 포화상태 
}

void enqueue(QueueType* q, element item) //큐 삽입 함수
{
	if (is_full(q))error("큐가 포화상태입니다.");//만약 큐가 포화상태면 에러함수
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //큐의 rear한칸 이동
	q->data[q->rear] = item; // 큐의rear에 item삽입
}

element dequeue(QueueType* q) //큐 내 아이템 삭제 함수
{
	if (is_empty(q))error("큐가 공백상태입니다."); // 큐가 비어있으면 에러함수
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // 큐의 front 한칸 이동
	return q->data[q->front];//front 값 반환
}

#define BUCKETS 10 //BUCKETS는 10
#define DIGITS 4 // DIGITS는 4
void radix_sort(int list[], int n) // 기수정렬함수
{
	int i, b, d, factor = 1; // int 자료형의 i, b, d, factor 는 1 선언
	QueueType queues[BUCKETS]; // QueueType자료형의 배열 queue선언(사이즈는 10)

	for (b = 0; b < BUCKETS; b++)init_queue(&queues[b]); //10회 반복하며 큐 초기화
	for (d = 0; d < DIGITS; d++) { // 4회 반복
		for (i = 0; i < n; i++) // n회반복
			enqueue(&queues[(list[i] / factor) % 10], list[i]);//큐에 리스트 삽입
		for (b = i = 0; b < BUCKETS; b++) // 10회 반복하며
			while (!is_empty(&queues[b])) // queues의[i]가 비어있지 않는동안
				list[i++] = dequeue(&queues[b]); //큐에서 뺀 값을 리스트에 삽입
		factor *= 10; // factor를 10 곱함(윗 자릿수 정렬하려고)
	}
}

#define SIZE 10 //SIZE는 10
int main(void) //메인함수
{ 
	int list[SIZE]; // 배열 list 선언
	srand(time(NULL)); // 난수 형성

	for (int i = 0; i < SIZE; i++) // SIZE 즉 10회 반복
		list[i] = rand() % 100; // list[i]에 0~99까지의 난수 삽입

	radix_sort(list, SIZE); // 기수정렬
	for (int i = 0; i < SIZE; i++) // 10회 반복
		printf("%d ", list[i]); // list[i]출력
	printf("\n"); //행 바꿈
	return 0; // 0반환
}