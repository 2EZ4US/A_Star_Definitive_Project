#ifndef _GRAPH
#define _GRAPH

const INTEGER INF = 1<<30;

typedef struct EDGE{
	INTEGER v;
	INTEGER weight;

	struct EDGE *next;
}EDGE;

typedef struct VERTEX{
	BOOL in_queue;
	INTEGER pos_in_queue;
	INTEGER distance;
	INTEGER prioriry_value;
	INTEGER heurisic;
	INTEGER index;
	INTEGER predecessor;

	EDGE *head;
	EDGE *tail;
}VERTEX;

typedef struct GRAPH{
	VERTEX **arr;
	INTEGER size;
}GRAPH;

GRAPH *GRAPH_Create(INTEGER size){
	GRAPH *new_GRAPH = (GRAPH *) malloc(sizeof(GRAPH));
	new_GRAPH->arr = (VERTEX **) malloc(size * sizeof(VERTEX *));

	INTEGER i;
	for(i = 0; i < size; ++i){
		new_GRAPH->arr[i] = (VERTEX *) malloc(sizeof(VERTEX));

		(new_GRAPH->arr[i])->in_queue = FALSE;
		(new_GRAPH->arr[i])->pos_in_queue = i;
		(new_GRAPH->arr[i])->distance = INF;
		(new_GRAPH->arr[i])->prioriry_value = INF;
		(new_GRAPH->arr[i])->heurisic = 0;
		(new_GRAPH->arr[i])->index = i;
		(new_GRAPH->arr[i])->predecessor = -1;

		(new_GRAPH->arr[i])->head = NULL;
		(new_GRAPH->arr[i])->tail = NULL;
	}

	new_GRAPH->size = size;

	return new_GRAPH;
}

void GRAPH_Insert_Heuristic(GRAPH *graph, INTEGER u, INTEGER heurisic){
	(graph->arr[u])->heurisic = heurisic;
}

void GRAPH_Insert_Edge(GRAPH *graph, INTEGER u, INTEGER v, INTEGER weight){
	EDGE *new_edge = (EDGE *) malloc(sizeof(EDGE));

	new_edge->v = v;
	new_edge->weight = weight;
	new_edge->next = NULL;

	if((graph->arr[u])->head == NULL && (graph->arr[u])->tail == NULL){
		(graph->arr[u])->head = new_edge;
		(graph->arr[u])->tail = new_edge;
	}
	else{
		(graph->arr[u])->tail->next = new_edge;
		(graph->arr[u])->tail = new_edge;
	}
}

#endif