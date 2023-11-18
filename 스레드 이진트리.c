#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread; //스레드이면 TRUE
}TreeNode;

//           G
//       C       F
//     A   B   D   E

TreeNode n1 = { 'A',NULL,NULL,1 };//스레드가 있다
TreeNode n2 = { 'B',NULL,NULL,1 };
TreeNode n3 = { 'C',&n1,&n2,0 };
TreeNode n4 = { 'D',NULL,NULL,1 };
TreeNode n5 = { 'E',NULL,NULL,0 }; //마지막이라서 스레드가 없다.
TreeNode n6 = { 'F',&n4,&n5,0 };
TreeNode n7 = { 'G',&n3,&n6,0 };
TreeNode* exp = &n7;

TreeNode* find_successor(TreeNode* p)
{
	TreeNode* q = p->right;

	if (q == NULL || p->is_thread == TRUE)
		return q;

	while (q->left != NULL)q = q->left;
	return q;
}
void thread_inorder(TreeNode* t)
{
	TreeNode* q;

	q = t;
	while (q->left)q = q->left;//가장 왼쪽노드로 간다.
	do {
		printf("%c->", q->data);
		q = find_successor(q);
	} while (q);//NULL이 아니면

}

int main(void)
{
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;

	thread_inorder(exp);
}

