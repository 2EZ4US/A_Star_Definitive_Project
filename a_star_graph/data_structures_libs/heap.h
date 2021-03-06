#ifndef _HEAP
#define _HEAP

typedef struct HEAP HEAP;

HEAP *HEAP_Create(Integer size, void *(*cmp_func)());

Bool HEAP_Is_Empty(HEAP *heap);

Integer HEAP_Get_Parent(Integer child);

Integer HEAP_Get_Left(Integer parent);

Integer HEAP_Get_Right(Integer parent);

Bool HEAP_Comparison(HEAP *heap, Integer i, Integer j);

void HEAP_Swap(HEAP *heap, Integer i, Integer j);

void HEAP_Enqueue(HEAP *heap, VERTEX *element);

void HEAP_Adjust(HEAP *heap, VERTEX *element);

void HEAP_Heapify(HEAP *heap, Integer index);

VERTEX *HEAP_Dequeue(HEAP *heap);

void HEAP_Destroy(HEAP *heap);

#include "heap.c"

#endif
