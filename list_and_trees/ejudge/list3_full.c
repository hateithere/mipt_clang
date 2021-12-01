#include <stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node {
	struct Node * next;
	struct Node * prev;
	Data data;
};


void list_init(struct Node * list);
void list_insert(struct Node * list, struct Node * t);
void list_insert_before(struct Node * list, struct Node * t);
void list_remove(struct Node * t);
struct Node * list_push_front(struct Node * list, Data d);
struct Node * list_push_back(struct Node * list, Data d);
Data list_pop_front(struct Node * list);
Data list_pop_back(struct Node * list);
Data list_delete(struct Node * t);
void list_print (struct Node * list);
Data list_sum (struct Node * list);
int list_is_empty(struct Node * list);
int list_clear(struct Node * list);
void list_for_each(struct Node * list, void (*func)(Data d, void * param), void * param);
void print_it(Data d, void * parameter);
void sum(Data a, void * s);

void list_init(struct Node * list) {
	list->next = list;
	list->prev = list;
	list->data = 113;
}

/*void list_print (struct Node * list) {
	if (list != list->next) {
		list_for_each(list, print_it, stdout);
		printf("\n");
	}
	else {
		printf("Empty list\n");
	}
}*/
void list_print (struct Node * list) {
	struct Node *ptr = list->next;
	if (ptr == list) {
		printf("Empty list\n");
	}
	else {
		while (ptr->next != list) {
			printf("%d ", ptr->data);
			//printf("%d [%p](prev is %p, next is %p)\n", ptr->data, ptr, ptr->prev, ptr->next);
			ptr = ptr->next;
		}
		printf("%d\n", ptr->data);
		//printf("%d [%p](prev is %p, next is %p)\n", ptr->data, ptr, ptr->prev, ptr->next);
	}
} 

void list_insert(struct Node * list, struct Node * t) {
	t->next = list->next;
	t->prev = list;
	if (t->next != list) {
		t->next->prev = t;
	}
	else {
		t->next = list;
		list->prev = t;
	}
	list->next = t;
}

void list_insert_before(struct Node * list, struct Node * t) {
	t->next = list;
	t->prev = list->prev;
	if (t->prev != list) {
		t->prev->next = t;
	}
	else {
		t->prev = list;
		list->next = t;
	}
	list->prev = t;
}

void list_remove(struct Node * t) {
	t->prev->next = t->next;
	t->next->prev = t->prev;
}

struct Node * list_push_front(struct Node * list, Data d) {
	struct Node *ptr = list->next;
	struct Node *oth = malloc(sizeof(struct Node));
	oth->data = d;
	oth->next = ptr;
	oth->prev = list;
	list->next = oth;
	ptr->prev = oth;
	return list;
}

struct Node * list_push_back(struct Node * list, Data d) {
	struct Node *ptr = list->prev;
	struct Node *oth = malloc(sizeof(struct Node));
	oth->data = d;
	oth->next = list;
	oth->prev = ptr;
	list->prev = oth;
	ptr->next = oth;
	return list;
}

int list_is_empty(struct Node * list) {
	if (list == list->next) {
		return 1;
	}
	return 0;
}

int list_clear(struct Node * list) {
	struct Node *ptr = list->next;
	
	struct Node *next;
	while (ptr->next != list) {
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
	list->next = list;
	list->prev = list;
	return 0;
}

Data list_pop_front(struct Node * list) {
	struct Node *ptr = list->next;
	Data val = ptr->data;
	list->next = ptr->next;
	ptr->next->prev = list;
	free(ptr);

	return val;
}

Data list_pop_back(struct Node * list) {
	struct Node *ptr = list->prev;
	Data val = ptr->data;
	list->prev = ptr->prev;
	ptr->prev->next = list;
	free(ptr);

	return val;
}

Data list_delete(struct Node * t) {
	if (t == t->next) {
		return 0;
	}
	t->prev->next = t->next;
	t->next->prev = t->prev;
	Data val = t->data;
	free(t);
	return val;
}

void list_for_each(struct Node * list, void (*func)(Data d, void * param), void * param) {
	struct Node *ptr = list->next;
	while (ptr->next != list) {
		func(ptr->data, param);
		ptr = ptr->next;
	}
}

void sum(Data a, void * s) {
	*(Data *)s += a;
}

void print_it(Data d, void * param) {
	FILE * fd = param;
	fprintf(fd, "%d ", d);
}

Data list_sum (struct Node * list) {
	int s = 0;
	list_for_each(list, sum, &s);
	return s;
}

int list_size(struct Node *list) {
	struct Node *ptr = list->next;
	if (ptr == list) {
		return 0;
	}
	int len = 1;

	while (ptr->next != list) {
		ptr = ptr->next;
		++len;
	}
	return len;
}

#define MAX 1000000

int main() {
	int i, k, l;
	struct Node * a = malloc(sizeof(struct Node));
	struct Node * b = malloc(sizeof(struct Node));	
	list_init(a);
	list_init(b);
	int A[5], B[5];

	for (i = 0; i < 5; ++i) {
		scanf("%d", &A[i]);
		list_push_back(a, A[i]);
	}
	
	for (i = 0; i < 5; ++i) {
		scanf("%d", &B[i]);
		list_push_back(b, B[i]);
	}

	for (i = 0; i<MAX; ++i) {
		if (list_size(a) == 0) {
			printf("second %d\n", i);
			while(list_delete(a->next));
			while(list_delete(b->next));
			free(a);
			free(b);
			return 0;
		}
		if (list_size(b) == 0) {
			printf("first %d\n", i);
			while(list_delete(a->next));
			while(list_delete(b->next));
			free(a);
			free(b);
			return 0;
		}
		k = list_pop_front(a);
		l = list_pop_front(b);
		if (k == 10 || l == 0) {
			list_push_back(b, k);
			list_push_back(b, l);		
		}
		else if (k == 0 || l == 10) {
			list_push_back(a, k);
			list_push_back(a, l);
		}
		else if (k > l) {
			list_push_back(a, k);
			list_push_back(a, l);
		}
		else {
			list_push_back(b, k);
			list_push_back(b, l);	
		}
	}
	printf("botva\n");
	while(list_delete(a->next));
	while(list_delete(b->next));
	free(a);
	free(b);
	return 0;
}
