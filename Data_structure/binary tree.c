#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int key;
	struct _Node *left;
	struct _Node *right;
}Node;

void node_insert(Node **node, Node **free, int key);
void node_delete(Node **node, Node **free, int key);
void node_print(Node *node);
void free_print(Node *free);
int main(void) {
	Node *root;
	Node *free;
	int x[12] = { 3, -3, 3, 1, 5, 2, -2, -1, 7, 8, -3, 4 };
	int i;

	root = NULL;
	free = NULL;

	for (i = 0; i < 12; i++) {
		if (x[i] > 0) node_insert(&root, &free, x[i]);
		else if (x[i] < 0) node_delete(&root, &free, x[i] * (-1));
		printf("node : ");
		node_print(root);
		printf("\n");
		printf("free : ");
		free_print(free);
		printf("\n\n");
	}
	return 0;
}
void node_insert(Node **node, Node **free, int key) {
	Node *x = *node;
	Node *tmp;

	if (*free == NULL)
		tmp = (Node*)malloc(sizeof(Node));
	else {
		tmp = *free;
		*free = (*free)->right;
	}
	tmp->key = key;
	tmp->left = NULL;
	tmp->right = NULL;

	if (x == NULL) *node = tmp;
	else {
		while (1) {
			if (x->key > key) {
				if (x->left == NULL) {
					x->left = tmp;
					break;
				}
				else x = x->left;
			}
			else {
				if (x->right == NULL) {
					x->right = tmp;
					break;
				}
				else x = x->right;
			}
		}
	}
}
void node_delete(Node **node, Node **free, int key) {
	Node *x = *node;
	Node *tmp;

	if (x->key == key) {
		if (x->left != NULL) {
			tmp = x->left;
			while (tmp->right != NULL) tmp = tmp->right;
			tmp->right = x->right;
			*node = x->left;
		}
		else if (x->right != NULL) {
			tmp = x->right;
			while (tmp->left != NULL) tmp = tmp->left;
			tmp->left = x->left;
			*node = x->right;
		}
		else {
			*node = NULL;
		}
		tmp = x;
	}
	else {
		while (1) {
			if (x->key > key) {
				if (x->left->key != key) x = x->left;
				else {
					if (x->left->left != NULL) {
						tmp = x->left->left;
						while (tmp->right != NULL) tmp = tmp->right;
						tmp->right = x->left->right;

						tmp = x->left;
						x->left = x->left->left;
					}
					else if (x->left->right != NULL) {
						tmp = x->left->right;
						while (tmp->left != NULL)tmp = tmp->left;
						tmp->left = x->left->left;

						tmp = x->left;
						x->left = x->left->right;
					}
					else {
						tmp = x->left;
						x->left = NULL;
					}
					break;
				}
			}
			else if (x->key < key) {
				if (x->right->key != key) x = x->right;
				else {
					if (x->right->left != NULL) {
						tmp = x->right->left;
						while (tmp->right != NULL) tmp = tmp->right;
						tmp->right = x->right->right;

						tmp = x->right;
						x->right = x->right->left;
					}
					else if (x->right->right != NULL) {
						tmp = x->right->right;
						while (tmp->left != NULL)tmp = tmp->left;
						tmp->left = x->right->left;

						tmp = x->right;
						x->right = x->right->right;
					}
					else {
						tmp = x->right;
						x->right = NULL;
					}
					break;
				}
			}
		}
	}
	tmp->right = *free;
	*free = tmp;
}
void node_print(Node *node) {
	if (node != NULL) {
		node_print(node->left);
		printf("%d ", node->key);
		node_print(node->right);
	}
}
void free_print(Node *free) {
	if (free != NULL) {
		printf("%d ", free->key);
		free_print(free->right);
	}
}