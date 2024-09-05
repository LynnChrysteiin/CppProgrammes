#include "link_list.h"

void delete_node_by_val(LinkList L, int x)
{
    if (L->next == NULL)
        return;
    LNode *cur = L->next;
    LNode *pre = L;
    while (cur)
    {
        if (cur->data == x)
        {
            pre->next = cur->next;
            cur->next = NULL;
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
    int L[n] = {1, 2, 3, 1, 4, 5, 1, 6, 7, 1};
    LinkList list = create_list(L, n);
    print_list(list);
    delete_node_by_val(list, 1);
    print_list(list);
    return 0;
}