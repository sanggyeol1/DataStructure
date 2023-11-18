#include <stdio.h> // print 함수를 사용할 수 있도록 하는 라이브러리
#include <stdlib.h>// 표준 유틸리티 함수들을 모아놓은 라이브러리
#include <time.h> //랜덤값을 받아오기 위한 라이브러리
#define _CRT_SECURE_NO_WARNINGS // scanf를 사용하기 위한 라이브러리

#define MAX_SIZE 10 //MAX_SIZE는 10

int list[MAX_SIZE]; // int 자료형의 배열 list 선언(사이즈 100)
int n; // int 자료형의 변수 n선언


#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t)) // x와 y를 바꾸는 SWAP선언
void bubble_sort(int list[], int n)//버블정렬 int 자료형과 int n 을 인수로 받음
{
	int i, j, temp; // int 자료형의 i, j, temp 선언
	for (i = n - 1; i > 0; i--) { // n-1부터 0이전까지 반복
		for (j = 0; j < i; j++) // 0부터 i-1까지 반복
			if (list[j] > list[j + 1])SWAP(list[j], list[j + 1], temp);//앞뒤의 레코드를 비교한 후 교체
	}
}

int main(void)//메인함수
{
	int i; //int 자료형의 i선언
	n = MAX_SIZE; //n은 MAX_SIZE
	srand(time(NULL)); //난수 형성
	for (i = 0; i < n; i++) //n번 반복, 즉 100회
		list[i] = rand() % 100; //난수의 범위는 0~99

	bubble_sort(list, n);//버블정렬
	for (i = 0; i < n; i++)printf("%d ", list[i]);//버블정렬후 출력
	printf("\n");//행 바꿈
	return 0;//0반환
}