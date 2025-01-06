#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	int size;
	struct Node* next;
}queue;

queue *front = NULL;
queue * back = NULL;

void ErrorPrint() {
	printf("-1\n");
}

void Push(int data) {
	queue *node = malloc(sizeof(queue));

	node->data = data;
	node->next = NULL;

	if (front == NULL) { //빈 큐
		front = node;
		back = node;
		back->size = 1;
		return;
	}
	else { 
		back->next = node;
		node->size = ++back->size;
		back = node;
		return;
	}
}

void Pop() {
	if (front == NULL) {
		ErrorPrint();
	}
	else {
		printf("%d\n", front->data);
		back->size--;

		if (back->size > 0) {
			queue* temp = front->next;
			free(front);
			front = temp;
		}
		else {
			free(front);
			back = NULL;
			front = NULL;
		}
		
	}
	return;
}


int main() {

	int N;
	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++) {
		char cmd[10];
		scanf("%s", &cmd);
		getchar();

		if (strcmp("push", cmd) == 0) {
			int data;
			scanf("%d", &data);
			getchar();
			Push(data);
		}
		else if (strcmp("pop", cmd) == 0) {
			Pop();
		}
		else if (strcmp("size", cmd) == 0) {
			if (back != NULL) {
				printf("%d\n", back->size);
			}
			else {
				printf("0\n");
			}
		}
		else if (strcmp("empty", cmd) == 0) {
			if (front == NULL) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (strcmp("front", cmd) == 0) {
			if (front != NULL) {
				printf("%d\n",front->data);
			}
			else {
				ErrorPrint();
			}

		}
		else if (strcmp("back", cmd) == 0) {
			if (back == NULL) {
				ErrorPrint();
			}
			else {
				printf("%d\n", back->data);
			}
		}
		
	}

	return 0;
}