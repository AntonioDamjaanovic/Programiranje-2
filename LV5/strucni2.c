#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Tocka;

typedef struct {
    Tocka t1;
    Tocka t2;
    Tocka t3;
} Trokut;

int duljinaPolja(int donjaGranica, int gornjaGranica);
float duljinaStranice(Tocka t1, Tocka t2);
float opsegTrokuta(float a, float b, float c);

int main() {
    int m = duljinaPolja(3, 30);
    int n = duljinaPolja(1, 11);

    Tocka* tocke = (Tocka*) malloc(m * sizeof(Tocka));
    Trokut* trokuti = (Trokut*) malloc(n * sizeof(Trokut));

    // Unos točaka i trokuta
    // ...

    // Izračun duljina stranica i opsega trokuta
    // ...

    free(tocke);
    free(trokuti);

    return 0;
}

int duljinaPolja(int donjaGranica, int gornjaGranica) {
    int duljina;
    do {
        printf("Unesite broj između %d i %d:", donjaGranica, gornjaGranica);
        scanf("%d", &duljina);
    } while (duljina < donjaGranica || duljina > gornjaGranica);
    return duljina;
}

float duljinaStranice(Tocka t1, Tocka t2) {
    return sqrt(pow(t2.x - t1.x, 2) + pow(t2.y - t1.y, 2));
}

float opsegTrokuta(float a, float b, float c) {
    return a + b + c;
}

