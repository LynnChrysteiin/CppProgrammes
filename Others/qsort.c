#include <stdio.h>

int partition(int array[],int left, int right)
{
    int pivot = array[left];
    while (left < right)
    {
        while (left < right && pivot <= array[right])
            right--;
        array[left] = array[right];
        while (left < right && array[left] <= pivot)
            left++;
        array[right] = array[left];
    }
    array[left] = pivot;
    return left;
}

void qsort(int array[], int left, int right)
{
    if (left > right)
        return;
    int pivot_pos = partition(array, left, right);
    qsort(array, left, pivot_pos - 1);
    qsort(array, pivot_pos + 1, right);
}

int main()
{
    int array[10] = {1, 4, 7, 6, 9, 0, 3, 2, 8, 5};
    qsort(array, 0, 9);
    for (int i = 0 ; i < 10; i++)
        printf("%d ", array[i]);
    return 0;
}