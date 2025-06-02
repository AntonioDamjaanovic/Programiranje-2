#include<stdio.h>

int main(){
    char *mjeseci[] = {"sijecanj", "veljaca", "ozujak", "travanj", "svibanj", "lipanj", "srpanj", "kolovoz", "rujan", "listopad", "studeni", "prosinac"};
    int mjesec;
    scanf("%d", &mjesec);

    if (mjesec > 12 || mjesec < 1){
        printf("REZULTATI:\n");
        printf("Nekorektan broj mjeseca");
    } else {
        printf("REZULTATI:\n");
        printf("%s", *(mjeseci + mjesec - 1));
    }
    return 0;
}
