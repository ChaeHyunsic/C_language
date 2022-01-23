#include <stdio.h>
#include <stdlib.h>

void counting_sort(int A[], int B[], int n, int k);
int main(void) {
	int A[8] = { 2, 5, 3, 0, 2, 3, 0, 3 };
	int B[8];
	int i;

	for (i = 0; i < 8; i++) printf("%d ", A[i]);
	printf("\n");

	counting_sort(A, B, 8, 5);

	for (i = 0; i < 8; i++) printf("%d ", B[i]);
	printf("\n");

	return 0;
}
void counting_sort(int A[], int B[], int n, int k) {
	int *C;
	int i;

	C = (int*)malloc(sizeof(int)*(k + 1));

	for (i = 0; i <= k; i++)
		C[i] = 0;

	for (i = 0; i < n; i++) 
		C[A[i]] = C[A[i]] + 1;

	for (i = 1; i <= k; i++)
		C[i] = C[i] + C[i - 1];

	for (i = n - 1; i >= 0; i--) {
		B[C[A[i]]-1] = A[i];
		C[A[i]] = C[A[i]] - 1;
	}
	free(C);
}