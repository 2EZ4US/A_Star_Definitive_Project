struct EDGE{
	Integer next_index;
	Integer weight;

	struct EDGE *next;
};

struct VERTEX{
	Bool in_queue;
	Integer pos_in_queue;
	Integer distance;
	Integer priority_value;
	Integer heuristic;
	Integer pos_in_graph;
	Integer predecessor;

	EDGE *head;
	EDGE *tail;
};

struct GRAPH{
	VERTEX **arr;
	Integer size;
};

Bool EDGE_Is_Empty(EDGE *edge){
	return (edge == NULL);
}

GRAPH *GRAPH_Create(Integer size){
	GRAPH *new_GRAPH = (GRAPH *) malloc(sizeof(GRAPH));
	new_GRAPH->arr = (VERTEX **) malloc(size * sizeof(VERTEX *));

	Integer i;
	for(i = 0; i < size; ++i){
		new_GRAPH->arr[i] = (VERTEX *) malloc(sizeof(VERTEX));

		(new_GRAPH->arr[i])->in_queue = FALSE;
		(new_GRAPH->arr[i])->pos_in_queue = i;
		(new_GRAPH->arr[i])->distance = INF;
		(new_GRAPH->arr[i])->priority_value = INF;
		(new_GRAPH->arr[i])->heuristic = 0;
		(new_GRAPH->arr[i])->pos_in_graph = i;
		(new_GRAPH->arr[i])->predecessor = -1;

		(new_GRAPH->arr[i])->head = NULL;
		(new_GRAPH->arr[i])->tail = NULL;
	}

	new_GRAPH->size = size;

	return new_GRAPH;
}

void GRAPH_Insert_Heuristic(GRAPH *graph, Integer u, Integer heuristic){
	(graph->arr[u])->heuristic = heuristic;
}

void GRAPH_Insert_Edge(GRAPH *graph, Integer u, Integer v, Integer weight){
	EDGE *new_edge = (EDGE *) malloc(sizeof(EDGE));

	new_edge->next_index = v;
	new_edge->weight = weight;
	new_edge->next = NULL;

	if(EDGE_Is_Empty((graph->arr[u])->head) && EDGE_Is_Empty((graph->arr[u])->head)){
		(graph->arr[u])->head = new_edge;
		(graph->arr[u])->tail = new_edge;
	}
	else{
		(graph->arr[u])->tail->next = new_edge;
		(graph->arr[u])->tail = new_edge;
	}
}

void EDGE_Destroy(EDGE *edge){
	if(EDGE_Is_Empty(edge)) return;

	EDGE_Destroy(edge->next);
	free(edge);
}

void GRAPH_Destroy(GRAPH *graph){
	Integer i;
	for(i = 0; i < graph->size; ++i){
		EDGE_Destroy((graph->arr[i])->head);
		free(graph->arr[i]);
	}

	free(graph->arr);
	free(graph);
}
