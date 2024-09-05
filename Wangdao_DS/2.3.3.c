#include "link_list.h"

void reverse_list(LinkList L)
{
    LNode *prev = L;
    LNode *curr = prev->next;
    LNode *rear = curr->next;
    curr->next = NULL;
    while (rear)
    {
        prev = curr;
        curr = rear;
        rear = rear->next;
        curr->next = prev;
    }
    L->next = curr;
}

int main()
{
    int n = 10;
    int A[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkList L = create_list(A, n);
    print_list(L);
    reverse_list(L);
    print_list(L);
    return 0;
}