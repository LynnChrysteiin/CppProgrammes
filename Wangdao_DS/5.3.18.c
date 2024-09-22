#include "binary_tree.h"

void print_in_expr(BiTree root, bool flag = true)
{
    if (root->left)
    {
        if (!flag)
            printf("(");
        print_in_expr(root->left, false);
    }
    printf("%c", root->data);
    if (root->right)
    {
        print_in_expr(root->right, false);
        if (!flag)
            printf(")");
    }
}

int main()
{
    int E[9] = {'/', '*', '-', '-', 'c', 'd', 'e', 'a', 'b'};
    /*
     *          /
     *      *       -
     *    -   c   d   e
     *   a b
     */
    BiTree exprT = create_tree(E, 9);
    print_in_expr(exprT);
    return 0;
}