#include <stdio.h>
#include <stdlib.h>

void find_elements(int *L1, int *L2, int *L3, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n)
    {
        if (L1[i] == L2[j] && L2[j] == L3[k])
        {
            printf("%d\n", L1[i]);
            i++;
            j++;
            k++;
        }
        int max = __max(L1[i], __max(L2[j], L3[k]));
        if (L1[i] < max)
            i++;
        if (L2[j] < max)
            j++;
        if (L3[k] < max)
            k++;
    }
}

int main()
{
    int n = 5;
    int L1[n] = {0, 1, 2, 3, 4};
    int L2[n] = {2, 3, 4, 5, 6};
    int L3[n] = {-2, -1, 0, 2, 3};
    find_elements(L1, L2, L3, n);
    return 0;
}