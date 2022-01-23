#include <stdio.h>
#include <stdlib.h>

#define M 10

typedef struct _Element {
	int key;
	int value;
	struct _Element *next;
	struct _Element *prev;
}Element;

int hash_func(int k);
Element *chained_hash_search(Element *T[], int k);
void print_table(Element *T[], int k);
void chained_hash_insert(Element *T[], Element *x);
void chained_hash_delete(Element *T[], int k);
int main(void) {
	Element *T[M] = { NULL };
	Element E[4] = { { 0, 3, NULL, NULL },{ 5, 20,NULL, NULL },{ 10, 10,NULL, NULL },{ 20, 30,NULL, NULL } };
	int i;

	for (i = 0; i < 4; i++) {
		printf("before insert...\n");
		print_table(T, E[i].key);

		chained_hash_insert(T, &E[i]);
		printf("after insert...\n");
		print_table(T, E[i].key);

		printf("before delete...\n");
		print_table(T, E[i].key);

		chained_hash_delete(T, E[i].key);
		printf("after delete...\n");
		print_table(T, E[i].key);

		printf("\n");
	}
	return 0;

}
int hash_func(int k) {
	return k%M;
}
Element *chained_hash_search(Element *T[], int k) {
	int key = hash_func(k);
	Element *tmp = T[key];

	while (tmp != NULL) {
		if (tmp->key == k) return tmp;
		else tmp = tmp->next;
	}
	return tmp;
}
void print_table(Element *T[], int k) {
	Element *tmp;

	tmp = chained_hash_search(T, k);
	if (tmp != NULL) printf("key %3d : value %3d\n", k, tmp->value);
	else printf("key %3d : value NULL\n", k);
}
void chained_hash_insert(Element *T[], Element *x) {
	int key = hash_func(x->key);
	
	if (T[key] == NULL) T[key] = x;
	else {
		T[key]->prev = x;
		x->next = T[key];
		T[key] = x;
	}
}
void chained_hash_delete(Element *T[], int k) {
	int key = hash_func(k);
	Element *tmp = T[key];

	while (tmp != NULL) {
		if (tmp->key == k) {
			if (tmp->prev == NULL) T[key] = tmp->next;
			else tmp->prev->next = tmp->next;

			if (tmp->next != NULL) tmp->next->prev = tmp->prev;
			return;
		}
		else tmp = tmp->next;
	}
}