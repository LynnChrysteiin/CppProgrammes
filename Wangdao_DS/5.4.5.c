#include "binary_tree.h"

typedef BiTree CSTree;

int get_depth(CSTree root)
{
    int hc, hs;
    if (root == NULL)
        return 0;
    else
    {
        hc = get_depth(root->left);
        hs = get_depth(root->right);
        if (hc + 1 > hs)
            return hc + 1;
        else
            return hs;
    }
}

int main()
{
    int L[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    CSTree tree = create_tree(L, 11);
    int depth = get_depth(tree);
    printf("%d\n", depth);
    return 0;
}