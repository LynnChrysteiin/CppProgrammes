#include <stdio.h>

void delete_duplication(int *L, int &n)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (L[i] == L[i - 1])
            cnt++;
        L[i - cnt] = L[i];
    }
    n -= cnt;
}

int main()
{
    int n = 20;
    int L[128] = {0, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6};
    delete_duplication(L, n);
    for (int i = 0; i < n; i++)
        printf("%d ", L[i]);
    return 0;
}
