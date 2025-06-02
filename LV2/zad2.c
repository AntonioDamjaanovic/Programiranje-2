#include <stdio.h>

struct datum {
    int dan, mjesec, godina;
};

typedef struct {
    char ime[20];
    char prezime[20];
    long int matbr;
    float prosjek;
    struct datum dat;
}ucenik;

int main() {
    ucenik u[40];
    int i, n, index = 0;
    printf("n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%s\n %s\n %ld\n %f\n %d.%d.%d.", u[i].ime, u[i].prezime, &u[i].matbr, &u[i].prosjek, &u[i].dat.dan, &u[i].dat.mjesec, &u[i].dat.godina);
    }

    float max = u[0].prosjek;
    for (i = 0; i < n; i++){
        if (u[i].prosjek > max){
            max = u[i].prosjek;
            index = i;
        }
    }

    printf("REZULTATI:\n");
    printf("%s %s", u[index].ime, u[index].prezime);

    return 0;
}
