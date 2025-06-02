#include "zad2_functions.h"
#include "stdio.h"
#include "stdlib.h"

void ucitavanje(ARTIKL *artikli, int n){
    int i;
    for (i = 0; i < n; i++) {
        scanf("%s\n %d\n %f\n", &artikli[i].ime, &artikli[i].kolicina, &artikli[i].cijena);
    }
}
ARTIKL *najveci(ARTIKL *artikli, int n){
    int i;
    ARTIKL *max = &artikli[0];
    for(i = 0; i < n; i++) {
        if (max->cijena < artikli[i].cijena)
            max = &artikli[i];
    }
    return max;
}
