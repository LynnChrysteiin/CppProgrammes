#include "binary_tree.h"

void print_ancestor_by_val(BiTree root, int x, bool &found)
{
    if (!root)
        return;
    if (!found)
        print_ancestor_by_val(root->left, x, found);
    if (!found)
        print_ancestor_by_val(root->right, x, found);
    if (found)
        printf("%d ", root->data);
    if (root->data == x)
        found = true;
}

int main()
{
    int L[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    /*
     *            1
     *      2          3
     *   4     5     6    7
     *  8 9  10
     */
    BiTree tree = create_tree(L, 10);
    bool found = false;
    print_ancestor_by_val(tree, 8, found);
    return 0;
}