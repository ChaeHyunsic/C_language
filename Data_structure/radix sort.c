#include <stdio.h>
#include <stdlib.h>

void radix_sort(int A[], int n, int d);
void digit_based_counting_sort(int A[], int B[], int n, int digit);
int get_digit(int n, int d);
int main(void) {
	int A[7] = { 329, 457, 657, 839, 436, 720, 355 };
	int i;

	for (i = 0; i < 7; i++) printf("%d ", A[i]);
	printf("\n");

	radix_sort(A, 7, 3);

	for (i = 0; i < 7; i++) printf("%d ", A[i]);
	printf("\n");

	return 0;
}
void radix_sort(int A[], int n, int d) {
	int *B;
	int i, j;

	B = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < d; i++) {
		digit_based_counting_sort(A, B, n, i);
		for (j = 0; j < n; j++)
			A[j] = B[j];
	}
	free(B);
}
void digit_based_counting_sort(int A[], int B[], int n, int digit) {
	int C[10];
	int tmp;
	int i;

	for (i = 0; i < 10; i++)
		C[i] = 0;
	for (i = 0; i < n; i++) {
		tmp = get_digit(A[i], digit);
		C[tmp] = C[tmp] + 1;
	}

	for (i = 1; i < 10; i++)
		C[i] = C[i] + C[i - 1];

	for (i = n - 1; i >= 0; i--) {
		tmp = get_digit(A[i], digit);
		B[C[tmp] - 1] = A[i];
		C[tmp] = C[tmp] - 1;
	}
}
int get_digit(int n, int d) {
	int i;
	for (i = 0; i < d; i++)
		n /= 10;
	return n % 10;
}