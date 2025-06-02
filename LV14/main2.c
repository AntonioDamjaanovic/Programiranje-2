#include <stdio.h>
#include <stdlib.h>
#include "automobil.h"
#include "automobil2.h"

int main() {
    int n;
    printf("Koliko automobila zelite unijeti? ");
    scanf("%d", &n);

    AUTOMOBIL *auti = (AUTOMOBIL*)malloc(n * sizeof(AUTOMOBIL));
    if (auti == NULL) {
        printf("Greska pri alokaciji memorije!\n");
        return 1;
    }

    unos(auti, n);
    ispis(auti, n);

    minPriceByHP(auti, n);

    printf("\nSortiram po maksimalnoj brzini (od najbrzeg ka najsporijem)...\n");
    sortByVmax(auti, n);
    ispis(auti, n);

    free(auti);
    return 0;
}
