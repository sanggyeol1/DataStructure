#include <stdio.h> // print 함수를 사용할 수 있도록 하는 라이브러리
#include <stdlib.h>// 표준 유틸리티 함수들을 모아놓은 라이브러리
#include <time.h> //랜덤값을 받아오기 위한 라이브러리
#define _CRT_SECURE_NO_WARNINGS // scanf를 사용하기 위한 라이브러리
#define MAX_SIZE 10 //MAX_SIZE는 10 상정
int list[MAX_SIZE]; // int 자료형의 배열 list 선언
int n; //int자료형의 n선언


void insertion_sort(int list[], int n)//배열list와 n을 인수로 받는 삽입정렬
{
	int i, j, key; // int 자료형의 i,j,key 선언
	for (i = 1; i < n; i++) { // 두번째부터 끝까지 반복
		key = list[i]; //list[i]는 키값
		for (j = i - 1; j >= 0 && list[j] > key; j--)//키값 이전값부터 끝까지 반복, key보다 작은값을 만나면 stop
			list[j + 1] = list[j]; //레코드를 오른쪽으로  밈
		list[j + 1] = key;	//key값 삽입
	}
}

int main(void)//메인함수
{
	int i; //int 자료형의 i선언 
	n = MAX_SIZE; //n은 MAX_SIZE즉, 10
	srand(time(NULL)); // 난수 형성
	for (i = 0; i < n; i++) //10번 반복
		list[i] = rand() % 100; //list[i]의 범위는 0~99

	insertion_sort(list, n); //삽입정렬 수행
	for (i = 0; i < n; i++) //10번 반복
		printf("%d ",list[i]); // list[i]출력
	printf("\n"); // 행 내림
	return 0; //0반환
}