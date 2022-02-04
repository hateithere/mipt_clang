#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int T;
typedef struct queue_s {
	T *body, *begin, *end, *body_end;
} queue;

queue* queue_new(size_t size) {
	queue *t = (queue *)malloc(sizeof(queue));
	assert(t != NULL);
	t->body = (int *)malloc(sizeof(T)*size);
	t->begin = t->end = t->body;
	t->body_end = t->body + size;
	return t;
}

void queue_delete(queue *t) {
	free(t->body);
	free(t);
}

void queue_enqueue(queue *t, T el) {
	assert(t->end < t->body_end);
	*t->end++ = el;
}

int queue_empty(queue const *t) {
	return t->begin == t->end;
}

T queue_dequeue(queue *t) {
	return *t->begin++;
}

