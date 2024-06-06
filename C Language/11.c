#include <stdio.h>

int main()
{
    unsigned int p;
    while (scanf("%d", &p) != EOF)
        if ((0 <= p) && (p <= 180))
            printf("%.2lf", (double)0.4913 * p);
        else if ((180 < p) && (p <= 280))
            printf("%.2lf", 180 * 0.4913 + (double)(p - 180) * 0.5913);
        else
            printf("%.2lf", 180 * 0.4913 + 100 * 0.5913 + (double)(p - 280) * 0.7913);
    return 0;
}