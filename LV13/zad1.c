#include <stdio.h>

enum tjedan { pon = 1, uto, sri, cet, pet, sub, ned};

int main() {
    enum tjedan number;
    do {
        scanf("%d", &number);
        printf("REZULTATI:\n");
    } while (number > 7 || number < 0);

    if (number == sub || number == ned) {
        printf("Vikeeeend!");
    }
    else
        printf("Radis jos %d dana do vikenda.", pet - number);
    return 0;
}

