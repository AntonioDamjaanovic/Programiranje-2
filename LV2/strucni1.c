#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void printStringBackward(const char *day) {
    for (int i = strlen(day) - 1; i >= 0; i--) {
        printf("%c", *(day + i));
    }
}

int countVowels(const char *day) {
    int count = 0;
    const char* vowels = "aeiouAEIOU";

    for (; *day != '\0'; day++) {
        for (const char *v = vowels; *v != '\0'; v++) {
            if (*day == *v) {
                count++;
                break;
            }
        }
    }
    return count;
}

const char* findDayWithMostVowels(const char* days[]) {
    int indexOfDay = 0, maxVowels = 0;

    for (int i = 0; i < 7; i++) {
        int numOfVowels = countVowels(*(days + i));
        if (numOfVowels > maxVowels) {
            maxVowels = numOfVowels;
            indexOfDay = i;
        }
    }
    return *(days + indexOfDay);
}

int main(void) {
    const char *days[] = {"Ponedjeljak", "Utorak", "Srijeda", "Četvrtak", "Petak", "Subota", "Nedjelja"};
    int n;

    do {
        printf("n:");
        scanf("%d", &n);
        if (n < 0 || n > 7) {
            printf("Krivo uneseni broj za dan!");
        }
    } while (n < 0 || n > 7);

    printf("Izabrani dan je %s\n", *(days + n - 1));

    const char *day = findDayWithMostVowels(days);
    printf("Day with most vowels is: %s\n", day);
    printf("Day printed backwards: ");
    printStringBackward(day);
}