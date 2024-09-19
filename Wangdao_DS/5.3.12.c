#include "binary_tree.h"

void post_order_traverse(BiTree root, BiTNode *node, bool &found, BiTNode *L[], int &n)
{
    if (!root)
        return;
    if (!found)
        post_order_traverse(root->left, node, found, L, n);
    if (!found)
        post_order_traverse(root->right, node, found, L, n);
    if (root == node)
        found = true;
    if (found)
        L[n++] = root;
}

void find_nearest_ancester(BiTree root, BiTNode *p, BiTNode *q, BiTNode *&r)
{
    BiTNode *P[10];
    BiTNode *Q[10];
    bool foundp = false, foundq = false;
    int lenp = 0, lenq = 0;
    post_order_traverse(root, p, foundp, P, lenp);
    post_order_traverse(root, q, foundq, Q, lenq);
    for (int i = lenp - 1, j = lenq - 1; i >= 0, j >= 0; i--, j--)
        if (P[i] != Q[j])
        {
            r = P[i + 1];
            return;
        }
}

int main()
{
    int L[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    /*
     *            1
     *      2            3
     *   4     5      6      7
     *  8 9  10
     */
    BiTree tree = create_tree(L, 10);
    BiTNode *p = NULL;
    BiTNode *q = NULL;
    find_node_by_val(tree, p, 4);
    find_node_by_val(tree, q, 10);
    BiTNode *r = NULL;
    find_nearest_ancester(tree, p, q, r);
    printf("%d\n", r->data);
    return 0;
}