#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x, y;
} Tocka;

typedef struct {
    Tocka t1, t2, t3;
    float opseg, udaljenost;
} Trokut;

int duljinaPolja(int donja, int gornja) {
    int broj;
    printf("Unesite broj između %d i %d:", donja, gornja);
    scanf("%d", &broj);
    return broj;
}

float udaljenostVrha(Tocka t) {
    return sqrt(pow(t.x, 2) + pow(t.y, 2));
}

int main() {
    int m = duljinaPolja(3, 30);
    int n = duljinaPolja(1, 11);

    Tocka* tocke = (Tocka*) malloc(m * sizeof(Tocka));

    Trokut* trokuti = (Trokut*) malloc(n * sizeof(Trokut));

    for (int i = 0; i < m; i++) {
        printf("Unesite koordinate tocke %d: ", i+1);
        scanf("%f %f", &tocke[i].x, &tocke[i].y);
    }

    for (int i = 0; i < n; i++) {
        printf("Unesite koordinate vrhova trokuta %d: ", i+1);
        scanf("%f %f %f %f %f %f", &trokuti[i].t1.x, &trokuti[i].t1.y, &trokuti[i].t2.x, &trokuti[i].t2.y, &trokuti[i].t3.x, &trokuti[i].t3.y);
        trokuti[i].opseg = udaljenostVrha(trokuti[i].t1) + udaljenostVrha(trokuti[i].t2) + udaljenostVrha(trokuti[i].t3);
        trokuti[i].udaljenost = trokuti[i].opseg / 3;
    }

    free(tocke);
    free(trokuti);

    return 0;
}

