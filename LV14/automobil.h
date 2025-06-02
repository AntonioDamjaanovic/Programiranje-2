#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

typedef struct {
    char marka[40];
    char model[40];
    int broj_konja;
    int max_brzina;
    float cijena;
} AUTOMOBIL;

void unos(AUTOMOBIL *auti, int n);
void ispis(const AUTOMOBIL *auti, int n);

#endif
