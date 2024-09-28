#include "binary_tree.h"

void count_leaves(BiTree forest, int *res)
{
    if (forest->left)
        count_leaves(forest->left, res);
    else
        (*res)++;
    if (forest->right)
        count_leaves(forest->right, res);
}

int main()
{
    int L[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    /*
     * child_sibling:
     *            0
     *          /   \
     *         1     2
     *       / \     / \
     *      3   4   5   6
     *     / \ / \
     *     7 8 9 10
     *
     * forest:
     *         0          2       6
     *      /  |  \      /
     *     1   4  10    5
     *    / \  /
     *   3  8 9
     *  /
     * 7
     *
     */
    BiTree forest = create_tree(L, 11);
    int leaves = 0;
    count_leaves(forest, &leaves);
    printf("%d\n", leaves);
    return 0;
}