#include <stdio.h>

void reverse_list(int *L, int l, int r)
{
    for (;l < r; l++, r--)
    {
        int tmp = L[l];
        L[l] = L[r];
        L[r] = tmp;
    }
}

void swap_list(int *L, int m, int n)
{
    reverse_list(L, 0, m + n);
    reverse_list(L, 0, n);
    reverse_list(L, n, m + n);
}

int main()
{
    int m = 3;
    int n = 5;
    int L[m + n] = {1, 2, 3, 4, 5, 6, 7, 8};
    swap_list(L, m, n);
    for (int i = 0; i < m + n; i++)
        printf("%d ", L[i]);
    return 0;
}