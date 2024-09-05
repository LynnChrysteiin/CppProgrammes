#include <stdio.h>

int find_element(int *A, int n)
{
    int cnt[n] = {0};
    for (int i = 0; i < n; i++)
        cnt[A[i]]++;
    for (int i = 0; i < n; i++)
        if (cnt[i] >= n / 2)
            return i;
    return -1;
}

int main()
{
    int n = 8;
    int A[n] = {0, 5, 5, 3, 5, 1, 5, 7};
    int res = find_element(A, n);
    printf("%d\n", res);
    return 0;
}