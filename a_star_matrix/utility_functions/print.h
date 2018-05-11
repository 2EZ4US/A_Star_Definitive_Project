
void Print_Matrix(MATRIX *matrix) {
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
    usleep(50000);
    printf("\n");
}
