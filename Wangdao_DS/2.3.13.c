#include "d_link_list.h"

DLNode *locate(DLinkList L, int x)
{
    DLNode *p = L->next;
    while (p->next != NULL && p->data != x)
        p = p->next;
    if (p->next == NULL)
        return NULL;
    p->freq++;
    if (p->prev == L || p->prev->freq > p->freq)
        return p;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    DLNode *q = p->prev;
    while (q->freq <= p->freq && q != L)
        q = q->prev;
    p->next = q->next;
    p->next->prev = p;
    q->next = p;
    p->prev = q;
    return p;
}

int main()
{
    int n = 10;
    int A[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    DLinkList H;
    DLinkList T;
    create_list(H, T, A, n);
    for (int i = 0; i < 4; i++)
        locate(H, i);
    locate(H, 2);
    locate(H, 3);
    print_list(H, T);
    return 0;
}