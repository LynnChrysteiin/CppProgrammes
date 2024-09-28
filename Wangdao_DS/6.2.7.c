#include <stdio.h>

int is_exist_el(int** G)
{
    int cnt = 0;
    int deg = 0;
    for (int u = 0; u < 5; u++)
    {
        for (int v = 0; v < 5; v++)
        {
            if (G[u][v] == 1)
                deg++;
        }
        if (deg % 2 == 1)
            cnt++;
        deg = 0;
    }
    return cnt == 0 || cnt == 2;
}

int main()
{
    int g1[5] = {0, 1, 0, 1, 1};
    int g2[5] = {1, 0, 1, 0, 0};
    int g3[5] = {0, 1, 0, 1, 0};
    int g4[5] = {1, 0, 1, 0, 1};
    int g5[5] = {1, 0, 0, 1, 0};
    int *G[5] = {g1, g2, g3, g4, g5};
    
    for (int u = 0; u < 5; u++)
    {
        for (int v = 0; v < 5; v++)
            printf("%d ", G[u][v]);
        printf("\n");
    }
    printf(is_exist_el(G) ? "Yes!\n" : "No!\n");
    return 0;
}