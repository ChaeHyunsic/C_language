#include <stdio.h>
#define QUEUE_SIZE 7

typedef struct _Queue {
	int queue[QUEUE_SIZE];
	int head;
	int tail;
}Queue;

void print(Queue *Q);
void enqueue(Queue *Q, int x);
int dequeue(Queue *Q);
int main(void) {
	Queue Q;
	int x;
	int menu;

	Q.head = 0;
	Q.tail = 0;
	while (1) {
		printf("select menu : ");
		scanf("%d", &menu);
		if (menu == 0) {
			printf("enqueue : ");
			scanf("%d", &x);
			enqueue(&Q, x);
			print(&Q);
		}
		else if (menu == 1) {
			printf("dequeue : %d\n", dequeue(&Q));
			print(&Q);
		}
		else
			break;
	}
	return 0;
}
void print(Queue *Q) {
	int tmp_head;

	tmp_head = Q->head;

	while (tmp_head != Q->tail) {
		printf("%d ", Q->queue[tmp_head]);
		if (tmp_head == QUEUE_SIZE - 1)
			tmp_head = 0;
		else
			tmp_head = tmp_head + 1;
	}
	printf("\n");
}
void enqueue(Queue *Q, int x) {
	Q->queue[Q->tail] = x;
	if (Q->tail == QUEUE_SIZE - 1)
		Q->tail = 0;
	else
		Q->tail = Q->tail + 1;
}
int dequeue(Queue *Q) {
	int x;

	x = Q->queue[Q->head];
	if (Q->head == QUEUE_SIZE - 1)
		Q->head = 0;
	else
		Q->head = Q->head + 1;
	return x;
}