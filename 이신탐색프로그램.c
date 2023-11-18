#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_ELEMENTS 1000//10000000L
int list[MAX_ELEMENTS];
int count;// ����Ƚ��

// ���� Ž��
int binsearch(int list[], int n, int searchnum)
{
    int left = 0;
    int right = n - 1;
    int middle;
    count = 0;
    while (left <= right) {// ���� ���ڵ��� ���� ������
        count++;
        middle = (left + right) / 2;
        if (searchnum == list[middle]) return middle;
        else if (searchnum < list[middle]) right = middle - 1;
        else left = middle + 1;
    }
    return -1;// �߰ߵ��� ���� 
}

// ���� Ž��
int seqsearch(int list[], int n, int searchnum)
{
    int i;

    count = 0;
    for (i = 0; i < n; i++) {
        count++;
        if (searchnum == list[i]) return i;
    }
    return -1;// �߰ߵ��� ���� 
}


int main()
{
    int i, value = 1;
    int search_number;
    int return_value;
    clock_t start, finish;
    clock_t  duration;
    list[0] = 0;
    for (i = 1; i < MAX_ELEMENTS; i++)
    {
        list[i] = value;
        value = value + 2;
    }
    printf("���ڸ� �Է��Ͻÿ�:");
    scanf("%d", &search_number);

    start = clock();
    return_value = seqsearch(list, MAX_ELEMENTS, search_number);
    finish = clock();
    duration = finish - start;
    printf("%d milliseconds\n", duration);
    printf("����Ž���� ����Ƚ��=%d\n\n ", count);

    start = clock();
    return_value = binsearch(list, MAX_ELEMENTS, search_number);
    finish = clock();
    duration = finish - start;
    printf("%d milliseconds\n", duration);
    printf("����Ž���� ����Ƚ��=%d\n ", count);
    if (return_value == -1) printf("���ڰ� �߰ߵ��� �ʾҽ��ϴ�.\n");
    else printf("���ڰ� ��ġ %d���� �߰ߵǾ����ϴ�.\n", return_value);
}
