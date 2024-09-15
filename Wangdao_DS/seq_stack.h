#ifndef _SEQ_STACK_H_
#define _SEQ_STACK_H_

#include <stdio.h>

#define MAXN 16

typedef struct SeqStack
{
    int data[MAXN];
    int size;
} SeqStack;

void init_stack(SeqStack &S)
{
    S.size = 0;
}

bool isOverflow(SeqStack S)
{
    return S.size == MAXN;
}

bool isEmpty(SeqStack S)
{
    return S.size == 0;
}

bool push(SeqStack &S, int x)
{
    if (isOverflow(S))
        return false;
    S.data[S.size] = x;
    S.size++;
    return true;
}

bool pop(SeqStack &S, int &x)
{
    if (isEmpty(S))
        return false;
    S.size--;
    x = S.data[S.size];
    return true;
}

#endif // !_SEQ_STACK_H_