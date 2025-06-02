#ifndef LV7_STUDENTI_H
#define LV7_STUDENTI_H

int procitajBrojStudenata(const char*);
void unesiStudente(int, const char*);

/*
#include <stdio.h>
#include <stdlib.h>

int procitajBrojStudenata(const char* putanja) {
    FILE* datoteka = fopen(putanja, "r");
    if (datoteka == NULL) {
        printf("Ne mogu otvoriti datoteku %s\n", putanja);
        exit(1);
    }
    int brojStudenata;
    fscanf(datoteka, "%d", &brojStudenata);
    fclose(datoteka);

    return brojStudenata;
}

void unesiStudente(int brojStudenata, const char* putanja) {
    FILE* datoteka = fopen(putanja, "w");
    if (datoteka == NULL) {
        printf("Ne mogu otvoriti datoteku %s\n", putanja);
        exit(1);
    }
    for (int i = 0; i < brojStudenata; i++) {
        char ime[50], prezime[50];
        scanf("%s %s", ime, prezime);
        fprintf(datoteka, "Student broj: %d.\tIme: %s\tPrezime: %s\n", i+1, ime, prezime);
    }
    fclose(datoteka);
}
 */
#endif //LV7_STUDENTI_H