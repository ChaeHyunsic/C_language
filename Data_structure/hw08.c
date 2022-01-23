#include <stdio.h>
#include <stdlib.h>

int Linear_Probing(int k, int i, int M) {
	return (k + i) % M;
}

int Quadratic_Probing(int k, int i, int M) {
	return (k + i + i * i) % M;
}

int hash_insert(int* T, int M, int key, int select) {
	int i, j;

	i = 0;
	do {
		if (select == 0) {
			j = Linear_Probing(key, i, M);
		}
		else {
			j = Quadratic_Probing(key, i, M);
		}
		if (T[j] == -1) {
			T[j] = key;
			return i;
		}
		else {
			i++;
		}
	} while (i != M);
}

int compare_hash(int M, int* key, int N) {
	int* TL, * TQ;
	int i, count_linear = 0, count_quadratic = 0;

	TL = (int*)malloc(sizeof(int) * M);
	TQ = (int*)malloc(sizeof(int) * M);

	for (i = 0; i < M; i++) {
		TL[i] = -1;
		TQ[i] = -1;
	}

	for (i = 0; i < N; i++) {
		count_linear += hash_insert(TL, M, key[i], 0);
		count_quadratic += hash_insert(TQ, M, key[i], 1);
	}
	return count_linear - count_quadratic;
}
