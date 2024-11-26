#include <stdio.h>

void dfs(int *G[], int u, int visited[], int &time, int timer[])
{
    visited[u] = 1;
    for (int v = 0; v < 5; v++)
        if (G[u][v] == 1 && visited[v] == 0)
            dfs(G, v, visited, time, timer);
    timer[u] = ++time;
}

void topological_sort(int *G[])
{
    int visited[5] = {0};
    int timer[5] = {0};
    int time = 0;
    for (int u = 0; u < 5; u++)
        if (!visited[u])
            dfs(G, u, visited, time, timer);
    for (int val = 5; val > 0; val--)
        for (int i = 0; i < 5; i++)
            if (timer[i] == val)
                printf("%d ", i + 1);
}

int main()
{
    int g1[5] = {0, 1, 0, 1, 1};
    int g2[5] = {0, 0, 1, 1, 0};
    int g3[5] = {0, 0, 0, 1, 0};
    int g4[5] = {0, 0, 0, 0, 0};
    int g5[5] = {0, 0, 0, 1, 0};
    int *G[5] = {g1, g2, g3, g4, g5};
    topological_sort(G);
    return 0;
}