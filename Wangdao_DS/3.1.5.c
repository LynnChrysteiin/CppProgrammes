#include <stdio.h>

#define MAXSIZE 32
typedef struct TwinSeqStack
{
    int data[MAXSIZE];
    int sizeA;
    int sizeB;
} TwinSeqStack;

void init_stack(TwinSeqStack &S)
{
    S.sizeA = 0;
    S.sizeB = 0;
}

bool isOverflow(TwinSeqStack S)
{
    return S.sizeA + S.sizeB == MAXSIZE;
}

bool pushA(TwinSeqStack &S, int x)
{
    if (isOverflow(S))
        return false;
    S.data[S.sizeA] = x;
    S.sizeA++;
    return true;
}

bool pushB(TwinSeqStack &S, int x)
{
    if (isOverflow(S))
        return false;
    S.data[MAXSIZE - 1 - S.sizeB] = x;
    S.sizeB++;
    return true;
}

bool popA(TwinSeqStack &S, int &x)
{
    if (S.sizeA == 0)
        return false;
    S.sizeA--;
    x = S.data[S.sizeA];
    return true;
}

bool popB(TwinSeqStack &S, int &x)
{
    if (S.sizeB == 0)
        return false;
    S.sizeB--;
    x = S.data[MAXSIZE - 1 - S.sizeB];
    return true;
}

int main()
{
    TwinSeqStack S;
    init_stack(S);
    for (int i = 0; i < 12; i++)
        pushA(S, i);
    for (int i = 0; i < 24; i++)
        pushB(S, i);
    for (int i = 0; i < MAXSIZE; i++)
        printf("%d ", S.data[i]);
    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        int tmp;
        popA(S, tmp);
        printf("%d ", tmp);
    }
    return 0;
}