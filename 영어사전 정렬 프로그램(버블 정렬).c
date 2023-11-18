#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>f
#include <stdlib.h>

#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
#define MAX_WORD_SIZE 50
#define MAX_MEANING_SIZE 500
#define SIZE 5

typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
}element;

element list[SIZE];

int main(void)
{
    int i, j;
    element temp;

    printf("5���� �ܾ�� �ǹ̸� �Է��Ͻÿ�\n");

    for (i = 0; i < SIZE; i++) {
        scanf("%s[^\n]", list[i].word);// ����Ű���� �����ϰ� �޴´�.
        scanf("%s[^\n]", list[i].meaning);// ����Ű���� �����ϰ� �޴´�.
    }

    // ���� ����
    for (i = 0; i < SIZE - 1; ++i) {
        for (j = i + 1; j < SIZE; ++j) {
            if (strcmp(list[i].word, list[j].word) > 0) {
                SWAP(list[i], list[j], temp);
            }
        }
    }

    printf("\n���� �� ������ ����: \n");
    for (i = 0; i < SIZE; i++) {
        printf("%s: %s \n", list[i].word, list[i].meaning);
    }

    return 0;
}
