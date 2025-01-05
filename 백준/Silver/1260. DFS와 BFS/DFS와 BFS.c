#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int num;
	struct Node* next;
}Node;

Node* TAIL;

int N, M, V;
int array[1001][1001];
int visited[1001];

void dfs(int node) {
	printf("%d ", node);
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1) continue;
		if (array[node][i] == 1) {
			visited[i] = 1;
			dfs(i);
		}
	}
}

void bfs() {
	Node* q = malloc(sizeof(Node));
	q->num = V;
	q->next = NULL;
	TAIL = q;
	visited[V] = 1;

	while (q != NULL) {
		Node* front = q;
		printf("%d ", q->num);

		for (int i = 1; i <= N; i++) {
			if (visited[i] == 1) continue;
			if (array[front->num][i] == 1) {
				Node* temp = malloc(sizeof(Node));
				TAIL->next = temp;
				temp->num = i;
				temp->next = NULL;
				TAIL = temp;
				visited[i] = 1;
			}
		}
		q = q->next;
		free(front);
	}
}

int main() {

	scanf("%d %d %d", &N, &M, &V);
	getchar();

	for (int i = 0; i < M; i++) {

		int from, to;
		scanf("%d %d", &from, &to);
		getchar();
		array[from][to] = 1;
		array[to][from] = 1;
	}

	visited[V] = 1;
	dfs(V);
	printf("\n");
	memset(visited, 0, sizeof(visited));
	bfs();
	
	return 0;
}