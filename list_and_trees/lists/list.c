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
	if (ptr == NULL) {
		printf("Empty list\n");
	}
	else {
		while (ptr->next != NULL) {
			printf("%d ", ptr->val);
			ptr = ptr->next;
		}
		printf("%d\n", ptr->val);
	}
}

Data list_remove_first (struct List * list) {
	struct Node *ptr = list->head;
	Data val = ptr->val;
	if (ptr->next == NULL) {
		list->head = NULL;
	}
	else {
		list->head = list->head->next;
	}
	free(ptr);
	return val;
} 

Data list_remove_last (struct List * list) {
	struct Node *ptr = list->head;
	Data val;
	if (ptr->next == NULL) {
		list->head = NULL;
		val = ptr->val;
		free(ptr);
	}
	else {
		while (ptr->next->next != NULL) {
			ptr = ptr->next;
		}	

		struct Node* lastNode = ptr->next;
		val = lastNode->val;
		ptr->next = NULL;
		free(lastNode);
	}
	
	return val;
}

Data list_get_first (struct List * list) {
	return list->head->val;
}

Data list_get_last (struct List * list) {
	struct Node *ptr = list->head;	
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	return ptr->val;
}
int list_size(struct List * list) {
	struct Node *ptr = list->head;
	if (ptr == NULL) {
		return 0;
	}
	int len = 1;
	while (ptr->next != NULL) {
		ptr = ptr->next;
		++len;
	}
	return len;
}

void list_clear(struct List * list) {	
	struct Node *ptr = list->head;
	
	if (ptr == NULL) {
		free(ptr);
	}
	else {
		struct Node *next;
		while (ptr->next != NULL) {
			next = ptr->next;
			free(ptr);
			ptr = next;
		}
	}
	list->head = NULL;
}

void list_destroy (struct List * list) {
	list_clear(list);
	free(list);
}
int main() {
	struct List * list = list_create();
	//printf("%d\n", list_size(list));
	list_add_last(list, 5);
	list_add_last(list, 6);
	list_add_first(list, 3);
	list_add_last(list, 8);
	list_add_last(list, 9);
	list_print(list);
	printf("Removed - %d\n", list_remove_first(list));
	list_print(list);
	printf("Removed - %d\n", list_remove_last(list));
	list_print(list);
	printf("%d\n", list_get_first(list));
	printf("%d\n", list_get_last(list));
	printf("%d\n", list_size(list));
	//list_clear(list);
	list_print(list);
	list_destroy(list);
	list_print(list);
	/*list = list_create();
	list_add_first(list, 5);
	list_print(list);
	list_destroy(list);*/
}
