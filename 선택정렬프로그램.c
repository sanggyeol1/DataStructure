#include <stdio.h> // print �Լ��� ����� �� �ֵ��� �ϴ� ���̺귯��
#include <stdlib.h>// ǥ�� ��ƿ��Ƽ �Լ����� ��Ƴ��� ���̺귯��
#include <time.h> //�������� �޾ƿ��� ���� ���̺귯��
#define _CRT_SECURE_NO_WARNINGS // scanf�� ����ϱ� ���� ���̺귯��
#define MAX_SIZE 10 // MAX_SIZE�� 10
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t)) //SWAP�Լ� ����
 
int list[MAX_SIZE]; //int �ڷ����� �迭 list����
int n; // int �ڷ����� n����

void selection_sort(int list[], int n) // list[]�� n�� �μ��� �޴� �������� �Լ�
{
	int i, j, least, temp; //int�ڷ����� i,j,least, temp����
	for (i = 0; i < n - 1; i++) { // i�� ó������ �������ε���-1���� �ݺ�
		least = i; //  �ӽ÷� i�� �ּڰ��� �ε����� ��
		for (j = i + 1; j < n; j++) // i���������� ������ �ݺ�
			if (list[j] < list[least])least = j; // ���� ���� ���� ������ ũ�� j�� �ּڰ��� �ε����� ����
		SWAP(list[i], list[least], temp);//list[i]�� list[least]�ٲ�
	}
}

int main(void) //�����Լ�
{
	int i; //int �ڷ����� i����
	n = MAX_SIZE; // n�� MAX_SIZE�� 10
	srand(time(NULL)); // ��������
	for (i = 0; i < n; i++) //10�� �ݺ�
		list[i] = rand() % 100; //list[i]���� 0~99������ ����

	selection_sort(list, n); //��������
	for (i = 0; i < n; i++)printf("%d ", list[i]); //�������� �� ����Ʈ ���
	printf("\n"); // �� ����
	return 0; //0 ��ȯ
}