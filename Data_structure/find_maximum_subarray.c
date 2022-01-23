#include <stdio.h>

void find_maximum_subarray(int A[], int low, int high,
	int *ret_left, int *ret_right, int *ret_sum);
void find_max_crossing_subarray(int A[], int low, int mid, int high,
	int *ret_left, int *ret_right, int *ret_sum);

int main(void){
	int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int left, right, sum;

	find_maximum_subarray(A, 0, 15, &left, &right, &sum);
	printf("%d %d %d\n", left, right, sum);
	return 0;
}
void find_maximum_subarray(int A[], int low, int high, int *ret_left, int *ret_right, int *ret_sum){
	int mid;
	int left_low, left_high, left_sum;
	int right_low, right_high, right_sum;
	int cross_low, cross_high, cross_sum;

	if (high == low){
		*ret_left = low;
		*ret_right = high;
		*ret_sum = A[low];
	}
	else{
		mid = (low + high) / 2;
		find_maximum_subarray(A, low, mid, &left_low, &left_high, &left_sum);
		find_maximum_subarray(A, mid+1, high, &right_low, &right_high, &right_sum);
		find_max_crossing_subarray(A, low, mid, high, &cross_low, &cross_high, &cross_sum);
		if (left_sum >= right_sum && left_sum >= cross_sum){
			*ret_left = left_low;
			*ret_right = left_high;
			*ret_sum = left_sum;
		}
		else if (right_sum >= left_sum && right_sum >= cross_sum){
			*ret_left = right_low;
			*ret_right = right_high;
			*ret_sum = right_sum;
		}
		else{
			*ret_left = cross_low;
			*ret_right = cross_high;
			*ret_sum = cross_sum;
		}
	}
}
void find_max_crossing_subarray(int A[], int low, int mid, int high,
	int *ret_left, int *ret_right, int *ret_sum){
	int left_sum, right_sum, sum;
	int i;

	sum = 0;
	for (i = mid; i >= low; i--){
		sum += A[i];
		if (i == mid || sum > left_sum){
			left_sum = sum;
			*ret_left = i;
		}
	}
	sum = 0;
	for (i = mid+1; i <= high; i++){
		sum += A[i];
		if (i == mid+1 || sum > right_sum){
			right_sum = sum;
			*ret_right = i;
		}
	}
	*ret_sum = left_sum + right_sum;
}