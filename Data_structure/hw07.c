#include <stdio.h>

void insert_node_array(int* next, int* key, int* prev, int n, int* L, int* free, int k) {
	int x, y;

	x = *free;
	y = *L;

	*free = next[x];
	key[x] = k;
	next[x] = *L;
	prev[x] = -1;
	prev[y] = x;
	*L = x;
}

void delete_node_array(int* next, int* key, int* prev, int n, int* L, int* free) {
	int x;

	x = *L;

	*L = next[x];
	prev[next[x]] = -1;
	next[x] = -1;
	key[x] = -1;
	prev[x] = -1;
	*free = x;
}
