#include <stdio.h>

void find_or_insert(int *L, int n, int x)
{
}

int main()
{
    int m = 10, n = 10;
    int L1[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int L2[128] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    find_or_insert(L1, m, 5);
    find_or_insert(L2, n, 5);
    for (int i = 0; i < m; i++)
        printf("%d ", L1[i]);
    for (int i = 0; i < n; i++)
        printf("%d ", L2[i]);
    return 0;
}