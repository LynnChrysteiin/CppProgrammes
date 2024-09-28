#include <stdio.h>

void dfs(int **G, int u, bool *res, bool *visited)
{
    if (visited[u] == true)
        (*res) = false;
    if ((*res) == false)
        return;
    visited[u] = true;
    for (int v = u; v < 4; v++)
    {
        if (G[u][v] == 1)
        {
            dfs(G, v, res, visited);
        }
    }
}

bool is_tree(int **G)
{
    bool visited[5] = {false};
    bool res = true;
    dfs(G, 0, &res, visited);
    for (int i = 0; i < 4; i++)
        if (visited[i] == false)
            return false;
    return res;
}

int main()
{
    int g0[4] = {0, 1, 1, 0};
    int g1[4] = {1, 0, 0, 0};
    int g2[4] = {1, 0, 0, 1};
    int g3[4] = {0, 0, 1, 0};
    // 0 - 1
    // |
    // 2 - 3
    int *G[4] = {g0, g1, g2, g3};
    printf(is_tree(G) ? "TRUE!\n" : "FALSE!\n");
    return 0;
}