#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int A[], int p, int r) {
	int i, j;
	int key;

	for (j = p; j <= r; j++) {
		key = A[j];
		i = j - 1;
		while (i > -1 && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

int partition(int A[], int p, int r) {
	int x;
	int i, j;
	int tmp;

	x = A[r];
	i = p - 1;
	for (j = p; j <= r - 1; j++) {
		if (A[j] <= x) {
			i++;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	tmp = A[r];
	A[r] = A[i + 1];
	A[i + 1] = tmp;

	return i + 1;
}

int hybridsort(int A[], int p, int r, int t) {
	int q;
	int left, right;

	if (r - p < t) {
		insertion_sort(A, p, r);
		return 1;
	}
	else {
		q = partition(A, p, r);
		left = hybridsort(A, p, q - 1, t);
		right = hybridsort(A, q + 1, r, t);
		return left + right;
	}
}