#include <stdio.h>

int main()
{
    double a, b;
    while (scanf("%lf %lf", &a, &b) != EOF)
        printf("%.2lf", (double)((int)(a / b * 10 + 0.5)) / 10);
    return 0;
}