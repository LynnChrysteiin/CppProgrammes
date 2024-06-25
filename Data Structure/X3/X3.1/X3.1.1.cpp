/*
 * ���������㷨
 * �㷨˼�룺
 * �������Ϊ�����֣�ǰһ����Ϊ�����򲿷֣���һ����Ϊδ���򲿷֣�ÿ�δ�δ���򲿷���ȡ��һ��Ԫ�ز��뵽�����򲿷��еĺ���λ�á�
 */

#include <cstdio>
#include <functional>

void insertSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}

template <class ElemType>
void insertSort(ElemType arr[], int n, std::function<bool(ElemType, ElemType)> cmp)
{
    int i, j;
    ElemType temp;
    for (i = 1; i < n; i++)
    {
        if (cmp(arr[i], arr[i - 1]))
        {
            temp = arr[i];
            for (j = i - 1; j >= 0 && cmp(temp, arr[j]); j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
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

    insertSort(arr, n);

    printf("\n\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    insertSort<int>(arr, n, [](int a, int b) -> bool
               { return a > b; });

    printf("\n\nReverse sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\n");

    return 0;
}