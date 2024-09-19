#include "tree_node_queue.h"

int get_width(BiTree root)
{
    SeqQueue Q;
    init_queue(Q);
    int max_width;
    enQ(Q, root);
    BiTNode *p;
    while (!empty(Q))
    {
        int size_q = get_size(Q);
        if (size_q > max_width)
            max_width = size_q;
        for (int i = 0; i < size_q; i++)
        {
            deQ(Q, p);
            if (p->left)
                enQ(Q, p->left);
            if (p->right)
                enQ(Q, p->right);
        }
    }
    return max_width;
}

int main()
{
    int L[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    /*
     *            1
     *      2            3
     *   4     5      6      7
     *  8 9  10 11  12 13  14
     */
    BiTree tree = create_tree(L, 14);
    printf("%d\n", get_width(tree));
    return 0;
}