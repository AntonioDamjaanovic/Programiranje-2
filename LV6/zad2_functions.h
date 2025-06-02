#ifndef LV6_ZAD2_FUNCTIONS_H
#define LV6_ZAD2_FUNCTIONS_H

typedef struct artikl {
    char ime[30];
    float cijena;
    int kolicina;
} ARTIKL;
void ucitavanje(ARTIKL*, int);
ARTIKL *najveci(ARTIKL*, int);

#endif //LV6_ZAD2_FUNCTIONS_H
