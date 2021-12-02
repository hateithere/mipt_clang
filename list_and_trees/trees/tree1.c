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

void tree_destroy (struct Node * tree) {
	if (tree->left != NULL) {
		tree_destroy(tree->left);
	}
	if(tree->right != NULL) {
		tree_destroy(tree->right);
	}
	free(tree);
}

/*int main() {
	struct Node * tree = NULL;
	tree = tree_add(tree, 7);
	//printf("Tree - [%p]\n", tree);
	tree = tree_add(tree, 3);
	//printf("Tree - [%p]\n", tree);
	tree = tree_add(tree, 2);
	tree = tree_add(tree, 1);
	tree = tree_add(tree, 9);
	tree = tree_add(tree, 5);
	tree = tree_add(tree, 4);
	tree = tree_add(tree, 6);
	tree = tree_add(tree, 8);
	//printf("Tree - [%p]\n", tree);
	tree_print(tree);
	tree_destroy(tree);
} */
