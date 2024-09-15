#include "seq_queue.h"
#include "seq_stack.h"

void reverse_queue(SeqQueue &Q)
{
    SeqStack S;
    init_stack(S);
    int tmp;
    while (!empty(Q))
    {
        deQ(Q, tmp);
        push(S, tmp);
    }
    while (!isEmpty(S))
    {   
        pop(S, tmp);
        enQ(Q, tmp);
    }
}

int main()
{
    SeqQueue Q;
    init_queue(Q);
    for (int i = 1; i <= 10; i++)
        enQ(Q, i);
    reverse_queue(Q);
    int tmp;
    while (!empty(Q))
    {
        deQ(Q, tmp);
        printf("%d ", tmp);
    }
    return 0;
}