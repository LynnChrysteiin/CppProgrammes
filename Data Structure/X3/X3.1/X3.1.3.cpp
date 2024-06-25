/*
 * 冒泡排序算法
 * 算法思想：
 * 1. 从头到尾依次比较相邻的两个元素，如果前一个元素大于后一个元素，则交换两个元素的位置
 * 2. 重复上述过程，直至没有元素需要交换
 */

#include <cstdio>

void bubbleSort(int arr[], int n)
{
    bool flag = true; // 标记是否有元素交换，如果没有元素交换则说明数组已经有序
    for (int i = 0; i < n && flag; i++)
    {
        flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            int temp;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }
    }
}

int main()
{
    int arr[] = {12, 8, 9, 14, 6, 5, 7, 1, 15, 3, 11, 13, 2, 10, 4};
    int n = sizeof(arr) / sizeof(int);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    return 0;
}