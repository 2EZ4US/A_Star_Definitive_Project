struct HEAP{
	VERTEX **arr;
	INTEGER size;

	void *(*cmp_func)();
};

HEAP *HEAP_Create(INTEGER size, void *(*cmp_func)()){
	HEAP *new_heap = (HEAP *) malloc(sizeof(HEAP));

	new_heap->arr = (VERTEX **) malloc((size + 1) * sizeof(VERTEX *));
	new_heap->size = 0;
	new_heap->cmp_func = cmp_func;

	return new_heap;
}

BOOL HEAP_Is_Empty(HEAP *heap){
	return heap->size == 0;
}

INTEGER HEAP_Get_Parent(INTEGER child){
	return child>>1;
}

INTEGER HEAP_Get_Left(INTEGER parent){
	return (parent<<1);
}

INTEGER HEAP_Get_Right(INTEGER parent){
	return (parent<<1) + 1;
}

BOOL HEAP_Comparison(HEAP *heap, INTEGER i, INTEGER j){
	return heap->cmp_func(heap->arr[i], heap->arr[j]);
}

void HEAP_Swap(HEAP *heap, INTEGER i, INTEGER j){
	VERTEX *temp = heap->arr[i];
	heap->arr[i] = heap->arr[j];
	heap->arr[j] = temp;

	(heap->arr[i])->pos_in_queue = i;
	(heap->arr[j])->pos_in_queue = j;
}

void HEAP_Enqueue(HEAP *heap, VERTEX *element){
	heap->arr[++heap->size] = element;
	element->in_queue = TRUE;
	element->pos_in_queue = heap->size;

	INTEGER child = heap->size;
	INTEGER parent = HEAP_Get_Parent(child);

	while(parent >= 1 && HEAP_Comparison(heap, child, parent)){
		HEAP_Swap(heap, child, parent);
		child = parent;
		parent = HEAP_Get_Parent(child);
	}
}

void HEAP_Adjust(HEAP *heap, VERTEX *element){
	INTEGER child = element->pos_in_queue;
	INTEGER parent = HEAP_Get_Parent(child);

	while(parent >= 1 && HEAP_Comparison(heap, child, parent)){
		HEAP_Swap(heap, child, parent);
		child = parent;
		parent = HEAP_Get_Parent(child);
	}
}

void HEAP_Heapify(HEAP *heap, INTEGER index){
	INTEGER swap_index = index;
	INTEGER left_index = HEAP_Get_Left(index);
	INTEGER right_index = HEAP_Get_Right(index);

	if(left_index <= heap->size && HEAP_Comparison(heap, left_index, swap_index)){
		swap_index = left_index;
	}
	if(right_index <= heap->size && HEAP_Comparison(heap, right_index, swap_index)){
		swap_index = right_index;
	}
	if(swap_index != index){
		HEAP_Swap(heap, swap_index, index);
		HEAP_Heapify(heap, swap_index);
	}
}

VERTEX *HEAP_Dequeue(HEAP *heap){
	VERTEX *dequeued = heap->arr[1];

	HEAP_Swap(heap, 1, heap->size--);
	HEAP_Heapify(heap, 1);

	dequeued->in_queue = FALSE;
	return dequeued;
}