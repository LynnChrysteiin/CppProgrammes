#include "binary_tree.h"

void exchange_children(BiTree &root)
{
    if (!root)
        return;

    exchange_children(root->left);
    exchange_children(root->right);
    
    BiTNode *p = root->left;
    root->left = root->right;
    root->right = p;
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
    int L[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BiTree T = create_tree(L, 10);
    exchange_children(T);
    in_order(T);
    return 0;
}