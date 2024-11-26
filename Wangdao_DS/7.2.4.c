#include <stdio.h>

void binary_search(int *A, int low, int high, int val, int *ans)
{
    if (low > high)
        return;
    int mid = (low + high) / 2;
    if (A[mid] == val)
    {
        *ans = mid;
        return;
    }
    else if (A[mid] > val)
        binary_search(A, low, mid - 1, val, ans);
    else
        binary_search(A, mid + 1, high, val, ans);
}

int main()
{
    int A[10] = {-1, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int val = 15;
    int ans = -1;
    binary_search(A, 1, 10, val, &ans);
    (ans != -1) ? printf("%d 's position is: %d.\n", val, ans) : printf("not found!\n");
    return 0;
}