
typedef struct MATRIX {
    Generic **graph;
    Generic **distance;
    Integer rows, columns;
} MATRIX;


MATRIX* MATRIX_Create(Integer rows, Integer columns) {
    MATRIX *new_graph = (MATRIX*) malloc(sizeof(MATRIX));
    new_graph->graph = (Generic**) malloc(rows * sizeof(Generic*));
    new_graph->distance = (Generic**) malloc(rows * sizeof(Generic*));
    for(Integer i = 0; i < rows; i++) {
        new_graph->graph[i] = (Generic*) malloc(columns * sizeof(Generic));
        new_graph->distance[i] = (Generic*) malloc(columns * sizeof(Generic));
        for(Integer j = 0; j < columns; j++) {
            new_graph->distance[i][j] = INF;
        }
    }
    new_graph->rows = rows;
    new_graph->columns = columns;
    return new_graph;
}

bool MATRIX_Arrived_Destination(PAIR *current, PAIR *destination) {
    if((current->i == destination->i) && (current->j == destination->j)) {
        return true;
    }
    return false;
}

bool MATRIX_Valid_Position(MATRIX *matrix, PAIR *current) {
    if((current->i >= 0 && current->i < matrix->rows) &&
            (current->j >= 0 && current->j < matrix->columns)) {
        return true;
    }
    return false;
}

bool MATRIX_Blocked_Position(MATRIX *matrix, PAIR *current) {
    if(MATRIX_Valid_Position(matrix, current) &&
            matrix->graph[current->i][current->j] == 0) {
        return false;
    }
    return true;
}

Generic MATRIX_Manhattan_Distance(PAIR *current, PAIR *destination) {
    return abs(current->i - destination->i) + abs(current->j - destination->j);
}

Generic MATRIX_Diagonal_Distance(PAIR *current, PAIR *destination) {
    return max(abs(current->i - destination->i), abs(current->j - destination->j));
}

Generic MATRIX_Get_Heuristic(PAIR *current, PAIR *destination, Generic (*lambda)()) {
    return lambda(current, destination);
}
