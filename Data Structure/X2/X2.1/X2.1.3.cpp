/*
 * 分块查找算法
 */

#include <cstdio>
#include <cstdlib>

typedef int ElemType;
typedef struct BlockList
{
    ElemType *data;
    int length;
    ElemType max;
    ElemType min;
    void init(int max)
    {
        data = (ElemType *)malloc(max * sizeof(ElemType));
        length = max;
    }
    void setData(int *a, int n)
    {
        max = a[0];
        min = a[0];
        for (int i = 0; i < n; i++)
        {
            data[i] = a[i];
            if (a[i] > max)
                max = a[i];
            if (a[i] < min)
                min = a[i];
        }
    }
    void destroy()
    {
        free(data);
    }
} BlockList;

typedef struct IndexList
{
    BlockList *data;
    int length;
    void init(int max)
    {
        data = (BlockList *)malloc(max * sizeof(BlockList));
        length = max;
    }
    void setData(BlockList *a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            data[i] = a[i];
        }
    }
    void destroy()
    {
        free(data);
    }
} IndexList;

int search(IndexList &indexList, ElemType key)
{
    for (int i = 0; i < indexList.length; i++)
    {
        if (key >= indexList.data[i].min && key <= indexList.data[i].max)
        {
            for (int j = 0; j < indexList.data[i].length; j++)
            {
                if (key == indexList.data[i].data[j])
                    return i * indexList.data[i].length + j;
            }
        }
    }
    return -1;
}

int main()
{
    IndexList indexList;
    indexList.init(3);
    BlockList blockList[3];
    blockList[0].init(5);
    blockList[1].init(5);
    blockList[2].init(5);
    int a[5] = {1, 3, 5, 4, 2};
    int b[5] = {8, 7, 10, 9, 6};
    int c[5] = {13, 15, 12, 14, 11};
    blockList[0].setData(a, 5);
    blockList[1].setData(b, 5);
    blockList[2].setData(c, 5);
    indexList.setData(blockList, 3);
    int key;
    scanf("%d", &key);
    int result = search(indexList, key);
    if (result == -1)
        printf("没有找到！\n");
    else
        printf("%d 是第 %d 个元素。\n", key, result + 1);
    return 0;
}