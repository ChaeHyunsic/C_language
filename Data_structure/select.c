#include <stdio.h>
#include <stdlib.h>
#define N 5

int select(int A[], int p, int r, int n);
void set_pivot(int A[], int p, int r, int x);
int partition(int A[], int p, int r);
int get_median(int A[], int p, int r);
void swap(int *a, int *b);
void insertion_sort(int A[], int p, int r);
int main(void) {
	int A[9] = { 8, 1, 6, 4, 0, 3, 9, 5, 2};
	int B[9];
	int i, j;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) B[j] = A[j];
		printf("%d\n", select(B, 0, 8, i));
	}

	return 0;
}
int select(int A[], int p, int r, int n) {
	int *median;
	int n_group;
	int tmp_p, tmp_r;
	int x, k;
	int i;

	if (p == r)
		return A[p];
	n_group = r - p + 1;
	n_group = n_group % N == 0 ? n_group / N : n_group / N + 1;
	median = (int*)malloc(sizeof(int)*n_group);

	for (i = 0; i < n_group; i++) {
		tmp_p = p + i*N;
		tmp_r = tmp_p + N - 1;
		tmp_r = tmp_r <= r ? tmp_r : r;
		insertion_sort(A, tmp_p, tmp_r);
		median[i] = get_median(A, tmp_p, tmp_r);
	}
	x = select(median, 0, n_group - 1, (n_group - 1) / 2);
	free(median);
	set_pivot(A, p, r, x);
	k = partition(A, p, r);
	
	if (n == k)
		return x;
	else if (n < k)
		return select(A, p, k - 1, n);
	else
		return select(A, k + 1, r, n);
}
void set_pivot(int A[], int p, int r, int x) {
	int i;

	for (i = p; i <= r; i++)
		if (A[i] == x)break;
	swap(&A[i], &A[r]);
}
int partition(int A[], int p, int r) {
	int x;
	int i, j;

	x = A[r];
	i = p - 1;
	for (j = p; j <= r - 1; j++) {
		if (A[j] <= x) {
			i = i + 1;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i + 1], &A[r]);

	return i + 1;
}
int get_median(int A[], int p, int r) {
	return A[(p + r) / 2];
}
void swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void insertion_sort(int A[], int p, int r) {
	int i, j;
	int key;

	for (j = p+1; j <= r; j++) {
		key = A[j];
		i = j - 1;
		while (i > p-1 && A[i] > key) {
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}
}