#include <stdio.h> // print �Լ��� ����� �� �ֵ��� �ϴ� ���̺귯��
#include <stdlib.h>// ǥ�� ��ƿ��Ƽ �Լ����� ��Ƴ��� ���̺귯��
#define _CRT_SECURE_NO_WARNINGS // scanf�� ����ϱ� ���� ���̺귯��
#define MAX_ELEMENT 200 //MAX_ELEMENT�� 200
typedef struct { //����ü ����
	int key; //int�ڷ����� key����
}element; // ����ü �̸��� element
 
typedef struct { // ����ü ����
	element heap[MAX_ELEMENT]; //element �ڷ����� �迭 heap ����
	int heap_size; //int�ڷ����� heap������ ����
}HeapType; //����ü �̸��� HeapType

HeapType* create() //�� ���� �Լ�
{
	return(HeapType*)malloc(sizeof(HeapType));//�� �����Ҵ�
}

void init(HeapType* h) //�� �ʱ�ȭ �Լ�
{
	h->heap_size = 0; //���� ������� 0
}

//���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
void insert_max_heap(HeapType* h, element item)//�� ��һ��� �Լ�
{
	int i; //int �ڷ����� i����
	i = ++(h->heap_size); //���� ������ �ϳ� �ø��� i�� ����

	//Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while((i!=1)&(item.key>h->heap[i/2].key)){// ���� ����� 1�� �ƴϸ鼭 �������� Ű���� �θ��� Ű������ ũ��
		h->heap[i] = h->heap[i / 2]; // ���� �� ���� �θ��� ����
		i /= 2; // i�� 2�� ����
	}
	h->heap[i] = item; //���ο� ��带 ����
}

//���� �Լ�
element delete_max_heap(HeapType* h) //���� ��� ���� �Լ�
{
	int parent, child; //int �ڷ����� parent, child����
	element item, temp; //element�ڷ����� item��temp����
	item = h->heap[1]; // item�� ��Ʈ ��� ����
	temp = h->heap[(h->heap_size)--];//���� ������ ���� temp�� ����
	parent = 1; //parent�� 1����
	child = 2; // child�� 2����
	while (child <= h->heap_size) { //child�� ���� ������� ������ ��� �ݺ�
		
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)child++; //���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.

		if (temp.key >= h->heap[child].key)break; //���� temp�� Ű������ �ڽĳ���� Ű���� �۰ų� ������ �ݺ� ����
		//�� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];//���� �θ��° �ε����� ���� �ڽĹ�° �ε��� ����
		parent = child; //parent�� child����
		child *= 2; // child�� 2 ����
	}
	h->heap[parent] = temp; // ���� ��ġ�� temp�� ����
	return item; // �����۰� ��ȯ
}

void heap_sort(element a[], int n)
{
	int i; // int�ڷ����� ����i����
	HeapType* h; // ��Ÿ�� ����ü h����
	h = create(); // �� ���� 
	init(h); //�� �ʱ�ȭ
	for (i = 0; i < n; i++)insert_max_heap(h, a[i]); // n���ݺ��ϸ� ���� ��� ����
	for (i = (n - 1); i >= 0; i--)a[i] = delete_max_heap(h); //������ ������ ��Ҹ� �迭�� ����
	free(h);//�� �޸� ����
}

#define SIZE 8 //SIZE �� 8
int main(void) //�����Լ�
{
	element list[SIZE] = { 23, 56, 11, 9, 56, 99, 27, 34 };//element �ڷ����� �迭 list����
	heap_sort(list, SIZE); // heap
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");
	return 0;
}