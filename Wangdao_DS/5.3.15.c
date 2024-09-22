#include "binary_tree.h"

BiTNode *last_leaf = NULL;
BiTNode *head = NULL;

void link_leaf(BiTree root)
{
    if (!root)
        return;
    if (root->left)
        link_leaf(root->left);
    if (root->right)
        link_leaf(root->right);
    if (root->left == NULL && root->right == NULL)
    {
        if (last_leaf == NULL)
        {
            head = root;
            last_leaf = root;
        }
        else
        {
            last_leaf->right = root;
            last_leaf = root;
        }
    }
}

int main()
{
    int L[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    /*
     *           1
     *      2         3
     *   4     5   6     7
     *  8 9  10
     */
    int H[1] = {0};
    BiTree tree = create_tree(L, 10);
    link_leaf(tree);
    BiTNode *p = head;
    printf("HEAD");
    while (p)
    {
        printf("->%d", p->data);
        p = p->right;
    }
    printf("->NULL");
    return 0;
}