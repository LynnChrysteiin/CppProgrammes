/*
 * ���������㷨
 * �㷨˼�룺
 * 1. ������������һ��Ԫ�أ���Ϊ����׼����pivot����
 * 2. �����������У����бȻ�׼ֵС��Ԫ�ذڷ��ڻ�׼ǰ�棬���бȻ�׼ֵ���Ԫ�ذڷ��ڻ�׼�ĺ��档
 * 3. �ݹ�ذ�С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵԪ�ص�����������
 */

#include <cstdio>

void quickSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int pivotIndex = [&](int arr[], int left, int right) -> int
    {
        int pivot = arr[left];
        while (left < right)
        {
            while (left < right && arr[right] >= pivot)
                right--;
            arr[left] = arr[right];
            while (left < right && arr[left] <= pivot)
                left++;
            arr[right] = arr[left];
        }
        arr[left] = pivot;
        return left;
    }(arr, left, right);

    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

int main()
{
    int arr[] = {12, 8, 9, 14, 6, 5, 7, 1, 15, 3, 11, 13, 2, 10, 4};
    int n = sizeof(arr) / sizeof(int);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    return 0;
}