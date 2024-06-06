#include <stdio.h>

int main()
{
    double a, b, c, p;
    while (scanf("%lf %lf %lf %lf", &a, &b, &c, &p) != EOF)
        printf("%.2lf", (double)((int)((a + b + c) / 3 * 10 + 0.5)) / 10 * p);
    return 0;
}