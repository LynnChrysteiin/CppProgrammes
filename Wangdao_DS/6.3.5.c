#include "adjlist_graph.h"

void find_all_path(AdjListGraph G, int vi, int vj, int path[], int c, bool visited[])
{
    path[c] = vi;
    visited[vi] = true;
    if (vi == vj)
    {
        for (int i = 0; i < c; i++)
            printf("%d-", path[i]);
        printf("%d\n", vj);
    }
    GraphNode *p = G.vertexes[vi].next_edge;
    while (p)
    {
        int vk = p->vertex_index;
        if (visited[vk] == false)
            find_all_path(G, vk, vj, path, c + 1, visited);
        p = p->next_edge;
    }
    visited[vi] = false;
}

int main()
{
    int V[5] = {0, 1, 2, 3, 4};
    AdjListGraph G = create_graph(V, 5);
    add_edge(G, 0, 1);
    add_edge(G, 1, 2);
    add_edge(G, 2, 4);
    add_edge(G, 1, 3);
    add_edge(G, 0, 2);
    add_edge(G, 2, 3);
    add_edge(G, 3, 4);
    add_edge(G, 0, 3);
    add_edge(G, 0, 4);
    int path[5];
    bool visited[5] = {false};
    find_all_path(G, 0, 4, path, 0, visited);
    return 0;
}