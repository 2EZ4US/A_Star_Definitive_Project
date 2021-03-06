
typedef struct HEAP {
    Generic *array;
    Integer size;
} HEAP;

HEAP* HEAP_Create(Integer MAX_HEAP_SIZE) {
    HEAP *new_heap = (HEAP*) malloc(sizeof(HEAP));
    new_heap->array = (Generic*) calloc(MAX_HEAP_SIZE, sizeof(Generic));
    new_heap->size = 0;
    return new_heap;
}

bool HEAP_Empty(HEAP *heap) {
    return (heap->size == 0);
}

Integer HEAP_Get_Parent(Integer index) {
    return (index >> 1);
}

Integer HEAP_Get_Left_Child(Integer index) {
    return (index << 1);
}

Integer HEAP_Get_Right_Child(Integer index) {
    return ((index << 1) + 1);
}

Integer HEAP_Size(HEAP *heap) {
    return heap->size;
}

void HEAP_Swap(HEAP *heap, Integer first_index, Integer second_index) {
    Generic aux = heap->array[first_index];
    heap->array[first_index] = heap->array[second_index];
    heap->array[second_index] = aux;
    return;
}

void HEAP_Enqueue(HEAP *heap, Generic data, bool (*Lambda)()) {
    heap->array[++heap->size] = data;
    Integer current = heap->size;
    Integer parent = HEAP_Get_Parent(current);

    while(parent >= 1 && Lambda(heap->array[current], heap->array[parent])) {
        HEAP_Swap(heap, current, parent);
        current = parent;
        parent = HEAP_Get_Parent(current);
    }
    return;
}

void HEAP_Heapify(HEAP *heap, Integer index, bool (*Lambda)()) {
    Integer least = index;
    Integer left = HEAP_Get_Left_Child(index);
    Integer right = HEAP_Get_Right_Child(index);

    if(left <= heap->size) {
        if(Lambda(heap->array[least], heap->array[left])) {
            least = left;
        }
    }
    if(right <= heap->size) {
        if(Lambda(heap->array[least], heap->array[right])) {
            least = right;
        }
    }
    if(least != index) {
        HEAP_Swap(heap, index, least);
        HEAP_Heapify(heap, least, Lambda);
    }
    return;
}

Generic HEAP_Dequeue(HEAP *heap, bool (*Lambda)()) {
    Generic save_first = heap->array[1];
    HEAP_Swap(heap, 1, heap->size--);
    HEAP_Heapify(heap, 1, Lambda);
    return save_first;
}


