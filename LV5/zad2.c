#include <stdio.h>
#include <string.h>

typedef struct {
    char naziv[50];
    float cijena;
    int kolicina;
} Artikl;

typedef struct {
    char kupac[50];
    char prodavac[50];
    int  broj_artikala;
    Artikl artikli[10];
    float ukupan_iznos;
} Racun;

void ispisRacuna(Racun *r) {
    int i;
    float cijena;
    int kolicina;
    printf("REZULTATI:\n");
    printf("Kupac: %s\n", r->kupac);
    printf("Prodavac: %s\n", r->prodavac);
    printf("-----------------------------\n");
    printf("Artikli: \n");
    printf("rb   naziv                    kolicina    cijena    ukupno\n");
    for (i = 0; i < r->broj_artikala; i++) {
        cijena = r->artikli[i].cijena;
        kolicina = r->artikli[i].kolicina;
        printf("%-4d %-25s %-10d %-10.2f %.2f\n", i+1, r->artikli[i].naziv, kolicina, cijena, kolicina * cijena);
    }
    printf("\nUkupan iznos racuna: %.2f", r->ukupan_iznos);
}

void unesiPodatkeRacuna(Racun *r) {
    int i, j;

    fgets(r->kupac, 50, stdin);
    for (i = 0; i < strlen(r->kupac); i++) {
        if (r->kupac[i] == '\n')
            r->kupac[i] = '\0';
    }
    fgets(r->prodavac, 50, stdin);
    for (i = 0; i < strlen(r->prodavac); i++) {
        if (r->prodavac[i] == '\n')
            r->prodavac[i] = '\0';
    }
    scanf("%d", &r->broj_artikala);

    for (i = 0; i < r->broj_artikala; i++) {
        getchar();
        fgets(r->artikli[i].naziv, 50, stdin);
        for (j = 0; j < strlen(r->artikli[i].naziv); j++) {
            if (r->artikli[i].naziv[j] == '\n')
                r->artikli[i].naziv[j] = '\0';
        }
        scanf("%f",&r->artikli[i].cijena);
        scanf("%d", &r->artikli[i].kolicina);
        r->ukupan_iznos = r->ukupan_iznos + r->artikli[i].cijena * r->artikli[i].kolicina;
    }
}

int main(void) {
    Racun racun;

    unesiPodatkeRacuna(&racun);

    ispisRacuna(&racun);

    return 0;
}

