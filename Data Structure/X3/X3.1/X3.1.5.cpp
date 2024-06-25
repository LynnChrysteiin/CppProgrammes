/*
 * ��ѡ������
 * �㷨˼�룺
 * 1. �Ӵ������������ҵ���С��Ԫ�أ����������еĵ�һ��Ԫ�ؽ���
 * 2. ��ʣ�µ�Ԫ�����ҵ���С��Ԫ�أ����������еĵڶ���Ԫ�ؽ���
 * 3. �ظ��������̣�ֱ��������������
 */

#include <cstdio>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main()
{
    int arr[] = {12, 8, 9, 14, 6, 5, 7, 1, 15, 3, 11, 13, 2, 10, 4};
    int n = sizeof(arr) / sizeof(int);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    selectionSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    return 0;
}