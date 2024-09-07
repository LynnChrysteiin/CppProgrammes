#include "link_list.h"

bool find_k_elem_from_last(LinkList L, int k)
{
    LNode *fast = L->next;
    LNode *slow = L->next;
    for (int i = 0; i < k ; i++)
    {
        if (fast->next)
            fast = fast->next;
        else
            return false;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    printf("The No.%d element from last is %d.\n", k, slow->data);
    return 1;
}

int main()
{
    int n = 10;
    int A[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkList L = create_list(A, n);
    bool res = find_k_elem_from_last(L, 7);
    printf(res ? "FOUND!" : "NOt FOUND!");
    return 0;
}