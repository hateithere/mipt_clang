#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node {
	Data val;            // данные в узле
	struct Node * left;  // левый ребенок
	struct Node * right; // правый ребенок
};

struct Node * tree_add (struct Node * tree, Data x) {	
	if (tree == NULL) {
		struct Node * data = malloc(sizeof(struct Node));
		data->left = NULL; data->right = NULL;
		data->val = x;
		//printf("Init tree - %d[%p]\n", data->val, data);
		return data;
	}

	if (x < tree->val) {
		if (tree->left == NULL) {
			struct Node * data = malloc(sizeof(struct Node));
			data->left = NULL; data->right = NULL;
			data->val = x;
			tree->left = data;
			//printf("Added - %d [%p] to node %d[%p] left[%p], right[%p]\n", x, data, tree->val, tree, tree->left, tree->right );
		}
		else {
			tree_add(tree->left, x);
		}
	}
	if (x > tree->val) {
		if (tree->right == NULL) {
			struct Node * data = malloc(sizeof(struct Node));
			data->left = NULL; data->right = NULL;
			data->val = x;
			tree->right = data;
			//printf("Added - %d [%p] to node %d[%p] left[%p], right[%p]\n", x, data, tree->val ,tree, tree->left, tree->right );
		}
		else {
			tree_add(tree->right, x);
		}
	}
	return tree;
	
}

void tree_print (struct Node * tree) {
	if (tree != NULL) {
		tree_print(tree->left);
		printf("%d ", tree->val);
		tree_print(tree->right);
	}
}

void tree_add_leafs (struct Node * tree, struct Node * * res) {
	if (tree != NULL) {
		tree_add_leafs(tree->left, res);
		if (tree->left == NULL && tree->right == NULL) {
			*res = tree_add(*res, tree->val);
		}
		tree_add_leafs(tree->right, res);
	}
}

void tree_destroy (struct Node * tree) {
	if (tree != NULL) {
		if (tree->left != NULL) {
			tree_destroy(tree->left);
		}
		if(tree->right != NULL) {
			tree_destroy(tree->right);
		}
		free(tree);
	}
}

int main() {
	int i;
	struct Node * tree = NULL;
	struct Node * res = NULL;
	scanf("%d", &i);
	while (i) {
		tree = tree_add(tree, i);
		scanf("%d", &i);	
	}

	tree_add_leafs(tree, &res);
	
	tree_print(res);
	tree_destroy(tree);	
	tree_destroy(res);
}
