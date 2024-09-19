#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct BiTNode
{
    ElemType data;
    BiTNode *left;
    BiTNode *right;
} BiTNode;

typedef BiTNode *BiTree;

void init_node(BiTree &tree)
{
    tree->left = NULL;
    tree->right = NULL;
}

BiTree create_tree(ElemType *data, int n) // create a tree by level order
{
    BiTree tree = (BiTree)malloc(sizeof(BiTNode));
    tree->data = data[0];
    init_node(tree);
    BiTree queue[n];
    int front = 0, rear = 0;
    queue[rear++] = tree;
    for (int i = 1; i < n; i++)
    {
        BiTree node = (BiTree)malloc(sizeof(BiTNode));
        node->data = data[i];
        init_node(node);
        if (queue[front]->left == NULL)
            queue[front]->left = node;
        else
            queue[front]->right = node;
        queue[rear++] = node;
        if (queue[front]->left != NULL && queue[front]->right != NULL)
            front++;
    }
    return tree;
}

void find_node_by_val(BiTree root, BiTNode *&p, int val)
{
    if (!root)
        return;
    if (root->data == val)
    {
        p = root;
        return;
    }
    find_node_by_val(root->left, p, val);
    find_node_by_val(root->right, p, val);
}

#endif // !_BINARY_TREE_H_