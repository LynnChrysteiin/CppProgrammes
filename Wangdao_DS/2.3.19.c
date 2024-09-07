#include "link_list.h"
#include <math.h>

#define n 10

void del_abs_dupli(LinkList L)
{
    bool exist[n] = {false};
    LNode *pre = L;
    LNode *cur = L->next;
    while (cur)
    {
        int val = abs(cur->data);
        if (exist[val] == false)
        {
            exist[val] = true;
            pre = cur;
            cur = cur->next;
        }
        else
        {
            LNode *rear = cur->next;
            pre->next = rear;
            free(cur);
            cur = rear;
        }
    }
}

int main()
{
    int m = 10;
    int A[m] = {0, 1, 2, -3, 3, -1, 2, 2, 1, 4};
    LinkList L = create_list(A, m);
    del_abs_dupli(L);
    print_list(L);
    return 0;
}