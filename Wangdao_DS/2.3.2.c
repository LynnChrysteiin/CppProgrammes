#include "link_list.h"

void delete_min(LinkList L)
{
    if (!L)
        return;
    LNode *minpre = NULL;
    LNode *pre = L;
    LNode *cur = L->next;
    int min = 0x7fffffff;
    while (cur)
    {
        if (cur->data < min)
        {
            min = cur->data;
            minpre = pre;
        }
        pre = cur;
        cur = cur->next;
    }
    cur = minpre->next;
    minpre->next = cur->next;
    cur->next = NULL;
    free(cur);
    cur = NULL;
}

int main()
{
    int n = 10;
    int A[n] = {1, 2, 3, 4, 5, 0, 6, 7, 8, 9};
    LinkList L = create_list(A, n);
    print_list(L);
    delete_min(L);
    print_list(L);
    return 0;
}