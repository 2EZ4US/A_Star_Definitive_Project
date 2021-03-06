#include "header.h"

Bool cmp_func(VERTEX *a, VERTEX *b){
	return a->priority_value < b->priority_value;
}

void Astar(GRAPH *graph, VERTEX *start, VERTEX *goal){
	HEAP *priority_queue = HEAP_Create(graph->size, cmp_func);

	start->distance = 0;
	start->priority_value = start->distance + start->heuristic;

	HEAP_Enqueue(priority_queue, start);

	while(!HEAP_Is_Empty(priority_queue)){
		VERTEX *current_vertex, *neighbor_vertex;
		EDGE *current_edge;

		current_vertex = HEAP_Dequeue(priority_queue);
		if(current_vertex == goal){
			HEAP_Destroy(priority_queue);
			return;
		}

		current_edge = current_vertex->head;
		while(!EDGE_Is_Empty(current_edge)){
			neighbor_vertex = graph->arr[current_edge->next_index];

			Integer dijkstra_cost = current_vertex->distance + current_edge->weight;
			Integer astar_cost = dijkstra_cost + current_vertex->heuristic;

			if(dijkstra_cost < neighbor_vertex->distance){
				neighbor_vertex->distance = dijkstra_cost;
				neighbor_vertex->priority_value = astar_cost;
				neighbor_vertex->predecessor = current_vertex->pos_in_graph;
				
				if(neighbor_vertex->in_queue) HEAP_Adjust(priority_queue, neighbor_vertex);
				else HEAP_Enqueue(priority_queue, neighbor_vertex);
			}

			current_edge = current_edge->next;
		}
	}

	HEAP_Destroy(priority_queue);
}

void main(void){
	Integer n, m, i, u, v, weight, heuristic;
	scanf("%lld %lld", &n, &m);
	GRAPH *graph = GRAPH_Create(n);

	for(i = 0; i < n; ++i){
		scanf("%lld", &heuristic);
		GRAPH_Insert_Heuristic(graph, i, heuristic);
	}

	for(i = 0; i < m; ++i){
		scanf("%lld %lld %lld", &u, &v, &weight);
		GRAPH_Insert_Edge(graph, u-1, v-1, weight);
		GRAPH_Insert_Edge(graph, v-1, u-1, weight);
	}

	Astar(graph, graph->arr[0], graph->arr[n-1]);

	printf("%lld\n", (graph->arr[n-1])->distance);

	GRAPH_Destroy(graph);

	return;
}