#include <stdio.h>

int find_middle(int *L1, int *L2, int n)
{
    int cnt = 0;
    int i = 0, j = 0;
    while (true)
    {
        if (L1[i] <= L2[j])
        {
            if (cnt == n - 1)
                return L1[i];
            i++;
            cnt++;
        }
        else
        {
            if (cnt == n - 1)
                return L2[j];
            j++;
            cnt++;
        }
    }
}

int main()
{
    int n = 5;
    int L1[n] = {11, 13, 15, 17, 19};
    int L2[n] = {2, 4, 6, 8, 20};
    int res = find_middle(L1, L2, n);
    printf("%d", res);
    return 0;
}