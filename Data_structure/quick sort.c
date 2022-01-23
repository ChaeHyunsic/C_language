#include <stdio.h>

int partition(int A[], int p, int r);
void quicksort(int A[], int p, int r);
void swap(int *a, int *b);
int main(void) {
	int A[8] = { 8, 1, 6, 4, 0, 3, 9, 5 };
	int i;

	for (i = 0; i < 8; i++) printf("%d ", A[i]);
	printf("\n");

	quicksort(A, 0, 7);

	for (i = 0; i < 8; i++) printf("%d ", A[i]);
	printf("\n");

	return 0;
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
void quicksort(int A[], int p, int r){
	int q;

	if (p < r) {
		q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}
void swap(int *a, int *b){
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}