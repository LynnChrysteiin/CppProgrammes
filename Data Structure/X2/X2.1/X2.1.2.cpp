/*
 * ���֣��۰룩�����㷨
 */

#include <cstdio>
#include <cstdlib>

typedef int ElemType;
typedef struct SeqList
{
    ElemType *data;
    int length;
    void init(int max)
    {
        data = (ElemType *)malloc(max * sizeof(ElemType));
        length = max;
    }
    void destroy()
    {
        free(data);
    }
} SeqList;

bool biSearch(SeqList L, ElemType key, int &result)
{
    int left = 0, right = L.length - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (L.data[middle] == key)
        {
            result = middle;
            return true;
        }
        else if (L.data[middle] < key)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return false;
}

int main()
{
    SeqList L;
    L.init(8);
    int a[8] = {1, 2, 3, 7, 8, 10, 17, 25};
    for (int i = 0; i < 8; i++)
        L.data[i] = a[i];
    int key;
    scanf("%d", &key);
    int res = 0;
    if (biSearch(L, key, res))
        printf("%d �ǵ� %d ��Ԫ�ء�\n", key, res + 1);
    else
        printf("û���ҵ�!\n");
    L.destroy();
    return 0;
}