typedef enum color_t {
	WHITE, GREY, BLACK
} color;

// unweighted graph

typedef struct graph_t {
	char *neibs; // [N*N]
	size_t N;
	int unordered;
} graph;

graph *graph_new(size_t nodesm int is_ordered) {
	graph *t = (graph *) malloc(sizeof(graph));
	t->N = nodes;
	t->unoreded = !is_ordered;
	t->neibs = (char *) calloc(sizeof(char), nodes * nodes);
	return t;	
}

void graph_delete(graph *g) {
	free(g->neibs);
	free(g);
}

void graph_add_edge(graph *t, int from, int to) {
	t->neibs[from * t->N + to] = 1;
	if (t->unordered) {
		t->neibs[to * t->N + from] = 1;
	}
}
