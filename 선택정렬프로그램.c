#include <stdio.h> // print 함수를 사용할 수 있도록 하는 라이브러리
#include <stdlib.h>// 표준 유틸리티 함수들을 모아놓은 라이브러리
#include <time.h> //랜덤값을 받아오기 위한 라이브러리
#define _CRT_SECURE_NO_WARNINGS // scanf를 사용하기 위한 라이브러리
#define MAX_SIZE 10 // MAX_SIZE는 10
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t)) //SWAP함수 선언
 
int list[MAX_SIZE]; //int 자료형의 배열 list선언
int n; // int 자료형의 n선언

void selection_sort(int list[], int n) // list[]와 n을 인수로 받는 선택정렬 함수
{
	int i, j, least, temp; //int자료형의 i,j,least, temp선언
	for (i = 0; i < n - 1; i++) { // i가 처음부터 마지막인덱스-1까지 반복
		least = i; //  임시로 i를 최솟값의 인덱스로 둠
		for (j = i + 1; j < n; j++) // i다음값부터 끝까지 반복
			if (list[j] < list[least])least = j; // 앞의 값이 뒤의 값보다 크면 j를 최솟값의 인덱스로 상정
		SWAP(list[i], list[least], temp);//list[i]와 list[least]바꿈
	}
}

int main(void) //메인함수
{
	int i; //int 자료형의 i선언
	n = MAX_SIZE; // n은 MAX_SIZE즉 10
	srand(time(NULL)); // 난수형성
	for (i = 0; i < n; i++) //10번 반복
		list[i] = rand() % 100; //list[i]값은 0~99사이의 난수

	selection_sort(list, n); //선택정렬
	for (i = 0; i < n; i++)printf("%d ", list[i]); //선택정렬 후 리스트 출력
	printf("\n"); // 행 내림
	return 0; //0 반환
}