#include <stdio.h>

typedef struct artikl {
    char ime[30];
    float cijena;
    int kolicina;
}ARTIKL;

int main(void) {
    ARTIKL artikli[10], *max;

    int i, n;
    do {
        scanf("%d", &n);
    } while (n > 10);

    for (i = 0; i < n; i++)
    {
        scanf("%s\n%d\n%f", artikli[i].ime, &artikli[i].kolicina, &artikli[i].cijena);
    }

    max = &artikli[0];
    for (i = 0; i < n; i++)
    {
        if (max->cijena < artikli[i].cijena)
            max = &artikli[i];
    }

    printf("REZULTATI:\n");
    printf("cijena: %.2f, kolicina: %d", max->cijena, max->kolicina);
    return 0;
}
