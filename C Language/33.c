#include <stdio.h>
#include <iostream>

void compute(float a, float b, float *pc, float *pd) {
    *pc = a + b;
    *pd = a - b;
}

int main() {
    float a, b, c, d;
    scanf("%f%f", &a, &b);
    compute(a, b, &c, &d);
    printf("%g %g", c, d);
    system("pause");
    return 0;
}