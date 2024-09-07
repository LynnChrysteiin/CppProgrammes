#include "link_list.h"

int find_max_twin_sum(LinkList L, int n)
{
    int sum[n / 2] = {0};
    int cnt = 0;
    LNode *p = L->next;
    while (p)
    {
        if (cnt < n / 2)
            sum[cnt] += p->data;
        else
            sum[n - cnt - 1] += p->data;
        cnt++;
        p = p->next;
    }
    int max = INT_MIN;
    for (int i = 0; i < n / 2; i++)
        if (sum[i] > max)
            max = sum[i];
    return max;
}

int main()
{
    int n = 10;
    int A[n] = {0, 1, 2, 3, 4, 9, 8, 7, 6, 5};
    LinkList L = create_list(A, n);
    printf("%d\n", find_max_twin_sum(L, n));
    return 0;
}