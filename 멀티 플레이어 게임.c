#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef char element[100];
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

typedef struct CListType {
	ListNode* head;
}CListType;

