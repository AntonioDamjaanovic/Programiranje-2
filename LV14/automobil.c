#include <stdio.h>
#include "automobil.h"

void unos(AUTOMOBIL *auti, int n) {
    for (int i = 0; i < n; ++i) {
        printf("Automobil #%d\n", i + 1);
        printf("Marka:");
        scanf("%s", auti[i].marka);
        printf("Model:");
        scanf("%s", auti[i].model);
        printf("Broj konja:");
        scanf("%d", &auti[i].broj_konja);
        printf("Maksimalna brzina:");
        scanf("%d", &auti[i].max_brzina);
        printf("Cijena:");
        scanf("%f", &auti[i].cijena);
    }
}

void ispis(const AUTOMOBIL *auti, int n) {
    printf("\n--- Podaci o automobilima ---\n");
    for (int i = 0; i < n; ++i) {
        printf("Automobil #%d:\n", i + 1);
        printf("  Marka: %s\n", auti[i].marka);
        printf("  Model: %s\n", auti[i].model);
        printf("  Broj konja: %d\n", auti[i].broj_konja);
        printf("  Maksimalna brzina: %d km/h\n", auti[i].max_brzina);
        printf("  Cijena: %.2f EUR\n", auti[i].cijena);
    }
}
