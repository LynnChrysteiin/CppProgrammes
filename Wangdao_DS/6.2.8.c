#include <stdio.h>

int count_k_vertex(int **G)
{
    int res = 0;
    for (int u = 0; u < 4; u++)
    {
        int ideg = 0;
        int odeg = 0;
        for (int v = 0; v < 4; v++)
            if (G[u][v] == 1)
                odeg++;
        for (int v = 0; v < 4; v++)
            if (G[v][u] == 1)
                ideg++;
        if (odeg > ideg)
        {
            res++;
            printf("%d ", u);
        }
    }
    return res;
}

int main()
{
    int g0[4] = {0, 1, 0, 1};
    int g1[4] = {0, 0, 1, 1};
    int g2[4] = {0, 0, 0, 1};
    int g3[4] = {0, 0, 0, 0};
    int *G[4] = {g0, g1, g2, g3};
    printf("K顶点为：");
    printf("\nK顶点有 %d 个。\n", count_k_vertex(G));
    return 0;
}