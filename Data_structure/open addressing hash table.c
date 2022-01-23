#include <stdio.h>
#include <stdlib.h>

#define M 10

#define DELETED -1

int hash_func(int k, int i);
int hash_search(int T[], int k);
void print_table(int T[], int k);
int hash_insert(int T[], int k);
void hash_delete(int T[], int k);
int main(void) {
	int T[M] = { 0 };
	int key[8] = { 3, 1, 5, 10, 2, 100, 7};
	int i;

	for (i = 0; i < 8; i++) {
		printf("before insert...\n");
		print_table(T, key[i]);

		hash_insert(T, key[i]);
		printf("after insert...\n");
		print_table(T, key[i]);

		printf("before delete...\n");
		print_table(T, key[i]);

		hash_delete(T, key[i]);
		printf("after delete...\n");
		print_table(T, key[i]);
		printf("\n");
	}
	return 0;

}
int hash_func(int k, int i) {
	return ((k%M) + i) % M;
}
int hash_search(int T[], int k) {
	int i;
	int j;

	i = 0;
	do {
		j = hash_func(k, i);
		if (T[j] != DELETED && T[j] == k) {
			return j;
		}
		else i = i + 1;
	} while (T[j] != NULL && i != M);
	return NULL;
}
void print_table(int T[], int k) {
	int key = hash_search(T, k);

	if (key != NULL) printf("key %3d\n", k);
	else printf("key NULL\n");
}
int hash_insert(int T[], int k) {
	int i;
	int j;

	i = 0;
	do {
		j = hash_func(k, i);
		if (T[j] == NULL || T[j] == DELETED) {
			T[j] = k;
			return j;
		}
		else i = i + 1;
	} while (i != M);
	return NULL;
}
void hash_delete(int T[], int k) {
	int key = hash_search(T, k);
	T[key] = DELETED;
}