#include <stdio.h>
#define STACK_SIZE 7

typedef struct _Stack {
	int stack[STACK_SIZE];
	int top;
}Stack;

void print(Stack *S);
void push(Stack *S, int x);
int pop(Stack *S);
int main(void) {
	Stack S;
	int x;
	int menu;

	S.top = -1;
	while (1) {
		printf("select menu : ");
		scanf("%d", &menu);
		if (menu == 0) {
			printf("push : ");
			scanf("%d", &x);
			push(&S, x);
			print(&S);
		}
		else if (menu == 1) {
			printf("pop : %d\n", pop(&S));
			print(&S);
		}
		else
			break;
	}
	return 0;
}
void print(Stack *S) {
	int tmp_top;

	tmp_top = S->top;

	while (tmp_top != -1) {
		printf("%d ", S->stack[tmp_top]);
		tmp_top = tmp_top - 1;
	}
	printf("\n");
}
void push(Stack *S, int x) {
	S->top = S->top + 1;
	S->stack[S->top] = x;
}
int pop(Stack *S) {
	S->top = S->top - 1;
	return S->stack[S->top + 1];
}