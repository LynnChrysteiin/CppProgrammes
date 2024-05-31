/*
 * 设计并实现一个算法，向已存在的图中添加一个顶点。图的存储结构采用邻接表。添加的顶点的位序在顶点集的末端。
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
    int countVertex() const { return nVertex; }
    int countEdge() const { return nEdge; }
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
    bool insertEdge(int v1, int v2, EdgeType w)
    {
        if (v1 < 0 || v1 >= nVertex || v2 < 0 || v2 >= nVertex)
            return false;
        if (existEdge(v1, v2))
            return false;
        EdgeNode *node = new EdgeNode(v2, w);
        node->nextEdge = vertex[v1].firstEdge;
        vertex[v1].firstEdge = node;
        if (graphType == "UDG" || graphType == "UDN")
        {
            EdgeNode *node = new EdgeNode(v1, w);
            node->nextEdge = vertex[v2].firstEdge;
            vertex[v2].firstEdge = node;
        }
        nEdge++;
        return true;
    }
    bool insertVertex(VertexType v)
    {
        for (int i = 0; i < nVertex; i++)
            if (vertex[i].data == v)
                return false;
        auto newVertex = new VertexNode[nVertex + 1];
        for (int i = 0; i < nVertex; i++)
            newVertex[i] = vertex[i];
        newVertex[nVertex].data = v;
        newVertex[nVertex].firstEdge = nullptr;
        delete[] vertex;
        vertex = newVertex;
        nVertex++;
        return true;
    }
    bool deleteVertex(int v)
    {
        if (v < 0 || v >= nVertex)
            return false;
        EdgeNode *node = vertex[v].firstEdge;
        while (node)
        {
            auto temp = node;
            node = node->nextEdge;
            delete temp;
            nEdge--;
        }
        vertex[v].firstEdge = nullptr;
        for (int i = 0; i < nVertex; i++)
        {
            if (i == v)
                continue;
            node = vertex[i].firstEdge;
            EdgeNode *prev = nullptr;
            while (node)
            {
                int verIdx = node->vertexIndex;
                if (verIdx > v)
                    node->vertexIndex--;
                if (verIdx == v)
                {
                    if (prev)
                        prev->nextEdge = node->nextEdge;
                    else
                        vertex[i].firstEdge = node->nextEdge;
                    auto temp = node;
                    node = node->nextEdge;
                    delete temp;
                    if (graphType == "DG" || graphType == "DN")
                        nEdge--;
                }
                else
                {
                    prev = node;
                    node = node->nextEdge;
                }
            }
        }
        nVertex--;
        for (int i = v; i < nVertex; i++)
            vertex[i] = vertex[i + 1];
        return true;
    }
    int getInDegree(int v) const
    {
        if (v < 0 || v >= nVertex || graphType == "UDG" || graphType == "UDN")
            return -1;
        int inDegree = 0;
        for (int i = 0; i < nVertex; i++)
        {
            EdgeNode *node = vertex[i].firstEdge;
            while (node)
            {
                if (node->vertexIndex == v)
                    inDegree++;
                node = node->nextEdge;
            }
        }
        return inDegree;
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
    int nEdge;
    cin >> nEdge; // 边数
    std::pair<int, int> edgePair[nEdge];
    for (int i = 0; i < nEdge; i++)
        cin >> edgePair[i].first >> edgePair[i].second; // 边集
    int weight[nEdge];
    if (graphType == "UDN" || graphType == "DN")
        for (int i = 0; i < nEdge; i++)
            cin >> weight[i]; // 权集
    else
        for (int i = 0; i < nEdge; i++)
            weight[i] = 1;
    std::string v;
    cin >> v; // 添加的顶点

    AdjList_Graph<std::string, int> graph(graphType, nVertex, nEdge, vertex, edgePair, weight);

    cout << graph.getGraphType() << endl;
    graph.printVertex();
    cout << endl;
    graph.printGraph();
    cout << endl
         << endl;

    graph.insertVertex(v);
    graph.printVertex();
    cout << endl;
    graph.printGraph();
    return 0;
}
