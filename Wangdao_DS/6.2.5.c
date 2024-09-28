#include "adjlist_graph.h"

void print_adjmatrix_by_adjlist(AdjListGraph adjlist_graph)
{
    int adjmatrix_graph[5][5];
    for (int i = 0; i < adjlist_graph.n_vertex; i++)
        for (int j = 0; j < adjlist_graph.n_vertex; j++)
            adjmatrix_graph[i][j] = 0;
    for (int i = 0; i < adjlist_graph.n_vertex; i++)
    {
        int u = adjlist_graph.vertexes[i].vertex_index;
        GraphNode *p = adjlist_graph.vertexes[i].next_edge;
        while (p)
        {
            int v = p->vertex_index;
            adjmatrix_graph[u][v] = 1;
            p = p->next_edge;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", adjmatrix_graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int v[5] = {0, 1, 2, 3, 4};
    AdjListGraph adjlist_graph = create_graph(v, 5);
    add_edge(adjlist_graph, 0, 1);
    add_edge(adjlist_graph, 1, 0);
    add_edge(adjlist_graph, 0, 2);
    add_edge(adjlist_graph, 2, 0);
    add_edge(adjlist_graph, 1, 4);
    add_edge(adjlist_graph, 4, 1);
    add_edge(adjlist_graph, 2, 3);
    add_edge(adjlist_graph, 3, 2);
    print_graph(adjlist_graph);
    printf("\n");
    print_adjmatrix_by_adjlist(adjlist_graph);
    return 0;
}