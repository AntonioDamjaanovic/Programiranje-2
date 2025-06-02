#include <stdio.h>
#include <stdlib.h>

int suma(int n) {
    if (n == 0)
        return 0;
    return (n % 10 + suma(n / 10));
}

int main() {
    int x;
    FILE *file = NULL;

    file = fopen("suma.txt", "w");
    if (file == NULL) {
        printf("Greska prilikom otvaranja datoteke");
        exit(EXIT_FAILURE);
    }

    scanf("%d", &x);
    printf("%d\n", suma(x));
    fprintf(file, "%d", suma(x));

    fclose(file);
    return 0;
}