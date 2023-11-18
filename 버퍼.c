#define _CRT_SECURE_NO_WARNINGS //scanf를 오류없이 사용할 수 있게 하는 코드
#include <stdio.h> // printf를 사용할 수 있게 하는 코드
#include <stdlib.h> // 유틸리티 함수 라이브러리 불러오기

#define MAX_QUEUE_SIZE 5 //최대 큐 사이즈 정의 = 5
typedef int element; // int 자료형을 element자료형으로 치환 가능
typedef struct { // 구조체 선언
	element data[MAX_QUEUE_SIZE]; // element 자료형인 data 배열선언
	int front, rear; // int 자료형인 front , rear변수 선언
} QueueType; // 구조체 이름은 QueueType

void error(const char* message) // 에러 표기 함수
{
	fprintf(stderr, "%s\n", message); // 오류 메세지 출력
	exit(1); // 탈출
}

void init_queue(QueueType* q) //큐 초기화 함수
{
	q->front = q->rear = 0; // 큐의 front 와 rear를 0으로 설정 : 공백상태
}

int is_empty(QueueType* q) // 공백상태 검출 함수
{
	return (q->front == q->rear); // 큐의 front와 rear가 같은 상태를 반환함
}

int is_full(QueueType* q) // 포화상태 검출 함수
{
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front); // 큐의 rear+1을 큐의 최대 사이즈로 나누었을 때 나머지 == 큐의 front 반환 (포화상태)
}

void queue_print(QueueType* q) // 큐 프린트함수
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear); // 큐의 front와 rear 출력
	if (!is_empty(q)) { // 만약 큐가 비어있지 않다면
		int i = q->front; // 큐의 front를 변수 i에 넣음
		do { // do while 문
			i = (i + 1) % (MAX_QUEUE_SIZE);//i에 (i+1)%MAX_QUEUE_SIZE 대입,즉 i는 front의 다음칸
			printf("%d | ", q->data[i]); // 큐의 가장 첫번째 데이터 출력
			if (i == q->rear) // 만약 i가 큐의 마지막 요소라면 (rear에 위치)
				break; // while문 탈출
		} while (i != q->front);// i가 
	}
	printf("\n"); // 행 변경
}

void enqueue(QueueType* q, element item) // 큐 삽입함수
{
	if (is_full(q)) // 큐가 포화상태라면
		error("큐가 포화상태입니다."); // error메시지 출력
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // 큐의 rear에 (q->rear+1)을 큐의최대사이즈로 나눈 값 대입 (rear한칸 이동)
		q->data[q->rear] = item; // 큐의 rear에 item 삽입
}

element dequeue(QueueType* q) // 큐 삭제 함수
{
	if (is_empty(q)) // 큐가 공백상태라면 
		error("큐가 공백상태입니다."); // error 메시지 출력
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // 큐의 front에 (q->front)를 큐의 최대사이즈로 나눈 값 대입 (front 한칸 이동)
	return q->data[q->front]; // data의 front번째 값 반환(삭제됨)
}

element peek(QueueType* q) // 큐의 요소 중 첫번째 값 반환함수
{
	if (is_empty(q)) // 만약 큐가 공백상태라면
		error("큐가 공백상태입니다."); // error메시지 출력
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE]; // 큐의 front+1을 큐의 최대사이즈로 나눈 값을 반환함(front+1하면 큐 자료의 첫번째에 해당)
}

int main(void)// 메인함수
{
	QueueType queue; // 큐 선언
	int element;	// int 자료형의 element 변수 선언

	init_queue(&queue); // 큐 초기화
	srand(time(NULL)); // 난수 생성

	for (int i = 0; i < 100; i++) { // 100번 반복하는 for 문
		if (rand() % 5 == 0) { // 난수가 5의 배수라면
			enqueue(&queue, rand() % 100); // 난수를 큐에 삽입
		}
		queue_print(&queue); // 큐를 출력함
		if (rand() % 10 == 0) { // 난수가 10의 배수라면
			int data = dequeue(&queue); // data변수에 삭제한 요소 삽입
		}
		queue_print(&queue); //큐 프린트
	}
	return 0; //0반환
}