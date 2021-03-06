#ifndef _GRAPH
#define _GRAPH

const Integer INF = 1<<30;

typedef struct EDGE EDGE;

typedef struct VERTEX VERTEX;

typedef struct GRAPH GRAPH;

Bool EDGE_Is_Empty(EDGE *edge);

GRAPH *GRAPH_Create(Integer size);

void GRAPH_Insert_Heuristic(GRAPH *graph, Integer u, Integer heuristic);

void GRAPH_Insert_Edge(GRAPH *graph, Integer u, Integer v, Integer weight);

void EDGE_Destroy(EDGE *edge);

void GRAPH_Destroy(GRAPH *graph);

#include "graph.c"

#endif
