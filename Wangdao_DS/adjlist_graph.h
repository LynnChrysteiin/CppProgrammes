#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode
{
    int vertex_index;
    GraphNode *next_edge;
} GraphNode;

typedef struct AdjListGraph
{
    GraphNode vertexes[8];
    int n_vertex;
} AdjListGraph;

AdjListGraph create_graph(int vertexes[], int n)
{
    AdjListGraph graph;
    for (int i = 0; i < n; i++)
    {
        graph.vertexes[i].vertex_index = vertexes[i];
        graph.vertexes[i].next_edge = NULL;
    }
    graph.n_vertex = n;
    return graph;
}

void add_edge(AdjListGraph &graph, int u, int v)
{
    GraphNode *edge = (GraphNode *)malloc(sizeof(GraphNode));
    edge->vertex_index = v;
    edge->next_edge = NULL;
    GraphNode *p = &(graph.vertexes[u]);
    while (p->next_edge)
        p = p->next_edge;
    p->next_edge = edge;
}

void print_graph(AdjListGraph graph)
{
    for (int i = 0; i < graph.n_vertex; i++)
    {
        auto p = graph.vertexes[i].next_edge;
        printf("%d: ", graph.vertexes[i].vertex_index);
        while (p)
        {
            printf("->%d ", p->vertex_index);
            p = p->next_edge;
        }
        printf("\n");
    }
}