#include <stdio.h> // print 함수를 사용할 수 있도록 하는 라이브러리
#include <stdlib.h>// 표준 유틸리티 함수들을 모아놓은 라이브러리
#define _CRT_SECURE_NO_WARNINGS // scanf를 사용하기 위한 라이브러리
#define MAX_ELEMENT 200 //MAX_ELEMENT는 200
typedef struct { //구조체 선언
	int key; //int자료형의 key선언
}element; // 구조체 이름은 element
 
typedef struct { // 구조체 선언
	element heap[MAX_ELEMENT]; //element 자료형의 배열 heap 선언
	int heap_size; //int자료형의 heap사이즈 선언
}HeapType; //구조체 이름은 HeapType

HeapType* create() //힙 생성 함수
{
	return(HeapType*)malloc(sizeof(HeapType));//힙 동적할당
}

void init(HeapType* h) //힙 초기화 함수
{
	h->heap_size = 0; //힙의 사이즈는 0
}

//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
void insert_max_heap(HeapType* h, element item)//힙 요소삽입 함수
{
	int i; //int 자료형의 i선언
	i = ++(h->heap_size); //힙의 사이즈 하나 늘리고 i에 넣음

	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while((i!=1)&(item.key>h->heap[i/2].key)){// 힙의 사이즈가 1이 아니면서 아이템의 키값이 부모의 키값보다 크면
		h->heap[i] = h->heap[i / 2]; // 힙의 맨 끝에 부모노드 복사
		i /= 2; // i를 2로 나눔
	}
	h->heap[i] = item; //새로운 노드를 삽입
}

//삭제 함수
element delete_max_heap(HeapType* h) //힙의 요소 삭제 함수
{
	int parent, child; //int 자료형의 parent, child선언
	element item, temp; //element자료형의 item과temp선언
	item = h->heap[1]; // item에 루트 노드 삽입
	temp = h->heap[(h->heap_size)--];//힙의 마지막 값을 temp에 넣음
	parent = 1; //parent에 1넣음
	child = 2; // child에 2넣음
	while (child <= h->heap_size) { //child가 힙의 사이즈보다 작을때 계속 반복
		
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)child++; //현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.

		if (temp.key >= h->heap[child].key)break; //만약 temp의 키값보다 자식노드의 키값이 작거나 같으면 반복 멈춤
		//한 단계 아래로 이동
		h->heap[parent] = h->heap[child];//힙의 부모번째 인덱스에 힙의 자식번째 인덱스 삽입
		parent = child; //parent에 child삽입
		child *= 2; // child에 2 곱함
	}
	h->heap[parent] = temp; // 최종 위치에 temp값 저장
	return item; // 아이템값 반환
}

void heap_sort(element a[], int n)
{
	int i; // int자료형의 변수i선언
	HeapType* h; // 힙타입 구조체 h선언
	h = create(); // 힙 생성 
	init(h); //힙 초기화
	for (i = 0; i < n; i++)insert_max_heap(h, a[i]); // n번반복하며 힙에 요소 삽입
	for (i = (n - 1); i >= 0; i--)a[i] = delete_max_heap(h); //힙에서 삭제된 요소를 배열에 저장
	free(h);//힙 메모리 해제
}

#define SIZE 8 //SIZE 는 8
int main(void) //메인함수
{
	element list[SIZE] = { 23, 56, 11, 9, 56, 99, 27, 34 };//element 자료형의 배열 list선언
	heap_sort(list, SIZE); // heap
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");
	return 0;
}