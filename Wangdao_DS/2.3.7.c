#include "link_list.h"

void delete_duplication(LinkList L)
{
    if (!L)
        return;
    LNode *pre = L;
    LNode *cur = L->next;
    while (cur)
    {
        if (pre->data == cur->data)
        {
            LNode *rear = cur->next;
            delete_node(pre);
            cur = rear;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
}

int main()
{
    int n = 10;
    int A[n] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 5};
    LinkList L = create_list(A, n);
    print_list(L);
    delete_duplication(L);
    print_list(L);
    return 0;
}