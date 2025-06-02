#include <stdio.h>
#include <string.h>

void obrnutiString(FILE *f, char *str, int index, int n) {
    if (index < n) {
        obrnutiString(f, str, index + 1, n);
        printf("%c", str[index]);
        fprintf(f, "%c", str[index]);
    }
}

int main() {
    char str[100];
    printf("Unesite string:");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = 0;

    FILE *file = fopen("string.txt", "w");
    if (file == NULL) {
        printf("Greska pri otvaranju datoteke!\n");
        return 1;
    }

    printf("Obrnuti string je upisan u datoteku string.txt i ispisuje se na standardni izlaz:\n");
    obrnutiString(file, str, 0, strlen(str));

    fclose(file);
    return 0;
}