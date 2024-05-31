/*
 * 使用构造函数，构造一个只有结点没有边的图。
 */

#include <iostream>
#include <string>

template <class VertexType, class EdgeType>
class AdjList_Graph
{
private:
    struct EdgeNode
    {
        int vertexIndex;
        EdgeType weight;
        EdgeNode *nextEdge;
        EdgeNode(int vertexIndex, EdgeType weight) : vertexIndex(vertexIndex), weight(weight), nextEdge(nullptr) {}
    };
    struct VertexNode
    {
        VertexType data;
        EdgeNode *firstEdge;
    };

private:
    std::string graphType;
    int nVertex;
    int nEdge;
    VertexNode *vertex;

public:
    AdjList_Graph(std::string graphType, int nVertex, int nEdge, VertexType *vertex, std::pair<int, int> *edgePair, EdgeType *weight)
        : graphType(graphType), nVertex(nVertex), nEdge(nEdge)
    {
        this->vertex = new VertexNode[nVertex];
        for (int i = 0; i < nVertex; i++)
        {
            this->vertex[i].data = vertex[i];
            this->vertex[i].firstEdge = nullptr;
        }
        for (int i = 0; i < nEdge; i++)
        {
            int v1 = edgePair[i].first;
            int v2 = edgePair[i].second;
            EdgeType w = weight[i];

            EdgeNode *edgeNode = new EdgeNode(v2, w);
            edgeNode->nextEdge = this->vertex[v1].firstEdge;
            this->vertex[v1].firstEdge = edgeNode;
            if (graphType == "UDG" || graphType == "UDN")
            {
                EdgeNode *edgeNode = new EdgeNode(v1, w);
                edgeNode->nextEdge = this->vertex[v2].firstEdge;
                this->vertex[v2].firstEdge = edgeNode;
            }
        }
    }
    AdjList_Graph(std::string graphType, int nVertex, VertexType *vertex)
        : graphType(graphType), nVertex(nVertex), nEdge(0)
    {
        this->vertex = new VertexNode[nVertex];
        for (int i = 0; i < nVertex; i++)
        {
            this->vertex[i].data = vertex[i];
            this->vertex[i].firstEdge = nullptr;
        }
    }
    ~AdjList_Graph()
    {
        for (int i = 0; i < nVertex; i++)
        {
            EdgeNode *node = vertex[i].firstEdge;
            while (node)
            {
                auto temp = node;
                node = node->nextEdge;
                delete temp;
            }
        }
        delete[] vertex;
    }
    std::string getGraphType() const { return graphType; }
    void printVertex() const
    {
        for (int i = 0; i < nVertex; i++)
        {
            std::cout << vertex[i].data;
            if (i != nVertex - 1)
                std::cout << " ";
        }
    }
    void printGraph() const
    {
        for (int i = 0; i < nVertex; i++)
        {
            std::cout << vertex[i].data;
            EdgeNode *node = vertex[i].firstEdge;
            while (node)
            {
                if (graphType == "UDN" || graphType == "DN")
                    std::cout << "->" << node->vertexIndex << "(" << node->weight << ")";
                else
                    std::cout << "->" << node->vertexIndex;
                node = node->nextEdge;
            }
            std::cout << "->nullptr";
            if (i != nVertex - 1)
                std::cout << std::endl;
        }
    }
    int getFirstAdjVertexIndex(int v) const
    {
        EdgeNode *node = vertex[v].firstEdge;
        if (node)
            return node->vertexIndex;
        return -1;
    }
    bool getWeight(int v1, int v2, EdgeType &w) const
    {
        if (v1 < 0 || v1 >= nVertex || v2 < 0 || v2 >= nVertex)
            return false;
        EdgeNode *node = vertex[v1].firstEdge;
        while (node)
        {
            if (node->vertexIndex == v2)
            {
                w = node->weight;
                return true;
            }
            node = node->nextEdge;
        }
        return false;
    }
    bool existEdge(int v1, int v2) const
    {
        if (v1 < 0 || v1 >= nVertex || v2 < 0 || v2 >= nVertex)
            return false;
        EdgeNode *node = vertex[v1].firstEdge;
        while (node)
        {
            if (node->vertexIndex == v2)
                return true;
            node = node->nextEdge;
        }
        return false;
    }
};

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    std::string graphType;
    cin >> graphType; // 图类型
    int nVertex;
    cin >> nVertex; // 顶点数
    std::string vertex[nVertex];
    for (int i = 0; i < nVertex; i++)
        cin >> vertex[i]; // 顶点集

    AdjList_Graph<std::string, int> graph(graphType, nVertex, vertex);
    cout << graph.getGraphType() << endl;
    graph.printVertex();
    cout << endl;
    graph.printGraph();
    return 0;
}