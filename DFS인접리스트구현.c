#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES];

void init(GraphType* g)
{
	int r;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++) {
		g->adj_list[r] = NULL;
	}
}

//정점삽입
void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

//간선삽입
void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}
//인접 행렬로 표현된 그래프에 대한 깊이 탐색 그래프
void dfs_list(GraphType* g, int v) {
	GraphNode* w;
	visited[v] = TRUE;
	printf("정점 %d-> ", v);
	for (w = g->adj_list[v]; w; w = w->link) {
		if (!visited[w->vertex])
			dfs_list(g, w->vertex);
	}
}

int main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)insert_vertex(g, i);

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	printf("깊이 우선 탐색\n");
	dfs_list(g, 0);
	printf("\n");
	free(g);
}





