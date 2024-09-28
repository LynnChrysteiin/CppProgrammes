#include <stdio.h>

#define MAXN 32

typedef struct
{
    int data[MAXN];
    int size;
} SeqBiTree;

void judge_bistree(SeqBiTree T, int root, bool &res, int max, int min)
{
    if (res == false || root >= T.size || T.data[root] == -1)
        return;
    if (T.data[root] <= min || T.data[root] >= max)
    {
        res = false;
        return;
    }
    int lchild = (root + 1) * 2 - 1;
    int rchild = (root + 1) * 2;
    if (lchild < T.size && T.data[lchild] != -1)
    {
        if (T.data[lchild] < T.data[root])
            judge_bistree(T, lchild, res, T.data[root], min);
        else
            res = false;
    }
    if (rchild < T.size && T.data[rchild] != -1)
    {
        if (T.data[rchild] > T.data[root])
            judge_bistree(T, rchild, res, max, T.data[root]);
        else
            res = false;
    }
}

int main()
{
    SeqBiTree T = {{45, 20, 60, -1, 55, -1, 80, -1, -1, 27}, 10};
    /*
     *            45
     *           /  \
     *         20    60
     *        /  \   / \
     *       #   55 #  80
     *      / \  /
     *     #  # 27 
     */
    bool res = true;
    judge_bistree(T, 0, res, 0x7fffffff, 0x80000000);
    printf(res ? "TRUE\n" : "FALSE\n");
    return 0;
}