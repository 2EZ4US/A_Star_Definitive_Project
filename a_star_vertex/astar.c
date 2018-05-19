#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long INTEGER;
typedef short int BOOL;

#define TRUE 1
#define FALSE 0

#include "graph.h"
#include "heap.h"

BOOL cmp_func(VERTEX *a, VERTEX *b){
	return a->prioriry_value < b->prioriry_value;
}

void Astar(GRAPH *graph, INTEGER start, INTEGER goal){
	HEAP *pq = HEAP_Create(graph->size, cmp_func);

	(graph->arr[start])->distance = 0;
	(graph->arr[start])->prioriry_value = 0;

	HEAP_Enqueue(pq, graph->arr[start]);

	while(!HEAP_Is_Empty(pq)){
		VERTEX *u, *v;	EDGE *e;

		u = HEAP_Dequeue(pq);
		if(u->index == goal) return;

		e = u->head;
		while(e != NULL){
			v = graph->arr[e->v];

			INTEGER dijkstra_cost = u->distance + e->weight;
			INTEGER astar_cost = dijkstra_cost + v->heurisic;

			if(dijkstra_cost < v->distance){
				v->distance = dijkstra_cost;
				v->prioriry_value = astar_cost;
				v->predecessor = u->index;
				
				if(v->in_queue) HEAP_Adjust(pq, v);
				else HEAP_Enqueue(pq, v);
			}

			e = e->next;
		}
	}
}

void main(void){

	INTEGER t, n, m, i, u, v, weight;
	scanf("%lld %lld %lld", &t, &n, &m);
	GRAPH *graph = GRAPH_Create(n);

	if(t == 1){
		INTEGER heurisic;
		for(i = 0; i < n; ++i){
			scanf("%lld %lld", &u, &heurisic);
			GRAPH_Insert_Heuristic(graph, u - 1, heurisic);
		}
	}

	for(i = 0; i < m; ++i){
		scanf("%lld %lld %lld", &u, &v, &weight);
		GRAPH_Insert_Edge(graph, u-1, v-1, weight);
		GRAPH_Insert_Edge(graph, v-1, u-1, weight);
	}

	Astar(graph, 0, n-1);

	printf("%lld\n", (graph->arr[n-1])->distance);

	return;
}