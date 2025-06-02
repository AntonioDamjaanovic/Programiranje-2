#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct tocka {
    float x, y, z;
} TOCKA;

typedef struct trokut {
    TOCKA *a, *b, *c;
} TROKUT;

int main() {
    FILE *file = NULL;
    file = fopen("model.txt", "r");
    if (file == NULL) {
        printf("Greska prilikom otvaranja datoteke!\n");
        exit(EXIT_FAILURE);
    }

    int n, m, i, d, e, f;
    float s1, s2, s3, op, max = 0;
    TOCKA *tocke = NULL;
    TROKUT *trokuti = NULL;

    fscanf(file, "%d %d", &n, &m);

    tocke = (TOCKA*)malloc(n * sizeof(TOCKA));
    if (tocke == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(EXIT_FAILURE);
    }

    trokuti = (TROKUT*)malloc(m * sizeof(TROKUT));
    if (trokuti == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(EXIT_FAILURE);
    }
    
    for (i = 0; i < n; i++) {
        fscanf(file, "%f %f %f", &tocke[i].x, &tocke[i].y, &tocke[i].z);
    }

    for (i = 0; i < m; i++) {
        fscanf(file, "%d %d %d", &d, &e, &f);
        trokuti[i].a = &tocke[d];
        trokuti[i].b = &tocke[e];
        trokuti[i].c = &tocke[f];
    }

    for (i = 0; i < m; i++) {
        s1 = sqrt(pow(trokuti[i].a->x - trokuti[i].b->x, 2) + pow(trokuti[i].a->y - trokuti[i].b->y, 2) + pow(trokuti[i].a->z - trokuti[i].b->z, 2));
        s2 = sqrt(pow(trokuti[i].b->x - trokuti[i].c->x, 2) + pow(trokuti[i].b->y - trokuti[i].c->y, 2) + pow(trokuti[i].b->z - trokuti[i].c->z, 2));
        s3 = sqrt(pow(trokuti[i].c->x - trokuti[i].a->x, 2) + pow(trokuti[i].c->y - trokuti[i].a->y, 2) + pow(trokuti[i].c->z - trokuti[i].a->z, 2));
        op = s1 + s2 + s3;
        if (op > max)
            max = op;
    }

    fclose(file);
    free(tocke);
    free(trokuti);

    printf("REZULTATI:\n");
    printf("%.2f",max);
    return 0;
}