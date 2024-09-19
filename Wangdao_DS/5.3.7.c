#include "binary_tree.h"

int double_son_nodes(BiTree root)
{
    if (!root)
        return 0;
    if (root->left && root->right)
        return double_son_nodes(root->left) + double_son_nodes(root->right) + 1;
    return double_son_nodes(root->left) + double_son_nodes(root->right);
}

int main()
{
    int L[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BiTree tree = create_tree(L, 10);
    printf("%d\n", double_son_nodes(tree));
    return 0;
}