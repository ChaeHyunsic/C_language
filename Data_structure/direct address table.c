#include <stdio.h>
#include <stdlib.h>

#define M 10

typedef struct _Element {
	int key;
	int value;
}Element;

Element *direct_address_search(Element *T[], int k);
void print_table(Element *T[], int k);
void direct_address_insert(Element *T[], Element *x);
void direct_address_delete(Element *T[], int k);
int main(void) {
	Element *T[M] = { NULL };
	Element E[4] = {{0, 3}, {5, 20}, {2, 10}, {9, 30}};
	int i;

	for (i = 0; i < 4; i++) {
		printf("before insert...\n");
		print_table(T, E[i].key);

		direct_address_insert(T, &E[i]);
		printf("after insert...\n");
		print_table(T, E[i].key);

		printf("before delete...\n");
		print_table(T, E[i].key);

		direct_address_delete(T, E[i].key);
		printf("after delete...\n");
		print_table(T, E[i].key);

		printf("\n");
	}
	return 0;

}
Element *direct_address_search(Element *T[], int k) {
	return T[k];
}
void print_table(Element *T[], int k) {
	Element *tmp;

	tmp = direct_address_search(T, k);
	if (tmp != NULL) printf("key %3d : value %3d\n", k, tmp->value);
	else printf("key %3d : value NULL\n", k);
}
void direct_address_insert(Element *T[], Element *x) {
	T[x->key] = x;
}
void direct_address_delete(Element *T[], int k) {
	T[k] = NULL;
}