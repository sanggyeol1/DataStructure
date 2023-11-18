#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENT 200
typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create()
{
	return(HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
	h->heap_size += 1;
	while ((h->heap_size != 1) && (item.key > h->heap[h->heap_size / 2].key)) {
		h->heap[h->heap_size] = h->heap[h->heap_size / 2];
		h->heap_size /= 2;
	}
	h->heap[h->heap_size] = item;
}

element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
}