#include "header.h"

int main() {
    Integer rows, columns;
    scanf("%lld %lld", &rows, &columns);
    MATRIX *my_matrix = MATRIX_Create(rows, columns);

    for(Integer i = 0; i < my_matrix->rows; i++)
        for(Integer j = 0; j < my_matrix->columns; j++)
            scanf("%lld", &my_matrix->graph[i][j]);

    Integer x, y;
    scanf("%lld %lld", &x, &y);
    PAIR *source = PAIR_Create(x, y, 0);

    scanf("%lld %lld", &x, &y);
    PAIR *destination = PAIR_Create(x, y, INF);

    A_Star_Matrix_Search(my_matrix, source, destination, MATRIX_Diagonal_Distance);
    return;
}
