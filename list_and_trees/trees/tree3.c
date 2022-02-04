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
unsigned int tree_height(struct Node * tree){
	unsigned int l, r;
	if (tree != NULL) {
		l = (tree->left  != NULL) ? tree_height(tree->left) : 0;
		r = (tree->right != NULL) ? tree_height(tree->right): 0;
		return ((l > r) ? l : r) + 1;
	}
	return 0;
}
int main() {
	int i;

	struct Node * tree = NULL;
	scanf("%d", &i);
	while (i) {
		tree = tree_add(tree, i);
		scanf("%d", &i);	
	}

	printf("%d\n", tree_height(tree));
	tree_destroy(tree);
} 
