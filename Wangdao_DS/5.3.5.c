#include "binary_tree.h"

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

int get_height(BiTree tree)
{
    if (!tree)
        return 0;
    SeqQueue(Q);
    init_queue(Q);
    BiTNode *p = tree;
    int h = 0;
    int last = 0;
    enQ(Q, p);
    while (!empty(Q))
    {
        int levelSize = (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
        for (int i = 0; i < levelSize; i++)
        {
            deQ(Q, p);
            if (p->left)
                enQ(Q, p->left);
            if (p->right)
                enQ(Q, p->right);
        }
        h++;
    }
    return h;
}

int main()
{
    int L[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    BiTree tree = create_tree(L, 13);
    printf("%d\n", get_height(tree));
    return 0;
}