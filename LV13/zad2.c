#include <stdio.h>
#include <stdlib.h>

#define INDEX(dg,gg) ((dg + gg) / 2);

int cmpfunc (const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int binarnaPretraga (int brojevi[], int x, int length, int *brk) {
    int dg, gg, s;

    dg = 0;
    gg = length - 1;
    while (dg <= gg) {
        s = INDEX(dg, gg);
        (*brk)++;
        if (x == brojevi[s]) {
            return s;
        }
        else if (x > brojevi[s])
            dg = s + 1;
        else if (x < brojevi[s])
            gg = s - 1;
        if (dg>gg) return -1;
    }
}

int  main() {
    FILE* file;
    int *brojevi;
    int broj;
    int dg = 0;
    int gg = 499;
    int brk = 0;
    int bp = 0;
    brojevi = (int*)malloc(500 * sizeof(int));
    if(brojevi == NULL) {
        return 1;
    }
    file = fopen("in.txt", "r");
    if(file == NULL) {
        return 1;
    }

    for (int i = 0; i < 499; i++) {
        fscanf(file, "%d", &brojevi[i]);
    }
    do {
        scanf("%d", &broj);
    } while(broj < 1 || broj > 1000);

    qsort(brojevi, 500, sizeof(int), cmpfunc);
    bp = binarnaPretraga(brojevi, broj, 500, &brk);

    printf("REZULTATI:\n");
    if (bp == -1) {
        printf("Broj nije nadjen.");
    } else {
        printf("Broj je nadjen.");
    }
    return 0;
}
