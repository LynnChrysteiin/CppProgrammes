#include "cir_d_link_list.h"

bool check_symmetry(CDLinkList L)
{
    CDLNode *p = L->prev;
    CDLNode *q = L->next;
    while (p != q && p->prev != q)
    {
        if (p->data == q->data)
        {
            p = p->prev;
            q = q->next;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    int n = 10;
    int A[n] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    CDLinkList L = create_list(A, n);
    printf(check_symmetry(L) ? "YES!" : "NO!");
    return 0;
}