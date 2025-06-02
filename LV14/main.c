#include <stdio.h>
#include <stdlib.h>
#include "automobil.h"

int main() {
    int n;
    printf("broj automobila:");
    scanf("%d", &n);

    AUTOMOBIL *auti = (AUTOMOBIL*)malloc(n * sizeof(AUTOMOBIL));
    if (auti == NULL) {
        printf("Greska pri alokaciji memorije!\n");
        return 1;
    }

    unos(auti, n);
    ispis(auti, n);

    free(auti);
    return 0;
}
