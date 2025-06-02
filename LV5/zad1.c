#include <stdio.h>
#include <math.h>

typedef struct {
    float x, y, z;
} Tocka;

typedef struct {
    Tocka *t1, *t2, *t3;
} Trokut;

void unesiTocke(Tocka*, int);
void unesiTrokute(Trokut*, Tocka*, int);
float pronadjiNajveciOpseg(Trokut*, int);

int main() {
    int n, m;
    Tocka tocke[100];
    Trokut trokuti[100];
    float opseg;

    printf("n:");
    scanf("%d", &n);
    printf("m:");
    scanf("%d", &m);

    unesiTocke(tocke, n);
    unesiTrokute(trokuti, tocke, m);

    opseg = pronadjiNajveciOpseg(trokuti, m);

    printf("REZULTATI:\n");
    printf("%.2f", opseg);
    return 0;
}

void unesiTocke(Tocka *t, int n){
    for (int i = 0; i < n; i++){
        scanf("%f %f %f", &t[i].x, &t[i].y, &t[i].z);
    }
}

void unesiTrokute(Trokut *tr,Tocka *t, int m) {
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        tr[i].t1 = &t[a];
        tr[i].t2 = &t[b];
        tr[i].t3 = &t[c];
    }
}

float pronadjiNajveciOpseg(Trokut *t, int m){
    float a, b, c, op, max = 0;

    for (int i = 0; i < m; i++){
        a = sqrt(pow(t[i].t1->x - t[i].t2->x,2) + pow(t[i].t1->y - t[i].t2->y,2) + pow(t[i].t1->z - t[i].t2->z,2));
        b = sqrt(pow(t[i].t2->x - t[i].t3->x,2) + pow(t[i].t2->y - t[i].t3->y,2) + pow(t[i].t2->z - t[i].t3->z,2));
        c = sqrt(pow(t[i].t3->x - t[i].t1->x,2) + pow(t[i].t3->y - t[i].t1->y,2) + pow(t[i].t3->z - t[i].t1->z,2));

        op = a + b +c;
        if (op > max)
            max = op;
    }
    return max;
}
