#include <stdio.h> // print �Լ��� ����� �� �ֵ��� �ϴ� ���̺귯��
#include <stdlib.h>// ǥ�� ��ƿ��Ƽ �Լ����� ��Ƴ��� ���̺귯��
#include <time.h> //�������� �޾ƿ��� ���� ���̺귯��
#define _CRT_SECURE_NO_WARNINGS // scanf�� ����ϱ� ���� ���̺귯��
#define MAX_SIZE 10 //MAX_SIZE�� 10 ����
int list[MAX_SIZE]; // int �ڷ����� �迭 list ����
int n; //int�ڷ����� n����


void insertion_sort(int list[], int n)//�迭list�� n�� �μ��� �޴� ��������
{
	int i, j, key; // int �ڷ����� i,j,key ����
	for (i = 1; i < n; i++) { // �ι�°���� ������ �ݺ�
		key = list[i]; //list[i]�� Ű��
		for (j = i - 1; j >= 0 && list[j] > key; j--)//Ű�� ���������� ������ �ݺ�, key���� �������� ������ stop
			list[j + 1] = list[j]; //���ڵ带 ����������  ��
		list[j + 1] = key;	//key�� ����
	}
}

int main(void)//�����Լ�
{
	int i; //int �ڷ����� i���� 
	n = MAX_SIZE; //n�� MAX_SIZE��, 10
	srand(time(NULL)); // ���� ����
	for (i = 0; i < n; i++) //10�� �ݺ�
		list[i] = rand() % 100; //list[i]�� ������ 0~99

	insertion_sort(list, n); //�������� ����
	for (i = 0; i < n; i++) //10�� �ݺ�
		printf("%d ",list[i]); // list[i]���
	printf("\n"); // �� ����
	return 0; //0��ȯ
}