#include <stdio.h>
#include <math.h>

int isPrime(int a)
{
    for (int i = 2; i <= sqrt(a); i++)
        if (a % i == 0)
            return 0;
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    int count = 0;
    for (int i = 3; i < n / 2; i++)
        if (isPrime(i) && isPrime(n - i))
            count++;
    printf("%d", count);
    return 0;
}