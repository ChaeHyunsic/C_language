#include <stdio.h>
#include <stdlib.h>

int partition(int A[], int p, int r);
int randomized_partition(int A[], int p, int r);
int randomized_select(int A[], int p, int r, int i);
void swap(int *a, int *b);
int random(int a, int b);
int main(void) {
	int A[8] = { 8, 1, 6, 4, 0, 3, 9, 5 };
	int i;

	for (i = 0; i < 8; i++) {
		printf("%d\n", randomized_select(A, 0, 7, i));
	}

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
int randomized_partition(int A[], int p, int r) {
	int i;

	i = random(p, r);
	swap(&A[r], &A[i]);

	return partition(A, p, r);
}
int randomized_select(int A[], int p, int r, int i){
	int q;
	int k;

	if (p == r)
		return A[p];
	q = randomized_partition(A, p, r);
	k = q - p;
	if (i == k)
		return A[q];
	else if (i < k)
		return randomized_select(A, p, q - 1, i);
	else
		return randomized_select(A, q + 1, r, i - k - 1);
}
void swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
int random(int a, int b) {
	return (rand() % (b - a + 1)) + a;
}