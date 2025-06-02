#include <stdio.h>

int suma(int);

int main() {
    int x;
    FILE *dat = NULL;

    dat = fopen("suma.txt","w");
    if (dat == NULL) {
        printf("Greska prilikom otvaranja datoteke");
    }

    scanf("%d", &x);
    printf("%d\n", suma(x));
    fprintf(dat,"%d", suma(x));

    return 0;
}

int suma(int n) {
    if (n == 0)
        return 0;
    return (n % 10 + suma(n / 10));
}