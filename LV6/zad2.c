#include "zad2_functions.h"
#include "zad2_functions.c"
#include <stdio.h>

int main(void) {
    ARTIKL *max, artikli[100];
    int n;
    printf("Unesi n:");
    scanf("%d", &n);

    ucitavanje(&artikli[0], n);
    max = najveci(&artikli[0], n);

    // ispis ne dirati, mora koristiti pokazivac max
    printf("REZULTATI:\n");
    printf("cijena: %.2f, kolicina: %d", max->cijena, max->kolicina);
    return 0;
}
