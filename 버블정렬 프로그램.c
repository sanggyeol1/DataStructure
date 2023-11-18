#include <stdio.h> // print �Լ��� ����� �� �ֵ��� �ϴ� ���̺귯��
#include <stdlib.h>// ǥ�� ��ƿ��Ƽ �Լ����� ��Ƴ��� ���̺귯��
#include <time.h> //�������� �޾ƿ��� ���� ���̺귯��
#define _CRT_SECURE_NO_WARNINGS // scanf�� ����ϱ� ���� ���̺귯��

#define MAX_SIZE 10 //MAX_SIZE�� 10

int list[MAX_SIZE]; // int �ڷ����� �迭 list ����(������ 100)
int n; // int �ڷ����� ���� n����


#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t)) // x�� y�� �ٲٴ� SWAP����
void bubble_sort(int list[], int n)//�������� int �ڷ����� int n �� �μ��� ����
{
	int i, j, temp; // int �ڷ����� i, j, temp ����
	for (i = n - 1; i > 0; i--) { // n-1���� 0�������� �ݺ�
		for (j = 0; j < i; j++) // 0���� i-1���� �ݺ�
			if (list[j] > list[j + 1])SWAP(list[j], list[j + 1], temp);//�յ��� ���ڵ带 ���� �� ��ü
	}
}

int main(void)//�����Լ�
{
	int i; //int �ڷ����� i����
	n = MAX_SIZE; //n�� MAX_SIZE
	srand(time(NULL)); //���� ����
	for (i = 0; i < n; i++) //n�� �ݺ�, �� 100ȸ
		list[i] = rand() % 100; //������ ������ 0~99

	bubble_sort(list, n);//��������
	for (i = 0; i < n; i++)printf("%d ", list[i]);//���������� ���
	printf("\n");//�� �ٲ�
	return 0;//0��ȯ
}