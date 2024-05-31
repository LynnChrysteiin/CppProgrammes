#include <stdio.h>

void getMaxSubseqSum(int N, int A[]) {
    int hasPosi = 0;
    int hasZero = 0;
    int hasNega = 0;
    int thisSum, maxSum;
    thisSum = maxSum = 0;
    int oldLeftNum, newLeftNum, rightNum;
    oldLeftNum = newLeftNum = A[1];
    rightNum = A[N];
    for (int i=1; i<=N; i++) {
        thisSum += A[i];
        if (A[i] == 0) hasZero = 1;
        else if (A[i] < 0) hasNega = 1;
        else if (A[i] > 0) hasPosi = 1;
        if (thisSum > maxSum) {
            maxSum = thisSum;
            rightNum = A[i];
            oldLeftNum = newLeftNum;
        }
        else if (thisSum < 0) {
            thisSum = 0;
            newLeftNum = A[i+1];
        }
    }
    if (hasNega && hasZero && hasPosi == 0) oldLeftNum = rightNum = 0;
    printf("%d %d %d", maxSum, oldLeftNum, rightNum);
}

int main() {
    int N;
    scanf("%d", &N);
    int A[N+1];
    for (int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
    }
    getMaxSubseqSum(N, A);
    return 0;
}