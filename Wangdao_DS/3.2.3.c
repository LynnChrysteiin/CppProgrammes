#include "seq_stack.h"

typedef struct DoubleStackQueue
{
    SeqStack Senq;
    SeqStack Sdeq;
} DoubleStackQueue;

void init_queue(DoubleStackQueue &Q)
{
    init_stack(Q.Senq);
    init_stack(Q.Sdeq);
}

bool empty(DoubleStackQueue Q)
{
    return isEmpty(Q.Senq) && isEmpty(Q.Sdeq);
}

bool enQ(DoubleStackQueue &Q, int x)
{
    if (isOverflow(Q.Senq))
        return false;
    push(Q.Senq, x);
    return true;
}

bool deQ(DoubleStackQueue &Q, int &x)
{
    if (empty(Q))
        return false;
    if (isEmpty(Q.Sdeq))
    {
        int tmp;
        while (!isEmpty(Q.Senq))
        {
            pop(Q.Senq, tmp);
            push(Q.Sdeq, tmp);
        }
    }
    pop(Q.Sdeq, x);
    return true;
}

int main()
{
    DoubleStackQueue Q;
    init_queue(Q);
    for (int i = 1; i <= 5; i++)
        enQ(Q, i);
    int tmp;
    for (int i = 0; i < 3; i++)
    {
        deQ(Q, tmp);
        printf("%d ", tmp);
    }
    printf("\n");
    for (int i = 6; i <= 10; i++)
        enQ(Q, i);
    while (!empty(Q))
    {
        deQ(Q, tmp);
        printf("%d ", tmp);
    }
    printf("\n");
    return 0;
}