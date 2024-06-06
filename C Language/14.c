#include <stdio.h>

int main()
{
    int n, total = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                total += i;
        }
        printf("%d", total);
        total = 0;
    }
    return 0;
}