#include "tree1.c"

int main() {
	int i;
	struct Node * tree = NULL;
	scanf("%d", &i);
	while (i) {
		tree = tree_add(tree, i);
		scanf("%d", &i);	
	}
	tree_print(tree);
	tree_destroy(tree);	
}
