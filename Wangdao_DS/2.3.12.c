#include "cir_d_link_list.h"

// 这里为方便仍然使用循环双链表头文件

void list_concat(CDLinkList &LA, CDLinkList &LB)
{
    CDLNode *tailA = LA->next;
    CDLNode *tailB = LB->next;

    while (tailA->next != LA)
        tailA = tailA->next;
    while (tailB->next != LB)
        tailB = tailB->next;

    tailA->next = LB->next;
    LB->next->prev = tailA;
    tailB->next = LA;
    LA->prev = tailB;

    LB->next = NULL;
    LB->prev = NULL;
}

int main()
{
    int m = 5;
    int n = 3;
    int A[m] = {1, 2, 3, 4, 5};
    int B[n] = {6, 7, 8};
    CDLinkList LA = create_list(A, m);
    CDLinkList LB = create_list(B, n);
    list_concat(LA, LB);
    print_list(LA);
    return 0;
}