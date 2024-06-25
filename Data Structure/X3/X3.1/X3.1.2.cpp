/*
 * ϣ�������㷨
 * �㷨˼�룺
 * �Ƚ����������зָ���������� a[i], a[i+d], a[i+2d], a[i+3d], ... �������У��ֱ����ֱ�Ӳ�������
 * ��С���� d ���ظ��������̣�ֱ�� d=1 ��
 */

#include <cstdio>

// Ԫ�ش��±� 1 ��ʼ�洢
void shellSort(int arr[], int n)
{
    int d, i, j;
    for (d = n / 2; d >= 1; d /= 2)
    {
        for (i = d + 1; i <= n; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                arr[0] = arr[i];
                for (j = i - d; j > 0 && arr[0] < arr[j]; j -= d)
                {
                    arr[j + d] = arr[j];
                }
                arr[j + d] = arr[0];
            }
        }
    }
}

int main()
{
    int arr[] = {0, 12, 8, 9, 14, 6, 5, 7, 1, 15, 3, 11, 13, 2, 10, 4};
    int n = sizeof(arr) / sizeof(int) - 1;

    printf("Original array:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    shellSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    return 0;
}