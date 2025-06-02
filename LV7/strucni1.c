#include "studenti.h"
#include "studenti.c"

int main() {
    const char* putanjaDoBrojaStudenata = "C:\\Users\\Antonio\\Desktop\\Demos\\Prog 2 Labosi\\LV7\\dat.txt";
    const char* putanjaDoStudenata = "studenti.txt";
    int brojStudenata = procitajBrojStudenata(putanjaDoBrojaStudenata);
    unesiStudente(brojStudenata, putanjaDoStudenata);
    return 0;
}