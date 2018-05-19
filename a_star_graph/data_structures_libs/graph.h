#ifndef _GRAPH
#define _GRAPH

const INTEGER INF = 1<<30;

typedef struct EDGE EDGE;

typedef struct VERTEX VERTEX;

typedef struct GRAPH GRAPH;

GRAPH *GRAPH_Create(INTEGER size);

void GRAPH_Insert_Heuristic(GRAPH *graph, INTEGER u, INTEGER heurisic);

void GRAPH_Insert_Edge(GRAPH *graph, INTEGER u, INTEGER v, INTEGER weight);

void GRAPH_Destroy(GRAPH *graph);

#include "graph.c"

#endif