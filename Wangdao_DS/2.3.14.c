#include "link_list.h"

void rshift(LinkList &L, int x)
{
    LNode *p = L->next;
    LNode *r = L;
    for (int i = 0; i < x; i++)
    {
        p = p->next;
        r = r->next;
    }
    LNode *q = L->next;
    L->next = p;
    while(p->next)
        p = p->next;
    p->next = q;
    r->next = NULL;
}

int main()
{
    int n = 10;
    int A[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkList L = create_list(A, n);
    rshift(L, 3);
    print_list(L);
    return 0;
}