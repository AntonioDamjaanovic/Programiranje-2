#include <stdio.h>
#include <stdlib.h>

typedef struct podaci {
    char prezime[20];
    char ime[20];
    int sifra;
    char adresa[100];
    int brTel;
} PODACI;

typedef struct posudba {
    char imeFilma[20];
    int datum;
    int sifraClana;
} POSUDBA;

void kreiraj() {
    FILE *fpt = NULL;
    fpt = fopen("clanovi.txt","wb");
    if (fpt == NULL) {
        perror("Greška");
        exit(EXIT_FAILURE);
    }

    fclose(fpt);
}

void procitaj() {
    PODACI clanovi[100];
    FILE *fpt = NULL;
    fpt = fopen("clanovi.txt","rb");
    if (fpt == NULL) {
        perror("Greška");
        exit(EXIT_FAILURE);
    }

    int brojClanova;
    fseek(fpt,0L,SEEK_END);
    brojClanova = ftell(fpt) / sizeof(PODACI);
    fread(&clanovi, sizeof(PODACI), brojClanova, fpt);

    fclose(fpt);
}

void dodaj() {
    PODACI clan = {0};
    FILE *fpt = NULL;
    fpt = fopen("clanovi.txt","ab+");
    if (fpt == NULL) {
        perror("Greška");
        exit(EXIT_FAILURE);
    }

    scanf("%s %s %d %[^\n] %d", clan.prezime, clan.ime, &clan.sifra, clan.adresa, &clan.brTel);
    fwrite(&clan, sizeof(PODACI), 1, fpt);

    fclose(fpt);
}

void posudi() {
    FILE *fpt = fopen("posudbe.txt","ab+");
    if (fpt == NULL) {
        perror("greska");
        exit(EXIT_FAILURE);
    }
    POSUDBA polje[4],poljee[100];

    int n, kolicina, i, j, broj = 0;
    do
        scanf("%d",&n);
    while (n>4 || n<0);
    for (i = 0; i < n; i++) {
        scanf("%[^\n]] %d %d", polje[i].imeFilma, &polje[i].datum, &polje[i].sifraClana);
        fseek(fpt,0L,SEEK_END);
        kolicina=ftell(fpt)/sizeof(POSUDBA);
        fread(poljee,sizeof(POSUDBA),kolicina,fpt);
        for (j = 0; j < kolicina; j++) {
            if (poljee[j].sifraClana == polje[j].sifraClana)
                broj++;
        }
        if (broj > 4) {
            exit(EXIT_SUCCESS);
        }
        else
            fwrite(&polje[i],sizeof(POSUDBA),1,fpt);

    }
}

int main() {
    int n;

    while(1) {
        scanf("%d",&n);
        switch (n) {
            case 1:
                kreiraj();
                break;
            case 2:
                procitaj();
                break;
            case 3:
                dodaj();
                break;
            case 4:
                posudi();
                break;
            default:
                exit(EXIT_SUCCESS);
                break;
        }
    }
    return 0;
}