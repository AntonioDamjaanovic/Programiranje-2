#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct clan {
    int ID;
    char ime[20];
    char prezime[20];
    char adresa[40];
    int brTel;
    int brojFilmova;
} CLAN;

void kreiraj() {
    FILE *fpt = NULL;
    fpt = fopen("clanovi.bin","wb");
    if (fpt == NULL) {
        perror("Greška");
        exit(EXIT_FAILURE);
    }

    int brojClanova = 0;
    fwrite(&brojClanova, sizeof(int), 1, fpt);

    fclose(fpt);
}

void dodaj() {
    CLAN clan;
    FILE *fpt = NULL;
    int brojClanova = 0;

    fpt = fopen("clanovi.bin","rb+");
    if (fpt == NULL) {
        perror("Greška");
        exit(EXIT_FAILURE);
    }

    fread(&brojClanova, sizeof(int), 1, fpt);
    brojClanova++;
    fseek(fpt, 0, SEEK_SET);
    fwrite(&brojClanova, sizeof(int), 1, fpt);

    printf("Unesite podatke o korisniku:\n");
    scanf("%d %s %s %s %d %d", &clan.ID, clan.ime, clan.prezime, clan.adresa , &clan.brTel, &clan.brojFilmova);

    fseek(fpt, 0, SEEK_END);
    fwrite(&clan, sizeof(CLAN), 1, fpt);

    fclose(fpt);
}

void procitaj() {
    CLAN *clanovi = NULL;
    FILE *fpt = NULL;
    int brojClanova = 0;

    fpt = fopen("clanovi.bin","rb");
    if (fpt == NULL) {
        perror("Greška");
        exit(EXIT_FAILURE);
    }
    fread(&brojClanova, sizeof(int), 1, fpt);
    clanovi = (CLAN*) malloc(brojClanova * sizeof(CLAN));

    fread(clanovi, sizeof(CLAN), brojClanova, fpt);

    fclose(fpt);
}

void ispisiSve() {
    CLAN *clanovi;
    FILE *fpt = NULL;
    int brojClanova = 0, i;

    fpt = fopen("clanovi.bin","rb");
    if (fpt == NULL) {
        perror("Greška");
        exit(EXIT_FAILURE);
    }
    fread(&brojClanova, sizeof(int), 1, fpt);
    clanovi = (CLAN*) malloc(brojClanova * sizeof(CLAN));

    fread(clanovi, sizeof(CLAN), brojClanova, fpt);

    for (i = 0; i < brojClanova; i++) {
        printf("\n");
        printf("Sifra: %d\n", clanovi[i].ID);
        printf("Ime: %s\n", clanovi[i].ime);
        printf("Prezime: %s\n", clanovi[i].prezime);
        printf("Adresa: %s\n", clanovi[i].adresa);
        printf("Broj telefona: %d\n", clanovi[i].brTel);
        printf("Broj filmova: %d\n", clanovi[i].brojFilmova);
    }

    fclose(fpt);
}

void pronadjiKorisnika(int ID) {
    CLAN *clanovi;
    FILE *fpt = NULL;
    int brojClanova = 0, i;
    int korisnikPronadjen = 0;

    fpt = fopen("clanovi.bin","rb");
    if (fpt == NULL) {
        perror("Greška");
        exit(EXIT_FAILURE);
    }
    fread(&brojClanova, sizeof(int), 1, fpt);
    clanovi = (CLAN*) malloc(brojClanova * sizeof(CLAN));

    fread(clanovi, sizeof(CLAN), brojClanova, fpt);

    for (i = 0; i < brojClanova; i++) {
        if (clanovi[i].ID == ID) {
            printf("Sifra: %d\n", clanovi[i].ID);
            printf("Ime: %s\n", clanovi[i].ime);
            printf("Prezime: %s\n", clanovi[i].prezime);
            printf("Adresa: %s\n", clanovi[i].adresa);
            printf("Broj telefona: %d\n", clanovi[i].brTel);
            printf("Broj filmova: %d\n", clanovi[i].brojFilmova);
            printf("\n");

            korisnikPronadjen = 1;
            break;
        }
    }

    if (korisnikPronadjen == 0) {
        printf("Korisnik sa sifrom %d ne postoji.\n", ID);
    }

    fclose(fpt);
}

int main() {
    int n, ID;
    char *izbor;
    kreiraj();

    while (1){
        printf("Unesite broj 1-5:");
        scanf("%d", &n);

        switch (n) {
            case 1:
                dodaj();
                break;
            case 2:
                procitaj();
                break;
            case 3:
                ispisiSve();
                break;
            case 4:
                printf("Unesi sifru korisnika:");
                scanf("%d", &ID);
                pronadjiKorisnika(ID);
                break;
            case 5:
                printf("Da li ste sigurni kako zelite zavrsiti program?");
                scanf("%s", izbor);
                if (strcmp(izbor, "da") == 0){
                    exit(EXIT_SUCCESS);
                }
                else{
                    break;
                }
        }
    }
}