#include <stdio.h>
#include <stdlib.h>

void sequentialSearch(int*, int);
int* readFromFile();
void generateRandomNumbers(int, int);

int main() {
    int n;
    int *polje = NULL;

    generateRandomNumbers(0, 1000);
    polje = readFromFile();

    do {
        scanf("%d", &n);
    } while (n > 1000 || n < 0);

    sequentialSearch(polje, n);

    return 0;
}

void sequentialSearch(int *polje, int n) {
    int found = 0, steps = 0;
    for (int i = 0; i < 500; i++) {
        steps++;
        if (n == polje[i]) {
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Broj %d nije pronadjen.", n);
    }
    else {
        printf("Broj %d je pronadjen nakon %d koraka.", n, steps);
    }
}

int* readFromFile() {
    FILE *file = fopen("dat.txt", "r");
    if (file == NULL) {
        perror("Greska s datotekom");
        exit(EXIT_FAILURE);
    }

    int *polje = (int*)malloc(500 * sizeof(int));
    if (polje == NULL) {
        printf("Nemoguće zauzeti memoriju za polje.");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 500; i++) {
        fscanf(file, "%d ", &polje[i]);
    }
    fclose(file);

    return polje;
}

void generateRandomNumbers(int lowerBound, int upperBound) {
    FILE *file = fopen("dat.txt", "w");
    if (file == NULL) {
        perror("Greska s datotekom");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 500; i++) {
        int number = rand() % (upperBound - lowerBound) + lowerBound;
        fprintf(file, "%d ", number);
    }

    fclose(file);
}