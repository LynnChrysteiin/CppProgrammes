#include <stdio.h>

void delete_element(int *L, int &n, int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (L[i] == x)
            cnt++;
        else
            L[i- cnt] = L[i];
    }
    n -= cnt;
}

int main()
{
    int L[128] = {0, 1, 3, 4, 5, 3, 6, 7, 3, 5, 8, 3};
    int n = 12;
    delete_element(L, n, 3);
    for (int i = 0; i < n; i++)
        printf("%d ", L[i]);
    return 0;
}
