#include <stdio.h>

typedef struct Node_ {
	int key;
	struct Node_* left;
	struct Node_* right;
	struct Node_* parent;
}Node;

int distance_bst(Node* x) {
	int count = 0;

	if (x->left != NULL) {
		count += distance_bst(x->left);
		if (!(x->key > x->left->key)) {
			count++;
		}
	}

	if (x->right != NULL) {
		count += distance_bst(x->right);
		if (!(x->key < x->right->key)) {
			count++;
		}
	}

	return count;
}
