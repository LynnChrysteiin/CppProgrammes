#include <stdio.h>

int main()
{
    double a;
    while (scanf("%lf", &a) != EOF)
        printf("%lf", a * a);
    return 0;
}