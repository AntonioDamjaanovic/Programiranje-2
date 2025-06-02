#include<stdio.h>
#include<math.h>

typedef struct tocka{
    int x, y, z;
}TOCKA;

typedef struct trokut{
    TOCKA *a, *b, *c;
}TROKUT;

int main() {
    int n, m, i, a, b, c;
    float s1, s2, s3, op, max = 0;
    TOCKA tocke[10];
    TROKUT trokuti[10];
    scanf("%d", &n);
    scanf("%d", &m);
    for(i = 0; i < n; i++){
        scanf("%d %d %d", &tocke[i].x, &tocke[i].y, &tocke[i].z);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        trokuti[i].a = &tocke[a];
        trokuti[i].b = &tocke[b];
        trokuti[i].c = &tocke[c];
    }
    for (i = 0; i < m; i++)
    {
        s1 = sqrt(pow(trokuti[i].a->x - trokuti[i].b->x, 2) + pow(trokuti[i].a->y - trokuti[i].b->y, 2) + pow(trokuti[i].a->z - trokuti[i].b->z, 2));
        s2 = sqrt(pow(trokuti[i].b->x - trokuti[i].c->x, 2) + pow(trokuti[i].b->y - trokuti[i].c->y, 2) + pow(trokuti[i].b->z - trokuti[i].c->z, 2));
        s3 = sqrt(pow(trokuti[i].c->x - trokuti[i].a->x, 2) + pow(trokuti[i].c->y - trokuti[i].a->y, 2) + pow(trokuti[i].c->z - trokuti[i].a->z, 2));
        op = s1 + s2 + s3;

        if (op > max)
            max = op;
    }
    printf("REZULTATI:\n");
    printf("%.2f", max);
    return 0;

}