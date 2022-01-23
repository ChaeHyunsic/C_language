#include <stdio.h>

void find_minmax(int A[], int p, int r, int *max, int *min);
void larger_smaller(int a, int b, int *max, int *min);
int main(void) {
	int A[8] = { 8, 12, 6, 4, 30, 3, 9, 55 };
	int max, min;
	find_minmax(A, 0, 7, &max, &min);
	printf("%d %d", max, min);

	return 0;
}
void find_minmax(int A[], int p, int r, int *max, int *min) {
	int base;
	int n;
	int a, b;
	int i, j;

	n = r - p + 1;

	if (n % 2 == 1) {
		*max = *min = A[0];
		base = 1;
	}
	else {
		larger_smaller(A[0], A[1], max, min);
		base = 2;
	}
	for (i = 0; i < (int)((n - 1) / 2); i++) {
		j = p + 2 * i + base;
		larger_smaller(A[j], A[j + 1], &a, &b);
		if (a > *max)
			*max = a;
		if (b < *min)
			*min = b;
	}
}
void larger_smaller(int a, int b, int *max, int *min) {
	if (a > b) {
		*max = a;
		*min = b;
	}
	else {
		*max = b;
		*min = a;
	}
}