#include "binary_tree.h"
#include "seq_stack.h"

#define MAXSIZE 32

typedef struct SeqQueue
{
    BiTNode *data[MAXSIZE];
    int front; // 0 ~ MAXSIZE-1
    int rear;  // 0 ~ MAXSIZE-1
    bool tag;  // 0: empty | 1: full
} SeqQueue;

void init_queue(SeqQueue &Q)
{
    Q.front = 0;
    Q.rear = 0;
    Q.tag = 0;
}

bool empty(SeqQueue Q)
{
    return (Q.front == Q.rear && Q.tag == 0);
}

bool full(SeqQueue Q)
{
    return (Q.front == Q.rear && Q.tag == 1);
}

bool enQ(SeqQueue &Q, BiTNode *x)
{
    if (full(Q))
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    Q.tag = 1;
    return true;
}

bool deQ(SeqQueue &Q, BiTNode *&x)
{
    if (empty(Q))
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    Q.tag = 0;
    return true;
}

void invert_level_order(BiTree tree)
{
    if (!tree)
        return;
    SeqStack S;
    SeqQueue(Q);
    init_stack(S);
    init_queue(Q);
    BiTNode *p = tree;
    enQ(Q, p);
    while (!empty(Q))
    {
        deQ(Q, p);
        push(S, p->data);
        if (p->left)
            enQ(Q, p->left);
        if (p->right)
            enQ(Q, p->right);
    }
    int x;
    while (!isEmpty(S))
    {
        pop(S, x);
        printf("%d ", x);
    }
}

int main()
{
    int L[7] = {1, 2, 3, 4, 5, 6, 7};
    BiTree tree = create_tree(L, 7);
    invert_level_order(tree);
    return 0;
}