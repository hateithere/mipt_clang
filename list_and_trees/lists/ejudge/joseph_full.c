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
	list->data = -1;
}

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
	
	struct Node *n;
	while (ptr->next != list) {
		n = ptr->next;
		free(ptr);
		ptr = n;
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
		return -1;
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
/*int main() {
struct Node x[10];
	struct Node * a = malloc(sizeof(struct Node));

	int i;
	list_init(a);

	
	for(i=0; i<10; i++) {
		x[i].data = i;
		list_insert(a, &x[i]);
	}
	list_print(a);
	//while(list_delete(a->next));
	list_clear(a);
	free(a);
}*/

int main() {
	int i;
	int N ,M;
	scanf("%d", &N);
	scanf("%d", &M);
	struct Node * a = malloc(sizeof(struct Node));
	struct Node * res = malloc(sizeof(struct Node));
	list_init(a);
	list_init(res);
	
	for(i=1; i<=N; i++) {
		list_push_back(a, i);
	}
	struct Node *ptr = a->next;
	struct Node *next = NULL;
	
	int size = N;
	while (ptr->next != ptr && ptr->prev != ptr) {
		for (i = 0; i < M-1; ++i) {
			if (ptr->next == a) {
				ptr = ptr->next->next;
			}
			else {
				ptr = ptr->next;
			}
		}

		if (size <=  3) {
			list_push_back(res, ptr->data);
		}

		next = ptr->next;
		list_delete(ptr);
	
		if (next == a) {
			ptr = next->next;
		}
		else {
			ptr = next;
		}
		--size;
	}

	list_print(res);

	while(list_delete(a->next) != -1);
	while(list_delete(res->next) != -1);
	free(a); free(res);
}
