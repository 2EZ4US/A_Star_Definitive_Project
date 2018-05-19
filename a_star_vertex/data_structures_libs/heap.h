#ifndef _HEAP
#define _HEAP

typedef struct HEAP HEAP;

HEAP *HEAP_Create(INTEGER size, void *(*cmp_func)());

BOOL HEAP_Is_Empty(HEAP *heap);

INTEGER HEAP_Get_Parent(INTEGER child);

INTEGER HEAP_Get_Left(INTEGER parent);

INTEGER HEAP_Get_Right(INTEGER parent);

BOOL HEAP_Comparison(HEAP *heap, INTEGER i, INTEGER j);

void HEAP_Swap(HEAP *heap, INTEGER i, INTEGER j);

void HEAP_Enqueue(HEAP *heap, VERTEX *element);

void HEAP_Adjust(HEAP *heap, VERTEX *element);

void HEAP_Heapify(HEAP *heap, INTEGER index);

VERTEX *HEAP_Dequeue(HEAP *heap);

#include "heap.c"

#endif
