#include <stdio.h>

void compute(float a, float b, float *pc, float *pd)
{
    *pc = a + b;
    *pd = a - b;
}

int main()
{
    float a, b, c, d;
    scanf("%f%f", &a, &b);
    compute(a, b, &c, &d);
    printf("%g %g", c, d);
    return 0;
}