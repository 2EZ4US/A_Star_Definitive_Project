
void U_Print_Matrix(MATRIX *matrix) {
    for(Integer i = 0; i < matrix->rows; i++) {
        for(Integer j = 0; j < matrix->columns; j++) {
            if(matrix->graph[i][j] == 0) {
                if(matrix->distance[i][j] != INF) {
                    if(matrix->distance[i][j] > 9) {
                        printf("%lld ", matrix->distance[i][j]);
                    } else {
                        printf(" %lld ", matrix->distance[i][j]);
                    }
                } else {
                    printf(" ~ ");
                }
            } else {
                printf(" @ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void U_Print_Final_Matrix(MATRIX *matrix, PAIR *source, PAIR *destination) {

    PAIR *current = destination;
    while(current->i != source->i && current->j != source->j) {
        matrix->mask[current->i][current->j] = 1;
        current = matrix->path[current->i][current->j];
    }

    for(Integer i = 0; i < matrix->rows; i++) {
        for(Integer j = 0; j < matrix->columns; j++) {
            if(matrix->graph[i][j] == 0) {
                if(matrix->mask[i][j])
                    printf(" O ");
                else
                    printf(" ~ ");
            } else {
                printf(" # ");
            }
        }
        printf("\n");
    }
}
