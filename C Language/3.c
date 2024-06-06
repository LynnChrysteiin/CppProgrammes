#include <stdio.h>

int main()
{
    int h, m, s;
    scanf("%d\n%d\n%d", &h, &m, &s);
    if (h < 10)
        printf("0%d:", h);
    else
        printf("%d:", h);
    if (m < 10)
        printf("0%d:", m);
    else
        printf("%d:", m);
    if (s < 10)
        printf("0%d", s);
    else
        printf("%d", s);
    return 0;
}