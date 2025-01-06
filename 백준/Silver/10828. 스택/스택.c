#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int data;
	int size;
	struct Node* next;
}stack;

stack* top = NULL;

void ErrorPrint() {
	printf("-1\n");
}

void Push(int data) {
	stack* node = malloc(sizeof(stack));
	node->data = data;
	node->next = NULL;

	if (top == NULL) {
		top = node;
		top->size = 1;
		return;
	}
	else {
		node->next = top;
		node->size = top->size + 1;
		top = node;
	}
	return;
}

void Pop() {
	if (top == NULL) {
		ErrorPrint();
	}
	else 
	{
		printf("%d\n", top->data);
		top->size--;

		if (top->size > 0) {
			stack* temp = top->next;
			free(top);
			top = temp;
		}
		else {
			free(top);
			top = NULL;
		}
	}
}

int main() {

	int N;
	
	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++) {
		char cmd[10];
		scanf("%s", &cmd);
		getchar();

		if (strcmp(cmd, "push") == 0) {
			int data;
			scanf("%d", &data);
			getchar();
			Push(data);
		}
		else if (strcmp(cmd, "pop") == 0) {
			Pop();
		}
		else if (strcmp(cmd, "size") == 0) {
			if (top == NULL) {
				printf("0\n");
			}
			else {
				printf("%d\n", top->size);
			}
		}
		else if (strcmp(cmd, "empty") == 0) {
			if (top == NULL) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (strcmp(cmd, "top") == 0) {
			if (top == NULL) {
				ErrorPrint();
			}
			else {
				printf("%d\n", top->data);
			}
		}
	}

	return;
}