#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int M[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%4d", M[j][i]);
        }
        printf("\n");
    }
    return 0;
}