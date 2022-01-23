#include <stdio.h>
#include <stdlib.h>

int parent(int i) {
	return (int)((i - 1) / 2);
}
int left(int i) {
	return 2 * i + 1;
}
int right(int i) {
	return 2 * i + 2;
}

void max_heap_append(int A[], int p, int q) {
	int tmp;

	while (p <= q) {
		if (p > 0 && A[parent(p)] < A[p]) {
			tmp = A[parent(p)];
			A[parent(p)] = A[p];
			A[p] = tmp;
			max_heap_append(A, parent(p), q);
		}
		p++;
	}
}

void max_heapify(int A[], int i, int n) {
	int l, r;
	int largest;
	int tmp;

	l = left(i);
	r = right(i);

	if (l <= n && A[l] > A[i])
		largest = l;
	else
		largest = i;

	if (r <= n && A[r] > A[largest])
		largest = r;

	if (largest != i) {
		tmp = A[i];
		A[i] = A[largest];
		A[largest] = tmp;
		max_heapify(A, largest, n);
	}
}

void build_max_heap(int A[], int n) {
	int i;

	for (i = parent(n); i >= 0; i--)
		max_heapify(A, i, n);
}