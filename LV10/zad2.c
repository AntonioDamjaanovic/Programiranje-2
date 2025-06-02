#include <stdio.h>
#include <stdlib.h>

typedef struct artikl {
    char *naziv;
    float cijena;
    int kolicina;
} ARTIKL;

typedef struct racun {
    char *prodavac;
    char *kupac;
    ARTIKL *artikli;
    int  brojArtikala;
    float ukupanIznos;
} RACUN;

int main() {
    FILE *file = fopen("racun.txt", "r");
    if (file == NULL) {
        printf("Greska prilikom otvaranja datoteke!\n");
        exit(EXIT_FAILURE);
    }

    float cijena;
    int kolicina, broj, i;
    RACUN racun;

    racun.ukupanIznos = 0;
    racun.artikli = (ARTIKL*)malloc(4 * sizeof(ARTIKL));
    if (racun.artikli == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(EXIT_FAILURE);
    }

    racun.prodavac = (char*)malloc(40 * sizeof(char));
    if (racun.prodavac == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(EXIT_FAILURE);
    }

    racun.kupac = (char*)malloc(40 * sizeof(char));
    if (racun.kupac == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%39[^\n] %39[^\n] ", racun.prodavac, racun.kupac);
    fscanf(file, "%d", &racun.brojArtikala);

    for (i = 0; i < racun.brojArtikala; i++) {
        fgetc(file);
        racun.artikli[i].naziv = (char*)malloc(40 * sizeof(char));
        fscanf(file, "%39[^\n]", racun.artikli[i].naziv, &racun.artikli[i].cijena, &racun.artikli[i].kolicina);
        fscanf(file, "%f", &racun.artikli[i].cijena);
        fscanf(file, "%d", &racun.artikli[i].kolicina);
        racun.ukupanIznos = racun.ukupanIznos + (float)(racun.artikli[i].cijena * racun.artikli[i].kolicina);
        printf("%f %d\n", racun.artikli[i].cijena, racun.artikli[i].kolicina);
        free(racun.artikli[i].naziv);

    }
    printf("REZULTATI:\n");
    printf("Ukupan iznos racuna: %.2f", racun.ukupanIznos);

    free(racun.prodavac);
    free(racun.kupac);
    free(racun.artikli);
    return 0;
}
