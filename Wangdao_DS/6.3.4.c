#include "adjlist_graph.h"
#include "seq_queue.h"
#include <stdbool.h>

void dfs(AdjListGraph G, int vi, int vj, bool *res, bool *visited)
{
    if (*res)
        return;
    if (vi == vj)
    {
        *res = true;
        return;
    }
    visited[vi] = true;
    GraphNode *p = G.vertexes[vi].next_edge;
    while (p)
    {
        if (!visited[p->vertex_index])
            dfs(G, p->vertex_index, vj, res, visited);
        p = p->next_edge;
    }
}

void bfs(AdjListGraph G, int vi, int vj, bool *res)
{
    bool visited[G.n_vertex] = {false};
    SeqQueue Q;
    init_queue(Q);
    enQ(Q, vi);
    while (!empty(Q))
    {
        int u;
        deQ(Q, u);
        visited[u] = true;
        if (u == vj)
        {
            *res = true;
            return;
        }
        GraphNode *p = G.vertexes[u].next_edge;
        while (p)
        {
            int v = p->vertex_index;
            if (visited[v] == false)
                enQ(Q, v);
            p = p->next_edge;
        }
    }
}

bool find_path(AdjListGraph G, int vi, int vj, char method) // method: 'd' = dfs, 'b' = bfs
{
    bool res = false;
    if (method == 'd')
    {
        bool visited[G.n_vertex];
        dfs(G, vi, vj, &res, visited);
    }
    else if (method == 'b')
    {
        bfs(G, vi, vj, &res);
    }
    return res;
}

int main()
{
    int V[4] = {0, 1, 2, 3};
    AdjListGraph G = create_graph(V, 4);
    add_edge(G, 0, 1);
    add_edge(G, 1, 3);
    add_edge(G, 3, 2);
    add_edge(G, 0, 3);
    bool res_dfs = find_path(G, 0, 2, 'd'); // dfs
    bool res_bfs = find_path(G, 0, 2, 'b'); // bfs
    printf("DFS: %s\n", res_dfs ? "true" : "false");
    printf("BFS: %s\n", res_bfs ? "true" : "false");
    return 0;
}