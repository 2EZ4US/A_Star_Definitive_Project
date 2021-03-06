
void A_Star_Matrix_Search(MATRIX *matrix, PAIR *source, PAIR *destination, Generic (*heuristic)()) {
    Integer dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
    Integer dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

    HEAP *priority_queue = HEAP_Create(matrix->rows * matrix->columns);

    HEAP_Enqueue(priority_queue, source, PAIR_Is_Lower);
    matrix->distance[source->i][source->j] = 0;

    while(!HEAP_Empty(priority_queue)) {
        U_Print_Matrix(matrix);
        PAIR *current = HEAP_Dequeue(priority_queue, PAIR_Is_Bigger);

        if(!MATRIX_Arrived_Destination(current, destination) ) {
            for(Integer i = 0; i < 7; i++) {
                PAIR *next = PAIR_Create(current->i + dx[i], current->j + dy[i], 0);

	           if(!MATRIX_Blocked_Position(matrix, next)) {
                    Generic new_cost = (Integer) MATRIX_Get_Heuristic(next, destination, heuristic) + 
                    (Integer) MATRIX_Get_Source_Distance(next, source, heuristic);
                    next->distance = new_cost;

                    if(new_cost < matrix->distance[next->i][next->j]) {
                        MATRIX_Set_Pair_Next_Path(matrix, current, next, new_cost);

                        matrix->distance[next->i][next->j] = new_cost;
                        HEAP_Enqueue(priority_queue, next, PAIR_Is_Lower);
                    }
                } 
            } 
        } else {
            while(!HEAP_Empty(priority_queue))
                HEAP_Dequeue(priority_queue, PAIR_Is_Bigger);
            U_Print_Final_Matrix(matrix, source, destination);
            return;
        }

        usleep(25000);
    }
    return;
}
