#include <stdio.h>

#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable:4996)

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, *right;
}TreeNode;

//순환적인 탐색 함수
TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL)return NULL;
	if (key == node->key)return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, int key)
{
	//트리가 공백이면 새로운 노드를 반환한다.
	if (node == NULL)return new_node(key);

	//그렇지않으면 순환적으로 트리를 내려간다.
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	return node;
}

TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	while (current->left != NULL)
		current = current->left;
	return current;
}
//이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고
//새로운 루트 노드를 반환한다.

TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL) return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);

	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		//세 번째 경우
		TreeNode* temp = min_value_node(root->right);

		//중위순회시 후계 노드를 복사한다.
		root->key = temp->key;
		//중위순회시 후계 노드를 삭제한다.
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

//중위순회
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d]", root->key);
		inorder(root->right);
	}
}

int main(void)
{
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견함\n");
	else
		printf("이진 탐색 트리에서 30을 발견못함\n");
	return 0;
}