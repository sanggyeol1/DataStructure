#include <stdio.h> // print 함수를 사용할 수 있도록 하는 라이브러리
#include <stdlib.h>// 표준 유틸리티 함수들을 모아놓은 라이브러리
#include <time.h> //랜덤값을 받아오기 위한 라이브러리
#define _CRT_SECURE_NO_WARNINGS // scanf를 사용하기 위한 라이브러리

#define MAX_SIZE 10 //MAX_SIZE는 10

int list[MAX_SIZE]; // 1000의 크기를 가진 배열 list 선언
int n; //int 자료형의 n선언

//gap 만큼 떨어진 요소들을 삽입 정렬
//정렬의 범위는 first에서last
void inc_insertion_sort(int list[],int first, int last, int gap)//삽입정렬
{
	int i, j, key; // int 자료형의 i,j,key선언
	for (i = first + gap; i <= last; i = i + gap) { //분할된 셀 내의 요소 갯수만큼 반복
		key = list[i]; // key는 list[i]
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) // 셀 내에서 반복
			list[j + gap] = list[j]; // 
		list[j + gap] = key;
	}
}

void shell_sort(int list[], int n)
{
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0)gap++;
			for (i = 0; i < gap; i++)
				inc_insertion_sort(list, i, n - 1, gap);
	}
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++)
		list[i] = rand() % 100;

	shell_sort(list, n);
	for (i = 0; i < n; i++)printf("%d ", list[i]);
	printf("\n");
	return 0;
}


