#include <stdio.h>
#include <stdlib.h>
#include <time.h>

short** zauzimanjeMatrice(int m) {
    short **matrica = (short **)malloc(m * sizeof(short *));
    if (matrica == NULL){
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        matrica[i] = (short *)malloc(m * sizeof(short));
        if (matrica[i] == NULL)
            exit(1);
    }
    return matrica;
}

void popunjavanjeMatrice(short **matrica, int m) {
    srand(time(0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            matrica[i][j] = rand() % (250 - (-1550) + 1) + (-1550);
}

short najveciParniBroj(short **matrica, int m) {
    short maxParni = -1551;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (matrica[m-j-1][i] % 2 == 0 && matrica[m-j-1][i] > maxParni)
                maxParni = matrica[m-j-1][i];
        }
    }
    return maxParni;
}

void novaMatrica(short **matrica, int m, short maxParni){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j < m - i - 1) {
                matrica[i][j] = maxParni;
            }
        }
    }
}

void ispisMatrice(short **matrica, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", matrica[i][j]);
        printf("\n");
    }
}

short** brisanjeMatrice(short **matrica, int m) {
    for (int i = 0; i < m; i++)
        free(matrica[i]);
    free(matrica);
    return NULL;
}

int main() {
    srand(time(0));
    int m = rand() % (18 - 3 + 1) + 3;
    m = 4;
    short **matrica = zauzimanjeMatrice(m);
    popunjavanjeMatrice(matrica, m);
    ispisMatrice(matrica, m);
    printf("\n");
    short maxParni = najveciParniBroj(matrica, m);
    novaMatrica(matrica, m, maxParni);
    ispisMatrice(matrica, m);
    matrica = brisanjeMatrice(matrica, m);

    return 0;
}

