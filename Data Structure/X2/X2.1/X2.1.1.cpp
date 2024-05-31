/*
 * ˳������㷨
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
        data = (ElemType *)malloc((max + 1) * sizeof(ElemType));
        length = max;
    }
    void destroy()
    {
        free(data);
    }
} SeqList;

int seqSearch(SeqList L, ElemType key)
{
    L.data[0] = key;
    int i = L.length;
    for (i; L.data[i] != key; i--)
        ;
    return i;
}

int main()
{
    SeqList L;
    L.init(8);
    int a[8] = {5, 1, 2, 6, 8, 3, 9, 0};
    for (int i = 0; i < 8; i++)
        L.data[i + 1] = a[i]; // ��1��ʼ�洢
    int key;
    scanf("%d", &key);
    int res = seqSearch(L, key);
    if (res)
        printf("%d �ǵ� %d ��Ԫ�ء�\n", key, res);
    else
        printf("û���ҵ�!\n");
    L.destroy();
    return 0;
}