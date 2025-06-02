#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int najveci(int *arr, int n) {
    if (n == 1)
        return arr[0];

    int max = najveci(arr, n-1);
    if (arr[n-1] > max)
        max = arr[n-1];

    return max;
}

int main() {
    int n;
    printf("Unesite broj elemenata:");
    scanf("%d", &n);

    if (n <= 0 || n > 20) {
        printf("Neispravan unos!\n");
        return 1;
    }

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Neuspjelo zauzimanje memorije!\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 151 - 50;
        printf("%d ", arr[i]);
    }

    int max = najveci(arr, n);

    FILE *file = fopen("najveci.txt", "w");
    if (file == NULL) {
        printf("Greska pri otvaranju datoteke!\n");
        return 1;
    }

    fprintf(file, "Najveci element je %d", max);
    fclose(file);
    printf("\nNajveci element je %d i upisan je u datoteku najveci.txt\n", max);

    free(arr);
    return 0;
}

