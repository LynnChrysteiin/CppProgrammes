#include <stdio.h>

void get_post_by_pre(int *pre, int *post, int lpre, int rpre, int lpost, int rpost)
{
    // 递归边界条件
    if (lpre > rpre)
        return;

    // 将先序序列第一个节点(根节点)放到后序序列的最后一个位置, 即N LR -> LR N
    post[rpost] = pre[lpre];

    // 递归地对左右子树作相同操作
    get_post_by_pre(pre, post, lpre + 1, (lpre + rpre) / 2, lpost, (lpost + rpost) / 2 - 1);
    get_post_by_pre(pre, post, (lpre + rpre) / 2 + 1, rpre, (lpost + rpost) / 2, rpost - 1);
}

int main()
{
    int pre[15] = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
    int post[15] = {0}; // {8, 9, 4, 10, 11, 5, 2, 12, 13, 6, 14, 15, 7, 3, 1};
    get_post_by_pre(pre, post, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
        printf("%d ", post[i]);
    return 0;
}