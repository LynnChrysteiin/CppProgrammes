#include "binary_tree.h"

void find_k_in_pre_order(BiTree root, int k, int &res, int &cnt)
{
    if (!root)
        return;
    if (++cnt == k)
    {
        res = root->data;
        return;
    }
    find_k_in_pre_order(root->left, k, res, cnt);
    find_k_in_pre_order(root->right, k, res, cnt);
}

int main()
{
    int L[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BiTree tree = create_tree(L, 10);
    int k = 5;
    int cnt = 0;
    int res;
    find_k_in_pre_order(tree, k, res, cnt);
    printf("%d\n", res);
    return 0;
}