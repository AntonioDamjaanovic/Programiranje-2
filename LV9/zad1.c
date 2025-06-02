#include <stdio.h>

FILE *file;
int ukupnaVisina;

void drawPyramid(int trenutniRed) {
    if (trenutniRed == 0) return;
    drawPyramid(trenutniRed - 1);

    int razmaci = ukupnaVisina - trenutniRed;
    for (int i = 0; i < razmaci; i++) {
        fprintf(file, " ");
        printf(" ");
    }

    int zvjezdice = 2 * trenutniRed - 1;
    for (int i = 0; i < zvjezdice; i++) {
        fprintf(file, "*");
        printf("*");
    }

    fprintf(file, "\n");
    printf("\n");
}

int main() {
    int visina;

    do {
        printf("visina:");
        scanf("%d", &visina);
    } while (visina < 1 || visina > 30);

    file = fopen("piramida.txt", "w");
    if (file == NULL) {
        printf("Greška pri kreiranju datoteke!\n");
        return 1;
    }

    ukupnaVisina = visina;
    drawPyramid(visina);
    fclose(file);

    return 0;
}
