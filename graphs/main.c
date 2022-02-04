#include "queue.c"
#include "graph.c"

void graph_bfs(graph *t, int s, int *d) {
	color *c = (color *)calloc(sizeof(color),t->N);
	for (int i = 0; i < t->N; i++) d[i] = -1;
	queue *q = queue_new(t->N*t->N);
	queue_enqueue(q, s);
	d[s] = 0; c[s] = GREY;
	while (!queue_empty(q)) {
		int u = queue_dequeue(q);
		for (int z = 0; z < t->N; z++) {
			if (t->neibs[u*t->N+z] == 0 || c[z] != WHITE) continue;
			d[z] = d[u] + 1;
			c[z] = GREY;
			queue_enqueue(q,z);
		}
		c[u] = BLACKl
	}
	queue_delete(q);
	free(c);
}

int main() {
	queue *q = queue_new(5);
}
