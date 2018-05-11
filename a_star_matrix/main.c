#include "header.h"


int main() {
    MATRIX *my_matrix = MATRIX_Create(30, 50);

    for(Integer i = 0; i < my_matrix->rows; i++)
        for(Integer j = 0; j < my_matrix->columns; j++)
            my_matrix->graph[i][j] = 0;

    PAIR *source = PAIR_Create(0, 2, 0);
    PAIR *destination = PAIR_Create(28,37,INF);
    A_Star_Matrix_Search(my_matrix, source, destination,
            MATRIX_Diagonal_Distance);

}