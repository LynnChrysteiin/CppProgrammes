#include "link_list.h"

void get_intersection(LinkList &Ldst, LinkList Lsrc)
{
    LNode *pre = Ldst;
    LNode *p = Ldst->next;
    LNode *q = Lsrc->next;
    while (p && q)
    {
        if (p->data > q->data)
            q = q->next;
        else if (p->data < q->data)
        {
            LNode *rear = p->next;
            delete_node(pre);
            p = rear;
        }
        else
        {
            pre = p;
            p = p->next;
            q = q->next;
        }
    }
    while (p)
    {
        LNode *rear = p->next;
        delete_node(pre);
        p = rear;
    }
}

int main()
{
    int m = 10;
    int n = 4;
    int A[m] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int B[n] = {1, 3, 5, 7};
    LinkList LA = create_list(A, m);
    LinkList LB = create_list(B, n);
    get_intersection(LA, LB);
    print_list(LA);
    return 0;
}