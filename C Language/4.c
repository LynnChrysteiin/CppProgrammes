#include <stdio.h>

int main()
{
    double a, b;
    while (scanf("%lf %lf", &a, &b) != EOF)
        printf("%.4lf", a + b);
    return 0;
}