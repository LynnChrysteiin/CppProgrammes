#include <stdio.h>

void reverse_list(int *P, int l, int r)
{
    for (; l < r; l++, r--)
    {
        int tmp = P[l];
        P[l] = P[r];
        P[r] = tmp;
    }
}

void left_shift(int *P, int n, int p)
{
    reverse_list(P, 0, n - 1);
    reverse_list(P, 0, n - p - 1);
    reverse_list(P, n - p, n - 1);
}

int main()
{
    int n = 10;
    int P[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    left_shift(P, n, 6);
    for (int i = 0; i < n; i++)
        printf("%d ", P[i]);
    return 0;
}