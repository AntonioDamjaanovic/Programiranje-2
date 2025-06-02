#include<stdio.h>
#include<stdlib.h>

int najveci (int **matrix, int n, int m);

int main(){
    int **matrix, m, n, i, j;

    do {
        scanf("%d", &n);
    } while (n < 2 || n > 5);
    do {
        scanf("%d", &m);
    } while (m < 2 || m > 8);

    matrix = (int**)malloc(n * sizeof(int*));
    if (matrix == NULL)
        return 0;

    for (i = 0; i < n; i++) {
        *(matrix + i) = (int*)malloc(m * sizeof(int));
        if (*(matrix + i) == NULL)
            return 0;
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            scanf("%d", (*(matrix + i) + j));
        }
    }

    printf("\nREZULTATI:\n");
    printf("%d", najveci(matrix, n, m));
    for (i = 0; i < n; i++)
        free(*(matrix + i));
    free(matrix);
    return 0;
}
int najveci(int **matrix, int n, int m){
    int max = **matrix, i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (max < *(*(matrix + i) + j))
                max = *(*(matrix + i) + j);
        }
    }
    return max;
}
