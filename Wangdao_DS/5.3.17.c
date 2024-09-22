#include "binary_tree.h"

void get_wpl(BiTree root, int w, int &wpl)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        wpl += root->data * w;
    get_wpl(root->left, w + 1, wpl);
    get_wpl(root->right, w + 1, wpl);
}

int main()
{
    int L[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    /*
     *         1
     *     2       3
     *   4   5   6   7
     *  8 9
     */
    BiTree T = create_tree(L, 9);
    int wpl = 0;
    get_wpl(T, 0, wpl);
    printf("%d\n", wpl);
    return 0;
}