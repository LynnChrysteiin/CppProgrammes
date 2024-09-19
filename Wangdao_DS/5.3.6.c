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

bool judge_comp_bitree(BiTree tree)
{
    SeqQueue Q;
    init_queue(Q);
    BiTNode *p = NULL;
    enQ(Q, tree);
    while (!empty(Q))
    {
        deQ(Q, p);
        if (p)
        {
            enQ(Q, p->left);
            enQ(Q, p->right);
        }
        else
        {
            while (!empty(Q))
            {
                deQ(Q, p);
                if (p)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int L[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BiTree tree = create_tree(L, 10);
    printf(judge_comp_bitree(tree) ? "True!" : "False!");
    return 0;
}