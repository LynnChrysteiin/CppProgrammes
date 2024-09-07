#include "link_list.h"

LNode *find_same_suffix_pos(LinkList LA, LinkList LB)
{
    int lena = 0;
    int lenb = 0;
    LNode *pa = LA->next;
    LNode *pb = LB->next;
    while (pa)
    {
        pa = pa->next;
        lena++;
    }
    while (pb)
    {
        pb = pb->next;
        lenb++;
    }
    pa = LA->next;
    pb = LB->next;
    int offset = lena - lenb;
    if (offset >= 0)
        for (int i = 0; i < offset; i++)
            pa = pa->next;
    else
        for (int i = 0; i < -offset; i++)
            pb = pb->next;
    while (pa->data != pb->data)
    {
        pa = pa->next;
        pb = pb->next;
    }
    return pa;
}

int main()
{
    int m = 10;
    int n = 5;
    int A[m] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int B[n] = {0, 1, 7, 8, 9};
    LinkList LA = create_list(A, m);
    LinkList LB = create_list(B, n);
    LNode *pos = find_same_suffix_pos(LA, LB);
    printf("%d\n", pos->data);
    return 0;
}