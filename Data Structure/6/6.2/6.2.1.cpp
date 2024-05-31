/*
 * 目的：使用C++模板设计并逐步完善图的邻接表抽象数据类型（ADT）。
 * 内容：
 * （1）请参照图的邻接矩阵模板类原型，设计并逐步完善图的邻接表ADT。
 *     （由于该环境目前仅支持单文件的编译，故将所有内容都集中在一个源文件内。
 *     在实际的设计中，推荐将抽象类及对应的派生类分别放在单独的头文件中。）
 * （2）使用构造函数，构造一个有权图。
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
                std::cout << "->" << node->vertexIndex << "(" << node->weight << ")";
                node = node->nextEdge;
            }
            std::cout << "->nullptr";
            if (i != nVertex - 1)
                std::cout << std::endl;
        }
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
    for (int i = 0; i < nEdge; i++)
        cin >> weight[i]; // 权集

    AdjList_Graph<std::string, int> graph(graphType, nVertex, nEdge, vertex, edgePair, weight);
    cout << graph.getGraphType() << endl;
    graph.printVertex();
    cout << endl;
    graph.printGraph();
    return 0;
}
