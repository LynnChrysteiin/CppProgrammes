#include <stdio.h>

bool delete_element(int *L, int &n, int s, int t)
{
    if (n == 0 || s >= t)
        return false;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (L[i] >= s && L[i] <= t)
            cnt++;
        else
            L[i - cnt] = L[i];
    }
    n -= cnt;
    return true;
}

int main()
{
    int n = 10;
    int L[128] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (!delete_element(L, n, 3, 7))
    {
        printf("Error!");
        return 0;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", L[i]);
    return 0;
}