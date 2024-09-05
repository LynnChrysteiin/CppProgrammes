#include <stdio.h>

int partition(int *A, int left, int right)
{
    int pivot = A[left];
    while (left < right)
    {
        while (left < right && A[right] >= pivot)
            right--;
        A[left] = A[right];
        while (left < right && A[left] <= pivot)
            left++;
        A[right] = A[left];
    }
    A[left] = pivot;
    return left;
}

void qsort(int *A, int left, int right)
{
    if (left < right)
    {
        int pivotPos = partition(A, left, right);
        qsort(A, left, pivotPos - 1);
        qsort(A, pivotPos + 1, right);
    }
}

int find_miss_min(int *A, int n)
{
    qsort(A, 0, n - 1);
    int x = 1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == x)
            x++;
        else if (A[i] > x)
            return x;
    }
    return x;
}

int main()
{
    int n = 10;
    int A[n] = {0, 2, 1, -1, -2, -3, 4, 3, 5, 7};
    int res = find_miss_min(A, n);
    printf("%d\n", res);
    return 0;
}