#include "link_list.h"

void split_list(LinkList L, int n, LinkList &A, LinkList &B)
{
    if (!L)
        return;
    LNode *tail = L;
    A = L;
    LNode *p = L->next;
    for (int i = 0; i < 2 * n; i++)
    {
        int val = p->data;
        p = p->next;
        if (i % 2 == 0) // 尾插法建立 A
            add_node_by_tail(tail, val);
        else // 头插法建立 B
            add_node_by_head(B, val);
    }
    L = NULL;
}

int main()
{
    int n = 5;
    int L[2 * n] = {0, 5, 1, 6, 2, 7, 3, 8, 4, 9};
    LinkList C = create_list(L, 2 * n);
    LinkList A;
    init_list(A);
    LinkList B;
    init_list(B);
    print_list(C);
    split_list(C, n, A, B);
    print_list(A);
    print_list(B);
    return 0;
}