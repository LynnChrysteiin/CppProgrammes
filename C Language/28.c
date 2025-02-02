#include <stdio.h>

int fac(int a)
{
    int res = 1;
    for (int i = 1; i <= a; i++)
        res *= i;
    return res;
}

int comb(int n, int m)
{
    return fac(n) / fac(m) / fac(n - m);
}

int main()
{
    int n, m, c;
    scanf("%d%d", &n, &m);
    c = comb(n, m);
    printf("%d", c);
    return 0;
}