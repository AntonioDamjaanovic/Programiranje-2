#include <stdio.h>

struct cpl {
    float re;
    float im;
};

int main(void) {
    struct cpl a, b, c, d;

    printf("Unesi prvi kompleksni broj:\n");
    scanf("%f %f", &a.re, &a.im);
    printf("Unesi drugi kompleksni broj:\n");
    scanf("%f %f", &b.re, &b.im);

    c.re = a.re + b.re;
    c.im = a.im + b.im;

    d.re = a.re - b.re;
    d.im = a.im - b.im;

    printf("REZULTATI:\n");
    printf("%.3f, %.3f*i\n", c.re, c.im);
    printf("%.3f, %.3f*i\n", d.re, d.im);
}