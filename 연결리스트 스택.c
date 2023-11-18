#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;