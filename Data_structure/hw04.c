#include<stdio.h>
#include<stdlib.h>

int partition(int A[], int p, int r) {
	int i, j, x;
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

void hybridsort(int A[], int p, int q, int t) {
	int i, j, key;
	int pivot;

	if (q - p < t) {
		for (j = p; j <= q; j++) {
			key = A[j];
			i = j - 1;
			while (i >= 0 && A[i] > key) {
				A[i + 1] = A[i];
				i = i - 1;
			}
			A[i + 1] = key;
		}
	}
	else {
		pivot = partition(A, p, q);
		hybridsort(A, p, pivot - 1, t);
		hybridsort(A, pivot + 1, q, t);
	}
}

int dynamic_counting_sort(int A[], int B[], int n) {
	int** C, * D;
	int i, j;
	int count = 0, sum = 0;
	int key;

	D = (int*)malloc(sizeof(int));

	for (i = 0; i < n; i++) {
		for (j = 0; j <= count; j++) {
			if (A[i] == D[j]) {
				break;
			}
		}
		if (j == count + 1) {
			D[count] = A[i];
			count++;
			D = realloc(D, (count + 1) * sizeof(int));
		}
	}

	hybridsort(D, 0, count - 1, 3);

	C = (int**)malloc(count * 2 * sizeof(int*));

	for (i = 0; i < count; i++) {
		C[i] = (int*)calloc(2, sizeof(int));
	}

	for (i = 0; i < count; i++) {
		C[i][0] = D[i];
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < count; j++) {
			if (A[i] == C[j][0]) {
				C[j][1]++;
			}
		}
	}

	for (i = 1; i < count; i++) {
		C[i][1] = C[i][1] + C[i - 1][1];
	}

	for (i = n - 1; i >= 0; i--) {
		for (j = 0; j < count; j++) {
			if (A[i] == C[j][0]) {
				B[C[j][1] - 1] = A[i];
				C[j][1]--;
			}
		}
	}

	for (i = 0; i < count; i++) {
		sum += C[i][1];
	}

	free(C);
	free(D);

	return sum;
}
