#include "binary_tree.h"

void destroy_tree(BiTree &root)
{
    if (!root)
        return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
    root = NULL;
}

void check_val(BiTree &root, int x)
{
    if (!root)
        return;
    if (root->data == x)
        destroy_tree(root);
    else
    {
        check_val(root->left, x);
        check_val(root->right, x);
    }
}

void in_order(BiTree root)
{
    if (!root)
        return;
    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

int main()
{
    int L[15] = {1, 2, 0, 0, 5, 6, 7, 8, 9, 10, 0, 12, 13, 14, 15};
    /*
     *             1
     *      2            0
     *   0     5      6      7
     *  8 9  10  0  12 13  14 15
     */
    BiTree tree = create_tree(L, 15);
    check_val(tree, 0);
    in_order(tree);
    return 0;
}