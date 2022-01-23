#include <stdio.h>
#include <stdlib.h>

typedef struct _Element {
	int key;
	struct _Element *prev;
	struct _Element *next;
}Element;

void list_print(Element *L);
Element *list_search(Element *L, int k);
void list_insert(Element *L, int k);
void list_delete(Element *L, int k);
int main(void) {
	Element L;
	int x;
	int menu;

	L.prev = &L;
	L.next = &L;

	while (1) {
		printf("select menu : ");
		scanf("%d", &menu);
		if (menu == 0) {
			printf("insert : ");
			scanf("%d", &x);
			list_insert(&L, x);
			list_print(&L);
		}
		else if (menu == 1) {
			printf("delete : ");
			scanf("%d", &x);
			list_delete(&L, x);
			list_print(&L);
		}
		else
			break;
	}
	return 0;
}
void list_print(Element *L) {
	Element *x;

	x = L->next;
	while (x != L) {
		printf("%d ", x->key);
		x = x->next;
	}
	printf("\n");
}
Element *list_search(Element *L, int k) {
	Element *x;

	x = L->next;
	while (x != L && x->key != k)
		x = x->next;
	return x;
}
void list_insert(Element *L, int k) {
	Element *x;

	x = (Element*)malloc(sizeof(Element));
	x->key = k;

	x->next = L->next;
	L->next->prev = x;
	L->next = x;
	x->prev = L;
}
void list_delete(Element *L, int k) {
	Element *x;

	x = list_search(L, k);
	if (x != NULL) {
		x->prev->next = x->next;
		x->next->prev = x->prev;
		free(x);
	}
}