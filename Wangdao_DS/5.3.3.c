#include "binary_tree.h"

#define MAXN 32

typedef struct NodeStack
{
    BiTNode *node[MAXN];
    int size;
} NodeStack;

void init_stack(NodeStack &stack)
{
    stack.size = 0;
}

bool empty(NodeStack stack)
{
    return stack.size == 0;
}

void push(NodeStack &stack, BiTNode *node)
{
    stack.node[stack.size++] = node;
}

void pop(NodeStack &stack, BiTNode *&node)
{
    node = stack.node[--stack.size];
}

void top(NodeStack &stack, BiTNode *&node)
{
    node = stack.node[stack.size - 1];
}

void post_order_no_recursion(BiTree tree)
{
    NodeStack S;
    init_stack(S);
    BiTNode *p = tree, *r = NULL;
    while (p || !empty(S))
    {
        if (p)
        {
            push(S, p);
            p = p->left;
        }
        else
        {
            top(S, p);
            if (p->right && p->right != r)
                p = p->right;
            else
            {
                pop(S, p);
                printf("%d ", p->data);
                r = p;
                p = NULL;
            }
        }
    }
}

int main()
{
    ElemType data[] = {1, 2, 3, 4, 5, 6, 7};
    /*
     *     1
     *    / \
     *   2   3
     *  / \ / \
     * 4  5 6  7
     * 
     */
    BiTree tree = create_tree(data, 7);
    post_order_no_recursion(tree);
    return 0;
}