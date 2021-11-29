#include <stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node {
	Data val;
	struct Node * next;
};
struct List {
		struct Node * head;
};


struct List * list_create ();
void list_add_first (struct List * list, Data x);
void list_add_last (struct List * list, Data x);
Data list_remove_first (struct List * list); 
Data list_remove_last (struct List * list);
Data list_get_first (struct List * list);
Data list_get_last (struct List * list);
void list_print (struct List * list);
int list_size(struct List * list);
void list_clear(struct List * list);
void list_destroy (struct List * list);

struct List * list_create () {
	struct List *list = malloc(sizeof(struct List));
	list->head = NULL;
	return list;
}

void list_add_last (struct List * list, Data x) {
	struct Node *ptr = list->head;
	if (ptr == NULL) {
		struct Node *oth = malloc(sizeof(struct Node));
		oth->val = x;
		oth->next = NULL;
		list->head = oth;
	}
	else {
		while (ptr->next != NULL) {
			ptr = ptr->next; 
		}
		struct Node *oth = malloc(sizeof(struct Node));
		oth->val = x;
		oth->next = NULL;
		ptr->next = oth;	
	}
}

void list_add_first (struct List * list, Data x) {
	struct Node *ptr = list->head;
	if (ptr == NULL) {
		struct Node *oth = malloc(sizeof(struct Node));
		oth->val = x;
		oth->next = NULL;
		list->head = oth;
	}
	else {
		struct Node *oth = malloc(sizeof(struct Node));
		oth->val = x;
		oth->next = ptr;
		list->head = oth;	
	}
}

void list_print(struct List * list) {
	struct Node *ptr = list->head;
	while (ptr->next != NULL) {
		printf("%p:%d (next is %p)\n", ptr, ptr->val, ptr->next);
		ptr = ptr->next;
	}
	printf("%p:%d (next is NULL)\n", ptr, ptr->val);
}

Data list_remove_first (struct List * list) {
	struct Node *ptr = list->head;
	Data val = ptr->val;
	list->head = ptr->next;
	free(ptr);
	return val;
} 

int main() {
	struct List * list = list_create();
	list_add_last(list, 5);
	list_add_last(list, 6);
	list_add_first(list, 3);
	list_print(list);
	printf("Removed - %d\n", list_remove_first(list));
	list_print(list);
	//list_destroy(list);
}
