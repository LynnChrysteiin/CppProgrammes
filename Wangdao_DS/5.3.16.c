#include "binary_tree.h"

void judge_similar(BiTree rootA, BiTree rootB, bool &res)
{
    if (rootA->left)
        if (rootB->left)
            judge_similar(rootA->left, rootB->left, res);
        else
            res = false;
    if (rootA->right)
        if (rootB->right)
            judge_similar(rootA->right, rootB->right, res);
        else
            res = false;
    if (!res)
        return;
}

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int B[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int C[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    BiTree TA = create_tree(A, 10);
    BiTree TB = create_tree(B, 10);
    BiTree TC = create_tree(C, 8);
    bool resAB = true, resAC = true;
    judge_similar(TA, TB, resAB);
    judge_similar(TA, TC, resAC);
    printf(resAB ? "AB TRUE\n" : "AB FALSE\n");
    printf(resAC ? "AC TRUE\n" : "AC FALSE\n");
    return 0;
}