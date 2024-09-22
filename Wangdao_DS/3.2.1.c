#include <stdio.h>

#define MAXSIZE 16

typedef struct SeqQueue
{
    int data[MAXSIZE];
    int front;      // 0 ~ MAXSIZE-1
    int rear;       // 0 ~ MAXSIZE-1
    bool tag;       // 0: empty | 1: full
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

bool enQ(SeqQueue &Q, int x)
{
    if (full(Q))
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    Q.tag = 1;
    return true;
}

bool deQ(SeqQueue &Q, int &x)
{
    if (empty(Q))
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    Q.tag = 0;
    return true;
}

int main()
{
    SeqQueue Q;
    init_queue(Q);
    for (int i = 0; i < 20; i++)
        enQ(Q, i);
    int tmp;
    for (int i = 0; i < MAXSIZE; i++)
    {
        deQ(Q, tmp);
        printf("%d ", tmp);
    }
    return 0;
}