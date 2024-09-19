#ifndef _TREE_NODE_QUEUE_H_
#define _TREE_NODE_QUEUE_H_

#include "binary_tree.h"

#define MAXSIZE 32

typedef struct SeqQueue
{
    BiTNode *data[MAXSIZE];
    int front; // 0 ~ MAXSIZE-1
    int rear;  // 0 ~ MAXSIZE-1
    bool tag;  // 0: empty | 1: full
    int size;
} SeqQueue;

void init_queue(SeqQueue &Q)
{
    Q.front = 0;
    Q.rear = 0;
    Q.tag = 0;
    Q.size = 0;
}

bool empty(SeqQueue Q)
{
    return (Q.front == Q.rear && Q.tag == 0);
}

bool full(SeqQueue Q)
{
    return (Q.front == Q.rear && Q.tag == 1);
}

int get_size(SeqQueue &Q)
{
    Q.size = (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
    return Q.size;
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

#endif // !_TREE_NODE_QUEUE_H_