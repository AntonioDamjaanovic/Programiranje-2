#include <stdio.h>
#include <stdlib.h>

int sequential(int *arrayToSearch, int valueToFind, int numberOfElements){
    int flag = 0, i;
    for (i = 0; i < numberOfElements; i++) {
        if (arrayToSearch[i] == valueToFind) {
            printf("%d je pronadjen u %d koraka.\n", valueToFind, i + 1);
            flag = 1;
            return i + 1;
        }
    }
    if (flag == 0)
        printf("%d nije pronadjen.\n", valueToFind);
    return 0;
}

void swap(int *x, int *y) {
    int help;
    help = *x;
    *x = *y;
    *y = help;
}

void qSort(int *arrayToSearch, int low, int high) {
    int i = low, j = high;
    int s = arrayToSearch[(low + high) / 2];
    while (i <= j) {
        while (arrayToSearch[i] < s)
            i++;
        while (arrayToSearch[j] > s)
            j--;
        if (i <= j) {
            swap(&arrayToSearch[i], &arrayToSearch[j]);
            i++;
            j--;
        }
    }
    if (low < j)
        qSort(arrayToSearch, low, j);
    if (i < high)
        qSort(arrayToSearch, i, high);
}

int binarySearch(int *arrayToSearch, int valueToFind, int numberOfElements){
    int dg = 0, gg = numberOfElements - 1, s, count = 0;
    qSort(arrayToSearch, dg, gg);

    while (dg <= gg) {
        s = (dg + gg) / 2;
        if (valueToFind == arrayToSearch[s]) {
            count++;
            printf("%d je pronadjen u %d koraka.\n", valueToFind, count);
            return count;
        }
        if (valueToFind > arrayToSearch[s]) {
            dg = s + 1;
            count++;
        }
        if (valueToFind < arrayToSearch[s]) {
            gg = s - 1;
            count++;
        }
    }
    if (dg > gg) {
        printf("%d nije pronadjen.\n", valueToFind);
        return 0;
    }
}

int main(void){
    int i = 0;

    FILE *file = fopen("dat.txt", "r");
    if (file == NULL) {
        printf("Datoteka dat.txt ne postoji.");
        exit(EXIT_FAILURE);
    }

    int helpValue;

    int counter = 0;
    while (fscanf(file, "%d ", &helpValue) != EOF)
        counter++;
    int *arrayToSearch = (int *)malloc(counter * sizeof(int));

    rewind(file);
    int j = 0;
    while (fscanf(file, "%d ", &arrayToSearch[j]) != EOF)
        j++;

    fclose(file);
    file = NULL;

    int valuesToFind[5];
    for (i = 0; i < 5; i++){
        do {
            printf("unesi %d. vrijednost:", i+1);
            scanf("%d", &valuesToFind[i]);
        } while (valuesToFind[i] <= 0 || valuesToFind[i] >= 1000);
    }

    int steps_sek = 0, check, divider = 0;
    printf("REZULTATI:\nSekvencijalno:\n");
    for (i = 0; i < 5; i++){
        printf("%d. broj ", i + 1);
        check = sequential(arrayToSearch, valuesToFind[i], counter);
        if (check != 0)
            divider++;
        steps_sek += check;
    }

    printf("\n");

    int steps_bin = 0;
    check = 0, divider = 0;
    printf("Binarno:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d. broj ", i + 1);
        check = binarySearch(arrayToSearch, valuesToFind[i], counter);
        if (check != 0)
            divider++;
        steps_bin += check;
    }

    if (divider == 0)
    {
        printf("Srednji broj koraka za sekvencijalno pretrazivanje je: %.2f\n", (float)steps_sek / 1);
        printf("Srednji broj koraka za binarno pretrazivanje je: %.2f\n", (float)steps_bin / 1);
    }

    else
    {
        printf("Srednji broj koraka za sekvencijalno pretrazivanje je: %.2f\n", (float)steps_sek / divider);
        printf("Srednji broj koraka za binarno pretrazivanje je: %.2f\n", (float)steps_bin / divider);
    }

    free(arrayToSearch);
    arrayToSearch = NULL;

    return 0;
}
