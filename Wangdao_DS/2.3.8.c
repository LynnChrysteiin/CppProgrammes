#include "link_list.h"

LinkList create_list_with_same_elements(LinkList LA, LinkList LB)
{
    LinkList LC;
    init_list(LC);
    if (!LA || !LB)
        return LC;
    LNode *pa = LA->next;
    LNode *pb = LB->next;
    LNode *tail = LC;
    while (pa && pb)
    {
        if (pa->data > pb->data)
            pb = pb->next;
        else if (pa->data < pb->data)
            pa = pa->next;
        else
        {
            add_node_by_tail(tail, pa->data);
            pa = pa->next;
            pb = pb->next;
        }
    }
    return LC;
}

int main()
{
    int m = 8;
    int n = 5;
    int A[m] = {1, 2, 3, 4, 5, 6, 7, 8};
    int B[n] = {1, 3, 5, 7, 9};
    LinkList LA = create_list(A, m);
    LinkList LB = create_list(B, n);
    LinkList LC = create_list_with_same_elements(LA, LB);
    print_list(LC);
    return 0;
}