#include <stdio.h>

#define MAXN 128

void invert_list(int *A, int len)
{
    for (int l = 0, r = len - 1; l < r; l++, r--)
    {
        int temp = A[l];
        A[l] = A[r];
        A[r] = temp;
    }
}

int main()
{
    int A[MAXN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = 10;
    invert_list(A, len);
    for (int i = 0; i < len; i++)
        printf("%d ", A[i]);
    return 0;
}
