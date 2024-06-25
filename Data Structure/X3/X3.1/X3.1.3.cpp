/*
 * ð�������㷨
 * �㷨˼�룺
 * 1. ��ͷ��β���αȽ����ڵ�����Ԫ�أ����ǰһ��Ԫ�ش��ں�һ��Ԫ�أ��򽻻�����Ԫ�ص�λ��
 * 2. �ظ��������̣�ֱ��û��Ԫ����Ҫ����
 */

#include <cstdio>

void bubbleSort(int arr[], int n)
{
    bool flag = true; // ����Ƿ���Ԫ�ؽ��������û��Ԫ�ؽ�����˵�������Ѿ�����
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