#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int A[], int n);
int main(void) {
	int A[9] = { 5, 2, 4, 7, 1, 3, 2, 6, 9 };
	int i;

	for (i = 0; i < 9; i++) printf("%d ", A[i]);
	printf("\n");

	insertion_sort(A, 9);

	for (i = 0; i < 9; i++) printf("%d ", A[i]);
	printf("\n");

	return 0;
}
void insertion_sort(int A[], int n) {
	int i, j;
	int key;

	for (j = 1; j < n; j++) {
		key = A[j];
		i = j - 1;
		while (i > -1 && A[i] > key) {
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}
}