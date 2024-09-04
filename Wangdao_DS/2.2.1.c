#include <stdio.h>
#include <stdlib.h>

#define MAXN 128

typedef struct
{
    int data[MAXN];
    int length;
} SeqList;

void init_list(SeqList L)
{
    L.length = 0;
}

SeqList create_list(int data[], int len)
{
    SeqList L;
    init_list(L);
    for (int i = 0; i < len; i++)
        L.data[i] = data[i];
    L.length = len;
    return L;
}

int pop_small(SeqList &L)
{
    if (L.length == 0)
    {
        printf("Empty list!");
        return 0x7fffffff;
    }
    int index = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < L.data[index])
            index = i;
    }
    int small;
    small = L.data[index];
    L.data[index] = L.data[--L.length];
    return small;
}

int main()
{
    int list[] = {8, 5, 3, 2, 7, 9, 10};
    SeqList L = create_list(list, 7);
    int small = pop_small(L);
    printf("%d\n", small);
    for (int i = 0; i < L.length; i++)
        printf("%d ", L.data[i]);
    return 0;
}
