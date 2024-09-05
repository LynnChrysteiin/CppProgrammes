#include "link_list.h"

void delete_node_between(LinkList L, int a, int b)
{
    if (!L)
        return;
    LNode *pre = L;
    LNode *cur = L->next;
    while (cur)
    {
        if (cur->data > a && cur->data < b)
        {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
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
    int A[10] = {1, 4, 3, 6, 2, 7, 0, 9, 8, 5};
    LinkList L = create_list(A, n);
    print_list(L);
    delete_node_between(L, 3, 7);
    print_list(L);
    return 0;
}