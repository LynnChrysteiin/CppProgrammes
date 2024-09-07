#include "link_list.h"

bool check_ring(LinkList L)
{
    LNode *fast = L->next;
    LNode *slow = L;
    while (fast != slow && fast && fast->next && slow)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast == slow)
        return true;
    else
        return false;
}

int main()
{
    int n = 10;
    int A[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkList L = create_list(A, n);
    
    // make a ring
    LNode *p = L->next;
    LNode *q = L->next;
    while (p->next)
        p = p->next;
    while (q->data != 5)
        q = q->next;
    p->next = q;
    
    printf(check_ring(L) ? "YES!" : "NO!");
    return 0;
}