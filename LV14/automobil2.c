#include <stdio.h>
#include "automobil2.h"

void minPriceByHP(const AUTOMOBIL *auti, int n) {
    if (n <= 0) return;

    int minIdx = 0;
    float minPricePerHP = auti[0].cijena / auti[0].broj_konja;

    for (int i = 1; i < n; ++i) {
        float pricePerHP = auti[i].cijena / auti[i].broj_konja;
        if (pricePerHP < minPricePerHP) {
            minPricePerHP = pricePerHP;
            minIdx = i;
        }
    }

    printf("\nAutomobil s najmanjom cijenom po konjskoj snazi:\n");
    printf("  Marka: %s\n", auti[minIdx].marka);
    printf("  Model: %s\n", auti[minIdx].model);
    printf("  Broj konja: %d\n", auti[minIdx].broj_konja);
    printf("  Maksimalna brzina: %d km/h\n", auti[minIdx].max_brzina);
    printf("  Cijena: %.2f EUR\n", auti[minIdx].cijena);
    printf("  Cijena po konjskoj snazi: %.2f EUR/KS\n", minPricePerHP);
}

void sortByVmax(AUTOMOBIL *auti, int n) {
    // Sortiraj od najbržeg do najsporijeg (Bubble sort)
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (auti[j].max_brzina < auti[j + 1].max_brzina) {
                AUTOMOBIL temp = auti[j];
                auti[j] = auti[j + 1];
                auti[j + 1] = temp;
            }
        }
    }
}
