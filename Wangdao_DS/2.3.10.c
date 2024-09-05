#include "link_list.h"

bool check_seq_sub(LinkList LA, LinkList LB)
{
    LNode *p = LA->next;
    LNode *q = LB->next;
    while (p && p->data != q->data)
        p = p->next;
    if (!p)
        return false;
    while (p && q)
    {
        if (p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    int m = 5;
    int n = 3;
    int A[m] = {1, 2, 3, 4, 5};
    int B[n] = {2, 3, 4};
    LinkList LA = create_list(A, m);
    LinkList LB = create_list(B, n);
    bool res = check_seq_sub(LA, LB);
    printf(res ? "YES!" : "NO!");
    return 0;
}