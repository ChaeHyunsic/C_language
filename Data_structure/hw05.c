#include <stdio.h>
#define QUEUE_SIZE 100

typedef struct _Queue {
	int queue[QUEUE_SIZE];
	int head;
	int tail;
}Queue;

void relocate(Queue* Q, int which, int base) {
	int tmp = Q->head - Q->tail;
	int start = Q->head, end = Q->tail;
	int i, j;
	int arr[QUEUE_SIZE];

	if (start > end) {
		for (i = start; i < QUEUE_SIZE; i++) {
			arr[i] = Q->queue[i];
		}
		for (i = 0; i < end; i++) {
			arr[i] = Q->queue[i];
		}
	}
	else {
		for (i = start; i < end; i++) {
			arr[i] = Q->queue[i];
		}
	}

	if (which == 'H') {
		Q->head = base;
		if (base - tmp < 0) {
			Q->tail = base - tmp + QUEUE_SIZE;
		}
		else {
			Q->tail = base - tmp;
		}
		if (Q->head > Q->tail) {
			j = start;
			for (i = Q->head; i < QUEUE_SIZE; i++) {
				Q->queue[i] = arr[j];
				if (j == QUEUE_SIZE - 1) {
					j = 0;
				}
				else
					j++;
			}
			for (i = 0; i < Q->tail; i++) {
				Q->queue[i] = arr[j];
				if (j == QUEUE_SIZE - 1) {
					j = 0;
				}
				else
					j++;
			}
		}
		else {
			j = start;
			for (i = Q->head; i < Q->tail; i++) {
				Q->queue[i] = arr[j];
				if (j == QUEUE_SIZE - 1) {
					j = 0;
				}
				else
					j++;
			}
		}
	}
	if (which == 'T') {
		Q->tail = base;
		if (base + tmp > QUEUE_SIZE) {
			Q->head = base + tmp - QUEUE_SIZE;
		}
		else {
			Q->head = base + tmp;
		}
		if (Q->head > Q->tail) {
			j = start;
			for (i = Q->head; i < QUEUE_SIZE; i++) {
				Q->queue[i] = arr[j];
				if (j == QUEUE_SIZE - 1) {
					j = 0;
				}
				else
					j++;
			}
			for (i = 0; i < Q->tail; i++) {
				Q->queue[i] = arr[j];
				if (j == QUEUE_SIZE - 1) {
					j = 0;
				}
				else
					j++;
			}
		}
		else {
			j = start;
			for (i = Q->head; i < Q->tail; i++) {
				Q->queue[i] = arr[j];
				if (j == QUEUE_SIZE - 1) {
					j = 0;
				}
				else
					j++;
			}
		}
	}
}
