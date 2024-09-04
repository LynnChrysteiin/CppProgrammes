#include <stdio.h>

void find_or_insert(int *L, int &n, int x)
{
    int left = 0;
    int right = n - 1;
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (L[middle] == x)
            break;
        else if (L[middle] < x)
            left = middle + 1;
        else
            right = middle - 1;
    }
    if (left > right)
    {
        for (int i = n - 1; i > right; i--)
            L[i + 1] = L[i];
        L[right + 1] = x;
        n++;
    }
    else if (L[middle] == x && middle != n - 1)
    {
        int tmp = L[middle];
        L[middle] = L[middle + 1];
        L[middle + 1] = tmp;
    }
}

int main()
{
    int m = 10, n = 10;
    int L1[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int L2[128] = {0, 1, 2, 4, 5, 6, 7, 8, 9, 10};
    find_or_insert(L1, m, 3);
    find_or_insert(L2, n, 3);
    for (int i = 0; i < m; i++)
        printf("%d ", L1[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", L2[i]);
    return 0;
}
