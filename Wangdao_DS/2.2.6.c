#include <stdio.h>

void merge_list(int *L1, int m, int *L2, int n, int *L)
{
    int i = 0, j = 0;
    for (; i < m && j < n;)
    {
        if (L1[i] <= L2[j])
        {
            L[i + j] = L1[i];
            i++;
        }
        else
        {
            L[i + j] = L2[j];
            j++;
        }
    }
    if (i < m)
        for (; i < m; i++)
            L[i + j] = L1[i];
    if (j < n)
        for (; j < n; j++)
            L[i + j] = L2[j];
}

int main()
{
    int m = 10;
    int n = 5;
    int L1[128] = {1, 4, 5, 6, 8, 9, 10, 13, 14, 15};
    int L2[128] = {2, 3, 7, 11, 12};
    int L[128];
    merge_list(L1, m, L2, n, L);
    for (int i = 0; i < m + n; i++)
        printf("%d ", L[i]);
    return 0;
}